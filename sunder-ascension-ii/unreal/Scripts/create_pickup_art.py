"""SUNDER: Ascension II — the six power-up pickups' art, in place of the placeholder diamonds.

Run inside the Unreal Editor (Tools → Execute Python Script…) AFTER create_arena_level.py, with the C++ in unreal/Source
compiled (SunderPickup's KindMeshes).

Does:
  1. imports unreal/Content/Pickups/SM_Pickup_<Kind>.fbx (blender/pickups.py --fbx: faceted gems after the web game's
     pickup icons, each with its emblem) into /Game/Sunder/Pickups;
  2. makes BP_SunderPickup (a SunderPickup child) with each kind's model in Kind Meshes;
  3. sets BP_SunderGameMode → Pickup Class to it, so enemies drop the gems.

Safe to run again. Untested until its first run.
"""
import os

import unreal

SOURCE_DIR = None   # None = ../Content/Pickups next to this script

MESH_DIR = "/Game/Sunder/Pickups"
BP_DIR = "/Game/Sunder/Blueprints"
GAME_MODE = BP_DIR + "/BP_SunderGameMode"
KINDS = ["spread", "laser", "power", "bomb", "shield", "life"]

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []


def log(msg):
    unreal.log("[SunderPickups] " + msg)


def step(label, fn, *args):
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:   # the editor's Python API differs a little between versions
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderPickups] {} failed: {}".format(label, exc))
        return None


def source_dir():
    if SOURCE_DIR:
        return SOURCE_DIR
    here = os.path.dirname(os.path.abspath(__file__))
    return os.path.normpath(os.path.join(here, "..", "Content", "Pickups"))


def mesh_name(kind):
    return "SM_Pickup_" + kind.capitalize()


def import_mesh(kind):
    name = mesh_name(kind)
    full = "{}/{}".format(MESH_DIR, name)
    source = os.path.join(source_dir(), name + ".fbx")
    if not os.path.isfile(source):
        raise RuntimeError("model not found: {} (run blender/pickups.py <dir> 0 --fbx)".format(source))
    task = unreal.AssetImportTask()
    task.set_editor_property("filename", source)
    task.set_editor_property("destination_path", MESH_DIR)
    task.set_editor_property("destination_name", name)
    task.set_editor_property("automated", True)
    task.set_editor_property("replace_existing", True)
    task.set_editor_property("save", True)
    try:
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
        task.set_editor_property("options", options)
    except Exception as exc:   # the Interchange importer may ignore these; the default import is still fine
        log("FBX options not applied ({}); using the importer's defaults".format(exc))
    TOOLS.import_asset_tasks([task])
    if not EAL.does_asset_exist(full):
        raise RuntimeError("import produced no " + full)
    return EAL.load_asset(full)


def build_pickup_bp(meshes):
    full = BP_DIR + "/BP_SunderPickup"
    if EAL.does_asset_exist(full):
        bp = EAL.load_asset(full)
    else:
        factory = unreal.BlueprintFactory()
        factory.set_editor_property("parent_class", unreal.SunderPickup)
        bp = TOOLS.create_asset("BP_SunderPickup", BP_DIR, unreal.Blueprint, factory)
        if bp is None:
            raise RuntimeError("could not create " + full)
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    cls = EAL.load_blueprint_class(full)
    cdo = unreal.get_default_object(cls)
    kind_meshes = {getattr(unreal.SunderPickupKind, kind.upper()): mesh for kind, mesh in meshes.items() if mesh is not None}
    cdo.set_editor_property("kind_meshes", kind_meshes)
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    EAL.save_loaded_asset(bp)
    return cls


def use_in_game_mode(pickup_class):
    if not EAL.does_asset_exist(GAME_MODE):
        raise RuntimeError(GAME_MODE + " not found; run create_arena_level.py first")
    bp = EAL.load_asset(GAME_MODE)
    unreal.get_default_object(EAL.load_blueprint_class(GAME_MODE)).set_editor_property("pickup_class", pickup_class)
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    EAL.save_loaded_asset(bp)


def main():
    if not hasattr(unreal, "SunderPickup"):
        unreal.log_error("[SunderPickups] C++ types not found: SunderPickup. Compile unreal/Source first.")
        return
    EAL.make_directory(MESH_DIR)
    meshes = {kind: step("import " + mesh_name(kind), import_mesh, kind) for kind in KINDS}
    pickup = None
    if any(m is not None for m in meshes.values()):
        pickup = step("BP_SunderPickup: each kind's gem", build_pickup_bp, meshes)
    if pickup is not None:
        step("BP_SunderGameMode → Pickup Class = BP_SunderPickup", use_in_game_mode, pickup)

    MANUAL.extend([
        "Play once: each emblem should read upright from the camera. If they read sideways, change Mesh Rotation (yaw) "
        "on BP_SunderPickup (default 90, the same turn the ships and Keepers use)",
        "The gems' glow imports as plain colour: give the 'gem' and 'emblem' material slots an emissive tint for bloom",
    ])
    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)


main()
