# Reassembly faithfulness (recompiled under CPython 3.9 vs original bytecode)

Each recovered `.py` is recompiled to a 3.9 `.pyc` and its code objects are
compared opcode-for-opcode against the original. **faithful** = the recovered
source round-trips to essentially the same bytecode (a proof of correctness).

- faithful (>=99.5%): **44**
- high (90-99.5%): **30**
- partial (<90%): **2**
- broken (won't recompile under 3.9 / empty): **29**

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
| `shims/gcode_button.py` | faithful | 100.0% |  |
| `shims/heater_generic.py` | faithful | 100.0% |  |
| `shims/homing_heaters.py` | faithful | 100.0% |  |
| `shims/io_remap.py` | faithful | 100.0% |  |
| `shims/manual_stepper.py` | faithful | 100.0% |  |
| `shims/motor_control.py` | faithful | 100.0% |  |
| `shims/multi_pin.py` | faithful | 100.0% |  |
| `shims/prtouch_v2.py` | faithful | 100.0% |  |
| `shims/prtouch_v3.py` | faithful | 100.0% |  |
| `shims/quad_gantry_level.py` | faithful | 100.0% |  |
| `shims/query_adc.py` | faithful | 100.0% |  |
| `shims/query_endstops.py` | faithful | 100.0% |  |
| `shims/respond.py` | faithful | 100.0% |  |
| `shims/sdcard_loop.py` | faithful | 100.0% |  |
| `shims/serial_485.py` | faithful | 100.0% |  |
| `shims/shaper_defs.py` | faithful | 100.0% |  |
| `shims/smart_effector.py` | faithful | 100.0% |  |
| `shims/static_digital_output.py` | faithful | 100.0% |  |
| `shims/stepper_enable.py` | faithful | 100.0% |  |
| `shims/temperature_sensor.py` | faithful | 100.0% |  |
| `shims/tmc2209.py` | faithful | 100.0% |  |
| `shims/fan_feedback.py` | faithful | 99.9% |  |
| `shims/replicape.py` | faithful | 99.9% |  |
| `shims/bus.py` | faithful | 99.8% |  |
| `shims/fan.py` | faithful | 99.8% |  |
| `shims/heater_fan.py` | faithful | 99.8% |  |
| `shims/temperature_fan.py` | faithful | 99.8% |  |
| `shims/bl24c16f.py` | faithful | 99.7% |  |
| `shims/pulse_counter.py` | faithful | 99.7% |  |
| `shims/skew_correction.py` | faithful | 99.7% |  |
| `shims/controller_fan.py` | faithful | 99.6% |  |
| `shims/filter.py` | faithful | 99.6% |  |
| `shims/force_move.py` | high | 99.4% |  |
| `shims/gcode_arcs.py` | high | 99.2% |  |
| `shims/statistics_ext.py` | high | 99.2% |  |
| `shims/tsl1401cl_filament_width_sensor.py` | high | 99.2% |  |
| `shims/dotstar.py` | high | 99.1% |  |
| `shims/filament_switch_sensor.py` | high | 99.1% |  |
| `shims/hall_filament_width_sensor.py` | high | 99.1% |  |
| `shims/temperature_mcu.py` | high | 99.1% |  |
| `shims/adxl345.py` | high | 99.0% |  |
| `shims/idle_timeout.py` | high | 99.0% |  |
| `shims/input_shaper.py` | high | 99.0% |  |
| `shims/pause_resume.py` | high | 98.9% |  |
| `shims/tmc_uart.py` | high | 98.7% |  |
| `shims/display_status.py` | high | 98.6% |  |
| `shims/manual_probe.py` | high | 98.6% |  |
| `shims/tuning_tower.py` | high | 98.6% |  |
| `shims/buttons.py` | high | 98.4% |  |
| `shims/exclude_object.py` | high | 98.4% |  |
| `shims/output_pin.py` | high | 98.4% |  |
| `shims/adc_temperature.py` | high | 97.9% |  |
| `shims/z_thermal_adjust.py` | high | 97.9% |  |
| `shims/z_tilt.py` | high | 97.9% |  |
| `shims/thermistor.py` | high | 97.2% |  |
| `shims/print_stats.py` | high | 97.0% |  |
| `shims/neopixel.py` | high | 96.8% |  |
| `shims/homing_override.py` | high | 96.7% |  |
| `shims/pid_calibrate.py` | high | 96.1% |  |
| `shims/lis2dw.py` | high | 93.9% |  |
| `shims/save_variables.py` | high | 93.8% |  |
| `shims/photograph.py` | high | 93.0% |  |
| `shims/verify_heater.py` | partial | 89.9% |  |
| `shims/bed_mesh.py` | partial | 14.8% |  |
| `shims/auto_addr_wrapper.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/base_info.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/belt_mdl.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/custom_macro.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/delta_calibrate.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/dirzctl.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/endstop_phase.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/gcode_macro.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/gcode_move.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/heater_bed.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/heaters.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/homing.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/hx711s.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/load_ai.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/metadata.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/motion_report.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/ms3200x.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/probe.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/prtouch.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/resonance_tester.py` | broken | — | compile-failed: PyCompileError: Sorry: IndentationError: unexpected un |
| `shims/shaper_calibrate.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/tmc.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/tmc2130.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/tmc2208.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/tmc2262.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/tool.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/virtual_sdcard.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `shims/z_align.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
| `so/auto_addr_wrapper.py` | broken | — | compile-failed: PyCompileError:   File "/home/user/printer_stuff/decom |
