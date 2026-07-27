# Source Generated with Decompyle++
# File: heater_fan.pyc (Python 3.9)

from . import fan
PIN_MIN_TIME = 0.1

class PrinterHeaterFan:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        self.printer.load_object(config, 'heaters')
        self.printer.register_event_handler('klippy:ready', self.handle_ready)
        self.heater_names = config.getlist('heater', ('extruder',))
        self.heater_temp = config.getfloat('heater_temp', 5e+01)
        self.heaters = []
        self.fan = fan.Fan(config, default_shutdown_speed=1.0)
        self.fan_speed = config.getfloat('fan_speed', 1.0, minval=0.0, maxval=1.0)
        self.last_speed = 0.0
        self.is_ptc_fan = config.getint('is_ptc_fan', 0)

    
    def handle_ready(self):
        pheaters = self.printer.lookup_object('heaters')
        self.heaters = [ pheaters.lookup_heater(n) for n in (self.heater_names) ]
        reactor = self.printer.get_reactor()
        reactor.register_timer(self.callback, reactor.monotonic() + PIN_MIN_TIME)

    
    def get_status(self, eventtime):
        return self.fan.get_status(eventtime)

    
    def callback(self, eventtime):
        speed = 0.0
        for heater in self.heaters:
            (current_temp, target_temp) = heater.get_temp(eventtime)
            if not target_temp:
                if current_temp > self.heater_temp:
                    speed = self.fan_speed
                    continue
                    chamber_heater = self.printer.lookup_object('heater_generic chamber_heater', None)
                    heater_bed_state = self.printer.lookup_object('heater_bed').heater_bed_state
                    if self.is_ptc_fan == 1 and target_temp > 40 and chamber_heater and hasattr(chamber_heater.control, 'max_delta'):
                        if chamber_heater.last_pwm_value == 0:
                            speed = 0
                        else:
                            speed = 0.3
                        if chamber_heater.control.count != 20:
                            speed = 0
        if speed != self.last_speed:
            self.last_speed = speed
            curtime = self.printer.get_reactor().monotonic()
            print_time = self.fan.get_mcu().estimated_print_time(curtime)
            self.fan.set_speed(print_time + PIN_MIN_TIME, speed)
        return eventtime + 1.0



def load_config_prefix(config):
    return PrinterHeaterFan(config)

