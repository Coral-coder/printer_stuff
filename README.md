# printer_stuff — source reconstruction

This repository received a drop of a **Creality-style Klipper firmware distribution**
(printer models F008 / F012 / F038 / K1, plus a CFS unit). Most of the "brains" were
shipped as **compiled artifacts** rather than source:

- Klipper `extras/` modules compiled to **Python 3.9 bytecode** (`proprietary/shims/*.pyc`)
- Cython-compiled Python C-extensions (`proprietary/so/*.cpython-39.so`)
- Compiled C (`proprietary/chelper/*.so`, `*.o`)
- Microcontroller firmware blobs (`fw/**/*.bin`)

The task for this branch is to **disassemble those compiled artifacts back to source
code and republish** the recovered source. This document tracks live progress so
downstream can see exactly what is done, what is in flight, and what is not
recoverable.

> Status is regenerated from `decompiled/_report.json` on each push.

## Payload inventory (what was pushed to `main`)

| Area | Contents | Nature | Recoverable to source? |
|------|----------|--------|------------------------|
| `config/**/*.cfg` | Klipper configs for each model | already plain text | n/a (already source) |
| `fw/**/*.bin` | MCU firmware (belt/motor/nozzle/rfid/bed/cfs/mcu) | stripped microcontroller binaries | no (not source-level) |
| `proprietary/shims/*.pyc` | 105 Klipper `extras` modules | **Python 3.9 bytecode** | **yes — primary target** |
| `proprietary/shims/*.py` | `prtouch*`, and loader stubs | already source | n/a |
| `proprietary/so/*.cpython-39.so` | Cython extension modules | native machine code | no (only stubs/symbols) |
| `proprietary/chelper/*.so`, `*.o` | compiled C helper | native machine code | header already present |

The `.pyc` headers were lightly tampered (bogus source-size field, year-2028 compile
timestamps) but the bytecode itself is standard, un-remapped CPython 3.9.

## Progress by step

- [x] **1. Monitor the empty repo for a push** — detected content on `main` (commit `61ebddc`).
- [x] **2. Identify the payload** — Klipper 3.9 `.pyc`, Cython `.so`, C, and MCU `.bin`.
- [x] **3. Stand up a 3.9-capable decompiler** — `decompyle3`/`uncompyle6` don't support 3.9
      (no p39 grammar); built **pycdc (Decompyle++)** from source as the engine.
- [x] **4. First-pass decompile of all 105 `.pyc`** — into `decompiled/` mirroring the layout.
- [x] **5. Repair systematic pycdc artifacts (pure post-processing)**:
  - keyword args `f(a, b, **('k1','k2'))` → `f(a, k1=b, k2=c)`
  - relative imports `from  import x` → `from . import x`
  - comprehensions `(lambda .0=None: [...])(it)` → real `[... for ... in it]`
- [ ] **6. Patch pycdc for missing 3.9 opcodes** *(in progress)* — the remaining failures
      are blocked by opcodes pycdc's ASTree doesn't implement for 3.9:
      `JUMP_IF_NOT_EXC_MATCH` (`try/except`), `MAP_ADD` (dict comprehensions),
      `DICT_MERGE`, `CALL_FUNCTION_EX`, `LOAD_ASSERTION_ERROR`, `LIST_TO_TUPLE`.
- [ ] **7. Document non-decompilable native artifacts** (`.so` / `.o` / `.bin`) with
      symbol/strings summaries and honest recoverability notes.
- [ ] **8. Final republish** with the complete recovered source tree.

## Decompilation results (current)

**57 / 105** modules recovered to syntactically valid Python (`ast.parse`-clean) so far.
The remaining **48** are blocked as follows and are the subject of step 6:

| Blocker | Files | Notes |
|---------|-------|-------|
| `try/except` (`JUMP_IF_NOT_EXC_MATCH`, incl. dropped-handler renders) | ~41 | pycdc has no 3.9 `try/except` support |
| dict comprehension (`MAP_ADD`) | 5 | modelled on existing list/set-comp handling |
| `DICT_MERGE` / `CALL_FUNCTION_EX` / misc | ~2 | additive ASTree cases |

Per-file machine-readable detail lives in [`decompiled/_report.json`](decompiled/_report.json).

### Known limitations (honest caveats)

- Decompiled source is a **faithful reconstruction, not the original file** — comments,
  original formatting, and some local variable names are not preserved by compilation.
- pycdc occasionally drops a called name, rendering `max(a, b)` as `None(a, b)`; these
  spots are flagged in the report (`none_calls`) and cross-checkable against
  `pycdas` disassembly. They parse but must be reviewed before running.
- `.so` / `.o` / `.bin` artifacts are native code; only the `.pyc` set is genuinely
  recoverable to source.

## Reproducing

The decompiler is built from [zrax/pycdc](https://github.com/zrax/pycdc); the
post-processing/repair pipeline is applied on top. Full method and the exact repair
transforms are described above and in the pipeline script kept with this branch.
