# Source Generated with Decompyle++
# File: heater_generic.pyc (Python 3.9)


def load_config_prefix(config):
    pheaters = config.get_printer().load_object(config, 'heaters')
    return pheaters.setup_heater(config)

