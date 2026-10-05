# TextureProgressBar

**Inherits:** Range

Texture-based progress bar. Useful for loading screens and life or stamina bars.

TextureProgressBar works like ProgressBar, but uses up to 3 textures instead of Godot's Theme resource. It can be used to create horizontal, vertical and radial progress bars.

## Properties

- `fill_mode: int` = `0` — The fill direction.
- `mouse_filter: Control.MouseFilter` = `1` — 
- `nine_patch_stretch: bool` = `false` — If `true`, Godot treats the bar's textures like in NinePatchRect.
- `radial_center_offset: Vector2` = `Vector2(0, 0)` — Offsets `texture_progress` if `fill_mode` is `FILL_CLOCKWISE`, `FILL_COUNTER_CLOCKWISE`, or `FILL_CLOCKWISE_AND_COUNTER_CLOCKWISE`.
- `radial_fill_degrees: float` = `360.0` — Upper limit for the fill of `texture_progress` if `fill_mode` is `FILL_CLOCKWISE`, `FILL_COUNTER_CLOCKWISE`, or `FILL_CLOCKWISE_AND_COUNTER_CLOCKWISE`.
- `radial_initial_angle: float` = `0.0` — Starting angle for the fill of `texture_progress` if `fill_mode` is `FILL_CLOCKWISE`, `FILL_COUNTER_CLOCKWISE`, or `FILL_CLOCKWISE_AND_COUNTER_CLOCKWISE`.
- `size_flags_vertical: Control.SizeFlags` = `1` — 
- `step: float` = `1.0` — 
- `stretch_margin_bottom: int` = `0` — The height of the 9-patch's bottom row.
- `stretch_margin_left: int` = `0` — The width of the 9-patch's left column.
- `stretch_margin_right: int` = `0` — The width of the 9-patch's right column.
- `stretch_margin_top: int` = `0` — The height of the 9-patch's top row.
- `texture_over: Texture2D` — Texture2D that draws over the progress bar.
- `texture_progress: Texture2D` — Texture2D that clips based on the node's `value` and `fill_mode`.
- `texture_progress_offset: Vector2` = `Vector2(0, 0)` — The offset of `texture_progress`.
- `texture_under: Texture2D` — Texture2D that draws under the progress bar.
- `tint_over: Color` = `Color(1, 1, 1, 1)` — Multiplies the color of the bar's `texture_over` texture.
- `tint_progress: Color` = `Color(1, 1, 1, 1)` — Multiplies the color of the bar's `texture_progress` texture.
- `tint_under: Color` = `Color(1, 1, 1, 1)` — Multiplies the color of the bar's `texture_under` texture.

## Methods

- `get_stretch_margin(margin: Side) -> int` *const* — Returns the stretch margin with the specified index.
- `set_stretch_margin(margin: Side, value: int) -> void` — Sets the stretch margin with the specified index.

## Enum FillMode

- `FILL_LEFT_TO_RIGHT = 0` — The `texture_progress` fills from left to right.
- `FILL_RIGHT_TO_LEFT = 1` — The `texture_progress` fills from right to left.
- `FILL_TOP_TO_BOTTOM = 2` — The `texture_progress` fills from top to bottom.
- `FILL_BOTTOM_TO_TOP = 3` — The `texture_progress` fills from bottom to top.
- `FILL_CLOCKWISE = 4` — Turns the node into a radial bar.
- `FILL_COUNTER_CLOCKWISE = 5` — Turns the node into a radial bar.
- `FILL_BILINEAR_LEFT_AND_RIGHT = 6` — The `texture_progress` fills from the center, expanding both towards the left and the right.
- `FILL_BILINEAR_TOP_AND_BOTTOM = 7` — The `texture_progress` fills from the center, expanding both towards the top and the bottom.
- `FILL_CLOCKWISE_AND_COUNTER_CLOCKWISE = 8` — Turns the node into a radial bar.
