# Source Generated with Decompyle++
# File: bed_mesh.pyc (Python 3.9)

import logging
import math
import json
import collections
from . import probe
from mymodule.mymovie import mymovie
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


def isclose(a, b, rel_tol, abs_tol = (1e-09, 0)):
    return abs(a - b) <= max(rel_tol * max(abs(a), abs(b)), abs_tol)


def within(coord, min_c, max_c, tol = (0,)):
    if coord[0] >= coord[0]:
        pass
    elif coord[0] >= min_c[0] - tol:
        if coord[1] >= coord[1]:
            return coord[1] >= min_c[1] - tol
        coord[1] >= coord[1]
    return coord[1]


def constrain(val, min_val, max_val):
    return min(max_val, max(min_val, val))


def lerp(t, v0, v1):
    return (1 - t) * v0 + t * v1


def parse_config_pair(config, option, default, minval, maxval = (None, None)):
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


def parse_gcmd_pair(gcmd, name, minval, maxval = (None, None)):
    
    try:
        pair = [ int(v.strip()) for v in (gcmd.get(name).split(',')) ]
    finally:
        pass
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
    finally:
        pass
    raise gcmd.error("Unable to parse parameter '%s'" % (name,))
    return (v1, v2)



class BedMesh:
    FADE_DISABLE = 2147483647
    
    def __init__(self, config):
        self._move_array = [
            0] * 13
        self.move_array = np.array(self._move_array, dtype=np.float64)
        self.move_array_addr_int = self.move_array.ctypes.data
        self.printer = config.get_printer()
        self.printer.register_event_handler('klippy:connect', self.handle_connect)
        self.last_position = [
            0,
            0,
            0,
            0]
        self.bmc = BedMeshCalibrate(config, self)
        self.z_mesh = None
        self.z_mesh_bak = None
        self.toolhead = None
        self.horizontal_move_z = config.getfloat('horizontal_move_z', 5)
        self._BedMesh__fade_start = config.getfloat('fade_start', 1)
        self._BedMesh__fade_end = config.getfloat('fade_end', 0)
        self._BedMesh__fade_dist = self._BedMesh__fade_end - self._BedMesh__fade_start
        if self._BedMesh__fade_dist <= 0:
            self._BedMesh__fade_start = self._BedMesh__fade_end = self.FADE_DISABLE
        self.log_fade_complete = False
        self.base_fade_target = config.getfloat('fade_target', None)
        self.fade_target = 0
        self.gcode = self.printer.lookup_object('gcode')
        self.splitter = mymovie.PyMoveSplitter(config.getfloat('split_delta_z', 0.025, minval=0.01), config.getfloat('move_check_distance', 5, minval=1))
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
    # WARNING: Decompyle incomplete

    
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
                if not self.fade_target <= self.fade_target or self.fade_target <= max_z:
                    pass
                else:
                    min_z
                if self.fade_target != 0:
                    err_target = self.fade_target
                    self.z_mesh = None
                    self.fade_target = 0
                    raise self.gcode.error('bed_mesh: ERROR, fade_target lies outside of mesh z range\nmin: %.4f, max: %.4f, fade_target: %.4f' % (min_z, max_z, err_target))
            (min_z, max_z) = mesh.get_z_range()
            if self._BedMesh__fade_dist <= max(abs(min_z), abs(max_z)):
                self.z_mesh = None
                self.fade_target = 0
                raise self.gcode.error('bed_mesh:  Mesh extends outside of the fade range, please see the fade_start and fade_end options inexample-extras.cfg. fade distance: %.2f mesh min: %.4fmesh max: %.4f' % (self._BedMesh__fade_dist, min_z, max_z))
        else:
            self.fade_target = 0
        self.z_mesh = mesh
        if self.z_mesh is not None:
            self.splitter.initialize(mesh.info_array_addr_int, self.fade_target)
        else:
            self.splitter.initialize(0, self.fade_target)
        gcode_move = self.printer.lookup_object('gcode_move')
        gcode_move.reset_last_position()
        self.update_status()

    
    def get_z_factor(self, z_pos):
        if z_pos >= self._Be