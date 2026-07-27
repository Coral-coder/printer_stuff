# =====================================================================
# PARTIAL DECOMPILATION -- this module did not fully round-trip.
# The 3.9 bytecode uses control flow the decompiler could not fully
# reconstruct (e.g. try/except/else with returns, or a generator with a
# dropped builtin rendered as `None(...)`). The code below is best-effort
# and will not import as-is. Ground-truth disassembly for repair:
#     decompiled/_disasm/custom_macro.txt
# =====================================================================

# Source Generated with Decompyle++
# File: custom_macro.pyc (Python 3.9)

import time

class CUSTOM_MACRO:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        self.gcode = self.printer.lookup_object('gcode')
        self.pheaters = None
        self.heater_hot = None
        self.extruder_temp = None
        self.bed_temp = None
        self.prtouch = None
        self.gcode.register_command('CX_PRINT_LEVELING_CALIBRATION', self.cmd_CX_PRINT_LEVELING_CALIBRATION, desc=self.cmd_CX_PRINT_LEVELING_CALIBRATION_help)
        self.gcode.register_command('CX_CLEAN_CALIBRATION_FLAGS', self.cmd_CX_CLEAN_CALIBRATION_FLAGS, desc=self.cmd_CX_CLEAN_CALIBRATION_FLAGS_help)
        self.gcode.register_command('CX_PRINT_DRAW_ONE_LINE', self.cmd_CX_PRINT_DRAW_ONE_LINE, desc=self.cmd_CX_PRINT_DRAW_ONE_LINE_help)
        self.gcode.register_command('CX_ROUGH_G28', self.cmd_CX_ROUGH_G28, desc=self.cmd_CX_ROUGH_G28_help)
        self.gcode.register_command('CX_NOZZLE_CLEAR', self.cmd_CX_NOZZLE_CLEAR, desc=self.cmd_CX_NOZZLE_CLEAR_help)
        self.default_extruder_temp = config.getfloat('default_extruder_temp', default=240)
        self.default_bed_temp = config.getfloat('default_bed_temp', default=50)
        self.g28_ext_temp = config.getfloat('g28_ext_temp', default=140)
        self.nozzle_clear = config.getboolean('nozzle_clear', True)
        self.calibration = config.getint('calibration', default=0)
        self.leveling_calibration = 0
        self.qmode_flag = 0
        self.gcode.register_command('SET_QMODE_FLAG', self.cmd_SET_QMODE_FLAG, desc=self.cmd_SET_QMODE_FLAG_help)

    
    def get_status(self, eventtime):
        return {
            'leveling_calibration': self.leveling_calibration,
            'default_extruder_temp': self.default_extruder_temp,
            'default_bed_temp': self.default_bed_temp,
            'g28_ext_temp': self.g28_ext_temp,
            'qmode_flag': self.qmode_flag }

    cmd_CX_PRINT_LEVELING_CALIBRATION_help = 'Start Print function,three parameter:EXTRUDER_TEMP(180-300),BED_TEMP(0-100),CALIBRATION(0 or 1)'
    
    def cmd_CX_PRINT_LEVELING_CALIBRATION(self, gcmd):
        self.gcode.run_script_from_command('CHECK_BED_MESH AUTO_G29=1')

    cmd_CX_CLEAN_CALIBRATION_FLAGS_help = 'Clean calibration flags'
    
    def cmd_CX_CLEAN_CALIBRATION_FLAGS(self, gcmd):
        self.leveling_calibration = 0

    cmd_CX_PRINT_DRAW_ONE_LINE_help = 'Draw one line before printing'
    
    def cmd_CX_PRINT_DRAW_ONE_LINE(self, gcmd):
        self.gcode.run_script_from_command('G28 X Y')
        self.gcode.run_script_from_command('M83')
        self.gcode.run_script_from_command('G1 X10 Y10 Z2 F6000')
        self.gcode.run_script_from_command('G1 Z0.1 F600')
        self.pheaters = self.printer.lookup_object('heaters')
        self.heater_hot = self.printer.lookup_object('extruder').heater
        self.gcode.respond_info('can_break_flag = %d' % self.pheaters.can_break_flag)
        self.gcode.run_script_from_command('M104 S%d' % self.extruder_temp)
        self.gcode.run_script_from_command('M140 S%d' % self.bed_temp)
        self.pheaters.set_temperature(self.heater_hot, self.extruder_temp, True)
        self.gcode.respond_info('can_break_flag = %d' % self.pheaters.can_break_flag)
        if self.pheaters.can_break_flag == 1:
            time.sleep(1)
            continue
        self.gcode.respond_info('can_break_flag = %d' % self.pheaters.can_break_flag)
        if self.pheaters.can_break_flag == 3:
            self.pheaters.can_break_flag = 0
            self.gcode.respond_info('can_break_flag is 3')
            self.gcode.run_script_from_command('G21')
            self.gcode.run_script_from_command('G1 F2400 E-0.5')
            self.gcode.run_script_from_command('SET_VELOCITY_LIMIT SQUARE_CORNER_VELOCITY=5')
            self.gcode.run_script_from_command('M204 S12000')
            self.gcode.run_script_from_command('G21')
            self.gcode.run_script_from_command('SET_VELOCITY_LIMIT AC