"""SUNDER: Ascension II — make the twelve Keeper boss Blueprints.

Run inside the Unreal Editor (Tools → Execute Python Script…) AFTER the C++ in unreal/Source is compiled and
create_enemies_and_waves.py has run.

Does:
  1. imports the Keeper models from unreal/Content/Keepers/*.fbx (exported from blender/keepers.py --fbx, one mesh each)
     into /Game/Sunder/Keepers/Meshes as SM_Keeper_<Name>;
  2. makes BP_KeeperShot (1 damage) and BP_KeeperShotHeavy (2 damage: the web game's battle-math rule that Keeper
     shots hit for 2 from Hour 7);
  3. makes BP_Keeper_<Name> for all twelve Hours with the web game's numbers: hull = boss_health × 1.3 rounded to tens
     (× 10 for Unreal damage), score, attack patterns, fire rate, and bullet / move speed (× 5: web px to Unreal units);
     Apep gets its open-jaws final form;
  4. makes DA_KeeperGauntlet (all twelve Keepers in order) and adds a Wepwawet wave to the end of DA_TestWaves.

Set USE_GAUNTLET_IN_ARENA = True to point the arena's wave director at the gauntlet instead.
Safe to run again. Untested until its first run.
"""
import os

import unreal

USE_GAUNTLET_IN_ARENA = False
KEEPER_FBX_DIR = None   # None = ../Content/Keepers next to this script; set a path if you moved the script

MESH_DIR = "/Game/Sunder/Keepers/Meshes"
KEEPER_DIR = "/Game/Sunder/Blueprints/Keepers"
SHOT_DIR = "/Game/Sunder/Blueprints"
WAVE_DIR = "/Game/Sunder/Waves"
MAP_PATH = "/Game/Sunder/Maps/L_SunderArena"

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []

# The web game's twelve Keepers (web/game.html STAGES and BOSS_LINES): hour, id, name, health, points, patterns,
# fire rate (s), bullet speed (px/s), move speed (px/s), taunt.
KEEPERS = [
    (1, "wepwawet", "Wepwawet, Opener of Ways", 180, 4000, ["AIMED_VOLLEY"], 1.3, 190, 60,
     '"I open every way. I close this one — on you."'),
    (2, "sobek", "Sobek Reborn", 220, 4700, ["SPREAD_FAN", "AIMED_VOLLEY"], 1.19, 205, 75,
     '"The flood remembers no heroes, little sun."'),
    (3, "umbra", "UMBRA, the Shadow Heir", 270, 5500, ["HORIZONTAL_SWEEP", "SPREAD_FAN"], 1.08, 219, 94,
     '"Every move you make, I made first."'),
    (4, "nun", "Nun, the Primeval Deep", 310, 6200, ["RADIAL_BURST", "HORIZONTAL_SWEEP"], 0.98, 232, 108,
     '"Before the world, there was me. After it, me again."'),
    (5, "sokar", "Sokar, Hawk of the Hidden Sand", 350, 6900, ["CROSS_RING", "AIMED_VOLLEY"], 0.91, 239, 101,
     '"The sand sees you. The hawk is already falling."'),
    (6, "seraphs", "The Fire Lake Seraphs", 410, 8000, ["SPIRAL", "RADIAL_BURST"], 0.87, 246, 94,
     '"Burn, and be weighed by the fire."'),
    (7, "umbra_coiled", "UMBRA, the Shadow Heir", 470, 9000, ["SPIRAL", "SPREAD_FAN", "CROSS_RING"], 0.8, 257, 101,
     '"You still don\'t know what I am, do you, Heir?"'),
    (8, "hittite", "The Hittite Engine", 530, 10200, ["WALL_BARRAGE", "CROSS_RING"], 0.69, 271, 118,
     '"You broke the Nine. You only bent me."'),
    (9, "ammit", "Ammit, Devourer of Hearts", 600, 11600, ["DUAL_SPIRAL", "RADIAL_BURST"], 0.62, 282, 104,
     '"Your heart is heavy, Heir. I can smell it."'),
    (10, "overlord_echo", "The Overlord's Echo", 690, 13600, ["DUAL_SPIRAL", "WALL_BARRAGE", "RADIAL_BURST"], 0.55, 293, 116,
     '"I DROWNED ATLANTIS. I WILL OUTLIVE THE SUN."'),
    (11, "umbra_unmasked", "UMBRA, the Shadow Heir", 810, 19100, ["DUAL_SPIRAL", "WALL_BARRAGE", "CROSS_RING", "SPIRAL"], 0.47, 305, 133,
     '"Take off the mask? Heir — this IS your face."'),
    (12, "apep", "APEP, THE SERPENT OF UNMAKING", 1100, 40000, ["DUAL_SPIRAL", "WALL_BARRAGE", "CROSS_RING", "RADIAL_BURST", "SPIRAL"], 0.4, 320, 140,
     '"I WAS HERE BEFORE THE FIRST DAWN. I WILL EAT THE LAST."'),
]
WEB_TO_UNREAL = 5.0       # the web canvas is 480 px across; the arena camera shows 2400 units
DAMAGE_SCALE = 10.0       # the ship's shots do 10 (the web game's bullets do 1)


def log(msg):
    unreal.log("[SunderKeepers] " + msg)


def step(label, fn, *args):
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderKeepers] {} failed: {}".format(label, exc))
        return None


def require_cpp():
    names = ("SunderKeeper", "SunderBossPattern", "SunderProjectile", "SunderWaveSet", "SunderWave")
    missing = [n for n in names if not hasattr(unreal, n)]
    if missing:
        raise RuntimeError("C++ types not found: {}. Compile unreal/Source (with SunderKeeper) first.".format(", ".join(missing)))


def mesh_name(kid):
    return "SM_Keeper_" + "".join(part.capitalize() for part in kid.split("_"))


def bp_name(kid):
    return "BP_Keeper_" + "".join(part.capitalize() for part in kid.split("_"))


def fbx_dir():
    if KEEPER_FBX_DIR:
        return KEEPER_FBX_DIR
    here = os.path.dirname(os.path.abspath(__file__))
    return os.path.normpath(os.path.join(here, "..", "Content", "Keepers"))


# ------------------------------------------------------------------ 1. models
def import_mesh(kid):
    name = mesh_name(kid)
    full = "{}/{}".format(MESH_DIR, name)
    source = os.path.join(fbx_dir(), name + ".fbx")
    if not os.path.isfile(source):
        raise RuntimeError("model not found: " + source)
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


# ------------------------------------------------------------------ 2–3. Blueprints
def blueprint(name, path, parent, defaults):
    full = "{}/{}".format(path, name)
    if EAL.does_asset_exist(full):
        bp = EAL.load_asset(full)
    else:
        factory = unreal.BlueprintFactory()
        factory.set_editor_property("parent_class", parent)
        bp = TOOLS.create_asset(name, path, unreal.Blueprint, factory)
        if bp is None:
            raise RuntimeError("could not create " + full)
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    cls = EAL.load_blueprint_class(full)
    cdo = unreal.get_default_object(cls)
    for prop, value in defaults.items():
        cdo.set_editor_property(prop, value)
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    EAL.save_loaded_asset(bp)
    log("ready " + full)
    return cls


def build_shots():
    light = blueprint("BP_KeeperShot", SHOT_DIR, unreal.SunderProjectile, {
        "damage": 1.0, "speed": 950.0, "max_lifetime": 4.0, "plasma_color": unreal.LinearColor(3.0, 2.0, 0.5, 1.0)})
    heavy = blueprint("BP_KeeperShotHeavy", SHOT_DIR, unreal.SunderProjectile, {
        "damage": 2.0, "speed": 950.0, "max_lifetime": 4.0, "plasma_color": unreal.LinearColor(4.0, 0.3, 0.9, 1.0)})
    return light, heavy


def hull(boss_health):
    """Battle math: boss hull = boss_health × 1.3, rounded to tens (half up, like Math.round), × DAMAGE_SCALE."""
    return int(boss_health * 1.3 / 10.0 + 0.5) * 10 * DAMAGE_SCALE


def build_keeper(entry, meshes, shots):
    hour, kid, name, health, points, patterns, fire, bullet, move, taunt = entry
    defaults = {
        "keeper_name": name, "taunt": taunt, "hour": hour,
        "max_health": float(hull(health)), "score_value": points,
        "patterns": [getattr(unreal.SunderBossPattern, p) for p in patterns],
        "fire_interval": fire, "bullet_speed": bullet * WEB_TO_UNREAL, "strafe_speed": move * WEB_TO_UNREAL,
        "shot_class": shots[1] if hour >= 7 else shots[0],
    }
    if meshes.get(kid) is not None:
        defaults["body_mesh"] = meshes[kid]
    else:
        MANUAL.append("{}: set Body Mesh (its model didn't import)".format(bp_name(kid)))
    if kid == "apep" and meshes.get("apep_p3") is not None:
        defaults["phase_three_mesh"] = meshes["apep_p3"]
        defaults["death_color"] = unreal.LinearColor(1.6, 0.5, 4.0, 1.0)
    return blueprint(bp_name(kid), KEEPER_DIR, unreal.SunderKeeper, defaults)


# ------------------------------------------------------------------ 4. waves
def keeper_wave(label, keeper_class):
    w = unreal.SunderWave()
    w.set_editor_property("wave_name", label)
    w.set_editor_property("groups", [])
    w.set_editor_property("keeper", keeper_class)
    w.set_editor_property("wait_for_clear", True)
    w.set_editor_property("max_duration", 300.0)
    w.set_editor_property("break_after", 3.0)
    return w


def build_gauntlet(keeper_classes):
    full = WAVE_DIR + "/DA_KeeperGauntlet"
    if EAL.does_asset_exist(full):
        data = EAL.load_asset(full)
    else:
        factory = unreal.DataAssetFactory()
        factory.set_editor_property("data_asset_class", unreal.SunderWaveSet)
        data = TOOLS.create_asset("DA_KeeperGauntlet", WAVE_DIR, unreal.SunderWaveSet, factory)
        if data is None:
            raise RuntimeError("could not create " + full)
    waves = [keeper_wave("HOUR {}".format(e[0]), keeper_classes[e[1]]) for e in KEEPERS if e[1] in keeper_classes]
    data.set_editor_property("waves", waves)
    data.set_editor_property("loop", False)
    EAL.save_loaded_asset(data)
    return data


def add_keeper_to_test_waves(wepwawet):
    full = WAVE_DIR + "/DA_TestWaves"
    if not EAL.does_asset_exist(full):
        raise RuntimeError(full + " not found; run create_enemies_and_waves.py first")
    data = EAL.load_asset(full)
    waves = list(data.get_editor_property("waves"))
    label = "KEEPER  ·  WEPWAWET"
    if any(w.get_editor_property("wave_name") == label for w in waves):
        log("DA_TestWaves already ends with Wepwawet")
        return data
    waves.append(keeper_wave(label, wepwawet))
    data.set_editor_property("waves", waves)
    EAL.save_loaded_asset(data)
    return data


def use_gauntlet(gauntlet):
    levels = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
    actors = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
    if not levels.load_level(MAP_PATH):
        raise RuntimeError("could not open " + MAP_PATH)
    directors = [a for a in actors.get_all_level_actors() if isinstance(a, unreal.SunderWaveDirector)]
    if not directors:
        raise RuntimeError("no SunderWaveDirector in the arena; run create_enemies_and_waves.py first")
    directors[0].set_editor_property("wave_set", gauntlet)
    levels.save_current_level()


def main():
    try:
        require_cpp()
    except RuntimeError as exc:
        unreal.log_error("[SunderKeepers] " + str(exc))
        return
    for path in (MESH_DIR, KEEPER_DIR, WAVE_DIR):
        EAL.make_directory(path)

    meshes = {}
    for kid in [e[1] for e in KEEPERS] + ["apep_p3"]:
        meshes[kid] = step("import " + mesh_name(kid), import_mesh, kid)

    shots = step("BP_KeeperShot + BP_KeeperShotHeavy", build_shots)
    if shots is None:
        unreal.log_error("[SunderKeepers] the Keeper shots could not be made; stopping")
        return
    classes = {}
    for entry in KEEPERS:
        cls = step(bp_name(entry[1]), build_keeper, entry, meshes, shots)
        if cls is not None:
            classes[entry[1]] = cls

    gauntlet = step("DA_KeeperGauntlet (12 Keepers)", build_gauntlet, classes)
    if "wepwawet" in classes:
        step("Wepwawet wave at the end of DA_TestWaves", add_keeper_to_test_waves, classes["wepwawet"])
    if USE_GAUNTLET_IN_ARENA and gauntlet is not None:
        step("arena wave director → DA_KeeperGauntlet", use_gauntlet, gauntlet)

    MANUAL.extend([
        "Check one Keeper in the arena faces down the screen; if a model is turned, change its Body Rotation (yaw) "
        "on the Keeper Blueprint (default yaw 90 assumes Unreal's usual Blender FBX axes)",
        "Keeper materials import with their base colours only; add emissive (crystal, cores, eyes) for the glow",
    ])
    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)
    log("Play L_SunderArena: Wepwawet arrives after the five test waves (or set USE_GAUNTLET_IN_ARENA for all twelve).")


main()
