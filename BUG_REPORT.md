# Firmware bug report — reconstructed Klipper source

This report catalogs genuine defects found in the reconstructed printer firmware
under `decompiled/shims/`. Because that source is a **byte-exact** reconstruction
(every module recompiles to bytecode identical to the shipped `.pyc`), **every bug
below is a real bug in the firmware that shipped on the printer**, not a
decompilation artifact. Findings in modules that were reconstructed from a
partial/segfaulted decompile were additionally cross-checked against the
ground-truth bytecode disassembly (`decompiled/_disasm/*.txt`).

**Scope.** Stock upstream Klipper code is largely correct and was used as a
reference; the defects concentrate in Creality's proprietary additions and their
modifications to stock files. Thermal-safety math (PID, bang-bang, thermistor
Steinhart-Hart, `verify_heater` fault detection) and the TMC CRC/current math were
audited specifically and found **correct**.

**Method.** Eight independent reviewers read all 104 modules; each finding was
traced to confirm reachability, then the load-bearing critical/high items were
re-verified by hand against the source and the shipped `config/*/printer.cfg`.

**Severity key.** `critical` = remote code execution / safety / can crash klippy on
a normal path on the shipped hardware. `high` = crash or clearly wrong behavior on a
reachable path (some are *latent* on the stock config — noted per-item). `medium` =
wrong behavior on an edge/error path or an operator-triggered hazard. `low` = minor
or diagnostic-only.

## Summary

| # | Severity | Location | Class | One-line |
|--:|----------|----------|-------|----------|
| 1 | **critical** | `virtual_sdcard.py:1051` | security (RCE) | shell-injection via gcode filename/path (`shell=True`) on every print start |
| 2 | high | `load_ai.py:126` | security | `'rm -rf ' + file_path` run with `shell=True` |
| 3 | high | `metadata.py:1214` | crash | `metadata['model_info']` KeyError aborts all metadata for a file |
| 4 | high | `metadata.py:420` | crash | unguarded `int()` on `flush_volumes_matrix` (Orca/Bambu decimals) |
| 5 | high | `auto_addr_wrapper.py:279,350` | crash | RS-485 ack for a CL/BT motor indexes a 1-element table → klippy shutdown |
| 6 | high | `auto_addr_wrapper.py:359` | crash | short/garbled 485 frame → IndexError in reactor callback |
| 7 | high | `hx711s.py:184` | crash | `read_base` trims 4 extrema from a too-short buffer (`base_count` 10–17) |
| 8 | high *(latent)* | `probe.py:140` | crash | `target_z` used unbound when `prtouch_v3` absent |
| 9 | high *(latent)* | `homing.py:58` | crash | `self.prtouch_v3.…` dereferenced right after being set to `None` |
| 10 | medium | `heater_bed.py:69` | safety/logic | `BED_HEADER_SET_HEARER_POWER_MAX` has no bounds → bypasses 220 V power cap |
| 11 | medium | `heater_bed.py:113` | crash | `np.polyfit` on empty/degenerate vector during power calibration |
| 12 | medium | `dirzctl.py:84` | logic | wait timeout ~10¹² × too large (exponent sign) → safety timeout dead |
| 13 | medium | `gcode_arcs.py:107` | numeric | `ZeroDivisionError` on a degenerate/collinear `G2`/`G3` |
| 14 | medium | `bed_mesh.py:923` | crash | `_sample_direct` assigns a 2-D matrix into a flat array (`mesh_pps: 0,0`) |
| 15 | medium | `z_tilt.py:39` | crash | shared `ZAdjustHelper` hard-requires `[z_tilt]` → crashes QUAD_GANTRY_LEVEL |
| 16 | medium | `prtouch.py:430,444,597` | numeric | normalize divides by `(max-min)` with no zero guard (flat sensor) |
| 17 | medium | `belt_mdl.py:507` | crash | reads `rec_data[4]` after only a `len < 3` check |
| 18 | medium | `ms3200x.py:405` | numeric | `MS32008_MOVE/SET PPS=0` → `ZeroDivisionError` (no `minval`) |
| 19 | medium | `homing.py:167` | crash | `json.loads` on a non-JSON error string on the homing-failure path |
| 20 | medium | `custom_macro.py:59` | crash | `M104 S%d` on `None` temp + `time.sleep` busy-wait blocks the reactor |
| 21 | medium | `pause_resume.py:222` | crash | `RESUME` does unguarded `json.loads` of the (post-power-loss) recovery file |
| 22 | medium | `tmc2262.py:442` | logic | COOLCONF `sedn` mask overlaps `seimin` (wrong CoolStep current) |
| 23 | medium | `input_shaper.py:148` | logic | `old_delay` never updated → toolhead flush-time list grows unbounded |
| 24 | medium | `fan_feedback.py:72` | crash | webhook callback wrong signature → `get_cx_fan_status` endpoint always fails |
| 25 | medium | `adxl345.py:124` | numeric | resonance shared-memory buffer undersized by the 4-byte header |
| 26 | low | `virtual_sdcard.py:1069` | logic | call passes nonexistent `get_layer_count=` kwarg (TypeError, swallowed) |
| 27 | low | `virtual_sdcard.py:94` | numeric | `1.0 / frame` with user `frame` (timelapse) → `ZeroDivisionError` |
| 28 | low | `load_ai.py:448` | resource-leak | HTTP connection not closed on the network-error path |
| 29 | low | `load_ai.py:383` | logic | empty subprocess stdout misread as a 10 s "timeout" |
| 30 | low | `heater_fan.py:40` | crash | unconditional `heater_bed` lookup (unused) crashes on bedless configs |
| 31 | low | `stepper_enable.py:105` | crash | `motor_off` looks up `virtual_sdcard` with no default |
| 32 | low | `bed_mesh.py:155` | crash | `update_mesh` webhook dereferences `self.z_mesh` with no `None` check |
| 33 | low | `z_align.py:305` | logic | `read_real_zmax` falls back to `0` (not the safe default) on missing key |
| 34 | low | `prtouch_v2.py:11` | crash | `vrt` unbound when `pr_version` is 0 or 3–100 (parser allows it) |
| 35 | low | `bl24c16f.py:126` | logic | `EEPROM_READ` reads then never prints the result |
| 36 | low | `bl24c16f.py:96,147` | numeric | inclusive `maxval=0x100000000` truncates 2³² to 0 |
| 37 | low | `temperature_mcu.py:129` | numeric | SAMD INT1V two's-complement uses `256-val` instead of `val-256` |
| 38 | low | `shaper_calibrate.py:278` | resource-leak | `SharedMemory.unlink()` without `close()` |
| 39 | low | `bus.py:252` | logic | `MCU_bus_digital_out` init uses `%c` instead of `%d` |
| 40 | low | `gcode_move.py:302…`, `replicape.py:21…` | logic | malformed JSON in error-protocol strings (systemic — see below) |

---

## Systemic patterns

Several defects are instances of the same root mistake — worth fixing as a class:

- **Optional `prtouch_v3` dereferenced unconditionally** (#8 `probe.py:140`, #9
  `homing.py:58`). The code sets `self.prtouch_v3 = <obj> if present else None` and
  then immediately uses it without a guard, even though later code guards it. **On
  the shipped printers this is latent** — all eight `config/*/printer.cfg` load
  `[prtouch_v3]`, so the object is always present — but it makes homing/probing crash
  on any config without it (BLTouch/inductive, `prtouch_v2`, `manual_stepper` homing).
- **Unvalidated RS-485 frames** (#5, #6 `auto_addr_wrapper`, #17 `belt_mdl.py:507`).
  Bus responses are indexed (`ret[4]`, `data[0..2]`, `dev_type-1`) after only a
  `None`/`len<3` check. A short, corrupted, or unexpected-device frame raises
  `IndexError` inside a reactor callback → **klippy shutdown mid-print**.
- **G-code command parameters accepted without bounds** (#10 `heater_bed` power, #18
  `ms3200x` PPS, #36 `bl24c16f` VAL). Values that the config path validates
  (`minval`/`maxval`) are read raw from the command, enabling divide-by-zero,
  truncation, or (for the bed power cap) a safety-limit bypass.
- **Malformed JSON in the error-code protocol** (#40). Many Creality error strings are
  meant to be machine-parseable `{"code","msg","values"}` JSON for the UI, but use a
  `:` where a `,` is required (`"code":"key272": "msg"`), or drop a comma, or double a
  quote. Affected: `gcode_move.py:302,305,339,342,797,816`, `homing.py:167` (built
  string), `replicape.py:21,47,54,102,104`. The UI's `JSON.parse` fails → the user
  sees a garbled/untranslated error. (Reporting-only; the underlying error still fires.)
- **`shell=True` with interpolated paths** (#1 `virtual_sdcard`, #2 `load_ai`). Building
  a shell command by string-formatting a filename/path is injectable.

---

## Detailed findings

### 1. `virtual_sdcard.py:1051` — shell-injection RCE via gcode filename/path — **critical**
```python
cmd = "%s /usr/share/klipper/klippy/extras/metadata.py -f '%s' -p %s" % (python_env, filename, filepath)
result = json.loads(check_output(cmd, shell=True).decode('utf-8'))
```
`get_print_file_metadata()` builds a shell command by interpolating `filename`
(single-quoted, but a `'` in the name closes the quote) and `filepath` (unquoted),
then runs it with `shell=True`. Both are user-controlled — the gcode file's basename
and its (subdirectory-capable) path. Linux filenames may contain `'`, `;`, `$`,
backticks, spaces. Reached on **every print start** (`cmd_SDCARD_PRINT_FILE` →
`record_print_history`/`load_gcode_metadata`) and via `SHOW_GCODE_FLUSH`.
- **Impact:** a file named e.g. `` a';reboot;'.gcode `` (or a subdir named `;cmd;`)
  executes arbitrary shell commands as the klipper user (often root on these boards)
  the moment it is printed — RCE from a network-uploadable filename.
- **Fix:** never use a shell — pass an argv list:
  `check_output([python_env, '.../metadata.py', '-f', filename, '-p', filepath])`.
  If a shell is unavoidable, `shlex.quote()` every interpolated value.

### 2. `load_ai.py:126` — `rm -rf` built by string concat with `shell=True` — **high (security)**
```python
command = 'rm -rf ' + file_path
subprocess.run(command, shell=True, check=True)
```
`remove_files()` is called from `cmd_LOAD_AI_DEAL` with `file_path` derived from
`os.walk(self.pic_dir)` (and `pic_dir` is operator-settable). Any shell metacharacter
or space breaks out: a benign `sub capture.bmp` deletes `.../sub` **and** `capture.bmp`
in the cwd; a crafted name yields arbitrary command execution.
- **Fix:** `subprocess.run(['rm', '-rf', file_path], check=True)` — or better
  `shutil.rmtree`/`os.remove` after validating the path is inside `pic_dir`.

### 3. `metadata.py:1214` — `metadata['model_info']` KeyError discards all metadata — **high (crash)**
```python
if not metadata['model_info'].get('multicolor_method'):   # also :1211 ['MaterialType']
```
`model_info` is only inserted when `parse_model_info()` returns non-`None`, and that
returns `None` on **any** exception — including a single malformed numeric header
(`;Machine Height:`) or a `UnicodeDecodeError` (the file is opened without
`errors='replace'`, unlike `get_slicer`). Once absent, the unconditional subscript
raises `KeyError`, which propagates to `main` and `sys.exit(-1)`s — so *all*
successfully-parsed fields (slicer, times, thumbnail, temps) are thrown away and the
file gets no metadata (may be unlistable/unstartable in the UI).
- **Fix:** `metadata.setdefault('model_info', {})` after the parse loop; open the file
  with `errors='replace'` and don't discard everything on one bad field.

### 4. `metadata.py:420` — unguarded `int()` in `PrusaSlicer.parse_flush_para` — **high (crash)**
```python
flush_volumes_matrix = [ int(x) for x in flush_volumes_matrix_match.group(1).strip().split(',') ]
```
Unlike the `_regex_find_*` helpers (which swallow exceptions), this parses directly.
Orca/Bambu multi-material gcode (matched by `PrusaSlicer.check_identity`) commonly
emits decimal matrix values (`280.0`), so `int('280.0')` raises `ValueError`, aborting
the whole extraction. The Creality copy at `:1066` uses `int(float(x))` specifically to
cope with this; the PrusaSlicer copy was not updated. `float(flush_multiplier)` at
`:417` is likewise unguarded.
- **Fix:** wrap in try/except returning `None` and use `int(float(x))` consistently.

### 5. `auto_addr_wrapper.py:279,350` — CL/BT-motor ack indexes a 1-element table — **high (crash)**
```python
addr_manager_table = dev_table_map_table[ack_data.dev_type - DEV_TYPE_INDEX_OFFSET].addr_manager_table
```
`dev_type` comes straight from the bus response; `dev_table_map_table` is built with a
single element (MB), yet `is_dev_type_valid()` accepts CL(2)/BT(3) motors. A CL/BT ack
gives index 1/2 → `IndexError` inside the `process_*` reactor callbacks → **klippy
shutdown** whenever such a motor is on the 485 bus.
- **Fix:** validate `dev_type` and bounds-check the index (and/or populate the table
  with the CL/BT entries the module already defines).

### 6. `auto_addr_wrapper.py:359` — short 485 frame → IndexError — **high (crash)**
```python
package = DataPackage(ret[0], ret[1], ret[2], ret[3], ret[4], [b for b in ret[5:-1]], ret[-1])
```
`send_package` only guards `ret is None`; `data_handler` then unpacks `ret[0..4]` and
`function_code_cb` reads `package.data[0..1]`. A short/garbled response passes the
`None` check and raises `IndexError` in the reactor callback → klippy shutdown.
- **Fix:** validate `len(ret)` (header+crc, and per-command payload length) first.

### 7. `hx711s.py:184` — `read_base` trims 4 extrema from a too-short buffer — **high (crash)**
```python
del vals[j][0:int(len(vals[j])/2)]          # keep ceil(cnt/2)
del vals[j][vals[j].index(min(vals[j]))]    # ×2 min, ×2 max  → needs ≥4 left
rvs[j].append(min(vals[j]))
```
Called as `read_base(int(base_count/2), …)` from probing/gap code; `base_count` has
`minval=10`, so `cnt` can be 5–8, leaving `ceil(cnt/2)−4 ≤ 0` items → `del`/`min([])`
raises `ValueError`. So any configured `base_count` in **10–17** crashes every
strain-gauge zeroing during G28/G29/probe. (Default 40 is safe — latent config-range
crash.)
- **Fix:** raise `base_count` `minval` to ≥18, or make the trimming adaptive/guarded.

### 8. `probe.py:140` — `target_z` used unbound when `prtouch_v3` absent — **high (crash, latent on stock)**
```python
self.prtouch_v3 = self.printer.lookup_object('prtouch_v3') if self.printer.objects.get('prtouch_v3') else None
if self.prtouch_v3 is not None:
    ...
    target_z = self.z_position          # only assigned here
pos[2] = target_z                        # used unconditionally
```
When `prtouch_v3` is not loaded, `target_z` is never bound → `UnboundLocalError` on
every `_probe()` (PROBE, PROBE_ACCURACY, CALIBRATE, BED_MESH, Z_TILT, QGL, probe
homing). **On the shipped printers this does not fire** — all eight configs load
`[prtouch_v3]` — but it breaks any BLTouch/inductive/`smart_effector` adaptation.
- **Fix:** initialize `target_z = self.z_position` before the `if` (as stock does).

### 9. `homing.py:58` — `prtouch_v3` dereferenced right after being set to `None` — **high (crash, latent on stock)**
```python
self.prtouch_v3 = self.printer.lookup_object('prtouch_v3') if self.printer.objects.get('prtouch_v3') else None
self.prtouch_v3.z_full_movement_flag = False     # AttributeError if None
```
Same pattern as #8 (later code guards `if self.prtouch_v3 is not None:`). `HomingMove`
is built by every home/probe/manual-home, so on a config without `prtouch_v3` all
homing raises `AttributeError`. **Latent on the shipped printers** (all load
`[prtouch_v3]`).
- **Fix:** `if self.prtouch_v3 is not None: self.prtouch_v3.z_full_movement_flag = False`.

### 10. `heater_bed.py:69` — `BED_HEADER_SET_HEARER_POWER_MAX` bypasses the 220 V power cap — **medium (safety)**
```python
max_power = gcmd.get_float('S', 1)
self.heater.max_power = max_power
self.heater.control.heater_max_power = max_power
```
No bounds (the config path enforces `above=0., maxval=1.`). The 110/220 V calibration
exists to cap a 220 V bed at `power_calibration_power_220` (0.75); this command can
raise it back above that with `S=1.5` — an overpower/overheat hazard on hardware that
was intentionally limited. Operator/macro-initiated, not autonomous.
- **Fix:** `gcmd.get_float('S', 1., above=0., maxval=1.)`.

### 11. `heater_bed.py:113` — `np.polyfit` on too few samples — **medium (crash)**
`get_heater_slope` only appends samples inside a ~10 °C window then drops the first;
if 0–1 land in the window, `np.polyfit(x, y, 1)` raises. Unhandled →
`BED_HEADER_POWER_CALIBRATION` aborts with a traceback, possibly leaving the bed at a
target with `max_power` partly adjusted.
- **Fix:** `if len(sample_temps) < 2: return 0.0` (or a clean `gcmd.error`).

### 12. `dirzctl.py:84` — wait timeout ~10¹² × too large — **medium (logic/safety)**
```python
while ... and time.time() - t_start < 1.5e+06 * step_us * step_cnt and len(self.all_params) != 2:
```
`step_us` is microseconds; the real move is `step_us*step_cnt*1e-6` s, but the bound is
`1.5e6*step_us*step_cnt` (~10¹² × too big — looks like `e+06` where `e-06` was meant).
The wait never times out on its own; it relies entirely on `is_shutdown`/`is_timeout`.
If the MCU drops a result packet on a `wait_finish=True` probe/home, the wait stalls
until a shutdown instead of timing out — the intended safety timeout is dead.
- **Fix:** `... < 1.5 * step_us * step_cnt * 1e-6 + margin`.

### 13. `gcode_arcs.py:107` — ZeroDivisionError on a degenerate arc — **medium (numeric)**
```python
real_segments = max(math.floor(mm_of_travel / self.mm_per_arc_segment), min_segments)
real_segments_mm = mm_of_travel / real_segments
```
`min_segments = ceil(... * circle_factor)` is 0 when `angular_travel == 0.0` (target
collinear with center and start, no Z travel), and then `mm_of_travel` is 0 too → `0/0`.
Upstream guards with `max(1., floor(...))`; this fork dropped the floor. A malformed
`G2`/`G3` raises an unhandled `ZeroDivisionError`, aborting the command/print.
- **Fix:** `real_segments = max(1, ...)`, or early-return when `mm_of_travel ≈ 0`.

### 14. `bed_mesh.py:923` — `_sample_direct` assigns a 2-D matrix into a flat array — **medium (crash)**
```python
self.__mesh_matrix[0:] = self.mesh_matrix     # 2-D list into a 1-D np.full(...)
```
The other samplers flatten first (`[item for row in ... for item in row]`); this one
doesn't. numpy can't broadcast `(y,x)` into `(y*x,)` → `ValueError` (reproduced).
`direct` sampling is selected by `mesh_pps: 0,0`; the error escapes `probe_finalize`
(which only catches `BedMeshError`), so `BED_MESH_CALIBRATE`/`load_profile` crash.
- **Fix:** flatten before assigning, like the other samplers.

### 15. `z_tilt.py:39` — shared `ZAdjustHelper` hard-requires `[z_tilt]` — **medium (crash)**
```python
z_tilt = self.printer.lookup_object('z_tilt')   # no default
z_tilt.stepper_z_adjustment += a
```
This Creality-added tracking runs inside `adjust_steppers`, which
`quad_gantry_level.py` also uses. A QGL printer normally has no `[z_tilt]` section, so
the lookup raises `Unknown config object 'z_tilt'` and `QUAD_GANTRY_LEVEL` aborts. (It
also only tracks `stepper_z`/`z1`, ignoring `z2`/`z3`.)
- **Fix:** `lookup_object('z_tilt', None)` and guard, or move the bookkeeping into `ZTilt`.

### 16. `prtouch.py:430,444,597` — normalize divides by `(max-min)` with no zero guard — **medium (numeric)**
```python
p0_vals[i] = (p0_vals[i] - min_val) / (max_val - min_val)
```
Flat readings (saturated/disconnected/unloaded sensor → all-equal) make the
denominator 0 → `ZeroDivisionError`. The author added exactly this guard in
`_check_trigger:219` (`max_val += 1 if (max_val-min_val)==0`) but omitted it here (and
in `_cal_min_z:597`). Crashes gap measurement/leveling on constant sensor data.
- **Fix:** bump `max_val` by 1 when `max_val == min_val`, as in `_check_trigger`.

### 17. `belt_mdl.py:507` — reads `rec_data[4]` after only `len < 3` — **medium (crash)**
```python
if len(rec_data) < 3: ... return (0, -2, 0)
...
sen_fun = rec_data[4]
```
A length-3/4 frame with the right head/addr passes the guard and then `IndexError`s on
`rec_data[4]`. A truncated 485 belt-module frame crashes the BELT_MDL_* command.
- **Fix:** guard `len(rec_data) < 5` (cover index 4) and validate slice bounds.

### 18. `ms3200x.py:405` — `PPS=0` → ZeroDivisionError — **medium (numeric)**
```python
u16reg = int(fclk / (int(pps) << 4))    # pps from gcmd.get_int('PPS') with no minval
```
`MS32008_MOVE PPS=0` / `MS32008_SET CH=A PPS=0` → `0<<4 == 0` → `ZeroDivisionError`.
- **Fix:** add `minval=1` to the `PPS` parse (and/or guard `pps == 0`).

### 19. `homing.py:167` — `json.loads` on a non-JSON error string — **medium (crash)**
```python
error_data = json.loads(error.replace("'", '"'))
```
On the force-stop path `error` is `'{"code":"key20", "msg":"...%s", "values":[%s]}' %
(str(e), str(e))` — `str(e)` is inserted raw into a quoted field and an unquoted array
element, so for any real message this is invalid JSON → `JSONDecodeError`, which is not
a `command_error` and so bypasses the `except self.printer.command_error` handlers.
(Also `error_data.get('values') == 'probe'` compares a list to a string.) Result:
a genuine MCU homing failure surfaces as an internal traceback instead of the intended
"key20" report, and the shutdown-context branch is skipped.
- **Fix:** build the string with `json.dumps` (properly escaped) and wrap `json.loads`
  in try/except that falls back to `raise command_error(error)`.

### 20. `custom_macro.py:59` — `M104 S%d` on `None` temp + reactor-blocking `sleep` — **medium (crash)**
```python
self.gcode.run_script_from_command('M104 S%d' % self.extruder_temp)   # None until CX_ROUGH_G28
...
while self.pheaters.can_break_flag == 1: time.sleep(1)                 # blocks the reactor
```
`extruder_temp`/`bed_temp` are `None` until `CX_ROUGH_G28` runs; calling
`CX_PRINT_DRAW_ONE_LINE`/`CX_NOZZLE_CLEAR` first raises `TypeError` (`'%d' % None`,
`None - 20`). Separately, the `time.sleep(1)` poll blocks klippy's event loop (MCU
comms scheduling) until `can_break_flag` changes.
- **Fix:** default/validate the temps before formatting; replace `time.sleep` with
  `reactor.pause(reactor.monotonic()+1)`.

### 21. `pause_resume.py:222` — `RESUME` does unguarded `json.loads` of the recovery file — **medium (crash)**
```python
with open(self.v_sd.print_file_name_path) as f:
    result = json.loads(f.read())            # no try/except
```
If `print_file_name.json` is empty/truncated (a realistic post-power-loss state — the
very scenario this feature recovers from — or a prior interrupted write), `json.loads`
raises `ValueError`, uncaught, so `RESUME` fails until the file is cleared by hand. The
analogous read at `:80-92` *is* guarded; this one (and `user_print_refer_path` at
`:94-98`) is not.
- **Fix:** wrap in try/except (match `:80-92`) and treat a parse failure as "no recovery".

### 22. `tmc2262.py:442` — COOLCONF `sedn` mask overlaps `seimin` — **medium (logic)**
```python
'sedn': 57344,     # 0xE000, bits 13–15  (should be 0x6000, bits 13–14)
'seimin': 32768,   # 0x8000, bit 15
```
`sedn` is one bit too wide (cf. `tmc2130.py:159` `'sedn': 24576`), so it shares bit 15
with `seimin`. `set_config_field('sedn', …)` then accepts 0–7 instead of 0–3, and any
value ≥4 flips `seimin` on; both are written to the chip. Default config sets both to 0
(no corruption by default), but a tuned CoolStep config gets the wrong current-decrement
rate and a wrongly-enabled minimum coolstep current.
- **Fix:** `'sedn': 24576`.

### 23. `input_shaper.py:148` — `old_delay` never updated → unbounded flush-time growth — **medium (logic)**
```python
self.toolhead.note_step_generation_scan_time(new_delay, old_delay=self.old_delay)
# missing: self.old_delay = new_delay
```
Upstream sets `self.old_delay = new_delay` right after; here `old_delay` is stuck at
`0.0` forever (only set in `connect()`). The toolhead uses it to `pop` the previous
flush-time entry; with it always falsy, every `SET_INPUT_SHAPER`/`UPDATE_INPUT_SHAPER`
(and the disable/enable pair fired on each resonance test) appends without removing, so
`kin_flush_times` grows unbounded and `kin_flush_delay` never decreases when you lower
or disable shaping.
- **Fix:** add `self.old_delay = new_delay` after the call.

### 24. `fan_feedback.py:72` — webhook endpoint callback has the wrong signature — **medium (crash)**
```python
def _get_cx_fan_status(self):          # must be (self, web_request)
    ...
    return self.cx_fan_status          # must be web_request.send(...)
```
Klipper invokes endpoints as `cb(web_request)`; this one takes only `self` and returns
a value. Every `get_cx_fan_status` query raises `TypeError` (caught by the webhooks
layer, so klippy stays up) — the endpoint is 100 % non-functional.
- **Fix:** `def _get_cx_fan_status(self, web_request): web_request.send(self.cx_fan_status)`.

### 25. `adxl345.py:124` — resonance shared-memory buffer undersized by the header — **medium (numeric)**
```python
shm_size = 32 * total                  # 4 doubles × 8 B × total
self.copy_int_to_buffer(buffer, 0, count); count += 4   # 4-B header at offset 0
```
Samples start at offset 4, so the payload needs `32*total + 4` bytes. When nothing is
filtered, the last sample's Z write runs 4 bytes past the mapping. The overflow is
swallowed by `copy_double_to_buffer`'s bare `except` (so the last Z is silently 0 and a
spurious `respond_info` is emitted), but if `total == 0` (messages with empty `data`),
`SharedMemory(size=0)` raises an uncaught `ValueError`. Default resonance path
(`low_mem=True`).
- **Fix:** `shm_size = 32 * total + 4`, and guard `total == 0`.

### 26–40. Low-severity
- **26 `virtual_sdcard.py:1069`** — `get_print_file_metadata(filename, get_layer_count=True)`: no such kwarg → `TypeError` (caught), so the fallback layer-count path never works. Fix: drop the kwarg.
- **27 `virtual_sdcard.py:94`** — `interval_time = 1.0 / frame` with user `delay_image.frame`; `frame=0` → `ZeroDivisionError` (and a synchronous `time.sleep` on the reactor). Fix: `frame = max(1, frame)`.
- **28 `load_ai.py:448`** — `conn.close()` only on the success path; the hard-coded `172.23.88.101:38765` upload server is often unreachable, so each failed `LOAD_AI_DEAL` leaks a socket FD. Fix: `try/finally: conn.close()`.
- **29 `load_ai.py:383`** — the AI wait loop keys on truthiness of `self.result` (init `{}`); empty stdout is misread as a 10 s "timeout" and the real `stderr` is discarded. Fix: use an explicit done flag.
- **30 `heater_fan.py:40`** — `lookup_object('heater_bed')` (no default) in the 1 Hz callback, and the result is unused; crashes klippy on a bedless `heater_fan` config. Fix: remove the dead line.
- **31 `stepper_enable.py:105`** — `motor_off` looks up `virtual_sdcard` with no default → `config_error` on M18/M84/restart if that section is absent. Fix: `lookup_object('virtual_sdcard', None)` + guard.
- **32 `bed_mesh.py:155`** — `update_mesh` webhook dereferences `self.z_mesh` (None until a mesh exists) with no guard, unlike `_get_mesh`. Fix: early-return when `None`.
- **33 `z_align.py:305`** — `read_real_zmax` uses `.get('zmax', 0)`; on a file missing the key the Z datum becomes 0 instead of the safe `max_z - 10`, and only the upper bound is clamped. Fix: `.get('zmax', max_z - 10)` and reject `<= 0`.
- **34 `prtouch_v2.py:11`** — `vrt` unbound when `pr_version` is 0 or 3–100 (parser allows `minval=0, maxval=100`) → `UnboundLocalError` at startup. Fix: `minval=1, maxval=2` or an `else: raise`.
- **35 `bl24c16f.py:126`** — `EEPROM_READ` builds `reg_vals` then never `respond_info`s it; the read appears to do nothing. Fix: add the response (cf. `EEPROM_DEBUG_READ`).
- **36 `bl24c16f.py:96,147`** — inclusive `maxval=0x100000000`; `VAL = 2³²` is accepted but packs to 4 bytes as `0`. Fix: `maxval=0xFFFFFFFF`.
- **37 `temperature_mcu.py:129`** — SAMD INT1V two's-complement: `val = 256 - val` should be `val - 256`; corrupts MCU-temp calibration on SAMD only (not Creality's STM32/GD32). Fix: `val -= 0x100`.
- **38 `shaper_calibrate.py:278`** — `SharedMemory.unlink()` without `close()`; the mapping/FD lingers to GC (4 segments/axis per SHAPER_CALIBRATE). Fix: `try/finally: shm.close()`.
- **39 `bus.py:252`** — `MCU_bus_digital_out` init path formats with `%c` instead of `%d`, emitting control chars in the `config_cmd`. Latent (no in-repo instantiator). Fix: `%d`.
- **40 malformed error-protocol JSON** — see the systemic pattern above: `gcode_move.py:302,305,339,342,797,816`, `homing.py:167`, `replicape.py:21,47,54,102,104`. UI `JSON.parse` fails; reporting-only. Fix: correct the `:`→`,` punctuation and stray quotes. (`replicape` is inert — that cape isn't used on these printers.)

---

## Modules reviewed and found clean

No genuine defects (logic matches correct stock Klipper or the Creality customization
is internally consistent): `print_stats`, `save_variables`, `sdcard_loop`,
`tuning_tower`, `exclude_object`, `gcode_macro`, `photograph`, `base_info`, `respond`,
`display_status`, `statistics_ext`, `manual_probe`, `skew_correction`,
`delta_calibrate`, `quad_gantry_level`, `smart_effector`, `heaters`, `heater_generic`,
`temperature_fan`, `temperature_sensor`, `thermistor`, `adc_temperature`, `adc_scaled`,
`verify_heater`, `controller_fan`, `pid_calibrate`, `homing_heaters`, `force_move`,
`manual_stepper`, `idle_timeout`, `motion_report`, `homing_override`,
`firmware_retraction`, `extruder_stepper`, `tmc`, `tmc_uart`, `tmc2130`, `tmc2208`,
`tmc2209`, `endstop_phase`, `motor_control`, `z_thermal_adjust`, `lis2dw`, `buttons`,
`filament_switch_sensor`, `filament_motion_sensor`, `hall_filament_width_sensor`,
`tsl1401cl_filament_width_sensor`, `fan`, `fan_generic`, `pulse_counter`, `neopixel`,
`dotstar`, `filter`, `gcode_button`, `multi_pin`, `query_adc`, `query_endstops`,
`static_digital_output`, `resonance_tester`.

`box`, `filament_rack`, `serial_485`, `prtouch_v3` are thin `load_config` loaders whose
real logic lives in the compiled Cython `*_wrapper` extensions (recovered as C under
`reconstructed/`, not audited here as Python).

## Notes and limitations

- **These are original-firmware bugs.** The source is byte-exact to the shipped `.pyc`;
  no defect here was introduced by reconstruction.
- **Confidence.** Every critical/high item was re-verified by hand against the source
  and the shipped `config/*/printer.cfg`; items #8 and #9 are explicitly marked *latent*
  because all eight stock configs load `[prtouch_v3]`.
- **Not exhaustive.** This is static review. Timing/reentrancy bugs that only appear
  under specific MCU interleavings, and defects inside the compiled `*_wrapper`/`.so`
  extensions and MCU firmware, are out of scope. `output_pin.checkpwm()` has a latent
  `AttributeError` (uninitialized `self.ispweron`) but is dead code and not counted.
