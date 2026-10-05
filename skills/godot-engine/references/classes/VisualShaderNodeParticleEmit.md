# VisualShaderNodeParticleEmit

**Inherits:** VisualShaderNode

A visual shader node that forces to emit a particle from a sub-emitter.

This node calls the internal `emit_subparticle` method. It will emit a particle from the configured sub-emitter and also allows to customize how it's emitted. Requires a sub-emitter assigned to the particles node that is using this shader.

## Properties

- `flags: VisualShaderNodeParticleEmit.EmitFlags` = `31` — Flags used to override the properties defined in the sub-emitter's process material.

## Enum EmitFlags

- `EMIT_FLAG_POSITION = 1` — If enabled, the particle starts with the position defined by this node.
- `EMIT_FLAG_ROT_SCALE = 2` — If enabled, the particle starts with the rotation and scale defined by this node.
- `EMIT_FLAG_VELOCITY = 4` — If enabled,the particle starts with the velocity defined by this node.
- `EMIT_FLAG_COLOR = 8` — If enabled, the particle starts with the color defined by this node.
- `EMIT_FLAG_CUSTOM = 16` — If enabled, the particle starts with the `CUSTOM` data defined by this node.
