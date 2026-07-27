# =====================================================================
# PARTIAL DECOMPILATION -- this module did not fully round-trip.
# The 3.9 bytecode uses control flow the decompiler could not fully
# reconstruct (e.g. try/except/else with returns, or a generator with a
# dropped builtin rendered as `None(...)`). The code below is best-effort
# and will not import as-is. Ground-truth disassembly for repair:
#     decompiled/_disasm/tool.txt
# =====================================================================

# Source Generated with Decompyle++
# File: tool.pyc (Python 3.9)

import re
import os
import logging
import threading
from subprocess import call
import json
import random
import time
from extras.base_info import base_dir
from datetime import datetime

def send(msg, data = { }):
    time_str = datetime.now().strftime('%Y%m%d')
    if time_str < '20250101':
        return None
    pipeFilePath = os.path.join(base_dir, 'creality/gui/config/pipe-' + time_str + '.json')
    
    try:
        os.makedirs(os.path.dirname(pipeFilePath), exist_ok=True)
        ret = re.findall('key(\\d+)', msg)
        if ret:
            msg = 'key%s' % ret[0]
            send_data = {
                'reqId': str(int(time.time() * 1000)),
                'dn': '00000000000000',
                'code': msg,
                'data': data }
            with open(pipeFilePath, 'a') as f:
                f.write(json.dumps(send_data))
                f.write(chr(3))
                f.flush()
    except Exception as err:
        logging.error('reportInformation err:%s' % err)




def reportInformation(msg, data = { }):
    t = threading.Thread(target=send, args=(msg, data))
    t.start()


def compress_key701(code, data):
    if code == 'key701':
        
        try:
            data = data.get('jobs', [])[0] if data.get('jobs', []) else { }
            metadata = data.get('metadata', { })
            model_info = metadata.get('model_info', { })
            result = '%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s' % (
                data.get('end_time', 0), data.get('filament_used', 0), data.get('filename', ''), data.get('print_duration', 0),
                data.get('start_time', 0), data.get('status', ''), data.get('error_msg', ''), data.get('total_duration', 0),
                metadata.get('estimated_time', 0), metadata.get('filament_total', 0), metadata.get('filament_weight_total', 0), metadata.get('first_layer_bed_temp', 0), metadata.get('first_layer_extr_temp', 0),
                metadata.get('first_layer_height', 0), metadata.get('gcode_end_byte', 0), metadata.get('gcode_start_byte', 0), metadata.get('layer_count', 0),
                metadata.get('layer_height', 0), metadata.get('modified', 0), metadata.get('object_height', 0), metadata.get('size', 0),
                metadata.get('slicer', ''), metadata.get('slicer_version', ''), model_info.get('MaterialType', ''), model_info.get('MaterialName', ''),
                model_info.get('MAXX', 0), model_info.get('MAXY', 0), model_info.get('MAXZ', 0), model_info.get('MINX', 0), model_info.get('MINY', 0), model_info.get('MINZ', 0))
            return result
        except Exception as err:
            logging.exception(err)



