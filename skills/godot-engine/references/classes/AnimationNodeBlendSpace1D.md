# AnimationNodeBlendSpace1D

**Inherits:** AnimationRootNode

A set of AnimationRootNodes placed on a virtual axis, crossfading between the two adjacent ones. Used by AnimationTree.

A resource used by AnimationNodeBlendTree. AnimationNodeBlendSpace1D represents a virtual axis on which any type of AnimationRootNodes can be added using `add_blend_point`. Outputs the linear blend of the two AnimationRootNodes adjacent to the current value. You can set the extents of the axis with `min_space` and `max_space`.

## Properties

- `blend_mode: AnimationNodeBlendSpace1D.BlendMode` = `0` — Controls the interpolation between animations.
- `cyclic_length: float` = `0.0` — The cycle length in seconds used by `SYNC_MODE_CYCLIC_CONSTANT`.
- `max_space: float` = `1.0` — The blend space's axis's upper limit for the points' position.
- `min_space: float` = `-1.0` — The blend space's axis's lower limit for the points' position.
- `snap: float` = `0.1` — Position increment to snap to when moving a point on the axis.
- `sync: bool` *(deprecated)* — If `true`, sync mode is enabled (equivalent to `SYNC_MODE_INDEPENDENT`).
- `sync_mode: AnimationNodeBlendSpace1D.SyncMode` = `0` — Controls how animations are synced when blended.
- `value_label: String` = `"value"` — Label of the virtual axis of the blend space.

## Methods

- `add_blend_point(node: AnimationRootNode, pos: float, at_index: int = -1, name: StringName = &"") -> void` — Adds a new point with `name` that represents a `node` on the virtual axis at a given position set by `pos`.
- `find_blend_point_by_name(name: StringName) -> int` *const* — Returns the index of the blend point with the given `name`.
- `get_blend_point_count() -> int` *const* — Returns the number of points on the blend axis.
- `get_blend_point_name(point: int) -> StringName` *const* — Returns the name of the blend point at index `point`.
- `get_blend_point_node(point: int) -> AnimationRootNode` *const* — Returns the AnimationNode referenced by the point at index `point`.
- `get_blend_point_position(point: int) -> float` *const* — Returns the position of the point at index `point`.
- `remove_blend_point(point: int) -> void` — Removes the point at index `point` from the blend axis.
- `reorder_blend_point(from_index: int, to_index: int) -> void` — Swaps the blend points at indices `from_index` and `to_index`, exchanging their positions and properties.
- `set_blend_point_name(point: int, name: StringName) -> void` — Sets the name of the blend point at index `point`.
- `set_blend_point_node(point: int, node: AnimationRootNode) -> void` — Changes the AnimationNode referenced by the point at index `point`.
- `set_blend_point_position(point: int, pos: float) -> void` — Updates the position of the point at index `point` on the blend axis.

## Enum BlendMode

- `BLEND_MODE_INTERPOLATED = 0` — The interpolation between animations is linear.
- `BLEND_MODE_DISCRETE = 1` — The blend space plays the animation of the animation node which blending position is closest to.
- `BLEND_MODE_DISCRETE_CARRY = 2` — Similar to `BLEND_MODE_DISCRETE`, but starts the new animation at the last animation's playback position.

## Enum SyncMode

- `SYNC_MODE_NONE = 0` — Inactive animations are frozen and do not advance.
- `SYNC_MODE_INDEPENDENT = 1` — Inactive animations advance with a weight of `0`.
- `SYNC_MODE_CYCLIC_MUTABLE = 2` — All animations are time-scaled so they stay in sync, with the cycle length dynamically computed from active blend weights.
- `SYNC_MODE_CYCLIC_CONSTANT = 3` — All animations are time-scaled so they complete one cycle in `cyclic_length` seconds, keeping them in sync regardless of their individual lengths.
