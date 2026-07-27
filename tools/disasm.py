#!/usr/bin/env python3.9
"""Dump the ORIGINAL bytecode of a shipped module as ground truth.

Usage:  python3.9 tools/disasm.py <module> [funcname]

Prints a full recursive disassembly of proprietary/shims/<module>.pyc (the
authoritative program). Optionally restrict to one code object by name. This is
the reference an editor uses to reconstruct source that recompiles byte-exact
(pair with tools/verify_module.py, which diffs the recompiled result).
"""
import sys, os, dis, marshal

ROOT = os.environ.get("REPO_ROOT", os.getcwd())

def load(p):
    return marshal.loads(open(p, "rb").read()[16:])

def walk(code, want, depth=0):
    if want is None or code.co_name == want:
        print(f"\n{'  '*depth}==== {code.co_name}  "
              f"(args={code.co_argcount}, kwonly={code.co_kwonlyargcount}, "
              f"flags=0x{code.co_flags:x}) ====")
        dis.dis(code)
    for c in code.co_consts:
        if hasattr(c, "co_code"):
            walk(c, want, depth + 1)

def main():
    mod = sys.argv[1]
    want = sys.argv[2] if len(sys.argv) > 2 else None
    pyc = os.path.join(ROOT, "proprietary/shims", mod + ".pyc")
    if not os.path.exists(pyc):
        pyc = os.path.join(ROOT, "proprietary/so", mod + ".pyc")
    code = load(pyc)
    walk(code, want)

if __name__ == "__main__":
    main()
