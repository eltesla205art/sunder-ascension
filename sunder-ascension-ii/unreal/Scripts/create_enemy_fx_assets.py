"""SUNDER: Ascension II — create the scriptable half of the enemy VFX (see ../ENEMY_VFX.md): the enemy shot trail and
the enemy explosion, and wire them up.

Run inside the Unreal Editor (Tools → Execute Python Script…) AFTER create_weapon_fx_assets.py (for the master
material) and create_enemies_and_waves.py (for BP_EnemyShot), with the C++ in unreal/Source compiled.

Creates under /Game/FX/Enemies:
  Materials/    MI_Enemy_Shot (round sprite, hot core), MI_Enemy_Flash, MI_Enemy_Spark, MI_Enemy_Ring (instances of
                M_FX_Additive)
  EffectTypes/  EFT_EnemyShot (never culled: a bullet's look must not vanish while it can still hit you),
                EFT_EnemyExplosion (at most 48 at once: a bomb can shoot down a screenful in one frame)
  Systems/      NS_Enemy_Shot, NS_Enemy_Explosion (pooled) — empty systems with their effect types; the emitters are
                built by hand

Then puts NS_Enemy_Shot on the Trail of BP_EnemyShot with its size (30) and the web game's violet as its colour, and
NS_Enemy_Explosion on the five enemy Blueprints as their Explosion FX, with each one's size (the bomber's is the web
game's big burst). In an Hour the explosion takes the Hour's colour (create_hour_waves.py sets it on each wave set).

Empty systems are safe: the shot keeps its placeholder bolt, and enemies burst in the shared plasma impacts, until
each system has an emitter; then they switch over by themselves, with no further wiring.

Safe to run again. Untested until its first run.
"""
import unreal

SHOT_BP = "/Game/Sunder/Blueprints/BP_EnemyShot"
SHOT_SIZE = 30.0                     # User.ShotSize: the web bullet is 12 px across, about 60 units with its glow
SHOT_COLOR = (1.3, 0.12, 2.7)        # User.ShotColor: the web game's violet #9B30D6, made bright for bloom

ENEMY_DIR = "/Game/Sunder/Blueprints/Enemies"
# Explosion FX per enemy: (User.Size, User.Big). Web: 14 sparks for a kill, 26 flung further for a bomber's.
EXPLOSIONS = {
    "BP_Enemy_Scout":   (40.0, False),
    "BP_Enemy_Diver":   (36.0, False),
    "BP_Enemy_Skimmer": (40.0, False),
    "BP_Enemy_Gunship": (64.0, False),
    "BP_Enemy_Bomber":  (80.0, True),
}
EXPLOSION_POOL = (48, 16)            # max pool size, pool prime size

ROOT = "/Game/FX/Enemies"
MAT_DIR = ROOT + "/Materials"
EFT_DIR = ROOT + "/EffectTypes"
SYS_DIR = ROOT + "/Systems"
MASTER = "/Game/FX/Weapons/Materials/M_FX_Additive"

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
MEL = unreal.MaterialEditingLibrary
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []


def log(msg):
    unreal.log("[SunderEnemyFX] " + msg)


def step(label, fn, *args):
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:   # the editor's Python API differs a little between versions
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderEnemyFX] {} failed: {}".format(label, exc))
        return None


def get_or_create(name, path, asset_class, factory):
    full = "{}/{}".format(path, name)
    if EAL.does_asset_exist(full):
        log("updating " + full)
        return EAL.load_asset(full)
    asset = TOOLS.create_asset(name, path, asset_class, factory)
    if asset is None:
        raise RuntimeError("could not create " + full)
    log("created " + full)
    return asset


# Mode: 0 ribbon, 1 round sprite, 2 ring (see create_weapon_fx_assets.py). Colour comes from Particle Color.
INSTANCES = {
    "MI_Enemy_Shot":  {"Mode": 1.0, "CoreSharpness": 4.0, "GlowSharpness": 1.4, "CoreBoost": 4.0},
    "MI_Enemy_Flash": {"Mode": 1.0, "CoreSharpness": 1.5, "GlowSharpness": 0.7, "CoreBoost": 3.0},   # soft, wide
    "MI_Enemy_Spark": {"Mode": 1.0, "CoreSharpness": 3.0, "GlowSharpness": 1.2, "CoreBoost": 3.0},
    "MI_Enemy_Ring":  {"Mode": 2.0, "CoreSharpness": 2.0, "GlowSharpness": 1.0, "CoreBoost": 3.0, "RingThickness": 0.12},
}


def build_instance(name, master):
    mi = get_or_create(name, MAT_DIR, unreal.MaterialInstanceConstant, unreal.MaterialInstanceConstantFactoryNew())
    MEL.set_material_instance_parent(mi, master)
    for param, value in INSTANCES[name].items():
        MEL.set_material_instance_scalar_parameter_value(mi, param, value)
    MEL.update_material_instance(mi)
    EAL.save_loaded_asset(mi)
    return mi


def build_effect_type(name, cull_reaction, max_instances):
    et = get_or_create(name, EFT_DIR, unreal.NiagaraEffectType, unreal.NiagaraEffectTypeFactoryNew())
    et.set_editor_property("cull_reaction", cull_reaction)
    et.set_editor_property("update_frequency", unreal.NiagaraScalabilityUpdateFrequency.CONTINUOUS)
    # max_instances 0 = no cap (and clears one set by hand)
    array = et.get_editor_property("system_scalability_settings")
    settings = list(array.get_editor_property("settings"))
    if max_instances or settings:
        if not settings:
            settings = [unreal.NiagaraSystemScalabilitySettings()]
        for entry in settings:
            entry.set_editor_property("cull_by_max_instance_count", bool(max_instances))
            if max_instances:
                entry.set_editor_property("max_instances", max_instances)
        array.set_editor_property("settings", settings)
        et.set_editor_property("system_scalability_settings", array)
    EAL.save_loaded_asset(et)
    return et


def build_system(name, effect_type, pool=None):
    system = get_or_create(name, SYS_DIR, unreal.NiagaraSystem, unreal.NiagaraSystemFactoryNew())
    if effect_type is not None:
        system.set_editor_property("effect_type", effect_type)
    if pool:
        for prop, value in zip(("max_pool_size", "pool_prime_size"), pool):
            try:
                system.set_editor_property(prop, value)
            except Exception as exc:
                MANUAL.append("{}: set {} = {} in System Properties  ({})".format(name, prop, value, exc))
    EAL.save_loaded_asset(system)
    return system


def wire_shot(trail_system):
    if not EAL.does_asset_exist(SHOT_BP):
        raise RuntimeError(SHOT_BP + " not found; run create_enemies_and_waves.py first")
    bp = EAL.load_asset(SHOT_BP)
    cdo = unreal.get_default_object(EAL.load_blueprint_class(SHOT_BP))
    trail = cdo.get_editor_property("trail")
    try:
        trail.set_asset(trail_system)
    except Exception:
        trail.set_editor_property("asset", trail_system)
    # the shot passes these to the trail (User.ShotSize, User.ShotColor) each time it's fired
    cdo.set_editor_property("trail_size", SHOT_SIZE)
    cdo.set_editor_property("heavy_trail", False)
    cdo.set_editor_property("plasma_color", unreal.LinearColor(SHOT_COLOR[0], SHOT_COLOR[1], SHOT_COLOR[2], 1.0))
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    EAL.save_loaded_asset(bp)


def wire_explosion(name, system):
    full = "{}/{}".format(ENEMY_DIR, name)
    if not EAL.does_asset_exist(full):
        raise RuntimeError(full + " not found; run create_enemies_and_waves.py first")
    size, big = EXPLOSIONS[name]
    bp = EAL.load_asset(full)
    cdo = unreal.get_default_object(EAL.load_blueprint_class(full))
    # the enemy hands these to the system when it's shot down (User.Size, User.Big, and User.Color = its DeathColor)
    cdo.set_editor_property("explosion_fx", system)
    cdo.set_editor_property("explosion_size", size)
    cdo.set_editor_property("big_burst", big)
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    EAL.save_loaded_asset(bp)


def main():
    if not hasattr(unreal, "SunderProjectile"):
        unreal.log_error("[SunderEnemyFX] C++ types not found: SunderProjectile. Compile unreal/Source first.")
        return
    for path in (MAT_DIR, EFT_DIR, SYS_DIR):
        EAL.make_directory(path)

    if EAL.does_asset_exist(MASTER):
        master = EAL.load_asset(MASTER)
        for name in INSTANCES:
            step(name, build_instance, name, master)
    else:
        MANUAL.append("Enemy material instances: run create_weapon_fx_assets.py first (needs " + MASTER + "), then this again")

    shot_type = step("EFT_EnemyShot effect type (never culled)", build_effect_type, "EFT_EnemyShot",
                     unreal.NiagaraCullReaction.DEACTIVATE, 0)
    shot = step("NS_Enemy_Shot (empty)", build_system, "NS_Enemy_Shot", shot_type)   # lives on the pooled shot: no pool
    if shot is not None:
        step("BP_EnemyShot: Trail = NS_Enemy_Shot, size 30, violet", wire_shot, shot)

    boom_type = step("EFT_EnemyExplosion effect type (at most 48)", build_effect_type, "EFT_EnemyExplosion",
                     unreal.NiagaraCullReaction.DEACTIVATE_IMMEDIATE, EXPLOSION_POOL[0])
    boom = step("NS_Enemy_Explosion (empty, pooled)", build_system, "NS_Enemy_Explosion", boom_type, EXPLOSION_POOL)
    if boom is not None:
        for name in EXPLOSIONS:
            step("{}: Explosion FX = NS_Enemy_Explosion".format(name), wire_explosion, name, boom)

    MANUAL.extend([
        "NS_Enemy_Shot: add the user parameters ShotColor and ShotSize (ENEMY_VFX.md §2) and the Orb and Wake "
        "emitters (§3); the placeholder bolt hides itself once the system has an emitter",
        "Play a dense wave and check stat Niagara against the budget in ENEMY_VFX.md §3",
        "NS_Enemy_Explosion: add the user parameters Color, Size and Big (ENEMY_VFX.md §5.1) and the Flash, Sparks, "
        "Ring and Embers emitters (§5.2); enemies switch from the plasma impacts to it once it has an emitter",
        "Run create_hour_waves.py again so each Hour's wave set carries its colour for the explosions",
    ])
    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)


main()
