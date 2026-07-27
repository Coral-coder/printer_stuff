# Source Generated with Decompyle++
# File: input_shaper.pyc (Python 3.9)

import collections
import chelper
from . import shaper_defs

class InputShaperParams:
    
    def __init__(self, axis, config):
        self.axis = axis
        self.shapers = { s.name: s.init_func for s in (shaper_defs.INPUT_SHAPERS) }
        shaper_type = config.get('shaper_type', 'mzv')
        self.shaper_type = config.get('shaper_type_' + axis, shaper_type)
        if self.shaper_type not in self.shapers:
            raise config.error('{"code":"key24", "msg":"Unsupported shaper type: %s", "values": ["%s"]}' % (self.shaper_type, self.shaper_type))
        self.damping_ratio = config.getfloat('damping_ratio_' + axis, shaper_defs.DEFAULT_DAMPING_RATIO, minval=0, maxval=1)
        self.shaper_freq = config.getfloat('shaper_freq_' + axis, 0, minval=0)

    
    def update(self, gcmd):
        axis = self.axis.upper()
        self.damping_ratio = gcmd.get_float('DAMPING_RATIO_' + axis, self.damping_ratio, minval=0, maxval=1)
        self.shaper_freq = gcmd.get_float('SHAPER_FREQ_' + axis, self.shaper_freq, minval=0)
        shaper_type = gcmd.get('SHAPER_TYPE', None)
        if shaper_type is None:
            shaper_type = gcmd.get('SHAPER_TYPE_' + axis, self.shaper_type)
        if shaper_type.lower() not in self.shapers:
            raise gcmd.error('{"code":"key24", "msg":"Unsupported shaper type: %s", "values": ["%s"]}' % (shaper_type, shaper_type))
        self.shaper_type = shaper_type.lower()

    
    def get_shaper(self):
        if not self.shaper_freq:
            (A, T) = shaper_defs.get_none_shaper()
        else:
            (A, T) = self.shapers[self.shaper_type](self.shaper_freq, self.damping_ratio)
        return (len(A), A, T)

    
    def get_status(self):
        return collections.OrderedDict([
            ('shaper_type', self.shaper_type),
            ('shaper_freq', '%.3f' % (self.shaper_freq,)),
            ('damping_ratio', '%.6f' % (self.damping_ratio,))])



class AxisInputShaper:
    
    def __init__(self, axis, config):
        self.axis = axis
        self.params = InputShaperParams(axis, config)
        (self.n, self.A, self.T) = self.params.get_shaper()
        self.saved = None

    
    def get_name(self):
        return 'shaper_' + self.axis

    
    def get_shaper(self):
        return (self.n, self.A, self.T)

    
    def update(self, gcmd):
        self.params.update(gcmd)
        old_n = self.n
        old_A = self.A
        old_T = self.T
        (self.n, self.A, self.T) = self.params.get_shaper()
        return (old_n, old_A, old_T) != (self.n, self.A, self.T)

    
    def set_shaper_kinematics(self, sk):
        (ffi_main, ffi_lib) = chelper.get_ffi()
        success = ffi_lib.input_shaper_set_shaper_params(sk, self.axis.encode(), self.n, self.A, self.T) == 0
        if not success:
            self.disable_shaping()
            ffi_lib.input_shaper_set_shaper_params(sk, self.axis.encode(), self.n, self.A, self.T)
        return success

    
    def get_step_generation_window(self):
        (ffi_main, ffi_lib) = chelper.get_ffi()
        return ffi_lib.input_shaper_get_step_generation_window(self.n, self.A, self.T)

    
    def disable_shaping(self):
        if self.saved is None and self.n:
            self.saved = (self.n, self.A, self.T)
        (A, T) = shaper_defs.get_none_shaper()
        self.n = len(A)
        self.A = A
        self.T = T

    
    def enable_shaping(self):
        if self.saved is None:
            return None
        (self.n, self.A, self.T) = None.saved
        self.saved = None

    
    def report(self, gcmd):
        info = None([ '%s_%s:%s' % (key, self.axis, value) for key, value in (self.params.get_status().items()) ])
        gcmd.respond_info(info)



class InputShaper:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        self.printer.register_event_handler('klippy:connect', self.connect)
        self.toolhead = None
        self.shapers = [
            AxisInputShaper('x', config),
            AxisInputShaper('y', config)]
        self.stepper_kinematics = []
        self.orig_stepper_kinematics = []
        gcode = self.printer.lookup_object('gcode')
        gcode.register_command('SET_INPUT_SHAPER', self.cmd_SET_INPUT_SHAPER, desc=self.cmd_SET_INPUT_SHAPER_help)
        gcode.register_command('UPDATE_INPUT_SHAPER', self.cmd_UPDATE_INPUT_SHAPER, desc=self.cmd_UPDATE_INPUT_SHAPER_help)

    
    def get_shapers(self):
        return self.shapers

    
    def connect(self):
        self.toolhead = self.printer.lookup_object('toolhead')
        kin = self.toolhead.get_kinematics()
        (ffi_main, ffi_lib) = chelper.get_ffi()
        steppers = kin.get_steppers()
        for s in steppers:
            sk = ffi_main.gc(ffi_lib.input_shaper_alloc(), ffi_lib.free)
            orig_sk = s.set_stepper_kinematics(sk)
            res = ffi_lib.input_shaper_set_sk(sk, orig_sk)
            if res < 0:
                s.set_stepper_kinematics(orig_sk)
                continue
            self.stepper_kinematics.append(sk)
            self.orig_stepper_kinematics.append(orig_sk)
        self.old_delay = 0
        self._update_input_shaping(error=self.printer.config_error)

    
    def _update_input_shaping(self, error = (None,)):
