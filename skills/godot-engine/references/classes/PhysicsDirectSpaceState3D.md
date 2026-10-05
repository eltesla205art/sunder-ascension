# PhysicsDirectSpaceState3D

**Inherits:** Object

Provides direct access to a physics space in the PhysicsServer3D.

Provides direct access to a physics space in the PhysicsServer3D. It's used mainly to do queries against objects and areas residing in a given space. Note: This class is not meant to be instantiated directly. Use `World3D.direct_space_state` to get the world's physics 3D space state.

## Methods

- `cast_motion(parameters: PhysicsShapeQueryParameters3D) -> PackedFloat32Array` — Checks how far a Shape3D can move without colliding.
- `cast_motion_into(parameters: PhysicsShapeQueryParameters3D, result: PhysicsCastMotionResult3D) -> bool` — Checks how far a Shape3D can move without colliding.
- `collide_shape(parameters: PhysicsShapeQueryParameters3D, max_results: int = 32) -> Vector3[]` — Checks the intersections of a shape, given through a PhysicsShapeQueryParameters3D object, against the space.
- `collide_shape_into(parameters: PhysicsShapeQueryParameters3D, result: PhysicsCollideShapeResult3D) -> bool` — Checks the intersections of a shape, given through a PhysicsShapeQueryParameters3D object, against the space.
- `get_rest_info(parameters: PhysicsShapeQueryParameters3D) -> Dictionary` — Checks the intersections of a shape, given through a PhysicsShapeQueryParameters3D object, against the space.
- `get_rest_info_into(parameters: PhysicsShapeQueryParameters3D, result: PhysicsGetRestInfoResult3D) -> bool` — Checks the intersections of a shape, given through a PhysicsShapeQueryParameters3D object, against the space.
- `intersect_point(parameters: PhysicsPointQueryParameters3D, max_results: int = 32) -> Dictionary[]` — Checks whether a point is inside any solid shape.
- `intersect_point_into(parameters: PhysicsPointQueryParameters3D, result: PhysicsIntersectPointResult3D) -> bool` — Checks whether a point is inside any solid shape.
- `intersect_ray(parameters: PhysicsRayQueryParameters3D) -> Dictionary` — Intersects a ray in a given space.
- `intersect_ray_into(parameters: PhysicsRayQueryParameters3D, result: PhysicsIntersectRayResult3D) -> bool` — Intersects a ray in a given space.
- `intersect_shape(parameters: PhysicsShapeQueryParameters3D, max_results: int = 32) -> Dictionary[]` — Checks the intersections of a shape, given through a PhysicsShapeQueryParameters3D object, against the space.
- `intersect_shape_into(parameters: PhysicsShapeQueryParameters3D, result: PhysicsIntersectShapeResult3D) -> bool` — Checks the intersections of a shape, given through a PhysicsShapeQueryParameters3D object, against the space.
