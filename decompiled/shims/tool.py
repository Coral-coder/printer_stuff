# =====================================================================
# PARTIAL DECOMPILATION -- this module did not fully round-trip.
# The 3.9 bytecode uses control flow the decompiler could not fully
# reconstruct (e.g. try/except/else with returns, or a generator with a
# dropped builtin rendered as `None(...)`). The code below is best-effort
# and will not import as-is. Ground-truth disassembly for repair:
#     decompiled/_disasm/tool.txt
# =====================================================================

# Source Generated with Decompyle++
# File: tool.pyc (Python 3.9)

import re
import os
import logging
import threading
from subprocess import call
import json
import random
import time
from extras.base_info import base_dir
from datetime import datetime

def send(msg, data = ({ },)):
