# TileMap

**Inherits:** Node2D
**Deprecated:** Use multiple TileMapLayer nodes instead. To convert a TileMap to a set of TileMapLayer nodes, open the TileMap bottom panel with the node selected, click the toolbox icon in the toolbar and choose 'Extract TileMap layers as individual TileMapLayer nodes'.

Node for 2D tile-based maps.

Node for 2D tile-based maps. Tilemaps use a TileSet which contain a list of tiles which are used to create grid-based maps. A TileMap may have several layers, layouting tiles on top of each other. For performance reasons, all TileMap updates are batched at the end of a frame.

## Properties

- `collision_animatable: bool` = `false` — If enabled, the TileMap will see its collisions synced to the physics tick and change its collision type from static to kinematic.
- `collision_visibility_mode: TileMap.VisibilityMode` = `0` — Show or hide the TileMap's collision shapes.
- `navigation_visibility_mode: TileMap.VisibilityMode` = `0` — Show or hide the TileMap's navigation meshes.
- `rendering_quadrant_size: int` = `16` — The TileMap's quadrant size.
- `tile_set: TileSet` — The TileSet used by this TileMap.

## Methods

- `_tile_data_runtime_update(layer: int, coords: Vector2i, tile_data: TileData) -> void` *virtual* — Called with a TileData object about to be used internally by the TileMap, allowing its modification at runtime.
- `_use_tile_data_runtime_update(layer: int, coords: Vector2i) -> bool` *virtual* — Should return `true` if the tile at coordinates `coords` on layer `layer` requires a runtime update.
- `add_layer(to_position: int) -> void` — Adds a layer at the given position `to_position` in the array.
- `clear() -> void` — Clears all cells.
- `clear_layer(layer: int) -> void` — Clears all cells on the given layer.
- `erase_cell(layer: int, coords: Vector2i) -> void` — Erases the cell on layer `layer` at coordinates `coords`.
- `fix_invalid_tiles() -> void` — Clears cells that do not exist in the tileset.
- `force_update(layer: int = -1) -> void` *(deprecated)* — Forces the TileMap and the layer `layer` to update.
- `get_cell_alternative_tile(layer: int, coords: Vector2i, use_proxies: bool = false) -> int` *const* — Returns the tile alternative ID of the cell on layer `layer` at `coords`.
- `get_cell_atlas_coords(layer: int, coords: Vector2i, use_proxies: bool = false) -> Vector2i` *const* — Returns the tile atlas coordinates ID of the cell on layer `layer` at coordinates `coords`.
- `get_cell_source_id(layer: int, coords: Vector2i, use_proxies: bool = false) -> int` *const* — Returns the tile source ID of the cell on layer `layer` at coordinates `coords`.
- `get_cell_tile_data(layer: int, coords: Vector2i, use_proxies: bool = false) -> TileData` *const* — Returns the TileData object associated with the given cell, or `null` if the cell does not exist or is not a TileSetAtlasSource.
- `get_coords_for_body_rid(body: RID) -> Vector2i` — Returns the coordinates of the tile for given physics body RID.
- `get_layer_for_body_rid(body: RID) -> int` — Returns the tilemap layer of the tile for given physics body RID.
- `get_layer_modulate(layer: int) -> Color` *const* — Returns a TileMap layer's modulate.
- `get_layer_name(layer: int) -> String` *const* — Returns a TileMap layer's name.
- `get_layer_navigation_map(layer: int) -> RID` *const* — Returns the RID of the NavigationServer2D navigation map assigned to the specified TileMap layer `layer`.
- `get_layer_y_sort_origin(layer: int) -> int` *const* — Returns a TileMap layer's Y sort origin.
- `get_layer_z_index(layer: int) -> int` *const* — Returns a TileMap layer's Z-index value.
- `get_layers_count() -> int` *const* — Returns the number of layers in the TileMap.
- `get_navigation_map(layer: int) -> RID` *const* *(deprecated)* — Returns the RID of the NavigationServer2D navigation map assigned to the specified TileMap layer `layer`.
- `get_neighbor_cell(coords: Vector2i, neighbor: TileSet.CellNeighbor) -> Vector2i` *const* — Returns the neighboring cell to the one at coordinates `coords`, identified by the `neighbor` direction.
- `get_pattern(layer: int, coords_array: Vector2i[]) -> TileMapPattern` — Creates a new TileMapPattern from the given layer and set of cells.
- `get_surrounding_cells(coords: Vector2i) -> Vector2i[]` — Returns the list of all neighbourings cells to the one at `coords`.
- `get_used_cells(layer: int) -> Vector2i[]` *const* — Returns a Vector2i array with the positions of all cells containing a tile in the given layer.
- `get_used_cells_by_id(layer: int, source_id: int = -1, atlas_coords: Vector2i = Vector2i(-1, -1), alternative_tile: int = -1) -> Vector2i[]` *const* — Returns a Vector2i array with the positions of all cells containing a tile in the given layer.
- `get_used_rect() -> Rect2i` *const* — Returns a rectangle enclosing the used (non-empty) tiles of the map, including all layers.
- `is_cell_flipped_h(layer: int, coords: Vector2i, use_proxies: bool = false) -> bool` *const* — Returns `true` if the cell on layer `layer` at coordinates `coords` is flipped horizontally.
- `is_cell_flipped_v(layer: int, coords: Vector2i, use_proxies: bool = false) -> bool` *const* — Returns `true` if the cell on layer `layer` at coordinates `coords` is flipped vertically.
- `is_cell_transposed(layer: int, coords: Vector2i, use_proxies: bool = false) -> bool` *const* — Returns `true` if the cell on layer `layer` at coordinates `coords` is transposed.
- `is_layer_enabled(layer: int) -> bool` *const* — Returns if a layer is enabled.
- `is_layer_navigation_enabled(layer: int) -> bool` *const* — Returns if a layer's built-in navigation regions generation is enabled.
- `is_layer_y_sort_enabled(layer: int) -> bool` *const* — Returns if a layer Y-sorts its tiles.
- `local_to_map(local_position: Vector2) -> Vector2i` *const* — Returns the map coordinates of the cell containing the given `local_position`.
- `map_pattern(position_in_tilemap: Vector2i, coords_in_pattern: Vector2i, pattern: TileMapPattern) -> Vector2i` — Returns for the given coordinate `coords_in_pattern` in a TileMapPattern the corresponding cell coordinates if the pattern was pasted at the `position_in_tilemap` coordinates (see `set_pattern`).
- `map_to_local(map_position: Vector2i) -> Vector2` *const* — Returns the centered position of a cell in the TileMap's local coordinate space.
- `move_layer(layer: int, to_position: int) -> void` — Moves the layer at index `layer` to the given position `to_position` in the array.
- `notify_runtime_tile_data_update(layer: int = -1) -> void` — Notifies the TileMap node that calls to `_use_tile_data_runtime_update` or `_tile_data_runtime_update` will lead to different results.
- `remove_layer(layer: int) -> void` — Removes the layer at index `layer`.
- `set_cell(layer: int, coords: Vector2i, source_id: int = -1, atlas_coords: Vector2i = Vector2i(-1, -1), alternative_tile: int = 0) -> void` — Sets the tile identifiers for the cell on layer `layer` at coordinates `coords`.
- `set_cells_terrain_connect(layer: int, cells: Vector2i[], terrain_set: int, terrain: int, ignore_empty_terrains: bool = true) -> void` — Update all the cells in the `cells` coordinates array so that they use the given `terrain` for the given `terrain_set`.
- `set_cells_terrain_path(layer: int, path: Vector2i[], terrain_set: int, terrain: int, ignore_empty_terrains: bool = true) -> void` — Update all the cells in the `path` coordinates array so that they use the given `terrain` for the given `terrain_set`.
- `set_layer_enabled(layer: int, enabled: bool) -> void` — Enables or disables the layer `layer`.
- `set_layer_modulate(layer: int, modulate: Color) -> void` — Sets a layer's color.
- `set_layer_name(layer: int, name: String) -> void` — Sets a layer's name.
- `set_layer_navigation_enabled(layer: int, enabled: bool) -> void` — Enables or disables a layer's built-in navigation regions generation.
- `set_layer_navigation_map(layer: int, map: RID) -> void` — Assigns `map` as a NavigationServer2D navigation map for the specified TileMap layer `layer`.
- `set_layer_y_sort_enabled(layer: int, y_sort_enabled: bool) -> void` — Enables or disables a layer's Y-sorting.
- `set_layer_y_sort_origin(layer: int, y_sort_origin: int) -> void` — Sets a layer's Y-sort origin value.
- `set_layer_z_index(layer: int, z_index: int) -> void` — Sets a layers Z-index value.
- `set_navigation_map(layer: int, map: RID) -> void` *(deprecated)* — Assigns `map` as a NavigationServer2D navigation map for the specified TileMap layer `layer`.
- `set_pattern(layer: int, position: Vector2i, pattern: TileMapPattern) -> void` — Paste the given TileMapPattern at the given `position` and `layer` in the tile map.
- `update_internals() -> void` — Triggers a direct update of the TileMap.

## Signals

- `changed()` — Emitted when the TileSet of this TileMap changes.

## Enum VisibilityMode

- `VISIBILITY_MODE_DEFAULT = 0` — Use the debug settings to determine visibility.
- `VISIBILITY_MODE_FORCE_HIDE = 2` — Always hide.
- `VISIBILITY_MODE_FORCE_SHOW = 1` — Always show.
