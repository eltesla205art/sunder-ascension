# OpenXRSpatialComponentPolygon2DList

**Inherits:** OpenXRSpatialComponentData

Object for storing the queries polygon2d result data.

Object for storing the queries 2D polygon result data when calling `OpenXRSpatialEntityExtension.query_snapshot`.

## Methods

- `get_transform(index: int) -> Transform3D` *const* — Returns the transform for positioning our polygon for the entity at this `index`.
- `get_vertices(snapshot: RID, index: int) -> PackedVector2Array` *const* — Returns the polygon vertices for the entity at this `index`.
