# Trail3D

**Inherits:** Line3D

A node to draw lines behind moving objects.

The Trail3D node draws a flat line in space, with an optional billboard mode. Note: This node is designed for visual effects. For solid lines, pipes, and tubes, use a CSGPolygon3D node in `CSGPolygon3D.MODE_PATH` mode.

## Properties

- `color: Color` = `Color(1, 1, 1, 1)` — The color of the trail.
- `color_gradient: Gradient` — The color gradient over the trail length.
- `emitting: bool` = `true` — If `true`, the trail will generate new points from its head.
- `lifetime: float` = `0.2` — The lifetime of the trail when `limit_mode` is `LIMIT_MODE_LIFETIME`.
- `limit_mode: Trail3D.LimitMode` = `0` — Whether to limit the trail by lifetime or length.
- `material: ShaderMaterial` — The material to assign to the trail mesh when `material_mode` is `Line3D.MATERIAL_MODE_CUSTOM`.
- `material_mode: Line3D.MaterialMode` = `0` — The material mode for the trail.
- `max_length: float` — The maximum length of the trail when `limit_mode` is `LIMIT_MODE_MAX_LENGTH`.
- `mesh_alignment: Line3D.MeshAlignment` = `1` — Alignment of the trail.
- `min_section_length: float` = `0.2` — Minimum required distance before adding a new section.
- `pin_uv: bool` = `false` — If `true`, pins the UVs to their positions in space.
- `tiling_mode: Line3D.TilingMode` = `1` — How to tile the UVs across the length of the trail.
- `tiling_multiplier: float` = `1.0` — UV multiplier across the length of the trail.
- `width: float` = `0.3` — Width of the trail.
- `width_curve: Curve` — Width across the length of the trail.

## Methods

- `clear() -> void` — Clears the trail.
- `get_current_length() -> float` *const* — Returns the current length of the trail.

## Enum LimitMode

- `LIMIT_MODE_LIFETIME = 0` — Limit the trail length in time.
- `LIMIT_MODE_MAX_LENGTH = 1` — Limit the trail length in size.
- `LIMIT_MODE_MAX = 2` — Represents the size of the `LimitMode` enum.
