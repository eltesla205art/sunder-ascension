# VisualShaderNodeParticleEmitter

**Inherits:** VisualShaderNode

A base class for particle emitters.

Particle emitter nodes can be used in "start" step of particle shaders and they define the starting position of the particles. Connect them to the Position output port.

## Properties

- `mode_2d: bool` = `false` — If `true`, the result of this emitter is projected to 2D space.
