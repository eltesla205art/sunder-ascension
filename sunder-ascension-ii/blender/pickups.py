"""SUNDER: Ascension II — the six power-up pickups as 3D gems, after the web game's pickup icons (web/game.html SVGS
powerup_*): a faceted diamond in the pickup's colour on a gold rim (cyan for the shield), with a raised emblem.

Run with Blender's Python (bpy 4.2):
    python pickups.py <out_dir> [size]          pickups_preview.png: all six from above and at an angle
    python pickups.py <out_dir> 0 --fbx         SM_Pickup_<Kind>.fbx for Unreal (one mesh each, lying flat, emblem
                                                reading up along +Y)

  Spread  red diamond, "S"        Laser   blue diamond, "L"        Power   a gold star
  Bomb    amber diamond, a bomb   Shield  blue diamond on a cyan rim, a ring
  Life    rose diamond, an ankh
1 Blender unit = 1 m = 100 Unreal units: each gem is about 1 m corner to corner; SunderPickup sizes it on screen.
"""
import math
import os
import sys

import bpy
import bmesh
from mathutils import Vector

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ships  # noqa: E402  (shared materials and helpers)

ARGS = [a for a in sys.argv[1:] if not a.startswith("--")]
OUT = ARGS[0] if len(ARGS) > 0 else "."
SIZE = int(ARGS[1]) if len(ARGS) > 1 else 160
FBX = "--fbx" in sys.argv

GOLD = (1.0, 0.70, 0.13)
CYAN = (0.27, 0.77, 1.0)
CREAM = (1.0, 0.92, 0.60)

# kind: (gem colour (from the SVG gradient's middle stop), rim, emblem)
PICKUPS = {
    "spread": ((0.76, 0.05, 0.05), GOLD, "S"),
    "laser":  ((0.03, 0.21, 0.69), GOLD, "L"),
    "power":  ((0.66, 0.43, 0.04), None, "star"),
    "bomb":   ((0.66, 0.23, 0.02), GOLD, "bomb"),
    "shield": ((0.04, 0.39, 0.76), CYAN, "ring"),
    "life":   ((0.76, 0.04, 0.15), GOLD, "ankh"),
}


def gem_material(color):
    """Glassy, lit from within: the SVG's radial gradient (pale centre, deep edge) as a coated jewel."""
    m = bpy.data.materials.new("gem")
    m.use_nodes = True
    b = m.node_tree.nodes["Principled BSDF"]
    b.inputs["Base Color"].default_value = (*color, 1)
    b.inputs["Metallic"].default_value = 0.2
    b.inputs["Roughness"].default_value = 0.12
    b.inputs["Coat Weight"].default_value = 1.0
    b.inputs["Emission Color"].default_value = (*color, 1)
    b.inputs["Emission Strength"].default_value = 0.9
    return m


def new_mesh(name, build):
    me = bpy.data.meshes.new(name)
    bm = bmesh.new()
    build(bm)
    bmesh.ops.recalc_face_normals(bm, faces=bm.faces)
    bm.to_mesh(me)
    bm.free()
    ob = bpy.data.objects.new(name, me)
    bpy.context.collection.objects.link(ob)
    return ob


def diamond_gem(mat, r=0.5, table=0.58, crown=0.13, pavilion=0.10):
    """A table-cut diamond seen point-up: a flat top facet, sloped crown, shallow point underneath."""
    def build(bm):
        girdle = [bm.verts.new((r * math.sin(a), r * math.cos(a), 0.0)) for a in (0, math.pi / 2, math.pi, 3 * math.pi / 2)]
        top = [bm.verts.new((v.co.x * table, v.co.y * table, crown)) for v in girdle]
        tip = bm.verts.new((0, 0, -pavilion))
        bm.faces.new(top)
        for i in range(4):
            j = (i + 1) % 4
            bm.faces.new((girdle[i], girdle[j], top[j], top[i]))
            bm.faces.new((girdle[j], girdle[i], tip))
    ob = new_mesh("gem", build)
    ships.assign(ob, mat)
    return ob


def star_points(r_out, r_in, n=5):
    pts = []
    for i in range(n * 2):
        a = math.pi / 2 + i * math.pi / n
        r = r_out if i % 2 == 0 else r_in
        pts.append((r * math.cos(a), r * math.sin(a)))
    return pts


def star_gem(mat, gold):
    """The Power pickup: a gold star (the SVG's star), its centre domed."""
    pts = star_points(0.52, 0.22)
    body = ships.flat_poly("star", list(reversed(pts)), 0.10, mat, z=-0.04)
    bpy.ops.mesh.primitive_uv_sphere_add(segments=32, ring_count=16, radius=0.13, location=(0, 0, 0.06))
    dome = bpy.context.object
    dome.scale = (1, 1, 0.45)
    ships.smooth(dome)
    ships.assign(dome, gold)
    return [body, dome]


def text_emblem(char, mat, z):
    bpy.ops.object.text_add(location=(0, 0, z))
    t = bpy.context.object
    t.data.body = char
    t.data.align_x = "CENTER"
    t.data.align_y = "CENTER"
    t.data.size = 0.46
    t.data.extrude = 0.025
    t.data.bevel_depth = 0.006
    bpy.ops.object.convert(target="MESH")
    ob = bpy.context.object
    ships.assign(ob, mat)
    return [ob]


def bomb_emblem(mat, dark, z):
    bpy.ops.mesh.primitive_uv_sphere_add(segments=32, ring_count=16, radius=0.15, location=(0, -0.04, z + 0.03))
    ball = bpy.context.object
    ball.scale = (1, 1, 0.55)
    ships.smooth(ball)
    ships.assign(ball, dark)
    # the fuse: a short curved tube up and to the right, and its spark
    curve = bpy.data.curves.new("fuse", "CURVE")
    curve.dimensions = "3D"
    spline = curve.splines.new("BEZIER")
    spline.bezier_points.add(1)
    for p, co, h in zip(spline.bezier_points, ((0.0, 0.09, z + 0.05), (0.09, 0.2, z + 0.05)), ((0.0, 0.16, z + 0.05), (0.03, 0.2, z + 0.05))):
        p.co = co
        p.handle_left_type = p.handle_right_type = "AUTO"
    curve.bevel_depth = 0.014
    fuse = bpy.data.objects.new("fuse", curve)
    bpy.context.collection.objects.link(fuse)
    bpy.context.view_layer.objects.active = fuse
    fuse.select_set(True)
    bpy.ops.object.convert(target="MESH")
    ships.assign(fuse, mat)
    bpy.ops.mesh.primitive_uv_sphere_add(segments=16, ring_count=8, radius=0.035, location=(0.1, 0.21, z + 0.05))
    spark = bpy.context.object
    ships.assign(spark, ships.mat_glow("spark", (1.0, 0.84, 0.29), 8.0))
    return [ball, fuse, spark]


def ring_emblem(mat, z):
    bpy.ops.mesh.primitive_torus_add(major_radius=0.15, minor_radius=0.024, location=(0, 0, z + 0.02))
    ring = bpy.context.object
    ships.assign(ring, mat)
    bpy.ops.mesh.primitive_uv_sphere_add(segments=24, ring_count=12, radius=0.055, location=(0, 0, z + 0.02))
    dot = bpy.context.object
    dot.scale = (1, 1, 0.5)
    ships.smooth(dot)
    ships.assign(dot, mat)
    return [ring, dot]


def ankh_emblem(mat, z):
    bpy.ops.mesh.primitive_torus_add(major_radius=0.065, minor_radius=0.022, location=(0, 0.13, z + 0.02))
    loop = bpy.context.object
    loop.scale = (0.85, 1.1, 1)
    parts = [loop]
    for loc, scale in (((0, -0.06, z + 0.02), (0.022, 0.14, 0.02)),    # the stem
                       ((0, 0.02, z + 0.02), (0.11, 0.022, 0.02))):    # the crossbar
        bpy.ops.mesh.primitive_cube_add(size=2, location=loc)
        bar = bpy.context.object
        bar.scale = scale
        bev = bar.modifiers.new("bevel", "BEVEL")
        bev.width = 0.008
        parts.append(bar)
    for p in parts:
        ships.assign(p, mat)
    return parts


def build_pickup(kind):
    color, rim, emblem = PICKUPS[kind]
    gold = ships.mat_metal("gold", GOLD, rough=0.22)
    cream = ships.mat_glow("emblem", CREAM, 1.6)
    if emblem == "star":
        return star_gem(ships.mat_metal("star", GOLD, rough=0.25), ships.mat_glow("core", (1.0, 0.62, 0.12), 1.2))
    parts = [diamond_gem(gem_material(color))]
    # the rim: a slightly larger flat diamond under the gem, showing as a gold (or cyan) border from above
    rim_mat = ships.mat_metal("rim", rim, rough=0.22 if rim != CYAN else 0.15)
    rim_pts = [(0.0, 0.57), (0.57, 0.0), (0.0, -0.57), (-0.57, 0.0)]
    parts.append(ships.flat_poly("rim", rim_pts, 0.06, rim_mat, z=-0.05))
    top = 0.13
    if emblem in ("S", "L"):
        parts += text_emblem(emblem, cream, top)
    elif emblem == "bomb":
        parts += bomb_emblem(cream, ships.mat_metal("bombshell", (0.16, 0.10, 0.02), rough=0.35), top)
    elif emblem == "ring":
        parts += ring_emblem(cream, top)
    elif emblem == "ankh":
        parts += ankh_emblem(cream, top)
    return parts


def unreal_name(kind):
    return "SM_Pickup_" + kind.capitalize()


def export_fbx(kind, path):
    meshes = [o for o in bpy.context.scene.objects if o.type == "MESH"]
    bpy.ops.object.select_all(action="DESELECT")
    for o in meshes:
        o.select_set(True)
    bpy.context.view_layer.objects.active = meshes[0]
    bpy.ops.object.convert(target="MESH")              # bake the bevel modifiers
    if len(meshes) > 1:
        bpy.ops.object.join()
    mesh = bpy.context.view_layer.objects.active
    bpy.ops.object.transform_apply(location=False, rotation=True, scale=True)
    mesh.name = unreal_name(kind)
    bpy.ops.export_scene.fbx(filepath=path, use_selection=True, object_types={"MESH"}, apply_unit_scale=True,
                             apply_scale_options="FBX_SCALE_UNITS", mesh_smooth_type="FACE", use_mesh_modifiers=True,
                             bake_anim=False, add_leaf_bones=False)


def preview(path, size):
    """All six in a row: from above (as the game sees them) and, below, tilted to show the cut and the emblems."""
    sc = bpy.context.scene
    sc.render.engine = "CYCLES"
    sc.cycles.device = "CPU"
    sc.cycles.samples = 48
    sc.cycles.use_denoising = True
    sc.render.resolution_x, sc.render.resolution_y = size * 6, size * 2
    sc.view_settings.view_transform = "AgX"
    sc.view_settings.look = "AgX - Punchy"
    w = bpy.data.worlds.new("w")
    sc.world = w
    w.use_nodes = True
    w.node_tree.nodes["Background"].inputs["Color"].default_value = (0.02, 0.02, 0.05, 1)
    cam = bpy.data.objects.new("cam", bpy.data.cameras.new("cam"))
    sc.collection.objects.link(cam)
    cam.data.type = "ORTHO"
    cam.data.ortho_scale = 6 * 1.4
    cam.location = (0, 0, 10)
    sc.camera = cam
    for name, loc, e, col in (("key", (-4, 4, 6), 900, (1, .92, .8)), ("rim", (5, -3, 3), 700, (.4, .6, 1)),
                              ("fill", (0, 0, 9), 200, (1, 1, 1))):
        ld = bpy.data.lights.new(name, "AREA")
        ld.energy, ld.color, ld.size = e, col, 6
        ob = bpy.data.objects.new(name, ld)
        sc.collection.objects.link(ob)
        ob.location = loc
        ob.rotation_euler = (Vector((0, 0, 0)) - Vector(loc)).to_track_quat("-Z", "Y").to_euler()
    sc.render.filepath = path
    bpy.ops.render.render(write_still=True)


def main():
    if FBX:
        for kind in PICKUPS:
            ships.reset()
            build_pickup(kind)
            export_fbx(kind, os.path.join(OUT, unreal_name(kind) + ".fbx"))
            print("exported", kind)
        return
    ships.reset()
    for i, kind in enumerate(PICKUPS):
        x = (i - 2.5) * 1.4
        for row, (y, tilt) in enumerate(((0.7, 0.0), (-0.7, math.radians(55)))):
            parts = build_pickup(kind)
            pivot = bpy.data.objects.new("pivot_{}_{}".format(kind, row), None)
            bpy.context.collection.objects.link(pivot)
            for p in parts:
                p.parent = pivot
            pivot.location = (x, y, 0)
            pivot.rotation_euler = (tilt, 0, math.radians(-20) if row else 0)
    preview(os.path.join(OUT, "pickups_preview.png"), SIZE)
    print("rendered pickups_preview.png")


if __name__ == "__main__":
    main()
