# RenderSceneBuffersRD

**Inherits:** RenderSceneBuffers

Render scene buffer implementation for the RenderingDevice based renderers.

This object manages all 3D rendering buffers for the rendering device based renderers. An instance of this object is created for every viewport that has 3D rendering enabled. See also RenderSceneBuffers. All buffers are organized in contexts.

## Methods

- `clear_context(context: StringName) -> void` — Frees all buffers related to this context.
- `create_texture(context: StringName, name: StringName, data_format: RenderingDevice.DataFormat, usage_bits: int, texture_samples: RenderingDevice.TextureSamples, size: Vector2i, layers: int, mipmaps: int, unique: bool, discardable: bool) -> RID` — Create a new texture with the given definition and cache this under the given name.
- `create_texture_from_format(context: StringName, name: StringName, format: RDTextureFormat, view: RDTextureView, unique: bool) -> RID` — Create a new texture using the given format and view and cache this under the given name.
- `create_texture_view(context: StringName, name: StringName, view_name: StringName, view: RDTextureView) -> RID` — Create a new texture view for an existing texture and cache this under the given `view_name`.
- `get_color_layer(layer: int, msaa: bool = false) -> RID` — Returns the specified layer from the color texture we are rendering 3D content to.
- `get_color_texture(msaa: bool = false) -> RID` — Returns the color texture we are rendering 3D content to.
- `get_depth_layer(layer: int, msaa: bool = false) -> RID` — Returns the specified layer from the depth texture we are rendering 3D content to.
- `get_depth_texture(msaa: bool = false) -> RID` — Returns the depth texture we are rendering 3D content to.
- `get_fsr_sharpness() -> float` *const* — Returns the FSR sharpness value used while rendering the 3D content (if `get_scaling_3d_mode` is an FSR mode).
- `get_internal_size() -> Vector2i` *const* — Returns the internal size of the render buffer (size before upscaling) with which textures are created by default.
- `get_msaa_3d() -> int[RenderingServer.ViewportMSAA]` *const* — Returns the applied 3D MSAA mode for this viewport.
- `get_render_target() -> RID` *const* — Returns the render target associated with this buffers object.
- `get_scaling_3d_mode() -> int[RenderingServer.ViewportScaling3DMode]` *const* — Returns the scaling mode used for upscaling.
- `get_screen_space_aa() -> int[RenderingServer.ViewportScreenSpaceAA]` *const* — Returns the screen-space antialiasing method applied.
- `get_target_size() -> Vector2i` *const* — Returns the target size of the render buffer (size after upscaling).
- `get_texture(context: StringName, name: StringName) -> RID` *const* — Returns a cached texture with this name.
- `get_texture_format(context: StringName, name: StringName) -> RDTextureFormat` *const* — Returns the texture format information with which a cached texture was created.
- `get_texture_samples() -> int[RenderingDevice.TextureSamples]` *const* — Returns the number of MSAA samples used.
- `get_texture_slice(context: StringName, name: StringName, layer: int, mipmap: int, layers: int, mipmaps: int) -> RID` — Returns a specific slice (layer or mipmap) for a cached texture.
- `get_texture_slice_size(context: StringName, name: StringName, mipmap: int) -> Vector2i` — Returns the texture size of a given slice of a cached texture.
- `get_texture_slice_view(context: StringName, name: StringName, layer: int, mipmap: int, layers: int, mipmaps: int, view: RDTextureView) -> RID` — Returns a specific view of a slice (layer or mipmap) for a cached texture.
- `get_use_debanding() -> bool` *const* — Returns `true` if debanding is enabled.
- `get_use_taa() -> bool` *const* — Returns `true` if TAA is enabled.
- `get_velocity_layer(layer: int, msaa: bool = false) -> RID` — Returns the specified layer from the velocity texture we are rendering 3D content to.
- `get_velocity_texture(msaa: bool = false) -> RID` — Returns the velocity texture we are rendering 3D content to.
- `get_view_count() -> int` *const* — Returns the view count for the associated viewport.
- `has_texture(context: StringName, name: StringName) -> bool` *const* — Returns `true` if a cached texture exists for this name.
