# OpenXRSpatialComponentBounded2DList

**Inherits:** OpenXRSpatialComponentData

Object for storing the queries bounded2d result data.

Object for storing the queries 2D bounding rectangle result data when calling `OpenXRSpatialEntityExtension.query_snapshot`.

## Methods

- `get_center_pose(index: int) -> Transform3D` *const* — Returns the center of our bounding rectangle for the entity at this `index`.
- `get_size(index: int) -> Vector2` *const* — Returns the size of our bounding rectangle for the entity at this `index`.
