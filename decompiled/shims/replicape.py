# =====================================================================
# PARTIAL DECOMPILATION -- this module did not fully round-trip.
# The 3.9 bytecode uses control flow the decompiler could not fully
# reconstruct (e.g. try/except/else with returns, or a generator with a
# dropped builtin rendered as `None(...)`). The code below is best-effort
# and will not import as-is. Ground-truth disassembly for repair:
#     decompiled/_disasm/replicape.txt
# =====================================================================

# Source Generated with Decompyle++
# File: replicape.pyc (Python 3.9)

import logging
import os
import pins
import mcu
from . import bus
REPLICAPE_MAX_CURRENT = 3.84
REPLICAPE_PCA9685_BUS = 2
REPLICAPE_PCA9685_ADDRESS = 112
REPLICAPE_PCA9685_CYCLE_TIME = 0.001
PIN_MIN_TIME = 0.1

class pca9685_pwm:
    
    def __init__(self, replicape, channel, pin_type, pin_params):
        self._replicape = replicape
        self._channel = channel
        if pin_type not in ('digital_out', 'pwm'):
            raise pins.error('{"code":"key276": "msg":"Pin type not supported on replicape", "values":[]}')
        self._mcu = replicape.host_mcu
        self._mcu.register_config_callback(self._build_config)
        self._bus = REPLICAPE_PCA9685_BUS
        self._address = REPLICAPE_PCA9685_ADDRESS
        self._cycle_time = REPLICAPE_PCA9685_CYCLE_TIME
        self._max_duration = 2
        self._oid = None
        self._invert = pin_params['invert']
        self._start_value = self._shutdown_value = float(self._invert)
        self._is_static = False
        self._last_clock = 0
        self._pwm_max = 0
        self._set_cmd = None

    
    def get_mcu(self):
        return self._mcu

    
    def setup_max_duration(self, max_duration):
        self._max_duration = max_duration

    
    def setup_cycle_time(self, cycle_time, hardware_pwm = (False,)):
        if hardware_pwm:
            raise pins.error('{"code":"key216", "msg": "pca9685 does not support hardware_pwm parameter" "values": []}')
        if cycle_time != self._cycle_time:
            logging.info('Ignoring pca9685 cycle time of %.6f (using %.6f)', cycle_time, self._cycle_time)

    
    def setup_start_value(self, start_value, shutdown_value, is_static = (False,)):
        if is_static and start_value != shutdown_value:
            raise pins.error('{"code":"key277": "msg":"Static pin can not have shutdown value", "values":[]}')
        if self._invert:
            start_value = 1 - start_value
            shutdown_value = 1 - shutdown_value
        self._start_value = max(0, min(1, start_value))
        self._shutdown_value = max(0, min(1, shutdown_value))
        self._is_static = is_static
        self._replicape.note_pwm_start_value(self._channel, self._start_value, self._shutdown_value)

    
    def _build_config(self):
        self._pwm_max = self._mcu.get_constant_float('PCA9685_MAX')
        cycle_ticks = self._mcu.seconds_to_clock(self._cycle_time)
        if self._is_static:
            self._mcu.add_config_cmd('set_pca9685_out bus=%d addr=%d channel=%d cycle_ticks=%d value=%d' % (self._bus, self._address, self._channel, cycle_ticks, self._start_value * self._pwm_max))
            return None
        None._mcu.request_move_queue_slot()
        self._oid = self._mcu.create_oid()
        self._mcu.add_config_cmd('config_pca9685 oid=%d bus=%d addr=%d channel=%d cycle_ticks=%d value=%d default_value=%d max_duration=%d' % (self._oid, self._bus, self._address, self._channel, cycle_ticks, self._start_value * self._pwm_max, self._shutdown_value * self._pwm_max, self._mcu.seconds_to_clock(self._max_duration)))
        cmd_queue = self._mcu.alloc_command_queue()
        self._set_cmd = self._mcu.lookup_command('queue_pca9685_out oid=%c clock=%u value=%hu', cq=cmd_queue)

    
    def set_pwm(self, print_time, value, cycle_time = (None,)):
        clock = self._mcu.print_time_to_clock(print_time)
        if self._invert:
            value = 1 - value
        value = int(max(0, min(1, value)) * self._pwm_max + 0.5)
        self._replicape.note_pwm_enable(print_time, self._channel, value)
        self._set_cmd.send([
            self._oid,
            clock,
            value], minclock=self._last_clock, reqclock=clock)
        self._last_clock = clock

    
    def set_digital(self, print_time, value):
        if value:
            self.set_pwm(print_time, 1)
        else:
            self.set_pwm(print_time, 0)



class ReplicapeDACEnable:
    
    def __init__(self, replicape, channel, pin_type, pin_params):
        if pin_type != 'digital_out':
            raise pins.error('{"code":"key277": "msg":"Static pin can not have shutdown value", "values":[]}')
        if pin_params['invert']:
            raise pins.error('{"code":"key278": "msg":"Replicape virtual enable pin can not be invertede", "values":[]}')
        self.mcu = replicape.host_mcu
        self.value = replicape.stepper_dacs[channel]
        self.pwm = pca9685_pwm(replicape, channel, pin_type, pin_params)

    
    def get_mcu(self):
        return self.mcu

    
    def setup_max_duration(self, max_duration):
        self.pwm.setup_max_duration(max_duration)

    
    def set_digital(self, print_time, value):
        if value:
            self.pwm.set_pwm(print_time, self.value)
        else:
            self.pwm.set_pwm(print_time, 0)


SERVO_PINS = {
    'servo0': ('/pwm0', 'gpio0_30', 'gpio1_18'),
    'servo1': ('/pwm1', 'gpio3_17', 'gpio1_19') }

class servo_pwm:
    
    def __init__(self, replicape, pin_params):
