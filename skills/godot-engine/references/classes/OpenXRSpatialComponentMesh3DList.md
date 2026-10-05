# OpenXRSpatialComponentMesh3DList

**Inherits:** OpenXRSpatialComponentData

Object for storing the queries mesh3d result data.

Object for storing the queries 3d mesh result data when calling `OpenXRSpatialEntityExtension.query_snapshot`.

## Methods

- `get_mesh(index: int) -> Mesh` *const* — Returns the mesh for the entity at this `index`.
- `get_transform(index: int) -> Transform3D` *const* — Returns the transform for positioning our mesh for the entity at this `index`.
