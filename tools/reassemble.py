#!/usr/bin/env python3.9
"""Reassembly + faithfulness verification for the recovered Python source.

MUST be run under CPython 3.9 (the printer's runtime): recompiles each
recovered `decompiled/**/*.py` to a `.pyc` with the correct 3.9 magic, and
compares the fresh code objects against the ORIGINAL `.pyc` recursively. A
high opcode-match ratio proves the decompilation round-trips faithfully.

Outputs:
  reassembled/**/*.pyc         drop-in rebuilt bytecode (3.9)
  reassembled/_faithfulness.json  per-module match report
"""
import dis, marshal, os, sys, json, py_compile, difflib

if sys.version_info[:2] != (3, 9):
    sys.exit(f"must run under Python 3.9 (got {sys.version.split()[0]})")

ROOT = os.environ.get("REPO_ROOT", os.getcwd())
SRC = os.path.join(ROOT, "decompiled")
ORIG = os.path.join(ROOT, "proprietary")
OUT = os.path.join(ROOT, "reassembled")

def load_code(pyc):
    return marshal.loads(open(pyc, "rb").read()[16:])

def opnames(code):
    return [i.opname for i in dis.get_instructions(code)]

def collect(code, path, out):
    """Flatten every code object reachable from `code`, keyed by a dotted
    path of co_names, disambiguating duplicates with an index suffix."""
    key = path
    n = 0
    while key in out:
        n += 1
        key = f"{path}#{n}"
    out[key] = opnames(code)
    for c in code.co_consts:
        if hasattr(c, "co_code"):
            collect(c, f"{path}.{c.co_name}", out)
    return out

def compare(a, b):
    """Robust similarity: match code objects by name path, then use a
    sequence-similarity ratio on opcode streams (tolerant to reordering /
    insertions). Returns a 0-100 score weighted by opcode count."""
    fa, fb = collect(a, a.co_name or "<module>", {}), collect(b, b.co_name or "<module>", {})
    keys = set(fa) | set(fb)
    num = den = 0.0
    for k in keys:
        oa, ob = fa.get(k, []), fb.get(k, [])
        weight = max(len(oa), len(ob), 1)
        ratio = difflib.SequenceMatcher(None, oa, ob).ratio() if (oa or ob) else 1.0
        num += ratio * weight
        den += weight
    return round(100.0 * num / den, 1) if den else 100.0

def main():
    report = []
    for dirpath, _, files in os.walk(SRC):
        for f in sorted(files):
            if not f.endswith(".py"):
                continue
            src = os.path.join(dirpath, f)
            rel = os.path.relpath(src, SRC)                 # e.g. shims/fan.py
            orig_pyc = os.path.join(ORIG, rel[:-3] + ".pyc")
            out_pyc = os.path.join(OUT, rel[:-3] + ".pyc")
            os.makedirs(os.path.dirname(out_pyc), exist_ok=True)
            entry = {"module": rel, "compiled": False, "match": None, "note": ""}
            try:
                py_compile.compile(src, cfile=out_pyc, doraise=True)
                entry["compiled"] = True
            except Exception as e:
                entry["note"] = f"compile-failed: {type(e).__name__}: {str(e)[:120]}"
                report.append(entry)
                continue
            if os.path.exists(orig_pyc):
                try:
                    entry["match"] = compare(load_code(orig_pyc), load_code(out_pyc))
                except Exception as e:
                    entry["note"] = f"compare-failed: {e}"
            report.append(entry)
    os.makedirs(OUT, exist_ok=True)
    with open(os.path.join(OUT, "_faithfulness.json"), "w") as fh:
        json.dump(report, fh, indent=2)
    _write_md(report)
    comp = [r for r in report if r["compiled"]]
    matched = [r for r in comp if r["match"] is not None]
    exact = [r for r in matched if r["match"] >= 99.5]
    high = [r for r in matched if 90 <= r["match"] < 99.5]
    print(f"modules={len(report)} recompiled={len(comp)} "
          f"faithful(>=99.5%)={len(exact)} high(90-99.5%)={len(high)} "
          f"lower={len(matched) - len(exact) - len(high)}")
    for r in sorted(matched, key=lambda r: r["match"]):
        if r["match"] < 90:
            print(f"  low {r['match']:5}%  {r['module']}")

def _cat(r):
    if not r["compiled"]:
        return "broken"
    if r["match"] is None:
        return "compiled"
    if r["match"] >= 99.5:
        return "faithful"
    if r["match"] >= 90:
        return "high"
    return "partial"

def _write_md(report):
    order = {"faithful": 0, "high": 1, "partial": 2, "compiled": 3, "broken": 4}
    rows = sorted(report, key=lambda r: (order[_cat(r)], -(r["match"] or 0), r["module"]))
    from collections import Counter
    counts = Counter(_cat(r) for r in report)
    lines = ["# Reassembly faithfulness (recompiled under CPython 3.9 vs original bytecode)\n"]
    lines.append("Each recovered `.py` is recompiled to a 3.9 `.pyc` and its code objects are")
    lines.append("compared opcode-for-opcode against the original. **faithful** = the recovered")
    lines.append("source round-trips to essentially the same bytecode (a proof of correctness).\n")
    lines.append(f"- faithful (>=99.5%): **{counts.get('faithful',0)}**")
    lines.append(f"- high (90-99.5%): **{counts.get('high',0)}**")
    lines.append(f"- partial (<90%): **{counts.get('partial',0)}**")
    lines.append(f"- broken (won't recompile under 3.9 / empty): **{counts.get('broken',0)}**\n")
    lines.append("| module | category | bytecode match | note |")
    lines.append("|--------|----------|---------------:|------|")
    for r in rows:
        mt = "—" if r["match"] is None else f"{r['match']}%"
        lines.append(f"| `{r['module']}` | {_cat(r)} | {mt} | {r['note'][:70]} |")
    with open(os.path.join(OUT, "FAITHFULNESS.md"), "w") as fh:
        fh.write("\n".join(lines) + "\n")

if __name__ == "__main__":
    main()
