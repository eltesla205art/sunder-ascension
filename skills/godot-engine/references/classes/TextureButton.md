# TextureButton

**Inherits:** BaseButton

Texture-based button. Supports Pressed, Hover, Disabled and Focused states.

TextureButton has the same functionality as Button, except it uses sprites instead of Godot's Theme resource. It is faster to create, but it doesn't support localization like more complex Controls. See also BaseButton which contains common properties and methods associated with this node. Note: Setting a texture for the "normal" state (`texture_normal`) is recommended.

## Properties

- `flip_h: bool` = `false` — If `true`, texture is flipped horizontally.
- `flip_v: bool` = `false` — If `true`, texture is flipped vertically.
- `ignore_texture_size: bool` = `false` — If `true`, the size of the texture won't be considered for minimum size calculation, so the TextureButton can be shrunk down past the texture size.
- `stretch_mode: TextureButton.StretchMode` = `2` — Controls the texture's behavior when you resize the node's bounding rectangle.
- `texture_click_mask: BitMap` — Pure black and white BitMap image to use for click detection.
- `texture_disabled: Texture2D` — Texture to display when the node is disabled.
- `texture_focused: Texture2D` — Texture to overlay on the base texture when the node has mouse or keyboard focus.
- `texture_hover: Texture2D` — Texture to display when the mouse hovers over the node.
- `texture_normal: Texture2D` — Texture to display by default, when the node is not in the disabled, hover or pressed state.
- `texture_pressed: Texture2D` — Texture to display on mouse down over the node, if the node has keyboard focus and the player presses the Enter key or if the player presses the `BaseButton.shortcut` key.

## Enum StretchMode

- `STRETCH_SCALE = 0` — Scale to fit the node's bounding rectangle.
- `STRETCH_TILE = 1` — Tile inside the node's bounding rectangle.
- `STRETCH_KEEP = 2` — The texture keeps its original size and stays in the bounding rectangle's top-left corner.
- `STRETCH_KEEP_CENTERED = 3` — The texture keeps its original size and stays centered in the node's bounding rectangle.
- `STRETCH_KEEP_ASPECT = 4` — Scale the texture to fit the node's bounding rectangle, but maintain the texture's aspect ratio.
- `STRETCH_KEEP_ASPECT_CENTERED = 5` — Scale the texture to fit the node's bounding rectangle, center it, and maintain its aspect ratio.
- `STRETCH_KEEP_ASPECT_COVERED = 6` — Scale the texture so that the shorter side fits the bounding rectangle.
