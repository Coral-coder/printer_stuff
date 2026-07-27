# printer_stuff — source reconstruction

This repository received a drop of a **Creality-style Klipper firmware distribution**
(printer models F008 / F012 / F038 / K1, plus a CFS unit). Most of the "brains" were
shipped as **compiled artifacts** rather than source:

- Klipper `extras/` modules compiled to **Python 3.9 bytecode** (`proprietary/shims/*.pyc`)
- Cython-compiled Python C-extensions (`proprietary/so/*.cpython-39.so`)
- Compiled C (`proprietary/chelper/*.so`, `*.o`)
- Microcontroller firmware blobs (`fw/**/*.bin`)

The task for this branch is to **disassemble those compiled artifacts back to source
code and republish** the recovered source. This document tracks status so downstream
can see exactly what is done and what is not recoverable.

> Regenerate everything with `tools/decompile.py` (Python) + `tools/pycdc-3.9-opcodes.patch`
> (the decompiler patch). Per-module status: [`decompiled/STATUS.md`](decompiled/STATUS.md).

## Payload inventory (what was pushed to `main`)

| Area | Contents | Nature | Recoverable to source? |
|------|----------|--------|------------------------|
| `config/**/*.cfg` | Klipper configs per model | already plain text | n/a (already source) |
| `fw/**/*.bin` | MCU firmware (belt/motor/nozzle/rfid/bed/cfs/mcu) | stripped ARM Cortex-M binaries | no |
| `proprietary/shims/*.pyc` | 105 Klipper `extras` modules | **Python 3.9 bytecode** | **yes — primary target** |
| `proprietary/shims/*.py` | `prtouch*`, loader stubs | already source | n/a |
| `proprietary/so/*.cpython-39.so` | Cython extension modules | ARM machine code | no (API surface documented) |
| `proprietary/chelper/*.so`, `*.o` | compiled C helper | ARM machine code | header already present |

The `.pyc` headers were lightly tampered (bogus source-size field, year-2028 compile
timestamps) but the bytecode itself is standard, un-remapped CPython 3.9.

## Results

### Python bytecode → source + verification

All **105** modules are decompiled into `decompiled/` and then put through the
**reassembly pipeline** (`tools/reassemble.py`): each recovered `.py` is recompiled
to a `.pyc` under **CPython 3.9** (the printer's runtime — magic matches exactly) and
its code objects are compared opcode-for-opcode against the *original* bytecode. That
bytecode-match ratio is the authoritative correctness gate — a high match is a *proof*
that the recovered source round-trips to the same program.

Two gates measure this (`tools/reassemble.py` = tolerant ratio;
`tools/bcdiff.py` / `tools/verify_module.py` = strict, byte-exact functional
match ignoring only code-object metadata):

| Gate | Count | Meaning |
|------|------:|---------|
| **byte-exact faithful** (`bcdiff`) | **105 / 105** | recompiles to *identical* bytecode — provably drop-in |
| ≥99.5% near-faithful (`reassemble`) | 105 | (superset — all are byte-exact) |
| recompiles at all (`ast_ok`) | 105 | valid 3.9 source |
| won't recompile | 0 | — |

**Every one of the 105 modules is now byte-exact faithful** — each recovered
`.py` recompiles under CPython 3.9 to bytecode *identical* to the shipped
original, opcode-for-opcode, constant-for-constant. This is a machine-checkable
proof that the reconstructed source is a true drop-in replacement, not an
approximation. The count climbed from 13 → 105 over this reconstruction pass via
decompiler fixes plus disassembly-guided per-module repair (see the `pycdc` and
`Byte-exact repair` commits). Full tables:
[`reassembled/FAITHFULNESS.md`](reassembled/FAITHFULNESS.md),
[`decompiled/STATUS.md`](decompiled/STATUS.md).

**How this was verified (honest note):** pycdc — even patched — has *silent*
correctness bugs on this obfuscated 3.9 bytecode: dropped operands rendered as
`None`, blocks mis-nested into `except:`, inverted boolean guards, misplaced
`return`s, dropped merge-point code, and outright segfaults on two modules. Rather
than trust "it parses," every module was driven to a **byte-exact** match against
its original bytecode with `tools/verify_module.py` (compile under 3.9, diff each
code object) as the gate — so any residual decompiler error is caught and repaired
by hand against the ground-truth disassembly (`tools/disasm.py`). A module is only
marked done when `verify_module.py` exits 0.

Upstream Klipper source was evaluated as a shortcut for the stock modules but rejected:
the printer runs an older fork (upstream `master` matched the original bytecode only
~50–66%), so the on-device decompilation is the more faithful basis.

### Compiled binaries → source (`reconstructed/`)

The Cython `.so`, the C helper, and the MCU `.bin` firmware are ARM machine code. They
were disassembled and **decompiled to C with Ghidra** (headless), giving genuine,
functionally-faithful recovered source under `reconstructed/`:

- [`reconstructed/chelper/`](reconstructed/chelper) — `c_helper.so` = open-source Klipper
  `chelper` (symbol-mapped to its upstream GPL translation units) **+** Creality's
  proprietary `serial_485`, recovered from the unstripped `serial_485_queue.o` and paired
  with the shipped header.
- [`reconstructed/so/`](reconstructed/so) — the 7 Cython `klippy/extras/*_wrapper.py`
  modules (box / filament_rack / motor_control / serial_485 / prtouch v1-v3) plus the C++
  `mymovie`, each decompiled to C. Faithful but C-API-level (see fidelity note).
- [`reconstructed/fw/`](reconstructed/fw) — the GD32 Cortex-M firmware (Klipper MCU images
  + the RT-Thread CFS app), decompiled to C, with vector-table analysis
  (`tools/fw_analyze.py`).

Symbol/identifier inventory: [`proprietary/NATIVE_ARTIFACTS.md`](proprietary/NATIVE_ARTIFACTS.md).

**Fidelity ceiling (honest):** decompiling *stripped* machine code yields faithful but
unlabeled C (`FUN_...` names, no types) — the Ghidra output is the ground truth of what
each binary does, not clean maintainable source. Where the artifact was built from
open-source origins (Klipper `chelper`, Klipper MCU firmware, RT-Thread), those upstream
trees are identified so a byte-faithful rebuild is possible; the genuinely proprietary
parts (Cython wrappers, `serial_485`) are recovered as decompiled C.

### Reassembly

`tools/rebuild.sh` + [`BUILD.md`](BUILD.md) rebuild every layer from the recovered source:
Python → 3.9 `.pyc` (verified against originals), C → ARM `.so`/`.o`
(`arm-linux-gnueabihf-gcc`), Cython `.py` → `.cpython-39.so`, and firmware from the
identified source trees (`arm-none-eabi-gcc`).

## Method

1. `decompyle3` / `uncompyle6` ship no Python-3.9 grammar, so the engine is
   **pycdc (Decompyle++)**, built from source.
2. pycdc's ASTree lacked several 3.9 opcodes; `tools/pycdc-3.9-opcodes.patch`
   (against pycdc `b428976`) adds them:
   - `MAP_ADD` (dict comprehensions) + `<dictcomp>`/`<setcomp>` recognition
   - `DICT_MERGE` / `DICT_UPDATE`, `CALL_FUNCTION_EX` (`f(*a, **kw)`), `LIST_TO_TUPLE`
   - `JUMP_IF_NOT_EXC_MATCH` (3.9 `try/except`), plus a `SETUP_FINALLY` look-ahead so
     3.9 try/except is not mis-rendered as `try/finally` (no exception table before 3.11)
3. `tools/decompile.py` runs pycdc over every `.pyc` and applies mechanically-safe,
   `ast`-validated repairs to pycdc's known rendering quirks:
   - `f(a, b, **('k1','k2'))` → `f(a, k1=b, k2=c)` (keyword-name tuples)
   - `from  import x` → `from . import x` (relative imports)
   - `(lambda .0=None: [...])(it)` → `[... for ... in it]` (comprehensions)
4. **Dual-engine safety net:** the try/except patch can desync pycdc's block
   stack on a couple of very complex modules and truncate them. So each `.pyc`
   is decompiled by *both* the patched and the pristine pycdc, keeping whichever
   recovers more. This guarantees no module is ever worse than stock pycdc
   (verified: 0 regressions, 26 modules more complete than the previous pass).
   Set `PYCDC_ORIG` to a stock pycdc binary to enable the fallback (2 modules
   use it: `metadata`, `replicape`).

## Progress by step

- [x] 1. Monitor the empty repo — detected content on `main` (`61ebddc`).
- [x] 2. Identify the payload (Klipper 3.9 `.pyc`, Cython `.so`, C, MCU `.bin`).
- [x] 3. Stand up a 3.9-capable decompiler (built + patched pycdc).
- [x] 4. Decompile all 105 `.pyc` into a mirrored `decompiled/` tree.
- [x] 5. Repair systematic pycdc artifacts (kwargs, imports, comprehensions).
- [x] 6. Patch pycdc for missing 3.9 opcodes (dict-comp, call-ex, **try/except**, …).
- [x] 7. **Reassembly pipeline** (`tools/reassemble.py`) — recompile under CPython 3.9,
      verify against original bytecode; drop-in `.pyc` written to `reassembled/`.
- [x] 8. Document native artifacts + ship disassembly for imperfect modules.
- [x] 9. **Drive every Python module to byte-exact faithful — 105 / 105 complete.**
- [x] 10. Reconstruct the compiled binaries to source (Cython `.so`, C helper, firmware) + rebuild rules.
- [x] 11. Republish to `main` (incremental checkpoints).

## Known limitations (honest caveats)

- All **105 Python modules** recompile to byte-identical CPython 3.9 bytecode — they
  are provably drop-in. What is *not* recoverable is cosmetic only: original comments,
  formatting, and a few local variable names are erased at compile time and cannot be
  reconstructed from bytecode. Behavior is identical.
- `.so` / `.o` / `.bin` are machine code (Cython extensions, C helper, MCU firmware).
  These are decompiled to faithful but unlabeled **C** with Ghidra under
  `reconstructed/` (the honest ceiling for stripped machine code); the Python `.pyc`
  set is the part recoverable to exact source, and it is 100% complete.
