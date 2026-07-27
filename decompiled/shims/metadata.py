# =====================================================================
# PARTIAL DECOMPILATION -- this module did not fully round-trip.
# The 3.9 bytecode uses control flow the decompiler could not fully
# reconstruct (e.g. try/except/else with returns, or a generator with a
# dropped builtin rendered as `None(...)`). The code below is best-effort
# and will not import as-is. Ground-truth disassembly for repair:
#     decompiled/_disasm/metadata.txt
# =====================================================================

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
