# Source Generated with Decompyle++
# File: tmc.pyc (Python 3.9)

import logging
import collections
import stepper

def ffs(mask):
    return (mask & -mask).bit_length() - 1


class FieldHelper:
    
    def __init__(self, all_fields, signed_fields, field_formatters, registers = ([], { }, None)):
        self.all_fields = all_fields
        self.signed_fields = { sf: 1 for sf in (signed_fields) }
        self.field_formatters = field_formatters
        self.registers = registers
        if self.registers is None:
            self.registers = collections.OrderedDict()
        self.field_to_register = { f: r for r, fields in (self.all_fields.items()) for f in fields }

    
    def lookup_register(self, field_name, default = (None,)):
        return self.field_to_register.get(field_name, default)

    
    def get_field(self, field_name, reg_value, reg_name = (None, None)):
        if reg_name is None:
            reg_name = self.field_to_register[field_name]
        if reg_value is None:
            reg_value = self.registers.get(reg_name, 0)
        mask = self.all_fields[reg_name][field_name]
        field_value = (reg_value & mask) >> ffs(mask)
        if field_name in self.signed_fields and (reg_value & mask) << 1 > mask:
            field_value -= 1 << field_value.bit_length()
        return field_value

    
    def set_field(self, field_name, field_value, reg_value, reg_name = (None, None)):
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
                continue
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
        self.last_drv_status = None
        self.last_status = None
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
                    continue
                    self.drv_status_reg_info = [
                        0,
                        reg_name,
                        mask,
                        err_mask,
                        cs_actual_mask]
                    return None

    
    def _query_register(self, reg_info, try_clear = (False,)):
        (last_value, reg_name, mask, err_mask, cs_actual_mask) = reg_info
        cleared_flags = 0
        count = 0
        
        try:
            val = self.mcu_tmc.get_register(reg_name)
        except self.printer.command_error:
            e = None
            
            try:
                count += 1
                if count < 3 and str(e).startswith('Unable to read tmc uart'):
                    reactor = self.printer.get_reactor()
                    reactor.pause(reactor.monotonic() + 0.05)
            finally:
                e = None
                del e
                continue
                raise 
                e = None
                del e
            e = None
            del e
            if val & mask != last_value & mask:
                fmt = self.fields.pretty_format(reg_name, val)
                logging.info("TMC '%s' reports %s", self.stepper_name, fmt)


        reg_info[0] = last_value = val
        if not val & err_mask:
            if cs_actual_mask or val & cs_actual_mask:
                pass
            else:
                irun = self.fields.get_field(self.irun_field)
                if not self.check_timer is None:
                    if irun < 4:
                        pass
                    elif not self.irun_field == 'irun' and self.fields.get_field('ihold'):
                        pass
                    else:
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
                            continue
                            return cleared_flags

    
    def _do_periodic_check(self, eventtime):
        
        try:
            self._query_register(self.drv_status_reg_info)
            if self.gstat_reg_info is not None:
                self._query_register(self.gstat_reg_info)
        except self.printer.command_error:
            e = None
            
            try:
                self.printer.invoke_shutdown(str(e))
            finally:
                e = None
                del e
                return None
                e = None
                del e
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

    
    def get_status(self, eventtime = (None,)):
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
        self.read_registers = None
        self.read_translate = None
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

    
    def _init_registers(self, print_time = (None,)):
        name_parts = self.config.get_name().split()
        logging.info('hys: name_parts: %s' % name_parts)
        for reg_name, val in self.fields.registers.items():
            if name_parts[0] == 'tmc2262' and reg_name == 'PLL':
                self.TMC2262_PLL_init(val, print_time)
                continue
            self.mcu_tmc.set_register(reg_name, val, print_time)

    
    def TMC2262_PLL_init(self, val, print_time = (None,)):
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
        if set_times:
            self.mcu_tmc.set_register('PLL', 0, print_time)
            logging.info('hys: configure & commit necessary bits, val = 0x%x' % (val | commit_mask | clk_fsm_ena_mask | clk_sys_sel_mask))
            self.mcu_tmc.set_register('PLL', val | commit_mask | clk_fsm_ena_mask | clk_sys_sel_mask, print_time)
            logging.info('hys: check for commit bit to be reset')
            timeout = 3
            if timeout:
                val_ret = self.mcu_tmc.get_register('PLL')
                logging.info('hys: get value: 0x%x' % val_ret)
                if not val_ret & commit_mask:
                    logging.info('hys: commit bit reset')
                else:
                    timeout -= 1
            val_clear = adc_clk_ena_mask | pll_lock_loss_mask | clk_is_stuck_mask | clk_loss_mask | clk_1mo_tmo_mask | clk_fsm_ena_mask
            self.mcu_tmc.set_register('PLL', val_clear, print_time)
            logging.info('hys: reset error, set value 0x%x' % val_clear)
            val_ret = self.mcu_tmc.get_register('PLL')
            val_clear = pll_lock_loss_mask | clk_is_stuck_mask | clk_loss_mask | clk_1mo_tmo_mask | clk_fsm_ena_mask
            logging.info('hys: check for errors and clk_fsm_ena, get value 0x%x, val_clear = 0x%x' % (val_ret, val_clear))
            if val_ret & val_clear == clk_fsm_ena_mask:
                logging.info('hys: errors clear')
            else:
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
      