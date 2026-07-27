# =====================================================================
# PARTIAL DECOMPILATION -- this module did not fully round-trip.
# The 3.9 bytecode uses control flow the decompiler could not fully
# reconstruct (e.g. try/except/else with returns, or a generator with a
# dropped builtin rendered as `None(...)`). The code below is best-effort
# and will not import as-is. Ground-truth disassembly for repair:
#     decompiled/_disasm/delta_calibrate.txt
# =====================================================================

# Source Generated with Decompyle++
# File: delta_calibrate.pyc (Python 3.9)

import math
import logging
import collections
import mathutil
from . import probe

def load_config_stable(config, option):
    return config.getfloatlist(option, count=3)

MeasureAngles = [
    2.1e+02,
    2.7e+02,
    3.3e+02,
    3e+01,
    9e+01,
    1.5e+02]
MeasureOuterRadius = 65
MeasureRidgeRadius = 4.5
MEASURE_WEIGHT = 0.5

def measurements_to_distances(measured_params, delta_params):
    mp = measured_params
    dp = delta_params
    scale = mp['SCALE'][0]
    cpw = mp['CENTER_PILLAR_WIDTHS']
    center_widths = [
        cpw[0],
        cpw[2],
        cpw[1],
        cpw[0],
        cpw[2],
        cpw[1]]
    center_dists = [ od - cw for od, cw in (zip(mp['CENTER_DISTS'], center_widths)) ]
    outer_dists = [ od - opw for od, opw in (zip(mp['OUTER_DISTS'], mp['OUTER_PILLAR_WIDTHS'])) ]
    obj_angles = list(map(math.radians, MeasureAngles))
    xy_angles = list(zip(map(math.cos, obj_angles), map(math.sin, obj_angles)))
    inner_ridge = MeasureRidgeRadius * scale
    inner_pos = [ (ax * inner_ridge, ay * inner_ridge, 0.0) for ax, ay in (xy_angles) ]
    outer_ridge = (MeasureOuterRadius + MeasureRidgeRadius) * scale
    outer_pos = [ (ax * outer_ridge, ay * outer_ridge, 0.0) for ax, ay in (xy_angles) ]
    center_positions = [ (cd, dp.calc_stable_position(ip), dp.calc_stable_position(op)) for cd, ip, op in (zip(center_dists, inner_pos, outer_pos)) ]
    outer_center = MeasureOuterRadius * scale
    start_pos = [ (ax * outer_center, ay * outer_center) for ax, ay in (xy_angles) ]
    shifted_angles = xy_angles[2:] + xy_angles[:2]
    first_pos = [ (ax * inner_ridge + spx, ay * inner_ridge + spy, 0.0) for (ax, ay), (spx, spy) in (zip(shifted_angles, start_pos)) ]
    second_pos = [ (ax * outer_ridge + spx, ay * outer_ridge + spy, 0.0) for (ax, ay), (spx, spy) in (zip(shifted_angles, start_pos)) ]
    outer_positions = [ (od, dp.calc_stable_position(fp), dp.calc_stable_position(sp)) for od, fp, sp in (zip(outer_dists, first_pos, second_pos)) ]
    return center_positions + outer_positions


class DeltaCalibrate:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        self.printer.register_event_handler('klippy:connect', self.handle_connect)
        radius = config.getfloat('radius', above=0.0)
        points = [
            (0.0, 0.0)]
        scatter = [
            0.95,
            0.9,
            0.85,
            0.7,
            0.75,
            0.8]
        for i in range(6):
            r = math.radians(9e+01 + 6e+01 * i)
            dist = radius * scatter[i]
            points.append((math.cos(r) * dist, math.sin(r) * dist))
        self.probe_helper = probe.ProbePointsHelper(config, self.probe_finalize, default_points=points)
        self.probe_helper.minimum_points(3)
        self.last_probe_positions = []
        for i in range(999):
            height = config.getfloat('height%d' % (i,), None)
            if height is None:
                break
            height_pos = load_config_stable(config, 'height%d_pos' % (i,))
            self.last_probe_positions.append((height, height_pos))
        self.manual_heights = []
        for i in range(999):
            height = config.getfloat('manual_height%d' % (i,), None)
            if height is None:
                break
            height_pos = load_config_stable(config, 'manual_height%d_pos' % (i,))
            self.manual_heights.append((height, height_pos))
        self.delta_analyze_entry = {
            'SCALE': (1.0,) }
        self.last_distances = []
        for i in range(999):
            dist = config.getfloat('distance%d' % (i,), None)
            if dist is None:
                break
            distance_pos1 = load_config_stable(config, 'distance%d_pos1' % (i,))
            distance_pos2 = load_config_stable(config, 'distance%d_pos2' % (i,))
            self.last_distances.append((dist, distance_pos1, distance_pos2))
        self.gcode = self.printer.lookup_object('gcode')
        self.gcode.register_command('DELTA_CALIBRATE', self.cmd_DELTA_CALIBRATE, desc=self.cmd_DELTA_CALIBRATE_help)
        self.gcode.register_command('DELTA_ANALYZE', self.cmd_DELTA_ANALYZE, desc=self.cmd_DELTA_ANALYZE_help)

    
    def handle_connect(self):
        kin = self.printer.lookup_object('toolhead').get_kinematics()
        if not hasattr(kin, 'get_calibration'):
            raise self.printer.config_error('Delta calibrate is only for delta printers')

    
    def save_state(self, probe_positions, distances, delta_params):
        configfile = self.printer.lookup_object('configfile')
        delta_params.save_state(configfile)
        section = 'delta_calibrate'
        configfile.remove_section(section)
        for i, (z_offset, spos) in enumerate(probe_positions):
            configfile.set(section, 'height%d' % (i,), z_offset)
            configfile.set(section, 'height%d_pos' % (i,), '%.3f,%.3f,%.3f' % tuple(spos))
        for i, (z_offset, spos) in enumerate(self.manual_heights):
            configfile.set(section, 'manual_height%d' % (i,), z_offset)
            configfile.set(section, 'manual_height%d_pos' % (i,), '%.3f,%.3f,%.3f' % tuple(spos))
        for i, (dist, spos1, spos2) in enumerate(distances):
            configfile.set(section, 'distance%d' % (i,), dist)
            configfile.set(section, 'distance%d_pos1' % (i,), '%.3f,%.3f,%.3f' % tuple(spos1))
            configfile.set(section, 'distance%d_pos2' % (i,), '%.3f,%.3f,%.3f' % tuple(spos2))

    
    def probe_finalize(self, offsets, positions):
        z_offset = offsets[2]
        kin = self.printer.lookup_object('toolhead').get_kinematics()
        delta_params = kin.get_calibration()
        probe_positions = [ (z_offset, delta_params.calc_stable_position(p)) for p in (positions) ]
        self.calculate_params(probe_positions, self.last_distances)

    
    def calculate_params(self, probe_positions, distances):
        height_positions = self.manual_heights + probe_positions
        kin = self.printer.lookup_object('toolhead').get_kinematics()
        orig_delta_params = odp = kin.get_calibration()
        (adj_params, params) = odp.coordinate_descent_params(distances)
        logging.info('Calculating delta_calibrate with:\n%s\n%s\nInitial delta_calibrate parameters: %s', height_positions, distances, params)
        z_weight = 1.0
        if distances:
            z_weight = len(distances) / (MEASURE_WEIGHT * len(probe_positions))
        
        def delta_errorfunc(params):
            
            try:
                delta_params = orig_delta_params.new_calibration(params)
                getpos = delta_params.get_position_from_stable
                total_error = 0.0
                for z_offset, stable_pos in height_positions:
                    (x, y, z) = getpos(stable_pos)
                    total_error += (z - z_offset) ** 2
                total_error *= z_weight
                for dist, stable_pos1, stable_pos2 in distances:
                    (x1, y1, z1) = getpos(stable_pos1)
                    (x2, y2, z2) = getpos(stable_pos2)
                    d = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2 + (z1 - z2) ** 2)
                    total_error += (d - dist) ** 2
                return total_error
            except ValueError:
                return 9999999999999.9


        new_params = mathutil.background_coordinate_descent(self.printer, adj_params, params, delta_errorfunc)
        logging.info('Calculated delta_calibrate parameters: %s', new_params)
        new_delta_params = orig_delta_params.new_calibration(new_params)
        for z_offset, spos in height_positions:
            logging.info('height orig: %.6f new: %.6f goal: %.6f', orig_delta_params.get_position_from_stable(spos)[2], new_delta_params.get_position_from_stable(spos)[2], z_offset)
        for dist, spos1, spos2 in distances:
            (x1, y1, z1) = orig_delta_params.get_position_from_stable(spos1)
            (x2, y2, z2) = orig_delta_params.get_position_from_stable(spos2)
            orig_dist = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2 + (z1 - z2) ** 2)
            (x1, y1, z1) = new_delta_params.get_position_from_stable(spos1)
            (x2, y2, z2) = new_delta_params.get_position_from_stable(spos2)
            new_dist = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2 + (z1 - z2) ** 2)
            logging.info('distance orig: %.6f new: %.6f goal: %.6f', orig_dist, new_dist, dist)
        self.save_state(probe_positions, distances, new_delta_params)
        self.gcode.respond_info('The SAVE_CONFIG command will update the printer config file\nwith these parameters and restart the printer.')

    cmd_DELTA_CALIBRATE_help = 'Delta calibration script'
    
    def cmd_DELTA_CALIBRATE(self, gcmd):
        self.probe_helper.start_probe(gcmd)

    
    def add_manual_height(self, height):
        toolhead = self.printer.lookup_object('toolhead')
        toolhead.flush_step_generation()
        kin = toolhead.get_kinematics()
        kin_spos = { s.get_name(): s.get_commanded_position() for s in (kin.get_steppers()) }
        kin_pos = kin.calc_position(kin_spos)
        delta_params = kin.get_calibration()
        stable_pos = tuple(delta_params.calc_stable_position(kin_pos))
        self.manual_heights.append((height, stable_pos))
        self.gcode.respond_info('Adding manual height: %.3f,%.3f,%.3f is actually z=%.3f' % (kin_pos[0], kin_pos[1], kin_pos[2], height))

    
    def do_extended_calibration(self):
        if len(self.delta_analyze_entry) <= 1:
            distances = self.last_distances
        elif len(self.delta_analyze_entry) < 5:
            raise self.gcode.error('Not all measurements provided')
        else:
            kin = self.printer.lookup_object('toolhead').get_kinematics()
            delta_params = kin.get_calibration()
            distances = measurements_to_distances(self.delta_analyze_entry, delta_params)
        if not self.last_probe_positions:
            raise self.gcode.error('Must run basic calibration with DELTA_CALIBRATE first')
        self.calculate_params(self.last_probe_positions, distances)

    cmd_DELTA_ANALYZE_help = 'Extended delta calibration tool'
    
    def cmd_DELTA_ANALYZE(self, gcmd):
        mheight = gcmd.get_float('MANUAL_HEIGHT', None)
        if mheight is not None:
            self.add_manual_height(mheight)
            return None
        args = {
            'CENTER_DISTS': 6,
            'CENTER_PILLAR_WIDTHS': 3,
            'OUTER_DISTS': 6,
            'OUTER_PILLAR_WIDTHS': 6,
            'SCALE': 1 }
        for name, count in args.items():
            data = gcmd.get(name, None)
            if data is None:
                continue
            
            try:
                parts = list(map(float, data.split(',')))
            except:
                raise gcmd.error("Unable to parse parameter '%s'" % (name,))

            if len(parts) != count:
                raise gcmd.error("Parameter '%s' must have %d values" % (name, count))
            self.delta_analyze_entry[name] = parts
            logging.info('DELTA_ANALYZE %s = %s', name, parts)
        action = gcmd.get('CALIBRATE', None)
        if action is not None:
            if action != 'extended':
                raise gcmd.error('Unknown calibrate action')
            self.do_extended_calibration()



def load_config(config):
    return DeltaCalibrate(config)

