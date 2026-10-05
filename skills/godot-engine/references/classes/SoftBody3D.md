# SoftBody3D

**Inherits:** MeshInstance3D

A deformable 3D physics mesh.

A deformable 3D physics mesh. Used to create elastic or deformable objects such as cloth, rubber, or other flexible materials. Additionally, SoftBody3D is subject to wind forces defined in Area3D (see `Area3D.wind_source_path`, `Area3D.wind_force_magnitude`, and `Area3D.wind_attenuation_factor`). Note: It's recommended to use Jolt Physics when using SoftBody3D instead of GodotPhysics3D, as Jolt Physics' soft body implementation is faster and more reliable.

## Properties

- `collision_layer: int` = `1` — The physics layers this SoftBody3D is in.
- `collision_mask: int` = `1` — The physics layers this SoftBody3D scans.
- `damping_coefficient: float` = `0.01` — The body's damping coefficient.
- `disable_mode: SoftBody3D.DisableMode` = `0` — Defines the behavior in physics when `Node.process_mode` is set to `Node.PROCESS_MODE_DISABLED`.
- `drag_coefficient: float` = `0.0` — The body's drag coefficient.
- `linear_stiffness: float` = `0.5` — Higher values will result in a stiffer body, while lower values will increase the body's ability to bend.
- `parent_collision_ignore: NodePath` = `NodePath("")` — NodePath to a CollisionObject3D this SoftBody3D should avoid clipping.
- `point_count: int` — The number of vertices (points) on the soft body mesh.
- `pressure_coefficient: float` = `0.0` — The pressure coefficient of this soft body.
- `ray_pickable: bool` = `true` — If `true`, the SoftBody3D will respond to RayCast3Ds.
- `shrinking_factor: float` = `0.0` — Scales the rest lengths of SoftBody3D's edge constraints.
- `simulation_precision: int` = `5` — Increasing this value will improve the resulting simulation, but can affect performance.
- `total_mass: float` = `1.0` — The SoftBody3D's mass.

## Methods

- `add_collision_exception_with(body: Node) -> void` — Adds a body to the list of bodies that this body can't collide with.
- `apply_central_force(force: Vector3) -> void` — Distributes and applies a force to all points.
- `apply_central_impulse(impulse: Vector3) -> void` — Distributes and applies an impulse to all points.
- `apply_force(point_index: int, force: Vector3) -> void` — Applies a force to a point.
- `apply_impulse(point_index: int, impulse: Vector3) -> void` — Applies an impulse to a point.
- `get_collision_exceptions() -> PhysicsBody3D[]` — Returns an array of nodes that were added as collision exceptions for this body.
- `get_collision_layer_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `collision_layer` is enabled, given a `layer_number` between 1 and 32.
- `get_collision_mask_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `collision_mask` is enabled, given a `layer_number` between 1 and 32.
- `get_physics_rid() -> RID` *const* — Returns the internal RID used by the PhysicsServer3D for this body.
- `get_point_transform(point_index: int) -> Vector3` — Returns local translation of a vertex in the surface array.
- `is_point_pinned(point_index: int) -> bool` *const* — Returns `true` if vertex is set to pinned.
- `remove_collision_exception_with(body: Node) -> void` — Removes a body from the list of bodies that this body can't collide with.
- `set_collision_layer_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `collision_layer`, given a `layer_number` between 1 and 32.
- `set_collision_mask_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `collision_mask`, given a `layer_number` between 1 and 32.
- `set_point_pinned(point_index: int, pinned: bool, attachment_path: NodePath = NodePath(""), insert_at: int = -1) -> void` — Sets the pinned state of a surface vertex.

## Enum DisableMode

- `DISABLE_MODE_REMOVE = 0` — When `Node.process_mode` is set to `Node.PROCESS_MODE_DISABLED`, remove from the physics simulation to stop all physics interactions with this SoftBody3D.
- `DISABLE_MODE_KEEP_ACTIVE = 1` — When `Node.process_mode` is set to `Node.PROCESS_MODE_DISABLED`, do not affect the physics simulation.
