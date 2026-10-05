# FogMaterial

**Inherits:** Material

A material that controls how volumetric fog is rendered, to be assigned to a FogVolume.

A Material resource that can be used by FogVolumes to draw volumetric effects. If you need more advanced effects, use a custom fog shader.

## Properties

- `albedo: Color` = `Color(1, 1, 1, 1)` — The single-scattering Color of the FogVolume.
- `density: float` = `1.0` — The density of the FogVolume.
- `density_texture: Texture3D` — The 3D texture that is used to scale the `density` of the FogVolume.
- `edge_fade: float` = `0.1` — The hardness of the edges of the FogVolume.
- `emission: Color` = `Color(0, 0, 0, 1)` — The Color of the light emitted by the FogVolume.
- `height_falloff: float` = `0.0` — The rate by which the height-based fog decreases in density as height increases in world space.
