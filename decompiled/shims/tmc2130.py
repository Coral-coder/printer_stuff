# Source Generated with Decompyle++
# File: tmc2130.pyc (Python 3.9)

import math
import logging
from . import bus, tmc
TMC_FREQUENCY = 1.32e+07
Registers = {
    'GCONF': 0,
    'GSTAT': 1,
    'IOIN': 4,
    'IHOLD_IRUN': 16,
    'TPOWERDOWN': 17,
    'TSTEP': 18,
    'TPWMTHRS': 19,
    'TCOOLTHRS': 20,
    'THIGH': 21,
    'XDIRECT': 45,
    'MSLUT0': 96,
    'MSLUT1': 97,
    'MSLUT2': 98,
    'MSLUT3': 99,
    'MSLUT4': 100,
    'MSLUT5': 101,
    'MSLUT6': 102,
    'MSLUT7': 103,
    'MSLUTSEL': 104,
    'MSLUTSTART': 105,
    'MSCNT': 106,
    'MSCURACT': 107,
    'CHOPCONF': 108,
    'COOLCONF': 109,
    'DCCTRL': 110,
    'DRV_STATUS': 111,
    'PWMCONF': 112,
    'PWM_SCALE': 113,
    'ENCM_CTRL': 114,
    'LOST_STEPS': 115 }
ReadRegisters = [
    'GCONF',
    'GSTAT',
    'IOIN',
    'TSTEP',
    'XDIRECT',
    'MSCNT',
    'MSCURACT',
    'CHOPCONF',
    'DRV_STATUS',
    'PWM_SCALE',
    'LOST_STEPS']
Fields = { }
Fields['GCONF'] = {
    'i_scale_analog': 1,
    'internal_rsense': 2,
    'en_pwm_mode': 4,
    'enc_commutation': 8,
    'shaft': 16,
    'diag0_error': 32,
    'diag0_otpw': 64,
    'diag0_stall': 128,
    'diag1_stall': 256,
    'diag1_index': 512,
    'diag1_onstate': 1024,
    'diag1_steps_skipped': 2048,
    'diag0_int_pushpull': 4096,
    'diag1_pushpull': 8192,
    'small_hysteresis': 16384,
    'stop_enable': 32768,
    'direct_mode': 65536,
    'test_mode': 131072 }
Fields['GSTAT'] = {
    'reset': 1,
    'drv_err': 2,
    'uv_cp': 4 }
Fields['IOIN'] = {
    'step': 1,
    'dir': 2,
    'dcen_cfg4': 4,
    'dcin_cfg5': 8,
    'drv_enn_cfg6': 16,
    'dco': 32,
    'version': 0xFF000000 }
Fields['IHOLD_IRUN'] = {
    'ihold': 31,
    'irun': 7936,
    'iholddelay': 983040 }
Fields['TPOWERDOWN'] = {
    'tpowerdown': 255 }
Fields['TSTEP'] = {
    'tstep': 1048575 }
Fields['TPWMTHRS'] = {
    'tpwmthrs': 1048575 }
Fields['TCOOLTHRS'] = {
    'tcoolthrs': 1048575 }
Fields['THIGH'] = {
    'thigh': 1048575 }
Fields['MSLUT0'] = {
    'mslut0': 0xFFFFFFFF }
Fields['MSLUT1'] = {
    'mslut1': 0xFFFFFFFF }
Fields['MSLUT2'] = {
    'mslut2': 0xFFFFFFFF }
Fields['MSLUT3'] = {
    'mslut3': 0xFFFFFFFF }
Fields['MSLUT4'] = {
    'mslut4': 0xFFFFFFFF }
Fields['MSLUT5'] = {
    'mslut5': 0xFFFFFFFF }
Fields['MSLUT6'] = {
    'mslut6': 0xFFFFFFFF }
Fields['MSLUT7'] = {
    'mslut7': 0xFFFFFFFF }
Fields['MSLUTSEL'] = {
    'x3': 0xFF000000,
    'x2': 16711680,
    'x1': 65280,
    'w3': 192,
    'w2': 48,
    'w1': 12,
    'w0': 3 }
Fields['MSLUTSTART'] = {
    'start_sin': 255,
    'start_sin90': 16711680 }
Fields['MSCNT'] = {
    'mscnt': 1023 }
Fields['MSCURACT'] = {
    'cur_a': 511,
    'cur_b': 33488896 }
Fields['CHOPCONF'] = {
    'toff': 15,
    'hstrt': 112,
    'hend': 1920,
    'fd3': 2048,
    'disfdcc': 4096,
    'rndtf': 8192,
    'chm': 16384,
    'tbl': 98304,
    'vsense': 131072,
    'vhighfs': 262144,
    'vhighchm': 524288,
    'sync': 15728640,
    'mres': 251658240,
    'intpol': 268435456,
    'dedge': 536870912,
    'diss2g': 1073741824 }
Fields['COOLCONF'] = {
    'semin': 15,
    'seup': 96,
    'semax': 3840,
    'sedn': 24576,
    'seimin': 32768,
    'sgt': 8323072,
    'sfilt': 16777216 }
Fields['DRV_STATUS'] = {
    'sg_result': 1023,
    'fsactive': 32768,
    'cs_actual': 2031616,
    'stallguard': 16777216,
    'ot': 33554432,
    'otpw': 67108864,
    's2ga': 134217728,
    's2gb': 268435456,
    'ola': 536870912,
    'olb': 1073741824,
    'stst': 0x80000000 }
Fields['PWMCONF'] = {
    'pwm_ampl': 255,
    'pwm_grad': 65280,
    'pwm_freq': 196608,
    'pwm_autoscale': 262144,
    'pwm_symmetric': 524288,
    'freewheel': 3145728 }
Fields['PWM_SCALE'] = {
    'pwm_scale': 255 }
Fields['LOST_STEPS'] = {
    'lost_steps': 1048575 }
SignedFields = [
    'cur_a',
    'cur_b',
    'sgt']
FieldFormatters = {
    'i_scale_analog': (lambda v: if v:
'1(ExtVREF)'),
    'shaft': (lambda v: if v:
'1(Reverse)'),
    'reset': (lambda v: if v:
'1(Reset)'),
    'drv_err': (lambda v: if v:
'1(ErrorShutdown!)'),
    'uv_cp': (lambda v: if v:
'1(Undervoltage!)'),
    'version': (lambda v: '%#x' % v),
    'mres': (lambda v: '%d(%dusteps)' % (v, 256 >> v)),
    'otpw': (lambda v: if v:
'1(OvertempWarning!)'),
    'ot': (lambda v: if v:
'1(OvertempError!)'),
    's2ga': (lambda v: if v:
'1(ShortToGND_A!)'),
    's2gb': (lambda v: if v:
'1(ShortToGND_B!)'),
    'ola': (lambda v: if v:
'1(OpenLoad_A!)'),
    'olb': (lambda v: if v:
'1(OpenLoad_B!)'),
    'cs_actual': (lambda v: if v:
'%d' % v) }
MAX_CURRENT = 2

class TMCCurrentHelper:
    
    def __init__(self, config, mcu_tmc):
        self.printer = config.get_printer()
        self.name = config.get_name().split()[-1]
        self.mcu_tmc = mcu_tmc
        self.fields = mcu_tmc.get_fields()
        run_current = config.getfloat('run_current', above=0, maxval=MAX_CURRENT)
        hold_current = config.getfloat('hold_current', MAX_CURRENT, above=0, maxval=MAX_CURRENT)
        self.req_hold_current = hold_current
        self.sense_resistor = config.getfloat('sense_resistor', 0.11, above=0)
        (vsense, irun, ihold) = self._calc_current(run_current, hold_current)
        self.fields.set_field('vsense', vsense)
        self.fields.set_field('ihold', ihold)
        self.fields.set_field('irun', irun)

    
    def _calc_current_bits(self, current, vsense):
        sense_resistor = self.sense_resistor + 0.02
        vref = 0.32
        if vsense:
            vref = 0.18
        cs = int(32 * sense_resistor * current * math.sqrt(2) / vref + 0.5) - 1
        return max(0, min(31, cs))

    
    def _calc_current_from_bits(self, cs, vsense):
        sense_resistor = self.sense_resistor + 0.02
        vref = 0.32
        if vsense:
            vref = 0.18
        return (cs + 1) * vref / (32 * sense_resistor * math.sqrt(2))

    
    def _calc_current(self, run_current, hold_current):
        vsense = True
        irun = self._calc_current_bits(run_current, True)
        if irun == 31:
            cur = self._calc_current_from_bits(irun, True)
            if cur < run_current:
                irun2 = self._calc_current_bits(run_current, False)
                cur2 = self._calc_current_from_bits(irun2, False)
                if abs(run_current - cur2) < abs(run_current - cur):
                    vsense = False
                    irun = irun2
        ihold = self._calc_current_bits(min(hold_current, run_current), vsense)
        return (vsense, irun, ihold)

    
    def get_current(self):
        irun = self.fields.get_field('irun')
        ihold = self.fields.get_field('ihold')
        vsense = self.fields.get_field('vsense')
        run_current = self._calc_current_from_bits(irun, vsense)
        hold_current = self._calc_current_from_bits(ihold, vsense)
        return (run_current, hold_current, self.req_hold_current, MAX_CURRENT)

    
    def set_current(self, run_current, hold_current, print_time):
        self.req_hold_current = hold_current
        (vsense, irun, ihold) = self._calc_current(run_current, hold_current)
        if vsense != self.fields.get_field('vsense'):
            val = self.fields.set_field('vsense', vsense)
            self.mcu_tmc.set_register('CHOPCONF', val, print_time)
        self.fields.set_field('ihold', ihold)
        val = self.fields.set_field('irun', irun)
        self.mcu_tmc.set_register('IHOLD_IRUN', val, print_time)



class MCU_TMC_SPI_chain:
    
    def __init__(self, config, chain_len = (1,)):
        self.printer = config.get_printer()
        self.chain_len = chain_len
        self.mutex = self.printer.get_reactor().mutex()
        share = None
        if chain_len > 1:
            share = 'tmc_spi_cs'
        self.spi = bus.MCU_SPI_from_config(config, 3, default_speed=4000000, share_type=share)
        self.taken_chain_positions = []

    
    def _build_cmd(self, data, chain_pos):
        return [
            0] * (self.chain_len - chain_pos) * 5 + data + [
            0] * (chain_pos - 1) * 5

    
    def reg_read(self, reg, chain_pos):
        cmd = self._build_cmd([
            reg,
            0,
            0,
            0,
            0], chain_pos)
        self.spi.spi_send(cmd)
        if self.printer.get_start_args().get('debugoutput') is not None:
            return 0
        params = None.spi.spi_transfer(cmd)
        pr = bytearray(params['response'])
        pr = pr[(self.chain_len - chain_pos) * 5:((self.chain_len - chain_pos) + 1) * 5]
        return pr[1] << 24 | pr[2] << 16 | pr[3] << 8 | pr[4]

    
    def reg_write(self, reg, val, chain_pos, print_time = (None,)):
        minclock = 0
        if print_time is not None:
            minclock = self.spi.get_mcu().print_time_to_clock(print_time)
        data = [
            (reg | 128) & 255,
            val >> 24 & 255,
            val >> 16 & 255,
            val >> 8 & 255,
            val & 255]
        if self.printer.get_start_args().get('debugoutput') is not None:
            self.spi.spi_send(self._build_cmd(data, chain_pos), minclock)
            return val
        write_cmd = None._build_cmd(data, chain_pos)
        dummy_read = self._build_cmd([
            0,
            0,
            0,
            0,
            0], chain_pos)
        params = self.spi.spi_transfer_with_preface(write_cmd, dummy_read, minclock=minclock)
        pr = bytearray(params['response'])
        pr = pr[(self.chain_len - chain_pos) * 5:((self.chain_len - chain_pos) + 1) * 5]
        return pr[1] << 24 | pr[2] << 16 | pr[3] << 8 | pr[4]



def lookup_tmc_spi_chain(config):
    chain_len = config.getint('chain_length', None, minval=2)
    if chain_len is None:
        return (MCU_TMC_SPI_chain(config, 1), 1)
    ppins = None.get_printer().lookup_object('pins')
    cs_pin_params = ppins.lookup_pin(config.get('cs_pin'), share_type='tmc_spi_cs')
    tmc_spi = cs_pin_params.get('class')
    if tmc_spi is None:
        tmc_spi = cs_pin_params['class'] = MCU_TMC_SPI_chain(config, chain_len)
    if chain_len != tmc_spi.chain_len:
        raise config.error('TMC SPI chain must have same length')
    chain_pos = config.getint('chain_position', minval=1, maxval=chain_len)
    if chain_pos in tmc_spi.taken_chain_positions:
        raise config.error('TMC SPI chain can not have duplicate position')
    tmc_spi.taken_chain_positions.append(chain_pos)
    return (tmc_spi, chain_pos)


class MCU_TMC_SPI:
    
    def __init__(self, config, name_to_reg, fields):
        self.printer = config.get_printer()
        self.name = config.get_name().split()[-1]
        (self.tmc_spi, self.chain_pos) = lookup_tmc_spi_chain(config)
        self.mutex = self.tmc_spi.mutex
        self.name_to_reg = name_to_reg
        self.fields = fields

    
    def get_fields(self):
        return self.fields

    
    def get_register(self, reg_name):
        reg = self.name_to_reg[reg_name]
        with self.mutex:
            read = self.tmc_spi.reg_read(reg, self.chain_pos)
            None(None, None, None)
        with None:
            if not None:
                pass
        return read

    
    def set_register(self, reg_name, val, print_time = (None,)):
        reg = self.name_to_reg[reg_name]
        with self.mutex:
            for retry in range(5):
                v = self.tmc_spi.reg_write(reg, val, self.chain_pos, print_time)
                if v == val:
                    pass
                None(None, None, None)
                return None
            None(None, None, None)
        with None:
            if not None:
                pass
        raise self.printer.command_error("Unable to write tmc spi '%s' register %s" % (self.name, reg_name))



class TMC2130:
    
    def __init__(self, config):
        self.fields = tmc.FieldHelper(Fields, SignedFields, FieldFormatters)
        self.mcu_tmc = MCU_TMC_SPI(config, Registers, self.fields)
        tmc.TMCVirtualPinHelper(config, self.mcu_tmc)
        current_helper = TMCCurrentHelper(config, self.mcu_tmc)
        cmdhelper = tmc.TMCCommandHelper(config, self.mcu_tmc, current_helper)
        cmdhelper.setup_register_dump(ReadRegisters)
        self.get_phase_offset = cmdhelper.get_phase_offset
        self.get_status = cmdhelper.get_status
        tmc.TMCWaveTableHelper(config, self.mcu_tmc)
        tmc.TMCStealthchopHelper(config, self.mcu_tmc, TMC_FREQUENCY)
        set_config_field = self.fields.set_config_field
        set_config_field(config, 'toff', 4)
        set_config_field(config, 'hstrt', 0)
        set_config_field(config, 'hend', 7)
        set_config_field(config, 'tbl', 1)
        set_config_field(config, 'iholddelay', 8)
        set_config_field(config, 'tpowerdown', 0)
        set_config_field(config, 'pwm_ampl', 128)
        set_config_field(config, 'pwm_grad', 4)
        set_config_field(config, 'pwm_freq', 1)
        set_config_field(config, 'pwm_autoscale', True)
        set_config_field(config, 'sgt', 0)



def load_config_prefix(config):
    return TMC2130(config)

