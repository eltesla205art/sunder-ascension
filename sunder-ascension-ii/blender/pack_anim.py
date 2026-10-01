"""Pack the Keeper animation frames from `keepers.py --anim` into sprite sheets for the game.

    python pack_anim.py <render_dir> <sheet_dir> <web_assets_dir>      (needs Pillow; plain Python, no Blender)

For each keeper_<id>_f00..fNN.png in <render_dir>/anim:
  - finds one crop box covering the Keeper in every frame, kept symmetric about the canvas centre
    (the centre is where the static sprite's centre is, so the game can draw both at the same point);
  - lays the frames left to right into <sheet_dir>/keeper_<id>_anim.png (full quality)
    and <web_assets_dir>/keeper_<id>_anim.webp (what the game loads).
"""
import glob
import os
import re
import sys

from PIL import Image

src, sheets, web = sys.argv[1], sys.argv[2], sys.argv[3]
os.makedirs(sheets, exist_ok=True)
os.makedirs(web, exist_ok=True)
frames = {}
for f in sorted(glob.glob(os.path.join(src, "anim", "keeper_*_f[0-9][0-9].png"))):
    kid = re.match(r"keeper_(.+)_f\d\d\.png", os.path.basename(f)).group(1)
    frames.setdefault(kid, []).append(f)

for kid, files in frames.items():
    ims = [Image.open(f).convert("RGBA") for f in files]
    W, H = ims[0].size
    cx, cy = W / 2, H / 2
    hw = hh = 0
    for im in ims:
        box = im.getchannel("A").point(lambda a: 255 if a > 6 else 0).getbbox()
        if box:
            hw = max(hw, cx - box[0], box[2] - cx)
            hh = max(hh, cy - box[1], box[3] - cy)
    hw, hh = int(hw) + 2, int(hh) + 2
    crop = (int(cx) - hw, int(cy) - hh, int(cx) + hw, int(cy) + hh)
    fw, fh = crop[2] - crop[0], crop[3] - crop[1]
    sheet = Image.new("RGBA", (fw * len(ims), fh))
    for i, im in enumerate(ims):
        sheet.paste(im.crop(crop), (i * fw, 0))
    sheet.save(os.path.join(sheets, f"keeper_{kid}_anim.png"))
    out = os.path.join(web, f"keeper_{kid}_anim.webp")
    sheet.save(out, "WEBP", quality=82, method=6)
    print(f"{kid}: {len(ims)} frames of {fw}x{fh}, {os.path.getsize(out) // 1024} KB")
