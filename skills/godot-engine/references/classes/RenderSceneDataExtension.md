# RenderSceneDataExtension

**Inherits:** RenderSceneData

This class allows for a RenderSceneData implementation to be made in GDExtension.

This class allows for a RenderSceneData implementation to be made in GDExtension.

## Methods

- `_get_cam_projection() -> Projection` *virtual const* — Implement this in GDExtension to return the camera Projection.
- `_get_cam_transform() -> Transform3D` *virtual const* — Implement this in GDExtension to return the camera Transform3D.
- `_get_uniform_buffer() -> RID` *virtual const* — Implement this in GDExtension to return the RID of the uniform buffer containing the scene data as a UBO.
- `_get_view_count() -> int` *virtual const* — Implement this in GDExtension to return the view count.
- `_get_view_eye_offset(view: int) -> Vector3` *virtual const* — Implement this in GDExtension to return the eye offset for the given `view`.
- `_get_view_projection(view: int) -> Projection` *virtual const* — Implement this in GDExtension to return the view Projection for the given `view`.
