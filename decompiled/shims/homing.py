# =====================================================================
# PARTIAL DECOMPILATION -- this module did not fully round-trip.
# The 3.9 bytecode uses control flow the decompiler could not fully
# reconstruct (e.g. try/except/else with returns, or a generator with a
# dropped builtin rendered as `None(...)`). The code below is best-effort
# and will not import as-is. Ground-truth disassembly for repair:
#     decompiled/_disasm/homing.txt
# =====================================================================

# Source Generated with Decompyle++
# File: homing.pyc (Python 3.9)

import logging
import math
import json
import os
from extras.z_align import MOTOR_PROTECT_ERROR, MOTOR_ZDOWN_TIMEOUT
HOMING_START_DELAY = 0.001
ENDSTOP_SAMPLE_TIME = 1.5e-05
ENDSTOP_SAMPLE_COUNT = 4

def multi_complete(printer, completions):
    if len(completions) == 1:
        return completions[0]
    reactor = None.get_reactor()
    cp = None((lambda e = None: [ c.wait() for c in (completions) ]
))
    for c in completions:
        None((lambda e = None, c = None: if c.wait():
cp.complete(1)))
    return cp


class StepperPosition:
    
    def __init__(self, stepper, endstop_name):
        self.stepper = stepper
        self.endstop_name = endstop_name
        self.stepper_name = stepper.get_name()
        self.start_pos = stepper.get_mcu_position()
        self.halt_pos = None
        self.trig_pos = None

    
    def note_home_end(self, trigger_time):
        self.halt_pos = self.stepper.get_mcu_position()
        self.trig_pos = self.stepper.get_past_mcu_position(trigger_time)



class HomingMove:
    
    def __init__(self, printer, endstops, toolhead = (None,)):
        self.printer = printer
        self.endstops = endstops
        if toolhead is None:
            toolhead = printer.lookup_object('toolhead')
        self.prtouch_v3 = self.printer.lookup_object('prtouch_v3') if self.printer.objects.get('prtouch_v3') else None
        self.prtouch_v3.z_full_movement_flag = False
        self.toolhead = toolhead
        self.stepper_positions = []

    
    def get_mcu_endstops(self):
        return [ es for es, name in (self.endstops) ]

    
    def _calc_endstop_rate(self, mcu_endstop, movepos, speed):
        startpos = self.toolhead.get_position()
        axes_d = [ mp - sp for mp, sp in (zip(movepos, startpos)) ]
        move_d = math.sqrt(sum([ d * d for d in (axes_d[:3]) ]))
        move_t = move_d / speed
        max_steps = None([ abs(s.calc_position_from_coord(startpos) - s.calc_position_from_coord(movepos)) / s.get_step_dist() for s in (mcu_endstop.get_steppers()) ])
        if max_steps <= 0:
            return 0.001
        return None / max_steps

    
    def calc_toolhead_pos(self, kin_spos, offsets):
        kin_spos = dict(kin_spos)
        kin = self.toolhead.get_kinematics()
        for stepper in kin.get_steppers():
            sname = stepper.get_name()
            kin_spos[sname] += offsets.get(sname, 0) * stepper.get_step_dist()
        thpos = self.toolhead.get_position()
        return list(kin.calc_position(kin_spos))[:3] + thpos[3:]

    
    def handle_force_stop(self):
        toolhead = self.printer.lookup_object('toolhead')
        toolhead._handle_shutdown()
        toolhead.reactor.pause(toolhead.reactor.monotonic() + 1)
        gcode = self.printer.lookup_object('gcode')
        gcode.run_script_from_command('MOTOR_CHECK_PROTECTION_AFTER_HOME DATA=11')
        gcode.run_script_from_command('MOTOR_STALL_MODE DATA=2')
        toolhead.can_pause = True

    
    def homing_move(self, movepos, speed, probe_pos, triggered, check_triggered = (False, True, True)):
        self.printer.send_event('homing:homing_move_begin', self)
        self.toolhead.flush_step_generation()
        kin = self.toolhead.get_kinematics()
        kin_spos = { s.get_name(): s.get_commanded_position() for s in (kin.get_steppers()) }
        self.stepper_positions = [ StepperPosition(s, name) for es, name in (self.endstops) for s in es.get_steppers() ]
        print_time = self.toolhead.get_last_move_time()
        endstop_triggers = []
        for mcu_endstop, name in self.endstops:
            rest_time = self._calc_endstop_rate(mcu_endstop, movepos, speed)
            wait = mcu_endstop.home_start(print_time, ENDSTOP_SAMPLE_TIME, ENDSTOP_SAMPLE_COUNT, rest_time, triggered=triggered)
            endstop_triggers.append(wait)
        all_endstop_trigger = multi_complete(self.printer, endstop_triggers)
        self.toolhead.dwell(HOMING_START_DELAY)
        error = None
        
        try:
            self.toolhead.drip_move(movepos, speed, all_endstop_trigger)
        except self.printer.command_error:
            e = None
            
            try:
                error = '{"code":"key20", "msg":"Error during homing move: %s", "values": [%s]}' % (str(e), str(e))
                logging.info('No trigger on %s after full movement, set MOTOR_STALL_MODE DATA=2' % name)
                self.handle_force_stop()
            finally:
                e = None
                del e
            e = None
            del e
            trigger_times = { }
            move_end_print_time = self.toolhead.get_last_move_time()
            suspended_det_status = False
            if self.prtouch_v3 is not None:
                suspended_det_status = self.prtouch_v3.get_suspended_det_status()


        for mcu_endstop, name in self.endstops:
            trigger_time = mcu_endstop.home_wait(move_end_print_time)
            if trigger_time > 0:
                trigger_times[name] = trigger_time
            elif trigger_time < 0 and error is None:
                error = '{"code":"key21", "msg":"Communication timeout during homing %s", "values": ["%s"]}' % (name, name)
                logging.info('Communication timeout during homing %s, set MOTOR_STALL_MODE DATA=2' % name)
                self.handle_force_stop()
            elif check_triggered and error is None and suspended_det_status is not True:
                error = '{"code":"key22", "msg":"No trigger on %s after full movement", "values": ["%s"]}' % (name, name)
                if name == 'z':
                    error = None
                    self.prtouch_v3.z_full_movement_flag = True
                    logging.info('No trigger on z after full movement, set MOTOR_STALL_MODE DATA=2')
                    gcode = self.printer.lookup_object('gcode')
                    gcode.run_script_from_command('MOTOR_STALL_MODE DATA=2')
            logging.info('No trigger on %s after full movement, set MOTOR_STALL_MODE DATA=2' % name)
            self.handle_force_stop()
        self.toolhead.flush_step_generation()
        for sp in self.stepper_positions:
            tt = trigger_times.get(sp.endstop_name, move_end_print_time)
            sp.note_home_end(tt)
        if probe_pos:
            halt_steps = { sp.stepper_name: sp.halt_pos - sp.start_pos for sp in (self.stepper_positions) }
            trig_steps = { sp.stepper_name: sp.trig_pos - sp.start_pos for sp in (self.stepper_positions) }
            haltpos = trigpos = self.calc_toolhead_pos(kin_spos, trig_steps)
            if trig_steps != halt_steps:
                haltpos = self.calc_toolhead_pos(kin_spos, halt_steps)
            else:
                haltpos = trigpos = movepos
                over_steps = { sp.stepper_name: sp.halt_pos - sp.trig_pos for sp in (self.stepper_positions) }
                if any(over_steps.values()):
                    self.toolhead.set_position(movepos)
                    halt_kin_spos = { s.get_name(): s.get_commanded_position() for s in (kin.get_steppers()) }
                    haltpos = self.calc_toolhead_pos(halt_kin_spos, over_steps)
        self.toolhead.set_position(haltpos)
        
        try:
            self.printer.send_event('homing:homing_move_end', self)
        except self.printer.command_error:
            e = None
            
            try:
                if error is None:
                    error = str(e)
            finally:
                e = None
                del e
            e = None
            del e
            if error is not None:
                error_data = json.loads(error.replace("'", '"'))
                if error_data.get('values') == 'probe':
                    gcode = self.printer.lookup_object('gcode')
                    gcode.run_script_from_command('Z_FAIL_PROTECT_HOTBED')
                    logging.info('Homing move end, error:%s' % error)
                raise self.printer.command_error(error)
            return trigpos



    
    def check_no_movement(self):
        if self.printer.get_start_args().get('debuginput') is not None:
            return None
        for sp in None.stepper_positions:
            if sp.start_pos == sp.trig_pos:
                return sp.endstop_name
            return None



class Homing:
    
    def __init__(self, printer):
        self.printer = printer
        self.toolhead = printer.lookup_object('toolhead')
        self.changed_axes = []
        self.trigger_mcu_pos = { }
        self.adjust_pos = { }
        self.stepper_z_sensorless_flag = False
        self.out_z_all = 0
        self.homez_info = None

    
    def set_axes(self, axes):
        self.changed_axes = axes

    
    def get_axes(self):
        return self.changed_axes

    
    def get_trigger_position(self, stepper_name):
        return self.trigger_mcu_pos[stepper_name]

    
    def set_stepper_adjustment(self, stepper_name, adjustment):
        self.adjust_pos[stepper_name] = adjustment

    
    def _fill_coord(self, coord):
