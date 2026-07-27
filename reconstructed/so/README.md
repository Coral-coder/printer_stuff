# Cython wrappers — recovered source

`proprietary/so/*.cpython-39.so` are Creality's proprietary `klippy/extras/*_wrapper.py`
modules, compiled to C by **Cython 0.29.21** and then to ARM machine code. They are the
closed-source heart of the multi-material / motor-control / probe stack; the thin
`proprietary/shims/*.py` loaders import their classes.

Each module is recovered here as `<name>.c` — the **Ghidra decompilation** of the ARM
machine code. This is *faithful, functionally-complete* source (every function is
present), but it is CPython-C-API-level C (the shape Cython emits), not the original
Python. Recovering clean maintainable Python from stripped machine code is not fully
automatable; the C is the ground truth, and `proprietary/NATIVE_ARTIFACTS.md` lists the
embedded class / method / gcode-command / config-param identifiers that name the API.

| Module | Loader stub | Exposed class | Role |
|--------|-------------|---------------|------|
| `box_wrapper` | `shims/box.py` | `MultiColorMeterialBoxWrapper` | multi-material box (CFS) control |
| `filament_rack_wrapper` | `shims/filament_rack.py` | `FilamentRackWrapper` | filament rack / flush |
| `motor_control_wrapper` | `shims/motor_control.py` | `Motor_Control` | closed-loop motor control |
| `serial_485_wrapper` | `shims/serial_485.py` | `Serial_485_Wrapper` | RS-485 transport |
| `mymovie` | (internal) | `MoveSplitter` (C++) | move splitting / z-mesh compensation |
| `prtouch_v1_wrapper` | `shims/prtouch.py` | prtouch v1 | strain-gauge bed probe |
| `prtouch_v2_wrapper` | `shims/prtouch_v2.py` | prtouch v2 | strain-gauge bed probe |
| `prtouch_v3_wrapper` | `shims/prtouch_v3.py` | prtouch v3 | strain-gauge bed probe |

`mymovie` is notable: it is C++ (not Cython) and Ghidra recovers demangled
`MoveSplitter::build_move/split/_calc_z_offset` etc. — the cleanest of the set.

**Rebuild:** `cython -3 <name>.py` → C → cross-compile to `<name>.cpython-39.so` with
`arm-linux-gnueabihf-gcc` against the CPython 3.9 ARM headers (see `../../BUILD.md`).
