# BoneAttachment3D

**Inherits:** Node3D

А node that dynamically copies or overrides the 3D transform of a bone in its parent Skeleton3D.

This node selects a bone in a Skeleton3D and attaches to it. This means that the BoneAttachment3D node will either dynamically copy or override the 3D transform of the selected bone.

## Properties

- `bone_idx: int` = `-1` — The index of the attached bone.
- `bone_name: String` = `""` — The name of the attached bone.
- `external_skeleton: NodePath` — The NodePath to the external Skeleton3D node.
- `override_pose: bool` = `false` — Whether the BoneAttachment3D node will override the bone pose of the bone it is attached to.
- `physics_interpolation_mode: Node.PhysicsInterpolationMode` = `2` — 
- `use_external_skeleton: bool` = `false` — Whether the BoneAttachment3D node will use an external Skeleton3D node rather than attempting to use its parent node as the Skeleton3D.

## Methods

- `get_skeleton() -> Skeleton3D` — Returns the parent or external Skeleton3D node if it exists, otherwise returns `null`.
- `on_skeleton_update() -> void` — A function that is called automatically when the Skeleton3D is updated.
