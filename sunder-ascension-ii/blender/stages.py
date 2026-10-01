"""SUNDER: Ascension II — top-down stage backdrops, one per Hour of the Night.

    python stages.py <out_dir> [samples] [id ...]      (no ids: render every stage)

Writes stage_<id>.png (480x720, opaque), arenas from DESIGN.md §1:
  horizon    — Hour 1: the western desert, rail yards and crystal-infested armour wrecks
  delta      — Hour 2: the drowned fields, black floodwater, reed beds and fallen obelisks
  mirror     — Hour 3: the glass desert, a cracked mirror plain reflecting the sky
  spires     — Hour 4: the sunken spires of Atlantis, ruins glowing on the deep floor
  sokar      — Hour 5: Sokar's dark sand-sea, shifting dunes and half-buried hawk statues
  firelake   — Hour 6: the Lake of Fire, cooled crust floating on lava
  coils      — Hour 7: open night with Apep's coils passing far below
  ironsky    — Hour 8: the iron sky, girder decks of the Hittite war-machine over cloud
  judgement  — Hour 9: the Judgement Hall, polished tiles, column tops, feather inlays
  starfall   — Hour 10: a dark underworld plain cratered by fallen crystal stars, gold ruins
  heart      — Hour 11: the buried Atlantean chamber floor, gold channels running toward the Heart
  apep       — Hour 12: the ground is Apep's back — obsidian scales over violet light, a ridge of spines
The game scrolls each tile, mirroring every other copy so the seam never shows, and keeps it dim behind play.
Kling helps: save a chosen Kling stage concept as ../art/kling/stage_<id>.png and re-run; it becomes the ground
texture under the Blender props and lighting (job IDs in ../artifacts/game-progress.md).
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


GROUND = []   # the first plane each builder adds is its ground; a Kling texture can be laid on it


def plane(z, m, w=W * 1.4, h=H * 1.4):
    bpy.ops.mesh.primitive_plane_add(size=1, location=(0, 0, z))
    p = obj()
    p.scale = (w, h, 1)
    ships.assign(p, m)
    GROUND.append(p)
    return p


def kling_ground(path):
    """Kling helps Blender: a Kling stage concept becomes the ground's colour, under Blender's own props and light.
    The plane is 1.4x the camera frame, so the image is scaled to match the visible 480x720 tile."""
    if not GROUND:
        return False
    m = GROUND[0].active_material
    nt = m.node_tree
    tex = nt.nodes.new("ShaderNodeTexImage")
    tex.image = bpy.data.images.load(path)
    tc = nt.nodes.new("ShaderNodeTexCoord")
    mp = nt.nodes.new("ShaderNodeMapping")
    mp.inputs["Location"].default_value = (-0.2, -0.2, 0)
    mp.inputs["Scale"].default_value = (1.4, 1.4, 1)
    nt.links.new(tc.outputs["UV"], mp.inputs["Vector"])
    nt.links.new(mp.outputs[0], tex.inputs["Vector"])
    nt.links.new(tex.outputs["Color"], nt.nodes["Principled BSDF"].inputs["Base Color"])
    nt.nodes["Principled BSDF"].inputs["Emission Strength"].default_value = 0.0
    return True


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


def box(loc, scale, m, rot=(0, 0, 0)):
    bpy.ops.mesh.primitive_cube_add(size=1, location=loc, rotation=rot)
    o = obj()
    o.scale = scale
    ships.assign(o, m)
    return o


def crystal_mat(strength=1.0):
    return mat("crystal", (0.6, 0.15, 0.55), rough=0.1, emit=(1.0, 0.2, 0.65), strength=strength)


def horizon():
    sand = mat("sand", (0.16, 0.10, 0.06), rough=0.95, bump=("noise", 1.5, 0.5))
    rail = mat("rail", (0.25, 0.25, 0.27), rough=0.35, metal=1.0)
    sleeper = mat("sleeper", (0.07, 0.05, 0.035), rough=0.9)
    wreck = mat("wreck", (0.06, 0.06, 0.07), rough=0.6, metal=0.7)
    crystal = crystal_mat(1.2)
    plane(0, sand)
    for x0 in (-2.4, 0.9, 2.9):                                    # rail lines running up the screen
        for y in [(-H / 2 - 0.5 + k * 0.45) for k in range(30)]:
            box((x0, y, 0.01), (0.9, 0.12, 0.03), sleeper)
        for dx in (-0.32, 0.32):
            box((x0 + dx, 0, 0.04), (0.05, H * 1.4, 0.05), rail)
    for x, y in scatter(6):                                          # wrecked armour, crystal bursting out
        box((x, y, 0.1), (0.7, 1.1, 0.2), wreck, rot=(0, 0, random.uniform(0, 3)))
        for k in range(3):
            shard((x + random.uniform(-0.3, 0.3), y + random.uniform(-0.4, 0.4), 0.2), 0.6, 0.1, crystal,
                  (random.uniform(-0.5, 0.5), random.uniform(-0.5, 0.5), 0))


def delta():
    water = mat("water", (0.01, 0.025, 0.035), rough=0.3, metal=0.2, bump=("noise", 6.0, 0.15))
    mud = mat("mud", (0.06, 0.05, 0.03), rough=0.95)
    reed = mat("reed", (0.05, 0.10, 0.05), rough=0.8)
    stone = mat("stone", (0.18, 0.14, 0.10), rough=0.8)
    plane(0, water)
    for x, y in scatter(9):                                          # mud islands with reed beds
        bpy.ops.mesh.primitive_uv_sphere_add(radius=1, location=(x, y, -0.05))
        o = obj()
        o.scale = (random.uniform(0.4, 0.9), random.uniform(0.3, 0.7), 0.08)
        ships.assign(o, mud)
        for k in range(12):
            a, r = random.uniform(0, math.tau), random.uniform(0, 0.5)
            bpy.ops.mesh.primitive_cone_add(vertices=4, radius1=0.03, radius2=0, depth=0.5,
                                            location=(x + math.cos(a) * r, y + math.sin(a) * r, 0.2),
                                            rotation=(random.uniform(-0.4, 0.4), random.uniform(-0.4, 0.4), 0))
            ships.assign(obj(), reed)
    for x, y in scatter(3):                                          # fallen obelisks half under water
        box((x, y, 0.02), (0.28, 1.6, 0.25), stone, rot=(0, 0, random.uniform(0, 3)))


def mirror():
    glass = mat("glass", (0.035, 0.035, 0.06), rough=0.25, metal=0.6, bump=("cracks", 0.9, 0.25))
    seam = mat("seam", (0.1, 0.12, 0.25), emit=(0.3, 0.4, 0.9), strength=0.25)
    crystal = crystal_mat(0.9)
    plane(0, glass)
    for k in range(9):                                               # long fracture lines across the mirror
        x, y = random.uniform(-W / 2, W / 2), random.uniform(-H / 2, H / 2)
        box((x, y, 0.005), (random.uniform(1.5, 4.0), 0.015, 0.01), seam, rot=(0, 0, random.uniform(0, 3)))
    for x, y in scatter(14):
        shard((x, y, 0.0), random.uniform(0.3, 0.7), 0.08, crystal, (random.uniform(-0.4, 0.4), random.uniform(-0.4, 0.4), 0))


def spires():
    floor = mat("floor", (0.01, 0.03, 0.05), rough=0.6, bump=("noise", 2.0, 0.4))
    ruin = mat("ruin", (0.05, 0.08, 0.10), rough=0.5, metal=0.6)
    gold = mat("gold", (0.45, 0.32, 0.12), rough=0.35, metal=1.0)
    glow = mat("glow", (0.01, 0.03, 0.05), emit=(0.15, 0.5, 0.8), strength=0.08)
    plane(0, floor)
    for x, y in scatter(10, 0.6):                                    # spire tops seen from above, gold-capped
        r = random.uniform(0.25, 0.55)
        bpy.ops.mesh.primitive_cone_add(vertices=4, radius1=r, radius2=0, depth=1.2, location=(x, y, 0.3),
                                        rotation=(0, 0, math.pi / 4))
        ships.assign(obj(), ruin)
        bpy.ops.mesh.primitive_cone_add(vertices=4, radius1=r * 0.4, radius2=0, depth=0.4, location=(x, y, 0.8),
                                        rotation=(0, 0, math.pi / 4))
        ships.assign(obj(), gold)
        bpy.ops.mesh.primitive_cylinder_add(radius=r * 1.5, depth=0.01, location=(x, y, 0.01))   # soft glow pool, no hard ring
        ships.assign(obj(), glow)
    for k in range(5):                                               # sunken causeways
        box((random.uniform(-W / 2, W / 2), random.uniform(-H / 2, H / 2), 0.02), (0.35, random.uniform(2, 4), 0.05), ruin,
            rot=(0, 0, random.choice((0, math.pi / 2))))


def sokar():
    sand = mat("sand", (0.08, 0.055, 0.035), rough=0.9, bump=("noise", 0.8, 1.2))
    bronze = mat("bronze", (0.30, 0.18, 0.08), rough=0.4, metal=0.8)
    plane(0, sand)
    for k in range(7):                                               # dune ridges
        y = -H / 2 + k * H / 6 + random.uniform(-0.4, 0.4)
        bpy.ops.mesh.primitive_uv_sphere_add(radius=1, location=(random.uniform(-1, 1), y, -0.25))
        o = obj()
        o.scale = (W * 0.8, 0.6, 0.35)
        o.rotation_euler = (0, 0, random.uniform(-0.25, 0.25))
        ships.assign(o, sand)
    for x, y in scatter(4, 0.8):                                     # half-buried hawk statues: wings spread
        box((x, y, 0.08), (0.25, 0.5, 0.2), bronze)
        for sgn in (1, -1):
            box((x + sgn * 0.45, y + 0.05, 0.05), (0.7, 0.18, 0.06), bronze, rot=(0, 0, sgn * 0.35))


def firelake():
    lava = mat("lava", (0.03, 0.004, 0.0), emit=(0.5, 0.06, 0.0), strength=0.12)
    crust = mat("crust", (0.03, 0.02, 0.02), rough=0.9, bump=("cracks", 2.5, 0.6))
    ember = mat("ember", (0.6, 0.2, 0.03), emit=(1.0, 0.35, 0.05), strength=0.8)
    plane(-0.05, lava)
    for x, y in scatter(16, 0.0):                                    # floating plates of cooled crust
        bpy.ops.mesh.primitive_cylinder_add(vertices=random.choice((5, 6, 7)), radius=random.uniform(0.4, 1.0),
                                            depth=0.1, location=(x, y, 0.0), rotation=(0, 0, random.uniform(0, 3)))
        ships.assign(obj(), crust)
    for x, y in scatter(30, 0.0):
        bpy.ops.mesh.primitive_uv_sphere_add(radius=0.03, location=(x, y, 0.1))
        ships.assign(obj(), ember)


def coils():
    void = mat("void", (0.01, 0.005, 0.02), rough=1.0)
    scale_m = mat("scales", (0.035, 0.015, 0.06), rough=0.3, metal=0.8)
    star = mat("star", (1, 1, 1), emit=(0.8, 0.8, 1.0), strength=1.5)
    plane(-2.0, void)
    for x, y in scatter(60, 0.0):
        bpy.ops.mesh.primitive_uv_sphere_add(radius=0.015, location=(x, y, -1.9))
        ships.assign(obj(), star)
    for k, (x0, amp) in enumerate(((-1.8, 1.4), (2.2, 1.0))):         # two huge coils sweeping under the play field
        cu = bpy.data.curves.new("coil", "CURVE")
        cu.dimensions = "3D"
        cu.bevel_depth = 0.9 - k * 0.25
        cu.bevel_resolution = 1
        sp = cu.splines.new("BEZIER")
        pts = [(x0 + amp * math.sin(i * 1.3 + k), -H / 2 - 1 + i * (H + 2) / 6, -1.0 - k * 0.4) for i in range(7)]
        sp.bezier_points.add(len(pts) - 1)
        for bp, p in zip(sp.bezier_points, pts):
            bp.co = p
            bp.handle_left_type = bp.handle_right_type = "AUTO"
        o = bpy.data.objects.new("coil", cu)
        bpy.context.collection.objects.link(o)
        o.data.materials.append(scale_m)
        for p in pts:
            shard(p, 0.5, 0.08, crystal_mat(0.8), (0, 0, 0))


def ironsky():
    cloud = mat("cloud", (0.05, 0.05, 0.07), rough=1.0, bump=("noise", 0.7, 0.8))
    iron = mat("iron", (0.07, 0.07, 0.08), rough=0.5, metal=0.9)
    rust = mat("rust", (0.15, 0.05, 0.02), rough=0.7, metal=0.4)
    lamp = mat("lamp", (1.0, 0.4, 0.1), emit=(1.0, 0.4, 0.1), strength=1.5)
    plane(-3.0, cloud)
    for x in (-2.6, 0.0, 2.6):                                       # girder decks running up the screen
        for dx in (-0.35, 0.35):
            box((x + dx, 0, 0.0), (0.08, H * 1.4, 0.12), iron)
        for k in range(16):
            y = -H / 2 - 0.5 + k * 0.85
            box((x, y, 0.0), (0.78, 0.07, 0.08), rust)
            box((x + random.choice((-0.35, 0.35)), y + 0.42, 0.0), (0.06, 0.95, 0.06), iron, rot=(0, 0, 0.6))
            if k % 4 == 0:
                bpy.ops.mesh.primitive_uv_sphere_add(radius=0.05, location=(x, y, 0.08))
                ships.assign(obj(), lamp)


def judgement():
    tile_a = mat("tile_a", (0.04, 0.035, 0.03), rough=0.25, metal=0.3)
    tile_b = mat("tile_b", (0.02, 0.018, 0.02), rough=0.25, metal=0.3)
    gold = mat("gold", (0.45, 0.32, 0.12), rough=0.35, metal=1.0)
    feather = mat("feather", (0.25, 0.18, 0.07), rough=0.35, metal=1.0)   # gold inlay, not glowing
    n = 0.8
    for i in range(int(W / n) + 2):                                  # checkerboard of polished tiles
        for j in range(int(H / n) + 2):
            box((-W / 2 + i * n, -H / 2 + j * n, 0), (n * 0.97, n * 0.97, 0.05), tile_a if (i + j) % 2 else tile_b)
    for x in (-2.8, 2.8):                                            # rows of column tops
        for k in range(5):
            y = -H / 2 + 1.2 + k * 2.4
            bpy.ops.mesh.primitive_cylinder_add(radius=0.5, depth=0.2, location=(x, y, 0.2))
            ships.assign(obj(), gold)
            bpy.ops.mesh.primitive_cylinder_add(radius=0.38, depth=0.22, location=(x, y, 0.22))
            ships.assign(obj(), tile_b)
    for y in (-H / 3, 0, H / 3):                                     # feather of Ma'at inlaid in the aisle
        bpy.ops.mesh.primitive_uv_sphere_add(radius=1, location=(0, y, 0.04))
        o = obj()
        o.scale = (0.18, 0.75, 0.02)
        ships.assign(o, feather)


STAGES = {"horizon": horizon, "delta": delta, "mirror": mirror, "spires": spires, "sokar": sokar,
          "firelake": firelake, "coils": coils, "ironsky": ironsky, "judgement": judgement,
          "starfall": starfall, "heart": heart, "apep": apep_back}


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
    only = sys.argv[3:]
    for sid, build in STAGES.items():
        if only and sid not in only:
            continue
        random.seed(sum(map(ord, sid)))
        ships.reset()
        GROUND.clear()
        build()
        kling = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "art", "kling", f"stage_{sid}.png")
        if os.path.exists(kling) and kling_ground(kling):
            print("using Kling ground texture for", sid)
        render(f"{OUT}/stage_{sid}.png")
        print("rendered", sid)


if __name__ == "__main__":
    main()
