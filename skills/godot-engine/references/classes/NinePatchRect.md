# NinePatchRect

**Inherits:** Control

A control that displays a texture by keeping its corners intact, but tiling its edges and center.

Also known as 9-slice panels, NinePatchRect produces clean panels of any size based on a small texture. To do so, it splits the texture in a 3×3 grid. When you scale the node, it tiles the texture's edges horizontally or vertically, tiles the center on both axes, and leaves the corners unchanged.

## Properties

- `axis_stretch_horizontal: NinePatchRect.AxisStretchMode` = `0` — The stretch mode to use for horizontal stretching/tiling.
- `axis_stretch_vertical: NinePatchRect.AxisStretchMode` = `0` — The stretch mode to use for vertical stretching/tiling.
- `draw_center: bool` = `true` — If `true`, draw the panel's center.
- `mouse_filter: Control.MouseFilter` = `2` — 
- `patch_margin_bottom: int` = `0` — The height of the 9-slice's bottom row.
- `patch_margin_left: int` = `0` — The width of the 9-slice's left column.
- `patch_margin_right: int` = `0` — The width of the 9-slice's right column.
- `patch_margin_top: int` = `0` — The height of the 9-slice's top row.
- `region_rect: Rect2` = `Rect2(0, 0, 0, 0)` — Rectangular region of the texture to sample from.
- `texture: Texture2D` — The node's texture resource.

## Methods

- `get_patch_margin(margin: Side) -> int` *const* — Returns the size of the margin on the specified `Side`.
- `set_patch_margin(margin: Side, value: int) -> void` — Sets the size of the margin on the specified `Side` to `value` pixels.

## Signals

- `texture_changed()` — Emitted when the node's texture changes.

## Enum AxisStretchMode

- `AXIS_STRETCH_MODE_STRETCH = 0` — Stretches the center texture across the NinePatchRect.
- `AXIS_STRETCH_MODE_TILE = 1` — Repeats the center texture across the NinePatchRect.
- `AXIS_STRETCH_MODE_TILE_FIT = 2` — Repeats the center texture across the NinePatchRect, but will also stretch the texture to make sure each tile is visible in full.
