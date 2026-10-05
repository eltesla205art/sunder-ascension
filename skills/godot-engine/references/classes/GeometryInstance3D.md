# GeometryInstance3D

**Inherits:** VisualInstance3D

Base node for geometry-based visual instances.

Base node for geometry-based visual instances. Shares some common functionality like visibility and custom materials.

## Properties

- `cast_shadow: GeometryInstance3D.ShadowCastingSetting` = `1` — The mode used to cast shadows from this instance.
- `custom_aabb: AABB` = `AABB(0, 0, 0, 0, 0, 0)` — Overrides the bounding box of this node with a custom one.
- `extra_cull_margin: float` = `0.0` — The extra distance added to the GeometryInstance3D's bounding box (AABB) to increase its cull box.
- `gi_lightmap_scale: GeometryInstance3D.LightmapScale` = `0` *(deprecated)* — The texel density to use for lightmapping in LightmapGI.
- `gi_lightmap_texel_scale: float` = `1.0` — The texel density to use for lightmapping in LightmapGI.
- `gi_mode: GeometryInstance3D.GIMode` = `1` — The global illumination mode to use for the whole geometry.
- `ignore_occlusion_culling: bool` = `false` — If `true`, disables occlusion culling for this instance.
- `lod_bias: float` = `1.0` — Changes how quickly the mesh transitions to a lower level of detail.
- `material_overlay: Material` — The material overlay for the whole geometry.
- `material_override: Material` — The material override for the whole geometry.
- `transparency: float` = `0.0` — The transparency applied to the whole geometry (as a multiplier of the materials' existing transparency).
- `visibility_range_begin: float` = `0.0` — Starting distance from which the GeometryInstance3D will be visible, taking `visibility_range_begin_margin` into account as well.
- `visibility_range_begin_margin: float` = `0.0` — Margin for the `visibility_range_begin` threshold.
- `visibility_range_end: float` = `0.0` — Distance from which the GeometryInstance3D will be hidden, taking `visibility_range_end_margin` into account as well.
- `visibility_range_end_margin: float` = `0.0` — Margin for the `visibility_range_end` threshold.
- `visibility_range_fade_mode: GeometryInstance3D.VisibilityRangeFadeMode` = `0` — Controls which instances will be faded when approaching the limits of the visibility range.

## Methods

- `get_instance_shader_parameter(name: StringName) -> Variant` *const* — Get the value of a shader parameter as set on this instance.
- `set_instance_shader_parameter(name: StringName, value: Variant) -> void` — Set the value of a shader uniform for this instance only (per-instance uniform).

## Enum ShadowCastingSetting

- `SHADOW_CASTING_SETTING_OFF = 0` — Will not cast any shadows.
- `SHADOW_CASTING_SETTING_ON = 1` — Will cast shadows from all visible faces in the GeometryInstance3D.
- `SHADOW_CASTING_SETTING_DOUBLE_SIDED = 2` — Will cast shadows from all visible faces in the GeometryInstance3D.
- `SHADOW_CASTING_SETTING_SHADOWS_ONLY = 3` — Will only show the shadows casted from this object.

## Enum GIMode

- `GI_MODE_DISABLED = 0` — Disabled global illumination mode.
- `GI_MODE_STATIC = 1` — Baked global illumination mode.
- `GI_MODE_DYNAMIC = 2` — Dynamic global illumination mode.

## Enum LightmapScale

- `LIGHTMAP_SCALE_1X = 0` — The standard texel density for lightmapping with LightmapGI.
- `LIGHTMAP_SCALE_2X = 1` — Multiplies texel density by 2× for lightmapping with LightmapGI.
- `LIGHTMAP_SCALE_4X = 2` — Multiplies texel density by 4× for lightmapping with LightmapGI.
- `LIGHTMAP_SCALE_8X = 3` — Multiplies texel density by 8× for lightmapping with LightmapGI.
- `LIGHTMAP_SCALE_MAX = 4` — Represents the size of the `LightmapScale` enum.

## Enum VisibilityRangeFadeMode

- `VISIBILITY_RANGE_FADE_DISABLED = 0` — Will not fade itself nor its visibility dependencies, hysteresis will be used instead.
- `VISIBILITY_RANGE_FADE_SELF = 1` — Will fade-out itself when reaching the limits of its own visibility range.
- `VISIBILITY_RANGE_FADE_DEPENDENCIES = 2` — Will fade-in its visibility dependencies (see `Node3D.visibility_parent`) when reaching the limits of its own visibility range.
