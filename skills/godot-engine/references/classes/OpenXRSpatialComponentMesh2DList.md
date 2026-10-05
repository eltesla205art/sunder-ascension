# OpenXRSpatialComponentMesh2DList

**Inherits:** OpenXRSpatialComponentData

Object for storing the queries mesh2d result data.

Object for storing the queries 2D mesh result data when calling `OpenXRSpatialEntityExtension.query_snapshot`.

## Methods

- `get_indices(snapshot: RID, index: int) -> PackedInt32Array` *const* — Returns the mesh indices for the entity at this `index`.
- `get_transform(index: int) -> Transform3D` *const* — Returns the transform for positioning our mesh for the entity at this `index`.
- `get_vertices(snapshot: RID, index: int) -> PackedVector2Array` *const* — Returns the mesh vertices for the entity at this `index`.
