# TileSetAtlasSource

**Inherits:** TileSetSource

Exposes a 2D atlas texture as a set of tiles for a TileSet resource.

An atlas is a grid of tiles laid out on a texture. Each tile in the grid must be exposed using `create_tile`. Those tiles are then indexed using their coordinates in the grid. Each tile can also have a size in the grid coordinates, making it more or less cells in the atlas.

## Properties

- `margins: Vector2i` = `Vector2i(0, 0)` — Margins, in pixels, to offset the origin of the grid in the texture.
- `separation: Vector2i` = `Vector2i(0, 0)` — Separation, in pixels, between each tile texture region of the grid.
- `texture: Texture2D` — The atlas texture.
- `texture_region_size: Vector2i` = `Vector2i(16, 16)` — The base tile size in the texture (in pixel).
- `use_texture_padding: bool` = `true` — If `true`, generates an internal texture with an additional one pixel padding around each tile.

## Methods

- `clear_tiles_outside_texture() -> void` — Removes all tiles that don't fit the available texture area.
- `create_alternative_tile(atlas_coords: Vector2i, alternative_id_override: int = -1) -> int` — Creates an alternative tile for the tile at coordinates `atlas_coords`.
- `create_tile(atlas_coords: Vector2i, size: Vector2i = Vector2i(1, 1)) -> void` — Creates a new tile at coordinates `atlas_coords` with the given `size`.
- `get_atlas_grid_size() -> Vector2i` *const* — Returns the atlas grid size, which depends on how many tiles can fit in the texture.
- `get_next_alternative_tile_id(atlas_coords: Vector2i) -> int` *const* — Returns the alternative ID a following call to `create_alternative_tile` would return.
- `get_runtime_texture() -> Texture2D` *const* — If `use_texture_padding` is `false`, returns `texture`.
- `get_runtime_tile_texture_region(atlas_coords: Vector2i, frame: int) -> Rect2i` *const* — Returns the region of the tile at coordinates `atlas_coords` for the given `frame` inside the texture returned by `get_runtime_texture`.
- `get_tile_animation_columns(atlas_coords: Vector2i) -> int` *const* — Returns how many columns the tile at `atlas_coords` has in its animation layout.
- `get_tile_animation_frame_duration(atlas_coords: Vector2i, frame_index: int) -> float` *const* — Returns the animation frame duration of frame `frame_index` for the tile at coordinates `atlas_coords`.
- `get_tile_animation_frames_count(atlas_coords: Vector2i) -> int` *const* — Returns how many animation frames has the tile at coordinates `atlas_coords`.
- `get_tile_animation_mode(atlas_coords: Vector2i) -> int[TileSetAtlasSource.TileAnimationMode]` *const* — Returns the tile animation mode of the tile at `atlas_coords`.
- `get_tile_animation_separation(atlas_coords: Vector2i) -> Vector2i` *const* — Returns the separation (as in the atlas grid) between each frame of an animated tile at coordinates `atlas_coords`.
- `get_tile_animation_speed(atlas_coords: Vector2i) -> float` *const* — Returns the animation speed of the tile at coordinates `atlas_coords`.
- `get_tile_animation_total_duration(atlas_coords: Vector2i) -> float` *const* — Returns the sum of the sum of the frame durations of the tile at coordinates `atlas_coords`.
- `get_tile_at_coords(atlas_coords: Vector2i) -> Vector2i` *const* — If there is a tile covering the `atlas_coords` coordinates, returns the top-left coordinates of the tile (thus its coordinate ID).
- `get_tile_data(atlas_coords: Vector2i, alternative_tile: int) -> TileData` *const* — Returns the TileData object for the given atlas coordinates and alternative ID.
- `get_tile_size_in_atlas(atlas_coords: Vector2i) -> Vector2i` *const* — Returns the size of the tile (in the grid coordinates system) at coordinates `atlas_coords`.
- `get_tile_texture_region(atlas_coords: Vector2i, frame: int = 0) -> Rect2i` *const* — Returns a tile's texture region in the atlas texture.
- `get_tiles_to_be_removed_on_change(texture: Texture2D, margins: Vector2i, separation: Vector2i, texture_region_size: Vector2i) -> PackedVector2Array` — Returns an array of tiles coordinates ID that will be automatically removed when modifying one or several of those properties: `texture`, `margins`, `separation` or `texture_region_size`.
- `has_room_for_tile(atlas_coords: Vector2i, size: Vector2i, animation_columns: int, animation_separation: Vector2i, frames_count: int, ignored_tile: Vector2i = Vector2i(-1, -1)) -> bool` *const* — Returns whether there is enough room in an atlas to create/modify a tile with the given properties.
- `has_tiles_outside_texture() -> bool` *const* — Checks if the source has any tiles that don't fit the texture area (either partially or completely).
- `move_tile_in_atlas(atlas_coords: Vector2i, new_atlas_coords: Vector2i = Vector2i(-1, -1), new_size: Vector2i = Vector2i(-1, -1)) -> void` — Move the tile and its alternatives at the `atlas_coords` coordinates to the `new_atlas_coords` coordinates with the `new_size` size.
- `remove_alternative_tile(atlas_coords: Vector2i, alternative_tile: int) -> void` — Remove a tile's alternative with alternative ID `alternative_tile`.
- `remove_tile(atlas_coords: Vector2i) -> void` — Remove a tile and its alternative at coordinates `atlas_coords`.
- `set_alternative_tile_id(atlas_coords: Vector2i, alternative_tile: int, new_id: int) -> void` — Change a tile's alternative ID from `alternative_tile` to `new_id`.
- `set_tile_animation_columns(atlas_coords: Vector2i, frame_columns: int) -> void` — Sets the number of columns in the animation layout of the tile at coordinates `atlas_coords`.
- `set_tile_animation_frame_duration(atlas_coords: Vector2i, frame_index: int, duration: float) -> void` — Sets the animation frame `duration` of frame `frame_index` for the tile at coordinates `atlas_coords`.
- `set_tile_animation_frames_count(atlas_coords: Vector2i, frames_count: int) -> void` — Sets how many animation frames the tile at coordinates `atlas_coords` has.
- `set_tile_animation_mode(atlas_coords: Vector2i, mode: TileSetAtlasSource.TileAnimationMode) -> void` — Sets the tile animation mode of the tile at `atlas_coords` to `mode`.
- `set_tile_animation_separation(atlas_coords: Vector2i, separation: Vector2i) -> void` — Sets the margin (in grid tiles) between each tile in the animation layout of the tile at coordinates `atlas_coords` has.
- `set_tile_animation_speed(atlas_coords: Vector2i, speed: float) -> void` — Sets the animation speed of the tile at coordinates `atlas_coords` has.

## Enum TileAnimationMode

- `TILE_ANIMATION_MODE_DEFAULT = 0` — Tile animations start at same time, looking identical.
- `TILE_ANIMATION_MODE_RANDOM_START_TIMES = 1` — Tile animations start at random times, looking varied.
- `TILE_ANIMATION_MODE_MAX = 2` — Represents the size of the `TileAnimationMode` enum.

## Constants

- `TRANSFORM_FLIP_H = 4096` — Represents cell's horizontal flip flag.
- `TRANSFORM_FLIP_V = 8192` — Represents cell's vertical flip flag.
- `TRANSFORM_TRANSPOSE = 16384` — Represents cell's transposed flag.
