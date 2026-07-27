# Source Generated with Decompyle++
# File: board_pins.pyc (Python 3.9)


class PrinterBoardAliases:
    
    def __init__(self, config):
        ppins = config.get_printer().lookup_object('pins')
        mcu_names = config.getlist('mcu', ('mcu',))
        pin_resolvers = [ ppins.get_pin_resolver(n) for n in (mcu_names) ]
        options = [
            'aliases'] + config.get_prefix_options('aliases_')
        for opt in options:
            aliases = config.getlists(opt, seps=('=', ','), count=2)
            for name, value in aliases:
                if value.startswith('<') and value.endswith('>'):
                    for pin_resolver in pin_resolvers:
                        pin_resolver.reserve_pin(name, value)
                    continue
                for pin_resolver in pin_resolvers:
                    pin_resolver.alias_pin(name, value)



def load_config(config):
    return PrinterBoardAliases(config)


def load_config_prefix(config):
    return PrinterBoardAliases(config)

