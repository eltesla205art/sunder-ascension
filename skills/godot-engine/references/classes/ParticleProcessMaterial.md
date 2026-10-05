# ParticleProcessMaterial

**Inherits:** Material

Holds a particle configuration for GPUParticles2D or GPUParticles3D nodes.

ParticleProcessMaterial defines particle properties and behavior. It is used in the `process_material` of the GPUParticles2D and GPUParticles3D nodes. Some of this material's properties are applied to each particle when emitted, while others can have a CurveTexture or a GradientTexture1D applied to vary numerical or color values over the lifetime of the particle.

## Properties

- `alpha_curve: Texture2D` — The alpha value of each particle's color will be multiplied by this CurveTexture over its lifetime.
- `angle_curve: Texture2D` — Each particle's rotation will be animated along this CurveTexture.
- `angle_max: float` = `0.0` — Maximum initial rotation applied to each particle, in degrees.
- `angle_min: float` = `0.0` — Minimum equivalent of `angle_max`.
- `angular_velocity_curve: Texture2D` — Each particle's angular velocity (rotation speed) will vary along this CurveTexture over its lifetime.
- `angular_velocity_max: float` = `0.0` — Maximum initial angular velocity (rotation speed) applied to each particle in degrees per second.
- `angular_velocity_min: float` = `0.0` — Minimum equivalent of `angular_velocity_max`.
- `anim_offset_curve: Texture2D` — Each particle's animation offset will vary along this CurveTexture.
- `anim_offset_max: float` = `0.0` — Maximum animation offset that corresponds to frame index in the texture.
- `anim_offset_min: float` = `0.0` — Minimum equivalent of `anim_offset_max`.
- `anim_speed_curve: Texture2D` — Each particle's animation speed will vary along this CurveTexture.
- `anim_speed_max: float` = `0.0` — Maximum particle animation speed.
- `anim_speed_min: float` = `0.0` — Minimum equivalent of `anim_speed_max`.
- `attractor_interaction_enabled: bool` = `true` — If `true`, interaction with particle attractors is enabled.
- `collision_bounce: float` — The particles' bounciness.
- `collision_friction: float` — The particles' friction.
- `collision_mode: ParticleProcessMaterial.CollisionMode` = `0` — The particles' collision mode.
- `collision_use_scale: bool` = `false` — If `true`, `GPUParticles3D.collision_base_size` is multiplied by the particle's effective scale (see `scale_min`, `scale_max`, `scale_curve`, and `scale_over_velocity_curve`).
- `color: Color` = `Color(1, 1, 1, 1)` — Each particle's initial color.
- `color_initial_ramp: Texture2D` — Each particle's initial color will vary along this GradientTexture1D (multiplied with `color`).
- `color_ramp: Texture2D` — Each particle's color will vary along this GradientTexture1D over its lifetime (multiplied with `color`).
- `damping_curve: Texture2D` — Damping will vary along this CurveTexture.
- `damping_max: float` = `0.0` — The maximum rate at which particles lose velocity.
- `damping_min: float` = `0.0` — Minimum equivalent of `damping_max`.
- `direction: Vector3` = `Vector3(1, 0, 0)` — Unit vector specifying the particles' emission direction.
- `directional_velocity_curve: Texture2D` — A curve that specifies the velocity along each of the axes of the particle system along its lifetime.
- `directional_velocity_max: float` — Maximum directional velocity value, which is multiplied by `directional_velocity_curve`.
- `directional_velocity_min: float` — Minimum directional velocity value, which is multiplied by `directional_velocity_curve`.
- `emission_box_extents: Vector3` — The box's extents if `emission_shape` is set to `EMISSION_SHAPE_BOX`.
- `emission_color_texture: Texture2D` — Particle color will be modulated by color determined by sampling this texture at the same point as the `emission_point_texture`.
- `emission_curve: Texture2D` — Each particle's color will be multiplied by this CurveTexture over its lifetime.
- `emission_normal_texture: Texture2D` — Particle velocity and rotation will be set by sampling this texture at the same point as the `emission_point_texture`.
- `emission_point_count: int` — The number of emission points if `emission_shape` is set to `EMISSION_SHAPE_POINTS` or `EMISSION_SHAPE_DIRECTED_POINTS`.
- `emission_point_texture: Texture2D` — Particles will be emitted at positions determined by sampling this texture at a random position.
- `emission_ring_axis: Vector3` — The axis of the ring when using the emitter `EMISSION_SHAPE_RING`.
- `emission_ring_cone_angle: float` — The angle of the cone when using the emitter `EMISSION_SHAPE_RING`.
- `emission_ring_height: float` — The height of the ring when using the emitter `EMISSION_SHAPE_RING`.
- `emission_ring_inner_radius: float` — The inner radius of the ring when using the emitter `EMISSION_SHAPE_RING`.
- `emission_ring_radius: float` — The radius of the ring when using the emitter `EMISSION_SHAPE_RING`.
- `emission_shape: ParticleProcessMaterial.EmissionShape` = `0` — Particles will be emitted inside this region.
- `emission_shape_offset: Vector3` = `Vector3(0, 0, 0)` — The offset for the `emission_shape`, in local space.
- `emission_shape_scale: Vector3` = `Vector3(1, 1, 1)` — The scale of the `emission_shape`, in local space.
- `emission_sphere_radius: float` — The sphere's radius if `emission_shape` is set to `EMISSION_SHAPE_SPHERE`.
- `flatness: float` = `0.0` — Amount of `spread` along the Y axis.
- `gravity: Vector3` = `Vector3(0, -9.8, 0)` — Gravity applied to every particle.
- `hue_variation_curve: Texture2D` — Each particle's hue will vary along this CurveTexture.
- `hue_variation_max: float` = `0.0` — Maximum initial hue variation applied to each particle.
- `hue_variation_min: float` = `0.0` — Minimum equivalent of `hue_variation_max`.
- `inherit_velocity_ratio: float` = `0.0` — Percentage of the velocity of the respective GPUParticles2D or GPUParticles3D inherited by each particle when spawning.
- `initial_velocity_max: float` = `0.0` — Maximum initial velocity magnitude for each particle.
- `initial_velocity_min: float` = `0.0` — Minimum equivalent of `initial_velocity_max`.
- `lifetime_randomness: float` = `0.0` — Particle lifetime randomness ratio.
- `linear_accel_curve: Texture2D` — Each particle's linear acceleration will vary along this CurveTexture.
- `linear_accel_max: float` = `0.0` — Maximum linear acceleration applied to each particle in the direction of motion.
- `linear_accel_min: float` = `0.0` — Minimum equivalent of `linear_accel_max`.
- `orbit_velocity_curve: Texture2D` — Each particle's orbital velocity will vary along this CurveTexture.
- `orbit_velocity_max: float` = `0.0` — Maximum orbital velocity applied to each particle.
- `orbit_velocity_min: float` = `0.0` — Minimum equivalent of `orbit_velocity_max`.
- `particle_flag_align_y: bool` = `false` — Align Y axis of particle with the direction of its velocity.
- `particle_flag_damping_as_friction: bool` = `false` — Changes the behavior of the damping properties from a linear deceleration to a deceleration based on speed percentage.
- `particle_flag_disable_z: bool` = `false` — If `true`, particles will not move on the z axis.
- `particle_flag_inherit_emitter_scale: bool` = `false` — If `true`, particles will inherit the scale of the emitter.
- `particle_flag_preserve_color: bool` = `false` — If `true`, preserves the color given by manual emission.
- `particle_flag_rotate_y: bool` = `false` — If `true`, particles rotate around Y axis by `angle_min`.
- `radial_accel_curve: Texture2D` — Each particle's radial acceleration will vary along this CurveTexture.
- `radial_accel_max: float` = `0.0` — Maximum radial acceleration applied to each particle.
- `radial_accel_min: float` = `0.0` — Minimum equivalent of `radial_accel_max`.
- `radial_velocity_curve: Texture2D` — A CurveTexture that defines the velocity over the particle's lifetime away (or toward) the `velocity_pivot`.
- `radial_velocity_max: float` = `0.0` — Maximum radial velocity applied to each particle.
- `radial_velocity_min: float` = `0.0` — Minimum radial velocity applied to each particle.
- `rotation_3d_max: Vector3` — The maximum 3D orientation, in degrees.
- `rotation_3d_min: Vector3` — The minimum 3D orientation, in degrees.
- `rotation_velocity_3d_curve: Texture2D` — Rotation velocity curve over lifetime, per-axis.
- `rotation_velocity_3d_max: Vector3` — Maximum 3D rotation velocity on the particle's local axis.
- `rotation_velocity_3d_min: Vector3` — Minimum 3D rotation velocity on the particle's local axis.
- `scale_3d_max: Vector3` — The maximum value of the random scale vector for each particle.
- `scale_3d_min: Vector3` — The minimum value of the random scale vector for each particle.
- `scale_curve: Texture2D` — Each particle's scale will vary along this CurveTexture over its lifetime.
- `scale_max: float` = `1.0` — Maximum initial scale applied to each particle.
- `scale_min: float` = `1.0` — Minimum equivalent of `scale_max`.
- `scale_over_velocity_curve: Texture2D` — Either a CurveTexture or a CurveXYZTexture that scales each particle based on its velocity.
- `scale_over_velocity_max: float` = `0.0` — Maximum velocity value reference for `scale_over_velocity_curve`.
- `scale_over_velocity_min: float` = `0.0` — Minimum velocity value reference for `scale_over_velocity_curve`.
- `spread: float` = `45.0` — Each particle's initial direction range from `+spread` to `-spread` degrees.
- `sub_emitter_amount_at_collision: int` — The amount of particles to spawn from the subemitter node when a collision occurs.
- `sub_emitter_amount_at_end: int` — The amount of particles to spawn from the subemitter node when the particle expires.
- `sub_emitter_amount_at_start: int` — The amount of particles to spawn from the subemitter node when the particle spawns.
- `sub_emitter_frequency: float` — The frequency at which particles should be emitted from the subemitter node.
- `sub_emitter_keep_velocity: bool` = `false` — If `true`, the subemitter inherits the parent particle's velocity when it spawns.
- `sub_emitter_mode: ParticleProcessMaterial.SubEmitterMode` = `0` — The particle subemitter mode (see `GPUParticles2D.sub_emitter` and `GPUParticles3D.sub_emitter`).
- `tangential_accel_curve: Texture2D` — Each particle's tangential acceleration will vary along this CurveTexture.
- `tangential_accel_max: float` = `0.0` — Maximum tangential acceleration applied to each particle.
- `tangential_accel_min: float` = `0.0` — Minimum equivalent of `tangential_accel_max`.
- `turbulence_enabled: bool` = `false` — If `true`, enables turbulence for the particle system.
- `turbulence_influence_max: float` = `0.1` — Maximum turbulence influence on each particle.
- `turbulence_influence_min: float` = `0.1` — Minimum turbulence influence on each particle.
- `turbulence_influence_over_life: Texture2D` — Each particle's amount of turbulence will be influenced along this CurveTexture over its life time.
- `turbulence_initial_displacement_max: float` = `0.0` — Maximum displacement of each particle's spawn position by the turbulence.
- `turbulence_initial_displacement_min: float` = `0.0` — Minimum displacement of each particle's spawn position by the turbulence.
- `turbulence_noise_scale: float` = `9.0` — This value controls the overall scale/frequency of the turbulence noise pattern.
- `turbulence_noise_speed: Vector3` = `Vector3(0, 0, 0)` — A scrolling velocity for the turbulence field.
- `turbulence_noise_speed_random: float` = `0.2` — The in-place rate of change of the turbulence field.
- `turbulence_noise_strength: float` = `1.0` — The turbulence noise strength.
- `use_rotation_3d: bool` = `false` — Enable the usage of `rotation_3d_min` and `rotation_3d_max`.
- `use_rotation_velocity_3d: bool` = `false` — Enable 3D rotation velocity.
- `use_scale_3d: bool` = `false` — Enable the usage of `scale_3d_min` and `scale_3d_max`.
- `velocity_limit_curve: Texture2D` — A CurveTexture that defines the maximum velocity of a particle during its lifetime.
- `velocity_pivot: Vector3` = `Vector3(0, 0, 0)` — A pivot point used to calculate radial and orbital velocity of particles.

## Methods

- `get_param(param: ParticleProcessMaterial.Parameter) -> Vector2` *const* — Returns the minimum and maximum values of the given `param` as a vector.
- `get_param_max(param: ParticleProcessMaterial.Parameter) -> float` *const* — Returns the maximum value range for the given parameter.
- `get_param_min(param: ParticleProcessMaterial.Parameter) -> float` *const* — Returns the minimum value range for the given parameter.
- `get_param_texture(param: ParticleProcessMaterial.Parameter) -> Texture2D` *const* — Returns the Texture2D used by the specified parameter.
- `get_particle_flag(particle_flag: ParticleProcessMaterial.ParticleFlags) -> bool` *const* — Returns `true` if the specified particle flag is enabled.
- `set_param(param: ParticleProcessMaterial.Parameter, value: Vector2) -> void` — Sets the minimum and maximum values of the given `param`.
- `set_param_max(param: ParticleProcessMaterial.Parameter, value: float) -> void` — Sets the maximum value range for the given parameter.
- `set_param_min(param: ParticleProcessMaterial.Parameter, value: float) -> void` — Sets the minimum value range for the given parameter.
- `set_param_texture(param: ParticleProcessMaterial.Parameter, texture: Texture2D) -> void` — Sets the Texture2D for the specified `Parameter`.
- `set_particle_flag(particle_flag: ParticleProcessMaterial.ParticleFlags, enable: bool) -> void` — Sets the `particle_flag` to `enable`.

## Signals

- `emission_shape_changed()` — Emitted when this material's emission shape is changed in any way.

## Enum Parameter

- `PARAM_INITIAL_LINEAR_VELOCITY = 0` — Use with `set_param_min`, `set_param_max`, and `set_param_texture` to set initial velocity properties.
- `PARAM_ANGULAR_VELOCITY = 1` — Use with `set_param_min`, `set_param_max`, and `set_param_texture` to set angular velocity properties.
- `PARAM_ORBIT_VELOCITY = 2` — Use with `set_param_min`, `set_param_max`, and `set_param_texture` to set orbital velocity properties.
- `PARAM_LINEAR_ACCEL = 3` — Use with `set_param_min`, `set_param_max`, and `set_param_texture` to set linear acceleration properties.
- `PARAM_RADIAL_ACCEL = 4` — Use with `set_param_min`, `set_param_max`, and `set_param_texture` to set radial acceleration properties.
- `PARAM_TANGENTIAL_ACCEL = 5` — Use with `set_param_min`, `set_param_max`, and `set_param_texture` to set tangential acceleration properties.
- `PARAM_DAMPING = 6` — Use with `set_param_min`, `set_param_max`, and `set_param_texture` to set damping properties.
- `PARAM_ANGLE = 7` — Use with `set_param_min`, `set_param_max`, and `set_param_texture` to set angle properties.
- `PARAM_SCALE = 8` — Use with `set_param_min`, `set_param_max`, and `set_param_texture` to set scale properties.
- `PARAM_HUE_VARIATION = 9` — Use with `set_param_min`, `set_param_max`, and `set_param_texture` to set hue variation properties.
- `PARAM_ANIM_SPEED = 10` — Use with `set_param_min`, `set_param_max`, and `set_param_texture` to set animation speed properties.
- `PARAM_ANIM_OFFSET = 11` — Use with `set_param_min`, `set_param_max`, and `set_param_texture` to set animation offset properties.
- `PARAM_RADIAL_VELOCITY = 15` — Use with `set_param_min`, `set_param_max`, and `set_param_texture` to set radial velocity properties.
- `PARAM_DIRECTIONAL_VELOCITY = 16` — Use with `set_param_min`, `set_param_max`, and `set_param_texture` to set directional velocity properties.
- `PARAM_SCALE_OVER_VELOCITY = 17` — Use with `set_param_min`, `set_param_max`, and `set_param_texture` to set scale over velocity properties.
- `PARAM_MAX = 18` — Represents the size of the `Parameter` enum.
- `PARAM_TURB_VEL_INFLUENCE = 13` — Use with `set_param_min` and `set_param_max` to set the turbulence minimum und maximum influence on each particles velocity.
- `PARAM_TURB_INIT_DISPLACEMENT = 14` — Use with `set_param_min` and `set_param_max` to set the turbulence minimum and maximum displacement of the particles spawn position.
- `PARAM_TURB_INFLUENCE_OVER_LIFE = 12` — Use with `set_param_texture` to set the turbulence influence over the particles life time.

## Enum ParticleFlags

- `PARTICLE_FLAG_ALIGN_Y_TO_VELOCITY = 0` — Use with `set_particle_flag` to set `particle_flag_align_y`.
- `PARTICLE_FLAG_ROTATE_Y = 1` — Use with `set_particle_flag` to set `particle_flag_rotate_y`.
- `PARTICLE_FLAG_DISABLE_Z = 2` — Use with `set_particle_flag` to set `particle_flag_disable_z`.
- `PARTICLE_FLAG_DAMPING_AS_FRICTION = 3` — Use with `set_particle_flag` to set `particle_flag_damping_as_friction`.
- `PARTICLE_FLAG_INHERIT_EMITTER_SCALE = 4` — Use with `set_particle_flag` to set `particle_flag_inherit_emitter_scale`.
- `PARTICLE_FLAG_PRESERVE_COLOR = 5` — Use with `set_particle_flag` to set `particle_flag_preserve_color`.
- `PARTICLE_FLAG_MAX = 6` — Represents the size of the `ParticleFlags` enum.

## Enum EmissionShape

- `EMISSION_SHAPE_POINT = 0` — All particles will be emitted from a single point.
- `EMISSION_SHAPE_SPHERE = 1` — Particles will be emitted in the volume of a sphere.
- `EMISSION_SHAPE_SPHERE_SURFACE = 2` — Particles will be emitted on the surface of a sphere.
- `EMISSION_SHAPE_BOX = 3` — Particles will be emitted in the volume of a box.
- `EMISSION_SHAPE_POINTS = 4` — Particles will be emitted at a position determined by sampling a random point on the `emission_point_texture`.
- `EMISSION_SHAPE_DIRECTED_POINTS = 5` — Particles will be emitted at a position determined by sampling a random point on the `emission_point_texture`.
- `EMISSION_SHAPE_RING = 6` — Particles will be emitted in a ring or cylinder.
- `EMISSION_SHAPE_MAX = 7` — Represents the size of the `EmissionShape` enum.

## Enum SubEmitterMode

- `SUB_EMITTER_DISABLED = 0` — The subemitter is disabled.
- `SUB_EMITTER_CONSTANT = 1` — The submitter is emitted on the constant interval defined by `sub_emitter_frequency`.
- `SUB_EMITTER_AT_END = 2` — The subemitter is emitted at the end of the particle's lifetime.
- `SUB_EMITTER_AT_COLLISION = 3` — The subemitter is emitted when the particle collides.
- `SUB_EMITTER_AT_START = 4` — The subemitter is emitted when the particle spawns.
- `SUB_EMITTER_MAX = 5` — Represents the size of the `SubEmitterMode` enum.

## Enum CollisionMode

- `COLLISION_DISABLED = 0` — No collision for particles.
- `COLLISION_RIGID = 1` — RigidBody3D-style collision for particles using GPUParticlesCollision3D nodes.
- `COLLISION_HIDE_ON_CONTACT = 2` — Hide particles instantly when colliding with a GPUParticlesCollision3D node.
- `COLLISION_MAX = 3` — Represents the size of the `CollisionMode` enum.
