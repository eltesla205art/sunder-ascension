"""SUNDER: Ascension II — title-screen backdrop.

The crystal gate of the First Hour rising from a night desert, the sun swallowed
by an eclipse, and Apep's crystal coils across the sky (DESIGN.md §1, §3).
Portrait framing to match the 480x720 game canvas; the logo, ship and prompts
are drawn by the game on top, so the upper third and the bottom stay calm.

    python title_scene.py <out.png> [width] [height] [samples]
"""
import math
import random
import sys

import bpy
import bmesh
from mathutils import Vector

OUT = sys.argv[1] if len(sys.argv) > 1 else "title_bg.png"
RW = int(sys.argv[2]) if len(sys.argv) > 2 else 720
RH = int(sys.argv[3]) if len(sys.argv) > 3 else 1080
SAMPLES = int(sys.argv[4]) if len(sys.argv) > 4 else 96
random.seed(12)

bpy.ops.wm.read_factory_settings(use_empty=True)
sc = bpy.context.scene
col = sc.collection


# ---------------------------------------------------------------- materials
def principled(name, base, metal=0.0, rough=0.5, emit=None, emit_str=0.0, trans=0.0, ior=1.45):
    m = bpy.data.materials.new(name)
    m.use_nodes = True
    b = m.node_tree.nodes["Principled BSDF"]
    b.inputs["Base Color"].default_value = (*base, 1)
    b.inputs["Metallic"].default_value = metal
    b.inputs["Roughness"].default_value = rough
    b.inputs["Transmission Weight"].default_value = trans
    b.inputs["IOR"].default_value = ior
    if emit:
        b.inputs["Emission Color"].default_value = (*emit, 1)
        b.inputs["Emission Strength"].default_value = emit_str
    return m


def emission(name, color, strength):
    m = bpy.data.materials.new(name)
    m.use_nodes = True
    nt = m.node_tree
    nt.nodes.clear()
    e = nt.nodes.new("ShaderNodeEmission")
    e.inputs["Color"].default_value = (*color, 1)
    e.inputs["Strength"].default_value = strength
    o = nt.nodes.new("ShaderNodeOutputMaterial")
    nt.links.new(e.outputs[0], o.inputs[0])
    return m


def radial_glow(name, inner, outer, strength, power=2.0, spread=2.0):
    """Emission that fades from the centre of a disc outwards, alpha-blended."""
    m = bpy.data.materials.new(name)
    m.use_nodes = True
    m.blend_method = "BLEND"
    nt = m.node_tree
    nt.nodes.clear()
    tc = nt.nodes.new("ShaderNodeTexCoord")
    grad = nt.nodes.new("ShaderNodeTexGradient")
    grad.gradient_type = "SPHERICAL"
    mp = nt.nodes.new("ShaderNodeMapping")
    mp.inputs["Scale"].default_value = (spread, spread, spread)
    nt.links.new(tc.outputs["Object"], mp.inputs["Vector"])
    nt.links.new(mp.outputs[0], grad.inputs["Vector"])
    pw = nt.nodes.new("ShaderNodeMath")
    pw.operation = "POWER"
    pw.inputs[1].default_value = power
    nt.links.new(grad.outputs["Fac"], pw.inputs[0])
    ramp = nt.nodes.new("ShaderNodeMixRGB")
    ramp.inputs["Color1"].default_value = (*outer, 1)
    ramp.inputs["Color2"].default_value = (*inner, 1)
    nt.links.new(pw.outputs[0], ramp.inputs["Fac"])
    em = nt.nodes.new("ShaderNodeEmission")
    em.inputs["Strength"].default_value = strength
    nt.links.new(ramp.outputs[0], em.inputs["Color"])
    tr = nt.nodes.new("ShaderNodeBsdfTransparent")
    mix = nt.nodes.new("ShaderNodeMixShader")
    nt.links.new(pw.outputs[0], mix.inputs["Fac"])
    nt.links.new(tr.outputs[0], mix.inputs[1])
    nt.links.new(em.outputs[0], mix.inputs[2])
    o = nt.nodes.new("ShaderNodeOutputMaterial")
    nt.links.new(mix.outputs[0], o.inputs[0])
    return m


def add_bump(mat, kind, scale, strength):
    """Bump the material's normal with a procedural texture (blocks / ripples)."""
    nt = mat.node_tree
    b = nt.nodes["Principled BSDF"]
    if kind == "brick":
        t = nt.nodes.new("ShaderNodeTexBrick")
        t.inputs["Scale"].default_value = scale
        t.inputs["Mortar Size"].default_value = 0.025
        t.inputs["Color1"].default_value = (1, 1, 1, 1)
        t.inputs["Color2"].default_value = (0.8, 0.8, 0.8, 1)
        t.inputs["Mortar"].default_value = (0, 0, 0, 1)
        src = t.outputs["Fac"]
    else:
        t = nt.nodes.new("ShaderNodeTexWave")
        t.inputs["Scale"].default_value = scale
        t.inputs["Distortion"].default_value = 6.0
        src = t.outputs["Fac"]
    bump = nt.nodes.new("ShaderNodeBump")
    bump.inputs["Strength"].default_value = strength
    nt.links.new(src, bump.inputs["Height"])
    nt.links.new(bump.outputs["Normal"], b.inputs["Normal"])


def link(obj, mat):
    obj.data.materials.clear()
    obj.data.materials.append(mat)
    return obj


GOLD = principled("gold", (0.85, 0.62, 0.22), metal=1.0, rough=0.35)
STONE = principled("stone", (0.26, 0.19, 0.13), rough=0.75)
SAND = principled("sand", (0.22, 0.15, 0.09), rough=0.9)
CRYSTAL = principled("crystal", (0.75, 0.25, 0.85), rough=0.06, trans=0.85, ior=1.6,
                     emit=(1.0, 0.25, 0.65), emit_str=1.8)
SERPENT = principled("serpent", (0.05, 0.025, 0.09), metal=0.9, rough=0.3,
                     emit=(0.45, 0.15, 0.9), emit_str=0.12)
add_bump(STONE, "brick", 3.0, 0.8)
add_bump(SAND, "wave", 0.6, 0.35)
VOID = principled("void", (0.0, 0.0, 0.0), rough=1.0)
RIM = emission("rim", (1.0, 0.72, 0.30), 40.0)
PORTAL = radial_glow("portal", (1.0, 0.30, 0.80), (0.30, 0.04, 0.50), 2.6, power=1.2, spread=1.5)
CORONA = radial_glow("corona", (1.0, 0.60, 0.25), (0.30, 0.06, 0.40), 2.2, power=3.0, spread=2.0)


# ---------------------------------------------------------------- world sky
w = bpy.data.worlds.new("sky")
sc.world = w
w.use_nodes = True
nt = w.node_tree
nt.nodes.clear()
tc = nt.nodes.new("ShaderNodeTexCoord")
sep = nt.nodes.new("ShaderNodeSeparateXYZ")
nt.links.new(tc.outputs["Generated"], sep.inputs[0])
ramp = nt.nodes.new("ShaderNodeValToRGB")
ramp.color_ramp.elements[0].position = 0.0
ramp.color_ramp.elements[0].color = (0.10, 0.04, 0.16, 1)    # violet horizon haze
ramp.color_ramp.elements[1].position = 0.45
ramp.color_ramp.elements[1].color = (0.006, 0.006, 0.025, 1)  # deep indigo zenith
nt.links.new(sep.outputs["Z"], ramp.inputs["Fac"])
# stars: tiny voronoi points
vor = nt.nodes.new("ShaderNodeTexVoronoi")
vor.feature = "DISTANCE_TO_EDGE"
vor.inputs["Scale"].default_value = 420.0
vor.inputs["Randomness"].default_value = 1.0
vor2 = nt.nodes.new("ShaderNodeTexVoronoi")
vor2.inputs["Scale"].default_value = 420.0
nt.links.new(tc.outputs["Generated"], vor2.inputs["Vector"])
lt = nt.nodes.new("ShaderNodeMath")
lt.operation = "LESS_THAN"
lt.inputs[1].default_value = 0.05
nt.links.new(vor2.outputs["Distance"], lt.inputs[0])
rnd = nt.nodes.new("ShaderNodeMath")
rnd.operation = "GREATER_THAN"
rnd.inputs[1].default_value = 0.72
nt.links.new(vor2.outputs["Color"], rnd.inputs[0])
star = nt.nodes.new("ShaderNodeMath")
star.operation = "MULTIPLY"
nt.links.new(lt.outputs[0], star.inputs[0])
nt.links.new(rnd.outputs[0], star.inputs[1])
starc = nt.nodes.new("ShaderNodeMath")
starc.operation = "MULTIPLY"
starc.inputs[1].default_value = 4.0
nt.links.new(star.outputs[0], starc.inputs[0])
add = nt.nodes.new("ShaderNodeMixRGB")
add.blend_type = "ADD"
add.inputs["Color2"].default_value = (0.85, 0.85, 1.0, 1)
nt.links.new(starc.outputs[0], add.inputs["Fac"])
nt.links.new(ramp.outputs["Color"], add.inputs["Color1"])
bg = nt.nodes.new("ShaderNodeBackground")
bg.inputs["Strength"].default_value = 1.0
nt.links.new(add.outputs[0], bg.inputs["Color"])
out = nt.nodes.new("ShaderNodeOutputWorld")
nt.links.new(bg.outputs[0], out.inputs[0])


# ---------------------------------------------------------------- desert
bpy.ops.mesh.primitive_plane_add(size=260, location=(0, 60, 0))
desert = bpy.context.object
sub = desert.modifiers.new("sub", "SUBSURF")
sub.subdivision_type = "SIMPLE"
sub.levels = sub.render_levels = 6
tex = bpy.data.textures.new("dunes", "CLOUDS")
tex.noise_scale = 14.0
tex.noise_depth = 1
disp = desert.modifiers.new("disp", "DISPLACE")
disp.texture = tex
disp.strength = 6.0
disp.mid_level = 0.6
link(desert, SAND)
for p in desert.data.polygons:
    p.use_smooth = True


# ---------------------------------------------------------------- the gate
def pylon(x):
    """Egyptian pylon: a tapered tower with a gold cap band."""
    bpy.ops.mesh.primitive_cube_add(size=1, location=(x, 0, 6))
    t = bpy.context.object
    t.scale = (3.2, 2.4, 12)
    bm = bmesh.new()
    bm.from_mesh(t.data)
    for v in bm.verts:
        if v.co.z > 0:
            v.co.x *= 0.72
            v.co.y *= 0.8
    bm.to_mesh(t.data)
    bm.free()
    bev = t.modifiers.new("b", "BEVEL")
    bev.width = 0.06
    bev.segments = 2
    link(t, STONE)
    bpy.ops.mesh.primitive_cube_add(size=1, location=(x, 0, 12.25))
    cap = bpy.context.object
    cap.scale = (2.6, 2.1, 0.5)
    link(cap, GOLD)
    for z in (3.0, 6.0, 9.0):  # carved gold bands
        bpy.ops.mesh.primitive_cube_add(size=1, location=(x, -1.05 + 0.05 * (z / 3), z))
        band = bpy.context.object
        band.scale = (3.2 - 0.27 * (z / 3), 0.12, 0.18)
        link(band, GOLD)


GX = 5.2
pylon(-GX)
pylon(GX)
# lintel
bpy.ops.mesh.primitive_cube_add(size=1, location=(0, 0, 12.9))
lin = bpy.context.object
lin.scale = (2 * GX + 2.8, 2.2, 0.9)
link(lin, GOLD)
# winged sun-disc emblem on the lintel
bpy.ops.mesh.primitive_cylinder_add(radius=0.55, depth=0.2, location=(0, -1.2, 12.9), rotation=(math.pi / 2, 0, 0))
link(bpy.context.object, emission("emblem", (1.0, 0.72, 0.30), 6))
for side in (-1, 1):  # the sun-disc's wings
    bpy.ops.mesh.primitive_cube_add(size=1, location=(side * 1.9, -1.2, 12.95))
    wing = bpy.context.object
    wing.scale = (2.6, 0.12, 0.32)
    wing.rotation_euler = (0, side * 0.12, 0)
    link(wing, GOLD)

# portal between the pylons
bpy.ops.mesh.primitive_plane_add(size=1, location=(0, 0.2, 6.2), rotation=(math.pi / 2, 0, 0))
portal = bpy.context.object
portal.scale = (8.2, 12.6, 1)
link(portal, PORTAL)


# ---------------------------------------------------------------- crystal growth
def shard(loc, h, r, tilt):
    bpy.ops.mesh.primitive_cone_add(vertices=6, radius1=r, radius2=r * 0.15, depth=h,
                                    location=(loc[0], loc[1], loc[2] + h / 2 * math.cos(tilt[0])),
                                    rotation=tilt)
    link(bpy.context.object, CRYSTAL)


for side in (-1, 1):
    for i in range(9):
        x = side * (GX + random.uniform(-1.8, 3.8))
        y = random.uniform(-3.5, 2.5)
        h = random.uniform(2.0, 8.5)
        shard((x, y, -0.3), h, random.uniform(0.35, 0.9),
              (random.uniform(-0.25, 0.25), side * random.uniform(0.05, 0.45), random.uniform(0, 3)))
# shards breaking through the sand towards the camera
for i in range(14):
    x = random.uniform(-14, 14)
    y = random.uniform(-9, -3)
    if abs(x) < 3:
        continue
    h = random.uniform(0.6, 3.0)
    shard((x, y, -0.4), h, random.uniform(0.15, 0.45),
          (random.uniform(-0.4, 0.4), random.uniform(-0.4, 0.4), random.uniform(0, 3)))


# ---------------------------------------------------------------- eclipse
SUN = Vector((0, 90, 64))
bpy.ops.mesh.primitive_circle_add(vertices=96, radius=10.0, fill_type="NGON", location=SUN, rotation=(math.pi / 2, 0, 0))
link(bpy.context.object, VOID)
bpy.ops.mesh.primitive_torus_add(major_radius=10.05, minor_radius=0.22, major_segments=128,
                                 location=SUN + Vector((0, 0.3, 0)), rotation=(math.pi / 2, 0, 0))
link(bpy.context.object, RIM)
bpy.ops.mesh.primitive_plane_add(size=1, location=SUN + Vector((0, 1.5, 0)), rotation=(math.pi / 2, 0, 0))
cor = bpy.context.object
cor.scale = (64, 64, 1)
link(cor, CORONA)


# ---------------------------------------------------------------- Apep, the serpent
def serpent():
    cu = bpy.data.curves.new("apep", "CURVE")
    cu.dimensions = "3D"
    cu.bevel_depth = 2.6
    cu.bevel_resolution = 1  # faceted, crystalline cross-section
    cu.resolution_u = 24
    sp = cu.splines.new("BEZIER")
    # one full coil around the eclipse, then the neck rears up-left and strikes down
    pts = [(-34, 112, 34, 0.25), (-24, 96, 78, 0.75), (8, 88, 90, 0.95), (28, 86, 66, 1.0),
           (18, 82, 40, 1.0), (-12, 80, 38, 1.0), (-30, 76, 52, 0.95), (-38, 64, 70, 0.95),
           (-32, 50, 74, 1.0)]
    sp.bezier_points.add(len(pts) - 1)
    for bp, (x, y, z, r) in zip(sp.bezier_points, pts):
        bp.co = (x, y, z)
        bp.handle_left_type = bp.handle_right_type = "AUTO"
        bp.radius = r
    ob = bpy.data.objects.new("apep", cu)
    col.objects.link(ob)
    link(ob, SERPENT)

    neck = Vector(pts[-1][:3])
    strike = Vector((0.75, -0.45, -0.48)).normalized()  # toward the gate and the camera
    head = neck + strike * 6.0
    rot = strike.to_track_quat("Z", "Y").to_euler()
    for jaw, off in ((1, 0.9), (-1, -0.9)):
        bpy.ops.mesh.primitive_cone_add(vertices=4, radius1=4.6, radius2=0.3, depth=12.0,
                                        location=head + Vector((0, 0, off * 1.5)), rotation=rot)
        h = bpy.context.object
        h.scale = (1.0, 0.5, 1.0)
        h.rotation_euler.rotate_axis("X", jaw * 0.28)
        link(h, SERPENT)
    bpy.ops.mesh.primitive_uv_sphere_add(radius=1.6, location=head + strike * 3.5)
    link(bpy.context.object, emission("maw", (1.0, 0.15, 0.50), 1.8))
    side = strike.cross(Vector((0, 0, 1))).normalized()
    for ex in (1.3, -1.3):
        bpy.ops.mesh.primitive_uv_sphere_add(radius=0.5, location=head - strike * 2.0 + side * ex * 1.4 + Vector((0, 0, 2.6)))
        link(bpy.context.object, emission("eye", (1.0, 0.70, 0.2), 12))
    # crystal spines along the back
    for i in range(1, len(pts) - 1):
        x, y, z, r = pts[i]
        for k in range(3):
            shard((x + random.uniform(-3, 3), y + random.uniform(-2, 2), z + r * 2.0),
                  random.uniform(2.5, 5.0) * r, 0.7 * r,
                  (random.uniform(-0.4, 0.4), random.uniform(-0.4, 0.4), 0))


serpent()


# ---------------------------------------------------------------- lights
def add_light(name, kind, loc, energy, color, size=5.0, target=(0, 0, 4)):
    ld = bpy.data.lights.new(name, kind)
    ld.energy = energy
    ld.color = color
    if kind == "AREA":
        ld.size = size
    if kind == "SUN":
        ld.angle = 0.05
    ob = bpy.data.objects.new(name, ld)
    col.objects.link(ob)
    ob.location = loc
    ob.rotation_euler = (Vector(target) - Vector(loc)).to_track_quat("-Z", "Y").to_euler()
    return ob


add_light("moon", "SUN", (-40, 60, 22), 0.9, (0.55, 0.65, 1.0))
add_light("portal", "POINT", (0, -2.5, 4.5), 2200, (1.0, 0.30, 0.80))
add_light("gate_key", "AREA", (-16, -14, 18), 900, (1.0, 0.80, 0.55), 8)
add_light("eclipse_back", "AREA", (0, 40, 30), 5000, (1.0, 0.62, 0.30), 20, target=(0, 0, 8))


# ---------------------------------------------------------------- camera + render
cam = bpy.data.objects.new("cam", bpy.data.cameras.new("cam"))
col.objects.link(cam)
cam.data.lens = 24
cam.location = (0, -30, 2.2)
cam.rotation_euler = (Vector((0, 40, 26)) - cam.location).to_track_quat("-Z", "Y").to_euler()
sc.camera = cam

sc.render.engine = "CYCLES"
sc.cycles.device = "CPU"
sc.cycles.samples = SAMPLES
sc.cycles.use_denoising = True
sc.cycles.max_bounces = 6
sc.render.resolution_x = RW
sc.render.resolution_y = RH
sc.view_settings.view_transform = "AgX"
sc.view_settings.look = "AgX - High Contrast"
sc.render.image_settings.file_format = "PNG"
sc.render.filepath = OUT
bpy.ops.render.render(write_still=True)
print("rendered", OUT)
