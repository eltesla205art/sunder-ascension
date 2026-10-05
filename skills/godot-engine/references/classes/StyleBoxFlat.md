# StyleBoxFlat

**Inherits:** StyleBox

A customizable StyleBox that doesn't use a texture.

By configuring various properties of this style box, you can achieve many common looks without the need of a texture. This includes optionally rounded borders, antialiasing, shadows, and skew. Setting corner radius to high values is allowed. As soon as corners overlap, the stylebox will switch to a relative system:  height = 30 corner_radius_top_left = 50 corner_radius_bottom_left = 100  The relative system now would take the 1:2 ratio of the two left corners to calculate the actual corner width.

## Properties

- `anti_aliasing: bool` = `true` — Antialiasing draws a small ring around the edges, which fades to transparency.
- `anti_aliasing_size: float` = `1.0` — This changes the size of the antialiasing effect.
- `bg_color: Color` = `Color(0.6, 0.6, 0.6, 1)` — The background color of the stylebox.
- `border_blend: bool` = `false` — If `true`, the border will fade into the background color.
- `border_color: Color` = `Color(0.8, 0.8, 0.8, 1)` — Sets the color of the border.
- `border_width_bottom: int` = `0` — Border width for the bottom border.
- `border_width_left: int` = `0` — Border width for the left border.
- `border_width_right: int` = `0` — Border width for the right border.
- `border_width_top: int` = `0` — Border width for the top border.
- `corner_detail: int` = `8` — This sets the number of vertices used for each corner.
- `corner_radius_bottom_left: int` = `0` — The bottom-left corner's radius.
- `corner_radius_bottom_right: int` = `0` — The bottom-right corner's radius.
- `corner_radius_top_left: int` = `0` — The top-left corner's radius.
- `corner_radius_top_right: int` = `0` — The top-right corner's radius.
- `draw_center: bool` = `true` — Toggles drawing of the inner part of the stylebox.
- `expand_margin_bottom: float` = `0.0` — Expands the stylebox outside of the control rect on the bottom edge.
- `expand_margin_left: float` = `0.0` — Expands the stylebox outside of the control rect on the left edge.
- `expand_margin_right: float` = `0.0` — Expands the stylebox outside of the control rect on the right edge.
- `expand_margin_top: float` = `0.0` — Expands the stylebox outside of the control rect on the top edge.
- `shadow_color: Color` = `Color(0, 0, 0, 0.6)` — The color of the shadow.
- `shadow_offset: Vector2` = `Vector2(0, 0)` — The shadow offset in pixels.
- `shadow_size: int` = `0` — The shadow size in pixels.
- `skew: Vector2` = `Vector2(0, 0)` — If set to a non-zero value on either axis, `skew` distorts the StyleBox horizontally and/or vertically.

## Methods

- `get_border_width(margin: Side) -> int` *const* — Returns the specified `Side`'s border width.
- `get_border_width_min() -> int` *const* — Returns the smallest border width out of all four borders.
- `get_corner_radius(corner: Corner) -> int` *const* — Returns the given `corner`'s radius.
- `get_expand_margin(margin: Side) -> float` *const* — Returns the size of the specified `Side`'s expand margin.
- `set_border_width(margin: Side, width: int) -> void` — Sets the specified `Side`'s border width to `width` pixels.
- `set_border_width_all(width: int) -> void` — Sets the border width to `width` pixels for all sides.
- `set_corner_radius(corner: Corner, radius: int) -> void` — Sets the corner radius to `radius` pixels for the given `corner`.
- `set_corner_radius_all(radius: int) -> void` — Sets the corner radius to `radius` pixels for all corners.
- `set_expand_margin(margin: Side, size: float) -> void` — Sets the expand margin to `size` pixels for the specified `Side`.
- `set_expand_margin_all(size: float) -> void` — Sets the expand margin to `size` pixels for all sides.
