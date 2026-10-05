# NavigationMeshGenerator

**Inherits:** Object
**Deprecated:** 

Helper class for creating and clearing navigation meshes.

This class is responsible for creating and clearing 3D navigation meshes used as NavigationMesh resources inside NavigationRegion3D. The NavigationMeshGenerator has very limited to no use for 2D as the navigation mesh baking process expects 3D node types and 3D source geometry to parse. The entire navigation mesh baking is best done in a separate thread as the voxelization, collision tests and mesh optimization steps involved are very slow and performance-intensive operations. Navigation mesh baking happens in multiple steps and the result depends on 3D source geometry and properties of the NavigationMesh resource.

## Methods

- `bake(navigation_mesh: NavigationMesh, root_node: Node) -> void` *(deprecated)* — Bakes the `navigation_mesh` with source geometry collected starting from the `root_node`.
- `bake_from_source_geometry_data(navigation_mesh: NavigationMesh, source_geometry_data: NavigationMeshSourceGeometryData3D, callback: Callable = Callable()) -> void` — Bakes the provided `navigation_mesh` with the data from the provided `source_geometry_data`.
- `clear(navigation_mesh: NavigationMesh) -> void` — Removes all polygons and vertices from the provided `navigation_mesh` resource.
- `parse_source_geometry_data(navigation_mesh: NavigationMesh, source_geometry_data: NavigationMeshSourceGeometryData3D, root_node: Node, callback: Callable = Callable()) -> void` — Parses the SceneTree for source geometry according to the properties of `navigation_mesh`.
