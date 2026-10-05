# PhysicsIntersectShapeResult2D

**Inherits:** RefCounted

Stores the results of a shape intersection query.

This class contains the intersection information produced by `PhysicsDirectSpaceState2D.intersect_shape_into`. It can store multiple intersections, up to a user-defined maximum.

## Properties

- `max_intersections: int` = `32` — The maximum number of intersections this result object can store.

## Methods

- `get_collider(intersection_index: int) -> Object` *const* — The colliding object.
- `get_collider_id(intersection_index: int) -> int` *const* — The colliding object's ID.
- `get_collider_rid(intersection_index: int) -> RID` *const* — The intersecting object's RID.
- `get_collider_shape(intersection_index: int) -> int` *const* — The shape index of the colliding shape.
- `get_intersection_count() -> int` *const* — Returns the number of shapes that intersect with the query shape.
