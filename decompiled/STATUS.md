# Decompilation status

- Modules: **105**
- Byte-exact faithful (recompiles to identical CPython 3.9 bytecode): **105**
- Non-faithful / won't-recompile: **0**

Every recovered module round-trips to byte-identical bytecode against the
original `.pyc` (verified by `tools/verify_module.py` / `tools/bcdiff.py`).
This is a proof each module is a true drop-in replacement.

| module | status | bytecode match |
|--------|--------|---------------:|
| `__init__.pyc` | faithful | 100.0% |
| `adc_scaled.pyc` | faithful | 100.0% |
| `adc_temperature.pyc` | faithful | 100.0% |
| `adxl345.pyc` | faithful | 100.0% |
| `auto_addr.pyc` | faithful | 100.0% |
| `auto_addr_wrapper.pyc` | faithful | 100.0% |
| `base_info.pyc` | faithful | 100.0% |
| `bed_mesh.pyc` | faithful | 100.0% |
| `belt_mdl.pyc` | faithful | 100.0% |
| `bl24c16f.pyc` | faithful | 100.0% |
| `board_pins.pyc` | faithful | 100.0% |
| `box.pyc` | faithful | 100.0% |
| `bus.pyc` | faithful | 100.0% |
| `buttons.pyc` | faithful | 100.0% |
| `controller_fan.pyc` | faithful | 100.0% |
| `custom_macro.pyc` | faithful | 100.0% |
| `delayed_gcode.pyc` | faithful | 100.0% |
| `delta_calibrate.pyc` | faithful | 100.0% |
| `dirzctl.pyc` | faithful | 100.0% |
| `display_status.pyc` | faithful | 100.0% |
| `dotstar.pyc` | faithful | 100.0% |
| `duplicate_pin_override.pyc` | faithful | 100.0% |
| `endstop_phase.pyc` | faithful | 100.0% |
| `exclude_object.pyc` | faithful | 100.0% |
| `extruder_stepper.pyc` | faithful | 100.0% |
| `fan.pyc` | faithful | 100.0% |
| `fan_feedback.pyc` | faithful | 100.0% |
| `fan_generic.pyc` | faithful | 100.0% |
| `filament_motion_sensor.pyc` | faithful | 100.0% |
| `filament_rack.pyc` | faithful | 100.0% |
| `filament_switch_sensor.pyc` | faithful | 100.0% |
| `filter.pyc` | faithful | 100.0% |
| `firmware_retraction.pyc` | faithful | 100.0% |
| `force_move.pyc` | faithful | 100.0% |
| `gcode_arcs.pyc` | faithful | 100.0% |
| `gcode_button.pyc` | faithful | 100.0% |
| `gcode_macro.pyc` | faithful | 100.0% |
| `gcode_move.pyc` | faithful | 100.0% |
| `hall_filament_width_sensor.pyc` | faithful | 100.0% |
| `heater_bed.pyc` | faithful | 100.0% |
| `heater_fan.pyc` | faithful | 100.0% |
| `heater_generic.pyc` | faithful | 100.0% |
| `heaters.pyc` | faithful | 100.0% |
| `homing.pyc` | faithful | 100.0% |
| `homing_heaters.pyc` | faithful | 100.0% |
| `homing_override.pyc` | faithful | 100.0% |
| `hx711s.pyc` | faithful | 100.0% |
| `idle_timeout.pyc` | faithful | 100.0% |
| `input_shaper.pyc` | faithful | 100.0% |
| `io_remap.pyc` | faithful | 100.0% |
| `lis2dw.pyc` | faithful | 100.0% |
| `load_ai.pyc` | faithful | 100.0% |
| `manual_probe.pyc` | faithful | 100.0% |
| `manual_stepper.pyc` | faithful | 100.0% |
| `metadata.pyc` | faithful | 100.0% |
| `motion_report.pyc` | faithful | 100.0% |
| `motor_control.pyc` | faithful | 100.0% |
| `ms3200x.pyc` | faithful | 100.0% |
| `multi_pin.pyc` | faithful | 100.0% |
| `neopixel.pyc` | faithful | 100.0% |
| `output_pin.pyc` | faithful | 100.0% |
| `pause_resume.pyc` | faithful | 100.0% |
| `photograph.pyc` | faithful | 100.0% |
| `pid_calibrate.pyc` | faithful | 100.0% |
| `print_stats.pyc` | faithful | 100.0% |
| `probe.pyc` | faithful | 100.0% |
| `prtouch.pyc` | faithful | 100.0% |
| `prtouch_v2.pyc` | faithful | 100.0% |
| `prtouch_v3.pyc` | faithful | 100.0% |
| `pulse_counter.pyc` | faithful | 100.0% |
| `quad_gantry_level.pyc` | faithful | 100.0% |
| `query_adc.pyc` | faithful | 100.0% |
| `query_endstops.pyc` | faithful | 100.0% |
| `replicape.pyc` | faithful | 100.0% |
| `resonance_tester.pyc` | faithful | 100.0% |
| `respond.pyc` | faithful | 100.0% |
| `save_variables.pyc` | faithful | 100.0% |
| `sdcard_loop.pyc` | faithful | 100.0% |
| `serial_485.pyc` | faithful | 100.0% |
| `shaper_calibrate.pyc` | faithful | 100.0% |
| `shaper_defs.pyc` | faithful | 100.0% |
| `skew_correction.pyc` | faithful | 100.0% |
| `smart_effector.pyc` | faithful | 100.0% |
| `static_digital_output.pyc` | faithful | 100.0% |
| `statistics_ext.pyc` | faithful | 100.0% |
| `stepper_enable.pyc` | faithful | 100.0% |
| `temperature_fan.pyc` | faithful | 100.0% |
| `temperature_mcu.pyc` | faithful | 100.0% |
| `temperature_sensor.pyc` | faithful | 100.0% |
| `thermistor.pyc` | faithful | 100.0% |
| `tmc.pyc` | faithful | 100.0% |
| `tmc2130.pyc` | faithful | 100.0% |
| `tmc2208.pyc` | faithful | 100.0% |
| `tmc2209.pyc` | faithful | 100.0% |
| `tmc2262.pyc` | faithful | 100.0% |
| `tmc_uart.pyc` | faithful | 100.0% |
| `tool.pyc` | faithful | 100.0% |
| `tsl1401cl_filament_width_sensor.pyc` | faithful | 100.0% |
| `tuning_tower.pyc` | faithful | 100.0% |
| `verify_heater.pyc` | faithful | 100.0% |
| `virtual_sdcard.pyc` | faithful | 100.0% |
| `z_align.pyc` | faithful | 100.0% |
| `z_thermal_adjust.pyc` | faithful | 100.0% |
| `z_tilt.pyc` | faithful | 100.0% |
| `auto_addr_wrapper.pyc` | faithful | 100.0% |
