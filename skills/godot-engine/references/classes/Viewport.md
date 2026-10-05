# Viewport

**Inherits:** Node

Abstract base class for viewports. Encapsulates drawing and interaction with a game world.

A Viewport creates a different view into the screen, or a sub-view inside another viewport. Child 2D nodes will display on it, and child Camera3D 3D nodes will render on it too. Optionally, a viewport can have its own 2D or 3D world, so it doesn't share what it draws with other viewports. Viewports can also choose to be audio listeners, so they generate positional audio depending on a 2D or 3D camera child of it.

## Properties

- `anisotropic_filtering_level: Viewport.AnisotropicFiltering` = `2` — Sets the maximum number of samples to take when using anisotropic filtering on textures (as a power of two).
- `audio_listener_enable_2d: bool` = `false` — If `true`, the viewport will process 2D audio streams.
- `audio_listener_enable_3d: bool` = `false` — If `true`, the viewport will process 3D audio streams.
- `canvas_cull_mask: int` = `4294967295` — The rendering layers in which this Viewport renders CanvasItem nodes.
- `canvas_item_default_texture_filter: Viewport.DefaultCanvasItemTextureFilter` = `1` — The default filter mode used by CanvasItem nodes in this viewport.
- `canvas_item_default_texture_repeat: Viewport.DefaultCanvasItemTextureRepeat` = `0` — The default repeat mode used by CanvasItem nodes in this viewport.
- `canvas_transform: Transform2D` — The canvas transform of the viewport, useful for changing the on-screen positions of all child CanvasItems.
- `debug_draw: Viewport.DebugDraw` = `0` — The overlay mode for test rendered geometry in debug purposes.
- `disable_3d: bool` = `false` — Disable 3D rendering (but keep 2D rendering).
- `fsr_sharpness: float` = `0.2` — Determines how sharp the upscaled image will be when using the FSR upscaling mode.
- `global_canvas_transform: Transform2D` — The global canvas transform of the viewport.
- `gui_disable_input: bool` = `false` — If `true`, the viewport will not receive input events.
- `gui_drag_threshold: int` = `10` — The minimum distance the mouse cursor must move while pressed before a drag operation begins.
- `gui_embed_subwindows: bool` = `false` — If `true`, sub-windows (popups and dialogs) will be embedded inside application window as control-like nodes.
- `gui_snap_controls_to_pixels: bool` = `true` — If `true`, the GUI controls on the viewport will lay pixel perfectly.
- `handle_input_locally: bool` = `true` — If `true`, this viewport will mark incoming input events as handled by itself.
- `mesh_lod_threshold: float` = `1.0` — The automatic LOD bias to use for meshes rendered within the Viewport (this is analogous to `ReflectionProbe.mesh_lod_threshold`).
- `msaa_2d: Viewport.MSAA` = `0` — The multisample antialiasing mode for 2D/Canvas rendering.
- `msaa_3d: Viewport.MSAA` = `0` — The multisample antialiasing mode for 3D rendering.
- `oversampling: bool` = `true` — If `true` and one of the following conditions are true: `SubViewport.size_2d_override_stretch` and `SubViewport.size_2d_override` are set, `Window.content_scale_factor` is set and scaling is enabled, `oversampling_override` is set, font and DPITexture oversampling are enabled.
- `oversampling_override: float` = `0.0` — If greater than zero, this value is used as the font oversampling factor, otherwise oversampling is equal to viewport scale.
- `own_world_3d: bool` = `false` — If `true`, the viewport will use a unique copy of the World3D defined in `world_3d`.
- `physics_interpolation_mode: Node.PhysicsInterpolationMode` = `1` — 
- `physics_object_picking: bool` = `false` — If `true`, the objects rendered by viewport become subjects of mouse picking process.
- `physics_object_picking_first_only: bool` = `false` — If `true`, the input_event signal will only be sent to one physics object in the mouse picking process.
- `physics_object_picking_sort: bool` = `false` — If `true`, objects receive mouse picking events sorted primarily by their `CanvasItem.z_index` and secondarily by their position in the scene tree.
- `positional_shadow_atlas_16_bits: bool` = `true` — Use 16 bits for the omni/spot shadow depth map.
- `positional_shadow_atlas_quad_0: Viewport.PositionalShadowAtlasQuadrantSubdiv` = `2` — The subdivision amount of the first quadrant on the shadow atlas.
- `positional_shadow_atlas_quad_1: Viewport.PositionalShadowAtlasQuadrantSubdiv` = `2` — The subdivision amount of the second quadrant on the shadow atlas.
- `positional_shadow_atlas_quad_2: Viewport.PositionalShadowAtlasQuadrantSubdiv` = `3` — The subdivision amount of the third quadrant on the shadow atlas.
- `positional_shadow_atlas_quad_3: Viewport.PositionalShadowAtlasQuadrantSubdiv` = `4` — The subdivision amount of the fourth quadrant on the shadow atlas.
- `positional_shadow_atlas_size: int` = `2048` — The shadow atlas's resolution (used for omni and spot lights).
- `scaling_3d_mode: Viewport.Scaling3DMode` = `0` — Sets scaling 3D mode.
- `scaling_3d_scale: float` = `1.0` — Scales the 3D render buffer based on the viewport size uses an image filter specified in `ProjectSettings.rendering/scaling_3d/mode` to scale the output image to the full viewport size.
- `screen_space_aa: Viewport.ScreenSpaceAA` = `0` — Sets the screen-space antialiasing method used.
- `sdf_oversize: Viewport.SDFOversize` = `1` — Controls how much of the original viewport's size should be covered by the 2D signed distance field.
- `sdf_scale: Viewport.SDFScale` = `1` — The resolution scale to use for the 2D signed distance field.
- `snap_2d_transforms_to_pixel: bool` = `false` — If `true`, CanvasItem nodes will internally snap to full pixels.
- `snap_2d_vertices_to_pixel: bool` = `false` — If `true`, vertices of CanvasItem nodes will snap to full pixels.
- `texture_mipmap_bias: float` = `0.0` — Affects the final texture sharpness by reading from a lower or higher mipmap (also called "texture LOD bias").
- `transparent_bg: bool` = `false` — If `true`, the viewport should render its background as transparent.
- `use_debanding: bool` = `false` — When using the Mobile or Forward+ renderers, set `use_debanding` to enable or disable the debanding feature of this Viewport.
- `use_hdr_2d: bool` = `false` — If `true`, 2D rendering will use a high dynamic range (HDR) `RGBA16` format framebuffer.
- `use_occlusion_culling: bool` = `false` — If `true`, OccluderInstance3D nodes will be usable for occlusion culling in 3D for this viewport.
- `use_taa: bool` = `false` — Enables temporal antialiasing for this viewport.
- `use_xr: bool` = `false` — If `true`, the viewport will use the primary XR interface to render XR output.
- `vrs_mode: Viewport.VRSMode` = `0` — The Variable Rate Shading (VRS) mode that is used for this viewport.
- `vrs_texture: Texture2D` — Texture to use when `vrs_mode` is set to `Viewport.VRS_TEXTURE`.
- `vrs_update_mode: Viewport.VRSUpdateMode` = `1` — Sets the update mode for Variable Rate Shading (VRS) for the viewport.
- `world_2d: World2D` — The custom World2D which can be used as 2D environment source.
- `world_3d: World3D` — The custom World3D which can be used as 3D environment source.

## Methods

- `find_world_2d() -> World2D` *const* — Returns the first valid World2D for this viewport, searching the `world_2d` property of itself and any Viewport ancestor.
- `find_world_3d() -> World3D` *const* — Returns the first valid World3D for this viewport, searching the `world_3d` property of itself and any Viewport ancestor.
- `get_audio_listener_2d() -> AudioListener2D` *const* — Returns the currently active 2D audio listener.
- `get_audio_listener_3d() -> AudioListener3D` *const* — Returns the currently active 3D audio listener.
- `get_camera_2d() -> Camera2D` *const* — Returns the currently active 2D camera.
- `get_camera_3d() -> Camera3D` *const* — Returns the currently active 3D camera.
- `get_canvas_cull_mask_bit(layer: int) -> bool` *const* — Returns an individual bit on the rendering layer mask.
- `get_embedded_subwindows() -> Window[]` *const* — Returns a list of the visible embedded Windows inside the viewport.
- `get_final_transform() -> Transform2D` *const* — Returns the transform from the viewport's coordinate system to the embedder's coordinate system.
- `get_mouse_position() -> Vector2` *const* — Returns the mouse's position in this Viewport using the coordinate system of this Viewport.
- `get_oversampling() -> float` *const* — Returns viewport oversampling factor.
- `get_positional_shadow_atlas_quadrant_subdiv(quadrant: int) -> int[Viewport.PositionalShadowAtlasQuadrantSubdiv]` *const* — Returns the positional shadow atlas quadrant subdivision of the specified quadrant.
- `get_render_info(type: Viewport.RenderInfoType, info: Viewport.RenderInfo) -> int` — Returns rendering statistics of the given type.
- `get_screen_transform() -> Transform2D` *const* — Returns the transform from the Viewport's coordinates to the screen coordinates of the containing window manager window.
- `get_stretch_transform() -> Transform2D` *const* — Returns the automatically computed 2D stretch transform, taking the Viewport's stretch settings into account.
- `get_texture() -> ViewportTexture` *const* — Returns the viewport's texture.
- `get_viewport_rid() -> RID` *const* — Returns the viewport's RID from the RenderingServer.
- `get_visible_rect() -> Rect2` *const* — Returns the visible rectangle in global screen coordinates.
- `gui_cancel_drag() -> void` — Cancels the drag operation that was previously started through `Control._get_drag_data` or forced with `Control.force_drag`.
- `gui_get_drag_data() -> Variant` *const* — Returns the drag data from the GUI, that was previously returned by `Control._get_drag_data`.
- `gui_get_drag_description() -> String` *const* — Returns the human-readable description of the drag data, used for assistive apps.
- `gui_get_focus_owner() -> Control` *const* — Returns the currently focused Control within this viewport.
- `gui_get_hovered_control() -> Control` *const* — Returns the Control that the mouse is currently hovering over in this viewport.
- `gui_is_drag_successful() -> bool` *const* — Returns `true` if the drag operation is successful.
- `gui_is_dragging() -> bool` *const* — Returns `true` if a drag operation is currently ongoing and where the drop action could happen in this viewport.
- `gui_release_focus() -> void` — Removes the focus from the currently focused Control within this viewport.
- `gui_set_drag_description(description: String) -> void` — Sets the human-readable description of the drag data to `description`, used for assistive apps.
- `is_input_handled() -> bool` *const* — Returns whether the current InputEvent has been handled.
- `notify_mouse_entered() -> void` — Inform the Viewport that the mouse has entered its area.
- `notify_mouse_exited() -> void` — Inform the Viewport that the mouse has left its area.
- `push_input(event: InputEvent, in_local_coords: bool = false) -> void` — Triggers the given `event` in this Viewport.
- `push_text_input(text: String) -> void` — Helper method which calls the `set_text()` method on the currently focused Control, provided that it is defined (e.g. if the focused Control is Button or LineEdit).
- `push_unhandled_input(event: InputEvent, in_local_coords: bool = false) -> void` *(deprecated)* — Triggers the given `event` in this Viewport.
- `set_canvas_cull_mask_bit(layer: int, enable: bool) -> void` — Set/clear individual bits on the rendering layer mask.
- `set_input_as_handled() -> void` — Stops the input from propagating further up the SceneTree.
- `set_positional_shadow_atlas_quadrant_subdiv(quadrant: int, subdiv: Viewport.PositionalShadowAtlasQuadrantSubdiv) -> void` — Sets the number of subdivisions to use in the specified quadrant.
- `update_mouse_cursor_state() -> void` — Force instantly updating the display based on the current mouse cursor position.
- `warp_mouse(position: Vector2) -> void` — Moves the mouse pointer to the specified position in this Viewport using the coordinate system of this Viewport.

## Signals

- `gui_focus_changed(node: Control)` — Emitted when a Control node grabs keyboard focus.
- `size_changed()` — Emitted when the size of the viewport is changed, whether by resizing of window, or some other means.

## Enum PositionalShadowAtlasQuadrantSubdiv

- `SHADOW_ATLAS_QUADRANT_SUBDIV_DISABLED = 0` — This quadrant will not be used.
- `SHADOW_ATLAS_QUADRANT_SUBDIV_1 = 1` — This quadrant will only be used by one shadow map.
- `SHADOW_ATLAS_QUADRANT_SUBDIV_4 = 2` — This quadrant will be split in 4 and used by up to 4 shadow maps.
- `SHADOW_ATLAS_QUADRANT_SUBDIV_16 = 3` — This quadrant will be split 16 ways and used by up to 16 shadow maps.
- `SHADOW_ATLAS_QUADRANT_SUBDIV_64 = 4` — This quadrant will be split 64 ways and used by up to 64 shadow maps.
- `SHADOW_ATLAS_QUADRANT_SUBDIV_256 = 5` — This quadrant will be split 256 ways and used by up to 256 shadow maps.
- `SHADOW_ATLAS_QUADRANT_SUBDIV_1024 = 6` — This quadrant will be split 1024 ways and used by up to 1024 shadow maps.
- `SHADOW_ATLAS_QUADRANT_SUBDIV_MAX = 7` — Represents the size of the `PositionalShadowAtlasQuadrantSubdiv` enum.

## Enum Scaling3DMode

- `SCALING_3D_MODE_BILINEAR = 0` — Use bilinear scaling for the viewport's 3D buffer.
- `SCALING_3D_MODE_FSR = 1` — Use AMD FidelityFX Super Resolution 1.0 upscaling for the viewport's 3D buffer.
- `SCALING_3D_MODE_FSR2 = 2` — Use AMD FidelityFX Super Resolution 2.2 upscaling for the viewport's 3D buffer.
- `SCALING_3D_MODE_METALFX_SPATIAL = 3` — Use the MetalFX spatial upscaler for the viewport's 3D buffer.
- `SCALING_3D_MODE_METALFX_TEMPORAL = 4` — Use the MetalFX temporal upscaler for the viewport's 3D buffer.
- `SCALING_3D_MODE_NEAREST = 5` — Use nearest-neighbor filtering for the viewport's 3D buffer.
- `SCALING_3D_MODE_MAX = 6` — Represents the size of the `Scaling3DMode` enum.

## Enum MSAA

- `MSAA_DISABLED = 0` — Multisample antialiasing mode disabled.
- `MSAA_2X = 1` — Use 2× Multisample Antialiasing.
- `MSAA_4X = 2` — Use 4× Multisample Antialiasing.
- `MSAA_8X = 3` — Use 8× Multisample Antialiasing.
- `MSAA_MAX = 4` — Represents the size of the `MSAA` enum.

## Enum AnisotropicFiltering

- `ANISOTROPY_DISABLED = 0` — Anisotropic filtering is disabled.
- `ANISOTROPY_2X = 1` — Use 2× anisotropic filtering.
- `ANISOTROPY_4X = 2` — Use 4× anisotropic filtering.
- `ANISOTROPY_8X = 3` — Use 8× anisotropic filtering.
- `ANISOTROPY_16X = 4` — Use 16× anisotropic filtering.
- `ANISOTROPY_MAX = 5` — Represents the size of the `AnisotropicFiltering` enum.

## Enum ScreenSpaceAA

- `SCREEN_SPACE_AA_DISABLED = 0` — Do not perform any antialiasing in the full screen post-process.
- `SCREEN_SPACE_AA_FXAA = 1` — Use fast approximate antialiasing.
- `SCREEN_SPACE_AA_SMAA = 2` — Use subpixel morphological antialiasing.
- `SCREEN_SPACE_AA_MAX = 3` — Represents the size of the `ScreenSpaceAA` enum.

## Enum RenderInfo

- `RENDER_INFO_OBJECTS_IN_FRAME = 0` — Amount of objects in frame.
- `RENDER_INFO_PRIMITIVES_IN_FRAME = 1` — Amount of vertices in frame.
- `RENDER_INFO_DRAW_CALLS_IN_FRAME = 2` — Amount of draw calls in frame.
- `RENDER_INFO_MAX = 3` — Represents the size of the `RenderInfo` enum.

## Enum RenderInfoType

- `RENDER_INFO_TYPE_VISIBLE = 0` — Visible render pass (excluding shadows).
- `RENDER_INFO_TYPE_SHADOW = 1` — Shadow render pass.
- `RENDER_INFO_TYPE_CANVAS = 2` — Canvas item rendering.
- `RENDER_INFO_TYPE_MAX = 3` — Represents the size of the `RenderInfoType` enum.

## Enum DebugDraw

- `DEBUG_DRAW_DISABLED = 0` — Objects are displayed normally.
- `DEBUG_DRAW_UNSHADED = 1` — Objects are displayed without light information.
- `DEBUG_DRAW_LIGHTING = 2` — Objects are displayed without textures and only with lighting information.
- `DEBUG_DRAW_OVERDRAW = 3` — Objects are displayed semi-transparent with additive blending so you can see where they are drawing over top of one another.
- `DEBUG_DRAW_WIREFRAME = 4` — Objects are displayed as wireframe models.
- `DEBUG_DRAW_NORMAL_BUFFER = 5` — Objects are displayed without lighting information and their textures replaced by normal mapping.
- `DEBUG_DRAW_VOXEL_GI_ALBEDO = 6` — Objects are displayed with only the albedo value from VoxelGIs.
- `DEBUG_DRAW_VOXEL_GI_LIGHTING = 7` — Objects are displayed with only the lighting value from VoxelGIs.
- `DEBUG_DRAW_VOXEL_GI_EMISSION = 8` — Objects are displayed with only the emission color from VoxelGIs.
- `DEBUG_DRAW_SHADOW_ATLAS = 9` — Draws the shadow atlas that stores shadows from OmniLight3Ds and SpotLight3Ds in the upper left quadrant of the Viewport.
- `DEBUG_DRAW_DIRECTIONAL_SHADOW_ATLAS = 10` — Draws the shadow atlas that stores shadows from DirectionalLight3Ds in the upper left quadrant of the Viewport.
- `DEBUG_DRAW_SCENE_LUMINANCE = 11` — Draws the scene luminance buffer (if available) in the upper left quadrant of the Viewport.
- `DEBUG_DRAW_SSAO = 12` — Draws the screen-space ambient occlusion texture instead of the scene so that you can clearly see how it is affecting objects.
- `DEBUG_DRAW_SSIL = 13` — Draws the screen-space indirect lighting texture instead of the scene so that you can clearly see how it is affecting objects.
- `DEBUG_DRAW_PSSM_SPLITS = 14` — Colors each PSSM split for the DirectionalLight3Ds in the scene a different color so you can see where the splits are.
- `DEBUG_DRAW_DECAL_ATLAS = 15` — Draws the decal atlas used by Decals and light projector textures in the upper left quadrant of the Viewport.
- `DEBUG_DRAW_SDFGI = 16` — Draws the cascades used to render signed distance field global illumination (SDFGI).
- `DEBUG_DRAW_SDFGI_PROBES = 17` — Draws the probes used for signed distance field global illumination (SDFGI).
- `DEBUG_DRAW_GI_BUFFER = 18` — Draws the buffer used for global illumination from VoxelGI or SDFGI.
- `DEBUG_DRAW_DISABLE_LOD = 19` — Draws all of the objects at their highest polycount regardless of their distance from the camera.
- `DEBUG_DRAW_CLUSTER_OMNI_LIGHTS = 20` — Draws the cluster used by OmniLight3D nodes to optimize light rendering.
- `DEBUG_DRAW_CLUSTER_SPOT_LIGHTS = 21` — Draws the cluster used by SpotLight3D nodes to optimize light rendering.
- `DEBUG_DRAW_CLUSTER_DECALS = 22` — Draws the cluster used by Decal nodes to optimize decal rendering.
- `DEBUG_DRAW_CLUSTER_REFLECTION_PROBES = 23` — Draws the cluster used by ReflectionProbe nodes to optimize reflection probes.
- `DEBUG_DRAW_OCCLUDERS = 24` — Draws the buffer used for occlusion culling.
- `DEBUG_DRAW_MOTION_VECTORS = 25` — Draws vector lines over the viewport to indicate the movement of pixels between frames.
- `DEBUG_DRAW_INTERNAL_BUFFER = 26` — Draws the internal resolution buffer of the scene in linear colorspace before tonemapping or post-processing is applied.
- `DEBUG_DRAW_CLUSTER_AREA_LIGHTS = 27` — Draws the cluster used by AreaLight3D nodes to optimize light rendering.
- `DEBUG_DRAW_AREA_LIGHT_ATLAS = 28` — Draws the atlas used by AreaLight3D nodes in the upper left quadrant of the Viewport.

## Enum DefaultCanvasItemTextureFilter

- `DEFAULT_CANVAS_ITEM_TEXTURE_FILTER_NEAREST = 0` — The texture filter reads from the nearest pixel only.
- `DEFAULT_CANVAS_ITEM_TEXTURE_FILTER_LINEAR = 1` — The texture filter blends between the nearest 4 pixels.
- `DEFAULT_CANVAS_ITEM_TEXTURE_FILTER_LINEAR_WITH_MIPMAPS = 2` — The texture filter blends between the nearest 4 pixels and between the nearest 2 mipmaps (or uses the nearest mipmap if `ProjectSettings.rendering/textures/default_filters/use_nearest_mipmap_filter` is `true`).
- `DEFAULT_CANVAS_ITEM_TEXTURE_FILTER_NEAREST_WITH_MIPMAPS = 3` — The texture filter reads from the nearest pixel and blends between the nearest 2 mipmaps (or uses the nearest mipmap if `ProjectSettings.rendering/textures/default_filters/use_nearest_mipmap_filter` is `true`).
- `DEFAULT_CANVAS_ITEM_TEXTURE_FILTER_PARENT_NODE = 4` — The Viewport will inherit the filter from its parent CanvasItem or Viewport.
- `DEFAULT_CANVAS_ITEM_TEXTURE_FILTER_MAX = 5` — Represents the size of the `DefaultCanvasItemTextureFilter` enum.

## Enum DefaultCanvasItemTextureRepeat

- `DEFAULT_CANVAS_ITEM_TEXTURE_REPEAT_DISABLED = 0` — Disables textures repeating.
- `DEFAULT_CANVAS_ITEM_TEXTURE_REPEAT_ENABLED = 1` — Enables the texture to repeat when UV coordinates are outside the 0-1 range.
- `DEFAULT_CANVAS_ITEM_TEXTURE_REPEAT_MIRROR = 2` — Flip the texture when repeating so that the edge lines up instead of abruptly changing.
- `DEFAULT_CANVAS_ITEM_TEXTURE_REPEAT_PARENT_NODE = 3` — The Viewport will inherit the repeat mode from its parent CanvasItem or Viewport.
- `DEFAULT_CANVAS_ITEM_TEXTURE_REPEAT_MAX = 4` — Represents the size of the `DefaultCanvasItemTextureRepeat` enum.

## Enum SDFOversize

- `SDF_OVERSIZE_100_PERCENT = 0` — The signed distance field only covers the viewport's own rectangle.
- `SDF_OVERSIZE_120_PERCENT = 1` — The signed distance field is expanded to cover 20% of the viewport's size around the borders.
- `SDF_OVERSIZE_150_PERCENT = 2` — The signed distance field is expanded to cover 50% of the viewport's size around the borders.
- `SDF_OVERSIZE_200_PERCENT = 3` — The signed distance field is expanded to cover 100% (double) of the viewport's size around the borders.
- `SDF_OVERSIZE_MAX = 4` — Represents the size of the `SDFOversize` enum.

## Enum SDFScale

- `SDF_SCALE_100_PERCENT = 0` — The signed distance field is rendered at full resolution.
- `SDF_SCALE_50_PERCENT = 1` — The signed distance field is rendered at half the resolution of this viewport.
- `SDF_SCALE_25_PERCENT = 2` — The signed distance field is rendered at a quarter the resolution of this viewport.
- `SDF_SCALE_MAX = 3` — Represents the size of the `SDFScale` enum.

## Enum VRSMode

- `VRS_DISABLED = 0` — Variable Rate Shading is disabled.
- `VRS_TEXTURE = 1` — Variable Rate Shading uses a texture.
- `VRS_XR = 2` — Variable Rate Shading's texture is supplied by the primary XRInterface.
- `VRS_MAX = 3` — Represents the size of the `VRSMode` enum.

## Enum VRSUpdateMode

- `VRS_UPDATE_DISABLED = 0` — The input texture for variable rate shading will not be processed.
- `VRS_UPDATE_ONCE = 1` — The input texture for variable rate shading will be processed once.
- `VRS_UPDATE_ALWAYS = 2` — The input texture for variable rate shading will be processed each frame.
- `VRS_UPDATE_MAX = 3` — Represents the size of the `VRSUpdateMode` enum.
