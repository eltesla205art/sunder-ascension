# TileSet

**Inherits:** Resource

Tile library for tilemaps.

A TileSet is a library of tiles for a TileMapLayer. A TileSet handles a list of TileSetSource, each of them storing a set of tiles. Tiles can either be from a TileSetAtlasSource, which renders tiles out of a texture with support for physics, navigation, etc., or from a TileSetScenesCollectionSource, which exposes scene-based tiles. Tiles are referenced by using three IDs: their source ID, their atlas coordinates ID, and their alternative tile ID.

## Properties

- `tile_layout: TileSet.TileLayout` = `0` — For all half-offset shapes (Isometric, Hexagonal and Half-Offset square), changes the way tiles are indexed in the TileMapLayer grid.
- `tile_offset_axis: TileSet.TileOffsetAxis` = `0` — For all half-offset shapes (Isometric, Hexagonal and Half-Offset square), determines the offset axis.
- `tile_shape: TileSet.TileShape` = `0` — The tile shape.
- `tile_size: Vector2i` = `Vector2i(16, 16)` — The tile size, in pixels.
- `uv_clipping: bool` = `false` — Enables/Disable uv clipping when rendering the tiles.

## Methods

- `add_custom_data_layer(to_position: int = -1) -> void` — Adds a custom data layer to the TileSet at the given position `to_position` in the array.
- `add_navigation_layer(to_position: int = -1) -> void` — Adds a navigation layer to the TileSet at the given position `to_position` in the array.
- `add_occlusion_layer(to_position: int = -1) -> void` — Adds an occlusion layer to the TileSet at the given position `to_position` in the array.
- `add_pattern(pattern: TileMapPattern, index: int = -1) -> int` — Adds a TileMapPattern to be stored in the TileSet resource.
- `add_physics_layer(to_position: int = -1) -> void` — Adds a physics layer to the TileSet at the given position `to_position` in the array.
- `add_source(source: TileSetSource, atlas_source_id_override: int = -1) -> int` — Adds a TileSetSource to the TileSet.
- `add_terrain(terrain_set: int, to_position: int = -1) -> void` — Adds a new terrain to the given terrain set `terrain_set` at the given position `to_position` in the array.
- `add_terrain_set(to_position: int = -1) -> void` — Adds a new terrain set at the given position `to_position` in the array.
- `cleanup_invalid_tile_proxies() -> void` — Clears tile proxies pointing to invalid tiles.
- `clear_terrains(terrain_set: int) -> void` — Clears all terrain properties for the given terrain set.
- `clear_tile_proxies() -> void` — Clears all tile proxies.
- `get_alternative_level_tile_proxy(source_from: int, coords_from: Vector2i, alternative_from: int) -> Array` — Returns the alternative-level proxy for the given identifiers.
- `get_coords_level_tile_proxy(source_from: int, coords_from: Vector2i) -> Array` — Returns the coordinate-level proxy for the given identifiers.
- `get_custom_data_layer_by_name(layer_name: String) -> int` *const* — Returns the index of the custom data layer identified by the given name.
- `get_custom_data_layer_name(layer_index: int) -> String` *const* — Returns the name of the custom data layer identified by the given index.
- `get_custom_data_layer_type(layer_index: int) -> int[Variant.Type]` *const* — Returns the type of the custom data layer identified by the given index.
- `get_custom_data_layers_count() -> int` *const* — Returns the custom data layers count.
- `get_navigation_layer_layer_value(layer_index: int, layer_number: int) -> bool` *const* — Returns whether or not the specified navigation layer of the TileSet navigation data layer identified by the given `layer_index` is enabled, given a navigation_layers `layer_number` between 1 and 32.
- `get_navigation_layer_layers(layer_index: int) -> int` *const* — Returns the navigation layers (as in the Navigation server) of the given TileSet navigation layer.
- `get_navigation_layers_count() -> int` *const* — Returns the navigation layers count.
- `get_next_source_id() -> int` *const* — Returns a new unused source ID.
- `get_occlusion_layer_light_mask(layer_index: int) -> int` *const* — Returns the light mask of the occlusion layer.
- `get_occlusion_layer_sdf_collision(layer_index: int) -> bool` *const* — Returns if the occluders from this layer use `sdf_collision`.
- `get_occlusion_layers_count() -> int` *const* — Returns the occlusion layers count.
- `get_pattern(index: int = -1) -> TileMapPattern` — Returns the TileMapPattern at the given `index`.
- `get_patterns_count() -> int` — Returns the number of TileMapPattern this tile set handles.
- `get_physics_layer_collision_layer(layer_index: int) -> int` *const* — Returns the collision layer (as in the physics server) bodies on the given TileSet's physics layer are in.
- `get_physics_layer_collision_mask(layer_index: int) -> int` *const* — Returns the collision mask of bodies on the given TileSet's physics layer.
- `get_physics_layer_collision_priority(layer_index: int) -> float` *const* — Returns the collision priority of bodies on the given TileSet's physics layer.
- `get_physics_layer_physics_material(layer_index: int) -> PhysicsMaterial` *const* — Returns the physics material of bodies on the given TileSet's physics layer.
- `get_physics_layers_count() -> int` *const* — Returns the physics layers count.
- `get_source(source_id: int) -> TileSetSource` *const* — Returns the TileSetSource with ID `source_id`.
- `get_source_count() -> int` *const* — Returns the number of TileSetSource in this TileSet.
- `get_source_id(index: int) -> int` *const* — Returns the source ID for source with index `index`.
- `get_source_level_tile_proxy(source_from: int) -> int` — Returns the source-level proxy for the given source identifier.
- `get_terrain_color(terrain_set: int, terrain_index: int) -> Color` *const* — Returns a terrain's color.
- `get_terrain_name(terrain_set: int, terrain_index: int) -> String` *const* — Returns a terrain's name.
- `get_terrain_set_mode(terrain_set: int) -> int[TileSet.TerrainMode]` *const* — Returns a terrain set mode.
- `get_terrain_sets_count() -> int` *const* — Returns the terrain sets count.
- `get_terrains_count(terrain_set: int) -> int` *const* — Returns the number of terrains in the given terrain set.
- `has_alternative_level_tile_proxy(source_from: int, coords_from: Vector2i, alternative_from: int) -> bool` — Returns if there is an alternative-level proxy for the given identifiers.
- `has_coords_level_tile_proxy(source_from: int, coords_from: Vector2i) -> bool` — Returns if there is a coodinates-level proxy for the given identifiers.
- `has_custom_data_layer_by_name(layer_name: String) -> bool` *const* — Returns if there is a custom data layer named `layer_name`.
- `has_source(source_id: int) -> bool` *const* — Returns if this TileSet has a source for the given source ID.
- `has_source_level_tile_proxy(source_from: int) -> bool` — Returns if there is a source-level proxy for the given source ID.
- `map_tile_proxy(source_from: int, coords_from: Vector2i, alternative_from: int) -> Array` *const* — According to the configured proxies, maps the provided identifiers to a new set of identifiers.
- `move_custom_data_layer(layer_index: int, to_position: int) -> void` — Moves the custom data layer at index `layer_index` to the given position `to_position` in the array.
- `move_navigation_layer(layer_index: int, to_position: int) -> void` — Moves the navigation layer at index `layer_index` to the given position `to_position` in the array.
- `move_occlusion_layer(layer_index: int, to_position: int) -> void` — Moves the occlusion layer at index `layer_index` to the given position `to_position` in the array.
- `move_physics_layer(layer_index: int, to_position: int) -> void` — Moves the physics layer at index `layer_index` to the given position `to_position` in the array.
- `move_terrain(terrain_set: int, terrain_index: int, to_position: int) -> void` — Moves the terrain at index `terrain_index` for terrain set `terrain_set` to the given position `to_position` in the array.
- `move_terrain_set(terrain_set: int, to_position: int) -> void` — Moves the terrain set at index `terrain_set` to the given position `to_position` in the array.
- `remove_alternative_level_tile_proxy(source_from: int, coords_from: Vector2i, alternative_from: int) -> void` — Removes an alternative-level proxy for the given identifiers.
- `remove_coords_level_tile_proxy(source_from: int, coords_from: Vector2i) -> void` — Removes a coordinates-level proxy for the given identifiers.
- `remove_custom_data_layer(layer_index: int) -> void` — Removes the custom data layer at index `layer_index`.
- `remove_navigation_layer(layer_index: int) -> void` — Removes the navigation layer at index `layer_index`.
- `remove_occlusion_layer(layer_index: int) -> void` — Removes the occlusion layer at index `layer_index`.
- `remove_pattern(index: int) -> void` — Remove the TileMapPattern at the given index.
- `remove_physics_layer(layer_index: int) -> void` — Removes the physics layer at index `layer_index`.
- `remove_source(source_id: int) -> void` — Removes the source with the given source ID.
- `remove_source_level_tile_proxy(source_from: int) -> void` — Removes a source-level tile proxy.
- `remove_terrain(terrain_set: int, terrain_index: int) -> void` — Removes the terrain at index `terrain_index` in the given terrain set `terrain_set`.
- `remove_terrain_set(terrain_set: int) -> void` — Removes the terrain set at index `terrain_set`.
- `set_alternative_level_tile_proxy(source_from: int, coords_from: Vector2i, alternative_from: int, source_to: int, coords_to: Vector2i, alternative_to: int) -> void` — Create an alternative-level proxy for the given identifiers.
- `set_coords_level_tile_proxy(source_from: int, coords_from: Vector2i, source_to: int, coords_to: Vector2i) -> void` — Creates a coordinates-level proxy for the given identifiers.
- `set_custom_data_layer_name(layer_index: int, layer_name: String) -> void` — Sets the name of the custom data layer identified by the given index.
- `set_custom_data_layer_type(layer_index: int, layer_type: Variant.Type) -> void` — Sets the type of the custom data layer identified by the given index.
- `set_navigation_layer_layer_value(layer_index: int, layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified navigation layer of the TileSet navigation data layer identified by the given `layer_index`, given a navigation_layers `layer_number` between 1 and 32.
- `set_navigation_layer_layers(layer_index: int, layers: int) -> void` — Sets the navigation layers (as in the navigation server) for navigation regions in the given TileSet navigation layer.
- `set_occlusion_layer_light_mask(layer_index: int, light_mask: int) -> void` — Sets the occlusion layer (as in the rendering server) for occluders in the given TileSet occlusion layer.
- `set_occlusion_layer_sdf_collision(layer_index: int, sdf_collision: bool) -> void` — Enables or disables SDF collision for occluders in the given TileSet occlusion layer.
- `set_physics_layer_collision_layer(layer_index: int, layer: int) -> void` — Sets the collision layer (as in the physics server) for bodies in the given TileSet physics layer.
- `set_physics_layer_collision_mask(layer_index: int, mask: int) -> void` — Sets the collision mask for bodies in the given TileSet physics layer.
- `set_physics_layer_collision_priority(layer_index: int, priority: float) -> void` — Sets the collision priority for bodies in the given TileSet physics layer.
- `set_physics_layer_physics_material(layer_index: int, physics_material: PhysicsMaterial) -> void` — Sets the physics material for bodies in the given TileSet physics layer.
- `set_source_id(source_id: int, new_source_id: int) -> void` — Changes a source's ID.
- `set_source_level_tile_proxy(source_from: int, source_to: int) -> void` — Creates a source-level proxy for the given source ID.
- `set_terrain_color(terrain_set: int, terrain_index: int, color: Color) -> void` — Sets a terrain's color.
- `set_terrain_name(terrain_set: int, terrain_index: int, name: String) -> void` — Sets a terrain's name.
- `set_terrain_set_mode(terrain_set: int, mode: TileSet.TerrainMode) -> void` — Sets a terrain mode.

## Enum TileShape

- `TILE_SHAPE_SQUARE = 0` — Rectangular tile shape.
- `TILE_SHAPE_ISOMETRIC = 1` — Diamond tile shape (for isometric look).
- `TILE_SHAPE_HALF_OFFSET_SQUARE = 2` — Rectangular tile shape with one row/column out of two offset by half a tile.
- `TILE_SHAPE_HEXAGON = 3` — Hexagonal tile shape.

## Enum TileLayout

- `TILE_LAYOUT_STACKED = 0` — Tile coordinates layout where both axis stay consistent with their respective local horizontal and vertical axis.
- `TILE_LAYOUT_STACKED_OFFSET = 1` — Same as `TILE_LAYOUT_STACKED`, but the first half-offset is negative instead of positive.
- `TILE_LAYOUT_STAIRS_RIGHT = 2` — Tile coordinates layout where the horizontal axis stay horizontal, and the vertical one goes down-right.
- `TILE_LAYOUT_STAIRS_DOWN = 3` — Tile coordinates layout where the vertical axis stay vertical, and the horizontal one goes down-right.
- `TILE_LAYOUT_DIAMOND_RIGHT = 4` — Tile coordinates layout where the horizontal axis goes up-right, and the vertical one goes down-right.
- `TILE_LAYOUT_DIAMOND_DOWN = 5` — Tile coordinates layout where the horizontal axis goes down-right, and the vertical one goes down-left.

## Enum TileOffsetAxis

- `TILE_OFFSET_AXIS_HORIZONTAL = 0` — Horizontal half-offset.
- `TILE_OFFSET_AXIS_VERTICAL = 1` — Vertical half-offset.

## Enum CellNeighbor

- `CELL_NEIGHBOR_RIGHT_SIDE = 0` — Neighbor on the right side.
- `CELL_NEIGHBOR_RIGHT_CORNER = 1` — Neighbor in the right corner.
- `CELL_NEIGHBOR_BOTTOM_RIGHT_SIDE = 2` — Neighbor on the bottom right side.
- `CELL_NEIGHBOR_BOTTOM_RIGHT_CORNER = 3` — Neighbor in the bottom right corner.
- `CELL_NEIGHBOR_BOTTOM_SIDE = 4` — Neighbor on the bottom side.
- `CELL_NEIGHBOR_BOTTOM_CORNER = 5` — Neighbor in the bottom corner.
- `CELL_NEIGHBOR_BOTTOM_LEFT_SIDE = 6` — Neighbor on the bottom left side.
- `CELL_NEIGHBOR_BOTTOM_LEFT_CORNER = 7` — Neighbor in the bottom left corner.
- `CELL_NEIGHBOR_LEFT_SIDE = 8` — Neighbor on the left side.
- `CELL_NEIGHBOR_LEFT_CORNER = 9` — Neighbor in the left corner.
- `CELL_NEIGHBOR_TOP_LEFT_SIDE = 10` — Neighbor on the top left side.
- `CELL_NEIGHBOR_TOP_LEFT_CORNER = 11` — Neighbor in the top left corner.
- `CELL_NEIGHBOR_TOP_SIDE = 12` — Neighbor on the top side.
- `CELL_NEIGHBOR_TOP_CORNER = 13` — Neighbor in the top corner.
- `CELL_NEIGHBOR_TOP_RIGHT_SIDE = 14` — Neighbor on the top right side.
- `CELL_NEIGHBOR_TOP_RIGHT_CORNER = 15` — Neighbor in the top right corner.

## Enum TerrainMode

- `TERRAIN_MODE_MATCH_CORNERS_AND_SIDES = 0` — Requires both corners and side to match with neighboring tiles' terrains.
- `TERRAIN_MODE_MATCH_CORNERS = 1` — Requires corners to match with neighboring tiles' terrains.
- `TERRAIN_MODE_MATCH_SIDES = 2` — Requires sides to match with neighboring tiles' terrains.
