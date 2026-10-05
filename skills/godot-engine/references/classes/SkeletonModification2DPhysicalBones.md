# SkeletonModification2DPhysicalBones

**Inherits:** SkeletonModification2D

A modification that applies the transforms of PhysicalBone2D nodes to Bone2D nodes.

This modification takes the transforms of PhysicalBone2D nodes and applies them to Bone2D nodes. This allows the Bone2D nodes to react to physics thanks to the linked PhysicalBone2D nodes.

## Properties

- `physical_bone_chain_length: int` = `0` — The number of PhysicalBone2D nodes linked in this modification.

## Methods

- `fetch_physical_bones() -> void` — Empties the list of PhysicalBone2D nodes and populates it with all PhysicalBone2D nodes that are children of the Skeleton2D.
- `get_physical_bone_node(joint_idx: int) -> NodePath` *const* — Returns the PhysicalBone2D node at `joint_idx`.
- `set_physical_bone_node(joint_idx: int, physicalbone2d_node: NodePath) -> void` — Sets the PhysicalBone2D node at `joint_idx`.
- `start_simulation(bones: StringName[] = []) -> void` — Tell the PhysicalBone2D nodes to start simulating and interacting with the physics world.
- `stop_simulation(bones: StringName[] = []) -> void` — Tell the PhysicalBone2D nodes to stop simulating and interacting with the physics world.
