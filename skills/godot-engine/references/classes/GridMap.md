# GridMap

**Inherits:** Node3D

Node for 3D tile-based maps.

GridMap lets you place meshes on a grid interactively. It works both from the editor and from scripts, which can help you create in-game level editors. GridMaps use a MeshLibrary which contains a list of tiles. Each tile is a mesh with materials plus optional collision and navigation shapes.

## Properties

- `bake_navigation: bool` = `false` — If `true`, this GridMap creates a navigation region for each cell that uses a `mesh_library` item with a navigation mesh.
- `cell_center_x: bool` = `true` — If `true`, grid items are centered on the X axis.
- `cell_center_y: bool` = `true` — If `true`, grid items are centered on the Y axis.
- `cell_center_z: bool` = `true` — If `true`, grid items are centered on the Z axis.
- `cell_octant_size: int` = `8` — The size of each octant measured in number of cells.
- `cell_scale: float` = `1.0` — The scale of the cell items.
- `cell_size: Vector3` = `Vector3(2, 2, 2)` — The dimensions of the grid's cells.
- `collision_layer: int` = `1` — The physics layers this GridMap is in.
- `collision_mask: int` = `1` — The physics layers this GridMap detects collisions in.
- `collision_priority: float` = `1.0` — The priority used to solve colliding when occurring penetration.
- `collision_visibility_mode: GridMap.DebugVisibilityMode` = `0` — Show or hide the GridMap's collision shapes.
- `debug_octant_color: Color` = `Color(1, 1, 1, 1)` — The Color used for rendering octant debug visuals when `debug_show_octants` is enabled.
- `debug_show_octants: bool` = `false` — If `true`, shows debug visuals for octants.
- `mesh_library: MeshLibrary` — The assigned MeshLibrary.
- `physics_material: PhysicsMaterial` — Overrides the default friction and bounce physics properties for the whole GridMap.

## Methods

- `clear() -> void` — Clear all cells.
- `clear_baked_meshes() -> void` — Clears all baked meshes.
- `get_bake_mesh_instance(idx: int) -> RID` — Returns RID of a baked mesh with the given `idx`.
- `get_bake_meshes() -> Array` — Returns an array of ArrayMeshes and Transform3D references of all bake meshes that exist within the current GridMap.
- `get_basis_with_orthogonal_index(index: int) -> Basis` *const* — Returns one of 24 possible rotations that lie along the vectors (x,y,z) with each component being either -1, 0, or 1.
- `get_cell_item(position: Vector3i) -> int` *const* — The MeshLibrary item index located at the given grid coordinates.
- `get_cell_item_basis(position: Vector3i) -> Basis` *const* — Returns the basis that gives the specified cell its orientation.
- `get_cell_item_orientation(position: Vector3i) -> int` *const* — The orientation of the cell at the given grid coordinates.
- `get_collision_layer_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `collision_layer` is enabled, given a `layer_number` between 1 and 32.
- `get_collision_mask_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `collision_mask` is enabled, given a `layer_number` between 1 and 32.
- `get_meshes() -> Array` *const* — Returns an array of Transform3D and Mesh references corresponding to the non-empty cells in the grid.
- `get_navigation_map() -> RID` *const* — Returns the RID of the navigation map this GridMap node uses for its cell baked navigation meshes.
- `get_octant_coords_from_cell_coords(cell_coords: Vector3i) -> Vector3i` *const* — Returns the Vector3i octant coordinates of the octant that the cell at `cell_coords` belongs to.
- `get_octants_in_bounds(bounds: AABB) -> Vector3i[]` *const* — Returns an array of Vector3i octant coordinates that are inside the given `bounds`, including octants that have no cells in use.
- `get_orthogonal_index_from_basis(basis: Basis) -> int` *const* — This function considers a discretization of rotations into 24 points on unit sphere, lying along the vectors (x,y,z) with each component being either -1, 0, or 1, and returns the index (in the range from 0 to 23) of the point best representing the orientation of the object.
- `get_used_cells() -> Vector3i[]` *const* — Returns an array of Vector3 with the non-empty cell coordinates in the grid map.
- `get_used_cells_by_item(item: int) -> Vector3i[]` *const* — Returns an array of all cells with the given item index specified in `item`.
- `get_used_cells_in_octant(octant_coords: Vector3i) -> Vector3i[]` *const* — Returns an array of Vector3is with the cell coordinates of non-empty cells inside the octant at `octant_coords`.
- `get_used_cells_in_octant_by_item(octant_coords: Vector3i, item: int) -> Vector3i[]` *const* — Returns an array of Vector3is with the cell coordinates of cells inside the octant at `octant_coords` that use the specified cell `item`.
- `get_used_octants() -> Vector3i[]` *const* — Returns an array of Vector3is with the octant coordinates of the non-empty octants in the grid map.
- `get_used_octants_by_item(item: int) -> Vector3i[]` *const* — Returns an array of Vector3is with the octant coordinates of the octants that use the specified `item` in the grid map.
- `get_used_octants_in_bounds(bounds: AABB) -> Vector3i[]` *const* — Returns an array of Vector3is with the octant coordinates of non-empty octants that are inside the local `bounds`.
- `local_to_map(local_position: Vector3) -> Vector3i` *const* — Returns the map coordinates of the cell containing the given `local_position`.
- `make_baked_meshes(gen_lightmap_uv: bool = false, lightmap_uv_texel_size: float = 0.1) -> void` — Generates a baked mesh that represents all meshes in the assigned MeshLibrary for use with LightmapGI.
- `map_to_local(map_position: Vector3i) -> Vector3` *const* — Returns the position of a grid cell in the GridMap's local coordinate space.
- `resource_changed(resource: Resource) -> void` *(deprecated)* — This method does nothing.
- `set_cell_item(position: Vector3i, item: int, orientation: int = 0) -> void` — Sets the mesh index for the cell referenced by its grid coordinates.
- `set_collision_layer_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `collision_layer`, given a `layer_number` between 1 and 32.
- `set_collision_mask_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `collision_mask`, given a `layer_number` between 1 and 32.
- `set_navigation_map(navigation_map: RID) -> void` — Sets the RID of the navigation map this GridMap node should use for its cell baked navigation meshes.

## Signals

- `cell_size_changed(cell_size: Vector3)` — Emitted when `cell_size` changes.
- `changed()` — Emitted when the MeshLibrary of this GridMap changes.

## Enum DebugVisibilityMode

- `DEBUG_VISIBILITY_MODE_DEFAULT = 0` — Hide the collisions debug shapes in the editor, and use the debug settings to determine their visibility in game (i.e.
- `DEBUG_VISIBILITY_MODE_FORCE_SHOW = 1` — Always show the collisions debug shapes.
- `DEBUG_VISIBILITY_MODE_FORCE_HIDE = 2` — Always hide the collisions debug shapes.

## Constants

- `INVALID_CELL_ITEM = -1` — Invalid cell item that can be used in `set_cell_item` to clear cells (or represent an empty cell in `get_cell_item`).
