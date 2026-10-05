# LinkButton

**Inherits:** BaseButton

A button that represents a link.

A button that represents a link. This type of button is primarily used for interactions that cause a context change (like linking to a web page). See also BaseButton which contains common properties and methods associated with this node.

## Properties

- `ellipsis_char: String` = `"…"` — Ellipsis character used for text clipping.
- `focus_mode: Control.FocusMode` = `3` — 
- `language: String` = `""` — Language code used for line-breaking and text shaping algorithms.
- `mouse_default_cursor_shape: Control.CursorShape` = `2` — 
- `structured_text_bidi_override: TextServer.StructuredTextParser` = `0` — Set BiDi algorithm override for the structured text.
- `structured_text_bidi_override_options: Array` = `[]` — Set additional options for BiDi override.
- `text: String` = `""` — The button's text that will be displayed inside the button's area.
- `text_direction: Control.TextDirection` = `0` — Base text writing direction.
- `text_overrun_behavior: TextServer.OverrunBehavior` = `0` — Sets the clipping behavior when the text exceeds the node's bounding rectangle.
- `underline: LinkButton.UnderlineMode` = `0` — The underline mode to use for the text.
- `uri: String` = `""` — The URI for this LinkButton.

## Enum UnderlineMode

- `UNDERLINE_MODE_ALWAYS = 0` — The LinkButton will always show an underline at the bottom of its text.
- `UNDERLINE_MODE_ON_HOVER = 1` — The LinkButton will show an underline at the bottom of its text when the mouse cursor is over it.
- `UNDERLINE_MODE_NEVER = 2` — The LinkButton will never show an underline at the bottom of its text.

## Theme items

- `font_color: Color` (color) = `Color(0.875, 0.875, 0.875, 1)`
- `font_disabled_color: Color` (color) = `Color(0, 0, 0, 1)`
- `font_focus_color: Color` (color) = `Color(0.95, 0.95, 0.95, 1)`
- `font_hover_color: Color` (color) = `Color(0.95, 0.95, 0.95, 1)`
- `font_hover_pressed_color: Color` (color) = `Color(0, 0, 0, 1)`
- `font_outline_color: Color` (color) = `Color(0, 0, 0, 1)`
- `font_pressed_color: Color` (color) = `Color(1, 1, 1, 1)`
- `outline_size: int` (constant) = `0`
- `underline_spacing: int` (constant) = `2`
- `font: Font` (font)
- `font_size: int` (font_size)
- `focus: StyleBox` (style)
