# PhysicsServer2D

**Inherits:** Object

A server interface for low-level 2D physics access.

PhysicsServer2D is the server responsible for all 2D physics. It can directly create and manipulate all physics objects: - A space is a self-contained world for a physics simulation. It contains bodies, areas, and joints. Its state can be queried for collision and intersection information, and several parameters of the simulation can be modified. - A shape is a geometric shape such as a circle, a rectangle, a capsule, or a polygon.

## Methods

- `area_add_shape(area: RID, shape: RID, transform: Transform2D = Transform2D(1, 0, 0, 1, 0, 0), disabled: bool = false) -> void` — Adds a shape to the area, with the given local transform.
- `area_attach_canvas_instance_id(area: RID, id: int) -> void` — Attaches the `ObjectID` of a canvas to the area.
- `area_attach_object_instance_id(area: RID, id: int) -> void` — Attaches the `ObjectID` of an Object to the area.
- `area_clear_shapes(area: RID) -> void` — Removes all shapes from the area.
- `area_create() -> RID` — Creates a 2D area object in the physics server, and returns the RID that identifies it.
- `area_get_canvas_instance_id(area: RID) -> int` *const* — Returns the `ObjectID` of the canvas attached to the area.
- `area_get_collision_layer(area: RID) -> int` *const* — Returns the physics layer or layers the area belongs to, as a bitmask.
- `area_get_collision_mask(area: RID) -> int` *const* — Returns the physics layer or layers the area can contact with, as a bitmask.
- `area_get_object_instance_id(area: RID) -> int` *const* — Returns the `ObjectID` attached to the area.
- `area_get_param(area: RID, param: PhysicsServer2D.AreaParameter) -> Variant` *const* — Returns the value of the given area parameter.
- `area_get_shape(area: RID, shape_idx: int) -> RID` *const* — Returns the RID of the shape with the given index in the area's array of shapes.
- `area_get_shape_count(area: RID) -> int` *const* — Returns the number of shapes added to the area.
- `area_get_shape_transform(area: RID, shape_idx: int) -> Transform2D` *const* — Returns the local transform matrix of the shape with the given index in the area's array of shapes.
- `area_get_space(area: RID) -> RID` *const* — Returns the RID of the space assigned to the area.
- `area_get_transform(area: RID) -> Transform2D` *const* — Returns the transform matrix of the area.
- `area_remove_shape(area: RID, shape_idx: int) -> void` — Removes the shape with the given index from the area's array of shapes.
- `area_set_area_monitor_callback(area: RID, callback: Callable) -> void` — Sets the area's area monitor callback.
- `area_set_collision_layer(area: RID, layer: int) -> void` — Assigns the area to one or many physics layers, via a bitmask.
- `area_set_collision_mask(area: RID, mask: int) -> void` — Sets which physics layers the area will monitor, via a bitmask.
- `area_set_monitor_callback(area: RID, callback: Callable) -> void` — Sets the area's body monitor callback.
- `area_set_monitorable(area: RID, monitorable: bool) -> void` — Sets whether the area is monitorable or not.
- `area_set_param(area: RID, param: PhysicsServer2D.AreaParameter, value: Variant) -> void` — Sets the value of the given area parameter.
- `area_set_shape(area: RID, shape_idx: int, shape: RID) -> void` — Replaces the area's shape at the given index by another shape, while not affecting the `transform` and `disabled` properties at the same index.
- `area_set_shape_disabled(area: RID, shape_idx: int, disabled: bool) -> void` — Sets the disabled property of the area's shape with the given index.
- `area_set_shape_transform(area: RID, shape_idx: int, transform: Transform2D) -> void` — Sets the local transform matrix of the area's shape with the given index.
- `area_set_space(area: RID, space: RID) -> void` — Adds the area to the given space, after removing the area from the previously assigned space (if any).
- `area_set_transform(area: RID, transform: Transform2D) -> void` — Sets the transform matrix of the area.
- `body_add_collision_exception(body: RID, excepted_body: RID) -> void` — Adds `excepted_body` to the body's list of collision exceptions, so that collisions with it are ignored.
- `body_add_constant_central_force(body: RID, force: Vector2) -> void` — Adds a constant directional force to the body.
- `body_add_constant_force(body: RID, force: Vector2, position: Vector2 = Vector2(0, 0)) -> void` — Adds a constant positioned force to the body.
- `body_add_constant_torque(body: RID, torque: float) -> void` — Adds a constant rotational force to the body.
- `body_add_shape(body: RID, shape: RID, transform: Transform2D = Transform2D(1, 0, 0, 1, 0, 0), disabled: bool = false) -> void` — Adds a shape to the area, with the given local transform.
- `body_apply_central_force(body: RID, force: Vector2) -> void` — Applies a directional force to the body, at the body's center of mass.
- `body_apply_central_impulse(body: RID, impulse: Vector2) -> void` — Applies a directional impulse to the body, at the body's center of mass.
- `body_apply_force(body: RID, force: Vector2, position: Vector2 = Vector2(0, 0)) -> void` — Applies a positioned force to the body.
- `body_apply_impulse(body: RID, impulse: Vector2, position: Vector2 = Vector2(0, 0)) -> void` — Applies a positioned impulse to the body.
- `body_apply_torque(body: RID, torque: float) -> void` — Applies a rotational force to the body.
- `body_apply_torque_impulse(body: RID, impulse: float) -> void` — Applies a rotational impulse to the body.
- `body_attach_canvas_instance_id(body: RID, id: int) -> void` — Attaches the `ObjectID` of a canvas to the body.
- `body_attach_object_instance_id(body: RID, id: int) -> void` — Attaches the `ObjectID` of an Object to the body.
- `body_clear_shapes(body: RID) -> void` — Removes all shapes from the body.
- `body_create() -> RID` — Creates a 2D body object in the physics server, and returns the RID that identifies it.
- `body_get_canvas_instance_id(body: RID) -> int` *const* — Returns the `ObjectID` of the canvas attached to the body.
- `body_get_collision_layer(body: RID) -> int` *const* — Returns the physics layer or layers the body belongs to, as a bitmask.
- `body_get_collision_mask(body: RID) -> int` *const* — Returns the physics layer or layers the body can collide with, as a bitmask.
- `body_get_collision_priority(body: RID) -> float` *const* — Returns the body's collision priority.
- `body_get_constant_force(body: RID) -> Vector2` *const* — Returns the body's total constant positional force applied during each physics update.
- `body_get_constant_torque(body: RID) -> float` *const* — Returns the body's total constant rotational force applied during each physics update.
- `body_get_continuous_collision_detection_mode(body: RID) -> int[PhysicsServer2D.CCDMode]` *const* — Returns the body's continuous collision detection mode.
- `body_get_direct_state(body: RID) -> PhysicsDirectBodyState2D` — Returns the PhysicsDirectBodyState2D of the body.
- `body_get_max_contacts_reported(body: RID) -> int` *const* — Returns the maximum number of contacts that the body can report.
- `body_get_mode(body: RID) -> int[PhysicsServer2D.BodyMode]` *const* — Returns the body's mode.
- `body_get_object_instance_id(body: RID) -> int` *const* — Returns the `ObjectID` attached to the body.
- `body_get_param(body: RID, param: PhysicsServer2D.BodyParameter) -> Variant` *const* — Returns the value of the given body parameter.
- `body_get_shape(body: RID, shape_idx: int) -> RID` *const* — Returns the RID of the shape with the given index in the body's array of shapes.
- `body_get_shape_count(body: RID) -> int` *const* — Returns the number of shapes added to the body.
- `body_get_shape_transform(body: RID, shape_idx: int) -> Transform2D` *const* — Returns the local transform matrix of the shape with the given index in the area's array of shapes.
- `body_get_space(body: RID) -> RID` *const* — Returns the RID of the space assigned to the body.
- `body_get_state(body: RID, state: PhysicsServer2D.BodyState) -> Variant` *const* — Returns the value of the given state of the body.
- `body_is_omitting_force_integration(body: RID) -> bool` *const* — Returns `true` if the body is omitting the standard force integration.
- `body_remove_collision_exception(body: RID, excepted_body: RID) -> void` — Removes `excepted_body` from the body's list of collision exceptions, so that collisions with it are no longer ignored.
- `body_remove_shape(body: RID, shape_idx: int) -> void` — Removes the shape with the given index from the body's array of shapes.
- `body_reset_mass_properties(body: RID) -> void` — Restores the default inertia and center of mass of the body based on its shapes.
- `body_set_axis_velocity(body: RID, axis_velocity: Vector2) -> void` — Modifies the body's linear velocity so that its projection to the axis `axis_velocity.normalized()` is exactly `axis_velocity.length()`.
- `body_set_collision_layer(body: RID, layer: int) -> void` — Sets the physics layer or layers the body belongs to, via a bitmask.
- `body_set_collision_mask(body: RID, mask: int) -> void` — Sets the physics layer or layers the body can collide with, via a bitmask.
- `body_set_collision_priority(body: RID, priority: float) -> void` — Sets the body's collision priority.
- `body_set_constant_force(body: RID, force: Vector2) -> void` — Sets the body's total constant positional force applied during each physics update.
- `body_set_constant_torque(body: RID, torque: float) -> void` — Sets the body's total constant rotational force applied during each physics update.
- `body_set_continuous_collision_detection_mode(body: RID, mode: PhysicsServer2D.CCDMode) -> void` — Sets the continuous collision detection mode.
- `body_set_force_integration_callback(body: RID, callable: Callable, userdata: Variant = null) -> void` — Sets the body's custom force integration callback function to `callable`.
- `body_set_max_contacts_reported(body: RID, amount: int) -> void` — Sets the maximum number of contacts that the body can report.
- `body_set_mode(body: RID, mode: PhysicsServer2D.BodyMode) -> void` — Sets the body's mode.
- `body_set_omit_force_integration(body: RID, enable: bool) -> void` — Sets whether the body omits the standard force integration.
- `body_set_param(body: RID, param: PhysicsServer2D.BodyParameter, value: Variant) -> void` — Sets the value of the given body parameter.
- `body_set_shape(body: RID, shape_idx: int, shape: RID) -> void` — Replaces the body's shape at the given index by another shape, while not affecting the `transform`, `disabled`, and one-way collision properties at the same index.
- `body_set_shape_as_one_way_collision(body: RID, shape_idx: int, enable: bool, margin: float, direction: Vector2 = Vector2(0, 1)) -> void` — Sets the one-way collision properties of the body's shape with the given index.
- `body_set_shape_disabled(body: RID, shape_idx: int, disabled: bool) -> void` — Sets the disabled property of the body's shape with the given index.
- `body_set_shape_transform(body: RID, shape_idx: int, transform: Transform2D) -> void` — Sets the local transform matrix of the body's shape with the given index.
- `body_set_space(body: RID, space: RID) -> void` — Adds the body to the given space, after removing the body from the previously assigned space (if any).
- `body_set_state(body: RID, state: PhysicsServer2D.BodyState, value: Variant) -> void` — Sets the value of a body's state.
- `body_set_state_sync_callback(body: RID, callable: Callable) -> void` — Sets the body's state synchronization callback function to `callable`.
- `body_test_motion(body: RID, parameters: PhysicsTestMotionParameters2D, result: PhysicsTestMotionResult2D = null) -> bool` — Returns `true` if a collision would result from moving the body along a motion vector from a given point in space.
- `capsule_shape_create() -> RID` — Creates a 2D capsule shape in the physics server, and returns the RID that identifies it.
- `circle_shape_create() -> RID` — Creates a 2D circle shape in the physics server, and returns the RID that identifies it.
- `concave_polygon_shape_create() -> RID` — Creates a 2D concave polygon shape in the physics server, and returns the RID that identifies it.
- `convex_polygon_shape_create() -> RID` — Creates a 2D convex polygon shape in the physics server, and returns the RID that identifies it.
- `damped_spring_joint_get_param(joint: RID, param: PhysicsServer2D.DampedSpringParam) -> float` *const* — Returns the value of the given damped spring joint parameter.
- `damped_spring_joint_set_param(joint: RID, param: PhysicsServer2D.DampedSpringParam, value: float) -> void` — Sets the value of the given damped spring joint parameter.
- `free_rid(rid: RID) -> void` — Destroys any of the objects created by PhysicsServer2D.
- `get_process_info(process_info: PhysicsServer2D.ProcessInfo) -> int` — Returns the value of a physics engine state specified by `process_info`.
- `joint_clear(joint: RID) -> void` — Destroys the joint with the given RID, creates a new uninitialized joint, and makes the RID refer to this new joint.
- `joint_create() -> RID` — Creates a 2D joint in the physics server, and returns the RID that identifies it.
- `joint_disable_collisions_between_bodies(joint: RID, disable: bool) -> void` — Sets whether the bodies attached to the Joint2D will collide with each other.
- `joint_get_param(joint: RID, param: PhysicsServer2D.JointParam) -> float` *const* — Returns the value of the given joint parameter.
- `joint_get_type(joint: RID) -> int[PhysicsServer2D.JointType]` *const* — Returns the joint's type.
- `joint_is_disabled_collisions_between_bodies(joint: RID) -> bool` *const* — Returns whether the bodies attached to the Joint2D will collide with each other.
- `joint_make_damped_spring(joint: RID, anchor_a: Vector2, anchor_b: Vector2, body_a: RID, body_b: RID = RID()) -> void` — Makes the joint a damped spring joint, attached at the point `anchor_a` (given in global coordinates) on the body `body_a` and at the point `anchor_b` (given in global coordinates) on the body `body_b`.
- `joint_make_groove(joint: RID, groove1_a: Vector2, groove2_a: Vector2, anchor_b: Vector2, body_a: RID = RID(), body_b: RID = RID()) -> void` — Makes the joint a groove joint.
- `joint_make_pin(joint: RID, anchor: Vector2, body_a: RID, body_b: RID = RID()) -> void` — Makes the joint a pin joint.
- `joint_set_param(joint: RID, param: PhysicsServer2D.JointParam, value: float) -> void` — Sets the value of the given joint parameter.
- `pin_joint_get_flag(joint: RID, flag: PhysicsServer2D.PinJointFlag) -> bool` *const* — Gets a pin joint flag.
- `pin_joint_get_param(joint: RID, param: PhysicsServer2D.PinJointParam) -> float` *const* — Returns the value of a pin joint parameter.
- `pin_joint_set_flag(joint: RID, flag: PhysicsServer2D.PinJointFlag, enabled: bool) -> void` — Sets a pin joint flag.
- `pin_joint_set_param(joint: RID, param: PhysicsServer2D.PinJointParam, value: float) -> void` — Sets a pin joint parameter.
- `rectangle_shape_create() -> RID` — Creates a 2D rectangle shape in the physics server, and returns the RID that identifies it.
- `segment_shape_create() -> RID` — Creates a 2D segment shape in the physics server, and returns the RID that identifies it.
- `separation_ray_shape_create() -> RID` — Creates a 2D separation ray shape in the physics server, and returns the RID that identifies it.
- `set_active(active: bool) -> void` — Activates or deactivates the 2D physics server.
- `shape_get_data(shape: RID) -> Variant` *const* — Returns the shape data that defines the configuration of the shape, such as the half-extents of a rectangle or the segments of a concave shape.
- `shape_get_type(shape: RID) -> int[PhysicsServer2D.ShapeType]` *const* — Returns the shape's type.
- `shape_set_data(shape: RID, data: Variant) -> void` — Sets the shape data that defines the configuration of the shape.
- `space_create() -> RID` — Creates a 2D space in the physics server, and returns the RID that identifies it.
- `space_get_direct_state(space: RID) -> PhysicsDirectSpaceState2D` — Returns the state of a space, a PhysicsDirectSpaceState2D.
- `space_get_param(space: RID, param: PhysicsServer2D.SpaceParameter) -> float` *const* — Returns the value of the given space parameter.
- `space_is_active(space: RID) -> bool` *const* — Returns `true` if the space is active.
- `space_set_active(space: RID, active: bool) -> void` — Activates or deactivates the space.
- `space_set_param(space: RID, param: PhysicsServer2D.SpaceParameter, value: float) -> void` — Sets the value of the given space parameter.
- `world_boundary_shape_create() -> RID` — Creates a 2D world boundary shape in the physics server, and returns the RID that identifies it.

## Enum SpaceParameter

- `SPACE_PARAM_CONTACT_RECYCLE_RADIUS = 0` — Constant to set/get the maximum distance a pair of bodies has to move before their collision status has to be recalculated.
- `SPACE_PARAM_CONTACT_MAX_SEPARATION = 1` — Constant to set/get the maximum distance a shape can be from another before they are considered separated and the contact is discarded.
- `SPACE_PARAM_CONTACT_MAX_ALLOWED_PENETRATION = 2` — Constant to set/get the maximum distance a shape can penetrate another shape before it is considered a collision.
- `SPACE_PARAM_CONTACT_DEFAULT_BIAS = 3` — Constant to set/get the default solver bias for all physics contacts.
- `SPACE_PARAM_BODY_LINEAR_VELOCITY_SLEEP_THRESHOLD = 4` — Constant to set/get the threshold linear velocity of activity.
- `SPACE_PARAM_BODY_ANGULAR_VELOCITY_SLEEP_THRESHOLD = 5` — Constant to set/get the threshold angular velocity of activity.
- `SPACE_PARAM_BODY_TIME_TO_SLEEP = 6` — Constant to set/get the maximum time of activity.
- `SPACE_PARAM_CONSTRAINT_DEFAULT_BIAS = 7` — Constant to set/get the default solver bias for all physics constraints.
- `SPACE_PARAM_SOLVER_ITERATIONS = 8` — Constant to set/get the number of solver iterations for all contacts and constraints.

## Enum ShapeType

- `SHAPE_WORLD_BOUNDARY = 0` — This is the constant for creating world boundary shapes.
- `SHAPE_SEPARATION_RAY = 1` — This is the constant for creating separation ray shapes.
- `SHAPE_SEGMENT = 2` — This is the constant for creating segment shapes.
- `SHAPE_CIRCLE = 3` — This is the constant for creating circle shapes.
- `SHAPE_RECTANGLE = 4` — This is the constant for creating rectangle shapes.
- `SHAPE_CAPSULE = 5` — This is the constant for creating capsule shapes.
- `SHAPE_CONVEX_POLYGON = 6` — This is the constant for creating convex polygon shapes.
- `SHAPE_CONCAVE_POLYGON = 7` — This is the constant for creating concave polygon shapes.
- `SHAPE_CUSTOM = 8` — This constant is used internally by the engine.

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

## Enum JointType

- `JOINT_TYPE_PIN = 0` — Constant to create pin joints.
- `JOINT_TYPE_GROOVE = 1` — Constant to create groove joints.
- `JOINT_TYPE_DAMPED_SPRING = 2` — Constant to create damped spring joints.
- `JOINT_TYPE_MAX = 3` — Represents the size of the `JointType` enum.

## Enum JointParam

- `JOINT_PARAM_BIAS = 0` — Constant to set/get how fast the joint pulls the bodies back to satisfy the joint constraint.
- `JOINT_PARAM_MAX_BIAS = 1` — Constant to set/get the maximum speed with which the joint can apply corrections.
- `JOINT_PARAM_MAX_FORCE = 2` — Constant to set/get the maximum force that the joint can use to act on the two bodies.

## Enum PinJointParam

- `PIN_JOINT_SOFTNESS = 0` — Constant to set/get a how much the bond of the pin joint can flex.
- `PIN_JOINT_LIMIT_UPPER = 1` — The maximum rotation around the pin.
- `PIN_JOINT_LIMIT_LOWER = 2` — The minimum rotation around the pin.
- `PIN_JOINT_MOTOR_TARGET_VELOCITY = 3` — Target speed for the motor.

## Enum PinJointFlag

- `PIN_JOINT_FLAG_ANGULAR_LIMIT_ENABLED = 0` — If `true`, the pin has a maximum and a minimum rotation.
- `PIN_JOINT_FLAG_MOTOR_ENABLED = 1` — If `true`, a motor turns the pin.

## Enum DampedSpringParam

- `DAMPED_SPRING_REST_LENGTH = 0` — Sets the resting length of the spring joint.
- `DAMPED_SPRING_STIFFNESS = 1` — Sets the stiffness of the spring joint.
- `DAMPED_SPRING_DAMPING = 2` — Sets the damping ratio of the spring joint.

## Enum CCDMode

- `CCD_MODE_DISABLED = 0` — Disables continuous collision detection.
- `CCD_MODE_CAST_RAY = 1` — Enables continuous collision detection by raycasting.
- `CCD_MODE_CAST_SHAPE = 2` — Enables continuous collision detection by shapecasting.

## Enum AreaBodyStatus

- `AREA_BODY_ADDED = 0` — The value of the first parameter and area callback function receives, when an object enters one of its shapes.
- `AREA_BODY_REMOVED = 1` — The value of the first parameter and area callback function receives, when an object exits one of its shapes.

## Enum ProcessInfo

- `INFO_ACTIVE_OBJECTS = 0` — Constant to get the number of objects that are not sleeping.
- `INFO_COLLISION_PAIRS = 1` — Constant to get the number of possible collisions.
- `INFO_ISLAND_COUNT = 2` — Constant to get the number of space regions where a collision could occur.
