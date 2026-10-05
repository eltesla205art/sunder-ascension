# BaseMaterial3D

**Inherits:** Material

Abstract base class for defining the 3D rendering properties of meshes.

This class serves as a default material with a wide variety of rendering features and properties without the need to write shader code. See the tutorial below for details.

## Properties

- `albedo_color: Color` = `Color(1, 1, 1, 1)` — The material's base color.
- `albedo_texture: Texture2D` — Texture to multiply by `albedo_color`.
- `albedo_texture_force_srgb: bool` = `false` — If `true`, forces a conversion of the `albedo_texture` from nonlinear sRGB encoding to linear encoding.
- `albedo_texture_msdf: bool` = `false` — Enables multichannel signed distance field rendering shader.
- `alpha_antialiasing_edge: float` — Threshold at which antialiasing will be applied on the alpha channel.
- `alpha_antialiasing_mode: BaseMaterial3D.AlphaAntiAliasing` — The type of alpha antialiasing to apply.
- `alpha_hash_scale: float` — The hashing scale for Alpha Hash.
- `alpha_scissor_threshold: float` — Threshold at which the alpha scissor will discard values.
- `anisotropy: float` = `0.0` — The strength of the anisotropy effect.
- `anisotropy_enabled: bool` = `false` — If `true`, anisotropy is enabled.
- `anisotropy_flowmap: Texture2D` — Texture that offsets the tangent map for anisotropy calculations and optionally controls the anisotropy effect (if an alpha channel is present).
- `ao_enabled: bool` = `false` — If `true`, ambient occlusion is enabled.
- `ao_light_affect: float` = `0.0` — Amount that ambient occlusion affects lighting from lights.
- `ao_on_uv2: bool` = `false` — If `true`, use `UV2` coordinates to look up from the `ao_texture`.
- `ao_texture: Texture2D` — Texture that defines the amount of ambient occlusion for a given point on the object.
- `ao_texture_channel: BaseMaterial3D.TextureChannel` = `0` — Specifies the channel of the `ao_texture` in which the ambient occlusion information is stored.
- `backlight: Color` = `Color(0, 0, 0, 1)` — The color used by the backlight effect.
- `backlight_enabled: bool` = `false` — If `true`, the backlight effect is enabled.
- `backlight_texture: Texture2D` — Texture used to control the backlight effect per-pixel.
- `bent_normal_enabled: bool` = `false` — If `true`, the bent normal map is enabled.
- `bent_normal_texture: Texture2D` — Texture that specifies the average direction of incoming ambient light at a given pixel.
- `billboard_keep_scale: bool` = `false` — If `true`, the shader will keep the scale set for the mesh.
- `billboard_mode: BaseMaterial3D.BillboardMode` = `0` — Controls how the object faces the camera.
- `blend_mode: BaseMaterial3D.BlendMode` = `0` — The material's blend mode.
- `clearcoat: float` = `1.0` — Sets the strength of the clearcoat effect.
- `clearcoat_enabled: bool` = `false` — If `true`, clearcoat rendering is enabled.
- `clearcoat_roughness: float` = `0.5` — Sets the roughness of the clearcoat pass.
- `clearcoat_texture: Texture2D` — Texture that defines the strength of the clearcoat effect and the glossiness of the clearcoat.
- `cull_mode: BaseMaterial3D.CullMode` = `0` — Determines which side of the triangle to cull depending on whether the triangle faces towards or away from the camera.
- `depth_draw_mode: BaseMaterial3D.DepthDrawMode` = `0` — Determines when depth rendering takes place.
- `depth_test: BaseMaterial3D.DepthTest` = `0` — Determines which comparison operator is used when testing depth.
- `detail_albedo: Texture2D` — Texture that specifies the color of the detail overlay.
- `detail_blend_mode: BaseMaterial3D.BlendMode` = `0` — Specifies how the `detail_albedo` should blend with the current `ALBEDO`.
- `detail_enabled: bool` = `false` — If `true`, enables the detail overlay.
- `detail_mask: Texture2D` — Texture used to specify how the detail textures get blended with the base textures.
- `detail_normal: Texture2D` — Texture that specifies the per-pixel normal of the detail overlay.
- `detail_uv_layer: BaseMaterial3D.DetailUV` = `0` — Specifies whether to use `UV` or `UV2` for the detail layer.
- `diffuse_mode: BaseMaterial3D.DiffuseMode` = `0` — The algorithm used for diffuse light scattering.
- `disable_ambient_light: bool` = `false` — If `true`, the object receives no ambient light.
- `disable_fog: bool` = `false` — If `true`, the object will not be affected by fog (neither volumetric nor depth fog).
- `disable_receive_shadows: bool` = `false` — If `true`, the object receives no shadow that would otherwise be cast onto it.
- `disable_specular_occlusion: bool` = `false` — If `true`, disables specular occlusion even if `ProjectSettings.rendering/reflections/specular_occlusion/enabled` is `false`.
- `distance_fade_max_distance: float` = `10.0` — Distance at which the object appears fully opaque.
- `distance_fade_min_distance: float` = `0.0` — Distance at which the object starts to become visible.
- `distance_fade_mode: BaseMaterial3D.DistanceFadeMode` = `0` — Specifies which type of fade to use.
- `emission: Color` = `Color(0, 0, 0, 1)` — The emitted light's color.
- `emission_enabled: bool` = `false` — If `true`, the body emits light.
- `emission_energy_multiplier: float` = `1.0` — Multiplier for emitted light.
- `emission_intensity: float` — Luminance of emitted light, measured in nits (candela per square meter).
- `emission_on_uv2: bool` = `false` — Use `UV2` to read from the `emission_texture`.
- `emission_operator: BaseMaterial3D.EmissionOperator` = `0` — Sets how `emission` interacts with `emission_texture`.
- `emission_texture: Texture2D` — Texture that specifies how much surface emits light at a given point.
- `fixed_size: bool` = `false` — If `true`, the object is rendered at the same size regardless of distance.
- `fov_override: float` = `75.0` — Overrides the Camera3D's field of view angle (in degrees).
- `grow: bool` = `false` — If `true`, enables the vertex grow setting.
- `grow_amount: float` = `0.0` — Grows object vertices in the direction of their normals.
- `heightmap_deep_parallax: bool` = `false` — If `true`, uses parallax occlusion mapping to represent depth in the material instead of simple offset mapping (see `heightmap_enabled`).
- `heightmap_enabled: bool` = `false` — If `true`, height mapping is enabled (also called "parallax mapping" or "depth mapping").
- `heightmap_flip_binormal: bool` = `false` — If `true`, flips the mesh's binormal vectors when interpreting the height map.
- `heightmap_flip_tangent: bool` = `false` — If `true`, flips the mesh's tangent vectors when interpreting the height map.
- `heightmap_flip_texture: bool` = `false` — If `true`, interprets the height map texture as a depth map, with brighter values appearing to be "lower" in altitude compared to darker values.
- `heightmap_max_layers: int` — The number of layers to use for parallax occlusion mapping when the camera is up close to the material.
- `heightmap_min_layers: int` — The number of layers to use for parallax occlusion mapping when the camera is far away from the material.
- `heightmap_scale: float` = `5.0` — The heightmap scale to use for the parallax effect (see `heightmap_enabled`).
- `heightmap_texture: Texture2D` — The texture to use as a height map.
- `metallic: float` = `0.0` — A high value makes the material appear more like a metal.
- `metallic_specular: float` = `0.5` — Adjusts the strength of specular reflections.
- `metallic_texture: Texture2D` — Texture used to specify metallic for an object.
- `metallic_texture_channel: BaseMaterial3D.TextureChannel` = `0` — Specifies the channel of the `metallic_texture` in which the metallic information is stored.
- `msdf_outline_size: float` = `0.0` — The width of the shape outline.
- `msdf_pixel_range: float` = `4.0` — The width of the range around the shape between the minimum and maximum representable signed distance.
- `no_depth_test: bool` = `false` — If `true`, depth testing is disabled and the object will be drawn in render order.
- `normal_enabled: bool` = `false` — If `true`, normal mapping is enabled.
- `normal_scale: float` = `1.0` — The strength of the normal map's effect.
- `normal_texture: Texture2D` — Texture used to specify the normal at a given pixel.
- `orm_texture: Texture2D` — The Occlusion/Roughness/Metallic texture to use.
- `particles_anim_enabled: bool` = `false` — If `true`, enables `particles_anim_*` properties.
- `particles_anim_h_frames: int` = `1` — The number of horizontal frames in the particle sprite sheet.
- `particles_anim_loop: bool` = `false` — If `true`, particle animations are looped.
- `particles_anim_v_frames: int` = `1` — The number of vertical frames in the particle sprite sheet.
- `point_size: float` = `1.0` — The point size in pixels.
- `proximity_fade_distance: float` = `1.0` — Distance over which the fade effect takes place.
- `proximity_fade_enabled: bool` = `false` — If `true`, the proximity fade effect is enabled.
- `refraction_enabled: bool` = `false` — If `true`, the refraction effect is enabled.
- `refraction_scale: float` = `0.05` — The strength of the refraction effect.
- `refraction_texture: Texture2D` — Texture that controls the strength of the refraction per-pixel.
- `refraction_texture_channel: BaseMaterial3D.TextureChannel` = `0` — Specifies the channel of the `refraction_texture` in which the refraction information is stored.
- `rim: float` = `1.0` — Sets the strength of the rim lighting effect.
- `rim_enabled: bool` = `false` — If `true`, rim effect is enabled.
- `rim_texture: Texture2D` — Texture used to set the strength of the rim lighting effect per-pixel.
- `rim_tint: float` = `0.5` — The amount of to blend light and albedo color when rendering rim effect.
- `roughness: float` = `1.0` — Surface reflection.
- `roughness_texture: Texture2D` — Texture used to control the roughness per-pixel.
- `roughness_texture_channel: BaseMaterial3D.TextureChannel` = `0` — Specifies the channel of the `roughness_texture` in which the roughness information is stored.
- `shading_mode: BaseMaterial3D.ShadingMode` = `1` — Sets whether the shading takes place, per-pixel, per-vertex or unshaded.
- `shadow_to_opacity: bool` = `false` — If `true`, enables the "shadow to opacity" render mode where lighting modifies the alpha so shadowed areas are opaque and non-shadowed areas are transparent.
- `specular_mode: BaseMaterial3D.SpecularMode` = `0` — The method for rendering the specular blob.
- `stencil_color: Color` = `Color(0, 0, 0, 1)` — The primary color of the stencil effect.
- `stencil_compare: BaseMaterial3D.StencilCompare` = `0` — The comparison operator to use for stencil masking operations.
- `stencil_flags: int` = `0` — The flags dictating how the stencil operation behaves.
- `stencil_mode: BaseMaterial3D.StencilMode` = `0` — The stencil effect mode.
- `stencil_outline_thickness: float` = `0.01` — The outline thickness for `STENCIL_MODE_OUTLINE`.
- `stencil_reference: int` = `1` — The stencil reference value (0-255).
- `subsurf_scatter_enabled: bool` = `false` — If `true`, subsurface scattering is enabled.
- `subsurf_scatter_skin_mode: bool` = `false` — If `true`, subsurface scattering will use a special mode optimized for the color and density of human skin, such as boosting the intensity of the red channel in subsurface scattering.
- `subsurf_scatter_strength: float` = `0.0` — The strength of the subsurface scattering effect.
- `subsurf_scatter_texture: Texture2D` — Texture used to control the subsurface scattering strength.
- `subsurf_scatter_transmittance_boost: float` = `0.0` — The intensity of the subsurface scattering transmittance effect.
- `subsurf_scatter_transmittance_color: Color` = `Color(1, 1, 1, 1)` — The color to multiply the subsurface scattering transmittance effect with.
- `subsurf_scatter_transmittance_depth: float` = `0.1` — The depth of the subsurface scattering transmittance effect.
- `subsurf_scatter_transmittance_enabled: bool` = `false` — If `true`, enables subsurface scattering transmittance.
- `subsurf_scatter_transmittance_texture: Texture2D` — The texture to use for multiplying the intensity of the subsurface scattering transmittance intensity.
- `texture_filter: BaseMaterial3D.TextureFilter` = `3` — Filter flags for the texture.
- `texture_repeat: bool` = `true` — If `true`, the texture repeats when exceeding the texture's size.
- `transparency: BaseMaterial3D.Transparency` = `0` — The material's transparency mode.
- `use_fov_override: bool` = `false` — If `true` use `fov_override` to override the Camera3D's field of view angle.
- `use_particle_trails: bool` = `false` — If `true`, enables parts of the shader required for GPUParticles3D trails to function.
- `use_point_size: bool` = `false` — If `true`, render point size can be changed.
- `use_z_clip_scale: bool` = `false` — If `true` use `z_clip_scale` to scale the object being rendered towards the camera to avoid clipping into things like walls.
- `uv1_offset: Vector3` = `Vector3(0, 0, 0)` — How much to offset the `UV` coordinates.
- `uv1_scale: Vector3` = `Vector3(1, 1, 1)` — How much to scale the `UV` coordinates.
- `uv1_triplanar: bool` = `false` — If `true`, instead of using `UV` textures will use a triplanar texture lookup to determine how to apply textures.
- `uv1_triplanar_sharpness: float` = `1.0` — A lower number blends the texture more softly while a higher number blends the texture more sharply.
- `uv1_world_triplanar: bool` = `false` — If `true`, triplanar mapping for `UV` is calculated in world space rather than object local space.
- `uv2_offset: Vector3` = `Vector3(0, 0, 0)` — How much to offset the `UV2` coordinates.
- `uv2_scale: Vector3` = `Vector3(1, 1, 1)` — How much to scale the `UV2` coordinates.
- `uv2_triplanar: bool` = `false` — If `true`, instead of using `UV2` textures will use a triplanar texture lookup to determine how to apply textures.
- `uv2_triplanar_sharpness: float` = `1.0` — A lower number blends the texture more softly while a higher number blends the texture more sharply.
- `uv2_world_triplanar: bool` = `false` — If `true`, triplanar mapping for `UV2` is calculated in world space rather than object local space.
- `vertex_color_is_srgb: bool` = `false` — If `true`, vertex colors are considered to be stored in nonlinear sRGB encoding and are converted to linear encoding during rendering.
- `vertex_color_use_as_albedo: bool` = `false` — If `true`, the vertex color is used as albedo color.
- `z_clip_scale: float` = `1.0` — Scales the object being rendered towards the camera to avoid clipping into things like walls.

## Methods

- `get_feature(feature: BaseMaterial3D.Feature) -> bool` *const* — Returns `true` if the specified `feature` is enabled.
- `get_flag(flag: BaseMaterial3D.Flags) -> bool` *const* — Returns `true` if the specified `flag` is enabled.
- `get_texture(param: BaseMaterial3D.TextureParam) -> Texture2D` *const* — Returns the Texture2D associated with the specified texture `param`.
- `set_feature(feature: BaseMaterial3D.Feature, enable: bool) -> void` — If `enable` is `true`, enables the specified `feature`.
- `set_flag(flag: BaseMaterial3D.Flags, enable: bool) -> void` — If `enable` is `true`, enables the specified `flag`.
- `set_texture(param: BaseMaterial3D.TextureParam, texture: Texture2D) -> void` — Sets the texture for the slot specified by `param`.

## Enum TextureParam

- `TEXTURE_ALBEDO = 0` — Texture specifying per-pixel color.
- `TEXTURE_METALLIC = 1` — Texture specifying per-pixel metallic value.
- `TEXTURE_ROUGHNESS = 2` — Texture specifying per-pixel roughness value.
- `TEXTURE_EMISSION = 3` — Texture specifying per-pixel emission color.
- `TEXTURE_NORMAL = 4` — Texture specifying per-pixel normal vector.
- `TEXTURE_BENT_NORMAL = 18` — Texture specifying per-pixel bent normal vector.
- `TEXTURE_RIM = 5` — Texture specifying per-pixel rim value.
- `TEXTURE_CLEARCOAT = 6` — Texture specifying per-pixel clearcoat value.
- `TEXTURE_FLOWMAP = 7` — Texture specifying per-pixel flowmap direction for use with `anisotropy`.
- `TEXTURE_AMBIENT_OCCLUSION = 8` — Texture specifying per-pixel ambient occlusion value.
- `TEXTURE_HEIGHTMAP = 9` — Texture specifying per-pixel height.
- `TEXTURE_SUBSURFACE_SCATTERING = 10` — Texture specifying per-pixel subsurface scattering.
- `TEXTURE_SUBSURFACE_TRANSMITTANCE = 11` — Texture specifying per-pixel transmittance for subsurface scattering.
- `TEXTURE_BACKLIGHT = 12` — Texture specifying per-pixel backlight color.
- `TEXTURE_REFRACTION = 13` — Texture specifying per-pixel refraction strength.
- `TEXTURE_DETAIL_MASK = 14` — Texture specifying per-pixel detail mask blending value.
- `TEXTURE_DETAIL_ALBEDO = 15` — Texture specifying per-pixel detail color.
- `TEXTURE_DETAIL_NORMAL = 16` — Texture specifying per-pixel detail normal.
- `TEXTURE_ORM = 17` — Texture holding ambient occlusion, roughness, and metallic.
- `TEXTURE_MAX = 19` — Represents the size of the `TextureParam` enum.

## Enum TextureFilter

- `TEXTURE_FILTER_NEAREST = 0` — The texture filter reads from the nearest pixel only.
- `TEXTURE_FILTER_LINEAR = 1` — The texture filter blends between the nearest 4 pixels.
- `TEXTURE_FILTER_NEAREST_WITH_MIPMAPS = 2` — The texture filter reads from the nearest pixel and blends between the nearest 2 mipmaps (or uses the nearest mipmap if `ProjectSettings.rendering/textures/default_filters/use_nearest_mipmap_filter` is `true`).
- `TEXTURE_FILTER_LINEAR_WITH_MIPMAPS = 3` — The texture filter blends between the nearest 4 pixels and between the nearest 2 mipmaps (or uses the nearest mipmap if `ProjectSettings.rendering/textures/default_filters/use_nearest_mipmap_filter` is `true`).
- `TEXTURE_FILTER_NEAREST_WITH_MIPMAPS_ANISOTROPIC = 4` — The texture filter reads from the nearest pixel and blends between 2 mipmaps (or uses the nearest mipmap if `ProjectSettings.rendering/textures/default_filters/use_nearest_mipmap_filter` is `true`) based on the angle between the surface and the camera view.
- `TEXTURE_FILTER_LINEAR_WITH_MIPMAPS_ANISOTROPIC = 5` — The texture filter blends between the nearest 4 pixels and blends between 2 mipmaps (or uses the nearest mipmap if `ProjectSettings.rendering/textures/default_filters/use_nearest_mipmap_filter` is `true`) based on the angle between the surface and the camera view.
- `TEXTURE_FILTER_MAX = 6` — Represents the size of the `TextureFilter` enum.

## Enum DetailUV

- `DETAIL_UV_1 = 0` — Use `UV` with the detail texture.
- `DETAIL_UV_2 = 1` — Use `UV2` with the detail texture.

## Enum Transparency

- `TRANSPARENCY_DISABLED = 0` — The material will not use transparency.
- `TRANSPARENCY_ALPHA = 1` — The material will use the texture's alpha values for transparency.
- `TRANSPARENCY_ALPHA_SCISSOR = 2` — The material will cut off all values below a threshold, the rest will remain opaque.
- `TRANSPARENCY_ALPHA_HASH = 3` — The material will cut off all values below a spatially-deterministic threshold, the rest will remain opaque.
- `TRANSPARENCY_ALPHA_DEPTH_PRE_PASS = 4` — The material will use the texture's alpha value for transparency, but will discard fragments with an alpha of less than 0.99 during the depth prepass and fragments with an alpha less than 0.1 during the shadow pass.
- `TRANSPARENCY_MAX = 5` — Represents the size of the `Transparency` enum.

## Enum ShadingMode

- `SHADING_MODE_UNSHADED = 0` — The object will not receive shadows.
- `SHADING_MODE_PER_PIXEL = 1` — The object will be shaded per pixel.
- `SHADING_MODE_PER_VERTEX = 2` — The object will be shaded per vertex.
- `SHADING_MODE_MAX = 3` — Represents the size of the `ShadingMode` enum.

## Enum Feature

- `FEATURE_EMISSION = 0` — Constant for setting `emission_enabled`.
- `FEATURE_NORMAL_MAPPING = 1` — Constant for setting `normal_enabled`.
- `FEATURE_RIM = 2` — Constant for setting `rim_enabled`.
- `FEATURE_CLEARCOAT = 3` — Constant for setting `clearcoat_enabled`.
- `FEATURE_ANISOTROPY = 4` — Constant for setting `anisotropy_enabled`.
- `FEATURE_AMBIENT_OCCLUSION = 5` — Constant for setting `ao_enabled`.
- `FEATURE_HEIGHT_MAPPING = 6` — Constant for setting `heightmap_enabled`.
- `FEATURE_SUBSURFACE_SCATTERING = 7` — Constant for setting `subsurf_scatter_enabled`.
- `FEATURE_SUBSURFACE_TRANSMITTANCE = 8` — Constant for setting `subsurf_scatter_transmittance_enabled`.
- `FEATURE_BACKLIGHT = 9` — Constant for setting `backlight_enabled`.
- `FEATURE_REFRACTION = 10` — Constant for setting `refraction_enabled`.
- `FEATURE_DETAIL = 11` — Constant for setting `detail_enabled`.
- `FEATURE_BENT_NORMAL_MAPPING = 12` — Constant for setting `bent_normal_enabled`.
- `FEATURE_PARTICLES_ANIMATION = 13` — Constant for setting `particles_anim_enabled`.
- `FEATURE_MAX = 14` — Represents the size of the `Feature` enum.

## Enum BlendMode

- `BLEND_MODE_MIX = 0` — Default blend mode.
- `BLEND_MODE_ADD = 1` — The color of the object is added to the background.
- `BLEND_MODE_SUB = 2` — The color of the object is subtracted from the background.
- `BLEND_MODE_MUL = 3` — The color of the object is multiplied by the background.
- `BLEND_MODE_PREMULT_ALPHA = 4` — The color of the object is added to the background and the alpha channel is used to mask out the background.

## Enum AlphaAntiAliasing

- `ALPHA_ANTIALIASING_OFF = 0` — Disables Alpha AntiAliasing for the material.
- `ALPHA_ANTIALIASING_ALPHA_TO_COVERAGE = 1` — Enables AlphaToCoverage.
- `ALPHA_ANTIALIASING_ALPHA_TO_COVERAGE_AND_TO_ONE = 2` — Enables AlphaToCoverage and forces all non-zero alpha values to `1`.

## Enum DepthDrawMode

- `DEPTH_DRAW_OPAQUE_ONLY = 0` — Default depth draw mode.
- `DEPTH_DRAW_ALWAYS = 1` — Objects will write to depth during the opaque and the transparent passes.
- `DEPTH_DRAW_DISABLED = 2` — Objects will not write their depth to the depth buffer, even during the depth prepass (if enabled).

## Enum DepthTest

- `DEPTH_TEST_DEFAULT = 0` — Depth test will discard the pixel if it is behind other pixels.
- `DEPTH_TEST_INVERTED = 1` — Depth test will discard the pixel if it is in front of other pixels.

## Enum CullMode

- `CULL_BACK = 0` — Default cull mode.
- `CULL_FRONT = 1` — Front face triangles will be culled when facing the camera.
- `CULL_DISABLED = 2` — No face culling is performed; both the front face and back face will be visible.

## Enum Flags

- `FLAG_DISABLE_DEPTH_TEST = 0` — Disables the depth test, so this object is drawn on top of all others drawn before it.
- `FLAG_ALBEDO_FROM_VERTEX_COLOR = 1` — Set `ALBEDO` to the per-vertex color specified in the mesh.
- `FLAG_SRGB_VERTEX_COLOR = 2` — Vertex colors are considered to be stored in nonlinear sRGB encoding and are converted to linear encoding during rendering.
- `FLAG_USE_POINT_SIZE = 3` — Uses point size to alter the size of primitive points.
- `FLAG_FIXED_SIZE = 4` — Object is scaled by depth so that it always appears the same size on screen.
- `FLAG_BILLBOARD_KEEP_SCALE = 5` — Shader will keep the scale set for the mesh.
- `FLAG_UV1_USE_TRIPLANAR = 6` — Use triplanar texture lookup for all texture lookups that would normally use `UV`.
- `FLAG_UV2_USE_TRIPLANAR = 7` — Use triplanar texture lookup for all texture lookups that would normally use `UV2`.
- `FLAG_UV1_USE_WORLD_TRIPLANAR = 8` — Use triplanar texture lookup for all texture lookups that would normally use `UV`.
- `FLAG_UV2_USE_WORLD_TRIPLANAR = 9` — Use triplanar texture lookup for all texture lookups that would normally use `UV2`.
- `FLAG_AO_ON_UV2 = 10` — Use `UV2` coordinates to look up from the `ao_texture`.
- `FLAG_EMISSION_ON_UV2 = 11` — Use `UV2` coordinates to look up from the `emission_texture`.
- `FLAG_ALBEDO_TEXTURE_FORCE_SRGB = 12` — Forces the shader to convert albedo from nonlinear sRGB encoding to linear encoding.
- `FLAG_DONT_RECEIVE_SHADOWS = 13` — Disables receiving shadows from other objects.
- `FLAG_DISABLE_AMBIENT_LIGHT = 14` — Disables receiving ambient light.
- `FLAG_USE_SHADOW_TO_OPACITY = 15` — Enables the shadow to opacity feature.
- `FLAG_USE_TEXTURE_REPEAT = 16` — Enables the texture to repeat when UV coordinates are outside the 0-1 range.
- `FLAG_INVERT_HEIGHTMAP = 17` — Invert values read from a depth texture to convert them to height values (heightmap).
- `FLAG_SUBSURFACE_MODE_SKIN = 18` — Enables the skin mode for subsurface scattering which is used to improve the look of subsurface scattering when used for human skin.
- `FLAG_PARTICLE_TRAILS_MODE = 19` — Enables parts of the shader required for GPUParticles3D trails to function.
- `FLAG_ALBEDO_TEXTURE_MSDF = 20` — Enables multichannel signed distance field rendering shader.
- `FLAG_DISABLE_FOG = 21` — Disables receiving depth-based or volumetric fog.
- `FLAG_DISABLE_SPECULAR_OCCLUSION = 22` — Disables specular occlusion.
- `FLAG_USE_Z_CLIP_SCALE = 23` — Enables using `z_clip_scale`.
- `FLAG_USE_FOV_OVERRIDE = 24` — Enables using `fov_override`.
- `FLAG_MAX = 25` — Represents the size of the `Flags` enum.

## Enum DiffuseMode

- `DIFFUSE_BURLEY = 0` — Default diffuse scattering algorithm.
- `DIFFUSE_LAMBERT = 1` — Diffuse scattering ignores roughness.
- `DIFFUSE_LAMBERT_WRAP = 2` — Extends Lambert to cover more than 90 degrees when roughness increases.
- `DIFFUSE_TOON = 3` — Uses a hard cut for lighting, with smoothing affected by roughness.

## Enum SpecularMode

- `SPECULAR_SCHLICK_GGX = 0` — Default specular blob.
- `SPECULAR_TOON = 1` — Toon blob which changes size based on roughness.
- `SPECULAR_DISABLED = 2` — No specular blob.

## Enum BillboardMode

- `BILLBOARD_DISABLED = 0` — Billboard mode is disabled.
- `BILLBOARD_ENABLED = 1` — The object's Z axis will always face the camera.
- `BILLBOARD_FIXED_Y = 2` — The object's X axis will always face the camera.
- `BILLBOARD_PARTICLES = 3` — Used for particle systems when assigned to GPUParticles3D and CPUParticles3D nodes (flipbook animation).

## Enum TextureChannel

- `TEXTURE_CHANNEL_RED = 0` — Used to read from the red channel of a texture.
- `TEXTURE_CHANNEL_GREEN = 1` — Used to read from the green channel of a texture.
- `TEXTURE_CHANNEL_BLUE = 2` — Used to read from the blue channel of a texture.
- `TEXTURE_CHANNEL_ALPHA = 3` — Used to read from the alpha channel of a texture.
- `TEXTURE_CHANNEL_GRAYSCALE = 4` — Used to read from the linear (non-perceptual) average of the red, green and blue channels of a texture.

## Enum EmissionOperator

- `EMISSION_OP_ADD = 0` — Adds the emission color to the color from the emission texture.
- `EMISSION_OP_MULTIPLY = 1` — Multiplies the emission color by the color from the emission texture.

## Enum DistanceFadeMode

- `DISTANCE_FADE_DISABLED = 0` — Do not use distance fade.
- `DISTANCE_FADE_PIXEL_ALPHA = 1` — Smoothly fades the object out based on each pixel's distance from the camera using the alpha channel.
- `DISTANCE_FADE_PIXEL_DITHER = 2` — Smoothly fades the object out based on each pixel's distance from the camera using a dithering approach.
- `DISTANCE_FADE_OBJECT_DITHER = 3` — Smoothly fades the object out based on the object's distance from the camera using a dithering approach.

## Enum StencilMode

- `STENCIL_MODE_DISABLED = 0` — Disables stencil operations.
- `STENCIL_MODE_OUTLINE = 1` — Stencil preset which applies an outline to the object.
- `STENCIL_MODE_XRAY = 2` — Stencil preset which shows a silhouette of the object behind walls.
- `STENCIL_MODE_CUSTOM = 3` — Enables stencil operations without a preset.

## Enum StencilFlags

- `STENCIL_FLAG_READ = 1` — The material will only be rendered where it passes a stencil comparison with existing stencil buffer values.
- `STENCIL_FLAG_WRITE = 2` — The material will write the reference value to the stencil buffer where it passes the depth test.
- `STENCIL_FLAG_WRITE_DEPTH_FAIL = 4` — The material will write the reference value to the stencil buffer where it fails the depth test.

## Enum StencilCompare

- `STENCIL_COMPARE_ALWAYS = 0` — Always passes the stencil test.
- `STENCIL_COMPARE_LESS = 1` — Passes the stencil test when the reference value is less than the existing stencil value.
- `STENCIL_COMPARE_EQUAL = 2` — Passes the stencil test when the reference value is equal to the existing stencil value.
- `STENCIL_COMPARE_LESS_OR_EQUAL = 3` — Passes the stencil test when the reference value is less than or equal to the existing stencil value.
- `STENCIL_COMPARE_GREATER = 4` — Passes the stencil test when the reference value is greater than the existing stencil value.
- `STENCIL_COMPARE_NOT_EQUAL = 5` — Passes the stencil test when the reference value is not equal to the existing stencil value.
- `STENCIL_COMPARE_GREATER_OR_EQUAL = 6` — Passes the stencil test when the reference value is greater than or equal to the existing stencil value.
