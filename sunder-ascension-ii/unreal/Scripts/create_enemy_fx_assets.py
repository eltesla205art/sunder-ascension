"""SUNDER: Ascension II — create the scriptable half of the enemy shot trail (see ../ENEMY_VFX.md) and wire it up.

Run inside the Unreal Editor (Tools → Execute Python Script…) AFTER create_weapon_fx_assets.py (for the master
material) and create_enemies_and_waves.py (for BP_EnemyShot), with the C++ in unreal/Source compiled.

Creates under /Game/FX/Enemies:
  Materials/    MI_Enemy_Shot (an instance of M_FX_Additive: round sprite, hot core)
  EffectTypes/  EFT_EnemyShot (never culled: a bullet's look must not vanish while it can still hit you)
  Systems/      NS_Enemy_Shot — an empty system with its effect type; the emitters are built by hand

Then puts NS_Enemy_Shot on the Trail of BP_EnemyShot with its size (30) and the web game's violet as its colour.

An empty system is safe: the shot keeps its placeholder bolt until the system has an emitter, then hides the bolt by
itself (ASunderProjectile::BeginPlay), with no further wiring.

Safe to run again. Untested until its first run.
"""
import unreal

SHOT_BP = "/Game/Sunder/Blueprints/BP_EnemyShot"
SHOT_SIZE = 30.0                     # User.ShotSize: the web bullet is 12 px across, about 60 units with its glow
SHOT_COLOR = (1.3, 0.12, 2.7)        # User.ShotColor: the web game's violet #9B30D6, made bright for bloom

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
INSTANCE = {"Mode": 1.0, "CoreSharpness": 4.0, "GlowSharpness": 1.4, "CoreBoost": 4.0}


def build_instance(master):
    mi = get_or_create("MI_Enemy_Shot", MAT_DIR, unreal.MaterialInstanceConstant,
                       unreal.MaterialInstanceConstantFactoryNew())
    MEL.set_material_instance_parent(mi, master)
    for param, value in INSTANCE.items():
        MEL.set_material_instance_scalar_parameter_value(mi, param, value)
    MEL.update_material_instance(mi)
    EAL.save_loaded_asset(mi)
    return mi


def build_effect_type():
    et = get_or_create("EFT_EnemyShot", EFT_DIR, unreal.NiagaraEffectType, unreal.NiagaraEffectTypeFactoryNew())
    et.set_editor_property("cull_reaction", unreal.NiagaraCullReaction.DEACTIVATE)
    et.set_editor_property("update_frequency", unreal.NiagaraScalabilityUpdateFrequency.CONTINUOUS)
    # no instance cap: every live bullet keeps its look (clears a cap if one was set by hand)
    array = et.get_editor_property("system_scalability_settings")
    settings = list(array.get_editor_property("settings"))
    if settings:
        for entry in settings:
            entry.set_editor_property("cull_by_max_instance_count", False)
        array.set_editor_property("settings", settings)
        et.set_editor_property("system_scalability_settings", array)
    EAL.save_loaded_asset(et)
    return et


def build_system(effect_type):
    # the trail lives on the pooled shot, so the system itself isn't pooled
    system = get_or_create("NS_Enemy_Shot", SYS_DIR, unreal.NiagaraSystem, unreal.NiagaraSystemFactoryNew())
    if effect_type is not None:
        system.set_editor_property("effect_type", effect_type)
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


def main():
    if not hasattr(unreal, "SunderProjectile"):
        unreal.log_error("[SunderEnemyFX] C++ types not found: SunderProjectile. Compile unreal/Source first.")
        return
    for path in (MAT_DIR, EFT_DIR, SYS_DIR):
        EAL.make_directory(path)

    if EAL.does_asset_exist(MASTER):
        step("MI_Enemy_Shot", build_instance, EAL.load_asset(MASTER))
    else:
        MANUAL.append("MI_Enemy_Shot: run create_weapon_fx_assets.py first (needs " + MASTER + "), then this again")

    effect_type = step("EFT_EnemyShot effect type (never culled)", build_effect_type)
    system = step("NS_Enemy_Shot (empty)", build_system, effect_type)
    if system is not None:
        step("BP_EnemyShot: Trail = NS_Enemy_Shot, size 30, violet", wire_shot, system)

    MANUAL.extend([
        "NS_Enemy_Shot: add the user parameters ShotColor and ShotSize (ENEMY_VFX.md §2) and the Orb and Wake "
        "emitters (§3); the placeholder bolt hides itself once the system has an emitter",
        "Play a dense wave and check stat Niagara against the budget in ENEMY_VFX.md §3",
    ])
    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)


main()
