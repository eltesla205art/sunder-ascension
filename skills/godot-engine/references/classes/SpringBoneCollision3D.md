# SpringBoneCollision3D

**Inherits:** Node3D

A base class of the collision that interacts with SpringBoneSimulator3D.

A collision can be a child of SpringBoneSimulator3D. If it is not a child of SpringBoneSimulator3D, it has no effect. The colliding and sliding are done in the SpringBoneSimulator3D's modification process in order of its collision list which is set by `SpringBoneSimulator3D.set_collision_path`. If `SpringBoneSimulator3D.are_all_child_collisions_enabled` is `true`, the order matches SceneTree.

## Properties

- `bone: int` = `-1` — The index of the attached bone.
- `bone_name: String` = `""` — The name of the attached bone.
- `physics_interpolation_mode: Node.PhysicsInterpolationMode` = `2` — 
- `position_offset: Vector3` — The offset of the position from Skeleton3D's `bone` pose position.
- `rotation_offset: Quaternion` — The offset of the rotation from Skeleton3D's `bone` pose rotation.

## Methods

- `get_skeleton() -> Skeleton3D` *const* — Get parent Skeleton3D node of the parent SpringBoneSimulator3D if found.
