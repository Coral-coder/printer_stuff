# Source Generated with Decompyle++
# File: gcode_move.pyc (Python 3.9)

import logging

class GCodeMove:
    
    def __init__(self, config):
        self.config = config
        self.variable_safe_z = 0
        if config.has_section('gcode_macro PRINTER_PARAM'):
            PRINTER_PARAM = config.getsection('gcode_macro PRINTER_PARAM')
            self.variable_safe_z = PRINTER_PARAM.getfloat('variable_z_safe_g28', 0)
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
            0,
            0,
            0,
            0]
        self.last_position = [
            0,
            0,
            0,
            0]
        self.homing_position = [
            0,
            0,
            0,
            0]
        self.speed = 25
        self.speed_factor = 0.0166667
        self.extrude_factor = 1
        self.saved_states = { }
        self.move_transform = None
        self.move_with_transform = None
        
        self.position_with_transform = lambda : [
0,
0,
0,
0]
        gcode.register_command('RESET_HOME_AXES_XY', self.cmd_reset_home_axes_xy, desc=self.cmd_RESET_HOME_AXES_XY_help)
        gcode.register_command('SET_LIMITS', self.cmd_set_limits, desc=self.cmd_SET_LIMITS_help)
        gcode.register_command('RESTORE_LIMITS', self.cmd_restore_limits, desc=self.cmd_RESTORE_LIMITS_help)
        gcode.register_command('SET_Z_LIMIT', self.cmd_set_z_limit)
        gcode.register_command('RESTORE_Z_LIMIT', self.cmd_restore_zlimit)

    cmd_RESET_HOME_AXES_XY_help = 'reset_home_axes'
    
    def cmd_reset_home_axes_xy(self, gcmd):
        min_x = 1
        max_x = -1
        min_y = 1
        max_y = -1
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
        self.extrude_factor = 1
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
        return self.speed_factor * 60

    
    def get_status(self, eventtime = (None,)):
        move_position = self._get_gcode_position()
        return {
            'speed_factor': self._get_gcode_speed_override(),
            'speed': self._get_gcode_speed(),
            'extrude_factor': self.extrude_factor,
            'absolute_coordinates': self.absolute_coord,
            'absolute_extrude': self.absolute_extrude,
            'homing