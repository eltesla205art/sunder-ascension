# OpenXRSpatialComponentBounded3DList

**Inherits:** OpenXRSpatialComponentData

Object for storing the queries bounded3d result data.

Object for storing the queries 3d bounding box result data when calling `OpenXRSpatialEntityExtension.query_snapshot`.

## Methods

- `get_center_pose(index: int) -> Transform3D` *const* — Returns the center of our bounding box for the entity at this `index`.
- `get_size(index: int) -> Vector3` *const* — Returns the size of our bounding box for the entity at this `index`.
