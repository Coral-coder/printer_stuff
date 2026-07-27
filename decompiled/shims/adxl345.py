# Source Generated with Decompyle++
# File: adxl345.pyc (Python 3.9)

import logging
import time
import collections
import threading
import multiprocessing
import os
from . import bus, motion_report
import struct
from multiprocessing import shared_memory
REG_DEVID = 0
REG_BW_RATE = 44
REG_POWER_CTL = 45
REG_DATA_FORMAT = 49
REG_FIFO_CTL = 56
REG_MOD_READ = 128
REG_MOD_MULTI = 64
QUERY_RATES = {
    25: 8,
    50: 9,
    100: 10,
    200: 11,
    400: 12,
    800: 13,
    1600: 14,
    3200: 15 }
ADXL345_DEV_ID = 229
SET_FIFO_CTL = 144
FREEFALL_ACCEL = 9806.65
SCALE_XY = 0.003774 * FREEFALL_ACCEL
SCALE_Z = 0.003906 * FREEFALL_ACCEL
Accel_Measurement = collections.namedtuple('Accel_Measurement', ('time', 'accel_x', 'accel_y', 'accel_z'))

class AccelQueryHelper:
    
    def __init__(self, printer, cconn):
        self.printer = printer
        self.cconn = cconn
        print_time = printer.lookup_object('toolhead').get_last_move_time()
        self.request_start_time = self.request_end_time = print_time
        self.samples = self.raw_samples = []

    
    def finish_measurements(self):
        toolhead = self.printer.lookup_object('toolhead')
        self.request_end_time = toolhead.get_last_move_time()
        toolhead.wait_moves()
        self.cconn.finalize()

    
    def _get_raw_samples(self):
        raw_samples = self.cconn.get_messages()
        if raw_samples:
            self.raw_samples = raw_samples
        return self.raw_samples

    
    def has_valid_samples(self):
        raw_samples = self._get_raw_samples()
        for msg in raw_samples:
            data = msg['params']['data']
            first_sample_time = data[0][0]
            last_sample_time = data[-1][0]
            if first_sample_time > self.request_end_time or last_sample_time < self.request_start_time:
                continue
            return True
        return False

    
    def get_samples(self):
        raw_samples = self._get_raw_samples()
        if not raw_samples:
            return self.samples
        total = sum([ len(m['params']['data']) for m in (raw_samples) ])
        count = 0
        self.samples = samples = [
            None] * total
        for msg in raw_samples:
            for samp_time, x, y, z in msg['params']['data']:
                if samp_time < self.request_start_time:
                    continue
                if samp_time > self.request_end_time:
                    break
                samples[count] = Accel_Measurement(samp_time, x, y, z)
                count += 1
        del samples[count:]
        return self.samples

    
    def copy_double_to_buffer(self, buffer, offset, val):
        bytes = struct.pack('d', val)
        
        try:
            buffer[offset:offset + 8] = bytearray(bytes)
            del bytes
        except:
            gcode = self.printer.lookup_object('gcode')
            gcode.respond_info('val: %f, bytes: %s, offset: %d' % (val, bytes.hex(), offset))


    
    def copy_int_to_buffer(self, buffer, offset, val):
        
        try:
            buffer[offset] = val & 255
            buffer[offset + 1] = val >> 8 & 255
            buffer[offset + 2] = val >> 16 & 255
            buffer[offset + 3] = val >> 24 & 255
        except:
            gcode = self.printer.lookup_object('gcode')
            gcode.respond_info('val: %f, offset: %d' % (val, offset))


    
    def get_samples_to_shared_mem(self):
        gcode = self.printer.lookup_object('gcode')
        raw_samples = self._get_raw_samples()
        if not raw_samples:
            return self.samples
        total = sum([ len(m['params']['data']) for m in (raw_samples) ])
        count = 0
        shm_size = 32 * total
        shm = shared_memory.SharedMemory(name='psm_samples', create=True, size=shm_size)
        buffer = shm.buf
        self.copy_int_to_buffer(buffer, 0, count)
        count += 4
        reactor = self.printer.get_reactor()
        for msg in raw_samples:
            for samp_time, x, y, z in msg['params']['data']:
                if samp_time < self.request_start_time:
                    continue
                if samp_time > self.request_end_time:
                    break
                if count % 960000 == 4:
                    reactor.pause(reactor.monotonic() + 0.1)
                self.copy_double_to_buffer(buffer, count, samp_time)
                count += 8
                self.copy_double_to_buffer(buffer, count, x)
                count += 8
                self.copy_double_to_buffer(buffer, count, y)
                count += 8
                self.copy_double_to_buffer(buffer, count, z)
                count += 8
        self.copy_int_to_buffer(buffer, 0, count)
        shm.close()
        gcode.respond_info('shm_size: %d, double bytes count: %d' % (shm_size, count))

    
    def write_to_file(self, filename):
        
        def write_impl():
            
            try:
                os.nice(20)
            except:
                pass

            f = open(filename, 'w')
            f.write('#time,accel_x,accel_y,accel_z\n')
            samples = self.samples or self.get_samples()
            for t, accel_x, accel_y, accel_z in samples:
                f.write('%.6f,%.6f,%.6f,%.6f\n' % (t, accel_x, accel_y, accel_z))
            f.close()

        write_proc = multiprocessing.Process(target=write_impl)
        write_proc.daemon = True
        write_proc.start()



class AccelCommandHelper:
    
    def __init__(self, config, chip):
        self.printer = config.get_printer()
        self.chip = chip
        self.bg_client = None
        name_parts = config.get_name().split()
        self.base_name = name_parts[0]
        self.name = name_parts[-1]
        self.register_commands(self.name)
        if len(name_parts) == 1:
            if self.name == 'adxl345' or not config.has_section('adxl345'):
                self.register_commands(None)
        webhooks = self.printer.lookup_object('webhooks')
        webhooks.register_endpoint('getAdxl345Status', self.get_adxl345_status)

    
    def get_adxl345_status(self, web_request):
        adxl345_is_exist = True
        
        try:
            aclient = self.chip.start_internal_client()
            self.printer.lookup_object('toolhead').dwell(1.0)
            aclient.finish_measurements()
            values = aclient.get_samples()
        except Exception as err:
            logging.error(err)
            values = ''
        if not values:
            adxl345_is_exist = False
        web_request.send({
            'adxl345_is_exist': adxl345_is_exist })

    
    def register_commands(self, name):
        gcode = self.printer.lookup_object('gcode')
        gcode.register_mux_command('ACCELEROMETER_MEASURE', 'CHIP', name, self.cmd_ACCELEROMETER_MEASURE, desc=self.cmd_ACCELEROMETER_MEASURE_help)
        gcode.register_mux_command('ACCELEROMETER_QUERY', 'CHIP', name, self.cmd_ACCELEROMETER_QUERY, desc=self.cmd_ACCELEROMETER_QUERY_help)
        gcode.register_mux_command('ACCELEROMETER_DEBUG_READ', 'CHIP', name, self.cmd_ACCELEROMETER_DEBUG_READ, desc=self.cmd_ACCELEROMETER_DEBUG_READ_help)
        gcode.register_mux_command('ACCELEROMETER_DEBUG_WRITE', 'CHIP', name, self.cmd_ACCELEROMETER_DEBUG_WRITE, desc=self.cmd_ACCELEROMETER_DEBUG_WRITE_help)

    cmd_ACCELEROMETER_MEASURE_help = 'Start/stop accelerometer'
    
    def cmd_ACCELEROMETER_MEASURE(self, gcmd):
        if self.bg_client is None:
            self.bg_client = self.chip.start_internal_client()
            gcmd.respond_info('accelerometer measurements started')
            return None
        name = gcmd.get('NAME', time.strftime('%Y%m%d_%H%M%S'))
        if not name.replace('-', '').replace('_', '').isalnum():
            raise gcmd.error('{"code":"key64", "msg":"Invalid adxl345 NAME parameter", "values": []}')
        bg_client = self.bg_client
        self.bg_client = None
        bg_client.finish_measurements()
        if self.base_name == self.name:
            filename = '/tmp/%s-%s.csv' % (self.base_name, name)
        else:
            filename = '/tmp/%s-%s-%s.csv' % (self.base_name, self.name, name)
        bg_client.write_to_file(filename)
        gcmd.respond_info('Writing raw accelerometer data to %s file' % (filename,))

    cmd_ACCELEROMETER_QUERY_help = 'Query accelerometer for the current values'
    
    def cmd_ACCELEROMETER_QUERY(self, gcmd):
        aclient = self.chip.start_internal_client()
        self.printer.lookup_object('toolhead').dwell(1.0)
        aclient.finish_measurements()
        values = aclient.get_samples()
        if not values:
            raise gcmd.error('{"code":"key232", "msg":"No adxl345 measurements found", "values": []}')
        (_, accel_x, accel_y, accel_z) = values[-1]
        gcmd.respond_info('accelerometer values (x, y, z): %.6f, %.6f, %.6f' % (accel_x, accel_y, accel_z))

    cmd_ACCELEROMETER_DEBUG_READ_help = 'Query register (for debugging)'
    
    def cmd_ACCELEROMETER_DEBUG_READ(self, gcmd):
        reg = gcmd.get('REG', minval=0, maxval=126, parser=(lambda x: int(x, 0)))
        val = self.chip.read_reg(reg)
        gcmd.respond_info('Accelerometer REG[0x%x] = 0x%x' % (reg, val))

    cmd_ACCELEROMETER_DEBUG_WRITE_help = 'Set register (for debugging)'
    
    def cmd_ACCELEROMETER_DEBUG_WRITE(self, gcmd):
        reg = gcmd.get('REG', minval=0, maxval=126, parser=(lambda x: int(x, 0)))
        val = gcmd.get('VAL', minval=0, maxval=255, parser=(lambda x: int(x, 0)))
        self.chip.set_reg(reg, val)



class ClockSyncRegression:
    
    def __init__(self, mcu, chip_clock_smooth, decay = 0.05):
        self.mcu = mcu
        self.chip_clock_smooth = chip_clock_smooth
        self.decay = decay
        self.last_chip_clock = self.last_exp_mcu_clock = 0.0
        self.mcu_clock_avg = self.mcu_clock_variance = 0.0
        self.chip_clock_avg = self.chip_clock_covariance = 0.0

    
    def reset(self, mcu_clock, chip_clock):
        self.mcu_clock_avg = self.last_mcu_clock = mcu_clock
        self.chip_clock_avg = chip_clock
        self.mcu_clock_variance = self.chip_clock_covariance = 0.0
        self.last_chip_clock = self.last_exp_mcu_clock = 0.0

    
    def update(self, mcu_clock, chip_clock):
        decay = self.decay
        diff_mcu_clock = mcu_clock - self.mcu_clock_avg
        self.mcu_clock_avg += decay * diff_mcu_clock
        self.mcu_clock_variance = (1.0 - decay) * (self.mcu_clock_variance + diff_mcu_clock ** 2 * decay)
        diff_chip_clock = chip_clock - self.chip_clock_avg
        self.chip_clock_avg += decay * diff_chip_clock
        self.chip_clock_covariance = (1.0 - decay) * (self.chip_clock_covariance + diff_mcu_clock * diff_chip_clock * decay)

    
    def set_last_chip_clock(self, chip_clock):
        (base_mcu, base_chip, inv_cfreq) = self.get_clock_translation()
        self.last_chip_clock = chip_clock
        self.last_exp_mcu_clock = base_mcu + (chip_clock - base_chip) * inv_cfreq

    
    def get_clock_translation(self):
        inv_chip_freq = self.mcu_clock_variance / self.chip_clock_covariance
        if not self.last_chip_clock:
            return (self.mcu_clock_avg, self.chip_clock_avg, inv_chip_freq)
        s_chip_clock = self.last_chip_clock + self.chip_clock_smooth
        scdiff = s_chip_clock - self.chip_clock_avg
        s_mcu_clock = self.mcu_clock_avg + scdiff * inv_chip_freq
        mdiff = s_mcu_clock - self.last_exp_mcu_clock
        s_inv_chip_freq = mdiff / self.chip_clock_smooth
        return (self.last_exp_mcu_clock, self.last_chip_clock, s_inv_chip_freq)

    
    def get_time_translation(self):
        (base_mcu, base_chip, inv_cfreq) = self.get_clock_translation()
        clock_to_print_time = self.mcu.clock_to_print_time
        base_time = clock_to_print_time(base_mcu)
        inv_freq = clock_to_print_time(base_mcu + inv_cfreq) - base_time
        return (base_time, base_chip, inv_freq)


MIN_MSG_TIME = 0.1
BYTES_PER_SAMPLE = 5
SAMPLES_PER_BLOCK = 10

class ADXL345:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        AccelCommandHelper(config, self)
        self.query_rate = 0
        am = {
            'x': (0, SCALE_XY),
            'y': (1, SCALE_XY),
            'z': (2, SCALE_Z),
            '-x': (0, -SCALE_XY),
            '-y': (1, -SCALE_XY),
            '-z': (2, -SCALE_Z) }
        axes_map = config.getlist('axes_map', ('x', 'y', 'z'), count=3)
        if any([ a not in am for a in (axes_map) ]):
            raise config.error('{"code": "key9", "msg": "Invalid adxl345 axes_map parameter"}')
        self.axes_map = [ am[a.strip()] for a in (axes_map) ]
        self.data_rate = config.getint('rate', 3200)
        if self.data_rate not in QUERY_RATES:
            raise config.error('{"code":"key245", "msg":"Invalid rate parameter: %d", "values": [%d]}' % (self.data_rate, self.data_rate))
        self.lock = threading.Lock()
        self.raw_samples = []
        self.spi = bus.MCU_SPI_from_config(config, 3, default_speed=5000000)
        self.mcu = mcu = self.spi.get_mcu()
        self.oid = oid = mcu.create_oid()
        self.query_adxl345_cmd = self.query_adxl345_end_cmd = None
        self.query_adxl345_status_cmd = None
        mcu.add_config_cmd('config_adxl345 oid=%d spi_oid=%d' % (oid, self.spi.get_oid()))
        mcu.add_config_cmd('query_adxl345 oid=%d clock=0 rest_ticks=0' % (oid,), on_restart=True)
        mcu.register_config_callback(self._build_config)
        mcu.register_response(self._handle_adxl345_data, 'adxl345_data', oid)
        self.last_sequence = self.max_query_duration = 0
        self.last_limit_count = self.last_error_count = 0
        self.clock_sync = ClockSyncRegression(self.mcu, 640)
        self.api_dump = motion_report.APIDumpHelper(self.printer, self._api_update, self._api_startstop, 0.1)
        self.name = config.get_name().split()[-1]
        wh = self.printer.lookup_object('webhooks')
        wh.register_mux_endpoint('adxl345/dump_adxl345', 'sensor', self.name, self._handle_dump_adxl345)

    
    def _build_config(self):
        cmdqueue = self.spi.get_command_queue()
        self.query_adxl345_cmd = self.mcu.lookup_command('query_adxl345 oid=%c clock=%u rest_ticks=%u', cq=cmdqueue)
        self.query_adxl345_end_cmd = self.mcu.lookup_query_command('query_adxl345 oid=%c clock=%u rest_ticks=%u', 'adxl345_status oid=%c clock=%u query_ticks=%u next_sequence=%hu buffered=%c fifo=%c limit_count=%hu', oid=self.oid, cq=cmdqueue)
        self.query_adxl345_status_cmd = self.mcu.lookup_query_command('query_adxl345_status oid=%c', 'adxl345_status oid=%c clock=%u query_ticks=%u next_sequence=%hu buffered=%c fifo=%c limit_count=%hu', oid=self.oid, cq=cmdqueue)

    
    def read_reg(self, reg):
        params = self.spi.spi_transfer([
            reg | REG_MOD_READ,
            0])
        response = bytearray(params['response'])
        return response[1]

    
    def set_reg(self, reg, val, minclock = 0):
        self.spi.spi_send([
            reg,
            val & 255], minclock=minclock)
        stored_val = self.read_reg(reg)
        if stored_val != val:
            raise self.printer.command_error('{"code":"key65", "msg":"Failed to set ADXL345 register [0x%x] to 0x%x: got 0x%x. \nThis is generally indicative of connection problems\n(e.g. faulty wiring)\nor a faulty adxl345 chip.", "values": ["%x","%x","%x"]}' % (reg, val, stored_val, reg, val, stored_val))

    
    def is_measuring(self):
        return self.query_rate > 0

    
    def _handle_adxl345_data(self, params):
        with self.lock:
            self.raw_samples.append(params)

    
    def _extract_samples(self, raw_samples):
        (x_pos, x_scale), (y_pos, y_scale), (z_pos, z_scale) = self.axes_map
        last_sequence = self.last_sequence
        (time_base, chip_base, inv_freq) = self.clock_sync.get_time_translation()
        count = seq = 0
        samples = [
            None] * (len(raw_samples) * SAMPLES_PER_BLOCK)
        for params in raw_samples:
            seq_diff = last_sequence - params['sequence'] & 65535
            seq_diff -= (seq_diff & 32768) << 1
            seq = last_sequence - seq_diff
            d = bytearray(params['data'])
            msg_cdiff = seq * SAMPLES_PER_BLOCK - chip_base
            for i in range(len(d) // BYTES_PER_SAMPLE):
                d_xyz = d[i * BYTES_PER_SAMPLE:(i + 1) * BYTES_PER_SAMPLE]
                (xlow, ylow, zlow, xzhigh, yzhigh) = d_xyz
                if yzhigh & 128:
                    self.last_error_count += 1
                    continue
                rx = (xlow | (xzhigh & 31) << 8) - ((xzhigh & 16) << 9)
                ry = (ylow | (yzhigh & 31) << 8) - ((yzhigh & 16) << 9)
                rz = (zlow | (xzhigh & 224) << 3 | (yzhigh & 224) << 6) - ((yzhigh & 64) << 7)
                raw_xyz = (rx, ry, rz)
                x = round(raw_xyz[x_pos] * x_scale, 6)
                y = round(raw_xyz[y_pos] * y_scale, 6)
                z = round(raw_xyz[z_pos] * z_scale, 6)
                ptime = round(time_base + (msg_cdiff + i) * inv_freq, 6)
                samples[count] = (ptime, x, y, z)
                count += 1
        self.clock_sync.set_last_chip_clock(seq * SAMPLES_PER_BLOCK + i)
        del samples[count:]
        return samples

    
    def _update_clock(self, minclock = 0):
        for retry in range(5):
            params = self.query_adxl345_status_cmd.send([
                self.oid], minclock=minclock)
            fifo = params['fifo'] & 127
            if fifo <= 32:
                break
        else:
            raise self.printer.command_error('{"code":"key118", "msg":"Unable to query adxl345 fifo", "values": []}')
        mcu_clock = self.mcu.clock32_to_clock64(params['clock'])
        sequence = self.last_sequence & -65536 | params['next_sequence']
        if sequence < self.last_sequence:
            sequence += 65536
        self.last_sequence = sequence
        buffered = params['buffered']
        limit_count = self.last_limit_count & -65536 | params['limit_count']
        if limit_count < self.last_limit_count:
            limit_count += 65536
        self.last_limit_count = limit_count
        duration = params['query_ticks']
        if duration > self.max_query_duration:
            self.max_query_duration = max(2 * self.max_query_duration, self.mcu.seconds_to_clock(5e-06))
            return None
        self.max_query_duration = 2 * duration
        msg_count = sequence * SAMPLES_PER_BLOCK + buffered // BYTES_PER_SAMPLE + fifo
        chip_clock = msg_count + 1
        self.clock_sync.update(mcu_clock + duration // 2, chip_clock)

    
    def _start_measurements(self):
        if self.is_measuring():
            return None
        dev_id = self.read_reg(REG_DEVID)
        if dev_id != ADXL345_DEV_ID:
            raise self.printer.command_error('{"code":"key119", "msg": "Invalid adxl345 id (got %x vs %x).This is generally indicative of connection problems(e.g. faulty wiring) or a faulty adxl345 chip.", "values": ["%x", "%x"]}' % (dev_id, ADXL345_DEV_ID, dev_id, ADXL345_DEV_ID))
        self.set_reg(REG_POWER_CTL, 0)
        self.set_reg(REG_DATA_FORMAT, 11)
        self.set_reg(REG_FIFO_CTL, 0)
        self.set_reg(REG_BW_RATE, QUERY_RATES[self.data_rate])
        self.set_reg(REG_FIFO_CTL, SET_FIFO_CTL)
        with self.lock:
            self.raw_samples = []
        systime = self.printer.get_reactor().monotonic()
        print_time = self.mcu.estimated_print_time(systime) + MIN_MSG_TIME
        reqclock = self.mcu.print_time_to_clock(print_time)
        rest_ticks = self.mcu.seconds_to_clock(4.0 / self.data_rate)
        self.query_rate = self.data_rate
        self.query_adxl345_cmd.send([
            self.oid,
            reqclock,
            rest_ticks], reqclock=reqclock)
        logging.info("ADXL345 starting '%s' measurements", self.name)
        self.last_sequence = 0
        self.last_limit_count = self.last_error_count = 0
        self.clock_sync.reset(reqclock, 0)
        self.max_query_duration = 0x80000000
        self._update_clock(minclock=reqclock)
        self.max_query_duration = 0x80000000

    
    def _finish_measurements(self):
        if not self.is_measuring():
            return None
        params = self.query_adxl345_end_cmd.send([
            self.oid,
            0,
            0])
        self.query_rate = 0
        with self.lock:
            self.raw_samples = []
        logging.info("ADXL345 finished '%s' measurements", self.name)

    
    def _api_update(self, eventtime):
        self._update_clock()
        with self.lock:
            raw_samples = self.raw_samples
            self.raw_samples = []
        if not raw_samples:
            return { }
        samples = self._extract_samples(raw_samples)
        if not samples:
            return { }
        return {
            'data': samples,
            'errors': self.last_error_count,
            'overflows': self.last_limit_count }

    
    def _api_startstop(self, is_start):
        if is_start:
            self._start_measurements()
        else:
            self._finish_measurements()

    
    def _handle_dump_adxl345(self, web_request):
        self.api_dump.add_client(web_request)
        hdr = ('time', 'x_acceleration', 'y_acceleration', 'z_acceleration')
        web_request.send({
            'header': hdr })

    
    def start_internal_client(self):
        cconn = self.api_dump.add_internal_client()
        return AccelQueryHelper(self.printer, cconn)



def load_config(config):
    return ADXL345(config)


def load_config_prefix(config):
    return ADXL345(config)

