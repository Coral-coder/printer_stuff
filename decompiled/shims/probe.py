# Source Generated with Decompyle++
# File: probe.pyc (Python 3.9)

import logging
import pins
from . import manual_probe
HINT_TIMEOUT = '\nIf the probe did not move far enough to trigger, then\nconsider reducing the Z axis minimum position so the probe\ncan travel further (the Z minimum position can be negative).\n'

class PrinterProbe:
    
    def __init__(self, config, mcu_probe):
        self.printer = config.get_printer()
        self.name = config.get_name()
        self.mcu_probe = mcu_probe
        self.speed = config.getfloat('speed', 5, above=0)
        self.lift_speed = config.getfloat('lift_speed', self.speed, above=0)
        self.x_offset = config.getfloat('x_offset', 0)
        self.y_offset = config.getfloat('y_offset', 0)
        self.z_offset = config.getfloat('z_offset')
        self.z_offset_calibrate = 0
        self.z_offset_change_flag = False
        self.probe_calibrate_z = 0
        self.multi_probe_pending = False
        self.last_state = False
        self.last_z_result = 0
        self.gcode_move = self.printer.load_object(config, 'gcode_move')
        if config.has_section('stepper_z'):
            zconfig = config.getsection('stepper_z')
            self.z_position = zconfig.getfloat('position_min', 0, note_valid=False)
        else:
            pconfig = config.getsection('printer')
            self.z_position = pconfig.getfloat('minimum_z_position', 0, note_valid=False)
        self.sample_count = config.getint('samples', 1, minval=1)
        self.sample_retract_dist = config.getfloat('sample_retract_dist', 2, above=0)
        atypes = {
            'median': 'median',
            'average': 'average' }
        self.samples_result = config.getchoice('samples_result', atypes, 'average')
        self.samples_tolerance = config.getfloat('samples_tolerance', 0.1, minval=0)
        self.samples_retries = config.getint('samples_tolerance_retries', 0, minval=0)
        self.printer.lookup_object('pins').register_chip('probe', self)
        self.printer.register_event_handler('homing:homing_move_begin', self._handle_homing_move_begin)
        self.printer.register_event_handler('homing:homing_move_end', self._handle_homing_move_end)
        self.printer.register_event_handler('homing:home_rails_begin', self._handle_home_rails_begin)
        self.printer.register_event_handler('homing:home_rails_end', self._handle_home_rails_end)
        self.printer.register_event_handler('gcode:command_error', self._handle_command_error)
        self.gcode = self.printer.lookup_object('gcode')
        self.gcode.register_command('PROBE', self.cmd_PROBE, desc=self.cmd_PROBE_help)
        self.gcode.register_command('QUERY_PROBE', self.cmd_QUERY_PROBE, desc=self.cmd_QUERY_PROBE_help)
        self.gcode.register_command('PROBE_CALIBRATE', self.cmd_PROBE_CALIBRATE, desc=self.cmd_PROBE_CALIBRATE_help)
        self.gcode.register_command('PROBE_ACCURACY', self.cmd_PROBE_ACCURACY, desc=self.cmd_PROBE_ACCURACY_help)
        self.gcode.register_command('Z_OFFSET_APPLY_PROBE', self.cmd_Z_OFFSET_APPLY_PROBE, desc=self.cmd_Z_OFFSET_APPLY_PROBE_help)

    
    def _handle_homing_move_begin(self, hmove):
        if self.mcu_probe in hmove.get_mcu_endstops():
            self.mcu_probe.probe_prepare(hmove)

    
    def _handle_homing_move_end(self, hmove):
        if self.mcu_probe in hmove.get_mcu_endstops():
            self.mcu_probe.probe_finish(hmove)

    
    def _handle_home_rails_begin(self, homing_state, rails):
        endstops = (lambda .0: [ es for rail in .0 for es, name in rail.get_endstops() ])(rails)
        if self.mcu_probe in endstops:
            self.multi_probe_begin()

    
    def _handle_home_rails_end(self, homing_state, rails):
        endstops = (lambda .0: [ es for rail in .0 for es, name in rail.get_endstops() ])(rails)
        if self.mcu_probe in endstops:
            self.multi_probe_end()

    
    def _handle_command_error(self):
        
        try:
            self.multi_probe_end()
        finally:
            pass
        logging.exception('Multi-probe end')
        return None


    
    def multi_probe_begin(self):
        self.mcu_probe.multi_probe_begin()
        self.multi_probe_pending = True

    
    def multi_probe_end(self):
        if self.multi_probe_pending:
            self.multi_probe_pending = False
            self.mcu_probe.multi_probe_end()

    
    def setup_pin(self, pin_type, pin_params):
        if pin_type != 'endstop' or pin_params['pin'] != 'z_virtual_endstop':
            raise pins.error('Probe virtual endstop only useful as endstop pin')
        if pin_params['invert'] or pin_params['pullup']:
            raise pins.error('Can not pullup/invert probe virtual endstop')
        return self.mcu_probe

    
    def get_lift_speed(self, gcmd = (None,)):
        if gcmd is not None:
            return gcmd.get_float('LIFT_SPEED', self.lift_speed, above=0)
        return None.lift_speed

    
    def get_offsets(self):
        return (self.x_offset, self.y_offset, self.z_offset)

    
    def _probe(self, speed, max_z_dist = (None,)):
        toolhead = self.printer.lookup_object('toolhead')
        curtime = self.printer.get_reactor().monotonic()
        if 'z' not in toolhead.get_status(curtime)['homed_axes']:
            raise self.printer.command_error('{"code":"key96", "msg": "Must home before probe", "values": []}')
        phoming = self.printer.lookup_object('homing')
        pos = toolhead.get_position()
        self.prtouch_v3 = self.printer.lookup_object('prtouch_v3') if self.printer.objects.get('prtouch_v3') else None
        if self.prtouch_v3 is not None:
            suspended_det_status = self.prtouch_v3.get_suspended_det_status()
            target_z = self.z_position
            if max_z_dist is not None and suspended_det_status is True:
                start_z = pos[2]
                max_target_z = start_z - max_z_dist
                if target_z < max_target_z:
                    target_z = max_target_z
        pos[2] = target_z
    # WARNING: Decompyle incomplete

    
    def _move(self, coord, speed):
        self.printer.lookup_object('toolhead').manual_move(coord, speed)

    
    def _calc_mean(self, positions):
        count = float(len(positions))
        return [ None((lambda (range(3)) = None: [ pos[i] for pos in (range(3)) ])(positions)) / count for None in (range(3)) ]

    
    def _calc_median(self, positions):
        z_sorted = sorted(positions, key=(lambda p: p[2]))
        middle = len(positions) // 2
        if len(positions) & 1 == 1:
            return z_sorted[middle]
        return None._calc_mean(z_sorted[middle - 1:middle + 1])

    
    def run_probe(self, gcmd):
        speed = gcmd.get_float('PROBE_SPEED', self.speed, above=0)
        lift_speed = self.get_lift_speed(gcmd)
        sample_count = gcmd.get_int('SAMPLES', self.sample_count, minval=1)
        sample_retract_dist = gcmd.get_float('SAMPLE_RETRACT_DIST', self.sample_retract_dist, above=0)
        samples_tolerance = gcmd.get_float('SAMPLES_TOLERANCE', self.samples_tolerance, minval=0)
        samples_retries = gcmd.get_int('SAMPLES_TOLERANCE_RETRIES', self.samples_retries, minval=0)
        samples_result = gcmd.get('SAMPLES_RESULT', self.samples_result)
        zmax_dist = gcmd.get_float('ZMAX_DIST', None, above=0)
        must_notify_multi_probe = not (self.multi_probe_pending)
        if must_notify_multi_probe:
            self.multi_probe_begin()
        probexy = self.printer.lookup_object('toolhead').get_position()[:2]
        retries = 0
        positions = []
        gcode = self.printer.lookup_object('gcode')
        if len(positions) < sample_count:
            gcode.check_cancel_running()
            if zmax_dist is not None:
                pos = self._probe(speed, max_z_dist=zmax_dist)
            else:
                pos = self._probe(speed)
            positions.append(pos)
            z_positions = (lambda .0: [ p[2] for p in .0 ])(positions)
            if max(z_positions) - min(z_positions) > samples_tolerance:
                if retries >= samples_retries:
                    raise gcmd.error('Probe samples exceed samples_tolerance')
                gcmd.respond_info('Probe samples exceed tolerance. Retrying...')
                retries += 1
                positions = []
            if len(positions) < sample_count:
                self._move(probexy + [
                    pos[2] + sample_retract_dist], lift_speed)
                continue
                if must_notify_multi_probe:
                    self.multi_probe_end()
        if samples_result == 'median':
            return self._calc_median(positions)
        return None._calc_mean(positions)

    cmd_PROBE_help = 'Probe Z-height at current XY position'
    
    def cmd_PROBE(self, gcmd):
        pos = self.run_probe(gcmd)
        gcmd.respond_info('Result is z=%.6f' % (pos[2],))
        self.last_z_result = pos[2]

    cmd_QUERY_PROBE_help = 'Return the status of the z-probe'
    
    def cmd_QUERY_PROBE(self, gcmd):
        toolhead = self.printer.lookup_object('toolhead')
        print_time = toolhead.get_last_move_time()
        res = self.mcu_probe.query_endstop(print_time)
        self.last_state = res
        gcmd.respond_info('probe: %s' % ([
            'open',
            'TRIGGERED'][not (not res)],))

    
    def get_status(self, eventtime):
        return {
            'last_query': self.last_state,
            'last_z_result': self.last_z_result,
            'z_offset': self.z_offset_calibrate if self.z_offset_change_flag else self.z_offset }

    cmd_PROBE_ACCURACY_help = 'Probe Z-height accuracy at current XY position'
    
    def cmd_PROBE_ACCURACY(self, gcmd):
        speed = gcmd.get_float('PROBE_SPEED', self.speed, above=0)
        lift_speed = self.get_lift_speed(gcmd)
        sample_count = gcmd.get_int('SAMPLES', 10, minval=1)
        sample_retract_dist = gcmd.get_float('SAMPLE_RETRACT_DIST', self.sample_retract_dist, above=0)
        toolhead = self.printer.lookup_object('toolhead')
        pos = toolhead.get_position()
        gcmd.respond_info('PROBE_ACCURACY at X:%.3f Y:%.3f Z:%.3f (samples=%d retract=%.3f speed=%.1f lift_speed=%.1f)\n' % (pos[0], pos[1], pos[2], sample_count, sample_retract_dist, speed, lift_speed))
        self.multi_probe_begin()
        positions = []
        if len(positions) < sample_count:
            pos = self._probe(speed)
            positions.append(pos)
            liftpos = [
                None,
                None,
                pos[2] + sample_retract_dist]
            self._move(liftpos, lift_speed)
            continue
        self.multi_probe_end()
        max_value = max((lambda .0: [ p[2] for p in .0 ])(positions))
        min_value = min((lambda .0: [ p[2] for p in .0 ])(positions))
        range_value = max_value - min_value
        avg_value = self._calc_mean(positions)[2]
        median = self._calc_median(positions)[2]
        deviation_sum = 0
        for i in range(len(positions)):
            deviation_sum += pow(positions[i][2] - avg_value, 2)
        sigma = (deviation_sum / len(positions)) ** 0.5
        z_values = (lambda .0: [ pos[2] for pos in .0 ])(positions)
        gcmd.respond_info('probe accuracy results: maximum %.6f, minimum %.6f, range %.6f, average %.6f, median %.6f, standard deviation %.6f' % (max_value, min_value, range_value, avg_value, median, sigma))
        return (max_value, min_value, range_value, avg_value, median, sigma, positions)

    
    def probe_calibrate_finalize(self, kin_pos):
        if kin_pos is None:
            return None
        z_offset = None.probe_calibrate_z - kin_pos[2]
        self.gcode.respond_info('%s: z_offset: %.3f\nThe SAVE_CONFIG command will update the printer config file\nwith the above and restart the printer.' % (self.name, z_offset))
        configfile = self.printer.lookup_object('configfile')
        configfile.set(self.name, 'z_offset', '%.3f' % (z_offset,))

    cmd_PROBE_CALIBRATE_help = "Calibrate the probe's z_offset"
    
    def cmd_PROBE_CALIBRATE(self, 