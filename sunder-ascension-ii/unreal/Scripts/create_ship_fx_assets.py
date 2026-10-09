"""SUNDER: Ascension II — create the scriptable half of the ship's VFX (see ../SHIP_VFX.md): its shield, its
explosion, its bomb blast and its form change, and wire them to the ship.

Run inside the Unreal Editor (Tools → Execute Python Script…) AFTER create_weapon_fx_assets.py (for the master material
and EFT_PlayerWeapon) and create_arena_level.py (for BP_SunderShip), with the C++ in unreal/Source compiled.

Creates under /Game/FX/Ship:
  Materials/  MI_Shield_Ring, MI_Shield_Glow, MI_Ship_Flash, MI_Bomb_Wave, MI_Form_Ray (instances of M_FX_Additive)
  Systems/    NS_Ship_Shield (looping), NS_Ship_ShieldEvent, NS_Ship_Explosion, NS_Ship_Bomb and NS_Ship_FormChange
              (one-shot, pooled): empty systems; build their emitters by hand from SHIP_VFX.md
and sets them on BP_SunderShip as Shield FX, Shield Event FX, Explosion FX, Bomb FX and Form FX.

Empty systems are safe: the ship keeps its placeholder shield disc, and plasma impacts for shield hits, hull hits, its
destruction, bombs and form rises, until a system has an emitter, then uses it with no further wiring.

Safe to run again. Untested until its first run.
"""
import unreal

ROOT = "/Game/FX/Ship"
MAT_DIR = ROOT + "/Materials"
SYS_DIR = ROOT + "/Systems"
MASTER = "/Game/FX/Weapons/Materials/M_FX_Additive"
EFFECT_TYPE = "/Game/FX/Weapons/EffectTypes/EFT_PlayerWeapon"
SHIP_BP = "/Game/Sunder/Blueprints/BP_SunderShip"

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
MEL = unreal.MaterialEditingLibrary
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []


def log(msg):
    unreal.log("[SunderShipFX] " + msg)


def step(label, fn, *args):
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:   # the editor's Python API differs a little between versions
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderShipFX] {} failed: {}".format(label, exc))
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
    "MI_Shield_Ring": {"Mode": 2.0, "CoreSharpness": 3.0, "GlowSharpness": 1.2, "CoreBoost": 5.0, "RingThickness": 0.06},
    "MI_Shield_Glow": {"Mode": 1.0, "CoreSharpness": 0.8, "GlowSharpness": 0.5, "CoreBoost": 1.0},
    "MI_Ship_Flash":  {"Mode": 1.0, "CoreSharpness": 2.0, "GlowSharpness": 0.6, "CoreBoost": 4.0},   # white-hot centre, wide
    "MI_Form_Ray":    {"Mode": 0.0, "CoreSharpness": 3.0, "GlowSharpness": 0.9, "CoreBoost": 3.0, "ScrollSpeed": 3.0},
    "MI_Bomb_Wave":   {"Mode": 2.0, "CoreSharpness": 1.5, "GlowSharpness": 0.5, "CoreBoost": 3.0, "RingThickness": 0.22},
}


def build_instance(name, master):
    mi = get_or_create(name, MAT_DIR, unreal.MaterialInstanceConstant, unreal.MaterialInstanceConstantFactoryNew())
    MEL.set_material_instance_parent(mi, master)
    for param, value in INSTANCES[name].items():
        MEL.set_material_instance_scalar_parameter_value(mi, param, value)
    MEL.update_material_instance(mi)
    EAL.save_loaded_asset(mi)
    return mi


def build_system(name, pool_max, pool_prime):
    system = get_or_create(name, SYS_DIR, unreal.NiagaraSystem, unreal.NiagaraSystemFactoryNew())
    if EAL.does_asset_exist(EFFECT_TYPE):
        system.set_editor_property("effect_type", EAL.load_asset(EFFECT_TYPE))
    else:
        MANUAL.append("{}: set Effect Type = EFT_PlayerWeapon (run create_weapon_fx_assets.py)".format(name))
    for prop, value in (("max_pool_size", pool_max), ("pool_prime_size", pool_prime)):
        if value is None:
            continue
        try:
            system.set_editor_property(prop, value)
        except Exception as exc:
            MANUAL.append("{}: set {} = {} in System Properties  ({})".format(name, prop, value, exc))
    EAL.save_loaded_asset(system)
    return system


def wire_ship(shield, event, explosion, bomb, form):
    if not EAL.does_asset_exist(SHIP_BP):
        raise RuntimeError(SHIP_BP + " not found; run create_arena_level.py first")
    bp = EAL.load_asset(SHIP_BP)
    cdo = unreal.get_default_object(EAL.load_blueprint_class(SHIP_BP))
    if shield is not None:
        cdo.set_editor_property("shield_fx", shield)
    if event is not None:
        cdo.set_editor_property("shield_event_fx", event)
    if explosion is not None:
        cdo.set_editor_property("explosion_fx", explosion)
    if bomb is not None:
        cdo.set_editor_property("bomb_fx", bomb)
    if form is not None:
        cdo.set_editor_property("form_fx", form)
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    EAL.save_loaded_asset(bp)


def main():
    if not hasattr(unreal, "SunderShipPawn"):
        unreal.log_error("[SunderShipFX] C++ types not found: SunderShipPawn. Compile unreal/Source first.")
        return
    for path in (MAT_DIR, SYS_DIR):
        EAL.make_directory(path)

    if EAL.does_asset_exist(MASTER):
        master = EAL.load_asset(MASTER)
        for name in INSTANCES:
            step(name, build_instance, name, master)
    else:
        MANUAL.append("Ship materials: run create_weapon_fx_assets.py first (needs " + MASTER + "), then this again")

    shield = step("NS_Ship_Shield (empty)", build_system, "NS_Ship_Shield", None, None)
    event = step("NS_Ship_ShieldEvent (empty)", build_system, "NS_Ship_ShieldEvent", 6, 2)
    # the explosion: a hull hit or the ship destroyed; at most a couple at once (a hit, then the death)
    explosion = step("NS_Ship_Explosion (empty)", build_system, "NS_Ship_Explosion", 3, 1)
    bomb = step("NS_Ship_Bomb (empty)", build_system, "NS_Ship_Bomb", 2, 1)   # one at a time, but two can overlap
    form = step("NS_Ship_FormChange (empty)", build_system, "NS_Ship_FormChange", 3, 1)
    step("BP_SunderShip: Shield FX, Shield Event FX, Explosion FX, Bomb FX and Form FX", wire_ship,
         shield, event, explosion, bomb, form)

    MANUAL.extend([
        "NS_Ship_Shield and NS_Ship_ShieldEvent: add the user parameters (SHIP_VFX.md §1.1) and the emitters (§2, §3)",
        "Scratch pad dynamic input SP_LayerMask (SHIP_VFX.md §1.3); SP_FlattenToPlane is from WEAPON_VFX.md §2.3",
        "NS_Ship_Explosion: add its user parameters (SHIP_VFX.md §5.1) and the emitters (§5.2)",
        "NS_Ship_Bomb: add its user parameters, including the WipedShots vector array (SHIP_VFX.md §7.1), and the "
        "emitters (§7.2)",
        "NS_Ship_FormChange: add its user parameters (SHIP_VFX.md §9.1) and the emitters (§9.2)",
    ])
    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)


main()
