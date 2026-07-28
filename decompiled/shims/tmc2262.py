# =====================================================================
# PARTIAL DECOMPILATION -- this module did not fully round-trip.
# The 3.9 bytecode uses control flow the decompiler could not fully
# reconstruct (e.g. try/except/else with returns, or a generator with a
# dropped builtin rendered as `None(...)`). The code below is best-effort
# and will not import as-is. Ground-truth disassembly for repair:
#     decompiled/_disasm/tmc2262.txt
# =====================================================================

# Source Generated with Decompyle++
# File: tmc2262.pyc (Python 3.9)

import math
import logging
from . import bus, tmc, tmc2130
Registers = {
    'GCONF': 0,
    'GSTAT': 1,
    'DIAG_CONF': 2,
    'DIAG_DAC_CONF': 3,
    'IOIN': 4,
    'DRV_CONF': 10,
    'PLL': 11,
    'IHOLD_IRUN': 16,
    'TPOWERDOWN': 17,
    'TSTEP': 18,
    'TPWMTHRS': 19,
    'TCOOLTHRS': 20,
    'THIGH': 21,
    'TSGP_LOW_VEL_THRS': 22,
    'T_RCOIL_MEAS': 23,
    'TUDCSTEP': 24,
    'UDC_CONF': 25,
    'STEPS_LOST': 26,
    'SW_MODE': 52,
    'SG_SEQ_STOP_STAT': 53,
    'ENCMODE': 56,
    'X_ENC': 57,
    'ENC_CONST': 58,
    'ENC_STATUS': 59,
    'ENC_LATCH': 60,
    'ENC_DEVIATION': 61,
    'CURRENT_PI_REG': 64,
    'ANGLE_PI_REG': 65,
    'CUR_ANGLE_LIMIT': 66,
    'ANGLE_LOWER_LIMIT': 67,
    'CUR_ANGLE_MEAS': 68,
    'PI_RESULTS': 69,
    'COIL_INDUCT': 70,
    'R_COIL': 71,
    'R_COIL_USER': 72,
    'SGP_CONF': 73,
    'SGP_IND_2_3': 74,
    'SGP_IND_0_1': 75,
    'INDUCTANCE_VOLTAGE': 76,
    'SGP_BEMF': 77,
    'COOLSTEPPLUS_CONF': 78,
    'COOLSTEPPLUS_PI_REG': 79,
    'COOLSTEPPLUS_PI_DOWN': 80,
    'COOLSTEPPLUS_RESERVE_CONF': 81,
    'COOLSTEPPLUS_LOAD_RESERVE': 82,
    'TSTEP_VELOCITY': 83,
    'ADC_VSUPPLY_TEMP': 88,
    'ADC_I': 89,
    'OTW_OV_VTH': 90,
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
    'DRV_STATUS': 111,
    'PWMCONF': 112 }
ReadRegisters = [
    'GCONF',
    'GSTAT',
    'DIAG_CONF',
    'DIAG_DAC_CONF',
    'IOIN',
    'DRV_CONF',
    'PLL',
    'IHOLD_IRUN',
    'TPOWERDOWN',
    'TSTEP',
    'TPWMTHRS',
    'TCOOLTHRS',
    'THIGH',
    'TSGP_LOW_VEL_THRS',
    'T_RCOIL_MEAS',
    'TUDCSTEP',
    'UDC_CONF',
    'STEPS_LOST',
    'SW_MODE',
    'SG_SEQ_STOP_STAT',
    'ENCMODE',
    'X_ENC',
    'ENC_CONST',
    'ENC_STATUS',
    'ENC_LATCH',
    'ENC_DEVIATION',
    'CURRENT_PI_REG',
    'ANGLE_PI_REG',
    'CUR_ANGLE_LIMIT',
    'ANGLE_LOWER_LIMIT',
    'CUR_ANGLE_MEAS',
    'PI_RESULTS',
    'COIL_INDUCT',
    'R_COIL',
    'R_COIL_USER',
    'SGP_CONF',
    'SGP_IND_2_3',
    'SGP_IND_0_1',
    'INDUCTANCE_VOLTAGE',
    'SGP_BEMF',
    'COOLSTEPPLUS_CONF',
    'COOLSTEPPLUS_PI_REG',
    'COOLSTEPPLUS_PI_DOWN',
    'COOLSTEPPLUS_RESERVE_CONF',
    'COOLSTEPPLUS_LOAD_RESERVE',
    'TSTEP_VELOCITY',
    'ADC_VSUPPLY_TEMP',
    'ADC_I',
    'OTW_OV_VTH',
    'MSLUT0',
    'MSLUT1',
    'MSLUT2',
    'MSLUT3',
    'MSLUT4',
    'MSLUT5',
    'MSLUT6',
    'MSLUT7',
    'MSLUTSEL',
    'MSLUTSTART',
    'MSCNT',
    'MSCURACT',
    'CHOPCONF',
    'COOLCONF',
    'DRV_STATUS',
    'PWMCONF']
Fields = { }
Fields['GCONF'] = {
    'fast_standstill': 1,
    'en_pwm_mode': 2,
    'multistep_filt': 4,
    'shaft': 8,
    'small_hysteresis': 16,
    'stop_enable': 32,
    'direct_mode': 64,
    'length_steppulse': 3840,
    'OV_nN': 512,
    'step_dir': 0x80000000 }
Fields['GSTAT'] = {
    'reset': 1,
    'drv_err': 2,
    'uv_cp': 4,
    'register_reset': 8,
    'vm_uvlo': 16,
    'vccio_uv': 32 }
Fields['DIAG_CONF'] = {
    'do0_error': 1,
    'do0_otpw': 2,
    'do0_stall': 4,
    'do0_index': 8,
    'do0_step': 16,
    'do0_dir': 32,
    'do0_xcomp': 64,
    'do0_ov': 128,
    'do0_dcustep': 256,
    'do0_ev_stop_ref': 512,
    'do0_ev_stop_sg': 1024,
    'do0_ev_pos_reached': 2048,
    'do0_ev_n_deviation': 4096,
    'do1_error': 8192,
    'do1_otpw': 16384,
    'do1_stall': 32768,
    'do1_index': 65536,
    'do1_step': 131072,
    'do1_dir': 262144,
    'do1_xcomp': 524288,
    'do1_ov': 1048576,
    'do1_dcustep': 2097152,
    'do1_ev_stop_ref': 4194304,
    'do1_ev_stop_sg': 8388608,
    'do1_ev_pos_reached': 16777216,
    'do1_ev_n_deviation': 33554432,
    'do0_nOD_PP': 268435456,
    'do0_invPP': 536870912,
    'do1_nOD_PP': 1073741824,
    'do1_invPP': 0x80000000 }
Fields['DIAG_DAC_CONF'] = {
    'do0_scope_en': 1,
    'do0_scope_sel': 496,
    'do1_scope_en': 4096,
    'do1_scope_sel': 2031616 }
Fields['IOIN'] = {
    'refl': 1,
    'refr': 2,
    'encb': 4,
    'enca': 8,
    'drv_enn': 16,
    'encn': 32,
    'ext_res_det': 8192,
    'ext_clk': 16384,
    'silicon_rv': 196608 }
Fields['DRV_CONF'] = {
    'current_range': 3,
    'current_range_scale': 12,
    'slope_control': 48 }
Fields['PLL'] = {
    'commit': 1,
    'ext_not_int': 2,
    'clk_sys_sel': 4,
    'adc_clk_ena': 24,
    'clock_divider': 992,
    'clk_fsm_ena': 1024,
    'clk_1mo_tmo': 4096,
    'clk_loss': 8192,
    'clk_is_stuck': 16384,
    'pll_lock_loss': 32768 }
Fields['IHOLD_IRUN'] = {
    'ihold': 255,
    'irun': 65280,
    'iholddelay': 4128768,
    'irundelay': 251658240 }
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
Fields['TSGP_LOW_VEL_THRS'] = {
    'TSGP_LOW_VEL_THRS': 1048575 }
Fields['T_RCOIL_MEAS'] = {
    'T_RCOIL_MEAS': 1048575 }
Fields['TUDCSTEP'] = {
    'TUDCSTEP': 1048575 }
Fields['UDC_CONF'] = {
    'DECEL_THRS': 15,
    'ACCEL_THRS': 240,
    'udc_enable': 256 }
Fields['STEPS_LOST'] = {
    'STEPS_LOST': 1048575 }
Fields['SW_MODE'] = {
    'stop_l_enable': 1,
    'stop_r_enable': 2,
    'pol_stop_l': 4,
    'pol_stop_r': 8,
    'swap_lr': 16,
    'latch_l_active': 32,
    'latch_l_inactive': 64,
    'latch_r_active': 128,
    'latch_r_inactive': 256,
    'en_latch_encoder': 512,
    'sg_stop': 1024,
    'en_softstop': 2048,
    'en_virtual_stio_l': 4096,
    'en_virtual_stio_r': 8192,
    'virtual_stop_enc': 16384,
    'hard_stop_clr_cur_int': 32768 }
Fields['SG_SEQ_STOP_STAT'] = {
    'status_stop_l': 1,
    'status_stop_r': 2,
    'status_latch_l': 4,
    'status_latch_r': 8,
    'event_latch_l': 16,
    'event_latch_r': 32,
    'event_stop_sg': 64,
    'event_pos_reached': 128,
    'velocity_reached': 256,
    'position_reached': 512,
    'vzero': 1024,
    't_zerowait_active': 2048,
    'second_move': 4096,
    'status_sg': 8192,
    'status_virtual_stop_r': 16384,
    'status_virtual_stop_l': 32768 }
Fields['ENCMODE'] = {
    'pol_A': 1,
    'pol_B': 2,
    'pol_N': 4,
    'ignore_AB': 8,
    'clr_cont': 16,
    'clr_once': 32,
    'pos_neg_edge': 192,
    'clr_enc_x': 256,
    'latch_x_act': 512,
    'enc_sel_decimal': 1024,
    'nBEMF_ABN_SEL': 2048,
    'bemf_hyst': 28672,
    'BEMF_BLANK_TIME': 16711680,
    'BEMF_FILTER_SEL': 805306368 }
Fields['X_ENC'] = {
    'X_ENC': 0xFFFFFFFF }
Fields['ENC_CONST'] = {
    'ENC_CONST': 0xFFFFFFFF }
Fields['ENC_STATUS'] = {
    'n_event': 1,
    'deviation_wam': 2 }
Fields['ENC_LATCH'] = {
    'ENC_LATCH': 0xFFFFFFFF }
Fields['ENC_DEVIATION'] = {
    'ENC_DEVIATION': 1048575 }
Fields['CURRENT_PI_REG'] = {
    'cur_p': 4095,
    'cur_i': 268369920 }
Fields['ANGLE_PI_REG'] = {
    'angle_p': 4095,
    'angle_i': 268369920 }
Fields['CUR_ANGLE_LIMIT'] = {
    'ANGLE_PI_LIMIT': 1023,
    'angle_pi_int_pos_clip': 4096,
    'angle_pi_int_neg_clip': 8192,
    'angle_pi_pos_clip': 16384,
    'angle_pi_neg_clip': 32768,
    'CUR_PI_LIMIT': 67043328,
    'cur_pi_int_pos_clip': 268435456,
    'cur_pi_int_neg_clip': 536870912,
    'cur_pi_pos_clip': 1073741824,
    'cur_pi_neg_clip': 0x80000000 }
Fields['ANGLE_LOWER_LIMIT'] = {
    'ANGLE_LOWER_I_LIMIT': 1023,
    'ANGLE_ERROR': 67043328 }
Fields['CUR_ANGLE_MEAS'] = {
    'AMPL_MEAS': 4095,
    'ANGLE_MEAS': 268369920 }
Fields['PI_RESULTS'] = {
    'PWM_CALC': 8191,
    'ANGLE_CORR_CAL': 50266112 }
Fields['COIL_INDUCT'] = {
    'coil_induct': 32767,
    'rcoil_manual': 65536,
    'rcoil_thermal_coupling': 131072 }
Fields['R_COIL'] = {
    'R_COIL_AUTO_B': 4095,
    'R_COIL_AUTO_A': 268369920 }
Fields['R_COIL_USER'] = {
    'R_COIL_USER_B': 4095,
    'R_COIL_USER_A': 268369920 }
Fields['SGP_CONF'] = {
    'SGP_THRS': 31,
    'sgp_filt_en': 4096,
    'sgp_low_vel_freeze': 8192,
    'sgp_clear_cur_pi': 16384,
    'SGP_LOW_VEL_SLOPE': 16711680,
    'SGP_LOW_VEL_CNTS': 805306368 }
Fields['SGP_IND_2_3'] = {
    'SGP_IND_2': 1023,
    'SGP_IND_3': 67043328 }
Fields['SGP_IND_0_1'] = {
    'SGP_IND_0': 1023,
    'SGP_IND_1': 67043328 }
Fields['INDUCTANCE_VOLTAGE'] = {
    'UL_B': 4095,
    'UL_B': 268369920 }
Fields['SGP_BEMF'] = {
    'SGP_RAW': 1023,
    'SGP_ABS': 268369920 }
Fields['COOLSTEPPLUS_CONF'] = {
    'COOL_CUR_DIV': 15,
    'load_filt_en': 16 }
Fields['COOLSTEPPLUS_PI_REG'] = {
    'COOLSTEP_P': 4095,
    'COOLSTEP_I': 4128768 }
Fields['COOLSTEPPLUS_PI_DOWN'] = {
    'COOL_PI_DOWN_LIMIT': 4095,
    'COOL_PI_OFF_SPEED': 268369920 }
Fields['COOLSTEPPLUS_LOAD_RESERVE'] = {
    'SGP_RESULT': 1023,
    'COOLSTEP_LOAD_RESERVE': 268369920 }
Fields['TSTEP_VELOCITY'] = {
    'TSTEP_VELOCITY': 8388607 }
Fields['ADC_VSUPPLY_TEMP'] = {
    'ADC_VSUPPLY': 511,
    'ADC_TEMP': 33488896 }
Fields['ADC_I'] = {
    'ADC_I_A': 4095,
    'ADC_I_B': 268369920 }
Fields['OTW_OV_VTH'] = {
    'OVERVOLTAGE_VTH': 511,
    'OVERTEMPPREWARNING': 33488896 }
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
    'w0': 3,
    'w1': 12,
    'w2': 48,
    'w3': 192,
    'x1': 65280,
    'x2': 16711680,
    'x3': 0xFF000000 }
Fields['MSLUTSTART'] = {
    'start_sin': 255,
    'start_sin90': 16711680,
    'offset_sin90': 0xFF000000 }
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
    'chm': 16384,
    'tbl': 98304,
    'tpfd': 15728640,
    'mres': 251658240,
    'intpol': 268435456,
    'dedge': 536870912 }
Fields['COOLCONF'] = {
    'semin': 15,
    'seup': 96,
    'semax': 3840,
    'sedn': 24576,
    'seimin': 32768,
    'sgt': 8323072,
    'thigh_sg_off': 8388608,
    'sfilt': 16777216 }
Fields['DRV_STATUS'] = {
    'sg_result': 1023,
    'seq_stopped': 1024,
    'ov': 2048,
    's2vsa': 4096,
    's2vsb': 8192,
    'stealth': 16384,
    'cs_actual': 16711680,
    'stallguard': 16777216,
    'ot': 33554432,
    'otpw': 67108864,
    's2ga': 134217728,
    's2gb': 268435456,
    'ola': 536870912,
    'olb': 1073741824,
    'stst': 0x80000000 }
Fields['PWMCONF'] = {
    'pwm_freq': 15,
    'freewheel': 48,
    'ol_thrsh': 192,
    'sd_on_meas_lo': 4096,
    'sd_on_meas_hi': 65536 }
SignedFields = [
    'cur_a',
    'cur_b',
    'sgt',
    'pwm_scale_auto']
FieldFormatters = {
    'shaft': (lambda v: '1(Reverse)' if v else ''),
    'reset': (lambda v: '1(Reset)' if v else ''),
    'drv_err': (lambda v: '1(ErrorShutdown!)' if v else ''),
    'uv_cp': (lambda v: '1(Undervoltage!)' if v else ''),
    'mres': (lambda v: '%d(%dusteps)' % (v, 256 >> v)),
    'otpw': (lambda v: '1(OvertempWarning!)' if v else ''),
    'ot': (lambda v: '1(OvertempError!)' if v else ''),
    's2ga': (lambda v: '1(ShortToGND_A!)' if v else ''),
    's2gb': (lambda v: '1(ShortToGND_B!)' if v else ''),
    'ola': (lambda v: '1(OpenLoad_A!)' if v else ''),
    'olb': (lambda v: '1(OpenLoad_B!)' if v else ''),
    'cs_actual': (lambda v: '%d' % v if v else '0(Reset?)'),
    's2vsa': (lambda v: '1(ShortToSupply_A!)' if v else ''),
    's2vsb': (lambda v: '1(ShortToSupply_B!)' if v else '') }
MAX_CURRENT = 4.24

class TMC2262CurrentHelper:
    
    def __init__(self, config, mcu_tmc):
        self.printer = config.get_printer()
        self.name = config.get_name().split()[-1]
        self.mcu_tmc = mcu_tmc
        self.fields = mcu_tmc.get_fields()
        self.current_range = config.getint('current_range', 0, minval=0, maxval=3)
        self.current_range_scale = config.getint('current_range_scale', 0, minval=0, maxval=3)
        if self.current_range >= 1:
            self.current_range_scale = 3
        Rref = config.getint('rref', 12000, minval=12000, maxval=60000)
        Kifs_values = {
            0: 18000,
            1: 36000,
            2: 54000,
            3: 72000 }
        CRS_values = {
            3: 1.0,
            2: 0.75,
            1: 0.5,
            0: 0.25 }
        self.IFS_current_RMS = float(CRS_values[self.current_range_scale] * Kifs_values[self.current_range]) / Rref / math.sqrt(2.0)
        run_current = config.getfloat('run_current', above=0.0, maxval=self.IFS_current_RMS)
        hold_current = config.getfloat('hold_current', self.IFS_current_RMS, above=0.0, maxval=self.IFS_current_RMS)
        self.req_hold_current = hold_current
        (irun, ihold) = self._calc_current(run_current, hold_current)
        self.fields.set_field('ihold', ihold)
        self.fields.set_field('irun', irun)
        self.fields.set_field('current_range', self.current_range)
        self.fields.set_field('current_range_scale', self.current_range_scale)

    
    def _calc_current_bits(self, current):
        cs = int(((current * 250 / MAX_CURRENT) * 4 / (self.current_range + 1)) * 4 / (self.current_range_scale + 1) + 0.5)
        return max(0, min(255, cs))

    
    def _calc_current(self, run_current, hold_current):
        irun = self._calc_current_bits(run_current)
        ihold = self._calc_current_bits(min(hold_current, run_current))
        return (irun, ihold)

    
    def _calc_current_from_field(self, field_name):
        current_range = self.fields.get_field('current_range')
        current_range_scale = self.fields.get_field('current_range_scale')
        bits = self.fields.get_field(field_name)
        return ((MAX_CURRENT * (current_range + 1) / 4) * (current_range_scale + 1) / 4) * bits / 250

    
    def get_current(self):
        run_current = self._calc_current_from_field('irun')
        hold_current = self._calc_current_from_field('ihold')
        return (run_current, hold_current, self.req_hold_current, self.IFS_current_RMS)

    
    def set_current(self, run_current, hold_current, print_time):
        (irun, ihold) = self._calc_current(run_current, hold_current)
        logging.info('hys: irun = %s, ihold = %s' % (irun, ihold))
        self.fields.set_field('ihold', ihold)
        val = self.fields.set_field('irun', irun)
        self.mcu_tmc.set_register('IHOLD_IRUN', val, print_time)



class TMC2262PLLHelper:
    
    def __init__(self, config):
        ext_clk_set = config.getboolean('driver_EXT_NOT_INT', False)
        logging.info('driver_EXT_NOT_INT: %s' % ext_clk_set)
        self.tmc_frequency = config.getfloat('tmc_frequency', 1.6e+07, minval=1e+06, maxval=3.2e+07)
        if not ext_clk_set:
            self.tmc_frequency = 1.6e+07

    
    def _calc_clock_divider(self):
        clock_divider = int((self.tmc_frequency / 1000000 - 1) + 0.5)
        logging.info('hys: clock_divider = 0x%x' % clock_divider)
        return clock_divider



class TMC2262:
    
    def __init__(self, config):
        self.fields = tmc.FieldHelper(Fields, SignedFields, FieldFormatters)
        set_config_field = self.fields.set_config_field
        set_config_field(config, 'small_hysteresis', True)
        set_config_field(config, 'en_pwm_mode', True)
        set_config_field(config, 'multistep_filt', True)
        set_config_field(config, 'step_dir', True)
        set_config_field(config, 'ext_not_int', False)
        PLL_helper = TMC2262PLLHelper(config)
        self.tmc_frequency = PLL_helper.tmc_frequency
        set_config_field(config, 'clock_divider', PLL_helper._calc_clock_divider())
        self.mcu_tmc = tmc2130.MCU_TMC_SPI(config, Registers, self.fields)
        tmc.TMCVirtualPinHelper(config, self.mcu_tmc)
        current_helper = TMC2262CurrentHelper(config, self.mcu_tmc)
        cmdhelper = tmc.TMCCommandHelper(config, self.mcu_tmc, current_helper)
        tmc.TMCMicrostepHelper(config, self.mcu_tmc)
        cmdhelper.setup_register_dump(ReadRegisters)
        self.get_phase_offset = cmdhelper.get_phase_offset
        self.get_status = cmdhelper.get_status
        tmc.TMCWaveTableHelper(config, self.mcu_tmc)
        tmc.TMCStealthchopHelper(config, self.mcu_tmc, self.tmc_frequency)
        tmc.TMCVcoolthrsHelper(config, self.mcu_tmc, self.tmc_frequency)
        set_config_field(config, 'toff', 3)
        set_config_field(config, 'hstrt', 5)
        set_config_field(config, 'hend', 2)
        set_config_field(config, 'fd3', 0)
        set_config_field(config, 'disfdcc', 0)
        set_config_field(config, 'chm', 0)
        set_config_field(config, 'tbl', 2)
        set_config_field(config, 'tpfd', 4)
        set_config_field(config, 'intpol', 1)
        set_config_field(config, 'dedge', 0)
        set_config_field(config, 'semin', 0)
        set_config_field(config, 'seup', 0)
        set_config_field(config, 'semax', 0)
        set_config_field(config, 'sedn', 0)
        set_config_field(config, 'seimin', 0)
        set_config_field(config, 'sgt', 0)
        set_config_field(config, 'sfilt', 0)
        set_config_field(config, 'iholddelay', 7)
        set_config_field(config, 'irundelay', 4)
        set_config_field(config, 'pwm_freq', 0)
        set_config_field(config, 'freewheel', 0)
        set_config_field(config, 'tpowerdown', 10)
        set_config_field(config, 'drv_enn', False)
        set_config_field(config, 'slope_control', 3)
        set_config_field(config, 'cur_p', 550)
        set_config_field(config, 'cur_i', 137)
        set_config_field(config, 'angle_p', 200)
        set_config_field(config, 'angle_i', 50)
        coil_induct = config.getint('coil_induct', 0.0)
        if coil_induct:
            set_config_field(config, 'coil_induct', coil_induct)



def load_config_prefix(config):
    return TMC2262(config)

