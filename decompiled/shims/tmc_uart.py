# Source Generated with Decompyle++
# File: tmc_uart.pyc (Python 3.9)

import logging

class MCU_analog_mux:
    
    def __init__(self, mcu, cmd_queue, select_pins_desc):
        self.mcu = mcu
        self.cmd_queue = cmd_queue
        ppins = mcu.get_printer().lookup_object('pins')
        select_pin_params = [ ppins.lookup_pin(spd, can_invert=True) for spd in (select_pins_desc) ]
        self.oids = [ self.mcu.create_oid() for pp in (select_pin_params) ]
        self.pins = (lambda .0: [ pp['pin'] for pp in .0 ])(select_pin_params)
        self.pin_values = tuple((lambda .0: [ -1 for pp in .0 ])(select_pin_params))
        for oid, pin in zip(self.oids, self.pins):
            self.mcu.add_config_cmd('config_digital_out oid=%d pin=%s value=0 default_value=0 max_duration=0' % (oid, pin))
        self.update_pin_cmd = None
        self.mcu.register_config_callback(self.build_config)

    
    def build_config(self):
        self.update_pin_cmd = self.mcu.lookup_command('update_digital_out oid=%c value=%c', cq=self.cmd_queue)

    
    def get_instance_id(self, select_pins_desc):
        ppins = self.mcu.get_printer().lookup_object('pins')
        select_pin_params = [ ppins.parse_pin(spd, can_invert=True) for spd in (select_pins_desc) ]
        for pin_params in select_pin_params:
            if pin_params['chip'] != self.mcu:
                raise self.mcu.get_printer().config_error('TMC mux pins must be on the same mcu')
        pins = (lambda .0: [ pp['pin'] for pp in .0 ])(select_pin_params)
        if pins != self.pins:
            raise self.mcu.get_printer().config_error('All TMC mux instances must use identical pins')
        return tuple((lambda .0: [ not pp['invert'] for pp in .0 ])(select_pin_params))

    
    def activate(self, instance_id):
