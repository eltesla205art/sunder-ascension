# NavigationMesh

**Inherits:** Resource

A navigation mesh that defines traversable areas and obstacles.

A navigation mesh is a collection of polygons that define which areas of an environment are traversable to aid agents in pathfinding through complicated spaces.

## Properties

- `agent_height: float` = `1.5` — The minimum floor to ceiling height that will still allow the floor area to be considered walkable.
- `agent_max_climb: float` = `0.25` — The minimum ledge height that is considered to still be traversable.
- `agent_max_slope: float` = `45.0` — The maximum slope that is considered walkable, in degrees.
- `agent_radius: float` = `0.5` — The distance to erode/shrink the walkable area of the heightfield away from obstructions.
- `border_size: float` = `0.0` — The size of the non-navigable border around the bake bounding area.
- `cell_height: float` = `0.25` — The cell height used to rasterize the navigation mesh vertices on the Y axis.
- `cell_size: float` = `0.25` — The cell size used to rasterize the navigation mesh vertices on the XZ plane.
- `detail_sample_distance: float` = `6.0` — The sampling distance to use when generating the detail mesh, in cell unit.
- `detail_sample_max_error: float` = `1.0` — The maximum distance the detail mesh surface should deviate from heightfield, in cell unit.
- `edge_max_error: float` = `1.3` — The maximum distance a simplified contour's border edges should deviate the original raw contour.
- `edge_max_length: float` = `0.0` — The maximum allowed length for contour edges along the border of the mesh.
- `filter_baking_aabb: AABB` = `AABB(0, 0, 0, 0, 0, 0)` — If the baking AABB has a volume the navigation mesh baking will be restricted to its enclosing area.
- `filter_baking_aabb_offset: Vector3` = `Vector3(0, 0, 0)` — The position offset applied to the `filter_baking_aabb` AABB.
- `filter_ledge_spans: bool` = `false` — If `true`, marks spans that are ledges as non-walkable.
- `filter_low_hanging_obstacles: bool` = `false` — If `true`, marks non-walkable spans as walkable if their maximum is within `agent_max_climb` of a walkable neighbor.
- `filter_walkable_low_height_spans: bool` = `false` — If `true`, marks walkable spans as not walkable if the clearance above the span is less than `agent_height`.
- `geometry_collision_mask: int` = `4294967295` — The physics layers to scan for static colliders.
- `geometry_parsed_geometry_type: NavigationMesh.ParsedGeometryType` = `2` — Determines which type of nodes will be parsed as geometry.
- `geometry_source_geometry_mode: NavigationMesh.SourceGeometryMode` = `0` — The source of the geometry used when baking.
- `geometry_source_group_name: StringName` = `&"navigation_mesh_source_group"` — The name of the group to scan for geometry.
- `region_merge_size: float` = `20.0` — Any regions with a size smaller than this will be merged with larger regions if possible.
- `region_min_size: float` = `2.0` — The minimum size of a region for it to be created.
- `sample_partition_type: NavigationMesh.SamplePartitionType` = `0` — Partitioning algorithm for creating the navigation mesh polys.
- `vertices_per_polygon: float` = `6.0` — The maximum number of vertices allowed for polygons generated during the contour to polygon conversion process.

## Methods

- `add_polygon(polygon: PackedInt32Array) -> void` — Adds a polygon using the indices of the vertices you get when calling `get_vertices`.
- `clear() -> void` — Clears the internal arrays for vertices and polygon indices.
- `clear_polygons() -> void` — Clears the array of polygons, but it doesn't clear the array of vertices.
- `create_from_mesh(mesh: Mesh) -> void` — Initializes the navigation mesh by setting the vertices and indices according to a Mesh.
- `get_collision_mask_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `geometry_collision_mask` is enabled, given a `layer_number` between 1 and 32.
- `get_polygon(idx: int) -> PackedInt32Array` — Returns a PackedInt32Array containing the indices of the vertices of a created polygon.
- `get_polygon_count() -> int` *const* — Returns the number of polygons in the navigation mesh.
- `get_vertices() -> PackedVector3Array` *const* — Returns a PackedVector3Array containing all the vertices being used to create the polygons.
- `set_collision_mask_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `geometry_collision_mask`, given a `layer_number` between 1 and 32.
- `set_vertices(vertices: PackedVector3Array) -> void` — Sets the vertices that can be then indexed to create polygons with the `add_polygon` method.

## Enum SamplePartitionType

- `SAMPLE_PARTITION_WATERSHED = 0` — Watershed partitioning.
- `SAMPLE_PARTITION_MONOTONE = 1` — Monotone partitioning.
- `SAMPLE_PARTITION_LAYERS = 2` — Layer partitioning.
- `SAMPLE_PARTITION_MAX = 3` — Represents the size of the `SamplePartitionType` enum.

## Enum ParsedGeometryType

- `PARSED_GEOMETRY_MESH_INSTANCES = 0` — Parses mesh instances as geometry.
- `PARSED_GEOMETRY_STATIC_COLLIDERS = 1` — Parses StaticBody3D colliders as geometry.
- `PARSED_GEOMETRY_BOTH = 2` — Both `PARSED_GEOMETRY_MESH_INSTANCES` and `PARSED_GEOMETRY_STATIC_COLLIDERS`.
- `PARSED_GEOMETRY_MAX = 3` — Represents the size of the `ParsedGeometryType` enum.

## Enum SourceGeometryMode

- `SOURCE_GEOMETRY_ROOT_NODE_CHILDREN = 0` — Scans the child nodes of the root node recursively for geometry.
- `SOURCE_GEOMETRY_GROUPS_WITH_CHILDREN = 1` — Scans nodes in a group and their child nodes recursively for geometry.
- `SOURCE_GEOMETRY_GROUPS_EXPLICIT = 2` — Uses nodes in a group for geometry.
- `SOURCE_GEOMETRY_MAX = 3` — Represents the size of the `SourceGeometryMode` enum.
