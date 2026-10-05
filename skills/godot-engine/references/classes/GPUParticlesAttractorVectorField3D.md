# GPUParticlesAttractorVectorField3D

**Inherits:** GPUParticlesAttractor3D

A box-shaped attractor with varying directions and strengths defined in it that influences particles from GPUParticles3D nodes.

A box-shaped attractor with varying directions and strengths defined in it that influences particles from GPUParticles3D nodes. Unlike GPUParticlesAttractorBox3D, GPUParticlesAttractorVectorField3D uses a `texture` to affect attraction strength within the box. This can be used to create complex attraction scenarios where particles travel in different directions depending on their location. This can be useful for weather effects such as sandstorms.

## Properties

- `size: Vector3` = `Vector3(2, 2, 2)` — The size of the vector field box in 3D units.
- `texture: Texture3D` — The 3D texture to be used.
