"""SUNDER: Ascension II — procedural starfighters, rendered top-down for game sprites.

Run with Blender's Python (bpy 4.2):
    python ships.py <out_dir> [size]           ship_<id>.png for every ship in SHIPS (transparent, nose pointing up)
    python ships.py <out_dir> 0 --fbx          SM_Ship_<Id>.fbx for Unreal instead (one mesh each, nose along +Y)
"""
import math
import sys

import bpy
import bmesh
from mathutils import Vector

ARGS = [a for a in sys.argv[1:] if not a.startswith("--")]
OUT = ARGS[0] if len(ARGS) > 0 else "."
SIZE = int(ARGS[1]) if len(ARGS) > 1 else 256
FBX = "--fbx" in sys.argv

# Each ship is the same kit of parts with different proportions and paint.
SHIPS = {
    "sunborn": dict(hull=(0.92, 0.70, 0.24), trim=(1.0, 0.86, 0.45), glow=(0.35, 0.85, 1.0),
                    length=2.2, width=0.34, span=1.55, sweep=0.55, engines=2, eng_r=0.17,
                    eng_x=0.42, canopy=(0.35, 0.85, 1.0), cannons=False, fins=2),
    "scarab":  dict(hull=(0.42, 0.04, 0.05), trim=(0.95, 0.72, 0.30), glow=(1.0, 0.55, 0.15),
                    length=2.0, width=0.46, span=1.75, sweep=0.30, engines=2, eng_r=0.24,
                    eng_x=0.52, canopy=(1.0, 0.55, 0.10), cannons=True, fins=1),
    "ibis":    dict(hull=(0.10, 0.55, 0.32), trim=(0.85, 0.92, 0.90), glow=(0.60, 1.0, 0.80),
                    length=2.4, width=0.26, span=1.30, sweep=0.80, engines=1, eng_r=0.15,
                    eng_x=0.0, canopy=(0.75, 1.0, 0.85), cannons=False, fins=2),
}


ORTHO = [4.0]


def reset():
    bpy.ops.wm.read_factory_settings(use_empty=True)


def mat_metal(name, color, rough=0.28, metal=1.0):
    m = bpy.data.materials.new(name)
    m.use_nodes = True
    b = m.node_tree.nodes["Principled BSDF"]
    b.inputs["Base Color"].default_value = (*color, 1)
    b.inputs["Metallic"].default_value = metal
    b.inputs["Roughness"].default_value = rough
    return m


def mat_glow(name, color, strength=6.0):
    m = bpy.data.materials.new(name)
    m.use_nodes = True
    b = m.node_tree.nodes["Principled BSDF"]
    b.inputs["Base Color"].default_value = (*color, 1)
    b.inputs["Emission Color"].default_value = (*color, 1)
    b.inputs["Emission Strength"].default_value = strength
    return m


def mat_glass(name, color):
    m = bpy.data.materials.new(name)
    m.use_nodes = True
    b = m.node_tree.nodes["Principled BSDF"]
    b.inputs["Base Color"].default_value = (*(c * 0.25 for c in color), 1)
    b.inputs["Roughness"].default_value = 0.08
    b.inputs["Coat Weight"].default_value = 1.0
    b.inputs["Emission Color"].default_value = (*color, 1)
    b.inputs["Emission Strength"].default_value = 0.9
    return m


def assign(obj, mat):
    obj.data.materials.clear()
    obj.data.materials.append(mat)


def smooth(obj):
    for p in obj.data.polygons:
        p.use_smooth = True


def flat_poly(name, pts, thick, mat, z=0.0):
    """Extruded 2D outline (x = right, y = forward) — wings, fins, panels."""
    me = bpy.data.meshes.new(name)
    bm = bmesh.new()
    verts = [bm.verts.new((x, y, z)) for x, y in pts]
    face = bm.faces.new(verts)
    r = bmesh.ops.extrude_face_region(bm, geom=[face])
    top = [e for e in r["geom"] if isinstance(e, bmesh.types.BMVert)]
    bmesh.ops.translate(bm, verts=top, vec=(0, 0, thick))
    bmesh.ops.recalc_face_normals(bm, faces=bm.faces)
    bm.to_mesh(me)
    bm.free()
    ob = bpy.data.objects.new(name, me)
    bpy.context.collection.objects.link(ob)
    bev = ob.modifiers.new("bevel", "BEVEL")
    bev.width = thick * 0.35
    bev.segments = 2
    assign(ob, mat)
    return ob


def build_ship(spec):
    hull = mat_metal("hull", spec["hull"], rough=0.32, metal=0.85)
    wingm = mat_metal("wing", tuple(c * 0.75 for c in spec["hull"]), rough=0.4, metal=0.55)
    trim = mat_metal("trim", spec["trim"], rough=0.22)
    glow = mat_glow("glow", spec["glow"], 14.0)
    canopy = mat_glass("canopy", spec["canopy"])
    dark = mat_metal("dark", (0.05, 0.05, 0.07), rough=0.5, metal=0.6)
    L, Wd = spec["length"], spec["width"]

    # fuselage: a stretched, tapered sphere — nose toward +Y
    bpy.ops.mesh.primitive_uv_sphere_add(segments=48, ring_count=24, radius=1)
    f = bpy.context.object
    f.scale = (Wd, L / 2, Wd * 0.62)
    bm = bmesh.new()
    bm.from_mesh(f.data)
    for v in bm.verts:  # needle nose, broad flat tail
        if v.co.y > 0:
            k = max(0.0, 1 - v.co.y) ** 0.75
            v.co.x *= k
            v.co.z *= k
        else:
            v.co.y *= 0.82
            v.co.x *= 1.0 + 0.25 * (-v.co.y)
    bm.to_mesh(f.data)
    bm.free()
    smooth(f)
    assign(f, hull)

    # nose cone tip
    bpy.ops.mesh.primitive_cone_add(vertices=32, radius1=Wd * 0.32, depth=0.42,
                                    location=(0, L / 2 + 0.05, 0.02), rotation=(-math.pi / 2, 0, 0))
    assign(bpy.context.object, trim)
    smooth(bpy.context.object)

    # canopy gem
    bpy.ops.mesh.primitive_uv_sphere_add(segments=32, ring_count=16, radius=1,
                                         location=(0, L * 0.16, Wd * 0.42))
    c = bpy.context.object
    c.scale = (Wd * 0.34, L * 0.12, Wd * 0.30)
    smooth(c)
    assign(c, canopy)

    # main wings (mirrored outline)
    s, sw = spec["span"], spec["sweep"]
    right = [(Wd * 0.7, 0.35), (s, -0.25 - sw * 0.6), (s, -0.55 - sw * 0.6),
             (Wd * 0.8, -0.55), (Wd * 0.7, -0.35)]
    for side in (1, -1):
        pts = [(x * side, y) for x, y in right]
        if side < 0:
            pts.reverse()
        flat_poly("wing", pts, 0.07, wingm, z=-0.02)
        # gold leading-edge trim
        edge = [(Wd * 0.75 * side, 0.38), (s * side, -0.22 - sw * 0.6),
                (s * side, -0.30 - sw * 0.6), (Wd * 0.75 * side, 0.26)]
        if side < 0:
            edge.reverse()
        flat_poly("edge", edge, 0.085, trim, z=-0.02)
        # glowing energy vein across the wing
        vein = [(Wd * 0.9 * side, -0.12), (s * 0.92 * side, -0.38 - sw * 0.6),
                (s * 0.92 * side, -0.43 - sw * 0.6), (Wd * 0.9 * side, -0.18)]
        if side < 0:
            vein.reverse()
        flat_poly("vein", vein, 0.095, glow, z=-0.02)
        # wingtip pods
        bpy.ops.mesh.primitive_cylinder_add(vertices=24, radius=0.06, depth=0.55,
                                            location=(s * side, -0.40 - sw * 0.6, 0.03),
                                            rotation=(math.pi / 2, 0, 0))
        assign(bpy.context.object, trim)

    # tail fins
    for i in range(spec["fins"]):
        side = 0 if spec["fins"] == 1 else (1 if i == 0 else -1)
        fx = side * Wd * 0.55
        fin = [(fx - 0.05, -0.35), (fx + 0.05, -0.35), (fx + 0.04, -L * 0.48), (fx - 0.04, -L * 0.52)]
        flat_poly("fin", fin, 0.32, hull, z=0.05)

    # engines with glowing exhausts at the rear
    n = spec["engines"]
    xs = [0.0] if n == 1 else [spec["eng_x"], -spec["eng_x"]]
    for x in xs:
        ey = -L * 0.36
        bpy.ops.mesh.primitive_cylinder_add(vertices=32, radius=spec["eng_r"], depth=0.7,
                                            location=(x, ey, -0.04), rotation=(math.pi / 2, 0, 0))
        e = bpy.context.object
        e.scale = (1, 1, 0.75)
        smooth(e)
        assign(e, hull)
        bpy.ops.mesh.primitive_torus_add(major_radius=spec["eng_r"] * 1.0, minor_radius=0.03,
                                         location=(x, ey - 0.33, -0.04), rotation=(math.pi / 2, 0, 0))
        assign(bpy.context.object, trim)
        bpy.ops.mesh.primitive_cylinder_add(vertices=32, radius=spec["eng_r"] * 0.8, depth=0.05,
                                            location=(x, ey - 0.36, -0.04), rotation=(math.pi / 2, 0, 0))
        assign(bpy.context.object, glow)

    # heavy side cannons (Scarab)
    if spec["cannons"]:
        for side in (1, -1):
            bpy.ops.mesh.primitive_cylinder_add(vertices=24, radius=0.075, depth=1.1,
                                                location=(side * (Wd + 0.22), 0.45, 0.0),
                                                rotation=(math.pi / 2, 0, 0))
            assign(bpy.context.object, dark)
            bpy.ops.mesh.primitive_torus_add(major_radius=0.085, minor_radius=0.025,
                                             location=(side * (Wd + 0.22), 1.0, 0.0),
                                             rotation=(math.pi / 2, 0, 0))
            assign(bpy.context.object, trim)

    # spine stripe
    flat_poly("spine", [(-0.035, L * 0.05), (0.035, L * 0.05), (0.035, -L * 0.40), (-0.035, -L * 0.40)],
              Wd * 0.68, glow, z=0.0)


def setup_render(size):
    sc = bpy.context.scene
    sc.render.engine = "CYCLES"
    sc.cycles.device = "CPU"
    sc.cycles.samples = 48
    sc.cycles.use_denoising = True
    sc.render.resolution_x = sc.render.resolution_y = size
    sc.render.film_transparent = True
    sc.render.image_settings.file_format = "PNG"
    sc.render.image_settings.color_mode = "RGBA"
    sc.view_settings.view_transform = "AgX"
    sc.view_settings.look = "AgX - Punchy"

    # world: dim indigo for reflections only (film is transparent)
    w = bpy.data.worlds.new("w")
    sc.world = w
    w.use_nodes = True
    w.node_tree.nodes["Background"].inputs["Color"].default_value = (0.05, 0.05, 0.12, 1)
    w.node_tree.nodes["Background"].inputs["Strength"].default_value = 1.0

    # top-down orthographic camera, nose up
    cam = bpy.data.objects.new("cam", bpy.data.cameras.new("cam"))
    sc.collection.objects.link(cam)
    cam.data.type = "ORTHO"
    cam.data.ortho_scale = ORTHO[0]
    cam.location = (0, 0, 10)
    sc.camera = cam

    def light(name, kind, loc, energy, color=(1, 1, 1), size=2.0):
        ld = bpy.data.lights.new(name, kind)
        ld.energy = energy
        ld.color = color
        if kind == "AREA":
            ld.size = size
        ob = bpy.data.objects.new(name, ld)
        sc.collection.objects.link(ob)
        ob.location = loc
        ob.rotation_euler = (Vector((0, 0, 0)) - Vector(loc)).to_track_quat("-Z", "Y").to_euler()

    light("key", "AREA", (-4, 4, 5), 700, (1.0, 0.92, 0.78), 3)    # warm key, upper left
    light("rim", "AREA", (5, -5, 2), 900, (0.40, 0.60, 1.0), 3)    # cool rim from below right
    light("fill", "AREA", (0, 0, 9), 90, (1, 1, 1), 8)


def export_fbx(sid, path):
    """The ship as ONE mesh (one section per material) for Unreal's FBX importer. 1 Blender unit = 1 m = 100 Unreal
    units, so the ships arrive about 200–250 units long; SunderShipPawn sizes and turns them from its loadout."""
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
    mesh.name = "SM_Ship_" + sid.capitalize()
    bpy.ops.export_scene.fbx(filepath=path, use_selection=True, object_types={"MESH"}, apply_unit_scale=True,
                             apply_scale_options="FBX_SCALE_UNITS", mesh_smooth_type="FACE", use_mesh_modifiers=True,
                             bake_anim=False, add_leaf_bones=False)


def main():
    for sid, spec in SHIPS.items():
        reset()
        build_ship(spec)
        if FBX:
            export_fbx(sid, f"{OUT}/SM_Ship_{sid.capitalize()}.fbx")
            print("exported", sid)
            continue
        ORTHO[0] = max(2 * spec["span"] + 0.3, spec["length"] * 1.25)
        setup_render(SIZE)
        bpy.context.scene.render.filepath = f"{OUT}/ship_{sid}.png"
        bpy.ops.render.render(write_still=True)
        print("rendered", sid)


if __name__ == "__main__":
    main()
