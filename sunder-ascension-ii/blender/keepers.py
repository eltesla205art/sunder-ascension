"""SUNDER: Ascension II — the Act I Keepers (Hours 1–3), modeled procedurally.

    python keepers.py <out_dir> [samples]

For each Keeper writes:
  keeper_<id>.png          top-down boss sprite (longest side 360 px, transparent, front facing DOWN the screen)
  keeper_<id>_portrait.png 3/4 hero portrait for the boss-intro card (320x320, transparent)
  keeper_<id>.glb          the model, for the Three.js Keeper viewer
Concept references: Kling jobs listed in ../artifacts/game-progress.md; canon in ../DESIGN.md §1.
Coordinates: +X right, +Y toward the top of the screen, +Z toward the camera. Bosses face -Y.
"""
import math
import os
import random
import sys

import bpy
import bmesh
from mathutils import Euler, Vector

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
_argv, sys.argv = sys.argv, sys.argv[:1]          # ships.py reads argv at import
import ships                                      # noqa: E402  (shared materials + parts)
sys.argv = _argv

OUT = sys.argv[1] if len(sys.argv) > 1 else "."
SAMPLES = int(sys.argv[2]) if len(sys.argv) > 2 else 64
assign, smooth, flat_poly = ships.assign, ships.smooth, ships.flat_poly


# ------------------------------------------------------------------ shared kit
def materials():
    m = dict(
        obsidian=ships.mat_metal("obsidian", (0.025, 0.022, 0.035), rough=0.22, metal=0.7),
        gold=ships.mat_metal("gold", (0.92, 0.68, 0.26), rough=0.28),
        bronze=ships.mat_metal("bronze", (0.50, 0.30, 0.12), rough=0.4),
        crystal=ships.mat_glow("crystal", (1.0, 0.18, 0.62), 4.0),
        core=ships.mat_glow("core", (1.0, 0.22, 0.68), 6.0),
        eye=ships.mat_glow("eye", (1.0, 0.75, 0.25), 9.0),
        teal=ships.mat_metal("teal", (0.04, 0.16, 0.13), rough=0.45, metal=0.35),
        bone=ships.mat_metal("bone", (0.80, 0.74, 0.62), rough=0.5, metal=0.0),
    )
    # glassy crystal shell: transmissive with a magenta glow
    c = bpy.data.materials.new("glass_crystal")
    c.use_nodes = True
    b = c.node_tree.nodes["Principled BSDF"]
    b.inputs["Base Color"].default_value = (0.85, 0.30, 0.80, 1)
    b.inputs["Roughness"].default_value = 0.05
    b.inputs["Transmission Weight"].default_value = 0.7
    b.inputs["Emission Color"].default_value = (1.0, 0.2, 0.65, 1)
    b.inputs["Emission Strength"].default_value = 2.5
    m["glass"] = c
    return m


def obj():
    return bpy.context.object


def box(loc, scale, mat, rot=(0, 0, 0), bevel=0.04):
    bpy.ops.mesh.primitive_cube_add(size=1, location=loc, rotation=rot)
    o = obj()
    o.scale = scale
    if bevel:
        bv = o.modifiers.new("b", "BEVEL")
        bv.width = bevel
        bv.segments = 2
    assign(o, mat)
    return o


def ball(loc, scale, mat, seg=32):
    bpy.ops.mesh.primitive_uv_sphere_add(segments=seg, ring_count=seg // 2, radius=1, location=loc)
    o = obj()
    o.scale = scale
    smooth(o)
    assign(o, mat)
    return o


def cyl(loc, r, depth, mat, rot=(0, 0, 0), verts=24):
    bpy.ops.mesh.primitive_cylinder_add(vertices=verts, radius=r, depth=depth, location=loc, rotation=rot)
    o = obj()
    assign(o, mat)
    return o


def cone(loc, r1, r2, depth, mat, rot=(0, 0, 0), verts=24):
    bpy.ops.mesh.primitive_cone_add(vertices=verts, radius1=r1, radius2=r2, depth=depth, location=loc, rotation=rot)
    o = obj()
    assign(o, mat)
    return o


def shard(loc, h, r, mat, tilt=(0, 0, 0)):
    """Hexagonal crystal spike rising along +Z from loc."""
    o = cone(loc, r, r * 0.12, h, mat, rot=tilt, verts=6)
    o.location = Vector(loc) + (Euler(tilt).to_matrix() @ Vector((0, 0, h / 2)))
    return o


def toward(direction):
    """Rotation that points a primitive's +Z axis along direction."""
    return Vector(direction).normalized().to_track_quat("Z", "Y").to_euler()


def limb(a, b, r, mat):
    """A capsule-ish segment from point a to point b."""
    a, b = Vector(a), Vector(b)
    o = cyl((a + b) / 2, r, (b - a).length, mat, rot=toward(b - a), verts=16)
    ball(a, (r * 1.15,) * 3, mat, seg=16)
    return o


# ------------------------------------------------------------------ the Keepers
def wepwawet(M):
    """Hour 1 — Wepwawet, Opener of Ways: a jackal-headed war-walker."""
    # armored torso
    t = ball((0, 0.25, 0.2), (1.25, 1.55, 0.55), M["obsidian"])
    box((0, 0.25, 0.62), (0.32, 2.4, 0.12), M["gold"])                       # spine plate
    for y in (-0.55, 0.25, 1.05):                                          # gold rib bands
        box((0, y, 0.45), (2.1, 0.12, 0.16), M["gold"])
    ball((0, 0.55, 0.72), (0.3, 0.3, 0.22), M["core"])                     # weak-point core
    for i, (x, y) in enumerate([(-0.45, 1.2), (0.45, 1.2), (-0.3, 1.65), (0.3, 1.65), (0, 1.35)]):
        shard((x, y, 0.45), 0.9 + 0.25 * (i % 2), 0.16, M["glass"], tilt=(0.35, x * 0.6, 0))
    # neck + jackal head, snout pointing down the screen (-Y)
    limb((0, -1.05, 0.35), (0, -1.65, 0.55), 0.32, M["obsidian"])
    head = ball((0, -1.95, 0.6), (0.7, 0.62, 0.48), M["obsidian"])
    box((0, -1.45, 0.55), (1.5, 0.22, 0.3), M["gold"])                     # gold collar
    cone((0, -3.0, 0.5), 0.44, 0.07, 1.6, M["obsidian"], rot=toward((0, -1, -0.1)))   # long snout
    box((0, -2.35, 1.0), (0.18, 1.2, 0.06), M["gold"])                     # gold muzzle stripe
    for s in (1, -1):
        # tall jackal ears, swept back and out so they read from above
        d = (s * 0.55, 0.75, 0.55)
        e = cone((0, 0, 0), 0.28, 0.02, 1.5, M["obsidian"], rot=toward(d), verts=4)
        e.location = Vector((s * 0.42, -1.75, 0.95)) + Vector(d).normalized() * 0.75
        e.scale = (1, 0.35, 1)
        g = cone((0, 0, 0), 0.15, 0.01, 1.1, M["gold"], rot=toward(d), verts=4)
        g.location = e.location + Vector((0, 0, 0.06))
        g.scale = (1, 0.3, 1)
        ball((s * 0.27, -2.3, 0.88), (0.1, 0.13, 0.06), M["eye"], seg=16)  # eyes
    # shoulders with crystal cannon pods
    for s in (1, -1):
        ball((s * 1.25, -0.55, 0.45), (0.55, 0.6, 0.38), M["gold"])
        cyl((s * 1.55, -1.25, 0.5), 0.2, 1.5, M["obsidian"], rot=(math.pi / 2, 0, 0), verts=6)
        cyl((s * 1.55, -2.0, 0.5), 0.24, 0.12, M["gold"], rot=(math.pi / 2, 0, 0), verts=6)
        cyl((s * 1.55, -2.07, 0.5), 0.14, 0.04, M["core"], rot=(math.pi / 2, 0, 0), verts=6)
    # four splayed legs: hip -> knee -> clawed foot
    for sx, sy in ((1, -1), (-1, -1), (1, 1), (-1, 1)):
        hip = Vector((sx * 0.95, sy * 0.55 + 0.25, 0.1))
        knee = Vector((sx * 2.0, sy * 1.25 + 0.25, 0.45))
        foot = Vector((sx * 2.35, sy * 2.0 + 0.25, -0.2))
        limb(hip, knee, 0.2, M["obsidian"])
        limb(knee, foot, 0.15, M["obsidian"])
        ball(knee, (0.27, 0.27, 0.27), M["gold"], seg=16)
        for k in (-0.25, 0, 0.25):
            cone(foot + Vector((k, sy * 0.25, 0)), 0.07, 0.01, 0.45, M["bone"],
                 rot=toward((k, sy, -0.3)), verts=8)
    # short tail
    limb((0, 1.6, 0.2), (0, 2.5, 0.05), 0.16, M["obsidian"])
    cone((0, 2.85, 0.0), 0.16, 0.0, 0.6, M["gold"], rot=toward((0, 1, -0.1)), verts=8)


def sobek(M):
    """Hour 2 — Sobek Reborn: an armored crocodile dreadnought."""
    body = ball((0, 0.2, 0.15), (1.15, 2.2, 0.45), M["teal"])
    # bronze armor plate rows with magenta seams
    for row in range(5):
        y = -1.3 + row * 0.7
        for s in (1, -1):
            box((s * 0.42, y, 0.5), (0.62, 0.5, 0.12), M["bronze"], rot=(0, s * 0.18, 0))
        box((0, y + 0.35, 0.47), (1.4, 0.06, 0.08), M["crystal"], bevel=0)
    # crystal spine ridge
    for i in range(7):
        shard((0, -1.2 + i * 0.5, 0.55), 0.55 + 0.25 * math.sin(i), 0.14, M["glass"], tilt=(0.4, 0, 0))
    ball((0, 0.5, 0.62), (0.3, 0.3, 0.25), M["core"])
    # long snout and jaws, pointing down the screen
    box((0, -2.75, 0.2), (0.75, 1.9, 0.3), M["teal"], rot=(0, 0, 0), bevel=0.12)
    box((0, -2.8, -0.08), (0.7, 1.8, 0.16), M["bronze"], bevel=0.06)       # lower jaw
    for s in (1, -1):
        for i in range(6):
            cone((s * 0.36, -2.0 - i * 0.28, 0.0), 0.05, 0.0, 0.22, M["bone"], rot=(math.pi, 0, 0), verts=6)
        ball((s * 0.3, -1.9, 0.48), (0.12, 0.14, 0.1), M["eye"], seg=16)  # eyes on the brow
        cyl((s * 0.25, -3.7, 0.18), 0.1, 0.5, M["obsidian"], rot=(math.pi / 2, 0, 0))   # jaw cannons
        cyl((s * 0.25, -3.97, 0.18), 0.07, 0.04, M["core"], rot=(math.pi / 2, 0, 0))
    ball((0, -3.55, 0.06), (0.32, 0.18, 0.1), M["crystal"])               # glowing maw
    # side turret clusters
    for s in (1, -1):
        for y in (-0.7, 0.9):
            cyl((s * 1.15, y, 0.35), 0.32, 0.3, M["bronze"])
            ball((s * 1.15, y, 0.52), (0.26, 0.26, 0.18), M["obsidian"])
            for k in (-0.12, 0.12):
                cyl((s * 1.15 + k, y - 0.45, 0.55), 0.05, 0.7, M["obsidian"], rot=(math.pi / 2, 0, 0), verts=12)
    # stubby clawed legs
    for sx, sy in ((1, -1), (-1, -1), (1, 1), (-1, 1)):
        a = Vector((sx * 0.9, sy * 1.1 + 0.2, 0.0))
        b = Vector((sx * 1.75, sy * 1.45 + 0.2, -0.1))
        limb(a, b, 0.2, M["teal"])
        for k in (-0.15, 0, 0.15):
            cone(b + Vector((sx * 0.15, k, 0)), 0.06, 0.0, 0.35, M["bone"], rot=toward((sx, k, -0.2)), verts=8)
    # segmented tail curving behind it
    prev = Vector((0, 2.25, 0.1))
    for i in range(7):
        r = 0.42 * (1 - i / 8)
        p = Vector((0.35 * math.sin(i * 0.7), 2.45 + i * 0.42, 0.1 - i * 0.02))
        ball(p, (r * 1.2, 0.3, r * 0.8), M["teal"], seg=16)
        box(p + Vector((0, 0, r * 0.7)), (r * 0.6, 0.18, 0.1), M["bronze"])
        prev = p


def umbra(M):
    """Hour 3 — UMBRA, the Shadow Heir: the Sunborn Thunder rebuilt in obsidian crystal."""
    spec = dict(ships.SHIPS["sunborn"])
    spec.update(hull=(0.03, 0.025, 0.05), trim=(0.55, 0.20, 0.75), glow=(1.0, 0.2, 0.7),
                canopy=(0.7, 0.3, 1.0), span=1.75, sweep=0.7)
    before = set(bpy.data.objects)
    ships.build_ship(spec)
    parts = [o for o in bpy.data.objects if o not in before]
    # gather the ship, flip it to face the player and scale it up to boss size
    bpy.ops.object.empty_add(location=(0, 0, 0))
    root = obj()
    for o in parts:
        o.parent = root
    root.rotation_euler = (0, 0, math.pi)
    root.scale = (1.9, 1.9, 1.9)
    # jagged crystal edges along the wings
    for s in (1, -1):
        for i in range(4):
            shard((s * (1.0 + i * 0.6), 0.2 + i * 0.45, 0.05), 0.9 - i * 0.1, 0.16, M["glass"],
                  tilt=(0.3, s * 0.3, 0))
    # orbiting shard drones
    for i in range(4):
        a = math.pi / 4 + i * math.pi / 2
        p = Vector((math.cos(a) * 2.9, math.sin(a) * 2.2, 0.3))
        bpy.ops.mesh.primitive_ico_sphere_add(subdivisions=1, radius=0.28, location=p)
        d = obj()
        d.scale = (0.7, 0.7, 1.6)
        d.rotation_euler = (0.6, 0.3, a)
        assign(d, M["glass"])
        ball(p, (0.1, 0.1, 0.1), M["core"], seg=12)


KEEPERS = {"wepwawet": wepwawet, "sobek": sobek, "umbra": umbra}


# ------------------------------------------------------------------ render setup
def lights():
    sc = bpy.context.scene
    w = bpy.data.worlds.new("w")
    sc.world = w
    w.use_nodes = True
    w.node_tree.nodes["Background"].inputs["Color"].default_value = (0.05, 0.05, 0.12, 1)

    def light(name, loc, energy, color, size):
        ld = bpy.data.lights.new(name, "AREA")
        ld.energy, ld.color, ld.size = energy, color, size
        o = bpy.data.objects.new(name, ld)
        sc.collection.objects.link(o)
        o.location = loc
        o.rotation_euler = (Vector((0, 0, 0)) - Vector(loc)).to_track_quat("-Z", "Y").to_euler()

    light("key", (-6, 5, 8), 1800, (1.0, 0.92, 0.78), 5)      # warm key, upper left
    light("rim", (7, -6, 3), 2200, (0.45, 0.55, 1.0), 5)      # cool rim from below right
    light("magenta", (0, -8, 1), 600, (1.0, 0.3, 0.8), 6)     # crystal bounce from the front
    light("fill", (0, 0, 12), 160, (1, 1, 1), 10)


def render(path, w, h, camera):
    sc = bpy.context.scene
    sc.render.engine = "CYCLES"
    sc.cycles.device = "CPU"
    sc.cycles.samples = SAMPLES
    sc.cycles.use_denoising = True
    sc.render.resolution_x, sc.render.resolution_y = w, h
    sc.render.film_transparent = True
    sc.render.image_settings.file_format = "PNG"
    sc.render.image_settings.color_mode = "RGBA"
    sc.view_settings.view_transform = "AgX"
    sc.view_settings.look = "AgX - Punchy"
    sc.camera = camera
    sc.render.filepath = path
    bpy.ops.render.render(write_still=True)


def camera(name, ortho=None, loc=(0, 0, 20), target=(0, 0, 0), lens=50):
    c = bpy.data.objects.new(name, bpy.data.cameras.new(name))
    bpy.context.scene.collection.objects.link(c)
    c.location = loc
    c.rotation_euler = (Vector(target) - Vector(loc)).to_track_quat("-Z", "Y").to_euler()
    if ortho:
        c.data.type = "ORTHO"
        c.data.ortho_scale = ortho
    else:
        c.data.lens = lens
    return c


def bounds():
    lo, hi = Vector((1e9,) * 3), Vector((-1e9,) * 3)
    dg = bpy.context.evaluated_depsgraph_get()
    for o in bpy.context.scene.objects:
        if o.type != "MESH":
            continue
        for corner in o.evaluated_get(dg).bound_box:
            p = o.matrix_world @ Vector(corner)
            lo = Vector(map(min, lo, p))
            hi = Vector(map(max, hi, p))
    return lo, hi


def merge_for_export():
    """Join every part into one mesh (one glTF primitive per material) so the Three.js viewer
    draws each Keeper in ~10 calls instead of one per part (threejs-aaa-graphics-builder budget)."""
    meshes = [o for o in bpy.context.scene.objects if o.type == "MESH"]
    bpy.ops.object.select_all(action="DESELECT")
    for o in meshes:
        o.select_set(True)
    bpy.context.view_layer.objects.active = meshes[0]
    bpy.ops.object.convert(target="MESH")      # bake bevels and parent transforms
    bpy.ops.object.join()


def main():
    random.seed(7)
    os.makedirs(OUT, exist_ok=True)
    for kid, build in KEEPERS.items():
        ships.reset()
        M = materials()
        build(M)
        bpy.context.view_layer.update()
        lights()
        lo, hi = bounds()
        size = hi - lo
        # top-down sprite: longest side 360 px, shaped to the silhouette (game draws it at half size)
        span = max(size.x, size.y) * 1.06
        k = 360 / span
        cx, cy = (lo.x + hi.x) / 2, (lo.y + hi.y) / 2
        top = camera("top", ortho=span, loc=(cx, cy, 30), target=(cx, cy, 0))
        render(f"{OUT}/keeper_{kid}.png", round(size.x * 1.06 * k), round(size.y * 1.06 * k), top)
        # 3/4 portrait, looking at the Keeper's face from below-front
        d = max(size.x, size.y) * 0.85
        port = camera("portrait", loc=(cx + d * 0.55, cy - d * 1.25, d * 0.9), target=(cx, cy - size.y * 0.12, 0), lens=55)
        render(f"{OUT}/keeper_{kid}_portrait.png", 320, 320, port)
        merge_for_export()
        bpy.ops.export_scene.gltf(filepath=f"{OUT}/keeper_{kid}.glb", export_format="GLB",
                                  export_apply=True, export_cameras=False, export_lights=False)
        print("built", kid, "size", tuple(round(v, 2) for v in size))


if __name__ == "__main__":
    main()
