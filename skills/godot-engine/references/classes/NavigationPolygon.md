# NavigationPolygon

**Inherits:** Resource

A 2D navigation mesh that describes a traversable surface for pathfinding.

A navigation mesh can be created either by baking it with the help of the NavigationServer2D, or by adding vertices and convex polygon indices arrays manually. To bake a navigation mesh at least one outline needs to be added that defines the outer bounds of the baked area. Adding vertices and polygon indices manually.

## Properties

- `agent_radius: float` = `10.0` — The distance to erode/shrink the walkable surface when baking the navigation mesh.
- `baking_rect: Rect2` = `Rect2(0, 0, 0, 0)` — If the baking Rect2 has an area the navigation mesh baking will be restricted to its enclosing area.
- `baking_rect_offset: Vector2` = `Vector2(0, 0)` — The position offset applied to the `baking_rect` Rect2.
- `border_size: float` = `0.0` — The size of the non-navigable border around the bake bounding area defined by the `baking_rect` Rect2.
- `cell_size: float` = `1.0` — The cell size used to rasterize the navigation mesh vertices.
- `parsed_collision_mask: int` = `4294967295` — The physics layers to scan for static colliders.
- `parsed_geometry_type: NavigationPolygon.ParsedGeometryType` = `2` — Determines which type of nodes will be parsed as geometry.
- `sample_partition_type: NavigationPolygon.SamplePartitionType` = `0` — Partitioning algorithm for creating the navigation mesh polys.
- `source_geometry_group_name: StringName` = `&"navigation_polygon_source_geometry_group"` — The group name of nodes that should be parsed for baking source geometry.
- `source_geometry_mode: NavigationPolygon.SourceGeometryMode` = `0` — The source of the geometry used when baking.

## Methods

- `add_outline(outline: PackedVector2Array) -> void` — Appends a PackedVector2Array that contains the vertices of an outline to the internal array that contains all the outlines.
- `add_outline_at_index(outline: PackedVector2Array, index: int) -> void` — Adds a PackedVector2Array that contains the vertices of an outline to the internal array that contains all the outlines at a fixed position.
- `add_polygon(polygon: PackedInt32Array) -> void` — Adds a polygon using the indices of the vertices you get when calling `get_vertices`.
- `clear() -> void` — Clears the internal arrays for vertices and polygon indices.
- `clear_outlines() -> void` — Clears the array of the outlines, but it doesn't clear the vertices and the polygons that were created by them.
- `clear_polygons() -> void` — Clears the array of polygons, but it doesn't clear the array of outlines and vertices.
- `get_navigation_mesh() -> NavigationMesh` — Returns the NavigationMesh resulting from this navigation polygon.
- `get_outline(idx: int) -> PackedVector2Array` *const* — Returns a PackedVector2Array containing the vertices of an outline that was created in the editor or by script.
- `get_outline_count() -> int` *const* — Returns the number of outlines that were created in the editor or by script.
- `get_parsed_collision_mask_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `parsed_collision_mask` is enabled, given a `layer_number` between 1 and 32.
- `get_polygon(idx: int) -> PackedInt32Array` — Returns a PackedInt32Array containing the indices of the vertices of a created polygon.
- `get_polygon_count() -> int` *const* — Returns the count of all polygons.
- `get_vertices() -> PackedVector2Array` *const* — Returns a PackedVector2Array containing all the vertices being used to create the polygons.
- `make_polygons_from_outlines() -> void` *(deprecated)* — Creates polygons from the outlines added in the editor or by script.
- `remove_outline(idx: int) -> void` — Removes an outline created in the editor or by script.
- `set_outline(idx: int, outline: PackedVector2Array) -> void` — Changes an outline created in the editor or by script.
- `set_parsed_collision_mask_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `parsed_collision_mask`, given a `layer_number` between 1 and 32.
- `set_vertices(vertices: PackedVector2Array) -> void` — Sets the vertices that can be then indexed to create polygons with the `add_polygon` method.

## Enum SamplePartitionType

- `SAMPLE_PARTITION_CONVEX_PARTITION = 0` — Convex partitioning that results in a navigation mesh with convex polygons.
- `SAMPLE_PARTITION_TRIANGULATE = 1` — Triangulation partitioning that results in a navigation mesh with triangle polygons.
- `SAMPLE_PARTITION_MAX = 2` — Represents the size of the `SamplePartitionType` enum.

## Enum ParsedGeometryType

- `PARSED_GEOMETRY_MESH_INSTANCES = 0` — Parses mesh instances as obstruction geometry.
- `PARSED_GEOMETRY_STATIC_COLLIDERS = 1` — Parses StaticBody2D and TileMap colliders as obstruction geometry.
- `PARSED_GEOMETRY_BOTH = 2` — Both `PARSED_GEOMETRY_MESH_INSTANCES` and `PARSED_GEOMETRY_STATIC_COLLIDERS`.
- `PARSED_GEOMETRY_MAX = 3` — Represents the size of the `ParsedGeometryType` enum.

## Enum SourceGeometryMode

- `SOURCE_GEOMETRY_ROOT_NODE_CHILDREN = 0` — Scans the child nodes of the root node recursively for geometry.
- `SOURCE_GEOMETRY_GROUPS_WITH_CHILDREN = 1` — Scans nodes in a group and their child nodes recursively for geometry.
- `SOURCE_GEOMETRY_GROUPS_EXPLICIT = 2` — Uses nodes in a group for geometry.
- `SOURCE_GEOMETRY_MAX = 3` — Represents the size of the `SourceGeometryMode` enum.
