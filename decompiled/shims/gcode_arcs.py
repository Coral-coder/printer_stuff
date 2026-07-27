# Source Generated with Decompyle++
# File: gcode_arcs.pyc (Python 3.9)

import math
ARC_PLANE_X_Y = 0
ARC_PLANE_X_Z = 1
ARC_PLANE_Y_Z = 2
X_AXIS = 0
Y_AXIS = 1
Z_AXIS = 2
E_AXIS = 3

class ArcSupport:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        self.accuracy = config.getfloat('resolution', 0.012, above=0.0)
        self.mm_per_arc_segment = config.getfloat('max_mm_per_arc_segment', 1.0, above=0.0)
        self.min_mm_per_arc_segment = config.getfloat('min_mm_per_arc_segment', 0.1, above=0.0)
        self.n_arc_revise = config.getfloat('n_arc_revise', 25.0, above=0.0)
        self.gcode_move = self.printer.load_object(config, 'gcode_move')
        self.gcode = self.printer.lookup_object('gcode')
        self.gcode.register_command('G2', self.cmd_G2)
        self.gcode.register_command('G3', self.cmd_G3)
        self.gcode.register_command('G17', self.cmd_G17)
        self.gcode.register_command('G18', self.cmd_G18)
        self.gcode.register_command('G19', self.cmd_G19)
        self.Coord = self.gcode.Coord
        self.plane = ARC_PLANE_X_Y

    
    def cmd_G2(self, gcmd):
        self._cmd_inner(gcmd, True)

    
    def cmd_G3(self, gcmd):
        self._cmd_inner(gcmd, False)

    
    def cmd_G17(self, gcmd):
        self.plane = ARC_PLANE_X_Y

    
    def cmd_G18(self, gcmd):
        self.plane = ARC_PLANE_X_Z

    
    def cmd_G19(self, gcmd):
        self.plane = ARC_PLANE_Y_Z

    
    def _cmd_inner(self, gcmd, clockwise):
        gcodestatus = self.gcode_move.get_status()
        if not gcodestatus['absolute_coordinates']:
            raise gcmd.error('G2/G3 does not support relative move mode')
        currentPos = gcodestatus['gcode_position']
        absolut_extrude = gcodestatus['absolute_extrude']
        asTarget = [
            gcmd.get_float('X', currentPos[0]),
            gcmd.get_float('Y', currentPos[1]),
            gcmd.get_float('Z', currentPos[2])]
        if gcmd.get_float('R', None) is not None:
            raise gcmd.error('G2/G3 does not support R moves')
        I = gcmd.get_float('I', 0.0)
        J = gcmd.get_float('J', 0.0)
        asPlanar = (I, J)
        axes = (X_AXIS, Y_AXIS, Z_AXIS)
        if self.plane == ARC_PLANE_X_Z:
            K = gcmd.get_float('K', 0.0)
            asPlanar = (I, K)
            axes = (X_AXIS, Z_AXIS, Y_AXIS)
        elif self.plane == ARC_PLANE_Y_Z:
            K = gcmd.get_float('K', 0.0)
            asPlanar = (J, K)
            axes = (Y_AXIS, Z_AXIS, X_AXIS)
        if not asPlanar[0] and not asPlanar[1]:
            raise gcmd.error('G2/G3 requires IJ, IK or JK parameters')
        self.planArc(currentPos, asTarget, asPlanar, clockwise, gcmd, absolut_extrude, *axes)

    
    def planArc(self, currentPos, targetPos, offset, clockwise, gcmd, absolut_extrude, alpha_axis, beta_axis, helical_axis):
        r_P = -offset[0]
        r_Q = -offset[1]
        center_P = currentPos[alpha_axis] - r_P
        center_Q = currentPos[beta_axis] - r_Q
        rt_Alpha = targetPos[alpha_axis] - center_P
        rt_Beta = targetPos[beta_axis] - center_Q
        angular_travel = math.atan2(r_P * rt_Beta - r_Q * rt_Alpha, r_P * rt_Alpha + r_Q * rt_Beta)
        if angular_travel < 0.0:
            angular_travel += 2.0 * math.pi
        if clockwise:
            angular_travel -= 2.0 * math.pi
        if angular_travel == 0.0 and currentPos[alpha_axis] == targetPos[alpha_axis] and currentPos[beta_axis] == targetPos[beta_axis]:
            angular_travel = 2.0 * math.pi
        abs_angle_arc = abs(angular_travel)
        circle_factor = abs_angle_arc / (2 * math.pi)
        linear_travel = targetPos[helical_axis] - currentPos[helical_axis]
        radius = math.hypot(r_P, r_Q)
        flat_mm = radius * angular_travel
        min_segments = 2 * math.pi / math.sqrt(8 * self.accuracy / radius)
        min_segments = math.ceil(min_segments * circle_factor)
        if linear_travel:
            mm_of_travel = math.hypot(flat_mm, linear_travel)
        else:
            mm_of_travel = math.fabs(flat_mm)
        real_segments = max(math.floor(mm_of_travel / self.mm_per_arc_segment), min_segments)
        real_segments_mm = mm_of_travel / real_segments
        segments = 0
        if real_segments_mm > self.mm_per_arc_segment:
            segments = math.ceil(mm_of_travel / self.mm_per_arc_segment)
        else:
            segments = real_segments
            if real_segments_mm < self.min_mm_per_arc_segment:
                segments = max(1, math.floor(mm_of_travel / self.min_mm_per_arc_segment))
        asE = gcmd.get_float('E', None)
        asF = gcmd.get_float('F', None)
        e_per_move = e_base = 0.0
        if asE is not None:
            if absolut_extrude:
                e_base = currentPos[3]
            e_per_move = (asE - e_base) / segments
        theta_per_segment = angular_travel / segments
        linear_per_segment = linear_travel / segments
        theta_per_segment_sqr = theta_per_segment * theta_per_segment
        sin_T = theta_per_segment - theta_per_segment_sqr * theta_per_segment / 6.0
        cos_T = 1 - 0.5 * theta_per_segment_sqr
        correct_count = 0
        if self.n_arc_revise:
            correct_count = self.n_arc_revise
        for i in range(1, int(segments) + 1):
            dist_Helical = i * linear_per_segment
            correct_count -= 1
            if correct_count > 0:
                r_new = r_P * sin_T + r_Q * cos_T
                r_P = r_P * cos_T - r_Q * sin_T
                r_Q = r_new
            else:
                correct_count = self.n_arc_revise
                angle_i = i * theta_per_segment
                cos_Ti = math.cos(angle_i)
                sin_Ti = math.sin(angle_i)
                r_P = -offset[0] * cos_Ti + offset[1] * sin_Ti
                r_Q = -offset[0] * sin_Ti - offset[1] * cos_Ti
            c = [
                None,
                None,
                None]
            c[alpha_axis] = center_P + r_P
            c[beta_axis] = center_Q + r_Q
            c[helical_axis] = currentPos[helical_axis] + dist_Helical
            if i == segments:
                c = targetPos
            g1_params = {
                'X': c[0],
                'Y': c[1],
                'Z': c[2] }
            if e_per_move:
                g1_params['E'] = e_base + e_per_move
                if absolut_extrude:
                    e_base += e_per_move
            if asF is not None:
                g1_params['F'] = asF
            g1_gcmd = self.gcode.create_gcode_command('G1', 'G1', g1_params)
            self.gcode_move.cmd_G1(g1_gcmd)



def load_config(config):
    return ArcSupport(config)

