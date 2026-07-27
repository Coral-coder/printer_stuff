#!/usr/bin/env python3
"""Structural analysis of the Cortex-M firmware images: parse the vector table
(initial SP, reset/fault handlers), infer the flash base, and surface build /
chip strings. No decompiler needed — this reads the raw vector table."""
import struct, os, glob, re, sys

ROOT = os.environ.get("REPO_ROOT", os.getcwd())

def analyze(path):
    d = open(path, "rb").read()
    sp, reset = struct.unpack("<II", d[:8])
    vecs = struct.unpack("<%dI" % min(64, len(d)//4), d[:min(256, (len(d)//4)*4)])
    handlers = [v for v in vecs[1:48] if (v & 1) and 0x08000000 <= v < 0x08100000]
    base = (min(handlers) & 0xFFFF0000) if handlers else 0
    strings = subprocess_strings(path)
    ver = [s for s in strings if re.search(r"build|V%d|version|MF0|20\d\d", s)][:6]
    chip = [s for s in strings if re.search(r"gd32|stm32|hk32|apm32|RT-Thread|cortex", s, re.I)][:6]
    return dict(size=len(d), sp=sp, reset=reset, base=base, handlers=len(handlers),
                ver=ver, chip=chip)

def subprocess_strings(path, minlen=6):
    import subprocess
    try:
        out = subprocess.run(["strings", "-n", str(minlen), path],
                             capture_output=True, text=True, timeout=30).stdout
        return out.splitlines()
    except Exception:
        return []

def main():
    seen = {}
    for f in sorted(glob.glob(os.path.join(ROOT, "fw/**/*.bin"), recursive=True)):
        import hashlib
        h = hashlib.sha1(open(f, "rb").read()).hexdigest()[:10]
        if h in seen:
            continue
        seen[h] = f
        a = analyze(f)
        rel = os.path.relpath(f, ROOT)
        print(f"{rel}")
        print(f"   size={a['size']:,} SP=0x{a['sp']:08x} reset=0x{a['reset']:08x} "
              f"flash_base~0x{a['base']:08x} handlers~{a['handlers']}")
        if a['ver']:  print(f"   build/ver: {a['ver']}")
        if a['chip']: print(f"   chip/rtos: {a['chip']}")

if __name__ == "__main__":
    main()
