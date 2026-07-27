#!/usr/bin/env python3.9
"""Safe AST-level repair of decompiler artifacts in decompiled/shims/*.py.

Run under CPython 3.9. Each transform is applied only if the module (a) parses,
(b) still parses after, and (c) its recompiled bytecode matches the original
*at least as well* as before (measured functionally). So a repair can only ever
increase faithfulness, never regress.

Transforms:
  * except-as cleanup:  `except T:` whose body is
        v = None
        try: <body> finally: v = None; del v
        v = None; del v
    -> `except T as v: <body>`   (pycdc can't render `except ... as v:`)
"""
import ast, os, sys, glob, marshal, dis, difflib, py_compile, tempfile

if sys.version_info[:2] != (3, 9):
    sys.exit("run under Python 3.9")

ROOT = os.environ.get("REPO_ROOT", os.getcwd())

# ---------- faithfulness scoring (same basis as tools/bcdiff.py) ----------
def _norm(v):
    if hasattr(v, "co_code"):
        return ("<code>", v.co_name)
    if isinstance(v, frozenset):
        return ("frozenset", tuple(sorted(map(repr, v))))
    if isinstance(v, tuple):
        return ("tuple", tuple(_norm(x) for x in v))
    return (type(v).__name__, v)

def _collect(code, path, out):
    k = path; n = 0
    while k in out:
        n += 1; k = "%s#%d" % (path, n)
    out[k] = [(i.opname, _norm(i.argval)) for i in dis.get_instructions(code)]
    for c in code.co_consts:
        if hasattr(c, "co_code"):
            _collect(c, path + "." + c.co_name, out)
    return out

def _score(orig_code, cand_code):
    fa = _collect(orig_code, "<m>", {})
    fb = _collect(cand_code, "<m>", {})
    num = den = 0.0
    for k in set(fa) | set(fb):
        oa, ob = fa.get(k, []), fb.get(k, [])
        w = max(len(oa), len(ob), 1)
        num += difflib.SequenceMatcher(None, oa, ob).ratio() * w
        den += w
    return num / den if den else 1.0

def _compile_score(src_text, orig_code, fname):
    try:
        cand = compile(src_text, fname, "exec")
    except Exception:
        return None
    return _score(orig_code, cand)

# ---------- transform: except-as cleanup ----------
def _is_del_none(stmts, var):
    """stmts == [v = None, del v] (order-tolerant, allows just one)."""
    ok = False
    for s in stmts:
        if isinstance(s, ast.Assign) and len(s.targets) == 1 \
                and isinstance(s.targets[0], ast.Name) and s.targets[0].id == var \
                and isinstance(s.value, ast.Constant) and s.value.value is None:
            ok = True
        elif isinstance(s, ast.Delete) and len(s.targets) == 1 \
                and isinstance(s.targets[0], ast.Name) and s.targets[0].id == var:
            ok = True
        else:
            return False
    return ok

class ExceptAs(ast.NodeTransformer):
    def __init__(self):
        self.changed = 0
    def visit_ExceptHandler(self, node):
        self.generic_visit(node)
        if node.name is not None or node.type is None:
            return node
        b = node.body
        # first stmt: v = None
        if not (b and isinstance(b[0], ast.Assign) and len(b[0].targets) == 1
                and isinstance(b[0].targets[0], ast.Name)
                and isinstance(b[0].value, ast.Constant) and b[0].value.value is None):
            return node
        var = b[0].targets[0].id
        # find the inner Try whose finalbody is the v cleanup
        rest = b[1:]
        if not (rest and isinstance(rest[0], ast.Try) and not rest[0].handlers
                and rest[0].finalbody and _is_del_none(rest[0].finalbody, var)):
            return node
        inner = rest[0]
        trailing = rest[1:]
        if trailing and not _is_del_none(trailing, var):
            return node
        node.name = var
        node.body = inner.body
        self.changed += 1
        return node

def repair(src_text):
    tree = ast.parse(src_text)
    tr = ExceptAs()
    tree = tr.fix_missing_locations(tree) if False else tr.visit(tree)
    ast.fix_missing_locations(tree)
    if tr.changed == 0:
        return None
    return ast.unparse(tree)

def main():
    files = sorted(glob.glob(os.path.join(ROOT, "decompiled/shims/*.py")))
    improved = 0
    for f in files:
        rel = os.path.relpath(f, os.path.join(ROOT, "decompiled"))
        orig_pyc = os.path.join(ROOT, "proprietary", rel[:-3] + ".pyc")
        if not os.path.exists(orig_pyc):
            continue
        src = open(f).read()
        try:
            ast.parse(src)
        except Exception:
            continue  # only touch modules that already parse
        orig_code = marshal.loads(open(orig_pyc, "rb").read()[16:])
        before = _compile_score(src, orig_code, f)
        try:
            new = repair(src)
        except Exception:
            new = None
        if not new:
            continue
        after = _compile_score(new, orig_code, f)
        if after is not None and (before is None or after >= before - 1e-9):
            open(f, "w").write(new)
            if after > (before or 0) + 1e-9:
                improved += 1
                print(f"  improved {os.path.basename(f)}: {before:.3f} -> {after:.3f}")
    print(f"except-as repair applied; modules improved: {improved}")

if __name__ == "__main__":
    main()
