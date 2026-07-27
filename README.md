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

### Python bytecode → source (`decompiled/`)

All **105** modules were run through the decompiler; **70** reconstruct to valid Python:

| Category | Count | Meaning |
|----------|------:|---------|
| **clean** | 57 | ast-valid, no known defects |
| **flagged** | 13 | ast-valid, but pycdc dropped a called builtin, rendered `None(...)` — see disasm |
| **partial** | 35 | did not fully round-trip; best-effort source + a `# PARTIAL` header |

Every non-clean module also gets a ground-truth bytecode disassembly under
[`decompiled/_disasm/`](decompiled/_disasm) so the exact logic is always recoverable
by hand. Full per-module table: [`decompiled/STATUS.md`](decompiled/STATUS.md);
machine-readable detail: `decompiled/_report.json`.

The 35 partials are blocked by decompiler control-flow bugs that go beyond the opcode
support added here (misplaced `return` inside `try`, generator expressions with a
dropped builtin, exception-variable cleanup that doesn't collapse, a couple of
functions the decompiler bails on entirely). These are documented, not silently
shipped as if complete.

### Native artifacts (not decompilable)

The Cython `.so`, the C helper, and the MCU `.bin` firmware are machine code and cannot
be turned back into faithful source. Their type, size, exported symbols and embedded
identifiers (which document the API surface — command names, class/method names) are
catalogued in [`proprietary/NATIVE_ARTIFACTS.md`](proprietary/NATIVE_ARTIFACTS.md).

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
- [x] 7. Document non-decompilable native artifacts + ship disassembly for imperfect modules.
- [x] 8. Republish to `main`.

## Known limitations (honest caveats)

- Decompiled source is a **faithful reconstruction, not the original file** — comments,
  original formatting, and some local names are lost at compile time.
- **flagged** modules parse but contain `None(...)` where a builtin name was dropped by
  the decompiler; verify against the paired `_disasm/*.txt` before running.
- **partial** modules will not import as-is; use them alongside their disassembly.
- `.so` / `.o` / `.bin` are machine code — only the `.pyc` set is recoverable to source.
