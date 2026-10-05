# SkeletonIK3D

**Inherits:** SkeletonModifier3D
**Deprecated:** 

A node used to rotate all bones of a Skeleton3D bone chain a way that places the end bone at a desired 3D position.

SkeletonIK3D is used to rotate all bones of a Skeleton3D bone chain a way that places the end bone at a desired 3D position. A typical scenario for IK in games is to place a character's feet on the ground or a character's hands on a currently held object. SkeletonIK uses FabrikInverseKinematic internally to solve the bone chain and applies the results to the Skeleton3D `bones_global_pose_override` property for all affected bones in the chain. If fully applied, this overwrites any bone transform from Animations or bone custom poses set by users.

## Properties

- `interpolation: float` *(deprecated)* — Interpolation value for how much the IK results are applied to the current skeleton bone chain.
- `magnet: Vector3` = `Vector3(0, 0, 0)` — Secondary target position (first is `target` property or `target_node`) for the IK chain.
- `max_iterations: int` = `10` — Number of iteration loops used by the IK solver to produce more accurate (and elegant) bone chain results.
- `min_distance: float` = `0.01` — The minimum distance between bone and goal target.
- `override_tip_basis: bool` = `true` — If `true` overwrites the rotation of the tip bone with the rotation of the `target` (or `target_node` if defined).
- `root_bone: StringName` = `&""` — The name of the current root bone, the first bone in the IK chain.
- `target: Transform3D` = `Transform3D(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)` — The first target of the IK chain where the tip bone is placed and, if `override_tip_basis` is `true`, how the tip bone is rotated.
- `target_node: NodePath` = `NodePath("")` — Target node NodePath for the IK chain.
- `tip_bone: StringName` = `&""` — The name of the current tip bone, the last bone in the IK chain placed at the `target` transform (or `target_node` if defined).
- `use_magnet: bool` = `false` — If `true`, instructs the IK solver to consider the secondary magnet target (pole target) when calculating the bone chain.

## Methods

- `get_parent_skeleton() -> Skeleton3D` *const* — Returns the parent Skeleton3D node that was present when SkeletonIK entered the scene tree.
- `is_running() -> bool` — Returns `true` if SkeletonIK is applying IK effects on continues frames to the Skeleton3D bones.
- `start(one_time: bool = false) -> void` — Starts applying IK effects on each frame to the Skeleton3D bones but will only take effect starting on the next frame.
- `stop() -> void` — Stops applying IK effects on each frame to the Skeleton3D bones and also calls `Skeleton3D.clear_bones_global_pose_override` to remove existing overrides on all bones.
