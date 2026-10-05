# PhysicalBone2D

**Inherits:** RigidBody2D

A RigidBody2D-derived node used to make Bone2Ds in a Skeleton2D react to physics.

The PhysicalBone2D node is a RigidBody2D-based node that can be used to make Bone2Ds in a Skeleton2D react to physics. Note: To make the Bone2Ds visually follow the PhysicalBone2D node, use a SkeletonModification2DPhysicalBones modification on the Skeleton2D parent. Note: The PhysicalBone2D node does not automatically create a Joint2D node to keep PhysicalBone2D nodes together. They must be created manually.

## Properties

- `auto_configure_joint: bool` = `true` — If `true`, the PhysicalBone2D will automatically configure the first Joint2D child node.
- `bone2d_index: int` = `-1` — The index of the Bone2D that this PhysicalBone2D should simulate.
- `bone2d_nodepath: NodePath` = `NodePath("")` — The NodePath to the Bone2D that this PhysicalBone2D should simulate.
- `follow_bone_when_simulating: bool` = `false` — If `true`, the PhysicalBone2D will keep the transform of the bone it is bound to when simulating physics.
- `simulate_physics: bool` = `false` — If `true`, the PhysicalBone2D will start simulating using physics.

## Methods

- `get_joint() -> Joint2D` *const* — Returns the first Joint2D child node, if one exists.
- `is_simulating_physics() -> bool` *const* — Returns a boolean that indicates whether the PhysicalBone2D is running and simulating using the Godot 2D physics engine.
