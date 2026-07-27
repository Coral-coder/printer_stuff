#!/usr/bin/env python3.9
"""Verify one recovered module against its original bytecode.

Usage:  python3.9 tools/verify_module.py <module-name>   (e.g. fan)

Compiles decompiled/shims/<mod>.py under CPython 3.9 and diffs each code
object's bytecode against proprietary/shims/<mod>.pyc. Prints FAITHFUL, or the
exact per-function opcode divergences to fix. Exit 0 iff byte-faithful.
"""
import sys, os, marshal, dis, difflib, py_compile, tempfile

ROOT = os.environ.get("REPO_ROOT", os.getcwd())

def load(p):
    return marshal.loads(open(p, "rb").read()[16:])

def norm(v):
    if hasattr(v, "co_code"):
        return ("<code>", v.co_name)
    if isinstance(v, frozenset):
        return ("frozenset", tuple(sorted(map(repr, v))))
    if isinstance(v, tuple):
        return ("tuple", tuple(norm(x) for x in v))
    return (type(v).__name__, v)

def collect(c, path, out):
    k = path; n = 0
    while k in out:
        n += 1; k = "%s#%d" % (path, n)
    out[k] = [(i.opname, norm(i.argval)) for i in dis.get_instructions(c)]
    for x in c.co_consts:
        if hasattr(x, "co_code"):
            collect(x, path + "." + x.co_name, out)
    return out

def main():
    mod = sys.argv[1]
    src = os.path.join(ROOT, "decompiled/shims", mod + ".py")
    orig = os.path.join(ROOT, "proprietary/shims", mod + ".pyc")
    tmp = tempfile.mktemp(suffix=".pyc")
    try:
        py_compile.compile(src, cfile=tmp, doraise=True)
    except Exception as e:
        print("WONT-COMPILE:", str(e).splitlines()[-1])
        sys.exit(2)
    fa = collect(load(orig), "<m>", {})
    fb = collect(load(tmp), "<m>", {})
    os.unlink(tmp)
    bad = 0
    for k in fa:
        if k not in fb:
            print("MISSING FUNCTION:", k); bad += 1; continue
        a, b = fa[k], fb[k]
        if a == b:
            continue
        bad += 1
        print(f"--- diverges: {k} (orig {len(a)} ops vs reasm {len(b)} ops) ---")
        sm = difflib.SequenceMatcher(None, a, b)
        for tag, i1, i2, j1, j2 in sm.get_opcodes():
            if tag == "equal":
                continue
            print(f"    orig  [{i1}:{i2}] = {a[i1:i2]}")
            print(f"    reasm [{j1}:{j2}] = {b[j1:j2]}")
    for k in fb:
        if k not in fa:
            print("EXTRA FUNCTION:", k); bad += 1
    if bad == 0:
        print("FAITHFUL")
        sys.exit(0)
    print(f"NOT-FAITHFUL ({bad} code objects diverge)")
    sys.exit(1)

if __name__ == "__main__":
    main()
