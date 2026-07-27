# Source Generated with Decompyle++
# File: pid_calibrate.pyc (Python 3.9)

import math
import logging
from . import heaters

class PIDCalibrate:
    
    def __init__(self, config):
        self.config = config
        self.printer = config.get_printer()
        gcode = self.printer.lookup_object('gcode')
        gcode.register_command('PID_CALIBRATE', self.cmd_PID_CALIBRATE, desc=self.cmd_PID_CALIBRATE_help)

    cmd_PID_CALIBRATE_help = 'Run PID calibration test'
    
    def cmd_PID_CALIBRATE(self, gcmd):
        heater_name = gcmd.get('HEATER')
        target = gcmd.get_float('TARGET')
        write_file = gcmd.get_int('WRITE_FILE', 0)
        pheaters = self.printer.lookup_object('heaters')
    # WARNING: Decompyle incomplete


TUNE_PID_DELTA = 5

class ControlAutoTune:
    
    def __init__(self, heater, target):
        self.heater = heater
        self.heater_max_power = heater.get_max_power()
        self.calibrate_temp = target
        self.heating = False
        self.peak = 0
        self.peak_time = 0
        self.peaks = []
        self.last_pwm = 0
        self.pwm_samples = []
        self.temp_samples = []

    
    def set_pwm(self, read_time, value):
        if value != self.last_pwm:
            self.pwm_samples.append((read_time + self.heater.get_pwm_delay(), value))
            self.last_pwm = value
        self.heater.set_pwm(read_time, value)

    
    def temperature_update(self, read_time, temp, target_temp):
        self.temp_samples.append((read_time, temp))
        if self.heating and temp >= target_temp:
            self.heating = False
            self.check_peaks()
            self.heater.alter_target(self.calibrate_temp - TUNE_PID_DELTA)
        elif self.heating and temp <= target_temp:
            self.heating = True
            self.check_peaks()
            self.heater.alter_target(self.calibrate_temp)
        if self.heating:
            self.set_pwm(read_time, self.heater_max_power)
            if temp < self.peak:
                self.peak = temp
                self.peak_time = read_time
            else:
                self.set_pwm(read_time, 0)
                if temp > self.peak:
                    self.peak = temp
                    self.peak_time = read_time

    
    def check_busy(self, eventtime, smoothed_temp, target_temp):
        if self.heating or len(self.peaks) < 12:
            return True

    
    def check_peaks(self):
        self.peaks.append((self.peak, self.peak_time))
        if self.heating:
            self.peak = 1e+07
        else:
            self.peak = -1e+07
        if len(self.peaks) < 4:
            return None
        None.calc_pid(len(self.peaks) - 1)

    
    def calc_pid(self, pos):
        temp_diff = self.peaks[pos][0] - self.peaks[pos - 1][0]
        time_diff = self.peaks[pos][1] - self.peaks[pos - 2][1]
        amplitude = 0.5 * abs(temp_diff)
        Ku = 4 * self.heater_max_power / (math.pi * amplitude)
        Tu = time_diff
        Ti = 0.5 * Tu
        Td = 0.125 * Tu
        Kp = 0.6 * Ku * heaters.PID_PARAM_BASE
        Ki = Kp / Ti
        Kd = Kp * Td
        logging.info('Autotune: raw=%f/%f Ku=%f Tu=%f  Kp=%f Ki=%f Kd=%f', temp_diff, self.heater_max_power, Ku, Tu, Kp, Ki, Kd)
        return (Kp, Ki, Kd)

    
    def calc_final_pid(self):
        cycle_times = [ (self.peaks[pos][1] - self.peaks[pos - 2][1], pos) for pos in (range(4, len(self.peaks))) ]
        midpoint_pos = sorted(cycle_times)[len(cycle_times) // 2][1]
        return self.calc_pid(midpoint_pos)

    
    def write_file(self, filename):
        pwm = (lambda .0: [ 'pwm: %.3f %.3f' % (time, value) for time, value in .0 ])(self.pwm_samples)
        out = (lambda .0: [ '%.3f %.3f' % (time, temp) for time, temp in .0 ])(self.temp_samples)
        f = open(filename, 'w')
        f.write('\n'.join(pwm + out))
        f.close()



def load_config(config):
    return PIDCalibrate(config)

