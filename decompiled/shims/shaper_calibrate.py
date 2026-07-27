# Source Generated with Decompyle++
# File: shaper_calibrate.pyc (Python 3.9)

import collections
import importlib
import logging
import math
import multiprocessing
import traceback
import os
import time
import subprocess
import shlex
from multiprocessing import shared_memory
shaper_defs = importlib.import_module('.shaper_defs', 'extras')
from base_info import base_dir
MIN_FREQ = 5
MAX_FREQ = 200
WINDOW_T_SEC = 0.5
MAX_SHAPER_FREQ = 150
TEST_DAMPING_RATIOS = [
    0.075,
    0.1,
    0.15]
AUTOTUNE_SHAPERS = [
    'zv',
    'mzv',
    'ei',
    '2hump_ei',
    '3hump_ei']

def exec_cmd(conn, method):
    
    try:
        val = os.nice(10)
    finally:
        pass
    
    try:
        process = subprocess.Popen(shlex.split(method), stdout=subprocess.PIPE)
        output = process.communicate()[0]
        retcode = process.poll()
    finally:
        pass
    retcode = -1
    conn.send((True, retcode))
    conn.close()
    return None
    if retcode is 0:
        conn.send((False, retcode))
    else:
        conn.send((True, retcode))


    conn.close()


class CalibrationData:
    
    def __init__(self, freq_bins, psd_sum, psd_x, psd_y, psd_z):
        self.freq_bins = freq_bins
        self.psd_sum = psd_sum
        self.psd_x = psd_x
        self.psd_y = psd_y
        self.psd_z = psd_z
        self._psd_list = [
            self.psd_sum,
            self.psd_x,
            self.psd_y,
            self.psd_z]
        self._psd_map = {
            'x': self.psd_x,
            'y': self.psd_y,
            'z': self.psd_z,
            'all': self.psd_sum }
        self.data_sets = 1

    
    def add_data(self, other):
        np = self.numpy
        joined_data_sets = self.data_sets + other.data_sets
        for psd, other_psd in zip(self._psd_list, other._psd_list):
            other_normalized = other.data_sets * np.interp(self.freq_bins, other.freq_bins, other_psd)
            psd *= self.data_sets
            psd[:] = (psd + other_normalized) * (1 / joined_data_sets)
        self.data_sets = joined_data_sets

    
    def set_numpy(self, numpy):
        self.numpy = numpy

    
    def normalize_to_frequencies(self):
        for psd in self._psd_list:
            psd /= self.freq_bins + 0.1
            psd[self.freq_bins < MIN_FREQ] = 0

    
    def get_psd(self, axis = ('all',)):
        return self._psd_map[axis]


CalibrationResult = collections.namedtuple('CalibrationResult', ('name', 'freq', 'vals', 'vibrs', 'smoothing', 'score', 'max_accel'))

class ShaperCalibrate:
    
    def __init__(self, printer):
        self.printer = printer
        self.error = printer.command_error if printer else Exception
        self.autotune_shapers = [
            'zv',
            'mzv',
            'ei',
            '2hump_ei',
            '3hump_ei']
        configfile = self.printer.lookup_object('configfile')
        gcode_macro_path = os.path.join(base_dir, 'printer_data/config/gcode_macro.cfg')
        gconfig = None
    # WARNING: Decompyle incomplete

    
    def background_process_exec(self, method, args):
        if self.printer is None:
            return method(*args)
        import queuelogger
        (parent_conn, child_conn) = multiprocessing.Pipe()
        
        def wrapper():
            
            try:
                gcode = self.printer.lookup_object('gcode')
                gcode.respond_info('current nice: %d' % os.nice(0), log=False)
                val = os.nice(10)
                gcode.respond_info('process id: %d, current nice: %d' % (os.getpid(), val), log=False)
            finally:
                pass
            gcode.respond_info('nice process failed', log=False)
            queuelogger.clear_bg_logging()
            
            try:
                res = method(*args)
            finally:
                pass
            child_conn.send((True, traceback.format_exc()))
            child_conn.close()
            return None
            child_conn.send((False, res))
            child_conn.close()
            return None



        calc_proc = multiprocessing.Process(target=wrapper)
        calc_proc.daemon = True
        calc_proc.start()
        reactor = self.printer.get_reactor()
        gcode = self.printer.lookup_object('gcode')
        eventtime = last_report_time = reactor.monotonic()
        if calc_proc.is_alive():
            if eventtime > last_report_time + 5:
                last_report_time = eventtime
                gcode.respond_info('Wait for calculations..', log=False)
            eventtime = reactor.pause(eventtime + 0.1)
            continue
        (is_err, res) = parent_conn.recv()
        if is_err:
            raise self.error('{"code": "key312", "msg": "Error in remote calculation: %s", "values":["%s"]}' % (res, res))
        calc_proc.join()
        parent_conn.close()
        return res

    
    def _split_into_windows(self, x, window_size, overlap):
        step_between_windows = window_size - overlap
        n_windows = (x.shape[-1] - overlap) // step_between_windows
        shape = (window_size, n_windows)
        strides = (x.strides[-1], step_between_windows * x.strides[-1])
        return self.numpy.lib.stride_tricks.as_strided(x, shape=shape, strides=strides, writeable=False)

    
    def _psd(self, x, fs, nfft):
        np = self.numpy
        window = np.kaiser(nfft, 6)
        scale = 1 / (window ** 2).sum()
        overlap = nfft // 2
        x = self._split_into_windows(x, nfft, overlap)
        x = window[(:, None)] * (x - np.mean(x, axis=0))
        result = np.fft.rfft(x, n=nfft, axis=0)
        result = np.conjugate(result) * result
        result *= scale / fs
        result[(1:-1, :)] *= 2
        psd = result.real.mean(axis=-1)
        freqs = np.fft.rfftfreq(nfft, 1 / fs)
        return (freqs, psd)

    
    def calc_freq_response(self, raw_values):
        np = self.numpy
        if raw_values is None:
            return None
        if None(raw_values, np.ndarray):
            data = raw_values
        else:
            samples = raw_values.get_samples()
            if not samples:
                return None
            data = None.array(samples)
        N = data.shape[0]
        T = data[(-1, 0)] - data[(0, 0)]
        SAMPLING_FREQ = N / T
        M = 1 << int(SAMPLING_FREQ * WINDOW_T_SEC - 1).bit_length()
        if N <= M:
            return None
        (fx, px) = None._psd(data[(:, 1)], SAMPLING_FREQ, M)
        (fy, py) = self._psd(data[(:, 2)], SAMPLING_FREQ, M)
        (fz, pz) = self._psd(data[(:, 3)], SAMPLING_FREQ, M)
        return CalibrationData(fx, px + py + pz, px, py, pz)

    
    def process_accelerometer_data(self, data):
        calibration_data = self.background_process_exec(self.calc_freq_response, (data,))
        if calibration_data is None:
            raise self.error('{"code": "key313", "msg": "Internal error processing accelerometer data %s", "values":["%s"]}' % (data, data))
        calibration_data.set_numpy(self.numpy)
        return calibration_data

    
    def lowmem_background_process_exec(self, method):
        if self.printer is None:
            return None
        ctx = None.get_context('spawn')
        (parent_conn, child_conn) = multiprocessing.Pipe()
        calc_proc = ctx.Process(target=exec_cmd, args=(child_conn, method))
        calc_proc.daemon = True
        calc_proc.start()
        reactor = self.printer.get_reactor()
        gcode = self.printer.lookup_object('gcode')
        eventtime = last_report_time = reactor.monotonic()
        if calc_proc.is_alive():
            if eventtime > last_report_time + 5:
                last_report_time = eventtime
                gcode.respond_info('Wait for calculations..')
            eventtime = reactor.pause(eventtime + 0.1)
            continue
        (is_err, res) = parent_conn.recv()
        if is_err:
            raise self.error('{"code": "key312", "msg": "Error in remote calculation: %s", "values":["%s"]}' % (res, res))
        calc_proc.join()
        parent_conn.close()
        return res

    
    def copy_samples_to_shared_memory(self, data):
        data.get_samples_to_shared_mem()

    
    def read_results_from_shared_memory(self, name):
        gcode = self.printer.lookup_object('gcode')
        
        try:
            shm = shared_memory.SharedMemory(name)
        finally:
            pass
        gcode.respond_info('open shared memory %s fail!' % name)
        return None
        np = self.numpy
        array = np.ndarray((shm.size // 8,), dtype=np.float64, buffer=shm.buf, offset=0)
        shm.unlink()
        return array.copy()


    
    def lowmem_process_accelerometer_data(self, data):
        gcode = self.printer.lookup_object('gcode')
        self.copy_samples_to_shared_memory(data)
        ret = self.lowmem_background_process_exec('/usr/bin/calc_psd')
        gcode.respond_info('calc_freq_response return (%d)' % ret)
        if ret is 0:
            fx = self.read_results_from_shared_memory('psm_freq')
            px = self.read_results_from_shared_memory('psm_px')
            py = self.read_results_from_shared_memory('psm_py')
            pz = self.read_results_from_shared_memory('psm_pz')
            calibration_data = CalibrationData(fx, px + py + pz, px, py, pz)
        else:
            calibration_data = None
        if calibration_data is None:
            raise self.error('{"code": "key313", "msg": "Internal error processing accelerometer data %s", "values":["%s"]}' % (data, data))
        calibration_data.set_numpy(self.numpy)
        return calibration_data

    
    def _estimate_shaper(self, shaper, test_damping_ratio, test_freqs):
        np = self.numpy
        A = np.array(shaper[0])
        T = np.array(shaper[1])
        inv_D = 1 / A.sum()
        omega = 2 * math.pi * test_freqs
        damping = test_damping_ratio * omega
        omega_d = omega * math.sqrt(1 - test_damping_ratio ** 2)
        W = A * np.exp(np.outer(-damping, T[-1] - T))
        S = W * np.sin(np.outer(omega_d, T))
        C = W * np.cos(np.outer(omega_d, T))
        return np.sqrt(S.sum(axis=1) ** 2 + C.sum(axis=1) ** 2) * inv_D

    
    def _estimate_remaining_vibrations(self, shaper, test_damping_ratio, freq_bins, psd):
        vals = self._estimate_shaper(shaper, test_damping_ratio, freq_bins)
        vibr_threshold = psd.max() / shaper_defs.SHAPER_VIBRATION_REDUCTION
        remaining_vibrations = self.numpy.maximum(vals * psd - vibr_threshold, 0).sum()
        all_vibrations = self.numpy.maximum(psd - vibr_threshold, 0).sum()
        return (remaining_vibrations / all_vibrations, vals)

    
    def _get_shaper_smoothing(self, shaper, accel, scv = (5000, 5)):
        half_accel = accel * 0.5
        (A, T) = shaper
        inv_D = 1 / sum(A)
        n = len(T)
        ts = None([ A[i] * T[i] for i in (range(n)) ]) * inv_D
        offset_90 = offset_180 = 0
        for i in range(n):
            if T[i] >= ts:
                offset_90 += A[i] * (scv + half_accel * (T[i] - ts)) * (T[i] - ts)
            offset_180 += A[i] * half_accel * (T[i] - ts) ** 2
        offset_90 *= inv_D * math.sqrt(2)
        offset_180 *= inv_D
        return max(offset_90, offset_180)

    
    def fit_shaper(self, shaper_cfg, calibration_data, max_smoothing):
