"""SUNDER: Ascension II — the three ships' models, in place of the placeholder cone.

Run inside the Unreal Editor (Tools → Execute Python Script…) AFTER create_arena_level.py, with the C++ in unreal/Source
compiled (FSunderShipLoadout's Mesh fields).

Does:
  1. imports unreal/Content/Ships/SM_Ship_Sunborn|Scarab|Ibis.fbx (blender/ships.py --fbx: the same models as the
     hangar's sprites, one mesh each) into /Game/Sunder/Ships;
  2. sets each as the Mesh of its ship in BP_SunderGameMode's Ships, so the arena flies the hangar's choice as its own
     model: turned nose-up (Mesh Rotation), sized (Mesh Length × Body Scale), its guns at its nose. It also sets each
     ship's Accent (the web game's accent, for its form changes), since saving the Ships list here stores every field.

Safe to run again. Untested until its first run.
"""
import os

import unreal

SOURCE_DIR = None   # None = ../Content/Ships next to this script

MESH_DIR = "/Game/Sunder/Ships"
GAME_MODE = "/Game/Sunder/Blueprints/BP_SunderGameMode"
SHIPS = ["sunborn", "scarab", "ibis"]
# The web game's ship accents (web/game.html SHIPS accent), HDR: the colour its form changes burst in.
ACCENTS = {"sunborn": (0.92, 2.43, 3.5), "scarab": (3.5, 0.92, 0.12), "ibis": (1.82, 3.5, 2.43)}

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []


def log(msg):
    unreal.log("[SunderShips] " + msg)


def step(label, fn, *args):
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:   # the editor's Python API differs a little between versions
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderShips] {} failed: {}".format(label, exc))
        return None


def source_dir():
    if SOURCE_DIR:
        return SOURCE_DIR
    here = os.path.dirname(os.path.abspath(__file__))
    return os.path.normpath(os.path.join(here, "..", "Content", "Ships"))


def mesh_name(sid):
    return "SM_Ship_" + sid.capitalize()


def import_mesh(sid):
    name = mesh_name(sid)
    full = "{}/{}".format(MESH_DIR, name)
    source = os.path.join(source_dir(), name + ".fbx")
    if not os.path.isfile(source):
        raise RuntimeError("model not found: {} (run blender/ships.py <dir> 0 --fbx)".format(source))
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


def set_ship_meshes(meshes):
    if not EAL.does_asset_exist(GAME_MODE):
        raise RuntimeError(GAME_MODE + " not found; run create_arena_level.py first")
    bp = EAL.load_asset(GAME_MODE)
    cdo = unreal.get_default_object(EAL.load_blueprint_class(GAME_MODE))
    ships = list(cdo.get_editor_property("ships"))
    found = set()
    for i, ship in enumerate(ships):
        sid = str(ship.get_editor_property("id")).lower()
        if sid in ACCENTS:
            try:
                ship.set_editor_property("accent", unreal.LinearColor(*ACCENTS[sid], 1.0))
                ships[i] = ship
            except Exception as exc:   # C++ from before Accent: compile unreal/Source again
                MANUAL.append("{}: Accent not set ({})".format(sid, exc))
        if meshes.get(sid) is not None:
            ship.set_editor_property("mesh", meshes[sid])
            ships[i] = ship
            found.add(sid)
    cdo.set_editor_property("ships", ships)
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    EAL.save_loaded_asset(bp)
    for sid in SHIPS:
        if sid not in found:
            MANUAL.append("BP_SunderGameMode → Ships: no ship with Id '{}' to give {}".format(sid, mesh_name(sid)))


def main():
    if not hasattr(unreal, "SunderShipLoadout"):
        unreal.log_error("[SunderShips] C++ types not found: SunderShipLoadout. Compile unreal/Source first.")
        return
    EAL.make_directory(MESH_DIR)
    meshes = {sid: step("import " + mesh_name(sid), import_mesh, sid) for sid in SHIPS}
    if any(m is not None for m in meshes.values()):
        step("BP_SunderGameMode → Ships: each ship's model", set_ship_meshes, meshes)

    MANUAL.extend([
        "Play once: each ship should point up the screen. If one flies sideways or backwards, change its Mesh Rotation "
        "(yaw) in BP_SunderGameMode → Ships (default 90, the same turn the Keepers use)",
        "The engine and wing glow import as plain colours: give the 'glow' material slots an emissive material "
        "(e.g. a Mode 1 instance of M_FX_Additive) for the bloom",
    ])
    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)
    log("Play L_SunderTitle: the ship you pick in the hangar now flies as its own model.")


main()
