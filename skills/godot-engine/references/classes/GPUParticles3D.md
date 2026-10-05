# GPUParticles3D

**Inherits:** GeometryInstance3D

A 3D particle emitter.

3D particle node used to create a variety of particle systems and effects. GPUParticles3D features an emitter that generates some number of particles at a given rate. Use `process_material` to add a ParticleProcessMaterial to configure particle appearance and behavior. Alternatively, you can add a ShaderMaterial which will be applied to all particles.

## Properties

- `amount: int` = `8` — The number of particles to emit in one emission cycle.
- `amount_ratio: float` = `1.0` — The ratio of particles that should actually be emitted.
- `collision_base_size: float` = `0.01` — The base diameter for particle collision in meters.
- `draw_order: GPUParticles3D.DrawOrder` = `0` — Particle draw order.
- `draw_pass_1: Mesh` — Mesh that is drawn for the first draw pass.
- `draw_pass_2: Mesh` — Mesh that is drawn for the second draw pass.
- `draw_pass_3: Mesh` — Mesh that is drawn for the third draw pass.
- `draw_pass_4: Mesh` — Mesh that is drawn for the fourth draw pass.
- `draw_passes: int` = `1` — The number of draw passes when rendering particles.
- `draw_skin: Skin` — 
- `emitting: bool` = `true` — If `true`, particles are being emitted.
- `explosiveness: float` = `0.0` — Time ratio between each emission.
- `fixed_fps: int` = `30` — The particle system's frame rate is fixed to a value.
- `fract_delta: bool` = `true` — If `true`, results in fractional delta calculation which has a smoother particles display effect.
- `interp_to_end: float` = `0.0` — Causes all the particles in this node to interpolate towards the end of their lifetime.
- `interpolate: bool` = `true` — Enables particle interpolation, which makes the particle movement smoother when their `fixed_fps` is lower than the screen refresh rate.
- `lifetime: float` = `1.0` — The amount of time each particle will exist (in seconds).
- `local_coords: bool` = `false` — If `true`, particles use the parent node's coordinate space (known as local coordinates).
- `one_shot: bool` = `false` — If `true`, only the number of particles equal to `amount` will be emitted.
- `preprocess: float` = `0.0` — Amount of time to preprocess the particles before animation starts.
- `process_material: Material` — Material for processing particles.
- `randomness: float` = `0.0` — Emission randomness ratio.
- `seed: int` = `0` — Sets the random seed used by the particle system.
- `speed_scale: float` = `1.0` — Speed scaling ratio.
- `sub_emitter: NodePath` = `NodePath("")` — Path to another GPUParticles3D node that will be used as a subemitter (see `ParticleProcessMaterial.sub_emitter_mode`).
- `trail_enabled: bool` = `false` — If `true`, enables particle trails using a mesh skinning system.
- `trail_lifetime: float` = `0.3` — The amount of time the particle's trail should represent (in seconds).
- `transform_align: GPUParticles3D.TransformAlign` = `0` — The alignment of particles.
- `transform_align_axis: RenderingServer.ParticlesTransformAlignAxis` — When using transform align local billboard, which axis to use for the billboarding.
- `transform_align_channel_filter: RenderingServer.ParticlesTransformAlignCustomSrc` — In the case of billboarded particles, which custom channel to read from to calculate their angle.
- `use_fixed_seed: bool` = `false` — If `true`, particles will use the same seed for every simulation using the seed defined in `seed`.
- `visibility_aabb: AABB` = `AABB(-4, -4, -4, 8, 8, 8)` — The AABB that determines the node's region which needs to be visible on screen for the particle system to be active.

## Methods

- `capture_aabb() -> AABB` *const* — Returns the axis-aligned bounding box that contains all the particles that are active in the current frame.
- `convert_from_particles(particles: Node) -> void` — Sets this node's properties to match a given CPUParticles3D node.
- `emit_particle(xform: Transform3D, velocity: Vector3, color: Color, custom: Color, flags: int) -> void` — Emits a single particle.
- `get_draw_pass_mesh(pass: int) -> Mesh` *const* — Returns the Mesh that is drawn at index `pass`.
- `request_particles_process(process_time: float, process_time_residual: float = 0.0) -> void` — Requests the particles to process for extra process time during a single frame.
- `restart(keep_seed: bool = false) -> void` — Restarts the particle emission cycle, clearing existing particles.
- `set_draw_pass_mesh(pass: int, mesh: Mesh) -> void` — Sets the Mesh that is drawn at index `pass`.

## Signals

- `finished()` — Emitted when all active particles have finished processing.

## Enum DrawOrder

- `DRAW_ORDER_INDEX = 0` — Particles are drawn in the order emitted.
- `DRAW_ORDER_LIFETIME = 1` — Particles are drawn in order of remaining lifetime.
- `DRAW_ORDER_REVERSE_LIFETIME = 2` — Particles are drawn in reverse order of remaining lifetime.
- `DRAW_ORDER_VIEW_DEPTH = 3` — Particles are drawn in order of depth.

## Enum EmitFlags

- `EMIT_FLAG_POSITION = 1` — Particle starts at the specified position.
- `EMIT_FLAG_ROTATION_SCALE = 2` — Particle starts with specified rotation and scale.
- `EMIT_FLAG_VELOCITY = 4` — Particle starts with the specified velocity vector, which defines the emission direction and speed.
- `EMIT_FLAG_COLOR = 8` — Particle starts with specified color.
- `EMIT_FLAG_CUSTOM = 16` — Particle starts with specified `CUSTOM` data.

## Enum TransformAlign

- `TRANSFORM_ALIGN_DISABLED = 0` — Do not align particle transforms relative to the camera or velocity.
- `TRANSFORM_ALIGN_Z_BILLBOARD = 1` — Align each particle's Z axis to face the camera.
- `TRANSFORM_ALIGN_Y_TO_VELOCITY = 2` — Align each particle's Y axis to the velocity vector.
- `TRANSFORM_ALIGN_Z_BILLBOARD_Y_TO_VELOCITY = 3` — Align each particle's Z axis to face the camera and Y axis to the velocity vector.
- `TRANSFORM_ALIGN_LOCAL_BILLBOARD = 4` — Align each particle's Z axis to face the camera, while preserving a given axis (X or Y).

## Constants

- `MAX_DRAW_PASSES = 4` — Maximum number of draw passes supported.
