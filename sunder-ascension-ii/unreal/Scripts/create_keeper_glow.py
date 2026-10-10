"""SUNDER: Ascension II — give the Keepers' glowing materials their glow, which the Codex viewer pulses.

Run inside the Unreal Editor (Tools → Execute Python Script…) AFTER create_keepers.py and create_keeper_anim.py.

FBX brings the Keepers' materials in with their base colours only. The glowing ones (crystal, cores, eyes, fire,
starfire, the Heart of Atlantis…) are read from Blender into unreal/Content/Keepers/keeper_glows.json by
blender/keepers.py <dir> 0 --glows: base colour, metal, roughness, glow colour and strength, capped as the web Codex
caps them (1.3, or 0.55 for see-through crystal). This script:
  1. makes M_Keeper_Glow (lit; Emissive = EmissiveColor × GlowStrength × GlowPulse) under /Game/Sunder/Keepers/Materials;
  2. makes MI_KeeperGlow_<name> for each glowing material (MI_KeeperGlow_<name>_<Id> where one Keeper's differs);
  3. puts them in the matching slots of each Keeper's model (SM_Keeper_<Id>) and its animation parts.
GlowPulse stays 1 in play. The Codex viewer (ASunderCodexStage) pulses it as the web viewer does:
0.75 + 0.35 × sin(3.1 t).

Safe to run again (slots are matched by their slot name, which keeps the Blender material's name). Untested until its
first run.
"""
import json
import os

import unreal

GLOW_JSON = None          # None = ../Content/Keepers/keeper_glows.json next to this script
MAT_DIR = "/Game/Sunder/Keepers/Materials"
MESH_DIR = "/Game/Sunder/Keepers/Meshes"
ANIM_DIR = "/Game/Sunder/Keepers/Anim"

KEEPERS = ["wepwawet", "sobek", "umbra", "nun", "sokar", "seraphs", "umbra_coiled", "hittite", "ammit",
           "overlord_echo", "umbra_unmasked", "apep"]

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
MEL = unreal.MaterialEditingLibrary
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []


def log(msg):
    unreal.log("[SunderKeeperGlow] " + msg)


def step(label, fn, *args):
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:   # the editor's Python API differs a little between versions
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderKeeperGlow] {} failed: {}".format(label, exc))
        return None


def camel(kid):
    return "".join(part.capitalize() for part in kid.split("_"))


def get_or_create(name, path, asset_class, factory):
    full = "{}/{}".format(path, name)
    if EAL.does_asset_exist(full):
        return EAL.load_asset(full)
    asset = TOOLS.create_asset(name, path, asset_class, factory)
    if asset is None:
        raise RuntimeError("could not create " + full)
    log("created " + full)
    return asset


def colour(rgb, a=1.0):
    return unreal.LinearColor(rgb[0], rgb[1], rgb[2], a)


def build_master():
    mat = get_or_create("M_Keeper_Glow", MAT_DIR, unreal.Material, unreal.MaterialFactoryNew())
    MEL.delete_all_material_expressions(mat)
    mat.set_editor_property("shading_model", unreal.MaterialShadingModel.MSM_DEFAULT_LIT)

    def node(cls, x, y):
        return MEL.create_material_expression(mat, cls, x, y)

    def scalar(name, value, x, y):
        e = node(unreal.MaterialExpressionScalarParameter, x, y)
        e.set_editor_property("parameter_name", name)
        e.set_editor_property("default_value", value)
        return e

    def vector(name, rgb, x, y):
        e = node(unreal.MaterialExpressionVectorParameter, x, y)
        e.set_editor_property("parameter_name", name)
        e.set_editor_property("default_value", colour(rgb))
        return e

    def link(src, out, dst, pin):
        if not MEL.connect_material_expressions(src, out, dst, pin):
            raise RuntimeError("could not connect {} → {}".format(out or "output", pin))

    def prop(src, out, which):
        if not MEL.connect_material_property(src, out, which):
            raise RuntimeError("could not connect to {}".format(which))

    prop(vector("BaseColor", (0.5, 0.5, 0.5), -600, -300), "", unreal.MaterialProperty.MP_BASE_COLOR)
    prop(scalar("Metallic", 0.0, -600, -150), "", unreal.MaterialProperty.MP_METALLIC)
    prop(scalar("Roughness", 0.5, -600, -50), "", unreal.MaterialProperty.MP_ROUGHNESS)
    strength = node(unreal.MaterialExpressionMultiply, -350, 150)
    link(vector("EmissiveColor", (1.0, 0.2, 0.6), -600, 80), "", strength, "A")
    link(scalar("GlowStrength", 1.3, -600, 230), "", strength, "B")
    pulse = node(unreal.MaterialExpressionMultiply, -150, 200)
    link(strength, "", pulse, "A")
    link(scalar("GlowPulse", 1.0, -600, 330), "", pulse, "B")      # the Codex viewer breathes this
    prop(pulse, "", unreal.MaterialProperty.MP_EMISSIVE_COLOR)
    MEL.layout_material_expressions(mat)
    MEL.recompile_material(mat)
    EAL.save_loaded_asset(mat)
    return mat


def build_instance(name, entry, master):
    mi = get_or_create(name, MAT_DIR, unreal.MaterialInstanceConstant, unreal.MaterialInstanceConstantFactoryNew())
    MEL.set_material_instance_parent(mi, master)
    MEL.set_material_instance_vector_parameter_value(mi, "BaseColor", colour(entry["base"]))
    MEL.set_material_instance_scalar_parameter_value(mi, "Metallic", entry["metallic"])
    MEL.set_material_instance_scalar_parameter_value(mi, "Roughness", entry["roughness"])
    MEL.set_material_instance_vector_parameter_value(mi, "EmissiveColor", colour(entry["emissive"]))
    MEL.set_material_instance_scalar_parameter_value(mi, "GlowStrength", entry["strength"])
    MEL.update_material_instance(mi)
    EAL.save_loaded_asset(mi)
    return mi


def keeper_meshes(kid):
    paths = ["{}/SM_Keeper_{}".format(MESH_DIR, camel(kid))]
    anim = "{}/SM_Keeper_{}".format(ANIM_DIR, camel(kid))
    if EAL.does_directory_exist(anim):
        paths += [p.split(".")[0] for p in EAL.list_assets(anim, recursive=False, include_folder=False)]
    meshes = []
    for path in paths:
        if EAL.does_asset_exist(path):
            asset = EAL.load_asset(path)
            if isinstance(asset, unreal.StaticMesh):
                meshes.append(asset)
    if not meshes:
        raise RuntimeError("no models for {} (run create_keepers.py first)".format(kid))
    return meshes


def slot_name(slot):
    name = str(slot.get_editor_property("material_slot_name") or "")
    if not name or name == "None":
        material = slot.get_editor_property("material_interface")
        name = material.get_name() if material else ""
    return name


def apply(kid, instances):
    glowing = 0
    for mesh in keeper_meshes(kid):
        slots = list(mesh.get_editor_property("static_materials"))
        changed = False
        for slot in slots:
            name = slot_name(slot)
            mi = instances.get((name, kid)) or instances.get((name, None))
            if mi is not None and slot.get_editor_property("material_interface") != mi:
                slot.set_editor_property("material_interface", mi)
                changed = True
            glowing += mi is not None
        if changed:
            mesh.set_editor_property("static_materials", slots)
            EAL.save_loaded_asset(mesh)
    log("{}: {} glowing slots".format(camel(kid), glowing))


def main():
    path = GLOW_JSON or os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)),
                                                      "..", "Content", "Keepers", "keeper_glows.json"))
    if not os.path.isfile(path):
        unreal.log_error("[SunderKeeperGlow] not found: {} (run blender/keepers.py <dir> 0 --glows)".format(path))
        return
    with open(path) as fh:
        data = json.load(fh)
    EAL.make_directory(MAT_DIR)
    master = step("M_Keeper_Glow (lit, pulsing emissive)", build_master)
    if master is None:
        return
    instances = {}
    for name, entry in sorted(data["materials"].items()):
        mi = step("MI_KeeperGlow_" + name, build_instance, "MI_KeeperGlow_" + name, entry, master)
        if mi is not None:
            instances[(name, None)] = mi
    for kid, own in sorted(data.get("keepers", {}).items()):
        for name, entry in sorted(own.items()):
            label = "MI_KeeperGlow_{}_{}".format(name, camel(kid))
            mi = step(label, build_instance, label, entry, master)
            if mi is not None:
                instances[(name, kid)] = mi
    for kid in KEEPERS:
        step("BP_Keeper_{}: glowing materials on its model and parts".format(camel(kid)), apply, kid, instances)
    MANUAL.append("Open the Codex on a Keeper you've met: its crystal, cores and eyes should glow and breathe as in "
                  "web/keepers.html. In the arena they glow steadily (GlowPulse 1)")
    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)


main()
