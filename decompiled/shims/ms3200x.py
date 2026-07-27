# =====================================================================
# PARTIAL DECOMPILATION -- this module did not fully round-trip.
# The 3.9 bytecode uses control flow the decompiler could not fully
# reconstruct (e.g. try/except/else with returns, or a generator with a
# dropped builtin rendered as `None(...)`). The code below is best-effort
# and will not import as-is. Ground-truth disassembly for repair:
#     decompiled/_disasm/ms3200x.txt
# =====================================================================

# Source Generated with Decompyle++
# File: ms3200x.pyc (Python 3.9)

from __future__ import annotations
import time
import logging
from . import bus
FCLK_FREQUENCY = 20000000
CHA = 16
CHB = 32
Registers = {
    'CONF0': 0,
    'CONF1': 1,
    'CONF2': 2,
    'DCMOTOR': 3,
    'CLR': 13,
    'WATCH': 14,
    'CHIPFLAG': 15,
    'CH_CTRL': 16,
    'CH_DIR_MS': 17,
    'ACH_FREQ_L': 18,
    'ACH_FREQ_H': 19,
    'ACH_PULSE_L': 20,
    'ACH_PULSE_H': 21,
    'ACH_AMP': 22,
    'READ_STATUS': 29,
    'ACH_PULSE_RECORD_H': 30,
    'ACH_PULSE_RECORD_L': 31 }
ReadRegisters = [
    'CONF0',
    'CONF1',
    'CONF2',
    'DCMOTOR',
    'CLR',
    'WATCH',
    'CHIPFLAG',
    'CH_CTRL',
    'CH_DIR_MS',
    'ACH_FREQ_L',
    'ACH_FREQ_H',
    'ACH_PULSE_L',
    'ACH_PULSE_H',
    'ACH_AMP',
    'READ_STATUS',
    'ACH_PULSE_RECORD_H',
    'ACH_PULSE_RECORD_L']
Fields = { }
Fields['CONF0'] = {
    'nRST_ENABLE': 0,
    'nRST_DISABLE': 1,
    'standby_DISABLE': 0,
    'standby_ENABLE': 2,
    'stm_fsw_MUL1': 0,
    'stm_fsw_MUL2': 4,
    'stm_fsw_MUL3': 8,
    'stm_fsw_MUL4': 12,
    'stm_fsw_MUL5': 16,
    'stm_fsw_MUL6P5': 20,
    'stm_fsw_MUL8': 24,
    'stm_fsw_MUL10': 28,
    'useExtClk_DISABLE': 0,
    'useExtClk_ENABLE': 64,
    'oscOFF_DISABLE': 0,
    'oscOFF_ENABLE': 128 }
Fields['CONF1'] = {
    'ACH_confLoad': 128,
    'BCH_confLoad': 64 }
Fields['CONF2'] = {
    'ACH_forceStop': 128,
    'BCH_forceStop': 64 }
Fields['DCMOTOR'] = {
    'DCMotor_Hiz': 0,
    'DCMotor_A2B': 1,
    'DCMotor_B2A': 2,
    'DCMotor_Brake': 3 }
Fields['CLR'] = {
    'uvloClr': 128,
    'otsClr': 64 }
Fields['WATCH'] = {
    'watchEN_ENABLE': 128,
    'watchEN_DISABLE': 0,
    'watch_ACH_FG': 0,
    'watch_ACH_Runing': 2,
    'watch_ACH_cacheBusy': 3,
    'watch_BCH_FG': 4,
    'watch_BCH_Runing': 6,
    'watch_BCH_cacheBusy': 7,
    'watch_OTP': 13,
    'watch_UVP': 14,
    'watch_SycClkDiv400': 15 }
Fields['CHIPFLAG'] = { }
Fields['CH_CTRL'] = {
    'CHx_PowDri_ENABLE': 64,
    'CHx_PowDri_DISABLE': 0,
    'CHx_recordRev_ENABLE': 32,
    'CHx_recordRev_DISABLE': 0 }
Fields['CH_DIR_MS'] = {
    'CHx_Dir_CW': 0,
    'CHx_Dir_CCW': 1,
    'CHx_ForceStopPosDiv4': 0,
    'CHx_ForceStopPosDiv2': 4,
    'CHx_ForceStopPos2Pha': 8,
    'CHx_ForceStopPos1Pha': 12,
    'CHx_msMode1Div256': 0,
    'CHx_msMode1Div128': 16,
    'CHx_msMode1Div64': 32,
    'CHx_msMode1Div32': 48,
    'CHx_msMode1Div16': 64,
    'CHx_msMode1Div8': 80,
    'CHx_msMode1Div4': 96,
    'CHx_msMode1Div2': 112,
    'CHx_msModeFull': 128 }
Fields['ACH_FREQ_L'] = {
    'freq_lo': 255 }
Fields['ACH_FREQ_H'] = {
    'freq_hi': 255 }
Fields['ACH_PULSE_L'] = {
    'pulse_lo': 255 }
Fields['ACH_PULSE_H'] = {
    'pulse_hi': 255 }
Fields['ACH_AMP'] = {
    'amp': 255 }
Fields['READ_STATUS'] = {
    'BIT_ChipOTS': 1,
    'BIT_ChipUVLO': 2,
    'BIT_CHx_cacheBusy': 4,
    'BIT_CHx_Running': 8 }
Fields['ACH_PULSE_RECORD_H'] = {
    'pulse_record_hi': 255 }
Fields['ACH_PULSE_RECORD_L'] = {
    'pulse_record_lo': 255 }

def flatten_fields():
    '''
    Return a flattened mapping: (reg_name, field_name) -> mask
    Useful for code that wants to lookup by tuple.
    '''
    flat = { }
    for reg, fdict in Fields.items():
        for fname, mask in fdict.items():
            flat[(reg, fname)] = mask
    return flat


class MS32008Error(Exception):
    pass


def load_config_prefix(config, name, default = (None,)):
    
    try:
        pass
    return None
    except Exception:
        return None



class MS32008:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        i2c_addr = 16
        self.i2c = self._get_i2c(config, i2c_addr)
        self.gcode = self.printer.lookup_object('gcode')
        self.gcode.register_command('MS32008_INIT', self.gcmd_init, desc='Init MS32008')
        self.gcode.register_command('MS32008_READ', self.gcmd_read, desc='Read MS32008 registers')
        self.gcode.register_command('MS32008_WRITE', self.gcmd_write, desc='Write MS32008 registers')
        self.gcode.register_command('MS32008_MOVE', self.gcmd_move, desc='High-level move (set PPS,steps,dir,ch_conf_load)')
        self.gcode.register_command('MS32008_SET', self.gcmd_set, desc='Set CH param like CURRENT/PPS/DIR')
        self.gcode.register_command('MS32008_DC', self.gcmd_dc, desc='Control DC motor channel')

    
    def _get_i2c(self, config, i2c_addr):
        '''
        hold on 
        NOTE: i2c fd
        '''
        
        try:
            i2c = bus.MCU_I2C_from_config(config, default_addr=i2c_addr)
            if hasattr(i2c, 'i2c_write') and hasattr(i2c, 'i2c_read'):
                pass
        return None
        except Exception:
            pass

        raise MS32008Error(f'''Could not find I2C bus object for \'{i2c_addr}\' - adjust i2c_bus in config''')

    
    def _i2c_write_reg(self, reg, data):
        """Write 'data' (an iterable of bytes) to register 'reg'."""
        if not isinstance(data, (bytes, bytearray, list, tuple)):
            data = [
                data]
        payload = [
            reg] + [ int(x) & 255 for x in (data) ]
        if hasattr(self.i2c, 'i2c_write'):
            self.i2c.i2c_write(payload)
            self.gcode.respond_info(f'''[DEBUG] _i2c_write_reg: pyload={payload}''')
            return None
        raise None('I2C write function not found on bus object')

    
    def _i2c_read_reg(self, reg, count):
        if hasattr(self.i2c, 'i2c_read'):
            raw = self.i2c.i2c_read([
                reg], count)
        else:
            raise MS32008Error('I2C read function not found on bus object')
        if isinstance(raw, dict):
            if raw.get('#name') != 'i2c_read_response':
                raise MS32008Error(f'''Invalid I2C protocol: {raw}''')
            if 'response' not in raw:
                raise MS32008Error(f'''I2C response missing data field: {raw}''')
            payload = raw['response']
        else:
            payload = raw
        if isinstance(payload, int):
            buf = bytes([
                payload])
        elif isinstance(payload, (bytes, bytearray)):
            buf = bytes(payload)
        elif isinstance(payload, str):
            buf = payload.encode('latin1')
        elif isinstance(payload, list):
            flat = []
            for x in payload:
                if isinstance(x, int):
                    flat.append(x & 255)
                    continue
                if isinstance(x, str):
                    flat.extend(x.encode('latin1'))
                    continue
                if isinstance(x, (bytes, bytearray)):
                    flat.extend(x)
                    continue
                raise MS32008Error(f'''Invalid I2C element type: {type(x)} in payload''')
            buf = bytes(flat)
        else:
            raise MS32008Error(f'''Unsupported I2C data type: {type(payload)}''')
        if len(buf) < count:
            raise MS32008Error(f'''I2C read returned too few bytes: expected {count}, got {len(buf)}''')
        buf = buf[-count:]
        self.gcode.respond_info(f'''[DEBUG] _i2c_read_reg: reg={reg} pyload={list(buf)}''')
        return list(buf)

    
    def soft_reset(self):
        r = self._i2c_read_reg(0, 1)
        val = r[0] & -2
        self._i2c_write_reg(0, [
            val])
        time.sleep(0.005)
        val |= 1
        self._i2c_write_reg(0, [
            val])

    
    def hard_sleep(self = None, enable = None):
        return self.soft_standby(enable)

    
    def soft_standby(self = None, enable = None):
        r = self._i2c_read_reg(0, 1)
        val = r[0]
        if enable:
            val |= 2
        else:
            val &= -3
        self._i2c_write_reg(0, [
            val])

    
    def set_fsw(self, fsw_val):
        r = self._i2c_read_reg(0, 1)
        val = r[0] & -29
        val |= fsw_val & 28
        self._i2c_write_reg(0, [
            val])

    
    def ext_clk(self = None, enable = None):
        r = self._i2c_read_reg(0, 1)
        val = r[0]
        if enable:
            val |= 32
        else:
            val &= -33
        self._i2c_write_reg(0, [
            val])

    
    def osc_off(self = None, enable = None):
        r = self._i2c_read_reg(0, 1)
        val = r[0]
        if enable:
            val |= 16
        else:
            val &= -17
        self._i2c_write_reg(0, [
            val])

    
    def ch_conf_load(self, ch_mask):
        self._i2c_write_reg(1, [
            ch_mask])

    
    def ch_force_stop(self, ch_mask):
        self._i2c_write_reg(2, [
            ch_mask])

    
    def dc_ctrl(self, mode):
        self._i2c_write_reg(3, [
            mode])

    
    def event_clr(self, mask):
        self._i2c_write_reg(13, [
            mask])

    
    def watch_sel(self = None, enable = None, sel = None):
        if enable:
            self._i2c_write_reg(14, [
                128 | sel & 127])
        else:
            self._i2c_write_reg(14, [
                0 | sel & 127])

    
    def read_chip_flag(self):
        return self._i2c_read_reg(15, 1)[0]

    
    def _ch_base(self, ch):
        if ch in ('A', 'CHA', 'a'):
            return 16
        if None in ('B', 'CHB', 'b'):
            return 32
        raise None("Unknown channel '{}'".format(ch))

    
    def set_ch_pd_out(self = None, ch = None, enable = None):
        base = self._ch_base(ch)
        r = self._i2c_read_reg(base + 0, 1)
        val = r[0]
        if enable:
            val |= 64
        else:
            val &= -65
        self._i2c_write_reg(base + 0, [
            val])

    
    def set_ch_record_rev(self = None, ch = None, enable = None):
        base = self._ch_base(ch)
        r = self._i2c_read_reg(base + 0, 1)
        val = r[0]
        if enable:
            val |= 32
        else:
            val &= -33
        self._i2c_write_reg(base + 0, [
            val])

    
    def set_ch_dir(self = None, ch = None, cw = None):
        base = self._ch_base(ch)
        r = self._i2c_read_reg(base + 1, 1)
        val = r[0]
        if cw:
            val &= -2
        else:
            val |= 1
        self._i2c_write_reg(base + 1, [
            val])

    
    def set_ch_stop_pos(self, ch, pos_mask):
        base = self._ch_base(ch)
        r = self._i2c_read_reg(base + 1, 1)
        val = r[0] & -13 | pos_mask & 12
        self._i2c_write_reg(base + 1, [
            val])

    
    def set_ch_ms_mode(self, ch, ms_mask):
        base = self._ch_base(ch)
        r = self._i2c_read_reg(base + 1, 1)
        val = r[0] & -241 | ms_mask & 240
        self._i2c_write_reg(base + 1, [
            val])

    
    def set_ch_pps(self, ch, pps):
        fclk = FCLK_FREQUENCY
        u16reg = int(fclk / (int(pps) << 4))
        lo = u16reg & 255
        hi = (u16reg & 65280) >> 8
        base = self._ch_base(ch) | 128
        self._i2c_write_reg(base + 2, [
            lo,
            hi])

    
    def set_ch_stepnum(self, ch, step_num):
        lo = step_num & 255
        hi = step_num >> 8 & 255
        base = self._ch_base(ch) | 128
        self._i2c_write_reg(base + 4, [
            lo,
            hi])

    
    def set_ch_current(self, ch, amp_percent):
        base = self._ch_base(ch)
        v = int(amp_percent) & 255
        self._i2c_write_reg(base + 6, [
            v])

    
    def read_ch_status(self, ch):
        base = self._ch_base(ch)
        return self._i2c_read_reg(base + 13, 1)[0]

    
    def read_ch_pulse_record(self, ch):
        base = self._ch_base(ch)
        r = self._i2c_read_reg(base + 14, 2)
        return r[1] << 8 | r[0]

    
    def force_enable_channel_power(self, ch):
        base = self._ch_base(ch)
        r = self._i2c_read_reg(base, 1)[0]
        r |= 64
        self._i2c_write_reg(base, [
            r])

    
    def init_chip(self, default_pps, default_step_fraction_div, default_current = (400, 10, 120)):
        '''
        Configure the chip with defaults similar to Init_MS32008() from control.c
        This writes the reg0 defaults, clears events, config channels, sets PPS/stepnum/current
        '''
        self.soft_reset()
        self.read_chip_flag()
        reg0 = 5
        self._i2c_write_reg(0, [
            reg0])
        self.dc_ctrl(0)
        self.event_clr(192)
        cha_byte0 = 64
        cha_byte1 = 96
        self._i2c_write_reg(144, [
            cha_byte0,
            cha_byte1])
        self._i2c_write_reg(160, [
            cha_byte0,
            cha_byte1])
        pps = default_pps
        stepnum = int(pps / default_step_fraction_div)

    
    def move_channel(self, ch, pps, steps, dir_cw = (True,)):
        '''
        High-level move: set pps, stepnum, dir, then issue conf_load to start.
        This mirrors how control.c sets registers then calls CHxConfLoad.
        '''
        self.set_ch_current(ch, 120)
        self.set_ch_pps(ch, pps)
        self.set_ch_stepnum(ch, steps)
        self.set_ch_dir(ch, dir_cw)
        if ch in ('A', 'CHA', 'a'):
            self.ch_conf_load(128)
        else:
            self.ch_conf_load(64)

    
    def motor_control(self, ch):
        r = self._i2c_read_reg(2, 1)[0]
        if ch == 'A':
            r = r | 128 if r & 128 == 0 else r & 127
        elif ch == 'B':
            r = r | 64 if r & 64 == 0 else r & 191
        elif ch == 'Z':
            r = r | 128 if r & 128 == 0 else r & 127
            r = r | 64 if r & 64 == 0 else r & 191
        self._i2c_write_reg(2, [
            r])

    
    def gcmd_init(self, gcmd):
        self.init_chip()
        gcmd.respond_info('MS32008 initialized')

    
    def gcmd_read(self, gcmd):
        reg = gcmd.get_int('REG')
        count = gcmd.get_int('COUNT')
        data = self._i2c_read_reg(reg, count)
        hexstr = ' '.join(for b in (data):
'0x%02X' % b)
        gcmd.respond_info('MS32008 READ: ' + hexstr)

    
    def gcmd_write(self, gcmd):
        reg = gcmd.get_int('REG')
        raw = gcmd.get('DATA')
        if not raw:
            raise gcmd.error('DATA required')
        data = [ int(x, 0) for x in (raw.split()) ]
        self._i2c_write_reg(reg | 128, data)
        gcmd.respond_info('MS32008 WRITE OK')

    
    def gcmd_move(self, gcmd):
        ch = gcmd.get('CH', 'A')
        pps = gcmd.get_int('PPS')
        steps = gcmd.get_int('STEPS')
        dirv = gcmd.get('DIR', 'CW')
        cw = dirv.upper() == 'CW'
        self.move_channel(ch, pps, steps, cw)
        gcmd.respond_info('MS32008 MOVE started')

    
    def gcmd_set(self, gcmd):
        ch = gcmd.get('CH', 'A')
        if gcmd.has('CURRENT'):
            cur = gcmd.get_int('CURRENT')
            self.set_ch_current(ch, cur)
            gcmd.respond_info('CURRENT set')
            return None
        if None.has('PPS'):
            pps = gcmd.get_int('PPS')
            self.set_ch_pps(ch, pps)
            gcmd.respond_info('PPS set')
            return None
        if None.has('STEP'):
            s = gcmd.get_int('STEP')
            self.set_ch_stepnum(ch, s)
            gcmd.respond_info('STEPNUM set')
            return None
        if None.has('DIR'):
            d = gcmd.get('DIR')
            self.set_ch_dir(ch, d.upper() == 'CW')
            gcmd.respond_info('DIR set')
            return None
        raise None.error('No known parameter provided')

    
    def gcmd_dc(self, gcmd):
        mode = gcmd.get_int('MODE')
        self.dc_ctrl(mode)
        gcmd.respond_info('DC control set')



def load_config(config):
    return MS32008(config)

