# MeshConvexDecompositionSettings

**Inherits:** RefCounted

Parameters to be used with a Mesh convex decomposition operation.

Parameters to be used with a Mesh convex decomposition operation.

## Properties

- `convex_hull_approximation: bool` = `true` — If `true`, uses approximation for computing convex hulls.
- `convex_hull_downsampling: int` = `4` — Controls the precision of the convex-hull generation process during the clipping plane selection stage.
- `max_concavity: float` = `1.0` — Maximum concavity.
- `max_convex_hulls: int` = `1` — The maximum number of convex hulls to produce from the merge operation.
- `max_num_vertices_per_convex_hull: int` = `32` — Controls the maximum number of triangles per convex-hull.
- `min_volume_per_convex_hull: float` = `0.0001` — Controls the adaptive sampling of the generated convex-hulls.
- `mode: MeshConvexDecompositionSettings.Mode` = `0` — Mode for the approximate convex decomposition.
- `normalize_mesh: bool` = `false` — If `true`, normalizes the mesh before applying the convex decomposition.
- `plane_downsampling: int` = `4` — Controls the granularity of the search for the "best" clipping plane.
- `project_hull_vertices: bool` = `true` — If `true`, projects output convex hull vertices onto the original source mesh to increase floating-point accuracy of the results.
- `resolution: int` = `10000` — Maximum number of voxels generated during the voxelization stage.
- `revolution_axes_clipping_bias: float` = `0.05` — Controls the bias toward clipping along revolution axes.
- `symmetry_planes_clipping_bias: float` = `0.05` — Controls the bias toward clipping along symmetry planes.

## Enum Mode

- `CONVEX_DECOMPOSITION_MODE_VOXEL = 0` — Constant for voxel-based approximate convex decomposition.
- `CONVEX_DECOMPOSITION_MODE_TETRAHEDRON = 1` — Constant for tetrahedron-based approximate convex decomposition.
