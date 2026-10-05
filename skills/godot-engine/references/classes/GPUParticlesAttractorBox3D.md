# GPUParticlesAttractorBox3D

**Inherits:** GPUParticlesAttractor3D

A box-shaped attractor that influences particles from GPUParticles3D nodes.

A box-shaped attractor that influences particles from GPUParticles3D nodes. Can be used to attract particles towards its origin, or to push them away from its origin. Particle attractors work in real-time and can be moved, rotated and scaled during gameplay. Unlike collision shapes, non-uniform scaling of attractors is also supported.

## Properties

- `size: Vector3` = `Vector3(2, 2, 2)` — The attractor box's size in 3D units.
