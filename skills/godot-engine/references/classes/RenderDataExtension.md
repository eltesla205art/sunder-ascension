# RenderDataExtension

**Inherits:** RenderData

This class allows for a RenderData implementation to be made in GDExtension.

This class allows for a RenderData implementation to be made in GDExtension.

## Methods

- `_get_camera_attributes() -> RID` *virtual const* — Implement this in GDExtension to return the RID for the implementation's camera attributes object.
- `_get_environment() -> RID` *virtual const* — Implement this in GDExtension to return the RID of the implementation's environment object.
- `_get_render_scene_buffers() -> RenderSceneBuffers` *virtual const* — Implement this in GDExtension to return the implementation's RenderSceneBuffers object.
- `_get_render_scene_data() -> RenderSceneData` *virtual const* — Implement this in GDExtension to return the implementation's RenderSceneDataExtension object.
