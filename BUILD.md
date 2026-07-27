# Reassembly pipeline — rebuilding the compiled artifacts from source

This repo recovers the closed-source parts of the distribution to source and then
**rebuilds** them into drop-in replacements. Run the whole thing with:

```bash
tools/rebuild.sh
```

Artifacts land in `reassembled/`. The layers, from most- to least-verifiable:

| Layer | Source | Rebuilt artifact | Tool | Status |
|-------|--------|------------------|------|--------|
| Python `extras` | `decompiled/**/*.py` | `*.pyc` | CPython **3.9** | **verified** vs original bytecode |
| C helper | `reconstructed/chelper/*.c/.h` | `c_helper.so`, `*.o` | `arm-linux-gnueabihf-gcc` | proprietary `serial_485` rebuilds; Klipper TUs are upstream GPL |
| Cython wrappers | `reconstructed/so/*.py` | `*.cpython-39.so` | Cython 0.29.x + ARM gcc | recovered as C (Ghidra) + Python API scaffolds |
| MCU firmware | Klipper / RT-Thread trees | `*.bin` | `arm-none-eabi-gcc` | documented (needs full vendor tree) |

## Toolchain

- **CPython 3.9** — the printer runtime (`.pyc` magic `0x0a0d0d61`). `uv python install 3.9`.
- **arm-linux-gnueabihf-gcc** — glibc ARM, for `c_helper.so` and the Cython `.cpython-39.so`
  (they are `ELF 32-bit ARM` shared objects). `apt install gcc-arm-linux-gnueabihf`.
- **arm-none-eabi-gcc** — bare-metal Cortex-M, for the firmware. `apt install gcc-arm-none-eabi`.
- **Cython 0.29.x** — the on-device modules were built with `_cython_0_29_21`.

## 1. Python extras (verified drop-in)

`tools/reassemble.py` (run under 3.9) recompiles each recovered `.py`, writes the `.pyc`
with the correct 3.9 magic, and **diffs its code objects against the original bytecode**.
A ≥99.5% opcode match is a proof the source round-trips. See
[`reassembled/FAITHFULNESS.md`](reassembled/FAITHFULNESS.md). These `.pyc` drop straight
into `klippy/extras/` on the printer.

## 2. C helper (`c_helper.so`)

`c_helper.so` is Klipper's open-source `chelper` (kinematics, `itersolve`, `trapq`,
`serialqueue`, `pollreactor`, input shaper) **plus** Creality's proprietary
`serial_485` / `msgblock_485`. The exported-symbol map is in
`reconstructed/chelper/README.md`.

- **Klipper TUs** (`itersolve.c`, `trapq.c`, `kin_*.c`, …): the source is upstream GPL
  Klipper `klippy/chelper/`. Build with the stock chelper `__init__.py` compile line
  (`gcc -shared -fPIC -O2 ...`), retargeted with `arm-linux-gnueabihf-gcc`.
- **`serial_485_queue.c`** (Creality): recovered from the unstripped `serial_485_queue.o`
  via Ghidra + the shipped `serial_485_queue.h`; rebuilds standalone (see `rebuild.sh`).

## 3. Cython wrappers (`*.cpython-39.so`)

These are `klippy/extras/*_wrapper.py` compiled to C by Cython 0.29.21, then to ARM.
Recovered two ways (both under `reconstructed/so/`):
- `*.c` — the faithful **Ghidra C decompilation** of the machine code (functionally
  complete, but CPython-C-API level, not maintainable Python).
- `*.py` — a **Python API scaffold** reconstructed from the embedded class / method /
  gcode-command / config-param symbols, matching the loader stubs in `proprietary/shims/`.

To rebuild: `cython -3 <mod>.py` → `<mod>.c` → cross-compile against the CPython 3.9 ARM
headers into `<mod>.cpython-39.so`. Faithful behaviour requires completing the scaffold
bodies from the Ghidra C — machine-code → clean Python is not fully automatable.

## 4. MCU firmware (`fw/**/*.bin`)

Stripped ARM Cortex-M images (GD32). The `mcu*`/`noz*`/`bed*` images are **Klipper MCU
firmware** — rebuild from the Klipper `src/` tree with `make menuconfig && make`
(`arm-none-eabi`). The `cfs*` image is an **RT-Thread** application (GD32 BSP). Ghidra C
decompilations are in `reconstructed/fw/` for reference; a byte-identical rebuild needs
the exact vendor source tree and config, which is not shipped here.
