# Sprite3D

**Inherits:** SpriteBase3D

2D sprite node in a 3D world.

A node that displays a 2D texture in a 3D environment. The texture displayed can be a region from a larger atlas texture, or a frame from a sprite sheet animation. See also SpriteBase3D where properties such as the billboard mode are defined.

## Properties

- `frame: int` = `0` — Current frame to display from sprite sheet.
- `frame_coords: Vector2i` = `Vector2i(0, 0)` — Coordinates of the frame to display from sprite sheet.
- `hframes: int` = `1` — The number of columns in the sprite sheet.
- `region_enabled: bool` = `false` — If `true`, the sprite will use `region_rect` and display only the specified part of its texture.
- `region_rect: Rect2` = `Rect2(0, 0, 0, 0)` — The region of the atlas texture to display.
- `texture: Texture2D` — Texture2D object to draw.
- `vframes: int` = `1` — The number of rows in the sprite sheet.

## Signals

- `frame_changed()` — Emitted when the `frame` changes.
- `texture_changed()` — Emitted when the `texture` changes.
