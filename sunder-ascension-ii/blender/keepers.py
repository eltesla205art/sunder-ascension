"""SUNDER: Ascension II — the Keepers of all four acts (Hours 1–12), modeled procedurally.

    python keepers.py <out_dir> [samples] [act|id]          act = 1..4 or one Keeper id (default: every Keeper)
    python keepers.py <out_dir> [samples] [act|id] --anim   animation frames instead (see below)

For each Keeper writes:
  keeper_<id>.png          top-down boss sprite (longest side 360 px, transparent, front facing DOWN the screen)
  keeper_<id>_portrait.png 3/4 hero portrait for the boss-intro card (320x320, transparent)
  keeper_<id>.glb          the model, for the Three.js Keeper viewer
With --anim, writes anim/keeper_<id>_fNN.png instead: FRAMES top-down frames of one seamless loop, drawn
at the static sprite's pixels-per-unit on a larger canvas centred on the same point (pack_anim.py crops and
packs them into the game's sprite sheets). The static outputs are not touched in this mode.
Concept references: Kling jobs listed in ../artifacts/game-progress.md; canon in ../DESIGN.md §1.
Coordinates: +X right, +Y toward the top of the screen, +Z toward the camera. Bosses face -Y.
"""
import math
import os
import random
import sys

import bpy
import bmesh
from mathutils import Euler, Matrix, Vector

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
_argv, sys.argv = sys.argv, sys.argv[:1]          # ships.py reads argv at import
import ships                                      # noqa: E402  (shared materials + parts)
sys.argv = _argv

ANIM = "--anim" in sys.argv
_args = [a for a in sys.argv if a != "--anim"]
OUT = _args[1] if len(_args) > 1 else "."
SAMPLES = int(_args[2]) if len(_args) > 2 else 64
ONLY_ACT = _args[3] if len(_args) > 3 else None   # "1".."4" renders one act, or a Keeper id; default: all
FRAMES = 8                                        # animation loop length (the game plays it at 8 fps)
WAVE = None                                       # animation phase in radians; None = the static model
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
    # Act III: iron, rust, beast hide, the feather of Ma'at, the weighed heart
    m["iron"] = ships.mat_metal("iron", (0.10, 0.10, 0.11), rough=0.55, metal=0.9)
    m["rust"] = ships.mat_metal("rust", (0.30, 0.10, 0.04), rough=0.7, metal=0.4)
    m["hide"] = ships.mat_metal("hide", (0.10, 0.12, 0.14), rough=0.6, metal=0.15)
    m["mane"] = ships.mat_metal("mane", (0.70, 0.42, 0.12), rough=0.45, metal=0.6)
    m["feather"] = ships.mat_glow("feather", (0.92, 0.95, 1.0), 1.2)
    m["heart"] = ships.mat_glow("heart", (0.85, 0.05, 0.12), 2.0)
    # Act IV: void-crystal scales, starfire, the Heart of Atlantis
    m["void"] = ships.mat_metal("void", (0.035, 0.015, 0.07), rough=0.22, metal=0.85)
    m["violet"] = ships.mat_glow("violet", (0.45, 0.12, 1.0), 2.2)
    m["starfire"] = ships.mat_glow("starfire", (0.85, 0.80, 1.0), 4.0)
    m["atlantis_heart"] = ships.mat_glow("atlantis_heart", (1.0, 0.42, 0.04), 1.8)
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


# ------------------------------------------------------------------ parts, for animation
_MARKS = []


def mark(name):
    """Start a named part: every object created from here to the next mark belongs to it.
    Marks only label objects, so the static model is identical with or without them."""
    _MARKS.append((name, set(bpy.data.objects)))


def parts():
    """name -> objects created under that mark (objects made before the first mark are the fixed body)."""
    out, snaps = {}, _MARKS + [("", set(bpy.data.objects))]
    for (name, before), (_, after) in zip(snaps, snaps[1:]):
        out.setdefault(name, []).extend(o for o in after - before)
    return out


def move(objs, pivot=(0, 0, 0), rot=(0, 0, 0), shift=(0, 0, 0), scale=None):
    """Rigidly turn (XYZ Euler, radians) and/or scale a part about pivot, then shift it."""
    p = Vector(pivot)
    m = Euler(rot).to_matrix().to_4x4()
    if scale is not None:
        sc = (scale,) * 3 if isinstance(scale, (int, float)) else scale
        m = m @ Matrix.Diagonal((*sc, 1))
    m = Matrix.Translation(p + Vector(shift)) @ m @ Matrix.Translation(-p)
    for o in objs:
        if o.parent in objs:          # its parent carries it
            continue
        o.matrix_world = m @ o.matrix_world


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
    mark("head")
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
    mark("shoulders")
    for s in (1, -1):
        ball((s * 1.25, -0.55, 0.45), (0.55, 0.6, 0.38), M["gold"])
        cyl((s * 1.55, -1.25, 0.5), 0.2, 1.5, M["obsidian"], rot=(math.pi / 2, 0, 0), verts=6)
        cyl((s * 1.55, -2.0, 0.5), 0.24, 0.12, M["gold"], rot=(math.pi / 2, 0, 0), verts=6)
        cyl((s * 1.55, -2.07, 0.5), 0.14, 0.04, M["core"], rot=(math.pi / 2, 0, 0), verts=6)
    # four splayed legs: hip -> knee -> clawed foot
    for sx, sy in ((1, -1), (-1, -1), (1, 1), (-1, 1)):
        mark(f"leg{sx}{sy}")
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
    mark("tail")
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
            mark(f"turret{s}{y}")
            cyl((s * 1.15, y, 0.35), 0.32, 0.3, M["bronze"])
            ball((s * 1.15, y, 0.52), (0.26, 0.26, 0.18), M["obsidian"])
            for k in (-0.12, 0.12):
                cyl((s * 1.15 + k, y - 0.45, 0.55), 0.05, 0.7, M["obsidian"], rot=(math.pi / 2, 0, 0), verts=12)
    # stubby clawed legs
    for sx, sy in ((1, -1), (-1, -1), (1, 1), (-1, 1)):
        mark(f"leg{sx}{sy}")
        a = Vector((sx * 0.9, sy * 1.1 + 0.2, 0.0))
        b = Vector((sx * 1.75, sy * 1.45 + 0.2, -0.1))
        limb(a, b, 0.2, M["teal"])
        for k in (-0.15, 0, 0.15):
            cone(b + Vector((sx * 0.15, k, 0)), 0.06, 0.0, 0.35, M["bone"], rot=toward((sx, k, -0.2)), verts=8)
    # segmented tail curving behind it
    prev = Vector((0, 2.25, 0.1))
    for i in range(7):
        mark(f"tail{i}")
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
        mark(f"drone{i}")
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
    mark("ring")
    bpy.ops.mesh.primitive_torus_add(major_radius=2.75, minor_radius=0.3, major_segments=96, location=(0, 0, 0.15))
    ring = obj()
    ring.scale = (1, 1, 0.55)
    assign(ring, M["abyss"])
    mark("spokes")
    for k in range(6):                                                     # spokes tying the ring to the dome
        a = k * math.tau / 6 + 0.26
        limb((math.cos(a) * 1.7, math.sin(a) * 1.7, 0.25), (math.cos(a) * 2.6, math.sin(a) * 2.6, 0.2), 0.1, M["gold"])
    mark("bars")
    for i in range(12):
        a = i * math.tau / 12
        box((math.cos(a) * 2.75, math.sin(a) * 2.75, 0.33), (0.6, 0.1, 0.05), M["atlantean"],
            rot=(0, 0, a + math.pi / 2), bevel=0)
    # eight sunken Atlantean spires standing on the ring, leaning outward
    mark("spires")
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
            mark(f"arm{s}{k}")
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
        mark(f"wing{s}")
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
    mark("tail")
    for i in range(7):
        a = math.pi / 2 + (i - 3) * 0.16
        root = Vector((0, 1.3, 0.25))
        tip = root + Vector((math.cos(a) * 1.9, math.sin(a) * 1.9, 0))
        perp = Vector((-math.sin(a), math.cos(a), 0)) * 0.16
        pts = [(root.x - perp.x, root.y - perp.y), (tip.x - perp.x, tip.y - perp.y),
               (tip.x + perp.x, tip.y + perp.y), (root.x + perp.x, root.y + perp.y)]
        flat_poly("tail", pts, 0.05, M["feather_dark"] if i % 2 else M["sand"], z=0.2 + i * 0.01)
    # talons gripping a gold sun-disc beneath it
    mark("talons")
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
        mark(f"ember{i}")
        cone((math.cos(a) * r, math.sin(a) * r, 0.1), 0.18, 0.0, 0.6 + 0.25 * (i % 3), M["ember"], verts=8).location.z += 0.35
    # four seraphs at the diagonals, each rearing toward the player's side of the screen
    for i in range(4):
        mark(f"seraph{i}")
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
        mark(f"flame{i}")
        for s in (1, -1):
            side = Vector((-out.y, out.x, 0)) * s
            for f in range(3):
                d = (out * 0.9 + side * (0.6 + f * 0.35)).normalized()
                fl = cone((0, 0, 0), 0.16, 0.0, 1.3 - f * 0.25, M["fire"] if f else M["ember"], rot=toward(d + Vector((0, 0, 0.25))), verts=6)
                fl.location = c + d * (0.75 - f * 0.1) + Vector((0, 0, 0.45))
                fl.scale = (1, 0.35, 1)


def as_mesh(o):
    """Curves don't join into the exported mesh; bake one to geometry."""
    bpy.ops.object.select_all(action="DESELECT")
    o.select_set(True)
    bpy.context.view_layer.objects.active = o
    bpy.ops.object.convert(target="MESH")
    return bpy.context.view_layer.objects.active


def umbra_coiled(M):
    """Hour 7 — UMBRA returns with Apep's coil wound around it, faster and colder."""
    umbra(M)
    mark("coil")
    cu = bpy.data.curves.new("coil", "CURVE")
    cu.dimensions = "3D"
    cu.bevel_depth = 0.32
    cu.bevel_resolution = 1                                   # faceted crystal cross-section
    cu.resolution_u = 20
    sp = cu.splines.new("BEZIER")
    pts = []
    for i in range(10):                                       # a helix loosely wrapped round the ship
        a = i * 0.95
        r = 3.1 - i * 0.12
        pts.append((math.cos(a) * r, math.sin(a) * r * 0.78, 0.15 + 0.85 * math.sin(i * 1.9), 0.55 + 0.5 * math.sin(i / 9 * math.pi)))
    sp.bezier_points.add(len(pts) - 1)
    for bp, (x, y, z, r) in zip(sp.bezier_points, pts):
        bp.co = (x, y, z)
        bp.handle_left_type = bp.handle_right_type = "AUTO"
        bp.radius = r
    ob = bpy.data.objects.new("coil", cu)
    bpy.context.collection.objects.link(ob)
    ob.data.materials.append(M["serpent"] if "serpent" in M else M["obsidian"])
    as_mesh(ob)
    # magenta crystal spines along the coil, and a serpent head biting toward the player
    for i in range(1, 9):
        x, y, z, r = pts[i]
        shard((x, y, z + 0.3 * r), 0.55 * r + 0.2, 0.12, M["glass"], tilt=(0.3, 0.2, 0))
    hx, hy, hz, _ = pts[-1]
    mark("coilhead")
    head = Vector((hx, hy, hz))
    strike = (Vector((0, -3.4, 0)) - head).normalized()
    for jaw in (1, -1):
        j = cone(head + strike * 0.9 + Vector((0, 0, jaw * 0.22)), 0.62, 0.05, 1.9, M["obsidian"], rot=toward(strike), verts=4)
        j.scale = (1, 0.5, 1)
    ball(head + strike * 1.0, (0.3, 0.3, 0.2), M["crystal"], seg=16)              # glowing maw
    side = strike.cross(Vector((0, 0, 1))).normalized()
    for e in (1, -1):
        ball(head + side * e * 0.28 + Vector((0, 0, 0.42)), (0.08, 0.08, 0.06), M["eye"], seg=12)


def hittite(M):
    """Hour 8 — the Hittite Engine: an iron sky-fortress rebuilt from a broken Bow, borne on chariot-wheel rotors."""
    # armoured hull: a long hexagonal deck
    hull = [(0, -2.4), (1.5, -1.6), (1.7, 1.3), (0.9, 2.3), (-0.9, 2.3), (-1.7, 1.3), (-1.5, -1.6)]
    flat_poly("deck", hull, 0.55, M["iron"], z=-0.2)
    flat_poly("deck_trim", [(x * 0.82, y * 0.82) for x, y in hull], 0.12, M["rust"], z=0.36)
    # battlements along the deck edge and four corner towers
    for (x0, y0), (x1, y1) in zip(hull, hull[1:] + hull[:1]):
        n = max(2, int(math.hypot(x1 - x0, y1 - y0) / 0.42))
        for k in range(n):
            t = (k + 0.5) / n
            box((x0 + (x1 - x0) * t, y0 + (y1 - y0) * t, 0.48), (0.2, 0.2, 0.22), M["iron"], bevel=0.02)
    for x, y in ((1.5, -1.5), (-1.5, -1.5), (1.6, 1.25), (-1.6, 1.25)):
        cyl((x, y, 0.6), 0.28, 0.9, M["iron"], verts=8)
        cone((x, y, 1.2), 0.32, 0.0, 0.4, M["rust"], verts=8)
    # rivet rows
    for y in (-1.2, -0.2, 0.8, 1.7):
        for x in (-1.2, -0.6, 0.6, 1.2):
            ball((x, y, 0.5), (0.06, 0.06, 0.04), M["bronze"], seg=8)
    # central citadel with a crystal reactor
    box((0, 0.5, 0.75), (1.3, 1.6, 0.6), M["iron"], bevel=0.08)
    box((0, 0.5, 1.12), (1.0, 1.25, 0.14), M["bronze"], bevel=0.04)
    for x in (-0.3, 0.3):
        box((x, 0.5, 1.25), (0.18, 0.9, 0.08), M["crystal"], bevel=0)    # reactor vents
    ball((0, 0.5, 1.3), (0.28, 0.28, 0.2), M["core"], seg=16)
    # wall-barrage battery along the bow: a row of cannons aimed down the screen
    mark("guns")
    for i in range(7):
        x = -1.05 + i * 0.35
        cyl((x, -2.0 + abs(x) * 0.5, 0.42), 0.09, 0.9, M["iron"], rot=(math.pi / 2, 0, 0), verts=12)
        cyl((x, -2.45 + abs(x) * 0.5, 0.42), 0.06, 0.04, M["core"], rot=(math.pi / 2, 0, 0), verts=12)
    mark("outriggers")
    # four six-spoked Hittite chariot wheels, laid flat as rotors on outriggers
    for sx, sy in ((1, -1), (-1, -1), (1, 1), (-1, 1)):
        c = Vector((sx * 2.6, sy * 1.35 + 0.25, 0.2))
        mark(f"strut{sx}{sy}")
        limb((sx * 1.4, sy * 1.0 + 0.25, 0.2), c, 0.14, M["iron"])
        mark(f"rotor{sx}{sy}")
        bpy.ops.mesh.primitive_torus_add(major_radius=0.95, minor_radius=0.1, location=c)
        assign(obj(), M["bronze"])
        for k in range(6):
            a = k * math.pi / 3
            box(c + Vector((math.cos(a) * 0.47, math.sin(a) * 0.47, 0)), (0.94, 0.08, 0.06), M["iron"],
                rot=(0, 0, a), bevel=0)
        cyl(c, 0.22, 0.3, M["rust"], verts=16)
        ball(c + Vector((0, 0, 0.18)), (0.12, 0.12, 0.08), M["crystal"], seg=12)
    # broken Bow trophies: crystal shards punched through the iron
    mark("trophies")
    for x, y in ((-0.9, 1.6), (1.0, -0.9), (-1.1, -0.6), (0.7, 1.9)):
        shard((x, y, 0.3), 0.9, 0.16, M["glass"], tilt=(0.3 * x, -0.3 * y, 0))


def ammit(M):
    """Hour 9 — Ammit, Devourer of Hearts: crocodile head, lion forequarters, hippo hindquarters, beneath the scales."""
    # hippo hindquarters and lion chest
    ball((0, 1.0, 0.2), (0.95, 0.9, 0.45), M["hide"])
    ball((0, -0.3, 0.35), (1.0, 0.95, 0.6), M["mane"])
    # lion mane: a ring of gold blades around the neck
    mark("mane")
    for i in range(16):
        a = math.pi + i * math.tau / 16
        d = Vector((math.cos(a), math.sin(a) * 0.8, 0))
        m = cone((0, 0, 0), 0.3, 0.0, 1.25, M["mane"] if i % 2 else M["gold"], rot=toward(d + Vector((0, 0, 0.3))), verts=6)
        m.location = Vector((0, -0.9, 0.55)) + d * 0.95
        m.scale = (1, 0.4, 1)
    # crocodile head and long jaws, pointing down the screen
    mark("head")
    ball((0, -1.25, 0.6), (0.55, 0.6, 0.42), M["hide"])
    for z, mat, k in ((0.62, M["hide"], 1.0), (0.38, M["bronze"], 0.9)):     # tapered upper and lower jaws
        j = cone((0, -2.2, z), 0.42 * k, 0.08, 1.7, mat, rot=toward((0, -1, 0)), verts=4)
        j.scale = (1.0, 0.42, 1.0)
        j.rotation_euler.rotate_axis("Y", math.pi / 4)
    for s in (1, -1):
        for i in range(5):
            cone((s * 0.26, -1.65 - i * 0.24, 0.42), 0.04, 0.0, 0.18, M["bone"], rot=(math.pi, 0, 0), verts=6)
        ball((s * 0.24, -1.4, 0.95), (0.06, 0.08, 0.04), M["eye"], seg=16)
    box((0, -1.0, 0.98), (0.7, 0.35, 0.08), M["gold"], rot=(0.25, 0, 0))   # headdress band
    # lion forelegs with claws, hippo hind legs
    mark("legs")
    for s in (1, -1):
        a, b = Vector((s * 0.85, -0.5, 0.1)), Vector((s * 1.45, -1.35, -0.1))
        limb(a, b, 0.22, M["mane"])
        for k in (-0.14, 0, 0.14):
            cone(b + Vector((k, -0.15, 0)), 0.05, 0.0, 0.35, M["bone"], rot=toward((k, -1, -0.3)), verts=8)
        limb((s * 0.95, 1.35, 0.0), (s * 1.25, 1.65, -0.15), 0.3, M["hide"])        # stubby hippo legs
        ball((s * 1.25, 1.65, -0.2), (0.34, 0.34, 0.2), M["hide"], seg=16)
    # stubby hippo tail
    mark("tail")
    limb((0, 2.05, 0.2), (0, 2.5, 0.05), 0.12, M["hide"])
    # the scales of judgement hovering over its back: beam, pillar, heart and feather pans
    mark("pillar")
    cyl((0, 0.6, 1.6), 0.06, 1.6, M["gold"], verts=12)
    mark("beam")
    box((0, 0.6, 2.4), (3.4, 0.12, 0.1), M["gold"], bevel=0.03)
    for s, item in ((1, "heart"), (-1, "feather")):
        mark(f"pan{s}")
        pan = Vector((s * 1.6, 0.6, 1.95))
        for k in range(3):
            a = k * math.tau / 3
            limb(pan + Vector((math.cos(a) * 0.4, math.sin(a) * 0.4, 0)), Vector((s * 1.6, 0.6, 2.38)), 0.015, M["gold"])
        bpy.ops.mesh.primitive_cylinder_add(vertices=24, radius=0.45, depth=0.06, location=pan)
        assign(obj(), M["gold"])
        if item == "heart":
            mark("heart")
            ball(pan + Vector((0, 0, 0.18)), (0.2, 0.18, 0.18), M["heart"], seg=16)
        else:
            f = ball(pan + Vector((0, 0, 0.12)), (0.12, 0.42, 0.04), M["feather"], seg=16)
            f.rotation_euler = (0, 0, 0.5)


def overlord_echo(M):
    """Hour 10 — the Overlord's Echo: the broken crown of Part 1's Crystal Overlord, full of falling stars."""
    # the hollow crown: a broken ring of crystal blades leaning outward
    for i in range(14):
        if i in (3, 9):                      # two blades lost when it shattered
            continue
        a = i * math.tau / 14
        out = Vector((math.cos(a), math.sin(a), 0))
        h = 1.8 + 0.9 * ((i * 5) % 3) / 2 + (1.0 if math.sin(a) < -0.6 else 0)   # tallest blades face the player
        b = shard(out * 1.55, h, 0.34, M["glass"], tilt=(-out.y * 0.45, out.x * 0.45, a))
        if i % 2 == 0:
            shard(out * 1.2, h * 0.6, 0.18, M["crystal"], tilt=(-out.y * 0.3, out.x * 0.3, a))
    mark("bowl")
    bpy.ops.mesh.primitive_torus_add(major_radius=1.55, minor_radius=0.16, major_segments=64, location=(0, 0, 0.1))
    assign(obj(), M["void"])
    # the hollow core: a void bowl full of falling stars
    ball((0, 0, -0.2), (1.25, 1.25, 0.35), M["void"])
    random.seed(10)
    for k in range(26):
        mark(f"star{k}")
        r, a = random.uniform(0, 1.05), random.uniform(0, math.tau)
        ball((math.cos(a) * r, math.sin(a) * r, random.uniform(0.0, 1.4)), (0.07,) * 3,
             M["starfire"] if k % 3 else M["core"], seg=10)
    mark("core")
    ball((0, 0, 0.35), (0.38, 0.38, 0.38), M["core"])
    mark("cracks")
    # glowing cracks across the void bowl
    for k in range(5):
        a = k * math.tau / 5 + 0.3
        box((math.cos(a) * 0.7, math.sin(a) * 0.7, 0.13), (1.0, 0.05, 0.04), M["violet"], rot=(0, 0, a), bevel=0)
    # gold Atlantean armour fragments still orbiting what's left
    for k in range(7):
        mark(f"frag{k}")
        a = k * math.tau / 7 + 0.4
        p = Vector((math.cos(a) * 3.0, math.sin(a) * 2.6, 0.3 + 0.3 * math.sin(k)))
        f = box(p, (0.7, 0.35, 0.08), M["gold"], rot=(0.4 * math.sin(k), 0.3, a + 0.6), bevel=0.03)
        box(p + Vector((0, 0, 0.05)), (0.45, 0.06, 0.06), M["violet"], rot=(0.4 * math.sin(k), 0.3, a + 0.6), bevel=0)
    # the jagged "jaw" of crystal reaching toward the player
    mark("jaw")
    for k, x in enumerate((-0.7, -0.25, 0.25, 0.7)):
        shard((x, -1.7, 0.0), 1.6 - abs(x) * 0.6, 0.22, M["glass"], tilt=(1.25, 0, 0))


def umbra_unmasked(M):
    """Hour 11 — UMBRA unmasked: the obsidian shell peels away and the gold Thunder beneath shows through.
    It was ELTESLA's shadow all along."""
    spec = dict(ships.SHIPS["sunborn"])
    spec.update(span=1.75, sweep=0.7, glow=(1.0, 0.85, 0.5))
    before = set(bpy.data.objects)
    ships.build_ship(spec)
    parts = [o for o in bpy.data.objects if o not in before]
    bpy.ops.object.empty_add(location=(0, 0, 0))
    root = obj()
    for o in parts:
        o.parent = root
    root.rotation_euler = (0, 0, math.pi)
    root.scale = (1.9, 1.9, 1.9)
    # obsidian mask plates still clinging on, and others peeling away, each with a hot gold seam
    random.seed(11)
    for k in range(16):
        mark(f"plate{k}")
        a = random.uniform(0, math.tau)
        clinging = k < 7
        r = random.uniform(0.6, 2.4) if clinging else random.uniform(2.8, 3.9)
        c = Vector((math.cos(a) * r, math.sin(a) * r * 0.75, 0.45 if clinging else random.uniform(0.6, 1.6)))
        sz = random.uniform(0.35, 0.7)
        tri = [(c.x, c.y + sz), (c.x + sz * 0.9, c.y - sz * 0.6), (c.x - sz * 0.8, c.y - sz * 0.5)]
        plate = flat_poly("mask", tri, 0.08, M["obsidian"], z=c.z)
        if clinging:   # a hot gold seam where the mask is splitting from the hull
            mark(f"seam{k}")
            box((c.x, c.y, c.z + 0.1), (sz * 0.9, 0.05, 0.03), M["ember"], rot=(0, 0, random.uniform(0, 3)), bevel=0)
        else:
            plate.rotation_euler = (random.uniform(-0.8, 0.8), random.uniform(-0.8, 0.8), 0)
    # the light breaking out of it
    mark("heart")
    ball((0, 0.2, 0.75), (0.3, 0.3, 0.2), M["atlantis_heart"], seg=16)


def apep(M, open_jaws=False):
    """Hour 12 — APEP, the Serpent of Unmaking. Phases 1–2: the head with its jaws shut, coils trailing behind.
    Final phase (open_jaws): the jaws thrown open on the Heart of Atlantis."""
    # coils trailing up the screen behind the head
    cu = bpy.data.curves.new("apep_body", "CURVE")
    cu.dimensions = "3D"
    cu.bevel_depth = 1.05
    cu.bevel_resolution = 1                                    # faceted crystal cross-section
    cu.resolution_u = 24
    sp = cu.splines.new("BEZIER")
    pts = [(0, 1.0, 0.1, 1.0), (2.7, 2.9, -0.2, 0.95), (-2.4, 4.8, 0.0, 0.75), (1.0, 6.3, -0.3, 0.4)]
    if WAVE is not None:                                       # animation: a wave travels down the coils
        pts = [(x + 0.55 * i / 3 * math.sin(WAVE - i * 1.3), y, z, r) for i, (x, y, z, r) in enumerate(pts)]
    sp.bezier_points.add(len(pts) - 1)
    for bp, (x, y, z, r) in zip(sp.bezier_points, pts):
        bp.co = (x, y, z)
        bp.handle_left_type = bp.handle_right_type = "AUTO"
        bp.radius = r
    ob = bpy.data.objects.new("apep_body", cu)
    bpy.context.collection.objects.link(ob)
    ob.data.materials.append(M["void"])
    as_mesh(ob)
    # violet light between the scales and a ridge of crystal spines down the back
    for i, (x, y, z, r) in enumerate(pts[:-1]):
        shard((x, y, z + r * 1.4), 1.5 * r + 0.3, 0.26 * r + 0.05, M["glass"], tilt=(0.25, 0, 0))
        ball((x, y, z + r * 1.2), (0.22 * r + 0.05,) * 3, M["core"], seg=12)
    # the head: broad and flat, pointing down the screen
    mark("head")
    ball((0, -0.5, 0.4), (1.9, 1.6, 0.75), M["void"])
    if not open_jaws:
        j = cone((0, -2.8, 0.4), 1.75, 0.15, 3.8, M["void"], rot=toward((0, -1, 0)), verts=4)
        j.scale = (1.0, 0.38, 1.0)
        j.rotation_euler.rotate_axis("Y", math.pi / 4)
        for s in (1, -1):
            for k in range(5):
                cone((s * (1.05 - k * 0.2), -1.7 - k * 0.48, 0.2), 0.09, 0.0, 0.42, M["glass"], rot=(math.pi, 0, 0), verts=6)
    else:
        # the jaws thrown open sideways, so the Heart is visible from above
        for s in (1, -1):
            mark(f"jaw{s}")
            d = Vector((s * 0.5, -1, 0)).normalized()
            j = cone((0, 0, 0), 1.15, 0.12, 3.6, M["void"], rot=toward(d), verts=4)
            j.location = Vector((s * 1.05, -2.3, 0.4))
            j.scale = (1.0, 0.38, 1.0)
            j.rotation_euler.rotate_axis("Y", math.pi / 4)
            for k in range(6):                                 # fangs along the inner edge
                p = Vector((s * 0.55, -1.6, 0.6)) + d * (k * 0.5)
                cone(p, 0.1, 0.0, 0.55, M["glass"], rot=toward((-s, 0, -0.4)), verts=6)
        mark("heart")
        ball((0, -2.3, 0.5), (0.75, 0.75, 0.6), M["atlantis_heart"])
        bpy.ops.mesh.primitive_torus_add(major_radius=1.1, minor_radius=0.08, location=(0, -2.3, 0.5))
        assign(obj(), M["violet"])
    # crown of crystal spines and burning eyes
    mark("crown")
    for i in range(9):
        a = math.pi * (0.1 + 0.8 * i / 8)
        shard((math.cos(a) * 1.75, 0.1 - math.sin(a) * 0.3, 0.9), 1.8 + 0.6 * math.sin(a), 0.28, M["glass"],
              tilt=(-0.5, math.cos(a) * 0.6, 0))
    for s in (1, -1):
        ball((s * 0.95, -1.35, 1.0), (0.16, 0.24, 0.07), M["eye"], seg=16)


KEEPERS = {"wepwawet": wepwawet, "sobek": sobek, "umbra": umbra,
           "nun": nun, "sokar": sokar, "seraphs": seraphs,
           "umbra_coiled": umbra_coiled, "hittite": hittite, "ammit": ammit,
           "overlord_echo": overlord_echo, "umbra_unmasked": umbra_unmasked,
           "apep": apep, "apep_p3": lambda M: apep(M, open_jaws=True)}
ACTS = {"1": ("wepwawet", "sobek", "umbra"), "2": ("nun", "sokar", "seraphs"),
        "3": ("umbra_coiled", "hittite", "ammit"), "4": ("overlord_echo", "umbra_unmasked", "apep", "apep_p3")}


# ------------------------------------------------------------------ animation: one seamless loop per Keeper
# Each animator poses the parts for loop angle w (0..2π). Only whole-loop motion is used (sin/cos of w,
# rotations through a symmetry step), so frame FRAMES wraps cleanly back to frame 0.
def pick(P, prefix):
    return [o for name, objs in P.items() if name.startswith(prefix) for o in objs]


def a_wepwawet(P, w):
    for sx, sy in ((1, -1), (-1, -1), (1, 1), (-1, 1)):            # diagonal pairs stride together
        stride = math.sin(w + (0 if sx * sy < 0 else math.pi))
        move(P[f"leg{sx}{sy}"], (sx * 0.95, sy * 0.55 + 0.25, 0.1), rot=(0, 0, sx * 0.16 * stride))
    move(P["head"], (0, -1.05, 0.35), rot=(0, 0, 0.07 * math.sin(w)))
    move(P["tail"], (0, 1.6, 0.2), rot=(0, 0, 0.35 * math.sin(2 * w)))


def a_sobek(P, w):
    for i in range(7):                                             # a wave travelling down the tail
        move(P[f"tail{i}"], shift=(0.32 * (i + 1) / 7 * math.sin(w - i * 0.8), 0, 0))
    for sx, sy in ((1, -1), (-1, -1), (1, 1), (-1, 1)):            # legs paddle
        move(P[f"leg{sx}{sy}"], (sx * 0.9, sy * 1.1 + 0.2, 0), rot=(0, 0, 0.22 * math.sin(w + (sx * sy) * 1.5)))
    for name, objs in P.items():                                   # turrets track the player
        if name.startswith("turret"):
            s = 1 if name[6] == "1" else -1
            y = float(name[7:] if s > 0 else name[8:])
            move(objs, (s * 1.15, y, 0.35), rot=(0, 0, s * 0.3 * math.sin(w + y)))


def a_umbra(P, w):
    move(pick(P, "drone"), rot=(0, 0, math.pi / 2 * w / math.tau))  # drones orbit one quarter turn per loop


def a_nun(P, w):
    move(P["spires"], rot=(0, 0, math.pi / 4 * w / math.tau))        # the spire crown turns one spire per loop
    for s in (1, -1):
        for k in (0, 1):
            move(P[f"arm{s}{k}"], (s * (0.6 + 0.3 * k), -1.1, 0.1), rot=(0, 0, 0.2 * math.sin(w + k * 1.8 + s)))


def a_sokar(P, w):
    for s in (1, -1):                                              # wingbeat
        move(P[f"wing{s}"], (s * 0.6, 0, 0.25), rot=(0, s * 0.55 * math.sin(w), 0))
    move(P["tail"], (0, 1.3, 0.25), rot=(0, 0, 0.14 * math.sin(w + 1)))


def a_seraphs(P, w):
    for i in range(4):
        a = math.pi / 4 + i * math.pi / 2
        c = (math.cos(a) * 2.35, math.sin(a) * 2.0, 0.2)
        sway = 0.14 * math.sin(w + i * math.pi / 2)
        move(P[f"seraph{i}"] + P[f"flame{i}"], c, rot=(0, 0, sway))
        move(P[f"flame{i}"], c, scale=1 + 0.16 * math.sin(2 * w + i))  # flame wings flicker
    for i in range(10):
        e = P[f"ember{i}"]
        move(e, e[0].location, scale=(1 + 0.3 * math.sin(2 * w + i * 1.7),) * 2 + (1,))


def a_umbra_coiled(P, w):
    a_umbra(P, w)
    move(P["coil"] + P["coilhead"], rot=(0, 0, 0.16 * math.sin(w)))  # the coil tightens and slackens
    move(P["coilhead"], shift=(0, -0.3 * max(0.0, math.sin(w + 1.2)), 0))   # and the head strikes


def a_hittite(P, w):
    for sx, sy in ((1, -1), (-1, -1), (1, 1), (-1, 1)):            # chariot wheels spin a third of a turn
        move(P[f"rotor{sx}{sy}"], (sx * 2.6, sy * 1.35 + 0.25, 0.2), rot=(0, 0, sx * sy * math.tau / 3 * w / math.tau))
    move(P["guns"], shift=(0, 0.14 * max(0.0, math.sin(2 * w)), 0))   # barrage recoil


def a_ammit(P, w):
    move(P["head"], (0, -0.9, 0.55), rot=(0, 0, 0.1 * math.sin(w)))
    move(P["mane"], (0, -0.9, 0.55), scale=1 + 0.05 * math.sin(2 * w))
    tilt = 0.28 * math.sin(w)                                      # the scales of judgement rock
    pivot = Vector((0, 0.6, 2.4))
    move(P["beam"], pivot, rot=(0, tilt, 0))
    for s in (1, -1):
        hang = Vector((s * 1.6, 0.6, 2.38))
        moved = Euler((0, tilt, 0)).to_matrix() @ (hang - pivot) + pivot
        move(P[f"pan{s}"] + (P["heart"] if s > 0 else []), shift=moved - hang)
    move(P["heart"], P["heart"][0].matrix_world.translation, scale=1 + 0.2 * max(0.0, math.sin(3 * w)))


def a_overlord_echo(P, w):
    for k in range(7):                                             # armour fragments orbit
        a = k * math.tau / 7 + 0.4
        da = math.tau / 7 * w / math.tau
        old = Vector((math.cos(a) * 3.0, math.sin(a) * 2.6, 0))
        new = Vector((math.cos(a + da) * 3.0, math.sin(a + da) * 2.6, 0))
        f = P[f"frag{k}"]
        move(f, f[0].location, rot=(0, 0, da), shift=new - old)
    for k in range(26):                                            # falling stars twinkle
        st = P[f"star{k}"]
        move(st, st[0].location, scale=0.5 + 0.7 * (0.5 + 0.5 * math.sin(w + k * 2.3)))
    move(P["core"], (0, 0, 0.35), scale=1 + 0.15 * math.sin(2 * w))


def a_umbra_unmasked(P, w):
    for k in range(16):
        plate = P[f"plate{k}"]
        if f"seam{k}" in P:                                        # clinging plates: seams pulse
            seam = P[f"seam{k}"]
            move(seam, seam[0].location, scale=(1 + 0.35 * math.sin(2 * w + k),) * 2 + (1,))
        else:                                                      # loose plates drift out and back
            c = plate[0].matrix_world @ Vector(plate[0].bound_box[0]).lerp(Vector(plate[0].bound_box[6]), 0.5)
            out = Vector((c.x, c.y, 0)).normalized()
            move(plate, c, rot=(0, 0, 0.25 * math.sin(w + k)), shift=out * 0.3 * math.sin(w + k))
    move(P["heart"], (0, 0.2, 0.75), scale=1 + 0.25 * math.sin(2 * w))


def a_apep(P, w):                                                  # the coil wave comes from WAVE in apep()
    move([o for name, objs in P.items() if name for o in objs], (0, 0.6, 0.4), rot=(0, 0, 0.05 * math.sin(w)))


def a_apep_p3(P, w):
    for s in (1, -1):                                              # the open jaws flex on the Heart
        move(P[f"jaw{s}"], (s * 0.6, -1.0, 0.4), rot=(0, 0, -s * 0.1 * math.sin(2 * w)))
    move(P["heart"], (0, -2.3, 0.5), scale=1 + 0.12 * math.sin(2 * w))
    a_apep(P, w)


ANIMS = {"wepwawet": a_wepwawet, "sobek": a_sobek, "umbra": a_umbra, "nun": a_nun, "sokar": a_sokar,
         "seraphs": a_seraphs, "umbra_coiled": a_umbra_coiled, "hittite": a_hittite, "ammit": a_ammit,
         "overlord_echo": a_overlord_echo, "umbra_unmasked": a_umbra_unmasked, "apep": a_apep, "apep_p3": a_apep_p3}


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


def build_keeper(kid, w=None):
    """Fresh scene with one Keeper; w=None is the static model, otherwise loop angle w is posed."""
    global WAVE
    ships.reset()
    _MARKS.clear()
    WAVE = w
    M = materials()
    KEEPERS[kid](M)
    WAVE = None
    bpy.context.view_layer.update()
    if w is not None:
        ANIMS[kid](parts(), w)
        bpy.context.view_layer.update()
    lights()


def main_anim(kid):
    """FRAMES loop frames at the static sprite's scale, on a 1.5x canvas centred where the sprite is."""
    random.seed(7)
    build_keeper(kid)
    lo, hi = bounds()
    size = hi - lo
    span = max(size.x, size.y) * 1.06            # same pixels-per-unit as keeper_<id>.png (360 / span)
    cx, cy = (lo.x + hi.x) / 2, (lo.y + hi.y) / 2
    os.makedirs(f"{OUT}/anim", exist_ok=True)
    for f in range(FRAMES):
        random.seed(7)
        build_keeper(kid, math.tau * f / FRAMES)
        cam = camera("top", ortho=span * 1.5, loc=(cx, cy, 30), target=(cx, cy, 0))
        render(f"{OUT}/anim/keeper_{kid}_f{f:02d}.png", 540, 540, cam)
    print("animated", kid)


def main():
    random.seed(7)
    os.makedirs(OUT, exist_ok=True)
    chosen = [k for k in KEEPERS if not ONLY_ACT or k == ONLY_ACT or k in ACTS.get(ONLY_ACT, ())]
    if ANIM:
        for kid in chosen:
            main_anim(kid)
        return
    for kid, build in KEEPERS.items():
        if kid not in chosen:
            continue
        ships.reset()
        _MARKS.clear()
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
        cz = (lo.z + hi.z) / 2                     # aim at mid-height so tall Keepers (Ammit's scales) stay in frame
        port = camera("portrait", loc=(cx + d * 0.55, cy - d * 1.25, d * 0.9 + cz), target=(cx, cy - size.y * 0.12, cz), lens=55)
        render(f"{OUT}/keeper_{kid}_portrait.png", 320, 320, port)
        merge_for_export()
        bpy.ops.export_scene.gltf(filepath=f"{OUT}/keeper_{kid}.glb", export_format="GLB",
                                  export_apply=True, export_cameras=False, export_lights=False)
        print("built", kid, "size", tuple(round(v, 2) for v in size))


if __name__ == "__main__":
    main()
