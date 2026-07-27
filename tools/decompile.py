#!/usr/bin/env python3
"""Decompile all .pyc under proprietary/ with pycdc, then repair the two
systematic, mechanically-safe pycdc artifacts:

  1. `f(a, b, c, **('k1','k2'))`  ->  `f(a, k1=b, k2=c)`
     (pycdc renders CALL_FUNCTION_KW keyword names as a trailing **tuple)
  2. `from  import x`             ->  `from . import x`
     (pycdc drops the leading dot on level-1 relative imports)

Each result is validated with ast.parse. A JSON report is emitted.
"""
import ast, json, os, subprocess, sys, re

ROOT = os.environ.get("REPO_ROOT", os.getcwd())
PYCDC = os.environ.get("PYCDC", "pycdc")  # path to a built zrax/pycdc binary
OUT = os.path.join(ROOT, "decompiled")

# ---- string/comment mask so paren scanning ignores quotes and comments ----
def mask(src):
    """Return a list `m` where m[i] is True if src[i] is 'code' (not inside a
    string literal or comment), so parens/commas there are structural."""
    m = [True] * len(src)
    i, n = 0, len(src)
    quote = None      # active string delimiter
    triple = False
    while i < n:
        c = src[i]
        if quote:
            m[i] = False
            if c == "\\" and not triple:
                if i + 1 < n:
                    m[i+1] = False
                i += 2
                continue
            if triple:
                if src[i:i+3] == quote:
                    m[i+1] = m[i+2] = False
                    i += 3
                    quote = None
                    triple = False
                    continue
            else:
                if c == quote:
                    quote = None
                elif c == "\n":
                    quote = None  # defensive; shouldn't happen
            i += 1
            continue
        # not in string
        if c == "#":
            while i < n and src[i] != "\n":
                m[i] = False
                i += 1
            continue
        if c in "\"'":
            if src[i:i+3] in ('"""', "'''"):
                quote = src[i:i+3]
                triple = True
                m[i] = m[i+1] = m[i+2] = False
                i += 3
                continue
            quote = c
            triple = False
            m[i] = False
            i += 1
            continue
        i += 1
    return m

def split_top_args(src, start, end, m):
    """Split src[start:end] into argument spans at top-level (depth-0) commas."""
    args, depth, cur = [], 0, start
    i = start
    while i < end:
        if m[i]:
            c = src[i]
            if c in "([{":
                depth += 1
            elif c in ")]}":
                depth -= 1
            elif c == "," and depth == 0:
                args.append((cur, i))
                cur = i + 1
        i += 1
    args.append((cur, end))
    # drop a trailing empty span from a trailing comma
    if args and src[args[-1][0]:args[-1][1]].strip() == "":
        args.pop()
    return args

def parse_names(tuple_body):
    """tuple_body is the text inside **( ... ); return the keyword names."""
    names = []
    for part in re.split(r",", tuple_body):
        part = part.strip()
        if not part:
            continue
        try:
            names.append(ast.literal_eval(part))
        except Exception:
            names.append(part.strip("'\""))
    return names

def find_matching(src, open_idx, m):
    """Given index of an opening bracket, return index of its match."""
    depth = 0
    i = open_idx
    n = len(src)
    while i < n:
        if m[i]:
            c = src[i]
            if c in "([{":
                depth += 1
            elif c in ")]}":
                depth -= 1
                if depth == 0:
                    return i
        i += 1
    return -1

def fix_kwargs(src):
    """Repeatedly rewrite one **('k',...) occurrence until none remain."""
    guard = 0
    while True:
        guard += 1
        if guard > 100000:
            break
        m = mask(src)
        # find a structural '**(' preceded (ignoring ws) by ',' — i.e. it is a
        # trailing kw-names tuple, not real dict unpacking of a variable.
        pos = -1
        i = 0
        while i < len(src) - 2:
            if m[i] and src[i:i+2] == "**" and i+2 < len(src) and src[i+2] == "(" and m[i+2]:
                pos = i
                break
            i += 1
        if pos == -1:
            return src
        star = pos
        inner_open = pos + 2
        inner_close = find_matching(src, inner_open, m)
        if inner_close == -1:
            return src  # malformed; give up gracefully
        tuple_body = src[inner_open+1:inner_close]
        # only treat as kw-names convention if body is all string literals
        stripped = tuple_body.strip().rstrip(",").strip()
        if not stripped or not re.fullmatch(r"\s*(['\"].*?['\"]\s*,?\s*)+", tuple_body, re.S):
            # not a literal-string tuple -> real **kwargs unpack of a tuple? leave it
            # to avoid infinite loop, blank the '**' marker temporarily is unsafe;
            # instead bail out of the whole pass.
            return src
        names = parse_names(tuple_body)
        # locate enclosing call open-paren by scanning left from star
        depth = 0
        j = star - 1
        call_open = -1
        while j >= 0:
            if m[j]:
                c = src[j]
                if c in ")]}":
                    depth += 1
                elif c in "([{":
                    if depth == 0:
                        call_open = j
                        break
                    depth -= 1
            j -= 1
        if call_open == -1:
            return src
        call_close = find_matching(src, call_open, m)
        if call_close == -1:
            return src
        args = split_top_args(src, call_open+1, call_close, m)
        # last arg span is the **(...) one
        real_args = args[:-1]
        N = len(names)
        if N > len(real_args):
            # can't map safely; bail this occurrence by leaving file unchanged
            return src
        head = real_args[:len(real_args)-N]
        kw = real_args[len(real_args)-N:]
        parts = [src[a:b].strip() for (a, b) in head]
        for name, (a, b) in zip(names, kw):
            parts.append(f"{name}={src[a:b].strip()}")
        new_call = src[call_open] + ", ".join(parts) + src[call_close]
        src = src[:call_open] + new_call + src[call_close+1:]
    return src

def fix_imports(src):
    # `from  import x` (empty module) -> `from . import x`
    src = re.sub(r"(?m)^(\s*)from\s+import\s+", r"\1from . import ", src)
    return src

_LAMBDA0 = re.compile(r"lambda\s+\.0\s*=\s*None\s*:")

def fix_comprehensions(src):
    """pycdc renders comprehensions/generators as the raw CPython form
      (lambda .0 = None: [ EXPR for T in .0 ])(ITERABLE)
    where `.0` is the internal iterator placeholder (invalid Python).
    Rewrite to a real comprehension: [ EXPR for T in ITERABLE ]."""
    guard = 0
    while True:
        guard += 1
        if guard > 100000:
            break
        m = mask(src)
        # find `(lambda .0 = None:` where the '(' just before lambda is structural
        mo = None
        for cand in _LAMBDA0.finditer(src):
            ls = cand.start()
            # find the '(' immediately preceding (skip whitespace)
            k = ls - 1
            while k >= 0 and src[k] in " \t\n":
                k -= 1
            if k >= 0 and src[k] == "(" and m[k]:
                mo = (cand, k)
                break
        if mo is None:
            return src
        cand, wrap_open = mo
        body_start = cand.end()  # just after the ':'
        wrap_close = find_matching(src, wrap_open, m)
        if wrap_close == -1:
            return src
        body = src[body_start:wrap_close]
        # the immediately following (ARG)
        j = wrap_close + 1
        while j < len(src) and src[j] in " \t\n":
            j += 1
        if j >= len(src) or src[j] != "(":
            return src
        arg_open = j
        arg_close = find_matching(src, arg_open, m)
        if arg_close == -1:
            return src
        arg = src[arg_open+1:arg_close].strip()
        # replace the `.0` placeholder(s) in body with the iterable (parenthesised)
        new_body = re.sub(r"(?<=[\s(,:])\.0(?=[\s)\],:])", "(" + arg + ")", body)
        replacement = new_body.strip()
        src = src[:wrap_open] + replacement + src[arg_close+1:]
    return src

def main():
    pycs = []
    for dirpath, _, files in os.walk(os.path.join(ROOT, "proprietary")):
        for f in files:
            if f.endswith(".pyc"):
                pycs.append(os.path.join(dirpath, f))
    pycs.sort()
    report = []
    for pyc in pycs:
        rel = os.path.relpath(pyc, ROOT)
        proc = subprocess.run([PYCDC, pyc], capture_output=True, text=True, timeout=120)
        raw = proc.stdout
        warn = proc.stderr.strip()
        try:
            repaired = fix_imports(fix_kwargs(fix_comprehensions(raw)))
        except Exception as e:
            repaired = raw
            warn = (warn + f"\n[repair-exception] {e}").strip()
        # validate
        raw_ok = _parses(raw)
        rep_ok = _parses(repaired)
        final = repaired if rep_ok or not raw_ok else raw
        # if repair broke a file that raw could parse, prefer raw
        if raw_ok and not rep_ok:
            final = raw
        out_rel = os.path.relpath(pyc, os.path.join(ROOT, "proprietary"))
        out_rel = out_rel[:-1]  # .pyc -> .py
        out_path = os.path.join(OUT, out_rel)
        os.makedirs(os.path.dirname(out_path), exist_ok=True)
        with open(out_path, "w") as fh:
            fh.write(final)
        report.append({
            "pyc": rel,
            "out": os.path.relpath(out_path, ROOT),
            "raw_parses": raw_ok,
            "repaired_parses": rep_ok,
            "used_repaired": final is repaired,
            "kw_tuples_remaining": final.count("**('") + final.count('**("'),
            "none_calls": len(re.findall(r"(?<![\w.])None\(", final)),
            "unsupported": ("Unsupported" in warn) or ("unsupported" in warn),
            "warn": warn[:400],
            "lines": final.count("\n") + 1,
        })
    with open(os.path.join(ROOT, "decompiled", "_report.json"), "w") as fh:
        json.dump(report, fh, indent=2)
    # summary
    n = len(report)
    ok = sum(1 for r in report if r["repaired_parses"])
    kwleft = sum(r["kw_tuples_remaining"] for r in report)
    nonec = sum(r["none_calls"] for r in report)
    uns = sum(1 for r in report if r["unsupported"])
    print(f"files={n} ast_ok={ok} ast_fail={n-ok} kw_tuples_left={kwleft} None_calls={nonec} files_with_unsupported_opcodes={uns}")
    print("--- ast failures ---")
    for r in report:
        if not r["repaired_parses"]:
            print(f"  {r['pyc']}  (raw_ok={r['raw_parses']}) warn={r['warn'][:120]!r}")

def _parses(s):
    try:
        ast.parse(s)
        return True
    except Exception:
        return False

if __name__ == "__main__":
    main()
