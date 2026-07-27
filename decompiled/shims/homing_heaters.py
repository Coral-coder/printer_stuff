# Source Generated with Decompyle++
# File: homing_heaters.pyc (Python 3.9)

import logging

class HomingHeaters:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        self.printer.register_event_handler('klippy:connect', self.handle_connect)
        self.printer.register_event_handler('homing:homing_move_begin', self.handle_homing_move_begin)
        self.printer.register_event_handler('homing:homing_move_end', self.handle_homing_move_end)
        self.disable_heaters = config.getlist('heaters', None)
        self.flaky_steppers = config.getlist('steppers', None)
        self.pheaters = self.printer.load_object(config, 'heaters')
        self.target_save = { }

    
    def handle_connect(self):
        all_heaters = self.pheaters.get_all_heaters()
        if self.disable_heaters is None:
            self.disable_heaters = all_heaters
        elif not None(for x in (self.disable_heaters):
x in all_heaters):
            raise self.printer.config_error('{"code":"key68", "msg": "One or more of these heaters are unknown: %s", "values": ["%s"]}' % (self.disable_heaters, self.disable_heaters))
        kin = self.printer.lookup_object('toolhead').get_kinematics()
        all_steppers = (lambda .0: [ s.get_name() for s in .0 ])(kin.get_steppers())
        if self.flaky_steppers is None:
            return None
        if not None(for x in (self.flaky_steppers):
x in all_steppers):
            raise self.printer.config_error('{"code":"key67", "msg":"One or more of these steppers are unknown: %s", "values": ["%s"]}' % (self.flaky_steppers, self.flaky_steppers))

    
    def check_eligible(self, endstops):
        if self.flaky_steppers is None:
            return True
        steppers_being_homed = (lambda 