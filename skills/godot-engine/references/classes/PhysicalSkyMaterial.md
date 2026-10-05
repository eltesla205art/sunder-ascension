# PhysicalSkyMaterial

**Inherits:** Material

A material that defines a sky for a Sky resource by a set of physical properties.

The PhysicalSkyMaterial uses the Preetham analytic daylight model to draw a sky based on physical properties. This results in a substantially more realistic sky than the ProceduralSkyMaterial, but it is slightly slower and less flexible. The PhysicalSkyMaterial only supports one sun. The color, energy, and direction of the sun are taken from the first DirectionalLight3D in the scene tree.

## Properties

- `energy_multiplier: float` = `1.0` — The sky's overall brightness multiplier.
- `ground_color: Color` = `Color(0.1, 0.07, 0.034, 1)` — Modulates the Color on the bottom half of the sky to represent the ground.
- `mie_coefficient: float` = `0.005` — Controls the strength of Mie scattering for the sky.
- `mie_color: Color` = `Color(0.69, 0.729, 0.812, 1)` — Controls the Color of the Mie scattering effect.
- `mie_eccentricity: float` = `0.8` — Controls the direction of the Mie scattering.
- `night_sky: Texture2D` — Texture2D for the night sky.
- `rayleigh_coefficient: float` = `2.0` — Controls the strength of the Rayleigh scattering.
- `rayleigh_color: Color` = `Color(0.3, 0.405, 0.6, 1)` — Controls the Color of the Rayleigh scattering.
- `sun_disk_scale: float` = `1.0` — Sets the size of the sun disk.
- `turbidity: float` = `10.0` — Sets the thickness of the atmosphere.
- `use_debanding: bool` = `true` — If `true`, enables debanding.
