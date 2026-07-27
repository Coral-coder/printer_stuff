# Source Generated with Decompyle++
# File: delayed_gcode.pyc (Python 3.9)

import logging

class DelayedGcode:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        self.reactor = self.printer.get_reactor()
        self.name = config.get_name().split()[1]
        self.gcode = self.printer.lookup_object('gcode')
        gcode_macro = self.printer.load_object(config, 'gcode_macro')
        self.timer_gcode = gcode_macro.load_template(config, 'gcode')
        self.duration = config.getfloat('initial_duration', 0, minval=0)
        self.timer_handler = None
        self.inside_timer = self.repeat = False
        self.printer.register_event_handler('klippy:ready', self._handle_ready)
        self.gcode.register_mux_command('UPDATE_DELAYED_GCODE', 'ID', self.name, self.cmd_UPDATE_DELAYED_GCODE, desc=self.cmd_UPDATE_DELAYED_GCODE_help)

    
    def _handle_ready(self):
        waketime = self.reactor.NEVER
        if self.duration:
            waketime = self.reactor.monotonic() + self.duration
        self.timer_handler = self.reactor.register_timer(self._gcode_timer_event, waketime)

    
    def _gcode_timer_event(self, eventtime):
        self.inside_timer = True
    # WARNING: Decompyle incomplete

    cmd_UPDATE_DELAYED_GCODE_help = 'Update the duration of a delayed_gcode'
    
    def cmd_UPDATE_DELAYED_GCODE(self, gcmd):
        self.duration = gcmd.get_float('DURATION', minval=0)
        if self.inside_timer:
            self.repeat = self.duration != 0
        else:
            waketime = self.reactor.NEVER
            if self.duration:
                waketime = self.reactor.monotonic() + self.duration
            self.reactor.update_timer(self.timer_handler, waketime)



def load_config_prefix(config):
    return DelayedGcode(config)

