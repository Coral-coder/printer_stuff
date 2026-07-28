# Source Generated with Decompyle++
# File: fan_feedback.pyc (Python 3.9)

import logging

class FanFeedback:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        self.print_delay_time = config.getfloat('print_delay_time', 3.0)
        self.current_delay_time = config.getfloat('current_delay_time', 2.0)
        ppins = self.printer.lookup_object('pins')
        self.params = []
        fan0_pin_sensor_pin = config.getlist('fan0_pin', None)
        self.mcu_fan_count = len(fan0_pin_sensor_pin)
        pins_count = 0
        pin_sensor_pin = fan0_pin_sensor_pin[pins_count]
        fan0_pin_params = ppins.lookup_pin(pin_sensor_pin, can_invert=False, can_pullup=True)
        mcu = fan0_pin_params['chip']
        mcu_oid = mcu.create_oid()
        mcu_config_cmd = 'config_fancheck oid=%d fan_num=%d ' % (mcu_oid, self.mcu_fan_count)
        mcu_config_cmd += ' fan%d_pin=%s pull_up%d=%s' % (pins_count, fan0_pin_params['pin'], pins_count, fan0_pin_params['pullup'])
        for i in range(self.mcu_fan_count - 1):
            pins_count += 1
            pin_sensor_pin = fan0_pin_sensor_pin[pins_count]
            fan0_pin_params = ppins.lookup_pin(pin_sensor_pin, can_invert=False, can_pullup=True)
            mcu_config_cmd += ' fan%d_pin=%s pull_up%d=%s' % (pins_count, fan0_pin_params['pin'], pins_count, fan0_pin_params['pullup'])
        for i in range(5 - self.mcu_fan_count):
            pins_count += 1
            mcu_config_cmd += ' fan%d_pin=%s pull_up%d=%s' % (pins_count, fan0_pin_params['pin'], pins_count, fan0_pin_params['pullup'])
        mcu.add_config_cmd(mcu_config_cmd)
        mcu.register_response(self._handle_result_fan_check0, 'fan_status', mcu_oid)
        param = (0, mcu_config_cmd, fan0_pin_params, mcu, mcu_oid)
        self.params.append(param)
        fan1_pin_sensor_pin = config.get('fan1_pin')
        fan2_pin_sensor_pin = config.get('fan2_pin')
        self.nozzle_mcu_fan_count = 2
        fan1_pin_params = ppins.lookup_pin(fan1_pin_sensor_pin, can_invert=False, can_pullup=True)
        fan2_pin_params = ppins.lookup_pin(fan2_pin_sensor_pin, can_invert=False, can_pullup=True)
        nozzle_mcu = fan1_pin_params['chip']
        nozzle_mcu_oid = nozzle_mcu.create_oid()
        nozzle_mcu_config_cmd = 'config_fancheck oid=%d fan_num=%d fan0_pin=%s pull_up0=%s fan1_pin=%s pull_up1=%s fan2_pin=%s pull_up2=%s fan3_pin=%s pull_up3=%s fan4_pin=%s pull_up4=%s' % (nozzle_mcu_oid, self.nozzle_mcu_fan_count, fan1_pin_params['pin'], fan1_pin_params['pullup'], fan2_pin_params['pin'], fan2_pin_params['pullup'], fan2_pin_params['pin'], fan2_pin_params['pullup'], fan2_pin_params['pin'], fan2_pin_params['pullup'], fan2_pin_params['pin'], fan2_pin_params['pullup'])
        nozzle_mcu.add_config_cmd(nozzle_mcu_config_cmd)
        nozzle_mcu.register_response(self._handle_result_fan_check1, 'fan_status', nozzle_mcu_oid)
        param = (1, nozzle_mcu_config_cmd, fan1_pin_params, nozzle_mcu, nozzle_mcu_oid)
        self.params.append(param)
        self.gcode = config.get_printer().lookup_object('gcode')
        self.gcode.register_command('QUERY_FAN_CHECK', self.cmd_QUERY_FAN_CHECK, desc=self.cmd_QUERY_FAN_CHECK_help)
        self.gcode.register_command('QUERY_PTC_FAN_CHECK', self.cmd_QUERY_PTC_FAN_CHECK, desc=self.cmd_QUERY_PTC_FAN_CHECK_help)
        self.print_stats = self.printer.load_object(config, 'print_stats')
        self.printer.register_event_handler('klippy:ready', self.handle_ready)
        self.ptc_fan_speed = { }
        self.cx_fan_status = { }
        webhooks = self.printer.lookup_object('webhooks')
        webhooks.register_endpoint('get_cx_fan_status', self._get_cx_fan_status)

    
    def handle_ready(self):
        reactor = self.printer.get_reactor()
        reactor.register_timer(self.cx_fan_status_update_event, reactor.monotonic() + 1.0)

    
    def delay_s(self, delay_s):
        toolhead = self.printer.lookup_object('toolhead')
        reactor = self.printer.get_reactor()
        eventtime = reactor.monotonic()
        if not self.printer.is_shutdown():
            toolhead.get_last_move_time()
            eventtime = reactor.pause(eventtime + delay_s)

    
    def _get_cx_fan_status(self, web_request):
        web_request.send(self.cx_fan_status)

    
    def cx_fan_status_update_event(self, eventtime):
        if self.print_stats.get_status(eventtime).get('state') != 'printing':
            next_time = eventtime + self.current_delay_time
        else:
            next_time = eventtime + self.print_delay_time
        for obj in self.params:
            cmd = 'query_fancheck oid=%c which_fan=%c'
            oid = obj[4]
            mcu = obj[3]
            query_cmd = mcu.lookup_command(cmd, cq=None)
            which_fan = 0
            if mcu._name == 'mcu':
                which_fan = 2 ** self.mcu_fan_count - 1
            elif mcu._name == 'nozzle_mcu':
                which_fan = 2 ** self.nozzle_mcu_fan_count - 1
            query_cmd.send([
                oid,
                which_fan])
        return next_time

    cmd_QUERY_FAN_CHECK_help = 'Check CXSW Special Fan Status'
    
    def cmd_QUERY_FAN_CHECK(self, gcmd):
        self.gcode.respond_info('%s' % self.cx_fan_status)

    cmd_QUERY_PTC_FAN_CHECK_help = 'Check CXSW Special PTC Fan Status'
    
    def cmd_QUERY_PTC_FAN_CHECK(self, gcmd):
        self.gcode.respond_info('multi ptc %s' % self.ptc_fan_speed)

    
    def _handle_result_fan_check0(self, params):
        fan0_speed = params.get('fan0_speed', 0)
        if self.mcu_fan_count > 1:
            ptc_fan_abnormal = False
            for i in range(self.mcu_fan_count):
                fan_key = 'fan%d_speed' % i
                self.ptc_fan_speed[fan_key] = fan_x_speed = params.get(fan_key, 0)
                if fan_x_speed == 0:
                    ptc_fan_abnormal = True
            if ptc_fan_abnormal:
                fan0_speed = 0
        self.cx_fan_status = {
            'fan0_speed': fan0_speed,
            'fan1_speed': self.cx_fan_status.get('fan1_speed', 0),
            'fan2_speed': self.cx_fan_status.get('fan2_speed', 0),
            'fan3_speed': self.cx_fan_status.get('fan3_speed', 0),
            'fan4_speed': self.cx_fan_status.get('fan4_speed', 0) }

    
    def _handle_result_fan_check1(self, params):
        self.cx_fan_status = {
            'fan0_speed': self.cx_fan_status.get('fan0_speed', 0),
            'fan1_speed': params.get('fan0_speed', 0),
            'fan2_speed': params.get('fan1_speed', 0),
            'fan3_speed': self.cx_fan_status.get('fan3_speed', 0),
            'fan4_speed': self.cx_fan_status.get('fan4_speed', 0) }

    
    def get_status(self, eventtime):
        return self.cx_fan_status



def load_config(config):
    return FanFeedback(config)

