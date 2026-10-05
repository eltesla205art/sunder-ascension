# SkeletonModification2DFABRIK

**Inherits:** SkeletonModification2D

A modification that uses FABRIK to manipulate a series of Bone2D nodes to reach a target.

This SkeletonModification2D uses an algorithm called Forward And Backward Reaching Inverse Kinematics, or FABRIK, to rotate a bone chain so that it reaches a target. FABRIK works by knowing the positions and lengths of a series of bones, typically called a "bone chain". It first starts by running a forward pass, which places the final bone at the target's position. Then all other bones are moved towards the tip bone, so they stay at the defined bone length away.

## Properties

- `fabrik_data_chain_length: int` = `0` — The number of FABRIK joints in the FABRIK modification.
- `target_nodepath: NodePath` = `NodePath("")` — The NodePath to the node that is the target for the FABRIK modification.

## Methods

- `get_fabrik_joint_bone2d_node(joint_idx: int) -> NodePath` *const* — Returns the Bone2D node assigned to the FABRIK joint at `joint_idx`.
- `get_fabrik_joint_bone_index(joint_idx: int) -> int` *const* — Returns the index of the Bone2D node assigned to the FABRIK joint at `joint_idx`.
- `get_fabrik_joint_magnet_position(joint_idx: int) -> Vector2` *const* — Returns the magnet position vector for the joint at `joint_idx`.
- `get_fabrik_joint_use_target_rotation(joint_idx: int) -> bool` *const* — Returns whether the joint is using the target's rotation rather than allowing FABRIK to rotate the joint.
- `set_fabrik_joint_bone2d_node(joint_idx: int, bone2d_nodepath: NodePath) -> void` — Sets the Bone2D node assigned to the FABRIK joint at `joint_idx`.
- `set_fabrik_joint_bone_index(joint_idx: int, bone_idx: int) -> void` — Sets the bone index, `bone_idx`, of the FABRIK joint at `joint_idx`.
- `set_fabrik_joint_magnet_position(joint_idx: int, magnet_position: Vector2) -> void` — Sets the magnet position vector for the joint at `joint_idx`.
- `set_fabrik_joint_use_target_rotation(joint_idx: int, use_target_rotation: bool) -> void` — Sets whether the joint at `joint_idx` will use the target node's rotation rather than letting FABRIK rotate the node.
