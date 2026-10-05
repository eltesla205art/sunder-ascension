# ProgressBar

**Inherits:** Range

A control used for visual representation of a percentage.

A control used for visual representation of a percentage. Shows the fill percentage in the center. Can also be used to show indeterminate progress. For more fill modes, use TextureProgressBar instead.

## Properties

- `editor_preview_indeterminate: bool` — If `false`, the `indeterminate` animation will be paused in the editor.
- `fill_mode: int` = `0` — The fill direction.
- `indeterminate: bool` = `false` — When set to `true`, the progress bar indicates that something is happening with an animation, but does not show the fill percentage or value.
- `show_percentage: bool` = `true` — If `true`, the fill percentage is displayed on the bar.

## Enum FillMode

- `FILL_BEGIN_TO_END = 0` — The progress bar fills from begin to end horizontally, according to the language direction.
- `FILL_END_TO_BEGIN = 1` — The progress bar fills from end to begin horizontally, according to the language direction.
- `FILL_TOP_TO_BOTTOM = 2` — The progress fills from top to bottom.
- `FILL_BOTTOM_TO_TOP = 3` — The progress fills from bottom to top.

## Theme items

- `font_color: Color` (color) = `Color(0.95, 0.95, 0.95, 1)`
- `font_outline_color: Color` (color) = `Color(0, 0, 0, 1)`
- `outline_size: int` (constant) = `0`
- `font: Font` (font)
- `font_size: int` (font_size)
- `background: StyleBox` (style)
- `fill: StyleBox` (style)
