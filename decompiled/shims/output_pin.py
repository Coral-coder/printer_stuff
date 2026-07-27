# =====================================================================
# PARTIAL DECOMPILATION -- this module did not fully round-trip.
# The 3.9 bytecode uses control flow the decompiler could not fully
# reconstruct (e.g. try/except/else with returns, or a generator with a
# dropped builtin rendered as `None(...)`). The code below is best-effort
# and will not import as-is. Ground-truth disassembly for repair:
#     decompiled/_disasm/output_pin.txt
# =====================================================================

# Source Generated with Decompyle++
# File: output_pin.pyc (Python 3.9)

PIN_MIN_TIME = 0.1
RESEND_HOST_TIME = 0.3 + PIN_MIN_TIME
MAX_SCHEDULE_TIME = 5.0
import logging

class PrinterOutputPin:
    
    def __init__(self, config):
        self.config = config
        self.printer = config.get_printer()
        ppins = self.printer.lookup_object('pins')
        self.is_pwm = config.getboolean('pwm', False)
        if self.is_pwm:
            self.mcu_pin = ppins.setup_pin('pwm', config.get('pin'))
            cycle_time = config.getfloat('cycle_time', 0.1, above=0.0, maxval=MAX_SCHEDULE_TIME)
            hardware_pwm = config.getboolean('hardware_pwm', False)
            self.mcu_pin.setup_cycle_time(cycle_time, hardware_pwm)
            self.scale = config.getfloat('scale', 1.0, above=0.0)
            self.last_cycle_time = self.default_cycle_time = cycle_time
        else:
            self.mcu_pin = ppins.setup_pin('digital_out', config.get('pin'))
            self.scale = 1.0
            self.last_cycle_time = self.default_cycle_time = 0.0
        self.last_print_time = 0.0
        static_value = config.getfloat('static_value', None, minval=0.0, maxval=self.scale)
        self.reactor = self.printer.get_reactor()
        self.resend_timer = None
        self.resend_interval = 0.0
        if static_value is not None:
            self.mcu_pin.setup_max_duration(0.0)
            self.last_value = static_value / self.scale
            self.mcu_pin.setup_start_value(self.last_value, self.last_value, True)
        else:
            max_mcu_duration = config.getfloat('maximum_mcu_duration', 0.0, minval=0.5, maxval=MAX_SCHEDULE_TIME)
            self.mcu_pin.setup_max_duration(max_mcu_duration)
            if max_mcu_duration:
                self.resend_interval = max_mcu_duration - RESEND_HOST_TIME
            self.last_value = config.getfloat('value', 0.0, minval=0.0, maxval=self.scale) / self.scale
            self.shutdown_value = config.getfloat('shutdown_value', 0.0, minval=0.0, maxval=self.scale) / self.scale
            self.mcu_pin.setup_start_value(self.last_value, self.shutdown_value)
            pin_name = config.get_name().split()[1]
            gcode = self.printer.lookup_object('gcode')
            gcode.register_mux_command('SET_PIN', 'PIN', pin_name, self.cmd_SET_PIN, desc=self.cmd_SET_PIN_help)
            self.heaters = self.printer.load_object(config, 'heaters')

    
    def set_poewon(self, value):
        value /= self.scale
        cycle_time = self.default_cycle_time
        toolhead = self.printer.lookup_object('toolhead')
        None((lambda print_time = None: self._set_pin(print_time, value, cycle_time)))

    
    def checkpwm(self, eventtime):
