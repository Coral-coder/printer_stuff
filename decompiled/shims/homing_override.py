# Source Generated with Decompyle++
# File: homing_override.pyc (Python 3.9)


class HomingOverride:
    
    def __init__(self, config):
        self.config = config
        self.printer = config.get_printer()
        self.start_pos = [ config.getfloat('set_position_' + a, None) for a in ('xyz') ]
        self.axes = config.get('axes', 'XYZ').upper()
        gcode_macro = self.printer.load_object(config, 'gcode_macro')
        self.template = gcode_macro.load_template(config, 'gcode')
        self.in_script = False
        self.printer.load_object(config, 'homing')
        self.gcode = self.printer.lookup_object('gcode')
        self.prev_G28 = self.gcode.register_command('G28', None)
        self.gcode.register_command('G28', self.cmd_G28)

    
    def cmd_G28(self, gcmd):
        if self.config.has_section('motor_control') and self.config.getsection('motor_control').getint('switch') == 1 and self.printer.lookup_object('motor_control').is_ready == False:
            self.gcode.respond_info('The motor parameters are initializing, Please try again later...')
            return None
        if self.in_script:
            self.prev_G28(gcmd)
            return None
        no_axis = True
        for axis in 'XYZ':
            if gcmd.get(axis, None) is not None:
                no_axis = False
                break
        if no_axis:
            override = True
        else:
            override = False
            for axis in self.axes:
                if gcmd.get(axis, None) is not None:
                    override = True
        if not override:
            self.prev_G28(gcmd)
            return None
        toolhead = self.printer.lookup_object('toolhead')
        pos = toolhead.get_position()
        homing_axes = []
        for axis, loc in enumerate(self.start_pos):
            if loc is not None:
                pos[axis] = loc
                homing_axes.append(axis)
        toolhead.set_position(pos, homing_axes=homing_axes)
        context = self.template.create_template_context()
        context['params'] = gcmd.get_command_parameters()
        try:
            self.in_script = True
            self.template.run_gcode_from_command(context)
        finally:
            self.in_script = False




def load_config(config):
    return HomingOverride(config)

