# SkeletonModification2DLookAt

**Inherits:** SkeletonModification2D

A modification that rotates a Bone2D node to look at a target.

This SkeletonModification2D rotates a bone to look a target. This is extremely helpful for moving character's head to look at the player, rotating a turret to look at a target, or any other case where you want to make a bone rotate towards something quickly and easily.

## Properties

- `bone2d_node: NodePath` = `NodePath("")` — The Bone2D node that the modification will operate on.
- `bone_index: int` = `-1` — The index of the Bone2D node that the modification will operate on.
- `target_nodepath: NodePath` = `NodePath("")` — The NodePath to the node that is the target for the LookAt modification.

## Methods

- `get_additional_rotation() -> float` *const* — Returns the amount of additional rotation that is applied after the LookAt modification executes.
- `get_constraint_angle_invert() -> bool` *const* — Returns whether the constraints to this modification are inverted or not.
- `get_constraint_angle_max() -> float` *const* — Returns the constraint's maximum allowed angle.
- `get_constraint_angle_min() -> float` *const* — Returns the constraint's minimum allowed angle.
- `get_enable_constraint() -> bool` *const* — Returns `true` if the LookAt modification is using constraints.
- `set_additional_rotation(rotation: float) -> void` — Sets the amount of additional rotation that is to be applied after executing the modification.
- `set_constraint_angle_invert(invert: bool) -> void` — When `true`, the modification will use an inverted joint constraint.
- `set_constraint_angle_max(angle_max: float) -> void` — Sets the constraint's maximum allowed angle.
- `set_constraint_angle_min(angle_min: float) -> void` — Sets the constraint's minimum allowed angle.
- `set_enable_constraint(enable_constraint: bool) -> void` — Sets whether this modification will use constraints or not.
