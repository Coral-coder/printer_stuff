# =====================================================================
# PARTIAL DECOMPILATION -- this module did not fully round-trip.
# The 3.9 bytecode uses control flow the decompiler could not fully
# reconstruct (e.g. try/except/else with returns, or a generator with a
# dropped builtin rendered as `None(...)`). The code below is best-effort
# and will not import as-is. Ground-truth disassembly for repair:
#     decompiled/_disasm/shaper_calibrate.txt
# =====================================================================

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
from .base_info import base_dir
MIN_FREQ = 5.0
MAX_FREQ = 2e+02
WINDOW_T_SEC = 0.5
MAX_SHAPER_FREQ = 1.5e+02
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
    except:
        pass

    
    try:
        process = subprocess.Popen(shlex.split(method), stdout=subprocess.PIPE)
        output = process.communicate()[0]
        retcode = process.poll()
    except:
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
            psd[:] = (psd + other_normalized) * (1.0 / joined_data_sets)
        self.data_sets = joined_data_sets

    
    def set_numpy(self, numpy):
        self.numpy = numpy

    
    def normalize_to_frequencies(self):
        for psd in self._psd_list:
            psd /= self.freq_bins + 0.1
            psd[self.freq_bins < MIN_FREQ] = 0.0

    
    def get_psd(self, axis = 'all'):
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
        
        try:
            gconfig = configfile.read_config(gcode_macro_path)
            if gconfig and gconfig.has_section('gcode_macro AUTOTUNE_SHAPERS'):
                AUTOTUNE_SHAPERS = gconfig.getsection('gcode_macro AUTOTUNE_SHAPERS')
                self.autotune_shapers = list(map((lambda x: x.replace("'", '')), AUTOTUNE_SHAPERS.getlist('variable_autotune_shapers', [
                    'zv',
                    'mzv',
                    'ei',
                    '2hump_ei',
                    '3hump_ei'])))
        except Exception as err:
            logging.error('gcode_macro_path: %s, configfile.read_config error:%s' % (gcode_macro_path, err))
        try:
            self.numpy = importlib.import_module('numpy')
        except ImportError:
            raise self.error('Failed to import `numpy` module, make sure it was installed via `~/klippy-env/bin/pip install` (refer to docs/Measuring_Resonances.md for more details).')



    
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
            except:
                gcode.respond_info('nice process failed', log=False)

            queuelogger.clear_bg_logging()
            
            try:
                res = method(*args)
            except:
                child_conn.send((True, traceback.format_exc()))
                child_conn.close()
                return None

            child_conn.send((False, res))
            child_conn.close()

        calc_proc = multiprocessing.Process(target=wrapper)
        calc_proc.daemon = True
        calc_proc.start()
        reactor = self.printer.get_reactor()
        gcode = self.printer.lookup_object('gcode')
        eventtime = last_report_time = reactor.monotonic()
        while calc_proc.is_alive():
            if eventtime > last_report_time + 5.0:
                last_report_time = eventtime
                gcode.respond_info('Wait for calculations..', log=False)
            eventtime = reactor.pause(eventtime + 0.1)
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
        window = np.kaiser(nfft, 6.0)
        scale = 1.0 / (window ** 2).sum()
        overlap = nfft // 2
        x = self._split_into_windows(x, nfft, overlap)
        x = window[:, None] * (x - np.mean(x, axis=0))
        result = np.fft.rfft(x, n=nfft, axis=0)
        result = np.conjugate(result) * result
        result *= scale / fs
        result[1:-1, :] *= 2.0
        psd = result.real.mean(axis=-1)
        freqs = np.fft.rfftfreq(nfft, 1.0 / fs)
        return (freqs, psd)

    
    def calc_freq_response(self, raw_values):
        np = self.numpy
        if raw_values is None:
            return None
        if isinstance(raw_values, np.ndarray):
            data = raw_values
        else:
            samples = raw_values.get_samples()
            if not samples:
                return None
            data = np.array(samples)
        N = data.shape[0]
        T = data[(-1, 0)] - data[(0, 0)]
        SAMPLING_FREQ = N / T
        M = 1 << int(SAMPLING_FREQ * WINDOW_T_SEC - 1).bit_length()
        if N <= M:
            return None
        (fx, px) = self._psd(data[:, 1], SAMPLING_FREQ, M)
        (fy, py) = self._psd(data[:, 2], SAMPLING_FREQ, M)
        (fz, pz) = self._psd(data[:, 3], SAMPLING_FREQ, M)
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
        ctx = multiprocessing.get_context('spawn')
        (parent_conn, child_conn) = multiprocessing.Pipe()
        calc_proc = ctx.Process(target=exec_cmd, args=(child_conn, method))
        calc_proc.daemon = True
        calc_proc.start()
        reactor = self.printer.get_reactor()
        gcode = self.printer.lookup_object('gcode')
        eventtime = last_report_time = reactor.monotonic()
        while calc_proc.is_alive():
            if eventtime > last_report_time + 5.0:
                last_report_time = eventtime
                gcode.respond_info('Wait for calculations..')
            eventtime = reactor.pause(eventtime + 0.1)
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
        except:
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
        A, T = np.array(shaper[0]), np.array(shaper[1])
        inv_D = 1.0 / A.sum()
        omega = 2.0 * math.pi * test_freqs
        damping = test_damping_ratio * omega
        omega_d = omega * math.sqrt(1.0 - test_damping_ratio ** 2)
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

    
    def _get_shaper_smoothing(self, shaper, accel = 5000, scv = 5.0):
        half_accel = accel * 0.5
        (A, T) = shaper
        inv_D = 1.0 / sum(A)
        n = len(T)
        ts = sum([ A[i] * T[i] for i in (range(n)) ]) * inv_D
        offset_90 = offset_180 = 0.0
        for i in range(n):
            if T[i] >= ts:
                offset_90 += A[i] * (scv + half_accel * (T[i] - ts)) * (T[i] - ts)
            offset_180 += A[i] * half_accel * (T[i] - ts) ** 2
        offset_90 *= inv_D * math.sqrt(2.0)
        offset_180 *= inv_D
        return max(offset_90, offset_180)

    
    def fit_shaper(self, shaper_cfg, calibration_data, max_smoothing):
        np = self.numpy
        test_freqs = np.arange(shaper_cfg.min_freq, MAX_SHAPER_FREQ, 0.2)
        freq_bins = calibration_data.freq_bins
        psd = calibration_data.psd_sum[freq_bins <= MAX_FREQ]
        freq_bins = freq_bins[freq_bins <= MAX_FREQ]
        best_res = None
        results = []
        for test_freq in test_freqs[::-1]:
            shaper_vibrations = 0.0
            shaper_vals = np.zeros(shape=freq_bins.shape)
            shaper = shaper_cfg.init_func(test_freq, shaper_defs.DEFAULT_DAMPING_RATIO)
            shaper_smoothing = self._get_shaper_smoothing(shaper)
            if max_smoothing and shaper_smoothing > max_smoothing and best_res:
                return best_res
            for dr in TEST_DAMPING_RATIOS:
                (vibrations, vals) = self._estimate_remaining_vibrations(shaper, dr, freq_bins, psd)
                shaper_vals = np.maximum(shaper_vals, vals)
                if vibrations > shaper_vibrations:
                    shaper_vibrations = vibrations
            max_accel = self.find_shaper_max_accel(shaper)
            shaper_score = shaper_smoothing * (shaper_vibrations ** 1.5 + shaper_vibrations * 0.2 + 0.01)
            results.append(CalibrationResult(name=shaper_cfg.name, freq=test_freq, vals=shaper_vals, vibrs=shaper_vibrations, smoothing=shaper_smoothing, score=shaper_score, max_accel=max_accel))
            if best_res is None or best_res.vibrs > results[-1].vibrs:
                best_res = results[-1]
        selected = best_res
        for res in results[::-1]:
            if res.vibrs < best_res.vibrs * 1.1 and res.score < selected.score:
                selected = res
        return selected

    
    def _bisect(self, func):
        left = right = 1.0
        while not func(left):
            right = left
            left *= 0.5
        if right == left:
            while func(right):
                right *= 2.0
        while right - left > 1e-08:
            middle = (left + right) * 0.5
            if func(middle):
                left = middle
            else:
                right = middle
        return left

    
    def find_shaper_max_accel(self, shaper):
        TARGET_SMOOTHING = 0.12
        max_accel = self._bisect((lambda test_accel: self._get_shaper_smoothing(shaper, test_accel) <= TARGET_SMOOTHING))
        return max_accel

    
    def find_best_shaper(self, calibration_data, max_smoothing, logger = None):
        best_shaper = None
        all_shapers = []
        for shaper_cfg in shaper_defs.INPUT_SHAPERS:
            if shaper_cfg.name not in self.autotune_shapers:
                continue
            shaper = self.background_process_exec(self.fit_shaper, (shaper_cfg, calibration_data, max_smoothing))
            if logger is not None:
                logger("Fitted shaper '%s' frequency = %.1f Hz (vibrations = %.1f%%, smoothing ~= %.3f)" % (shaper.name, shaper.freq, shaper.vibrs * 1e+02, shaper.smoothing))
                logger("To avoid too much smoothing with '%s', suggested max_accel <= %.0f mm/sec^2" % (shaper.name, round(shaper.max_accel / 1e+02) * 1e+02))
            all_shapers.append(shaper)
            if best_shaper is None or shaper.score * 1.2 < best_shaper.score or shaper.score * 1.05 < best_shaper.score and shaper.smoothing * 1.1 < best_shaper.smoothing:
                best_shaper = shaper
        return (best_shaper, all_shapers)

    
    def save_params(self, configfile, axis, shaper_name, shaper_freq):
        if axis == 'xy':
            self.save_params(configfile, 'x', shaper_name, shaper_freq)
            self.save_params(configfile, 'y', shaper_name, shaper_freq)
        else:
            configfile.set('input_shaper', 'shaper_type_' + axis, shaper_name)
            configfile.set('input_shaper', 'shaper_freq_' + axis, '%.1f' % (shaper_freq,))

    
    def apply_params(self, input_shaper, axis, shaper_name, shaper_freq):
        if axis == 'xy':
            self.apply_params(input_shaper, 'x', shaper_name, shaper_freq)
            self.apply_params(input_shaper, 'y', shaper_name, shaper_freq)
            return None
        gcode = self.printer.lookup_object('gcode')
        axis = axis.upper()
        input_shaper.cmd_SET_INPUT_SHAPER(gcode.create_gcode_command('SET_INPUT_SHAPER', 'SET_INPUT_SHAPER', {
            'SHAPER_TYPE_' + axis: shaper_name,
            'SHAPER_FREQ_' + axis: shaper_freq }))

    
    def save_calibration_data(self, output, calibration_data, shapers = None):
        
        try:
            with open(output, 'w') as csvfile:
                csvfile.write('freq,psd_x,psd_y,psd_z,psd_xyz')
                if shapers:
                    for shaper in shapers:
                        csvfile.write(',%s(%.1f)' % (shaper.name, shaper.freq))
                csvfile.write('\n')
                num_freqs = calibration_data.freq_bins.shape[0]
                for i in range(num_freqs):
                    if calibration_data.freq_bins[i] >= MAX_FREQ:
                        break
                    csvfile.write('%.1f,%.3e,%.3e,%.3e,%.3e' % (calibration_data.freq_bins[i], calibration_data.psd_x[i], calibration_data.psd_y[i], calibration_data.psd_z[i], calibration_data.psd_sum[i]))
                    if shapers:
                        for shaper in shapers:
                            csvfile.write(',%.3f' % (shaper.vals[i],))
                    csvfile.write('\n')
        except IOError as e:
            raise self.error({
                'code': 'key314',
                'msg': "Error writing to file '%s': %s",
                'values': [
                    '%s',
                    '%s'] }, output, str(e), output, str(e))




