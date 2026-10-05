# RenderSceneData

**Inherits:** Object

Abstract render data object, holds scene data related to rendering a single frame of a viewport.

Abstract scene data object, exists for the duration of rendering a single viewport. See also RenderSceneDataRD, RenderData, and RenderDataRD. Note: This is an internal rendering server object. Do not instantiate this class from a script.

## Methods

- `get_cam_projection() -> Projection` *const* — Returns the camera projection used to render this frame.
- `get_cam_transform() -> Transform3D` *const* — Returns the camera transform used to render this frame.
- `get_uniform_buffer() -> RID` *const* — Return the RID of the uniform buffer containing the scene data as a UBO.
- `get_view_count() -> int` *const* — Returns the number of views being rendered.
- `get_view_eye_offset(view: int) -> Vector3` *const* — Returns the eye offset per view used to render this frame.
- `get_view_projection(view: int) -> Projection` *const* — Returns the view projection per view used to render this frame.
