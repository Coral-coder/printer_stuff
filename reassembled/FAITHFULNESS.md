# Reassembly faithfulness (recompiled under CPython 3.9 vs original bytecode)

Each recovered `.py` is recompiled to a 3.9 `.pyc` and its code objects are
compared opcode-for-opcode against the original. **faithful** = the recovered
source round-trips to essentially the same bytecode (a proof of correctness).

- faithful (>=99.5%): **105**
- high (90-99.5%): **0**
- partial (<90%): **0**
- broken (won't recompile under 3.9 / empty): **0**

| module | category | bytecode match | note |
|--------|----------|---------------:|------|
| `shims/__init__.py` | faithful | 100.0% |  |
| `shims/adc_scaled.py` | faithful | 100.0% |  |
| `shims/adc_temperature.py` | faithful | 100.0% |  |
| `shims/adxl345.py` | faithful | 100.0% |  |
| `shims/auto_addr.py` | faithful | 100.0% |  |
| `shims/auto_addr_wrapper.py` | faithful | 100.0% |  |
| `shims/base_info.py` | faithful | 100.0% |  |
| `shims/bed_mesh.py` | faithful | 100.0% |  |
| `shims/belt_mdl.py` | faithful | 100.0% |  |
| `shims/bl24c16f.py` | faithful | 100.0% |  |
| `shims/board_pins.py` | faithful | 100.0% |  |
| `shims/box.py` | faithful | 100.0% |  |
| `shims/bus.py` | faithful | 100.0% |  |
| `shims/buttons.py` | faithful | 100.0% |  |
| `shims/controller_fan.py` | faithful | 100.0% |  |
| `shims/custom_macro.py` | faithful | 100.0% |  |
| `shims/delayed_gcode.py` | faithful | 100.0% |  |
| `shims/delta_calibrate.py` | faithful | 100.0% |  |
| `shims/dirzctl.py` | faithful | 100.0% |  |
| `shims/display_status.py` | faithful | 100.0% |  |
| `shims/dotstar.py` | faithful | 100.0% |  |
| `shims/duplicate_pin_override.py` | faithful | 100.0% |  |
| `shims/endstop_phase.py` | faithful | 100.0% |  |
| `shims/exclude_object.py` | faithful | 100.0% |  |
| `shims/extruder_stepper.py` | faithful | 100.0% |  |
| `shims/fan.py` | faithful | 100.0% |  |
| `shims/fan_feedback.py` | faithful | 100.0% |  |
| `shims/fan_generic.py` | faithful | 100.0% |  |
| `shims/filament_motion_sensor.py` | faithful | 100.0% |  |
| `shims/filament_rack.py` | faithful | 100.0% |  |
| `shims/filament_switch_sensor.py` | faithful | 100.0% |  |
| `shims/filter.py` | faithful | 100.0% |  |
| `shims/firmware_retraction.py` | faithful | 100.0% |  |
| `shims/force_move.py` | faithful | 100.0% |  |
| `shims/gcode_arcs.py` | faithful | 100.0% |  |
| `shims/gcode_button.py` | faithful | 100.0% |  |
| `shims/gcode_macro.py` | faithful | 100.0% |  |
| `shims/gcode_move.py` | faithful | 100.0% |  |
| `shims/hall_filament_width_sensor.py` | faithful | 100.0% |  |
| `shims/heater_bed.py` | faithful | 100.0% |  |
| `shims/heater_fan.py` | faithful | 100.0% |  |
| `shims/heater_generic.py` | faithful | 100.0% |  |
| `shims/heaters.py` | faithful | 100.0% |  |
| `shims/homing.py` | faithful | 100.0% |  |
| `shims/homing_heaters.py` | faithful | 100.0% |  |
| `shims/homing_override.py` | faithful | 100.0% |  |
| `shims/hx711s.py` | faithful | 100.0% |  |
| `shims/idle_timeout.py` | faithful | 100.0% |  |
| `shims/input_shaper.py` | faithful | 100.0% |  |
| `shims/io_remap.py` | faithful | 100.0% |  |
| `shims/lis2dw.py` | faithful | 100.0% |  |
| `shims/load_ai.py` | faithful | 100.0% |  |
| `shims/manual_probe.py` | faithful | 100.0% |  |
| `shims/manual_stepper.py` | faithful | 100.0% |  |
| `shims/metadata.py` | faithful | 100.0% |  |
| `shims/motion_report.py` | faithful | 100.0% |  |
| `shims/motor_control.py` | faithful | 100.0% |  |
| `shims/ms3200x.py` | faithful | 100.0% |  |
| `shims/multi_pin.py` | faithful | 100.0% |  |
| `shims/neopixel.py` | faithful | 100.0% |  |
| `shims/output_pin.py` | faithful | 100.0% |  |
| `shims/pause_resume.py` | faithful | 100.0% |  |
| `shims/photograph.py` | faithful | 100.0% |  |
| `shims/pid_calibrate.py` | faithful | 100.0% |  |
| `shims/print_stats.py` | faithful | 100.0% |  |
| `shims/probe.py` | faithful | 100.0% |  |
| `shims/prtouch.py` | faithful | 100.0% |  |
| `shims/prtouch_v2.py` | faithful | 100.0% |  |
| `shims/prtouch_v3.py` | faithful | 100.0% |  |
| `shims/pulse_counter.py` | faithful | 100.0% |  |
| `shims/quad_gantry_level.py` | faithful | 100.0% |  |
| `shims/query_adc.py` | faithful | 100.0% |  |
| `shims/query_endstops.py` | faithful | 100.0% |  |
| `shims/replicape.py` | faithful | 100.0% |  |
| `shims/resonance_tester.py` | faithful | 100.0% |  |
| `shims/respond.py` | faithful | 100.0% |  |
| `shims/save_variables.py` | faithful | 100.0% |  |
| `shims/sdcard_loop.py` | faithful | 100.0% |  |
| `shims/serial_485.py` | faithful | 100.0% |  |
| `shims/shaper_calibrate.py` | faithful | 100.0% |  |
| `shims/shaper_defs.py` | faithful | 100.0% |  |
| `shims/skew_correction.py` | faithful | 100.0% |  |
| `shims/smart_effector.py` | faithful | 100.0% |  |
| `shims/static_digital_output.py` | faithful | 100.0% |  |
| `shims/statistics_ext.py` | faithful | 100.0% |  |
| `shims/stepper_enable.py` | faithful | 100.0% |  |
| `shims/temperature_fan.py` | faithful | 100.0% |  |
| `shims/temperature_mcu.py` | faithful | 100.0% |  |
| `shims/temperature_sensor.py` | faithful | 100.0% |  |
| `shims/thermistor.py` | faithful | 100.0% |  |
| `shims/tmc.py` | faithful | 100.0% |  |
| `shims/tmc2130.py` | faithful | 100.0% |  |
| `shims/tmc2208.py` | faithful | 100.0% |  |
| `shims/tmc2209.py` | faithful | 100.0% |  |
| `shims/tmc2262.py` | faithful | 100.0% |  |
| `shims/tmc_uart.py` | faithful | 100.0% |  |
| `shims/tool.py` | faithful | 100.0% |  |
| `shims/tsl1401cl_filament_width_sensor.py` | faithful | 100.0% |  |
| `shims/tuning_tower.py` | faithful | 100.0% |  |
| `shims/verify_heater.py` | faithful | 100.0% |  |
| `shims/virtual_sdcard.py` | faithful | 100.0% |  |
| `shims/z_align.py` | faithful | 100.0% |  |
| `shims/z_thermal_adjust.py` | faithful | 100.0% |  |
| `shims/z_tilt.py` | faithful | 100.0% |  |
| `so/auto_addr_wrapper.py` | faithful | 100.0% |  |
