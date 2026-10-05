# RenderingServer

**Inherits:** Object

Server for anything visible.

The rendering server is the API backend for everything visible. The whole scene system mounts on it to display. The rendering server is completely opaque: the internals are entirely implementation-specific and cannot be accessed. The rendering server can be used to bypass the scene/Node system entirely.

## Properties

- `render_loop_enabled: bool` — If `false`, disables rendering completely, but the engine logic is still being processed.

## Methods

- `area_light_create() -> RID` — Creates a new area light and adds it to the RenderingServer.
- `bake_render_uv2(base: RID, material_overrides: RID[], image_size: Vector2i) -> Image[]` — Bakes the material data of the Mesh passed in the `base` parameter with optional `material_overrides` to a set of Images of size `image_size`.
- `call_on_render_thread(callable: Callable) -> void` — As the RenderingServer actual logic may run on a separate thread, accessing its internals from the main (or any other) thread will result in errors.
- `camera_attributes_create() -> RID` — Creates a camera attributes object and adds it to the RenderingServer.
- `camera_attributes_set_auto_exposure(camera_attributes: RID, enable: bool, min_sensitivity: float, max_sensitivity: float, speed: float, scale: float) -> void` — Sets the parameters to use with the auto-exposure effect.
- `camera_attributes_set_dof_blur(camera_attributes: RID, far_enable: bool, far_distance: float, far_transition: float, near_enable: bool, near_distance: float, near_transition: float, amount: float) -> void` — Sets the parameters to use with the DOF blur effect.
- `camera_attributes_set_dof_blur_bokeh_shape(shape: RenderingServer.DOFBokehShape) -> void` — Sets the shape of the DOF bokeh pattern to `shape`.
- `camera_attributes_set_dof_blur_quality(quality: RenderingServer.DOFBlurQuality, use_jitter: bool) -> void` — Sets the quality level of the DOF blur effect to `quality`.
- `camera_attributes_set_exposure(camera_attributes: RID, multiplier: float, normalization: float) -> void` — Sets the exposure values that will be used by the renderers.
- `camera_create() -> RID` — Creates a 3D camera and adds it to the RenderingServer.
- `camera_set_camera_attributes(camera: RID, effects: RID) -> void` — Sets the camera_attributes created with `camera_attributes_create` to the given camera.
- `camera_set_compositor(camera: RID, compositor: RID) -> void` — Sets the compositor used by this camera.
- `camera_set_cull_mask(camera: RID, layers: int) -> void` — Sets the cull mask associated with this camera.
- `camera_set_environment(camera: RID, env: RID) -> void` — Sets the environment used by this camera.
- `camera_set_frustum(camera: RID, size: float, offset: Vector2, z_near: float, z_far: float) -> void` — Sets camera to use frustum projection.
- `camera_set_orthogonal(camera: RID, size: float, z_near: float, z_far: float) -> void` — Sets camera to use orthogonal projection, also known as orthographic projection.
- `camera_set_perspective(camera: RID, fovy_degrees: float, z_near: float, z_far: float) -> void` — Sets camera to use perspective projection.
- `camera_set_transform(camera: RID, transform: Transform3D) -> void` — Sets Transform3D of camera.
- `camera_set_use_vertical_aspect(camera: RID, enable: bool) -> void` — If `true`, preserves the horizontal aspect ratio which is equivalent to `Camera3D.KEEP_WIDTH`.
- `camera_set_xr_projections(camera: RID, projections: Projection[], offsets: Transform3D[] = []) -> void` — Sets camera to use any set of `projections`.
- `canvas_create() -> RID` — Creates a canvas and returns the assigned RID.
- `canvas_item_add_animation_slice(item: RID, animation_length: float, slice_begin: float, slice_end: float, offset: float = 0.0) -> void` — Subsequent drawing commands will be ignored unless they fall within the specified animation slice.
- `canvas_item_add_circle(item: RID, pos: Vector2, radius: float, color: Color, antialiased: bool = false) -> void` — Draws a circle on the CanvasItem pointed to by the `item` RID.
- `canvas_item_add_clip_ignore(item: RID, ignore: bool) -> void` — If `ignore` is `true`, ignore clipping on items drawn with this canvas item until this is called again with `ignore` set to `false`.
- `canvas_item_add_ellipse(item: RID, pos: Vector2, major: float, minor: float, color: Color, antialiased: bool = false) -> void` — Draws an ellipse with semi-major axis `major` and semi-minor axis `minor` on the CanvasItem pointed to by the `item` RID.
- `canvas_item_add_lcd_texture_rect_region(item: RID, rect: Rect2, texture: RID, src_rect: Rect2, modulate: Color) -> void` — See also `CanvasItem.draw_lcd_texture_rect_region`.
- `canvas_item_add_line(item: RID, from: Vector2, to: Vector2, color: Color, width: float = -1.0, antialiased: bool = false) -> void` — Draws a line on the CanvasItem pointed to by the `item` RID.
- `canvas_item_add_mesh(item: RID, mesh: RID, transform: Transform2D = Transform2D(1, 0, 0, 1, 0, 0), modulate: Color = Color(1, 1, 1, 1), texture: RID = RID()) -> void` — Draws a mesh created with `mesh_create` with given `transform`, `modulate` color, and `texture`.
- `canvas_item_add_msdf_texture_rect_region(item: RID, rect: Rect2, texture: RID, src_rect: Rect2, modulate: Color = Color(1, 1, 1, 1), outline_size: int = 0, px_range: float = 1.0, scale: float = 1.0) -> void` — See also `CanvasItem.draw_msdf_texture_rect_region`.
- `canvas_item_add_multiline(item: RID, points: PackedVector2Array, colors: PackedColorArray, width: float = -1.0, antialiased: bool = false) -> void` — Draws a 2D multiline on the CanvasItem pointed to by the `item` RID.
- `canvas_item_add_multimesh(item: RID, mesh: RID, texture: RID = RID()) -> void` — Draws a 2D MultiMesh on the CanvasItem pointed to by the `item` RID.
- `canvas_item_add_nine_patch(item: RID, rect: Rect2, source: Rect2, texture: RID, topleft: Vector2, bottomright: Vector2, x_axis_mode: RenderingServer.NinePatchAxisMode = 0, y_axis_mode: RenderingServer.NinePatchAxisMode = 0, draw_center: bool = true, modulate: Color = Color(1, 1, 1, 1)) -> void` — Draws a nine-patch rectangle on the CanvasItem pointed to by the `item` RID.
- `canvas_item_add_particles(item: RID, particles: RID, texture: RID) -> void` — Draws particles on the CanvasItem pointed to by the `item` RID.
- `canvas_item_add_polygon(item: RID, points: PackedVector2Array, colors: PackedColorArray, uvs: PackedVector2Array = PackedVector2Array(), texture: RID = RID()) -> void` — Draws a 2D polygon on the CanvasItem pointed to by the `item` RID.
- `canvas_item_add_polyline(item: RID, points: PackedVector2Array, colors: PackedColorArray, width: float = -1.0, antialiased: bool = false) -> void` — Draws a 2D polyline on the CanvasItem pointed to by the `item` RID.
- `canvas_item_add_primitive(item: RID, points: PackedVector2Array, colors: PackedColorArray, uvs: PackedVector2Array, texture: RID) -> void` — Draws a 2D primitive on the CanvasItem pointed to by the `item` RID.
- `canvas_item_add_rect(item: RID, rect: Rect2, color: Color, antialiased: bool = false) -> void` — Draws a rectangle on the CanvasItem pointed to by the `item` RID.
- `canvas_item_add_set_transform(item: RID, transform: Transform2D) -> void` — Sets a Transform2D that will be used to transform subsequent canvas item commands.
- `canvas_item_add_texture_rect(item: RID, rect: Rect2, texture: RID, tile: bool = false, modulate: Color = Color(1, 1, 1, 1), transpose: bool = false) -> void` — Draws a 2D textured rectangle on the CanvasItem pointed to by the `item` RID.
- `canvas_item_add_texture_rect_region(item: RID, rect: Rect2, texture: RID, src_rect: Rect2, modulate: Color = Color(1, 1, 1, 1), transpose: bool = false, clip_uv: bool = true) -> void` — Draws the specified region of a 2D textured rectangle on the CanvasItem pointed to by the `item` RID.
- `canvas_item_add_triangle_array(item: RID, indices: PackedInt32Array, points: PackedVector2Array, colors: PackedColorArray, uvs: PackedVector2Array = PackedVector2Array(), bones: PackedInt32Array = PackedInt32Array(), weights: PackedFloat32Array = PackedFloat32Array(), texture: RID = RID(), count: int = -1) -> void` — Draws a triangle array on the CanvasItem pointed to by the `item` RID.
- `canvas_item_attach_skeleton(item: RID, skeleton: RID) -> void` — Attaches a skeleton to the CanvasItem.
- `canvas_item_clear(item: RID) -> void` — Clears the CanvasItem and removes all commands in it.
- `canvas_item_create() -> RID` — Creates a new CanvasItem instance and returns its RID.
- `canvas_item_get_instance_shader_parameter(instance: RID, parameter: StringName) -> Variant` *const* — Returns the value of the per-instance shader uniform from the specified canvas item instance.
- `canvas_item_get_instance_shader_parameter_default_value(instance: RID, parameter: StringName) -> Variant` *const* — Returns the default value of the per-instance shader uniform from the specified canvas item instance.
- `canvas_item_get_instance_shader_parameter_list(instance: RID) -> Dictionary[]` *const* — Returns a dictionary of per-instance shader uniform names of the per-instance shader uniform from the specified canvas item instance.
- `canvas_item_reset_physics_interpolation(item: RID) -> void` — Prevents physics interpolation for the current physics tick.
- `canvas_item_set_canvas_group_mode(item: RID, mode: RenderingServer.CanvasGroupMode, clear_margin: float = 5.0, fit_empty: bool = false, fit_margin: float = 0.0, blur_mipmaps: bool = false) -> void` — Sets the canvas group mode used during 2D rendering for the canvas item specified by the `item` RID.
- `canvas_item_set_clip(item: RID, clip: bool) -> void` — If `clip` is `true`, makes the canvas item specified by the `item` RID not draw anything outside of its rect's coordinates.
- `canvas_item_set_copy_to_backbuffer(item: RID, enabled: bool, rect: Rect2) -> void` — Sets the CanvasItem to copy a rect to the backbuffer.
- `canvas_item_set_custom_rect(item: RID, use_custom_rect: bool, rect: Rect2 = Rect2(0, 0, 0, 0)) -> void` — If `use_custom_rect` is `true`, sets the custom visibility rectangle (used for culling) to `rect` for the canvas item specified by `item`.
- `canvas_item_set_default_texture_filter(item: RID, filter: RenderingServer.CanvasItemTextureFilter) -> void` — Sets the default texture filter mode for the canvas item specified by the `item` RID.
- `canvas_item_set_default_texture_repeat(item: RID, repeat: RenderingServer.CanvasItemTextureRepeat) -> void` — Sets the default texture repeat mode for the canvas item specified by the `item` RID.
- `canvas_item_set_distance_field_mode(item: RID, enabled: bool) -> void` — If `enabled` is `true`, enables multichannel signed distance field rendering mode for the canvas item specified by the `item` RID.
- `canvas_item_set_draw_behind_parent(item: RID, enabled: bool) -> void` — If `enabled` is `true`, draws the canvas item specified by the `item` RID behind its parent.
- `canvas_item_set_draw_index(item: RID, index: int) -> void` — Sets the index for the CanvasItem.
- `canvas_item_set_instance_shader_parameter(instance: RID, parameter: StringName, value: Variant) -> void` — Sets the per-instance shader uniform on the specified canvas item instance.
- `canvas_item_set_interpolated(item: RID, interpolated: bool) -> void` — If `interpolated` is `true`, turns on physics interpolation for the canvas item.
- `canvas_item_set_light_mask(item: RID, mask: int) -> void` — Sets the light `mask` for the canvas item specified by the `item` RID.
- `canvas_item_set_material(item: RID, material: RID) -> void` — Sets a new `material` to the canvas item specified by the `item` RID.
- `canvas_item_set_modulate(item: RID, color: Color) -> void` — Multiplies the color of the canvas item specified by the `item` RID, while affecting its children.
- `canvas_item_set_parent(item: RID, parent: RID) -> void` — Sets a parent CanvasItem to the CanvasItem.
- `canvas_item_set_self_modulate(item: RID, color: Color) -> void` — Multiplies the color of the canvas item specified by the `item` RID, without affecting its children.
- `canvas_item_set_sort_children_by_y(item: RID, enabled: bool) -> void` — If `enabled` is `true`, child nodes with the lowest Y position are drawn before those with a higher Y position.
- `canvas_item_set_transform(item: RID, transform: Transform2D) -> void` — Sets the `transform` of the canvas item specified by the `item` RID.
- `canvas_item_set_use_parent_material(item: RID, enabled: bool) -> void` — Sets if the CanvasItem uses its parent's material.
- `canvas_item_set_visibility_layer(item: RID, visibility_layer: int) -> void` — Sets the rendering visibility layer associated with this CanvasItem.
- `canvas_item_set_visibility_notifier(item: RID, enable: bool, area: Rect2, enter_callable: Callable, exit_callable: Callable) -> void` — Sets the given CanvasItem as visibility notifier.
- `canvas_item_set_visible(item: RID, visible: bool) -> void` — Sets the visibility of the CanvasItem.
- `canvas_item_set_z_as_relative_to_parent(item: RID, enabled: bool) -> void` — If this is enabled, the Z index of the parent will be added to the children's Z index.
- `canvas_item_set_z_index(item: RID, z_index: int) -> void` — Sets the CanvasItem's Z index, i.e. its draw order (lower indexes are drawn first).
- `canvas_item_transform_physics_interpolation(item: RID, transform: Transform2D) -> void` — Transforms both the current and previous stored transform for a canvas item.
- `canvas_light_attach_to_canvas(light: RID, canvas: RID) -> void` — Attaches the canvas light to the canvas.
- `canvas_light_create() -> RID` — Creates a canvas light and adds it to the RenderingServer.
- `canvas_light_occluder_attach_to_canvas(occluder: RID, canvas: RID) -> void` — Attaches a light occluder to the canvas.
- `canvas_light_occluder_create() -> RID` — Creates a light occluder and adds it to the RenderingServer.
- `canvas_light_occluder_reset_physics_interpolation(occluder: RID) -> void` — Prevents physics interpolation for the current physics tick.
- `canvas_light_occluder_set_as_sdf_collision(occluder: RID, enable: bool) -> void` — Enables or disables using the light occluder as a signed distance field for 2D particle collision.
- `canvas_light_occluder_set_enabled(occluder: RID, enabled: bool) -> void` — Enables or disables light occluder.
- `canvas_light_occluder_set_interpolated(occluder: RID, interpolated: bool) -> void` — If `interpolated` is `true`, turns on physics interpolation for the light occluder.
- `canvas_light_occluder_set_light_mask(occluder: RID, mask: int) -> void` — The light mask.
- `canvas_light_occluder_set_polygon(occluder: RID, polygon: RID) -> void` — Sets a light occluder's polygon.
- `canvas_light_occluder_set_transform(occluder: RID, transform: Transform2D) -> void` — Sets a light occluder's Transform2D.
- `canvas_light_occluder_transform_physics_interpolation(occluder: RID, transform: Transform2D) -> void` — Transforms both the current and previous stored transform for a light occluder.
- `canvas_light_reset_physics_interpolation(light: RID) -> void` — Prevents physics interpolation for the current physics tick.
- `canvas_light_set_blend_mode(light: RID, mode: RenderingServer.CanvasLightBlendMode) -> void` — Sets the blend mode for the given canvas light to `mode`.
- `canvas_light_set_color(light: RID, color: Color) -> void` — Sets the color for a light.
- `canvas_light_set_enabled(light: RID, enabled: bool) -> void` — Enables or disables a canvas light.
- `canvas_light_set_energy(light: RID, energy: float) -> void` — Sets a canvas light's energy.
- `canvas_light_set_height(light: RID, height: float) -> void` — Sets a canvas light's height.
- `canvas_light_set_interpolated(light: RID, interpolated: bool) -> void` — If `interpolated` is `true`, turns on physics interpolation for the canvas light.
- `canvas_light_set_item_cull_mask(light: RID, mask: int) -> void` — The light mask.
- `canvas_light_set_item_shadow_cull_mask(light: RID, mask: int) -> void` — The binary mask used to determine which layers this canvas light's shadows affects.
- `canvas_light_set_layer_range(light: RID, min_layer: int, max_layer: int) -> void` — The layer range that gets rendered with this light.
- `canvas_light_set_mode(light: RID, mode: RenderingServer.CanvasLightMode) -> void` — Sets the mode of the canvas light.
- `canvas_light_set_shadow_color(light: RID, color: Color) -> void` — Sets the color of the canvas light's shadow.
- `canvas_light_set_shadow_enabled(light: RID, enabled: bool) -> void` — Enables or disables the canvas light's shadow.
- `canvas_light_set_shadow_filter(light: RID, filter: RenderingServer.CanvasLightShadowFilter) -> void` — Sets the canvas light's shadow's filter.
- `canvas_light_set_shadow_smooth(light: RID, smooth: float) -> void` — Smoothens the shadow.
- `canvas_light_set_texture(light: RID, texture: RID) -> void` — Sets the texture to be used by a PointLight2D.
- `canvas_light_set_texture_offset(light: RID, offset: Vector2) -> void` — Sets the offset of a PointLight2D's texture.
- `canvas_light_set_texture_scale(light: RID, scale: float) -> void` — Sets the scale factor of a PointLight2D's texture.
- `canvas_light_set_transform(light: RID, transform: Transform2D) -> void` — Sets the canvas light's Transform2D.
- `canvas_light_set_z_range(light: RID, min_z: int, max_z: int) -> void` — Sets the Z range of objects that will be affected by this light.
- `canvas_light_transform_physics_interpolation(light: RID, transform: Transform2D) -> void` — Transforms both the current and previous stored transform for a canvas light.
- `canvas_occluder_polygon_create() -> RID` — Creates a new light occluder polygon and adds it to the RenderingServer.
- `canvas_occluder_polygon_set_cull_mode(occluder_polygon: RID, mode: RenderingServer.CanvasOccluderPolygonCullMode) -> void` — Sets an occluder polygon's cull mode.
- `canvas_occluder_polygon_set_shape(occluder_polygon: RID, shape: PackedVector2Array, closed: bool) -> void` — Sets the shape of the occluder polygon.
- `canvas_set_disable_scale(disable: bool) -> void` — If `disable` is `true`, makes 2D rendering ignore the canvas scale defined for each canvas layer.
- `canvas_set_item_mirroring(canvas: RID, item: RID, mirroring: Vector2) -> void` — A copy of the canvas item will be drawn with a local offset of the `mirroring`.
- `canvas_set_item_repeat(item: RID, repeat_size: Vector2, repeat_times: int) -> void` — A copy of the canvas item will be drawn with a local offset of the `repeat_size` by the number of times of the `repeat_times`.
- `canvas_set_modulate(canvas: RID, color: Color) -> void` — Modulates all colors in the given canvas.
- `canvas_set_shadow_texture_size(size: int) -> void` — Sets the `ProjectSettings.rendering/2d/shadow_atlas/size` to use for Light2D shadow rendering (in pixels).
- `canvas_texture_create() -> RID` — Creates a canvas texture and adds it to the RenderingServer.
- `canvas_texture_set_channel(canvas_texture: RID, channel: RenderingServer.CanvasTextureChannel, texture: RID) -> void` — Sets the `channel`'s `texture` for the canvas texture specified by the `canvas_texture` RID.
- `canvas_texture_set_shading_parameters(canvas_texture: RID, base_color: Color, shininess: float) -> void` — Sets the `base_color` and `shininess` to use for the canvas texture specified by the `canvas_texture` RID.
- `canvas_texture_set_texture_filter(canvas_texture: RID, filter: RenderingServer.CanvasItemTextureFilter) -> void` — Sets the texture `filter` mode to use for the canvas texture specified by the `canvas_texture` RID.
- `canvas_texture_set_texture_repeat(canvas_texture: RID, repeat: RenderingServer.CanvasItemTextureRepeat) -> void` — Sets the texture `repeat` mode to use for the canvas texture specified by the `canvas_texture` RID.
- `compositor_create() -> RID` — Creates a new compositor and adds it to the RenderingServer.
- `compositor_effect_create() -> RID` — Creates a new rendering effect and adds it to the RenderingServer.
- `compositor_effect_set_callback(effect: RID, callback_type: RenderingServer.CompositorEffectCallbackType, callback: Callable) -> void` — Sets the callback type (`callback_type`) and callback method(`callback`) for this rendering effect.
- `compositor_effect_set_enabled(effect: RID, enabled: bool) -> void` — Enables/disables this rendering effect.
- `compositor_effect_set_flag(effect: RID, flag: RenderingServer.CompositorEffectFlags, set: bool) -> void` — Sets the flag (`flag`) for this rendering effect to `true` or `false` (`set`).
- `compositor_set_compositor_effects(compositor: RID, effects: RID[]) -> void` — Sets the compositor effects for the specified compositor RID.
- `create_local_rendering_device() -> RenderingDevice` *const* — Creates a RenderingDevice that can be used to do draw and compute operations on a separate thread.
- `debug_canvas_item_get_rect(item: RID) -> Rect2` — Returns the bounding rectangle for a canvas item in local space, as calculated by the renderer.
- `decal_create() -> RID` — Creates a decal and adds it to the RenderingServer.
- `decal_set_albedo_mix(decal: RID, albedo_mix: float) -> void` — Sets the `albedo_mix` in the decal specified by the `decal` RID.
- `decal_set_cull_mask(decal: RID, mask: int) -> void` — Sets the cull `mask` in the decal specified by the `decal` RID.
- `decal_set_distance_fade(decal: RID, enabled: bool, begin: float, length: float) -> void` — Sets the distance fade parameters in the decal specified by the `decal` RID.
- `decal_set_emission_energy(decal: RID, energy: float) -> void` — Sets the emission `energy` in the decal specified by the `decal` RID.
- `decal_set_fade(decal: RID, above: float, below: float) -> void` — Sets the upper fade (`above`) and lower fade (`below`) in the decal specified by the `decal` RID.
- `decal_set_modulate(decal: RID, color: Color) -> void` — Sets the color multiplier in the decal specified by the `decal` RID to `color`.
- `decal_set_normal_fade(decal: RID, fade: float) -> void` — Sets the normal `fade` in the decal specified by the `decal` RID.
- `decal_set_size(decal: RID, size: Vector3) -> void` — Sets the `size` of the decal specified by the `decal` RID.
- `decal_set_texture(decal: RID, type: RenderingServer.DecalTexture, texture: RID) -> void` — Sets the `texture` in the given texture `type` slot for the specified decal.
- `decals_set_filter(filter: RenderingServer.DecalFilter) -> void` — Sets the texture `filter` mode to use when rendering decals.
- `directional_light_create() -> RID` — Creates a directional light and adds it to the RenderingServer.
- `directional_shadow_atlas_set_size(size: int, is_16bits: bool) -> void` — Sets the `size` of the directional light shadows in 3D.
- `directional_soft_shadow_filter_set_quality(quality: RenderingServer.ShadowQuality) -> void` — Sets the filter `quality` for directional light shadows in 3D.
- `environment_bake_panorama(environment: RID, bake_irradiance: bool, size: Vector2i) -> Image` — Generates and returns an Image containing the radiance map for the specified `environment` RID's sky.
- `environment_create() -> RID` — Creates an environment and adds it to the RenderingServer.
- `environment_glow_set_use_bicubic_upscale(enable: bool) -> void` — If `enable` is `true`, enables bicubic upscaling for glow which improves quality at the cost of performance.
- `environment_set_adjustment(env: RID, enable: bool, brightness: float, contrast: float, saturation: float, use_1d_color_correction: bool, color_correction: RID) -> void` — Sets the values to be used with the "adjustments" post-process effect.
- `environment_set_ambient_light(env: RID, color: Color, ambient: RenderingServer.EnvironmentAmbientSource = 0, energy: float = 1.0, sky_contribution: float = 0.0, reflection_source: RenderingServer.EnvironmentReflectionSource = 0) -> void` — Sets the values to be used for ambient light rendering.
- `environment_set_background(env: RID, bg: RenderingServer.EnvironmentBG) -> void` — Sets the environment's background mode.
- `environment_set_bg_color(env: RID, color: Color) -> void` — Color displayed for clear areas of the scene.
- `environment_set_bg_energy(env: RID, multiplier: float, exposure_value: float) -> void` — Sets the intensity of the background color.
- `environment_set_camera_id(env: RID, id: int) -> void` — Sets the camera ID to be used as environment background.
- `environment_set_canvas_max_layer(env: RID, max_layer: int) -> void` — Sets the maximum layer to use if using Canvas background mode.
- `environment_set_fog(env: RID, enable: bool, light_color: Color, light_energy: float, sun_scatter: float, density: float, height: float, height_density: float, aerial_perspective: float, sky_affect: float, fog_mode: RenderingServer.EnvironmentFogMode = 0) -> void` — Configures fog for the specified environment RID.
- `environment_set_fog_depth(env: RID, curve: float, begin: float, end: float) -> void` — Configures fog depth for the specified environment RID.
- `environment_set_glow(env: RID, enable: bool, levels: PackedFloat32Array, intensity: float, strength: float, mix: float, bloom_threshold: float, blend_mode: RenderingServer.EnvironmentGlowBlendMode, hdr_bleed_threshold: float, hdr_bleed_scale: float, hdr_luminance_cap: float, glow_map_strength: float, glow_map: RID) -> void` — Configures glow for the specified environment RID.
- `environment_set_sdfgi(env: RID, enable: bool, cascades: int, min_cell_size: float, y_scale: RenderingServer.EnvironmentSDFGIYScale, use_occlusion: bool, bounce_feedback: float, read_sky: bool, energy: float, normal_bias: float, probe_bias: float) -> void` — Configures signed distance field global illumination for the specified environment RID.
- `environment_set_sdfgi_frames_to_converge(frames: RenderingServer.EnvironmentSDFGIFramesToConverge) -> void` — Sets the number of frames to use for converging signed distance field global illumination.
- `environment_set_sdfgi_frames_to_update_light(frames: RenderingServer.EnvironmentSDFGIFramesToUpdateLight) -> void` — Sets the update speed for dynamic lights' indirect lighting when computing signed distance field global illumination.
- `environment_set_sdfgi_ray_count(ray_count: RenderingServer.EnvironmentSDFGIRayCount) -> void` — Sets the number of rays to throw per frame when computing signed distance field global illumination.
- `environment_set_sky(env: RID, sky: RID) -> void` — Sets the Sky to be used as the environment's background when using BGMode sky.
- `environment_set_sky_custom_fov(env: RID, scale: float) -> void` — Sets a custom field of view for the background Sky.
- `environment_set_sky_orientation(env: RID, orientation: Basis) -> void` — Sets the rotation of the background Sky expressed as a Basis.
- `environment_set_ssao(env: RID, enable: bool, radius: float, intensity: float, power: float, detail: float, horizon: float, sharpness: float, light_affect: float, ao_channel_affect: float) -> void` — Sets the variables to be used with the screen-space ambient occlusion (SSAO) post-process effect.
- `environment_set_ssao_quality(quality: RenderingServer.EnvironmentSSAOQuality, half_size: bool, adaptive_target: float, blur_passes: int, fadeout_from: float, fadeout_to: float) -> void` — Sets the quality level of the screen-space ambient occlusion (SSAO) post-process effect.
- `environment_set_ssil_quality(quality: RenderingServer.EnvironmentSSILQuality, half_size: bool, adaptive_target: float, blur_passes: int, fadeout_from: float, fadeout_to: float) -> void` — Sets the quality level of the screen-space indirect lighting (SSIL) post-process effect.
- `environment_set_ssr(env: RID, enable: bool, max_steps: int, fade_in: float, fade_out: float, depth_tolerance: float) -> void` — Sets the variables to be used with the screen-space reflections (SSR) post-process effect.
- `environment_set_ssr_half_size(half_size: bool) -> void` — Sets whether screen-space reflections will be rendered at full or half size.
- `environment_set_ssr_roughness_quality(quality: RenderingServer.EnvironmentSSRRoughnessQuality) -> void` *(deprecated)*
- `environment_set_tonemap(env: RID, tone_mapper: RenderingServer.EnvironmentToneMapper, exposure: float, white: float) -> void` — Sets the variables to be used with the "tonemap" post-process effect.
- `environment_set_tonemap_agx_contrast(env: RID, agx_contrast: float) -> void` — See `Environment.tonemap_agx_contrast` for more details.
- `environment_set_volumetric_fog(env: RID, enable: bool, density: float, albedo: Color, emission: Color, emission_energy: float, anisotropy: float, length: float, detail_spread: float, gi_inject: float, temporal_reprojection: bool, temporal_reprojection_amount: float, ambient_inject: float, sky_affect: float) -> void` — Sets the variables to be used with the volumetric fog post-process effect.
- `environment_set_volumetric_fog_filter_active(active: bool) -> void` — Enables filtering of the volumetric fog scattering buffer.
- `environment_set_volumetric_fog_volume_size(size: int, depth: int) -> void` — Sets the resolution of the volumetric fog's froxel buffer.
- `fog_volume_create() -> RID` — Creates a new fog volume and adds it to the RenderingServer.
- `fog_volume_set_material(fog_volume: RID, material: RID) -> void` — Sets the Material of the fog volume.
- `fog_volume_set_shape(fog_volume: RID, shape: RenderingServer.FogVolumeShape) -> void` — Sets the shape of the fog volume to either `RenderingServer.FOG_VOLUME_SHAPE_ELLIPSOID`, `RenderingServer.FOG_VOLUME_SHAPE_CONE`, `RenderingServer.FOG_VOLUME_SHAPE_CYLINDER`, `RenderingServer.FOG_VOLUME_SHAPE_BOX` or `RenderingServer.FOG_VOLUME_SHAPE_WORLD`.
- `fog_volume_set_size(fog_volume: RID, size: Vector3) -> void` — Sets the size of the fog volume when shape is `RenderingServer.FOG_VOLUME_SHAPE_ELLIPSOID`, `RenderingServer.FOG_VOLUME_SHAPE_CONE`, `RenderingServer.FOG_VOLUME_SHAPE_CYLINDER` or `RenderingServer.FOG_VOLUME_SHAPE_BOX`.
- `force_draw(swap_buffers: bool = true, frame_step: float = 0.0) -> void` — Forces redrawing of all viewports at once.
- `force_sync() -> void` — Forces a synchronization between the CPU and GPU, which may be required in certain cases.
- `free_rid(rid: RID) -> void` — Tries to free an object in the RenderingServer.
- `get_current_rendering_driver_name() -> String` *const* — Returns the name of the current rendering driver.
- `get_current_rendering_method() -> String` *const* — Returns the name of the current rendering method.
- `get_default_clear_color() -> Color` — Returns the default clear color which is used when a specific clear color has not been selected.
- `get_frame_setup_time_cpu() -> float` *const* — Returns the time taken to setup rendering on the CPU in milliseconds.
- `get_rendering_device() -> RenderingDevice` *const* — Returns the global RenderingDevice.
- `get_rendering_info(info: RenderingServer.RenderingInfo) -> int` — Returns a statistic about the rendering engine which can be used for performance profiling.
- `get_shader_parameter_list(shader: RID) -> Dictionary[]` *const* — Returns the parameters of a shader.
- `get_test_cube() -> RID` — Returns the RID of the test cube.
- `get_test_texture() -> RID` — Returns the RID of a 256×256 texture with a testing pattern on it (in `Image.FORMAT_RGB8` format).
- `get_video_adapter_api_version() -> String` *const* — Returns the version of the graphics video adapter currently in use (e.g. "1.2.189" for Vulkan, "3.3.0 NVIDIA 510.60.02" for OpenGL).
- `get_video_adapter_name() -> String` *const* — Returns the name of the video adapter (e.g. "GeForce GTX 1080/PCIe/SSE2").
- `get_video_adapter_type() -> int[RenderingDevice.DeviceType]` *const* — Returns the type of the video adapter.
- `get_video_adapter_vendor() -> String` *const* — Returns the vendor of the video adapter (e.g. "NVIDIA Corporation").
- `get_white_texture() -> RID` — Returns the ID of a 4×4 white texture (in `Image.FORMAT_RGB8` format).
- `gi_set_use_half_resolution(half_resolution: bool) -> void` — If `half_resolution` is `true`, renders VoxelGI and SDFGI (`Environment.sdfgi_enabled`) buffers at halved resolution on each axis (e.g. 960×540 when the viewport size is 1920×1080).
- `global_shader_parameter_add(name: StringName, type: RenderingServer.GlobalShaderParameterType, default_value: Variant) -> void` — Creates a new global shader uniform.
- `global_shader_parameter_get(name: StringName) -> Variant` *const* — Returns the value of the global shader uniform specified by `name`.
- `global_shader_parameter_get_list() -> StringName[]` *const* — Returns the list of global shader uniform names.
- `global_shader_parameter_get_type(name: StringName) -> int[RenderingServer.GlobalShaderParameterType]` *const* — Returns the type associated to the global shader uniform specified by `name`.
- `global_shader_parameter_remove(name: StringName) -> void` — Removes the global shader uniform specified by `name`.
- `global_shader_parameter_set(name: StringName, value: Variant) -> void` — Sets the global shader uniform `name` to `value`.
- `global_shader_parameter_set_override(name: StringName, value: Variant) -> void` — Overrides the global shader uniform `name` with `value`.
- `has_changed() -> bool` *const* — Returns `true` if changes have been made to the RenderingServer's data.
- `has_feature(feature: RenderingServer.Features) -> bool` *const* *(deprecated)* — This method does nothing and always returns `false`.
- `has_os_feature(feature: String) -> bool` *const* — Returns `true` if the OS supports a certain `feature`.
- `instance_attach_object_instance_id(instance: RID, id: int) -> void` — Attaches a unique Object ID to instance.
- `instance_attach_skeleton(instance: RID, skeleton: RID) -> void` — Attaches a skeleton to an instance.
- `instance_create() -> RID` — Creates a visual instance and adds it to the RenderingServer.
- `instance_create2(base: RID, scenario: RID) -> RID` — Creates a visual instance, adds it to the RenderingServer, and sets both base and scenario.
- `instance_geometry_get_shader_parameter(instance: RID, parameter: StringName) -> Variant` *const* — Returns the value of the per-instance shader uniform from the specified 3D geometry instance.
- `instance_geometry_get_shader_parameter_default_value(instance: RID, parameter: StringName) -> Variant` *const* — Returns the default value of the per-instance shader uniform from the specified 3D geometry instance.
- `instance_geometry_get_shader_parameter_list(instance: RID) -> Dictionary[]` *const* — Returns a dictionary of per-instance shader uniform names of the per-instance shader uniform from the specified 3D geometry instance.
- `instance_geometry_set_cast_shadows_setting(instance: RID, shadow_casting_setting: RenderingServer.ShadowCastingSetting) -> void` — Sets the shadow casting setting.
- `instance_geometry_set_flag(instance: RID, flag: RenderingServer.InstanceFlags, enabled: bool) -> void` — Sets the `flag` for a given `instance` to `enabled`.
- `instance_geometry_set_lightmap(instance: RID, lightmap: RID, lightmap_uv_scale: Rect2, lightmap_slice: int) -> void` — Sets the lightmap GI instance to use for the specified 3D geometry instance.
- `instance_geometry_set_lod_bias(instance: RID, lod_bias: float) -> void` — Sets the level of detail bias to use when rendering the specified 3D geometry instance.
- `instance_geometry_set_material_overlay(instance: RID, material: RID) -> void` — Sets a material that will be rendered for all surfaces on top of active materials for the mesh associated with this instance.
- `instance_geometry_set_material_override(instance: RID, material: RID) -> void` — Sets a material that will override the material for all surfaces on the mesh associated with this instance.
- `instance_geometry_set_shader_parameter(instance: RID, parameter: StringName, value: Variant) -> void` — Sets the per-instance shader uniform on the specified 3D geometry instance.
- `instance_geometry_set_transparency(instance: RID, transparency: float) -> void` — Sets the transparency for the given geometry instance.
- `instance_geometry_set_visibility_range(instance: RID, min: float, max: float, min_margin: float, max_margin: float, fade_mode: RenderingServer.VisibilityRangeFadeMode) -> void` — Sets the visibility range values for the given geometry instance.
- `instance_set_base(instance: RID, base: RID) -> void` — Sets the base of the instance.
- `instance_set_blend_shape_weight(instance: RID, shape: int, weight: float) -> void` — Sets the weight for a given blend shape associated with this instance.
- `instance_set_custom_aabb(instance: RID, aabb: AABB) -> void` — Sets a custom AABB to use when culling objects from the view frustum.
- `instance_set_extra_visibility_margin(instance: RID, margin: float) -> void` — Sets a margin to increase the size of the AABB when culling objects from the view frustum.
- `instance_set_ignore_culling(instance: RID, enabled: bool) -> void` — If `true`, ignores all culling on the specified 3D geometry instance, including frustum culling, occlusion culling, and layer culling.
- `instance_set_layer_mask(instance: RID, mask: int) -> void` — Sets the render layers that this instance will be drawn to.
- `instance_set_pivot_data(instance: RID, sorting_offset: float, use_aabb_center: bool) -> void` — Sets the sorting offset and switches between using the bounding box or instance origin for depth sorting.
- `instance_set_scenario(instance: RID, scenario: RID) -> void` — Sets the scenario that the instance is in.
- `instance_set_surface_override_material(instance: RID, surface: int, material: RID) -> void` — Sets the override material of a specific surface.
- `instance_set_transform(instance: RID, transform: Transform3D) -> void` — Sets the world space transform of the instance.
- `instance_set_visibility_parent(instance: RID, parent: RID) -> void` — Sets the visibility parent for the given instance.
- `instance_set_visible(instance: RID, visible: bool) -> void` — Sets whether an instance is drawn or not.
- `instance_teleport(instance: RID) -> void` — Resets motion vectors and other interpolated values.
- `instances_cull_aabb(aabb: AABB, scenario: RID = RID()) -> PackedInt64Array` *const* — Returns an array of object IDs intersecting with the provided AABB.
- `instances_cull_convex(convex: Plane[], scenario: RID = RID()) -> PackedInt64Array` *const* — Returns an array of object IDs intersecting with the provided convex shape.
- `instances_cull_ray(from: Vector3, to: Vector3, scenario: RID = RID()) -> PackedInt64Array` *const* — Returns an array of object IDs intersecting with the provided 3D ray.
- `is_on_render_thread() -> bool` — Returns `true` if our code is currently executing on the rendering thread.
- `light_area_set_normalize_energy(light: RID, enable: bool) -> void` — Defines whether the energy of an AreaLight3D is normalized (divided) by its area.
- `light_area_set_size(light: RID, size: Vector2) -> void` — Sets the extents (width and height) in meters for this area light.
- `light_directional_set_blend_splits(light: RID, enable: bool) -> void` — If `true`, this directional light will blend between shadow map splits resulting in a smoother transition between them.
- `light_directional_set_shadow_mode(light: RID, mode: RenderingServer.LightDirectionalShadowMode) -> void` — Sets the shadow mode for this directional light.
- `light_directional_set_sky_mode(light: RID, mode: RenderingServer.LightDirectionalSkyMode) -> void` — If `true`, this light will not be used for anything except sky shaders.
- `light_omni_set_shadow_mode(light: RID, mode: RenderingServer.LightOmniShadowMode) -> void` — Sets whether to use a dual paraboloid or a cubemap for the shadow map.
- `light_projectors_set_filter(filter: RenderingServer.LightProjectorFilter) -> void` — Sets the texture filter mode to use when rendering light projectors.
- `light_set_allow_contact_shadows(light: RID, enable: bool) -> void` — If `true`, allows screen-space contact shadows for this light.
- `light_set_bake_mode(light: RID, bake_mode: RenderingServer.LightBakeMode) -> void` — Sets the bake mode to use for the specified 3D light.
- `light_set_color(light: RID, color: Color) -> void` — Sets the color of the light.
- `light_set_cull_mask(light: RID, mask: int) -> void` — Sets the cull mask for this 3D light.
- `light_set_distance_fade(decal: RID, enabled: bool, begin: float, shadow: float, length: float) -> void` — Sets the distance fade for this 3D light.
- `light_set_max_sdfgi_cascade(light: RID, cascade: int) -> void` — Sets the maximum SDFGI cascade in which the 3D light's indirect lighting is rendered.
- `light_set_negative(light: RID, enable: bool) -> void` — If `true`, the 3D light will subtract light instead of adding light.
- `light_set_param(light: RID, param: RenderingServer.LightParam, value: float) -> void` — Sets the specified 3D light parameter.
- `light_set_projector(light: RID, texture: RID) -> void` — Sets the projector texture to use for the specified 3D light.
- `light_set_reverse_cull_face_mode(light: RID, enabled: bool) -> void` — If `true`, reverses the backface culling of the mesh.
- `light_set_shadow(light: RID, enabled: bool) -> void` — If `true`, light will cast shadows.
- `light_set_shadow_caster_mask(light: RID, mask: int) -> void` — Sets the shadow caster mask for this 3D light.
- `lightmap_create() -> RID` — Creates a new lightmap global illumination instance and adds it to the RenderingServer.
- `lightmap_get_probe_capture_bsp_tree(lightmap: RID) -> PackedInt32Array` *const* — Returns the BSP tree data used for accelerating probe lookups.
- `lightmap_get_probe_capture_points(lightmap: RID) -> PackedVector3Array` *const* — Returns the local space positions of each lightmap probe capture point.
- `lightmap_get_probe_capture_sh(lightmap: RID) -> PackedColorArray` *const* — Returns the L0, L1, and L2 spherical harmonics data for each lightmap probe capture point.
- `lightmap_get_probe_capture_tetrahedra(lightmap: RID) -> PackedInt32Array` *const* — Returns the tetrahedralization data used for interpolating between lightmap probe capture points.
- `lightmap_set_baked_exposure_normalization(lightmap: RID, baked_exposure: float) -> void` — Used to inform the renderer what exposure normalization value was used while baking the lightmap.
- `lightmap_set_probe_bounds(lightmap: RID, bounds: AABB) -> void` — Sets the bounds that this lightmap instance should visually affect, both in terms of static lightmap baking and probe-based global illumination.
- `lightmap_set_probe_capture_data(lightmap: RID, points: PackedVector3Array, point_sh: PackedColorArray, tetrahedra: PackedInt32Array, bsp_tree: PackedInt32Array) -> void` — Sets the probe capture data for the given lightmap instance.
- `lightmap_set_probe_capture_update_speed(speed: float) -> void` — The framerate-independent update speed when representing dynamic object lighting from LightmapProbes.
- `lightmap_set_probe_interior(lightmap: RID, interior: bool) -> void` — Sets whether the lightmap instance should be considered as interior (when `interior` is `true`).
- `lightmap_set_textures(lightmap: RID, light: RID, uses_sh: bool) -> void` — Set the textures on the given `lightmap` GI instance to the texture array pointed to by the `light` RID.
- `lightmaps_set_bicubic_filter(enable: bool) -> void` — Toggles whether a bicubic filter should be used when lightmaps are sampled.
- `make_sphere_mesh(latitudes: int, longitudes: int, radius: float) -> RID` — Returns a mesh of a sphere with the given number of horizontal subdivisions, vertical subdivisions and radius.
- `material_create() -> RID` — Creates an empty material and adds it to the RenderingServer.
- `material_get_param(material: RID, parameter: StringName) -> Variant` *const* — Returns the value of a certain material's parameter.
- `material_set_next_pass(material: RID, next_material: RID) -> void` — Sets an object's next material.
- `material_set_param(material: RID, parameter: StringName, value: Variant) -> void` — Sets a material's parameter.
- `material_set_render_priority(material: RID, priority: int) -> void` — Sets a material's render priority.
- `material_set_shader(shader_material: RID, shader: RID) -> void` — Sets a shader material's shader.
- `material_set_use_debanding(enable: bool) -> void` — When using the Mobile renderer, `material_set_use_debanding` can be used to enable or disable the debanding feature of 3D materials (BaseMaterial3D and ShaderMaterial).
- `mesh_add_surface(mesh: RID, surface: Dictionary) -> void` — Creates a new surface on the given `mesh`.
- `mesh_add_surface_from_arrays(mesh: RID, primitive: RenderingServer.PrimitiveType, arrays: Array, blend_shapes: Array = [], lods: Dictionary = {}, compress_format: RenderingServer.ArrayFormat = 0) -> void` — Creates a new surface on the given `mesh`.
- `mesh_clear(mesh: RID) -> void` — Removes all surfaces from a mesh.
- `mesh_create() -> RID` — Creates a new mesh and adds it to the RenderingServer.
- `mesh_create_from_surfaces(surfaces: Dictionary[], blend_shape_count: int = 0) -> RID` — Creates a new mesh with predefined surfaces for it and adds the mesh to the RenderingServer.
- `mesh_get_blend_shape_count(mesh: RID) -> int` *const* — Returns a mesh's blend shape count.
- `mesh_get_blend_shape_mode(mesh: RID) -> int[RenderingServer.BlendShapeMode]` *const* — Returns a mesh's blend shape mode.
- `mesh_get_custom_aabb(mesh: RID) -> AABB` *const* — Returns a mesh's custom aabb.
- `mesh_get_surface(mesh: RID, surface: int) -> Dictionary` — Returns a mesh's surface as a dictionary following the same structure as described in `mesh_add_surface`.
- `mesh_get_surface_count(mesh: RID) -> int` *const* — Returns a mesh's number of surfaces.
- `mesh_set_blend_shape_mode(mesh: RID, mode: RenderingServer.BlendShapeMode) -> void` — Sets a mesh's blend shape mode.
- `mesh_set_custom_aabb(mesh: RID, aabb: AABB) -> void` — Sets a mesh's custom aabb.
- `mesh_set_shadow_mesh(mesh: RID, shadow_mesh: RID) -> void` — Sets an optional second mesh which can be used for rendering shadows and the depth prepass.
- `mesh_surface_get_arrays(mesh: RID, surface: int) -> Array` *const* — Returns a mesh's surface's buffer arrays.
- `mesh_surface_get_attribute_buffer_rd_rid(mesh: RID, surface: int) -> RID` *const* — Returns the RenderingDevice RID handle of the attribute buffer of the given mesh surface (Color, UV, UV2, Custom0-3).
- `mesh_surface_get_blend_shape_arrays(mesh: RID, surface: int) -> Array[]` *const* — Returns a mesh's surface's arrays for blend shapes.
- `mesh_surface_get_format_attribute_stride(format: RenderingServer.ArrayFormat, vertex_count: int) -> int` *const* — Returns the stride of the attribute buffer for a mesh with given `format`.
- `mesh_surface_get_format_index_stride(format: RenderingServer.ArrayFormat, vertex_count: int) -> int` *const* — Returns the stride of the index buffer for a mesh with the given `format`.
- `mesh_surface_get_format_normal_tangent_stride(format: RenderingServer.ArrayFormat, vertex_count: int) -> int` *const* — Returns the stride of the combined normals and tangents for a mesh with given `format`.
- `mesh_surface_get_format_offset(format: RenderingServer.ArrayFormat, vertex_count: int, array_index: int) -> int` *const* — Returns the offset of a given attribute by `array_index` in the start of its respective buffer.
- `mesh_surface_get_format_skin_stride(format: RenderingServer.ArrayFormat, vertex_count: int) -> int` *const* — Returns the stride of the skin buffer for a mesh with given `format`.
- `mesh_surface_get_format_vertex_stride(format: RenderingServer.ArrayFormat, vertex_count: int) -> int` *const* — Returns the stride of the vertex positions for a mesh with given `format`.
- `mesh_surface_get_index_buffer_rd_rid(mesh: RID, surface: int) -> RID` *const* — Returns the RenderingDevice RID handle of the index buffer of the given mesh surface.
- `mesh_surface_get_material(mesh: RID, surface: int) -> RID` *const* — Returns a mesh's surface's material.
- `mesh_surface_get_skin_buffer_rd_rid(mesh: RID, surface: int) -> RID` *const* — Returns the RenderingDevice RID handle of the skin buffer of the given mesh surface (Bones, Weights).
- `mesh_surface_get_vertex_buffer_rd_rid(mesh: RID, surface: int) -> RID` *const* — Returns the RenderingDevice RID handle of the vertex buffer of the given mesh surface (Vertex, Normal, Tangent).
- `mesh_surface_remove(mesh: RID, surface: int) -> void` — Removes the surface at the given index from the Mesh, shifting surfaces with higher index down by one.
- `mesh_surface_set_material(mesh: RID, surface: int, material: RID) -> void` — Sets a mesh's surface's material.
- `mesh_surface_update_attribute_region(mesh: RID, surface: int, offset: int, data: PackedByteArray) -> void` — Updates the attribute buffer of the mesh surface with the given `data`.
- `mesh_surface_update_index_region(mesh: RID, surface: int, offset: int, data: PackedByteArray) -> void` — Updates the index buffer of the mesh surface with the given `data`.
- `mesh_surface_update_skin_region(mesh: RID, surface: int, offset: int, data: PackedByteArray) -> void` — Updates the skin buffer of the mesh surface with the given `data`.
- `mesh_surface_update_vertex_region(mesh: RID, surface: int, offset: int, data: PackedByteArray) -> void` — Updates the vertex buffer of the mesh surface with the given `data`.
- `multimesh_allocate_data(multimesh: RID, instances: int, transform_format: RenderingServer.MultimeshTransformFormat, color_format: bool = false, custom_data_format: bool = false, use_indirect: bool = false) -> void` — Sets up the multimesh using the specified data.
- `multimesh_create() -> RID` — Creates a new multimesh on the RenderingServer and returns an RID handle.
- `multimesh_get_aabb(multimesh: RID) -> AABB` *const* — Calculates and returns the axis-aligned bounding box that encloses all instances within the multimesh.
- `multimesh_get_buffer(multimesh: RID) -> PackedFloat32Array` *const* — Returns the MultiMesh data (such as instance transforms, colors, etc.).
- `multimesh_get_buffer_rd_rid(multimesh: RID) -> RID` *const* — Returns the RenderingDevice RID handle of the MultiMesh, which can be used as any other buffer on the Rendering Device.
- `multimesh_get_command_buffer_rd_rid(multimesh: RID) -> RID` *const* — Returns the RenderingDevice RID handle of the MultiMesh command buffer.
- `multimesh_get_custom_aabb(multimesh: RID) -> AABB` *const* — Returns the custom AABB defined for this MultiMesh resource.
- `multimesh_get_instance_count(multimesh: RID) -> int` *const* — Returns the number of instances allocated for this multimesh.
- `multimesh_get_mesh(multimesh: RID) -> RID` *const* — Returns the RID of the mesh that will be used in drawing this multimesh.
- `multimesh_get_visible_instances(multimesh: RID) -> int` *const* — Returns the number of visible instances for this multimesh.
- `multimesh_instance_get_color(multimesh: RID, index: int) -> Color` *const* — Returns the color by which the specified instance will be modulated.
- `multimesh_instance_get_custom_data(multimesh: RID, index: int) -> Color` *const* — Returns the custom data associated with the specified instance.
- `multimesh_instance_get_transform(multimesh: RID, index: int) -> Transform3D` *const* — Returns the Transform3D of the specified instance.
- `multimesh_instance_get_transform_2d(multimesh: RID, index: int) -> Transform2D` *const* — Returns the Transform2D of the specified instance.
- `multimesh_instance_reset_physics_interpolation(multimesh: RID, index: int) -> void` — Prevents physics interpolation for the specified instance during the current physics tick.
- `multimesh_instance_set_color(multimesh: RID, index: int, color: Color) -> void` — Sets the color by which this instance will be modulated.
- `multimesh_instance_set_custom_data(multimesh: RID, index: int, custom_data: Color) -> void` — Sets the custom data for this instance.
- `multimesh_instance_set_transform(multimesh: RID, index: int, transform: Transform3D) -> void` — Sets the Transform3D for this instance.
- `multimesh_instance_set_transform_2d(multimesh: RID, index: int, transform: Transform2D) -> void` — Sets the Transform2D for this instance.
- `multimesh_instances_reset_physics_interpolation(multimesh: RID) -> void` — Prevents physics interpolation for all instances during the current physics tick.
- `multimesh_set_buffer(multimesh: RID, buffer: PackedFloat32Array) -> void` — Set the entire data to use for drawing the `multimesh` at once to `buffer` (such as instance transforms and colors).
- `multimesh_set_buffer_interpolated(multimesh: RID, buffer: PackedFloat32Array, buffer_previous: PackedFloat32Array) -> void` — Alternative version of `multimesh_set_buffer` for use with physics interpolation.
- `multimesh_set_custom_aabb(multimesh: RID, aabb: AABB) -> void` — Sets the custom AABB for this MultiMesh resource.
- `multimesh_set_mesh(multimesh: RID, mesh: RID) -> void` — Sets the mesh to be drawn by the multimesh.
- `multimesh_set_physics_interpolated(multimesh: RID, interpolated: bool) -> void` — Turns on and off physics interpolation for this MultiMesh resource.
- `multimesh_set_physics_interpolation_quality(multimesh: RID, quality: RenderingServer.MultimeshPhysicsInterpolationQuality) -> void` — Sets the physics interpolation quality for the MultiMesh.
- `multimesh_set_visible_instances(multimesh: RID, visible: int) -> void` — Sets the number of instances visible at a given time.
- `occluder_create() -> RID` — Creates an occluder instance and adds it to the RenderingServer.
- `occluder_set_mesh(occluder: RID, vertices: PackedVector3Array, indices: PackedInt32Array) -> void` — Sets the mesh data for the given occluder RID, which controls the shape of the occlusion culling that will be performed.
- `omni_light_create() -> RID` — Creates a new omni light and adds it to the RenderingServer.
- `particles_collision_create() -> RID` — Creates a new 3D GPU particle collision or attractor and adds it to the RenderingServer.
- `particles_collision_height_field_update(particles_collision: RID) -> void` — Requests an update for the 3D GPU particle collision heightfield.
- `particles_collision_set_attractor_attenuation(particles_collision: RID, curve: float) -> void` — Sets the attenuation `curve` for the 3D GPU particles attractor specified by the `particles_collision` RID.
- `particles_collision_set_attractor_directionality(particles_collision: RID, amount: float) -> void` — Sets the directionality `amount` for the 3D GPU particles attractor specified by the `particles_collision` RID.
- `particles_collision_set_attractor_strength(particles_collision: RID, strength: float) -> void` — Sets the `strength` for the 3D GPU particles attractor specified by the `particles_collision` RID.
- `particles_collision_set_box_extents(particles_collision: RID, extents: Vector3) -> void` — Sets the `extents` for the 3D GPU particles collision by the `particles_collision` RID.
- `particles_collision_set_collision_type(particles_collision: RID, type: RenderingServer.ParticlesCollisionType) -> void` — Sets the collision or attractor shape `type` for the 3D GPU particles collision or attractor specified by the `particles_collision` RID.
- `particles_collision_set_cull_mask(particles_collision: RID, mask: int) -> void` — Sets the cull `mask` for the 3D GPU particles collision or attractor specified by the `particles_collision` RID.
- `particles_collision_set_field_texture(particles_collision: RID, texture: RID) -> void` — Sets the signed distance field `texture` for the 3D GPU particles collision specified by the `particles_collision` RID.
- `particles_collision_set_height_field_mask(particles_collision: RID, mask: int) -> void` — Sets the heightfield `mask` for the 3D GPU particles heightfield collision specified by the `particles_collision` RID.
- `particles_collision_set_height_field_resolution(particles_collision: RID, resolution: RenderingServer.ParticlesCollisionHeightfieldResolution) -> void` — Sets the heightmap `resolution` for the 3D GPU particles heightfield collision specified by the `particles_collision` RID.
- `particles_collision_set_sphere_radius(particles_collision: RID, radius: float) -> void` — Sets the `radius` for the 3D GPU particles sphere collision or attractor specified by the `particles_collision` RID.
- `particles_create() -> RID` — Creates a GPU-based particle system and adds it to the RenderingServer.
- `particles_emit(particles: RID, transform: Transform3D, velocity: Vector3, color: Color, custom: Color, emit_flags: int) -> void` — Manually emits particles from the `particles` instance.
- `particles_get_current_aabb(particles: RID) -> AABB` — Calculates and returns the axis-aligned bounding box that contains all the particles.
- `particles_get_emitting(particles: RID) -> bool` — Returns `true` if particles are currently set to emitting.
- `particles_is_inactive(particles: RID) -> bool` — Returns `true` if particles are not emitting and particles are set to inactive.
- `particles_request_process(particles: RID) -> void` — Add particle system to list of particle systems that need to be updated.
- `particles_request_process_time(particles: RID, process_time: float, process_time_residual: float = 0.0) -> void` — Requests the particles to process for extra process time during a single frame.
- `particles_restart(particles: RID) -> void` — Reset the particles on the next update.
- `particles_set_amount(particles: RID, amount: int) -> void` — Sets the number of particles to be drawn and allocates the memory for them.
- `particles_set_amount_ratio(particles: RID, ratio: float) -> void` — Sets the amount ratio for particles to be emitted.
- `particles_set_collision_base_size(particles: RID, size: float) -> void` — Sets the base size for particle collision.
- `particles_set_custom_aabb(particles: RID, aabb: AABB) -> void` — Sets a custom axis-aligned bounding box for the particle system.
- `particles_set_draw_order(particles: RID, order: RenderingServer.ParticlesDrawOrder) -> void` — Sets the draw order of the particles.
- `particles_set_draw_pass_mesh(particles: RID, pass: int, mesh: RID) -> void` — Sets the mesh to be used for the specified draw pass.
- `particles_set_draw_passes(particles: RID, count: int) -> void` — Sets the number of draw passes to use.
- `particles_set_emission_transform(particles: RID, transform: Transform3D) -> void` — Sets the Transform3D that will be used by the particles when they first emit.
- `particles_set_emitter_velocity(particles: RID, velocity: Vector3) -> void` — Sets the velocity of a particle node, that will be used by `ParticleProcessMaterial.inherit_velocity_ratio`.
- `particles_set_emitting(particles: RID, emitting: bool) -> void` — If `true`, particles will emit over time.
- `particles_set_explosiveness_ratio(particles: RID, ratio: float) -> void` — Sets the explosiveness ratio.
- `particles_set_fixed_fps(particles: RID, fps: int) -> void` — Sets the frame rate that the particle system rendering will be fixed to.
- `particles_set_fractional_delta(particles: RID, enable: bool) -> void` — If `true`, uses fractional delta which smooths the movement of the particles.
- `particles_set_interp_to_end(particles: RID, factor: float) -> void` — Sets the value that informs a ParticleProcessMaterial to rush all particles towards the end of their lifetime.
- `particles_set_interpolate(particles: RID, enable: bool) -> void` — Sets whether particles should use interpolation between fixed steps.
- `particles_set_lifetime(particles: RID, lifetime: float) -> void` — Sets the lifetime of each particle in the system.
- `particles_set_mode(particles: RID, mode: RenderingServer.ParticlesMode) -> void` — Sets whether the GPU particles specified by the `particles` RID should be rendered in 2D or 3D according to `mode`.
- `particles_set_one_shot(particles: RID, one_shot: bool) -> void` — If `true`, particles will emit once and then stop.
- `particles_set_pre_process_time(particles: RID, time: float) -> void` — Sets the preprocess time for the particles' animation.
- `particles_set_process_material(particles: RID, material: RID) -> void` — Sets the material for processing the particles.
- `particles_set_randomness_ratio(particles: RID, ratio: float) -> void` — Sets the emission randomness ratio.
- `particles_set_speed_scale(particles: RID, scale: float) -> void` — Sets the speed scale of the particle system.
- `particles_set_subemitter(particles: RID, subemitter_particles: RID) -> void` — Sets the subemitter particles for the particle system.
- `particles_set_trail_bind_poses(particles: RID, bind_poses: Transform3D[]) -> void` — Sets the trail bind poses for the particle system.
- `particles_set_trails(particles: RID, enable: bool, length_sec: float) -> void` — If `enable` is `true`, enables trails for the `particles` with the specified `length_sec` in seconds.
- `particles_set_transform_align(particles: RID, align: RenderingServer.ParticlesTransformAlign) -> void` — Sets the transform alignment for the particle system.
- `particles_set_transform_align_axis(particles: RID, rotation_axis: RenderingServer.ParticlesTransformAlignAxis) -> void` — Sets which axis to use for transform alignment.
- `particles_set_transform_align_channel_filter(particles: RID, channel_filter: RenderingServer.ParticlesTransformAlignCustomSrc) -> void` — When using Z-Billboarding, which CUSTOM channel to read from.
- `particles_set_use_local_coordinates(particles: RID, enable: bool) -> void` — If `true`, particles use local coordinates.
- `positional_soft_shadow_filter_set_quality(quality: RenderingServer.ShadowQuality) -> void` — Sets the filter quality for omni and spot light shadows in 3D.
- `reflection_probe_create() -> RID` — Creates a reflection probe and adds it to the RenderingServer.
- `reflection_probe_set_ambient_color(probe: RID, color: Color) -> void` — Sets the reflection probe's custom ambient light color.
- `reflection_probe_set_ambient_energy(probe: RID, energy: float) -> void` — Sets the reflection probe's custom ambient light energy.
- `reflection_probe_set_ambient_mode(probe: RID, mode: RenderingServer.ReflectionProbeAmbientMode) -> void` — Sets the reflection probe's ambient light mode.
- `reflection_probe_set_as_interior(probe: RID, enable: bool) -> void` — If `true`, reflections will ignore sky contribution.
- `reflection_probe_set_blend_distance(probe: RID, blend_distance: float) -> void` — Sets the distance in meters over which a probe blends into the scene.
- `reflection_probe_set_cull_mask(probe: RID, layers: int) -> void` — Sets the render cull mask for this reflection probe.
- `reflection_probe_set_enable_box_projection(probe: RID, enable: bool) -> void` — If `true`, uses box projection.
- `reflection_probe_set_enable_shadows(probe: RID, enable: bool) -> void` — If `true`, computes shadows in the reflection probe.
- `reflection_probe_set_intensity(probe: RID, intensity: float) -> void` — Sets the intensity of the reflection probe.
- `reflection_probe_set_max_distance(probe: RID, distance: float) -> void` — Sets the max distance away from the probe an object can be before it is culled.
- `reflection_probe_set_mesh_lod_threshold(probe: RID, pixels: float) -> void` — Sets the mesh level of detail to use in the reflection probe rendering.
- `reflection_probe_set_origin_offset(probe: RID, offset: Vector3) -> void` — Sets the origin offset to be used when this reflection probe is in box project mode.
- `reflection_probe_set_reflection_mask(probe: RID, layers: int) -> void` — Sets the render reflection mask for this reflection probe.
- `reflection_probe_set_resolution(probe: RID, resolution: int) -> void` *(deprecated)* — Deprecated.
- `reflection_probe_set_size(probe: RID, size: Vector3) -> void` — Sets the size of the area that the reflection probe will capture.
- `reflection_probe_set_update_mode(probe: RID, mode: RenderingServer.ReflectionProbeUpdateMode) -> void` — Sets how often the reflection probe updates.
- `request_frame_drawn_callback(callable: Callable) -> void` — Schedules a callback to the given callable after a frame has been drawn.
- `scenario_create() -> RID` — Creates a scenario and adds it to the RenderingServer.
- `scenario_set_camera_attributes(scenario: RID, effects: RID) -> void` — Sets the camera attributes (`effects`) that will be used with this scenario.
- `scenario_set_compositor(scenario: RID, compositor: RID) -> void` — Sets the compositor (`compositor`) that will be used with this scenario.
- `scenario_set_environment(scenario: RID, environment: RID) -> void` — Sets the environment that will be used with this scenario.
- `scenario_set_fallback_environment(scenario: RID, environment: RID) -> void` — Sets the fallback environment to be used by this scenario.
- `screen_space_roughness_limiter_set_active(enable: bool, amount: float, limit: float) -> void` — Sets the screen-space roughness limiter parameters, such as whether it should be enabled and its thresholds.
- `set_boot_image(image: Image, color: Color, scale: bool, use_filter: bool = true) -> void` *(deprecated)* — Sets a boot image.
- `set_boot_image_with_stretch(image: Image, color: Color, stretch_mode: RenderingServer.SplashStretchMode, use_filter: bool = true) -> void` — Sets a boot image.
- `set_debug_generate_wireframes(generate: bool) -> void` — If `generate` is `true`, generates debug wireframes for all meshes that are loaded when using the Compatibility renderer.
- `set_default_clear_color(color: Color) -> void` — Sets the default clear color which is used when a specific clear color has not been selected.
- `shader_create() -> RID` — Creates an empty shader and adds it to the RenderingServer.
- `shader_get_code(shader: RID) -> String` *const* — Returns a shader's source code as a string.
- `shader_get_default_texture_parameter(shader: RID, name: StringName, index: int = 0) -> RID` *const* — Returns a default texture from a shader searched by name.
- `shader_get_parameter_default(shader: RID, name: StringName) -> Variant` *const* — Returns the default value for the specified shader uniform.
- `shader_set_code(shader: RID, code: String) -> void` — Sets the shader's source code (which triggers recompilation after being changed).
- `shader_set_default_texture_parameter(shader: RID, name: StringName, texture: RID, index: int = 0) -> void` — Sets a shader's default texture.
- `shader_set_path_hint(shader: RID, path: String) -> void` — Sets the path hint for the specified shader.
- `skeleton_allocate_data(skeleton: RID, bones: int, is_2d_skeleton: bool = false) -> void` — Allocates data for this skeleton using the number of bones specified in `bones`.
- `skeleton_bone_get_transform(skeleton: RID, bone: int) -> Transform3D` *const* — Returns the Transform3D set for a specific bone of this skeleton.
- `skeleton_bone_get_transform_2d(skeleton: RID, bone: int) -> Transform2D` *const* — Returns the Transform2D set for a specific bone of this skeleton.
- `skeleton_bone_set_transform(skeleton: RID, bone: int, transform: Transform3D) -> void` — Sets the Transform3D for a specific bone of this skeleton.
- `skeleton_bone_set_transform_2d(skeleton: RID, bone: int, transform: Transform2D) -> void` — Sets the Transform2D for a specific bone of this skeleton.
- `skeleton_create() -> RID` — Creates a skeleton and adds it to the RenderingServer.
- `skeleton_get_bone_count(skeleton: RID) -> int` *const* — Returns the number of bones allocated for this skeleton.
- `skeleton_set_base_transform_2d(skeleton: RID, base_transform: Transform2D) -> void` — Sets the base Transform2D to use for the specified skeleton.
- `sky_bake_panorama(sky: RID, energy: float, bake_irradiance: bool, size: Vector2i) -> Image` — Generates and returns an Image containing the radiance map for the specified `sky` RID.
- `sky_create() -> RID` — Creates an empty sky and adds it to the RenderingServer.
- `sky_set_material(sky: RID, material: RID) -> void` — Sets the material that the sky uses to render the background, ambient and reflection maps.
- `sky_set_mode(sky: RID, mode: RenderingServer.SkyMode) -> void` — Sets the process `mode` of the sky specified by the `sky` RID.
- `sky_set_radiance_size(sky: RID, radiance_size: int) -> void` — Sets the `radiance_size` of the sky specified by the `sky` RID (in pixels).
- `spot_light_create() -> RID` — Creates a spot light and adds it to the RenderingServer.
- `sub_surface_scattering_set_quality(quality: RenderingServer.SubSurfaceScatteringQuality) -> void` — Sets `ProjectSettings.rendering/environment/subsurface_scattering/subsurface_scattering_quality` to use when rendering materials that have subsurface scattering enabled.
- `sub_surface_scattering_set_scale(scale: float, depth_scale: float) -> void` — Sets the `ProjectSettings.rendering/environment/subsurface_scattering/subsurface_scattering_scale` and `ProjectSettings.rendering/environment/subsurface_scattering/subsurface_scattering_depth_scale` to use when rendering materials that have subsurface scattering enabled.
- `texture_2d_create(image: Image) -> RID` — Creates a 2-dimensional texture and adds it to the RenderingServer.
- `texture_2d_get(texture: RID) -> Image` *const* — Returns an Image instance from the given `texture` RID.
- `texture_2d_layer_get(texture: RID, layer: int) -> Image` *const* — Returns an Image instance from the given `texture` RID and `layer`.
- `texture_2d_layered_create(layers: Image[], layered_type: RenderingServer.TextureLayeredType) -> RID` — Creates a 2-dimensional layered texture and adds it to the RenderingServer.
- `texture_2d_layered_placeholder_create(layered_type: RenderingServer.TextureLayeredType) -> RID` — Creates a placeholder for a 2-dimensional layered texture and adds it to the RenderingServer.
- `texture_2d_placeholder_create() -> RID` — Creates a placeholder for a 2-dimensional layered texture and adds it to the RenderingServer.
- `texture_2d_update(texture: RID, image: Image, layer: int) -> void` — Updates the texture specified by the `texture` RID with the data in `image`.
- `texture_3d_create(format: Image.Format, width: int, height: int, depth: int, mipmaps: bool, data: Image[]) -> RID` — Note: The equivalent resource is Texture3D.
- `texture_3d_get(texture: RID) -> Image[]` *const* — Returns 3D texture data as an array of Images for the specified texture RID.
- `texture_3d_placeholder_create() -> RID` — Creates a placeholder for a 3-dimensional texture and adds it to the RenderingServer.
- `texture_3d_update(texture: RID, data: Image[]) -> void` — Updates the texture specified by the `texture` RID's data with the data in `data`.
- `texture_create_from_native_handle(type: RenderingServer.TextureType, format: Image.Format, native_handle: int, width: int, height: int, depth: int, layers: int = 1, layered_type: RenderingServer.TextureLayeredType = 0) -> RID` — Creates a texture based on a native handle that was created outside of Godot's renderer.
- `texture_drawable_blit_rect(textures: RID[], rect: Rect2i, material: RID, modulate: Color, source_textures: RID[], to_mipmap: int = 0) -> void` — Draws to `rect` on up to 4 given Drawable `textures`, using a TextureBlit Shader from `material`.
- `texture_drawable_create(width: int, height: int, format: RenderingServer.TextureDrawableFormat, color: Color = Color(1, 1, 1, 1), with_mipmaps: bool = false) -> RID` — Creates a 2-dimensional texture and adds it to the RenderingServer.
- `texture_drawable_generate_mipmaps(texture: RID) -> void` — Calculates new MipMaps for the given Drawable `texture`.
- `texture_drawable_get_default_material() -> RID` *const* — Returns a ShaderMaterial with the default texture_blit Shader.
- `texture_get_format(texture: RID) -> int[Image.Format]` *const* — Returns the format for the texture.
- `texture_get_native_handle(texture: RID, srgb: bool = false) -> int` *const* — Returns the internal graphics handle for this texture object.
- `texture_get_path(texture: RID) -> String` *const* — Returns the resource path (starting with `res://` or `uid://`) for the specified texture RID.
- `texture_get_rd_texture(texture: RID, srgb: bool = false) -> RID` *const* — Returns a texture RID that can be used with RenderingDevice.
- `texture_proxy_create(base: RID) -> RID` *(deprecated)* — This method does nothing and always returns an invalid RID.
- `texture_proxy_update(texture: RID, proxy_to: RID) -> void` *(deprecated)* — This method does nothing.
- `texture_rd_create(rd_texture: RID, layer_type: RenderingServer.TextureLayeredType = 0) -> RID` — Creates a new texture object based on a texture created directly on the RenderingDevice.
- `texture_replace(texture: RID, by_texture: RID) -> void` — Replaces `texture`'s texture data by the texture specified by the `by_texture` RID, without changing `texture`'s RID.
- `texture_replace_compatible(texture: RID, by_texture: RID) -> void` — Replaces `texture`'s texture data by the texture specified by the `by_texture` RID, without changing `texture`'s RID.
- `texture_set_force_redraw_if_visible(texture: RID, enable: bool) -> void` — Sets whether the texture RID should force redrawing when it's visible on screen when `OS.low_processor_usage_mode` is `true`.
- `texture_set_path(texture: RID, path: String) -> void` — Sets the resource path for this texture RID.
- `texture_set_size_override(texture: RID, width: int, height: int) -> void` — Sets the size at which the texture should be displayed in 2D, ignoring its original size.
- `viewport_attach_camera(viewport: RID, camera: RID) -> void` — Sets a viewport's camera.
- `viewport_attach_canvas(viewport: RID, canvas: RID) -> void` — Sets a viewport's canvas.
- `viewport_attach_to_screen(viewport: RID, rect: Rect2 = Rect2(0, 0, 0, 0), screen: int = 0) -> void` — Copies the viewport to a region of the screen specified by `rect`.
- `viewport_create() -> RID` — Creates an empty viewport and adds it to the RenderingServer.
- `viewport_get_measured_render_time_cpu(viewport: RID) -> float` *const* — Returns the CPU time taken to render the last frame in milliseconds.
- `viewport_get_measured_render_time_gpu(viewport: RID) -> float` *const* — Returns the GPU time taken to render the last frame in milliseconds.
- `viewport_get_render_info(viewport: RID, type: RenderingServer.ViewportRenderInfoType, info: RenderingServer.ViewportRenderInfo) -> int` — Returns a statistic about the rendering engine which can be used for performance profiling.
- `viewport_get_render_target(viewport: RID) -> RID` *const* — Returns the render target for the viewport.
- `viewport_get_texture(viewport: RID) -> RID` *const* — Returns the viewport's last rendered frame.
- `viewport_get_update_mode(viewport: RID) -> int[RenderingServer.ViewportUpdateMode]` *const* — Returns the viewport's update mode.
- `viewport_remove_canvas(viewport: RID, canvas: RID) -> void` — Detaches a viewport from a canvas.
- `viewport_set_active(viewport: RID, active: bool) -> void` — If `true`, sets the viewport active, else sets it inactive.
- `viewport_set_anisotropic_filtering_level(viewport: RID, anisotropic_filtering_level: RenderingServer.ViewportAnisotropicFiltering) -> void` — Sets the maximum number of samples to take when using anisotropic filtering on textures (as a power of two).
- `viewport_set_canvas_cull_mask(viewport: RID, canvas_cull_mask: int) -> void` — Sets the rendering mask associated with this Viewport.
- `viewport_set_canvas_stacking(viewport: RID, canvas: RID, layer: int, sublayer: int) -> void` — Sets the stacking order for a viewport's canvas.
- `viewport_set_canvas_transform(viewport: RID, canvas: RID, offset: Transform2D) -> void` — Sets the transformation of a viewport's canvas.
- `viewport_set_clear_mode(viewport: RID, clear_mode: RenderingServer.ViewportClearMode) -> void` — Sets the clear mode of a viewport.
- `viewport_set_debug_draw(viewport: RID, draw: RenderingServer.ViewportDebugDraw) -> void` — Sets the debug draw mode of a viewport.
- `viewport_set_default_canvas_item_texture_filter(viewport: RID, filter: RenderingServer.CanvasItemTextureFilter) -> void` — Sets the default texture filtering mode for the specified `viewport` RID.
- `viewport_set_default_canvas_item_texture_repeat(viewport: RID, repeat: RenderingServer.CanvasItemTextureRepeat) -> void` — Sets the default texture repeat mode for the specified `viewport` RID.
- `viewport_set_disable_2d(viewport: RID, disable: bool) -> void` — If `true`, the viewport's canvas (i.e. 2D and GUI elements) is not rendered.
- `viewport_set_disable_3d(viewport: RID, disable: bool) -> void` — If `true`, the viewport's 3D elements are not rendered.
- `viewport_set_environment_mode(viewport: RID, mode: RenderingServer.ViewportEnvironmentMode) -> void` — Sets the viewport's environment mode which allows enabling or disabling rendering of 3D environment over 2D canvas.
- `viewport_set_fsr_sharpness(viewport: RID, sharpness: float) -> void` — Determines how sharp the upscaled image will be when using the FSR upscaling mode.
- `viewport_set_global_canvas_transform(viewport: RID, transform: Transform2D) -> void` — Sets the viewport's global transformation matrix.
- `viewport_set_measure_render_time(viewport: RID, enable: bool) -> void` — Sets the measurement for the given `viewport` RID (obtained using `Viewport.get_viewport_rid`).
- `viewport_set_msaa_2d(viewport: RID, msaa: RenderingServer.ViewportMSAA) -> void` — Sets the multisample antialiasing mode for 2D/Canvas on the specified `viewport` RID.
- `viewport_set_msaa_3d(viewport: RID, msaa: RenderingServer.ViewportMSAA) -> void` — Sets the multisample antialiasing mode for 3D on the specified `viewport` RID.
- `viewport_set_occlusion_culling_build_quality(quality: RenderingServer.ViewportOcclusionCullingBuildQuality) -> void` — Sets the `ProjectSettings.rendering/occlusion_culling/bvh_build_quality` to use for occlusion culling.
- `viewport_set_occlusion_rays_per_thread(rays_per_thread: int) -> void` — Sets the `ProjectSettings.rendering/occlusion_culling/occlusion_rays_per_thread` to use for occlusion culling.
- `viewport_set_parent_viewport(viewport: RID, parent_viewport: RID) -> void` — Sets the viewport's parent to the viewport specified by the `parent_viewport` RID.
- `viewport_set_positional_shadow_atlas_quadrant_subdivision(viewport: RID, quadrant: int, subdivision: int) -> void` — Sets the number of subdivisions to use in the specified shadow atlas `quadrant` for omni and spot shadows.
- `viewport_set_positional_shadow_atlas_size(viewport: RID, size: int, use_16_bits: bool = false) -> void` — Sets the `size` of the shadow atlas's images (used for omni and spot lights) on the viewport specified by the `viewport` RID.
- `viewport_set_render_direct_to_screen(viewport: RID, enabled: bool) -> void` — If `true`, render the contents of the viewport directly to screen.
- `viewport_set_scaling_3d_mode(viewport: RID, scaling_3d_mode: RenderingServer.ViewportScaling3DMode) -> void` — Sets the 3D resolution scaling mode.
- `viewport_set_scaling_3d_scale(viewport: RID, scale: float) -> void` — Scales the 3D render buffer based on the viewport size uses an image filter specified in `ViewportScaling3DMode` to scale the output image to the full viewport size.
- `viewport_set_scenario(viewport: RID, scenario: RID) -> void` — Sets a viewport's scenario.
- `viewport_set_screen_space_aa(viewport: RID, mode: RenderingServer.ViewportScreenSpaceAA) -> void` — Sets the viewport's screen-space antialiasing mode.
- `viewport_set_sdf_oversize_and_scale(viewport: RID, oversize: RenderingServer.ViewportSDFOversize, scale: RenderingServer.ViewportSDFScale) -> void` — Sets the viewport's 2D signed distance field `ProjectSettings.rendering/2d/sdf/oversize` and `ProjectSettings.rendering/2d/sdf/scale`.
- `viewport_set_size(viewport: RID, width: int, height: int, view_count: int = 1) -> void` — Sets the viewport's `width` and `height` in pixels.
- `viewport_set_snap_2d_transforms_to_pixel(viewport: RID, enabled: bool) -> void` — If `true`, canvas item transforms (i.e. origin position) are snapped to the nearest pixel when rendering.
- `viewport_set_snap_2d_vertices_to_pixel(viewport: RID, enabled: bool) -> void` — If `true`, canvas item vertices (i.e. polygon points) are snapped to the nearest pixel when rendering.
- `viewport_set_texture_mipmap_bias(viewport: RID, mipmap_bias: float) -> void` — Affects the final texture sharpness by reading from a lower or higher mipmap (also called "texture LOD bias").
- `viewport_set_transparent_background(viewport: RID, enabled: bool) -> void` — If `true`, the viewport renders its background as transparent.
- `viewport_set_update_mode(viewport: RID, update_mode: RenderingServer.ViewportUpdateMode) -> void` — Sets when the viewport should be updated.
- `viewport_set_use_debanding(viewport: RID, enable: bool) -> void` — Equivalent to `Viewport.use_debanding`.
- `viewport_set_use_hdr_2d(viewport: RID, enabled: bool) -> void` — If `true`, 2D rendering will use a high dynamic range (HDR) `RGBA16` format framebuffer.
- `viewport_set_use_occlusion_culling(viewport: RID, enable: bool) -> void` — If `true`, enables occlusion culling on the specified viewport.
- `viewport_set_use_taa(viewport: RID, enable: bool) -> void` — If `true`, use temporal antialiasing.
- `viewport_set_use_xr(viewport: RID, use_xr: bool) -> void` — If `true`, the viewport uses augmented or virtual reality technologies.
- `viewport_set_vrs_mode(viewport: RID, mode: RenderingServer.ViewportVRSMode) -> void` — Sets the Variable Rate Shading (VRS) mode for the viewport.
- `viewport_set_vrs_texture(viewport: RID, texture: RID) -> void` — The texture to use when the VRS mode is set to `RenderingServer.VIEWPORT_VRS_TEXTURE`.
- `viewport_set_vrs_update_mode(viewport: RID, mode: RenderingServer.ViewportVRSUpdateMode) -> void` — Sets the update mode for Variable Rate Shading (VRS) for the viewport.
- `visibility_notifier_create() -> RID` — Creates a new 3D visibility notifier object and adds it to the RenderingServer.
- `visibility_notifier_set_aabb(notifier: RID, aabb: AABB) -> void` — Sets the AABB of the specified visibility notifier.
- `visibility_notifier_set_callbacks(notifier: RID, enter_callable: Callable, exit_callable: Callable) -> void` — Sets the methods to be called when the notifier enters or exits the view.
- `voxel_gi_allocate_data(voxel_gi: RID, to_cell_xform: Transform3D, aabb: AABB, octree_size: Vector3i, octree_cells: PackedByteArray, data_cells: PackedByteArray, distance_field: PackedByteArray, level_counts: PackedInt32Array) -> void` — Allocates and initializes the voxel GI data for the specified `voxel_gi` RID.
- `voxel_gi_create() -> RID` — Creates a new voxel-based global illumination object and adds it to the RenderingServer.
- `voxel_gi_get_data_cells(voxel_gi: RID) -> PackedByteArray` *const* — Returns the data cells for the specified voxel GI data instance.
- `voxel_gi_get_distance_field(voxel_gi: RID) -> PackedByteArray` *const* — Returns the distance field data for the specified voxel GI data instance.
- `voxel_gi_get_level_counts(voxel_gi: RID) -> PackedInt32Array` *const* — Returns the level counts for the specified voxel GI data instance.
- `voxel_gi_get_octree_cells(voxel_gi: RID) -> PackedByteArray` *const* — Returns the octree cell data for the specified voxel GI data instance.
- `voxel_gi_get_octree_size(voxel_gi: RID) -> Vector3i` *const* — Returns the octree size for the specified voxel GI data instance, which corresponds to the number of subdivisions per axis.
- `voxel_gi_get_to_cell_xform(voxel_gi: RID) -> Transform3D` *const* — Returns the transform to cell space for the specified voxel GI data instance.
- `voxel_gi_set_baked_exposure_normalization(voxel_gi: RID, baked_exposure: float) -> void` — Used to inform the renderer what exposure normalization value was used while baking the voxel gi.
- `voxel_gi_set_bias(voxel_gi: RID, bias: float) -> void` — Sets the `VoxelGIData.bias` value to use on the specified `voxel_gi`'s RID.
- `voxel_gi_set_dynamic_range(voxel_gi: RID, range: float) -> void` — Sets the `VoxelGIData.dynamic_range` value to use on the specified `voxel_gi`'s RID.
- `voxel_gi_set_energy(voxel_gi: RID, energy: float) -> void` — Sets the `VoxelGIData.energy` value to use on the specified `voxel_gi`'s RID.
- `voxel_gi_set_interior(voxel_gi: RID, enable: bool) -> void` — Sets the `VoxelGIData.interior` value to use on the specified `voxel_gi`'s RID.
- `voxel_gi_set_normal_bias(voxel_gi: RID, bias: float) -> void` — Sets the `VoxelGIData.normal_bias` value to use on the specified `voxel_gi`'s RID.
- `voxel_gi_set_propagation(voxel_gi: RID, amount: float) -> void` — Sets the `VoxelGIData.propagation` value to use on the specified `voxel_gi`'s RID.
- `voxel_gi_set_quality(quality: RenderingServer.VoxelGIQuality) -> void` — Sets the `ProjectSettings.rendering/global_illumination/voxel_gi/quality` value to use when rendering.
- `voxel_gi_set_use_two_bounces(voxel_gi: RID, enable: bool) -> void` — Sets the `VoxelGIData.use_two_bounces` value to use on the specified `voxel_gi`'s RID.

## Signals

- `frame_post_draw()` — Emitted at the end of the frame, after the RenderingServer has finished updating all the Viewports.
- `frame_pre_draw()` — Emitted at the beginning of the frame, before the RenderingServer updates all the Viewports.

## Enum TextureType

- `TEXTURE_TYPE_2D = 0` — 2D texture.
- `TEXTURE_TYPE_LAYERED = 1` — Layered texture.
- `TEXTURE_TYPE_3D = 2` — 3D texture.

## Enum TextureLayeredType

- `TEXTURE_LAYERED_2D_ARRAY = 0` — Array of 2-dimensional textures (see Texture2DArray).
- `TEXTURE_LAYERED_CUBEMAP = 1` — Cubemap texture (see Cubemap).
- `TEXTURE_LAYERED_CUBEMAP_ARRAY = 2` — Array of cubemap textures (see CubemapArray).

## Enum CubeMapLayer

- `CUBEMAP_LAYER_LEFT = 0` — Left face of a Cubemap.
- `CUBEMAP_LAYER_RIGHT = 1` — Right face of a Cubemap.
- `CUBEMAP_LAYER_BOTTOM = 2` — Bottom face of a Cubemap.
- `CUBEMAP_LAYER_TOP = 3` — Top face of a Cubemap.
- `CUBEMAP_LAYER_FRONT = 4` — Front face of a Cubemap.
- `CUBEMAP_LAYER_BACK = 5` — Back face of a Cubemap.

## Enum TextureDrawableFormat

- `TEXTURE_DRAWABLE_FORMAT_RGBA8 = 0` — OpenGL texture format RGBA with four components, each with a bitdepth of 8.
- `TEXTURE_DRAWABLE_FORMAT_RGBA8_SRGB = 1` — OpenGL texture format RGBA with four components, each with a bitdepth of 8.
- `TEXTURE_DRAWABLE_FORMAT_RGBAH = 2` — OpenGL texture format GL_RGBA16F where there are four components, each a 16-bit "half-precision" floating-point value.
- `TEXTURE_DRAWABLE_FORMAT_RGBAF = 3` — OpenGL texture format GL_RGBA32F where there are four components, each a 32-bit floating-point value.

## Enum ShaderMode

- `SHADER_SPATIAL = 0` — Shader is a 3D shader.
- `SHADER_CANVAS_ITEM = 1` — Shader is a 2D shader.
- `SHADER_PARTICLES = 2` — Shader is a particle shader (can be used in both 2D and 3D).
- `SHADER_SKY = 3` — Shader is a 3D sky shader.
- `SHADER_FOG = 4` — Shader is a 3D fog shader.
- `SHADER_TEXTURE_BLIT = 5` — Shader is a texture_blit shader.
- `SHADER_MAX = 6` — Represents the size of the `ShaderMode` enum.

## Enum ArrayType

- `ARRAY_VERTEX = 0` — Array is a vertex position array.
- `ARRAY_NORMAL = 1` — Array is a normal array.
- `ARRAY_TANGENT = 2` — Array is a tangent array.
- `ARRAY_COLOR = 3` — Array is a vertex color array.
- `ARRAY_TEX_UV = 4` — Array is a UV coordinates array.
- `ARRAY_TEX_UV2 = 5` — Array is a UV coordinates array for the second set of UV coordinates.
- `ARRAY_CUSTOM0 = 6` — Array is a custom data array for the first set of custom data.
- `ARRAY_CUSTOM1 = 7` — Array is a custom data array for the second set of custom data.
- `ARRAY_CUSTOM2 = 8` — Array is a custom data array for the third set of custom data.
- `ARRAY_CUSTOM3 = 9` — Array is a custom data array for the fourth set of custom data.
- `ARRAY_BONES = 10` — Array contains bone information.
- `ARRAY_WEIGHTS = 11` — Array is weight information.
- `ARRAY_INDEX = 12` — Array is an index array.
- `ARRAY_MAX = 13` — Represents the size of the `ArrayType` enum.

## Enum ArrayCustomFormat

- `ARRAY_CUSTOM_RGBA8_UNORM = 0` — Custom data array contains 8-bit-per-channel red/green/blue/alpha color data.
- `ARRAY_CUSTOM_RGBA8_SNORM = 1` — Custom data array contains 8-bit-per-channel red/green/blue/alpha color data.
- `ARRAY_CUSTOM_RG_HALF = 2` — Custom data array contains 16-bit-per-channel red/green color data.
- `ARRAY_CUSTOM_RGBA_HALF = 3` — Custom data array contains 16-bit-per-channel red/green/blue/alpha color data.
- `ARRAY_CUSTOM_R_FLOAT = 4` — Custom data array contains 32-bit-per-channel red color data.
- `ARRAY_CUSTOM_RG_FLOAT = 5` — Custom data array contains 32-bit-per-channel red/green color data.
- `ARRAY_CUSTOM_RGB_FLOAT = 6` — Custom data array contains 32-bit-per-channel red/green/blue color data.
- `ARRAY_CUSTOM_RGBA_FLOAT = 7` — Custom data array contains 32-bit-per-channel red/green/blue/alpha color data.
- `ARRAY_CUSTOM_MAX = 8` — Represents the size of the `ArrayCustomFormat` enum.

## Enum ArrayFormat

- `ARRAY_FORMAT_VERTEX = 1` — Flag used to mark a vertex position array.
- `ARRAY_FORMAT_NORMAL = 2` — Flag used to mark a normal array.
- `ARRAY_FORMAT_TANGENT = 4` — Flag used to mark a tangent array.
- `ARRAY_FORMAT_COLOR = 8` — Flag used to mark a vertex color array.
- `ARRAY_FORMAT_TEX_UV = 16` — Flag used to mark a UV coordinates array.
- `ARRAY_FORMAT_TEX_UV2 = 32` — Flag used to mark a UV coordinates array for the second UV coordinates.
- `ARRAY_FORMAT_CUSTOM0 = 64` — Flag used to mark an array of custom per-vertex data for the first set of custom data.
- `ARRAY_FORMAT_CUSTOM1 = 128` — Flag used to mark an array of custom per-vertex data for the second set of custom data.
- `ARRAY_FORMAT_CUSTOM2 = 256` — Flag used to mark an array of custom per-vertex data for the third set of custom data.
- `ARRAY_FORMAT_CUSTOM3 = 512` — Flag used to mark an array of custom per-vertex data for the fourth set of custom data.
- `ARRAY_FORMAT_BONES = 1024` — Flag used to mark a bone information array.
- `ARRAY_FORMAT_WEIGHTS = 2048` — Flag used to mark a weights array.
- `ARRAY_FORMAT_INDEX = 4096` — Flag used to mark an index array.
- `ARRAY_FORMAT_BLEND_SHAPE_MASK = 7` — Mask of mesh channels permitted in blend shapes.
- `ARRAY_FORMAT_CUSTOM_BASE = 13` — Shift of first custom channel.
- `ARRAY_FORMAT_CUSTOM_BITS = 3` — Number of format bits per custom channel.
- `ARRAY_FORMAT_CUSTOM0_SHIFT = 13` — Amount to shift `ArrayCustomFormat` for custom channel index 0.
- `ARRAY_FORMAT_CUSTOM1_SHIFT = 16` — Amount to shift `ArrayCustomFormat` for custom channel index 1.
- `ARRAY_FORMAT_CUSTOM2_SHIFT = 19` — Amount to shift `ArrayCustomFormat` for custom channel index 2.
- `ARRAY_FORMAT_CUSTOM3_SHIFT = 22` — Amount to shift `ArrayCustomFormat` for custom channel index 3.
- `ARRAY_FORMAT_CUSTOM_MASK = 7` — Mask of custom format bits per custom channel.
- `ARRAY_COMPRESS_FLAGS_BASE = 25` — Shift of first compress flag.
- `ARRAY_FLAG_USE_2D_VERTICES = 33554432` — Flag used to mark that the array contains 2D vertices.
- `ARRAY_FLAG_USE_DYNAMIC_UPDATE = 67108864` — Flag used to mark that the mesh data will use `GL_DYNAMIC_DRAW` on GLES.
- `ARRAY_FLAG_USE_8_BONE_WEIGHTS = 134217728` — Flag used to mark that the array uses 8 bone weights instead of 4.
- `ARRAY_FLAG_USES_EMPTY_VERTEX_ARRAY = 268435456` — Flag used to mark that the mesh does not have a vertex array and instead will infer vertex positions in the shader using indices and other information.
- `ARRAY_FLAG_COMPRESS_ATTRIBUTES = 536870912` — Flag used to mark that a mesh is using compressed attributes (vertices, normals, tangents, UVs).
- `ARRAY_FLAG_USE_STORAGE_BUFFER = 1073741824` — Flag used to mark that the surface's vertex, attribute, skin, and index buffers must be created with the storage-buffer usage bit so they can be bound as storage buffers in compute shaders.
- `ARRAY_FLAG_FORMAT_VERSION_BASE = 35` — Flag used to mark the start of the bits used to store the mesh version.
- `ARRAY_FLAG_FORMAT_VERSION_SHIFT = 35` — Flag used to shift a mesh format int to bring the version into the lowest digits.
- `ARRAY_FLAG_FORMAT_VERSION_1 = 0` — Flag used to record the format used by prior mesh versions before the introduction of a version.
- `ARRAY_FLAG_FORMAT_VERSION_2 = 34359738368` — Flag used to record the second iteration of the mesh version flag.
- `ARRAY_FLAG_FORMAT_CURRENT_VERSION = 34359738368` — Flag used to record the current version that the engine expects.
- `ARRAY_FLAG_FORMAT_VERSION_MASK = 255` — Flag used to isolate the bits used for mesh version after using `ARRAY_FLAG_FORMAT_VERSION_SHIFT` to shift them into place.

## Enum PrimitiveType

- `PRIMITIVE_POINTS = 0` — Primitive to draw consists of points.
- `PRIMITIVE_LINES = 1` — Primitive to draw consists of lines.
- `PRIMITIVE_LINE_STRIP = 2` — Primitive to draw consists of a line strip from start to end.
- `PRIMITIVE_TRIANGLES = 3` — Primitive to draw consists of triangles.
- `PRIMITIVE_TRIANGLE_STRIP = 4` — Primitive to draw consists of a triangle strip (the last 3 vertices are always combined to make a triangle).
- `PRIMITIVE_MAX = 5` — Represents the size of the `PrimitiveType` enum.

## Enum BlendShapeMode

- `BLEND_SHAPE_MODE_NORMALIZED = 0` — Blend shapes are normalized.
- `BLEND_SHAPE_MODE_RELATIVE = 1` — Blend shapes are relative to base weight.

## Enum MultimeshTransformFormat

- `MULTIMESH_TRANSFORM_2D = 0` — Use Transform2D to store MultiMesh transform.
- `MULTIMESH_TRANSFORM_3D = 1` — Use Transform3D to store MultiMesh transform.

## Enum MultimeshPhysicsInterpolationQuality

- `MULTIMESH_INTERP_QUALITY_FAST = 0` — MultiMesh physics interpolation favors speed over quality.
- `MULTIMESH_INTERP_QUALITY_HIGH = 1` — MultiMesh physics interpolation favors quality over speed.

## Enum LightProjectorFilter

- `LIGHT_PROJECTOR_FILTER_NEAREST = 0` — Nearest-neighbor filter for light projectors (use for pixel art light projectors).
- `LIGHT_PROJECTOR_FILTER_LINEAR = 1` — Linear filter for light projectors (use for non-pixel art light projectors).
- `LIGHT_PROJECTOR_FILTER_NEAREST_MIPMAPS = 2` — Nearest-neighbor filter for light projectors (use for pixel art light projectors).
- `LIGHT_PROJECTOR_FILTER_LINEAR_MIPMAPS = 3` — Linear filter for light projectors (use for non-pixel art light projectors).
- `LIGHT_PROJECTOR_FILTER_NEAREST_MIPMAPS_ANISOTROPIC = 4` — Nearest-neighbor filter for light projectors (use for pixel art light projectors).
- `LIGHT_PROJECTOR_FILTER_LINEAR_MIPMAPS_ANISOTROPIC = 5` — Linear filter for light projectors (use for non-pixel art light projectors).

## Enum LightType

- `LIGHT_DIRECTIONAL = 0` — Directional (sun/moon) light (see DirectionalLight3D).
- `LIGHT_OMNI = 1` — Omni light (see OmniLight3D).
- `LIGHT_SPOT = 2` — Spot light (see SpotLight3D).
- `LIGHT_AREA = 3` — Area light (see AreaLight3D).

## Enum LightParam

- `LIGHT_PARAM_ENERGY = 0` — The light's energy multiplier.
- `LIGHT_PARAM_INDIRECT_ENERGY = 1` — The light's indirect energy multiplier (final indirect energy is `LIGHT_PARAM_ENERGY` * `LIGHT_PARAM_INDIRECT_ENERGY`).
- `LIGHT_PARAM_VOLUMETRIC_FOG_ENERGY = 2` — The light's volumetric fog energy multiplier (final volumetric fog energy is `LIGHT_PARAM_ENERGY` * `LIGHT_PARAM_VOLUMETRIC_FOG_ENERGY`).
- `LIGHT_PARAM_SPECULAR = 3` — The light's influence on specularity.
- `LIGHT_PARAM_RANGE = 4` — The light's range.
- `LIGHT_PARAM_SIZE = 5` — The size of the light when using spot light or omni light.
- `LIGHT_PARAM_ATTENUATION = 6` — The light's attenuation.
- `LIGHT_PARAM_SPOT_ANGLE = 7` — The spotlight's angle.
- `LIGHT_PARAM_SPOT_ATTENUATION = 8` — The spotlight's attenuation.
- `LIGHT_PARAM_SHADOW_MAX_DISTANCE = 9` — The maximum distance for shadow splits.
- `LIGHT_PARAM_SHADOW_SPLIT_1_OFFSET = 10` — Proportion of shadow atlas occupied by the first split.
- `LIGHT_PARAM_SHADOW_SPLIT_2_OFFSET = 11` — Proportion of shadow atlas occupied by the second split.
- `LIGHT_PARAM_SHADOW_SPLIT_3_OFFSET = 12` — Proportion of shadow atlas occupied by the third split.
- `LIGHT_PARAM_SHADOW_FADE_START = 13` — Proportion of shadow max distance where the shadow will start to fade out.
- `LIGHT_PARAM_SHADOW_NORMAL_BIAS = 14` — Normal bias used to offset shadow lookup by object normal.
- `LIGHT_PARAM_SHADOW_BIAS = 15` — Bias for the shadow lookup to fix self-shadowing artifacts.
- `LIGHT_PARAM_SHADOW_PANCAKE_SIZE = 16` — Sets the size of the directional shadow pancake.
- `LIGHT_PARAM_SHADOW_OPACITY = 17` — The light's shadow opacity.
- `LIGHT_PARAM_SHADOW_BLUR = 18` — Blurs the edges of the shadow.
- `LIGHT_PARAM_TRANSMITTANCE_BIAS = 19` — 
- `LIGHT_PARAM_INTENSITY = 20` — Constant representing the intensity of the light, measured in Lumens when dealing with a SpotLight3D or OmniLight3D, or measured in Lux with a DirectionalLight3D.
- `LIGHT_PARAM_CONTACT_SHADOW_OPACITY = 21` — Changes the opacity of the lights screen-space contact shadows.
- `LIGHT_PARAM_CONTACT_SHADOW_BLUR = 22` — Blurs the edges of the contact shadow.
- `LIGHT_PARAM_MAX = 23` — Represents the size of the `LightParam` enum.

## Enum LightBakeMode

- `LIGHT_BAKE_DISABLED = 0` — Light is ignored when baking.
- `LIGHT_BAKE_STATIC = 1` — Light is taken into account in static baking (VoxelGI, LightmapGI, SDFGI (`Environment.sdfgi_enabled`)).
- `LIGHT_BAKE_DYNAMIC = 2` — Light is taken into account in dynamic baking (VoxelGI and SDFGI (`Environment.sdfgi_enabled`) only).

## Enum LightOmniShadowMode

- `LIGHT_OMNI_SHADOW_DUAL_PARABOLOID = 0` — Use a dual paraboloid shadow map for omni lights.
- `LIGHT_OMNI_SHADOW_CUBE = 1` — Use a cubemap shadow map for omni lights.

## Enum LightDirectionalShadowMode

- `LIGHT_DIRECTIONAL_SHADOW_ORTHOGONAL = 0` — Use orthogonal shadow projection for directional light.
- `LIGHT_DIRECTIONAL_SHADOW_PARALLEL_2_SPLITS = 1` — Use 2 splits for shadow projection when using directional light.
- `LIGHT_DIRECTIONAL_SHADOW_PARALLEL_4_SPLITS = 2` — Use 4 splits for shadow projection when using directional light.

## Enum LightDirectionalSkyMode

- `LIGHT_DIRECTIONAL_SKY_MODE_LIGHT_AND_SKY = 0` — Use DirectionalLight3D in both sky rendering and scene lighting.
- `LIGHT_DIRECTIONAL_SKY_MODE_LIGHT_ONLY = 1` — Only use DirectionalLight3D in scene lighting.
- `LIGHT_DIRECTIONAL_SKY_MODE_SKY_ONLY = 2` — Only use DirectionalLight3D in sky rendering.

## Enum ShadowQuality

- `SHADOW_QUALITY_HARD = 0` — Lowest shadow filtering quality (fastest).
- `SHADOW_QUALITY_SOFT_VERY_LOW = 1` — Very low shadow filtering quality (faster).
- `SHADOW_QUALITY_SOFT_LOW = 2` — Low shadow filtering quality (fast).
- `SHADOW_QUALITY_SOFT_MEDIUM = 3` — Medium low shadow filtering quality (average).
- `SHADOW_QUALITY_SOFT_HIGH = 4` — High low shadow filtering quality (slow).
- `SHADOW_QUALITY_SOFT_ULTRA = 5` — Highest low shadow filtering quality (slowest).
- `SHADOW_QUALITY_MAX = 6` — Represents the size of the `ShadowQuality` enum.

## Enum ReflectionProbeUpdateMode

- `REFLECTION_PROBE_UPDATE_ONCE = 0` — Reflection probe will update reflections once and then stop.
- `REFLECTION_PROBE_UPDATE_ALWAYS = 1` — Reflection probe will update each frame.

## Enum ReflectionProbeAmbientMode

- `REFLECTION_PROBE_AMBIENT_DISABLED = 0` — Do not apply any ambient lighting inside the reflection probe's box defined by its size.
- `REFLECTION_PROBE_AMBIENT_ENVIRONMENT = 1` — Apply automatically-sourced environment lighting inside the reflection probe's box defined by its size.
- `REFLECTION_PROBE_AMBIENT_COLOR = 2` — Apply custom ambient lighting inside the reflection probe's box defined by its size.

## Enum DecalTexture

- `DECAL_TEXTURE_ALBEDO = 0` — Albedo texture slot in a decal (`Decal.texture_albedo`).
- `DECAL_TEXTURE_NORMAL = 1` — Normal map texture slot in a decal (`Decal.texture_normal`).
- `DECAL_TEXTURE_ORM = 2` — Occlusion/Roughness/Metallic texture slot in a decal (`Decal.texture_orm`).
- `DECAL_TEXTURE_EMISSION = 3` — Emission texture slot in a decal (`Decal.texture_emission`).
- `DECAL_TEXTURE_MAX = 4` — Represents the size of the `DecalTexture` enum.

## Enum DecalFilter

- `DECAL_FILTER_NEAREST = 0` — Nearest-neighbor filter for decals (use for pixel art decals).
- `DECAL_FILTER_LINEAR = 1` — Linear filter for decals (use for non-pixel art decals).
- `DECAL_FILTER_NEAREST_MIPMAPS = 2` — Nearest-neighbor filter for decals (use for pixel art decals).
- `DECAL_FILTER_LINEAR_MIPMAPS = 3` — Linear filter for decals (use for non-pixel art decals).
- `DECAL_FILTER_NEAREST_MIPMAPS_ANISOTROPIC = 4` — Nearest-neighbor filter for decals (use for pixel art decals).
- `DECAL_FILTER_LINEAR_MIPMAPS_ANISOTROPIC = 5` — Linear filter for decals (use for non-pixel art decals).

## Enum VoxelGIQuality

- `VOXEL_GI_QUALITY_LOW = 0` — Low VoxelGI rendering quality using 4 cones.
- `VOXEL_GI_QUALITY_HIGH = 1` — High VoxelGI rendering quality using 6 cones.

## Enum ParticlesMode

- `PARTICLES_MODE_2D = 0` — 2D particles.
- `PARTICLES_MODE_3D = 1` — 3D particles.

## Enum ParticlesTransformAlign

- `PARTICLES_TRANSFORM_ALIGN_DISABLED = 0` — Do not align particle transforms relative to the camera or velocity.
- `PARTICLES_TRANSFORM_ALIGN_Z_BILLBOARD = 1` — Align each particle's Z axis to face the camera.
- `PARTICLES_TRANSFORM_ALIGN_Y_TO_VELOCITY = 2` — Align each particle's Y axis to the velocity vector.
- `PARTICLES_TRANSFORM_ALIGN_Z_BILLBOARD_Y_TO_VELOCITY = 3` — Align each particle's Z axis to face the camera and Y axis to the velocity vector.
- `PARTICLES_TRANSFORM_ALIGN_LOCAL_BILLBOARD = 4` — Billboard each particles around a local axis.

## Enum ParticlesTransformAlignCustomSrc

- `PARTICLES_ALIGN_CHANNEL_FILTER_DISABLED = 0` — Do not read from CUSTOM when performing billboarding.
- `PARTICLES_ALIGN_CHANNEL_FILTER_X = 1` — Read from `CUSTOM.x` when performing billboarding and use it as an angle, in radians.
- `PARTICLES_ALIGN_CHANNEL_FILTER_Y = 2` — Read from `CUSTOM.y` when performing billboarding and use it as an angle, in radians.
- `PARTICLES_ALIGN_CHANNEL_FILTER_Z = 3` — Read from `CUSTOM.z` when performing billboarding and use it as an angle, in radians.
- `PARTICLES_ALIGN_CHANNEL_FILTER_W = 4` — Read from `CUSTOM.w` when performing billboarding and use it as an angle, in radians.

## Enum ParticlesTransformAlignAxis

- `PARTICLES_ALIGN_AXIS_X = 0` — Use the X axis for local billboarding.
- `PARTICLES_ALIGN_AXIS_Y = 1` — Use the Y axis for local billboarding.

## Enum ParticlesDrawOrder

- `PARTICLES_DRAW_ORDER_INDEX = 0` — Draw particles in the order that they appear in the particles array.
- `PARTICLES_DRAW_ORDER_LIFETIME = 1` — Sort particles based on their lifetime.
- `PARTICLES_DRAW_ORDER_REVERSE_LIFETIME = 2` — Sort particles based on the inverse of their lifetime.
- `PARTICLES_DRAW_ORDER_VIEW_DEPTH = 3` — Sort particles based on their distance to the camera.

## Enum ParticlesCollisionType

- `PARTICLES_COLLISION_TYPE_SPHERE_ATTRACT = 0` — Sphere attractor type for GPUParticles3D (see GPUParticlesAttractorSphere3D).
- `PARTICLES_COLLISION_TYPE_BOX_ATTRACT = 1` — Box attractor type for GPUParticles3D (see GPUParticlesAttractorBox3D).
- `PARTICLES_COLLISION_TYPE_VECTOR_FIELD_ATTRACT = 2` — Vector field attractor type for GPUParticles3D (see GPUParticlesAttractorVectorField3D).
- `PARTICLES_COLLISION_TYPE_SPHERE_COLLIDE = 3` — Sphere collision type for GPUParticles3D (see GPUParticlesCollisionSphere3D).
- `PARTICLES_COLLISION_TYPE_BOX_COLLIDE = 4` — Box collision type for GPUParticles3D (see GPUParticlesCollisionBox3D).
- `PARTICLES_COLLISION_TYPE_SDF_COLLIDE = 5` — Signed distance field collision type for GPUParticles3D (see GPUParticlesCollisionSDF3D).
- `PARTICLES_COLLISION_TYPE_HEIGHTFIELD_COLLIDE = 6` — Heightfield collision type for GPUParticles3D (see GPUParticlesCollisionHeightField3D).

## Enum ParticlesCollisionHeightfieldResolution

- `PARTICLES_COLLISION_HEIGHTFIELD_RESOLUTION_256 = 0` — 256×256 heightfield resolution for GPUParticlesCollisionHeightField3D.
- `PARTICLES_COLLISION_HEIGHTFIELD_RESOLUTION_512 = 1` — 512×512 heightfield resolution for GPUParticlesCollisionHeightField3D.
- `PARTICLES_COLLISION_HEIGHTFIELD_RESOLUTION_1024 = 2` — 1024×1024 heightfield resolution for GPUParticlesCollisionHeightField3D.
- `PARTICLES_COLLISION_HEIGHTFIELD_RESOLUTION_2048 = 3` — 2048×2048 heightfield resolution for GPUParticlesCollisionHeightField3D.
- `PARTICLES_COLLISION_HEIGHTFIELD_RESOLUTION_4096 = 4` — 4096×4096 heightfield resolution for GPUParticlesCollisionHeightField3D.
- `PARTICLES_COLLISION_HEIGHTFIELD_RESOLUTION_8192 = 5` — 8192×8192 heightfield resolution for GPUParticlesCollisionHeightField3D.
- `PARTICLES_COLLISION_HEIGHTFIELD_RESOLUTION_MAX = 6` — Represents the size of the `ParticlesCollisionHeightfieldResolution` enum.

## Enum FogVolumeShape

- `FOG_VOLUME_SHAPE_ELLIPSOID = 0` — FogVolume will be shaped like an ellipsoid (stretched sphere).
- `FOG_VOLUME_SHAPE_CONE = 1` — FogVolume will be shaped like a cone pointing upwards (in local coordinates).
- `FOG_VOLUME_SHAPE_CYLINDER = 2` — FogVolume will be shaped like an upright cylinder (in local coordinates).
- `FOG_VOLUME_SHAPE_BOX = 3` — FogVolume will be shaped like a box.
- `FOG_VOLUME_SHAPE_WORLD = 4` — FogVolume will have no shape, will cover the whole world and will not be culled.
- `FOG_VOLUME_SHAPE_MAX = 5` — Represents the size of the `FogVolumeShape` enum.

## Enum ViewportScaling3DMode

- `VIEWPORT_SCALING_3D_MODE_BILINEAR = 0` — Use bilinear scaling for the viewport's 3D buffer.
- `VIEWPORT_SCALING_3D_MODE_FSR = 1` — Use AMD FidelityFX Super Resolution 1.0 upscaling for the viewport's 3D buffer.
- `VIEWPORT_SCALING_3D_MODE_FSR2 = 2` — Use AMD FidelityFX Super Resolution 2.2 upscaling for the viewport's 3D buffer.
- `VIEWPORT_SCALING_3D_MODE_METALFX_SPATIAL = 3` — Use MetalFX spatial upscaling for the viewport's 3D buffer.
- `VIEWPORT_SCALING_3D_MODE_METALFX_TEMPORAL = 4` — Use MetalFX temporal upscaling for the viewport's 3D buffer.
- `VIEWPORT_SCALING_3D_MODE_NEAREST = 5` — Use nearest-neighbor filtering for the viewport's 3D buffer.
- `VIEWPORT_SCALING_3D_MODE_MAX = 6` — Represents the size of the `ViewportScaling3DMode` enum.

## Enum ViewportUpdateMode

- `VIEWPORT_UPDATE_DISABLED = 0` — Do not update the viewport's render target.
- `VIEWPORT_UPDATE_ONCE = 1` — Update the viewport's render target once, then switch to `VIEWPORT_UPDATE_DISABLED`.
- `VIEWPORT_UPDATE_WHEN_VISIBLE = 2` — Update the viewport's render target only when it is visible.
- `VIEWPORT_UPDATE_WHEN_PARENT_VISIBLE = 3` — Update the viewport's render target only when its parent is visible.
- `VIEWPORT_UPDATE_ALWAYS = 4` — Always update the viewport's render target.

## Enum ViewportClearMode

- `VIEWPORT_CLEAR_ALWAYS = 0` — Always clear the viewport's render target before drawing.
- `VIEWPORT_CLEAR_NEVER = 1` — Never clear the viewport's render target.
- `VIEWPORT_CLEAR_ONLY_NEXT_FRAME = 2` — Clear the viewport's render target on the next frame, then switch to `VIEWPORT_CLEAR_NEVER`.

## Enum ViewportEnvironmentMode

- `VIEWPORT_ENVIRONMENT_DISABLED = 0` — Disable rendering of 3D environment over 2D canvas.
- `VIEWPORT_ENVIRONMENT_ENABLED = 1` — Enable rendering of 3D environment over 2D canvas.
- `VIEWPORT_ENVIRONMENT_INHERIT = 2` — Inherit enable/disable value from parent.
- `VIEWPORT_ENVIRONMENT_MAX = 3` — Represents the size of the `ViewportEnvironmentMode` enum.

## Enum ViewportSDFOversize

- `VIEWPORT_SDF_OVERSIZE_100_PERCENT = 0` — Do not oversize the 2D signed distance field.
- `VIEWPORT_SDF_OVERSIZE_120_PERCENT = 1` — 2D signed distance field covers 20% of the viewport's size outside the viewport on each side (top, right, bottom, left).
- `VIEWPORT_SDF_OVERSIZE_150_PERCENT = 2` — 2D signed distance field covers 50% of the viewport's size outside the viewport on each side (top, right, bottom, left).
- `VIEWPORT_SDF_OVERSIZE_200_PERCENT = 3` — 2D signed distance field covers 100% of the viewport's size outside the viewport on each side (top, right, bottom, left).
- `VIEWPORT_SDF_OVERSIZE_MAX = 4` — Represents the size of the `ViewportSDFOversize` enum.

## Enum ViewportSDFScale

- `VIEWPORT_SDF_SCALE_100_PERCENT = 0` — Full resolution 2D signed distance field scale.
- `VIEWPORT_SDF_SCALE_50_PERCENT = 1` — Half resolution 2D signed distance field scale on each axis (25% of the viewport pixel count).
- `VIEWPORT_SDF_SCALE_25_PERCENT = 2` — Quarter resolution 2D signed distance field scale on each axis (6.25% of the viewport pixel count).
- `VIEWPORT_SDF_SCALE_MAX = 3` — Represents the size of the `ViewportSDFScale` enum.

## Enum ViewportMSAA

- `VIEWPORT_MSAA_DISABLED = 0` — Multisample antialiasing for 3D is disabled.
- `VIEWPORT_MSAA_2X = 1` — Multisample antialiasing uses 2 samples per pixel for 3D.
- `VIEWPORT_MSAA_4X = 2` — Multisample antialiasing uses 4 samples per pixel for 3D.
- `VIEWPORT_MSAA_8X = 3` — Multisample antialiasing uses 8 samples per pixel for 3D.
- `VIEWPORT_MSAA_MAX = 4` — Represents the size of the `ViewportMSAA` enum.

## Enum ViewportAnisotropicFiltering

- `VIEWPORT_ANISOTROPY_DISABLED = 0` — Anisotropic filtering is disabled.
- `VIEWPORT_ANISOTROPY_2X = 1` — Use 2× anisotropic filtering.
- `VIEWPORT_ANISOTROPY_4X = 2` — Use 4× anisotropic filtering.
- `VIEWPORT_ANISOTROPY_8X = 3` — Use 8× anisotropic filtering.
- `VIEWPORT_ANISOTROPY_16X = 4` — Use 16× anisotropic filtering.
- `VIEWPORT_ANISOTROPY_MAX = 5` — Represents the size of the `ViewportAnisotropicFiltering` enum.

## Enum ViewportScreenSpaceAA

- `VIEWPORT_SCREEN_SPACE_AA_DISABLED = 0` — Do not perform any antialiasing in the full screen post-process.
- `VIEWPORT_SCREEN_SPACE_AA_FXAA = 1` — Use fast approximate antialiasing.
- `VIEWPORT_SCREEN_SPACE_AA_SMAA = 2` — Use subpixel morphological antialiasing.
- `VIEWPORT_SCREEN_SPACE_AA_MAX = 3` — Represents the size of the `ViewportScreenSpaceAA` enum.

## Enum ViewportOcclusionCullingBuildQuality

- `VIEWPORT_OCCLUSION_BUILD_QUALITY_LOW = 0` — Low occlusion culling BVH build quality (as defined by Embree).
- `VIEWPORT_OCCLUSION_BUILD_QUALITY_MEDIUM = 1` — Medium occlusion culling BVH build quality (as defined by Embree).
- `VIEWPORT_OCCLUSION_BUILD_QUALITY_HIGH = 2` — High occlusion culling BVH build quality (as defined by Embree).

## Enum ViewportRenderInfo

- `VIEWPORT_RENDER_INFO_OBJECTS_IN_FRAME = 0` — Number of objects drawn in a single frame.
- `VIEWPORT_RENDER_INFO_PRIMITIVES_IN_FRAME = 1` — Number of points, lines, or triangles drawn in a single frame.
- `VIEWPORT_RENDER_INFO_DRAW_CALLS_IN_FRAME = 2` — Number of draw calls during this frame.
- `VIEWPORT_RENDER_INFO_MAX = 3` — Represents the size of the `ViewportRenderInfo` enum.

## Enum ViewportRenderInfoType

- `VIEWPORT_RENDER_INFO_TYPE_VISIBLE = 0` — Visible render pass (excluding shadows).
- `VIEWPORT_RENDER_INFO_TYPE_SHADOW = 1` — Shadow render pass.
- `VIEWPORT_RENDER_INFO_TYPE_CANVAS = 2` — Canvas item rendering.
- `VIEWPORT_RENDER_INFO_TYPE_MAX = 3` — Represents the size of the `ViewportRenderInfoType` enum.

## Enum ViewportDebugDraw

- `VIEWPORT_DEBUG_DRAW_DISABLED = 0` — Debug draw is disabled.
- `VIEWPORT_DEBUG_DRAW_UNSHADED = 1` — Objects are displayed without light information.
- `VIEWPORT_DEBUG_DRAW_LIGHTING = 2` — Objects are displayed with only light information.
- `VIEWPORT_DEBUG_DRAW_OVERDRAW = 3` — Objects are displayed semi-transparent with additive blending so you can see where they are drawing over top of one another.
- `VIEWPORT_DEBUG_DRAW_WIREFRAME = 4` — Debug draw draws objects in wireframe.
- `VIEWPORT_DEBUG_DRAW_NORMAL_BUFFER = 5` — Normal buffer is drawn instead of regular scene so you can see the per-pixel normals that will be used by post-processing effects.
- `VIEWPORT_DEBUG_DRAW_VOXEL_GI_ALBEDO = 6` — Objects are displayed with only the albedo value from VoxelGIs.
- `VIEWPORT_DEBUG_DRAW_VOXEL_GI_LIGHTING = 7` — Objects are displayed with only the lighting value from VoxelGIs.
- `VIEWPORT_DEBUG_DRAW_VOXEL_GI_EMISSION = 8` — Objects are displayed with only the emission color from VoxelGIs.
- `VIEWPORT_DEBUG_DRAW_SHADOW_ATLAS = 9` — Draws the shadow atlas that stores shadows from OmniLight3Ds and SpotLight3Ds in the upper left quadrant of the Viewport.
- `VIEWPORT_DEBUG_DRAW_DIRECTIONAL_SHADOW_ATLAS = 10` — Draws the shadow atlas that stores shadows from DirectionalLight3Ds in the upper left quadrant of the Viewport.
- `VIEWPORT_DEBUG_DRAW_SCENE_LUMINANCE = 11` — Draws the estimated scene luminance.
- `VIEWPORT_DEBUG_DRAW_SSAO = 12` — Draws the screen space ambient occlusion texture instead of the scene so that you can clearly see how it is affecting objects.
- `VIEWPORT_DEBUG_DRAW_SSIL = 13` — Draws the screen space indirect lighting texture instead of the scene so that you can clearly see how it is affecting objects.
- `VIEWPORT_DEBUG_DRAW_PSSM_SPLITS = 14` — Colors each PSSM split for the DirectionalLight3Ds in the scene a different color so you can see where the splits are.
- `VIEWPORT_DEBUG_DRAW_DECAL_ATLAS = 15` — Draws the decal atlas that stores decal textures from Decals.
- `VIEWPORT_DEBUG_DRAW_SDFGI = 16` — Draws SDFGI cascade data.
- `VIEWPORT_DEBUG_DRAW_SDFGI_PROBES = 17` — Draws SDFGI probe data.
- `VIEWPORT_DEBUG_DRAW_GI_BUFFER = 18` — Draws the global illumination buffer from VoxelGI or SDFGI.
- `VIEWPORT_DEBUG_DRAW_DISABLE_LOD = 19` — Disable mesh LOD.
- `VIEWPORT_DEBUG_DRAW_CLUSTER_OMNI_LIGHTS = 20` — Draws the OmniLight3D cluster.
- `VIEWPORT_DEBUG_DRAW_CLUSTER_SPOT_LIGHTS = 21` — Draws the SpotLight3D cluster.
- `VIEWPORT_DEBUG_DRAW_CLUSTER_DECALS = 22` — Draws the Decal cluster.
- `VIEWPORT_DEBUG_DRAW_CLUSTER_REFLECTION_PROBES = 23` — Draws the ReflectionProbe cluster.
- `VIEWPORT_DEBUG_DRAW_OCCLUDERS = 24` — Draws the occlusion culling buffer.
- `VIEWPORT_DEBUG_DRAW_MOTION_VECTORS = 25` — Draws the motion vectors buffer.
- `VIEWPORT_DEBUG_DRAW_INTERNAL_BUFFER = 26` — Internal buffer is drawn instead of regular scene so you can see the per-pixel output that will be used by post-processing effects.

## Enum ViewportVRSMode

- `VIEWPORT_VRS_DISABLED = 0` — Variable rate shading is disabled.
- `VIEWPORT_VRS_TEXTURE = 1` — Variable rate shading uses a texture.
- `VIEWPORT_VRS_XR = 2` — Variable rate shading texture is supplied by the primary XRInterface.
- `VIEWPORT_VRS_MAX = 3` — Represents the size of the `ViewportVRSMode` enum.

## Enum ViewportVRSUpdateMode

- `VIEWPORT_VRS_UPDATE_DISABLED = 0` — The input texture for variable rate shading will not be processed.
- `VIEWPORT_VRS_UPDATE_ONCE = 1` — The input texture for variable rate shading will be processed once.
- `VIEWPORT_VRS_UPDATE_ALWAYS = 2` — The input texture for variable rate shading will be processed each frame.
- `VIEWPORT_VRS_UPDATE_MAX = 3` — Represents the size of the `ViewportVRSUpdateMode` enum.

## Enum SkyMode

- `SKY_MODE_AUTOMATIC = 0` — Automatically selects the appropriate process mode based on your sky shader.
- `SKY_MODE_QUALITY = 1` — Uses high quality importance sampling to process the radiance map.
- `SKY_MODE_INCREMENTAL = 2` — Uses the same high quality importance sampling to process the radiance map as `SKY_MODE_QUALITY`, but updates over several frames.
- `SKY_MODE_REALTIME = 3` — Uses the fast filtering algorithm to process the radiance map.

## Enum CompositorEffectFlags

- `COMPOSITOR_EFFECT_FLAG_ACCESS_RESOLVED_COLOR = 1` — The rendering effect requires the color buffer to be resolved if MSAA is enabled.
- `COMPOSITOR_EFFECT_FLAG_ACCESS_RESOLVED_DEPTH = 2` — The rendering effect requires the depth buffer to be resolved if MSAA is enabled.
- `COMPOSITOR_EFFECT_FLAG_NEEDS_MOTION_VECTORS = 4` — The rendering effect requires motion vectors to be produced.
- `COMPOSITOR_EFFECT_FLAG_NEEDS_ROUGHNESS = 8` — The rendering effect requires normals and roughness g-buffer to be produced (Forward+ only).
- `COMPOSITOR_EFFECT_FLAG_NEEDS_SEPARATE_SPECULAR = 16` — The rendering effect requires specular data to be separated out (Forward+ only).

## Enum CompositorEffectCallbackType

- `COMPOSITOR_EFFECT_CALLBACK_TYPE_PRE_OPAQUE = 0` — The callback is called before our opaque rendering pass, but after depth prepass (if applicable).
- `COMPOSITOR_EFFECT_CALLBACK_TYPE_POST_OPAQUE = 1` — The callback is called after our opaque rendering pass, but before our sky is rendered.
- `COMPOSITOR_EFFECT_CALLBACK_TYPE_POST_SKY = 2` — The callback is called after our sky is rendered, but before our back buffers are created (and if enabled, before subsurface scattering and/or screen space reflections).
- `COMPOSITOR_EFFECT_CALLBACK_TYPE_PRE_TRANSPARENT = 3` — The callback is called before our transparent rendering pass, but after our sky is rendered and we've created our back buffers.
- `COMPOSITOR_EFFECT_CALLBACK_TYPE_POST_TRANSPARENT = 4` — The callback is called after our transparent rendering pass, but before any built-in post-processing effects and output to our render target.
- `COMPOSITOR_EFFECT_CALLBACK_TYPE_ANY = -1` — 

## Enum EnvironmentBG

- `ENV_BG_CLEAR_COLOR = 0` — Use the clear color as background.
- `ENV_BG_COLOR = 1` — Use a specified color as the background.
- `ENV_BG_SKY = 2` — Use a sky resource for the background.
- `ENV_BG_CANVAS = 3` — Use a specified canvas layer as the background.
- `ENV_BG_KEEP = 4` — Do not clear the background, use whatever was rendered last frame as the background.
- `ENV_BG_CAMERA_FEED = 5` — Displays a camera feed in the background.
- `ENV_BG_MAX = 6` — Represents the size of the `EnvironmentBG` enum.

## Enum EnvironmentAmbientSource

- `ENV_AMBIENT_SOURCE_BG = 0` — Gather ambient light from whichever source is specified as the background.
- `ENV_AMBIENT_SOURCE_DISABLED = 1` — Disable ambient light.
- `ENV_AMBIENT_SOURCE_COLOR = 2` — Specify a specific Color for ambient light.
- `ENV_AMBIENT_SOURCE_SKY = 3` — Gather ambient light from the Sky regardless of what the background is.

## Enum EnvironmentReflectionSource

- `ENV_REFLECTION_SOURCE_BG = 0` — Use the background for reflections.
- `ENV_REFLECTION_SOURCE_DISABLED = 1` — Disable reflections.
- `ENV_REFLECTION_SOURCE_SKY = 2` — Use the Sky for reflections regardless of what the background is.

## Enum EnvironmentGlowBlendMode

- `ENV_GLOW_BLEND_MODE_ADDITIVE = 0` — Adds the glow effect to the scene.
- `ENV_GLOW_BLEND_MODE_SCREEN = 1` — Adds the glow effect to the scene after modifying the glow influence based on the scene value; dark values will be highly influenced by glow and bright values will not be influenced by glow.
- `ENV_GLOW_BLEND_MODE_SOFTLIGHT = 2` — Adds the glow effect to the tonemapped image after modifying the glow influence based on the image value; dark values and bright values will not be influenced by glow and mid-range values will be highly influenced by glow.
- `ENV_GLOW_BLEND_MODE_REPLACE = 3` — Replaces all pixels' color by the glow effect.
- `ENV_GLOW_BLEND_MODE_MIX = 4` — Mixes the glow image with the scene image.

## Enum EnvironmentFogMode

- `ENV_FOG_MODE_EXPONENTIAL = 0` — Use a physically-based fog model defined primarily by fog density.
- `ENV_FOG_MODE_DEPTH = 1` — Use a simple fog model defined by start and end positions and a custom curve.

## Enum EnvironmentToneMapper

- `ENV_TONE_MAPPER_LINEAR = 0` — Does not modify color data, resulting in a linear tonemapping curve which unnaturally clips bright values, causing bright lighting to look blown out.
- `ENV_TONE_MAPPER_REINHARD = 1` — A simple tonemapping curve that rolls off bright values to prevent clipping.
- `ENV_TONE_MAPPER_FILMIC = 2` — Uses a film-like tonemapping curve to prevent clipping of bright values and provide better contrast than `ENV_TONE_MAPPER_REINHARD`.
- `ENV_TONE_MAPPER_ACES = 3` — Uses a high-contrast film-like tonemapping curve and desaturates bright values for a more realistic appearance.
- `ENV_TONE_MAPPER_AGX = 4` — Uses an adjustable film-like tonemapping curve and desaturates bright values for a more realistic appearance.

## Enum EnvironmentSSRRoughnessQuality

- `ENV_SSR_ROUGHNESS_QUALITY_DISABLED = 0` — Lowest quality of roughness filter for screen-space reflections.
- `ENV_SSR_ROUGHNESS_QUALITY_LOW = 1` — Low quality of roughness filter for screen-space reflections.
- `ENV_SSR_ROUGHNESS_QUALITY_MEDIUM = 2` — Medium quality of roughness filter for screen-space reflections.
- `ENV_SSR_ROUGHNESS_QUALITY_HIGH = 3` — High quality of roughness filter for screen-space reflections.

## Enum EnvironmentSSAOQuality

- `ENV_SSAO_QUALITY_VERY_LOW = 0` — Lowest quality of screen-space ambient occlusion.
- `ENV_SSAO_QUALITY_LOW = 1` — Low quality screen-space ambient occlusion.
- `ENV_SSAO_QUALITY_MEDIUM = 2` — Medium quality screen-space ambient occlusion.
- `ENV_SSAO_QUALITY_HIGH = 3` — High quality screen-space ambient occlusion.
- `ENV_SSAO_QUALITY_ULTRA = 4` — Highest quality screen-space ambient occlusion.

## Enum EnvironmentSSILQuality

- `ENV_SSIL_QUALITY_VERY_LOW = 0` — Lowest quality of screen-space indirect lighting.
- `ENV_SSIL_QUALITY_LOW = 1` — Low quality screen-space indirect lighting.
- `ENV_SSIL_QUALITY_MEDIUM = 2` — High quality screen-space indirect lighting.
- `ENV_SSIL_QUALITY_HIGH = 3` — High quality screen-space indirect lighting.
- `ENV_SSIL_QUALITY_ULTRA = 4` — Highest quality screen-space indirect lighting.

## Enum EnvironmentSDFGIYScale

- `ENV_SDFGI_Y_SCALE_50_PERCENT = 0` — Use 50% scale for SDFGI on the Y (vertical) axis.
- `ENV_SDFGI_Y_SCALE_75_PERCENT = 1` — Use 75% scale for SDFGI on the Y (vertical) axis.
- `ENV_SDFGI_Y_SCALE_100_PERCENT = 2` — Use 100% scale for SDFGI on the Y (vertical) axis.

## Enum EnvironmentSDFGIRayCount

- `ENV_SDFGI_RAY_COUNT_4 = 0` — Throw 4 rays per frame when converging SDFGI.
- `ENV_SDFGI_RAY_COUNT_8 = 1` — Throw 8 rays per frame when converging SDFGI.
- `ENV_SDFGI_RAY_COUNT_16 = 2` — Throw 16 rays per frame when converging SDFGI.
- `ENV_SDFGI_RAY_COUNT_32 = 3` — Throw 32 rays per frame when converging SDFGI.
- `ENV_SDFGI_RAY_COUNT_64 = 4` — Throw 64 rays per frame when converging SDFGI.
- `ENV_SDFGI_RAY_COUNT_96 = 5` — Throw 96 rays per frame when converging SDFGI.
- `ENV_SDFGI_RAY_COUNT_128 = 6` — Throw 128 rays per frame when converging SDFGI.
- `ENV_SDFGI_RAY_COUNT_MAX = 7` — Represents the size of the `EnvironmentSDFGIRayCount` enum.

## Enum EnvironmentSDFGIFramesToConverge

- `ENV_SDFGI_CONVERGE_IN_5_FRAMES = 0` — Converge SDFGI over 5 frames.
- `ENV_SDFGI_CONVERGE_IN_10_FRAMES = 1` — Configure SDFGI to fully converge over 10 frames.
- `ENV_SDFGI_CONVERGE_IN_15_FRAMES = 2` — Configure SDFGI to fully converge over 15 frames.
- `ENV_SDFGI_CONVERGE_IN_20_FRAMES = 3` — Configure SDFGI to fully converge over 20 frames.
- `ENV_SDFGI_CONVERGE_IN_25_FRAMES = 4` — Configure SDFGI to fully converge over 25 frames.
- `ENV_SDFGI_CONVERGE_IN_30_FRAMES = 5` — Configure SDFGI to fully converge over 30 frames.
- `ENV_SDFGI_CONVERGE_MAX = 6` — Represents the size of the `EnvironmentSDFGIFramesToConverge` enum.

## Enum EnvironmentSDFGIFramesToUpdateLight

- `ENV_SDFGI_UPDATE_LIGHT_IN_1_FRAME = 0` — Update indirect light from dynamic lights in SDFGI over 1 frame.
- `ENV_SDFGI_UPDATE_LIGHT_IN_2_FRAMES = 1` — Update indirect light from dynamic lights in SDFGI over 2 frames.
- `ENV_SDFGI_UPDATE_LIGHT_IN_4_FRAMES = 2` — Update indirect light from dynamic lights in SDFGI over 4 frames.
- `ENV_SDFGI_UPDATE_LIGHT_IN_8_FRAMES = 3` — Update indirect light from dynamic lights in SDFGI over 8 frames.
- `ENV_SDFGI_UPDATE_LIGHT_IN_16_FRAMES = 4` — Update indirect light from dynamic lights in SDFGI over 16 frames.
- `ENV_SDFGI_UPDATE_LIGHT_MAX = 5` — Represents the size of the `EnvironmentSDFGIFramesToUpdateLight` enum.

## Enum SubSurfaceScatteringQuality

- `SUB_SURFACE_SCATTERING_QUALITY_DISABLED = 0` — Disables subsurface scattering entirely, even on materials that have `BaseMaterial3D.subsurf_scatter_enabled` set to `true`.
- `SUB_SURFACE_SCATTERING_QUALITY_LOW = 1` — Low subsurface scattering quality.
- `SUB_SURFACE_SCATTERING_QUALITY_MEDIUM = 2` — Medium subsurface scattering quality.
- `SUB_SURFACE_SCATTERING_QUALITY_HIGH = 3` — High subsurface scattering quality.

## Enum DOFBokehShape

- `DOF_BOKEH_BOX = 0` — Calculate the DOF blur using a box filter.
- `DOF_BOKEH_HEXAGON = 1` — Calculates DOF blur using a hexagon shaped filter.
- `DOF_BOKEH_CIRCLE = 2` — Calculates DOF blur using a circle shaped filter.

## Enum DOFBlurQuality

- `DOF_BLUR_QUALITY_VERY_LOW = 0` — Lowest quality DOF blur.
- `DOF_BLUR_QUALITY_LOW = 1` — Low quality DOF blur.
- `DOF_BLUR_QUALITY_MEDIUM = 2` — Medium quality DOF blur.
- `DOF_BLUR_QUALITY_HIGH = 3` — Highest quality DOF blur.

## Enum InstanceType

- `INSTANCE_NONE = 0` — The instance does not have a type.
- `INSTANCE_MESH = 1` — The instance is a mesh.
- `INSTANCE_MULTIMESH = 2` — The instance is a multimesh.
- `INSTANCE_PARTICLES = 3` — The instance is a particle emitter.
- `INSTANCE_PARTICLES_COLLISION = 4` — The instance is a GPUParticles collision shape.
- `INSTANCE_LIGHT = 5` — The instance is a light.
- `INSTANCE_REFLECTION_PROBE = 6` — The instance is a reflection probe.
- `INSTANCE_DECAL = 7` — The instance is a decal.
- `INSTANCE_VOXEL_GI = 8` — The instance is a VoxelGI.
- `INSTANCE_LIGHTMAP = 9` — The instance is a lightmap.
- `INSTANCE_OCCLUDER = 10` — The instance is an occlusion culling occluder.
- `INSTANCE_VISIBLITY_NOTIFIER = 11` — The instance is a visible on-screen notifier.
- `INSTANCE_FOG_VOLUME = 12` — The instance is a fog volume.
- `INSTANCE_MAX = 13` — Represents the size of the `InstanceType` enum.
- `INSTANCE_GEOMETRY_MASK = 14` — A combination of the flags of geometry instances (mesh, multimesh, immediate and particles).

## Enum InstanceFlags

- `INSTANCE_FLAG_USE_BAKED_LIGHT = 0` — Allows the instance to be used in baked lighting.
- `INSTANCE_FLAG_USE_DYNAMIC_GI = 1` — Allows the instance to be used with dynamic global illumination.
- `INSTANCE_FLAG_DRAW_NEXT_FRAME_IF_VISIBLE = 2` — When set, manually requests to draw geometry on next frame.
- `INSTANCE_FLAG_IGNORE_OCCLUSION_CULLING = 3` — Always draw, even if the instance would be culled by occlusion culling.
- `INSTANCE_FLAG_MAX = 4` — Represents the size of the `InstanceFlags` enum.

## Enum ShadowCastingSetting

- `SHADOW_CASTING_SETTING_OFF = 0` — Disable shadows from this instance.
- `SHADOW_CASTING_SETTING_ON = 1` — Cast shadows from this instance.
- `SHADOW_CASTING_SETTING_DOUBLE_SIDED = 2` — Disable backface culling when rendering the shadow of the object.
- `SHADOW_CASTING_SETTING_SHADOWS_ONLY = 3` — Only render the shadows from the object.

## Enum VisibilityRangeFadeMode

- `VISIBILITY_RANGE_FADE_DISABLED = 0` — Disable visibility range fading for the given instance.
- `VISIBILITY_RANGE_FADE_SELF = 1` — Fade-out the given instance when it approaches its visibility range limits.
- `VISIBILITY_RANGE_FADE_DEPENDENCIES = 2` — Fade-in the given instance's dependencies when reaching its visibility range limits.

## Enum BakeChannels

- `BAKE_CHANNEL_ALBEDO_ALPHA = 0` — Index of Image in array of Images returned by `bake_render_uv2`.
- `BAKE_CHANNEL_NORMAL = 1` — Index of Image in array of Images returned by `bake_render_uv2`.
- `BAKE_CHANNEL_ORM = 2` — Index of Image in array of Images returned by `bake_render_uv2`.
- `BAKE_CHANNEL_EMISSION = 3` — Index of Image in array of Images returned by `bake_render_uv2`.

## Enum CanvasTextureChannel

- `CANVAS_TEXTURE_CHANNEL_DIFFUSE = 0` — Diffuse canvas texture (`CanvasTexture.diffuse_texture`).
- `CANVAS_TEXTURE_CHANNEL_NORMAL = 1` — Normal map canvas texture (`CanvasTexture.normal_texture`).
- `CANVAS_TEXTURE_CHANNEL_SPECULAR = 2` — Specular map canvas texture (`CanvasTexture.specular_texture`).

## Enum NinePatchAxisMode

- `NINE_PATCH_STRETCH = 0` — The nine patch gets stretched where needed.
- `NINE_PATCH_TILE = 1` — The nine patch gets filled with tiles where needed.
- `NINE_PATCH_TILE_FIT = 2` — The nine patch gets filled with tiles where needed and stretches them a bit if needed.

## Enum CanvasItemTextureFilter

- `CANVAS_ITEM_TEXTURE_FILTER_DEFAULT = 0` — Uses the default filter mode for this Viewport.
- `CANVAS_ITEM_TEXTURE_FILTER_NEAREST = 1` — The texture filter reads from the nearest pixel only.
- `CANVAS_ITEM_TEXTURE_FILTER_LINEAR = 2` — The texture filter blends between the nearest 4 pixels.
- `CANVAS_ITEM_TEXTURE_FILTER_NEAREST_WITH_MIPMAPS = 3` — The texture filter reads from the nearest pixel and blends between the nearest 2 mipmaps (or uses the nearest mipmap if `ProjectSettings.rendering/textures/default_filters/use_nearest_mipmap_filter` is `true`).
- `CANVAS_ITEM_TEXTURE_FILTER_LINEAR_WITH_MIPMAPS = 4` — The texture filter blends between the nearest 4 pixels and between the nearest 2 mipmaps (or uses the nearest mipmap if `ProjectSettings.rendering/textures/default_filters/use_nearest_mipmap_filter` is `true`).
- `CANVAS_ITEM_TEXTURE_FILTER_NEAREST_WITH_MIPMAPS_ANISOTROPIC = 5` — The texture filter reads from the nearest pixel and blends between 2 mipmaps (or uses the nearest mipmap if `ProjectSettings.rendering/textures/default_filters/use_nearest_mipmap_filter` is `true`) based on the angle between the surface and the camera view.
- `CANVAS_ITEM_TEXTURE_FILTER_LINEAR_WITH_MIPMAPS_ANISOTROPIC = 6` — The texture filter blends between the nearest 4 pixels and blends between 2 mipmaps (or uses the nearest mipmap if `ProjectSettings.rendering/textures/default_filters/use_nearest_mipmap_filter` is `true`) based on the angle between the surface and the camera view.
- `CANVAS_ITEM_TEXTURE_FILTER_MAX = 7` — Max value for `CanvasItemTextureFilter` enum.

## Enum CanvasItemTextureRepeat

- `CANVAS_ITEM_TEXTURE_REPEAT_DEFAULT = 0` — Uses the default repeat mode for this Viewport.
- `CANVAS_ITEM_TEXTURE_REPEAT_DISABLED = 1` — Disables textures repeating.
- `CANVAS_ITEM_TEXTURE_REPEAT_ENABLED = 2` — Enables the texture to repeat when UV coordinates are outside the 0-1 range.
- `CANVAS_ITEM_TEXTURE_REPEAT_MIRROR = 3` — Flip the texture when repeating so that the edge lines up instead of abruptly changing.
- `CANVAS_ITEM_TEXTURE_REPEAT_MAX = 4` — Max value for `CanvasItemTextureRepeat` enum.

## Enum CanvasGroupMode

- `CANVAS_GROUP_MODE_DISABLED = 0` — Child draws over parent and is not clipped.
- `CANVAS_GROUP_MODE_CLIP_ONLY = 1` — Parent is used for the purposes of clipping only.
- `CANVAS_GROUP_MODE_CLIP_AND_DRAW = 2` — Parent is used for clipping child, but parent is also drawn underneath child as normal before clipping child to its visible area.
- `CANVAS_GROUP_MODE_TRANSPARENT = 3` — 

## Enum CanvasLightMode

- `CANVAS_LIGHT_MODE_POINT = 0` — 2D point light (see PointLight2D).
- `CANVAS_LIGHT_MODE_DIRECTIONAL = 1` — 2D directional (sun/moon) light (see DirectionalLight2D).

## Enum CanvasLightBlendMode

- `CANVAS_LIGHT_BLEND_MODE_ADD = 0` — Adds light color additive to the canvas.
- `CANVAS_LIGHT_BLEND_MODE_SUB = 1` — Adds light color subtractive to the canvas.
- `CANVAS_LIGHT_BLEND_MODE_MIX = 2` — The light adds color depending on transparency.

## Enum CanvasLightShadowFilter

- `CANVAS_LIGHT_FILTER_NONE = 0` — Do not apply a filter to canvas light shadows.
- `CANVAS_LIGHT_FILTER_PCF5 = 1` — Use PCF5 filtering to filter canvas light shadows.
- `CANVAS_LIGHT_FILTER_PCF13 = 2` — Use PCF13 filtering to filter canvas light shadows.
- `CANVAS_LIGHT_FILTER_MAX = 3` — Max value of the `CanvasLightShadowFilter` enum.

## Enum CanvasOccluderPolygonCullMode

- `CANVAS_OCCLUDER_POLYGON_CULL_DISABLED = 0` — Culling of the canvas occluder is disabled.
- `CANVAS_OCCLUDER_POLYGON_CULL_CLOCKWISE = 1` — Culling of the canvas occluder is clockwise.
- `CANVAS_OCCLUDER_POLYGON_CULL_COUNTER_CLOCKWISE = 2` — Culling of the canvas occluder is counterclockwise.

## Enum GlobalShaderParameterType

- `GLOBAL_VAR_TYPE_BOOL = 0` — Boolean global shader parameter (`global uniform bool ...`).
- `GLOBAL_VAR_TYPE_BVEC2 = 1` — 2-dimensional boolean vector global shader parameter (`global uniform bvec2 ...`).
- `GLOBAL_VAR_TYPE_BVEC3 = 2` — 3-dimensional boolean vector global shader parameter (`global uniform bvec3 ...`).
- `GLOBAL_VAR_TYPE_BVEC4 = 3` — 4-dimensional boolean vector global shader parameter (`global uniform bvec4 ...`).
- `GLOBAL_VAR_TYPE_INT = 4` — Integer global shader parameter (`global uniform int ...`).
- `GLOBAL_VAR_TYPE_IVEC2 = 5` — 2-dimensional integer vector global shader parameter (`global uniform ivec2 ...`).
- `GLOBAL_VAR_TYPE_IVEC3 = 6` — 3-dimensional integer vector global shader parameter (`global uniform ivec3 ...`).
- `GLOBAL_VAR_TYPE_IVEC4 = 7` — 4-dimensional integer vector global shader parameter (`global uniform ivec4 ...`).
- `GLOBAL_VAR_TYPE_RECT2I = 8` — 2-dimensional integer rectangle global shader parameter (`global uniform ivec4 ...`).
- `GLOBAL_VAR_TYPE_UINT = 9` — Unsigned integer global shader parameter (`global uniform uint ...`).
- `GLOBAL_VAR_TYPE_UVEC2 = 10` — 2-dimensional unsigned integer vector global shader parameter (`global uniform uvec2 ...`).
- `GLOBAL_VAR_TYPE_UVEC3 = 11` — 3-dimensional unsigned integer vector global shader parameter (`global uniform uvec3 ...`).
- `GLOBAL_VAR_TYPE_UVEC4 = 12` — 4-dimensional unsigned integer vector global shader parameter (`global uniform uvec4 ...`).
- `GLOBAL_VAR_TYPE_FLOAT = 13` — Single-precision floating-point global shader parameter (`global uniform float ...`).
- `GLOBAL_VAR_TYPE_VEC2 = 14` — 2-dimensional floating-point vector global shader parameter (`global uniform vec2 ...`).
- `GLOBAL_VAR_TYPE_VEC3 = 15` — 3-dimensional floating-point vector global shader parameter (`global uniform vec3 ...`).
- `GLOBAL_VAR_TYPE_VEC4 = 16` — 4-dimensional floating-point vector global shader parameter (`global uniform vec4 ...`).
- `GLOBAL_VAR_TYPE_COLOR = 17` — Color global shader parameter (`global uniform vec4 ...`).
- `GLOBAL_VAR_TYPE_RECT2 = 18` — 2-dimensional floating-point rectangle global shader parameter (`global uniform vec4 ...`).
- `GLOBAL_VAR_TYPE_MAT2 = 19` — 2×2 matrix global shader parameter (`global uniform mat2 ...`).
- `GLOBAL_VAR_TYPE_MAT3 = 20` — 3×3 matrix global shader parameter (`global uniform mat3 ...`).
- `GLOBAL_VAR_TYPE_MAT4 = 21` — 4×4 matrix global shader parameter (`global uniform mat4 ...`).
- `GLOBAL_VAR_TYPE_TRANSFORM_2D = 22` — 2-dimensional transform global shader parameter (`global uniform mat2x3 ...`).
- `GLOBAL_VAR_TYPE_TRANSFORM = 23` — 3-dimensional transform global shader parameter (`global uniform mat3x4 ...`).
- `GLOBAL_VAR_TYPE_SAMPLER2D = 24` — 2D sampler global shader parameter (`global uniform sampler2D ...`).
- `GLOBAL_VAR_TYPE_SAMPLER2DARRAY = 25` — 2D sampler array global shader parameter (`global uniform sampler2DArray ...`).
- `GLOBAL_VAR_TYPE_SAMPLER3D = 26` — 3D sampler global shader parameter (`global uniform sampler3D ...`).
- `GLOBAL_VAR_TYPE_SAMPLERCUBE = 27` — Cubemap sampler global shader parameter (`global uniform samplerCube ...`).
- `GLOBAL_VAR_TYPE_SAMPLEREXT = 28` — External sampler global shader parameter (`global uniform samplerExternalOES ...`).
- `GLOBAL_VAR_TYPE_MAX = 29` — Represents the size of the `GlobalShaderParameterType` enum.

## Enum RenderingInfo

- `RENDERING_INFO_TOTAL_OBJECTS_IN_FRAME = 0` — Number of objects rendered in the current 3D scene.
- `RENDERING_INFO_TOTAL_PRIMITIVES_IN_FRAME = 1` — Number of points, lines, or triangles rendered in the current 3D scene.
- `RENDERING_INFO_TOTAL_DRAW_CALLS_IN_FRAME = 2` — Number of draw calls performed to render in the current 3D scene.
- `RENDERING_INFO_TEXTURE_MEM_USED = 3` — Texture memory used (in bytes).
- `RENDERING_INFO_BUFFER_MEM_USED = 4` — Buffer memory used (in bytes).
- `RENDERING_INFO_VIDEO_MEM_USED = 5` — Video memory used (in bytes).
- `RENDERING_INFO_PIPELINE_COMPILATIONS_CANVAS = 6` — Number of pipeline compilations that were triggered by the 2D canvas renderer.
- `RENDERING_INFO_PIPELINE_COMPILATIONS_MESH = 7` — Number of pipeline compilations that were triggered by loading meshes.
- `RENDERING_INFO_PIPELINE_COMPILATIONS_SURFACE = 8` — Number of pipeline compilations that were triggered by building the surface cache before rendering the scene.
- `RENDERING_INFO_PIPELINE_COMPILATIONS_DRAW = 9` — Number of pipeline compilations that were triggered while drawing the scene.
- `RENDERING_INFO_PIPELINE_COMPILATIONS_SPECIALIZATION = 10` — Number of pipeline compilations that were triggered to optimize the current scene.

## Enum PipelineSource

- `PIPELINE_SOURCE_CANVAS = 0` — Pipeline compilation that was triggered by the 2D canvas renderer.
- `PIPELINE_SOURCE_MESH = 1` — Pipeline compilation that was triggered by loading a mesh.
- `PIPELINE_SOURCE_SURFACE = 2` — Pipeline compilation that was triggered by building the surface cache before rendering the scene.
- `PIPELINE_SOURCE_DRAW = 3` — Pipeline compilation that was triggered while drawing the scene.
- `PIPELINE_SOURCE_SPECIALIZATION = 4` — Pipeline compilation that was triggered to optimize the current scene.
- `PIPELINE_SOURCE_MAX = 5` — Represents the size of the `PipelineSource` enum.

## Enum SplashStretchMode

- `SPLASH_STRETCH_MODE_DISABLED = 0` — No stretching is applied.
- `SPLASH_STRETCH_MODE_KEEP = 1` — Stretches image to fullscreen while preserving aspect ratio.
- `SPLASH_STRETCH_MODE_KEEP_WIDTH = 2` — Stretches the height of the image based on the width of the screen.
- `SPLASH_STRETCH_MODE_KEEP_HEIGHT = 3` — Stretches the width of the image based on the height of the screen.
- `SPLASH_STRETCH_MODE_COVER = 4` — Stretches the image to cover the entire screen while preserving aspect ratio.
- `SPLASH_STRETCH_MODE_IGNORE = 5` — Stretches the image to cover the entire screen but doesn't preserve aspect ratio.

## Enum Features

- `FEATURE_SHADERS = 0` — 
- `FEATURE_MULTITHREADED = 1` — 

## Constants

- `NO_INDEX_ARRAY = -1` — Marks an error that shows that the index array is empty.
- `ARRAY_WEIGHTS_SIZE = 4` — Number of weights/bones per vertex.
- `CANVAS_ITEM_Z_MIN = -4096` — The minimum Z-layer for canvas items.
- `CANVAS_ITEM_Z_MAX = 4096` — The maximum Z-layer for canvas items.
- `CANVAS_LAYER_MIN = -2147483648` — The minimum canvas layer.
- `CANVAS_LAYER_MAX = 2147483647` — The maximum canvas layer.
- `MAX_GLOW_LEVELS = 7` — The maximum number of glow levels that can be used with the glow post-processing effect.
- `MAX_CURSORS = 8` — 
- `MAX_2D_DIRECTIONAL_LIGHTS = 8` — The maximum number of directional lights that can be rendered at a given time in 2D.
- `MAX_MESH_SURFACES = 256` — The maximum number of surfaces a mesh can have.
- `MATERIAL_RENDER_PRIORITY_MIN = -128` — The minimum renderpriority of all materials.
- `MATERIAL_RENDER_PRIORITY_MAX = 127` — The maximum renderpriority of all materials.
- `ARRAY_CUSTOM_COUNT = 4` — The number of custom data arrays available (`ARRAY_CUSTOM0`, `ARRAY_CUSTOM1`, `ARRAY_CUSTOM2`, `ARRAY_CUSTOM3`).
- `PARTICLES_EMIT_FLAG_POSITION = 1` — Particle starts at the specified position.
- `PARTICLES_EMIT_FLAG_ROTATION_SCALE = 2` — Particle starts with specified rotation and scale.
- `PARTICLES_EMIT_FLAG_VELOCITY = 4` — Particle starts with the specified velocity vector, which defines the emission direction and speed.
- `PARTICLES_EMIT_FLAG_COLOR = 8` — Particle starts with specified color.
- `PARTICLES_EMIT_FLAG_CUSTOM = 16` — Particle starts with specified `CUSTOM` data.
