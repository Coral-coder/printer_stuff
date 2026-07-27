# Source Generated with Decompyle++
# File: gcode_macro.pyc (Python 3.9)

import traceback
import logging
import ast
import copy
import jinja2

class GetStatusWrapper:
    
    def __init__(self, printer, eventtime = (None,)):
        self.printer = printer
        self.eventtime = eventtime
        self.cache = { }

    
    def __getitem__(self, val):
        sval = str(val).strip()
        if sval in self.cache:
            return self.cache[sval]
        po = None.printer.lookup_object(sval, None)
        if not po is None or hasattr(po, 'get_status'):
            raise KeyError(val)
        if self.eventtime is None:
            self.eventtime = self.printer.get_reactor().monotonic()
        self.cache[sval] = res = copy.deepcopy(po.get_status(self.eventtime))
        return res

    
    def __contains__(self, val):
        pass
    # WARNING: Decompyle incomplete

    
    def __iter__(self):
