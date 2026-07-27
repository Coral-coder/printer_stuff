# Source Generated with Decompyle++
# File: prtouch_v3.pyc (Python 3.9)

from . import prtouch_v3_wrapper
from . import probe as probes

def load_config(config):
    prtouch = prtouch_v3_wrapper.PRTouchEndstopWrapper(config)
    config.get_printer().add_object('axis_twist_compensation', prtouch)
    config.get_printer().add_object('probe', probes.PrinterProbe(config, prtouch))
    return prtouch

