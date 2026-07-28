# v1.0.0 — Bug-fix release

First tagged release of the reconstructed printer firmware. It builds on the
**byte-exact** source reconstruction (all 105 Klipper `extras` modules recompile to
bytecode identical to the shipped `.pyc`) and applies fixes for **every defect** found
in the firmware audit ([`BUG_REPORT.md`](BUG_REPORT.md)).

Cut from the `bugfix` branch. `main` is intentionally left as the faithful,
byte-identical reconstruction; this release is the *patched* variant.

## What's in it

**42 fixes across 31 modules** — the 40 catalogued findings plus 2 extra instances of
the same classes found during fix review (a 6th malformed-JSON string in `replicape`,
and two more `prtouch_v3` None-derefs in `homing`).

### By severity
- **1 critical** — `virtual_sdcard` metadata subprocess: shell-injection RCE via a
  gcode filename/path was executed with `shell=True`. Now uses an argv list (no shell).
- **8 high** — `load_ai` `rm -rf` shell-injection → argv list; `metadata`
  `model_info`/`flush_para` crash guards (KeyError/ValueError that discarded a file's
  metadata); `probe`/`homing` `prtouch_v3` None-guards; `auto_addr_wrapper`/`belt_mdl`
  RS-485 frame bounds checks (IndexError → klippy shutdown); `hx711s` short-buffer guard.
- **15 medium** — `heater_bed` power-cap bounds (bed-power-limit bypass); `dirzctl`
  wait-timeout unit error (dead safety timeout); `gcode_arcs` `max(1, …)` (÷0 on a
  degenerate arc); `bed_mesh` `_sample_direct` flatten; `z_tilt`/QGL lookup guard;
  `prtouch`/`ms3200x` zero-division guards; `tmc2262` COOLCONF `sedn` mask; `input_shaper`
  `old_delay` (unbounded flush-time growth); `fan_feedback` webhook signature;
  `adxl345` shared-memory sizing; `custom_macro`/`pause_resume` crash & reactor-block fixes.
- **16 low** — resource-leak closes (`load_ai` socket, `shaper_calibrate` shm);
  unbounded gcode params (`bl24c16f`); malformed error-protocol JSON strings
  (`gcode_move`, `replicape`); `heater_fan`/`stepper_enable`/`bed_mesh` guards;
  `z_align` datum default; `temperature_mcu` two's-complement sign; `bus` `%c`→`%d`; etc.

The full per-finding detail (code, trigger, impact, fix) is in
[`BUG_REPORT.md`](BUG_REPORT.md).

## Verification

`tools/verify_bugfix.py` (the functionality gate) **passes**:

- all **105** modules compile under CPython 3.9;
- the **73 untouched** modules remain **byte-identical** to the original bytecode — the
  fixes caused no collateral change anywhere else;
- the **31 fixed** modules compile and intentionally differ.

Every fix was additionally reviewed by two independent adversarial passes against the
original bytecode intent — confirming each fix addresses its bug and introduces no new
defect (edge cases, control flow, guard scope all checked). Highlights that were
explicitly validated: the `heater_bed` polyfit guard runs *after* the bed is commanded
off (no thermal hazard); `homing`'s `json.loads` is caught (`JSONDecodeError ⊂
ValueError`); `auto_addr_wrapper`'s bounds guard gates every downstream indexing site.

> **Static verification only.** These fixes are verified to compile, to not regress the
> untouched modules, and to be logically correct on review. They have **not** been run
> on printer hardware. Validate on a test machine before production use.

## Deployment

These are host-side `klippy/extras` modules. To deploy, copy the patched `.py` (or the
recompiled `.pyc`) into `/usr/share/klipper/klippy/extras/` on the printer and restart
klippy:

```bash
# from a checkout of this tag
cp decompiled/shims/*.py  /usr/share/klipper/klippy/extras/
# (Klipper compiles .py on load; or ship reassembled/shims/*.pyc instead)
```

No cross-compilation and no MCU reflash are required — the native artifacts
(Cython `.so`, C helper `.so`, MCU `.bin` firmware) are **unchanged**; none of the
audited defects live there.

## Not included / known limits

- The compiled Cython `*_wrapper` extensions, the C helper, and the MCU firmware are not
  rebuilt here (recovered only as Ghidra C under `reconstructed/`); they carry no
  reported bug and are shipped as-is.
- Cosmetic reconstruction traces (lost comments, some local names) remain; behavior is
  unaffected.
