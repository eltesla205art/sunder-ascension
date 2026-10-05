# VisualInstance3D

**Inherits:** Node3D

Parent of all visual 3D nodes.

The VisualInstance3D is used to connect a resource to a visual representation. All visual 3D nodes inherit from the VisualInstance3D. In general, you should not access the VisualInstance3D properties directly as they are accessed and managed by the nodes that inherit from VisualInstance3D. VisualInstance3D is the node representation of the RenderingServer instance.

## Properties

- `layers: int` = `1` — The render layer(s) this VisualInstance3D is drawn on.
- `sorting_offset: float` = `0.0` — The amount by which the depth of this VisualInstance3D will be adjusted when sorting by depth.
- `sorting_use_aabb_center: bool` — If `true`, the object is sorted based on the AABB center.

## Methods

- `_get_aabb() -> AABB` *virtual const*
- `get_aabb() -> AABB` *const* — Returns the AABB (also known as the bounding box) for this VisualInstance3D.
- `get_base() -> RID` *const* — Returns the RID of the resource associated with this VisualInstance3D.
- `get_instance() -> RID` *const* — Returns the RID of this instance.
- `get_layer_mask_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `layers` is enabled, given a `layer_number` between 1 and 20.
- `set_base(base: RID) -> void` — Sets the resource that is instantiated by this VisualInstance3D, which changes how the engine handles the VisualInstance3D under the hood.
- `set_layer_mask_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `layers`, given a `layer_number` between 1 and 20.
