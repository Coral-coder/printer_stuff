# =====================================================================
# PARTIAL DECOMPILATION -- this module did not fully round-trip.
# The 3.9 bytecode uses control flow the decompiler could not fully
# reconstruct (e.g. try/except/else with returns, or a generator with a
# dropped builtin rendered as `None(...)`). The code below is best-effort
# and will not import as-is. Ground-truth disassembly for repair:
#     decompiled/_disasm/tmc.txt
# =====================================================================

# Source Generated with Decompyle++
# File: tmc.pyc (Python 3.9)

import logging
import collections
import stepper

def ffs(mask):
    return (mask & -mask).bit_length() - 1


class FieldHelper:
    
    def __init__(self, all_fields, signed_fields = [], field_formatters = { }, registers = None):
        self.all_fields = all_fields
        self.signed_fields = { sf: 1 for sf in (signed_fields) }
        self.field_formatters = field_formatters
        self.registers = registers
        if self.registers is None:
            self.registers = collections.OrderedDict()
        self.field_to_register = { f: r for r, fields in (self.all_fields.items()) for f in fields }

    
    def lookup_register(self, field_name, default = None):
        return self.field_to_register.get(field_name, default)

    
    def get_field(self, field_name, reg_value = None, reg_name = None):
        if reg_name is None:
            reg_name = self.field_to_register[field_name]
        if reg_value is None:
            reg_value = self.registers.get(reg_name, 0)
        mask = self.all_fields[reg_name][field_name]
        field_value = (reg_value & mask) >> ffs(mask)
        if field_name in self.signed_fields and (reg_value & mask) << 1 > mask:
            field_value -= 1 << field_value.bit_length()
        return field_value

    
    def set_field(self, field_name, field_value, reg_value = None, reg_name = None):
        if reg_name is None:
            reg_name = self.field_to_register[field_name]
        if reg_value is None:
            reg_value = self.registers.get(reg_name, 0)
        mask = self.all_fields[reg_name][field_name]
        new_value = reg_value & ~mask | field_value << ffs(mask) & mask
        self.registers[reg_name] = new_value
        return new_value

    
    def set_config_field(self, config, field_name, default):
        config_name = 'driver_' + field_name.upper()
        reg_name = self.field_to_register[field_name]
        mask = self.all_fields[reg_name][field_name]
        maxval = mask >> ffs(mask)
        if maxval == 1:
            val = config.getboolean(config_name, default)
        elif field_name in self.signed_fields:
            val = config.getint(config_name, default, minval=-(maxval // 2 + 1), maxval=maxval // 2)
        else:
            val = config.getint(config_name, default, minval=0, maxval=maxval)
        return self.set_field(field_name, val)

    
    def pretty_format(self, reg_name, reg_value):
        reg_fields = self.all_fields.get(reg_name, { })
        reg_fields = sorted([ (mask, name) for name, mask in (reg_fields.items()) ])
        fields = []
        for mask, field_name in reg_fields:
            field_value = self.get_field(field_name, reg_value, reg_name)
            sval = self.field_formatters.get(field_name, str)(field_value)
            if sval and sval != '0':
                fields.append(' %s=%s' % (field_name, sval))
        return '%-11s %08x%s' % (reg_name + ':', reg_value, ''.join(fields))

    
    def get_reg_fields(self, reg_name, reg_value):
        reg_fields = self.all_fields.get(reg_name, { })
        return { field_name: self.get_field(field_name, reg_value, reg_name) for field_name, mask in (reg_fields.items()) }



class TMCErrorCheck:
    
    def __init__(self, config, mcu_tmc):
        self.printer = config.get_printer()
        name_parts = config.get_name().split()
        self.stepper_name = ' '.join(name_parts[1:])
        self.mcu_tmc = mcu_tmc
        self.fields = mcu_tmc.get_fields()
        self.check_timer = None
        self.last_drv_status = self.last_status = None
        reg_name = self.fields.lookup_register('drv_err')
        if reg_name is not None:
            self.gstat_reg_info = [
                0,
                reg_name,
                0xFFFFFFFF,
                0xFFFFFFFF,
                0]
        else:
            self.gstat_reg_info = None
        self.clear_gstat = True
        self.irun_field = 'irun'
        reg_name = 'DRV_STATUS'
        mask = err_mask = cs_actual_mask = 0
        if name_parts[0] == 'tmc2130':
            self.clear_gstat = False
            cs_actual_mask = self.fields.all_fields[reg_name]['cs_actual']
        elif name_parts[0] == 'tmc2660':
            self.irun_field = 'cs'
            reg_name = 'READRSP@RDSEL2'
            cs_actual_mask = self.fields.all_fields[reg_name]['se']
        err_fields = [
            'ot',
            's2ga',
            's2gb',
            's2vsa',
            's2vsb']
        warn_fields = [
            'otpw',
            't120',
            't143',
            't150',
            't157']
        for f in err_fields + warn_fields:
            if f in self.fields.all_fields[reg_name]:
                mask |= self.fields.all_fields[reg_name][f]
                if f in err_fields:
                    err_mask |= self.fields.all_fields[reg_name][f]
        self.drv_status_reg_info = [
            0,
            reg_name,
            mask,
            err_mask,
            cs_actual_mask]

    
    def _query_register(self, reg_info, try_clear = False):
        (last_value, reg_name, mask, err_mask, cs_actual_mask) = reg_info
        cleared_flags = 0
        count = 0
        
        while 1:
            try:
                val = self.mcu_tmc.get_register(reg_name)
            except self.printer.command_error as e:
                count += 1
                if count < 3 and str(e).startswith('Unable to read tmc uart'):
                    reactor = self.printer.get_reactor()
                    reactor.pause(reactor.monotonic() + 0.05)
                    continue
                raise
            if val & mask != last_value & mask:
                fmt = self.fields.pretty_format(reg_name, val)
                logging.info("TMC '%s' reports %s", self.stepper_name, fmt)
            reg_info[0] = last_value = val
            if not val & err_mask:
                if not cs_actual_mask or val & cs_actual_mask:
                    break
                irun = self.fields.get_field(self.irun_field)
                if self.check_timer is None or irun < 4:
                    break
                if self.irun_field == 'irun' and not self.fields.get_field('ihold'):
                    break
            count += 1
            if count >= 3:
                fmt = self.fields.pretty_format(reg_name, val)
                code_key = 'key505'
                m = '{"code":"%s","msg":"TMC \'%s\' reports error: %s"}' % (code_key, self.stepper_name, fmt)
                raise self.printer.command_error(m)
            if try_clear and val & err_mask:
                try_clear = False
                cleared_flags |= val & err_mask
                self.mcu_tmc.set_register(reg_name, val & err_mask)
        return cleared_flags

    
    def _do_periodic_check(self, eventtime):
        try:
            self._query_register(self.drv_status_reg_info)
            if self.gstat_reg_info is not None:
                self._query_register(self.gstat_reg_info)
        except self.printer.command_error as e:
            self.printer.invoke_shutdown(str(e))
            return self.printer.get_reactor().NEVER
        return eventtime + 1.0



    
    def stop_checks(self):
        if self.check_timer is None:
            return None
        self.printer.get_reactor().unregister_timer(self.check_timer)
        self.check_timer = None

    
    def start_checks(self):
        if self.check_timer is not None:
            self.stop_checks()
        cleared_flags = 0
        self._query_register(self.drv_status_reg_info)
        if self.gstat_reg_info is not None:
            cleared_flags = self._query_register(self.gstat_reg_info, try_clear=self.clear_gstat)
        reactor = self.printer.get_reactor()
        curtime = reactor.monotonic()
        self.check_timer = reactor.register_timer(self._do_periodic_check, curtime + 1.0)
        if cleared_flags:
            reset_mask = self.fields.all_fields['GSTAT']['reset']
            if cleared_flags & reset_mask:
                return True
        return False

    
    def get_status(self, eventtime = None):
        if self.check_timer is None:
            return {
                'drv_status': None }
        (last_value, reg_name) = self.drv_status_reg_info[:2]
        if last_value != self.last_drv_status:
            self.last_drv_status = last_value
            fields = self.fields.get_reg_fields(reg_name, last_value)
            fields = { n: v for n, v in (fields.items()) if v }
            self.last_status = {
                'drv_status': fields }
        return self.last_status



class TMCCommandHelper:
    
    def __init__(self, config, mcu_tmc, current_helper):
        self.printer = config.get_printer()
        self.config = config
        self.stepper_name = ' '.join(config.get_name().split()[1:])
        self.name = config.get_name().split()[-1]
        self.mcu_tmc = mcu_tmc
        self.current_helper = current_helper
        self.echeck_helper = TMCErrorCheck(config, mcu_tmc)
        self.fields = mcu_tmc.get_fields()
        self.read_registers = self.read_translate = None
        self.toff = None
        self.mcu_phase_offset = None
        self.stepper = None
        self.stepper_enable = self.printer.load_object(config, 'stepper_enable')
        self.printer.register_event_handler('stepper:sync_mcu_position', self._handle_sync_mcu_pos)
        self.printer.register_event_handler('stepper:set_sdir_inverted', self._handle_sync_mcu_pos)
        self.printer.register_event_handler('klippy:mcu_identify', self._handle_mcu_identify)
        self.printer.register_event_handler('klippy:connect', self._handle_connect)
        TMCMicrostepHelper(config, mcu_tmc)
        gcode = self.printer.lookup_object('gcode')
        gcode.register_mux_command('SET_TMC_FIELD', 'STEPPER', self.name, self.cmd_SET_TMC_FIELD, desc=self.cmd_SET_TMC_FIELD_help)
        gcode.register_mux_command('GET_TMC_FIELD', 'STEPPER', self.name, self.cmd_GET_TMC_FIELD, desc=self.cmd_GET_TMC_FIELD_help)
        gcode.register_mux_command('INIT_TMC', 'STEPPER', self.name, self.cmd_INIT_TMC, desc=self.cmd_INIT_TMC_help)
        gcode.register_mux_command('SET_TMC_CURRENT', 'STEPPER', self.name, self.cmd_SET_TMC_CURRENT, desc=self.cmd_SET_TMC_CURRENT_help)

    
    def _init_registers(self, print_time = None):
        name_parts = self.config.get_name().split()
        logging.info('hys: name_parts: %s' % name_parts)
        for reg_name, val in self.fields.registers.items():
            if name_parts[0] == 'tmc2262' and reg_name == 'PLL':
                self.TMC2262_PLL_init(val, print_time)
                continue
            self.mcu_tmc.set_register(reg_name, val, print_time)

    
    def TMC2262_PLL_init(self, val, print_time = None):
        logging.info('hys: TMC2262_PLL_init start')
        logging.info('hys: set PLL val -- 0x%x' % val)
        commit_mask = self.mcu_tmc.fields.all_fields['PLL']['commit']
        clk_sys_sel_mask = self.mcu_tmc.fields.all_fields['PLL']['clk_sys_sel']
        clk_fsm_ena_mask = self.mcu_tmc.fields.all_fields['PLL']['clk_fsm_ena']
        adc_clk_ena_mask = self.mcu_tmc.fields.all_fields['PLL']['adc_clk_ena']
        clk_1mo_tmo_mask = self.mcu_tmc.fields.all_fields['PLL']['clk_1mo_tmo']
        clk_loss_mask = self.mcu_tmc.fields.all_fields['PLL']['clk_loss']
        clk_is_stuck_mask = self.mcu_tmc.fields.all_fields['PLL']['clk_is_stuck']
        pll_lock_loss_mask = self.mcu_tmc.fields.all_fields['PLL']['pll_lock_loss']
        set_times = 3
        while set_times:
            self.mcu_tmc.set_register('PLL', 0, print_time)
            logging.info('hys: configure & commit necessary bits, val = 0x%x' % (val | commit_mask | clk_fsm_ena_mask | clk_sys_sel_mask))
            self.mcu_tmc.set_register('PLL', val | commit_mask | clk_fsm_ena_mask | clk_sys_sel_mask, print_time)
            logging.info('hys: check for commit bit to be reset')
            timeout = 3
            while timeout:
                val_ret = self.mcu_tmc.get_register('PLL')
                logging.info('hys: get value: 0x%x' % val_ret)
                if not val_ret & commit_mask:
                    logging.info('hys: commit bit reset')
                    break
                timeout -= 1
            val_clear = adc_clk_ena_mask | pll_lock_loss_mask | clk_is_stuck_mask | clk_loss_mask | clk_1mo_tmo_mask | clk_fsm_ena_mask
            self.mcu_tmc.set_register('PLL', val_clear, print_time)
            logging.info('hys: reset error, set value 0x%x' % val_clear)
            val_ret = self.mcu_tmc.get_register('PLL')
            val_clear = pll_lock_loss_mask | clk_is_stuck_mask | clk_loss_mask | clk_1mo_tmo_mask | clk_fsm_ena_mask
            logging.info('hys: check for errors and clk_fsm_ena, get value 0x%x, val_clear = 0x%x' % (val_ret, val_clear))
            if val_ret & val_clear == clk_fsm_ena_mask:
                logging.info('hys: errors clear')
                break
            set_times -= 1
        logging.info('hys: TMC2262_PLL_init end')

    cmd_INIT_TMC_help = 'Initialize TMC stepper driver registers'
    
    def cmd_INIT_TMC(self, gcmd):
        logging.info('INIT_TMC %s', self.name)
        print_time = self.printer.lookup_object('toolhead').get_last_move_time()
        self._init_registers(print_time)

    cmd_SET_TMC_FIELD_help = 'Set a register field of a TMC driver'
    
    def cmd_SET_TMC_FIELD(self, gcmd):
        field_name = gcmd.get('FIELD').lower()
        reg_name = self.fields.lookup_register(field_name, None)
        if reg_name is None:
            raise gcmd.error("Unknown field name '%s'" % (field_name,))
        value = gcmd.get_int('VALUE')
        reg_val = self.fields.set_field(field_name, value)
        print_time = self.printer.lookup_object('toolhead').get_last_move_time()
        self.mcu_tmc.set_register(reg_name, reg_val, print_time)

    cmd_GET_TMC_FIELD_help = 'Get a register field of a TMC driver'
    
    def cmd_GET_TMC_FIELD(self, gcmd):
        field_name = gcmd.get('FIELD').lower()
        reg_name = self.fields.lookup_register(field_name, None)
        if reg_name is None:
            raise gcmd.error("Unknown field name '%s'" % (field_name,))
        reg_val = self.fields.registers.get(reg_name, 0)
        reg_fields = self.fields.get_reg_fields(reg_name, reg_val)
        value = reg_fields.get(field_name, 0)
        gcmd.respond_info('Field %s: %d' % (field_name, value))

    cmd_SET_TMC_CURRENT_help = 'Set the current of a TMC driver'
    
    def cmd_SET_TMC_CURRENT(self, gcmd):
        ch = self.current_helper
        (prev_cur, prev_hold_cur, req_hold_cur, max_cur) = ch.get_current()
        run_current = gcmd.get_float('CURRENT', None, minval=0.0, maxval=max_cur)
        hold_current = gcmd.get_float('HOLDCURRENT', None, above=0.0, maxval=max_cur)
        if run_current is not None or hold_current is not None:
            if run_current is None:
                run_current = prev_cur
            if hold_current is None:
                hold_current = req_hold_cur
            toolhead = self.printer.lookup_object('toolhead')
            print_time = toolhead.get_last_move_time()
            ch.set_current(run_current, hold_current, print_time)
            (prev_cur, prev_hold_cur, req_hold_cur, max_cur) = ch.get_current()
        if prev_hold_cur is None:
            gcmd.respond_info('Run Current: %0.2fA' % (prev_cur,))
        else:
            gcmd.respond_info('Run Current: %0.2fA Hold Current: %0.2fA' % (prev_cur, prev_hold_cur))

    def _get_phases(self):
        return (256 >> self.fields.get_field('mres')) * 4

    def get_phase_offset(self):
        return self.mcu_phase_offset, self._get_phases()

    def _query_phase(self):
        field_name = 'mscnt'
        if self.fields.lookup_register(field_name, None) is None:
            field_name = 'mstep'
        reg = self.mcu_tmc.get_register(self.fields.lookup_register(field_name))
        return self.fields.get_field(field_name, reg)

    def _handle_sync_mcu_pos(self, stepper):
        if stepper.get_name() != self.stepper_name:
            return
        try:
            driver_phase = self._query_phase()
        except self.printer.command_error as e:
            logging.info('Unable to obtain tmc %s phase', self.stepper_name)
            self.mcu_phase_offset = None
            enable_line = self.stepper_enable.lookup_enable(self.stepper_name)
            if enable_line.is_motor_enabled():
                raise
            return
        if not stepper.get_dir_inverted()[0]:
            driver_phase = 1023 - driver_phase
        phases = self._get_phases()
        phase = int(float(driver_phase) / 1024 * phases + 0.5) % phases
        moff = (phase - stepper.get_mcu_position()) % phases
        if self.mcu_phase_offset is not None and self.mcu_phase_offset != moff:
            logging.warning('Stepper %s phase change (was %d now %d)', self.stepper_name, self.mcu_phase_offset, moff)
        self.mcu_phase_offset = moff

    def _do_enable(self, print_time):
        try:
            if self.toff is not None:
                self.fields.set_field('toff', self.toff)
            self._init_registers()
            did_reset = self.echeck_helper.start_checks()
            if did_reset:
                self.mcu_phase_offset = None
            if self.mcu_phase_offset is not None:
                return
            gcode = self.printer.lookup_object('gcode')
            with gcode.get_mutex():
                if self.mcu_phase_offset is not None:
                    return
                logging.info('Pausing toolhead to calculate %s phase offset', self.stepper_name)
                self.printer.lookup_object('toolhead').wait_moves()
                self._handle_sync_mcu_pos(self.stepper)
        except self.printer.command_error as e:
            self.printer.invoke_shutdown(str(e))

    def _do_disable(self, print_time):
        try:
            if self.toff is not None:
                val = self.fields.set_field('toff', 0)
                reg_name = self.fields.lookup_register('toff')
                self.mcu_tmc.set_register(reg_name, val, print_time)
            self.echeck_helper.stop_checks()
        except self.printer.command_error as e:
            self.printer.invoke_shutdown(str(e))

    def _handle_mcu_identify(self):
        force_move = self.printer.lookup_object('force_move')
        self.stepper = force_move.lookup_stepper(self.stepper_name)
        self.stepper.setup_default_pulse_duration(1e-07, True)

    def _handle_stepper_enable(self, print_time, is_enable):
        if is_enable:
            cb = lambda ev: self._do_enable(print_time)
        else:
            cb = lambda ev: self._do_disable(print_time)
        self.printer.get_reactor().register_callback(cb)

    def _handle_connect(self):
        (pulse_duration, step_both_edge) = self.stepper.get_pulse_duration()
        if step_both_edge:
            self.fields.set_field('dedge', 1)
        enable_line = self.stepper_enable.lookup_enable(self.stepper_name)
        enable_line.register_state_callback(self._handle_stepper_enable)
        if not enable_line.has_dedicated_enable():
            self.toff = self.fields.get_field('toff')
            self.fields.set_field('toff', 0)
            logging.info("Enabling TMC virtual enable for '%s'", self.stepper_name)
        try:
            self._init_registers()
        except self.printer.command_error as e:
            logging.info('TMC %s failed to init: %s', self.name, str(e))

    def get_status(self, eventtime = None):
        cpos = None
        if self.stepper is not None and self.mcu_phase_offset is not None:
            cpos = self.stepper.mcu_to_commanded_position(self.mcu_phase_offset)
        current = self.current_helper.get_current()
        res = {
            'mcu_phase_offset': self.mcu_phase_offset,
            'phase_offset_position': cpos,
            'run_current': current[0],
            'hold_current': current[1] }
        res.update(self.echeck_helper.get_status(eventtime))
        return res

    def setup_register_dump(self, read_registers, read_translate = None):
        self.read_registers = read_registers
        self.read_translate = read_translate
        gcode = self.printer.lookup_object('gcode')
        gcode.register_mux_command('DUMP_TMC', 'STEPPER', self.name, self.cmd_DUMP_TMC, desc=self.cmd_DUMP_TMC_help)

    cmd_DUMP_TMC_help = 'Read and display TMC stepper driver registers'

    def cmd_DUMP_TMC(self, gcmd):
        logging.info('DUMP_TMC %s', self.name)
        print_time = self.printer.lookup_object('toolhead').get_last_move_time()
        gcmd.respond_info('========== Write-only registers ==========')
        for reg_name, val in self.fields.registers.items():
            if reg_name not in self.read_registers:
                gcmd.respond_info(self.fields.pretty_format(reg_name, val))
        gcmd.respond_info('========== Queried registers ==========')
        for reg_name in self.read_registers:
            val = self.mcu_tmc.get_register(reg_name)
            if self.read_translate is not None:
                (reg_name, val) = self.read_translate(reg_name, val)
            gcmd.respond_info(self.fields.pretty_format(reg_name, val))


class TMCVirtualPinHelper:

    def __init__(self, config, mcu_tmc):
        self.printer = config.get_printer()
        self.mcu_tmc = mcu_tmc
        self.fields = mcu_tmc.get_fields()
        if self.fields.lookup_register('diag0_stall') is not None:
            if config.get('diag0_pin', None) is not None:
                self.diag_pin = config.get('diag0_pin')
                self.diag_pin_field = 'diag0_stall'
            else:
                self.diag_pin = config.get('diag1_pin', None)
                self.diag_pin_field = 'diag1_stall'
        else:
            self.diag_pin = config.get('diag_pin', None)
            self.diag_pin_field = None
        self.mcu_endstop = None
        self.en_pwm = False
        self.pwmthrs = 0
        name_parts = config.get_name().split()
        ppins = self.printer.lookup_object('pins')
        ppins.register_chip('%s_%s' % (name_parts[0], name_parts[-1]), self)

    def setup_pin(self, pin_type, pin_params):
        ppins = self.printer.lookup_object('pins')
        if pin_type != 'endstop' or pin_params['pin'] != 'virtual_endstop':
            raise ppins.error('tmc virtual endstop only useful as endstop')
        if pin_params['invert'] or pin_params['pullup']:
            raise ppins.error('Can not pullup/invert tmc virtual pin')
        if self.diag_pin is None:
            raise ppins.error('tmc virtual endstop requires diag pin config')
        reg = self.fields.lookup_register('en_pwm_mode', None)
        if reg is None:
            self.en_pwm = not self.fields.get_field('en_spreadcycle')
            self.pwmthrs = self.fields.get_field('tpwmthrs')
        else:
            self.en_pwm = self.fields.get_field('en_pwm_mode')
            self.pwmthrs = 0
        self.printer.register_event_handler('homing:homing_move_begin', self.handle_homing_move_begin)
        self.printer.register_event_handler('homing:homing_move_end', self.handle_homing_move_end)
        self.mcu_endstop = ppins.setup_pin('endstop', self.diag_pin)
        return self.mcu_endstop

    def handle_homing_move_begin(self, hmove):
        if self.mcu_endstop not in hmove.get_mcu_endstops():
            return
        reg = self.fields.lookup_register('en_pwm_mode', None)
        if reg is None:
            tp_val = self.fields.set_field('tpwmthrs', 0)
            self.mcu_tmc.set_register('TPWMTHRS', tp_val)
            val = self.fields.set_field('en_spreadcycle', 0)
        else:
            self.fields.set_field('en_pwm_mode', 0)
            val = self.fields.set_field(self.diag_pin_field, 1)
        self.mcu_tmc.set_register('GCONF', val)
        tc_val = self.fields.set_field('tcoolthrs', 1048575)
        self.mcu_tmc.set_register('TCOOLTHRS', tc_val)

    def handle_homing_move_end(self, hmove):
        if self.mcu_endstop not in hmove.get_mcu_endstops():
            return
        reg = self.fields.lookup_register('en_pwm_mode', None)
        if reg is None:
            tp_val = self.fields.set_field('tpwmthrs', self.pwmthrs)
            self.mcu_tmc.set_register('TPWMTHRS', tp_val)
            val = self.fields.set_field('en_spreadcycle', not self.en_pwm)
        else:
            self.fields.set_field('en_pwm_mode', self.en_pwm)
            val = self.fields.set_field(self.diag_pin_field, 0)
        self.mcu_tmc.set_register('GCONF', val)
        tc_val = self.fields.set_field('tcoolthrs', 0)
        self.mcu_tmc.set_register('TCOOLTHRS', tc_val)


def TMCWaveTableHelper(config, mcu_tmc):
    set_config_field = mcu_tmc.get_fields().set_config_field
    set_config_field(config, 'mslut0', 2863314260)
    set_config_field(config, 'mslut1', 1251300522)
    set_config_field(config, 'mslut2', 608774441)
    set_config_field(config, 'mslut3', 269500962)
    set_config_field(config, 'mslut4', 4227858431)
    set_config_field(config, 'mslut5', 3048961917)
    set_config_field(config, 'mslut6', 1227445590)
    set_config_field(config, 'mslut7', 4211234)
    set_config_field(config, 'w0', 2)
    set_config_field(config, 'w1', 1)
    set_config_field(config, 'w2', 1)
    set_config_field(config, 'w3', 1)
    set_config_field(config, 'x1', 128)
    set_config_field(config, 'x2', 255)
    set_config_field(config, 'x3', 255)
    set_config_field(config, 'start_sin', 0)
    set_config_field(config, 'start_sin90', 247)


def TMCMicrostepHelper(config, mcu_tmc):
    fields = mcu_tmc.get_fields()
    stepper_name = ' '.join(config.get_name().split()[1:])
    if not config.has_section(stepper_name):
        raise config.error("Could not find config section '[%s]' required by tmc driver" % (stepper_name,))
    stepper_config = ms_config = config.getsection(stepper_name)
    if stepper_config.get('microsteps', None, note_valid=False) is None and config.get('microsteps', None, note_valid=False) is not None:
        ms_config = config
    steps = {
        256: 0,
        128: 1,
        64: 2,
        32: 3,
        16: 4,
        8: 5,
        4: 6,
        2: 7,
        1: 8 }
    mres = ms_config.getchoice('microsteps', steps)
    fields.set_field('mres', mres)
    fields.set_field('intpol', config.getboolean('interpolate', True))


def TMCStealthchopHelper(config, mcu_tmc, tmc_freq):
    fields = mcu_tmc.get_fields()
    en_pwm_mode = False
    velocity = config.getfloat('stealthchop_threshold', 0.0, minval=0.0)
    if velocity:
        stepper_name = ' '.join(config.get_name().split()[1:])
        sconfig = config.getsection(stepper_name)
        (rotation_dist, steps_per_rotation) = stepper.parse_step_distance(sconfig)
        step_dist = rotation_dist / steps_per_rotation
        step_dist_256 = step_dist / (1 << fields.get_field('mres'))
        threshold = int(tmc_freq * step_dist_256 / velocity + 0.5)
        fields.set_field('tpwmthrs', max(0, min(1048575, threshold)))
        en_pwm_mode = True
    reg = fields.lookup_register('en_pwm_mode', None)
    if reg is not None:
        name_parts = config.get_name().split()
        if name_parts[0] == 'tmc2262':
            return
        fields.set_field('en_pwm_mode', en_pwm_mode)
    else:
        fields.set_field('en_spreadcycle', not en_pwm_mode)


def TMCVcoolthrsHelper(config, mcu_tmc, tmc_freq):
    fields = mcu_tmc.get_fields()
    velocity = config.getfloat('coolstep_threshold', None, minval=0.0)
    tcoolthrs = 0
    if velocity:
        stepper_name = ' '.join(config.get_name().split()[1:])
        sconfig = config.getsection(stepper_name)
        (rotation_dist, steps_per_rotation) = stepper.parse_step_distance(sconfig)
        step_dist = rotation_dist / steps_per_rotation
        step_dist_256 = step_dist / (1 << fields.get_field('mres'))
        tcoolthrs = int(tmc_freq * step_dist_256 / velocity + 0.5)
    fields.set_field('tcoolthrs', tcoolthrs)