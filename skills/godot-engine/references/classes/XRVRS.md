# XRVRS

**Inherits:** Object

Helper class for XR interfaces that generates VRS images.

This class is used by various XR interfaces to generate VRS textures that can be used to speed up rendering.

## Properties

- `vrs_min_radius: float` = `20.0` — The minimum radius around the focal point where full quality is guaranteed if VRS is used as a percentage of screen size.
- `vrs_render_region: Rect2i` = `Rect2i(0, 0, 0, 0)` — The render region that the VRS texture will be scaled to when generated.
- `vrs_strength: float` = `1.0` — The strength used to calculate the VRS density map.

## Methods

- `make_vrs_texture(target_size: Vector2, eye_foci: PackedVector2Array) -> RID` — Generates the VRS texture based on a render `target_size` adjusted by our VRS tile size.
