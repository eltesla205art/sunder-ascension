"""SUNDER: Ascension II — the Keepers of Act I (Hours 1–3) and Act II (Hours 4–6), modeled procedurally.

    python keepers.py <out_dir> [samples] [act]      act = 1 or 2 (default: every Keeper)

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
ONLY_ACT = sys.argv[3] if len(sys.argv) > 3 else None   # "1" or "2" renders one act; default: all
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
    # Act II: deep water glass, fire, desert bronze
    w = bpy.data.materials.new("deep_water")
    w.use_nodes = True
    b = w.node_tree.nodes["Principled BSDF"]
    b.inputs["Base Color"].default_value = (0.01, 0.10, 0.20, 1)
    b.inputs["Metallic"].default_value = 0.3
    b.inputs["Roughness"].default_value = 0.08
    b.inputs["Coat Weight"].default_value = 1.0
    b.inputs["Emission Color"].default_value = (0.10, 0.45, 0.85, 1)
    b.inputs["Emission Strength"].default_value = 0.35
    m["water"] = w
    m["abyss"] = ships.mat_metal("abyss", (0.02, 0.06, 0.10), rough=0.25, metal=0.7)
    m["atlantean"] = ships.mat_glow("atlantean", (0.35, 0.85, 1.0), 5.0)
    # AgX pushes bright emission toward white, so fire uses deep, saturated colours at low strength
    m["fire"] = ships.mat_glow("fire", (0.85, 0.12, 0.01), 1.1)
    m["ember"] = ships.mat_glow("ember", (1.0, 0.32, 0.03), 1.6)
    m["sand"] = ships.mat_metal("sand", (0.36, 0.22, 0.10), rough=0.4, metal=0.65)
    m["feather_dark"] = ships.mat_metal("feather_dark", (0.06, 0.045, 0.035), rough=0.5, metal=0.3)
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


def nun(M):
    """Hour 4 — Nun, the Primeval Deep: a ring-shaped abyssal guardian carrying Atlantis's sunken spires."""
    # central dome of deep water around a primordial eye
    ball((0, 0, 0.2), (1.35, 1.35, 0.7), M["water"])
    ball((0, 0, 0.35), (0.85, 0.85, 0.55), M["abyss"])
    ball((0, -0.25, 0.85), (0.38, 0.32, 0.18), M["atlantean"])                 # the eye, looking down-screen
    ball((0, -0.32, 0.98), (0.14, 0.1, 0.06), M["core"], seg=16)              # corrupted pupil
    # two concentric gold rings, the outer one segmented like a lock
    bpy.ops.mesh.primitive_torus_add(major_radius=1.75, minor_radius=0.12, location=(0, 0, 0.25))
    assign(obj(), M["gold"])
    bpy.ops.mesh.primitive_torus_add(major_radius=2.75, minor_radius=0.3, major_segments=96, location=(0, 0, 0.15))
    ring = obj()
    ring.scale = (1, 1, 0.55)
    assign(ring, M["abyss"])
    for k in range(6):                                                     # spokes tying the ring to the dome
        a = k * math.tau / 6 + 0.26
        limb((math.cos(a) * 1.7, math.sin(a) * 1.7, 0.25), (math.cos(a) * 2.6, math.sin(a) * 2.6, 0.2), 0.1, M["gold"])
    for i in range(12):
        a = i * math.tau / 12
        box((math.cos(a) * 2.75, math.sin(a) * 2.75, 0.33), (0.6, 0.1, 0.05), M["atlantean"],
            rot=(0, 0, a + math.pi / 2), bevel=0)
    # eight sunken Atlantean spires standing on the ring, leaning outward
    for i in range(8):
        a = math.pi / 8 + i * math.tau / 8
        base = Vector((math.cos(a) * 2.75, math.sin(a) * 2.75, 0.3))
        lean = (-math.sin(a) * 0.35, math.cos(a) * 0.35, 0)  # tilt away from the centre
        h = 1.6 + 0.5 * (i % 2)
        spire = cone(base, 0.28, 0.06, h, M["gold"], rot=(lean[1] * -1, lean[0], 0), verts=4)
        spire.location = base + Euler((lean[1] * -1, lean[0], 0)).to_matrix() @ Vector((0, 0, h / 2))
        ball(base + Vector((0, 0, 0.15)), (0.22, 0.22, 0.12), M["water"], seg=16)
    # four tentacle arms reaching toward the player, crystal-tipped
    for s in (1, -1):
        for k, spread in ((0, 0.45), (1, 1.05)):
            pts = [Vector((s * (0.6 + 0.3 * k), -1.1, 0.1)),
                   Vector((s * (1.3 + spread), -2.4, 0.0)),
                   Vector((s * (1.0 + spread * 1.4), -3.6, -0.05))]
            r = 0.26
            for a_, b_ in zip(pts, pts[1:]):
                limb(a_, b_, r, M["abyss"])
                r *= 0.75
            shard(pts[-1], 0.9, 0.16, M["glass"], tilt=(-0.6, 0, 0))


def sokar(M):
    """Hour 5 — Sokar, Hawk of the Hidden Sand: a falcon war-god of bronze and black feathers."""
    # body and chest plate
    ball((0, 0.2, 0.3), (0.8, 1.45, 0.55), M["sand"])
    box((0, -0.35, 0.68), (0.9, 0.9, 0.12), M["gold"], bevel=0.08)
    ball((0, -0.35, 0.8), (0.24, 0.24, 0.14), M["core"], seg=16)              # heart-core
    # falcon head with hooked beak pointing down the screen
    ball((0, -1.45, 0.65), (0.55, 0.55, 0.48), M["feather_dark"])
    cone((0, -2.15, 0.5), 0.34, 0.02, 1.0, M["gold"], rot=toward((0, -1, -0.45)), verts=12)
    box((0, -1.15, 1.0), (0.5, 0.35, 0.12), M["gold"], rot=(0.3, 0, 0))   # crest
    for s in (1, -1):
        box((s * 0.3, -1.6, 0.95), (0.18, 0.4, 0.05), M["gold"], rot=(0, 0, s * 0.3))  # gold eye markings
        ball((s * 0.26, -1.72, 0.92), (0.09, 0.09, 0.05), M["eye"], seg=16)
    # wings: layered feather blades sweeping out and slightly forward
    for s in (1, -1):
        for i in range(11):
            t = i / 10
            root = Vector((s * (0.6 + t * 1.1), 0.2 - t * 0.3, 0.25 + 0.02 * i))
            tip = root + Vector((s * (1.6 + t * 1.6), 1.0 - t * 2.0, 0.0))
            mat = M["feather_dark"] if (i % 2 or t > 0.6) else M["sand"]
            pts = [(root.x, root.y + 0.2), (tip.x, tip.y + 0.06), (tip.x + s * 0.12, tip.y - 0.12), (root.x, root.y - 0.18)]
            if s < 0:
                pts.reverse()
            flat_poly("feather", pts, 0.06, mat, z=root.z)
        # crystal-corrupted leading edge
        for i in range(4):
            shard((s * (1.6 + i * 0.75), 0.75 - i * 0.2, 0.4), 0.7, 0.13, M["glass"], tilt=(0.5, s * 0.4, 0))
    # tail fan at the top of the screen
    for i in range(7):
        a = math.pi / 2 + (i - 3) * 0.16
        root = Vector((0, 1.3, 0.25))
        tip = root + Vector((math.cos(a) * 1.9, math.sin(a) * 1.9, 0))
        perp = Vector((-math.sin(a), math.cos(a), 0)) * 0.16
        pts = [(root.x - perp.x, root.y - perp.y), (tip.x - perp.x, tip.y - perp.y),
               (tip.x + perp.x, tip.y + perp.y), (root.x + perp.x, root.y + perp.y)]
        flat_poly("tail", pts, 0.05, M["feather_dark"] if i % 2 else M["sand"], z=0.2 + i * 0.01)
    # talons gripping a gold sun-disc beneath it
    bpy.ops.mesh.primitive_torus_add(major_radius=0.55, minor_radius=0.09, location=(0, 0.55, -0.2))
    assign(obj(), M["gold"])
    for s in (1, -1):
        for k in (-0.15, 0.15):
            cone((s * 0.45 + k, 0.2, -0.15), 0.06, 0.0, 0.4, M["bone"], rot=toward((s * 0.4, -1, -0.5)), verts=8)


def seraphs(M):
    """Hour 6 — The Fire Lake Seraphs: four winged fire-cobras circling a burning brazier."""
    # the burning lake: a gold brazier ring with a disc of fire
    bpy.ops.mesh.primitive_cylinder_add(vertices=48, radius=1.15, depth=0.35, location=(0, 0, -0.1))
    assign(obj(), M["obsidian"])
    bpy.ops.mesh.primitive_torus_add(major_radius=1.15, minor_radius=0.1, location=(0, 0, 0.08))
    assign(obj(), M["gold"])
    bpy.ops.mesh.primitive_cylinder_add(vertices=48, radius=1.0, depth=0.05, location=(0, 0, 0.1))
    assign(obj(), M["fire"])
    for i in range(10):
        a = i * math.tau / 10 + 0.3
        r = 0.35 + 0.45 * ((i * 7) % 3) / 2
        cone((math.cos(a) * r, math.sin(a) * r, 0.1), 0.18, 0.0, 0.6 + 0.25 * (i % 3), M["ember"], verts=8).location.z += 0.35
    # four seraphs at the diagonals, each rearing toward the player's side of the screen
    for i in range(4):
        a = math.pi / 4 + i * math.pi / 2
        c = Vector((math.cos(a) * 2.35, math.sin(a) * 2.0, 0.2))
        out = Vector((math.cos(a), math.sin(a), 0))
        # coiled body
        for k in range(6):
            t = k / 5
            p = c + Vector((math.cos(a + 2.4 * t) * 0.45, math.sin(a + 2.4 * t) * 0.45, -0.05 + 0.08 * k))
            ball(p, (0.26 - 0.03 * k,) * 2 + (0.2,), M["obsidian"], seg=16)
        # flared cobra hood with a gold and fire pattern, facing down-screen
        hood = c + Vector((0, -0.35, 0.55))
        h = ball(hood, (0.68, 0.55, 0.12), M["obsidian"])                         # flared hood, flat to the camera
        h.rotation_euler = (-0.35, 0, 0)
        g = ball(hood + Vector((0, -0.02, 0.1)), (0.5, 0.4, 0.06), M["gold"])
        g.rotation_euler = (-0.35, 0, 0)
        f = ball(hood + Vector((0, -0.05, 0.16)), (0.2, 0.26, 0.04), M["fire"], seg=16)
        f.rotation_euler = (-0.35, 0, 0)
        ball(hood + Vector((0, -0.75, 0.2)), (0.2, 0.3, 0.14), M["obsidian"], seg=16)   # head, striking down-screen
        for s in (1, -1):
            ball(hood + Vector((s * 0.1, -0.92, 0.3)), (0.04, 0.05, 0.03), M["eye"], seg=12)
        # flame wings spreading outward from the brazier
        for s in (1, -1):
            side = Vector((-out.y, out.x, 0)) * s
            for f in range(3):
                d = (out * 0.9 + side * (0.6 + f * 0.35)).normalized()
                fl = cone((0, 0, 0), 0.16, 0.0, 1.3 - f * 0.25, M["fire"] if f else M["ember"], rot=toward(d + Vector((0, 0, 0.25))), verts=6)
                fl.location = c + d * (0.75 - f * 0.1) + Vector((0, 0, 0.45))
                fl.scale = (1, 0.35, 1)


KEEPERS = {"wepwawet": wepwawet, "sobek": sobek, "umbra": umbra,
           "nun": nun, "sokar": sokar, "seraphs": seraphs}
ACTS = {"1": ("wepwawet", "sobek", "umbra"), "2": ("nun", "sokar", "seraphs")}


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
        if ONLY_ACT and kid not in ACTS[ONLY_ACT]:
            continue
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
