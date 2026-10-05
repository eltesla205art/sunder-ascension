# PhysicsServer3D

**Inherits:** Object

A server interface for low-level 3D physics access.

PhysicsServer3D is the server responsible for all 3D physics. It can directly create and manipulate all physics objects: - A space is a self-contained world for a physics simulation. It contains bodies, areas, and joints. Its state can be queried for collision and intersection information, and several parameters of the simulation can be modified. - A shape is a geometric shape such as a sphere, a box, a cylinder, or a polygon.

## Methods

- `area_add_shape(area: RID, shape: RID, transform: Transform3D = Transform3D(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0), disabled: bool = false) -> void` — Adds a shape to the area, along with a transform matrix.
- `area_attach_object_instance_id(area: RID, id: int) -> void` — Assigns the area to a descendant of Object, so it can exist in the node tree.
- `area_clear_shapes(area: RID) -> void` — Removes all shapes from an area.
- `area_create() -> RID` — Creates a 3D area object in the physics server, and returns the RID that identifies it.
- `area_get_collision_layer(area: RID) -> int` *const* — Returns the physics layer or layers an area belongs to.
- `area_get_collision_mask(area: RID) -> int` *const* — Returns the physics layer or layers an area can contact with.
- `area_get_object_instance_id(area: RID) -> int` *const* — Gets the instance ID of the object the area is assigned to.
- `area_get_param(area: RID, param: PhysicsServer3D.AreaParameter) -> Variant` *const* — Returns an area parameter value.
- `area_get_shape(area: RID, shape_idx: int) -> RID` *const* — Returns the RID of the nth shape of an area.
- `area_get_shape_count(area: RID) -> int` *const* — Returns the number of shapes assigned to an area.
- `area_get_shape_transform(area: RID, shape_idx: int) -> Transform3D` *const* — Returns the transform matrix of a shape within an area.
- `area_get_space(area: RID) -> RID` *const* — Returns the space assigned to the area.
- `area_get_transform(area: RID) -> Transform3D` *const* — Returns the transform matrix for an area.
- `area_remove_shape(area: RID, shape_idx: int) -> void` — Removes a shape from an area.
- `area_set_area_monitor_callback(area: RID, callback: Callable) -> void` — Sets the area's area monitor callback.
- `area_set_collision_layer(area: RID, layer: int) -> void` — Assigns the area to one or many physics layers.
- `area_set_collision_mask(area: RID, mask: int) -> void` — Sets which physics layers the area will monitor.
- `area_set_monitor_callback(area: RID, callback: Callable) -> void` — Sets the area's body monitor callback.
- `area_set_monitorable(area: RID, monitorable: bool) -> void`
- `area_set_param(area: RID, param: PhysicsServer3D.AreaParameter, value: Variant) -> void` — Sets the value for an area parameter.
- `area_set_ray_pickable(area: RID, enable: bool) -> void` — Sets object pickable with rays.
- `area_set_shape(area: RID, shape_idx: int, shape: RID) -> void` — Substitutes a given area shape by another.
- `area_set_shape_disabled(area: RID, shape_idx: int, disabled: bool) -> void`
- `area_set_shape_transform(area: RID, shape_idx: int, transform: Transform3D) -> void` — Sets the transform matrix for an area shape.
- `area_set_space(area: RID, space: RID) -> void` — Assigns a space to the area.
- `area_set_transform(area: RID, transform: Transform3D) -> void` — Sets the transform matrix for an area.
- `body_add_collision_exception(body: RID, excepted_body: RID) -> void` — Adds a body to the list of bodies exempt from collisions.
- `body_add_constant_central_force(body: RID, force: Vector3) -> void` — Adds a constant directional force without affecting rotation that keeps being applied over time until cleared with `body_set_constant_force(body, Vector3(0, 0, 0))`.
- `body_add_constant_force(body: RID, force: Vector3, position: Vector3 = Vector3(0, 0, 0)) -> void` — Adds a constant positioned force to the body that keeps being applied over time until cleared with `body_set_constant_force(body, Vector3(0, 0, 0))`.
- `body_add_constant_torque(body: RID, torque: Vector3) -> void` — Adds a constant rotational force without affecting position that keeps being applied over time until cleared with `body_set_constant_torque(body, Vector3(0, 0, 0))`.
- `body_add_shape(body: RID, shape: RID, transform: Transform3D = Transform3D(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0), disabled: bool = false) -> void` — Adds a shape to the body, along with a transform matrix.
- `body_apply_central_force(body: RID, force: Vector3) -> void` — Applies a directional force without affecting rotation.
- `body_apply_central_impulse(body: RID, impulse: Vector3) -> void` — Applies a directional impulse without affecting rotation.
- `body_apply_force(body: RID, force: Vector3, position: Vector3 = Vector3(0, 0, 0)) -> void` — Applies a positioned force to the body.
- `body_apply_impulse(body: RID, impulse: Vector3, position: Vector3 = Vector3(0, 0, 0)) -> void` — Applies a positioned impulse to the body.
- `body_apply_torque(body: RID, torque: Vector3) -> void` — Applies a rotational force without affecting position.
- `body_apply_torque_impulse(body: RID, impulse: Vector3) -> void` — Applies a rotational impulse to the body without affecting the position.
- `body_attach_object_instance_id(body: RID, id: int) -> void` — Assigns the area to a descendant of Object, so it can exist in the node tree.
- `body_clear_shapes(body: RID) -> void` — Removes all shapes from a body.
- `body_create() -> RID` — Creates a 3D body object in the physics server, and returns the RID that identifies it.
- `body_get_collision_layer(body: RID) -> int` *const* — Returns the physics layer or layers a body belongs to.
- `body_get_collision_mask(body: RID) -> int` *const* — Returns the physics layer or layers a body can collide with.
- `body_get_collision_priority(body: RID) -> float` *const* — Returns the body's collision priority.
- `body_get_constant_force(body: RID) -> Vector3` *const* — Returns the body's total constant positional forces applied during each physics update.
- `body_get_constant_torque(body: RID) -> Vector3` *const* — Returns the body's total constant rotational forces applied during each physics update.
- `body_get_direct_state(body: RID) -> PhysicsDirectBodyState3D` — Returns the PhysicsDirectBodyState3D of the body.
- `body_get_max_contacts_reported(body: RID) -> int` *const* — Returns the maximum contacts that can be reported.
- `body_get_mode(body: RID) -> int[PhysicsServer3D.BodyMode]` *const* — Returns the body mode.
- `body_get_object_instance_id(body: RID) -> int` *const* — Gets the instance ID of the object the area is assigned to.
- `body_get_param(body: RID, param: PhysicsServer3D.BodyParameter) -> Variant` *const* — Returns the value of a body parameter.
- `body_get_shape(body: RID, shape_idx: int) -> RID` *const* — Returns the RID of the nth shape of a body.
- `body_get_shape_count(body: RID) -> int` *const* — Returns the number of shapes assigned to a body.
- `body_get_shape_transform(body: RID, shape_idx: int) -> Transform3D` *const* — Returns the transform matrix of a body shape.
- `body_get_space(body: RID) -> RID` *const* — Returns the RID of the space assigned to a body.
- `body_get_state(body: RID, state: PhysicsServer3D.BodyState) -> Variant` *const* — Returns a body state.
- `body_is_axis_locked(body: RID, axis: PhysicsServer3D.BodyAxis) -> bool` *const*
- `body_is_continuous_collision_detection_enabled(body: RID) -> bool` *const* — If `true`, the continuous collision detection mode is enabled.
- `body_is_omitting_force_integration(body: RID) -> bool` *const* — Returns `true` if the body is omitting the standard force integration.
- `body_remove_collision_exception(body: RID, excepted_body: RID) -> void` — Removes a body from the list of bodies exempt from collisions.
- `body_remove_shape(body: RID, shape_idx: int) -> void` — Removes a shape from a body.
- `body_reset_mass_properties(body: RID) -> void` — Restores the default inertia and center of mass based on shapes to cancel any custom values previously set using `body_set_param`.
- `body_set_axis_lock(body: RID, axis: PhysicsServer3D.BodyAxis, lock: bool) -> void`
- `body_set_axis_velocity(body: RID, axis_velocity: Vector3) -> void` — Sets an axis velocity.
- `body_set_collision_layer(body: RID, layer: int) -> void` — Sets the physics layer or layers a body belongs to.
- `body_set_collision_mask(body: RID, mask: int) -> void` — Sets the physics layer or layers a body can collide with.
- `body_set_collision_priority(body: RID, priority: float) -> void` — Sets the body's collision priority.
- `body_set_constant_force(body: RID, force: Vector3) -> void` — Sets the body's total constant positional forces applied during each physics update.
- `body_set_constant_torque(body: RID, torque: Vector3) -> void` — Sets the body's total constant rotational forces applied during each physics update.
- `body_set_enable_continuous_collision_detection(body: RID, enable: bool) -> void` — If `true`, the continuous collision detection mode is enabled.
- `body_set_force_integration_callback(body: RID, callable: Callable, userdata: Variant = null) -> void` — Sets the body's custom force integration callback function to `callable`.
- `body_set_max_contacts_reported(body: RID, amount: int) -> void` — Sets the maximum contacts to report.
- `body_set_mode(body: RID, mode: PhysicsServer3D.BodyMode) -> void` — Sets the body mode.
- `body_set_omit_force_integration(body: RID, enable: bool) -> void` — Sets whether the body omits the standard force integration.
- `body_set_param(body: RID, param: PhysicsServer3D.BodyParameter, value: Variant) -> void` — Sets a body parameter.
- `body_set_ray_pickable(body: RID, enable: bool) -> void` — Sets the body pickable with rays if `enable` is set.
- `body_set_shape(body: RID, shape_idx: int, shape: RID) -> void` — Substitutes a given body shape by another.
- `body_set_shape_disabled(body: RID, shape_idx: int, disabled: bool) -> void`
- `body_set_shape_transform(body: RID, shape_idx: int, transform: Transform3D) -> void` — Sets the transform matrix for a body shape.
- `body_set_space(body: RID, space: RID) -> void` — Assigns a space to the body (see `space_create`).
- `body_set_state(body: RID, state: PhysicsServer3D.BodyState, value: Variant) -> void` — Sets a body state.
- `body_set_state_sync_callback(body: RID, callable: Callable) -> void` — Sets the body's state synchronization callback function to `callable`.
- `body_test_motion(body: RID, parameters: PhysicsTestMotionParameters3D, result: PhysicsTestMotionResult3D = null) -> bool` — Returns `true` if a collision would result from moving along a motion vector from a given point in space.
- `box_shape_create() -> RID` — Creates a 3D box shape in the physics server, and returns the RID that identifies it.
- `capsule_shape_create() -> RID` — Creates a 3D capsule shape in the physics server, and returns the RID that identifies it.
- `concave_polygon_shape_create() -> RID` — Creates a 3D concave polygon shape in the physics server, and returns the RID that identifies it.
- `cone_twist_joint_get_param(joint: RID, param: PhysicsServer3D.ConeTwistJointParam) -> float` *const* — Gets a cone twist joint parameter.
- `cone_twist_joint_set_param(joint: RID, param: PhysicsServer3D.ConeTwistJointParam, value: float) -> void` — Sets a cone twist joint parameter.
- `convex_polygon_shape_create() -> RID` — Creates a 3D convex polygon shape in the physics server, and returns the RID that identifies it.
- `custom_shape_create() -> RID` — Creates a custom shape in the physics server, and returns the RID that identifies it.
- `cylinder_shape_create() -> RID` — Creates a 3D cylinder shape in the physics server, and returns the RID that identifies it.
- `free_rid(rid: RID) -> void` — Destroys any of the objects created by PhysicsServer3D.
- `generic_6dof_joint_get_angular_target_rotation(joint: RID) -> Quaternion` *const* — Returns the target angular orientation of a generic 6DOF joint as a body-space quaternion describing the desired orientation of body B relative to body A.
- `generic_6dof_joint_get_flag(joint: RID, axis: Vector3.Axis, flag: PhysicsServer3D.G6DOFJointAxisFlag) -> bool` *const* — Returns the value of a generic 6DOF joint flag.
- `generic_6dof_joint_get_param(joint: RID, axis: Vector3.Axis, param: PhysicsServer3D.G6DOFJointAxisParam) -> float` *const* — Returns the value of a generic 6DOF joint parameter.
- `generic_6dof_joint_set_angular_target_rotation(joint: RID, target_rotation: Quaternion) -> void` — Sets the target angular orientation of a generic 6DOF joint as a body-space quaternion describing the desired orientation of body B relative to body A.
- `generic_6dof_joint_set_flag(joint: RID, axis: Vector3.Axis, flag: PhysicsServer3D.G6DOFJointAxisFlag, enable: bool) -> void` — Sets the value of a given generic 6DOF joint flag.
- `generic_6dof_joint_set_param(joint: RID, axis: Vector3.Axis, param: PhysicsServer3D.G6DOFJointAxisParam, value: float) -> void` — Sets the value of a given generic 6DOF joint parameter.
- `get_process_info(process_info: PhysicsServer3D.ProcessInfo) -> int` — Returns the value of a physics engine state specified by `process_info`.
- `heightmap_shape_create() -> RID` — Creates a 3D heightmap shape in the physics server, and returns the RID that identifies it.
- `hinge_joint_get_flag(joint: RID, flag: PhysicsServer3D.HingeJointFlag) -> bool` *const* — Gets a hinge joint flag.
- `hinge_joint_get_param(joint: RID, param: PhysicsServer3D.HingeJointParam) -> float` *const* — Gets a hinge joint parameter.
- `hinge_joint_set_flag(joint: RID, flag: PhysicsServer3D.HingeJointFlag, enabled: bool) -> void` — Sets a hinge joint flag.
- `hinge_joint_set_param(joint: RID, param: PhysicsServer3D.HingeJointParam, value: float) -> void` — Sets a hinge joint parameter.
- `joint_clear(joint: RID) -> void`
- `joint_create() -> RID`
- `joint_disable_collisions_between_bodies(joint: RID, disable: bool) -> void` — Sets whether the bodies attached to the Joint3D will collide with each other.
- `joint_get_solver_priority(joint: RID) -> int` *const* — Gets the priority value of the Joint3D.
- `joint_get_type(joint: RID) -> int[PhysicsServer3D.JointType]` *const* — Returns the type of the Joint3D.
- `joint_is_disabled_collisions_between_bodies(joint: RID) -> bool` *const* — Returns whether the bodies attached to the Joint3D will collide with each other.
- `joint_make_cone_twist(joint: RID, body_A: RID, local_ref_A: Transform3D, body_B: RID, local_ref_B: Transform3D) -> void`
- `joint_make_generic_6dof(joint: RID, body_A: RID, local_ref_A: Transform3D, body_B: RID, local_ref_B: Transform3D) -> void` — Make the joint a generic six degrees of freedom (6DOF) joint.
- `joint_make_hinge(joint: RID, body_A: RID, hinge_A: Transform3D, body_B: RID, hinge_B: Transform3D) -> void`
- `joint_make_pin(joint: RID, body_A: RID, local_A: Vector3, body_B: RID, local_B: Vector3) -> void`
- `joint_make_slider(joint: RID, body_A: RID, local_ref_A: Transform3D, body_B: RID, local_ref_B: Transform3D) -> void`
- `joint_set_solver_priority(joint: RID, priority: int) -> void` — Sets the priority value of the Joint3D.
- `pin_joint_get_local_a(joint: RID) -> Vector3` *const* — Returns position of the joint in the local space of body a of the joint.
- `pin_joint_get_local_b(joint: RID) -> Vector3` *const* — Returns position of the joint in the local space of body b of the joint.
- `pin_joint_get_param(joint: RID, param: PhysicsServer3D.PinJointParam) -> float` *const* — Gets a pin joint parameter.
- `pin_joint_set_local_a(joint: RID, local_A: Vector3) -> void` — Sets position of the joint in the local space of body a of the joint.
- `pin_joint_set_local_b(joint: RID, local_B: Vector3) -> void` — Sets position of the joint in the local space of body b of the joint.
- `pin_joint_set_param(joint: RID, param: PhysicsServer3D.PinJointParam, value: float) -> void` — Sets a pin joint parameter.
- `separation_ray_shape_create() -> RID` — Creates a 3D separation ray shape in the physics server, and returns the RID that identifies it.
- `set_active(active: bool) -> void` — Activates or deactivates the 3D physics engine.
- `shape_get_data(shape: RID) -> Variant` *const* — Returns the shape data that configures the shape, such as the half-extents of a box or the triangles of a concave (trimesh) shape.
- `shape_get_margin(shape: RID) -> float` *const* — Returns the collision margin for the shape.
- `shape_get_type(shape: RID) -> int[PhysicsServer3D.ShapeType]` *const* — Returns the shape's type.
- `shape_set_data(shape: RID, data: Variant) -> void` — Sets the shape data that configures the shape.
- `shape_set_margin(shape: RID, margin: float) -> void` — Sets the collision margin for the shape.
- `slider_joint_get_param(joint: RID, param: PhysicsServer3D.SliderJointParam) -> float` *const* — Gets a slider joint parameter.
- `slider_joint_set_param(joint: RID, param: PhysicsServer3D.SliderJointParam, value: float) -> void` — Gets a slider joint parameter.
- `soft_body_add_collision_exception(body: RID, body_b: RID) -> void` — Adds the given body to the list of bodies exempt from collisions.
- `soft_body_apply_central_force(body: RID, force: Vector3) -> void` — Distributes and applies a force to all points.
- `soft_body_apply_central_impulse(body: RID, impulse: Vector3) -> void` — Distributes and applies an impulse to all points.
- `soft_body_apply_point_force(body: RID, point_index: int, force: Vector3) -> void` — Applies a force to a point.
- `soft_body_apply_point_impulse(body: RID, point_index: int, impulse: Vector3) -> void` — Applies an impulse to a point.
- `soft_body_create() -> RID` — Creates a new soft body and returns its internal RID.
- `soft_body_get_bounds(body: RID) -> AABB` *const* — Returns the bounds of the given soft body in global coordinates.
- `soft_body_get_collision_layer(body: RID) -> int` *const* — Returns the physics layer or layers that the given soft body belongs to.
- `soft_body_get_collision_mask(body: RID) -> int` *const* — Returns the physics layer or layers that the given soft body can collide with.
- `soft_body_get_damping_coefficient(body: RID) -> float` *const* — Returns the damping coefficient of the given soft body.
- `soft_body_get_drag_coefficient(body: RID) -> float` *const* — Returns the drag coefficient of the given soft body.
- `soft_body_get_linear_stiffness(body: RID) -> float` *const* — Returns the linear stiffness of the given soft body.
- `soft_body_get_point_global_position(body: RID, point_index: int) -> Vector3` *const* — Returns the current position of the given soft body point in global coordinates.
- `soft_body_get_pressure_coefficient(body: RID) -> float` *const* — Returns the pressure coefficient of the given soft body.
- `soft_body_get_shrinking_factor(body: RID) -> float` *const* — Returns the shrinking factor of the given soft body.
- `soft_body_get_simulation_precision(body: RID) -> int` *const* — Returns the simulation precision of the given soft body.
- `soft_body_get_space(body: RID) -> RID` *const* — Returns the RID of the space assigned to the given soft body.
- `soft_body_get_state(body: RID, state: PhysicsServer3D.BodyState) -> Variant` *const* — Returns the given soft body state.
- `soft_body_get_total_mass(body: RID) -> float` *const* — Returns the total mass assigned to the given soft body.
- `soft_body_is_point_pinned(body: RID, point_index: int) -> bool` *const* — Returns whether the given soft body point is pinned.
- `soft_body_move_point(body: RID, point_index: int, global_position: Vector3) -> void` — Moves the given soft body point to a position in global coordinates.
- `soft_body_pin_point(body: RID, point_index: int, pin: bool) -> void` — Pins or unpins the given soft body point based on the value of `pin`.
- `soft_body_remove_all_pinned_points(body: RID) -> void` — Unpins all points of the given soft body.
- `soft_body_remove_collision_exception(body: RID, body_b: RID) -> void` — Removes the given body from the list of bodies exempt from collisions.
- `soft_body_set_collision_layer(body: RID, layer: int) -> void` — Sets the physics layer or layers the given soft body belongs to.
- `soft_body_set_collision_mask(body: RID, mask: int) -> void` — Sets the physics layer or layers the given soft body can collide with.
- `soft_body_set_damping_coefficient(body: RID, damping_coefficient: float) -> void` — Sets the damping coefficient of the given soft body.
- `soft_body_set_drag_coefficient(body: RID, drag_coefficient: float) -> void` — Sets the drag coefficient of the given soft body.
- `soft_body_set_linear_stiffness(body: RID, stiffness: float) -> void` — Sets the linear stiffness of the given soft body.
- `soft_body_set_mesh(body: RID, mesh: RID) -> void` — Sets the mesh of the given soft body.
- `soft_body_set_pressure_coefficient(body: RID, pressure_coefficient: float) -> void` — Sets the pressure coefficient of the given soft body.
- `soft_body_set_ray_pickable(body: RID, enable: bool) -> void` — Sets whether the given soft body will be pickable when using object picking.
- `soft_body_set_shrinking_factor(body: RID, shrinking_factor: float) -> void` — Sets the shrinking factor of the given soft body.
- `soft_body_set_simulation_precision(body: RID, simulation_precision: int) -> void` — Sets the simulation precision of the given soft body.
- `soft_body_set_space(body: RID, space: RID) -> void` — Assigns a space to the given soft body (see `space_create`).
- `soft_body_set_state(body: RID, state: PhysicsServer3D.BodyState, variant: Variant) -> void` — Sets the given body state for the given body.
- `soft_body_set_total_mass(body: RID, total_mass: float) -> void` — Sets the total mass for the given soft body.
- `soft_body_set_transform(body: RID, transform: Transform3D) -> void` — Sets the global transform of the given soft body.
- `soft_body_update_rendering_server(body: RID, rendering_server_handler: PhysicsServer3DRenderingServerHandler) -> void` — Requests that the physics server updates the rendering server with the latest positions of the given soft body's points through the `rendering_server_handler` interface.
- `space_create() -> RID` — Creates a space.
- `space_get_direct_state(space: RID) -> PhysicsDirectSpaceState3D` — Returns the state of a space, a PhysicsDirectSpaceState3D.
- `space_get_param(space: RID, param: PhysicsServer3D.SpaceParameter) -> float` *const* — Returns the value of a space parameter.
- `space_is_active(space: RID) -> bool` *const* — Returns whether the space is active.
- `space_set_active(space: RID, active: bool) -> void` — Marks a space as active.
- `space_set_param(space: RID, param: PhysicsServer3D.SpaceParameter, value: float) -> void` — Sets the value for a space parameter.
- `sphere_shape_create() -> RID` — Creates a 3D sphere shape in the physics server, and returns the RID that identifies it.
- `world_boundary_shape_create() -> RID` — Creates a 3D world boundary shape in the physics server, and returns the RID that identifies it.

## Enum JointType

- `JOINT_TYPE_PIN = 0` — The Joint3D is a PinJoint3D.
- `JOINT_TYPE_HINGE = 1` — The Joint3D is a HingeJoint3D.
- `JOINT_TYPE_SLIDER = 2` — The Joint3D is a SliderJoint3D.
- `JOINT_TYPE_CONE_TWIST = 3` — The Joint3D is a ConeTwistJoint3D.
- `JOINT_TYPE_6DOF = 4` — The Joint3D is a Generic6DOFJoint3D.
- `JOINT_TYPE_MAX = 5` — Represents the size of the `JointType` enum.

## Enum PinJointParam

- `PIN_JOINT_BIAS = 0` — The strength with which the pinned objects try to stay in positional relation to each other.
- `PIN_JOINT_DAMPING = 1` — The strength with which the pinned objects try to stay in velocity relation to each other.
- `PIN_JOINT_IMPULSE_CLAMP = 2` — If above 0, this value is the maximum value for an impulse that this Joint3D puts on its ends.

## Enum HingeJointParam

- `HINGE_JOINT_BIAS = 0` — The speed with which the two bodies get pulled together when they move in different directions.
- `HINGE_JOINT_LIMIT_UPPER = 1` — The maximum rotation across the Hinge.
- `HINGE_JOINT_LIMIT_LOWER = 2` — The minimum rotation across the Hinge.
- `HINGE_JOINT_LIMIT_BIAS = 3` — The speed with which the rotation across the axis perpendicular to the hinge gets corrected.
- `HINGE_JOINT_LIMIT_SOFTNESS = 4` — Note: Only supported when using GodotPhysics3D.
- `HINGE_JOINT_LIMIT_RELAXATION = 5` — The lower this value, the more the rotation gets slowed down.
- `HINGE_JOINT_MOTOR_TARGET_VELOCITY = 6` — Target speed for the motor.
- `HINGE_JOINT_MOTOR_MAX_IMPULSE = 7` — Maximum acceleration for the motor.

## Enum HingeJointFlag

- `HINGE_JOINT_FLAG_USE_LIMIT = 0` — If `true`, the Hinge has a maximum and a minimum rotation.
- `HINGE_JOINT_FLAG_ENABLE_MOTOR = 1` — If `true`, a motor turns the Hinge.

## Enum SliderJointParam

- `SLIDER_JOINT_LINEAR_LIMIT_UPPER = 0` — The maximum difference between the pivot points on their X axis before damping happens.
- `SLIDER_JOINT_LINEAR_LIMIT_LOWER = 1` — The minimum difference between the pivot points on their X axis before damping happens.
- `SLIDER_JOINT_LINEAR_LIMIT_SOFTNESS = 2` — A factor applied to the movement across the slider axis once the limits get surpassed.
- `SLIDER_JOINT_LINEAR_LIMIT_RESTITUTION = 3` — The amount of restitution once the limits are surpassed.
- `SLIDER_JOINT_LINEAR_LIMIT_DAMPING = 4` — The amount of damping once the slider limits are surpassed.
- `SLIDER_JOINT_LINEAR_MOTION_SOFTNESS = 5` — A factor applied to the movement across the slider axis as long as the slider is in the limits.
- `SLIDER_JOINT_LINEAR_MOTION_RESTITUTION = 6` — The amount of restitution inside the slider limits.
- `SLIDER_JOINT_LINEAR_MOTION_DAMPING = 7` — The amount of damping inside the slider limits.
- `SLIDER_JOINT_LINEAR_ORTHOGONAL_SOFTNESS = 8` — A factor applied to the movement across axes orthogonal to the slider.
- `SLIDER_JOINT_LINEAR_ORTHOGONAL_RESTITUTION = 9` — The amount of restitution when movement is across axes orthogonal to the slider.
- `SLIDER_JOINT_LINEAR_ORTHOGONAL_DAMPING = 10` — The amount of damping when movement is across axes orthogonal to the slider.
- `SLIDER_JOINT_ANGULAR_LIMIT_UPPER = 11` — The upper limit of rotation in the slider.
- `SLIDER_JOINT_ANGULAR_LIMIT_LOWER = 12` — The lower limit of rotation in the slider.
- `SLIDER_JOINT_ANGULAR_LIMIT_SOFTNESS = 13` — A factor applied to the all rotation once the limit is surpassed.
- `SLIDER_JOINT_ANGULAR_LIMIT_RESTITUTION = 14` — The amount of restitution of the rotation when the limit is surpassed.
- `SLIDER_JOINT_ANGULAR_LIMIT_DAMPING = 15` — The amount of damping of the rotation when the limit is surpassed.
- `SLIDER_JOINT_ANGULAR_MOTION_SOFTNESS = 16` — A factor that gets applied to the all rotation in the limits.
- `SLIDER_JOINT_ANGULAR_MOTION_RESTITUTION = 17` — The amount of restitution of the rotation in the limits.
- `SLIDER_JOINT_ANGULAR_MOTION_DAMPING = 18` — The amount of damping of the rotation in the limits.
- `SLIDER_JOINT_ANGULAR_ORTHOGONAL_SOFTNESS = 19` — A factor that gets applied to the all rotation across axes orthogonal to the slider.
- `SLIDER_JOINT_ANGULAR_ORTHOGONAL_RESTITUTION = 20` — The amount of restitution of the rotation across axes orthogonal to the slider.
- `SLIDER_JOINT_ANGULAR_ORTHOGONAL_DAMPING = 21` — The amount of damping of the rotation across axes orthogonal to the slider.
- `SLIDER_JOINT_MAX = 22` — Represents the size of the `SliderJointParam` enum.

## Enum ConeTwistJointParam

- `CONE_TWIST_JOINT_SWING_SPAN = 0` — Swing is rotation from side to side, around the axis perpendicular to the twist axis.
- `CONE_TWIST_JOINT_TWIST_SPAN = 1` — Twist is the rotation around the twist axis, this value defined how far the joint can twist.
- `CONE_TWIST_JOINT_BIAS = 2` — The speed with which the swing or twist will take place.
- `CONE_TWIST_JOINT_SOFTNESS = 3` — The ease with which the Joint3D twists, if it's too low, it takes more force to twist the joint.
- `CONE_TWIST_JOINT_RELAXATION = 4` — Defines, how fast the swing- and twist-speed-difference on both sides gets synced.

## Enum G6DOFJointAxisParam

- `G6DOF_JOINT_LINEAR_LOWER_LIMIT = 0` — The minimum difference between the pivot points' axes.
- `G6DOF_JOINT_LINEAR_UPPER_LIMIT = 1` — The maximum difference between the pivot points' axes.
- `G6DOF_JOINT_LINEAR_LIMIT_SOFTNESS = 2` — A factor that gets applied to the movement across the axes.
- `G6DOF_JOINT_LINEAR_RESTITUTION = 3` — The amount of restitution on the axes movement.
- `G6DOF_JOINT_LINEAR_DAMPING = 4` — The amount of damping that happens at the linear motion across the axes.
- `G6DOF_JOINT_LINEAR_MOTOR_TARGET_VELOCITY = 5` — The velocity that the joint's linear motor will attempt to reach.
- `G6DOF_JOINT_LINEAR_MOTOR_FORCE_LIMIT = 6` — The maximum force that the linear motor can apply while trying to reach the target velocity.
- `G6DOF_JOINT_LINEAR_SPRING_STIFFNESS = 7` — 
- `G6DOF_JOINT_LINEAR_SPRING_DAMPING = 8` — 
- `G6DOF_JOINT_LINEAR_SPRING_EQUILIBRIUM_POINT = 9` — 
- `G6DOF_JOINT_ANGULAR_LOWER_LIMIT = 10` — The minimum rotation in negative direction to break loose and rotate around the axes.
- `G6DOF_JOINT_ANGULAR_UPPER_LIMIT = 11` — The minimum rotation in positive direction to break loose and rotate around the axes.
- `G6DOF_JOINT_ANGULAR_LIMIT_SOFTNESS = 12` — A factor that gets multiplied onto all rotations across the axes.
- `G6DOF_JOINT_ANGULAR_DAMPING = 13` — The amount of rotational damping across the axes.
- `G6DOF_JOINT_ANGULAR_RESTITUTION = 14` — The amount of rotational restitution across the axes.
- `G6DOF_JOINT_ANGULAR_FORCE_LIMIT = 15` — The maximum amount of force that can occur, when rotating around the axes.
- `G6DOF_JOINT_ANGULAR_ERP = 16` — When correcting the crossing of limits in rotation across the axes, this error tolerance factor defines how much the correction gets slowed down.
- `G6DOF_JOINT_ANGULAR_MOTOR_TARGET_VELOCITY = 17` — Target speed for the motor at the axes.
- `G6DOF_JOINT_ANGULAR_MOTOR_FORCE_LIMIT = 18` — Maximum acceleration for the motor at the axes.
- `G6DOF_JOINT_ANGULAR_SPRING_STIFFNESS = 19` — 
- `G6DOF_JOINT_ANGULAR_SPRING_DAMPING = 20` — 
- `G6DOF_JOINT_ANGULAR_SPRING_EQUILIBRIUM_POINT = 21` — 
- `G6DOF_JOINT_LINEAR_DRIVE_FORCE_LIMIT = 22` — The maximum force the joint can apply along this linear axis.
- `G6DOF_JOINT_ANGULAR_DRIVE_TORQUE_LIMIT = 23` — The maximum torque the joint can apply around this angular axis.
- `G6DOF_JOINT_MAX = 24` — Represents the size of the `G6DOFJointAxisParam` enum.

## Enum G6DOFJointAxisFlag

- `G6DOF_JOINT_FLAG_ENABLE_LINEAR_LIMIT = 0` — If set, linear motion is possible within the given limits.
- `G6DOF_JOINT_FLAG_ENABLE_ANGULAR_LIMIT = 1` — If set, rotational motion is possible.
- `G6DOF_JOINT_FLAG_ENABLE_ANGULAR_SPRING = 2` — 
- `G6DOF_JOINT_FLAG_ENABLE_LINEAR_SPRING = 3` — 
- `G6DOF_JOINT_FLAG_ENABLE_ANGULAR_MOTOR = 4` — If set, there is a rotational or angular motor across these axes.
- `G6DOF_JOINT_FLAG_ENABLE_MOTOR = 4` — If set, there is a rotational or angular motor across these axes.
- `G6DOF_JOINT_FLAG_ENABLE_LINEAR_MOTOR = 5` — If set, there is a linear motor on this axis that targets a specific velocity.
- `G6DOF_JOINT_FLAG_MAX = 6` — Represents the size of the `G6DOFJointAxisFlag` enum.

## Enum ShapeType

- `SHAPE_WORLD_BOUNDARY = 0` — Constant for creating a world boundary shape (used by the WorldBoundaryShape3D resource).
- `SHAPE_SEPARATION_RAY = 1` — Constant for creating a separation ray shape (used by the SeparationRayShape3D resource).
- `SHAPE_SPHERE = 2` — Constant for creating a sphere shape (used by the SphereShape3D resource).
- `SHAPE_BOX = 3` — Constant for creating a box shape (used by the BoxShape3D resource).
- `SHAPE_CAPSULE = 4` — Constant for creating a capsule shape (used by the CapsuleShape3D resource).
- `SHAPE_CYLINDER = 5` — Constant for creating a cylinder shape (used by the CylinderShape3D resource).
- `SHAPE_CONVEX_POLYGON = 6` — Constant for creating a convex polygon shape (used by the ConvexPolygonShape3D resource).
- `SHAPE_CONCAVE_POLYGON = 7` — Constant for creating a concave polygon (trimesh) shape (used by the ConcavePolygonShape3D resource).
- `SHAPE_HEIGHTMAP = 8` — Constant for creating a heightmap shape (used by the HeightMapShape3D resource).
- `SHAPE_SOFT_BODY = 9` — Constant used internally for a soft body shape.
- `SHAPE_CUSTOM = 10` — Constant used internally for a custom shape.

## Enum AreaParameter

- `AREA_PARAM_GRAVITY_OVERRIDE_MODE = 0` — Constant to set/get gravity override mode in an area.
- `AREA_PARAM_GRAVITY = 1` — Constant to set/get gravity strength in an area.
- `AREA_PARAM_GRAVITY_VECTOR = 2` — Constant to set/get gravity vector/center in an area.
- `AREA_PARAM_GRAVITY_IS_POINT = 3` — Constant to set/get whether the gravity vector of an area is a direction, or a center point.
- `AREA_PARAM_GRAVITY_POINT_UNIT_DISTANCE = 4` — Constant to set/get the distance at which the gravity strength is equal to the gravity controlled by `AREA_PARAM_GRAVITY`.
- `AREA_PARAM_LINEAR_DAMP_OVERRIDE_MODE = 5` — Constant to set/get linear damping override mode in an area.
- `AREA_PARAM_LINEAR_DAMP = 6` — Constant to set/get the linear damping factor of an area.
- `AREA_PARAM_ANGULAR_DAMP_OVERRIDE_MODE = 7` — Constant to set/get angular damping override mode in an area.
- `AREA_PARAM_ANGULAR_DAMP = 8` — Constant to set/get the angular damping factor of an area.
- `AREA_PARAM_PRIORITY = 9` — Constant to set/get the priority (order of processing) of an area.
- `AREA_PARAM_WIND_FORCE_MAGNITUDE = 10` — Constant to set/get the magnitude of area-specific wind force.
- `AREA_PARAM_WIND_SOURCE = 11` — Constant to set/get the 3D vector that specifies the origin from which an area-specific wind blows.
- `AREA_PARAM_WIND_DIRECTION = 12` — Constant to set/get the 3D vector that specifies the direction in which an area-specific wind blows.
- `AREA_PARAM_WIND_ATTENUATION_FACTOR = 13` — Constant to set/get the exponential rate at which wind force decreases with distance from its origin.

## Enum AreaSpaceOverrideMode

- `AREA_SPACE_OVERRIDE_DISABLED = 0` — This area does not affect gravity/damp.
- `AREA_SPACE_OVERRIDE_COMBINE = 1` — This area adds its gravity/damp values to whatever has been calculated so far.
- `AREA_SPACE_OVERRIDE_COMBINE_REPLACE = 2` — This area adds its gravity/damp values to whatever has been calculated so far.
- `AREA_SPACE_OVERRIDE_REPLACE = 3` — This area replaces any gravity/damp, even the default one, and stops taking into account the rest of the areas.
- `AREA_SPACE_OVERRIDE_REPLACE_COMBINE = 4` — This area replaces any gravity/damp calculated so far, but keeps calculating the rest of the areas, down to the default one.

## Enum BodyMode

- `BODY_MODE_STATIC = 0` — Constant for static bodies.
- `BODY_MODE_KINEMATIC = 1` — Constant for kinematic bodies.
- `BODY_MODE_RIGID = 2` — Constant for rigid bodies.
- `BODY_MODE_RIGID_LINEAR = 3` — Constant for linear rigid bodies.

## Enum BodyParameter

- `BODY_PARAM_BOUNCE = 0` — Constant to set/get a body's bounce factor.
- `BODY_PARAM_FRICTION = 1` — Constant to set/get a body's friction.
- `BODY_PARAM_MASS = 2` — Constant to set/get a body's mass.
- `BODY_PARAM_INERTIA = 3` — Constant to set/get a body's inertia.
- `BODY_PARAM_CENTER_OF_MASS = 4` — Constant to set/get a body's center of mass position in the body's local coordinate system.
- `BODY_PARAM_GRAVITY_SCALE = 5` — Constant to set/get a body's gravity multiplier.
- `BODY_PARAM_LINEAR_DAMP_MODE = 6` — Constant to set/get a body's linear damping mode.
- `BODY_PARAM_ANGULAR_DAMP_MODE = 7` — Constant to set/get a body's angular damping mode.
- `BODY_PARAM_LINEAR_DAMP = 8` — Constant to set/get a body's linear damping factor.
- `BODY_PARAM_ANGULAR_DAMP = 9` — Constant to set/get a body's angular damping factor.
- `BODY_PARAM_MAX = 10` — Represents the size of the `BodyParameter` enum.

## Enum BodyDampMode

- `BODY_DAMP_MODE_COMBINE = 0` — The body's damping value is added to any value set in areas or the default value.
- `BODY_DAMP_MODE_REPLACE = 1` — The body's damping value replaces any value set in areas or the default value.

## Enum BodyState

- `BODY_STATE_TRANSFORM = 0` — Constant to set/get the current transform matrix of the body.
- `BODY_STATE_LINEAR_VELOCITY = 1` — Constant to set/get the current linear velocity of the body.
- `BODY_STATE_ANGULAR_VELOCITY = 2` — Constant to set/get the current angular velocity of the body.
- `BODY_STATE_SLEEPING = 3` — Constant to sleep/wake up a body, or to get whether it is sleeping.
- `BODY_STATE_CAN_SLEEP = 4` — Constant to set/get whether the body can sleep.

## Enum AreaBodyStatus

- `AREA_BODY_ADDED = 0` — The value of the first parameter and area callback function receives, when an object enters one of its shapes.
- `AREA_BODY_REMOVED = 1` — The value of the first parameter and area callback function receives, when an object exits one of its shapes.

## Enum ProcessInfo

- `INFO_ACTIVE_OBJECTS = 0` — Constant to get the number of objects that are not sleeping.
- `INFO_COLLISION_PAIRS = 1` — Constant to get the number of possible collisions.
- `INFO_ISLAND_COUNT = 2` — Constant to get the number of space regions where a collision could occur.

## Enum SpaceParameter

- `SPACE_PARAM_CONTACT_RECYCLE_RADIUS = 0` — Constant to set/get the maximum distance a pair of bodies has to move before their collision status has to be recalculated.
- `SPACE_PARAM_CONTACT_MAX_SEPARATION = 1` — Constant to set/get the maximum distance a shape can be from another before they are considered separated and the contact is discarded.
- `SPACE_PARAM_CONTACT_MAX_ALLOWED_PENETRATION = 2` — Constant to set/get the maximum distance a shape can penetrate another shape before it is considered a collision.
- `SPACE_PARAM_CONTACT_DEFAULT_BIAS = 3` — Constant to set/get the default solver bias for all physics contacts.
- `SPACE_PARAM_BODY_LINEAR_VELOCITY_SLEEP_THRESHOLD = 4` — Constant to set/get the threshold linear velocity of activity.
- `SPACE_PARAM_BODY_ANGULAR_VELOCITY_SLEEP_THRESHOLD = 5` — Constant to set/get the threshold angular velocity of activity.
- `SPACE_PARAM_BODY_TIME_TO_SLEEP = 6` — Constant to set/get the maximum time of activity.
- `SPACE_PARAM_SOLVER_ITERATIONS = 7` — Constant to set/get the number of solver iterations for contacts and constraints.

## Enum BodyAxis

- `BODY_AXIS_LINEAR_X = 1` — 
- `BODY_AXIS_LINEAR_Y = 2` — 
- `BODY_AXIS_LINEAR_Z = 4` — 
- `BODY_AXIS_ANGULAR_X = 8` — 
- `BODY_AXIS_ANGULAR_Y = 16` — 
- `BODY_AXIS_ANGULAR_Z = 32` —
