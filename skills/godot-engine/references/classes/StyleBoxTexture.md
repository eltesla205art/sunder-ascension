# StyleBoxTexture

**Inherits:** StyleBox

A texture-based nine-patch StyleBox.

A texture-based nine-patch StyleBox, in a way similar to NinePatchRect. This stylebox performs a 3×3 scaling of a texture, where only the center cell is fully stretched. This makes it possible to design bordered styles regardless of the stylebox's size.

## Properties

- `axis_stretch_horizontal: StyleBoxTexture.AxisStretchMode` = `0` — Controls how the stylebox's texture will be stretched or tiled horizontally.
- `axis_stretch_vertical: StyleBoxTexture.AxisStretchMode` = `0` — Controls how the stylebox's texture will be stretched or tiled vertically.
- `draw_center: bool` = `true` — If `true`, the nine-patch texture's center tile will be drawn.
- `expand_margin_bottom: float` = `0.0` — Expands the bottom margin of this style box when drawing, causing it to be drawn larger than requested.
- `expand_margin_left: float` = `0.0` — Expands the left margin of this style box when drawing, causing it to be drawn larger than requested.
- `expand_margin_right: float` = `0.0` — Expands the right margin of this style box when drawing, causing it to be drawn larger than requested.
- `expand_margin_top: float` = `0.0` — Expands the top margin of this style box when drawing, causing it to be drawn larger than requested.
- `modulate_color: Color` = `Color(1, 1, 1, 1)` — Modulates the color of the texture when this style box is drawn.
- `region_rect: Rect2` = `Rect2(0, 0, 0, 0)` — The region to use from the `texture`.
- `texture: Texture2D` — The texture to use when drawing this style box.
- `texture_margin_bottom: float` = `0.0` — Increases the bottom margin of the 3×3 texture box.
- `texture_margin_left: float` = `0.0` — Increases the left margin of the 3×3 texture box.
- `texture_margin_right: float` = `0.0` — Increases the right margin of the 3×3 texture box.
- `texture_margin_top: float` = `0.0` — Increases the top margin of the 3×3 texture box.

## Methods

- `get_expand_margin(margin: Side) -> float` *const* — Returns the expand margin size of the specified `Side`.
- `get_texture_margin(margin: Side) -> float` *const* — Returns the margin size of the specified `Side`.
- `set_expand_margin(margin: Side, size: float) -> void` — Sets the expand margin to `size` pixels for the specified `Side`.
- `set_expand_margin_all(size: float) -> void` — Sets the expand margin to `size` pixels for all sides.
- `set_texture_margin(margin: Side, size: float) -> void` — Sets the margin to `size` pixels for the specified `Side`.
- `set_texture_margin_all(size: float) -> void` — Sets the margin to `size` pixels for all sides.

## Enum AxisStretchMode

- `AXIS_STRETCH_MODE_STRETCH = 0` — Stretch the stylebox's texture.
- `AXIS_STRETCH_MODE_TILE = 1` — Repeats the stylebox's texture to match the stylebox's size according to the nine-patch system.
- `AXIS_STRETCH_MODE_TILE_FIT = 2` — Repeats the stylebox's texture to match the stylebox's size according to the nine-patch system.
