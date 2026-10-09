"""SUNDER: Ascension II — create the scriptable half of the pickup collect VFX (see ../PICKUP_VFX.md) and wire it up.

Run inside the Unreal Editor (Tools → Execute Python Script…) AFTER create_weapon_fx_assets.py (for the master material
and EFT_PlayerWeapon) and create_pickup_art.py (for BP_SunderPickup), with the C++ in unreal/Source compiled.

Creates under /Game/FX/Pickups:
  Materials/  MI_Pickup_Mote, MI_Pickup_Ring (instances of M_FX_Additive)
  Systems/    NS_Pickup_Collect (one-shot, pooled): an empty system; build its emitters by hand from PICKUP_VFX.md
and sets it on BP_SunderPickup as Collect FX.

An empty system is safe: a collected pickup shows a plasma impact in its colour until the system has an emitter, then
uses it with no further wiring.

Safe to run again. Untested until its first run.
"""
import unreal

ROOT = "/Game/FX/Pickups"
MAT_DIR = ROOT + "/Materials"
SYS_DIR = ROOT + "/Systems"
MASTER = "/Game/FX/Weapons/Materials/M_FX_Additive"
EFFECT_TYPE = "/Game/FX/Weapons/EffectTypes/EFT_PlayerWeapon"
PICKUP_BP = "/Game/Sunder/Blueprints/BP_SunderPickup"
POOL = (6, 2)        # max pool size, prime size: a few can be collected close together

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
MEL = unreal.MaterialEditingLibrary
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []


def log(msg):
    unreal.log("[SunderPickupFX] " + msg)


def step(label, fn, *args):
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:   # the editor's Python API differs a little between versions
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderPickupFX] {} failed: {}".format(label, exc))
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
    "MI_Pickup_Mote": {"Mode": 1.0, "CoreSharpness": 3.5, "GlowSharpness": 1.3, "CoreBoost": 4.0},   # bright points
    "MI_Pickup_Ring": {"Mode": 2.0, "CoreSharpness": 2.5, "GlowSharpness": 1.0, "CoreBoost": 4.0, "RingThickness": 0.08},
}


def build_instance(name, master):
    mi = get_or_create(name, MAT_DIR, unreal.MaterialInstanceConstant, unreal.MaterialInstanceConstantFactoryNew())
    MEL.set_material_instance_parent(mi, master)
    for param, value in INSTANCES[name].items():
        MEL.set_material_instance_scalar_parameter_value(mi, param, value)
    MEL.update_material_instance(mi)
    EAL.save_loaded_asset(mi)
    return mi


def build_system():
    system = get_or_create("NS_Pickup_Collect", SYS_DIR, unreal.NiagaraSystem, unreal.NiagaraSystemFactoryNew())
    if EAL.does_asset_exist(EFFECT_TYPE):
        system.set_editor_property("effect_type", EAL.load_asset(EFFECT_TYPE))   # never culled: it's your own pickup
    else:
        MANUAL.append("NS_Pickup_Collect: set Effect Type = EFT_PlayerWeapon (run create_weapon_fx_assets.py)")
    for prop, value in zip(("max_pool_size", "pool_prime_size"), POOL):
        try:
            system.set_editor_property(prop, value)
        except Exception as exc:
            MANUAL.append("NS_Pickup_Collect: set {} = {} in System Properties  ({})".format(prop, value, exc))
    EAL.save_loaded_asset(system)
    return system


def wire_pickup(system):
    if not EAL.does_asset_exist(PICKUP_BP):
        raise RuntimeError(PICKUP_BP + " not found; run create_pickup_art.py first")
    bp = EAL.load_asset(PICKUP_BP)
    cdo = unreal.get_default_object(EAL.load_blueprint_class(PICKUP_BP))
    # the pickup hands User.Color, Kind, Size and ToShip to the system when it's collected
    cdo.set_editor_property("collect_fx", system)
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    EAL.save_loaded_asset(bp)


def main():
    if not hasattr(unreal, "SunderPickup"):
        unreal.log_error("[SunderPickupFX] C++ types not found: SunderPickup. Compile unreal/Source first.")
        return
    for path in (MAT_DIR, SYS_DIR):
        EAL.make_directory(path)

    if EAL.does_asset_exist(MASTER):
        master = EAL.load_asset(MASTER)
        for name in INSTANCES:
            step(name, build_instance, name, master)
    else:
        MANUAL.append("Pickup materials: run create_weapon_fx_assets.py first (needs " + MASTER + "), then this again")

    system = step("NS_Pickup_Collect (empty, pooled)", build_system)
    if system is not None:
        step("BP_SunderPickup: Collect FX = NS_Pickup_Collect", wire_pickup, system)

    MANUAL.append("NS_Pickup_Collect: add the user parameters (PICKUP_VFX.md §2) and the emitters (§3); collected "
                  "pickups switch from the plasma impact to it once it has an emitter")
    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)


main()
