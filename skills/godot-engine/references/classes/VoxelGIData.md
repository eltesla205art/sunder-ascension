# VoxelGIData

**Inherits:** Resource

Contains baked voxel global illumination data for use in a VoxelGI node.

VoxelGIData contains baked voxel global illumination for use in a VoxelGI node. VoxelGIData also offers several properties to adjust the final appearance of the global illumination. These properties can be adjusted at run-time without having to bake the VoxelGI node again. Note: To prevent text-based scene files (`.tscn`) from growing too much and becoming slow to load and save, always save VoxelGIData to an external binary resource file (`.res`) instead of embedding it within the scene.

## Properties

- `bias: float` = `1.5` — The normal bias to use for indirect lighting and reflections.
- `dynamic_range: float` = `2.0` — The dynamic range to use (`1.0` represents a low dynamic range scene brightness).
- `energy: float` = `1.0` — The energy of the indirect lighting and reflections produced by the VoxelGI node.
- `interior: bool` = `false` — If `true`, Environment lighting is ignored by the VoxelGI node.
- `normal_bias: float` = `0.0` — The normal bias to use for indirect lighting and reflections.
- `propagation: float` = `0.5` — The multiplier to use when light bounces off a surface.
- `use_two_bounces: bool` = `true` — If `true`, performs two bounces of indirect lighting instead of one.

## Methods

- `allocate(to_cell_xform: Transform3D, aabb: AABB, octree_size: Vector3, octree_cells: PackedByteArray, data_cells: PackedByteArray, distance_field: PackedByteArray, level_counts: PackedInt32Array) -> void` — Initializes this VoxelGIData with the specified data.
- `get_bounds() -> AABB` *const* — Returns the bounds of the baked voxel data as an AABB, which should match `VoxelGI.size` after being baked (which only contains the size as a Vector3).
- `get_data_cells() -> PackedByteArray` *const* — Returns the baked cell data for this VoxelGIData.
- `get_level_counts() -> PackedInt32Array` *const* — Returns the baked level counts for this VoxelGIData.
- `get_octree_cells() -> PackedByteArray` *const* — Returns the baked octree cell data for this VoxelGIData.
- `get_octree_size() -> Vector3` *const* — Returns the baked octree size for this VoxelGIData, which corresponds to the number of subdivisions per axis.
- `get_to_cell_xform() -> Transform3D` *const* — Returns the baked cell transform for this VoxelGIData.
