# TileSetSource

**Inherits:** Resource

Exposes a set of tiles for a TileSet resource.

Exposes a set of tiles for a TileSet resource. Tiles in a source are indexed with two IDs, coordinates ID (of type Vector2i) and an alternative ID (of type int), named according to their use in the TileSetAtlasSource class. Depending on the TileSet source type, those IDs might have restrictions on their values, this is why the base TileSetSource class only exposes getters for them. You can iterate over all tiles exposed by a TileSetSource by first iterating over coordinates IDs using `get_tiles_count` and `get_tile_id`, then over alternative IDs using `get_alternative_tiles_count` and `get_alternative_tile_id`.

## Methods

- `get_alternative_tile_id(atlas_coords: Vector2i, index: int) -> int` *const* — Returns the alternative ID for the tile with coordinates ID `atlas_coords` at index `index`.
- `get_alternative_tiles_count(atlas_coords: Vector2i) -> int` *const* — Returns the number of alternatives tiles for the coordinates ID `atlas_coords`.
- `get_tile_id(index: int) -> Vector2i` *const* — Returns the tile coordinates ID of the tile with index `index`.
- `get_tiles_count() -> int` *const* — Returns how many tiles this atlas source defines (not including alternative tiles).
- `has_alternative_tile(atlas_coords: Vector2i, alternative_tile: int) -> bool` *const* — Returns if the base tile at coordinates `atlas_coords` has an alternative with ID `alternative_tile`.
- `has_tile(atlas_coords: Vector2i) -> bool` *const* — Returns if this atlas has a tile with coordinates ID `atlas_coords`.
