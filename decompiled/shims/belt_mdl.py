# Source Generated with Decompyle++
# File: belt_mdl.pyc (Python 3.9)

import numpy as np
from box_wrapper import BoxAction

class COM:
    
    def __init__(self):
        self.head = 247
        self.addr = 33
        self.len = 3
        self.star = 0
        self.fun = 0
        self.data = []
        self.crc = 255



class STA:
    
    def __init__(self):
        self.read_version_cmd = 0
        self.read_version_resp = 0
        self.read_flash_cmd = 2
        self.read_flash_resp = 2
        self.write_flash_cmd = 4
        self.write_flash_resp = 4
        self.read_adc_cmd = 6
        self.read_adc_resp = 6
        self.move_slider_cmd = 8
        self.move_slider_resp = 8



def split_to_bytes(data):
    data = data & 0xFFFFFFFF
    return [ data >> 8 * i & 255 for i in (range(4)) ][::-1]


def bytes_to_int(byte_array):
    pass
# WARNING: Decompyle incomplete


class MDL:
    
    def __init__(self, val):
        self.value = val
        self.softversion = 0
        self.halversion = 0
        self.current_status = 0
        self.total_place = 0
        self.total_tension = 0
        self.idl_adc = 0xFFFFFFFF
        self.full_adc = 0xFFFFFFFF
        self.current_place_adc = 0xFFFFFFFF
        self.current_place = 0
        self.current_tension = 0
        self.target_place = 0
        self.target_move = 0
        self.target_tension = 0
        self.target_error = 0
        self.error_result = 0
        self.tension_correction_dir = 0
        self.uart_pin = None
        self.convert = False
        self.read_flash = False
        self.slope = 0
        self.intercept = 0
        self.mistake = 0.02
        self.adjustnum1 = 140
        self.adjustnum2 = 160



class BELT_MDL:
    
    def __init__(self, config):
        self.config = config
        self.printer = config.get_printer()
        self.gcode = self.printer.lookup_object('gcode')
        name_parts = config.get_name().split()
        self.base_name = name_parts[0]
        self.name = name_parts[-1]
        self.mdl = { }
        self.mdl = MDL(self)
        self.com = { }
        self.com = COM()
        self.sta = { }
        self.sta = STA()
        self.mdl.total_place = config.getint('ch_max_dis', default=5, minval=0, maxval=10)
        self.mdl.target_tension = config.getint('ch_best_n', default=140, minval=0, maxval=300)
        self.mdl.target_error = config.getfloat('ch_best_error', default=0.05, minval=0.001, maxval=1)
        self._serial = self.printer.lookup_object('serial_485 serial485')
        self.gcode.register_mux_command('BELT_MDL_INFO', 'MDL_NAME', self.name, self.cmd_BELT_MDL_INFO, desc=self.cmd_BELT_MDL_INFO_help)
        self.gcode.register_mux_command('BELT_MDL_MOVE', 'MDL_NAME', self.name, self.cmd_BELT_MDL_MOVE, desc=self.cmd_BELT_MDL_MOVE_help)
        self.gcode.register_mux_command('BELT_MDL_SET', 'MDL_NAME', self.name, self.cmd_BELT_MDL_SET, desc=self.cmd_BELT_MDL_SET_help)
        self.gcode.register_mux_command('BELT_MDL_CALI', 'MDL_NAME', self.name, self.cmd_BELT_MDL_CALI, desc=self.cmd_BELT_MDL_CALI_help)
        self.gcode.register_mux_command('BELT_MDL_TEST', 'MDL_NAME', self.name, self.cmd_BELT_MDL_TEST, desc=self.cmd_BELT_MDL_TEST_help)
        self.webhooks = self.printer.lookup_object('webhooks')
        self.webhooks.register_mux_endpoint('belt_mdl_test', 'MDL_NAME', self.name, self._belt_mdl_test)

    
    def get_mdl_data(self):
        self.config_addr()
        self.mdl_info_cmd()
        self.error_result = 1
        target_max = self.mdl.target_tension * (1 + self.mdl.target_error)
        target_min = self.mdl.target_tension * (1 - self.mdl.target_error)
        if (self.mdl.current_tension > target_min) & (self.mdl.current_tension < target_max):
            self.error_result = 0
        self.gcode.respond_info('MDL_NAME: %s' % (self.name,))
        result = {
            'current_tension': self.mdl.current_tension,
            'target_error': self.error_result }
        return result

    cmd_BELT_MDL_TEST_help = 'BELT_MDL_TEST.'
    
    def cmd_BELT_MDL_TEST(self, gcmd):
        self.gcode.respond_info('get_mdl_data: %s' % self.get_mdl_data())

    
    def _belt_mdl_test(self, web_request):
        web_request.send(self.get_mdl_data())

    
    def mdl_info_cmd(self):
        self.gcode.respond_info('ACK_mdl_info')
        self.Get_version()
        self.get_flash_data()
        self.init_adc_to_num()
        self.get_adc()
        self.adc_to_num(self.mdl.current_place_adc)

    
    def set_place(self):
        self.gcode.respond_info('ACK_mdl_pos')
        if self.mdl.current_place == 0xFFFFFFFF:
            if self.name == 'mdlx':
                raise self.printer.command_error('{"code":"key714", "msg":"Belt tension module strain gauge not calibrated abnormal: \'%s\' set_place_error", "values": []}' % self.name)
            if self.name == 'mdly':
                raise self.printer.command_error('{"code":"key715", "msg":"Belt tension module strain gauge not calibrated abnormal: \'%s\' set_place_error", "values": []}' % self.name)
        self.target_move = self.target_place - self.mdl.current_place
        self.mdl.current_place = self.target_place
        movedir = 1 if self.target_move > 0 else 0
        movenum = abs(self.target_move)
        self.set_move(movedir, movenum)
        self.write_flash()

    
    def run_tension(self):
        movetimes = 0
        movetimes += 1
        self.gcode.respond_info('times:%s' % movetimes)
        if movetimes > 200:
            return 0
        aimpull = self.target_tension - self.mdl.current_tension
        aimpull = abs(aimpull)
        aimpull = 10 if aimpull > 10 else aimpull
        aimmove = int(aimpull) + 2
        if aimmove > movetimes:
            aimmove = aimmove - movetimes
        elif movetimes > 110:
            aimmove = 1
        elif movetimes > 70:
            aimmove = 2
        elif movetimes > 50:
            aimmove = 3
        elif movetimes > 40:
            aimmove = 4
        elif movetimes > 20 and aimmove > movetimes - 20:
            aimmove = aimmove + 20 - movetimes
        if self.target_tension * (1 + self.mdl.mistake) < self.mdl.current_tension:
            self.get_adc()
            self.adc_to_num(self.mdl.current_place_adc)
            return 1
        if self.target_tension * (1 - self.mdl.mistake) > self.mdl.current_tension:
            self.set_move(1, aimmove)
            self.mdl.current_place = self.mdl.current_place + aimmove
            self.get_adc()
            self.adc_to_num(self.mdl.current_place_adc)
            continue
        return 1

    
    def set_tension(self):
        self.init_adc_to_num()
        self.get_adc()
        self.adc_to_num(self.mdl.current_place_adc)
        for i in range(2):
            self.run_tension()
            self.gcode.run_script_from_command('RESET_HOME_AXES_XY')
            self.gcode.run_script_from_command('MOTOR_CONTROL NUM=1 DATA=2')
            self.gcode.run_script_from_command('MOTOR_CONTROL NUM=2 DATA=2')
            self.printer.get_reactor().pause(self.printer.get_reactor().monotonic() + 0.3)
            self.gcode.run_script_from_command('FORCE_MOVE STEPPER=stepper_x DISTANCE=-200 VELOCITY=60')
            self.gcode.run_script_from_command('FORCE_MOVE STEPPER=stepper_y DISTANCE=200 VELOCITY=60')
            self.gcode.run_script_from_command('M400')
            self.gcode.run_script_from_command('FORCE_MOVE STEPPER=stepper_x DISTANCE=200 VELOCITY=60')
            self.gcode.run_script_from_command('FORCE_MOVE STEPPER=stepper_y DISTANCE=-200 VELOCITY=60')
            self.gcode.run_script_from_command('M400')
            self.gcode.run_script_from_command('MOTOR_CONTROL NUM=1 DATA=1')
            self.gcode.run_script_from_command('MOTOR_CONTROL NUM=2 DATA=1')
            self.gcode.run_script_from_command('M84')
        run_result = self.run_tension()
        if run_result == 0:
            if self.name == 'mdlx':
                raise self.printer.command_error('{"code":"key718", "msg":"Belt tensioning timeout: \'%s\'", "values": []}' % self.name)
            if self.name == 'mdly':
                raise self.printer.command_error('{"code":"key719", "msg":"Belt tensioning timeout: \'%s\'", "values": []}' % self.name)
        self.write_flash()

    
    def set_tension_correction(self):
        if self.tension_correction_dir == 0:
            self.mdl.current_place = 0
            self.write_flash()
        elif self.tension_correction_dir == 1:
            self.mdl.adjustnum1 = self.tension_correction_ten
            self.get_adc()
            self.mdl.idl_adc = self.mdl.current_place_adc
            self.write_flash()
        elif self.tension_correction_dir == 2:
            self.mdl.adjustnum2 = self.tension_correction_ten
            self.get_adc()
            self.mdl.full_adc = self.mdl.current_place_adc
            self.write_flash()

    cmd_BELT_MDL_INFO_help = 'obtain detailed parameters for the given module'
    
    def cmd_BELT_MDL_INFO(self, gcmd):
        self.config_addr()
        self.mdl_info_cmd()
        self.gcode.respond_info('MDL_NAME: %s' % (self.name,))

    cmd_BELT_MDL_MOVE_help = 'set the position of the module slider.'
    
    def cmd_BELT_MDL_MOVE(self, gcmd):
        self.config_addr()
        self.target_place = gcmd.get_int('POS', 0)
        self.set_place()
        self.gcode.respond_info('MDL_NAME: %s' % (self.name,))

    cmd_BELT_MDL_SET_help = 'set the module tension value.'
    
    def cmd_BELT_MDL_SET(self, gcmd):
        self.config_addr()
        self.target_tension = gcmd.get_int('MDL_N', 1.4e+02)
        self.set_tension()
        self.gcode.respond_info('MDL_NAME: %s' % (self.name,))

    cmd_BELT_MDL_CALI_help = 'calibrate stroke and pressure.'
    
    def cmd_BELT_MDL_CALI(self, gcmd):
        self.config_addr()
        self.tension_correction_dir = gcmd.get_int('DIR', 0)
        self.tension_correction_ten = gcmd.get_int('TEN', None)
        self.set_tension_correction()
        self.gcode.respond_info('MDL_NAME: %s' % (self.name,))

    
    def Get_version(self):
        sendbuf = self.send_sensor_data(self.sta.read_version_cmd, [])
        uartbuf = self.send_data(sendbuf)
        redata = self.recv_sensor_data(uartbuf)
        if redata[0] == 0:
            self.gcode.respond_info('reset:start error')
            return redata
        if redata[1] != self.sta.read_version_resp:
            self.gcode.respond_info('reset:comfun error')
            redata = (0, -5, 0)
            return redata
        if redata[1] == self.sta.read_version_resp:
            self.mdl.halversion = redata[2][:2]
            self.mdl.softversion = redata[2][2:]
            self.gcode.respond_info('halversion:%s' % self.mdl.halversion)
            self.gcode.respond_info('softversion:%s' % self.mdl.softversion)

    
    def Get_flash(self, flash_num):
        sendbuf = self.send_sensor_data(self.sta.read_flash_cmd, [
            flash_num])
        uartbuf = self.send_data(sendbuf)
        redata = self.recv_sensor_data(uartbuf)
        if redata[0] == 0:
            self.gcode.respond_info('reset:start error')
            return redata
        if redata[1] != self.sta.read_flash_resp:
            self.gcode.respond_info('reset:comfun error')
            redata = (0, -5, 0)
            return redata
        if redata[1] == self.sta.read_flash_resp:
            return redata

    
    def get_flash_data(self):
        flash_buf = self.Get_flash(3)
        if flash_buf[0] == 0:
            return None
        if flash_buf[0] == 1:
            flash_data_num = flash_buf[2][0]
            flash_data0 = flash_buf[2][1:5]
            flash_data1 = flash_buf[2][5:9]
            flash_data2 = flash_buf[2][9:13]
            flash_data_num0 = bytes_to_int(flash_data0)
            flash_data_num1 = bytes_to_int(flash_data1)
            flash_data_num2 = bytes_to_int(flash_data2)
            self.mdl.current_place = flash_data_num0
            self.mdl.idl_adc = flash_data_num1
            self.mdl.full_adc = flash_data_num2
            self.gcode.respond_info('current_place:%s' % self.mdl.current_place)
            self.gcode.respond_info('idl_adc:%s' % self.mdl.idl_adc)
            self.gcode.respond_info('full_adc:%s' % self.mdl.full_adc)
            if (self.mdl.current_place == 0xFFFFFFFF) | (self.mdl.idl_adc == 0xFFFFFFFF) | (self.mdl.full_adc == 0xFFFFFFFF):
                if self.name == 'mdlx':
                    raise self.printer.command_error('{"code":"key714", "msg":"Belt tension module strain gauge not calibrated abnormal: \'%s\'", "values": []}' % self.name)
                if self.name == 'mdly':
                    raise self.printer.command_error('{"code":"key715", "msg":"Belt tension module strain gauge not calibrated abnormal: \'%s\'", "values": []}' % self.name)

    
    def write_flash_buf(self, flash_num, flash_data):
        flash_data_buf = [
            flash_num]
        flash_data_buf.extend(flash_data)
        sendbuf = self.send_sensor_data(self.sta.write_flash_cmd, flash_data_buf)
        uartbuf = self.send_data(sendbuf)
        redata = self.recv_sensor_data(uartbuf)
        if redata[0] == 0:
            self.gcode.respond_info('reset:start error')
            return redata
        if redata[1] != self.sta.write_flash_resp:
            self.gcode.respond_info('reset:comfun error')
            redata = (0, -5, 0)
            return redata
        if redata[1] == self.sta.write_flash_resp:
            return redata

    
    def write_flash(self):
        data0 = self.mdl.current_place
        data1 = self.mdl.idl_adc
        data2 = self.mdl.full_adc
        buf_data0 = split_to_bytes(data0)
        buf_data1 = split_to_bytes(data1)
        buf_data2 = split_to_bytes(data2)
        data_buf = buf_data0
        data_buf.extend(buf_data1)
        data_buf.extend(buf_data2)
        flash_buf = self.write_flash_buf(3, data_buf)
        self.gcode.respond_info('flash_data:%s' % flash_buf[2])
        if flash_buf[0] == 0:
            return None
        if flash_buf[0] == 1:
            flash_data_num = flash_buf[2][0]
            flash_data0 = flash_buf[2][1:5]
            flash_data1 = flash_buf[2][5:9]
            flash_data2 = flash_buf[2][9:13]
            flash_data_num0 = bytes_to_int(flash_data0)
            flash_data_num1 = bytes_to_int(flash_data1)
            flash_data_num2 = bytes_to_int(flash_data2)
            if (self.mdl.current_place == flash_data_num0) | (self.mdl.idl_adc == flash_data_num1) | (self.mdl.full_adc == flash_data_num2):
                return 1
            return -1

    
    def get_adc_buf(self):
        sendbuf = self.send_sensor_data(self.sta.read_adc_cmd, [])
        uartbuf = self.send_data(sendbuf)
        redata = self.recv_sensor_data(uartbuf)
        if redata[0] == 0:
            self.gcode.respond_info('reset:start error')
            return redata
        if redata[1] != self.sta.read_adc_resp:
            self.gcode.respond_info('reset:comfun error')
            redata = (0, -5, 0)
            return redata
        if redata[1] == self.sta.read_adc_resp:
            return redata

    
    def get_adc(self):
        adc_buf = self.get_adc_buf()
        self.gcode.respond_info('adc_buf:%s' % adc_buf[2])
        if adc_buf[0] == 0:
            return None
        if adc_buf[0] == 1:
            adc_num = bytes_to_int(adc_buf[2])
            self.mdl.current_place_adc = adc_num
            self.gcode.respond_info('adc_num:%s' % adc_num)
            return adc_num

    
    def set_move_buf(self, dir, rang_buf):
        set_move_buf = [
            dir]
        set_move_buf.extend(rang_buf)
        sendbuf = self.send_sensor_data(self.sta.move_slider_cmd, set_move_buf)
        uartbuf = self.send_data(sendbuf)
        redata = self.recv_sensor_data(uartbuf)
        if redata[0] == 0:
            self.gcode.respond_info('reset:start error')
            return redata
        if redata[1] != self.sta.move_slider_resp:
            self.gcode.respond_info('reset:comfun error')
            redata = (0, -5, 0)
            return redata
        if redata[1] == self.sta.move_slider_resp:
            return redata

    
    def set_move(self, dir, rang_num):
        if (rang_num >= 0) & (rang_num < 65535):
            rang_buf = []
            rang_buf = split_to_bytes(rang_num)
            move_buf = self.set_move_buf(dir, rang_buf)
            delaytime = rang_num * 0.0132
            reactor = self.printer.get_reactor()
            reactor.pause(reactor.monotonic() + delaytime)
            self.gcode.respond_info('move_buf:%s' % move_buf[2])
            if move_buf[0] == 0:
                return None
            if move_buf[0] == 1:
                move_num_buf = move_buf[2][1:]
                move_num = bytes_to_int(move_num_buf)
                self.gcode.respond_info('move_num:%s' % move_num)
                self.gcode.respond_info('current_place:%s' % self.mdl.current_place)
                return move_num
        self.gcode.respond_info('move_num error:%s' % move_num)

    
    def init_adc_to_num(self):
        if (self.mdl.current_place == 0xFFFFFFFF) | (self.mdl.idl_adc == 0xFFFFFFFF) | (self.mdl.full_adc == 0xFFFFFFFF):
            if self.name == 'mdlx':
                raise self.printer.command_error('{"code":"key714", "msg":"Belt tension module strain gauge not calibrated abnormal: \'%s\'adc_to_num_error", "values": []}' % self.name)
            if self.name == 'mdly':
                raise self.printer.command_error('{"code":"key715", "msg":"Belt tension module strain gauge not calibrated abnormal: \'%s\'adc_to_num_error", "values": []}' % self.name)
        if (self.mdl.idl_adc == 0) | (self.mdl.full_adc == 0):
            if self.name == 'mdlx':
                raise self.printer.command_error('{"code":"key720", "msg":"The calibration value of the strain gauge is zero: \'%s\'calibration_num_error", "values": []}' % self.name)
            if self.name == 'mdly':
                raise self.printer.command_error('{"code":"key721", "msg":"The calibration value of the strain gauge is zero: \'%s\'calibration_num_error", "values": []}' % self.name)
        xd = [
            self.mdl.idl_adc,
            self.mdl.full_adc]
        yd = [
            self.mdl.adjustnum1,
            self.mdl.adjustnum2]
        xn = np.array(xd)
        yn = np.array(yd)
        coefficients = np.polyfit(xn, yn, 1)
        (slope, intercept) = coefficients
        self.mdl.slope = slope
        self.mdl.intercept = intercept
        self.gcode.respond_info('slope:%s' % slope)
        self.gcode.respond_info('intercept:%s' % intercept)

    
    def adc_to_num(self, adc_data):
        if (self.mdl.slope == 0) & (self.mdl.intercept == 0):
            return None
        adc_num = adc_data * self.mdl.slope + self.mdl.intercept
        self.mdl.current_tension = adc_num
        self.gcode.respond_info('pull_num:%s' % adc_num)
        if (adc_num > 600) | (adc_num < -300):
            if self.name == 'mdlx':
                raise self.printer.command_error('{"code":"key716", "msg":"Abnormal belt tension: \'%s\' pull_num_error", "values": []}' % self.name)
            if self.name == 'mdly':
                raise self.printer.command_error('{"code":"key717", "msg":"Abnormal belt tension: \'%s\' pull_num_error", "values": []}' % self.name)
        return adc_num

    
    def config_addr(self):
        self.com.addr = 34 if self.name == 'mdly' else 33

    
    def send_sensor_data(self, sen_fun, sen_data):
        self.com.len = len(sen_data) + 3
        self.com.data = sen_data
        self.com.fun = sen_fun
        self.com.crc = 0
        combuf = []
        combuf.append(self.com.head)
        combuf.append(self.com.addr)
        combuf.append(self.com.len)
        combuf.append(self.com.star)
        combuf.append(self.com.fun)
        combuf.extend(self.com.data)
        combuf.append(self.com.crc)
        return combuf

    
    def recv_sensor_data(self, rec_data):
        if rec_data == None:
            self.gcode.respond_info('reset:resetbuf is None')
            if self.name == 'mdlx':
                raise self.printer.command_error('{"code":"key712", "msg":"Communication abnormality of belt automatic tensioning module 485: \'%s\'", "values": []}' % self.name)
            if self.name == 'mdly':
                raise self.printer.command_error('{"code":"key713", "msg":"Communication abnormality of belt automatic tensioning module 485: \'%s\'", "values": []}' % self.name)
            return (0, -1, 0)
        if len(rec_data) < 3:
            self.gcode.respond_info('reset: <3')
            return (0, -2, 0)
        if rec_data[0] != self.com.head:
            self.gcode.respond_info('reset: head error')
            return (0, -3, 0)
        if rec_data[1] != self.com.addr:
            self.gcode.respond_info('reset: head error')
            return (0, -4, 0)
        leng = rec_data[2]
        sen_fun = rec_data[4]
        sen_data = rec_data[5:(leng - 3) + 5]
        return (1, sen_fun, sen_data)

    
    def send_data(self, hex_data):
        hexsendbuf = hex_data[1:-1]
        readbuf = self._serial.cmd_send_data_with_response(hexsendbuf, 1)
        return readbuf

    
    def get_status(self, eventime):
        return dict(tension=self.mdl.current_tension)



def load_config(config):
    prt = BELT_MDL(config)
    return prt


def load_config_prefix(config):
    prt = BELT_MDL(config)
    return prt

