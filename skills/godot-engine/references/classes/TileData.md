# TileData

**Inherits:** Object

Settings for a single tile in a TileSet.

TileData object represents a single tile in a TileSet. It is usually edited using the tileset editor, but it can be modified at runtime using `TileMapLayer._tile_data_runtime_update`.

## Properties

- `flip_h: bool` = `false` — If `true`, the tile will have its texture flipped horizontally.
- `flip_v: bool` = `false` — If `true`, the tile will have its texture flipped vertically.
- `material: Material` — The Material to use for this TileData.
- `modulate: Color` = `Color(1, 1, 1, 1)` — Color modulation of the tile.
- `probability: float` = `1.0` — Relative probability of this tile being selected when drawing a pattern of random tiles.
- `terrain: int` = `-1` — ID of the terrain from the terrain set that the tile uses.
- `terrain_set: int` = `-1` — ID of the terrain set that the tile uses.
- `texture_origin: Vector2i` = `Vector2i(0, 0)` — Offsets the position of where the tile is drawn.
- `transpose: bool` = `false` — If `true`, the tile will display transposed, i.e. with horizontal and vertical texture UVs swapped.
- `y_sort_origin: int` = `0` — Vertical point of the tile used for determining y-sorted order.
- `z_index: int` = `0` — Ordering index of this tile, relative to TileMapLayer.

## Methods

- `add_collision_polygon(layer_id: int) -> void` — Adds a collision polygon to the tile on the given TileSet physics layer.
- `add_occluder_polygon(layer_id: int) -> void` — Adds an occlusion polygon to the tile on the TileSet occlusion layer with index `layer_id`.
- `get_collision_polygon_one_way_margin(layer_id: int, polygon_index: int) -> float` *const* — Returns the one-way margin (for one-way platforms) of the polygon at index `polygon_index` for TileSet physics layer with index `layer_id`.
- `get_collision_polygon_points(layer_id: int, polygon_index: int) -> PackedVector2Array` *const* — Returns the points of the polygon at index `polygon_index` for TileSet physics layer with index `layer_id`.
- `get_collision_polygons_count(layer_id: int) -> int` *const* — Returns how many polygons the tile has for TileSet physics layer with index `layer_id`.
- `get_constant_angular_velocity(layer_id: int) -> float` *const* — Returns the constant angular velocity applied to objects colliding with this tile.
- `get_constant_linear_velocity(layer_id: int) -> Vector2` *const* — Returns the constant linear velocity applied to objects colliding with this tile.
- `get_custom_data(layer_name: String) -> Variant` *const* — Returns the custom data value for custom data layer named `layer_name`.
- `get_custom_data_by_layer_id(layer_id: int) -> Variant` *const* — Returns the custom data value for custom data layer with index `layer_id`.
- `get_navigation_polygon(layer_id: int, flip_h: bool = false, flip_v: bool = false, transpose: bool = false) -> NavigationPolygon` *const* — Returns the navigation polygon of the tile for the TileSet navigation layer with index `layer_id`.
- `get_occluder(layer_id: int, flip_h: bool = false, flip_v: bool = false, transpose: bool = false) -> OccluderPolygon2D` *const* *(deprecated)* — Returns the occluder polygon of the tile for the TileSet occlusion layer with index `layer_id`.
- `get_occluder_polygon(layer_id: int, polygon_index: int, flip_h: bool = false, flip_v: bool = false, transpose: bool = false) -> OccluderPolygon2D` *const* — Returns the occluder polygon at index `polygon_index` from the TileSet occlusion layer with index `layer_id`.
- `get_occluder_polygons_count(layer_id: int) -> int` *const* — Returns the number of occluder polygons of the tile in the TileSet occlusion layer with index `layer_id`.
- `get_terrain_peering_bit(peering_bit: TileSet.CellNeighbor) -> int` *const* — Returns the tile's terrain bit for the given `peering_bit` direction.
- `has_custom_data(layer_name: String) -> bool` *const* — Returns whether there exists a custom data layer named `layer_name`.
- `is_collision_polygon_one_way(layer_id: int, polygon_index: int) -> bool` *const* — Returns whether one-way collisions are enabled for the polygon at index `polygon_index` for TileSet physics layer with index `layer_id`.
- `is_valid_terrain_peering_bit(peering_bit: TileSet.CellNeighbor) -> bool` *const* — Returns whether the given `peering_bit` direction is valid for this tile.
- `remove_collision_polygon(layer_id: int, polygon_index: int) -> void` — Removes the polygon at index `polygon_index` for TileSet physics layer with index `layer_id`.
- `remove_occluder_polygon(layer_id: int, polygon_index: int) -> void` — Removes the polygon at index `polygon_index` for TileSet occlusion layer with index `layer_id`.
- `set_collision_polygon_one_way(layer_id: int, polygon_index: int, one_way: bool) -> void` — Enables/disables one-way collisions on the polygon at index `polygon_index` for TileSet physics layer with index `layer_id`.
- `set_collision_polygon_one_way_margin(layer_id: int, polygon_index: int, one_way_margin: float) -> void` — Sets the one-way margin (for one-way platforms) of the polygon at index `polygon_index` for TileSet physics layer with index `layer_id`.
- `set_collision_polygon_points(layer_id: int, polygon_index: int, polygon: PackedVector2Array) -> void` — Sets the points of the polygon at index `polygon_index` for TileSet physics layer with index `layer_id`.
- `set_collision_polygons_count(layer_id: int, polygons_count: int) -> void` — Sets the polygons count for TileSet physics layer with index `layer_id`.
- `set_constant_angular_velocity(layer_id: int, velocity: float) -> void` — Sets the constant angular velocity.
- `set_constant_linear_velocity(layer_id: int, velocity: Vector2) -> void` — Sets the constant linear velocity.
- `set_custom_data(layer_name: String, value: Variant) -> void` — Sets the tile's custom data value for the TileSet custom data layer with name `layer_name`.
- `set_custom_data_by_layer_id(layer_id: int, value: Variant) -> void` — Sets the tile's custom data value for the TileSet custom data layer with index `layer_id`.
- `set_navigation_polygon(layer_id: int, navigation_polygon: NavigationPolygon) -> void` — Sets the navigation polygon for the TileSet navigation layer with index `layer_id`.
- `set_occluder(layer_id: int, occluder_polygon: OccluderPolygon2D) -> void` *(deprecated)* — Sets the occluder for the TileSet occlusion layer with index `layer_id`.
- `set_occluder_polygon(layer_id: int, polygon_index: int, polygon: OccluderPolygon2D) -> void` — Sets the occluder for polygon with index `polygon_index` in the TileSet occlusion layer with index `layer_id`.
- `set_occluder_polygons_count(layer_id: int, polygons_count: int) -> void` — Sets the occluder polygon count in the TileSet occlusion layer with index `layer_id`.
- `set_terrain_peering_bit(peering_bit: TileSet.CellNeighbor, terrain: int) -> void` — Sets the tile's terrain bit for the given `peering_bit` direction.

## Signals

- `changed()` — Emitted when any of the properties are changed.
