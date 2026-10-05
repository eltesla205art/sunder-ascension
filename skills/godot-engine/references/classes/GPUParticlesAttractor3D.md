# GPUParticlesAttractor3D

**Inherits:** VisualInstance3D

Abstract base class for 3D particle attractors.

Particle attractors can be used to attract particles towards the attractor's origin, or to push them away from the attractor's origin. Particle attractors work in real-time and can be moved, rotated and scaled during gameplay. Unlike collision shapes, non-uniform scaling of attractors is also supported. Attractors can be temporarily disabled by hiding them, or by setting their `strength` to `0.0`.

## Properties

- `attenuation: float` = `1.0` — The particle attractor's attenuation.
- `cull_mask: int` = `4294967295` — The particle rendering layers (`VisualInstance3D.layers`) that will be affected by the attractor.
- `directionality: float` = `0.0` — Adjusts how directional the attractor is.
- `strength: float` = `1.0` — Adjusts the strength of the attractor.
