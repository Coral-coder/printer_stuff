# Source Generated with Decompyle++
# File: fan_generic.pyc (Python 3.9)

from . import fan

class PrinterFanGeneric:
    cmd_SET_FAN_SPEED_help = 'Sets the speed of a fan'
    
    def __init__(self, config):
        self.printer = config.get_printer()
        self.fan = fan.Fan(config, default_shutdown_speed=0)
        self.fan_name = config.get_name().split()[-1]
        gcode = self.printer.lookup_object('gcode')
        gcode.register_mux_command('SET_FAN_SPEED', 'FAN', self.fan_name, self.cmd_SET_FAN_SPEED, desc=self.cmd_SET_FAN_SPEED_help)

    
    def get_status(self, eventtime):
        return self.fan.get_status(eventtime)

    
    def cmd_SET_FAN_SPEED(self, gcmd):
        speed = gcmd.get_float('SPEED', 0)
        self.fan.set_speed_from_command(speed)



def load_config_prefix(config):
    return PrinterFanGeneric(config)

