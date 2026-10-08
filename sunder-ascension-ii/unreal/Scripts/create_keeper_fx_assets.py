"""SUNDER: Ascension II — create the scriptable half of the Keeper VFX (see ../KEEPER_VFX.md) and wire it to the Keepers.

Run inside the Unreal Editor (Tools → Execute Python Script…) AFTER create_weapon_fx_assets.py (for the master
material) and create_keepers.py (for the Keeper Blueprints), with the C++ in unreal/Source compiled.

Creates under /Game/FX/Keepers:
  Materials/    MI_Keeper_Glow, MI_Keeper_Rune, MI_Keeper_Ray, MI_Keeper_Shot (instances of M_FX_Additive)
  EffectTypes/  EFT_Keeper (never culled), EFT_KeeperShot (many instances, culled last)
  Systems/      NS_Keeper_Aura, NS_Keeper_Arrival, NS_Keeper_Muzzle, NS_Keeper_PhaseShift, NS_Keeper_Death,
                NS_Keeper_Shot — empty systems with their effect type and pool sizes; emitters are built by hand

Then sets, on all twelve BP_Keeper_* Blueprints, the five Keeper systems and each Keeper's two glow colours (its
Hour's colour and an accent), and puts NS_Keeper_Shot on the Trail of BP_KeeperShot and BP_KeeperShotHeavy with their
sizes (34 / 46) and the heavy shot's flag.

Empty systems are safe: the Keeper skips a system that has no emitters yet and uses the shared plasma impacts, so the
game looks the same until each system is built, then picks it up with no further wiring.

Safe to run again. Untested until its first run.
"""
import unreal

# The Keeper shots' trail settings (User.ShotSize, User.Heavy): the heavy shot (Hours 7+) is bigger, with embers.
SHOT_TRAILS = {"BP_KeeperShot": (34.0, False), "BP_KeeperShotHeavy": (46.0, True)}

ROOT = "/Game/FX/Keepers"
MAT_DIR = ROOT + "/Materials"
EFT_DIR = ROOT + "/EffectTypes"
SYS_DIR = ROOT + "/Systems"
MASTER = "/Game/FX/Weapons/Materials/M_FX_Additive"
KEEPER_DIR = "/Game/Sunder/Blueprints/Keepers"
SHOT_DIR = "/Game/Sunder/Blueprints"

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
MEL = unreal.MaterialEditingLibrary
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []


def log(msg):
    unreal.log("[SunderKeeperFX] " + msg)


def step(label, fn, *args):
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:   # the editor's Python API differs a little between versions
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderKeeperFX] {} failed: {}".format(label, exc))
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


# ------------------------------------------------------------------ colours
def hdr(hex_rgb, strength):
    """sRGB hex → linear HDR colour, brightest channel = strength (bloom does the rest)."""
    rgb = [int(hex_rgb[i:i + 2], 16) / 255.0 for i in (1, 3, 5)]
    lin = [c / 12.92 if c <= 0.04045 else ((c + 0.055) / 1.055) ** 2.4 for c in rgb]
    peak = max(max(lin), 1e-4)
    return [c / peak * strength for c in lin]


# Glow colours per Keeper: KeeperColor is its Hour's colour (web/game.html STAGES tint), AccentColor its emissive
# material in blender/keepers.py (crystal, Atlantean cyan, violet, fire, heart...). Starting points: tune by eye.
CRYSTAL, CYAN, VIOLET, AMBER = "#FF73CF", "#9EEFFF", "#B45CFF", "#FFE08A"
EMBER, HEART, ORANGE, STARFIRE = "#FF9A30", "#ED3E61", "#FFAD38", "#EDE7FF"
KEEPER_FX = {
    "wepwawet":       ("#D98C4D", CRYSTAL),
    "sobek":          ("#66BFCC", CYAN),
    "umbra":          ("#B3BFD9", VIOLET),
    "nun":            ("#4D8CCC", CYAN),
    "sokar":          ("#C9A04D", AMBER),
    "seraphs":        ("#E0603A", EMBER),
    "umbra_coiled":   ("#9B5CE0", VIOLET),
    "hittite":        ("#994D4D", EMBER),
    "ammit":          ("#D9A633", HEART),
    "overlord_echo":  ("#CC4DE6", ORANGE),
    "umbra_unmasked": ("#8FE3FF", STARFIRE),
    "apep":           ("#7A2BD6", VIOLET),
}
KEEPER_GLOW = 3.5
ACCENT_GLOW = 4.0


def linear_color(values):
    return unreal.LinearColor(values[0], values[1], values[2], 1.0)


def bp_name(kid):
    return "BP_Keeper_" + "".join(part.capitalize() for part in kid.split("_"))


# ------------------------------------------------------------------ materials (instances of the weapons' master)
# Mode: 0 ribbon, 1 round sprite, 2 ring (see create_weapon_fx_assets.py). Colour comes from Particle Color.
INSTANCES = {
    "MI_Keeper_Glow": {"Mode": 1.0, "CoreSharpness": 1.2, "GlowSharpness": 0.6, "CoreBoost": 1.5},   # soft halo, cores
    "MI_Keeper_Rune": {"Mode": 2.0, "CoreSharpness": 2.0, "GlowSharpness": 1.0, "CoreBoost": 4.0, "RingThickness": 0.08},
    "MI_Keeper_Ray":  {"Mode": 0.0, "CoreSharpness": 3.0, "GlowSharpness": 0.9, "CoreBoost": 3.0, "ScrollSpeed": 4.0},
    "MI_Keeper_Shot": {"Mode": 1.0, "CoreSharpness": 5.0, "GlowSharpness": 1.6, "CoreBoost": 6.0},   # hot core, tight glow
}


def build_instance(name, master):
    mi = get_or_create(name, MAT_DIR, unreal.MaterialInstanceConstant, unreal.MaterialInstanceConstantFactoryNew())
    MEL.set_material_instance_parent(mi, master)
    for param, value in INSTANCES[name].items():
        MEL.set_material_instance_scalar_parameter_value(mi, param, value)
    MEL.update_material_instance(mi)
    EAL.save_loaded_asset(mi)
    return mi


# ------------------------------------------------------------------ effect types
def build_effect_type(name, cull_reaction, frequency, max_instances):
    et = get_or_create(name, EFT_DIR, unreal.NiagaraEffectType, unreal.NiagaraEffectTypeFactoryNew())
    et.set_editor_property("cull_reaction", cull_reaction)
    et.set_editor_property("update_frequency", frequency)
    if max_instances:
        array = et.get_editor_property("system_scalability_settings")
        settings = list(array.get_editor_property("settings"))
        if not settings:
            settings = [unreal.NiagaraSystemScalabilitySettings()]
        first = settings[0]
        first.set_editor_property("cull_by_max_instance_count", True)
        first.set_editor_property("max_instances", max_instances)
        settings[0] = first
        array.set_editor_property("settings", settings)
        et.set_editor_property("system_scalability_settings", array)
    EAL.save_loaded_asset(et)
    return et


# ------------------------------------------------------------------ systems (empty; emitters by hand)
# name: (effect type key, max pool size, pool prime size) — the aura and shot trails live on actors, so no pool.
SYSTEMS = {
    "NS_Keeper_Aura":       ("keeper", None, None),
    "NS_Keeper_Arrival":    ("keeper", 2, 1),
    "NS_Keeper_Muzzle":     ("keeper", 24, 12),
    "NS_Keeper_PhaseShift": ("keeper", 4, 2),
    "NS_Keeper_Death":      ("keeper", 2, 1),
    "NS_Keeper_Shot":       ("shot", None, None),
}


def build_system(name, effect_type, pool_max, pool_prime):
    system = get_or_create(name, SYS_DIR, unreal.NiagaraSystem, unreal.NiagaraSystemFactoryNew())
    if effect_type is not None:
        system.set_editor_property("effect_type", effect_type)
    for prop, value in (("max_pool_size", pool_max), ("pool_prime_size", pool_prime)):
        if value is None:
            continue
        try:
            system.set_editor_property(prop, value)
        except Exception as exc:
            MANUAL.append("{}: set {} = {} in System Properties  ({})".format(name, prop, value, exc))
    EAL.save_loaded_asset(system)
    return system


# ------------------------------------------------------------------ wiring
def edit_blueprint(full, apply):
    if not EAL.does_asset_exist(full):
        raise RuntimeError(full + " not found; run create_keepers.py first")
    bp = EAL.load_asset(full)
    cdo = unreal.get_default_object(EAL.load_blueprint_class(full))
    apply(cdo)
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    EAL.save_loaded_asset(bp)


def wire_keeper(kid, systems):
    keeper_hex, accent_hex = KEEPER_FX[kid]

    def apply(cdo):
        for prop, name in (("aura_fx", "NS_Keeper_Aura"), ("arrival_fx", "NS_Keeper_Arrival"),
                           ("muzzle_fx", "NS_Keeper_Muzzle"), ("phase_shift_fx", "NS_Keeper_PhaseShift"),
                           ("death_fx", "NS_Keeper_Death")):
            if systems.get(name) is not None:
                cdo.set_editor_property(prop, systems[name])
        cdo.set_editor_property("keeper_color", linear_color(hdr(keeper_hex, KEEPER_GLOW)))
        cdo.set_editor_property("accent_color", linear_color(hdr(accent_hex, ACCENT_GLOW)))

    edit_blueprint("{}/{}".format(KEEPER_DIR, bp_name(kid)), apply)


def wire_shot(name, trail_system):
    size, heavy = SHOT_TRAILS.get(name, (34.0, False))

    def apply(cdo):
        trail = cdo.get_editor_property("trail")
        try:
            trail.set_asset(trail_system)
        except Exception:
            trail.set_editor_property("asset", trail_system)
        # the shot passes these to the trail each time it's fired; it hides its placeholder sphere by itself once
        # NS_Keeper_Shot has emitters
        cdo.set_editor_property("trail_size", size)
        cdo.set_editor_property("heavy_trail", heavy)

    edit_blueprint("{}/{}".format(SHOT_DIR, name), apply)


def main():
    missing = [n for n in ("SunderKeeper", "SunderProjectile") if not hasattr(unreal, n)]
    if missing:
        unreal.log_error("[SunderKeeperFX] C++ types not found: {}. Compile unreal/Source first.".format(", ".join(missing)))
        return
    for path in (MAT_DIR, EFT_DIR, SYS_DIR):
        EAL.make_directory(path)

    if EAL.does_asset_exist(MASTER):
        master = EAL.load_asset(MASTER)
        for name in INSTANCES:
            step(name, build_instance, name, master)
    else:
        MANUAL.append("Keeper material instances: run create_weapon_fx_assets.py first (needs " + MASTER + "), then this again")

    effect_types = {
        "keeper": step("EFT_Keeper effect type", build_effect_type, "EFT_Keeper",
                       unreal.NiagaraCullReaction.DEACTIVATE, unreal.NiagaraScalabilityUpdateFrequency.CONTINUOUS, 0),
        "shot": step("EFT_KeeperShot effect type", build_effect_type, "EFT_KeeperShot",
                     unreal.NiagaraCullReaction.DEACTIVATE_IMMEDIATE, unreal.NiagaraScalabilityUpdateFrequency.LOW, 400),
    }
    systems = {}
    for name, (et_key, pool_max, pool_prime) in SYSTEMS.items():
        systems[name] = step(name + " (empty)", build_system, name, effect_types[et_key], pool_max, pool_prime)

    for kid in KEEPER_FX:
        step("{}: effects and colours".format(bp_name(kid)), wire_keeper, kid, systems)
    if systems.get("NS_Keeper_Shot") is not None:
        for shot in ("BP_KeeperShot", "BP_KeeperShotHeavy"):
            step("{}: Trail = NS_Keeper_Shot".format(shot), wire_shot, shot, systems["NS_Keeper_Shot"])

    MANUAL.extend([
        "Each NS_Keeper_* system: add the user parameters (KEEPER_VFX.md §1.1) and its emitters (§2–§7)",
        "Scratch pad dynamic input SP_KeeperPulse (KEEPER_VFX.md §1.3); SP_ErraticJitter and SP_FlattenToPlane come "
        "from WEAPON_VFX.md §2.3",
    ])
    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)


main()
