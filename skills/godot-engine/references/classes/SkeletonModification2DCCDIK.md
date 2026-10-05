# SkeletonModification2DCCDIK

**Inherits:** SkeletonModification2D

A modification that uses CCDIK to manipulate a series of bones to reach a target in 2D.

This SkeletonModification2D uses an algorithm called Cyclic Coordinate Descent Inverse Kinematics, or CCDIK, to manipulate a chain of bones in a Skeleton2D so it reaches a defined target. CCDIK works by rotating a set of bones, typically called a "bone chain", on a single axis. Each bone is rotated to face the target from the tip (by default), which over a chain of bones allow it to rotate properly to reach the target. Because the bones only rotate on a single axis, CCDIK can look more robotic than other IK solvers.

## Properties

- `ccdik_data_chain_length: int` = `0` — The number of CCDIK joints in the CCDIK modification.
- `target_nodepath: NodePath` = `NodePath("")` — The NodePath to the node that is the target for the CCDIK modification.
- `tip_nodepath: NodePath` = `NodePath("")` — The end position of the CCDIK chain.

## Methods

- `get_ccdik_joint_bone2d_node(joint_idx: int) -> NodePath` *const* — Returns the Bone2D node assigned to the CCDIK joint at `joint_idx`.
- `get_ccdik_joint_bone_index(joint_idx: int) -> int` *const* — Returns the index of the Bone2D node assigned to the CCDIK joint at `joint_idx`.
- `get_ccdik_joint_constraint_angle_invert(joint_idx: int) -> bool` *const* — Returns whether the CCDIK joint at `joint_idx` uses an inverted joint constraint.
- `get_ccdik_joint_constraint_angle_max(joint_idx: int) -> float` *const* — Returns the maximum angle constraint for the joint at `joint_idx`.
- `get_ccdik_joint_constraint_angle_min(joint_idx: int) -> float` *const* — Returns the minimum angle constraint for the joint at `joint_idx`.
- `get_ccdik_joint_enable_constraint(joint_idx: int) -> bool` *const* — Returns whether angle constraints on the CCDIK joint at `joint_idx` are enabled.
- `get_ccdik_joint_rotate_from_joint(joint_idx: int) -> bool` *const* — Returns whether the joint at `joint_idx` is set to rotate from the joint, `true`, or to rotate from the tip, `false`.
- `set_ccdik_joint_bone2d_node(joint_idx: int, bone2d_nodepath: NodePath) -> void` — Sets the Bone2D node assigned to the CCDIK joint at `joint_idx`.
- `set_ccdik_joint_bone_index(joint_idx: int, bone_idx: int) -> void` — Sets the bone index, `bone_idx`, of the CCDIK joint at `joint_idx`.
- `set_ccdik_joint_constraint_angle_invert(joint_idx: int, invert: bool) -> void` — Sets whether the CCDIK joint at `joint_idx` uses an inverted joint constraint.
- `set_ccdik_joint_constraint_angle_max(joint_idx: int, angle_max: float) -> void` — Sets the maximum angle constraint for the joint at `joint_idx`.
- `set_ccdik_joint_constraint_angle_min(joint_idx: int, angle_min: float) -> void` — Sets the minimum angle constraint for the joint at `joint_idx`.
- `set_ccdik_joint_enable_constraint(joint_idx: int, enable_constraint: bool) -> void` — Determines whether angle constraints on the CCDIK joint at `joint_idx` are enabled.
- `set_ccdik_joint_rotate_from_joint(joint_idx: int, rotate_from_joint: bool) -> void` — Sets whether the joint at `joint_idx` is set to rotate from the joint, `true`, or to rotate from the tip, `false`.
