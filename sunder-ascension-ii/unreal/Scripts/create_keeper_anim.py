"""SUNDER: Ascension II — import the Keepers' animation loops for the Codex viewer.

Run inside the Unreal Editor (Tools → Execute Python Script…) AFTER create_keepers.py (its materials are reused), with
the C++ in unreal/Source compiled (it needs USunderKeeperAnim).

The loops are the web Codex's own (the GLBs' baked animation), written as rigid parts by
blender/keepers.py <dir> 8 --fbx-anim into unreal/Content/Keepers/Anim/SM_Keeper_<Id>/:
  SM_Keeper_<Id>_Body.fbx     the fixed body, in the Keeper model's own space
  SM_Keeper_<Id>_<Part>.fbx   each moving part about its own pivot
  SM_Keeper_<Id>_Anim.json    each part's transform for every frame of one loop (32 a second), in Unreal's axes
  SM_Keeper_Apep_Body_FNN.fbx Apep's body at each of those frames: his coil wave bends it, so the viewer flips through
                              them (the web GLB blends wave morph targets instead)

Does, for each of the twelve Keepers:
  1. imports the parts into /Game/Sunder/Keepers/Anim/SM_Keeper_<Id> (materials found among the Keepers' own);
  2. makes /Game/Sunder/Keepers/Anim/DA_KeeperAnim_<Id> with the body, the parts and their frames.
The Codex viewer (ASunderCodexStage) plays a Keeper's loop as soon as its asset exists; without one it shows the still
model.

Safe to run again. Untested until its first run.
"""
import json
import os

import unreal

ANIM_SOURCE_DIR = None    # None = ../Content/Keepers/Anim next to this script; set a path if you moved the script
DEST = "/Game/Sunder/Keepers/Anim"

KEEPERS = ["wepwawet", "sobek", "umbra", "nun", "sokar", "seraphs", "umbra_coiled", "hittite", "ammit",
           "overlord_echo", "umbra_unmasked", "apep"]

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []


def log(msg):
    unreal.log("[SunderKeeperAnim] " + msg)


def step(label, fn, *args):
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:   # the editor's Python API differs a little between versions
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderKeeperAnim] {} failed: {}".format(label, exc))
        return None


def camel(kid):
    return "".join(part.capitalize() for part in kid.split("_"))


def source_dir():
    if ANIM_SOURCE_DIR:
        return ANIM_SOURCE_DIR
    here = os.path.dirname(os.path.abspath(__file__))
    return os.path.normpath(os.path.join(here, "..", "Content", "Keepers", "Anim"))


def fbx_options():
    options = unreal.FbxImportUI()
    options.set_editor_property("import_mesh", True)
    options.set_editor_property("import_as_skeletal", False)
    options.set_editor_property("import_animations", False)
    options.set_editor_property("import_materials", True)
    options.set_editor_property("import_textures", False)
    options.set_editor_property("mesh_type_to_import", unreal.FBXImportType.FBXIT_STATIC_MESH)
    mesh_data = options.get_editor_property("static_mesh_import_data")
    mesh_data.set_editor_property("combine_meshes", True)
    mesh_data.set_editor_property("auto_generate_collision", False)
    mesh_data.set_editor_property("transform_vertex_to_absolute", True)   # the parts' frames assume the model's space
    try:   # reuse the Keeper's materials from create_keepers.py (and any glow added to them since)
        options.get_editor_property("texture_import_data").set_editor_property(
            "material_search_location", unreal.MaterialSearchLocation.ALL_ASSETS)
    except Exception as exc:
        log("material search not set ({}); parts may get their own copies of the materials".format(exc))
    return options


def import_parts(kid, names):
    folder = os.path.join(source_dir(), "SM_Keeper_" + camel(kid))
    dest = "{}/SM_Keeper_{}".format(DEST, camel(kid))
    tasks = []
    for name in names:
        source = os.path.join(folder, name + ".fbx")
        if not os.path.isfile(source):
            raise RuntimeError("not found: " + source)
        task = unreal.AssetImportTask()
        task.set_editor_property("filename", source)
        task.set_editor_property("destination_path", dest)
        task.set_editor_property("destination_name", name)
        task.set_editor_property("automated", True)
        task.set_editor_property("replace_existing", True)
        task.set_editor_property("save", True)
        try:
            task.set_editor_property("options", fbx_options())
        except Exception as exc:   # the Interchange importer may ignore these; the default import is still fine
            log("FBX options not applied ({}); using the importer's defaults".format(exc))
        tasks.append(task)
    TOOLS.import_asset_tasks(tasks)
    meshes = {}
    for name in names:
        full = "{}/{}".format(dest, name)
        if not EAL.does_asset_exist(full):
            raise RuntimeError("import produced no " + full)
        meshes[name] = EAL.load_asset(full)
    return meshes


def frame(values):
    x, y, z, qx, qy, qz, qw, sx, sy, sz = values
    t = unreal.Transform()
    try:
        t.set_editor_property("translation", unreal.Vector(x, y, z))
        t.set_editor_property("rotation", unreal.Quat(qx, qy, qz, qw))
        t.set_editor_property("scale3d", unreal.Vector(sx, sy, sz))
    except Exception:
        t = unreal.Transform(unreal.Vector(x, y, z), unreal.Quat(qx, qy, qz, qw).rotator(), unreal.Vector(sx, sy, sz))
    return t


def build(kid):
    path = os.path.join(source_dir(), "SM_Keeper_" + camel(kid), "SM_Keeper_{}_Anim.json".format(camel(kid)))
    if not os.path.isfile(path):
        raise RuntimeError("not found: {} (run blender/keepers.py <dir> 8 --fbx-anim)".format(path))
    with open(path) as fh:
        data = json.load(fh)
    frames = data.get("body_frames", [])
    meshes = import_parts(kid, [data["body"]] + [p["name"] for p in data["parts"]] + frames)

    name = "DA_KeeperAnim_" + camel(kid)
    full = "{}/{}".format(DEST, name)
    if EAL.does_asset_exist(full):
        asset = EAL.load_asset(full)
    else:
        factory = unreal.DataAssetFactory()
        factory.set_editor_property("data_asset_class", unreal.SunderKeeperAnim)
        asset = TOOLS.create_asset(name, DEST, unreal.SunderKeeperAnim, factory)
        if asset is None:
            raise RuntimeError("could not create " + full)
    parts = []
    for p in data["parts"]:
        part = unreal.SunderKeeperAnimPart()
        part.set_editor_property("mesh", meshes[p["name"]])
        part.set_editor_property("frames", [frame(f) for f in p["frames"]])
        parts.append(part)
    asset.set_editor_property("body", meshes[data["body"]])
    asset.set_editor_property("body_frames", [meshes[name] for name in frames])
    asset.set_editor_property("parts", parts)
    asset.set_editor_property("frames_per_second", float(data["fps"]))
    EAL.save_loaded_asset(asset)
    log("{}: body{} and {} moving parts, {} frames".format(
        name, " ({} wave frames)".format(len(frames)) if frames else "", len(parts), data["frames"]))


def main():
    if not hasattr(unreal, "SunderKeeperAnim"):
        unreal.log_error("[SunderKeeperAnim] C++ types not found: SunderKeeperAnim. Compile unreal/Source first.")
        return
    EAL.make_directory(DEST)
    for kid in KEEPERS:
        step("DA_KeeperAnim_" + camel(kid), build, kid)
    MANUAL.append("Open the Codex (title → CODEX, or pause → CODEX) on a Keeper you've met: its parts should move as in "
                  "web/keepers.html. If a part sits apart from the body, its FBX import didn't keep the model's space "
                  "(check Transform Vertex to Absolute on the part, then re-import)")
    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)


main()
