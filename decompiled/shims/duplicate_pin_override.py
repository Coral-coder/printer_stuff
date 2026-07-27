# Source Generated with Decompyle++
# File: duplicate_pin_override.pyc (Python 3.9)


class PrinterDupPinOverride:
    
    def __init__(self, config):
        printer = config.get_printer()
        ppins = printer.lookup_object('pins')
        for pin_desc in config.getlist('pins'):
            ppins.allow_multi_use_pin(pin_desc)



def load_config(config):
    return PrinterDupPinOverride(config)

