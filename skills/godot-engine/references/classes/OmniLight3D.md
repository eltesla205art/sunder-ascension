# OmniLight3D

**Inherits:** Light3D

Omnidirectional light, such as a light bulb or a candle.

An Omnidirectional light is a type of Light3D that emits light in all directions. The light is attenuated by distance and this attenuation can be configured by changing its energy, radius, and attenuation parameters. Note: When using the Mobile rendering method, only 8 omni lights can be displayed on each mesh resource. Attempting to display more than 8 omni lights on a single mesh resource will result in omni lights flickering in and out as the camera moves.

## Properties

- `light_specular: float` = `0.5` — 
- `omni_attenuation: float` = `1.0` — Controls the distance attenuation function for omnilights.
- `omni_range: float` = `5.0` — The light's radius.
- `omni_shadow_mode: OmniLight3D.ShadowMode` = `1` — 
- `shadow_normal_bias: float` = `1.0` — 

## Enum ShadowMode

- `SHADOW_DUAL_PARABOLOID = 0` — Shadows are rendered to a dual-paraboloid texture.
- `SHADOW_CUBE = 1` — Shadows are rendered to a cubemap.
