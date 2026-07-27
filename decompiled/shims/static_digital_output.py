# Source Generated with Decompyle++
# File: static_digital_output.pyc (Python 3.9)


class PrinterStaticDigitalOut:
    
    def __init__(self, config):
        printer = config.get_printer()
        ppins = printer.lookup_object('pins')
        pin_list = config.getlist('pins')
        for pin_desc in pin_list:
            mcu_pin = ppins.setup_pin('digital_out', pin_desc)
            mcu_pin.setup_start_value(1, 1, True)



def load_config_prefix(config):
    return PrinterStaticDigitalOut(config)

