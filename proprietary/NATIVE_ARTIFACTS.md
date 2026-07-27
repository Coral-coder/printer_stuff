# Native (non-Python) artifacts

These artifacts are **compiled machine code**, not Python. Unlike the `.pyc` bytecode (recovered to source under `decompiled/`), native code cannot be decompiled back to faithful source. This inventory records what each artifact is and what metadata is recoverable (exported symbols, embedded identifiers), so the API surface is documented even where the implementation is not.

## Cython extension modules (`proprietary/so/*.cpython-39.so`)

CPython 3.9 C-extensions compiled from Cython. The Python loader stubs in `proprietary/shims/` (e.g. `box.py`) import classes from these. The class/function names are embedded and listed below; the bodies are ARM machine code and are not recoverable to Python.

### `proprietary/so/box_wrapper.cpython-39.so`
- ELF 32-bit LSB shared object, ARM, EABI5 version 1 (SYSV), dynamically linked, stripped
- size: 1,934,720 bytes, sha1 `f730f9124512`
- embedded identifiers: `_ITM_deregisterTMCloneTable`, `_ITM_registerTMCloneTable`, `memcmp`, `raise`, `_edata`, `_end`, `macro_extrusion_all_materials_err_retry_process`, `z_err_extrusion_all_materials_err`, `power_loss_same_material_process`, `macro_extrusion_all_materials_err`, `get_material_max_extrusion_speed`, `extruder_extrude_err_retry_process`, `extrude_process_auto_retry_process`, `extrude_material_len_for_extruder`, `execute_toolhead_ai_waste_management`, `diff_material_type_min_flush_len`, `communication_get_hardware_status`, `communication_get_filament_sensor_state`, `communication_ctrl_connection_motor_action`, `cmd_ctrl_connection_motor_action`, `cmd_BOX_SET_CURRENT_BOX_IDLE_MODE`, `box_start_get_rfid_and_remain_len`, `box_retrude_material_filament_err_part`, `auto_retry_filament_sensor_second`, `BOX_CTRL_CONNECTION_MOTOR_ACTION`, `print_end_move_to_cut_err_retry_process`, `generate_check_preloading_scrap_slot_func`, `communication_tighten_up_enable`, `use_ending_material_flag_clear`, `communication_get_buffer_state`, `communication_extrude2_process`, `filament_max_volumetric_speed`, `filament_err_tighten_up_event`, `cr_break_extruder_extrude_err`, `communication_set_pre_loading`, `communication_retrude_process`, `communication_measuring_wheel`, `communication_extrude_process`, `cmd_update_same_material_list`, `cmd_retrude_material_with_tnn`

### `proprietary/so/filament_rack_wrapper.cpython-39.so`
- ELF 32-bit LSB shared object, ARM, EABI5 version 1 (SYSV), dynamically linked, stripped
- size: 206,768 bytes, sha1 `f4351bca207f`
- embedded identifiers: `_ITM_deregisterTMCloneTable`, `_ITM_registerTMCloneTable`, `memcmp`, `_edata`, `_end`, `diff_material_type_min_flush_len`, `filament_max_volumetric_speed`, `check_flush_temp_and_extrude`, `cmd_send_data_with_response`, `cmd_filament_rack_pre_flush`, `is_different_type_material`, `cmd_filament_rack_set_temp`, `get_material_target_speed`, `can_get_filament_rack_tmp`, `FILAMENT_RACK_RESTORE_FAN`, `remain_material_velocity`, `get_material_target_temp`, `cmd_filament_rack_modify`, `run_script_from_command`, `cmd_filament_rack_flush`, `FILAMENT_RACK_PRE_FLUSH`, `register_event_handler`, `get_command_parameters`, `FILAMENT_RACK_SET_TEMP`, `FILAMENT_RACK_SAVE_FAN`, `remain_material_color`, `current_material_type`, `can_get_filament_rack`, `remain_material_type`, `quickly_wait_heating`, `max_volumetric_speed`, `max_temp_flush_times`, `FILAMENT_RACK_MODIFY`, `enable_get_filament`, `FilamentRackWrapper`, `FILAMENT_RACK_FLUSH`, `nozzle_temperature`, `last_material_type`, `filament_rack_data`, `cline_in_traceback`

### `proprietary/so/motor_control_wrapper.cpython-39.so`
- ELF 32-bit LSB shared object, ARM, EABI5 version 1 (SYSV), dynamically linked, stripped
- size: 1,136,924 bytes, sha1 `892a0486165e`
- embedded identifiers: `_ITM_deregisterTMCloneTable`, `_ITM_registerTMCloneTable`, `memcmp`, `_edata`, `_end`, `UUUUU`, `controller_motor_ripple_compensator_sin_coeffs_2_term_phi`, `system_id_RL_param_param_current_err_size`, `system_id_RL_param_param_current_buff_size`, `protection_param_encoder_mutation_coefficient_lower`, `param_encoder_calibtate_official_ud_cal_set`, `motor_encoder_calibrate_official_help`, `motor_check_protection_after_home_help`, `driver_board_param_adc_calibration_buffer_size`, `controller_z3_filter_binary_second_order_param_zeta_0D`, `controller_z3_filter_binary_second_order_param_zeta_0N`, `controller_z3_filter_binary_second_order_param_depth`, `controller_z3_filter_binary_second_order_param_fc`, `controller_spd_out_filter_notch_2_param_depth`, `controller_spd_out_filter_notch_2_param_f_width`, `controller_spd_out_filter_notch_2_param_f0`, `controller_spd_out_filter_binary_second_order_param_zeta_0D`, `controller_spd_out_filter_binary_second_order_param_zeta_0N`, `controller_spd_out_filter_binary_second_order_param_depth`, `controller_spd_out_filter_binary_second_order_param_fc`, `controller_spd_loop_pid_ud_filter_param_fc`, `controller_spd_loop_pid_fal_param_inteval_gain`, `controller_spd_loop_pid_fal_param_section_nums`, `controller_spd_loop_pid_fal_param_zoom`, `controller_spd_loop_pid_fal_param_d`, `controller_spd_loop_pid_fal_param_a`, `controller_pos_loop_pid_ud_filter_param_fc`, `controller_pos_loop_pid_fal_param_inteval_gain`, `controller_pos_loop_pid_fal_param_section_nums`, `controller_pos_loop_pid_fal_param_zoom`, `controller_pos_loop_pid_fal_param_d`, `controller_pos_loop_pid_fal_param_a`, `controller_motor_ripple_compensator_sin_coeffs_2_term_n`, `controller_motor_ripple_compensator_sin_coeffs_2_term_A`, `controller_motor_ripple_compensator_sin_coeffs_1_term_phi`

### `proprietary/so/mymovie.cpython-39.so`
- ELF 32-bit LSB shared object, ARM, EABI5 version 1 (SYSV), dynamically linked, stripped
- size: 150,368 bytes, sha1 `f2f2df63a813`
- embedded identifiers: `_ITM_deregisterTMCloneTable`, `_ITM_registerTMCloneTable`, `fmax`, `fmin`, `floor`, `_Z7isclosedddd`, `_ZN12MoveSplitterC2Edd`, `puts`, `_ZN12MoveSplitterC1Edd`, `_ZN12MoveSplitter10initializeEjd`, `_Z12get_z_factorjd`, `_Z25zmesh_calc_c_for_externalddj`, `_ZN12MoveSplitter14_calc_z_offsetEdd`, `_ZN12MoveSplitter10build_moveEj`, `sqrt`, `_ZN12MoveSplitter14_set_next_moveEd`, `_ZN12MoveSplitter5splitEj`, `_ZN12MoveSplitter20build_move_and_splitEj`, `_Z20li_get_cur_move_addrv`, `_ZN12MoveSplitter14split_for_loopEj`, `_Z20estimated_print_timejd`, `_Z12report_errnoPKc`, `strerror`, `stderr`, `_Z13get_monotonicv`, `clock_gettime`, `free`, `_Znwj`, `_ZdlPvj`, `_ZN4MoveC1Ev`, `_ZN4Move10move_errorEPc`, `_ZN4Move12set_junctionEddd`, `_ZN4Move13calc_junctionEPS_d`, `_ZN4Move11limit_speedEdd`, `_Z20li_set_cur_move_addrj`, `_Z17set_extruder_infoj`, `_Z18set_corexykin_infodddddddd`, `_Z26get_moveq_only_data_bufferv`, `_Z14move_queue_addP4Move`, `_Z14move_queue_deli`

### `proprietary/so/prtouch_v1_wrapper.cpython-39.so`
- ELF 32-bit LSB shared object, ARM, EABI5 version 1 (SYSV), dynamically linked, stripped
- size: 1,097,640 bytes, sha1 `a2f14cee3521`
- embedded identifiers: `_ITM_deregisterTMCloneTable`, `_ITM_registerTMCloneTable`, `memcmp`, `raise`, `_edata`, `_end`, `PR_ERR_CODE_PRES_VAL_IS_CONSTANT`, `PR_ERR_CODE_PRES_READ_DATA_TIMEOUT`, `PR_ERR_CODE_G28_Z_DETECTION_TIMEOUT`, `_handle_result_read_pres_prtouch`, `_handle_result_run_step_prtouch`, `_handle_result_run_pres_prtouch`, `PR_ERR_CODE_STEP_LOST_RUN_DATA`, `PR_ERR_CODE_PRES_NOT_BE_SENSED`, `PR_ERR_CODE_PRES_NOISE_TOO_BIG`, `PR_ERR_CODE_PRES_LOST_RUN_DATA`, `After_G28Z_skip_bed_tilt_flag`, `PR_ERR_CODE_SWAP_PIN_DETECTI`, `nozzle_clear_z_out_of_range`, `cmd_START_STEP_PRTOUCH_help`, `cmd_SELF_CHECK_PRTOUCH_help`, `PR_ERR_CODE_PR_NOT_TRIGGER`, `PR_ERR_CODE_HAVE_LOST_STEP`, `safe_move_z_tri_call_back`, `prtouch_shake_check_error`, `_handle_step_debug_prtouch`, `_handle_pres_debug_prtouch`, `static_check_error_state`, `result_read_pres_prtouch`, `register_config_callback`, `cmd_ACCURATE_HOME_Z_help`, `run_script_from_command`, `result_run_step_prtouch`, `result_run_pres_prtouch`, `recored_Coarse_Probe_mm`, `cmd_CHECK_BED_MESH_help`, `write_swap_prtouch_cmd`, `start_step_prtouch_cmd`, `start_pres_prtouch_cmd`, `square_corner_velocity`

### `proprietary/so/prtouch_v2_wrapper.cpython-39.so`
- ELF 32-bit LSB shared object, ARM, EABI5 version 1 (SYSV), dynamically linked, stripped
- size: 1,069,428 bytes, sha1 `9533acd2303d`
- embedded identifiers: `_ITM_deregisterTMCloneTable`, `_ITM_registerTMCloneTable`, `memcmp`, `raise`, `_edata`, `_end`, `PR_ERR_CODE_PRES_VAL_IS_CONSTANT`, `PR_ERR_CODE_PRES_READ_DATA_TIMEOUT`, `PR_ERR_CODE_G28_Z_DETECTION_TIMEOUT`, `_handle_result_read_pres_prtouch`, `_handle_result_run_step_prtouch`, `_handle_result_run_pres_prtouch`, `PR_ERR_CODE_STEP_LOST_RUN_DATA`, `PR_ERR_CODE_PRES_NOT_BE_SENSED`, `PR_ERR_CODE_PRES_NOISE_TOO_BIG`, `PR_ERR_CODE_PRES_LOST_RUN_DATA`, `After_G28Z_skip_bed_tilt_flag`, `PR_ERR_CODE_SWAP_PIN_DETECTI`, `nozzle_clear_z_out_of_range`, `cmd_START_STEP_PRTOUCH_help`, `cmd_SELF_CHECK_PRTOUCH_help`, `PR_ERR_CODE_PR_NOT_TRIGGER`, `PR_ERR_CODE_HAVE_LOST_STEP`, `safe_move_z_tri_call_back`, `prtouch_shake_check_error`, `_handle_step_debug_prtouch`, `_handle_pres_debug_prtouch`, `_correct_bed_mesh_one_data`, `static_check_error_state`, `result_read_pres_prtouch`, `register_config_callback`, `cmd_ACCURATE_HOME_Z_help`, `run_script_from_command`, `result_run_step_prtouch`, `result_run_pres_prtouch`, `recored_Coarse_Probe_mm`, `cmd_CHECK_BED_MESH_help`, `bed_mesh_bottom_mid_com`, `write_swap_prtouch_cmd`, `start_step_prtouch_cmd`

### `proprietary/so/prtouch_v3_wrapper.cpython-39.so`
- ELF 32-bit LSB shared object, ARM, EABI5 version 1 (SYSV), dynamically linked, stripped
- size: 1,298,608 bytes, sha1 `66e35bdd7912`
- embedded identifiers: `_ITM_deregisterTMCloneTable`, `_ITM_registerTMCloneTable`, `memcmp`, `memmove`, `_edata`, `_end`, `PR_ERR_CODE_G28_Z_DETECTION_TIMEOUT`, `set_z_temp_compensation_callbak`, `cmd_SET_CUMULATIVE_HEATING_TIME`, `_handle_check_chamber_temp_comp`, `PR_ERR_CODE_PRES_NOT_BE_SENSED`, `PR_ERR_CODE_PLATFORM_DETECTI`, `test_pres_amplitude_threshold`, `cmd_PRTOUCH_PLATFORM_DET_help`, `test_pres_amplitude_read_cnt`, `test_pres_amplitude_loop_cnt`, `cmd_TEST_PRES_AMPLITUDE_help`, `cmd_SET_TEMP_NOT_LINEAR_help`, `TEST_PRES_AMPLITUDE_THRESHLD`, `TEST_PRES_AMPLITUDE_READ_CNT`, `PR_ERR_CODE_SWAP_PIN_DETECTI`, `PR_ERR_CODE_G28_ACCU_FAILE`, `regional_prtouch_percentage`, `cmd_BED_MESH_CALIBRATE_help`, `_chamber_comp_do_query_timer`, `bed_mesh_fall_comp_diagonal`, `SET_CUMULATIVE_HEATING_TIME`, `register_chamber_temp_comp`, `get_temperature_compensate`, `cmd_TEST_BED_MESH_CAL_help`, `cmd_BED_MESH_CAL_LOOP_help`, `PR_ERR_CODE_NEED_RESET_XYZ`, `test_pres_amplitude_scale`, `mcu_to_commanded_position`, `cmd_NEXT_HOMEZ_NACCU_help`, `cmd_BED_MESH_PROFILE_help`, `TEST_PRES_AMPLITUDE_SCALE`, `test_pres_amplitude_path`, `test_pres_amplitude_file`, `requested_accel_to_decel`

### `proprietary/so/serial_485_wrapper.cpython-39.so`
- ELF 32-bit LSB shared object, ARM, EABI5 version 1 (SYSV), dynamically linked, stripped
- size: 143,704 bytes, sha1 `f2c8a4c0cd95`
- embedded identifiers: `_ITM_deregisterTMCloneTable`, `_ITM_registerTMCloneTable`, `memmove`, `_edata`, `_end`, `cmd_send_data_with_response`, `serial_485_queue_get_stats`, `serial_485_queue_alloc`, `register_event_handler`, `get_command_parameters`, `serial_485_queue_send`, `serial_485_queue_pull`, `serial_485_queue_free`, `serial_485_queue_exit`, `pending_notifications`, `is_exist_in_send_list`, `DefaultMessages_485`, `send_queue_process`, `send_notifications`, `notifications_addr`, `cline_in_traceback`, `Serial_485_Wrapper`, `register_response`, `raw_send_wait_ack`, `notifications_cmd`, `cmd_485_send_data`, `background_thread`, `remove_send_data`, `register_command`, `_firmware_restart`, `handle_callback`, `SerialException`, `SERIAL_SEND_STR`, `serial_fd_type`, `send_list_copy`, `register_timer`, `handle_default`, `async_complete`, `_start_session`, `notifications`

## Compiled C helper (`proprietary/chelper/`)

### `proprietary/chelper/c_helper.so`
- ELF 32-bit LSB shared object, ARM, EABI5 version 1 (SYSV), dynamically linked, stripped
- size: 46,668 bytes, sha1 `17b7d22231b8`

### `proprietary/chelper/serial_485_queue.h`
- C **header source** (already present, not compiled).

### `proprietary/chelper/serial_485_queue.o`
- ELF 32-bit LSB relocatable, ARM, EABI5 version 1 (SYSV), not stripped
- size: 56,196 bytes, sha1 `56d09f3da545`
- symbols: `serial_485_queue_alloc`, `serial_485_queue_exit`, `serial_485_queue_extract_old`, `serial_485_queue_free`, `serial_485_queue_get_stats`, `serial_485_queue_pull`, `serial_485_queue_send`

## Microcontroller firmware (`fw/**/*.bin`)

Flashable firmware images for the printer's sub-processors (main MCU, nozzle, bed, belt, motor, RFID, CFS). These are stripped ARM Cortex-M binaries with no symbol table; they are **not** decompilable to source. Listed by content hash (several paths share identical images).

| sha1 | size | type | path(s) |
|------|------|------|---------|
| `759d05692c8d` | 6,560 | data | `fw/F008/belt/bet0_023_C03-bet0_000_001.bin`<br>`fw/F012/belt/bet0_023_C03-bet0_000_001.bin` |
| `f22e565e0eed` | 28,812 | data | `fw/F008/mcu0_130_G32-mcu0_020_000.bin` |
| `7846b42bd7f3` | 30,948 | data | `fw/F008/mcu0_140_G32-mcu0_022_000.bin` |
| `efe60e848e5d` | 116,412 | data | `fw/F008/mot0_022_C30-mot2_002_081.bin`<br>`fw/F008/mot1_022_C30-mot2_002_081.bin`<br>`fw/F008/mot2_022_C30-mot2_002_081.bin`<br>`fw/F012/mot0_022_C30-mot2_002_081.bin`<br>`fw/F012/mot1_022_C30-mot2_002_081.bin`<br>`fw/F012/mot2_022_C30-mot2_002_081.bin` |
| `466f50b0cf7b` | 116,396 | data | `fw/F008/motor/mot0_021_C30-mot2_002_081.bin`<br>`fw/F008/motor/mot0_023_C30-mot2_002_081.bin`<br>`fw/F008/motor/mot1_023_C30-mot2_002_081.bin`<br>`fw/F008/motor/mot2_023_C30-mot2_002_081.bin`<br>`fw/F012/motor/mot0_021_C30-mot2_002_081.bin`<br>`fw/F012/motor/mot0_023_C30-mot2_002_081.bin`<br>`fw/F012/motor/mot1_023_C30-mot2_002_081.bin`<br>`fw/F012/motor/mot2_023_C30-mot2_002_081.bin` |
| `212f12c6ece1` | 30,872 | data | `fw/F008/noz0_130_G30-noz0_021_000.bin`<br>`fw/F012/noz0_130_G30-noz0_021_000.bin`<br>`fw/F038/noz0_130_G30-noz0_021_000.bin` |
| `8d72d277ed7c` | 20,200 | ARM Cortex-M firmware | `fw/F008/rfid/rfd0_010_G21-rfd0_000_009.bin`<br>`fw/F012/rfid/rfd0_010_G21-rfd0_000_009.bin` |
| `285dccb0b8b1` | 30,948 | data | `fw/F012/mcu0_120_G32-mcu0_001_000.bin` |
| `2315d955a275` | 42,616 | data | `fw/K1/bed0_100_G21-bed0_004_000.bin` |
| `4e788bbf90c6` | 42,616 | data | `fw/K1/bed0_110_G21-bed0_004_000.bin` |
| `715a87b7e7b1` | 31,424 | data | `fw/K1/mcu0_110_G32-mcu0_004_000.bin` |
| `3a56edf35a9c` | 31,424 | data | `fw/K1/mcu0_120_G32-mcu0_004_000.bin` |
| `d4063704497b` | 31,440 | data | `fw/K1/noz0_110_G30-noz0_002_000.bin` |
| `f8295bac84ea` | 37,636 | data | `fw/K1/noz0_110_S06-noz0_000_000.bin` |
| `20b6625ae07d` | 31,440 | data | `fw/K1/noz0_120_G30-noz0_003_000.bin` |
| `fbe6cecc5542` | 174,820 | ARM Cortex-M firmware | `fw/cfs/cfs0_050_G30-cfs0_000_142.bin`<br>`fw/cfs/cfs0_050_G32-cfs0_000_142.bin` |

> Recoverability: firmware and Cython/C artifacts are machine code. Only the `.pyc` bytecode was recoverable to source. This is documented, not a gap in effort.
