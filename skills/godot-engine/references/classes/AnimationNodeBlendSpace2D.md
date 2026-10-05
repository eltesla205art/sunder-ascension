# AnimationNodeBlendSpace2D

**Inherits:** AnimationRootNode

A set of AnimationRootNodes placed on 2D coordinates, crossfading between the three adjacent ones. Used by AnimationTree.

A resource used by AnimationNodeBlendTree. AnimationNodeBlendSpace2D represents a virtual 2D space on which AnimationRootNodes are placed. Outputs the linear blend of the three adjacent animations using a Vector2 weight. Adjacent in this context means the three AnimationRootNodes making up the triangle that contains the current value.

## Properties

- `auto_triangles: bool` = `true` — If `true`, the blend space is triangulated automatically.
- `blend_mode: AnimationNodeBlendSpace2D.BlendMode` = `0` — Controls the interpolation between animations.
- `cyclic_length: float` = `0.0` — The cycle length in seconds used by `SYNC_MODE_CYCLIC_CONSTANT`.
- `max_space: Vector2` = `Vector2(1, 1)` — The blend space's X and Y axes' upper limit for the points' position.
- `min_space: Vector2` = `Vector2(-1, -1)` — The blend space's X and Y axes' lower limit for the points' position.
- `snap: Vector2` = `Vector2(0.1, 0.1)` — Position increment to snap to when moving a point.
- `sync: bool` *(deprecated)* — If `true`, sync mode is enabled (equivalent to `SYNC_MODE_INDEPENDENT`).
- `sync_mode: AnimationNodeBlendSpace2D.SyncMode` = `0` — Controls how animations are synced when blended.
- `x_label: String` = `"x"` — Name of the blend space's X axis.
- `y_label: String` = `"y"` — Name of the blend space's Y axis.

## Methods

- `add_blend_point(node: AnimationRootNode, pos: Vector2, at_index: int = -1, name: StringName = &"") -> void` — Adds a new point with `name` that represents a `node` at the position set by `pos`.
- `add_triangle(x: int, y: int, z: int, at_index: int = -1) -> void` — Creates a new triangle using three points `x`, `y`, and `z`.
- `find_blend_point_by_name(name: StringName) -> int` *const* — Returns the index of the blend point with the given `name`.
- `get_blend_point_count() -> int` *const* — Returns the number of points in the blend space.
- `get_blend_point_name(point: int) -> StringName` *const* — Returns the name of the blend point at index `point`.
- `get_blend_point_node(point: int) -> AnimationRootNode` *const* — Returns the AnimationRootNode referenced by the point at index `point`.
- `get_blend_point_position(point: int) -> Vector2` *const* — Returns the position of the point at index `point`.
- `get_triangle_count() -> int` *const* — Returns the number of triangles in the blend space.
- `get_triangle_point(triangle: int, point: int) -> int` — Returns the position of the point at index `point` in the triangle of index `triangle`.
- `remove_blend_point(point: int) -> void` — Removes the point at index `point` from the blend space.
- `remove_triangle(triangle: int) -> void` — Removes the triangle at index `triangle` from the blend space.
- `reorder_blend_point(from_index: int, to_index: int) -> void` — Swaps the blend points at indices `from_index` and `to_index`, exchanging their positions and properties.
- `set_blend_point_name(point: int, name: StringName) -> void` — Sets the name of the blend point at index `point`.
- `set_blend_point_node(point: int, node: AnimationRootNode) -> void` — Changes the AnimationNode referenced by the point at index `point`.
- `set_blend_point_position(point: int, pos: Vector2) -> void` — Updates the position of the point at index `point` in the blend space.

## Signals

- `triangles_updated()` — Emitted every time the blend space's triangles are created, removed, or when one of their vertices changes position.

## Enum BlendMode

- `BLEND_MODE_INTERPOLATED = 0` — The interpolation between animations is linear.
- `BLEND_MODE_DISCRETE = 1` — The blend space plays the animation of the animation node which blending position is closest to.
- `BLEND_MODE_DISCRETE_CARRY = 2` — Similar to `BLEND_MODE_DISCRETE`, but starts the new animation at the last animation's playback position.

## Enum SyncMode

- `SYNC_MODE_NONE = 0` — Inactive animations are frozen and do not advance.
- `SYNC_MODE_INDEPENDENT = 1` — Inactive animations advance with a weight of `0`.
- `SYNC_MODE_CYCLIC_MUTABLE = 2` — All animations are time-scaled so they stay in sync, with the cycle length dynamically computed from active blend weights.
- `SYNC_MODE_CYCLIC_CONSTANT = 3` — All animations are time-scaled so they complete one cycle in `cyclic_length` seconds, keeping them in sync regardless of their individual lengths.
