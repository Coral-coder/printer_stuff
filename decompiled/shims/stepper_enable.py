# Source Generated with Decompyle++
# File: stepper_enable.pyc (Python 3.9)

import logging
DISABLE_STALL_TIME = 0.1

class StepperEnablePin:
    
    def __init__(self, mcu_enable, enable_count):
        self.mcu_enable = mcu_enable
        self.enable_count = enable_count
        self.is_dedicated = True

    
    def set_enable(self, print_time):
        if not self.enable_count:
            self.mcu_enable.set_digital(print_time, 1)
        self.enable_count += 1

    
    def set_disable(self, print_time):
        self.enable_count -= 1
        if not self.enable_count:
            self.mcu_enable.set_digital(print_time, 0)



def setup_enable_pin(printer, pin):
    if pin is None:
        enable = StepperEnablePin(None, 9999)
        enable.is_dedicated = False
        return enable
    ppins = None.lookup_object('pins')
    pin_params = ppins.lookup_pin(pin, can_invert=True, share_type='stepper_enable')
    enable = pin_params.get('class')
    if enable is not None:
        enable.is_dedicated = False
        return enable
    mcu_enable = None['chip'].setup_pin('digital_out', pin_params)
    mcu_enable.setup_max_duration(0)
    enable = pin_params['class'] = StepperEnablePin(mcu_enable, 0)
    return enable


class EnableTracking:
    
    def __init__(self, stepper, enable):
        self.stepper = stepper
        self.enable = enable
        self.callbacks = []
        self.is_enabled = False
        self.stepper.add_active_callback(self.motor_enable)

    
    def register_state_callback(self, callback):
        self.callbacks.append(callback)

    
    def motor_enable(self, print_time):
        if not self.is_enabled:
            for cb in self.callbacks:
                cb(print_time, True)
            self.enable.set_enable(print_time)
            self.is_enabled = True

    
    def motor_disable(self, print_time):
        if self.is_enabled:
            for cb in self.callbacks:
                cb(print_time, False)
            self.enable.set_disable(print_time)
            self.is_enabled = False
            self.stepper.add_active_callback(self.motor_enable)

    
    def is_motor_enabled(self):
        return self.is_enabled

    
    def has_dedicated_enable(self):
        return self.enable.is_dedicated



class PrinterStepperEnable:
    
    def __init__(self, config):
        self.config = config
        self.printer = config.get_printer()
        self.enable_lines = { }
        self.printer.register_event_handler('gcode:request_restart', self._handle_request_restart)
        gcode = self.printer.lookup_object('gcode')
        gcode.register_command('M18', self.cmd_M18)
        gcode.register_command('M84', self.cmd_M18)
        gcode.register_command('SET_STEPPER_ENABLE', self.cmd_SET_STEPPER_ENABLE, desc=self.cmd_SET_STEPPER_ENABLE_help)

    
    def register_stepper(self, config, mcu_stepper):
        name = mcu_stepper.get_name()
        enable = setup_enable_pin(self.printer, config.get('enable_pin', None))
        self.enable_lines[name] = EnableTracking(mcu_stepper, enable)

    
    def motor_off(self):
        vsd = self.printer.lookup_object('virtual_sdcard')
        vsd.bed_mesh_calibate_state = False
        if self.config.has_section('z_align'):
            z_align = self.printer.lookup_object('z_align')
            z_align.is_already_zodwn = False
        toolhead = self.printer.lookup_object('toolhead')
        toolhead.dwell(DISABLE_STALL_TIME)
        print_time = toolhead.get_last_move_time()
        for el in self.enable_lines.values():
            el.motor_disable(print_time)
        self.printer.send_event('stepper_enable:motor_off', print_time)
        toolhead.dwell(DISABLE_STALL_TIME)

    
    def motor_debug_enable(self, stepper, enable):
        toolhead = self.printer.lookup_object('toolhead')
        toolhead.dwell(DISABLE_STALL_TIME)
        print_time = toolhead.get_last_move_time()
        el = self.enable_lines[stepper]
        if enable:
            el.motor_enable(print_time)
            logging.info('%s has been manually enabled', stepper)
        else:
            el.motor_disable(print_time)
            logging.info('%s has been manually disabled', stepper)
        toolhead.dwell(DISABLE_STALL_TIME)

    
    def _handle_request_restart(self, print_time):
        self.motor_off()

    
    def cmd_M18(self, gcmd):
        self.motor_off()

    cmd_SET_STEPPER_ENABLE_help = 'Enable/disable individual stepper by name'
    
    def cmd_SET_STEPPER_ENABLE(self, gcmd):
        stepper_name = gcmd.get('STEPPER', None)
        if stepper_name not in self.enable_lines:
            gcmd.respond_info('SET_STEPPER_ENABLE: Invalid stepper "%s"' % (stepper_name,))
            return None
        stepper_enable = None.get_int('ENABLE', 1)
        self.motor_debug_enable(stepper_name, stepper_enable)

    
    def lookup_enable(self, name):
        if name not in self.enable_lines:
            raise self.printer.config_error("Unknown stepper '%s'" % (name,))
        return self.enable_lines[name]

    
    def get_steppers(self):
        return list(self.enable_lines.keys())



def load_config(config):
    return PrinterStepperEnable(config)

