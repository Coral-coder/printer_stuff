#!/usr/bin/env bash
# =============================================================================
# Reassembly pipeline: rebuild every compiled artifact from recovered source.
#
# Layers, in order of fidelity / verifiability:
#   1. Python extras   decompiled/**/*.py     -> *.pyc  (CPython 3.9)   [VERIFIED]
#   2. C helper        reconstructed/chelper/ -> c_helper.so / *.o (ARM)
#   3. Cython wrappers reconstructed/so/*.py  -> *.cpython-39.so  (ARM)
#   4. MCU firmware    (Klipper / RT-Thread source trees)          [DOC ONLY]
#
# Toolchain:
#   - CPython 3.9              (printer runtime; `uv python install 3.9`)
#   - arm-linux-gnueabihf-gcc  (glibc ARM .so: chelper + cython modules)
#   - arm-none-eabi-gcc        (bare-metal Cortex-M firmware)
#   - Cython 0.29.x            (matches the on-device _cython_0_29_21 runtime)
# =============================================================================
set -uo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"

PY39="${PY39:-$(command -v python3.9 || true)}"
ARM_GCC="${ARM_GCC:-arm-linux-gnueabihf-gcc}"
OUT="$ROOT/reassembled"
mkdir -p "$OUT"

step() { printf '\n=== %s ===\n' "$1"; }

# ---- 1. Python extras: recover -> 3.9 .pyc, verified against originals ------
step "1/4  Python extras -> .pyc (CPython 3.9)"
if [ -n "$PY39" ] && "$PY39" -c 'import sys;assert sys.version_info[:2]==(3,9)' 2>/dev/null; then
    REPO_ROOT="$ROOT" "$PY39" tools/reassemble.py
else
    echo "  ! CPython 3.9 not found; set PY39=/path/to/python3.9 (uv python install 3.9)"
fi

# ---- 2. C helper: recovered C -> ARM shared object --------------------------
step "2/4  C helper -> c_helper.so (ARM, arm-linux-gnueabihf)"
if command -v "$ARM_GCC" >/dev/null && [ -d reconstructed/chelper ]; then
    mkdir -p "$OUT/chelper"
    # serial_485 (the Creality-proprietary part) is a standalone TU we can build:
    if [ -f reconstructed/chelper/serial_485_queue.c ]; then
        "$ARM_GCC" -Ireconstructed/chelper -O2 -fPIC -pthread \
            -c reconstructed/chelper/serial_485_queue.c \
            -o "$OUT/chelper/serial_485_queue.o" \
            && echo "  built serial_485_queue.o (ARM)" \
            || echo "  ! serial_485_queue.c needs its companion headers (see BUILD.md)"
    fi
    echo "  (full c_helper.so links the Klipper chelper TUs; see reconstructed/chelper/README.md)"
else
    echo "  ! $ARM_GCC or reconstructed/chelper missing"
fi

# ---- 3. Cython wrappers: recovered .py -> ARM extension module --------------
step "3/4  Cython wrappers -> *.cpython-39.so (ARM)"
if command -v "$ARM_GCC" >/dev/null && [ -d reconstructed/so ]; then
    echo "  cythonize reconstructed/so/*.py with Cython 0.29.x, then cross-compile:"
    echo "    cython -3 <mod>.py -o <mod>.c && $ARM_GCC -shared -fPIC -I<py39-arm-headers> <mod>.c -o <mod>.cpython-39.so"
    echo "  (requires CPython 3.9 ARM dev headers for the target; see BUILD.md)"
else
    echo "  ! toolchain or reconstructed/so missing"
fi

# ---- 4. Firmware: source-tree builds (documented) ---------------------------
step "4/4  MCU firmware (.bin)"
echo "  Klipper MCU images: 'make menuconfig && make' in the Klipper src tree (arm-none-eabi)."
echo "  CFS image: RT-Thread + GD32 BSP build. See reconstructed/fw/README.md."

step "done"
echo "Reassembled artifacts under: $OUT"
