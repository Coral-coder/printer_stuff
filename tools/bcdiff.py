#!/usr/bin/env python3.9
"""Pinpoint why a recovered module diverges from its original bytecode.

Run under CPython 3.9. For each non-faithful module it recompiles the recovered
source, aligns opcode streams per code object (by name), and reports the first
few divergences — classified — so root causes can be fixed by impact.
"""
import dis, marshal, os, sys, difflib, json, collections, py_compile, tempfile

ROOT = os.environ.get("REPO_ROOT", os.getcwd())
SRC = os.path.join(ROOT, "decompiled")
ORIG = os.path.join(ROOT, "proprietary")

def load(pyc):
    return marshal.loads(open(pyc, "rb").read()[16:])

def _norm(v):
    # Normalise an instruction's argval for functional comparison:
    #  - code objects -> placeholder (their bodies are compared recursively)
    #  - keep numeric TYPE distinct so 0 != 0.0, True != 1
    if hasattr(v, "co_code"):
        return ("<code>", v.co_name)
    if isinstance(v, frozenset):
        return ("frozenset", tuple(sorted(map(repr, v))))
    if isinstance(v, tuple):
        return ("tuple", tuple(_norm(x) for x in v))
    return (type(v).__name__, v)

def ops(code):
    return [(i.opname, _norm(i.argval)) for i in dis.get_instructions(code)]

def collect(code, path, out):
    key = path; n = 0
    while key in out:
        n += 1; key = "%s#%d" % (path, n)
    out[key] = code
    for c in code.co_consts:
        if hasattr(c, "co_code"):
            collect(c, path + "." + c.co_name, out)
    return out

def classify(a_ops, b_ops):
    """a=orig, b=reassembled. Return a short label for the first divergence."""
    sm = difflib.SequenceMatcher(None, [o for o, _ in a_ops], [o for o, _ in b_ops])
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "equal":
            continue
        ao = a_ops[i1:i2]; bo = b_ops[j1:j2]
        aset = {o for o, _ in ao}; bset = {o for o, _ in bo}
        # dropped operand -> None
        if any(o.startswith("LOAD_") for o, _ in ao) and \
           any(o == "LOAD_CONST" and r in ("None", "") for o, r in bo):
            return "dropped-name->None"
        if "SETUP_FINALLY" in aset or "SETUP_FINALLY" in bset:
            return "try/finally-structure"
        if aset & {"POP_JUMP_IF_TRUE", "POP_JUMP_IF_FALSE"} != bset & {"POP_JUMP_IF_TRUE", "POP_JUMP_IF_FALSE"}:
            return "branch-logic"
        if "CONTINUE_LOOP" in aset or "JUMP_ABSOLUTE" in aset or "BREAK_LOOP" in aset:
            return "loop-jump(break/continue)"
        if aset ^ bset:
            return "opcode-mismatch:" + ",".join(sorted(aset ^ bset)[:3])
        return "operand-mismatch"
    return "len-mismatch" if len(a_ops) != len(b_ops) else "equal"

def main():
    target = sys.argv[1] if len(sys.argv) > 1 else None
    cats = collections.Counter()
    detail = []
    for dirpath, _, files in os.walk(SRC):
        for f in sorted(files):
            if not f.endswith(".py"):
                continue
            rel = os.path.relpath(os.path.join(dirpath, f), SRC)
            if target and target not in rel:
                continue
            src = os.path.join(dirpath, f)
            orig_pyc = os.path.join(ORIG, rel[:-3] + ".pyc")
            if not os.path.exists(orig_pyc):
                continue
            with tempfile.NamedTemporaryFile(suffix=".pyc", delete=False) as tf:
                tmp = tf.name
            try:
                py_compile.compile(src, cfile=tmp, doraise=True)
            except Exception as e:
                cats["WONT-COMPILE"] += 1
                detail.append((rel, "WONT-COMPILE", str(e).splitlines()[-1][:70]))
                continue
            fa = collect(load(orig_pyc), "<m>", {})
            fb = collect(load(tmp), "<m>", {})
            os.unlink(tmp)
            divs = []
            for k in fa:
                if k not in fb:
                    divs.append("missing-fn:" + k.split(".")[-1]); continue
                oa, ob = ops(fa[k]), ops(fb[k])
                if oa != ob:
                    # opnames identical but argrepr differs = benign-ish (const/name)
                    if [o for o, _ in oa] == [o for o, _ in ob]:
                        divs.append("argrepr-only")
                    else:
                        divs.append(classify(oa, ob))
            extra = ""
            if len(fb) > len(fa):
                divs.append("extra-fn")
            if not divs:
                cats["FAITHFUL"] += 1
                continue
            # a module is only faithful if ZERO functions diverge; otherwise
            # label it by its single most-severe divergence
            sev = ["WONT-COMPILE", "missing-fn", "extra-fn", "loop-jump(break/continue)",
                   "try/finally-structure", "branch-logic", "opcode-mismatch",
                   "dropped-name->None", "operand-mismatch", "argrepr-only", "len-mismatch"]
            def rank(d):
                for i, s in enumerate(sev):
                    if d.startswith(s):
                        return i
                return len(sev)
            worst = min(divs, key=rank)
            cats["NON-FAITHFUL:" + worst.split(":")[0]] += 1
            detail.append((rel, dict(collections.Counter(divs)) if target else worst, extra))
    print("=== divergence categories (module counts) ===")
    for k, v in cats.most_common():
        print(f"  {v:3}  {k}")
    if target:
        print("\n=== detail ===")
        for rel, d, extra in detail:
            print(f"  {rel}: {d} {extra}")
    else:
        print("\n=== per-module primary divergence ===")
        for rel, top, _ in sorted(detail):
            print(f"  {top:34} {rel}")

if __name__ == "__main__":
    main()
