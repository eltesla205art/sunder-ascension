# ProceduralSkyMaterial

**Inherits:** Material

A material that defines a simple sky for a Sky resource.

ProceduralSkyMaterial provides a way to create an effective background quickly by defining procedural parameters for the sun, the sky and the ground. The sky and ground are defined by a main color, a color at the horizon, and an easing curve to interpolate between them. Suns are described by a position in the sky, a color, and a max angle from the sun at which the easing curve ends. The max angle therefore defines the size of the sun in the sky.

## Properties

- `energy_multiplier: float` = `1.0` — The sky's overall brightness multiplier.
- `ground_bottom_color: Color` = `Color(0.2, 0.169, 0.133, 1)` — Color of the ground at the bottom.
- `ground_curve: float` = `0.02` — How quickly the `ground_horizon_color` fades into the `ground_bottom_color`.
- `ground_energy_multiplier: float` = `1.0` — Multiplier for ground color.
- `ground_horizon_color: Color` = `Color(0.6463, 0.6558, 0.6708, 1)` — Color of the ground at the horizon.
- `sky_cover: Texture2D` — The sky cover texture to use.
- `sky_cover_modulate: Color` = `Color(1, 1, 1, 1)` — The tint to apply to the `sky_cover` texture.
- `sky_curve: float` = `0.15` — How quickly the `sky_horizon_color` fades into the `sky_top_color`.
- `sky_energy_multiplier: float` = `1.0` — Multiplier for sky color.
- `sky_horizon_color: Color` = `Color(0.6463, 0.6558, 0.6708, 1)` — Color of the sky at the horizon.
- `sky_top_color: Color` = `Color(0.385, 0.454, 0.55, 1)` — Color of the sky at the top.
- `sun_angle_max: float` = `30.0` — Distance from center of sun where it fades out completely.
- `sun_curve: float` = `0.15` — How quickly the sun fades away between the edge of the sun disk and `sun_angle_max`.
- `use_debanding: bool` = `true` — If `true`, enables debanding.
