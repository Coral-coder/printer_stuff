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
