# Source Generated with Decompyle++
# File: tmc2209.pyc (Python 3.9)

from . import tmc2208, tmc2130, tmc, tmc_uart
TMC_FREQUENCY = 1.2e+07
Registers = dict(tmc2208.Registers)
Registers.update({
    'TCOOLTHRS': 20,
    'COOLCONF': 66,
    'SGTHRS': 64,
    'SG_RESULT': 65 })
ReadRegisters = tmc2208.ReadRegisters + [
    'SG_RESULT']
Fields = dict(tmc2208.Fields)
Fields['COOLCONF'] = {
    'semin': 15,
    'seup': 96,
    'semax': 3840,
    'sedn': 24576,
    'seimin': 32768 }
Fields['IOIN'] = {
    'enn': 1,
    'ms1': 4,
    'ms2': 8,
    'diag': 16,
    'pdn_uart': 64,
    'step': 128,
    'spread_en': 256,
    'dir': 512,
    'version': 0xFF000000 }
Fields['SGTHRS'] = {
    'sgthrs': 255 }
Fields['SG_RESULT'] = {
    'sg_result': 1023 }
Fields['TCOOLTHRS'] = {
    'tcoolthrs': 1048575 }
FieldFormatters = dict(tmc2208.FieldFormatters)

class TMC2209:
    
    def __init__(self, config):
        self.fields = tmc.FieldHelper(Fields, tmc2208.SignedFields, FieldFormatters)
        self.mcu_tmc = tmc_uart.MCU_TMC_uart(config, Registers, self.fields, 3)
        self.fields.set_field('pdn_disable', True)
        self.fields.set_field('senddelay', 2)
        tmc.TMCVirtualPinHelper(config, self.mcu_tmc)
        current_helper = tmc2130.TMCCurrentHelper(config, self.mcu_tmc)
        cmdhelper = tmc.TMCCommandHelper(config, self.mcu_tmc, current_helper)
        cmdhelper.setup_register_dump(ReadRegisters)
        self.get_phase_offset = cmdhelper.get_phase_offset
        self.get_status = cmdhelper.get_status
        self.fields.set_field('pdn_disable', True)
        self.fields.set_field('mstep_reg_select', True)
        self.fields.set_field('multistep_filt', True)
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
        set_config_field(config, 'sgthrs', 0)



def load_config_prefix(config):
    return TMC2209(config)

