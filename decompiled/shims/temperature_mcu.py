# Source Generated with Decompyle++
# File: temperature_mcu.pyc (Python 3.9)

import logging
import mcu
SAMPLE_TIME = 0.001
SAMPLE_COUNT = 8
REPORT_TIME = 0.3
RANGE_CHECK_COUNT = 4

class PrinterTemperatureMCU:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        self.base_temperature = self.slope = None
        self.temp1 = self.adc1 = self.temp2 = self.adc2 = None
        self.min_temp = self.max_temp = 0.0
        self.debug_read_cmd = None
        mcu_name = config.get('sensor_mcu', 'mcu')
        self.temp1 = config.getfloat('sensor_temperature1', None)
        if self.temp1 is not None:
            self.adc1 = config.getfloat('sensor_adc1', minval=0.0, maxval=1.0)
            self.temp2 = config.getfloat('sensor_temperature2', None)
            if self.temp2 is not None:
                self.adc2 = config.getfloat('sensor_adc2', minval=0.0, maxval=1.0)
        ppins = config.get_printer().lookup_object('pins')
        self.mcu_adc = ppins.setup_pin('adc', '%s:ADC_TEMPERATURE' % (mcu_name,))
        self.mcu_adc.setup_adc_callback(REPORT_TIME, self.adc_callback)
        query_adc = config.get_printer().load_object(config, 'query_adc')
        query_adc.register_adc(config.get_name(), self.mcu_adc)
        if self.printer.get_start_args().get('debugoutput') is not None:
            self.mcu_adc.setup_minmax(SAMPLE_TIME, SAMPLE_COUNT, range_check_count=RANGE_CHECK_COUNT)
            return None
        self.printer.register_event_handler('klippy:mcu_identify', self._mcu_identify)

    
    def setup_callback(self, temperature_callback):
        self.temperature_callback = temperature_callback

    
    def get_report_time_delta(self):
        return REPORT_TIME

    
    def adc_callback(self, read_time, read_value):
        temp = self.base_temperature + read_value * self.slope
        self.temperature_callback(read_time + SAMPLE_COUNT * SAMPLE_TIME, temp)

    
    def setup_minmax(self, min_temp, max_temp):
        self.min_temp = min_temp
        self.max_temp = max_temp

    
    def calc_adc(self, temp):
        return (temp - self.base_temperature) / self.slope

    
    def calc_base(self, temp, adc):
        return temp - adc * self.slope

    
    def _mcu_identify(self):
        mcu = self.mcu_adc.get_mcu()
        self.debug_read_cmd = mcu.lookup_query_command('debug_read order=%c addr=%u', 'debug_result val=%u')
        self.mcu_type = mcu.get_constants().get('MCU', '')
        cfg_funcs = [
            ('rp2040', self.config_rp2040),
            ('sam3', self.config_sam3),
            ('sam4', self.config_sam4),
            ('same70', self.config_same70),
            ('samd21', self.config_samd21),
            ('samd51', self.config_samd51),
            ('same5', self.config_samd51),
            ('stm32f1', self.config_stm32f1),
            ('stm32f2', self.config_stm32f2),
            ('stm32f4', self.config_stm32f4),
            ('stm32f042', self.config_stm32f0x2),
            ('stm32f070', self.config_stm32f070),
            ('stm32f072', self.config_stm32f0x2),
            ('stm32g0', self.config_stm32g0),
            ('stm32g4', self.config_stm32g0),
            ('stm32l4', self.config_stm32g0),
            ('stm32h723', self.config_stm32h723),
            ('stm32h7', self.config_stm32h7),
            ('gd32f303xe', self.config_gd32f303xe),
            ('', self.config_unknown)]
        for name, func in cfg_funcs:
            if self.mcu_type.startswith(name):
                func()
                break
        logging.info("mcu_temperature '%s' nominal base=%.6f slope=%.6f", mcu.get_name(), self.base_temperature, self.slope)
        if self.temp1 is not None:
            if self.temp2 is not None:
                self.slope = (self.temp2 - self.temp1) / (self.adc2 - self.adc1)
            self.base_temperature = self.calc_base(self.temp1, self.adc1)
        adc_range = [ self.calc_adc(t) for t in ((self.min_temp, self.max_temp)) ]
        self.mcu_adc.setup_minmax(SAMPLE_TIME, SAMPLE_COUNT, minval=min(adc_range), maxval=max(adc_range), range_check_count=RANGE_CHECK_COUNT)

    
    def config_unknown(self):
        raise self.printer.config_error('MCU temperature not supported on %s' % (self.mcu_type,))

    
    def config_rp2040(self):
        self.slope = -1917.4898314933175
        self.base_temperature = self.calc_base(27.0, 0.21393939393939393)

    
    def config_sam3(self):
        self.slope = 1245.2830188679245
        self.base_temperature = self.calc_base(27.0, 0.24242424242424246)

    
    def config_sam4(self):
        self.slope = 702.127659574468
        self.base_temperature = self.calc_base(27.0, 0.4363636363636364)

    
    def config_same70(self):
        self.slope = 1416.3090128755364
        self.base_temperature = self.calc_base(25.0, 0.2181818181818182)

    
    def config_samd21(self, addr = 8413232):
        
        def get1v(val):
            if val & 128:
                val = val - 256
            return 1.0 - val / 1e+03

        cal1 = self.read32(addr)
        cal2 = self.read32(addr + 4)
        room_temp = (cal1 >> 0 & 255) + (cal1 >> 8 & 15) / 1e+01
        hot_temp = (cal1 >> 12 & 255) + (cal1 >> 20 & 15) / 1e+01
        room_1v = get1v(cal1 >> 24 & 255)
        hot_1v = get1v(cal2 >> 0 & 255)
        room_adc = (cal2 >> 8 & 4095) * room_1v / 13513.5
        hot_adc = (cal2 >> 20 & 4095) * hot_1v / 13513.5
        self.slope = (hot_temp - room_temp) / (hot_adc - room_adc)
        self.base_temperature = self.calc_base(room_temp, room_adc)

    
    def config_samd51(self):
        self.config_samd21(addr=8388864)

    
    def config_stm32f1(self):
        self.slope = -767.4418604651163
        self.base_temperature = self.calc_base(25.0, 0.43333333333333335)

    
    def config_stm32f2(self):
        self.slope = 1.32e+03
        self.base_temperature = self.calc_base(25.0, 0.23030303030303031)

    
    def config_stm32f4(self, addr1 = 536836652, addr2 = 536836654):
        cal_adc_30 = self.read16(addr1) / 4095.0
        cal_adc_110 = self.read16(addr2) / 4095.0
        self.slope = 8e+01 / (cal_adc_110 - cal_adc_30)
        self.base_temperature = self.calc_base(3e+01, cal_adc_30)

    
    def config_stm32f0x2(self):
        self.config_stm32f4(addr1=536868792, addr2=536868802)

    
    def config_stm32f070(self):
        self.slope = -767.4418604651163
        cal_adc_30 = self.read16(536868792) / 4095.0
        self.base_temperature = self.calc_base(3e+01, cal_adc_30)

    
    def config_stm32g0(self):
        cal_adc_30 = self.read16(536835496) * 3.0 / 13513.5
        cal_adc_130 = self.read16(536835530) * 3.0 / 13513.5
        self.slope = 1e+02 / (cal_adc_130 - cal_adc_30)
        self.base_temperature = self.calc_base(3e+01, cal_adc_30)

    
    def config_stm32h723(self):
        cal_adc_30 = self.read16(535947296) / 4095.0
        cal_adc_130 = self.read16(535947328) / 4095.0
        self.slope = 1e+02 / (cal_adc_130 - cal_adc_30)
        self.base_temperature = self.calc_base(3e+01, cal_adc_30)

    
    def config_stm32h7(self):
        cal_adc_30 = self.read16(535947296) / 65535.0
        cal_adc_110 = self.read16(535947328) / 65535.0
        self.slope = 8e+01 / (cal_adc_110 - cal_adc_30)
        self.base_temperature = self.calc_base(3e+01, cal_adc_30)

    
    def config_gd32f303xe(self):
        self.slope = -804.8780487804877
        self.base_temperature = self.calc_base(25.0, 0.4393939393939394)

    
    def read16(self, addr):
        params = self.debug_read_cmd.send([
            1,
            addr])
        return params['val']

    
    def read32(self, addr):
        params = self.debug_read_cmd.send([
            2,
            addr])
        return params['val']



def load_config(config):
    pheaters = config.get_printer().load_object(config, 'heaters')
    pheaters.add_sensor_factory('temperature_mcu', PrinterTemperatureMCU)

