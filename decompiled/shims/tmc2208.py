# =====================================================================
# PARTIAL DECOMPILATION -- this module did not fully round-trip.
# The 3.9 bytecode uses control flow the decompiler could not fully
# reconstruct (e.g. try/except/else with returns, or a generator with a
# dropped builtin rendered as `None(...)`). The code below is best-effort
# and will not import as-is. Ground-truth disassembly for repair:
#     decompiled/_disasm/tmc2208.txt
# =====================================================================

# Source Generated with Decompyle++
# File: tmc2208.pyc (Python 3.9)

import logging
from . import tmc, tmc_uart, tmc2130
TMC_FREQUENCY = 1.2e+07
Registers = {
    'GCONF': 0,
    'GSTAT': 1,
    'IFCNT': 2,
    'SLAVECONF': 3,
    'OTP_PROG': 4,
    'OTP_READ': 5,
    'IOIN': 6,
    'FACTORY_CONF': 7,
    'IHOLD_IRUN': 16,
    'TPOWERDOWN': 17,
    'TSTEP': 18,
    'TPWMTHRS': 19,
    'VACTUAL': 34,
    'MSCNT': 106,
    'MSCURACT': 107,
    'CHOPCONF': 108,
    'DRV_STATUS': 111,
    'PWMCONF': 112,
    'PWM_SCALE': 113,
    'PWM_AUTO': 114 }
ReadRegisters = [
    'GCONF',
    'GSTAT',
    'IFCNT',
    'OTP_READ',
    'IOIN',
    'FACTORY_CONF',
    'TSTEP',
    'MSCNT',
    'MSCURACT',
    'CHOPCONF',
    'DRV_STATUS',
    'PWMCONF',
    'PWM_SCALE',
    'PWM_AUTO']
Fields = { }
Fields['GCONF'] = {
    'i_scale_analog': 1,
    'internal_rsense': 2,
    'en_spreadcycle': 4,
    'shaft': 8,
    'index_otpw': 16,
    'index_step': 32,
    'pdn_disable': 64,
    'mstep_reg_select': 128,
    'multistep_filt': 256,
    'test_mode': 512 }
Fields['GSTAT'] = {
    'reset': 1,
    'drv_err': 2,
    'uv_cp': 4 }
Fields['IFCNT'] = {
    'ifcnt': 255 }
Fields['SLAVECONF'] = {
    'senddelay': 3840 }
Fields['OTP_PROG'] = {
    'otpbit': 7,
    'otpbyte': 48,
    'otpmagic': 65280 }
Fields['OTP_READ'] = {
    'otp_fclktrim': 31,
    'otp_ottrim': 32,
    'otp_internalrsense': 64,
    'otp_tbl': 128,
    'otp_pwm_grad': 3840,
    'otp_pwm_autograd': 4096,
    'otp_tpwmthrs': 57344,
    'otp_pwm_ofs': 65536,
    'otp_pwm_reg': 131072,
    'otp_pwm_freq': 262144,
    'otp_iholddelay': 1572864,
    'otp_ihold': 6291456,
    'otp_en_spreadcycle': 8388608 }
Fields['IOIN@TMC222x'] = {
    'pdn_uart': 2,
    'spread': 4,
    'dir': 8,
    'enn': 16,
    'step': 32,
    'ms1': 64,
    'ms2': 128,
    'sel_a': 256,
    'version': 0xFF000000 }
Fields['IOIN@TMC220x'] = {
    'enn': 1,
    'ms1': 4,
    'ms2': 8,
    'diag': 16,
    'pdn_uart': 64,
    'step': 128,
    'sel_a': 256,
    'dir': 512,
    'version': 0xFF000000 }
Fields['FACTORY_CONF'] = {
    'fclktrim': 31,
    'ottrim': 768 }
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
Fields['VACTUAL'] = {
    'vactual': 16777215 }
Fields['MSCNT'] = {
    'mscnt': 1023 }
Fields['MSCURACT'] = {
    'cur_a': 511,
    'cur_b': 33488896 }
Fields['CHOPCONF'] = {
    'toff': 15,
    'hstrt': 112,
    'hend': 1920,
    'tbl': 98304,
    'vsense': 131072,
    'mres': 251658240,
    'intpol': 268435456,
    'dedge': 536870912,
    'diss2g': 1073741824,
    'diss2vs': 0x80000000 }
Fields['DRV_STATUS'] = {
    'otpw': 1,
    'ot': 2,
    's2ga': 4,
    's2gb': 8,
    's2vsa': 16,
    's2vsb': 32,
    'ola': 64,
    'olb': 128,
    't120': 256,
    't143': 512,
    't150': 1024,
    't157': 2048,
    'cs_actual': 2031616,
    'stealth': 1073741824,
    'stst': 0x80000000 }
Fields['PWMCONF'] = {
    'pwm_ofs': 255,
    'pwm_grad': 65280,
    'pwm_freq': 196608,
    'pwm_autoscale': 262144,
    'pwm_autograd': 524288,
    'freewheel': 3145728,
    'pwm_reg': 251658240,
    'pwm_lim': 0xF0000000 }
Fields['PWM_SCALE'] = {
    'pwm_scale_sum': 255,
    'pwm_scale_auto': 33488896 }
Fields['PWM_AUTO'] = {
    'pwm_ofs_auto': 255,
    'pwm_grad_auto': 16711680 }
SignedFields = [
    'cur_a',
    'cur_b',
    'pwm_scale_auto']
FieldFormatters = dict(tmc2130.FieldFormatters)
FieldFormatters.update({
    'sel_a': (lambda v: '%d(%s)' % (v, [
'TMC222x',
'TMC220x'][v])),
    's2vsa': (lambda v: if v:
'1(LowSideShort_A!)'),
    's2vsb': (lambda v: if v:
'1(LowSideShort_B!)') })

class TMC2208:
    
    def __init__(self, config):
        self.config = config
        self.printer = config.get_printer()
        self.gcode = self.printer.lookup_object('gcode')
        self.fields = tmc.FieldHelper(Fields, SignedFields, FieldFormatters)
        self.mcu_tmc = tmc_uart.MCU_TMC_uart(config, Registers, self.fields)
        self.fields.set_field('pdn_disable', True)
        current_helper = tmc2130.TMCCurrentHelper(config, self.mcu_tmc)
        cmdhelper = tmc.TMCCommandHelper(config, self.mcu_tmc, current_helper)
        cmdhelper.setup_register_dump(ReadRegisters, self.read_translate)
        self.get_phase_offset = cmdhelper.get_phase_offset
        self.get_status = cmdhelper.get_status
        self.fields.set_field('mstep_reg_select', True)
        self.fields.set_field('multistep_filt', True)
        self.mcu_freq = TMC_FREQUENCY
        tmc.TMCStealthchopHelper(config, self.mcu_tmc, TMC_FREQUENCY)
        set_config_field = self.fields.set_config_field
        set_config_field(config, 'toff', 3)
        set_config_field(config, 'hstrt', 5)
        set_config_field(config, 'hend', 0)
        set_config_field(config, 'tbl', 2)
        set_config_field(config, 'iholddelay', 8)
        set_config_field(config, 'tpowerdown', 20)
        set_config_field(config, 'pwm_ofs', 36)
        set_config_field(config, 'pwm_grad', 14)
        set_config_field(config, 'pwm_freq', 1)
        set_config_field(config, 'pwm_autoscale', True)
        set_config_field(config, 'pwm_autograd', True)
        set_config_field(config, 'pwm_reg', 8)
        set_config_field(config, 'pwm_lim', 12)
        self.gcode.register_command('TMC2208_STEALTHCHOP', self.cmd_TMC2208_STEALTHCHOP)

    
    def read_translate(self, reg_name, val):
        if reg_name == 'IOIN':
            drv_type = self.fields.get_field('sel_a', val)
            reg_name = 'IOIN@TMC220x' if drv_type else 'IOIN@TMC222x'
        return (reg_name, val)

    
    def cmd_TMC2208_STEALTHCHOP(self, gcmd):
        velocity = gcmd.get_float('VAL', 0)
        stepper = gcmd.get('STEPPER', 0)
        threshold = TMCStealthchopCal(self.config, self.mcu_tmc, self.mcu_freq, velocity)
        en_spreadcycle = 0 if threshold > 0 else 1
        self.gcode.run_script_from_command('SET_TMC_FIELD STEPPER=%s FIELD=en_spreadcycle VALUE=%d' % (stepper, en_spreadcycle))
        self.gcode.run_script_from_command('SET_TMC_FIELD STEPPER=%s FIELD=tpwmthrs VALUE=%d' % (stepper, threshold))
        self.gcode.run_script_from_command('GET_TMC_FIELD STEPPER=%s FIELD=tpwmthrs' % stepper)



def load_config_prefix(config):
    return TMC2208(config)


def TMCStealthchopCal(config, mcu_tmc, tmc_freq, velocity):
    fields = mcu_tmc.get_fields()
    threshold = 0
    if velocity:
        stepper_name = ' '.join(config.get_name().split()[1:])
        sconfig = config.getsection(stepper_name)
        import stepper
        (rotation_dist, steps_per_rotation) = stepper.parse_step_distance(sconfig)
        step_dist = rotation_dist / steps_per_rotation
        step_dist_256 = step_dist / (1 << fields.get_field('mres'))
        threshold = int(tmc_freq * step_dist_256 / velocity + 0.5)
    return max(0, min(1048575, threshold))

