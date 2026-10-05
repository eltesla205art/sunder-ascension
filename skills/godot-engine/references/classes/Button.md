# Button

**Inherits:** BaseButton

A themed button that can contain text and an icon.

Button is the standard themed button. It can contain text and an icon, and it will display them according to the current Theme. Example: Create a button and connect a method that will be called when the button is pressed:  See also BaseButton which contains common properties and methods associated with this node. Note: Buttons support multitouch via touch input, allowing multiple buttons to be pressed at the same time.

## Properties

- `alignment: HorizontalAlignment` = `1` — Text alignment policy for the button's text.
- `autowrap_mode: TextServer.AutowrapMode` = `0` — If set to something other than `TextServer.AUTOWRAP_OFF`, the text gets wrapped inside the node's bounding rectangle.
- `autowrap_trim_flags: TextServer.LineBreakFlag` = `128` — Autowrap space trimming flags.
- `clip_text: bool` = `false` — If `true`, text that is too large to fit the button is clipped horizontally.
- `expand_icon: bool` = `false` — When enabled, the button's icon will expand/shrink to fit the button's size while keeping its aspect.
- `flat: bool` = `false` — Flat buttons don't display decoration.
- `icon: Texture2D` — Button's icon, if text is present the icon will be placed before the text.
- `icon_alignment: HorizontalAlignment` = `0` — Specifies if the icon should be aligned horizontally to the left, right, or center of a button.
- `language: String` = `""` — Language code used for line-breaking and text shaping algorithms.
- `text: String` = `""` — The button's text that will be displayed inside the button's area.
- `text_direction: Control.TextDirection` = `0` — Base text writing direction.
- `text_overrun_behavior: TextServer.OverrunBehavior` = `0` — Sets the clipping behavior when the text exceeds the node's bounding rectangle.
- `vertical_icon_alignment: VerticalAlignment` = `1` — Specifies if the icon should be aligned vertically to the top, bottom, or center of a button.

## Theme items

- `font_color: Color` (color) = `Color(0.875, 0.875, 0.875, 1)`
- `font_disabled_color: Color` (color) = `Color(0.875, 0.875, 0.875, 0.5)`
- `font_focus_color: Color` (color) = `Color(0.95, 0.95, 0.95, 1)`
- `font_hover_color: Color` (color) = `Color(0.95, 0.95, 0.95, 1)`
- `font_hover_pressed_color: Color` (color) = `Color(1, 1, 1, 1)`
- `font_outline_color: Color` (color) = `Color(0, 0, 0, 1)`
- `font_pressed_color: Color` (color) = `Color(1, 1, 1, 1)`
- `icon_disabled_color: Color` (color) = `Color(1, 1, 1, 0.4)`
- `icon_focus_color: Color` (color) = `Color(1, 1, 1, 1)`
- `icon_hover_color: Color` (color) = `Color(1, 1, 1, 1)`
- `icon_hover_pressed_color: Color` (color) = `Color(1, 1, 1, 1)`
- `icon_normal_color: Color` (color) = `Color(1, 1, 1, 1)`
- `icon_pressed_color: Color` (color) = `Color(1, 1, 1, 1)`
- `align_to_largest_stylebox: int` (constant) = `0`
- `h_separation: int` (constant) = `4`
- `icon_max_width: int` (constant) = `0`
- `line_spacing: int` (constant) = `0`
- `outline_size: int` (constant) = `0`
- `font: Font` (font)
- `font_size: int` (font_size)
- `icon: Texture2D` (icon)
- `disabled: StyleBox` (style)
- `disabled_mirrored: StyleBox` (style)
- `focus: StyleBox` (style)
- `hover: StyleBox` (style)
- `hover_mirrored: StyleBox` (style)
- `hover_pressed: StyleBox` (style)
- `hover_pressed_mirrored: StyleBox` (style)
- `normal: StyleBox` (style)
- `normal_mirrored: StyleBox` (style)
- `pressed: StyleBox` (style)
- `pressed_mirrored: StyleBox` (style)
