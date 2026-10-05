# CPUParticles2D

**Inherits:** Node2D

A CPU-based 2D particle emitter.

CPU-based 2D particle node used to create a variety of particle systems and effects. See also GPUParticles2D, which provides the same functionality with hardware acceleration, but may not run on older devices.

## Properties

- `amount: int` = `8` — Number of particles emitted in one emission cycle.
- `angle_curve: Curve` — Each particle's rotation will be animated along this Curve.
- `angle_max: float` = `0.0` — Maximum initial rotation applied to each particle, in degrees.
- `angle_min: float` = `0.0` — Minimum equivalent of `angle_max`.
- `angular_velocity_curve: Curve` — Each particle's angular velocity will vary along this Curve.
- `angular_velocity_max: float` = `0.0` — Maximum initial angular velocity (rotation speed) applied to each particle in degrees per second.
- `angular_velocity_min: float` = `0.0` — Minimum equivalent of `angular_velocity_max`.
- `anim_offset_curve: Curve` — Each particle's animation offset will vary along this Curve.
- `anim_offset_max: float` = `0.0` — Maximum animation offset that corresponds to frame index in the texture.
- `anim_offset_min: float` = `0.0` — Minimum equivalent of `anim_offset_max`.
- `anim_speed_curve: Curve` — Each particle's animation speed will vary along this Curve.
- `anim_speed_max: float` = `0.0` — Maximum particle animation speed.
- `anim_speed_min: float` = `0.0` — Minimum equivalent of `anim_speed_max`.
- `color: Color` = `Color(1, 1, 1, 1)` — Each particle's initial color.
- `color_initial_ramp: Gradient` — Each particle's initial color will vary along this Gradient (multiplied with `color`).
- `color_ramp: Gradient` — Each particle's color will vary along this Gradient over its lifetime (multiplied with `color`).
- `damping_curve: Curve` — Damping will vary along this Curve.
- `damping_max: float` = `0.0` — The maximum rate at which particles lose velocity.
- `damping_min: float` = `0.0` — Minimum equivalent of `damping_max`.
- `direction: Vector2` = `Vector2(1, 0)` — Unit vector specifying the particles' emission direction.
- `draw_order: CPUParticles2D.DrawOrder` = `0` — Particle draw order.
- `emission_colors: PackedColorArray` — Sets the Colors to modulate particles by when using `EMISSION_SHAPE_POINTS` or `EMISSION_SHAPE_DIRECTED_POINTS`.
- `emission_normals: PackedVector2Array` — Sets the direction the particles will be emitted in when using `EMISSION_SHAPE_DIRECTED_POINTS`.
- `emission_points: PackedVector2Array` — Sets the initial positions to spawn particles when using `EMISSION_SHAPE_POINTS` or `EMISSION_SHAPE_DIRECTED_POINTS`.
- `emission_rect_extents: Vector2` — The rectangle's extents if `emission_shape` is set to `EMISSION_SHAPE_RECTANGLE`.
- `emission_ring_inner_radius: float` — The ring's inner radius if `emission_shape` is set to `EMISSION_SHAPE_RING`.
- `emission_ring_radius: float` — The ring's outer radius if `emission_shape` is set to `EMISSION_SHAPE_RING`.
- `emission_shape: CPUParticles2D.EmissionShape` = `0` — Particles will be emitted inside this region.
- `emission_sphere_radius: float` — The sphere's radius if `emission_shape` is set to `EMISSION_SHAPE_SPHERE`.
- `emitting: bool` = `true` — If `true`, particles are being emitted.
- `explosiveness: float` = `0.0` — How rapidly particles in an emission cycle are emitted.
- `fixed_fps: int` = `0` — The particle system's frame rate is fixed to a value.
- `fract_delta: bool` = `true` — If `true`, results in fractional delta calculation which has a smoother particles display effect.
- `gravity: Vector2` = `Vector2(0, 980)` — Gravity applied to every particle.
- `hue_variation_curve: Curve` — Each particle's hue will vary along this Curve.
- `hue_variation_max: float` = `0.0` — Maximum initial hue variation applied to each particle.
- `hue_variation_min: float` = `0.0` — Minimum equivalent of `hue_variation_max`.
- `initial_velocity_max: float` = `0.0` — Maximum initial velocity magnitude for each particle.
- `initial_velocity_min: float` = `0.0` — Minimum equivalent of `initial_velocity_max`.
- `lifetime: float` = `1.0` — Amount of time each particle will exist.
- `lifetime_randomness: float` = `0.0` — Particle lifetime randomness ratio.
- `linear_accel_curve: Curve` — Each particle's linear acceleration will vary along this Curve.
- `linear_accel_max: float` = `0.0` — Maximum linear acceleration applied to each particle in the direction of motion.
- `linear_accel_min: float` = `0.0` — Minimum equivalent of `linear_accel_max`.
- `local_coords: bool` = `false` — If `true`, particles use the parent node's coordinate space (known as local coordinates).
- `one_shot: bool` = `false` — If `true`, only one emission cycle occurs.
- `orbit_velocity_curve: Curve` — Each particle's orbital velocity will vary along this Curve.
- `orbit_velocity_max: float` = `0.0` — Maximum orbital velocity applied to each particle.
- `orbit_velocity_min: float` = `0.0` — Minimum equivalent of `orbit_velocity_max`.
- `particle_flag_align_y: bool` = `false` — Align Y axis of particle with the direction of its velocity.
- `physics_interpolation_mode: Node.PhysicsInterpolationMode` = `2` — 
- `preprocess: float` = `0.0` — Particle system starts as if it had already run for this many seconds.
- `radial_accel_curve: Curve` — Each particle's radial acceleration will vary along this Curve.
- `radial_accel_max: float` = `0.0` — Maximum radial acceleration applied to each particle.
- `radial_accel_min: float` = `0.0` — Minimum equivalent of `radial_accel_max`.
- `randomness: float` = `0.0` — Emission lifetime randomness ratio.
- `scale_amount_curve: Curve` — Each particle's scale will vary along this Curve.
- `scale_amount_max: float` = `1.0` — Maximum initial scale applied to each particle.
- `scale_amount_min: float` = `1.0` — Minimum equivalent of `scale_amount_max`.
- `scale_curve_x: Curve` — Each particle's horizontal scale will vary along this Curve.
- `scale_curve_y: Curve` — Each particle's vertical scale will vary along this Curve.
- `seed: int` = `0` — Sets the random seed used by the particle system.
- `speed_scale: float` = `1.0` — Particle system's running speed scaling ratio.
- `split_scale: bool` = `false` — If `true`, the scale curve will be split into x and y components.
- `spread: float` = `45.0` — Each particle's initial direction range from `+spread` to `-spread` degrees.
- `tangential_accel_curve: Curve` — Each particle's tangential acceleration will vary along this Curve.
- `tangential_accel_max: float` = `0.0` — Maximum tangential acceleration applied to each particle.
- `tangential_accel_min: float` = `0.0` — Minimum equivalent of `tangential_accel_max`.
- `texture: Texture2D` — Particle texture.
- `use_fixed_seed: bool` = `false` — If `true`, particles will use the same seed for every simulation using the seed defined in `seed`.

## Methods

- `convert_from_particles(particles: Node) -> void` — Sets this node's properties to match a given GPUParticles2D node with an assigned ParticleProcessMaterial.
- `get_param_curve(param: CPUParticles2D.Parameter) -> Curve` *const* — Returns the Curve of the parameter specified by `Parameter`.
- `get_param_max(param: CPUParticles2D.Parameter) -> float` *const* — Returns the maximum value range for the given parameter.
- `get_param_min(param: CPUParticles2D.Parameter) -> float` *const* — Returns the minimum value range for the given parameter.
- `get_particle_flag(particle_flag: CPUParticles2D.ParticleFlags) -> bool` *const* — Returns the enabled state of the given particle flag.
- `request_particles_process(process_time: float, process_time_residual: float = 0.0) -> void` — Requests the particles to process for extra process time during a single frame.
- `restart(keep_seed: bool = false) -> void` — Restarts the particle emitter.
- `set_param_curve(param: CPUParticles2D.Parameter, curve: Curve) -> void` — Sets the Curve of the parameter specified by `Parameter`.
- `set_param_max(param: CPUParticles2D.Parameter, value: float) -> void` — Sets the maximum value for the given parameter.
- `set_param_min(param: CPUParticles2D.Parameter, value: float) -> void` — Sets the minimum value for the given parameter.
- `set_particle_flag(particle_flag: CPUParticles2D.ParticleFlags, enable: bool) -> void` — Enables or disables the given particle flag.

## Signals

- `finished()` — Emitted when all active particles have finished processing.

## Enum DrawOrder

- `DRAW_ORDER_INDEX = 0` — Particles are drawn in the order emitted.
- `DRAW_ORDER_LIFETIME = 1` — Particles are drawn in order of remaining lifetime.

## Enum Parameter

- `PARAM_INITIAL_LINEAR_VELOCITY = 0` — Use with `set_param_min`, `set_param_max`, and `set_param_curve` to set initial velocity properties.
- `PARAM_ANGULAR_VELOCITY = 1` — Use with `set_param_min`, `set_param_max`, and `set_param_curve` to set angular velocity properties.
- `PARAM_ORBIT_VELOCITY = 2` — Use with `set_param_min`, `set_param_max`, and `set_param_curve` to set orbital velocity properties.
- `PARAM_LINEAR_ACCEL = 3` — Use with `set_param_min`, `set_param_max`, and `set_param_curve` to set linear acceleration properties.
- `PARAM_RADIAL_ACCEL = 4` — Use with `set_param_min`, `set_param_max`, and `set_param_curve` to set radial acceleration properties.
- `PARAM_TANGENTIAL_ACCEL = 5` — Use with `set_param_min`, `set_param_max`, and `set_param_curve` to set tangential acceleration properties.
- `PARAM_DAMPING = 6` — Use with `set_param_min`, `set_param_max`, and `set_param_curve` to set damping properties.
- `PARAM_ANGLE = 7` — Use with `set_param_min`, `set_param_max`, and `set_param_curve` to set angle properties.
- `PARAM_SCALE = 8` — Use with `set_param_min`, `set_param_max`, and `set_param_curve` to set scale properties.
- `PARAM_HUE_VARIATION = 9` — Use with `set_param_min`, `set_param_max`, and `set_param_curve` to set hue variation properties.
- `PARAM_ANIM_SPEED = 10` — Use with `set_param_min`, `set_param_max`, and `set_param_curve` to set animation speed properties.
- `PARAM_ANIM_OFFSET = 11` — Use with `set_param_min`, `set_param_max`, and `set_param_curve` to set animation offset properties.
- `PARAM_MAX = 12` — Represents the size of the `Parameter` enum.

## Enum ParticleFlags

- `PARTICLE_FLAG_ALIGN_Y_TO_VELOCITY = 0` — Use with `set_particle_flag` to set `particle_flag_align_y`.
- `PARTICLE_FLAG_ROTATE_Y = 1` — Present for consistency with 3D particle nodes, not used in 2D.
- `PARTICLE_FLAG_DISABLE_Z = 2` — Present for consistency with 3D particle nodes, not used in 2D.
- `PARTICLE_FLAG_MAX = 3` — Represents the size of the `ParticleFlags` enum.

## Enum EmissionShape

- `EMISSION_SHAPE_POINT = 0` — All particles will be emitted from a single point.
- `EMISSION_SHAPE_SPHERE = 1` — Particles will be emitted in the volume of a sphere flattened to two dimensions.
- `EMISSION_SHAPE_SPHERE_SURFACE = 2` — Particles will be emitted on the surface of a sphere flattened to two dimensions.
- `EMISSION_SHAPE_RECTANGLE = 3` — Particles will be emitted in the area of a rectangle.
- `EMISSION_SHAPE_POINTS = 4` — Particles will be emitted at a position chosen randomly among `emission_points`.
- `EMISSION_SHAPE_DIRECTED_POINTS = 5` — Particles will be emitted at a position chosen randomly among `emission_points`.
- `EMISSION_SHAPE_RING = 6` — Particles will be emitted in the area of a ring parameterized by its outer and inner radius.
- `EMISSION_SHAPE_MAX = 7` — Represents the size of the `EmissionShape` enum.
