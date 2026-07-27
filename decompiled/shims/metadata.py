# Source Generated with Decompyle++
# File: metadata.pyc (Python 3.9)

from __future__ import annotations
import json
import argparse
import re
import os
import sys
import base64
import traceback
import tempfile
import zipfile
import shutil
import uuid
from PIL import Image
from typing import TYPE_CHECKING, Any, Optional, Dict, List, Tuple, Type
if TYPE_CHECKING:
    pass
UFP_MODEL_PATH = '/3D/model.gcode'
UFP_THUMB_PATH = '/Metadata/thumbnail.png'

def log_to_stderr(msg = None):
    sys.stderr.write(f'''{msg}\n''')
    sys.stderr.flush()


def _regex_find_floats(pattern = None, data = None, strict = None):
    fptrn = '\\d+\\.\\d*' if strict else '\\d+\\.?\\d*'
    matches = re.findall(pattern, data)
# WARNING: Decompyle incomplete


def _regex_find_ints(pattern = None, data = None):
    matches = re.findall(pattern, data)
# WARNING: Decompyle incomplete


def _regex_find_first(pattern = None, data = None):
    match = re.search(pattern, data)
    val = None
# WARNING: Decompyle incomplete


def _regex_find_int(pattern = None, data = None):
    match = re.search(pattern, data)
    val = None
# WARNING: Decompyle incomplete


def _regex_find_string(pattern = None, data = None):
    match = re.search(pattern, data)
    if match:
        return match.group(1).strip('"')


def get_print_file_metadata(file_path):
    result = { }
    count = 3000
# WARNING: Decompyle incomplete


class BaseSlicer(object):
    
    def __init__(self = None, file_path = None):
        self.path = file_path
        self.header_data = ''
        self.footer_data = ''
        self.layer_height = None
        self.has_m486_objects = False

    
    def set_data(self = None, header_data = None, footer_data = None, fsize = {
        'header_data': 'str',
        'footer_data': 'str',
        'fsize': 'int',
        'return': 'None' }):
        self.header_data = header_data
        self.footer_data = footer_data
        self.size = fsize

    
    def _parse_min_float(self = None, pattern = None, data = None, strict = (False,)):
        result = _regex_find_floats(pattern, data, strict)
        if result:
            return min(result)
        return None

    
    def _parse_max_float(self = None, pattern = None, data = None, strict = (False,)):
        result = _regex_find_floats(pattern, data, strict)
        if result:
            return max(result)
        return None

    
    def _check_has_objects(self = None, data = None, pattern = None):
        match = re.search('\\n((DEFINE_OBJECT)|(EXCLUDE_OBJECT_DEFINE)) NAME=', data)
        if match is not None:
            fname = os.path.basename(self.path)
            log_to_stderr(f'''File \'{fname}\' currently supports cancellation, processing aborted''')
            if match.group(1).startswith('DEFINE_OBJECT'):
                log_to_stderr('Legacy object processing detected.  This is not compatible with official versions of Klipper.')
            return False
        patterns = [
            None]
        if pattern is not None:
            patterns.append(pattern)
        for regex in patterns:
            if re.search(regex, data) is not None:
                self.has_m486_objects = regex == '\\nM486'
                return True
            return False

    
    def check_identity(self = None, data = None):
        pass

    
    def has_objects(self = None):
        return self._check_has_objects(self.header_data)

    
    def parse_gcode_start_byte(self = None):
        m = re.search('\\n[MG]\\d+\\s.*\\n', self.header_data)
        if m is None:
            return None
        return None.start()

    
    def parse_gcode_end_byte(self = None):
        rev_data = self.footer_data[::-1]
        m = re.search('\\n.*\\s\\d+[MG]\\n', rev_data)
        if m is None:
            return None
        return None.size - m.start()

    
    def parse_first_layer_height(self = None):
        pass

    
    def parse_model_info(self):
        pass

    
    def parse_layer_height(self = None):
        pass

    
    def parse_object_height(self = None):
        pass

    
    def parse_filament_total(self = None):
        pass

    
    def parse_filament_weight_total(self = None):
        pass

    
    def parse_filament_name(self = None):
        pass

    
    def parse_filament_type(self = None):
        pass

    
    def parse_estimated_time(self = None):
        pass

    
    def parse_first_layer_bed_temp(self = None):
        pass

    
    def parse_chamber_temp(self = None):
        pass

    
    def parse_first_layer_extr_temp(self = None):
        pass

    
    def parse_layer_count(self = None):
        pass

    
    def parse_nozzle_diameter(self = None):
        pass

    
    def parse_flush_para(self = None):
        pass

    
    def parse_default_filament_colour(self = None):
        pass



class UnknownSlicer(BaseSlicer):
    
    def check_identity(self = None, data = None):
        return {
            'slicer': 'Unknown' }

    
    def parse_first_layer_height(self = None):
        return self._parse_min_float('G1\\sZ\\d+\\.\\d*', self.header_data)

    
    def parse_model_info(self):
        return get_print_file_metadata(self.path)

    
    def parse_object_height(self = None):
        return self._parse_max_float('G1\\sZ\\d+\\.\\d*', self.footer_data)

    
    def parse_first_layer_extr_temp(self = None):
        return _regex_find_first('M109 S(\\d+\\.?\\d*)', self.header_data)

    
    def parse_first_layer_bed_temp(self = None):
        return _regex_find_first('M190 S(\\d+\\.?\\d*)', self.header_data)

    
    def parse_chamber_temp(self = None):
        return _regex_find_first('M191 S(\\d+\\.?\\d*)', self.header_data)



class PrusaSlicer(BaseSlicer):
    
    def check_identity(self = None, data = None):
        aliases = {
            'PrusaSlicer': 'PrusaSlicer\\s(.*)\\son',
            'SuperSlicer': 'SuperSlicer\\s(.*)\\son',
            'OrcaSlicer': 'OrcaSlicer\\s(.*)\\son',
            'SliCR-3D': 'SliCR-3D\\s(.*)\\son',
            'BambuStudio': 'BambuStudio[^ ]*\\s(.*)\\n',
            'A3dp-Slicer': 'A3dp-Slicer\\s(.*)\\son' }
        for name, expr in aliases.items():
            match = re.search(expr, data)
            if match:
                return {
                    'slicer': name,
                    'slicer_version': match.group(1) }
            return None

    
    def has_objects(self = None):
        return self._check_has_objects(self.header_data, '\\n; printing object')

    
    def parse_first_layer_height(self = None):
        pct = _regex_find_first('; first_layer_height = (\\d+)%', self.footer_data)
        if pct is not None:
            if self.layer_height is None:
                return None
            return None((pct / 100) * self.layer_height, 6)
        return None('; first_layer_height = (\\d+\\.?\\d*)', self.footer_data)

    
    def parse_model_info(self):
        return get_print_file_metadata(self.path)

    
    def parse_layer_height(self = None):
        self.layer_height = _regex_find_first('; layer_height = (\\d+\\.?\\d*)', self.footer_data)
        return self.layer_height

    
    def parse_object_height(self = None):
        matches = re.findall(';BEFORE_LAYER_CHANGE\\n(?:.*\\n)?;(\\d+\\.?\\d*)', self.footer_data)
    # WARNING: Decompyle incomplete

    
    def parse_filament_total(self = None):
        return _regex_find_first('filament\\sused\\s\\[mm\\]\\s=\\s(\\d+\\.\\d*)', self.footer_data)

    
    def parse_filament_weight_total(self = None):
        return _regex_find_first('total\\sfilament\\sused\\s\\[g\\]\\s=\\s(\\d+\\.\\d*)', self.footer_data)

    
    def parse_filament_type(self = None):
        return _regex_find_string(';\\sfilament_type\\s=\\s(.*)', self.footer_data)

    
    def parse_filament_name(self = None):
        return _regex_find_string(';\\sfilament_settings_id\\s=\\s(.*)', self.footer_data)

    
    def parse_estimated_time(self = None):
        time_match = re.search(';\\sestimated\\sprinting\\stime.*', self.footer_data)
        if not time_match:
            return None
        total_time = None
        time_group = time_match.group()
        time_patterns = [
            ('(\\d+)d', 86400),
            ('(\\d+)h', 3600),
            ('(\\d+)m', 60),
            ('(\\d+)s', 1)]
    # WARNING: Decompyle incomplete

    
    def parse_first_layer_extr_temp(self = None):
        return _regex_find_first('; first_layer_temperature = (\\d+\\.?\\d*)', self.footer_data)

    
    def parse_first_layer_bed_temp(self = None):
        return _regex_find_first('; first_layer_bed_temperature = (\\d+\\.?\\d*)', self.footer_data)

    
    def parse_chamber_temp(self = None):
        return _regex_find_first('; chamber_temperature = (\\d+\\.?\\d*)', self.footer_data)

    
    def parse_nozzle_diameter(self = None):
        return _regex_find_first(';\\snozzle_diameter\\s=\\s(\\d+\\.\\d*)', self.footer_data)

    
    def parse_layer_count(self = None):
        return _regex_find_int('; total layers count = (\\d+)', self.footer_data)

    
    def parse_flush_para(self = None):
        flush_multiplier = None
        flush_volumes_matrix = None
        flush_multiplier_match = re.search('; flush_multiplier\\s*=\\s*([\\d.]+)', self.footer_data)
        if flush_multiplier_match:
            flush_multiplier = float(flush_multiplier_match.group(1))
        flush_volumes_matrix_match = re.search('; flush_volumes_matrix\\s*=\\s*([^;]+)', self.footer_data)
        if flush_volumes_matrix_match:
            flush_volumes_matrix = [ int(x) for x in (flush_volumes_matrix_match.group(1).strip().split(',')) ]
        if flush_multiplier is not None or flush_volumes_matrix is not None:
            return {
                'flush_multiplier': flush_multiplier,
                'flush_volumes_matrix': flush_volumes_matrix }
        return None



class Slic3rPE(PrusaSlicer):
    
    def check_identity(self = None, data = None):
        match = re.search('Slic3r\\sPrusa\\sEdition\\s(.*)\\son', data)
        if match:
            return {
                'slicer': 'Slic3r PE',
                'slicer_version': match.group(1) }

    
    def parse_filament_total(self = None):
        return _regex_find_first('filament\\sused\\s=\\s(\\d+\\.\\d+)mm', self.footer_data)



class Slic3r(Slic3rPE):
    
    def check_identity(self = None, data = None):
        match = re.search('Slic3r\\s(\\d.*)\\son', data)
        if match:
            return {
                'slicer': 'Slic3r',
                'slicer_version': match.group(1) }

    
    def parse_filament_total(self = None):
        filament = _regex_find_first(';\\sfilament\\_length\\_m\\s=\\s(\\d+\\.\\d*)', self.footer_data)
        if filament is not None:
            filament *= 1000
        return filament

    
    def parse_filament_weight_total(self = None):
        return _regex_find_first(';\\sfilament\\smass\\_g\\s=\\s(\\d+\\.\\d*)', self.footer_data)

    
    def parse_estimated_time(self = None):
        pass



class Cura(BaseSlicer):
    
    def check_identity(self = None, data = None):
        match = re.search('Cura_SteamEngine\\s(.*)', data)
        if match:
            return {
                'slicer': 'Cura',
                'slicer_version': match.group(1) }

    
    def has_objects(self = None):
        return self._check_has_objects(self.header_data, '\\n;MESH:')

    
    def parse_first_layer_height(self = None):
        return _regex_find_first(';MINZ:(\\d+\\.?\\d*)', self.header_data)

    
    def parse_model_info(self):
        return get_print_file_metadata(self.path)

    
    def parse_layer_height(self = None):
        self.layer_height = _regex_find_first(';Layer\\sheight:\\s(\\d+\\.?\\d*)', self.header_data)
        return self.layer_height

    
    def parse_object_height(self = None):
        return _regex_find_first(';MAXZ:(\\d+\\.?\\d*)', self.header_data)

    
    def parse_filament_total(self = None):
        filament = _regex_find_first(';Filament\\sused:\\s(\\d+\\.?\\d*)m', self.header_data)
        if filament is not None:
            filament *= 1000
        return filament

    
    def parse_filament_weight_total(self = None):
        return _regex_find_first(';Filament\\sweight\\s=\\s.(\\d+\\.\\d+).', self.header_data)

    
    def parse_filament_type(self = None):
        return _regex_find_string(';Filament\\stype\\s=\\s(.*)', self.header_data)

    
    def parse_filament_name(self = None):
        return _regex_find_string(';Filament\\sname\\s=\\s(.*)', self.header_data)

    
    def parse_estimated_time(self = None):
        return self._parse_max_float(';TIME:.*', self.header_data)

    
    def parse_first_layer_extr_temp(self = None):
        return _regex_find_first('M109 S(\\d+\\.?\\d*)', self.header_data)

    
    def parse_first_layer_bed_temp(self = None):
        return _regex_find_first('M190 S(\\d+\\.?\\d*)', self.header_data)

    
    def parse_chamber_temp(self = None):
        return _regex_find_first('M191 S(\\d+\\.?\\d*)', self.header_data)

    
    def parse_layer_count(self = None):
        return _regex_find_int(';LAYER_COUNT\\:(\\d+)', self.header_data)

    
    def parse_nozzle_diameter(self = None):
        return _regex_find_first(';Nozzle\\sdiameter\\s=\\s(\\d+\\.\\d*)', self.header_data)



class Simplify3D(BaseSlicer):
    
    def check_identity(self = None, data = None):
        match = re.search('Simplify3D\\(R\\)\\sVersion\\s(.*)', data)
        if match:
            self._version = match.group(1)
            self._is_v5 = self._version.startswith('5')
            return {
                'slicer': 'Simplify3D',
                'slicer_version': match.group(1) }

    
    def parse_first_layer_height(self = None):
        return self._parse_min_float('G1\\sZ\\d+\\.\\d*', self.header_data)

    
    def parse_model_info(self):
        return get_print_file_metadata(self.path)

    
    def parse_layer_height(self = None):
        self.layer_height = _regex_find_first(';\\s+layerHeight,(\\d+\\.?\\d*)', self.header_data)
        return self.layer_height

    
    def parse_object_height(self = None):
        return self._parse_max_float('G1\\sZ\\d+\\.\\d*', self.footer_data)

    
    def parse_filament_total(self = None):
        return _regex_find_first(';\\s+(?:Filament\\slength|Material\\sLength):\\s(\\d+\\.?\\d*)\\smm', self.footer_data)

    
    def parse_filament_weight_total(self = None):
        return _regex_find_first(';\\s+(?:Plastic\\sweight|Material\\sWeight):\\s(\\d+\\.?\\d*)\\sg', self.footer_data)

    
    def parse_filament_name(self = None):
        return _regex_find_string(';\\s+printMaterial,(.*)', self.header_data)

    
    def parse_filament_type(self = None):
        return _regex_find_string(';\\s+makerBotModelMaterial,(.*)', self.footer_data)

    
    def parse_estimated_time(self = None):
        time_match = re.search(';\\s+Build (t|T)ime:.*', self.footer_data)
        if not time_match:
            return None
        total_time = None
        time_group = time_match.group()
        time_patterns = [
            ('(\\d+)\\shours?', 3600),
            ('(\\d+)\\smin', 60),
            ('(\\d+)\\ssec', 1)]
    # WARNING: Decompyle incomplete

    
    def _get_temp_items(self = None, pattern = None):
        match = re.search(pattern, self.header_data)
        if match is None:
            return []
        return None.group().split(',')[1:]

    
    def _get_first_layer_temp(self = None, heater = None):
        heaters = self._get_temp_items('temperatureName.*')
        temps = self._get_temp_items('temperatureSetpointTemperatures.*')
    # WARNING: Decompyle incomplete

    
    def _get_first_layer_temp_v5(self = None, heater_type = None):
        pattern = f''';\\s+temperatureController,.+?;\\s+temperatureType,{heater_type}.+?;\\s+temperatureSetpoints,\\d+\\|(\\d+)'''
        match = re.search(pattern, self.header_data, re.MULTILINE | re.DOTALL)
    # WARNING: Decompyle incomplete

    
    def parse_first_layer_extr_temp(self = None):
        if self._is_v5:
            return self._get_first_layer_temp_v5('extruder')
        return None._get_first_layer_temp('Extruder 1')

    
    def parse_first_layer_bed_temp(self = None):
        if self._is_v5:
            return self._get_first_layer_temp_v5('platform')
        return None._get_first_layer_temp('Heated Bed')

    
    def parse_nozzle_diameter(self = None):
        return _regex_find_first(';\\s+(?:extruderDiameter|nozzleDiameter),(\\d+\\.\\d*)', self.header_data)



class KISSlicer(BaseSlicer):
    
    def check_identity(self = None, data = None):
        match = re.search(';\\sKISSlicer', data)
        if match:
            ident = {
                'slicer': 'KISSlicer' }
            vmatch = re.search(';\\sversion\\s(.*)', data)
            if vmatch:
                version = vmatch.group(1).replace(' ', '-')
                ident['slicer_version'] = version
            return ident

    
    def parse_first_layer_height(self = None):
        return _regex_find_first(';\\s+first_layer_thickness_mm\\s=\\s(\\d+\\.?\\d*)', self.header_data)

    
    def parse_model_info(self):
        return get_print_file_metadata(self.path)

    
    def parse_layer_height(self = None):
        self.layer_height = _regex_find_first(';\\s+max_layer_thickness_mm\\s=\\s(\\d+\\.?\\d*)', self.header_data)
        return self.layer_height

    
    def parse_object_height(self = None):
        return self._parse_max_float(';\\sEND_LAYER_OBJECT\\sz.*', self.footer_data)

    
    def parse_filament_total(self = None):
        filament = _regex_find_floats(';\\s+Ext\\s.*mm', self.footer_data, strict=True)
        if filament:
            return sum(filament)

    
    def parse_estimated_time(self = None):
        time = _regex_find_first(';\\sCalculated.*Build\\sTime:\\s(\\d+\\.?\\d*)\\sminutes', self.footer_data)
        if time is not None:
            time *= 60
            return round(time, 2)

    
    def parse_first_layer_extr_temp(self = None):
        return _regex_find_first('; first_layer_C = (\\d+\\.?\\d*)', self.header_data)

    
    def parse_first_layer_bed_temp(self = None):
        return _regex_find_first('; bed_C = (\\d+\\.?\\d*)', self.header_data)

    
    def parse_chamber_temp(self = None):
        return _regex_find_first('; chamber_C = (\\d+\\.?\\d*)', self.header_data)



class IdeaMaker(BaseSlicer):
    
    def check_identity(self = None, data = None):
        match = re.search('\\sideaMaker\\s(.*),', data)
        if match:
            return {
                'slicer': 'IdeaMaker',
                'slicer_version': match.group(1) }

    
    def has_objects(self = None):
        return self._check_has_objects(self.header_data, '\\n;PRINTING:')

    
    def parse_first_layer_height(self = None):
        layer_info = _regex_find_floats(';LAYER:0\\s*.*\\s*;HEIGHT.*', self.header_data)
        if len(layer_info) >= 3:
            return layer_info[2]

    
    def parse_model_info(self):
        return get_print_file_metadata(self.path)

    
    def parse_layer_height(self = None):
        layer_info = _regex_find_floats(';LAYER:1\\s*.*\\s*;HEIGHT.*', self.header_data)
        if len(layer_info) >= 3:
            self.layer_height = layer_info[2]
            return self.layer_height

    
    def parse_object_height(self = None):
        bounds = _regex_find_floats(';Bounding Box:.*', self.header_data)
        if len(bounds) >= 6:
            return bounds[5]

    
    def parse_filament_total(self = None):
        filament = _regex_find_floats(';Material.\\d\\sUsed:.*', self.footer_data, strict=True)
        if filament:
            return sum(filament)

    
    def parse_filament_type(self = None):
        return _regex_find_string(';Filament\\stype\\s=\\s(.*)', self.header_data)

    
    def parse_filament_name(self = None):
        return _regex_find_string(';Filament\\sname\\s=\\s(.*)', self.header_data)

    
    def parse_filament_weight_total(self = None):
        pi = 3.14159
        length = _regex_find_floats(';Material.\\d\\sUsed:.*', self.footer_data, strict=True)
        diameter = _regex_find_floats(';Filament\\sDiameter\\s.\\d:.*', self.header_data, strict=True)
        density = _regex_find_floats(';Filament\\sDensity\\s.\\d:.*', self.header_data, strict=True)
        if len(density) == len(density) or len(density) == len(diameter):
            pass
        else:
            len(length)
        weights = [ (pi / 4) * diameter[i] ** 2 * length[i] * density[i] / 1000000 for i in (range(len(length))) ]
        return sum(weights)

    
    def parse_estimated_time(self = None):
        return _regex_find_first(';Print\\sTime:\\s(\\d+\\.?\\d*)', self.footer_data)

    
    def parse_first_layer_extr_temp(self = None):
        return _regex_find_first('M109 T0 S(\\d+\\.?\\d*)', self.header_data)

    
    def parse_first_layer_bed_temp(self = None):
        return _regex_find_first('M190 S(\\d+\\.?\\d*)', self.header_data)

    
    def parse_chamber_temp(self = None):
        return _regex_find_first('M191 S(\\d+\\.?\\d*)', self.header_data)

    
    def parse_nozzle_diameter(self = None):
        return _regex_find_first(';Dimension:(?:\\s\\d+\\.\\d+){3}\\s(\\d+\\.\\d+)', self.header_data)



class IceSL(BaseSlicer):
    
    def check_identity(self = None, data = None):
        match = re.search('<IceSL\\s(.*)>', data)
        if match:
            version = match.group(1) if match.group(1)[0].isdigit() else '-'
            return {
                'slicer': 'IceSL',
                'slicer_version': version }

    
    def parse_first_layer_height(self = None):
        return _regex_find_first(';\\sz_layer_height_first_layer_mm\\s:\\s+(\\d+\\.\\d+)', self.header_data)

    
    def parse_model_info(self):
        return get_print_file_metadata(self.path)

    
    def parse_layer_height(self = None):
        self.layer_height = _regex_find_first(';\\sz_layer_height_mm\\s:\\s+(\\d+\\.\\d+)', self.header_data)
        return self.layer_height

    
    def parse_object_height(self = None):
        return _regex_find_first(';\\sprint_height_mm\\s:\\s+(\\d+\\.\\d+)', self.header_data)

    
    def parse_first_layer_extr_temp(self = None):
        return _regex_find_first(';\\sextruder_temp_degree_c_0\\s:\\s+(\\d+\\.?\\d*)', self.header_data)

    
    def parse_first_layer_bed_temp(self = None):
        return _regex_find_first(';\\sbed_temp_degree_c\\s:\\s+(\\d+\\.?\\d*)', self.header_data)

    
    def parse_chamber_temp(self = None):
        return _regex_find_first(';\\schamber_temp_degree_c\\s:\\s+(\\d+\\.?\\d*)', self.header_data)

    
    def parse_filament_total(self = None):
        return _regex_find_first(';\\sfilament_used_mm\\s:\\s+(\\d+\\.\\d+)', self.header_data)

    
    def parse_filament_weight_total(self = None):
        return _regex_find_first(';\\sfilament_used_g\\s:\\s+(\\d+\\.\\d+)', self.header_data)

    
    def parse_filament_name(self = None):
        return _regex_find_string(';\\sfilament_name\\s:\\s+(.*)', self.header_data)

    
    def parse_filament_type(self = None):
        return _regex_find_string(';\\sfilament_type\\s:\\s+(.*)', self.header_data)

    
    def parse_estimated_time(self = None):
        return _regex_find_first(';\\sestimated_print_time_s\\s:\\s+(\\d*\\.*\\d*)', self.header_data)

    
    def parse_layer_count(self = None):
        return _regex_find_int(';\\slayer_count\\s:\\s+(\\d+)', self.header_data)

    
    def parse_nozzle_diameter(self = None):
        return _regex_find_first(';\\snozzle_diameter_mm_0\\s:\\s+(\\d+\\.\\d+)', self.header_data)



class KiriMoto(BaseSlicer):
    
    def check_identity(self = None, data = None):
        variants = {
            'Kiri:Moto': '; Generated by Kiri:Moto (\\d.+)',
            'SimplyPrint': '; Generated by Kiri:Moto \\(SimplyPrint\\) (.+)' }
        for name, pattern in variants.items():
            match = re.search(pattern, data)
            if match:
                return {
                    'slicer': name,
                    'slicer_version': match.group(1) }
            return None

    
    def parse_first_layer_height(self = None):
        return _regex_find_first('; firstSliceHeight = (\\d+\\.\\d+)', self.header_data)

    
    def parse_model_info(self):
        return get_print_file_metadata(self.path)

    
    def parse_layer_height(self = None):
        self.layer_height = _regex_find_first('; sliceHeight = (\\d+\\.\\d+)', self.header_data)
        return self.layer_height

    
    def parse_object_height(self = None):
        return self._parse_max_float('G1 Z\\d+\\.\\d+ (?:; z-hop end|F\\d+\\n)', self.footer_data, strict=True)

    
    def parse_layer_count(self = None):
        matches = re.findall(';; --- layer (\\d+) \\(.+', self.footer_data)
        if not matches:
            return None
        :
            matches = re.findall(';; --- layer (\\d+) \\(.+', self.footer_data)
            if not matches:
                return None
            
            return int(matches[-1]) + 1
        return int(matches[-1]) + 1
    # WARNING: Decompyle incomplete

    
    def parse_estimated_time(self = None):
        return _regex_find_int('; --- print time: (\\d+)s', self.footer_data)

    
    def parse_filament_total(self = None):
        return _regex_find_first('; --- filament used: (\\d+\\.?\\d*) mm', self.footer_data)

    
    def parse_first_layer_extr_temp(self = None):
        return _regex_find_first('; firstLayerNozzleTemp = (\\d+\\.?\\d*)', self.header_data)

    
    def parse_first_layer_bed_temp(self = None):
        return _regex_find_first('; firstLayerBedTemp = (\\d+\\.?\\d*)', self.header_data)



class Creality(BaseSlicer):
    
    def check_identity(self = None, data = None):
        aliases = {
            'Creality_Cloud': 'Creality_Cloud',
            'Creative3D': 'Creative3D',
            'Creality': 'Creality' }
        pattern = 'Version : V([\\d\\.]+)'
        match_version = re.search(pattern, data)
        if not match_version:
            match_version = re.search('[tr] V([\\d\\.]+)', data)
        slicer_version = match_version.group(1) if match_version else '1.0'
        for name, expr in aliases.items():
            match = re.search(expr, data)
            if match:
                return {
                    'slicer': name,
                    'slicer_version': slicer_version }
            return None

    
    def parse_first_layer_height(self = None):
        first_layer_height = _regex_find_first(';MINZ:(\\d+\\.?\\d*)', self.header_data)
        if not first_layer_height:
            first_layer_height = _regex_find_first(';MINZ:(\\d+\\.?\\d*)', self.footer_data)
        if not first_layer_height:
            first_layer_height = _regex_find_first('; first_layer_height = (\\d+\\.?\\d*)', self.footer_data)
        return first_layer_height

    
    def parse_model_info(self):
        return get_print_file_metadata(self.path)

    
    def parse_layer_height(self = None):
        pattern = ';Layer height:\\s*(\\d+\\.?\\d*)'
        self.layer_height = _regex_find_first(pattern, self.header_data)
        if not self.layer_height:
            self.layer_height = _regex_find_first('; layer_height = (\\d+\\.\\d*)', self.footer_data)
        return self.layer_height

    
    def parse_object_height(self = None):
        matches = re.findall(';MAXZ:(\\d+\\.?\\d*)', self.header_data)
    # WARNING: Decompyle incomplete

    
    def parse_layer_count(self = None):
        layer_count = _regex_find_int(';LAYER_COUNT\\:(\\d+)', self.header_data)
        if not layer_count:
            layer_count = _regex_find_int('; total layer number: (\\d+)', self.header_data)
        return layer_count

    
    def parse_filament_type(self = None):
        result = ''
        filament_type = _regex_find_string(';Material Type:(\\S+)', self.header_data)
        if not filament_type:
            filament_type = _regex_find_string('; default_filament_type = (\\S+)', self.footer_data)
        if not filament_type:
            filament_type = _regex_find_string('; filament_type = (\\S+)', self.footer_data)
        if filament_type:
            result = filament_type.strip(';')
        return result

    
    def parse_filament_name(self = None):
        return _regex_find_string(';Material Name:(.+)', self.header_data)

    
    def parse_uuid(self = None):
        return _regex_find_string('; creality_uuid: (.+)', self.header_data)

    
    def parse_filament_total(self = None):
        filament_total = _regex_find_first(';Filament used:(\\d+\\.?\\d*)m', self.header_data)
        if filament_total:
            filament_total = filament_total * 1000
        return filament_total

    
    def parse_filament_weight_total(self = None):
        filament_weight_total = _regex_find_first(';Filament Weight:(\\d+\\.?\\d*)', self.header_data)
        if filament_weight_total:
            filament_weight_total = filament_weight_total * 5.88
        return filament_weight_total

    
    def parse_estimated_time(self = None):
        total_time = _regex_find_first(';TIME:(\\d+)', self.header_data)
        if not total_time:
            hour = _regex_find_int('; estimated printing time.*?(\\d+)h', self.footer_data)
            min = _regex_find_int('; estimated printing time.*?(\\d+)m', self.footer_data)
            sec = _regex_find_int('; estimated printing time.*?(\\d+)s', self.footer_data)
            total_time = 0
            if hour:
                total_time = hour * 60 * 60
            if min:
                total_time = total_time + min * 60
            if sec:
                total_time = total_time + sec
        return total_time

    
    def parse_first_layer_extr_temp(self = None):
        return _regex_find_first(';Print Temperature:(\\d+\\.?\\d*)', self.header_data)

    
    def parse_first_layer_bed_temp(self = None):
        return _regex_find_first(';Bed Temperature:(\\d+\\.?\\d*)', self.header_data)

    
    def parse_flush_para(self = None):
        flush_multiplier = None
        flush_volumes_matrix = None
        flush_multiplier_match = re.search('; flush_multiplier\\s*=\\s*([\\d.]+)', self.header_data)
        if not flush_multiplier_match:
            flush_multiplier_match = re.search('; flush_multiplier\\s*=\\s*([\\d.]+)', self.footer_data)
        if flush_multiplier_match:
            flush_multiplier = float(flush_multiplier_match.group(1))
        flush_volumes_matrix_match = re.search('; flush_volumes_matrix\\s*=\\s*([^;]+)', self.header_data)
        if not flush_volumes_matrix_match:
            flush_volumes_matrix_match = re.search('; flush_volumes_matrix\\s*=\\s*([^;]+)', self.footer_data)
        if flush_volumes_matrix_match:
            flush_volumes_matrix = [ int(float(x)) for x in (flush_volumes_matrix_match.group(1).strip().split(',')) ]
        if flush_multiplier is not None or flush_volumes_matrix is not None:
            return {
                'flush_multiplier': flush_multiplier,
                'flush_volumes_matrix': flush_volumes_matrix }
        return None

    
    def parse_default_filament_colour(self = None):
        default_filament_colour = []
        default_filament_colour_match = re.search('default_filament_colour = (\\S+)', self.header_data)
        if not default_filament_colour_match:
            default_filament_colour_match = re.search('default_filament_colour = (\\S+)', self.footer_data)
        if default_filament_colour_match:
            default_filament_colour = default_filament_colour_match.group(1).split(';')
        return default_filament_colour

    
    def parse_filament_used_g(self = None):
        filament_used_g = []
        filament_used_g_match = re.search('; filament used \\[g\\] = (.+)', self.header_data)
        if not filament_used_g_match:
            filament_used_g_match = re.search('; filament used \\[g\\] = (.+)', self.footer_data)
        if filament_used_g_match:
            filament_used_g = filament_used_g_match.group(1).split(', ')
        return filament_used_g


READ_SIZE = 524288
SUPPORTED_SLICERS: 'List[Type[BaseSlicer]]' = [
    PrusaSlicer,
    Slic3rPE,
    Slic3r,
    Cura,
    Simplify3D,
    KISSlicer,
    IdeaMaker,
    IceSL,
    KiriMoto,
    Creality]
SUPPORTED_DATA = [
    'gcode_start_byte',
    'gcode_end_byte',
    'layer_count',
    'object_height',
    'estimated_time',
    'nozzle_diameter',
    'layer_height',
    'first_layer_height',
    'first_layer_extr_temp',
    'first_layer_bed_temp',
    'chamber_temp',
    'filament_name',
    'filament_type',
    'filament_total',
    'filament_weight_total',
    'flush_para',
    'model_info',
    'default_filament_colour',
    'filament_used_g',
    'uuid']

def process_objects(file_path = None, slicer = None, name = None):
    pass
# WARNING: Decompyle incomplete


def get_slicer(file_path = None):
    header_data = footer_data = ''
    slicer = None
    size = os.path.getsize(file_path)
    with open(file_path, 'r', encoding='utf-8', errors='replace') as f:
        header_data = f.read(READ_SIZE)
        for impl in SUPPORTED_SLICERS:
            slicer = impl(file_path)
            ident = slicer.check_identity(header_data)
            if ident is not None:
                pass
            
            slicer = UnknownSlicer(file_path)
            ident = slicer.check_identity(header_data)
            if size > READ_SIZE * 2:
                f.seek(size - READ_SIZE)
                footer_data = f.read()
            elif size > READ_SIZE:
                remaining = size - READ_SIZE
                footer_data = header_data[remaining - READ_SIZE:] + f.read()
            else:
                footer_data = header_data
        slicer.set_data(header_data, footer_data, size)
        None(None, None, None)
    with None:
        if not None:
            pass
    if ident is None:
        ident = {
            'slicer': 'unknown' }
    return (slicer, ident)


def extract_metadata(file_path = None, check_objects = None):
    metadata = { }
    (slicer, ident) = get_slicer(file_path)
    if check_objects and slicer.has_objects():
        name = ident.get('slicer', 'unknown')
        if process_objects(file_path, slicer, name):
            (slicer, ident) = get_slicer(file_path)
    metadata['size'] = os.path.getsize(file_path)
    metadata['modified'] = os.path.getmtime(file_path)
    metadata['uuid'] = str(uuid.uuid4())
    metadata.update(ident)
    for key in SUPPORTED_DATA:
        if hasattr(slicer, 'parse_' + key):
            func = getattr(slicer, 'parse_' + key)
            result = func()
            if result is not None:
                metadata[key] = result
                continue
                if metadata.get('filament_type'):
                    metadata['model_info']['MaterialType'] = metadata.get('filament_type')
    if metadata.get('filament_name'):
        metadata['model_info']['MaterialName'] = metadata.get('filament_name')
    if not metadata['model_info'].get('multicolor_method'):
        metadata['model_info']['multicolor_method'] = 0
    return metadata


def extract_ufp(ufp_path = None, dest_path = None):
    if not os.path.isfile(ufp_path):
        log_to_stderr(f'''UFP file Not Found: {ufp_path}''')
        sys.exit(-1)
    thumb_name = os.path.splitext(os.path.basename(dest_path))[0] + '.png'
    dest_thumb_dir = os.path.join(os.path.dirname(dest_path), '.thumbs')
    dest_thumb_path = os.path.join(dest_thumb_dir, thumb_name)
# WARNING: Decompyle incomplete


def main(path = None, filename = None, ufp = None, check_objects = {
    'path': 'str',
    'filename': 'str',
    'ufp': 'Optional[str]',
    'check_objects': 'bool',
    'return': 'None' }):
    file_path = os.path.join(path, filename)
    if ufp is not None:
        extract_ufp(ufp, file_path)
    metadata = { }
    if not os.path.isfile(file_path):
        log_to_stderr(f'''File Not Found: {file_path}''')
        sys.exit(-1)
# WARNING: Decompyle incomplete

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='GCode Metadata Extraction Utility')
    parser.add_argument('-f', '--filename', metavar='<filename>', help='name gcode file to parse')
    parser.add_argument('-p', '--path', default=os.path.abspath(os.path.dirname(__file__)), metavar='<path>', help='optional absolute path for file')
    parser.add_argument('-u', '--ufp', metavar='<ufp file>', default=None, help='optional path of ufp file to extract')
    parser.add_argument('-o', '--check-objects', dest='check_objects', action='store_true', help='process gcode file for exclude opbject functionality')
    args = parser.parse_args()
    check_objects = args.check_objects
    enabled_msg = 'enabled' if check_objects else 'disabled'
    log_to_stderr(f'''Object Processing is {enabled_msg}''')
    main(args.path, args.filename, args.ufp, check_objects)
