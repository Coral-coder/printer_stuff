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
        self._max_duration = 2.0
        self._oid = None
        self._invert = pin_params['invert']
        self._start_value = self._shutdown_value = float(self._invert)
        self._is_static = False
        self._last_clock = 0
        self._pwm_max = 0.0
        self._set_cmd = None

    
    def get_mcu(self):
        return self._mcu

    
    def setup_max_duration(self, max_duration):
        self._max_duration = max_duration

    
    def setup_cycle_time(self, cycle_time, hardware_pwm = False):
        if hardware_pwm:
            raise pins.error('{"code":"key216", "msg": "pca9685 does not support hardware_pwm parameter" "values": []}')
        if cycle_time != self._cycle_time:
            logging.info('Ignoring pca9685 cycle time of %.6f (using %.6f)', cycle_time, self._cycle_time)

    
    def setup_start_value(self, start_value, shutdown_value, is_static = False):
        if is_static and start_value != shutdown_value:
            raise pins.error('{"code":"key277": "msg":"Static pin can not have shutdown value", "values":[]}')
        if self._invert:
            start_value = 1.0 - start_value
            shutdown_value = 1.0 - shutdown_value
        self._start_value = max(0.0, min(1.0, start_value))
        self._shutdown_value = max(0.0, min(1.0, shutdown_value))
        self._is_static = is_static
        self._replicape.note_pwm_start_value(self._channel, self._start_value, self._shutdown_value)

    
    def _build_config(self):
        self._pwm_max = self._mcu.get_constant_float('PCA9685_MAX')
        cycle_ticks = self._mcu.seconds_to_clock(self._cycle_time)
        if self._is_static:
            self._mcu.add_config_cmd('set_pca9685_out bus=%d addr=%d channel=%d cycle_ticks=%d value=%d' % (self._bus, self._address, self._channel, cycle_ticks, self._start_value * self._pwm_max))
            return None
        self._mcu.request_move_queue_slot()
        self._oid = self._mcu.create_oid()
        self._mcu.add_config_cmd('config_pca9685 oid=%d bus=%d addr=%d channel=%d cycle_ticks=%d value=%d default_value=%d max_duration=%d' % (self._oid, self._bus, self._address, self._channel, cycle_ticks, self._start_value * self._pwm_max, self._shutdown_value * self._pwm_max, self._mcu.seconds_to_clock(self._max_duration)))
        cmd_queue = self._mcu.alloc_command_queue()
        self._set_cmd = self._mcu.lookup_command('queue_pca9685_out oid=%c clock=%u value=%hu', cq=cmd_queue)

    
    def set_pwm(self, print_time, value, cycle_time = None):
        clock = self._mcu.print_time_to_clock(print_time)
        if self._invert:
            value = 1.0 - value
        value = int(max(0.0, min(1.0, value)) * self._pwm_max + 0.5)
        self._replicape.note_pwm_enable(print_time, self._channel, value)
        self._set_cmd.send([
            self._oid,
            clock,
            value], minclock=self._last_clock, reqclock=clock)
        self._last_clock = clock

    
    def set_digital(self, print_time, value):
        if value:
            self.set_pwm(print_time, 1.0)
        else:
            self.set_pwm(print_time, 0.0)



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
            self.pwm.set_pwm(print_time, 0.0)


SERVO_PINS = {
    'servo0': ('/pwm0', 'gpio0_30', 'gpio1_18'),
    'servo1': ('/pwm1', 'gpio3_17', 'gpio1_19') }

class servo_pwm:
    
    def __init__(self, replicape, pin_params):
        config_name = pin_params['pin']
        pwmchip = 'pwmchip0'
        if not replicape.host_mcu.is_fileoutput():

            try:
                pwmdev = os.listdir('/sys/devices/platform/ocp/48302000.epwmss/48302200.pwm/pwm/')
                pwmchip = [ pc for pc in (pwmdev) if pc.startswith('pwmchip') ][0]
            except:
                raise pins.error('{"code":"key279": "msg":"Replicape unable to determine pwmchip", "values":[]}')

        (pwm_pin, resv1, resv2) = SERVO_PINS[config_name]
        pin_params = dict(pin_params)
        pin_params['pin'] = pwmchip + pwm_pin
        self.mcu_pwm = replicape.host_mcu.setup_pin('pwm', pin_params)
        self.get_mcu = self.mcu_pwm.get_mcu
        self.setup_max_duration = self.mcu_pwm.setup_max_duration
        self.setup_start_value = self.mcu_pwm.setup_start_value
        self.set_pwm = self.mcu_pwm.set_pwm
        pru_mcu = replicape.mcu_pwm_enable.get_mcu()
        printer = pru_mcu.get_printer()
        ppins = printer.lookup_object('pins')
        pin_resolver = ppins.get_pin_resolver(pru_mcu.get_name())
        pin_resolver.reserve_pin(resv1, config_name)
        pin_resolver.reserve_pin(resv2, config_name)

    
    def setup_cycle_time(self, cycle_time, hardware_pwm = False):
        self.mcu_pwm.setup_cycle_time(cycle_time, True)


ReplicapeStepConfig = {
    'disable': None,
    '1': 160,
    '2': 224,
    'spread2': 32,
    '4': 176,
    '16': 240,
    'spread4': 48,
    'spread16': 128,
    'stealth4': 192,
    'stealth16': 0 }

class Replicape:
    
    def __init__(self, config):
        printer = config.get_printer()
        ppins = printer.lookup_object('pins')
        ppins.register_chip('replicape', self)
        revisions = {
            'B3': 'B3' }
        config.getchoice('revision', revisions)
        self.host_mcu = mcu.get_printer_mcu(printer, config.get('host_mcu'))
        enable_pin = config.get('enable_pin', '!gpio0_20')
        self.mcu_pwm_enable = ppins.setup_pin('digital_out', enable_pin)
        self.mcu_pwm_enable.setup_max_duration(0.0)
        self.mcu_pwm_start_value = self.mcu_pwm_shutdown_value = False
        self.pins = {
            'power_e': (pca9685_pwm, 5),
            'power_h': (pca9685_pwm, 3),
            'power_hotbed': (pca9685_pwm, 4),
            'power_fan0': (pca9685_pwm, 7),
            'power_fan1': (pca9685_pwm, 8),
            'power_fan2': (pca9685_pwm, 9),
            'power_fan3': (pca9685_pwm, 10) }
        self.servo_pins = {
            'servo0': 3,
            'servo1': 2 }
        self.last_stepper_time = 0.0
        self.stepper_dacs = { }
        shift_registers = [
            1,
            0,
            0,
            1,
            1]
        for port, name in enumerate('xyzeh'):
            prefix = 'stepper_%s_' % (name,)
            sc = config.getchoice(prefix + 'microstep_mode', ReplicapeStepConfig, 'disable')
            if sc is None:
                continue
            sc |= shift_registers[port]
            if config.getboolean(prefix + 'chopper_off_time_high', False):
                sc |= 8
            if config.getboolean(prefix + 'chopper_hysteresis_high', False):
                sc |= 4
            if config.getboolean(prefix + 'chopper_blank_time_high', True):
                sc |= 2
            shift_registers[port] = sc
            channel = port + 11
            cur = config.getfloat(prefix + 'current', above=0.0, maxval=REPLICAPE_MAX_CURRENT)
            self.stepper_dacs[channel] = cur / REPLICAPE_MAX_CURRENT
            self.pins[prefix + 'enable'] = (ReplicapeDACEnable, channel)
        self.enabled_channels = { ch: False for cl, ch in (self.pins.values()) }
        self.sr_disabled = list(reversed(shift_registers))
        if [ i for i in ((0, 1, 2)) if 11 + i in self.stepper_dacs ]:
            shift_registers[0] &= -2
        if [ i for i in ((3, 4)) if 11 + i in self.stepper_dacs ]:
            shift_registers[3] &= -2
        if config.getboolean('standstill_power_down', False) and self.stepper_dacs:
            shift_registers[4] &= -2
        self.sr_enabled = list(reversed(shift_registers))
        sr_spi_bus = 'spidev1.1'
        if not self.host_mcu.is_fileoutput() and os.path.exists('/sys/devices/platform/ocp/481a0000.spi/spi_master/spi2'):
            sr_spi_bus = 'spidev2.1'
        self.sr_spi = bus.MCU_SPI(self.host_mcu, sr_spi_bus, None, 0, 50000000)
        self.sr_spi.setup_shutdown_msg(self.sr_disabled)
        self.sr_spi.spi_send(self.sr_disabled)

    
    def note_pwm_start_value(self, channel, start_value, shutdown_value):
        self.mcu_pwm_start_value |= (not (not start_value))
        self.mcu_pwm_shutdown_value |= (not (not shutdown_value))
        self.mcu_pwm_enable.setup_start_value(self.mcu_pwm_start_value, self.mcu_pwm_shutdown_value)
        self.enabled_channels[channel] = not (not start_value)

    
    def note_pwm_enable(self, print_time, channel, value):
        is_enable = not (not value)
        if self.enabled_channels[channel] == is_enable:
            return None
        self.enabled_channels[channel] = is_enable
        on_channels = [ 1 for c, e in (self.enabled_channels.items()) if e ]
        if not on_channels:
            self.mcu_pwm_enable.set_digital(print_time, 0)
        elif is_enable and len(on_channels) == 1:
            self.mcu_pwm_enable.set_digital(print_time, 1)
        if channel not in self.stepper_dacs:
            return None
        on_dacs = [ 1 for c in (self.stepper_dacs.keys()) if self.enabled_channels[c] ]
        if not on_dacs:
            sr = self.sr_disabled
        elif is_enable and len(on_dacs) == 1:
            sr = self.sr_enabled
        else:
            return None
        print_time = max(print_time, self.last_stepper_time + PIN_MIN_TIME)
        clock = self.host_mcu.print_time_to_clock(print_time)
        self.sr_spi.spi_send(sr, minclock=clock, reqclock=clock)

    
    def setup_pin(self, pin_type, pin_params):
        pin = pin_params['pin']
        if pin in self.pins:
            (pclass, channel) = self.pins[pin]
            return pclass(self, channel, pin_type, pin_params)
        if pin in self.servo_pins:
            index = self.servo_pins[pin]
            self.sr_enabled[index] |= 1
            self.sr_disabled[index] |= 1
            self.sr_spi.spi_send(self.sr_disabled)
            return servo_pwm(self, pin_params)
        raise pins.error('Unknown replicape pin %s' % (pin,))



def load_config(config):
    return Replicape(config)

