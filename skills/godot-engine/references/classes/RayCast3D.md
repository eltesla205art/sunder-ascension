# RayCast3D

**Inherits:** Node3D

A ray in 3D space, used to find the first collision object it intersects.

A raycast represents a ray from its origin to its `target_position` that finds the closest object along its path, if it intersects any. RayCast3D can ignore some objects by adding them to an exception list, by making its detection reporting ignore Area3Ds (`collide_with_areas`) or PhysicsBody3Ds (`collide_with_bodies`), or by configuring physics layers. RayCast3D calculates intersection every physics frame, and it holds the result until the next physics frame. For an immediate raycast, or if you want to configure a RayCast3D multiple times within the same physics frame, use `force_raycast_update`.

## Properties

- `collide_with_areas: bool` = `false` — If `true`, collisions with Area3Ds will be reported.
- `collide_with_bodies: bool` = `true` — If `true`, collisions with PhysicsBody3Ds will be reported.
- `collision_mask: int` = `1` — The ray's collision mask.
- `debug_shape_custom_color: Color` = `Color(0, 0, 0, 1)` — The custom color to use to draw the shape in the editor and at run-time if Visible Collision Shapes is enabled in the Debug menu.
- `debug_shape_thickness: int` = `2` — If set to `1`, a line is used as the debug shape.
- `enabled: bool` = `true` — If `true`, collisions will be reported.
- `exclude_parent: bool` = `true` — If `true`, this raycast will not report collisions with its parent node.
- `hit_back_faces: bool` = `true` — If `true`, the ray will hit back faces with concave polygon shapes with back face enabled or heightmap shapes.
- `hit_from_inside: bool` = `false` — If `true`, the ray will detect a hit when starting inside shapes.
- `target_position: Vector3` = `Vector3(0, -1, 0)` — The ray's destination point, relative to this raycast's `Node3D.position`.

## Methods

- `add_exception(node: CollisionObject3D) -> void` — Adds a collision exception so the ray does not report collisions with the specified `node`.
- `add_exception_rid(rid: RID) -> void` — Adds a collision exception so the ray does not report collisions with the specified RID.
- `clear_exceptions() -> void` — Removes all collision exceptions for this ray.
- `force_raycast_update() -> void` — Updates the collision information for the ray immediately, without waiting for the next `_physics_process` call.
- `get_collider() -> Object` *const* — Returns the first object that the ray intersects, or `null` if no object is intersecting the ray (i.e.
- `get_collider_rid() -> RID` *const* — Returns the RID of the first object that the ray intersects, or an empty RID if no object is intersecting the ray (i.e.
- `get_collider_shape() -> int` *const* — Returns the shape ID of the first object that the ray intersects, or `0` if no object is intersecting the ray (i.e.
- `get_collision_face_index() -> int` *const* — Returns the collision object's face index at the collision point, or `-1` if the shape intersecting the ray is not a ConcavePolygonShape3D.
- `get_collision_mask_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `collision_mask` is enabled, given a `layer_number` between 1 and 32.
- `get_collision_normal() -> Vector3` *const* — Returns the normal of the intersecting object's shape at the collision point, or `Vector3(0, 0, 0)` if the ray starts inside the shape and `hit_from_inside` is `true`.
- `get_collision_point() -> Vector3` *const* — Returns the collision point at which the ray intersects the closest object, in the global coordinate system.
- `is_colliding() -> bool` *const* — Returns whether any object is intersecting with the ray's vector (considering the vector length).
- `remove_exception(node: CollisionObject3D) -> void` — Removes a collision exception so the ray can report collisions with the specified `node`.
- `remove_exception_rid(rid: RID) -> void` — Removes a collision exception so the ray can report collisions with the specified RID.
- `set_collision_mask_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `collision_mask`, given a `layer_number` between 1 and 32.
