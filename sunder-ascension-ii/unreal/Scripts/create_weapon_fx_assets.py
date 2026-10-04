"""SUNDER: Ascension II — create the scriptable half of the weapon VFX (see ../WEAPON_VFX.md).

Run inside the Unreal Editor: Tools → Execute Python Script… → this file
(needs the Python Editor Script Plugin, on by default in UE5).

Creates under /Game/FX/Weapons:
  Materials/    M_FX_Additive (unlit additive master, full node graph) and its five instances:
                MI_Beam_Core, MI_Beam_Glow, MI_Spark, MI_ShockRing, MI_PlasmaTendril
  EffectTypes/  EFT_PlayerWeapon (never culled), EFT_Impact (max 40, newest kept, culled immediately)
  Systems/      NS_Laser_Beam, NS_PlasmaBurst_Impact, NS_PlasmaBurst_ImpactLite — empty systems with their effect
                type and pool sizes set; their emitters are built by hand following the guide

Safe to run again: existing assets are updated, not duplicated (the master material's graph is rebuilt).
Each step runs on its own; anything this engine version's Python API refuses is logged and listed at the end as a
manual step, so one missing call never stops the rest.

Written without an Unreal install, so untested until its first run.
"""
import unreal

ROOT = "/Game/FX/Weapons"
MAT_DIR = ROOT + "/Materials"
EFT_DIR = ROOT + "/EffectTypes"
SYS_DIR = ROOT + "/Systems"

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
MEL = unreal.MaterialEditingLibrary
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []


def log(msg):
    unreal.log("[SunderFX] " + msg)


def step(label, fn, *args):
    """Run one step; on failure record it as a manual step instead of stopping the script."""
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:  # the editor's Python API differs a little between versions
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderFX] {} failed: {}".format(label, exc))
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


# ------------------------------------------------------------------ the master material
# One Custom node draws every look the weapons need, picked per instance by the Mode parameter:
#   0 = ribbon (V runs across the beam or tendril), 1 = round sprite (sparks, flash), 2 = ring (shock ring).
PROFILE_HLSL = """
float flick = 0.85 + 0.15 * sin(Time * 37.0 + UV.x * 23.0 - Time * ScrollSpeed) * sin(Time * 11.0 - UV.x * 7.0);
float core;
float glow;
if (Mode < 0.5)
{
    float v = abs(UV.y * 2.0 - 1.0);                       // 0 on the centre line, 1 at the edges
    core = pow(saturate(1.0 - v), CoreSharpness);
    glow = pow(saturate(1.0 - v), GlowSharpness);
}
else if (Mode < 1.5)
{
    float r = saturate(length(UV * 2.0 - 1.0));            // radial falloff
    core = pow(saturate(1.0 - r), CoreSharpness);
    glow = pow(saturate(1.0 - r), GlowSharpness);
    flick = 1.0;
}
else
{
    float r = length(UV * 2.0 - 1.0);                      // a band Thickness wide at the sprite's edge
    float band = saturate(1.0 - abs(r - (1.0 - Thickness)) / max(Thickness, 0.001));
    core = pow(band, CoreSharpness);
    glow = band;
    flick = 1.0;
}
return (GlowColor * glow + CoreColor * CoreBoost * core) * PColor.rgb * PAlpha * flick;
"""

CUSTOM_INPUTS = ["UV", "Time", "PColor", "PAlpha", "Mode", "CoreSharpness", "GlowSharpness", "Thickness",
                 "ScrollSpeed", "CoreBoost", "CoreColor", "GlowColor"]


def build_master():
    mat = get_or_create("M_FX_Additive", MAT_DIR, unreal.Material, unreal.MaterialFactoryNew())
    MEL.delete_all_material_expressions(mat)
    mat.set_editor_property("shading_model", unreal.MaterialShadingModel.MSM_UNLIT)
    mat.set_editor_property("blend_mode", unreal.BlendMode.BLEND_ADDITIVE)
    mat.set_editor_property("two_sided", True)
    for flag in ("used_with_niagara_sprites", "used_with_niagara_ribbons", "used_with_niagara_mesh_particles"):
        try:
            mat.set_editor_property(flag, True)
        except Exception as exc:
            MANUAL.append("M_FX_Additive: tick Usage → {}  ({})".format(flag, exc))

    def node(cls, x, y):
        return MEL.create_material_expression(mat, cls, x, y)

    def scalar(name, value, x, y):
        e = node(unreal.MaterialExpressionScalarParameter, x, y)
        e.set_editor_property("parameter_name", name)
        e.set_editor_property("default_value", value)
        return e

    def vector(name, color, x, y):
        e = node(unreal.MaterialExpressionVectorParameter, x, y)
        e.set_editor_property("parameter_name", name)
        e.set_editor_property("default_value", color)
        return e

    def link(src, out, dst, pin):
        if not MEL.connect_material_expressions(src, out, dst, pin):
            raise RuntimeError("could not connect {} → {}".format(out or "output", pin))

    custom = node(unreal.MaterialExpressionCustom, -200, 0)
    custom.set_editor_property("code", PROFILE_HLSL)
    custom.set_editor_property("output_type", unreal.CustomMaterialOutputType.CMOT_FLOAT3)
    custom.set_editor_property("description", "SunderFXProfile")
    inputs = []
    for name in CUSTOM_INPUTS:
        pin = unreal.CustomInput()
        pin.set_editor_property("input_name", name)
        inputs.append(pin)
    custom.set_editor_property("inputs", inputs)

    link(node(unreal.MaterialExpressionTextureCoordinate, -800, -500), "", custom, "UV")
    link(node(unreal.MaterialExpressionTime, -800, -420), "", custom, "Time")
    particle_color = node(unreal.MaterialExpressionParticleColor, -800, -340)
    link(particle_color, "", custom, "PColor")
    link(particle_color, "A", custom, "PAlpha")

    # ring thickness: per-particle Dynamic Parameter 1 (defaults to 1) × the instance's RingThickness
    dynamic = node(unreal.MaterialExpressionDynamicParameter, -1000, 420)
    thickness = node(unreal.MaterialExpressionMultiply, -800, 420)
    link(dynamic, "Param1", thickness, "A")
    link(scalar("RingThickness", 0.25, -1000, 560), "", thickness, "B")
    link(thickness, "", custom, "Thickness")

    y = -200
    for name, value in (("Mode", 0.0), ("CoreSharpness", 8.0), ("GlowSharpness", 1.5),
                        ("ScrollSpeed", 12.0), ("CoreBoost", 6.0)):
        link(scalar(name, value, -800, y), "", custom, name)
        y += 80
    link(vector("CoreColor", unreal.LinearColor(1.0, 1.0, 1.0, 1.0), -800, y), "", custom, "CoreColor")
    link(vector("GlowColor", unreal.LinearColor(1.0, 0.25, 0.6, 1.0), -800, y + 160), "", custom, "GlowColor")

    if not MEL.connect_material_property(custom, "", unreal.MaterialProperty.MP_EMISSIVE_COLOR):
        raise RuntimeError("could not connect the profile to Emissive Color")
    MEL.layout_material_expressions(mat)
    MEL.recompile_material(mat)
    EAL.save_loaded_asset(mat)
    return mat


# Colours multiply Particle Color, which the systems set (Sunborn gold beam, magenta plasma); see guide §0.2.
INSTANCES = {
    "MI_Beam_Core":     {"Mode": 0.0, "CoreSharpness": 8.0, "GlowSharpness": 2.5, "CoreBoost": 8.0, "ScrollSpeed": 14.0},
    "MI_Beam_Glow":     {"Mode": 0.0, "CoreSharpness": 3.0, "GlowSharpness": 0.8, "CoreBoost": 1.5, "ScrollSpeed": 8.0},
    "MI_Spark":         {"Mode": 1.0, "CoreSharpness": 2.5, "GlowSharpness": 1.0, "CoreBoost": 4.0},
    "MI_ShockRing":     {"Mode": 2.0, "CoreSharpness": 1.5, "GlowSharpness": 1.0, "CoreBoost": 3.0, "RingThickness": 0.25},
    "MI_PlasmaTendril": {"Mode": 0.0, "CoreSharpness": 4.0, "GlowSharpness": 1.2, "CoreBoost": 5.0, "ScrollSpeed": 20.0},
}
INSTANCE_COLORS = {
    "MI_Beam_Glow": {"GlowColor": unreal.LinearColor(1.0, 0.25, 0.64, 1.0)},    # magenta sheath around the gold core
    "MI_PlasmaTendril": {"CoreColor": unreal.LinearColor(1.0, 0.9, 1.0, 1.0)},
}


def build_instance(name, master):
    mi = get_or_create(name, MAT_DIR, unreal.MaterialInstanceConstant, unreal.MaterialInstanceConstantFactoryNew())
    MEL.set_material_instance_parent(mi, master)
    for param, value in INSTANCES[name].items():
        MEL.set_material_instance_scalar_parameter_value(mi, param, value)
    for param, color in INSTANCE_COLORS.get(name, {}).items():
        MEL.set_material_instance_vector_parameter_value(mi, param, color)
    MEL.update_material_instance(mi)
    EAL.save_loaded_asset(mi)
    return mi


# ------------------------------------------------------------------ effect types (guide §3.3)
def build_effect_type(name, cull_reaction, frequency, max_instances, newest_first):
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
        MANUAL.append("{}: add Medium (24) and Low (12) max-instance tiers and Spawn Count Scale 0.7 / 0.4 "
                      "per quality level (guide §3.3); the script sets one tier of {}".format(name, max_instances))
    if newest_first:
        handler = unreal.new_object(unreal.NiagaraSignificanceHandlerAge, outer=et)
        et.set_editor_property("significance_handler", handler)
    EAL.save_loaded_asset(et)
    return et


# ------------------------------------------------------------------ systems (empty; emitters by hand)
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


def main():
    for path in (MAT_DIR, EFT_DIR, SYS_DIR):
        EAL.make_directory(path)

    master = step("M_FX_Additive master material", build_master)
    if master is not None:
        for name in INSTANCES:
            step(name, build_instance, name, master)
    else:
        MANUAL.append("Material instances: skipped because the master material failed (guide §0.2)")

    weapon = step("EFT_PlayerWeapon effect type", build_effect_type, "EFT_PlayerWeapon",
                  unreal.NiagaraCullReaction.DEACTIVATE, unreal.NiagaraScalabilityUpdateFrequency.CONTINUOUS, 0, False)
    impact = step("EFT_Impact effect type", build_effect_type, "EFT_Impact",
                  unreal.NiagaraCullReaction.DEACTIVATE_IMMEDIATE, unreal.NiagaraScalabilityUpdateFrequency.LOW, 40, True)

    step("NS_Laser_Beam (empty)", build_system, "NS_Laser_Beam", weapon, None, None)
    step("NS_PlasmaBurst_Impact (empty)", build_system, "NS_PlasmaBurst_Impact", impact, 48, 32)
    step("NS_PlasmaBurst_ImpactLite (empty)", build_system, "NS_PlasmaBurst_ImpactLite", impact, 48, 32)

    # What Python can't reach: the emitter stacks and user parameters, edited in the Niagara editor.
    MANUAL.extend([
        "NS_Laser_Beam: add the user parameters (guide §1.1), Fixed Bounds ±4096, and emitters "
        "Beam_Core, Beam_MuzzleFlare, Beam_ImpactSparks, Beam_ImpactGlow (§1.2–1.5)",
        "NS_PlasmaBurst_Impact: add the user parameters (§2.1), Fixed Bounds ±512, and emitters "
        "Flash, ShockRing, Tendril_Heads, Tendril_Ribbons, Erratic_Sparks, Residue (§2.2)",
        "NS_PlasmaBurst_ImpactLite: same user parameters; Flash + Erratic_Sparks with a burst of 15 only",
        "Scratch pad modules SP_InitBeamU, SP_BeamPosition, SP_BeamWidth, SP_ErraticJitter, SP_FlattenToPlane: "
        "paste the HLSL from §1.2 and §2.3",
        "Project Settings → Game → Sunder Impact FX: ImpactFX = NS_PlasmaBurst_Impact, "
        "ImpactFXLite = NS_PlasmaBurst_ImpactLite (needs the C++ from unreal/Source compiled)",
    ])

    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)


main()
