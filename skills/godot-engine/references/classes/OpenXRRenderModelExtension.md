# OpenXRRenderModelExtension

**Inherits:** OpenXRExtensionWrapper

This class implements the OpenXR Render Model Extension.

This class implements the OpenXR Render Model Extension, if enabled it will maintain a list of active render models and provides an interface to the render model data.

## Methods

- `is_active() -> bool` *const* — Returns `true` if OpenXR's render model extension is supported and enabled.
- `render_model_create(render_model_id: int) -> RID` — Creates a render model object within OpenXR using a render model id.
- `render_model_destroy(render_model: RID) -> void` — Destroys a render model object within OpenXR that was previously created with `render_model_create`.
- `render_model_get_all() -> RID[]` — Returns an array of all currently active render models registered with this extension.
- `render_model_get_animatable_node_count(render_model: RID) -> int` *const* — Returns the number of animatable nodes this render model has.
- `render_model_get_animatable_node_name(render_model: RID, index: int) -> String` *const* — Returns the name of the given animatable node.
- `render_model_get_animatable_node_transform(render_model: RID, index: int) -> Transform3D` *const* — Returns the current local transform for an animatable node.
- `render_model_get_confidence(render_model: RID) -> int[XRPose.TrackingConfidence]` *const* — Returns the tracking confidence of the tracking data for the render model.
- `render_model_get_root_transform(render_model: RID) -> Transform3D` *const* — Returns the root transform of a render model.
- `render_model_get_subaction_paths(render_model: RID) -> PackedStringArray` — Returns a list of active subaction paths for this `render_model`.
- `render_model_get_top_level_path(render_model: RID) -> String` *const* — Returns the top level path associated with this `render_model`.
- `render_model_is_animatable_node_visible(render_model: RID, index: int) -> bool` *const* — Returns `true` if this animatable node should be visible.
- `render_model_new_scene_instance(render_model: RID) -> Node3D` *const* — Returns an instance of a subscene that contains all MeshInstance3D nodes that allow you to visualize the render model.

## Signals

- `render_model_added(render_model: RID)` — Emitted when a new render model is added.
- `render_model_removed(render_model: RID)` — Emitted when a render model is removed.
- `render_model_top_level_path_changed(render_model: RID)` — Emitted when the top level path associated with a render model changed.
