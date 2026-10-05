# ArrayOccluder3D

**Inherits:** Occluder3D

3D polygon shape for use with occlusion culling in OccluderInstance3D.

ArrayOccluder3D stores an arbitrary 3D polygon shape that can be used by the engine's occlusion culling system. This is analogous to ArrayMesh, but for occluders. See OccluderInstance3D's documentation for instructions on setting up occlusion culling.

## Properties

- `indices: PackedInt32Array` = `PackedInt32Array()` — The occluder's index position.
- `vertices: PackedVector3Array` = `PackedVector3Array()` — The occluder's vertex positions in local 3D coordinates.

## Methods

- `set_arrays(vertices: PackedVector3Array, indices: PackedInt32Array) -> void` — Sets `indices` and `vertices`, while updating the final occluder only once after both values are set.
