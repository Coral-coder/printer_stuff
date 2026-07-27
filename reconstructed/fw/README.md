# MCU firmware — recovered C (reference)

`fw/**/*.bin` are flashable **ARM Cortex-M (GD32)** images for the printer's
sub-processors. They are stripped raw binaries (no ELF, no symbol table), so
`<name>.c` here is the **Ghidra decompilation** — functionally faithful but with
generated `FUN_xxxxxxxx` names and no types. Useful for understanding behaviour;
a byte-identical rebuild needs the original vendor source tree + config.

Vector-table analysis (`tools/fw_analyze.py`):

| Image | Type | Flash base | Initial SP | Notes |
|-------|------|-----------|-----------|-------|
| `mcu*` | **Klipper MCU firmware** | 0x08000000 | 0x20010000 | build from Klipper `src/` (`make`, arm-none-eabi) |
| `noz*` | Klipper MCU firmware | 0x08000000 | — | nozzle-board MCU |
| `bed*` | Klipper MCU firmware | 0x08000000 | — | bed MCU |
| `cfs*` | **RT-Thread application** | 0x08010000 (app; bootloader at 0x08000000) | 0x20006ee8 | GD32 BSP; "MF003"; secure chip fm15l013 |

- **Klipper MCU images** (`mcu`/`noz`/`bed`): open-source Klipper micro-controller
  firmware. Rebuild from the Klipper source tree: `make menuconfig` (select the GD32
  target) then `make`, with `arm-none-eabi-gcc`. The Ghidra C confirms the Klipper
  command dispatch / scheduler structure.
- **CFS image** (`cfs`): an RT-Thread RTOS application for the multi-material feeder
  (`RT-Thread team` banner, `gd32_uart_*`, `gd32_periph_list`). Rebuild needs the
  RT-Thread project + GD32 BSP; the Ghidra C is provided for reference only.

> Fidelity: firmware is stripped machine code with no symbols — this is the honest
> ceiling for reconstruction. The decompilations are complete and correct in behaviour
> but are not drop-in source. The open-source origin (Klipper MCU / RT-Thread) is
> identified so the real source trees can be used for a faithful rebuild.
