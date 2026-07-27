# Source Generated with Decompyle++
# File: buttons.pyc (Python 3.9)

import logging
QUERY_TIME = 0.002
RETRANSMIT_COUNT = 50

class MCU_buttons:
    
    def __init__(self, printer, mcu):
        self.reactor = printer.get_reactor()
        self.mcu = mcu
        self.mcu.register_config_callback(self.build_config)
        self.pin_list = []
        self.callbacks = []
        self.invert = self.last_button = 0
        self.ack_cmd = None
        self.ack_count = 0

    
    def setup_buttons(self, pins, callback):
        mask = 0
        shift = len(self.pin_list)
        for pin_params in pins:
            if pin_params['invert']:
                self.invert |= 1 << len(self.pin_list)
            mask |= 1 << len(self.pin_list)
            self.pin_list.append((pin_params['pin'], pin_params['pullup']))
        self.callbacks.append((mask, shift, callback))

    
    def build_config(self):
        if not self.pin_list:
            return None
        self.oid = None.mcu.create_oid()
        self.mcu.add_config_cmd('config_buttons oid=%d button_count=%d' % (self.oid, len(self.pin_list)))
        for pin, pull_up in enumerate(self.pin_list):
            self.mcu.add_config_cmd('buttons_add oid=%d pos=%d pin=%s pull_up=%d' % (self.oid, i, pin, pull_up), is_init=True)
        cmd_queue = self.mcu.alloc_command_queue()
        self.ack_cmd = self.mcu.lookup_command('buttons_ack oid=%c count=%c', cq=cmd_queue)
        clock = self.mcu.get_query_slot(self.oid)
        rest_ticks = self.mcu.seconds_to_clock(QUERY_TIME)
        self.mcu.add_config_cmd('buttons_query oid=%d clock=%d rest_ticks=%d retransmit_count=%d invert=%d' % (self.oid, clock, rest_ticks, RETRANSMIT_COUNT, self.invert), is_init=True)
        self.mcu.register_response(self.handle_buttons_state, 'buttons_state', self.oid)

    
    def handle_buttons_state(self, params):
        ack_count = self.ack_count
        ack_diff = ack_count - params['ack_count'] & 255
        if ack_diff & 128:
            ack_diff -= 256
        msg_ack_count = ack_count - ack_diff
        buttons = bytearray(params['state'])
        new_count = msg_ack_count + len(buttons) - self.ack_count
        if new_count <= 0:
            return None
        new_buttons = None[-new_count:]
        self.ack_cmd.send([
            self.oid,
            new_count])
        self.ack_count += new_count
        for nb in new_buttons:
            self.reactor.register_async_callback((lambda e, s, b = (self, nb): s.handle_button(e, b)))

    
    def handle_button(self, eventtime, button):
