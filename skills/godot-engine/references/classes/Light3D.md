# Light3D

**Inherits:** VisualInstance3D

Provides a base class for different kinds of light nodes.

Light3D is the abstract base class for light nodes. As it can't be instantiated, it shouldn't be used directly. Other types of light nodes inherit from it. Light3D contains the common variables and parameters used for lighting.

## Properties

- `distance_fade_begin: float` = `40.0` — The distance from the camera at which the light begins to fade away (in 3D units).
- `distance_fade_enabled: bool` = `false` — If `true`, the light will smoothly fade away when far from the active Camera3D starting at `distance_fade_begin`.
- `distance_fade_length: float` = `10.0` — Distance over which the light and its shadow fades.
- `distance_fade_shadow: float` = `50.0` — The distance from the camera at which the light's shadow cuts off (in 3D units).
- `editor_only: bool` = `false` — If `true`, the light only appears in the editor and will not be visible at runtime.
- `light_angular_distance: float` = `0.0` — The light's angular size in degrees.
- `light_bake_mode: Light3D.BakeMode` = `2` — The light's bake mode.
- `light_color: Color` = `Color(1, 1, 1, 1)` — The light's color in nonlinear sRGB encoding.
- `light_cull_mask: int` = `4294967295` — The light will affect objects in the selected layers.
- `light_energy: float` = `1.0` — The light's strength multiplier (this is not a physical unit).
- `light_indirect_energy: float` = `1.0` — Secondary multiplier used with indirect light (light bounces).
- `light_intensity_lumens: float` — Used by positional lights (OmniLight3D and SpotLight3D) when `ProjectSettings.rendering/lights_and_shadows/use_physical_light_units` is `true`.
- `light_intensity_lux: float` — Used by DirectionalLight3Ds when `ProjectSettings.rendering/lights_and_shadows/use_physical_light_units` is `true`.
- `light_negative: bool` = `false` — If `true`, the light's effect is reversed, darkening areas and casting bright shadows.
- `light_projector: Texture2D` — Texture2D projected by light.
- `light_size: float` = `0.0` — The simulated size of the light in Godot units, affecting shading and shadows.
- `light_specular: float` = `1.0` — The intensity of the specular blob in objects affected by the light.
- `light_temperature: float` — Sets the color temperature of the light source, measured in Kelvin.
- `light_volumetric_fog_energy: float` = `1.0` — Secondary multiplier multiplied with `light_energy` then used with the Environment's volumetric fog (if enabled).
- `shadow_bias: float` = `0.1` — Used to adjust shadow appearance.
- `shadow_blur: float` = `1.0` — Blurs the edges of the shadow.
- `shadow_caster_mask: int` = `4294967295` — The light will only cast shadows using objects in the selected layers.
- `shadow_contact_shadows_allow: bool` = `true` — Enables screen-space contact shadows for this light.
- `shadow_contact_shadows_blur: float` = `1.0` — Blurs the edges of the contact shadow.
- `shadow_contact_shadows_opacity: float` = `1.0` — Changes the opacity of this light's screen-space contact shadows.
- `shadow_enabled: bool` = `false` — If `true`, the light will cast real-time shadows.
- `shadow_normal_bias: float` = `2.0` — Offsets the lookup into the shadow map by the object's normal.
- `shadow_opacity: float` = `1.0` — The opacity to use when rendering the light's shadow map.
- `shadow_reverse_cull_face: bool` = `false` — If `true`, reverses the backface culling of the mesh.
- `shadow_transmittance_bias: float` = `0.05` — 

## Methods

- `get_correlated_color() -> Color` *const* — Returns the Color of an idealized blackbody at the given `light_temperature`.
- `get_param(param: Light3D.Param) -> float` *const* — Returns the value of the specified `Light3D.Param` parameter.
- `set_param(param: Light3D.Param, value: float) -> void` — Sets the value of the specified `Light3D.Param` parameter.

## Enum Param

- `PARAM_ENERGY = 0` — Constant for accessing `light_energy`.
- `PARAM_INDIRECT_ENERGY = 1` — Constant for accessing `light_indirect_energy`.
- `PARAM_VOLUMETRIC_FOG_ENERGY = 2` — Constant for accessing `light_volumetric_fog_energy`.
- `PARAM_SPECULAR = 3` — Constant for accessing `light_specular`.
- `PARAM_RANGE = 4` — Constant for accessing `OmniLight3D.omni_range` or `SpotLight3D.spot_range`.
- `PARAM_SIZE = 5` — Constant for accessing `light_size`.
- `PARAM_ATTENUATION = 6` — Constant for accessing `OmniLight3D.omni_attenuation` or `SpotLight3D.spot_attenuation`.
- `PARAM_SPOT_ANGLE = 7` — Constant for accessing `SpotLight3D.spot_angle`.
- `PARAM_SPOT_ATTENUATION = 8` — Constant for accessing `SpotLight3D.spot_angle_attenuation`.
- `PARAM_SHADOW_MAX_DISTANCE = 9` — Constant for accessing `DirectionalLight3D.directional_shadow_max_distance`.
- `PARAM_SHADOW_SPLIT_1_OFFSET = 10` — Constant for accessing `DirectionalLight3D.directional_shadow_split_1`.
- `PARAM_SHADOW_SPLIT_2_OFFSET = 11` — Constant for accessing `DirectionalLight3D.directional_shadow_split_2`.
- `PARAM_SHADOW_SPLIT_3_OFFSET = 12` — Constant for accessing `DirectionalLight3D.directional_shadow_split_3`.
- `PARAM_SHADOW_FADE_START = 13` — Constant for accessing `DirectionalLight3D.directional_shadow_fade_start`.
- `PARAM_SHADOW_NORMAL_BIAS = 14` — Constant for accessing `shadow_normal_bias`.
- `PARAM_SHADOW_BIAS = 15` — Constant for accessing `shadow_bias`.
- `PARAM_SHADOW_PANCAKE_SIZE = 16` — Constant for accessing `DirectionalLight3D.directional_shadow_pancake_size`.
- `PARAM_SHADOW_OPACITY = 17` — Constant for accessing `shadow_opacity`.
- `PARAM_SHADOW_BLUR = 18` — Constant for accessing `shadow_blur`.
- `PARAM_TRANSMITTANCE_BIAS = 19` — Constant for accessing `shadow_transmittance_bias`.
- `PARAM_INTENSITY = 20` — Constant for accessing `light_intensity_lumens` and `light_intensity_lux`.
- `PARAM_CONTACT_SHADOW_OPACITY = 21` — Constant for accessing `shadow_contact_shadows_opacity`.
- `PARAM_CONTACT_SHADOW_BLUR = 22` — Constant for accessing `shadow_contact_shadows_blur`.
- `PARAM_MAX = 23` — Represents the size of the `Param` enum.

## Enum BakeMode

- `BAKE_DISABLED = 0` — Light is ignored when baking.
- `BAKE_STATIC = 1` — Light is taken into account in static baking (VoxelGI, LightmapGI, SDFGI (`Environment.sdfgi_enabled`)).
- `BAKE_DYNAMIC = 2` — Light is taken into account in dynamic baking (VoxelGI and SDFGI (`Environment.sdfgi_enabled`)).
