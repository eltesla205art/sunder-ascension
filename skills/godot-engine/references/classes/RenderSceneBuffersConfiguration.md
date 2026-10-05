# RenderSceneBuffersConfiguration

**Inherits:** RefCounted

Configuration object used to setup a RenderSceneBuffers object.

This configuration object is created and populated by the render engine on a viewport change and used to (re)configure a RenderSceneBuffers object.

## Properties

- `anisotropic_filtering_level: RenderingServer.ViewportAnisotropicFiltering` = `2` — Level of the anisotropic filter.
- `fsr_sharpness: float` = `0.0` — FSR Sharpness applicable if FSR upscaling is used.
- `internal_size: Vector2i` = `Vector2i(0, 0)` — The size of the 3D render buffer used for rendering.
- `msaa_3d: RenderingServer.ViewportMSAA` = `0` — The MSAA mode we're using for 3D rendering.
- `render_target: RID` = `RID()` — The render target associated with these buffer.
- `scaling_3d_mode: RenderingServer.ViewportScaling3DMode` = `255` — The requested scaling mode with which we upscale/downscale if `internal_size` and `target_size` are not equal.
- `screen_space_aa: RenderingServer.ViewportScreenSpaceAA` = `0` — The requested screen space AA applied in post processing.
- `target_size: Vector2i` = `Vector2i(0, 0)` — The target (upscale) size if scaling is used.
- `texture_mipmap_bias: float` = `0.0` — Bias applied to mipmaps.
- `view_count: int` = `1` — The number of views we're rendering.
