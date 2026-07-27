# Decompilation status

- Modules: **105**
- Clean (ast-valid, no known defects): **57**
- Ast-valid but flagged (`None(...)` dropped builtin -- see disasm): **13**
- Partial (did not fully round-trip -- see disasm): **35**

| module | status | lines |
|--------|--------|-------|
| `controller_fan.pyc` | partial | 75 |
| `exclude_object.pyc` | partial | 319 |
| `heaters.pyc` | partial | 427 |
| `homing.pyc` | partial | 229 |
| `homing_heaters.pyc` | partial | 38 |
| `input_shaper.pyc` | partial | 150 |
| `load_ai.pyc` | partial | 553 |
| `metadata.pyc` | partial | 1120 |
| `ms3200x.pyc` | partial | 565 |
| `neopixel.pyc` | partial | 67 |
| `output_pin.pyc` | partial | 58 |
| `probe.pyc` | partial | 272 |
| `replicape.pyc` | partial | 292 |
| `shaper_calibrate.pyc` | partial | 355 |
| `tmc2130.pyc` | partial | 434 |
| `auto_addr_wrapper.pyc` | partial | 179 |
| `bed_mesh.pyc` | partial | 212 |
| `buttons.pyc` | partial | 67 |
| `custom_macro.pyc` | partial | 75 |
| `delta_calibrate.pyc` | partial | 254 |
| `dirzctl.pyc` | partial | 33 |
| `gcode_macro.pyc` | partial | 52 |
| `gcode_move.pyc` | partial | 374 |
| `heater_bed.pyc` | partial | 141 |
| `prtouch.pyc` | partial | 246 |
| `resonance_tester.pyc` | partial | 374 |
| `skew_correction.pyc` | partial | 112 |
| `tmc.pyc` | partial | 66 |
| `tmc2208.pyc` | partial | 247 |
| `tmc2262.pyc` | partial | 639 |
| `tmc_uart.pyc` | partial | 39 |
| `tool.pyc` | partial | 16 |
| `virtual_sdcard.pyc` | partial | 198 |
| `z_align.pyc` | partial | 173 |
| `auto_addr_wrapper.pyc` | partial | 179 |
| `adxl345.pyc` | flagged (7x None-call) | 574 |
| `belt_mdl.pyc` | flagged (1x None-call) | 538 |
| `endstop_phase.pyc` | flagged (2x None-call) | 243 |
| `fan.pyc` | flagged (1x None-call) | 125 |
| `filter.pyc` | flagged (1x None-call) | 153 |
| `gcode_arcs.pyc` | flagged (1x None-call) | 171 |
| `lis2dw.pyc` | flagged (5x None-call) | 271 |
| `pause_resume.pyc` | flagged (5x None-call) | 283 |
| `print_stats.pyc` | flagged (2x None-call) | 202 |
| `quad_gantry_level.pyc` | flagged (1x None-call) | 116 |
| `query_endstops.pyc` | flagged (1x None-call) | 56 |
| `sdcard_loop.pyc` | flagged (1x None-call) | 73 |
| `z_tilt.pyc` | flagged (2x None-call) | 299 |
| `__init__.pyc` | clean | 8 |
| `adc_scaled.pyc` | clean | 97 |
| `adc_temperature.pyc` | clean | 610 |
| `auto_addr.pyc` | clean | 10 |
| `base_info.pyc` | clean | 1 |
| `bl24c16f.pyc` | clean | 282 |
| `board_pins.pyc` | clean | 32 |
| `box.pyc` | clean | 9 |
| `bus.pyc` | clean | 261 |
| `delayed_gcode.pyc` | clean | 60 |
| `display_status.pyc` | clean | 62 |
| `dotstar.pyc` | clean | 59 |
| `duplicate_pin_override.pyc` | clean | 18 |
| `extruder_stepper.pyc` | clean | 28 |
| `fan_feedback.pyc` | clean | 144 |
| `fan_generic.pyc` | clean | 30 |
| `filament_motion_sensor.pyc` | clean | 74 |
| `filament_rack.pyc` | clean | 9 |
| `filament_switch_sensor.pyc` | clean | 126 |
| `firmware_retraction.pyc` | clean | 61 |
| `force_move.pyc` | clean | 159 |
| `gcode_button.pyc` | clean | 58 |
| `hall_filament_width_sensor.pyc` | clean | 184 |
| `heater_fan.pyc` | clean | 62 |
| `heater_generic.pyc` | clean | 9 |
| `homing_override.pyc` | clean | 70 |
| `hx711s.pyc` | clean | 243 |
| `idle_timeout.pyc` | clean | 112 |
| `io_remap.pyc` | clean | 59 |
| `manual_probe.pyc` | clean | 269 |
| `manual_stepper.pyc` | clean | 164 |
| `motion_report.pyc` | clean | 1 |
| `motor_control.pyc` | clean | 9 |
| `multi_pin.pyc` | clean | 72 |
| `photograph.pyc` | clean | 30 |
| `pid_calibrate.pyc` | clean | 181 |
| `prtouch_v2.pyc` | clean | 17 |
| `prtouch_v3.pyc` | clean | 13 |
| `pulse_counter.pyc` | clean | 81 |
| `query_adc.pyc` | clean | 40 |
| `respond.pyc` | clean | 54 |
| `save_variables.pyc` | clean | 100 |
| `serial_485.pyc` | clean | 9 |
| `shaper_defs.pyc` | clean | 135 |
| `smart_effector.pyc` | clean | 168 |
| `static_digital_output.pyc` | clean | 20 |
| `statistics_ext.pyc` | clean | 94 |
| `stepper_enable.pyc` | clean | 165 |
| `temperature_fan.pyc` | clean | 197 |
| `temperature_mcu.pyc` | clean | 224 |
| `temperature_sensor.pyc` | clean | 49 |
| `thermistor.pyc` | clean | 127 |
| `tmc2209.pyc` | clean | 77 |
| `tsl1401cl_filament_width_sensor.pyc` | clean | 124 |
| `tuning_tower.pyc` | clean | 113 |
| `verify_heater.pyc` | clean | 119 |
| `z_thermal_adjust.pyc` | clean | 174 |
