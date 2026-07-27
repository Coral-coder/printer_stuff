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
        
        try:
            if not os.path.exists(self.filename):
                open(self.filename, 'w').close()
            self.loadVariables()
        except self.printer.command_error:
            e = None
            
            try:
                raise config.error(str(e))
            finally:
                e = None
                del e
            e = None
            del e
            gcode = self.printer.lookup_object('gcode')
            return None



    
    def loadVariables(self):
        allvars = { }
        varfile = configparser.ConfigParser()
        
        try:
            varfile.read(self.filename)
            if varfile.has_section('Variables'):
                for name, val in varfile.items('Variables'):
                    allvars[name] = ast.literal_eval(val)
        except:
            msg = '{"code": "key284", "msg": ""Unable to parse existing variable file", "values": []}'
            logging.exception(msg)
            raise self.printer.command_error(msg)

        self.allVariables = allvars

    cmd_SAVE_VARIABLE_help = 'Save arbitrary variables to disk'
    
    def cmd_SAVE_VARIABLE(self, gcmd):
        varname = gcmd.get('VARIABLE')
        value = gcmd.get('VALUE')
        
        try:
            value = ast.literal_eval(value)
        except ValueError:
            e = None
            
            try:
                raise gcmd.error('{"code": "key285", "msg": "Unable to parse \'%s\' as a literal", "values": ["%s"]}' % (value, value))
            finally:
                e = None
                del e
            e = None
            del e
            newvars = dict(self.allVariables)
            newvars[varname] = value
            varfile = configparser.ConfigParser()
            for name, val in sorted(newvars.items()):
                varfile.set('Variables', name, repr(val))
            
            try:
                f = open(self.filename, 'w')
                varfile.write(f)
                f.close()
            except:
                msg = '{"code": "key286", "msg": "Unable to save variable", "values": []}'
                logging.exception(msg)
                raise gcmd.error(msg)

            self.loadVariables()
            return None



    
    def get_status(self, eventtime):
        return {
            'variables': self.allVariables }



def load_config(config):
    return SaveVariables(config)

