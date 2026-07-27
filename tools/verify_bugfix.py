#!/usr/bin/env python3.9
"""Functionality gate for the bugfix branch.

Run under CPython 3.9 from the repo root. It:
  1. Compiles every recovered module under 3.9 (must all succeed).
  2. Determines which shim modules changed vs the faithful baseline (`main`).
  3. Asserts every UNCHANGED module still recompiles byte-identical to the
     original .pyc — i.e. the fixes caused no collateral change anywhere else.
  4. Confirms each CHANGED module compiles and (expectedly) now differs from the
     original bytecode — that difference is the intended fix.

Exit 0 iff: all compile AND all unchanged modules are still byte-exact.
"""
import os, sys, subprocess, marshal, dis, py_compile, tempfile

if sys.version_info[:2] != (3, 9):
    sys.exit("run under Python 3.9")

ROOT = os.environ.get("REPO_ROOT", os.getcwd())
SHIMS = os.path.join(ROOT, "decompiled", "shims")

def load(pyc):
    return marshal.loads(open(pyc, "rb").read()[16:])

def ops(code):
    out = [(i.opname, i.argval if not hasattr(i.argval, "co_code")
            else ("<code>", i.argval.co_name)) for i in dis.get_instructions(code)]
    return out

def collect(code, path, acc):
    k = path; n = 0
    while k in acc:
        n += 1; k = "%s#%d" % (path, n)
    acc[k] = code
    for c in code.co_consts:
        if hasattr(c, "co_code"):
            collect(c, path + "." + c.co_name, acc)
    return acc

def faithful(src_py, orig_pyc):
    tmp = tempfile.mktemp(suffix=".pyc")
    try:
        py_compile.compile(src_py, cfile=tmp, doraise=True)
    except Exception:
        return None  # won't compile
    fa = collect(load(orig_pyc), "<m>", {})
    fb = collect(load(tmp), "<m>", {})
    os.unlink(tmp)
    if set(fa) != set(fb):
        return False
    for k in fa:
        if ops(fa[k]) != ops(fb[k]):
            return False
    return True

def changed_shims():
    """Shim modules whose source differs from origin/main (the baseline)."""
    for base in ("origin/main", "main"):
        r = subprocess.run(["git", "diff", "--name-only", base, "--", "decompiled/shims"],
                           cwd=ROOT, capture_output=True, text=True)
        if r.returncode == 0:
            return {os.path.basename(p) for p in r.stdout.split() if p.endswith(".py")}
    return set()

def main():
    changed = changed_shims()
    wont_compile, regressions, fixed_ok, unchanged_ok = [], [], [], []
    for f in sorted(os.listdir(SHIMS)):
        if not f.endswith(".py"):
            continue
        src = os.path.join(SHIMS, f)
        orig = os.path.join(ROOT, "proprietary", "shims", f[:-3] + ".pyc")
        # compile check (always)
        try:
            py_compile.compile(src, cfile=tempfile.mktemp(suffix=".pyc"), doraise=True)
        except Exception as e:
            wont_compile.append((f, str(e).splitlines()[-1][:70])); continue
        if not os.path.exists(orig):
            continue
        fa = faithful(src, orig)
        if f in changed:
            # intended fix: must compile (done above); should now differ
            fixed_ok.append((f, "differs" if fa is False else "IDENTICAL(?)"))
        else:
            if fa is True:
                unchanged_ok.append(f)
            else:
                regressions.append(f)

    print("=== bugfix functionality gate ===")
    print(f"changed (fixed) modules : {len(changed)}")
    print(f"unchanged still byte-exact: {len(unchanged_ok)}")
    print(f"won't-compile           : {len(wont_compile)}")
    print(f"regressions (unchanged but now differ): {len(regressions)}")
    if changed:
        print("\nfixed modules:")
        for f, note in sorted(fixed_ok):
            flag = "" if note == "differs" else "  <-- WARNING: no bytecode change"
            print(f"  {f:32} {note}{flag}")
    if wont_compile:
        print("\nWON'T COMPILE:")
        for f, e in wont_compile:
            print(f"  {f}: {e}")
    if regressions:
        print("\nREGRESSIONS (untouched module changed unexpectedly):")
        for f in regressions:
            print(f"  {f}")
    ok = not wont_compile and not regressions
    print("\nRESULT:", "PASS" if ok else "FAIL")
    sys.exit(0 if ok else 1)

if __name__ == "__main__":
    main()
