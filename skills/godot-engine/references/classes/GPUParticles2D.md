# GPUParticles2D

**Inherits:** Node2D

A 2D particle emitter.

2D particle node used to create a variety of particle systems and effects. GPUParticles2D features an emitter that generates some number of particles at a given rate. Use the `process_material` property to add a ParticleProcessMaterial to configure particle appearance and behavior. Alternatively, you can add a ShaderMaterial which will be applied to all particles. 2D particles can optionally collide with LightOccluder2D, but they don't collide with PhysicsBody2D nodes.

## Properties

- `amount: int` = `8` — The number of particles to emit in one emission cycle.
- `amount_ratio: float` = `1.0` — The ratio of particles that should actually be emitted.
- `collision_base_size: float` = `1.0` — Multiplier for particle's collision radius.
- `draw_order: GPUParticles2D.DrawOrder` = `1` — Particle draw order.
- `emitting: bool` = `true` — If `true`, particles are being emitted.
- `explosiveness: float` = `0.0` — How rapidly particles in an emission cycle are emitted.
- `fixed_fps: int` = `30` — The particle system's frame rate is fixed to a value.
- `fract_delta: bool` = `true` — If `true`, results in fractional delta calculation which has a smoother particles display effect.
- `interp_to_end: float` = `0.0` — Causes all the particles in this node to interpolate towards the end of their lifetime.
- `interpolate: bool` = `true` — Enables particle interpolation, which makes the particle movement smoother when their `fixed_fps` is lower than the screen refresh rate.
- `lifetime: float` = `1.0` — The amount of time each particle will exist (in seconds).
- `local_coords: bool` = `false` — If `true`, particles use the parent node's coordinate space (known as local coordinates).
- `one_shot: bool` = `false` — If `true`, only one emission cycle occurs.
- `preprocess: float` = `0.0` — Particle system starts as if it had already run for this many seconds.
- `process_material: Material` — Material for processing particles.
- `randomness: float` = `0.0` — Emission lifetime randomness ratio.
- `seed: int` = `0` — Sets the random seed used by the particle system.
- `speed_scale: float` = `1.0` — Particle system's running speed scaling ratio.
- `sub_emitter: NodePath` = `NodePath("")` — Path to another GPUParticles2D node that will be used as a subemitter (see `ParticleProcessMaterial.sub_emitter_mode`).
- `texture: Texture2D` — Particle texture.
- `trail_enabled: bool` = `false` — If `true`, enables particle trails using a mesh skinning system.
- `trail_lifetime: float` = `0.3` — The amount of time the particle's trail should represent (in seconds).
- `trail_section_subdivisions: int` = `4` — The number of subdivisions to use for the particle trail rendering.
- `trail_sections: int` = `8` — The number of sections to use for the particle trail rendering.
- `use_fixed_seed: bool` = `false` — If `true`, particles will use the same seed for every simulation using the seed defined in `seed`.
- `visibility_rect: Rect2` = `Rect2(-100, -100, 200, 200)` — The Rect2 that determines the node's region which needs to be visible on screen for the particle system to be active.

## Methods

- `capture_rect() -> Rect2` *const* — Returns a rectangle containing the positions of all existing particles.
- `convert_from_particles(particles: Node) -> void` — Sets this node's properties to match a given CPUParticles2D node.
- `emit_particle(xform: Transform2D, velocity: Vector2, color: Color, custom: Color, flags: int) -> void` — Emits a single particle.
- `request_particles_process(process_time: float, process_time_residual: float = 0) -> void` — Requests the particles to process for extra process time during a single frame.
- `restart(keep_seed: bool = false) -> void` — Restarts the particle emission cycle, clearing existing particles.

## Signals

- `finished()` — Emitted when all active particles have finished processing.

## Enum DrawOrder

- `DRAW_ORDER_INDEX = 0` — Particles are drawn in the order emitted.
- `DRAW_ORDER_LIFETIME = 1` — Particles are drawn in order of remaining lifetime.
- `DRAW_ORDER_REVERSE_LIFETIME = 2` — Particles are drawn in reverse order of remaining lifetime.

## Enum EmitFlags

- `EMIT_FLAG_POSITION = 1` — Particle starts at the specified position.
- `EMIT_FLAG_ROTATION_SCALE = 2` — Particle starts with specified rotation and scale.
- `EMIT_FLAG_VELOCITY = 4` — Particle starts with the specified velocity vector, which defines the emission direction and speed.
- `EMIT_FLAG_COLOR = 8` — Particle starts with specified color.
- `EMIT_FLAG_CUSTOM = 16` — Particle starts with specified `CUSTOM` data.
