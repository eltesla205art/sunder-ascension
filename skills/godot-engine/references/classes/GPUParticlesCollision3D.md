# GPUParticlesCollision3D

**Inherits:** VisualInstance3D

Abstract base class for 3D particle collision shapes affecting GPUParticles3D nodes.

Particle collision shapes can be used to make particles stop or bounce against them. Particle collision shapes work in real-time and can be moved, rotated and scaled during gameplay. Unlike attractors, non-uniform scaling of collision shapes is not supported. Particle collision shapes can be temporarily disabled by hiding them.

## Properties

- `cull_mask: int` = `4294967295` — The particle rendering layers (`VisualInstance3D.layers`) that will be affected by the collision shape.
