# Bone2D

**Inherits:** Node2D

A joint used with Skeleton2D to control and animate other nodes.

A hierarchy of Bone2Ds can be bound to a Skeleton2D to control and animate other Node2D nodes. You can use Bone2D and Skeleton2D nodes to animate 2D meshes created with the Polygon2D UV editor. Each bone has a `rest` transform that you can reset to with `apply_rest`. These rest poses are relative to the bone's parent.

## Properties

- `rest: Transform2D` = `Transform2D(0, 0, 0, 0, 0, 0)` — Rest transform of the bone.

## Methods

- `apply_rest() -> void` — Resets the bone to the rest pose.
- `get_autocalculate_length_and_angle() -> bool` *const* — Returns whether this Bone2D is going to autocalculate its length and bone angle using its first Bone2D child node, if one exists.
- `get_bone_angle() -> float` *const* — Returns the angle of the bone in the Bone2D.
- `get_index_in_skeleton() -> int` *const* — Returns the node's index as part of the entire skeleton.
- `get_length() -> float` *const* — Returns the length of the bone in the Bone2D node.
- `get_skeleton_rest() -> Transform2D` *const* — Returns the node's `rest` Transform2D if it doesn't have a parent, or its rest pose relative to its parent.
- `set_autocalculate_length_and_angle(auto_calculate: bool) -> void` — When set to `true`, the Bone2D node will attempt to automatically calculate the bone angle and length using the first child Bone2D node, if one exists.
- `set_bone_angle(angle: float) -> void` — Sets the bone angle for the Bone2D.
- `set_length(length: float) -> void` — Sets the length of the bone in the Bone2D.
