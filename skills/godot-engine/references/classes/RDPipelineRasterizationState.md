# RDPipelineRasterizationState

**Inherits:** RefCounted

Pipeline rasterization state (used by RenderingDevice).

This object is used by RenderingDevice.

## Properties

- `cull_mode: RenderingDevice.PolygonCullMode` = `0` — The cull mode to use when drawing polygons, which determines whether front faces or backfaces are hidden.
- `depth_bias_clamp: float` = `0.0` — A limit for how much each depth value can be offset.
- `depth_bias_constant_factor: float` = `0.0` — A constant offset added to each depth value.
- `depth_bias_enabled: bool` = `false` — If `true`, each generated depth value will by offset by some amount.
- `depth_bias_slope_factor: float` = `0.0` — A constant scale applied to the slope of each polygon's depth.
- `discard_primitives: bool` = `false` — If `true`, primitives are discarded immediately before the rasterization stage.
- `enable_depth_clamp: bool` = `false` — If `true`, clamps depth values according to the minimum and maximum depth of the associated viewport.
- `front_face: RenderingDevice.PolygonFrontFace` = `0` — The winding order to use to determine which face of a triangle is considered its front face.
- `line_width: float` = `1.0` — The line width to use when drawing lines (in pixels).
- `patch_control_points: int` = `1` — The number of control points to use when drawing a patch with tessellation enabled.
- `wireframe: bool` = `false` — If `true`, performs wireframe rendering for triangles instead of flat or textured rendering.
