# Source Generated with Decompyle++
# File: idle_timeout.pyc (Python 3.9)

import logging
DEFAULT_IDLE_GCODE = "\n{% if 'heaters' in printer %}\n   TURN_OFF_HEATERS\n{% endif %}\nM84\n"
PIN_MIN_TIME = 0.1
READY_TIMEOUT = 0.5

class IdleTimeout:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        self.reactor = self.printer.get_reactor()
        self.gcode = self.printer.lookup_object('gcode')
        self.toolhead = None
        self.timeout_timer = None
        self.printer.register_event_handler('klippy:ready', self.handle_ready)
        self.idle_timeout = config.getfloat('timeout', 600, above=0)
        gcode_macro = self.printer.load_object(config, 'gcode_macro')
        self.idle_gcode = gcode_macro.load_template(config, 'gcode', DEFAULT_IDLE_GCODE)
        self.gcode.register_command('SET_IDLE_TIMEOUT', self.cmd_SET_IDLE_TIMEOUT, desc=self.cmd_SET_IDLE_TIMEOUT_help)
        self.state = 'Idle'
        self.last_print_start_systime = 0

    
    def get_status(self, eventtime):
        printing_time = 0
        if self.state == 'Printing':
            printing_time = eventtime - self.last_print_start_systime
        return {
            'state': self.state,
            'printing_time': printing_time }

    
    def handle_ready(self):
        self.toolhead = self.printer.lookup_object('toolhead')
        self.timeout_timer = self.reactor.register_timer(self.timeout_handler)
        self.printer.register_event_handler('toolhead:sync_print_time', self.handle_sync_print_time)

    
    def transition_idle_state(self, eventtime):
        self.state = 'Printing'
        
        try:
            script = self.idle_gcode.render()
            res = self.gcode.run_script(script)
        finally:
            pass
        logging.exception('idle timeout gcode execution')
        self.state = 'Ready'
        return None
        print_time = self.toolhead.get_last_move_time()
        self.state = 'Idle'
        self.printer.send_event('idle_timeout:idle', print_time)
        return self.reactor.NEVER


    
    def check_idle_timeout(self, eventtime):
        (print_time, est_print_time, lookahead_empty) = self.toolhead.check_busy(eventtime)
        idle_time = est_print_time - print_time
        if lookahead_empty or idle_time < 1:
            return eventtime + self.idle_timeout
        if None < self.idle_timeout:
            return eventtime + self.idle_timeout - idle_time
        if None.gcode.get_mutex().test():
            return eventtime + 1
        return None.transition_idle_state(eventtime)

    
    def timeout_handler(self, eventtime):
        if self.printer.is_shutdown():
            return self.reactor.NEVER
        if None.state == 'Ready':
            return self.check_idle_timeout(eventtime)
        (print_time, est_print_time, lookahead_empty) = None.toolhead.check_busy(eventtime)
        buffer_time = min(2, print_time - est_print_time)
        if not lookahead_empty:
            return eventtime + READY_TIMEOUT + max(0, buffer_time)
        if None > -READY_TIMEOUT:
            return eventtime + READY_TIMEOUT + buffer_time
        if None.gcode.get_mutex().test():
            return eventtime + READY_TIMEOUT
        self.state = None
        self.printer.send_event('idle_timeout:ready', est_print_time + PIN_MIN_TIME)
        return eventtime + self.idle_timeout

    
    def handle_sync_print_time(self, curtime, print_time, est_print_time):
        if self.state == 'Printing':
            return None
        self.state = None
        self.last_print_start_systime = curtime
        check_time = READY_TIMEOUT + print_time - est_print_time
        self.reactor.update_timer(self.timeout_timer, curtime + check_time)
        self.printer.send_event('idle_timeout:printing', est_print_time + PIN_MIN_TIME)

    cmd_SET_IDLE_TIMEOUT_help = 'Set the idle timeout in seconds'
    
    def cmd_SET_IDLE_TIMEOUT(self, gcmd):
        timeout = gcmd.get_float('TIMEOUT', self.idle_timeout, above=0)
        self.idle_timeout = timeout
        gcmd.respond_info('idle_timeout: Timeout set to %.2f s' % (timeout,))
        if self.state == 'Ready':
            checktime = self.reactor.monotonic() + timeout
            self.reactor.update_timer(self.timeout_timer, checktime)



def load_config(config):
    return IdleTimeout(config)

