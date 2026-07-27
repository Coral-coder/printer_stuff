# Source Generated with Decompyle++
# File: manual_probe.pyc (Python 3.9)

import logging
import bisect

class ManualProbe:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        self.gcode = self.printer.lookup_object('gcode')
        self.gcode_move = self.printer.load_object(config, 'gcode_move')
        self.gcode.register_command('MANUAL_PROBE', self.cmd_MANUAL_PROBE, desc=self.cmd_MANUAL_PROBE_help)
        zconfig = config.getsection('stepper_z')
        self.z_position_endstop = zconfig.getfloat('position_endstop', None, note_valid=False)
        a_tower_config = config.getsection('stepper_a')
        self.a_position_endstop = a_tower_config.getfloat('position_endstop', None, note_valid=False)
        b_tower_config = config.getsection('stepper_b')
        self.b_position_endstop = b_tower_config.getfloat('position_endstop', None, note_valid=False)
        c_tower_config = config.getsection('stepper_c')
        self.c_position_endstop = c_tower_config.getfloat('position_endstop', None, note_valid=False)
        if self.z_position_endstop is not None:
            self.gcode.register_command('Z_ENDSTOP_CALIBRATE', self.cmd_Z_ENDSTOP_CALIBRATE, desc=self.cmd_Z_ENDSTOP_CALIBRATE_help)
            self.gcode.register_command('Z_OFFSET_APPLY_ENDSTOP', self.cmd_Z_OFFSET_APPLY_ENDSTOP, desc=self.cmd_Z_OFFSET_APPLY_ENDSTOP_help)
        if 'delta' == config.getsection('printer').get('kinematics'):
            self.gcode.register_command('Z_OFFSET_APPLY_ENDSTOP', self.cmd_Z_OFFSET_APPLY_DELTA_ENDSTOPS, desc=self.cmd_Z_OFFSET_APPLY_ENDSTOP_help)
        self.reset_status()

    
    def manual_probe_finalize(self, kin_pos):
        if kin_pos is not None:
            self.gcode.respond_info('Z position is %.3f' % (kin_pos[2],))

    
    def reset_status(self):
        self.status = {
            'is_active': False,
            'z_position': None,
            'z_position_lower': None,
            'z_position_upper': None }

    
    def get_status(self, eventtime):
        return self.status

    cmd_MANUAL_PROBE_help = 'Start manual probe helper script'
    
    def cmd_MANUAL_PROBE(self, gcmd):
        ManualProbeHelper(self.printer, gcmd, self.manual_probe_finalize)

    
    def z_endstop_finalize(self, kin_pos):
        if kin_pos is None:
            return None
        z_pos = None.z_position_endstop - kin_pos[2]
        self.gcode.respond_info('stepper_z: position_endstop: %.3f\nThe SAVE_CONFIG command will update the printer config file\nwith the above and restart the printer.' % (z_pos,))
        configfile = self.printer.lookup_object('configfile')
        configfile.set('stepper_z', 'position_endstop', '%.3f' % (z_pos,))

    cmd_Z_ENDSTOP_CALIBRATE_help = 'Calibrate a Z endstop'
    
    def cmd_Z_ENDSTOP_CALIBRATE(self, gcmd):
        ManualProbeHelper(self.printer, gcmd, self.z_endstop_finalize)

    
    def cmd_Z_OFFSET_APPLY_ENDSTOP(self, gcmd):
        offset = self.gcode_move.get_status()['homing_origin'].z
        configfile = self.printer.lookup_object('configfile')
        if offset == 0:
            self.gcode.respond_info('Nothing to do: Z Offset is 0')
        else:
            new_calibrate = self.z_position_endstop - offset
            self.gcode.respond_info('stepper_z: position_endstop: %.3f\nThe SAVE_CONFIG command will update the printer config file\nwith the above and restart the printer.' % new_calibrate)
            configfile.set('stepper_z', 'position_endstop', '%.3f' % (new_calibrate,))

    
    def cmd_Z_OFFSET_APPLY_DELTA_ENDSTOPS(self, gcmd):
        offset = self.gcode_move.get_status()['homing_origin'].z
        configfile = self.printer.lookup_object('configfile')
        if offset == 0:
            self.gcode.respond_info('Nothing to do: Z Offset is 0')
        else:
            new_a_calibrate = self.a_position_endstop - offset
            new_b_calibrate = self.b_position_endstop - offset
            new_c_calibrate = self.c_position_endstop - offset
            self.gcode.respond_info('stepper_a: position_endstop: %.3f\nstepper_b: position_endstop: %.3f\nstepper_c: position_endstop: %.3f\nThe SAVE_CONFIG command will update the printer config file\nwith the above and restart the printer.' % (new_a_calibrate, new_b_calibrate, new_c_calibrate))
            configfile.set('stepper_a', 'position_endstop', '%.3f' % (new_a_calibrate,))
            configfile.set('stepper_b', 'position_endstop', '%.3f' % (new_b_calibrate,))
            configfile.set('stepper_c', 'position_endstop', '%.3f' % (new_c_calibrate,))

    cmd_Z_OFFSET_APPLY_ENDSTOP_help = 'Adjust the z endstop_position'


def verify_no_manual_probe(printer):
    gcode = printer.lookup_object('gcode')
# WARNING: Decompyle incomplete

Z_BOB_MINIMUM = 0.5
BISECT_MAX = 0.2

class ManualProbeHelper:
    
    def __init__(self, printer, gcmd, finalize_callback):
        self.printer = printer
        self.finalize_callback = finalize_callback
        self.gcode = self.printer.lookup_object('gcode')
        self.toolhead = self.printer.lookup_object('toolhead')
        self.manual_probe = self.printer.lookup_object('manual_probe')
        self.speed = gcmd.get_float('SPEED', 5)
        self.past_positions = []
        self.last_toolhead_pos = None
        self.last_kinematics_pos = None
        verify_no_manual_probe(printer)
        self.gcode.register_command('ACCEPT', self.cmd_ACCEPT, desc=self.cmd_ACCEPT_help)
        self.gcode.register_command('NEXT', self.cmd_ACCEPT)
        self.gcode.register_command('ABORT', self.cmd_ABORT, desc=self.cmd_ABORT_help)
        self.gcode.register_command('TESTZ', self.cmd_TESTZ, desc=self.cmd_TESTZ_help)
        self.gcode.respond_info('Starting manual Z probe. Use TESTZ to adjust position.\nFinish with ACCEPT or ABORT command.')
        self.start_position = self.toolhead.get_position()
        self.report_z_status()

    
    def get_kinematics_pos(self):
        toolhead_pos = self.toolhead.get_position()
        if toolhead_pos == self.last_toolhead_pos:
            return self.last_kinematics_pos
        None.toolhead.flush_step_generation()
        kin = self.toolhead.get_kinematics()
        kin_spos = { s.get_name(): s.get_commanded_position() for s in (kin.get_steppers()) }
        kin_pos = kin.calc_position(kin_spos)
        self.last_toolhead_pos = toolhead_pos
        self.last_kinematics_pos = kin_pos
        return kin_pos

    
    def move_z(self, z_pos):
        curpos = self.toolhead.get_position()
    # WARNING: Decompyle incomplete

    
    def report_z_status(self, warn_no_change, prev_pos = (False, None)):
        kin_pos = self.get_kinematics_pos()
        z_pos = kin_pos[2]
        if warn_no_change and z_pos == prev_pos:
            self.gcode.respond_info('WARNING: No change in position (reached stepper resolution)')
        pp = self.past_positions
        next_pos = bisect.bisect_left(pp, z_pos)
        prev_pos = next_pos - 1
        if next_pos < len(pp) and pp[next_pos] == z_pos:
            next_pos += 1
        prev_pos_val = None
        next_pos_val = None
        prev_str = next_str = '??????'
        if prev_pos >= 0:
            prev_pos_val = pp[prev_pos]
            prev_str = '%.3f' % (prev_pos_val,)
        if next_pos < len(pp):
            next_pos_val = pp[next_pos]
            next_str = '%.3f' % (next_pos_val,)
        self.manual_probe.status = {
            'is_active': True,
            'z_position': z_pos,
            'z_position_lower': prev_pos_val,
            'z_position_upper': next_pos_val }
        self.gcode.respond_info('Z position: %s --> %.3f <-- %s' % (prev_str, z_pos, next_str))

    cmd_ACCEPT_help = 'Accept the current Z position'
    
    def cmd_ACCEPT(self, gcmd):
        pos = self.toolhead.get_position()
        start_pos = self.start_position
        if pos[:2] != start_pos[:2] or pos[2] >= start_pos[2]:
            gcmd.respond_info('Manual probe failed! Use TESTZ commands to position the\nnozzle prior to running ACCEPT.')
            self.finalize(False)
            return None
        None.finalize(True)

    cmd_ABORT_help = 'Abort manual Z probing tool'
    
    def cmd_ABORT(self, gcmd):
        self.finalize(False)

    cmd_TESTZ_help = 'Move to new Z height'
    
    def cmd_TESTZ(self, gcmd):
        kin_pos = self.get_kinematics_pos()
        z_pos = kin_pos[2]
        pp = self.past_positions
        insert_pos = bisect.bisect_left(pp, z_pos)
        if insert_pos >= len(pp) or pp[insert_pos] != z_pos:
            pp.insert(insert_pos, z_pos)
        req = gcmd.get('Z')
        if req in ('+', '++'):
            check_z = 1e+13
            if insert_pos < len(self.past_positions) - 1:
                check_z = self.past_positions[insert_pos + 1]
            if req == '+':
                check_z = (check_z + z_pos) / 2
            next_z_pos = min(check_z, z_pos + BISECT_MAX)
        elif req in ('-', '--'):
            check_z = -1e+13
            if insert_pos > 0:
                check_z = self.past_positions[insert_pos - 1]
            if req == '-':
                check_z = (check_z + z_pos) / 2
            next_z_pos = max(check_z, z_pos - BISECT_MAX)
        else:
            next_z_pos = z_pos + gcmd.get_float('Z')
        self.move_z(next_z_pos)
        self.report_z_status(next_z_pos != z_pos, z_pos)

    
    def finalize(self, success):
        self.manual_probe.reset_status()
        self.gcode.register_command('ACCEPT', None)
        self.gcode.register_command('NEXT', None)
        self.gcode.register_command('ABORT', None)
        self.gcode.register_command('TESTZ', None)
        kin_pos = None
        if success:
            kin_pos = self.get_kinematics_pos()
        self.finalize_callback(kin_pos)



def load_config(config):
    return ManualProbe(config)

