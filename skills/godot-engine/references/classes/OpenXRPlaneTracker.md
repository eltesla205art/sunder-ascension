# OpenXRPlaneTracker

**Inherits:** OpenXRSpatialEntityTracker

Spatial entity tracker for our spatial entity plane tracking extension.

Spatial entity tracker for our OpenXR spatial entity plane tracking extension. These trackers identify entities in our real space such as walls, floors, tables, etc. and map their location to our virtual space.

## Properties

- `bounds_size: Vector2` = `Vector2(0, 0)` — The bounding size of the plane.
- `plane_alignment: OpenXRSpatialComponentPlaneAlignmentList.PlaneAlignment` = `0` — The main alignment in space of this plane.
- `plane_label: String` = `""` — The semantic label for this plane.

## Methods

- `clear_mesh_data() -> void` — Clears the mesh data for this tracker.
- `get_indices() -> PackedInt32Array` *const* — Gets the index data for the mesh.
- `get_mesh() -> Mesh` — Gets a mesh created from either the mesh data or from our bounding size for this plane.
- `get_mesh_offset() -> Transform3D` *const* — Gets the transform by which to offset the mesh and collision shape from our pose to display these correctly.
- `get_shape(thickness: float = 0.01) -> Shape3D` — Gets a collision shape built either from the mesh data or from our bounding size for this plane.
- `get_vertices() -> PackedVector2Array` *const* — Gets the vertex data for the mesh.
- `set_mesh_data(origin: Transform3D, vertices: PackedVector2Array, indices: PackedInt32Array = PackedInt32Array()) -> void` — Sets the mesh data for this plane.

## Signals

- `mesh_changed()` — Emitted when our mesh data has changed the mesh instance and collision needs to be updated.
