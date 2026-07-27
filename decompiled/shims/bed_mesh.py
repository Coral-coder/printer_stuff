# Source Generated with Decompyle++
# File: bed_mesh.pyc (Python 3.9)

import logging
import math
import json
import collections
from . import probe
import mymodule.mymovie as mymovie
import numpy as np
PROFILE_VERSION = 1
PROFILE_OPTIONS = {
    'min_x': float,
    'max_x': float,
    'min_y': float,
    'max_y': float,
    'x_count': int,
    'y_count': int,
    'mesh_x_pps': int,
    'mesh_y_pps': int,
    'algo': str,
    'tension': float }

class BedMeshError(Exception):
    pass


def isclose(a, b, rel_tol = 1e-09, abs_tol = 0.0):
    return abs(a - b) <= max(rel_tol * max(abs(a), abs(b)), abs_tol)


def within(coord, min_c, max_c, tol = 0.0):
    return max_c[0] + tol >= coord[0] >= min_c[0] - tol and max_c[1] + tol >= coord[1] >= min_c[1] - tol


def constrain(val, min_val, max_val):
    return min(max_val, max(min_val, val))


def lerp(t, v0, v1):
    return (1.0 - t) * v0 + t * v1


def parse_config_pair(config, option, default, minval = None, maxval = None):
    pair = config.getintlist(option, (default, default))
    if len(pair) != 2:
        if len(pair) != 1:
            raise config.error("bed_mesh: malformed '%s' value: %s" % (option, config.get(option)))
        pair = (pair[0], pair[0])
    if minval is not None:
        if pair[0] < minval or pair[1] < minval:
            raise config.error("Option '%s' in section bed_mesh must have a minimum of %s" % (option, str(minval)))
    if maxval is not None:
        if pair[0] > maxval or pair[1] > maxval:
            raise config.error("Option '%s' in section bed_mesh must have a maximum of %s" % (option, str(maxval)))
    return pair


def parse_gcmd_pair(gcmd, name, minval = None, maxval = None):
    
    try:
        pair = [ int(v.strip()) for v in (gcmd.get(name).split(',')) ]
    except:
        raise gcmd.error("Unable to parse parameter '%s'" % (name,))

    if len(pair) != 2:
        if len(pair) != 1:
            raise gcmd.error("Unable to parse parameter '%s'" % (name,))
        pair = (pair[0], pair[0])
    if minval is not None:
        if pair[0] < minval or pair[1] < minval:
            raise gcmd.error("Parameter '%s' must have a minimum of %d" % (name, minval))
    if maxval is not None:
        if pair[0] > maxval or pair[1] > maxval:
            raise gcmd.error("Parameter '%s' must have a maximum of %d" % (name, maxval))
    return pair


def parse_gcmd_coord(gcmd, name):
    
    try:
        (v1, v2) = [ float(v.strip()) for v in (gcmd.get(name).split(',')) ]
    except:
        raise gcmd.error("Unable to parse parameter '%s'" % (name,))

    return (v1, v2)


class BedMesh:
    FADE_DISABLE = 2147483647
    
    def __init__(self, config):
        self._move_array = [
            0.0] * 13
        self.move_array = np.array(self._move_array, dtype=np.float64)
        self.move_array_addr_int = self.move_array.ctypes.data
        self.printer = config.get_printer()
        self.printer.register_event_handler('klippy:connect', self.handle_connect)
        self.last_position = [
            0.0,
            0.0,
            0.0,
            0.0]
        self.bmc = BedMeshCalibrate(config, self)
        self.z_mesh = None
        self.z_mesh_bak = None
        self.toolhead = None
        self.horizontal_move_z = config.getfloat('horizontal_move_z', 5.0)
        self._BedMesh__fade_start = config.getfloat('fade_start', 1.0)
        self._BedMesh__fade_end = config.getfloat('fade_end', 0.0)
        self._BedMesh__fade_dist = self._BedMesh__fade_end - self._BedMesh__fade_start
        if self._BedMesh__fade_dist <= 0.0:
            self._BedMesh__fade_start = self._BedMesh__fade_end = self.FADE_DISABLE
        self.log_fade_complete = False
        self.base_fade_target = config.getfloat('fade_target', None)
        self.fade_target = 0.0
        self.gcode = self.printer.lookup_object('gcode')
        self.splitter = mymovie.PyMoveSplitter(config.getfloat('split_delta_z', 0.025, minval=0.01), config.getfloat('move_check_distance', 5.0, minval=1.0))
        self.pmgr = ProfileManager(config, self)
        self.save_profile = self.pmgr.save_profile
        self.load_profile = self.pmgr.load_profile
        self.gcode.register_command('BED_MESH_OUTPUT', self.cmd_BED_MESH_OUTPUT, desc=self.cmd_BED_MESH_OUTPUT_help)
        self.gcode.register_command('BED_MESH_MAP', self.cmd_BED_MESH_MAP, desc=self.cmd_BED_MESH_MAP_help)
        self.gcode.register_command('BED_MESH_CLEAR', self.cmd_BED_MESH_CLEAR, desc=self.cmd_BED_MESH_CLEAR_help)
        self.gcode.register_command('BED_MESH_OFFSET', self.cmd_BED_MESH_OFFSET, desc=self.cmd_BED_MESH_OFFSET_help)
        self.gcode.register_command('BED_MESH_SAVE', self.cmd_BED_MESH_SAVE, desc=self.cmd_BED_MESH_SAVE_help)
        self.gcode.register_command('BED_MESH_RESTORE', self.cmd_BED_MESH_RESTORE, desc=self.cmd_BED_MESH_RESTORE_help)
        webhooks = self.printer.lookup_object('webhooks')
        webhooks.register_endpoint('get_mesh', self._get_mesh)
        webhooks.register_endpoint('update_mesh', self.update_mesh)
        gcode_move = self.printer.load_object(config, 'gcode_move')
        gcode_move.set_move_transform(self)
        self.update_status()
        self.move_array[9] = self._BedMesh__fade_start
        self.move_array[10] = self._BedMesh__fade_end
        self.move_array[11] = self._BedMesh__fade_dist

    
    def _get_mesh(self, web_request):
        probed_matrix = [
            []]

        try:
            probed_matrix = self.z_mesh.get_probed_matrix()
        except Exception as err:
            logging.error(err)
        web_request.send({
            'probed_matrix': probed_matrix })


    
    def update_mesh(self, web_request):
        probed_matrix = web_request.get('probed_matrix', [
            []])
        self.z_mesh.update_mesh_probed_matrix(probed_matrix)
        self.set_mesh(self.z_mesh)
        self.update_status()
        self.save_profile(self.pmgr.get_current_profile())
        self.load_profile(self.pmgr.get_current_profile())
        self.gcode.run_script_from_command('CXSAVE_CONFIG')
        probed_matrix = self.z_mesh.get_probed_matrix()
        web_request.send({
            'probed_matrix': probed_matrix })

    
    def handle_connect(self):
        self.toolhead = self.printer.lookup_object('toolhead')
        self.bmc.print_generated_points(logging.info)
        self.pmgr.initialize()

    
    def set_mesh(self, mesh):
        if mesh is not None and self._BedMesh__fade_end != self.FADE_DISABLE:
            self.log_fade_complete = True
            if self.base_fade_target is None:
                self.fade_target = mesh.avg_z
            else:
                self.fade_target = self.base_fade_target
                (min_z, max_z) = mesh.get_z_range()
                if not min_z <= self.fade_target <= max_z and self.fade_target != 0.0:
                    err_target = self.fade_target
                    self.z_mesh = None
                    self.fade_target = 0.0
                    raise self.gcode.error('bed_mesh: ERROR, fade_target lies outside of mesh z range\nmin: %.4f, max: %.4f, fade_target: %.4f' % (min_z, max_z, err_target))
            (min_z, max_z) = mesh.get_z_range()
            if self._BedMesh__fade_dist <= max(abs(min_z), abs(max_z)):
                self.z_mesh = None
                self.fade_target = 0.0
                raise self.gcode.error('bed_mesh:  Mesh extends outside of the fade range, please see the fade_start and fade_end options inexample-extras.cfg. fade distance: %.2f mesh min: %.4fmesh max: %.4f' % (self._BedMesh__fade_dist, min_z, max_z))
        else:
            self.fade_target = 0.0
        self.z_mesh = mesh
        if self.z_mesh is not None:
            self.splitter.initialize(mesh.info_array_addr_int, self.fade_target)
        else:
            self.splitter.initialize(0, self.fade_target)
        gcode_move = self.printer.lookup_object('gcode_move')
        gcode_move.reset_last_position()
        self.update_status()


    def get_z_factor(self, z_pos):
        if z_pos >= self._BedMesh__fade_end:
            return 0.0
        elif z_pos >= self._BedMesh__fade_start:
            return (self._BedMesh__fade_end - z_pos) / self._BedMesh__fade_dist
        else:
            return 1.0


    def get_position(self):
        if self.z_mesh is None:
            self.last_position[:] = self.toolhead.get_position()
            self.last_position[2] -= self.fade_target
        else:
            (x, y, z, e) = self.toolhead.get_position()
            max_adj = self.z_mesh.calc_z(x, y)
            factor = 1.0
            z_adj = max_adj - self.fade_target
            if min(z, z - max_adj) >= self._BedMesh__fade_end:
                factor = 0.0
            elif max(z, z - max_adj) >= self._BedMesh__fade_start:
                factor = (self._BedMesh__fade_end + self.fade_target - z) / (self._BedMesh__fade_dist - z_adj)
                factor = constrain(factor, 0.0, 1.0)
            final_z_adj = factor * z_adj + self.fade_target
            self.last_position[:] = [
                x,
                y,
                z - final_z_adj,
                e]
        return list(self.last_position)


    def set_z_temp_compensation(self):
        if self.z_mesh is None:
            return None
        self.z_mesh.set_z_temp_compensation()


    def move(self, newpos, speed):
        factor = mymovie.Py_get_z_factor(self.move_array_addr_int, newpos[2])
        if self.z_mesh is None or not factor:
            (x, y, z, e) = newpos
            if self.log_fade_complete:
                self.log_fade_complete = False
                logging.info('bed_mesh fade complete: Current Z: %.4f fade_target: %.4f ' % (z, self.fade_target))
            self.toolhead.move([
                x,
                y,
                z + self.fade_target,
                e], speed)
        else:
            self.move_array[0] = self.last_position[0]
            self.move_array[1] = self.last_position[1]
            self.move_array[2] = self.last_position[2]
            self.move_array[3] = self.last_position[3]
            self.move_array[4] = newpos[0]
            self.move_array[5] = newpos[1]
            self.move_array[6] = newpos[2]
            self.move_array[7] = newpos[3]
            self.move_array[8] = factor
            self.move_array[12] = speed
            self.set_z_temp_compensation()
            self.splitter.build_move(self.move_array_addr_int)
            while True:
                self.splitter.split_for_loop(self.move_array_addr_int)
                if self.move_array[4] == 0:
                    self.toolhead.simple_move(self.move_array[0:4])
                elif self.move_array[4] == 7:
                    break
                elif self.move_array[4] == -1:
                    raise self.gcode.error('bed_mesh: Slice distance is negative or greater than entire move length')
                elif self.move_array[4] == -2:
                    raise self.gcode.error('Mesh Leveling: Error splitting move ')
        self.last_position[:] = newpos


    def get_status(self, eventtime = None):
        return self.status


    def update_status(self):
        self.status = {
            'profile_name': '',
            'mesh_min': (0.0, 0.0),
            'mesh_max': (0.0, 0.0),
            'probed_matrix': [
                []],
            'mesh_matrix': [
                []],
            'profiles': self.pmgr.get_profiles() }
        if self.z_mesh is not None:
            params = self.z_mesh.get_mesh_params()
            mesh_min = (params['min_x'], params['min_y'])
            mesh_max = (params['max_x'], params['max_y'])
            probed_matrix = self.z_mesh.get_probed_matrix()
            mesh_matrix = self.z_mesh.get_mesh_matrix()
            self.status['profile_name'] = self.pmgr.get_current_profile()
            self.status['mesh_min'] = mesh_min
            self.status['mesh_max'] = mesh_max
            self.status['probed_matrix'] = probed_matrix
            self.status['mesh_matrix'] = mesh_matrix


    def get_mesh(self):
        return self.z_mesh

    cmd_BED_MESH_OUTPUT_help = 'Retrieve interpolated grid of probed z-points'

    def cmd_BED_MESH_OUTPUT(self, gcmd):
        if gcmd.get_int('PGP', 0):
            self.bmc.print_generated_points(gcmd.respond_info)
        elif self.z_mesh is None:
            gcmd.respond_info('Bed has not been probed')
        else:
            self.z_mesh.print_probed_matrix(gcmd.respond_info)
            self.z_mesh.print_mesh(gcmd.respond_raw, self.horizontal_move_z)

    cmd_BED_MESH_MAP_help = 'Serialize mesh and output to terminal'

    def cmd_BED_MESH_MAP(self, gcmd):
        if self.z_mesh is not None:
            params = self.z_mesh.get_mesh_params()
            outdict = {
                'mesh_min': (params['min_x'], params['min_y']),
                'mesh_max': (params['max_x'], params['max_y']),
                'z_positions': self.z_mesh.get_probed_matrix() }
            gcmd.respond_raw('mesh_map_output ' + json.dumps(outdict))
        else:
            gcmd.respond_info('Bed has not been probed')

    cmd_BED_MESH_CLEAR_help = 'Clear the Mesh so no z-adjustment is made'

    def cmd_BED_MESH_CLEAR(self, gcmd):
        self.set_mesh(None)

    cmd_BED_MESH_OFFSET_help = 'Add X/Y offsets to the mesh lookup'

    def cmd_BED_MESH_OFFSET(self, gcmd):
        if self.z_mesh is not None:
            offsets = [
                None,
                None]
            for (i, axis) in enumerate([
                'X',
                'Y']):
                offsets[i] = gcmd.get_float(axis, None)
            self.z_mesh.set_mesh_offsets(offsets)
            gcode_move = self.printer.lookup_object('gcode_move')
            gcode_move.reset_last_position()
        else:
            gcmd.respond_info('No mesh loaded to offset')

    cmd_BED_MESH_SAVE_help = 'Save the Mesh to bak'

    def cmd_BED_MESH_SAVE(self, gcmd):
        if self.z_mesh is not None:
            self.z_mesh_bak = self.z_mesh

    cmd_BED_MESH_RESTORE_help = 'Restore the bak Mesh to Mesh'

    def cmd_BED_MESH_RESTORE(self, gcmd):
        self.set_mesh(self.z_mesh_bak)

class BedMeshCalibrate:
    ALGOS = [
        'lagrange',
        'bicubic']

    def __init__(self, config, bedmesh):
        self.printer = config.get_printer()
        self.orig_config = {
            'radius': None,
            'origin': None }
        self.radius = self.origin = None
        self.mesh_min = self.mesh_max = (0.0, 0.0)
        self.relative_reference_index = config.getint('relative_reference_index', None)
        self.faulty_regions = []
        self.substituted_indices = collections.OrderedDict()
        self.orig_config['rri'] = self.relative_reference_index
        self.bedmesh = bedmesh
        self.mesh_config = collections.OrderedDict()
        self._init_mesh_config(config)
        self._generate_points(config.error)
        self._profile_name = None
        self.orig_points = self.points
        self.probe_helper = probe.ProbePointsHelper(config, self.probe_finalize, self._get_adjusted_points())
        self.probe_helper.minimum_points(3)
        self.probe_helper.use_xy_offsets(True)
        self.gcode = self.printer.lookup_object('gcode')
        self.gcode.register_command('BED_MESH_CALIBRATE', self.cmd_BED_MESH_CALIBRATE, desc=self.cmd_BED_MESH_CALIBRATE_help)

    def _generate_points(self, error):
        x_cnt = self.mesh_config['x_count']
        y_cnt = self.mesh_config['y_count']
        (min_x, min_y) = self.mesh_min
        (max_x, max_y) = self.mesh_max
        x_dist = (max_x - min_x) / (x_cnt - 1)
        y_dist = (max_y - min_y) / (y_cnt - 1)
        x_dist = math.floor(x_dist * 100) / 100
        y_dist = math.floor(y_dist * 100) / 100
        if x_dist < 1.0 or y_dist < 1.0:
            raise error('{"code":"key43", "msg":"bed_mesh: min/max points too close together", "values": []}')
        if self.radius is not None:
            y_dist = x_dist
            new_r = x_cnt // 2 * x_dist
            min_x = min_y = -new_r
            max_x = max_y = new_r
        else:
            max_x = min_x + x_dist * (x_cnt - 1)
        pos_y = min_y
        points = []
        for i in range(y_cnt):
            for j in range(x_cnt):
                if not i % 2:
                    pos_x = min_x + j * x_dist
                else:
                    pos_x = max_x - j * x_dist
                if self.radius is None:
                    points.append((pos_x, pos_y))
                else:
                    dist_from_origin = math.sqrt(pos_x * pos_x + pos_y * pos_y)
                    if dist_from_origin <= self.radius:
                        points.append((self.origin[0] + pos_x, self.origin[1] + pos_y))
            pos_y += y_dist
        self.points = points
        if not self.faulty_regions:
            return None
        last_y = self.points[0][1]
        is_reversed = False
        for (i, coord) in enumerate(self.points):
            if not isclose(coord[1], last_y):
                is_reversed = not is_reversed
            last_y = coord[1]
            adj_coords = []
            for (min_c, max_c) in self.faulty_regions:
                if within(coord, min_c, max_c, tol=1e-05):
                    adj_coords = [
                        (min_c[0], coord[1]),
                        (coord[0], min_c[1]),
                        (coord[0], max_c[1]),
                        (max_c[0], coord[1])]
                    if is_reversed:
                        first = adj_coords[0]
                        adj_coords[0] = adj_coords[-1]
                        adj_coords[-1] = first
                    break
            if not adj_coords:
                continue
            valid_coords = []
            for ac in adj_coords:
                if self.radius is None:
                    if within(ac, (min_x, min_y), (max_x, max_y), 1e-06):
                        valid_coords.append(ac)
                else:
                    dist_from_origin = math.sqrt(ac[0] * ac[0] + ac[1] * ac[1])
                    if dist_from_origin <= self.radius:
                        valid_coords.append(ac)
            if not valid_coords:
                raise error('bed_mesh: Unable to generate coordinates for faulty region at index: %d' % i)
            self.substituted_indices[i] = valid_coords

    def print_generated_points(self, print_func):
        x_offset = y_offset = 0.0
        probe = self.printer.lookup_object('probe', None)
        if probe is not None:
            (x_offset, y_offset) = probe.get_offsets()[:2]
        print_func('bed_mesh: generated points\nIndex |  Tool Adjusted  |   Probe')
        for (i, (x, y)) in enumerate(self.points):
            adj_pt = '(%.1f, %.1f)' % (x - x_offset, y - y_offset)
            mesh_pt = '(%.1f, %.1f)' % (x, y)
            print_func('  %-4d| %-16s| %s' % (i, adj_pt, mesh_pt))
        if self.relative_reference_index is not None:
            rri = self.relative_reference_index
            print_func('bed_mesh: relative_reference_index %d is (%.2f, %.2f)' % (rri, self.points[rri][0], self.points[rri][1]))
        if self.substituted_indices:
            print_func('bed_mesh: faulty region points')
            for (i, v) in self.substituted_indices.items():
                pt = self.points[i]
                print_func('%d (%.2f, %.2f), substituted points: %s' % (i, pt[0], pt[1], repr(v)))

    def _init_mesh_config(self, config):
        mesh_cfg = self.mesh_config
        orig_cfg = self.orig_config
        self.radius = config.getfloat('mesh_radius', None, above=0.0)
        if self.radius is not None:
            self.origin = config.getfloatlist('mesh_origin', (0.0, 0.0), count=2)
            x_cnt = y_cnt = config.getint('round_probe_count', 5, minval=3)
            if not x_cnt & 1:
                raise config.error('bed_mesh: probe_count must be odd for round beds')
            self.radius = math.floor(self.radius * 10) / 10
            orig_cfg['radius'] = self.radius
            orig_cfg['origin'] = self.origin
            min_x = min_y = -self.radius
            max_x = max_y = self.radius
        else:
            (x_cnt, y_cnt) = parse_config_pair(config, 'probe_count', 3, minval=3)
            (min_x, min_y) = config.getfloatlist('mesh_min', count=2)
            (max_x, max_y) = config.getfloatlist('mesh_max', count=2)
            if max_x <= min_x or max_y <= min_y:
                raise config.error('bed_mesh: invalid min/max points')
        orig_cfg['x_count'] = mesh_cfg['x_count'] = x_cnt
        orig_cfg['y_count'] = mesh_cfg['y_count'] = y_cnt
        orig_cfg['mesh_min'] = self.mesh_min = (min_x, min_y)
        orig_cfg['mesh_max'] = self.mesh_max = (max_x, max_y)
        pps = parse_config_pair(config, 'mesh_pps', 2, minval=0)
        orig_cfg['mesh_x_pps'] = mesh_cfg['mesh_x_pps'] = pps[0]
        orig_cfg['mesh_y_pps'] = mesh_cfg['mesh_y_pps'] = pps[1]
        orig_cfg['algo'] = mesh_cfg['algo'] = config.get('algorithm', 'lagrange').strip().lower()
        orig_cfg['tension'] = mesh_cfg['tension'] = config.getfloat('bicubic_tension', 0.2, minval=0.0, maxval=2.0)
        for i in list(range(1, 100, 1)):
            start = config.getfloatlist('faulty_region_%d_min' % (i,), None, count=2)
            if start is None:
                break
            end = config.getfloatlist('faulty_region_%d_max' % (i,), count=2)
            c1 = [ min([s, e]) for (s, e) in zip(start, end) ]
            c3 = [ max([s, e]) for (s, e) in zip(start, end) ]
            c2 = [
                c1[0],
                c3[1]]
            c4 = [
                c3[0],
                c1[1]]
            for (j, (prev_c1, prev_c3)) in enumerate(self.faulty_regions):
                prev_c2 = [
                    prev_c1[0],
                    prev_c3[1]]
                prev_c4 = [
                    prev_c3[0],
                    prev_c1[1]]
                for coord in (prev_c1, prev_c2, prev_c3, prev_c4):
                    if within(coord, c1, c3):
                        raise config.error('bed_mesh: Existing faulty_region_%d %s overlaps added faulty_region_%d %s' % (j + 1, repr([prev_c1, prev_c3]), i, repr([c1, c3])))
                for coord in (c1, c2, c3, c4):
                    if within(coord, prev_c1, prev_c3):
                        raise config.error('bed_mesh: Added faulty_region_%d %s overlaps existing faulty_region_%d %s' % (i, repr([c1, c3]), j + 1, repr([prev_c1, prev_c3])))
            self.faulty_regions.append((c1, c3))
        self._verify_algorithm(config.error)

    def _verify_algorithm(self, error):
        params = self.mesh_config
        x_pps = params['mesh_x_pps']
        y_pps = params['mesh_y_pps']
        if params['algo'] not in self.ALGOS:
            raise error('bed_mesh: Unknown algorithm <%s>' % self.mesh_config['algo'])
        max_probe_cnt = max(params['x_count'], params['y_count'])
        min_probe_cnt = min(params['x_count'], params['y_count'])
        if max(x_pps, y_pps) == 0:
            self.mesh_config['algo'] = 'direct'
        elif params['algo'] == 'lagrange' and max_probe_cnt > 6:
            raise error('bed_mesh: cannot exceed a probe_count of 6 when using lagrange interpolation. Configured Probe Count: %d, %d' % (self.mesh_config['x_count'], self.mesh_config['y_count']))
        elif params['algo'] == 'bicubic' and min_probe_cnt < 4:
            if max_probe_cnt > 6:
                raise error('bed_mesh: invalid probe_count option when using bicubic interpolation.  Combination of 3 points on one axis with more than 6 on another is not permitted. Configured Probe Count: %d, %d' % (self.mesh_config['x_count'], self.mesh_config['y_count']))
            else:
                logging.info('bed_mesh: bicubic interpolation with a probe_count of less than 4 points detected.  Forcing lagrange interpolation. Configured Probe Count: %d, %d' % (self.mesh_config['x_count'], self.mesh_config['y_count']))
                params['algo'] = 'lagrange'

    def update_config(self, gcmd):
        self.radius = self.orig_config['radius']
        self.origin = self.orig_config['origin']
        self.relative_reference_index = self.orig_config['rri']
        self.mesh_min = self.orig_config['mesh_min']
        self.mesh_max = self.orig_config['mesh_max']
        for key in list(self.mesh_config.keys()):
            self.mesh_config[key] = self.orig_config[key]
        params = gcmd.get_command_parameters()
        need_cfg_update = False
        if 'RELATIVE_REFERENCE_INDEX' in params:
            self.relative_reference_index = gcmd.get_int('RELATIVE_REFERENCE_INDEX')
            if self.relative_reference_index < 0:
                self.relative_reference_index = None
            need_cfg_update = True
        if self.radius is not None:
            if 'MESH_RADIUS' in params:
                self.radius = gcmd.get_float('MESH_RADIUS')
                self.radius = math.floor(self.radius * 10) / 10
                self.mesh_min = (-self.radius, -self.radius)
                self.mesh_max = (self.radius, self.radius)
                need_cfg_update = True
            if 'MESH_ORIGIN' in params:
                self.origin = parse_gcmd_coord(gcmd, 'MESH_ORIGIN')
                need_cfg_update = True
            if 'ROUND_PROBE_COUNT' in params:
                cnt = gcmd.get_int('ROUND_PROBE_COUNT', minval=3)
                self.mesh_config['x_count'] = cnt
                self.mesh_config['y_count'] = cnt
                need_cfg_update = True
        else:
            if 'MESH_MIN' in params:
                self.mesh_min = parse_gcmd_coord(gcmd, 'MESH_MIN')
                need_cfg_update = True
            if 'MESH_MAX' in params:
                self.mesh_max = parse_gcmd_coord(gcmd, 'MESH_MAX')
                need_cfg_update = True
            if 'PROBE_COUNT' in params:
                (x_cnt, y_cnt) = parse_gcmd_pair(gcmd, 'PROBE_COUNT', minval=3)
                self.mesh_config['x_count'] = x_cnt
                self.mesh_config['y_count'] = y_cnt
                need_cfg_update = True
        if 'ALGORITHM' in params:
            self.mesh_config['algo'] = gcmd.get('ALGORITHM').strip().lower()
            need_cfg_update = True
        if need_cfg_update:
            self._verify_algorithm(gcmd.error)
            self._generate_points(gcmd.error)
            gcmd.respond_info('Generating new points...')
            self.print_generated_points(gcmd.respond_info)
            pts = self._get_adjusted_points()
            self.probe_helper.update_probe_points(pts, 3)
            msg = 'relative_reference_index: %s\n' % self.relative_reference_index
            msg += '\n'.join([ '%s: %s' % (k, v) for (k, v) in self.mesh_config.items() ])
            logging.info('Updated Mesh Configuration:\n' + msg)
        else:
            self.points = self.orig_points
            pts = self._get_adjusted_points()
            self.probe_helper.update_probe_points(pts, 3)

    def _get_adjusted_points(self):
        if not self.substituted_indices:
            return self.points
        adj_pts = []
        last_index = 0
        for (i, pts) in self.substituted_indices.items():
            adj_pts.extend(self.points[last_index:i])
            adj_pts.extend(pts)
            last_index = i + 1
        adj_pts.extend(self.points[last_index:])
        return adj_pts

    cmd_BED_MESH_CALIBRATE_help = 'Perform Mesh Bed Leveling'

    def cmd_BED_MESH_CALIBRATE(self, gcmd):
        self._profile_name = gcmd.get('PROFILE', 'default')
        if not self._profile_name.strip():
            raise gcmd.error("Value for parameter 'PROFILE' must be specified")
        self.bedmesh.set_mesh(None)
        self.update_config(gcmd)
        self.probe_helper.start_probe(gcmd)

    def probe_finalize(self, offsets, positions):
        (x_offset, y_offset, z_offset) = offsets
        positions = [ [
            round(p[0], 2),
            round(p[1], 2),
            p[2]] for p in positions ]
        params = dict(self.mesh_config)
        params['min_x'] = min(positions, key=lambda p: p[0])[0] + x_offset
        params['max_x'] = max(positions, key=lambda p: p[0])[0] + x_offset
        params['min_y'] = min(positions, key=lambda p: p[1])[1] + y_offset
        params['max_y'] = max(positions, key=lambda p: p[1])[1] + y_offset
        x_cnt = params['x_count']
        y_cnt = params['y_count']
        if self.substituted_indices:
            corrected_pts = []
            idx_offset = 0
            start_idx = 0
            for (i, pts) in self.substituted_indices.items():
                fpt = [ p - o for (p, o) in zip(self.points[i], offsets[:2]) ]
                idx = i + idx_offset
                corrected_pts.extend(positions[start_idx:idx])
                avg_z = sum([ p[2] for p in positions[idx:idx + len(pts)] ]) / len(pts)
                idx_offset += len(pts) - 1
                start_idx = idx + len(pts)
                fpt.append(avg_z)
                logging.info('bed_mesh: Replacing value at faulty index %d (%.4f, %.4f): avg value = %.6f, avg w/ z_offset = %.6f' % (i, fpt[0], fpt[1], avg_z, avg_z - z_offset))
                corrected_pts.append(fpt)
            corrected_pts.extend(positions[start_idx:])
            if len(self.points) != len(corrected_pts):
                self._dump_points(positions, corrected_pts, offsets)
                raise self.gcode.error('bed_mesh: invalid position list size, generated count: %d, probed count: %d' % (len(self.points), len(corrected_pts)))
            for (gen_pt, probed) in zip(self.points, corrected_pts):
                off_pt = [ p - o for (p, o) in zip(gen_pt, offsets[:2]) ]
                if not (isclose(off_pt[0], probed[0], abs_tol=0.1) and isclose(off_pt[1], probed[1], abs_tol=0.1)):
                    self._dump_points(positions, corrected_pts, offsets)
                    raise self.gcode.error('bed_mesh: point mismatch, orig = (%.2f, %.2f), probed = (%.2f, %.2f)' % (off_pt[0], off_pt[1], probed[0], probed[1]))
            positions = corrected_pts
        if self.relative_reference_index is not None:
            z_offset = positions[self.relative_reference_index][2]
        probed_matrix = []
        row = []
        prev_pos = positions[0]
        for pos in positions:
            if not isclose(pos[1], prev_pos[1], abs_tol=0.1):
                probed_matrix.append(row)
                row = []
            if pos[0] > prev_pos[0]:
                row.append(pos[2] - z_offset)
            else:
                row.insert(0, pos[2] - z_offset)
            prev_pos = pos
        probed_matrix.append(row)
        if len(probed_matrix) != y_cnt:
            raise self.gcode.error('bed_mesh: Invalid y-axis table length\nProbed table length: %d Probed Table:\n%s' % (len(probed_matrix), str(probed_matrix)))
        if self.radius is not None:
            for row in probed_matrix:
                row_size = len(row)
                if not row_size & 1:
                    msg = 'bed_mesh: incorrect number of points sampled on X\n'
                    msg += 'Probed Table:\n'
                    msg += str(probed_matrix)
                    raise self.gcode.error(msg)
                buf_cnt = (x_cnt - row_size) // 2
                if buf_cnt == 0:
                    continue
                left_buffer = [
                    row[0]] * buf_cnt
                right_buffer = [
                    row[row_size - 1]] * buf_cnt
                row[0:0] = left_buffer
                row.extend(right_buffer)
        for row in probed_matrix:
            if len(row) != x_cnt:
                raise self.gcode.error('bed_mesh: invalid x-axis table length\nProbed table length: %d Probed Table:\n%s' % (len(probed_matrix), str(probed_matrix)))
        z_mesh = ZMesh(params, self.printer)
        try:
            z_mesh.build_mesh(probed_matrix)
        except BedMeshError as e:
            raise self.gcode.error(str(e))
        self.bedmesh.set_mesh(z_mesh)
        self.gcode.respond_info('Mesh Bed Leveling Complete')
        self.bedmesh.save_profile(self._profile_name)

    def _dump_points(self, probed_pts, corrected_pts, offsets):
        max_len = max([
            len(self.points),
            len(probed_pts),
            len(corrected_pts)])
        logging.info('bed_mesh: calibration point dump\nIndex | %-17s| %-25s| Corrected Point' % ('Generated Point', 'Probed Point'))
        for i in list(range(max_len)):
            gen_pt = probed_pt = corr_pt = ''
            if i < len(self.points):
                off_pt = [ p - o for (p, o) in zip(self.points[i], offsets[:2]) ]
                gen_pt = '(%.2f, %.2f)' % tuple(off_pt)
            if i < len(probed_pts):
                probed_pt = '(%.2f, %.2f, %.4f)' % tuple(probed_pts[i])
            if i < len(corrected_pts):
                corr_pt = '(%.2f, %.2f, %.4f)' % tuple(corrected_pts[i])
            logging.info('  %-4d| %-17s| %-25s| %s' % (i, gen_pt, probed_pt, corr_pt))
