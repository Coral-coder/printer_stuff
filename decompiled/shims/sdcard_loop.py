# Source Generated with Decompyle++
# File: sdcard_loop.pyc (Python 3.9)

import logging

class SDCardLoop:
    
    def __init__(self, config):
        printer = config.get_printer()
        self.sdcard = printer.load_object(config, 'virtual_sdcard')
        self.gcode = printer.lookup_object('gcode')
        self.gcode.register_command('SDCARD_LOOP_BEGIN', self.cmd_SDCARD_LOOP_BEGIN, desc=self.cmd_SDCARD_LOOP_BEGIN_help)
        self.gcode.register_command('SDCARD_LOOP_END', self.cmd_SDCARD_LOOP_END, desc=self.cmd_SDCARD_LOOP_END_help)
        self.gcode.register_command('SDCARD_LOOP_DESIST', self.cmd_SDCARD_LOOP_DESIST, desc=self.cmd_SDCARD_LOOP_DESIST_help)
        self.loop_stack = []

    cmd_SDCARD_LOOP_BEGIN_help = 'Begins a looped section in the SD file.'
    
    def cmd_SDCARD_LOOP_BEGIN(self, gcmd):
        count = gcmd.get_int('COUNT', minval=0)
        if not self.loop_begin(count):
            raise gcmd.error('{"code":"key176", "msg": "Only permitted in SD file.", "values": []}')

    cmd_SDCARD_LOOP_END_help = 'Ends a looped section in the SD file.'
    
    def cmd_SDCARD_LOOP_END(self, gcmd):
        if not self.loop_end():
            raise gcmd.error('{"code":"key176", "msg": "Only permitted in SD file.", "values": []}')

    cmd_SDCARD_LOOP_DESIST_help = 'Stops iterating the current loop stack.'
    
    def cmd_SDCARD_LOOP_DESIST(self, gcmd):
        if not self.loop_desist():
            raise gcmd.error('{"code":"key177", "msg": "Only permitted outside of a SD file..", "values": []}')

    
    def loop_begin(self, count):
        if not self.sdcard.is_cmd_from_sd():
            return False
        self.loop_stack.append((count, self.sdcard.get_file_position()))
        return True

    
    def loop_end(self):
        if not self.sdcard.is_cmd_from_sd():
            return False
        if len(self.loop_stack) == 0:
            return True
        (count, position) = self.loop_stack.pop()
        if count == 0:
            self.sdcard.set_file_position(position)
            self.loop_stack.append((0, position))
        elif count == 1:
            pass
        else:
            self.sdcard.set_file_position(position)
            self.loop_stack.append((count - 1, position))
        return True

    
    def loop_desist(self):
        if self.sdcard.is_cmd_from_sd():
            return False
        logging.info('Desisting existing SD loops')
        self.loop_stack = []
        return True



def load_config(config):
    return SDCardLoop(config)

