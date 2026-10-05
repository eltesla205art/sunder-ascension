# PathFollow2D

**Inherits:** Node2D

Point sampler for a Path2D.

This node takes its parent Path2D, and returns the coordinates of a point within it, given a distance from the first vertex. It is useful for making other nodes follow a path, without coding the movement pattern. For that, the nodes must be children of this node. The descendant nodes will then move accordingly when setting the `progress` in this node.

## Properties

- `cubic_interp: bool` = `true` — If `true`, the position between two cached points is interpolated cubically, and linearly otherwise.
- `h_offset: float` = `0.0` — The node's offset along the curve.
- `loop: bool` = `true` — If `true`, any offset outside the path's length will wrap around, instead of stopping at the ends.
- `progress: float` = `0.0` — The distance along the path, in pixels.
- `progress_ratio: float` = `0.0` — The distance along the path as a number in the range 0.0 (for the first vertex) to 1.0 (for the last).
- `rotates: bool` = `true` — If `true`, this node rotates to follow the path, with the +X direction facing forward on the path.
- `v_offset: float` = `0.0` — The node's offset perpendicular to the curve.
