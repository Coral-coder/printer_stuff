#!/usr/bin/env bash
# build_flashable_image.sh
# ------------------------------------------------------------------------------
# Overlay the bug-fixed Klipper `extras` modules onto a STOCK Creality K1-series
# firmware .img and repack a flashable image.
#
# Run on a Linux PC (NOT the printer) with `p7zip-full` and `squashfs-tools`
# installed:   sudo apt install p7zip-full squashfs-tools
#
# The K1 .img format is:  password-protected 7z  ->  split root0/root1/...  ->
# concatenated squashfs rootfs. Creality ships NO checksums/signatures, so a
# correctly repacked image flashes via the normal USB updater.
#
# This script is STRUCTURE-ADAPTIVE: it reads the split part size, squashfs
# compression and block size from YOUR base image and mirrors them, so the
# output matches your exact firmware version rather than a hard-coded guess.
#
# !!! READ THE README BEFORE FLASHING. Wrong model/version = bricked printer. !!!
# ------------------------------------------------------------------------------
set -euo pipefail

BASE_IMG=""; PATCH_DIR=""; OUT_IMG=""; EXTRAS_SUBPATH="usr/share/klipper/klippy/extras"
PW="${CREALITY_IMG_PASSWORD:-}"

die(){ echo "ERROR: $*" >&2; exit 1; }
usage(){ cat >&2 <<EOF
Usage: $0 --base STOCK.img --patch PATCH_DIR --out PATCHED.img [--password PW] [--extras-path PATH]
  --base        stock Creality K1-series firmware .img (download for YOUR exact model)
  --patch       directory of patched .pyc files to drop into klippy/extras
  --out         output flashable .img to create
  --password    7z password for the image (or set CREALITY_IMG_PASSWORD; or omit to be prompted)
  --extras-path override the in-rootfs extras path (default: $EXTRAS_SUBPATH)
EOF
exit 1; }

while [ $# -gt 0 ]; do case "$1" in
  --base) BASE_IMG="$2"; shift 2;;
  --patch) PATCH_DIR="$2"; shift 2;;
  --out) OUT_IMG="$2"; shift 2;;
  --password) PW="$2"; shift 2;;
  --extras-path) EXTRAS_SUBPATH="$2"; shift 2;;
  -h|--help) usage;;
  *) die "unknown arg: $1";;
esac; done

[ -n "$BASE_IMG" ] && [ -f "$BASE_IMG" ] || die "--base image not found"
[ -n "$PATCH_DIR" ] && [ -d "$PATCH_DIR" ] || die "--patch dir not found"
[ -n "$OUT_IMG" ] || die "--out required"
# resolve to absolute paths NOW (the repack step runs inside a cd'd subshell)
BASE_IMG="$(readlink -f "$BASE_IMG")"
PATCH_DIR="$(readlink -f "$PATCH_DIR")"
case "$OUT_IMG" in /*) ;; *) OUT_IMG="$PWD/$OUT_IMG";; esac
for t in 7z unsquashfs mksquashfs split; do command -v "$t" >/dev/null || die "missing tool: $t (apt install p7zip-full squashfs-tools)"; done

PWARG=(); [ -n "$PW" ] && PWARG=(-p"$PW")   # if empty, 7z prompts interactively

WORK="$(mktemp -d)"; trap 'rm -rf "$WORK"' EXIT
echo ">> workspace: $WORK"

echo ">> [1/6] extracting base image ..."
mkdir "$WORK/unpack"
7z x "${PWARG[@]}" -o"$WORK/unpack" "$BASE_IMG" >/dev/null || die "7z extract failed (wrong password? not a K1 7z image?)"

# identify the split rootfs parts (root0, root1, ...) in numeric order, + other members
mapfile -t PARTS < <(cd "$WORK/unpack" && ls | grep -E '^root[0-9]+$' | sort -V)
[ "${#PARTS[@]}" -gt 0 ] || die "no root* parts inside the image — unexpected layout"
mapfile -t OTHERS < <(cd "$WORK/unpack" && ls | grep -vE '^root[0-9]+$' || true)
PARTSIZE="$(stat -c%s "$WORK/unpack/${PARTS[0]}")"
# detect naming width (root0 vs root00) from the first part
PREFIXNUM="${PARTS[0]#root}"; PAD="${#PREFIXNUM}"
echo "   parts=${#PARTS[@]}  partsize=${PARTSIZE}  pad=${PAD}  others=[${OTHERS[*]:-none}]"

echo ">> [2/6] reassembling + inspecting squashfs ..."
( cd "$WORK/unpack" && cat "${PARTS[@]}" > "$WORK/rootfs.sqfs" )
COMP="$(unsquashfs -s "$WORK/rootfs.sqfs" | awk '/Compression/{print $2; exit}')"
BLK="$(unsquashfs -s "$WORK/rootfs.sqfs"  | awk '/Block size/{print $3; exit}')"
[ -n "$COMP" ] && [ -n "$BLK" ] || die "could not read squashfs superblock"
echo "   squashfs comp=$COMP block=$BLK"

echo ">> [3/6] unpacking rootfs ..."
unsquashfs -q -d "$WORK/root" "$WORK/rootfs.sqfs" >/dev/null
DEST="$WORK/root/$EXTRAS_SUBPATH"
[ -d "$DEST" ] || die "extras path '$EXTRAS_SUBPATH' not present in rootfs — check --extras-path"

echo ">> [4/6] overlaying patched modules ..."
n=0; for f in "$PATCH_DIR"/*.pyc; do [ -e "$f" ] || continue; cp -f "$f" "$DEST/"; n=$((n+1)); echo "   + $(basename "$f")"; done
[ "$n" -gt 0 ] || die "no .pyc found in --patch dir"
find "$WORK/root" -name '__pycache__' -type d -prune -exec rm -rf {} + 2>/dev/null || true
echo "   overlaid $n module(s)"

echo ">> [5/6] rebuilding squashfs (comp=$COMP block=$BLK) ..."
mksquashfs "$WORK/root" "$WORK/newrootfs.sqfs" -comp "$COMP" -b "$BLK" -noappend -no-progress >/dev/null

echo ">> [6/6] re-splitting + repacking 7z ..."
mkdir "$WORK/repack"
( cd "$WORK/repack" && split -b "$PARTSIZE" -d -a "$PAD" "$WORK/newrootfs.sqfs" root )
# normalise names to the vendor pattern rootN with the detected padding
i=0; for p in $(cd "$WORK/repack" && ls | sort -V); do
  printf -v name "root%0${PAD}d" "$i"
  [ "$p" = "$name" ] || mv "$WORK/repack/$p" "$WORK/repack/$name"; i=$((i+1))
done
NEWCOUNT="$(ls "$WORK/repack" | wc -l)"
[ "$NEWCOUNT" -le 10 ] || echo "   WARNING: $NEWCOUNT parts (>10); verify your updater concatenates root* in numeric order"
# bring across any non-root members unchanged
for o in "${OTHERS[@]:-}"; do [ -n "$o" ] && cp -a "$WORK/unpack/$o" "$WORK/repack/$o"; done
# header-encryption on if the base had encrypted headers (listing without pw fails)
MHE=(); 7z l "$BASE_IMG" >/dev/null 2>&1 || MHE=(-mhe=on)
rm -f "$OUT_IMG"
( cd "$WORK/repack" && 7z a -t7z "${PWARG[@]}" "${MHE[@]}" "$OUT_IMG" ./* >/dev/null ) \
  || die "7z repack failed"

echo ">> DONE: $OUT_IMG"
ls -lh "$OUT_IMG"
echo ">> ${n} module(s) overlaid; base parts mirrored (${#PARTS[@]} -> ${NEWCOUNT}, size ${PARTSIZE})."
echo ">> Flash by copying '$OUT_IMG' to a FAT32 USB root and confirming the on-screen update."
echo ">> Keep the STOCK image handy for recovery. Verify model/version FIRST (see README)."
