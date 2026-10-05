# TextureRect

**Inherits:** Control

A control that displays a texture.

A control that displays a texture, for example an icon inside a GUI. The texture's placement can be controlled with the `stretch_mode` property. It can scale, tile, or stay centered inside its bounding rectangle.

## Properties

- `expand_mode: TextureRect.ExpandMode` = `0` — Defines how minimum size is determined based on the texture's size.
- `flip_h: bool` = `false` — If `true`, texture is flipped horizontally.
- `flip_v: bool` = `false` — If `true`, texture is flipped vertically.
- `mouse_filter: Control.MouseFilter` = `1` — 
- `stretch_mode: TextureRect.StretchMode` = `0` — Controls the texture's behavior when resizing the node's bounding rectangle.
- `texture: Texture2D` — The node's Texture2D resource.

## Enum ExpandMode

- `EXPAND_KEEP_SIZE = 0` — The minimum size will be equal to texture size, i.e.
- `EXPAND_IGNORE_SIZE = 1` — The size of the texture won't be considered for minimum size calculation, so the TextureRect can be shrunk down past the texture size.
- `EXPAND_FIT_WIDTH = 2` — The height of the texture will be ignored.
- `EXPAND_FIT_WIDTH_PROPORTIONAL = 3` — Same as `EXPAND_FIT_WIDTH`, but keeps texture's aspect ratio.
- `EXPAND_FIT_HEIGHT = 4` — The width of the texture will be ignored.
- `EXPAND_FIT_HEIGHT_PROPORTIONAL = 5` — Same as `EXPAND_FIT_HEIGHT`, but keeps texture's aspect ratio.

## Enum StretchMode

- `STRETCH_SCALE = 0` — Scale to fit the node's bounding rectangle.
- `STRETCH_TILE = 1` — Tile inside the node's bounding rectangle.
- `STRETCH_KEEP = 2` — The texture keeps its original size and stays in the bounding rectangle's top-left corner.
- `STRETCH_KEEP_CENTERED = 3` — The texture keeps its original size and stays centered in the node's bounding rectangle.
- `STRETCH_KEEP_ASPECT = 4` — Scale the texture to fit the node's bounding rectangle, but maintain the texture's aspect ratio.
- `STRETCH_KEEP_ASPECT_CENTERED = 5` — Scale the texture to fit the node's bounding rectangle, center it and maintain its aspect ratio.
- `STRETCH_KEEP_ASPECT_COVERED = 6` — Scale the texture so that the shorter side fits the bounding rectangle.
