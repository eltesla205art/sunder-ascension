"""SUNDER: Ascension II — the Codex viewer's stars and fog (the sky of web/keepers.html).

Run inside the Unreal Editor (Tools → Execute Python Script…) with the C++ in unreal/Source compiled. Makes, under
/Game/Sunder/UI/Codex:
  M_Codex_Star   unlit, the web stars' pale blue (#cfd6ff at 0.8): ASunderCodexStage scatters 900 of them on a dome
                 40-70 m out, as keepers.html does, turning with the Keeper as the web camera orbits under them;
                 the plinth's glowing seam wears it too, its colour breathing pink
  PP_Codex_Fog   a post-process material for the viewer's capture: three.js's Fog(0x16102e, 14, 34), a linear fade to
                 the sky's indigo from 14 m to 34 m from the camera, on the Keeper and its plinth only (they write
                 custom depth; the sky and the stars don't, as three.js leaves the background and the stars unfogged)
The stage picks them up by path when it is first made; without them the sky is bare and clear and the seam is missing.
The fog needs Project Settings → Rendering → Custom Depth-Stencil Pass = Enabled (the default).

Safe to run again. Untested until its first run.
"""
import unreal

DIR = "/Game/Sunder/UI/Codex"
U = 60.0                                          # the stage's units per web metre
STAR = (0.624 * 0.8, 0.672 * 0.8, 1.0 * 0.8)      # #cfd6ff, linear, at the points' 0.8 opacity
FOG = (0.0080, 0.0052, 0.0273)                    # #16102e, linear
FOG_NEAR, FOG_FAR = 14.0 * U, 34.0 * U

FOG_HLSL = """float m = Custom.r < Depth.r + 2.0 ? 1.0 : 0.0;   // only what wrote custom depth: the Keeper and plinth
float f = saturate((Depth.r - Near) / max(Far - Near, 1.0)) * m;
return lerp(InColor.rgb, FogColor.rgb, f);"""

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
MEL = unreal.MaterialEditingLibrary
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []


def log(msg):
    unreal.log("[SunderCodexViewer] " + msg)


def step(label, fn, *args):
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:   # the editor's Python API differs a little between versions
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderCodexViewer] {} failed: {}".format(label, exc))
        return None


def fresh_material(name):
    full = "{}/{}".format(DIR, name)
    mat = EAL.load_asset(full) if EAL.does_asset_exist(full) else \
        TOOLS.create_asset(name, DIR, unreal.Material, unreal.MaterialFactoryNew())
    if mat is None:
        raise RuntimeError("could not create " + full)
    MEL.delete_all_material_expressions(mat)
    return mat


def vector(mat, name, rgb, x, y):
    e = MEL.create_material_expression(mat, unreal.MaterialExpressionVectorParameter, x, y)
    e.set_editor_property("parameter_name", name)
    e.set_editor_property("default_value", unreal.LinearColor(rgb[0], rgb[1], rgb[2], 1.0))
    return e


def scalar(mat, name, value, x, y):
    e = MEL.create_material_expression(mat, unreal.MaterialExpressionScalarParameter, x, y)
    e.set_editor_property("parameter_name", name)
    e.set_editor_property("default_value", value)
    return e


def finish(mat):
    MEL.layout_material_expressions(mat)
    MEL.recompile_material(mat)
    EAL.save_loaded_asset(mat)
    return mat


def build_star():
    mat = fresh_material("M_Codex_Star")
    mat.set_editor_property("shading_model", unreal.MaterialShadingModel.MSM_UNLIT)
    try:
        mat.set_editor_property("used_with_instanced_static_meshes", True)
    except Exception as exc:
        MANUAL.append("M_Codex_Star: tick Usage → Used with Instanced Static Meshes  ({})".format(exc))
    if not MEL.connect_material_property(vector(mat, "Color", STAR, -400, 0), "", unreal.MaterialProperty.MP_EMISSIVE_COLOR):
        raise RuntimeError("could not connect the star colour")
    return finish(mat)


def scene_texture(mat, which, x, y):
    e = MEL.create_material_expression(mat, unreal.MaterialExpressionSceneTexture, x, y)
    e.set_editor_property("scene_texture_id", which)
    return e


def build_fog():
    mat = fresh_material("PP_Codex_Fog")
    mat.set_editor_property("material_domain", unreal.MaterialDomain.MD_POST_PROCESS)
    for location in ("BL_SCENE_COLOR_AFTER_DOF", "BL_BEFORE_TONEMAPPING"):   # the name changed in UE 5.1
        if hasattr(unreal.BlendableLocation, location):
            mat.set_editor_property("blendable_location", getattr(unreal.BlendableLocation, location))
            break
    custom = MEL.create_material_expression(mat, unreal.MaterialExpressionCustom, -200, 0)
    custom.set_editor_property("code", FOG_HLSL)
    custom.set_editor_property("output_type", unreal.CustomMaterialOutputType.CMOT_FLOAT3)
    custom.set_editor_property("description", "CodexFog")
    pins = []
    for name in ("InColor", "Depth", "Custom", "Near", "Far", "FogColor"):
        pin = unreal.CustomInput()
        pin.set_editor_property("input_name", name)
        pins.append(pin)
    custom.set_editor_property("inputs", pins)
    sources = (
        ("InColor", scene_texture(mat, unreal.SceneTextureId.PPI_POST_PROCESS_INPUT0, -700, -300), "Color"),
        ("Depth", scene_texture(mat, unreal.SceneTextureId.PPI_SCENE_DEPTH, -700, -150), "Color"),
        ("Custom", scene_texture(mat, unreal.SceneTextureId.PPI_CUSTOM_DEPTH, -700, 0), "Color"),
        ("Near", scalar(mat, "FogNear", FOG_NEAR, -700, 150), ""),
        ("Far", scalar(mat, "FogFar", FOG_FAR, -700, 230), ""),
        ("FogColor", vector(mat, "FogColor", FOG, -700, 310), ""),
    )
    for pin, src, out in sources:
        if not MEL.connect_material_expressions(src, out, custom, pin):
            raise RuntimeError("could not connect " + pin)
    if not MEL.connect_material_property(custom, "", unreal.MaterialProperty.MP_EMISSIVE_COLOR):
        raise RuntimeError("could not connect the fog to Emissive Color")
    return finish(mat)


def main():
    EAL.make_directory(DIR)
    step("M_Codex_Star (the web sky's stars)", build_star)
    step("PP_Codex_Fog (three.js Fog 0x16102e, 14-34 m, on the Keeper and plinth)", build_fog)
    MANUAL.append("Open the Codex on a Keeper you've met: stars over the indigo sky, turning with the Keeper; the back "
                  "of the plinth fading a little into the sky's colour. (The stage is made once per level: restart the "
                  "level to see newly made assets.)")
    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)


main()
