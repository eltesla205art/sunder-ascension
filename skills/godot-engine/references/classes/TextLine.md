# TextLine

**Inherits:** RefCounted

Holds a line of text.

Abstraction over TextServer for handling a single line of text.

## Properties

- `alignment: HorizontalAlignment` = `0` — Sets text alignment within the line as if the line was horizontal.
- `direction: TextServer.Direction` = `0` — Text writing direction.
- `ellipsis_char: String` = `"…"` — Ellipsis character used for text clipping.
- `flags: TextServer.JustificationFlag` = `3` — Line alignment rules.
- `orientation: TextServer.Orientation` = `0` — Text orientation.
- `preserve_control: bool` = `false` — If set to `true` text will display control characters.
- `preserve_invalid: bool` = `true` — If set to `true` text will display invalid characters.
- `text_overrun_behavior: TextServer.OverrunBehavior` = `3` — The clipping behavior when the text exceeds the text line's set width.
- `width: float` = `-1.0` — Text line width.

## Methods

- `add_object(key: Variant, size: Vector2, inline_align: InlineAlignment = 5, length: int = 1, baseline: float = 0.0) -> bool` — Adds inline object to the text buffer, `key` must be unique.
- `add_string(text: String, font: Font, font_size: int, language: String = "", meta: Variant = null) -> bool` — Adds text span and font to draw it.
- `clear() -> void` — Clears text line (removes text and inline objects).
- `draw(canvas: RID, pos: Vector2, color: Color = Color(1, 1, 1, 1), oversampling: float = 0.0) -> void` *const* — Draw text into a canvas item at a given position, with `color`.
- `draw_outline(canvas: RID, pos: Vector2, outline_size: int = 1, color: Color = Color(1, 1, 1, 1), oversampling: float = 0.0) -> void` *const* — Draw text into a canvas item at a given position, with `color`.
- `duplicate() -> TextLine` *const* — Duplicates this TextLine.
- `get_inferred_direction() -> int[TextServer.Direction]` *const* — Returns the text writing direction inferred by the BiDi algorithm.
- `get_line_ascent() -> float` *const* — Returns the text ascent (number of pixels above the baseline for horizontal layout or to the left of baseline for vertical).
- `get_line_descent() -> float` *const* — Returns the text descent (number of pixels below the baseline for horizontal layout or to the right of baseline for vertical).
- `get_line_underline_position() -> float` *const* — Returns pixel offset of the underline below the baseline.
- `get_line_underline_thickness() -> float` *const* — Returns thickness of the underline.
- `get_line_width() -> float` *const* — Returns width (for horizontal layout) or height (for vertical) of the text.
- `get_object_rect(key: Variant) -> Rect2` *const* — Returns bounding rectangle of the inline object.
- `get_objects() -> Array` *const* — Returns array of inline objects.
- `get_rid() -> RID` *const* — Returns TextServer buffer RID.
- `get_size() -> Vector2` *const* — Returns size of the bounding box of the text.
- `has_object(key: Variant) -> bool` *const* — Returns `true` if an object with `key` is embedded in this line.
- `hit_test(coords: float) -> int` *const* — Returns caret character offset at the specified pixel offset at the baseline.
- `resize_object(key: Variant, size: Vector2, inline_align: InlineAlignment = 5, baseline: float = 0.0) -> bool` — Sets new size and alignment of embedded object.
- `set_bidi_override(override: Array) -> void` — Overrides BiDi for the structured text.
- `tab_align(tab_stops: PackedFloat32Array) -> void` — Aligns text to the given tab-stops.
