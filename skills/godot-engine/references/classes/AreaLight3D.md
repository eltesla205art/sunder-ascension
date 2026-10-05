# AreaLight3D

**Inherits:** Light3D

An area light, such as a neon light tube or a screen.

An area light is a type of Light3D node that emits light over a two-dimensional area, in the shape of a rectangle. The light is attenuated throughout the distance. This attenuation can be configured by changing the energy, `area_attenuation`, and `area_range`. Light is emitted in the -Z direction of the node's global basis.

## Properties

- `area_attenuation: float` = `1.0` — Controls the distance attenuation function for this area light.
- `area_normalize_energy: bool` = `true` — Defines whether the energy is normalized (divided) by the surface area of the light.
- `area_range: float` = `5.0` — The range of the area in meters.
- `area_size: Vector2` = `Vector2(1, 1)` — The extents (width and height) of the area in meters.
- `area_texture: Texture2D` — An optional texture to use as a light source.
- `light_size: float` = `0.5` — 
- `shadow_normal_bias: float` = `1.0` —
