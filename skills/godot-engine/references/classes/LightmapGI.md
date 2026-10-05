# LightmapGI

**Inherits:** VisualInstance3D

Computes and stores baked lightmaps for fast global illumination.

The LightmapGI node is used to compute and store baked lightmaps. Lightmaps are used to provide high-quality indirect lighting with very little light leaking. LightmapGI can also provide rough reflections using spherical harmonics if `directional` is enabled. Dynamic objects can receive indirect lighting thanks to light probes, which can be automatically placed by setting `generate_probes_subdiv` to a value other than `GENERATE_PROBES_DISABLED`.

## Properties

- `bias: float` = `0.0005` — The bias to use when computing shadows.
- `bounce_indirect_energy: float` = `1.0` — The energy multiplier for each bounce.
- `bounces: int` = `3` — Number of light bounces that are taken into account during baking.
- `camera_attributes: CameraAttributes` — The CameraAttributes resource that specifies exposure levels to bake at.
- `denoiser_range: int` = `10` — The distance in pixels from which the denoiser samples.
- `denoiser_strength: float` = `0.1` — The strength of denoising step applied to the generated lightmaps.
- `directional: bool` = `false` — If `true`, bakes lightmaps to contain directional information as spherical harmonics.
- `environment_custom_color: Color` = `Color(1, 1, 1, 1)` — The color to use for environment lighting.
- `environment_custom_energy: float` = `1.0` — The color multiplier to use for environment lighting.
- `environment_custom_sky: Sky` — The sky to use as a source of environment lighting.
- `environment_mode: LightmapGI.EnvironmentMode` = `1` — The environment mode to use when baking lightmaps.
- `generate_probes_subdiv: LightmapGI.GenerateProbes` = `2` — The level of subdivision to use when automatically generating LightmapProbes for dynamic object lighting.
- `interior: bool` = `false` — If `true`, ignore environment lighting when baking lightmaps.
- `light_data: LightmapGIData` — The LightmapGIData associated to this LightmapGI node.
- `max_texture_size: int` = `16384` — The maximum texture size for the generated texture atlas.
- `quality: LightmapGI.BakeQuality` = `1` — The quality preset to use when baking lightmaps.
- `shadowmask_mode: LightmapGIData.ShadowmaskMode` = `0` — The shadowmasking policy to use for directional shadows on static objects that are baked with this LightmapGI instance.
- `specular_intensity: float` = `0.0` — The strength of the lightmap's approximated specular lobe.
- `supersampling: bool` = `false` — If `true`, lightmaps are baked with the texel scale multiplied with `supersampling_factor` and downsampled before saving the lightmap (so the effective texel density is identical to having supersampling disabled).
- `supersampling_factor: float` = `2.0` — The factor by which the texel density is multiplied for supersampling.
- `texel_scale: float` = `1.0` — Scales the lightmap texel density of all meshes for the current bake.
- `use_denoiser: bool` = `true` — If `true`, uses a GPU-based denoising algorithm on the generated lightmap.
- `use_texture_for_bounces: bool` = `true` — If `true`, a texture with the lighting information will be generated to speed up the generation of indirect lighting at the cost of some accuracy.

## Enum BakeQuality

- `BAKE_QUALITY_LOW = 0` — Low bake quality (fastest bake times).
- `BAKE_QUALITY_MEDIUM = 1` — Medium bake quality (fast bake times).
- `BAKE_QUALITY_HIGH = 2` — High bake quality (slow bake times).
- `BAKE_QUALITY_ULTRA = 3` — Highest bake quality (slowest bake times).

## Enum GenerateProbes

- `GENERATE_PROBES_DISABLED = 0` — Don't generate additional lightmap probes for lighting dynamic objects.
- `GENERATE_PROBES_SUBDIV_4 = 1` — Lowest level of subdivision (fastest bake times, smallest file sizes).
- `GENERATE_PROBES_SUBDIV_8 = 2` — Low level of subdivision (fast bake times, small file sizes).
- `GENERATE_PROBES_SUBDIV_16 = 3` — High level of subdivision (slow bake times, large file sizes).
- `GENERATE_PROBES_SUBDIV_32 = 4` — Highest level of subdivision (slowest bake times, largest file sizes).

## Enum BakeError

- `BAKE_ERROR_OK = 0` — Lightmap baking was successful.
- `BAKE_ERROR_NO_SCENE_ROOT = 1` — Lightmap baking failed because the root node for the edited scene could not be accessed.
- `BAKE_ERROR_FOREIGN_DATA = 2` — Lightmap baking failed as the lightmap data resource is embedded in a foreign resource.
- `BAKE_ERROR_NO_LIGHTMAPPER = 3` — Lightmap baking failed as there is no lightmapper available in this Godot build.
- `BAKE_ERROR_NO_SAVE_PATH = 4` — Lightmap baking failed as the LightmapGIData save path isn't configured in the resource.
- `BAKE_ERROR_NO_MESHES = 5` — Lightmap baking failed as there are no meshes whose `GeometryInstance3D.gi_mode` is `GeometryInstance3D.GI_MODE_STATIC` and with valid UV2 mapping in the current scene.
- `BAKE_ERROR_MESHES_INVALID = 6` — Lightmap baking failed as the lightmapper failed to analyze some of the meshes marked as static for baking.
- `BAKE_ERROR_CANT_CREATE_IMAGE = 7` — Lightmap baking failed as the resulting image couldn't be saved or imported by Godot after it was saved.
- `BAKE_ERROR_USER_ABORTED = 8` — The user aborted the lightmap baking operation (typically by clicking the Cancel button in the progress dialog).
- `BAKE_ERROR_TEXTURE_SIZE_TOO_SMALL = 9` — Lightmap baking failed as the maximum texture size is too small to fit some of the meshes marked for baking.
- `BAKE_ERROR_LIGHTMAP_TOO_SMALL = 10` — Lightmap baking failed as the lightmap is too small.
- `BAKE_ERROR_ATLAS_TOO_SMALL = 11` — Lightmap baking failed as the lightmap was unable to fit into an atlas.

## Enum EnvironmentMode

- `ENVIRONMENT_MODE_DISABLED = 0` — Ignore environment lighting when baking lightmaps.
- `ENVIRONMENT_MODE_SCENE = 1` — Use the scene's environment lighting when baking lightmaps.
- `ENVIRONMENT_MODE_CUSTOM_SKY = 2` — Use `environment_custom_sky` as a source of environment lighting when baking lightmaps.
- `ENVIRONMENT_MODE_CUSTOM_COLOR = 3` — Use `environment_custom_color` multiplied by `environment_custom_energy` as a constant source of environment lighting when baking lightmaps.
