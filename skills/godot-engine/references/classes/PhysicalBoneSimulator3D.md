# PhysicalBoneSimulator3D

**Inherits:** SkeletonModifier3D

Node that can be the parent of PhysicalBone3D and can apply the simulation results to Skeleton3D.

Node that can be the parent of PhysicalBone3D and can apply the simulation results to Skeleton3D.

## Methods

- `is_simulating_physics() -> bool` *const* — Returns a boolean that indicates whether the PhysicalBoneSimulator3D is running and simulating.
- `physical_bones_add_collision_exception(exception: RID) -> void` — Adds a collision exception to the physical bone.
- `physical_bones_remove_collision_exception(exception: RID) -> void` — Removes a collision exception to the physical bone.
- `physical_bones_start_simulation(bones: StringName[] = []) -> void` — Tells the PhysicalBone3D nodes in the Skeleton to start simulating and reacting to the physics world.
- `physical_bones_stop_simulation() -> void` — Tells the PhysicalBone3D nodes in the Skeleton to stop simulating.
