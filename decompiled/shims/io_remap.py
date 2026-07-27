# Source Generated with Decompyle++
# File: io_remap.pyc (Python 3.9)

import mcu
import logging

class CommandError(Exception):
    pass


class IORemap:
    error = CommandError
    
    def __init__(self, config):
        self.config = config
        self.printer = config.get_printer()
        self.src_pin_list = self.config.getsection('io_remap').getlist('src_pin_list')
        for src_pin in self.src_pin_list:
            setattr(self, src_pin, self.config.getsection('io_remap').get(src_pin))
            src_pin_pullup = '%s_pullup' % src_pin
            setattr(self, src_pin_pullup, self.config.getsection('io_remap').getint(src_pin_pullup))
        self.remap_mcu = self.config.getsection('io_remap').get('remap_mcu')
        self.remap_pin = self.config.getsection('io_remap').get('remap_pin')
        self.remap_def = self.config.getsection('io_remap').getint('remap_def')
        self.filterNum = self.config.getsection('io_remap').getint('filterNum')
        self.periodTicks = self.config.getsection('io_remap').getint('periodTicks')
        self.mcu = mcu.get_printer_mcu(self.printer, self.remap_mcu)
        self.oidx = self.mcu.create_oid()
        self.oidy = self.mcu.create_oid()
        self.mcu.register_config_callback(self._build_config)
        self.gcode = config.get_printer().lookup_object('gcode')
        self.gcode.register_command('SET_IOREMAP', self.cmd_SET_IOREMAP)

    
    def _build_config(self):
        for src_pin in self.src_pin_list:
            src_pin_pullup = '%s_pullup' % src_pin
            self.mcu.add_config_cmd('config_ioRemap oid=%d src_pin=%s src_pullup=%d remap_pin=%s remap_def=%d' % (self.oidx, getattr(self, src_pin), getattr(self, src_pin_pullup), self.remap_pin, self.remap_def))
            self.gcode.respond_info('config_ioRemap oid=%s src_pin=%s src_pullup=%s remap_pin=%s remap_def=%s' % (self.oidx, getattr(self, src_pin), getattr(self, src_pin_pullup), self.remap_pin, self.remap_def))

    
    def cmd_SET_IOREMAP(self, gcmd):
        operation = gcmd.get_int('S', 0)
        axes = gcmd.get_int('AXES', 0)
        oid = self.oidx if axes == 0 else self.oidy
        operation_ioRemap = self.mcu.lookup_query_command('operation_ioRemap oid=%c operation=%c filterNum=%c periodTicks=%u', 'query_ioRemap oid=%c sta=%c', oid=oid)
        operation_ioRemap.send([
            oid,
            operation,
            self.filterNum,
            self.periodTicks])
        self.gcode.respond_info('operation_ioRemap oid=%s operation=%s filterNum=%s periodTicks=%s' % (oid, operation, self.filterNum, self.periodTicks))



def load_config(config):
    return IORemap(config)

