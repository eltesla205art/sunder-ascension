# Label

**Inherits:** Control

A control for displaying plain text.

A control for displaying plain text. It gives you control over the horizontal and vertical alignment and can wrap the text inside the node's bounding rectangle. It doesn't support bold, italics, or other rich text formatting. For that, use RichTextLabel instead.

## Properties

- `autowrap_mode: TextServer.AutowrapMode` = `0` — If set to something other than `TextServer.AUTOWRAP_OFF`, the text gets wrapped inside the node's bounding rectangle.
- `autowrap_trim_flags: TextServer.LineBreakFlag` = `192` — Autowrap space trimming flags.
- `clip_text: bool` = `false` — If `true`, the Label only shows the text that fits inside its bounding rectangle and will clip text horizontally.
- `ellipsis_char: String` = `"…"` — Ellipsis character used for text clipping.
- `horizontal_alignment: HorizontalAlignment` = `0` — Controls the text's horizontal alignment.
- `justification_flags: TextServer.JustificationFlag` = `163` — Line fill alignment rules.
- `label_settings: LabelSettings` — A LabelSettings resource that can be shared between multiple Label nodes.
- `language: String` = `""` — Language code used for line-breaking and text shaping algorithms.
- `lines_skipped: int` = `0` — The number of the lines ignored and not displayed from the start of the `text` value.
- `max_lines_visible: int` = `-1` — Limits the lines of text the node shows on screen.
- `maximum_font_size: int` = `60` — The maximum font size used when `resize_font_to_fit` is enabled.
- `minimum_font_size: int` = `10` — The minimum font size used when `resize_font_to_fit` is enabled.
- `mouse_filter: Control.MouseFilter` = `2` — 
- `paragraph_separator: String` = `"\\n"` — String used as a paragraph separator.
- `resize_font_to_fit: bool` = `false` — If `true`, the text size will automatically shrink or grow to fit within the node's bounding rectangle.
- `size_flags_vertical: Control.SizeFlags` = `4` — 
- `structured_text_bidi_override: TextServer.StructuredTextParser` = `0` — Set BiDi algorithm override for the structured text.
- `structured_text_bidi_override_options: Array` = `[]` — Set additional options for BiDi override.
- `tab_stops: PackedFloat32Array` = `PackedFloat32Array()` — Aligns text to the given tab-stops.
- `text: String` = `""` — The text to display on screen.
- `text_direction: Control.TextDirection` = `0` — Base text writing direction.
- `text_overrun_behavior: TextServer.OverrunBehavior` = `0` — The clipping behavior when the text exceeds the node's bounding rectangle.
- `uppercase: bool` = `false` — If `true`, all the text displays as UPPERCASE.
- `vertical_alignment: VerticalAlignment` = `0` — Controls the text's vertical alignment.
- `visible_characters: int` = `-1` — The number of characters to display.
- `visible_characters_behavior: TextServer.VisibleCharactersBehavior` = `0` — The clipping behavior when `visible_characters` or `visible_ratio` is set.
- `visible_ratio: float` = `1.0` — The fraction of characters to display, relative to the total number of characters (see `get_total_character_count`).

## Methods

- `get_character_bounds(pos: int) -> Rect2` *const* — Returns the bounding rectangle of the character at position `pos` in the label's local coordinate system.
- `get_line_count() -> int` *const* — Returns the number of lines of text the Label has.
- `get_line_height(line: int = -1) -> int` *const* — Returns the height of the line `line`.
- `get_rendered_font_size() -> int` *const* — Returns the font size that is currently used for rendering.
- `get_total_character_count() -> int` *const* — Returns the total number of printable characters in the text (excluding spaces and newlines).
- `get_visible_line_count() -> int` *const* — Returns the number of lines shown.

## Theme items

- `font_color: Color` (color) = `Color(1, 1, 1, 1)`
- `font_outline_color: Color` (color) = `Color(0, 0, 0, 1)`
- `font_shadow_color: Color` (color) = `Color(0, 0, 0, 0)`
- `line_spacing: int` (constant) = `3`
- `outline_size: int` (constant) = `0`
- `paragraph_spacing: int` (constant) = `0`
- `shadow_offset_x: int` (constant) = `1`
- `shadow_offset_y: int` (constant) = `1`
- `shadow_outline_size: int` (constant) = `1`
- `font: Font` (font)
- `font_size: int` (font_size)
- `focus: StyleBox` (style)
- `normal: StyleBox` (style)
