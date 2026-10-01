"""SUNDER: Ascension II — top-down stage backdrops for the Act IV Hours.

    python stages.py <out_dir> [samples]

Writes stage_<id>.png (480x720, opaque) for:
  starfall — Hour 10: a dark underworld plain cratered by fallen crystal stars, gold ruins
  heart    — Hour 11: the buried Atlantean chamber floor, gold channels running toward the Heart
  apep     — Hour 12: the ground is Apep's back — obsidian scales over violet light, a ridge of spines
The game scrolls each tile, mirroring every other copy so the seam never shows, and keeps it dim behind play.
Matching Kling stage concepts (job IDs in ../artifacts/game-progress.md) can replace these files.
"""
import math
import os
import random
import sys

import bpy
from mathutils import Vector

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
_argv, sys.argv = sys.argv, sys.argv[:1]
import ships  # noqa: E402
sys.argv = _argv

OUT = sys.argv[1] if len(sys.argv) > 1 else "."
SAMPLES = int(sys.argv[2]) if len(sys.argv) > 2 else 48
W, H = 8.0, 12.0          # world units of one 480x720 tile


def obj():
    return bpy.context.object


def mat(name, color, rough=0.8, metal=0.0, emit=None, strength=0.0, bump=None):
    m = bpy.data.materials.new(name)
    m.use_nodes = True
    nt = m.node_tree
    b = nt.nodes["Principled BSDF"]
    b.inputs["Base Color"].default_value = (*color, 1)
    b.inputs["Roughness"].default_value = rough
    b.inputs["Metallic"].default_value = metal
    if emit:
        b.inputs["Emission Color"].default_value = (*emit, 1)
        b.inputs["Emission Strength"].default_value = strength
    if bump:
        kind, scale, amount = bump
        t = nt.nodes.new("ShaderNodeTexVoronoi" if kind == "cracks" else "ShaderNodeTexNoise")
        t.inputs["Scale"].default_value = scale
        if kind == "cracks":
            t.feature = "DISTANCE_TO_EDGE"
        bp = nt.nodes.new("ShaderNodeBump")
        bp.inputs["Strength"].default_value = amount
        nt.links.new(t.outputs["Distance" if kind == "cracks" else "Fac"], bp.inputs["Height"])
        nt.links.new(bp.outputs["Normal"], b.inputs["Normal"])
    return m


def plane(z, m, w=W * 1.4, h=H * 1.4):
    bpy.ops.mesh.primitive_plane_add(size=1, location=(0, 0, z))
    p = obj()
    p.scale = (w, h, 1)
    ships.assign(p, m)
    return p


def shard(loc, h, r, m, tilt):
    bpy.ops.mesh.primitive_cone_add(vertices=6, radius1=r, radius2=r * 0.1, depth=h, location=loc, rotation=tilt)
    ships.assign(obj(), m)


def scatter(n, margin=0.3):
    return [(random.uniform(-W / 2 + margin, W / 2 - margin), random.uniform(-H / 2 + margin, H / 2 - margin))
            for _ in range(n)]


def starfall():
    ground = mat("ground", (0.035, 0.03, 0.05), rough=0.9, bump=("cracks", 3.0, 0.6))
    rim = mat("rim", (0.08, 0.06, 0.09), rough=0.7)
    crystal = mat("crystal", (0.6, 0.15, 0.55), rough=0.1, emit=(1.0, 0.2, 0.65), strength=1.4)
    star = mat("star", (1, 1, 1), emit=(0.8, 0.75, 1.0), strength=3.0)
    gold = mat("gold", (0.6, 0.42, 0.15), rough=0.4, metal=1.0)
    plane(0, ground)
    for x, y in scatter(11, 0.8):                                   # impact craters with a star at the bottom
        r = random.uniform(0.4, 0.95)
        bpy.ops.mesh.primitive_torus_add(major_radius=r, minor_radius=r * 0.18, location=(x, y, 0.02))
        ships.assign(obj(), rim)
        bpy.ops.mesh.primitive_cylinder_add(radius=r * 0.85, depth=0.02, location=(x, y, 0.0))
        ships.assign(obj(), mat("pit", (0.01, 0.008, 0.015), rough=1.0))
        bpy.ops.mesh.primitive_uv_sphere_add(radius=r * 0.12, location=(x, y, 0.05))
        ships.assign(obj(), star)
        for k in range(4):
            a = random.uniform(0, math.tau)
            shard((x + math.cos(a) * r * 0.4, y + math.sin(a) * r * 0.4, 0.1), r * 0.7, r * 0.1, crystal,
                  (math.cos(a) * 0.6, math.sin(a) * 0.6, 0))
    for x, y in scatter(10):                                       # broken gold ruins
        bpy.ops.mesh.primitive_cube_add(size=1, location=(x, y, 0.05), rotation=(0, 0, random.uniform(0, 3)))
        o = obj()
        o.scale = (random.uniform(0.2, 0.6), random.uniform(0.1, 0.25), 0.1)
        ships.assign(o, gold)


def heart():
    floor = mat("floor", (0.03, 0.025, 0.03), rough=0.35, metal=0.4, bump=("cracks", 1.2, 0.35))
    channel = mat("channel", (0.4, 0.25, 0.05), emit=(1.0, 0.55, 0.12), strength=1.6)
    crystal = mat("crystal", (0.6, 0.15, 0.55), rough=0.1, emit=(1.0, 0.2, 0.65), strength=1.0)
    plane(0, floor)
    # gold channels: a circuit of straight runs and right-angle turns flowing up the screen toward the Heart
    for lane in (-3.3, -2.0, -0.7, 0.7, 2.0, 3.3):
        x, y = lane, -H / 2 - 0.5
        while y < H / 2 + 0.5:
            run = random.uniform(1.0, 2.6)
            bpy.ops.mesh.primitive_cube_add(size=1, location=(x, y + run / 2, 0.01))
            o = obj()
            o.scale = (0.07, run, 0.02)
            ships.assign(o, channel)
            y += run
            dx = random.choice((-0.7, 0.7))
            if abs(x + dx - lane) < 0.8:
                bpy.ops.mesh.primitive_cube_add(size=1, location=(x + dx / 2, y, 0.01))
                o = obj()
                o.scale = (abs(dx) + 0.07, 0.07, 0.02)
                ships.assign(o, channel)
                x += dx
    for y in (-H / 4, H / 4):                                       # carved glyph bands
        bpy.ops.mesh.primitive_cube_add(size=1, location=(0, y, 0.0))
        o = obj()
        o.scale = (W * 1.4, 0.35, 0.02)
        ships.assign(o, mat("band", (0.12, 0.09, 0.05), rough=0.5, metal=0.8))
    for x, y in scatter(8):
        shard((x, y, 0.0), random.uniform(0.4, 0.9), 0.1, crystal, (random.uniform(-0.4, 0.4), random.uniform(-0.4, 0.4), 0))


def apep_back():
    under = mat("under", (0.05, 0.0, 0.1), emit=(0.45, 0.1, 1.0), strength=0.9)
    scale_m = mat("scale", (0.035, 0.02, 0.06), rough=0.25, metal=0.85)
    spine = mat("spine", (0.6, 0.15, 0.55), rough=0.1, emit=(1.0, 0.2, 0.65), strength=1.2)
    plane(-0.15, under)
    # rows of overlapping scales, offset every other row
    rows, cols = 13, 7
    for r in range(rows):
        y = -H / 2 - 0.5 + r * (H + 1) / rows
        for c in range(cols + 1):
            x = -W / 2 + (c + (0.5 if r % 2 else 0)) * W / cols
            bpy.ops.mesh.primitive_uv_sphere_add(segments=16, ring_count=8, radius=1, location=(x, y, 0))
            o = obj()
            o.scale = (W / cols * 0.62, (H + 1) / rows * 0.85, 0.12)
            o.rotation_euler = (0.25, 0, 0)                          # lift the leading edge so light leaks between
            ships.assign(o, scale_m)
    for y in [(-H / 2 + k * 1.0) for k in range(13)]:                # the crystal ridge down the middle
        shard((0, y, 0.1), 0.7, 0.16, spine, (-0.3, 0, 0))


STAGES = {"starfall": starfall, "heart": heart, "apep": apep_back}


def render(path):
    sc = bpy.context.scene
    w = bpy.data.worlds.new("w")
    sc.world = w
    w.use_nodes = True
    w.node_tree.nodes["Background"].inputs["Color"].default_value = (0.02, 0.02, 0.05, 1)
    for name, loc, energy, color in (("moon", (-6, 7, 9), 900, (0.55, 0.62, 1.0)),
                                     ("fill", (4, -6, 6), 250, (0.8, 0.6, 1.0))):
        ld = bpy.data.lights.new(name, "AREA")
        ld.energy, ld.color, ld.size = energy, color, 6
        o = bpy.data.objects.new(name, ld)
        sc.collection.objects.link(o)
        o.location = loc
        o.rotation_euler = (Vector((0, 0, 0)) - Vector(loc)).to_track_quat("-Z", "Y").to_euler()
    cam = bpy.data.objects.new("cam", bpy.data.cameras.new("cam"))
    sc.collection.objects.link(cam)
    cam.data.type = "ORTHO"
    cam.data.ortho_scale = H
    cam.location = (0, 0, 20)
    sc.camera = cam
    sc.render.engine = "CYCLES"
    sc.cycles.device = "CPU"
    sc.cycles.samples = SAMPLES
    sc.cycles.use_denoising = True
    sc.render.resolution_x, sc.render.resolution_y = 480, 720
    sc.view_settings.view_transform = "AgX"
    sc.render.image_settings.file_format = "PNG"
    sc.render.filepath = path
    bpy.ops.render.render(write_still=True)


def main():
    os.makedirs(OUT, exist_ok=True)
    for sid, build in STAGES.items():
        random.seed(sum(map(ord, sid)))
        ships.reset()
        build()
        render(f"{OUT}/stage_{sid}.png")
        print("rendered", sid)


if __name__ == "__main__":
    main()
