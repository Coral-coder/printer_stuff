# =====================================================================
# PARTIAL DECOMPILATION -- this module did not fully round-trip.
# The 3.9 bytecode uses control flow the decompiler could not fully
# reconstruct (e.g. try/except/else with returns, or a generator with a
# dropped builtin rendered as `None(...)`). The code below is best-effort
# and will not import as-is. Ground-truth disassembly for repair:
#     decompiled/_disasm/skew_correction.txt
# =====================================================================

# Source Generated with Decompyle++
# File: skew_correction.pyc (Python 3.9)

import math

def calc_skew_factor(ac, bd, ad):
    side = math.sqrt(2 * ac * ac + 2 * bd * bd - 4 * ad * ad) / 2
    return math.tan(math.pi / 2 - math.acos((ac * ac - side * side - ad * ad) / (2 * side * ad)))


class PrinterSkew:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        self.name = config.get_name()
        self.toolhead = None
        self.xy_factor = 0
        self.xz_factor = 0
        self.yz_factor = 0
        self.skew_profiles = { }
        self._load_storage(config)
        self.printer.register_event_handler('klippy:connect', self._handle_connect)
        self.next_transform = None
        gcode = self.printer.lookup_object('gcode')
        gcode.register_command('GET_CURRENT_SKEW', self.cmd_GET_CURRENT_SKEW, desc=self.cmd_GET_CURRENT_SKEW_help)
        gcode.register_command('CALC_MEASURED_SKEW', self.cmd_CALC_MEASURED_SKEW, desc=self.cmd_CALC_MEASURED_SKEW_help)
        gcode.register_command('SET_SKEW', self.cmd_SET_SKEW, desc=self.cmd_SET_SKEW_help)
        gcode.register_command('SKEW_PROFILE', self.cmd_SKEW_PROFILE, desc=self.cmd_SKEW_PROFILE_help)

    
    def _handle_connect(self):
        gcode_move = self.printer.lookup_object('gcode_move')
        self.next_transform = gcode_move.set_move_transform(self, force=True)

    
    def _load_storage(self, config):
        stored_profs = config.get_prefix_sections(self.name)
        stored_profs = [ s for s in (stored_profs) if s.get_name() != self.name ]
        for profile in stored_profs:
            name = profile.get_name().split(' ', 1)[1]
            self.skew_profiles[name] = {
                'xy_skew': profile.getfloat('xy_skew'),
                'xz_skew': profile.getfloat('xz_skew'),
                'yz_skew': profile.getfloat('yz_skew') }

    
    def calc_skew(self, pos):
        skewed_x = pos[0] - pos[1] * self.xy_factor - pos[2] * (self.xz_factor - self.xy_factor * self.yz_factor)
        skewed_y = pos[1] - pos[2] * self.yz_factor
        return [
            skewed_x,
            skewed_y,
            pos[2],
            pos[3]]

    
    def calc_unskew(self, pos):
        skewed_x = pos[0] + pos[1] * self.xy_factor + pos[2] * self.xz_factor
        skewed_y = pos[1] + pos[2] * self.yz_factor
        return [
            skewed_x,
            skewed_y,
            pos[2],
            pos[3]]

    
    def get_position(self):
        return self.calc_unskew(self.next_transform.get_position())

    
    def move(self, newpos, speed):
        corrected_pos = self.calc_skew(newpos)
        self.next_transform.move(corrected_pos, speed)

    
    def _update_skew(self, xy_factor, xz_factor, yz_factor):
        self.xy_factor = xy_factor
        self.xz_factor = xz_factor
        self.yz_factor = yz_factor
        gcode_move = self.printer.lookup_object('gcode_move')
        gcode_move.reset_last_position()

    cmd_GET_CURRENT_SKEW_help = 'Report current printer skew'
    
    def cmd_GET_CURRENT_SKEW(self, gcmd):
        out = 'Current Printer Skew:'
        planes = [
            'XY',
            'XZ',
            'YZ']
        factors = [
            self.xy_factor,
            self.xz_factor,
            self.yz_factor]
        for plane, fac in zip(planes, factors):
            out += '\n' + plane
            out += ' Skew: %.6f radians, %.2f degrees' % (fac, math.degrees(fac))
        gcmd.respond_info(out)

    cmd_CALC_MEASURED_SKEW_help = 'Calculate skew from measured print'
    
    def cmd_CALC_MEASURED_SKEW(self, gcmd):
        ac = gcmd.get_float('AC', above=0)
        bd = gcmd.get_float('BD', above=0)
        ad = gcmd.get_float('AD', above=0)
        factor = calc_skew_factor(ac, bd, ad)
        gcmd.respond_info('Calculated Skew: %.6f radians, %.2f degrees' % (factor, math.degrees(factor)))

    cmd_SET_SKEW_help = 'Set skew based on lengths of measured object'
    
    def cmd_SET_SKEW(self, gcmd):
