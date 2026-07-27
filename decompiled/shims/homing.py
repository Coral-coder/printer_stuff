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
    # WARNING: Decompyle incomplete

    
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
