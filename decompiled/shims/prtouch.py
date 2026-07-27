# =====================================================================
# PARTIAL DECOMPILATION -- this module did not fully round-trip.
# The 3.9 bytecode uses control flow the decompiler could not fully
# reconstruct (e.g. try/except/else with returns, or a generator with a
# dropped builtin rendered as `None(...)`). The code below is best-effort
# and will not import as-is. Ground-truth disassembly for repair:
#     decompiled/_disasm/prtouch.txt
# =====================================================================

# Source Generated with Decompyle++
# File: prtouch.pyc (Python 3.9)

import logging
import math
import random
from . import probe
import mcu
import time
import socket

class PRTouchCFG:
    
    def __init__(self, config):
        self.base_count = config.getint('base_count', default=40, minval=10, maxval=100)
        self.pi_count = config.getint('pi_count', default=32, minval=16, maxval=128)
        self.min_hold = config.getint('min_hold', default=3000, minval=100, maxval=50000)
        self.max_hold = config.getint('max_hold', default=50000, minval=100, maxval=100000)
        self.hot_min_temp = config.getfloat('s_hot_min_temp', default=140, minval=80, maxval=200)
        self.hot_max_temp = config.getfloat('s_hot_max_temp', default=200, minval=180, maxval=300)
        self.bed_max_temp = config.getfloat('s_bed_max_temp', default=60, minval=45, maxval=100)
        self.pa_fil_len_mm = config.getint('pa_fil_len_mm', default=2, minval=2, maxval=100)
        self.pa_fil_dis_mm = config.getint('pa_fil_dis_mm', default=30, minval=2, maxval=100)
        self.pa_clr_dis_mm = config.getint('pa_clr_dis_mm', default=20, minval=2, maxval=100)
        self.pa_clr_down_mm = config.getfloat('pa_clr_down_mm', default=-0.1, minval=-1, maxval=1)
        self.clr_noz_start_x = config.getfloat('clr_noz_start_x', default=0, minval=0, maxval=1000)
        self.clr_noz_start_y = config.getfloat('clr_noz_start_y', default=0, minval=0, maxval=1000)
        self.clr_noz_len_x = config.getfloat('clr_noz_len_x', default=0, minval=self.pa_clr_dis_mm + 6, maxval=1000)
        self.clr_noz_len_y = config.getfloat('clr_noz_len_y', default=0, minval=0, maxval=1000)
        self.bed_max_err = config.getint('bed_max_err', default=2, minval=2, maxval=10)
        self.max_z = config.getsection('stepper_z').getfloat('position_max', default=300, minval=100, maxval=500)
        self.g29_xy_speed = config.getfloat('g29_xy_speed', default=150, minval=10, maxval=1000)
        self.fix_z_offset = config.getfloat('fix_z_offset', default=0, minval=-1, maxval=1)
        self.max_dis_bef_g28 = config.getfloat('max_dis_bef_g28', default=10, minval=0, maxval=50)
        self.dead_zone_bef_g28 = config.getfloat('dead_zone_bef_g28', default=self.max_dis_bef_g28 / 2, minval=0, maxval=50)
        self.g28_sta0_speed = config.getfloat('g28_sta0_speed', default=2, minval=0.1, maxval=10)
        self.g28_sta1_speed = config.getfloat('g28_sta1_speed', default=2.5, minval=0.1, maxval=10)
        self.g29_rdy_speed = config.getfloat('g29_rdy_speed', default=2.5, minval=0.1, maxval=10)
        self.g29_speed = config.getfloat('g29_speed', default=2, minval=0.1, maxval=10)
        self.show_msg = config.getboolean('show_msg', default=False)
        self.best_above_z = config.getfloat('best_above_z', default=1.5, minval=0.5, maxval=10)
        self.g28_wait_cool_down = config.getboolean('g28_wait_cool_down', default=False)
        self.shake_cnt = config.getint('shake_cnt', default=4, minval=1, maxval=512)
        self.shake_range = config.getint('shake_range', default=0.5, minval=0.1, maxval=2)
        self.shake_max_velocity = config.getfloat('shake_max_velocity', default=100, minval=1, maxval=5000)
        self.shake_max_accel = config.getfloat('shake_max_accel', default=1000, minval=1, maxval=50000)
        self.g28_sta0_min_hold = config.getint('g28_sta0_min_hold', default=self.min_hold * 2, minval=100, maxval=100000)
        self.need_measure_gap = config.getboolean('need_measure_gap', default=True)
        self.gap_dis_range = config.getfloat('gap_dis_range', default=0.6, minval=0.2, maxval=2)
        self.z_gap_00 = config.getfloat('z_gap_00', default=0, minval=-1, maxval=1)
        self.z_gap_01 = config.getfloat('z_gap_01', default=0, minval=-1, maxval=1)
        self.z_gap_10 = config.getfloat('z_gap_10', default=0, minval=-1, maxval=1)
        self.z_gap_11 = config.getfloat('z_gap_11', default=0, minval=-1, maxval=1)
        self.check_bed_mesh_max_err = config.getfloat('check_bed_mesh_max_err', default=0.2, minval=0.01, maxval=1)
        self.tri_wave_ip = config.get('tri_wave_ip', None)
        self.self_z_offset = config.getfloat('self_z_offset', default=0, minval=-2, maxval=2)
        self.stored_profs = config.get_prefix_sections('prtouch')
        self.stored_profs = self.stored_profs[1] if len(self.stored_profs) == 2 and self.need_measure_gap else None



class PRTouchVAL:
    
    def __init__(self, config):
        self.out_index = 0
        self.out_val_mm = 0
        self.rdy_pos = [
            [
                0,
                0,
                0] * 4]
        self.gap_pos = None
        self.g29_cnt = int(0)
        self.re_probe_cnt = 0
        self.home_xy = None
        self.jump_probe_ready = False



class PRTouchOBJ:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        self.toolhead = None
        self.hx711s = None
        self.pheaters = None
        self.heater_hot = None
        self.heater_bed = None
        self.bed_mesh = None
        self.mcu = None
        self.dirzctl = None
        self.kin = None
        self.gcode = self.printer.lookup_object('gcode')

    
    def find_objs(self):
        self.toolhead = self.printer.lookup_object('toolhead')
        self.hx711s = self.printer.lookup_object('hx711s')
        self.pheaters = self.printer.lookup_object('heaters')
        self.heater_hot = self.printer.lookup_object('extruder').heater
        self.heater_bed = self.printer.lookup_object('heater_bed').heater
        self.bed_mesh = self.printer.lookup_object('bed_mesh')
        self.dirzctl = self.printer.lookup_object('dirzctl')
        self.mcu = self.hx711s.mcu
        self.filter = self.printer.lookup_object('filter')
        self.kin = self.toolhead.get_kinematics()



class PRTouchEndstopWrapper:
    
    def __init__(self, config):
        self.cfg = PRTouchCFG(config)
        self.val = PRTouchVAL(config)
        self.obj = PRTouchOBJ(config)
        self.obj.printer.register_event_handler('klippy:mcu_identify', self._handle_mcu_identify)
        self.obj.gcode.register_command('PRTOUCH_TEST', self.cmd_PRTOUCH_TEST, desc=self.cmd_PRTOUCH_TEST_help)
        self.obj.gcode.register_command('PRTOUCH_READY', self.cmd_PRTOUCH_READY, desc=self.cmd_PRTOUCH_READY_help)
        self.obj.gcode.register_command('NOZZLE_CLEAR', self.cmd_NOZZLE_CLEAR, desc=self.cmd_NOZZLE_CLEAR_help)
        self.obj.gcode.register_command('CHECK_BED_MESH', self.cmd_CHECK_BED_MESH, desc=self.cmd_CHECK_BED_MESH_help)
        self.obj.gcode.register_command('MEASURE_GAP_TEST', self.cmd_MEASURE_GAP_TEST, desc=self.cmd_MEASURE_GAP_TEST_help)

    
    def _handle_mcu_identify(self):
        self.obj.find_objs()
        (min_x, min_y) = self.obj.bed_mesh.bmc.mesh_min
        (max_x, max_y) = self.obj.bed_mesh.bmc.mesh_max
        self.val.rdy_pos = [
            [
                min_x,
                min_y,
                self.cfg.bed_max_err + 1],
            [
                min_x,
                max_y,
                self.cfg.bed_max_err + 1],
            [
                max_x,
                max_y,
                self.cfg.bed_max_err + 1],
            [
                max_x,
                min_y,
                self.cfg.bed_max_err + 1]]
        self.val.gap_pos = [
            [
                min_x + 1,
                min_y + 1,
                self.cfg.z_gap_00],
            [
                min_x + 1,
                max_y - 1,
                self.cfg.z_gap_01],
            [
                max_x - 1,
                max_y - 1,
                self.cfg.z_gap_11],
            [
                max_x - 1,
                min_y + 1,
                self.cfg.z_gap_10]]
        if self.cfg.clr_noz_start_x <= 0 and self.cfg.clr_noz_start_y <= 0 and self.cfg.clr_noz_len_x <= 0 or self.cfg.clr_noz_len_y <= 0:
            self.cfg.clr_noz_start_x = (max_x - min_x) * 1 / 3 + min_x
            self.cfg.clr_noz_start_y = max_y - 6
            self.cfg.clr_noz_len_x = (max_x - min_x) * 1 / 3
            self.cfg.clr_noz_len_y = 5
        self.val.home_xy = [
            (max_x - min_x) / 2 + min_x,
            (max_y - min_y) / 2 + min_y]

    
    def get_mcu(self):
        return self.obj.mcu

    
    def multi_probe_begin(self):
        pass

    
    def multi_probe_end(self):
        pass

    
    def probe_prepare(self, hmove):
        pass

    
    def home_start(self, print_time, sample_time, sample_count, rest_time, triggered = (True,)):
        return True

    
    def add_stepper(self, stepper):
        pass

    
    def get_steppers(self):
        return self.obj.dirzctl.steppers

    
    def ck_sys_sta(self):
        if not (self.obj.hx711s.is_shutdown) and not (self.obj.hx711s.is_timeout) and not (self.obj.dirzctl.is_shutdown):
            pass
        return not (self.obj.dirzctl.is_timeout)

    
    def _ck_g28ed(self, is_precision = (True,)):
        for i in range(3):
            if self.obj.kin.limits[i][0] > self.obj.kin.limits[i][1]:
                self.obj.gcode.run_script_from_command('G28')
            
            return None

    
    def _move(self, pos, speed, wait = (True,)):
        if not self.obj.hx711s.is_shutdown and self.obj.hx711s.is_timeout and self.obj.dirzctl.is_shutdown and self.obj.dirzctl.is_timeout:
            self.obj.gcode.run_script_from_command('G1 F%d X%.3f Y%.3f Z%.3f' % (speed * 60, pos[0], pos[1], pos[2]) if len(pos) >= 3 else 'G1 F%d X%.3f Y%.3f' % (speed * 60, pos[0], pos[1]))
            if wait:
                self.obj.toolhead.wait_moves()

    
    def _check_index(self, index):
        if index <= self.cfg.pi_count - 3 and index >= self.cfg.pi_count * 2 / 3:
            return True

    
    def _get_linear2(self, p1, p2, po, is_base_x):
        if not (math.fabs(p1[0] - p2[0]) < 0.001 or is_base_x or math.fabs(p1[1] - p2[1]) < 0.001) and is_base_x:
            return po
        a = (None[2] - p1[2]) / p2[0] - p1[0] if is_base_x else p2[1] - p1[1]
        b = p1[2] - p1[0] if is_base_x else p1[1] * a
        po[2] = a * po[0] if is_base_x else po[1] + b
        return po

    
    def _pnt_tri_msg(self, index, msg, ary):
        if self.cfg.show_msg:
            self.pnt_msg('TRI SUCCESS BY: ' + msg)
            self.pnt_array('TRI CH=%d ARY=' % index, ary)

    
    def _check_trigger(self, arg_index, fit_vals, unfit_vals, min_hold, max_hold):
        (all_params, tick) = self.obj.dirzctl.get_params()
        if len(all_params) == 2:
            self._pnt_tri_msg(arg_index, 'Tri by Dirzctl run over!', fit_vals)
            return True
        fit_vals_t = (lambda 