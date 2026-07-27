# Reassembly faithfulness (recompiled under CPython 3.9 vs original bytecode)

Each recovered `.py` is recompiled to a 3.9 `.pyc` and its code objects are
compared opcode-for-opcode against the original. **faithful** = the recovered
source round-trips to essentially the same bytecode (a proof of correctness).

- faithful (>=99.5%): **36**
- high (90-99.5%): **29**
- partial (<90%): **3**
- broken (won't recompile under 3.9 / empty): **37**

| module | category | bytecode match | note |
|--------|----------|---------------:|------|
| `shims/__init__.py` | faithful | 100.0% |  |
| `shims/adc_scaled.py` | faithful | 100.0% |  |
| `shims/auto_addr.py` | faithful | 100.0% |  |
| `shims/board_pins.py` | faithful | 100.0% |  |
| `shims/box.py` | faithful | 100.0% |  |
| `shims/delayed_gcode.py` | faithful | 100.0% |  |
| `shims/duplicate_pin_override.py` | faithful | 100.0% |  |
| `shims/extruder_stepper.py` | faithful | 100.0% |  |
| `shims/fan_generic.py` | faithful | 100.0% |  |
| `shims/filament_motion_sensor.py` | faithful | 100.0% |  |
| `shims/filament_rack.py` | faithful | 100.0% |  |
| `shims/firmware_retraction.py` | faithful | 100.0% |  |
| `shims/heater_generic.py` | faithful | 100.0% |  |
| `shims/io_remap.py` | faithful | 100.0% |  |
| `shims/manual_stepper.py` | faithful | 100.0% |  |
| `shims/motor_control.py` | faithful | 100.0% |  |
| `shims/prtouch_v2.py` | faithful | 100.0% |  |
| `shims/prtouch_v3.py` | faithful | 100.0% |  |
| `shims/query_endstops.py` | faithful | 100.0% |  |
| `shims/respond.py` | faithful | 100.0% |  |
| `shims/serial_485.py` | faithful | 100.0% |  |
| `shims/shaper_defs.py` | faithful | 100.0% |  |
| `shims/smart_effector.py` | faithful | 100.0% |  |
| `shims/static_digital_output.py` | faithful | 100.0% |  |
| `shims/temperature_sensor.py` | faithful | 100.0% |  |
| `shims/tmc2209.py` | faithful | 100.0% |  |
| `shims/fan_feedback.py` | faithful | 99.9% |  |
| `shims/heater_fan.py` | faithful | 99.8% |  |
| `shims/bl24c16f.py` | faithful | 99.7% |  |
| `shims/pulse_counter.py` | faithful | 99.7% |  |
| `shims/temperature_fan.py` | faithful | 99.7% |  |
| `shims/fan.py` | faithful | 99.6% |  |
| `shims/multi_pin.py` | faithful | 99.6% |  |
| `shims/quad_gantry_level.py` | faithful | 99.6% |  |
| `shims/filter.py` | faithful | 99.5% |  |
| `shims/stepper_enable.py` | faithful | 99.5% |  |
| `shims/bus.py` | high | 99.4% |  |
| `shims/query_adc.py` | high | 99.4% |  |
| `shims/force_move.py` | high | 99.2% |  |
| `shims/gcode_arcs.py` | high | 99.2% |  |
| `shims/statistics_ext.py` | high | 99.2% |  |
| `shims/gcode_button.py` | high | 99.1% |  |
| `shims/hall_filament_width_sensor.py` | high | 99.0% |  |
| `shims/temperature_mcu.py` | high | 99.0% |  |
| `shims/tsl1401cl_filament_width_sensor.py` | high | 99.0% |  |
| `shims/dotstar.py` | high | 98.8% |  |
| `shims/filament_switch_sensor.py` | high | 98.8% |  |
| `shims/pause_resume.py` | high | 98.7% |  |
| `shims/adxl345.py` | high | 98.6% |  |
| `shims/display_status.py` | high | 98.6% |  |
| `shims/sdcard_loop.py` | high | 98.5% |  |
| `shims/tuning_tower.py` | high | 98.4% |  |
| `shims/manual_probe.py` | high | 98.3% |  |
| `shims/adc_temperature.py` | high | 97.9% |  |
| `shims/z_thermal_adjust.py` | high | 97.9% |  |
| `shims/z_tilt.py` | high | 97.7% |  |
| `shims/idle_timeout.py` | high | 97.5% |  |
| `shims/print_stats.py` | high | 96.8% |  |
| `shims/thermistor.py` | high | 96.8% |  |
| `shims/homing_override.py` | high | 96.1% |  |
| `shims/pid_calibrate.py` | high | 96.0% |  |
| `shims/base_info.py` | high | 95.9% |  |
| `shims/lis2dw.py` | high | 93.9% |  |
| `shims/save_variables.py` | high | 93.8% |  |
| `shims/photograph.py` | high | 93.0% |  |
| `shims/verify_heater.py` | partial | 86.7% |  |
| `shims/bed_mesh.py` | partial | 14.8% |  |
| `shims/motion_report.py` | partial | 0.2% |  |
| `shims/auto_addr_wrapper.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/belt_mdl.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/buttons.py` | broken | — | compile-failed: PyCompileError: Sorry: IndentationError: expected an i |
| `shims/controller_fan.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/custom_macro.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/delta_calibrate.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/dirzctl.py` | broken | — | compile-failed: PyCompileError: Sorry: IndentationError: expected an i |
| `shims/endstop_phase.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/exclude_object.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/gcode_macro.py` | broken | — | compile-failed: PyCompileError: Sorry: IndentationError: expected an i |
| `shims/gcode_move.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/heater_bed.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/heaters.py` | broken | — | compile-failed: PyCompileError: Sorry: IndentationError: expected an i |
| `shims/homing.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/homing_heaters.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/hx711s.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/input_shaper.py` | broken | — | compile-failed: PyCompileError: Sorry: IndentationError: expected an i |
| `shims/load_ai.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/metadata.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/ms3200x.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/neopixel.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/output_pin.py` | broken | — | compile-failed: PyCompileError: Sorry: IndentationError: expected an i |
| `shims/probe.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/prtouch.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/replicape.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/resonance_tester.py` | broken | — | compile-failed: PyCompileError: Sorry: IndentationError: unexpected un |
| `shims/shaper_calibrate.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/skew_correction.py` | broken | — | compile-failed: PyCompileError: Sorry: IndentationError: expected an i |
| `shims/tmc.py` | broken | — | compile-failed: PyCompileError: Sorry: IndentationError: expected an i |
| `shims/tmc2130.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/tmc2208.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/tmc2262.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/tmc_uart.py` | broken | — | compile-failed: PyCompileError: Sorry: IndentationError: expected an i |
| `shims/tool.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/virtual_sdcard.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/z_align.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `so/auto_addr_wrapper.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
