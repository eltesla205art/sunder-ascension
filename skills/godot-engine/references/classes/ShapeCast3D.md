# ShapeCast3D

**Inherits:** Node3D

A 3D shape that sweeps a region of space to detect CollisionObject3Ds.

Shape casting allows to detect collision objects by sweeping its `shape` along the cast direction determined by `target_position`. This is similar to RayCast3D, but it allows for sweeping a region of space, rather than just a straight line. ShapeCast3D can detect multiple collision objects. It is useful for things like wide laser beams or snapping a simple shape to a floor.

## Properties

- `collide_with_areas: bool` = `false` — If `true`, collisions with Area3Ds will be reported.
- `collide_with_bodies: bool` = `true` — If `true`, collisions with PhysicsBody3Ds will be reported.
- `collision_mask: int` = `1` — The shape's collision mask.
- `collision_result: Array` = `[]` — Returns the complete collision information from the collision sweep.
- `debug_shape_custom_color: Color` = `Color(0, 0, 0, 1)` — The custom color to use to draw the shape in the editor and at run-time if Visible Collision Shapes is enabled in the Debug menu.
- `enabled: bool` = `true` — If `true`, collisions will be reported.
- `exclude_parent: bool` = `true` — If `true`, the parent node will be excluded from collision detection.
- `margin: float` = `0.0` — The collision margin for the shape.
- `max_results: int` = `32` — The number of intersections can be limited with this parameter, to reduce the processing time.
- `shape: Shape3D` — The shape to be used for collision queries.
- `target_position: Vector3` = `Vector3(0, -1, 0)` — The shape's destination point, relative to this node's `Node3D.position`.

## Methods

- `add_exception(node: CollisionObject3D) -> void` — Adds a collision exception so the shape does not report collisions with the specified node.
- `add_exception_rid(rid: RID) -> void` — Adds a collision exception so the shape does not report collisions with the specified RID.
- `clear_exceptions() -> void` — Removes all collision exceptions for this shape.
- `force_shapecast_update() -> void` — Updates the collision information for the shape immediately, without waiting for the next `_physics_process` call.
- `get_closest_collision_safe_fraction() -> float` *const* — Returns the fraction from this cast's origin to its `target_position` of how far the shape can move without triggering a collision, as a value between `0.0` and `1.0`.
- `get_closest_collision_unsafe_fraction() -> float` *const* — Returns the fraction from this cast's origin to its `target_position` of how far the shape must move to trigger a collision, as a value between `0.0` and `1.0`.
- `get_collider(index: int) -> Object` *const* — Returns the collided Object of one of the multiple collisions at `index`, or `null` if no object is intersecting the shape (i.e.
- `get_collider_rid(index: int) -> RID` *const* — Returns the RID of the collided object of one of the multiple collisions at `index`.
- `get_collider_shape(index: int) -> int` *const* — Returns the shape ID of the colliding shape of one of the multiple collisions at `index`, or `0` if no object is intersecting the shape (i.e.
- `get_collision_count() -> int` *const* — The number of collisions detected at the point of impact.
- `get_collision_mask_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `collision_mask` is enabled, given a `layer_number` between 1 and 32.
- `get_collision_normal(index: int) -> Vector3` *const* — Returns the normal of one of the multiple collisions at `index` of the intersecting object.
- `get_collision_point(index: int) -> Vector3` *const* — Returns the collision point of one of the multiple collisions at `index` where the shape intersects the colliding object.
- `is_colliding() -> bool` *const* — Returns whether any object is intersecting with the shape's vector (considering the vector length).
- `remove_exception(node: CollisionObject3D) -> void` — Removes a collision exception so the shape does report collisions with the specified node.
- `remove_exception_rid(rid: RID) -> void` — Removes a collision exception so the shape does report collisions with the specified RID.
- `resource_changed(resource: Resource) -> void` *(deprecated)* — This method does nothing.
- `set_collision_mask_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `collision_mask`, given a `layer_number` between 1 and 32.
