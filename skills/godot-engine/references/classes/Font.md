# Font

**Inherits:** Resource

Abstract base class for fonts and font variations.

Abstract base class for different font types. It has methods for drawing text and font character introspection.

## Properties

- `fallbacks: Font[]` = `[]` — Array of fallback Fonts to use as a substitute if a glyph is not found in this current Font.

## Methods

- `draw_char(canvas_item: RID, pos: Vector2, char: int, font_size: int, modulate: Color = Color(1, 1, 1, 1), oversampling: float = 0.0) -> float` *const* — Draw a single Unicode character `char` into a canvas item using the font, at a given position, with `modulate` color.
- `draw_char_outline(canvas_item: RID, pos: Vector2, char: int, font_size: int, size: int = -1, modulate: Color = Color(1, 1, 1, 1), oversampling: float = 0.0) -> float` *const* — Draw a single Unicode character `char` outline into a canvas item using the font, at a given position, with `modulate` color and `size` outline size.
- `draw_multiline_string(canvas_item: RID, pos: Vector2, text: String, alignment: HorizontalAlignment = 0, width: float = -1, font_size: int = 16, max_lines: int = -1, modulate: Color = Color(1, 1, 1, 1), brk_flags: TextServer.LineBreakFlag = 3, justification_flags: TextServer.JustificationFlag = 3, direction: TextServer.Direction = 0, orientation: TextServer.Orientation = 0, oversampling: float = 0.0) -> void` *const* — Breaks `text` into lines using rules specified by `brk_flags` and draws it into a canvas item using the font, at a given position, with `modulate` color, optionally clipping the width and aligning horizontally.
- `draw_multiline_string_outline(canvas_item: RID, pos: Vector2, text: String, alignment: HorizontalAlignment = 0, width: float = -1, font_size: int = 16, max_lines: int = -1, size: int = 1, modulate: Color = Color(1, 1, 1, 1), brk_flags: TextServer.LineBreakFlag = 3, justification_flags: TextServer.JustificationFlag = 3, direction: TextServer.Direction = 0, orientation: TextServer.Orientation = 0, oversampling: float = 0.0) -> void` *const* — Breaks `text` to the lines using rules specified by `brk_flags` and draws text outline into a canvas item using the font, at a given position, with `modulate` color and `size` outline size, optionally clipping the width and aligning horizontally.
- `draw_string(canvas_item: RID, pos: Vector2, text: String, alignment: HorizontalAlignment = 0, width: float = -1, font_size: int = 16, modulate: Color = Color(1, 1, 1, 1), justification_flags: TextServer.JustificationFlag = 3, direction: TextServer.Direction = 0, orientation: TextServer.Orientation = 0, oversampling: float = 0.0) -> void` *const* — Draw `text` into a canvas item using the font, at a given position, with `modulate` color, optionally clipping the width and aligning horizontally.
- `draw_string_outline(canvas_item: RID, pos: Vector2, text: String, alignment: HorizontalAlignment = 0, width: float = -1, font_size: int = 16, size: int = 1, modulate: Color = Color(1, 1, 1, 1), justification_flags: TextServer.JustificationFlag = 3, direction: TextServer.Direction = 0, orientation: TextServer.Orientation = 0, oversampling: float = 0.0) -> void` *const* — Draw `text` outline into a canvas item using the font, at a given position, with `modulate` color and `size` outline size, optionally clipping the width and aligning horizontally.
- `find_variation(variation_coordinates: Dictionary, face_index: int = 0, strength: float = 0.0, transform: Transform2D = Transform2D(1, 0, 0, 1, 0, 0), spacing_top: int = 0, spacing_bottom: int = 0, spacing_space: int = 0, spacing_glyph: int = 0, baseline_offset: float = 0.0, palette_index: int = 0, custom_colors: PackedColorArray = PackedColorArray()) -> RID` *const* — Returns TextServer RID of the font cache for specific variation.
- `get_ascent(font_size: int = 16) -> float` *const* — Returns the maximum font ascent (number of pixels above the baseline) of this font and all fallback fonts.
- `get_char_size(char: int, font_size: int) -> Vector2` *const* — Returns the size of a character.
- `get_descent(font_size: int = 16) -> float` *const* — Returns the maximum font descent (number of pixels below the baseline) of this font and all fallback fonts.
- `get_face_count() -> int` *const* — Returns number of faces in the TrueType / OpenType collection.
- `get_font_name() -> String` *const* — Returns font family name.
- `get_font_stretch() -> int` *const* — Returns font stretch amount, compared to a normal width.
- `get_font_style() -> int[TextServer.FontStyle]` *const* — Returns font style flags.
- `get_font_style_name() -> String` *const* — Returns font style name.
- `get_font_weight() -> int` *const* — Returns weight (boldness) of the font.
- `get_height(font_size: int = 16) -> float` *const* — Returns the total average font height (ascent plus descent) in pixels.
- `get_multiline_string_size(text: String, alignment: HorizontalAlignment = 0, width: float = -1, font_size: int = 16, max_lines: int = -1, brk_flags: TextServer.LineBreakFlag = 3, justification_flags: TextServer.JustificationFlag = 3, direction: TextServer.Direction = 0, orientation: TextServer.Orientation = 0) -> Vector2` *const* — Returns the size of a bounding box of a string broken into the lines, taking kerning and advance into account.
- `get_opentype_features() -> Dictionary` *const* — Returns a set of OpenType feature tags.
- `get_ot_name_strings() -> Dictionary` *const* — Returns Dictionary with OpenType font name strings (localized font names, version, description, license information, sample text, etc.).
- `get_palette_colors(index: int) -> PackedColorArray` *const* — Returns the array in the predefined color palette at `index`.
- `get_palette_count() -> int` *const* — Returns the number of predefined color palettes.
- `get_palette_name(index: int) -> String` *const* — Returns the name of the predefined color palette at `index`.
- `get_rids() -> RID[]` *const* — Returns Array of valid Font RIDs, which can be passed to the TextServer methods.
- `get_spacing(spacing: TextServer.SpacingType) -> int` *const* — Returns the amount of spacing for the given `spacing` type.
- `get_string_size(text: String, alignment: HorizontalAlignment = 0, width: float = -1, font_size: int = 16, justification_flags: TextServer.JustificationFlag = 3, direction: TextServer.Direction = 0, orientation: TextServer.Orientation = 0) -> Vector2` *const* — Returns the size of a bounding box of a single-line string, taking kerning, advance and subpixel positioning into account.
- `get_supported_chars() -> String` *const* — Returns a string containing all the characters available in the font.
- `get_supported_feature_list() -> Dictionary` *const* — Returns list of OpenType features supported by font.
- `get_supported_variation_list() -> Dictionary` *const* — Returns list of supported variation coordinates, each coordinate is returned as `tag: Vector3i(min_value,max_value,default_value)`.
- `get_underline_position(font_size: int = 16) -> float` *const* — Returns average pixel offset of the underline below the baseline.
- `get_underline_thickness(font_size: int = 16) -> float` *const* — Returns average thickness of the underline.
- `has_char(char: int) -> bool` *const* — Returns `true` if a Unicode `char` is available in the font.
- `is_language_supported(language: String) -> bool` *const* — Returns `true` if the font supports the given language (as a ISO 639 code).
- `is_script_supported(script: String) -> bool` *const* — Returns `true` if the font supports the given script (as a ISO 15924 code).
- `set_cache_capacity(single_line: int, multi_line: int) -> void` — Sets LRU cache capacity for `draw_*` methods.
