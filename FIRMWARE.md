# Bug-fixed firmware package (Creality K1 / F-series)

`tools/build_firmware.py` assembles a **deployable, bug-fixed firmware package**
from the `bugfix` branch. Build it (must run under CPython 3.9, the printer
runtime) with:

```bash
FW_VER=v1.0.0 python3.9 tools/build_firmware.py
# output: dist/creality-klipper-bugfix-<ver>/  (+ tar it up to ship)
```

## What this is — and what it is not

This is an **overlay package for the host side**, not a full flashable OS image.
This repository holds only the closed-source `klippy/extras` subset, the
proprietary native `.so`/`.o`, and the prebuilt MCU `.bin` blobs — **not**
Klipper core, the Linux kernel, or the Buildroot rootfs. A full `.img` therefore
cannot be produced from here. What *can* be produced, and is, is the patched
`extras` tree plus the carried-through vendor binaries, applied on top of an
existing install.

**Every audited defect lives in the host Python layer.** So the only thing that
actually changes in this package is the Python bytecode; everything native is
the original vendor binary, unchanged.

## Bundle contents (148 files)

| Path | Count | Origin |
|------|-------|--------|
| `klipper/klippy/extras/*.pyc` — **patched** | 31 | recompiled from bug-fixed source, in the vendor's hash-based `.pyc` format with `/extras/<name>.py` filenames |
| `klipper/klippy/extras/*.pyc` — untouched | 73 | **carried byte-for-byte from the original vendor `.pyc`** |
| `klipper/klippy/extras/*.so` (Cython wrappers) | 8 | original vendor binary, unchanged |
| `klipper/klippy/chelper/{c_helper.so,serial_485_queue.o}` | 2 | original vendor binary, unchanged |
| `mcu-firmware/**/*.bin` (K1, F008, F012, F038, cfs) | 33 | original vendor MCU images, unchanged |
| `MANIFEST.sha256`, `PATCHED.txt`, `install.sh` | 3 | build metadata + installer |

The 31 patched modules are listed in `packaging/PATCHED.txt`; per-file SHA-256s
are in `packaging/MANIFEST.sha256`.

## Verification performed at build time

Run against the vendor originals, all passing:

- 104/104 shipped `.pyc` marshal-load as valid 3.9 bytecode;
- the **73 untouched modules are byte-identical** to the vendor `.pyc`;
- the **31 patched modules differ** from vendor (0 accidentally identical), each
  emitted in the vendor's hash-based format with the on-printer filename;
- the critical fix is present in the shipped bytecode — the shell format-string
  `metadata.py -f '%s'` (the RCE vector) is **absent** from `virtual_sdcard.pyc`,
  replaced by an argv-list `subprocess` call.

`tools/verify_bugfix.py` (run under 3.9) independently confirms the source layer:
all compile, 73 unchanged are opcode-identical, 31 fixed differ, 0 regressions.

## Install (on the printer)

```bash
tar -xzf creality-klipper-bugfix-v1.0.0.tar.gz
cd creality-klipper-bugfix-v1.0.0
sh install.sh          # backs up /usr/share/klipper first; set KLIPPER=... to override
systemctl restart klipper
```

`install.sh` backs up the existing `/usr/share/klipper` before overlaying, verifies
checksums, and prints a one-line rollback command. The MCU `.bin` images under
`mcu-firmware/` are the **original** vendor blobs — flash them from the printer UI
only if a board update is separately required; they carry no code change here.

## Honest limitations

- **Statically verified, not hardware-tested.** Nothing here has been run on a
  printer or even loaded into a live klippy process. Validate on a test machine
  before production.
- **Native `.so` / MCU `.bin` are not rebuilt** — they are the original vendor
  binaries. They can't be faithfully recompiled from reverse-engineered source,
  and they contain none of the audited bugs, so they are carried through as-is.
- This overlay assumes a K1/F-series install whose `klippy/extras` matches the
  reconstructed module set. Diff `MANIFEST.sha256` against your device if unsure.
