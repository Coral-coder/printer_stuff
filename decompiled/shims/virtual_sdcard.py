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
        interval_time = 1.0 / frame
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
        self.speed_factor = 0.016666666666666666
        self.run_dis = 0.0
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
            except Exception:
                err = None
                
                try:
                    logging.exception(err)
                finally:
                    err = None
                    del err
                err = None
                del err
                return None



    
    def calculate_filament_weight(self, filament_used, filament_diameter, filament_density = (1.75, 0.00125)):
        import math
        radius = filament_diameter / 2
        volume = math.pi * radius ** 2 * filament_used
        weight = volume * filament_density
        return weight

    
    def update_cut_used(self):
        self.update_maintenance_item(update_cut_used=True)

    
    def update_filament_used(self):
        filament_used = self.printer.lookup_object('print_stats').filament_used
        if filament_used > 0:
            weight = self.calculate_filament_weight(filament_used)
            self.update_maintenance_item(update_filament_used=True, filament_used=weight)

    
    def cancel_power_loss_update_filament_used(self):
        filament_used = 0
        
        try:
            if os.path.exists(self.print_file_name_path):
                with open(self.print_file_name_path, 'r') as f:
                    ret = json.loads(f.read())
                    filament_used = ret.get('filament_used', 0)
            if filament_used > 0:
                weight = self.calculate_filament_weight(filament_used)
                self.update_maintenance_item(update_filament_used=True, filament_used=weight)
        except Exception:
            err = None
            
            try:
                pass
            finally:
                err = None
                del err
            err = None
            del err
            return None



    
    def reset_cut_calibration_count(self):
        self.gcode.run_script_from_command('SET_MAINTENANCE_ITEM_VARIABLE NAME=calibrate VARIABLE=cut_calibration VALUE=0')

    
    def reset_shaper_calibrate_count(self):
        self.gcode.run_script_from_command('SET_MAINTENANCE_ITEM_VARIABLE NAME=calibrate VARIABLE=shaper_calibrate VALUE=0')

    
    def update_maintenance_item_timer(self, eventtime):
        self.notify_maintenance_item()
        
        try:
            if not os.path.exists(self.maintenance_item_path):
                with open(self.maintenance_item_path, 'w') as f:
                    f.write(json.dumps(MAINTENANCE_ITEM))
                    f.flush()
            print_stats = self.printer.lookup_object('print_stats')
            if print_stats.state == 'printing':
                self.update_maintenance_item()
        except Exception:
            e = None
            
            try:
                logging.error('Error in update_maintenance_item: %s' % str(e))
            finally:
                e = None
                del e
            e = None
            del e
            return eventtime + 6e+01



    
    def update_maintenance_item(self, update_cut_used, update_filament_used, filament_used, variable_update, update_item_name, variable_update_obj, reset_value = (False, False, 0, False, '', '', 0)):
        interval = 60
        with self.lock:
            if not os.path.exists(self.maintenance_item_path):
                with open(self.maintenance_item_path, 'w') as f:
                    f.write(json.dumps(MAINTENANCE_ITEM))
                    f.flush()
            else:
                result = { }
                
                try:
                    with open(self.maintenance_item_path, 'r') as f:
                        result = json.loads(f.read())
                    if not result:
                        os.remove(self.maintenance_item_path)
                return None
                if variable_update:
                    if result.get(update_item_name) and result.get(update_item_name).get(variable_update_obj):
                        result[update_item_name][variable_update_obj]['cur_value'] = reset_value
                        with open(self.maintenance_item_path, 'w') as f:
                            f.write(json.dumps(result))
                            f.flush()
                        self.notify_maintenance_item()
                None(None, None, None)
                return None
                result = self.check_item(result=result, interval=interval, update_cut_used=update_cut_used, update_filament_used=update_filament_used, filament_used=filament_used)
                with open(self.maintenance_item_path, 'w') as f:
                    f.write(json.dumps(result))
                    f.flush()
                self.notify_maintenance_item()
                except Exception:
                    err = None
                    
                    try:
                        logging.error('open maintenance_item_path err:%s' % str(err))
                        os.remove(self.maintenance_item_path)
                    finally:
                        err = None
                        del err
                    err = None
                    del err
                    if not None:
                        pass



    
    def check_item(self, result, interval, update_cut_used, update_filament_used, filament_used, max_value = (0, 0x38D7EA4C67FFF)):
        if update_cut_used:
            if result['calibrate']['cut_calibration']['cur_value'] < max_value:
                result['calibrate']['cut_calibration']['cur_value'] += 1
            if result['machine_wear_parts_replacement']['cut']['cur_value'] < max_value:
                result['machine_wear_parts_replacement']['cut']['cur_value'] += 1
            return result
        if None:
            if result['machine_wear_parts_replacement']['nozzle']['cur_value'] < max_value:
                result['machine_wear_parts_replacement']['nozzle']['cur_value'] += filament_used
            return result
        if None['calibrate']['shaper_calibrate']['cur_value'] < max_value:
            result['calibrate']['shaper_calibrate']['cur_value'] += interval
        if result['calibrate']['belt_tensioning']['cur_value'] < max_value:
            result['calibrate']['belt_tensioning']['cur_value'] += interval
        if result['routine_maintenance']['motion_mechanism_lubrication']['cur_value'] < max_value:
            result['routine_maintenance']['motion_mechanism_lubrication']['cur_value'] += interval
        if result['routine_maintenance']['camera_maintenance']['cur_value'] < max_value:
            result['routine_maintenance']['camera_maintenance']['cur_value'] += interval
        if result['routine_maintenance']['fan_inspection']['cur_value'] < max_value:
            result['routine_maintenance']['fan_inspection']['cur_value'] += interval
        if result['machine_wear_parts_replacement']['machine_teflon_tube']['cur_value'] < max_value:
            result['machine_wear_parts_replacement']['machine_teflon_tube']['cur_value'] += interval
        if result['machine_wear_parts_replacement']['wipe_mouth_strip']['cur_value'] < max_value:
            result['machine_wear_parts_replacement']['wipe_mouth_strip']['cur_value'] += interval
        if result['machine_wear_parts_replacement']['air_filter']['cur_value'] < max_value:
            result['machine_wear_parts_replacement']['air_filter']['cur_value'] += interval
        if not self.check_cfs_enable():
            return result
        if None['cfs_wear_parts_replacement']['cfs_teflon_tube']['cur_value'] < max_value:
            result['cfs_wear_parts_replacement']['cfs_teflon_tube']['cur_value'] += interval
        if result['cfs_wear_parts_replacement']['cfs_desiccant']['cur_value'] < max_value:
            result['cfs_wear_parts_replacement']['cfs_desiccant']['cur_value'] += interval
        return result

    
    def check_cfs_enable(self):
        box_enable = 0
        
        try:
            box = self.printer.lookup_object('box', None)
            if box and os.path.exists(box.box_state.tn_save_data_path):
                with open(box.box_state.tn_save_data_path, 'r') as f:
                    data = json.load(f)
                    box_enable = data.get('enable', 0)
        except Exception:
            err = None
            
            try:
                pass
            finally:
                err = None
                del err
            err = None
            del err
            return box_enable



    
    def get_maintenance_item(self, web_request):
        response = { }
        maintenance_item_param = self.printer.lookup_object('gcode_macro MAINTENANCE_ITEM_PARAM', None)
        if maintenance_item_param and os.path.exists(self.maintenance_item_path):
            
            try:
                with open(self.maintenance_item_path, 'r') as f:
                    result = json.loads(f.read())
                    result = self.maintenance_item_add_threshold(result)
                    result = self.maintenance_item_add_timeout(result)
                    response = result
            except Exception:
                err = None
                
                try:
                    logging.exception(err)
                finally:
                    err = None
                    del err
                err = None
                del err
                return response



    
    def maintenance_item_add_threshold(self, result):
        maintenance_item_param = self.printer.lookup_object('gcode_macro MAINTENANCE_ITEM_PARAM', None).variables
        result['calibrate']['cut_calibration']['threshold'] = maintenance_item_param.get('cut_calibration')
        result['calibrate']['shaper_calibrate']['threshold'] = maintenance_item_param.get('shaper_calibrate')
        result['calibrate']['belt_tensioning']['threshold'] = maintenance_item_param.get('belt_tensioning')
        result['routine_maintenance']['motion_mechanism_lubrication']['threshold'] = maintenance_item_param.get('motion_mechanism_lubrication')
        result['routine_maintenance']['camera_maintenance']['threshold'] = maintenance_item_param.get('camera_maintenance')
        result['routine_maintenance']['fan_inspection']['threshold'] = maintenance_item_param.get('fan_inspection')
        result['machine_wear_parts_replacement']['nozzle']['threshold'] = maintenance_item_param.get('nozzle')
        result['machine_wear_parts_replacement']['cut']['threshold'] = maintenance_item_param.get('cut')
        result['machine_wear_parts_replacement']['machine_teflon_tube']['threshold'] = maintenance_item_param.get('machine_teflon_tube')
        result['machine_wear_parts_replacement']['wipe_mouth_strip']['threshold'] = maintenance_item_param.get('wipe_mouth_strip')
        result['machine_wear_parts_replacement']['air_filter']['threshold'] = maintenance_item_param.get('air_filter')
        result['cfs_wear_parts_replacement']['cfs_teflon_tube']['threshold'] = maintenance_item_param.get('cfs_teflon_tube')
        result['cfs_wear_parts_replacement']['cfs_desiccant']['threshold'] = maintenance_item_param.get('cfs_desiccant')
        result['calibrate']['cut_calibration']['timeout'] = False
        result['calibrate']['shaper_calibrate']['timeout'] = False
        result['calibrate']['belt_tensioning']['timeout'] = False
        result['routine_maintenance']['motion_mechanism_lubrication']['timeout'] = False
        result['routine_maintenance']['camera_maintenance']['timeout'] = False
        result['routine_maintenance']['fan_inspection']['timeout'] = False
        result['machine_wear_parts_replacement']['nozzle']['timeout'] = False
        result['machine_wear_parts_replacement']['cut']['timeout'] = False
        result['machine_wear_parts_replacement']['machine_teflon_tube']['timeout'] = False
        result['machine_wear_parts_replacement']['wipe_mouth_strip']['timeout'] = False
        result['machine_wear_parts_replacement']['air_filter']['timeout'] = False
        result['cfs_wear_parts_replacement']['cfs_teflon_tube']['timeout'] = False
        result['cfs_wear_parts_replacement']['cfs_desiccant']['timeout'] = False
        return result

    
    def maintenance_item_add_timeout(self, result):
        maintenance_item_param = self.printer.lookup_object('gcode_macro MAINTENANCE_ITEM_PARAM', None).variables
        if result['calibrate']['cut_calibration']['cur_value'] > maintenance_item_param.get('cut_calibration'):
            result['calibrate']['cut_calibration']['timeout'] = True
        if result['calibrate']['shaper_calibrate']['cur_value'] > maintenance_item_param.get('shaper_calibrate'):
            result['calibrate']['shaper_calibrate']['timeout'] = True
        if result['calibrate']['belt_tensioning']['cur_value'] > maintenance_item_param.get('belt_tensioning'):
            result['calibrate']['belt_tensioning']['timeout'] = True
        if result['routine_maintenance']['motion_mechanism_lubrication']['cur_value'] > maintenance_item_param.get('motion_mechanism_lubrication'):
            result['routine_maintenance']['motion_mechanism_lubrication']['timeout'] = True
        if result['routine_maintenance']['camera_maintenance']['cur_value'] > maintenance_item_param.get('camera_maintenance'):
            result['routine_maintenance']['camera_maintenance']['timeout'] = True
        if result['routine_maintenance']['fan_inspection']['cur_value'] > maintenance_item_param.get('fan_inspection'):
            result['routine_maintenance']['fan_inspection']['timeout'] = True
        if result['machine_wear_parts_replacement']['nozzle']['cur_value'] > maintenance_item_param.get('nozzle'):
            result['machine_wear_parts_replacement']['nozzle']['timeout'] = True
        if result['machine_wear_parts_replacement']['cut']['cur_value'] > maintenance_item_param.get('cut'):
            result['machine_wear_parts_replacement']['cut']['timeout'] = True
        if result['machine_wear_parts_replacement']['machine_teflon_tube']['cur_value'] > maintenance_item_param.get('machine_teflon_tube'):
            result['machine_wear_parts_replacement']['machine_teflon_tube']['timeout'] = True
        if result['machine_wear_parts_replacement']['wipe_mouth_strip']['cur_value'] > maintenance_item_param.get('wipe_mouth_strip'):
            result['machine_wear_parts_replacement']['wipe_mouth_strip']['timeout'] = True
        if result['machine_wear_parts_replacement']['air_filter']['cur_value'] > maintenance_item_param.get('air_filter'):
            result['machine_wear_parts_replacement']['air_filter']['timeout'] = True
        if result['cfs_wear_parts_replacement']['cfs_teflon_tube']['cur_value'] > maintenance_item_param.get('cfs_teflon_tube'):
            result['cfs_wear_parts_replacement']['cfs_teflon_tube']['timeout'] = True
        if result['cfs_wear_parts_replacement']['cfs_desiccant']['cur_value'] > maintenance_item_param.get('cfs_desiccant'):
            result['cfs_wear_parts_replacement']['cfs_desiccant']['timeout'] = True
        return result

    
    def cmd_SET_MAINTENANCE_ITEM_VARIABLE(self, gcmd):
        name = gcmd.get('NAME', '')
        variable = gcmd.get('VARIABLE', '')
        value = gcmd.get_int('VALUE', 0)
        if name and variable:
            self.update_maintenance_item(variable_update=True, update_item_name=name, variable_update_obj=variable, reset_value=value)

    
    def handle_shutdown(self):
        if self.work_timer is not None:
            self.must_pause_work = True
            
            try:
                readpos = max(self.file_position - 1024, 0)
                readcount = self.file_position - readpos
                self.current_file.seek(readpos)
                data = self.current_file.read(readcount + 128)
            except:
                logging.exception('virtual_sdcard shutdown read')
                return None

            logging.info('Virtual sdcard (%d): %s\nUpcoming (%d): %s', readpos, repr(data[:readcount]), self.file_position, repr(data[readcount:]))
        self.print_first_layer = False
        self.first_layer_stop = False
        self.print_stats.power_loss = 0
        self.count_M204 = 0
        self.fan_state = { }

    
    def stats(self, eventtime):
        if self.work_timer is None:
            return (False, '')
        return (None, 'sd_pos=%d' % (self.file_position,))

    
    def get_file_list(self, check_subdirs = (False,)):
        if check_subdirs:
            flist = []
            for root, dirs, files in os.walk(self.sdcard_dirname, followlinks=True):
                for name in files:
                    ext = name[name.rfind('.') + 1:]
                    if ext not in VALID_GCODE_EXTS:
                        continue
                    full_path = os.path.join(root, name)
                    r_path = full_path[len(self.sdcard_dirname) + 1:]
                    size = os.path.getsize(full_path)
                    flist.append((r_path, size))
            return sorted(flist, key=(lambda f: f[0].lower()))
        dname = None.sdcard_dirname
        
        try:
            filenames = os.listdir(self.sdcard_dirname)
        return None
        logging.exception('virtual_sdcard get_file_list')
        raise self.gcode.error('Unable to get file list')


    
    def get_status(self, eventtime):
        res = copy.deepcopy({
            'file_path': self.file_path(),
            'progress': self.progress(),
            'is_active': self.is_active(),
            'file_position': self.file_position,
            'file_size': self.file_size,
            'first_layer_stop': self.first_layer_stop,
            'layer': self.layer,
            'layer_count': self.layer_count,
            'run_dis': self.run_dis,
            'bed_mesh_calibate_state': self.bed_mesh_calibate_state,
            'cur_print_data': self.cur_print_data.get('jobs', [])[0] if self.cur_print_data.get('jobs', []) else { } })
        return res

    
    def file_path(self):
        if self.current_file:
            return self.current_file.name

    
    def progress(self):
        if self.file_size:
            return float(self.file_position) / self.file_size
        return None

    
    def is_active(self):
        return self.work_timer is not None

    
    def do_pause(self):
        if self.work_timer is not None:
            self.must_pause_work = True
            if not self.work_timer is not None and self.cmd_from_sd:
                self.reactor.pause(self.reactor.monotonic() + 0.001)
                continue

    
    def do_resume(self):
        if self.work_timer is not None:
            raise self.gcode.error('SD busy')
        self.must_pause_work = False
        self.work_timer = self.reactor.register_timer(self.work_handler, self.reactor.NOW)

    
    def do_cancel(self):
        self.printer.send_event('v_sd:update_filament_used')
        self.reactor.pause(self.reactor.monotonic() + 0.2)
        self.is_cancel = True
        self.print_stats.power_loss = 0
        self.first_layer_stop = False
        self.print_first_layer = False
        self.count_M204 = 0
        self.layer = 0
        self.layer_count = 0
        self.fan_state = { }
        self.resume_print_speed()
        if self.current_file is not None:
            self.do_pause()
            self.current_file.close()
            self.current_file = None
            self.print_stats.note_cancel()
        self.is_cancel = False
        self.file_position = self.file_size = 0.0
        self.ignore_M = False

    
    def cmd_CLEAR_EEPROM_INFO(self, gcmd):
        call = call
        import subprocess
        if os.path.exists(self.print_file_name_path):
            os.remove(self.print_file_name_path)
        if os.path.exists(self.gcode.exclude_object_info):
            os.remove(self.gcode.exclude_object_info)
        call('sync', shell=True)
        
        try:
            power_loss_switch = False
            if os.path.exists(self.user_print_refer_path):
                with open(self.user_print_refer_path, 'r') as f:
                    data = json.loads(f.read())
                    power_loss_switch = data.get('power_loss', { }).get('switch', False)
            bl24c16f = self.printer.lookup_object('bl24c16f') if 'bl24c16f' in self.printer.objects else None
            if power_loss_switch and bl24c16f:
                bl24c16f.setEepromDisable()
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



    
    def cmd_error(self, gcmd):
        raise gcmd.error('SD write not supported')

    
    def _reset_file(self):
        if self.current_file is not None:
            self.do_pause()
            self.current_file.close()
            self.current_file = None
        self.file_position = self.file_size = 0.0
        self.print_stats.reset()
        self.printer.send_event('virtual_sdcard:reset_file')

    cmd_SDCARD_RESET_FILE_help = 'Clears a loaded SD File. Stops the print if necessary'
    
    def cmd_SDCARD_RESET_FILE(self, gcmd):
        if self.cmd_from_sd:
            raise gcmd.error('SDCARD_RESET_FILE cannot be run from the sdcard')
        self._reset_file()

    cmd_SDCARD_PRINT_FILE_help = 'Loads a SD file and starts the print.  May include files in subdirectories.'
    
    def cmd_SDCARD_PRINT_FILE(self, gcmd):
        if self.config.has_section('motor_control') and self.config.getsection('motor_control').getint('switch') == 1 and self.printer.lookup_object('motor_control').is_ready == False:
            self.gcode.respond_info('The motor parameters are initializing, Please try again later...')
            return None
        if None.config.has_section('prtouch_v3') and self.bed_mesh_calibate_state == False and gcmd.get('ISCONTINUEPRINT', False) == False and self.forced_leveling:
            self.run_bed_mesh_calibate = True
        self.end_print_state = False
        self.layer_key = ''
        self.print_id = ''
        if self.work_timer is not None:
            raise gcmd.error('SD busy')
        self._reset_file()
        filename = gcmd.get('FILENAME')
        self.is_continue_print = gcmd.get('ISCONTINUEPRINT', False)
        if self.printer.lookup_object('box', None):
            self.printer.lookup_object('box').box_state.is_continue_print = gcmd.get('ISCONTINUEPRINT', False)
        self.rm_power_loss_info()
        first_floor = gcmd.get('FIRST_FLOOR_PRINT', None)
        if first_floor is None or first_floor == False:
            self.print_first_layer = False
        else:
            self.print_first_layer = True
        if filename[0] == '/':
            filename = filename[1:]
        self._load_file(gcmd, filename, check_subdirs=True)
        self.load_gcode_metadata(str(self.current_file.name))
        self.record_print_history(str(self.current_file.name))
        self.do_resume()

    cmd_SHOW_GCODE_FLUSH_help = 'Load SD file and display multi-color gcode material change flushing parameters.'
    
    def cmd_SHOW_GCODE_FLUSH(self, gcmd):
        if self.work_timer is not None:
            raise gcmd.error('SD busy')
        filename = gcmd.get('FILENAME')
        if filename is None:
            logging.warning('Invalid FILENAME parameter')
            return None
        if None[0] == '/':
            filename = filename[1:]
        self.load_gcode_metadata(str(filename))
        flush_para = self.get_gcode_flush_para()
        if flush_para is None:
            logging.warning('Error in getting flushing parameters')
            return None
        None.gcode.respond_info('shwo gcode flush para: %s' % flush_para)

    
    def load_gcode_metadata(self, file_path = ('',)):
        self.gcode_metadata = self.get_print_file_metadata(file_path)
        logging.info('gcode_metadata: %s' % self.gcode_metadata)

    
    def record_print_history(self, file_path = ('',)):
        
        try:
            if os.path.exists(file_path):
                dir_path = os.path.dirname(file_path)
                file_name = os.path.basename(file_path)
                metadata_info = self.get_print_file_metadata(filename=file_name, filepath=dir_path)
                self.layer_count = self.get_file_layer_count(self.current_file.name, metadata_info=metadata_info)
                start_time = time.time()
                self.print_id = str(start_time)
                metadata = metadata_info.get('metadata', { })
                json_to_write = {
                    'print_id': self.print_id }
                with open('/tmp/cx_print_id.json', 'w') as f:
                    json.dump(json_to_write, f)
                    f.flush()
                data = {
                    'end_time': start_time,
                    'filament_used': 0,
                    'filename': file_name,
                    'metadata': metadata,
                    'print_duration': 0,
                    'start_time': start_time,
                    'status': 'in_progress',
                    'total_duration': 0 }
                result = {
                    'count': 1,
                    'jobs': [
                        data] }
                self.cur_print_data = result
        return None
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



    
    def update_print_history_info(self, only_update_status, state, error_msg = (False, '', '')):
        if self.print_id:
            ret = { }
            
            try:
                update_obj = None
                index = -1
                ret = self.cur_print_data
                if ret and ret.get('jobs', []):
                    print_list = ret.get('jobs', [])
                    for obj in print_list:
                        if obj.get('start_time', '') and str(obj.get('start_time', '')) == self.print_id:
                            index = print_list.index(obj)
                            update_obj = obj
                            if not only_update_status:
                                update_obj['filament_used'] = self.print_stats.filament_used
                                update_obj['print_duration'] = self.print_stats.print_duration
                                update_obj['total_duration'] = self.print_stats.total_duration
                        update_obj['end_time'] = time.time()
                        if not state:
                            state = 'in_progress'
                        if error_msg:
                            update_obj['error_msg'] = error_msg
                        update_obj['status'] = state
                if index != -1:
                    print_list[index] = update_obj
                    ret['jobs'] = print_list
                    self.cur_print_data = ret
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



    
    def rm_power_loss_info(self):
        if self.is_continue_print and os.path.exists(self.print_file_name_path):
            
            try:
                power_loss_switch = False
                with open(self.user_print_refer_path, 'r') as f:
                    data = json.loads(f.read())
                    power_loss_switch = data.get('power_loss', { }).get('switch', False)
                bl24c16f = self.printer.lookup_object('bl24c16f') if 'bl24c16f' in self.printer.objects and power_loss_switch else None
                if power_loss_switch and bl24c16f:
                    os.remove(self.print_file_name_path)
                    if os.path.exists(self.gcode.exclude_object_info):
                        os.remove(self.gcode.exclude_object_info)
                    self.gcode.run_script_from_command('EEPROM_WRITE_BYTE ADDR=1 VAL=255')
                    logging.info('rm power_loss info success')
            except Exception:
                err = None
                
                try:
                    logging.error('rm power_loss info fail, err:%s' % err)
                finally:
                    err = None
                    del err
                err = None
                del err
                return None



    
    def cmd_M20(self, gcmd):
        files = self.get_file_list()
        gcmd.respond_raw('Begin file list')
        for fname, fsize in files:
            gcmd.respond_raw('%s %d' % (fname, fsize))
        gcmd.respond_raw('End file list')

    
    def cmd_M21(self, gcmd):
        gcmd.respond_raw('SD card ok')

    
    def cmd_M23(self, gcmd):
        if self.work_timer is not None:
            raise gcmd.error('SD busy')
        self._reset_file()
        filename = gcmd.get_raw_command_parameters().strip()
        if filename.startswith('/'):
            filename = filename[1:]
        self._load_file(gcmd, filename)

    
    def _load_file(self, gcmd, filename, check_subdirs = (False,)):
        files = self.get_file_list(check_subdirs)
        flist = [ f[0] for f in (files) ]
        files_by_lower = { fname.lower(): fname for fname, fsize in (files) }
        fname = filename
        
        try:
            if fname not in flist:
                fname = files_by_lower[fname.lower()]
            fname = os.path.join(self.sdcard_dirname, fname)
            f = io.open(fname, 'r', newline='')
            f.seek(0, os.SEEK_END)
            fsize = f.tell()
            f.seek(0)
        except:
            logging.exception('virtual_sdcard file open')
            return None

        gcmd.respond_raw('File opened:%s Size:%d' % (filename, fsize))
        gcmd.respond_raw('File selected')
        self.current_file = f
        self.file_position = 0
        self.file_size = fsize
        self.print_stats.set_current_file(filename)

    
    def cmd_M24(self, gcmd):
        self.do_resume()

    
    def cmd_M25(self, gcmd):
        self.do_pause()

    
    def cmd_M26(self, gcmd):
        if self.work_timer is not None:
            raise gcmd.error('SD busy')
        pos = gcmd.get_int('S', minval=0)
        self.file_position = pos

    
    def cmd_M27(self, gcmd):
        if self.current_file is None:
            gcmd.respond_raw('Not SD printing.')
            return None
        None.respond_raw('SD printing byte %d/%d' % (self.file_position, self.file_size))

    
    def get_file_position(self):
        return self.next_file_position

    
    def set_file_position(self, pos):
        self.next_file_position = pos

    
    def is_cmd_from_sd(self):
        return self.cmd_from_sd

    
    def tail_read(self, f):
