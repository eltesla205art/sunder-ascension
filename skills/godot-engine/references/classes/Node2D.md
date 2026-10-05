# Node2D

**Inherits:** CanvasItem

A 2D game object, inherited by all 2D-related nodes. Has a position, rotation, scale, and skew.

A 2D game object, with a transform (position, rotation, and scale). All 2D nodes, including physics objects and sprites, inherit from Node2D. Use Node2D as a parent node to move, scale and rotate children in a 2D project. Also gives control of the node's render order.

## Properties

- `global_position: Vector2` — Global position.
- `global_rotation: float` — Global rotation in radians.
- `global_rotation_degrees: float` — Helper property to access `global_rotation` in degrees instead of radians.
- `global_scale: Vector2` — Global scale.
- `global_skew: float` — Global skew in radians.
- `global_transform: Transform2D` — Global Transform2D.
- `position: Vector2` = `Vector2(0, 0)` — Position, relative to the node's parent.
- `rotation: float` = `0.0` — Rotation in radians, relative to the node's parent.
- `rotation_degrees: float` — Helper property to access `rotation` in degrees instead of radians.
- `scale: Vector2` = `Vector2(1, 1)` — The node's scale, relative to the node's parent.
- `skew: float` = `0.0` — If set to a non-zero value, slants the node in one direction or another.
- `transform: Transform2D` — The node's Transform2D, relative to the node's parent.

## Methods

- `apply_scale(ratio: Vector2) -> void` — Multiplies the current scale by the `ratio` vector.
- `get_angle_to(point: Vector2) -> float` *const* — Returns the angle between the node and the `point` in radians.
- `get_relative_transform_to_parent(parent: Node) -> Transform2D` *const* — Returns the Transform2D relative to this node's parent.
- `global_translate(offset: Vector2) -> void` — Adds the `offset` vector to the node's global position.
- `look_at(point: Vector2) -> void` — Rotates the node so that its local +X axis points towards the `point`, which is expected to use global coordinates.
- `move_local_x(delta: float, scaled: bool = false) -> void` — Applies a local translation on the node's X axis with the amount specified in `delta`.
- `move_local_y(delta: float, scaled: bool = false) -> void` — Applies a local translation on the node's Y axis with the amount specified in `delta`.
- `rotate(radians: float) -> void` — Applies a rotation to the node, in radians, starting from its current rotation.
- `to_global(local_point: Vector2) -> Vector2` *const* — Transforms the provided local position into a position in global coordinate space.
- `to_local(global_point: Vector2) -> Vector2` *const* — Transforms the provided global position into a position in local coordinate space.
- `translate(offset: Vector2) -> void` — Translates the node by the given `offset` in local coordinates.
