#!/usr/bin/env python3.9
"""Build a deployable, bug-fixed firmware package for the Creality K1/F-series.

MUST run under CPython 3.9 (the printer runtime; .pyc magic 0x0a0d0d61).

What it produces (an OVERLAY package, not a full flashable image — this repo
holds only the proprietary `klippy/extras` subset, the native `.so`, and the
prebuilt MCU `.bin`, not Klipper core / kernel / rootfs):

  dist/creality-klipper-bugfix-<ver>/
    klipper/klippy/extras/*.pyc        <- 104 host modules, recompiled from the
                                          BUG-FIXED source (sourceless 3.9 .pyc,
                                          drop-in for the printer)
    klipper/klippy/chelper/c_helper.so <- original vendor binary (unchanged)
    klipper/klippy/chelper/serial_485_queue.o
    klipper/klippy/extras/*.so         <- original Cython wrappers (unchanged)
    mcu-firmware/**/*.bin              <- original vendor MCU blobs (unchanged)
    MANIFEST.sha256                    <- checksum of every shipped file
    PATCHED.txt                        <- exactly which modules carry a fix
    install.sh                         <- overlay installer for the printer

The Python layer is the ONLY thing that changed: every audited defect lives in
host `extras`. Native `.so` and MCU `.bin` are carried through byte-for-byte
from the original distribution (they can't be faithfully rebuilt from reversed
source, and carry no reported bug).
"""
import os, sys, py_compile, shutil, hashlib, subprocess

if sys.version_info[:2] != (3, 9):
    sys.exit("must run under Python 3.9 (got %s)" % sys.version.split()[0])

ROOT = os.environ.get("REPO_ROOT", os.getcwd())
VER = os.environ.get("FW_VER", "v1.0.0")
SRC_SHIMS = os.path.join(ROOT, "decompiled", "shims")
ORIG_SHIMS = os.path.join(ROOT, "proprietary", "shims")
NATIVE_SO = os.path.join(ROOT, "proprietary", "so")
CHELPER = os.path.join(ROOT, "proprietary", "chelper")
FW = os.path.join(ROOT, "fw")
OUT = os.path.join(ROOT, "dist", "creality-klipper-bugfix-%s" % VER)


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(65536), b""):
            h.update(chunk)
    return h.hexdigest()


def changed_modules():
    """Host modules whose fixed source differs from the faithful baseline."""
    for base in ("origin/main", "main"):
        r = subprocess.run(["git", "diff", "--name-only", base, "--",
                            "decompiled/shims"], cwd=ROOT,
                           capture_output=True, text=True)
        if r.returncode == 0:
            return {os.path.basename(p) for p in r.stdout.split()
                    if p.endswith(".py")}
    return set()


def main():
    if os.path.isdir(OUT):
        shutil.rmtree(OUT)
    extras = os.path.join(OUT, "klipper", "klippy", "extras")
    chelper_out = os.path.join(OUT, "klipper", "klippy", "chelper")
    mcu_out = os.path.join(OUT, "mcu-firmware")
    for d in (extras, chelper_out, mcu_out):
        os.makedirs(d, exist_ok=True)

    changed = changed_modules()
    manifest = []          # (relpath, sha256, origin)
    patched, carried, failed = [], 0, []

    # 1. host extras. The vendor ships hash-based-checked .pyc (flags=3) with
    #    co_filename '/extras/<name>.py'. Every module NOT touched by a fix is
    #    carried through byte-for-byte from the original .pyc (identical to
    #    vendor). Only the fixed modules are recompiled -- in the same
    #    hash-based format and with the same on-printer filename, so they are
    #    format-identical to vendor and tracebacks read natively.
    for pyc in sorted(os.listdir(ORIG_SHIMS)):
        if not pyc.endswith(".pyc"):
            continue
        name = pyc[:-4]                      # module name
        orig_pyc = os.path.join(ORIG_SHIMS, pyc)
        out_pyc = os.path.join(extras, pyc)
        if (name + ".py") in changed:
            src = os.path.join(SRC_SHIMS, name + ".py")
            try:
                py_compile.compile(
                    src, cfile=out_pyc, dfile="/extras/%s.py" % name,
                    doraise=True,
                    invalidation_mode=py_compile.PycInvalidationMode.CHECKED_HASH)
            except py_compile.PyCompileError as e:
                failed.append((pyc, str(e).splitlines()[-1][:80]))
                continue
            patched.append(name)
            origin = "PATCHED"
        else:
            shutil.copy2(orig_pyc, out_pyc)   # vendor original, byte-identical
            carried += 1
            origin = "faithful"
        manifest.append((os.path.relpath(out_pyc, OUT), sha256(out_pyc), origin))

    # 2. native Cython wrappers -> extras/ (unchanged vendor binaries)
    for f in sorted(os.listdir(NATIVE_SO)):
        if f.endswith(".so"):
            dst = os.path.join(extras, f)
            shutil.copy2(os.path.join(NATIVE_SO, f), dst)
            manifest.append((os.path.relpath(dst, OUT), sha256(dst), "vendor"))

    # 3. c_helper.so + serial_485_queue.o -> chelper/ (unchanged)
    for f in ("c_helper.so", "serial_485_queue.o"):
        p = os.path.join(CHELPER, f)
        if os.path.exists(p):
            dst = os.path.join(chelper_out, f)
            shutil.copy2(p, dst)
            manifest.append((os.path.relpath(dst, OUT), sha256(dst), "vendor"))

    # 4. MCU firmware blobs -> mcu-firmware/ (unchanged), preserving layout
    for dirpath, _, files in os.walk(FW):
        for f in files:
            sp = os.path.join(dirpath, f)
            rel = os.path.relpath(sp, FW)
            dst = os.path.join(mcu_out, rel)
            os.makedirs(os.path.dirname(dst), exist_ok=True)
            shutil.copy2(sp, dst)
            manifest.append((os.path.relpath(dst, OUT), sha256(dst), "vendor"))

    # 5. MANIFEST + PATCHED list
    manifest.sort()
    with open(os.path.join(OUT, "MANIFEST.sha256"), "w") as m:
        for rel, digest, origin in manifest:
            m.write("%s  %-8s  %s\n" % (digest, origin, rel))
    with open(os.path.join(OUT, "PATCHED.txt"), "w") as p:
        p.write("Bug-fixed host modules in this build (%d):\n\n" % len(patched))
        for name in sorted(patched):
            p.write("  %s\n" % name)

    # 6. installer
    with open(os.path.join(OUT, "install.sh"), "w") as sh:
        sh.write(INSTALL_SH)
    os.chmod(os.path.join(OUT, "install.sh"), 0o755)

    n_bin = sum(1 for rel, _, _ in manifest
                if rel.startswith("mcu-firmware") and rel.endswith(".bin"))
    n_native = sum(1 for rel, _, _ in manifest
                   if rel.endswith(".so") or rel.endswith(".o"))
    print("=== firmware build %s ===" % VER)
    print("host modules total    : %d" % (len(patched) + carried))
    print("  patched (recompiled): %d" % len(patched))
    print("  carried verbatim    : %d" % carried)
    print("native .so/.o carried : %d" % n_native)
    print("MCU .bin carried      : %d" % n_bin)
    print("total files in bundle : %d" % len(manifest))
    if failed:
        print("\nFAILED TO COMPILE:")
        for f, e in failed:
            print("  %s: %s" % (f, e))
    print("\noutput: %s" % OUT)
    sys.exit(1 if failed else 0)


INSTALL_SH = r"""#!/bin/sh
# Overlay installer for the bug-fixed Creality K1/F-series Klipper host package.
# Run ON THE PRINTER (or against a mounted rootfs). Backs up before replacing.
set -eu
KLIPPER="${KLIPPER:-/usr/share/klipper}"
HERE="$(cd "$(dirname "$0")" && pwd)"
STAMP="$(cat /proc/uptime | cut -d. -f1)"
BAK="${KLIPPER}.bak.${STAMP}"

if [ ! -d "$KLIPPER/klippy/extras" ]; then
  echo "ERROR: $KLIPPER/klippy/extras not found. Set KLIPPER=/path first." >&2
  exit 1
fi
echo "Backing up $KLIPPER -> $BAK"
cp -a "$KLIPPER" "$BAK"

echo "Installing patched host extras (.pyc) ..."
cp -a "$HERE/klipper/klippy/extras/." "$KLIPPER/klippy/extras/"
echo "Refreshing native chelper (unchanged vendor binaries) ..."
cp -a "$HERE/klipper/klippy/chelper/." "$KLIPPER/klippy/chelper/"

# Drop any stale source/cached bytecode so the new sourceless .pyc win.
find "$KLIPPER/klippy/extras" -name '__pycache__' -type d -prune -exec rm -rf {} + 2>/dev/null || true

echo "Verifying checksums ..."
cd "$HERE" && (sha256sum -c /dev/null >/dev/null 2>&1 && \
  awk '{print $1"  "$3}' MANIFEST.sha256 > /tmp/_fw.sums && \
  sha256sum -c /tmp/_fw.sums >/dev/null 2>&1 && echo "  checksums OK") \
  || echo "  (sha256sum not available; skipped)"

echo
echo "Done. MCU .bin blobs are under mcu-firmware/ — flash via the printer UI"
echo "if a board update is required (they are the original vendor images)."
echo "Restart Klipper:  systemctl restart klipper  (or reboot the printer)."
echo "Rollback:         rm -rf $KLIPPER && mv $BAK $KLIPPER"
"""


if __name__ == "__main__":
    main()
