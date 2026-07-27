# =====================================================================
# PARTIAL DECOMPILATION -- this module did not fully round-trip.
# The 3.9 bytecode uses control flow the decompiler could not fully
# reconstruct (e.g. try/except/else with returns, or a generator with a
# dropped builtin rendered as `None(...)`). The code below is best-effort
# and will not import as-is. Ground-truth disassembly for repair:
#     decompiled/_disasm/gcode_move.txt
# =====================================================================

# Source Generated with Decompyle++
# File: gcode_move.pyc (Python 3.9)

import logging

class GCodeMove:
    
    def __init__(self, config):
        self.config = config
        self.variable_safe_z = 0
        if config.has_section('gcode_macro PRINTER_PARAM'):
            PRINTER_PARAM = config.getsection('gcode_macro PRINTER_PARAM')
            self.variable_safe_z = PRINTER_PARAM.getfloat('variable_z_safe_g28', 0.0)
        self.printer = printer = config.get_printer()
        printer.register_event_handler('klippy:ready', self._handle_ready)
        printer.register_event_handler('klippy:shutdown', self._handle_shutdown)
        printer.register_event_handler('toolhead:set_position', self.reset_last_position)
        printer.register_event_handler('toolhead:manual_move', self.reset_last_position)
        printer.register_event_handler('gcode:command_error', self.reset_last_position)
        printer.register_event_handler('extruder:activate_extruder', self._handle_activate_extruder)
        printer.register_event_handler('homing:home_rails_end', self._handle_home_rails_end)
        self.is_printer_ready = False
        gcode = printer.lookup_object('gcode')
        handlers = [
            'G1',
            'G20',
            'G21',
            'M82',
            'M83',
            'G90',
            'G91',
            'G92',
            'M220',
            'M221',
            'SET_GCODE_OFFSET',
            'SAVE_GCODE_STATE',
            'RESTORE_GCODE_STATE']
        for cmd in handlers:
            func = getattr(self, 'cmd_' + cmd)
            desc = getattr(self, 'cmd_' + cmd + '_help', None)
            gcode.register_command(cmd, func, False, desc)
        gcode.register_command('G0', self.cmd_G1)
        gcode.register_command('M114', self.cmd_M114, True)
        gcode.register_command('GET_POSITION', self.cmd_GET_POSITION, True, desc=self.cmd_GET_POSITION_help)
        gcode.register_command('SET_POSITION', self.cmd_SET_POSITION, True, desc=self.cmd_SET_POSITION_help)
        gcode.register_command('SAVE_ENDPRINT', self.cmd_SAVE_ENDPRINT)
        gcode.gcode_move = self
        self.Coord = gcode.Coord
        self.absolute_coord = self.absolute_extrude = True
        self.base_position = [
            0.0,
            0.0,
            0.0,
            0.0]
        self.last_position = [
            0.0,
            0.0,
            0.0,
            0.0]
        self.homing_position = [
            0.0,
            0.0,
            0.0,
            0.0]
        self.speed = 25.0
        self.speed_factor = 0.016666666666666666
        self.extrude_factor = 1.0
        self.saved_states = { }
        self.move_transform = None
        self.move_with_transform = None
        
        self.position_with_transform = lambda : [
0.0,
0.0,
0.0,
0.0]
        gcode.register_command('RESET_HOME_AXES_XY', self.cmd_reset_home_axes_xy, desc=self.cmd_RESET_HOME_AXES_XY_help)
        gcode.register_command('SET_LIMITS', self.cmd_set_limits, desc=self.cmd_SET_LIMITS_help)
        gcode.register_command('RESTORE_LIMITS', self.cmd_restore_limits, desc=self.cmd_RESTORE_LIMITS_help)
        gcode.register_command('SET_Z_LIMIT', self.cmd_set_z_limit)
        gcode.register_command('RESTORE_Z_LIMIT', self.cmd_restore_zlimit)

    cmd_RESET_HOME_AXES_XY_help = 'reset_home_axes'
    
    def cmd_reset_home_axes_xy(self, gcmd):
        min_x = 1.0
        max_x = -1.0
        min_y = 1.0
        max_y = -1.0
        self.printer.lookup_object('toolhead').kin.set_limits(min_x, max_x, min_y, max_y)

    
    def cmd_set_z_limit(self, gcmd):
        zmax_safe_pox_diff = 0
        if self.config.has_section('z_align'):
            zmax_safe_pox_diff = self.printer.lookup_object('z_align').zmax_safe_pox_diff
        fade_target = 0
        if self.config.has_section('prtouch_v3'):
            prtouch_v3 = self.printer.lookup_object('prtouch_v3')
            if isinstance(prtouch_v3.bed_mesh.fade_target, int) or isinstance(prtouch_v3.bed_mesh.fade_target, float):
                fade_target = abs(prtouch_v3.bed_mesh.fade_target)
        if fade_target > 5:
            logging.info('set_z_limit fade_target: {} > 5, reset to 0'.format(fade_target))
            fade_target = 0
        logging.info('set_z_limit fade_target: {}'.format(fade_target))
        offset_value = 0.2
        min_z = self.config.getsection('stepper_z').getfloat('position_min', default=-10)
        max_z = (self.config.getsection('stepper_z').getfloat('position_max', default=360) - zmax_safe_pox_diff) + fade_target + offset_value
        self.printer.lookup_object('toolhead').kin.set_z_limit(min_z, max_z)

    
    def cmd_restore_zlimit(self, gcmd):
        min_z = self.config.getsection('stepper_z').getfloat('position_min', default=-10)
        max_z = self.config.getsection('stepper_z').getfloat('position_max', default=360)
        self.printer.lookup_object('toolhead').kin.set_z_limit(min_z, max_z)

    cmd_SET_LIMITS_help = 'SET NEW LIMITS MAXY 400'
    
    def cmd_set_limits(self, gcmd):
        min_x = self.config.getsection('stepper_x').getfloat('position_min', default=-12)
        max_x = self.config.getsection('stepper_x').getfloat('position_max', default=356)
        min_y = self.config.getsection('stepper_y').getfloat('position_min', default=-10)
        max_y = self.config.getsection('stepper_y').getfloat('position_max', default=400)
        self.printer.lookup_object('toolhead').kin.set_limits(min_x, max_x, min_y, max_y)

    cmd_RESTORE_LIMITS_help = 'RESTORE_LIMITS'
    
    def cmd_restore_limits(self, gcmd):
        self.printer.lookup_object('toolhead').kin.restore_limits()

    
    def _handle_ready(self):
        self.is_printer_ready = True
        if self.move_transform is None:
            toolhead = self.printer.lookup_object('toolhead')
            self.move_with_transform = toolhead.move
            self.position_with_transform = toolhead.get_position
        self.reset_last_position()

    
    def _handle_shutdown(self):
        if not self.is_printer_ready:
            return None
        self.is_printer_ready = None
        logging.info('gcode state: absolute_coord=%s absolute_extrude=%s base_position=%s last_position=%s homing_position=%s speed_factor=%s extrude_factor=%s speed=%s', self.absolute_coord, self.absolute_extrude, self.base_position, self.last_position, self.homing_position, self.speed_factor, self.extrude_factor, self.speed)

    
    def _handle_activate_extruder(self):
        self.reset_last_position()
        self.extrude_factor = 1.0
        self.base_position[3] = self.last_position[3]

    
    def _handle_home_rails_end(self, homing_state, rails):
        self.reset_last_position()
        for axis in homing_state.get_axes():
            self.base_position[axis] = self.homing_position[axis]

    
    def set_move_transform(self, transform, force = (False,)):
        if not self.move_transform is not None and force:
            raise self.printer.config_error('G-Code move transform already specified')
        old_transform = self.move_transform
        if old_transform is None:
            old_transform = self.printer.lookup_object('toolhead', None)
        self.move_transform = transform
        self.move_with_transform = transform.move
        self.position_with_transform = transform.get_position
        return old_transform

    
    def _get_gcode_position(self):
        p = [ lp - bp for lp, bp in (zip(self.last_position, self.base_position)) ]
        p[3] /= self.extrude_factor
        return p

    
    def _get_gcode_speed(self):
        return self.speed / self.speed_factor

    
    def _get_gcode_speed_override(self):
        return self.speed_factor * 6e+01

    
    def get_status(self, eventtime = (None,)):
        move_position = self._get_gcode_position()
        return {
            'speed_factor': self._get_gcode_speed_override(),
            'speed': self._get_gcode_speed(),
            'extrude_factor': self.extrude_factor,
            'absolute_coordinates': self.absolute_coord,
            'absolute_extrude': self.absolute_extrude,
            'homing_origin': self.Coord(*self.homing_position),
            'position': self.Coord(*self.last_position),
            'gcode_position': self.Coord(*move_position) }

    
    def reset_last_position(self):
        if self.is_printer_ready:
            self.last_position = self.position_with_transform()

    
    def auto_protect_coordinate_system(self):
        gcode = self.printer.lookup_object('gcode')
        (bx, by, bz) = self.base_position[:3]
        (px, py, pz) = self.last_position[:3]
        if bx == 0.0 and by == 0.0 and bz == 0.0:
            return False
        None.info('Coordinate pollution detected, auto recovering: physical=(%.3f, %.3f, %.3f)', px, py, pz)
        gcode_speed = self._get_gcode_speed()
        toolhead = self.printer.lookup_object('toolhead')
        (min_z, max_z) = toolhead.kin.limits[2]
        current_pos = toolhead.get_position()
        current_physical_z = current_pos[2]
        z_lift_height = 5.0
        if min_z <= max_z:
            lift_target_z = current_physical_z + z_lift_height
            if lift_target_z > max_z:
                z_lift_height = max(0.0, max_z - current_physical_z - 0.1)
                if z_lift_height < 1.0:
                    z_lift_height = 0.0
        gcode.run_script_from_command('G91')
        if z_lift_height > 0.01:
            gcode.run_script_from_command(f'''G1 Z{z_lift_height:.5f} F3000''')
        cmd = f'''G1 X{-px:.5f} Y{-py:.5f} F3000'''
        gcode.run_script_from_command(cmd)
        gcode.run_script_from_command('G90')
        gcode.run_script_from_command('G92')
        if z_lift_height > 0.01:
            if min_z <= max_z:
                restore_target_z = current_physical_z
                if restore_target_z < min_z:
                    restore_z_move = z_lift_height - ((current_physical_z - min_z) + 0.1)
                    if restore_z_move > 0.01:
                        gcode.run_script_from_command('G91')
                        gcode.run_script_from_command(f'''G1 Z{-restore_z_move:.5f} F3000''')
                        gcode.run_script_from_command('G90')
                    else:
                        gcode.run_script_from_command('G91')
                        gcode.run_script_from_command(f'''G1 Z{-z_lift_height:.5f} F3000''')
                        gcode.run_script_from_command('G90')
                else:
                    gcode.run_script_from_command('G91')
                    gcode.run_script_from_command(f'''G1 Z{-z_lift_height:.5f} F3000''')
                    gcode.run_script_from_command('G90')
            else:
                gcode.run_script_from_command('G90')
        self.speed = gcode_speed * self.speed_factor
        return True

    
    def simple_cmd_G1(self, line):
        cpos = line.find(';')
        if cpos > 0:
            line = line[:cpos]
        parts = line.split()
        
        try:
            for part in parts[1:]:
                if part[0] == 'E' or part[0] == 'e':
                    if not self.absolute_coord or self.absolute_extrude:
                        self.last_position[3] += float(part[1:]) * self.extrude_factor
                    else:
                        self.last_position[3] = float(part[1:]) * self.extrude_factor + self.base_position[3]
                    continue
                if part[0] == 'X' or part[0] == 'x':
                    if not self.absolute_coord:
                        self.last_position[0] += float(part[1:])
                    else:
                        self.last_position[0] = float(part[1:]) + self.base_position[0]
                    continue
                if part[0] == 'Y' or part[0] == 'y':
                    if not self.absolute_coord:
                        self.last_position[1] += float(part[1:])
                    else:
                        self.last_position[1] = float(part[1:]) + self.base_position[1]
                    continue
                if part[0] == 'Z' or part[0] == 'z':
                    toolhead = self.printer.lookup_object('toolhead')
                    print_stats = self.printer.lookup_object('print_stats')
                    max_z = toolhead.kin.limits[2][1] + 5
                    curtime = self.printer.get_reactor().monotonic()
                    if ('z' in toolhead.get_status(curtime)['homed_axes'] or float(part[1:]) > max_z or self.absolute_coord) and self.last_position[2] + float(part[1:]) > max_z:
                        m = '{"code":"587","msg":"Move out of range %s", "values":[]}' % str(part)
                        self.printer.lookup_object('gcode')._respond_error(m)
                        if print_stats.state == 'printing' and self.printer.lookup_object('pause_resume').pause_start == False and self.printer.lookup_object('virtual_sdcard').is_move_out_of_range_in_printing == False:
                            self.printer.lookup_object('virtual_sdcard').is_move_out_of_range_in_printing = True
                    return None
                if not None.absolute_coord:
                    self.last_position[2] += float(part[1:])
                else:
                    self.last_position[2] = float(part[1:]) + self.base_position[2]
            if not part[0] == 'F':
                if part[0] == 'f':
                    gcode_speed = float(part[1:])
                    if gcode_speed <= 0.0:
                        raise Exception('{"code":"key272": "msg":"Invalid speed in \'%s\'", "values":["%s"]}' % (line, line))
                    self.speed = gcode_speed * self.speed_factor
            else:
                except ValueError:
                    e = None
                    
                    try:
                        raise Exception('{"code":"key273": "msg":"Unable to parse move \'%s\'", "values":["%s"]}' % (line, line))
                    finally:
                        e = None
                        del e
                    e = None
                    del e
                    return None



    
    def cmd_G1(self, gcmd):
        params = gcmd.get_command_parameters()
        
        try:
            for pos, axis in enumerate('XYZ'):
                if axis in params:
                    v = float(params[axis])
                    if not self.absolute_coord:
                        self.last_position[pos] += v
                        continue
                self.last_position[pos] = v + self.base_position[pos]
            if 'Z' in params:
                print_stats = self.printer.lookup_object('print_stats')
                if print_stats.state != 'printing':
                    toolhead = self.printer.lookup_object('toolhead')
                    curtime = self.printer.get_reactor().monotonic()
                    if 'z' in toolhead.get_status(curtime)['homed_axes'] and self.last_position[2] < -2:
                        logging.info('Minimum Limit -2 last_position[2]:%s' % self.last_position[2])
                        self.last_position[2] = -2
            if 'E' in params:
                v = float(params['E']) * self.extrude_factor
                if not self.absolute_coord or self.absolute_extrude:
                    self.last_position[3] += v
                else:
                    self.last_position[3] = v + self.base_position[3]
            if 'F' in params:
                gcode_speed = float(params['F'])
                if gcode_speed <= 0.0:
                    raise gcmd.error('{"code":"key272": "msg":"Invalid speed in \'%s\'", "values":["%s"]}' % (gcmd.get_commandline(), gcmd.get_commandline()))
                self.speed = gcode_speed * self.speed_factor
        except ValueError:
            e = None
            
            try:
                raise gcmd.error('{"code":"key273": "msg":"Unable to parse move \'%s\'", "values":["%s"]}' % (gcmd.get_commandline(), gcmd.get_commandline()))
            finally:
                e = None
                del e
            e = None
            del e
            return None



    
    def cmd_G20(self, gcmd):
        raise gcmd.error('Machine does not support G20 (inches) command')

    
    def cmd_G21(self, gcmd):
        pass

    
    def cmd_M82(self, gcmd):
        self.absolute_extrude = True

    
    def cmd_M83(self, gcmd):
        self.absolute_extrude = False

    
    def cmd_G90(self, gcmd):
        self.absolute_coord = True

    
    def cmd_G91(self, gcmd):
        self.absolute_coord = False

    
    def cmd_G92(self, gcmd):
        offsets = [ gcmd.get_float(a, None) for a in ('XYZE') ]
        for i, offset in enumerate(offsets):
            if offset is not None or i == 3:
                offset *= self.extrude_factor
            self.base_position[i] = self.last_position[i] - offset
        if offsets == [
            None,
            None,
            None,
            None]:
            self.base_position = list(self.last_position)

    
    def cmd_M114(self, gcmd):
        p = self._get_gcode_position()
        gcmd.respond_raw('X:%.3f Y:%.3f Z:%.3f E:%.3f' % tuple(p))

    
    def cmd_M220(self, gcmd):
        value = gcmd.get_float('S', 1e+02, above=0.0) / 6e+03
        self.speed = self._get_gcode_speed() * value
        self.speed_factor = value
        import json
        
        try:
            SAVE = int(gcmd.get('SAVE', 0))
            speed_S = int(gcmd.get_float('S', 1e+02, above=0.0))
            v_sd = self.printer.lookup_object('virtual_sdcard')
            speed_mode_path = v_sd.speed_mode_path
            if SAVE == 1:
                result = { }
                result['speed_mode'] = 1
                result['value'] = speed_S
                with open(speed_mode_path, 'w') as f:
                    f.write(json.dumps(result))
                    f.flush()
        except Exception:
            err = None
            
            try:
                err_msg = 'cmd_M220 err %s' % str(err)
                logging.error(err_msg)
            finally:
                err = None
                del err
            err = None
            del err
            return None



    
    def cmd_M221(self, gcmd):
        new_extrude_factor = gcmd.get_float('S', 1e+02, above=0.0) / 1e+02
        last_e_pos = self.last_position[3]
        e_value = (last_e_pos - self.base_position[3]) / self.extrude_factor
        self.base_position[3] = last_e_pos - e_value * new_extrude_factor
        self.extrude_factor = new_extrude_factor
        import json
        
        try:
            SAVE = int(gcmd.get('SAVE', 0))
            speed_S = int(gcmd.get_float('S', 1e+02, above=0.0))
            v_sd = self.printer.lookup_object('virtual_sdcard')
            if SAVE == 1:
                result = { }
                result['value'] = speed_S
                with open(v_sd.flow_rate_path, 'w') as f:
                    f.write(json.dumps(result))
                    f.flush()
        except Exception:
            err = None
            
            try:
                err_msg = 'cmd_M221 err %s' % str(err)
                logging.error(err_msg)
            finally:
                err = None
                del err
            err = None
            del err
            return None



    cmd_SET_GCODE_OFFSET_help = 'Set a virtual offset to g-code positions'
    
    def cmd_SET_GCODE_OFFSET(self, gcmd):
        move_delta = [
            0.0,
            0.0,
            0.0,
            0.0]
        for pos, axis in enumerate('XYZE'):
            offset = gcmd.get_float(axis, None)
            if offset is None:
                offset = gcmd.get_float(axis + '_ADJUST', None)
                if offset is None:
                    continue
                offset += self.homing_position[pos]
            delta = offset - self.homing_position[pos]
            move_delta[pos] = delta
            self.base_position[pos] += delta
            self.homing_position[pos] = offset
        if gcmd.get_int('MOVE', 0):
            speed = gcmd.get_float('MOVE_SPEED', self.speed, above=0.0)
            for pos, delta in enumerate(move_delta):
                self.last_position[pos] += delta
            self.move_with_transform(self.last_position, speed)

    
    def recordPrintFileName(self, path, file_n