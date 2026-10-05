# Path2D

**Inherits:** Node2D

Contains a Curve2D path for PathFollow2D nodes to follow.

Can have PathFollow2D child nodes moving along the Curve2D. See PathFollow2D for more information on usage. Note: The path is considered as relative to the moved nodes (children of PathFollow2D). As such, the curve should usually start with a zero vector (`(0, 0)`).

## Properties

- `curve: Curve2D` — A Curve2D describing the path.
