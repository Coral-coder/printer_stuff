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
        pass
    # WARNING: Decompyle incomplete

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
        self.gcode.register_command('SDCARD_PRINT_FILE', self.cmd_SDCARD_PRINT_FILE, self.cmd