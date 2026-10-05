# PhysicsDirectSpaceState2D

**Inherits:** Object

Provides direct access to a physics space in the PhysicsServer2D.

Provides direct access to a physics space in the PhysicsServer2D. It's used mainly to do queries against objects and areas residing in a given space. Note: This class is not meant to be instantiated directly. Use `World2D.direct_space_state` to get the world's physics 2D space state.

## Methods

- `cast_motion(parameters: PhysicsShapeQueryParameters2D) -> PackedFloat32Array` — Checks how far a Shape2D can move without colliding.
- `cast_motion_into(parameters: PhysicsShapeQueryParameters2D, result: PhysicsCastMotionResult2D) -> bool` — Checks how far a Shape2D can move without colliding.
- `collide_shape(parameters: PhysicsShapeQueryParameters2D, max_results: int = 32) -> Vector2[]` — Checks the intersections of a shape, given through a PhysicsShapeQueryParameters2D object, against the space.
- `collide_shape_into(parameters: PhysicsShapeQueryParameters2D, result: PhysicsCollideShapeResult2D) -> bool` — Checks the intersections of a shape, given through a PhysicsShapeQueryParameters2D object, against the space.
- `get_rest_info(parameters: PhysicsShapeQueryParameters2D) -> Dictionary` — Checks the intersections of a shape, given through a PhysicsShapeQueryParameters2D object, against the space.
- `get_rest_info_into(parameters: PhysicsShapeQueryParameters2D, result: PhysicsGetRestInfoResult2D) -> bool` — Checks the intersections of a shape, given through a PhysicsShapeQueryParameters2D object, against the space.
- `intersect_point(parameters: PhysicsPointQueryParameters2D, max_results: int = 32) -> Dictionary[]` — Checks whether a point is inside any solid shape.
- `intersect_point_into(parameters: PhysicsPointQueryParameters2D, result: PhysicsIntersectPointResult2D) -> bool` — Checks whether a point is inside any solid shape.
- `intersect_ray(parameters: PhysicsRayQueryParameters2D) -> Dictionary` — Intersects a ray in a given space.
- `intersect_ray_into(parameters: PhysicsRayQueryParameters2D, result: PhysicsIntersectRayResult2D) -> bool` — Intersects a ray in a given space.
- `intersect_shape(parameters: PhysicsShapeQueryParameters2D, max_results: int = 32) -> Dictionary[]` — Checks the intersections of a shape, given through a PhysicsShapeQueryParameters2D object, against the space.
- `intersect_shape_into(parameters: PhysicsShapeQueryParameters2D, result: PhysicsIntersectShapeResult2D) -> bool` — Checks the intersections of a shape, given through a PhysicsShapeQueryParameters2D object, against the space.
