# Source Generated with Decompyle++
# File: save_variables.pyc (Python 3.9)

import os
import logging
import ast
import configparser

class SaveVariables:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        self.filename = os.path.expanduser(config.get('filename'))
        self.allVariables = { }
    # WARNING: Decompyle incomplete

    
    def loadVariables(self):
        allvars = { }
        varfile = configparser.ConfigParser()
        
        try:
            varfile.read(self.filename)
            if varfile.has_section('Variables'):
                for name, val in varfile.items('Variables'):
                    allvars[name] = ast.literal_eval(val)
        finally:
            pass
        msg = '{"code": "key284", "msg": ""Unable to parse existing variable file", "values": []}'
        logging.exception(msg)
        raise self.printer.command_error(msg)
        self.allVariables = allvars
        return None


    cmd_SAVE_VARIABLE_help = 'Save arbitrary variables to disk'
    
    def cmd_SAVE_VARIABLE(self, gcmd):
        varname = gcmd.get('VARIABLE')
        value = gcmd.get('VALUE')
    # WARNING: Decompyle incomplete

    
    def get_status(self, eventtime):
        return {
            'variables': self.allVariables }



def load_config(config):
    return SaveVariables(config)

