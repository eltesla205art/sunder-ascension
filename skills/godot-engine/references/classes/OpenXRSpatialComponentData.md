# OpenXRSpatialComponentData

**Inherits:** RefCounted

Object for storing OpenXR spatial entity component data.

Object for storing OpenXR spatial entity component data.

## Methods

- `_get_component_type() -> int` *virtual const* — Return the component type for the component we store data for.
- `_get_structure_data(next: int) -> int` *virtual* — Return a pointer to the structure data that will be submitted along with the snapshot query.
- `_set_capacity(capacity: int) -> void` *virtual* — Sets the expected capacity as provided by the spatial entities query system.
- `get_component_type() -> int` *const* — Gets this OpenXRSpatialComponentData's `XrSpatialComponentTypeEXT`.
- `set_capacity(capacity: int) -> void` — Sets the expected capacity as provided by the spatial entities query system.
