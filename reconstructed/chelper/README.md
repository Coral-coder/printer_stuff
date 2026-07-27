# chelper — recovered C source

`proprietary/chelper/c_helper.so` (stripped ARM shared object) is **Klipper's
open-source `chelper`** plus **Creality's proprietary `serial_485` / `msgblock_485`**
additions. The 112 exported functions split cleanly:

## Klipper `chelper` (upstream GPL — `klippy/chelper/*.c`)

| Exported symbols | Upstream translation unit |
|------------------|---------------------------|
| `itersolve_*`, `move_alloc`, `move_get_coord/distance` | `itersolve.c`, `trapq.c` |
| `cartesian_*`, `corexy_*`, `corexz_*`, `polar_*`, `delta_*`, `deltesian_*`, `rotary_delta_*` | `kin_*.c` |
| `extruder_stepper_alloc`, `extruder_set_pressure_advance` | `kin_extruder.c` |
| `input_shaper_*` | `kin_shaper.c` |
| `serialqueue`/`message_*`, `msgblock_check`, `msgblock_crc16_ccitt` | `serialqueue.c`, `msgblock.c` |
| `pollreactor_*` | `pollreactor.c` |
| `steppersync_*`, `stepcompress_*` | `stepcompress.c` |
| `clock_from_clock32/time`, `get_monotonic`, `errorf`, `report_errno`, `dump_string`, `fd_set_non_blocking`, `pyhelper` | `pyhelper.c` |

These are the actual GPL sources of the `.so` (build them from the Klipper `chelper`
tree, retargeted with `arm-linux-gnueabihf-gcc`).

## Creality proprietary additions (recovered here)

| Symbols | Source |
|---------|--------|
| `serial_485_queue_alloc/free/exit/send/pull/get_stats/extract_old` | `serial_485_queue.c` (recovered) |
| `msgblock_485_check`, `msgblock_485_crc8` | `msgblock_485.*` |
| `get_flushing_volume` | (Creality helper) |

- `serial_485_queue.h` — shipped verbatim (structs + prototypes).
- `serial_485_queue.c` — recovered from the **unstripped** `serial_485_queue.o`
  (Ghidra decompilation, `serial_485_queue.raw.c`). It is a Creality RS-485 adaptation
  of Klipper's `serialqueue.c` (same `background_thread` / `kick_event` /
  `command_event` / `input_event` reactor structure), verified against the header's
  `struct serial_485_queue` field offsets.
- `list.h`, `pollreactor.h`, `compiler.h` — upstream Klipper headers (needed to compile).

> Fidelity: the Klipper parts are exact upstream GPL source; the Creality parts are
> machine-decompiled C (functionally faithful, recovered from the object file).
