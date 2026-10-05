"""SUNDER: Ascension II — make the enemy Blueprints, a test wave set, and put a wave director in the arena.

Run inside the Unreal Editor (Tools → Execute Python Script…) AFTER the C++ in unreal/Source is compiled and
create_arena_level.py has made L_SunderArena.

Creates under /Game/Sunder:
  Blueprints/BP_EnemyShot          enemy plasma (slow, 1 damage, hits only the player's ship)
  Blueprints/Enemies/BP_Enemy_Scout     weaves down, aimed single shots          (web game: "weave")
  Blueprints/Enemies/BP_Enemy_Diver     drifts in, then dives at you, no guns    ("dive")
  Blueprints/Enemies/BP_Enemy_Skimmer   zigzags, aimed 3-shot bursts             ("zigzag")
  Blueprints/Enemies/BP_Enemy_Gunship   holds the top band and strafes, 5-way spread ("formation")
  Blueprints/Enemies/BP_Enemy_Bomber    slow and heavy, radial rings             (the "bomber" waves)
  Waves/DA_TestWaves               five waves that build up, then loop tougher
and in L_SunderArena: a SunderWaveDirector using DA_TestWaves (the three target dummies are removed: the waves
replace them and they would stop the beam).

Press Play: waves arrive, the HUD shows score, lives, hull and each wave's name; lose every life for DAWN DENIED and a
restart. Safe to run again (assets are updated; the director is reused). Untested until its first run.
"""
import unreal

BP_DIR = "/Game/Sunder/Blueprints"
ENEMY_DIR = BP_DIR + "/Enemies"
WAVE_DIR = "/Game/Sunder/Waves"
MAP_PATH = "/Game/Sunder/Maps/L_SunderArena"

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []


def log(msg):
    unreal.log("[SunderWaves] " + msg)


def step(label, fn, *args):
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderWaves] {} failed: {}".format(label, exc))
        return None


def require_cpp():
    names = ("SunderEnemy", "SunderProjectile", "SunderWaveDirector", "SunderWaveSet", "SunderWave",
             "SunderSpawnGroup", "SunderMovePattern", "SunderFirePattern", "SunderFormation")
    missing = [n for n in names if not hasattr(unreal, n)]
    if missing:
        raise RuntimeError("C++ types not found: {}. Compile unreal/Source into your game module first, "
                           "then run this again.".format(", ".join(missing)))


def blueprint(name, path, parent, defaults):
    full = "{}/{}".format(path, name)
    if EAL.does_asset_exist(full):
        bp = EAL.load_asset(full)
        log("updating " + full)
    else:
        factory = unreal.BlueprintFactory()
        factory.set_editor_property("parent_class", parent)
        bp = TOOLS.create_asset(name, path, unreal.Blueprint, factory)
        if bp is None:
            raise RuntimeError("could not create " + full)
        log("created " + full)
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    cls = EAL.load_blueprint_class(full)
    cdo = unreal.get_default_object(cls)
    for prop, value in defaults.items():
        cdo.set_editor_property(prop, value)
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    EAL.save_loaded_asset(bp)
    return cls


def shape(name):
    return EAL.load_asset("/Engine/BasicShapes/" + name)


def color(r, g, b):
    return unreal.LinearColor(r, g, b, 1.0)


def build_enemy_shot():
    return blueprint("BP_EnemyShot", BP_DIR, unreal.SunderProjectile, {
        "damage": 1.0, "speed": 520.0, "max_lifetime": 5.0,
        "plasma_color": color(4.0, 0.35, 1.2),                      # hot magenta-red, distinct from the player's
    })


def build_enemies(shot):
    move, fire = unreal.SunderMovePattern, unreal.SunderFirePattern
    violet, bronze, teal, crimson = color(0.35, 0.08, 0.55), color(0.55, 0.32, 0.12), color(0.05, 0.35, 0.35), color(0.55, 0.06, 0.12)
    specs = {
        "BP_Enemy_Scout": {
            "body_mesh": shape("Cone"), "body_scale": unreal.Vector(0.55, 0.55, 0.55), "body_color": violet,
            "max_health": 20.0, "score_value": 100, "move_pattern": move.WEAVE, "speed": 260.0,
            "weave_amplitude": 160.0, "weave_frequency": 0.55,
            "fire_pattern": fire.AIMED, "shot_count": 1, "fire_interval": 1.8, "first_shot_delay": 1.2},
        "BP_Enemy_Diver": {
            "body_mesh": shape("Cone"), "body_scale": unreal.Vector(0.45, 0.45, 0.7), "body_color": crimson,
            "max_health": 15.0, "score_value": 120, "move_pattern": move.DIVE, "speed": 480.0, "dive_delay": 0.9,
            "fire_pattern": fire.NONE},
        "BP_Enemy_Skimmer": {
            "body_mesh": shape("Sphere"), "body_scale": unreal.Vector(0.55, 0.55, 0.3), "body_color": teal,
            "max_health": 25.0, "score_value": 150, "move_pattern": move.ZIGZAG, "speed": 340.0, "zigzag_interval": 0.55,
            "fire_pattern": fire.AIMED, "shot_count": 3, "fire_interval": 2.2, "first_shot_delay": 1.0},
        "BP_Enemy_Gunship": {
            "body_mesh": shape("Cube"), "body_scale": unreal.Vector(0.9, 1.6, 0.35),
            "body_rotation": unreal.Rotator(0.0, 0.0, 0.0), "body_color": bronze,
            "max_health": 120.0, "score_value": 400, "move_pattern": move.STRAFE, "speed": 200.0,
            "strafe_hold_depth": 0.22, "strafe_time": 7.0, "weave_frequency": 0.18, "weave_amplitude": 250.0,
            "fire_pattern": fire.SPREAD, "shot_count": 5, "spread_angle": 60.0, "fire_interval": 1.3, "first_shot_delay": 1.5},
        "BP_Enemy_Bomber": {
            "body_mesh": shape("Cylinder"), "body_scale": unreal.Vector(1.3, 1.3, 0.35),
            "body_rotation": unreal.Rotator(0.0, 0.0, 0.0), "body_color": color(0.12, 0.10, 0.16),
            "max_health": 220.0, "score_value": 600, "move_pattern": move.STRAIGHT, "speed": 95.0,
            "drop_chance_bonus": 0.12,                        # the web game's bombers drop more (+0.16 vs +0.04)
            "fire_pattern": fire.RADIAL, "shot_count": 12, "fire_interval": 2.0, "first_shot_delay": 1.0},
    }
    classes = {}
    for name, defaults in specs.items():
        if shot is not None and defaults["fire_pattern"] != fire.NONE:
            defaults["shot_class"] = shot
        cls = step(name, blueprint, name, ENEMY_DIR, unreal.SunderEnemy, defaults)
        if cls is not None:
            classes[name] = cls
    return classes


# ------------------------------------------------------------------ waves
def group(cls, count, formation, delay=0.0, interval=0.4, lane=0.0, spacing=160.0):
    g = unreal.SunderSpawnGroup()
    g.set_editor_property("enemy_class", cls)
    g.set_editor_property("count", count)
    g.set_editor_property("formation", formation)
    g.set_editor_property("delay", delay)
    g.set_editor_property("interval", interval)
    g.set_editor_property("lane", lane)
    g.set_editor_property("spacing", spacing)
    return g


def wave(name, groups, wait=True, max_duration=30.0, rest=2.0):
    w = unreal.SunderWave()
    w.set_editor_property("wave_name", name)
    w.set_editor_property("groups", groups)
    w.set_editor_property("wait_for_clear", wait)              # UE Python drops the b prefix of bools
    w.set_editor_property("max_duration", max_duration)
    w.set_editor_property("break_after", rest)
    return w


def build_waves(enemies):
    need = ("BP_Enemy_Scout", "BP_Enemy_Diver", "BP_Enemy_Skimmer", "BP_Enemy_Gunship", "BP_Enemy_Bomber")
    missing = [n for n in need if n not in enemies]
    if missing:
        raise RuntimeError("enemy Blueprints missing: " + ", ".join(missing))
    scout, diver, skimmer, gunship, bomber = (enemies[n] for n in need)
    F = unreal.SunderFormation
    waves = [
        wave("SCOUT PATROL", [group(scout, 5, F.COLUMN, 0.0, 0.55, -0.5),
                              group(scout, 5, F.COLUMN, 1.5, 0.55, 0.5)]),
        wave("DIVE FLIGHT", [group(diver, 7, F.V, 0.0, 0.06, 0.0, 140.0),
                             group(diver, 6, F.RANDOM, 3.0, 0.6)]),
        wave("GUNLINE", [group(gunship, 2, F.LINE, 0.0, 0.0, 0.0, 1000.0),
                         group(scout, 8, F.SIDES, 2.0, 0.45)], max_duration=26.0),
        wave("SKIMMER SWARM", [group(skimmer, 10, F.RANDOM, 0.0, 0.35),
                               group(diver, 5, F.LINE, 4.0, 0.0, 0.0, 220.0)]),
        wave("THE BOMBER", [group(bomber, 1, F.COLUMN, 0.0, 0.0, 0.0),
                            group(gunship, 2, F.LINE, 3.0, 0.0, 0.0, 1300.0),
                            group(scout, 8, F.COLUMN, 6.0, 0.3, 0.0)], max_duration=40.0, rest=3.0),
    ]
    full = WAVE_DIR + "/DA_TestWaves"
    if EAL.does_asset_exist(full):
        data = EAL.load_asset(full)
        log("updating " + full)
    else:
        factory = unreal.DataAssetFactory()
        factory.set_editor_property("data_asset_class", unreal.SunderWaveSet)
        data = TOOLS.create_asset("DA_TestWaves", WAVE_DIR, unreal.SunderWaveSet, factory)
        if data is None:
            raise RuntimeError("could not create " + full)
        log("created " + full)
    data.set_editor_property("waves", waves)
    data.set_editor_property("loop", True)
    EAL.save_loaded_asset(data)
    return data


# ------------------------------------------------------------------ the arena
def place_director(wave_set):
    levels = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
    actors = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
    if not EAL.does_asset_exist(MAP_PATH):
        raise RuntimeError(MAP_PATH + " not found; run create_arena_level.py first")
    if not levels.load_level(MAP_PATH):
        raise RuntimeError("could not open " + MAP_PATH)

    everything = actors.get_all_level_actors()
    dummies = [a for a in everything if isinstance(a, unreal.SunderTargetDummy)]
    for dummy in dummies:
        actors.destroy_actor(dummy)
    if dummies:
        log("removed {} target dummies (the waves replace them)".format(len(dummies)))

    directors = [a for a in everything if isinstance(a, unreal.SunderWaveDirector)]
    director = directors[0] if directors else actors.spawn_actor_from_class(
        unreal.SunderWaveDirector, unreal.Vector(0.0, 0.0, 0.0), unreal.Rotator(0.0, 0.0, 0.0))
    if director is None:
        raise RuntimeError("could not place a SunderWaveDirector")
    director.set_actor_label("WaveDirector")
    director.set_editor_property("wave_set", wave_set)
    levels.save_current_level()


def main():
    try:
        require_cpp()
    except RuntimeError as exc:
        unreal.log_error("[SunderWaves] " + str(exc))
        return
    for path in (BP_DIR, ENEMY_DIR, WAVE_DIR):
        EAL.make_directory(path)

    shot = step("BP_EnemyShot", build_enemy_shot)
    enemies = build_enemies(shot)
    waves = step("DA_TestWaves (5 waves, looping)", build_waves, enemies)
    if waves is not None:
        step("WaveDirector in L_SunderArena", place_director, waves)
    else:
        MANUAL.append("L_SunderArena: place a SunderWaveDirector at the ship's height and set Wave Set = DA_TestWaves")

    MANUAL.extend([
        "Enemy Blueprints: swap the engine shapes for real enemy meshes and materials when they exist",
        "BP_EnemyShot: give its Trail component a Niagara system (enemy plasma) when one exists",
    ])
    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)
    log("Open L_SunderArena and press Play: waves start after 1.5 s.")


main()
