# TextParagraph

**Inherits:** RefCounted

Holds a paragraph of text.

Abstraction over TextServer for handling a single paragraph of text.

## Properties

- `alignment: HorizontalAlignment` = `0` — Paragraph horizontal alignment.
- `break_flags: TextServer.LineBreakFlag` = `3` — Line breaking rules.
- `custom_punctuation: String` = `""` — Custom punctuation character list, used for word breaking.
- `direction: TextServer.Direction` = `0` — Text writing direction.
- `ellipsis_char: String` = `"…"` — Ellipsis character used for text clipping.
- `justification_flags: TextServer.JustificationFlag` = `163` — Line fill alignment rules.
- `line_spacing: float` = `0.0` — Additional vertical spacing between lines (in pixels), spacing is added to line descent.
- `max_lines_visible: int` = `-1` — Limits the lines of text shown.
- `orientation: TextServer.Orientation` = `0` — Text orientation.
- `preserve_control: bool` = `false` — If set to `true` text will display control characters.
- `preserve_invalid: bool` = `true` — If set to `true` text will display invalid characters.
- `text_overrun_behavior: TextServer.OverrunBehavior` = `0` — The clipping behavior when the text exceeds the paragraph's set width.
- `width: float` = `-1.0` — Paragraph width.

## Methods

- `add_object(key: Variant, size: Vector2, inline_align: InlineAlignment = 5, length: int = 1, baseline: float = 0.0) -> bool` — Adds inline object to the text buffer, `key` must be unique.
- `add_string(text: String, font: Font, font_size: int, language: String = "", meta: Variant = null) -> bool` — Adds text span and font to draw it.
- `clear() -> void` — Clears text paragraph (removes text and inline objects).
- `clear_dropcap() -> void` — Removes dropcap.
- `draw(canvas: RID, pos: Vector2, color: Color = Color(1, 1, 1, 1), dc_color: Color = Color(1, 1, 1, 1), oversampling: float = 0.0) -> void` *const* — Draw all lines of the text and drop cap into a canvas item at a given position, with `color`.
- `draw_dropcap(canvas: RID, pos: Vector2, color: Color = Color(1, 1, 1, 1), oversampling: float = 0.0) -> void` *const* — Draw drop cap into a canvas item at a given position, with `color`.
- `draw_dropcap_outline(canvas: RID, pos: Vector2, outline_size: int = 1, color: Color = Color(1, 1, 1, 1), oversampling: float = 0.0) -> void` *const* — Draw drop cap outline into a canvas item at a given position, with `color`.
- `draw_line(canvas: RID, pos: Vector2, line: int, color: Color = Color(1, 1, 1, 1), oversampling: float = 0.0) -> void` *const* — Draw single line of text into a canvas item at a given position, with `color`.
- `draw_line_outline(canvas: RID, pos: Vector2, line: int, outline_size: int = 1, color: Color = Color(1, 1, 1, 1), oversampling: float = 0.0) -> void` *const* — Draw outline of the single line of text into a canvas item at a given position, with `color`.
- `draw_outline(canvas: RID, pos: Vector2, outline_size: int = 1, color: Color = Color(1, 1, 1, 1), dc_color: Color = Color(1, 1, 1, 1), oversampling: float = 0.0) -> void` *const* — Draw outlines of all lines of the text and drop cap into a canvas item at a given position, with `color`.
- `duplicate() -> TextParagraph` *const* — Duplicates this TextParagraph.
- `get_dropcap_lines() -> int` *const* — Returns number of lines used by dropcap.
- `get_dropcap_rid() -> RID` *const* — Returns drop cap text buffer RID.
- `get_dropcap_size() -> Vector2` *const* — Returns drop cap bounding box size.
- `get_inferred_direction() -> int[TextServer.Direction]` *const* — Returns the text writing direction inferred by the BiDi algorithm.
- `get_line_ascent(line: int) -> float` *const* — Returns the text line ascent (number of pixels above the baseline for horizontal layout or to the left of baseline for vertical).
- `get_line_count() -> int` *const* — Returns number of lines in the paragraph.
- `get_line_descent(line: int) -> float` *const* — Returns the text line descent (number of pixels below the baseline for horizontal layout or to the right of baseline for vertical).
- `get_line_object_rect(line: int, key: Variant) -> Rect2` *const* — Returns bounding rectangle of the inline object.
- `get_line_objects(line: int) -> Array` *const* — Returns array of inline objects in the line.
- `get_line_range(line: int) -> Vector2i` *const* — Returns character range of the line.
- `get_line_rid(line: int) -> RID` *const* — Returns TextServer line buffer RID.
- `get_line_size(line: int) -> Vector2` *const* — Returns size of the bounding box of the line of text.
- `get_line_underline_position(line: int) -> float` *const* — Returns pixel offset of the underline below the baseline.
- `get_line_underline_thickness(line: int) -> float` *const* — Returns thickness of the underline.
- `get_line_width(line: int) -> float` *const* — Returns width (for horizontal layout) or height (for vertical) of the line of text.
- `get_non_wrapped_size() -> Vector2` *const* — Returns the size of the bounding box of the paragraph, without line breaks.
- `get_range() -> Vector2i` *const* — Returns the character range of the paragraph.
- `get_rid() -> RID` *const* — Returns TextServer full string buffer RID.
- `get_size() -> Vector2` *const* — Returns the size of the bounding box of the paragraph.
- `has_object(key: Variant) -> bool` *const* — Returns `true` if an object with `key` is embedded in this shaped text buffer.
- `hit_test(coords: Vector2) -> int` *const* — Returns caret character offset at the specified coordinates.
- `resize_object(key: Variant, size: Vector2, inline_align: InlineAlignment = 5, baseline: float = 0.0) -> bool` — Sets new size and alignment of embedded object.
- `set_bidi_override(override: Array) -> void` — Overrides BiDi for the structured text.
- `set_dropcap(text: String, font: Font, font_size: int, dropcap_margins: Rect2 = Rect2(0, 0, 0, 0), language: String = "") -> bool` — Sets drop cap, overrides previously set drop cap.
- `tab_align(tab_stops: PackedFloat32Array) -> void` — Aligns paragraph to the given tab-stops.
