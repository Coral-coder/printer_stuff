# =====================================================================
# PARTIAL DECOMPILATION -- this module did not fully round-trip.
# The 3.9 bytecode uses control flow the decompiler could not fully
# reconstruct (e.g. try/except/else with returns, or a generator with a
# dropped builtin rendered as `None(...)`). The code below is best-effort
# and will not import as-is. Ground-truth disassembly for repair:
#     decompiled/_disasm/auto_addr_wrapper.txt
# =====================================================================

# Source Generated with Decompyle++
# File: auto_addr_wrapper.pyc (Python 3.9)

import logging
import copy
from dataclasses import dataclass
from typing import List, Union
MAX_DATA_LEN = 100
MAX_UNIID_LEN = 12
MAX_LOST_CNT = 3
PACK_HEAD = 247
BROADCAST_ADDR = 255
BROADCAST_ADDR_MB = 254
BROADCAST_ADDR_CLM = 253
BROADCAST_ADDR_BTM = 252
CMD_GET_SLAVE_INFO = 161
CMD_SET_SLAVE_ADDR = 160
CMD_ONLINE_CHECK = 162
CMD_GET_ADDR_TABLE = 163
CMD_LOADER_TO_APP = 11
MODE_APP = 0
MODE_LOADER = 1
DEV_TYPE_MB = 1
DEV_TYPE_CLM = 2
DEV_TYPE_BTM = 3
DEV_TYPE_INDEX_OFFSET = DEV_TYPE_MB
POLY = 7
STATUS_OK = 0
ONLINE_STATE_OFFLINE = 0
ONLINE_STATE_ONLINE = 1
ONLINE_STATE_INIT = 2
ONLINE_STATE_WAIT_FOR_ACK = 3
MAX_GET_TIMES = 2
MAX_SET_TIMES = 2
TIMEOUT_SHORT_TIME = 0.05
TIMEOUT_MEDIUM_TIME = 0.1
TIMEOUT_LONG_TIME = 1
cmd_timeout = {
    CMD_LOADER_TO_APP: TIMEOUT_SHORT_TIME,
    CMD_ONLINE_CHECK: TIMEOUT_MEDIUM_TIME,
    CMD_GET_ADDR_TABLE: TIMEOUT_SHORT_TIME,
    CMD_SET_SLAVE_ADDR: TIMEOUT_SHORT_TIME,
    CMD_GET_SLAVE_INFO: TIMEOUT_LONG_TIME }
name_map = {
    DEV_TYPE_MB: 'mb_addr_table_uniids' }
DataPackage = dataclass(<NODE:12>)
FcAckData = dataclass(<NODE:12>)
AddrManager = dataclass(<NODE:12>)
addr_manager_table_mb = [
    AddrManager(1, [
        0], 0, 0, 0, 0, 0),
    AddrManager(2, [
        0], 0, 0, 0, 0, 0),
    AddrManager(3, [
        0], 0, 0, 0, 0, 0),
    AddrManager(4, [
        0], 0, 0, 0, 0, 0)]
addr_manager_table_cl_motor = [
    AddrManager(129, [
        0], 0, 0, 0, 0, 0),
    AddrManager(130, [
        0], 0, 0, 0, 0, 0),
    AddrManager(131, [
        0], 0, 0, 0, 0, 0),
    AddrManager(132, [
        0], 0, 0, 0, 0, 0)]
addr_manager_table_bt_motor = [
    AddrManager(145, [
        0], 0, 0, 0, 0, 0),
    AddrManager(146, [
        0], 0, 0, 0, 0, 0)]

class DevTableMap:
    
    def __init__(self, dev_type, broadcast_addr, addr_manager_table):
        self.dev_type = dev_type
        self.broadcast_addr = broadcast_addr
        self.addr_manager_table = addr_manager_table
        self.size = len(addr_manager_table)


dev_table_map_table = [
    DevTableMap(DEV_TYPE_MB, BROADCAST_ADDR_MB, addr_manager_table_mb)]

class AutoAddrWrapper:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        self.reactor = self.printer.get_reactor()
        self.configfile = self.printer.lookup_object('configfile')
        self.config = config
        self.gcode = self.printer.lookup_object('gcode')
        self._serial = self.printer.lookup_object('serial_485 serial485')
        self.debug = config.getint('debug', default=0, minval=0, maxval=1)
        self.uniid_changed = False
        self.print_stats = None
        self.gcode.register_command('PRINT_ADDR_TABLE', self.cmd_PRINT_ADDR_TABLE)
        for i in range(len(dev_table_map_table)):
            dev_table_map = dev_table_map_table[i]
            self.get_addr_table_uniids(dev_table_map)
        if config.has_section('motor_control') and config.getsection('motor_control').getint('switch') == 1:
            self.printer.register_event_handler('auto_addr:start', self.reg_auto_addr_set)
        else:
            self.printer.register_event_handler('klippy:ready', self.reg_auto_addr_set)
        self.printer.register_event_handler('auto_addr:set_finished', self.reg_auto_addr_process)
        self.dprintf('auto addr wrapper init')

    
    def get_addr_table_uniids(self, dev_table_map):
        name = name_map[dev_table_map.dev_type]
        if self.config.get(name, None) is not None:
            
            def custom_int_parser(value):
                
                try:
                    if value.startswith('0x') or value.startswith('0X'):
                        pass
                return None
                return int(value)
                except ValueError:
                    e = None
                    
                    try:
                        raise ValueError(f'''Invalid literal for int with base 10 or 16: \'{value}\''''), e
                    finally:
                        e = None
                        del e
                    e = None
                    del e
                    return None



            uniids = self.config.getlists(name, seps=(',', '\n'), parser=custom_int_parser)
            if len(uniids) != dev_table_map.size:
                self.dprintf('Error: %s, uniids len: %d, dev_table_map.size: %d' % (name, len(uniids), dev_table_map.size))
            else:
                self.dprintf('addr table uniid get %s' % name)
                for i in range(dev_table_map.size):
                    dev_table_map.addr_manager_table[i].uniid = list(uniids[i])
                    if len(uniids[i]) >= 1 and uniids[i][0] != 0:
                        dev_table_map.addr_manager_table[i].mapped = 1
                        dev_table_map.addr_manager_table[i].online = ONLINE_STATE_INIT
                    self.dprintf('addr %d: %s' % (dev_table_map.addr_manager_table[i].addr, dev_table_map.addr_manager_table[i].uniid))
        else:
            self.dprintf('Error: %s not exist' % name)

    
    def save_addr_table_uniids(self, dev_table_map):
        dev_type = dev_table_map.dev_type
        name = name_map[dev_type]
        self.dprintf('addr table uniid save %s' % name)
        uniids = ''
        for i in range(dev_table_map.size):
            uniids += '\n  '
            for j in range(len(dev_table_map.addr_manager_table[i].uniid)):
                uniids += '0x%02X, ' % dev_table_map.addr_manager_table[i].uniid[j]
            uniids = uniids[:-2]
        self.dprintf('uniids: %s' % uniids)
        section = 'auto_addr'
        self.configfile.set(section, name, uniids)
        self.gcode.run_script_from_command('CXSAVE_CONFIG')

    
    def cmd_PRINT_ADDR_TABLE(self, gcmd):
        for i in range(len(dev_table_map_table)):
            dev_table_map = dev_table_map_table[i]
            addr_manager_table = dev_table_map.addr_manager_table
            size = len(addr_manager_table)
            for i in range(size):
                response = '0x%02X, ' % addr_manager_table[i].addr
                for j in range(len(addr_manager_table[i].uniid)):
                    response += '0x%02X, ' % addr_manager_table[i].uniid[j]
                response += '%d, %d, %d, %d, mode:%d' % (addr_manager_table[i].mapped, addr_manager_table[i].online, addr_manager_table[i].acked, addr_manager_table[i].lost_cnt, addr_manager_table[i].mode)
                gcmd.respond_info(response)

    
    def addr_allocate(self, uniid, addr_manager_table):
