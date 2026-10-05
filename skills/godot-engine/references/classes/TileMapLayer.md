# TileMapLayer

**Inherits:** Node2D

Node for 2D tile-based maps.

Node for 2D tile-based maps. A TileMapLayer uses a TileSet which contain a list of tiles which are used to create grid-based maps. Unlike the TileMap node, which is deprecated, TileMapLayer has only one layer of tiles. You can use several TileMapLayer to achieve the same result as a TileMap node.

## Properties

- `collision_enabled: bool` = `true` — Enable or disable collisions.
- `collision_visibility_mode: TileMapLayer.DebugVisibilityMode` = `0` — Show or hide the TileMapLayer's collision shapes.
- `enabled: bool` = `true` — If `false`, disables this TileMapLayer completely (rendering, collision, navigation, scene tiles, etc.)
- `navigation_enabled: bool` = `true` — If `true`, navigation regions are enabled.
- `navigation_visibility_mode: TileMapLayer.DebugVisibilityMode` = `0` — Show or hide the TileMapLayer's navigation meshes.
- `occlusion_enabled: bool` = `true` — Enable or disable light occlusion.
- `physics_quadrant_size: int` = `16` — The TileMapLayer's physics quadrant size.
- `rendering_quadrant_size: int` = `16` — The TileMapLayer's rendering quadrant size.
- `tile_map_data: PackedByteArray` = `PackedByteArray()` — The raw tile map data as a byte array.
- `tile_set: TileSet` — The TileSet used by this layer.
- `use_kinematic_bodies: bool` = `false` — If `true`, this TileMapLayer collision shapes will be instantiated as kinematic bodies.
- `x_draw_order_reversed: bool` = `false` — If `CanvasItem.y_sort_enabled` is enabled, setting this to `true` will reverse the order the tiles are drawn on the X-axis.
- `y_sort_origin: int` = `0` — This Y-sort origin value is added to each tile's Y-sort origin value.

## Methods

- `_tile_data_runtime_update(coords: Vector2i, tile_data: TileData) -> void` *virtual* — Called with a TileData object about to be used internally by the TileMapLayer, allowing its modification at runtime.
- `_update_cells(coords: Vector2i[], forced_cleanup: bool) -> void` *virtual* — Called when this TileMapLayer's cells need an internal update.
- `_use_tile_data_runtime_update(coords: Vector2i) -> bool` *virtual* — Should return `true` if the tile at coordinates `coords` requires a runtime update.
- `clear() -> void` — Clears all cells.
- `erase_cell(coords: Vector2i) -> void` — Erases the cell at coordinates `coords`.
- `fix_invalid_tiles() -> void` — Clears cells containing tiles that do not exist in the `tile_set`.
- `get_cell_alternative_tile(coords: Vector2i) -> int` *const* — Returns the tile alternative ID of the cell at coordinates `coords`.
- `get_cell_atlas_coords(coords: Vector2i) -> Vector2i` *const* — Returns the tile atlas coordinates ID of the cell at coordinates `coords`.
- `get_cell_source_id(coords: Vector2i) -> int` *const* — Returns the tile source ID of the cell at coordinates `coords`.
- `get_cell_tile_data(coords: Vector2i) -> TileData` *const* — Returns the TileData object associated with the given cell, or `null` if the cell does not exist or is not a TileSetAtlasSource.
- `get_coords_for_body_rid(body: RID) -> Vector2i` *const* — Returns the coordinates of the physics quadrant (see `physics_quadrant_size`) for given physics body RID.
- `get_navigation_map() -> RID` *const* — Returns the RID of the NavigationServer2D navigation used by this TileMapLayer.
- `get_neighbor_cell(coords: Vector2i, neighbor: TileSet.CellNeighbor) -> Vector2i` *const* — Returns the neighboring cell to the one at coordinates `coords`, identified by the `neighbor` direction.
- `get_pattern(coords_array: Vector2i[]) -> TileMapPattern` — Creates and returns a new TileMapPattern from the given array of cells.
- `get_surrounding_cells(coords: Vector2i) -> Vector2i[]` — Returns the list of all neighboring cells to the one at `coords`.
- `get_used_cells() -> Vector2i[]` *const* — Returns a Vector2i array with the positions of all cells containing a tile.
- `get_used_cells_by_id(source_id: int = -1, atlas_coords: Vector2i = Vector2i(-1, -1), alternative_tile: int = -1) -> Vector2i[]` *const* — Returns a Vector2i array with the positions of all cells containing a tile.
- `get_used_rect() -> Rect2i` *const* — Returns a rectangle enclosing the used (non-empty) tiles of the map.
- `has_body_rid(body: RID) -> bool` *const* — Returns whether the provided `body` RID belongs to one of this TileMapLayer's cells.
- `is_cell_flipped_h(coords: Vector2i) -> bool` *const* — Returns `true` if the cell at coordinates `coords` is flipped horizontally.
- `is_cell_flipped_v(coords: Vector2i) -> bool` *const* — Returns `true` if the cell at coordinates `coords` is flipped vertically.
- `is_cell_transposed(coords: Vector2i) -> bool` *const* — Returns `true` if the cell at coordinates `coords` is transposed.
- `local_to_map(local_position: Vector2) -> Vector2i` *const* — Returns the map coordinates of the cell containing the given `local_position`.
- `map_pattern(position_in_tilemap: Vector2i, coords_in_pattern: Vector2i, pattern: TileMapPattern) -> Vector2i` — Returns for the given coordinates `coords_in_pattern` in a TileMapPattern the corresponding cell coordinates if the pattern was pasted at the `position_in_tilemap` coordinates (see `set_pattern`).
- `map_to_local(map_position: Vector2i) -> Vector2` *const* — Returns the centered position of a cell in the TileMapLayer's local coordinate space.
- `notify_runtime_tile_data_update() -> void` — Notifies the TileMapLayer node that calls to `_use_tile_data_runtime_update` or `_tile_data_runtime_update` will lead to different results.
- `set_cell(coords: Vector2i, source_id: int = -1, atlas_coords: Vector2i = Vector2i(-1, -1), alternative_tile: int = 0) -> void` — Sets the tile identifiers for the cell at coordinates `coords`.
- `set_cells_terrain_connect(cells: Vector2i[], terrain_set: int, terrain: int, ignore_empty_terrains: bool = true) -> void` — Update all the cells in the `cells` coordinates array so that they use the given `terrain` for the given `terrain_set`.
- `set_cells_terrain_path(path: Vector2i[], terrain_set: int, terrain: int, ignore_empty_terrains: bool = true) -> void` — Update all the cells in the `path` coordinates array so that they use the given `terrain` for the given `terrain_set`.
- `set_navigation_map(map: RID) -> void` — Sets a custom `map` as a NavigationServer2D navigation map.
- `set_pattern(position: Vector2i, pattern: TileMapPattern) -> void` — Pastes the TileMapPattern at the given `position` in the tile map.
- `update_internals() -> void` — Triggers a direct update of the TileMapLayer.

## Signals

- `changed()` — Emitted when this TileMapLayer's properties changes, including changes to its assigned TileSet.

## Enum DebugVisibilityMode

- `DEBUG_VISIBILITY_MODE_DEFAULT = 0` — Hide the collisions or navigation debug shapes in the editor, and use the debug settings to determine their visibility in game (i.e.
- `DEBUG_VISIBILITY_MODE_FORCE_HIDE = 2` — Always hide the collisions or navigation debug shapes.
- `DEBUG_VISIBILITY_MODE_FORCE_SHOW = 1` — Always show the collisions or navigation debug shapes.
