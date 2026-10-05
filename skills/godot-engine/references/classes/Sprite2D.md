# Sprite2D

**Inherits:** Node2D

General-purpose sprite node.

A node that displays a 2D texture. The texture displayed can be a region from a larger atlas texture, or a frame from a sprite sheet animation.

## Properties

- `centered: bool` = `true` — If `true`, texture is centered.
- `flip_h: bool` = `false` — If `true`, texture is flipped horizontally.
- `flip_v: bool` = `false` — If `true`, texture is flipped vertically.
- `frame: int` = `0` — Current frame to display from sprite sheet.
- `frame_coords: Vector2i` = `Vector2i(0, 0)` — Coordinates of the frame to display from sprite sheet.
- `hframes: int` = `1` — The number of columns in the sprite sheet.
- `offset: Vector2` = `Vector2(0, 0)` — The texture's drawing offset.
- `region_enabled: bool` = `false` — If `true`, texture is cut from a larger atlas texture.
- `region_filter_clip_enabled: bool` = `false` — If `true`, the area outside of the `region_rect` is clipped to avoid bleeding of the surrounding texture pixels.
- `region_rect: Rect2` = `Rect2(0, 0, 0, 0)` — The region of the atlas texture to display.
- `texture: Texture2D` — Texture2D object to draw.
- `vframes: int` = `1` — The number of rows in the sprite sheet.

## Methods

- `get_rect() -> Rect2` *const* — Returns a Rect2 representing the Sprite2D's boundary in local coordinates.
- `is_pixel_opaque(pos: Vector2) -> bool` *const* — Returns `true` if the pixel at the given position is opaque, `false` otherwise.

## Signals

- `frame_changed()` — Emitted when the `frame` changes.
- `texture_changed()` — Emitted when the `texture` changes.
