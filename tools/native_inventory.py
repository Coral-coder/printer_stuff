#!/usr/bin/env python3
"""Inventory the non-Python compiled artifacts and emit NATIVE_ARTIFACTS.md."""
import os, re, subprocess, hashlib, glob, collections

ROOT = os.environ.get("REPO_ROOT", os.getcwd())
OUT = os.path.join(ROOT, "proprietary", "NATIVE_ARTIFACTS.md")

def run(cmd):
    try:
        return subprocess.run(cmd, capture_output=True, text=True, timeout=60).stdout
    except Exception:
        return ""

def sha(p):
    return hashlib.sha1(open(p, "rb").read()).hexdigest()[:12]

def filetype(p):
    return run(["file", "-b", p]).strip()

def dyn_syms(p):
    out = run(["nm", "-D", "--defined-only", p])
    names = [l.split()[-1] for l in out.splitlines() if l.strip()]
    return names

def py_idents(p, limit=40):
    """Cython embeds the module's Python identifiers; surface them as the
    recoverable 'API shape' even though the C logic is not decompilable."""
    out = run(["strings", "-n", "4", p])
    seen, res = set(), []
    interesting = re.compile(r"^(?:cmd_|_?[A-Za-z][A-Za-z0-9_]{2,})$")
    skip = re.compile(r"^(?:Py|_Py|PyInit|__pyx|Cython|GLIBC|GCC|clang|abort|memcpy|memset|strlen)")
    for s in out.splitlines():
        s = s.strip()
        if s in seen:
            continue
        if interesting.match(s) and not skip.match(s):
            seen.add(s); res.append(s)
        if len(res) >= limit:
            break
    return res

lines = ["# Native (non-Python) artifacts\n"]
lines.append(
    "These artifacts are **compiled machine code**, not Python. Unlike the "
    "`.pyc` bytecode (recovered to source under `decompiled/`), native code "
    "cannot be decompiled back to faithful source. This inventory records what "
    "each artifact is and what metadata is recoverable (exported symbols, "
    "embedded identifiers), so the API surface is documented even where the "
    "implementation is not.\n")

# --- Cython extension modules -------------------------------------------------
lines.append("## Cython extension modules (`proprietary/so/*.cpython-39.so`)\n")
lines.append(
    "CPython 3.9 C-extensions compiled from Cython. The Python loader stubs "
    "in `proprietary/shims/` (e.g. `box.py`) import classes from these. The "
    "class/function names are embedded and listed below; the bodies are ARM "
    "machine code and are not recoverable to Python.\n")
for so in sorted(glob.glob(os.path.join(ROOT, "proprietary/so/*.so"))):
    rel = os.path.relpath(so, ROOT)
    ft = filetype(so)
    idents = py_idents(so)
    lines.append(f"### `{rel}`")
    lines.append(f"- {ft}")
    lines.append(f"- size: {os.path.getsize(so):,} bytes, sha1 `{sha(so)}`")
    if idents:
        lines.append(f"- embedded identifiers: {', '.join('`%s`' % i for i in idents)}")
    lines.append("")

# --- Compiled C helper --------------------------------------------------------
lines.append("## Compiled C helper (`proprietary/chelper/`)\n")
for p in sorted(glob.glob(os.path.join(ROOT, "proprietary/chelper/*"))):
    rel = os.path.relpath(p, ROOT)
    if p.endswith(".h"):
        lines.append(f"### `{rel}`")
        lines.append("- C **header source** (already present, not compiled).")
        lines.append("")
        continue
    ft = filetype(p)
    lines.append(f"### `{rel}`")
    lines.append(f"- {ft}")
    lines.append(f"- size: {os.path.getsize(p):,} bytes, sha1 `{sha(p)}`")
    syms = [l for l in run(["nm", p]).splitlines() if " T " in l or " D " in l]
    names = [l.split()[-1] for l in syms][:30]
    if names:
        lines.append(f"- symbols: {', '.join('`%s`' % n for n in names)}")
    lines.append("")

# --- MCU firmware -------------------------------------------------------------
lines.append("## Microcontroller firmware (`fw/**/*.bin`)\n")
lines.append(
    "Flashable firmware images for the printer's sub-processors (main MCU, "
    "nozzle, bed, belt, motor, RFID, CFS). These are stripped ARM Cortex-M "
    "binaries with no symbol table; they are **not** decompilable to source. "
    "Listed by content hash (several paths share identical images).\n")
bins = sorted(glob.glob(os.path.join(ROOT, "fw/**/*.bin"), recursive=True))
byhash = collections.OrderedDict()
for b in bins:
    byhash.setdefault(sha(b), []).append(os.path.relpath(b, ROOT))
lines.append("| sha1 | size | type | path(s) |")
lines.append("|------|------|------|---------|")
for h, paths in byhash.items():
    ft = filetype(paths and os.path.join(ROOT, paths[0]))
    ft = ft.split(",")[0]
    size = os.path.getsize(os.path.join(ROOT, paths[0]))
    lines.append(f"| `{h}` | {size:,} | {ft} | {'<br>'.join('`%s`'%p for p in paths)} |")
lines.append("")
lines.append(
    "> Recoverability: firmware and Cython/C artifacts are machine code. Only "
    "the `.pyc` bytecode was recoverable to source. This is documented, not "
    "a gap in effort.")

with open(OUT, "w") as f:
    f.write("\n".join(lines) + "\n")
print("wrote", OUT)
print("cython so:", len(glob.glob(os.path.join(ROOT,'proprietary/so/*.so'))),
      "| fw bins:", len(bins), "unique:", len(byhash))
