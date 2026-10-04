"""SUNDER: Ascension II — make the ship Blueprints and the test arena level.

Run inside the Unreal Editor (Tools → Execute Python Script…) AFTER:
  1. the C++ in unreal/Source is compiled into your game module (this script needs its classes), and
  2. create_weapon_fx_assets.py has run (for NS_Laser_Beam; the level still builds without it).

Creates:
  /Game/Sunder/Blueprints/BP_PlasmaShot        child of SunderProjectile (the pooled plasma shot)
  /Game/Sunder/Blueprints/BP_SunderShip        child of SunderShipPawn, beam = NS_Laser_Beam, shots = BP_PlasmaShot
  /Game/Sunder/Blueprints/BP_SunderGameMode    child of SunderGameMode, default pawn = BP_SunderShip
  /Game/Sunder/Maps/L_SunderArena              top-down arena: orthographic camera looking straight down (+X up the
                                               screen), dark floor, light, player start low on the screen, three
                                               drifting target dummies, bloom; game mode override = BP_SunderGameMode

Press Play in L_SunderArena:  W A S D / left stick move · Space / right trigger beam · J / left mouse / A shoot.
Safe to run again (existing Blueprints are updated; the level is rebuilt only if it doesn't exist yet).
Written without an Unreal install, so untested until its first run.
"""
import unreal

BP_DIR = "/Game/Sunder/Blueprints"
MAP_DIR = "/Game/Sunder/Maps"
MAP_PATH = MAP_DIR + "/L_SunderArena"
BEAM_SYSTEM = "/Game/FX/Weapons/Systems/NS_Laser_Beam"

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []


def log(msg):
    unreal.log("[SunderArena] " + msg)


def step(label, fn, *args):
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderArena] {} failed: {}".format(label, exc))
        return None


def require_cpp():
    missing = [name for name in ("SunderShipPawn", "SunderProjectile", "SunderGameMode", "SunderTargetDummy")
               if not hasattr(unreal, name)]
    if missing:
        raise RuntimeError("C++ classes not found: {}. Compile unreal/Source into your game module first "
                           "(see unreal/Source/README.md), then run this again.".format(", ".join(missing)))


# ------------------------------------------------------------------ Blueprints
def blueprint(name, parent):
    """Create (or load) a Blueprint child of a C++ class; return (blueprint asset, its class, its defaults object)."""
    full = "{}/{}".format(BP_DIR, name)
    if EAL.does_asset_exist(full):
        bp = EAL.load_asset(full)
        log("updating " + full)
    else:
        factory = unreal.BlueprintFactory()
        factory.set_editor_property("parent_class", parent)
        bp = TOOLS.create_asset(name, BP_DIR, unreal.Blueprint, factory)
        if bp is None:
            raise RuntimeError("could not create " + full)
        log("created " + full)
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    bp_class = EAL.load_blueprint_class(full)
    return bp, bp_class, unreal.get_default_object(bp_class)


def finish(bp):
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    EAL.save_loaded_asset(bp)


def build_shot():
    bp, cls, cdo = blueprint("BP_PlasmaShot", unreal.SunderProjectile)
    cdo.set_editor_property("damage", 10.0)
    cdo.set_editor_property("speed", 2200.0)
    finish(bp)
    return cls


def build_ship(shot_class):
    bp, cls, cdo = blueprint("BP_SunderShip", unreal.SunderShipPawn)
    if shot_class is not None:
        cdo.set_editor_property("projectile_class", shot_class)
    if EAL.does_asset_exist(BEAM_SYSTEM):
        cdo.set_editor_property("beam_system", EAL.load_asset(BEAM_SYSTEM))
    else:
        MANUAL.append("BP_SunderShip: set Beam System = NS_Laser_Beam (run create_weapon_fx_assets.py first)")
    finish(bp)
    return cls


def build_game_mode(ship_class):
    bp, cls, cdo = blueprint("BP_SunderGameMode", unreal.SunderGameMode)
    if ship_class is not None:
        cdo.set_editor_property("default_pawn_class", ship_class)
    finish(bp)
    return cls


# ------------------------------------------------------------------ the level
def spawn(cls, location, rotation=None, label=None):
    actors = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
    actor = actors.spawn_actor_from_class(cls, location, rotation or unreal.Rotator(0.0, 0.0, 0.0))
    if actor is None:
        raise RuntimeError("could not spawn {}".format(cls))
    if label:
        actor.set_actor_label(label)
    return actor


def build_level(game_mode_class):
    levels = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
    if EAL.does_asset_exist(MAP_PATH):
        log(MAP_PATH + " already exists; leaving it as it is (delete it to rebuild)")
        return
    if not levels.new_level(MAP_PATH):
        raise RuntimeError("could not create " + MAP_PATH)

    # Orthographic camera straight down: with pitch -90 its up is world +X (up the screen) and its right is +Y.
    camera = spawn(unreal.CameraActor, unreal.Vector(0.0, 0.0, 2000.0), unreal.Rotator(0.0, -90.0, 0.0), "ArenaCamera")
    lens = camera.get_editor_property("camera_component")
    lens.set_editor_property("projection_mode", unreal.CameraProjectionMode.ORTHOGRAPHIC)
    lens.set_editor_property("ortho_width", 2400.0)
    lens.set_editor_property("constrain_aspect_ratio", False)
    camera.set_editor_property("auto_activate_for_player", unreal.AutoReceiveInput.PLAYER0)

    floor = spawn(unreal.StaticMeshActor, unreal.Vector(0.0, 0.0, -200.0), None, "ArenaFloor")
    floor_mesh = floor.get_editor_property("static_mesh_component")
    floor_mesh.set_static_mesh(EAL.load_asset("/Engine/BasicShapes/Plane"))
    floor.set_actor_scale3d(unreal.Vector(16.0, 28.0, 1.0))          # a little wider than the camera sees
    dark = "/Engine/EngineMaterials/CubeMaterial"
    if EAL.does_asset_exist(dark):
        floor_mesh.set_material(0, EAL.load_asset(dark))

    spawn(unreal.DirectionalLight, unreal.Vector(0.0, 0.0, 800.0), unreal.Rotator(0.0, -55.0, 30.0), "KeyLight")
    spawn(unreal.SkyLight, unreal.Vector(0.0, 0.0, 600.0), None, "SkyLight")
    spawn(unreal.PlayerStart, unreal.Vector(-450.0, 0.0, 0.0), None, "PlayerStart")   # low on the screen

    for i, y in enumerate((-500.0, 0.0, 500.0)):
        dummy = spawn(unreal.SunderTargetDummy, unreal.Vector(350.0 + 120.0 * (i % 2), y, 0.0), None,
                      "TargetDummy{}".format(i + 1))
        dummy.set_actor_scale3d(unreal.Vector(1.2, 1.2, 0.4))

    step("Post process (bloom, fixed exposure)", build_post_process)

    world = unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem).get_editor_world()
    if game_mode_class is not None:
        world.get_world_settings().set_editor_property("default_game_mode", game_mode_class)
    else:
        MANUAL.append("L_SunderArena → World Settings: GameMode Override = BP_SunderGameMode")
    levels.save_current_level()


def build_post_process():
    volume = spawn(unreal.PostProcessVolume, unreal.Vector(0.0, 0.0, 0.0), None, "ArenaPostProcess")
    volume.set_editor_property("unbound", True)
    settings = volume.get_editor_property("settings")
    for prop, value in (("override_bloom_intensity", True), ("bloom_intensity", 1.2),
                        ("override_auto_exposure_min_brightness", True), ("auto_exposure_min_brightness", 1.0),
                        ("override_auto_exposure_max_brightness", True), ("auto_exposure_max_brightness", 1.0)):
        settings.set_editor_property(prop, value)
    volume.set_editor_property("settings", settings)


def main():
    try:
        require_cpp()
    except RuntimeError as exc:
        unreal.log_error("[SunderArena] " + str(exc))
        return
    EAL.make_directory(BP_DIR)
    EAL.make_directory(MAP_DIR)

    shot = step("BP_PlasmaShot", build_shot)
    ship = step("BP_SunderShip", build_ship, shot)
    mode = step("BP_SunderGameMode", build_game_mode, ship)
    step("L_SunderArena", build_level, mode)

    MANUAL.extend([
        "Project Settings → Maps & Modes: Editor Startup Map and Game Default Map = L_SunderArena (optional)",
        "BP_SunderShip: swap the placeholder cone for the ship mesh when it is imported",
        "BP_PlasmaShot: set the Trail component's Niagara system when a shot trail exists",
    ])
    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)
    log("Open L_SunderArena and press Play: WASD move, Space beam, J shoot.")


main()
