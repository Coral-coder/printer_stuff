# Source Generated with Decompyle++
# File: extruder_stepper.pyc (Python 3.9)

import logging
from kinematics import extruder

class PrinterExtruderStepper:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        self.extruder_stepper = extruder.ExtruderStepper(config)
        self.extruder_name = config.get('extruder')
        self.printer.register_event_handler('klippy:connect', self.handle_connect)

    
    def handle_connect(self):
        self.extruder_stepper.sync_to_extruder(self.extruder_name)

    
    def get_status(self, eventtime):
        return self.extruder_stepper.get_status(eventtime)



def load_config_prefix(config):
    return PrinterExtruderStepper(config)

