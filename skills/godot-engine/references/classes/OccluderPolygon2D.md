# OccluderPolygon2D

**Inherits:** Resource

Defines a 2D polygon for LightOccluder2D.

Editor facility that helps you draw a 2D polygon used as resource for LightOccluder2D.

## Properties

- `closed: bool` = `true` — If `true`, closes the polygon.
- `cull_mode: OccluderPolygon2D.CullMode` = `0` — The culling mode to use.
- `polygon: PackedVector2Array` = `PackedVector2Array()` — A Vector2 array with the index for polygon's vertices positions.

## Enum CullMode

- `CULL_DISABLED = 0` — Culling is disabled.
- `CULL_CLOCKWISE = 1` — Culling is performed in the clockwise direction.
- `CULL_COUNTER_CLOCKWISE = 2` — Culling is performed in the counterclockwise direction.
