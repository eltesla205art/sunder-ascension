# SkeletonModification2DTwoBoneIK

**Inherits:** SkeletonModification2D

A modification that rotates two bones using the law of cosines to reach the target.

This SkeletonModification2D uses an algorithm typically called TwoBoneIK. This algorithm works by leveraging the law of cosines and the lengths of the bones to figure out what rotation the bones currently have, and what rotation they need to make a complete triangle, where the first bone, the second bone, and the target form the three vertices of the triangle. Because the algorithm works by making a triangle, it can only operate on two bones. TwoBoneIK is great for arms, legs, and really any joints that can be represented by just two bones that bend to reach a target.

## Properties

- `flip_bend_direction: bool` = `false` — If `true`, the bones in the modification will bend outward as opposed to inwards when contracting.
- `target_maximum_distance: float` = `0.0` — The maximum distance the target can be at.
- `target_minimum_distance: float` = `0.0` — The minimum distance the target can be at.
- `target_nodepath: NodePath` = `NodePath("")` — The NodePath to the node that is the target for the TwoBoneIK modification.

## Methods

- `get_joint_one_bone2d_node() -> NodePath` *const* — Returns the Bone2D node that is being used as the first bone in the TwoBoneIK modification.
- `get_joint_one_bone_idx() -> int` *const* — Returns the index of the Bone2D node that is being used as the first bone in the TwoBoneIK modification.
- `get_joint_two_bone2d_node() -> NodePath` *const* — Returns the Bone2D node that is being used as the second bone in the TwoBoneIK modification.
- `get_joint_two_bone_idx() -> int` *const* — Returns the index of the Bone2D node that is being used as the second bone in the TwoBoneIK modification.
- `set_joint_one_bone2d_node(bone2d_node: NodePath) -> void` — Sets the Bone2D node that is being used as the first bone in the TwoBoneIK modification.
- `set_joint_one_bone_idx(bone_idx: int) -> void` — Sets the index of the Bone2D node that is being used as the first bone in the TwoBoneIK modification.
- `set_joint_two_bone2d_node(bone2d_node: NodePath) -> void` — Sets the Bone2D node that is being used as the second bone in the TwoBoneIK modification.
- `set_joint_two_bone_idx(bone_idx: int) -> void` — Sets the index of the Bone2D node that is being used as the second bone in the TwoBoneIK modification.
