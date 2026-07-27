# Source Generated with Decompyle++
# File: prtouch_v2.pyc (Python 3.9)

from . import probe
from . import prtouch_v2_wrapper
from . import prtouch_v1_wrapper

def load_config(config):
    pr_version = config.getint('pr_version', default=1, minval=0, maxval=100)
    if pr_version == 2:
        vrt = prtouch_v2_wrapper.PRTouchEndstopWrapper(config)
    if pr_version == 1:
        vrt = prtouch_v1_wrapper.PRTouchEndstopWrapper(config)
    config.get_printer().add_object('probe', probe.PrinterProbe(config, vrt))
    return vrt

