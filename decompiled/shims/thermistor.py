# Source Generated with Decompyle++
# File: thermistor.pyc (Python 3.9)

import math
import logging
from . import adc_temperature
KELVIN_TO_CELSIUS = -273.15

class Thermistor:
    
    def __init__(self, pullup, inline_resistor):
        self.pullup = pullup
        self.inline_resistor = inline_resistor
        self.c1 = self.c2 = self.c3 = 0.0

    
    def setup_coefficients(self, t1, r1, t2, r2, t3, r3, name = ('',)):
        inv_t1 = 1.0 / (t1 - KELVIN_TO_CELSIUS)
        inv_t2 = 1.0 / (t2 - KELVIN_TO_CELSIUS)
        inv_t3 = 1.0 / (t3 - KELVIN_TO_CELSIUS)
        ln_r1 = math.log(r1)
        ln_r2 = math.log(r2)
        ln_r3 = math.log(r3)
        ln3_r1 = ln_r1 ** 3
        ln3_r2 = ln_r2 ** 3
        ln3_r3 = ln_r3 ** 3
        inv_t12 = inv_t1 - inv_t2
        inv_t13 = inv_t1 - inv_t3
        ln_r12 = ln_r1 - ln_r2
        ln_r13 = ln_r1 - ln_r3
        ln3_r12 = ln3_r1 - ln3_r2
        ln3_r13 = ln3_r1 - ln3_r3
        self.c3 = (inv_t12 - inv_t13 * ln_r12 / ln_r13) / (ln3_r12 - ln3_r13 * ln_r12 / ln_r13)
        if self.c3 <= 0.0:
            beta = ln_r13 / inv_t13
            logging.warn('Using thermistor beta %.3f in heater %s', beta, name)
            self.setup_coefficients_beta(t1, r1, beta)
            return None
        self.c2 = (inv_t12 - self.c3 * ln3_r12) / ln_r12
        self.c1 = inv_t1 - self.c2 * ln_r1 - self.c3 * ln3_r1

    
    def setup_coefficients_beta(self, t1, r1, beta):
        inv_t1 = 1.0 / (t1 - KELVIN_TO_CELSIUS)
        ln_r1 = math.log(r1)
        self.c3 = 0.0
        self.c2 = 1.0 / beta
        self.c1 = inv_t1 - self.c2 * ln_r1

    
    def calc_temp(self, adc):
        adc = max(1e-05, min(0.99999, adc))
        r = self.pullup * adc / (1.0 - adc)
        ln_r = math.log(r - self.inline_resistor)
        inv_t = self.c1 + self.c2 * ln_r + self.c3 * ln_r ** 3
        return 1.0 / inv_t + KELVIN_TO_CELSIUS

    
    def calc_adc(self, temp):
        if temp <= KELVIN_TO_CELSIUS:
            return 1.0
        inv_t = 1.0 / (temp - KELVIN_TO_CELSIUS)
        if self.c3:
            y = (self.c1 - inv_t) / (2.0 * self.c3)
            x = math.sqrt((self.c2 / (3.0 * self.c3)) ** 3 + y ** 2)
            ln_r = math.pow(x - y, 0.3333333333333333) - math.pow(x + y, 0.3333333333333333)
        else:
            ln_r = (inv_t - self.c1) / self.c2
        r = math.exp(ln_r) + self.inline_resistor
        return r / (self.pullup + r)



def PrinterThermistor(config, params):
    pullup = config.getfloat('pullup_resistor', 4.7e+03, above=0.0)
    inline_resistor = config.getfloat('inline_resistor', 0.0, minval=0.0)
    thermistor = Thermistor(pullup, inline_resistor)
    if 'beta' in params:
        thermistor.setup_coefficients_beta(params['t1'], params['r1'], params['beta'])
    else:
        thermistor.setup_coefficients(params['t1'], params['r1'], params['t2'], params['r2'], params['t3'], params['r3'], name=config.get_name())
    return adc_temperature.PrinterADCtoTemperature(config, thermistor)


class CustomThermistor:
    
    def __init__(self, config):
        self.name = ' '.join(config.get_name().split()[1:])
        t1 = config.getfloat('temperature1', minval=KELVIN_TO_CELSIUS)
        r1 = config.getfloat('resistance1', minval=0.0)
        beta = config.getfloat('beta', None, above=0.0)
        if beta is not None:
            self.params = {
                't1': t1,
                'r1': r1,
                'beta': beta }
            return None
        t2 = config.getfloat('temperature2', minval=KELVIN_TO_CELSIUS)
        r2 = config.getfloat('resistance2', minval=0.0)
        t3 = config.getfloat('temperature3', minval=KELVIN_TO_CELSIUS)
        r3 = config.getfloat('resistance3', minval=0.0)
        (t1, r1) = ()
        (t2, r2) = sorted([
            (t1, r1),
            (t2, r2),
            (t3, r3)])
        (t3, r3) = None
        self.params = {
            't1': t1,
            'r1': r1,
            't2': t2,
            'r2': r2,
            't3': t3,
            'r3': r3 }

    
    def create(self, config):
        return PrinterThermistor(config, self.params)



def load_config_prefix(config):
    thermistor = CustomThermistor(config)
    pheaters = config.get_printer().load_object(config, 'heaters')
    pheaters.add_sensor_factory(thermistor.name, thermistor.create)

