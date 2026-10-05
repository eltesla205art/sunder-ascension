# ModifierBoneTarget3D

**Inherits:** SkeletonModifier3D

А node that dynamically copies the 3D transform of a bone in its parent Skeleton3D.

This node selects a bone in a Skeleton3D and attaches to it. This means that the ModifierBoneTarget3D node will dynamically copy the 3D transform of the selected bone. The functionality is similar to BoneAttachment3D, but this node adopts the SkeletonModifier3D cycle and is intended to be used as another SkeletonModifier3D's target.

## Properties

- `bone: int` = `-1` — The index of the attached bone.
- `bone_name: String` = `""` — The name of the attached bone.
- `physics_interpolation_mode: Node.PhysicsInterpolationMode` = `2` —
