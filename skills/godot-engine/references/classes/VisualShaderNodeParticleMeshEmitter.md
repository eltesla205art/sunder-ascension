# VisualShaderNodeParticleMeshEmitter

**Inherits:** VisualShaderNodeParticleEmitter

A visual shader node that makes particles emitted in a shape defined by a Mesh.

VisualShaderNodeParticleEmitter that makes the particles emitted in a shape of the assigned `mesh`. It will emit from the mesh's surfaces, either all or only the specified one.

## Properties

- `mesh: Mesh` — The Mesh that defines emission shape.
- `surface_index: int` = `0` — Index of the surface that emits particles.
- `use_all_surfaces: bool` = `true` — If `true`, the particles will emit from all surfaces of the mesh.
