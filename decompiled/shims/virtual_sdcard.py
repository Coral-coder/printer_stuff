# =====================================================================
# PARTIAL DECOMPILATION -- this module did not fully round-trip.
# The 3.9 bytecode uses control flow the decompiler could not fully
# reconstruct (e.g. try/except/else with returns, or a generator with a
# dropped builtin rendered as `None(...)`). The code below is best-effort
# and will not import as-is. Ground-truth disassembly for repair:
#     decompiled/_disasm/virtual_sdcard.txt
# =====================================================================

# Source Generated with Decompyle++
# File: virtual_sdcard.pyc (Python 3.9)

import os
import logging
import io
import json
import time
import re
import threading
import copy
from base_info import base_dir, system_info_instance
VALID_GCODE_EXTS = [
    'gcode',
    'g',
    'gco']
LAYER_KEYS = [
    '; layer #',
    ';LAYER:',
    '; layer:',
    '; LAYER:',
    ';AFTER_LAYER_CHANGE',
    ';LAYER_CHANGE']
MAINTENANCE_ITEM = {
    'calibrate': {
        'cut_calibration': {
            'cur_value': 0 },
        'shaper_calibrate': {
            'cur_value': 0 },
        'belt_tensioning': {
            'cur_value': 0 } },
    'routine_maintenance': {
        'motion_mechanism_lubrication': {
            'cur_value': 0 },
        'camera_maintenance': {
            'cur_value': 0 },
        'fan_inspection': {
            'cur_value': 0 } },
    'machine_wear_parts_replacement': {
        'nozzle': {
            'cur_value': 0 },
        'cut': {
            'cur_value': 0 },
        'machine_teflon_tube': {
            'cur_value': 0 },
        'wipe_mouth_strip': {
            'cur_value': 0 },
        'air_filter': {
            'cur_value': 0 } },
    'cfs_wear_parts_replacement': {
        'cfs_teflon_tube': {
            'cur_value': 0 },
        'cfs_desiccant': {
            'cur_value': 0 } } }

def capture(end_print, frame = (False, 15)):
    import subprocess
    python_path = '/usr/share/klippy-env/bin/python'
    cmd_path = '/usr/share/klipper/klippy/extras/photograph.py'
    capture_shell = ''
    
    def run_cmd(capture_shell = None):
        
        try:
            logging.info(capture_shell)
            capture_ret = subprocess.check_output(capture_shell, shell=True).decode('utf-8')
            logging.info('%s return:#%s#' % (capture_shell, str(capture_ret)))
        except Exception:
            err = None
            
            try:
                logging.error(err)
            finally:
                err = None
                del err
            err = None
            del err
            return None



    if system_info_instance._h264_encoder_flag == 'NO_H264_ENCODER' and end_print == True:
        capture_shell = 'capture 0 1'
        background_thread = threading.Thread(target=run_cmd, args=(capture_shell,))
        background_thread.start()
        logging.info('background_thread capture 0 1')
        return None
    if None._h264_encoder_flag == 'NO_H264_ENCODER' and end_print == False:
        subprocess.Popen([
            python_path,
            cmd_path])
    elif system_info_instance._h264_encoder_flag == 'H264_ENCODER' and end_print == True:
        interval_time = 1 / frame
        start_time = 1
        if start_time > 0:
            run_cmd('capture 0')
            time.sleep(interval_time)
            start_time = start_time - interval_time
            continue
        else:
            capture_shell = 'capture 0'
    if capture_shell:
        run_cmd(capture_shell)


class VirtualSD:
    
    def __init__(self, config):
        self.config = config
        self.printer = config.get_printer()
        self.printer.register_event_handler('klippy:shutdown', self.handle_shutdown)
        self.printer.register_event_handler('klippy:ready', self._handle_ready)
        sd = config.get('path')
        self.offset_value = config.getfloat('offset_value', 0)
        self.forced_leveling = config.getboolean('forced_leveling', default=False)
        self.sdcard_dirname = os.path.normpath(os.path.expanduser(sd))
        self.current_file = None
        self.file_position = self.file_size = 0
        self.print_stats = self.printer.load_object(config, 'print_stats')
        self.reactor = self.printer.get_reactor()
        self.must_pause_work = self.cmd_from_sd = False
        self.next_file_position = 0
        self.work_timer = None
        gcode_macro = self.printer.load_object(config, 'gcode_macro')
        self.on_error_gcode = gcode_macro.load_template(config, 'on_error_gcode', '')
        self.gcode = self.printer.lookup_object('gcode')
        for cmd in ('M20', 'M21', 'M23', 'M24', 'M25', 'M26', 'M27'):
            self.gcode.register_command(cmd, getattr(self, 'cmd_' + cmd))
        for cmd in ('M28', 'M29', 'M30'):
            self.gcode.register_command(cmd, self.cmd_error)
        self.gcode.register_command('SDCARD_RESET_FILE', self.cmd_SDCARD_RESET_FILE, desc=self.cmd_SDCARD_RESET_FILE_help)
        self.gcode.register_command('SDCARD_PRINT_FILE', self.cmd_SDCARD_PRINT_FILE, desc=self.cmd_SDCARD_PRINT_FILE_help)
        self.gcode.register_command('SHOW_GCODE_FLUSH', self.cmd_SHOW_GCODE_FLUSH, desc=self.cmd_SHOW_GCODE_FLUSH_help)
        self.gcode.register_command('CLEAR_EEPROM_INFO', self.cmd_CLEAR_EEPROM_INFO)
        self.gcode.register_command('SET_MAINTENANCE_ITEM_VARIABLE', self.cmd_SET_MAINTENANCE_ITEM_VARIABLE)
        self.count_G1 = 0
        self.count_line = 0
        self.do_resume_status = False
        self.eepromWriteCount = 1
        self.fan_state = { }
        self.gcode_layer_path = os.path.join(base_dir, 'creality/userdata/config/gcode_layer.json')
        self.user_print_refer_path = os.path.join(base_dir, 'creality/userdata/config/user_print_refer.json')
        self.print_file_name_path = os.path.join(base_dir, 'creality/userdata/config/print_file_name.json')
        self.speed_mode_path = os.path.join(base_dir, 'creality/userdata/config/speed_mode.json')
        self.flow_rate_path = os.path.join(base_dir, 'creality/userdata/config/flow_rate.json')
        self.maintenance_item_path = os.path.join(base_dir, 'creality/userdata/config/maintenance_item.json')
        self.print_first_layer = False
        self.first_layer_stop = False
        self.count_M204 = 0
        self.layer = 0
        self.layer_count = 0
        self.is_continue_print = False
        self.restore_err = False
        self.restore_print_timer = None
        self.print_info = None
        self.XYZET = None
        self.slow_print = False
        self.slow_count = 0
        self.speed_factor = 0.0166667
        self.run_dis = 0
        self.print_id = ''
        self.cur_print_data = { }
        self.gcode_metadata = None
        self.end_print_state = False
        self.last_layer = 0
        self.is_cancel = False
        self.bed_mesh_calibate_state = False
        self.run_bed_mesh_calibate = False
        self.layer_key = ''
        self.lock = threading.Lock()
        self.is_move_out_of_range_in_printing = False
        self.ignore_M = False

    
    def _handle_ready(self):
        self._maintenance_item_timer = self.reactor.register_timer(self.update_maintenance_item_timer)
        self.reactor.update_timer(self._maintenance_item_timer, self.reactor.NOW)
        self.printer.register_event_handler('v_sd:update_cut_used', self.update_cut_used)
        self.printer.register_event_handler('v_sd:update_filament_used', self.update_filament_used)
        self.printer.register_event_handler('v_sd:cancel_power_loss_update_filament_used', self.cancel_power_loss_update_filament_used)
        self.printer.register_event_handler('v_sd:reset_cut_calibration_count', self.reset_cut_calibration_count)
        self.printer.register_event_handler('v_sd:reset_shaper_calibrate_count', self.reset_shaper_calibrate_count)
        webhooks = self.printer.lookup_object('webhooks')
        webhooks.register_endpoint('get_maintenance_item', self.get_maintenance_item)

    
    def notify_maintenance_item(self):
        maintenance_item_param = self.printer.lookup_object('gcode_macro MAINTENANCE_ITEM_PARAM', None)
        if maintenance_item_param and self.config.has_section('gcode_macro MAINTENANCE_ITEM') and os.path.exists(self.maintenance_item_path):
            
            try:
                obj = self.printer.lookup_object('gcode_macro MAINTENANCE_ITEM')
                with open(self.maintenance_item_path, 'r') as f:
                    result = json.loads(f.read())
                    result = self.maintenance_item_add_threshold(result)
                    result = self.maintenance_item_add_timeout(result)
                    obj.variables = result
         