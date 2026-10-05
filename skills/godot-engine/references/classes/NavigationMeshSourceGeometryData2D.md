# NavigationMeshSourceGeometryData2D

**Inherits:** Resource

Container for parsed source geometry data used in navigation mesh baking.

Container for parsed source geometry data used in navigation mesh baking.

## Methods

- `add_obstruction_outline(shape_outline: PackedVector2Array) -> void` — Adds the outline points of a shape as obstructed area.
- `add_projected_obstruction(vertices: PackedVector2Array, carve: bool) -> void` — Adds a projected obstruction shape to the source geometry.
- `add_traversable_outline(shape_outline: PackedVector2Array) -> void` — Adds the outline points of a shape as traversable area.
- `append_obstruction_outlines(obstruction_outlines: PackedVector2Array[]) -> void` — Appends another array of `obstruction_outlines` at the end of the existing obstruction outlines array.
- `append_traversable_outlines(traversable_outlines: PackedVector2Array[]) -> void` — Appends another array of `traversable_outlines` at the end of the existing traversable outlines array.
- `clear() -> void` — Clears the internal data.
- `clear_projected_obstructions() -> void` — Clears all projected obstructions.
- `get_bounds() -> Rect2` — Returns an axis-aligned bounding box that covers all the stored geometry data.
- `get_obstruction_outlines() -> PackedVector2Array[]` *const* — Returns all the obstructed area outlines arrays.
- `get_projected_obstructions() -> Array` *const* — Returns the projected obstructions as an Array of dictionaries.
- `get_traversable_outlines() -> PackedVector2Array[]` *const* — Returns all the traversable area outlines arrays.
- `has_data() -> bool` — Returns `true` when parsed source geometry data exists.
- `merge(other_geometry: NavigationMeshSourceGeometryData2D) -> void` — Adds the geometry data of another NavigationMeshSourceGeometryData2D to the navigation mesh baking data.
- `set_obstruction_outlines(obstruction_outlines: PackedVector2Array[]) -> void` — Sets all the obstructed area outlines arrays.
- `set_projected_obstructions(projected_obstructions: Array) -> void` — Sets the projected obstructions with an Array of Dictionaries with the following key value pairs:
- `set_traversable_outlines(traversable_outlines: PackedVector2Array[]) -> void` — Sets all the traversable area outlines arrays.
