# TextServer

**Inherits:** RefCounted

A server interface for font management and text rendering.

TextServer is the API backend for managing fonts and rendering text. Note: This is a low-level API, consider using TextLine, TextParagraph, and Font classes instead. This is an abstract class, so to get the currently active TextServer instance, use the following code:

## Methods

- `create_font() -> RID` — Creates a new, empty font cache entry resource.
- `create_font_linked_variation(font_rid: RID) -> RID` — Creates a new variation existing font which is reusing the same glyph cache and font data.
- `create_shaped_text(direction: TextServer.Direction = 0, orientation: TextServer.Orientation = 0) -> RID` — Creates a new buffer for complex text layout, with the given `direction` and `orientation`.
- `draw_hex_code_box(canvas: RID, size: int, pos: Vector2, index: int, color: Color) -> void` *const* — Draws box displaying character hexadecimal code.
- `font_clear_glyphs(font_rid: RID, size: Vector2i) -> void` — Removes all rendered glyph information from the cache entry.
- `font_clear_kerning_map(font_rid: RID, size: int) -> void` — Removes all kerning overrides.
- `font_clear_size_cache(font_rid: RID) -> void` — Removes all font sizes from the cache entry.
- `font_clear_system_fallback_cache() -> void` — Frees all automatically loaded system fonts.
- `font_clear_textures(font_rid: RID, size: Vector2i) -> void` — Removes all textures from font cache entry.
- `font_draw_glyph(font_rid: RID, canvas: RID, size: int, pos: Vector2, index: int, color: Color = Color(1, 1, 1, 1), oversampling: float = 0.0) -> void` *const* — Draws single glyph into a canvas item at the position, using `font_rid` at the size `size`.
- `font_draw_glyph_outline(font_rid: RID, canvas: RID, size: int, outline_size: int, pos: Vector2, index: int, color: Color = Color(1, 1, 1, 1), oversampling: float = 0.0) -> void` *const* — Draws single glyph outline of size `outline_size` into a canvas item at the position, using `font_rid` at the size `size`.
- `font_get_antialiasing(font_rid: RID) -> int[TextServer.FontAntialiasing]` *const* — Returns font anti-aliasing mode.
- `font_get_ascent(font_rid: RID, size: int) -> float` *const* — Returns the font ascent (number of pixels above the baseline).
- `font_get_baseline_offset(font_rid: RID) -> float` *const* — Returns extra baseline offset (as a fraction of font height).
- `font_get_char_from_glyph_index(font_rid: RID, size: int, glyph_index: int) -> int` *const* — Returns character code associated with `glyph_index`, or `0` if `glyph_index` is invalid.
- `font_get_descent(font_rid: RID, size: int) -> float` *const* — Returns the font descent (number of pixels below the baseline).
- `font_get_disable_embedded_bitmaps(font_rid: RID) -> bool` *const* — Returns whether the font's embedded bitmap loading is disabled.
- `font_get_embolden(font_rid: RID) -> float` *const* — Returns font embolden strength.
- `font_get_face_count(font_rid: RID) -> int` *const* — Returns number of faces in the TrueType / OpenType collection.
- `font_get_face_index(font_rid: RID) -> int` *const* — Returns an active face index in the TrueType / OpenType collection.
- `font_get_fixed_size(font_rid: RID) -> int` *const* — Returns bitmap font fixed size.
- `font_get_fixed_size_scale_mode(font_rid: RID) -> int[TextServer.FixedSizeScaleMode]` *const* — Returns bitmap font scaling mode.
- `font_get_generate_mipmaps(font_rid: RID) -> bool` *const* — Returns `true` if font texture mipmap generation is enabled.
- `font_get_global_oversampling() -> float` *const* *(deprecated)* — This method does nothing and always returns `1.0`.
- `font_get_glyph_advance(font_rid: RID, size: int, glyph: int) -> Vector2` *const* — Returns glyph advance (offset of the next glyph).
- `font_get_glyph_contours(font: RID, size: int, index: int) -> Dictionary` *const* — Returns outline contours of the glyph as a Dictionary with the following contents: `points` - PackedVector3Array, containing outline points.
- `font_get_glyph_index(font_rid: RID, size: int, char: int, variation_selector: int) -> int` *const* — Returns the glyph index of a `char`, optionally modified by the `variation_selector`.
- `font_get_glyph_list(font_rid: RID, size: Vector2i) -> PackedInt32Array` *const* — Returns list of rendered glyphs in the cache entry.
- `font_get_glyph_offset(font_rid: RID, size: Vector2i, glyph: int) -> Vector2` *const* — Returns glyph offset from the baseline.
- `font_get_glyph_size(font_rid: RID, size: Vector2i, glyph: int) -> Vector2` *const* — Returns size of the glyph.
- `font_get_glyph_texture_idx(font_rid: RID, size: Vector2i, glyph: int) -> int` *const* — Returns index of the cache texture containing the glyph.
- `font_get_glyph_texture_rid(font_rid: RID, size: Vector2i, glyph: int) -> RID` *const* — Returns resource ID of the cache texture containing the glyph.
- `font_get_glyph_texture_size(font_rid: RID, size: Vector2i, glyph: int) -> Vector2` *const* — Returns size of the cache texture containing the glyph.
- `font_get_glyph_uv_rect(font_rid: RID, size: Vector2i, glyph: int) -> Rect2` *const* — Returns rectangle in the cache texture containing the glyph.
- `font_get_hinting(font_rid: RID) -> int[TextServer.Hinting]` *const* — Returns the font hinting mode.
- `font_get_keep_rounding_remainders(font_rid: RID) -> bool` *const* — Returns glyph position rounding behavior.
- `font_get_kerning(font_rid: RID, size: int, glyph_pair: Vector2i) -> Vector2` *const* — Returns kerning for the pair of glyphs.
- `font_get_kerning_list(font_rid: RID, size: int) -> Vector2i[]` *const* — Returns list of the kerning overrides.
- `font_get_language_support_override(font_rid: RID, language: String) -> bool` — Returns `true` if support override is enabled for the `language`.
- `font_get_language_support_overrides(font_rid: RID) -> PackedStringArray` — Returns list of language support overrides.
- `font_get_msdf_pixel_range(font_rid: RID) -> int` *const* — Returns the width of the range around the shape between the minimum and maximum representable signed distance.
- `font_get_msdf_size(font_rid: RID) -> int` *const* — Returns source font size used to generate MSDF textures.
- `font_get_name(font_rid: RID) -> String` *const* — Returns font family name.
- `font_get_opentype_feature_overrides(font_rid: RID) -> Dictionary` *const* — Returns font OpenType feature set override.
- `font_get_ot_name_strings(font_rid: RID) -> Dictionary` *const* — Returns Dictionary with OpenType font name strings (localized font names, version, description, license information, sample text, etc.).
- `font_get_oversampling(font_rid: RID) -> float` *const* — Returns oversampling factor override.
- `font_get_palette_colors(font_rid: RID, index: int) -> PackedColorArray` *const* — Returns the array in the predefined color palette at `index`.
- `font_get_palette_count(font_rid: RID) -> int` *const* — Returns the number of predefined color palettes.
- `font_get_palette_custom_colors(font_rid: RID) -> PackedColorArray` *const* — Returns array of custom colors to override predefined palette.
- `font_get_palette_name(font_rid: RID, index: int) -> String` *const* — Returns the name of the predefined color palette at `index`.
- `font_get_scale(font_rid: RID, size: int) -> float` *const* — Returns scaling factor of the color bitmap font.
- `font_get_script_support_override(font_rid: RID, script: String) -> bool` — Returns `true` if support override is enabled for the `script`.
- `font_get_script_support_overrides(font_rid: RID) -> PackedStringArray` — Returns list of script support overrides.
- `font_get_size_cache_info(font_rid: RID) -> Dictionary[]` *const* — Returns font cache information, each entry contains the following fields: `Vector2i size_px` - font size in pixels, `float viewport_oversampling` - viewport oversampling factor, `int glyphs` - number of rendered glyphs, `int textures` - number of used textures, `int textures_size` - size of texture data in bytes.
- `font_get_size_cache_list(font_rid: RID) -> Vector2i[]` *const* — Returns list of the font sizes in the cache.
- `font_get_spacing(font_rid: RID, spacing: TextServer.SpacingType) -> int` *const* — Returns the spacing for `spacing` in pixels (not relative to the font size).
- `font_get_stretch(font_rid: RID) -> int` *const* — Returns font stretch amount, compared to a normal width.
- `font_get_style(font_rid: RID) -> int[TextServer.FontStyle]` *const* — Returns font style flags.
- `font_get_style_name(font_rid: RID) -> String` *const* — Returns font style name.
- `font_get_subpixel_positioning(font_rid: RID) -> int[TextServer.SubpixelPositioning]` *const* — Returns font subpixel glyph positioning mode.
- `font_get_supported_chars(font_rid: RID) -> String` *const* — Returns a string containing all the characters available in the font.
- `font_get_supported_glyphs(font_rid: RID) -> PackedInt32Array` *const* — Returns an array containing all glyph indices in the font.
- `font_get_texture_count(font_rid: RID, size: Vector2i) -> int` *const* — Returns number of textures used by font cache entry.
- `font_get_texture_image(font_rid: RID, size: Vector2i, texture_index: int) -> Image` *const* — Returns font cache texture image data.
- `font_get_texture_offsets(font_rid: RID, size: Vector2i, texture_index: int) -> PackedInt32Array` *const* — Returns array containing glyph packing data.
- `font_get_transform(font_rid: RID) -> Transform2D` *const* — Returns 2D transform applied to the font outlines.
- `font_get_underline_position(font_rid: RID, size: int) -> float` *const* — Returns pixel offset of the underline below the baseline.
- `font_get_underline_thickness(font_rid: RID, size: int) -> float` *const* — Returns thickness of the underline in pixels.
- `font_get_used_palette(font_rid: RID) -> int` *const* — Returns used palette index.
- `font_get_variation_coordinates(font_rid: RID) -> Dictionary` *const* — Returns variation coordinates for the specified font cache entry.
- `font_get_weight(font_rid: RID) -> int` *const* — Returns weight (boldness) of the font.
- `font_has_char(font_rid: RID, char: int) -> bool` *const* — Returns `true` if a Unicode `char` is available in the font.
- `font_is_allow_system_fallback(font_rid: RID) -> bool` *const* — Returns `true` if system fonts can be automatically used as fallbacks.
- `font_is_force_autohinter(font_rid: RID) -> bool` *const* — Returns `true` if auto-hinting is supported and preferred over font built-in hinting.
- `font_is_language_supported(font_rid: RID, language: String) -> bool` *const* — Returns `true` if the font supports the given language (as a ISO 639 code).
- `font_is_modulate_color_glyphs(font_rid: RID) -> bool` *const* — Returns `true` if color modulation is applied when drawing the font's colored glyphs.
- `font_is_multichannel_signed_distance_field(font_rid: RID) -> bool` *const* — Returns `true` if glyphs of all sizes are rendered using single multichannel signed distance field generated from the dynamic font vector data.
- `font_is_script_supported(font_rid: RID, script: String) -> bool` *const* — Returns `true` if the font supports the given script (as a ISO 15924 code).
- `font_remove_glyph(font_rid: RID, size: Vector2i, glyph: int) -> void` — Removes specified rendered glyph information from the cache entry.
- `font_remove_kerning(font_rid: RID, size: int, glyph_pair: Vector2i) -> void` — Removes kerning override for the pair of glyphs.
- `font_remove_language_support_override(font_rid: RID, language: String) -> void` — Remove language support override.
- `font_remove_script_support_override(font_rid: RID, script: String) -> void` — Removes script support override.
- `font_remove_size_cache(font_rid: RID, size: Vector2i) -> void` — Removes specified font size from the cache entry.
- `font_remove_texture(font_rid: RID, size: Vector2i, texture_index: int) -> void` — Removes specified texture from the cache entry.
- `font_render_glyph(font_rid: RID, size: Vector2i, index: int) -> void` — Renders specified glyph to the font cache texture.
- `font_render_range(font_rid: RID, size: Vector2i, start: int, end: int) -> void` — Renders the range of characters to the font cache texture.
- `font_set_allow_system_fallback(font_rid: RID, allow_system_fallback: bool) -> void` — If set to `true`, system fonts can be automatically used as fallbacks.
- `font_set_antialiasing(font_rid: RID, antialiasing: TextServer.FontAntialiasing) -> void` — Sets font anti-aliasing mode.
- `font_set_ascent(font_rid: RID, size: int, ascent: float) -> void` — Sets the font ascent (number of pixels above the baseline).
- `font_set_baseline_offset(font_rid: RID, baseline_offset: float) -> void` — Sets extra baseline offset (as a fraction of font height).
- `font_set_data(font_rid: RID, data: PackedByteArray) -> void` — Sets font source data, e.g contents of the dynamic font source file.
- `font_set_descent(font_rid: RID, size: int, descent: float) -> void` — Sets the font descent (number of pixels below the baseline).
- `font_set_disable_embedded_bitmaps(font_rid: RID, disable_embedded_bitmaps: bool) -> void` — If set to `true`, embedded font bitmap loading is disabled (bitmap-only and color fonts ignore this property).
- `font_set_embolden(font_rid: RID, strength: float) -> void` — Sets font embolden strength.
- `font_set_face_index(font_rid: RID, face_index: int) -> void` — Sets an active face index in the TrueType / OpenType collection.
- `font_set_fixed_size(font_rid: RID, fixed_size: int) -> void` — Sets bitmap font fixed size.
- `font_set_fixed_size_scale_mode(font_rid: RID, fixed_size_scale_mode: TextServer.FixedSizeScaleMode) -> void` — Sets bitmap font scaling mode.
- `font_set_force_autohinter(font_rid: RID, force_autohinter: bool) -> void` — If set to `true` auto-hinting is preferred over font built-in hinting.
- `font_set_generate_mipmaps(font_rid: RID, generate_mipmaps: bool) -> void` — If set to `true` font texture mipmap generation is enabled.
- `font_set_global_oversampling(oversampling: float) -> void` *(deprecated)* — This method does nothing.
- `font_set_glyph_advance(font_rid: RID, size: int, glyph: int, advance: Vector2) -> void` — Sets glyph advance (offset of the next glyph).
- `font_set_glyph_offset(font_rid: RID, size: Vector2i, glyph: int, offset: Vector2) -> void` — Sets glyph offset from the baseline.
- `font_set_glyph_size(font_rid: RID, size: Vector2i, glyph: int, gl_size: Vector2) -> void` — Sets size of the glyph.
- `font_set_glyph_texture_idx(font_rid: RID, size: Vector2i, glyph: int, texture_idx: int) -> void` — Sets index of the cache texture containing the glyph.
- `font_set_glyph_uv_rect(font_rid: RID, size: Vector2i, glyph: int, uv_rect: Rect2) -> void` — Sets rectangle in the cache texture containing the glyph.
- `font_set_hinting(font_rid: RID, hinting: TextServer.Hinting) -> void` — Sets font hinting mode.
- `font_set_keep_rounding_remainders(font_rid: RID, keep_rounding_remainders: bool) -> void` — Sets glyph position rounding behavior.
- `font_set_kerning(font_rid: RID, size: int, glyph_pair: Vector2i, kerning: Vector2) -> void` — Sets kerning for the pair of glyphs.
- `font_set_language_support_override(font_rid: RID, language: String, supported: bool) -> void` — Adds override for `font_is_language_supported`.
- `font_set_modulate_color_glyphs(font_rid: RID, modulate: bool) -> void` — If set to `true`, color modulation is applied when drawing colored glyphs, otherwise it's applied to the monochrome glyphs only.
- `font_set_msdf_pixel_range(font_rid: RID, msdf_pixel_range: int) -> void` — Sets the width of the range around the shape between the minimum and maximum representable signed distance.
- `font_set_msdf_size(font_rid: RID, msdf_size: int) -> void` — Sets source font size used to generate MSDF textures.
- `font_set_multichannel_signed_distance_field(font_rid: RID, msdf: bool) -> void` — If set to `true`, glyphs of all sizes are rendered using single multichannel signed distance field generated from the dynamic font vector data.
- `font_set_name(font_rid: RID, name: String) -> void` — Sets the font family name.
- `font_set_opentype_feature_overrides(font_rid: RID, overrides: Dictionary) -> void` — Sets font OpenType feature set override.
- `font_set_oversampling(font_rid: RID, oversampling: float) -> void` — If set to a positive value, overrides the oversampling factor of the viewport this font is used in.
- `font_set_palette_custom_colors(font_rid: RID, colors: PackedColorArray) -> void` — Sets array of custom colors to override predefined palette.
- `font_set_scale(font_rid: RID, size: int, scale: float) -> void` — Sets scaling factor of the color bitmap font.
- `font_set_script_support_override(font_rid: RID, script: String, supported: bool) -> void` — Adds override for `font_is_script_supported`.
- `font_set_spacing(font_rid: RID, spacing: TextServer.SpacingType, value: int) -> void` — Sets the spacing for `spacing` to `value` in pixels (not relative to the font size).
- `font_set_stretch(font_rid: RID, weight: int) -> void` — Sets font stretch amount, compared to a normal width.
- `font_set_style(font_rid: RID, style: TextServer.FontStyle) -> void` — Sets the font style flags.
- `font_set_style_name(font_rid: RID, name: String) -> void` — Sets the font style name.
- `font_set_subpixel_positioning(font_rid: RID, subpixel_positioning: TextServer.SubpixelPositioning) -> void` — Sets font subpixel glyph positioning mode.
- `font_set_texture_image(font_rid: RID, size: Vector2i, texture_index: int, image: Image) -> void` — Sets font cache texture image data.
- `font_set_texture_offsets(font_rid: RID, size: Vector2i, texture_index: int, offset: PackedInt32Array) -> void` — Sets array containing glyph packing data.
- `font_set_transform(font_rid: RID, transform: Transform2D) -> void` — Sets 2D transform, applied to the font outlines, can be used for slanting, flipping, and rotating glyphs.
- `font_set_underline_position(font_rid: RID, size: int, underline_position: float) -> void` — Sets pixel offset of the underline below the baseline.
- `font_set_underline_thickness(font_rid: RID, size: int, underline_thickness: float) -> void` — Sets thickness of the underline in pixels.
- `font_set_used_palette(font_rid: RID, index: int) -> void` — Sets used palette index.
- `font_set_variation_coordinates(font_rid: RID, variation_coordinates: Dictionary) -> void` — Sets variation coordinates for the specified font cache entry.
- `font_set_weight(font_rid: RID, weight: int) -> void` — Sets weight (boldness) of the font.
- `font_supported_feature_list(font_rid: RID) -> Dictionary` *const* — Returns the dictionary of the supported OpenType features.
- `font_supported_variation_list(font_rid: RID) -> Dictionary` *const* — Returns the dictionary of the supported OpenType variation coordinates.
- `format_number(number: String, language: String = "") -> String` *const* *(deprecated)* — Converts a number from Western Arabic (0..9) to the numeral system used in the given `language`.
- `free_rid(rid: RID) -> void` — Frees an object created by this TextServer.
- `get_features() -> int` *const* — Returns text server features, see `Feature`.
- `get_hex_code_box_size(size: int, index: int) -> Vector2` *const* — Returns size of the replacement character (box with character hexadecimal code that is drawn in place of invalid characters).
- `get_name() -> String` *const* — Returns the name of the server interface.
- `get_short_name() -> String` *const* — Returns the short name of the server interface.
- `get_support_data() -> PackedByteArray` *const* — Returns default TextServer database (e.g.
- `get_support_data_filename() -> String` *const* — Returns default TextServer database (e.g.
- `get_support_data_info() -> String` *const* — Returns TextServer database (e.g.
- `has(rid: RID) -> bool` — Returns `true` if `rid` is valid resource owned by this text server.
- `has_feature(feature: TextServer.Feature) -> bool` *const* — Returns `true` if the server supports a feature.
- `is_confusable(string: String, dict: PackedStringArray) -> int` *const* — Returns index of the first string in `dict` which is visually confusable with the `string`, or `-1` if none is found.
- `is_locale_right_to_left(locale: String) -> bool` *const* — Returns `true` if locale is right-to-left.
- `is_locale_using_support_data(locale: String) -> bool` *const* — Returns `true` if the locale requires text server support data for line/word breaking.
- `is_valid_identifier(string: String) -> bool` *const* — Returns `true` if `string` is a valid identifier.
- `is_valid_letter(unicode: int) -> bool` *const* — Returns `true` if the given code point is a valid letter, i.e. it belongs to the Unicode category "L".
- `load_support_data(filename: String) -> bool` — Loads optional TextServer database (e.g.
- `name_to_tag(name: String) -> int` *const* — Converts the given readable name of a feature, variation, script, or language to an OpenType tag.
- `parse_number(number: String, language: String = "") -> String` *const* *(deprecated)* — Converts `number` from the numeral system used in the given `language` to Western Arabic (0..9).
- `parse_structured_text(parser_type: TextServer.StructuredTextParser, args: Array, text: String) -> Vector3i[]` *const* — Default implementation of the BiDi algorithm override function.
- `percent_sign(language: String = "") -> String` *const* *(deprecated)* — Returns the percent sign used in the given `language`.
- `save_support_data(filename: String) -> bool` *const* — Saves optional TextServer database (e.g.
- `shaped_get_run_count(shaped: RID) -> int` *const* — Returns the number of uniform text runs in the buffer.
- `shaped_get_run_direction(shaped: RID, index: int) -> int[TextServer.Direction]` *const* — Returns the direction of the `index` text run (in visual order).
- `shaped_get_run_font_rid(shaped: RID, index: int) -> RID` *const* — Returns the font RID of the `index` text run (in visual order).
- `shaped_get_run_font_size(shaped: RID, index: int) -> int` *const* — Returns the font size of the `index` text run (in visual order).
- `shaped_get_run_glyph_range(shaped: RID, index: int) -> Vector2i` *const* — Returns the glyph range of the `index` text run (in visual order).
- `shaped_get_run_language(shaped: RID, index: int) -> String` *const* — Returns the language of the `index` text run (in visual order).
- `shaped_get_run_object(shaped: RID, index: int) -> Variant` *const* — Returns the embedded object of the `index` text run (in visual order).
- `shaped_get_run_range(shaped: RID, index: int) -> Vector2i` *const* — Returns the source text range of the `index` text run (in visual order).
- `shaped_get_run_text(shaped: RID, index: int) -> String` *const* — Returns the source text of the `index` text run (in visual order).
- `shaped_get_span_count(shaped: RID) -> int` *const* — Returns number of text spans added using `shaped_text_add_string` or `shaped_text_add_object`.
- `shaped_get_span_embedded_object(shaped: RID, index: int) -> Variant` *const* — Returns text embedded object key.
- `shaped_get_span_meta(shaped: RID, index: int) -> Variant` *const* — Returns text span metadata.
- `shaped_get_span_object(shaped: RID, index: int) -> Variant` *const* — Returns the text span embedded object key.
- `shaped_get_span_text(shaped: RID, index: int) -> String` *const* — Returns the text span source text.
- `shaped_get_text(shaped: RID) -> String` *const* — Returns the text buffer source text, including object replacement characters.
- `shaped_set_span_update_font(shaped: RID, index: int, fonts: RID[], size: int, opentype_features: Dictionary = {}) -> void` — Changes text span font, font size, and OpenType features, without changing the text.
- `shaped_text_add_object(shaped: RID, key: Variant, size: Vector2, inline_align: InlineAlignment = 5, length: int = 1, baseline: float = 0.0) -> bool` — Adds inline object to the text buffer, `key` must be unique.
- `shaped_text_add_string(shaped: RID, text: String, fonts: RID[], size: int, opentype_features: Dictionary = {}, language: String = "", meta: Variant = null) -> bool` — Adds text span and font to draw it to the text buffer.
- `shaped_text_clear(rid: RID) -> void` — Clears text buffer (removes text and inline objects).
- `shaped_text_closest_character_pos(shaped: RID, pos: int) -> int` *const* — Returns composite character position closest to the `pos`.
- `shaped_text_draw(shaped: RID, canvas: RID, pos: Vector2, clip_l: float = -1, clip_r: float = -1, color: Color = Color(1, 1, 1, 1), oversampling: float = 0.0) -> void` *const* — Draw shaped text into a canvas item at a given position, with `color`.
- `shaped_text_draw_outline(shaped: RID, canvas: RID, pos: Vector2, clip_l: float = -1, clip_r: float = -1, outline_size: int = 1, color: Color = Color(1, 1, 1, 1), oversampling: float = 0.0) -> void` *const* — Draw the outline of the shaped text into a canvas item at a given position, with `color`.
- `shaped_text_duplicate(rid: RID) -> RID` — Duplicates shaped text buffer.
- `shaped_text_fit_to_width(shaped: RID, width: float, justification_flags: TextServer.JustificationFlag = 3) -> float` — Adjusts text width to fit to specified width, returns new text width.
- `shaped_text_get_ascent(shaped: RID) -> float` *const* — Returns the text ascent (number of pixels above the baseline for horizontal layout or to the left of baseline for vertical).
- `shaped_text_get_carets(shaped: RID, position: int) -> Dictionary` *const* — Returns shapes of the carets corresponding to the character offset `position` in the text.
- `shaped_text_get_character_breaks(shaped: RID) -> PackedInt32Array` *const* — Returns array of the composite character boundaries.
- `shaped_text_get_custom_ellipsis(shaped: RID) -> int` *const* — Returns ellipsis character used for text clipping.
- `shaped_text_get_custom_punctuation(shaped: RID) -> String` *const* — Returns custom punctuation character list, used for word breaking.
- `shaped_text_get_descent(shaped: RID) -> float` *const* — Returns the text descent (number of pixels below the baseline for horizontal layout or to the right of baseline for vertical).
- `shaped_text_get_direction(shaped: RID) -> int[TextServer.Direction]` *const* — Returns direction of the text.
- `shaped_text_get_dominant_direction_in_range(shaped: RID, start: int, end: int) -> int[TextServer.Direction]` *const* — Returns dominant direction of in the range of text.
- `shaped_text_get_ellipsis_glyph_count(shaped: RID) -> int` *const* — Returns number of glyphs in the ellipsis.
- `shaped_text_get_ellipsis_glyphs(shaped: RID) -> Dictionary[]` *const* — Returns array of the glyphs in the ellipsis.
- `shaped_text_get_ellipsis_pos(shaped: RID) -> int` *const* — Returns position of the ellipsis.
- `shaped_text_get_glyph_count(shaped: RID) -> int` *const* — Returns number of glyphs in the buffer.
- `shaped_text_get_glyphs(shaped: RID) -> Dictionary[]` *const* — Returns an array of glyphs in the visual order.
- `shaped_text_get_grapheme_bounds(shaped: RID, pos: int) -> Vector2` *const* — Returns composite character's bounds as offsets from the start of the line.
- `shaped_text_get_inferred_direction(shaped: RID) -> int[TextServer.Direction]` *const* — Returns direction of the text, inferred by the BiDi algorithm.
- `shaped_text_get_line_breaks(shaped: RID, width: float, start: int = 0, break_flags: TextServer.LineBreakFlag = 3) -> PackedInt32Array` *const* — Breaks text to the lines and returns character ranges for each line.
- `shaped_text_get_line_breaks_adv(shaped: RID, width: PackedFloat32Array, start: int = 0, once: bool = true, break_flags: TextServer.LineBreakFlag = 3) -> PackedInt32Array` *const* — Breaks text to the lines and columns.
- `shaped_text_get_object_glyph(shaped: RID, key: Variant) -> int` *const* — Returns the glyph index of the inline object.
- `shaped_text_get_object_range(shaped: RID, key: Variant) -> Vector2i` *const* — Returns the character range of the inline object.
- `shaped_text_get_object_rect(shaped: RID, key: Variant) -> Rect2` *const* — Returns bounding rectangle of the inline object.
- `shaped_text_get_objects(shaped: RID) -> Array` *const* — Returns array of inline objects.
- `shaped_text_get_orientation(shaped: RID) -> int[TextServer.Orientation]` *const* — Returns text orientation.
- `shaped_text_get_parent(shaped: RID) -> RID` *const* — Returns the parent buffer from which the substring originates.
- `shaped_text_get_preserve_control(shaped: RID) -> bool` *const* — Returns `true` if text buffer is configured to display control characters.
- `shaped_text_get_preserve_invalid(shaped: RID) -> bool` *const* — Returns `true` if text buffer is configured to display hexadecimal codes in place of invalid characters.
- `shaped_text_get_range(shaped: RID) -> Vector2i` *const* — Returns substring buffer character range in the parent buffer.
- `shaped_text_get_selection(shaped: RID, start: int, end: int) -> PackedVector2Array` *const* — Returns selection rectangles for the specified character range.
- `shaped_text_get_size(shaped: RID) -> Vector2` *const* — Returns size of the text.
- `shaped_text_get_spacing(shaped: RID, spacing: TextServer.SpacingType) -> int` *const* — Returns extra spacing added between glyphs or lines in pixels.
- `shaped_text_get_trim_pos(shaped: RID) -> int` *const* — Returns the position of the overrun trim.
- `shaped_text_get_underline_position(shaped: RID) -> float` *const* — Returns pixel offset of the underline below the baseline.
- `shaped_text_get_underline_thickness(shaped: RID) -> float` *const* — Returns thickness of the underline.
- `shaped_text_get_width(shaped: RID) -> float` *const* — Returns width (for horizontal layout) or height (for vertical) of the text.
- `shaped_text_get_word_breaks(shaped: RID, grapheme_flags: TextServer.GraphemeFlag = 264, skip_grapheme_flags: TextServer.GraphemeFlag = 4) -> PackedInt32Array` *const* — Breaks text into words and returns array of character ranges.
- `shaped_text_has_object(shaped: RID, key: Variant) -> bool` *const* — Returns `true` if an object with `key` is embedded in this shaped text buffer.
- `shaped_text_has_visible_chars(shaped: RID) -> bool` *const* — Returns `true` if text buffer contains any visible characters.
- `shaped_text_hit_test_grapheme(shaped: RID, coords: float) -> int` *const* — Returns grapheme index at the specified pixel offset at the baseline, or `-1` if none is found.
- `shaped_text_hit_test_position(shaped: RID, coords: float) -> int` *const* — Returns caret character offset at the specified pixel offset at the baseline.
- `shaped_text_is_ready(shaped: RID) -> bool` *const* — Returns `true` if buffer is successfully shaped.
- `shaped_text_next_character_pos(shaped: RID, pos: int) -> int` *const* — Returns composite character end position closest to the `pos`.
- `shaped_text_next_grapheme_pos(shaped: RID, pos: int) -> int` *const* — Returns grapheme end position closest to the `pos`.
- `shaped_text_overrun_trim_to_width(shaped: RID, width: float = 0, overrun_trim_flags: TextServer.TextOverrunFlag = 0) -> void` — Trims text if it exceeds the given width.
- `shaped_text_prev_character_pos(shaped: RID, pos: int) -> int` *const* — Returns composite character start position closest to the `pos`.
- `shaped_text_prev_grapheme_pos(shaped: RID, pos: int) -> int` *const* — Returns grapheme start position closest to the `pos`.
- `shaped_text_resize_object(shaped: RID, key: Variant, size: Vector2, inline_align: InlineAlignment = 5, baseline: float = 0.0) -> bool` — Sets new size and alignment of embedded object.
- `shaped_text_set_bidi_override(shaped: RID, override: Array) -> void` — Overrides BiDi for the structured text.
- `shaped_text_set_custom_ellipsis(shaped: RID, char: int) -> void` — Sets ellipsis character used for text clipping.
- `shaped_text_set_custom_punctuation(shaped: RID, punct: String) -> void` — Sets custom punctuation character list, used for word breaking.
- `shaped_text_set_direction(shaped: RID, direction: TextServer.Direction = 0) -> void` — Sets desired text direction.
- `shaped_text_set_orientation(shaped: RID, orientation: TextServer.Orientation = 0) -> void` — Sets desired text orientation.
- `shaped_text_set_preserve_control(shaped: RID, enabled: bool) -> void` — If set to `true` text buffer will display control characters.
- `shaped_text_set_preserve_invalid(shaped: RID, enabled: bool) -> void` — If set to `true` text buffer will display invalid characters as hexadecimal codes, otherwise nothing is displayed.
- `shaped_text_set_spacing(shaped: RID, spacing: TextServer.SpacingType, value: int) -> void` — Sets extra spacing added between glyphs or lines in pixels.
- `shaped_text_shape(shaped: RID) -> bool` — Shapes buffer if it's not shaped.
- `shaped_text_sort_logical(shaped: RID) -> Dictionary[]` — Returns text glyphs in the logical order.
- `shaped_text_substr(shaped: RID, start: int, length: int) -> RID` *const* — Returns text buffer for the substring of the text in the `shaped` text buffer (including inline objects).
- `shaped_text_tab_align(shaped: RID, tab_stops: PackedFloat32Array) -> float` — Aligns shaped text to the given tab-stops.
- `spoof_check(string: String) -> bool` *const* — Returns `true` if `string` is likely to be an attempt at confusing the reader.
- `string_get_character_breaks(string: String, language: String = "") -> PackedInt32Array` *const* — Returns array of the composite character boundaries.
- `string_get_word_breaks(string: String, language: String = "", chars_per_line: int = 0) -> PackedInt32Array` *const* — Returns an array of the word break boundaries.
- `string_to_lower(string: String, language: String = "") -> String` *const* — Returns the string converted to `lowercase`.
- `string_to_title(string: String, language: String = "") -> String` *const* — Returns the string converted to `Title Case`.
- `string_to_upper(string: String, language: String = "") -> String` *const* — Returns the string converted to `UPPERCASE`.
- `strip_diacritics(string: String) -> String` *const* — Strips diacritics from the string.
- `tag_to_name(tag: int) -> String` *const* — Converts the given OpenType tag to the readable name of a feature, variation, script, or language.

## Enum FontAntialiasing

- `FONT_ANTIALIASING_NONE = 0` — Font glyphs are rasterized as 1-bit bitmaps.
- `FONT_ANTIALIASING_GRAY = 1` — Font glyphs are rasterized as 8-bit grayscale anti-aliased bitmaps.
- `FONT_ANTIALIASING_LCD = 2` — Font glyphs are rasterized for LCD screens.

## Enum FontLCDSubpixelLayout

- `FONT_LCD_SUBPIXEL_LAYOUT_NONE = 0` — Unknown or unsupported subpixel layout, LCD subpixel antialiasing is disabled.
- `FONT_LCD_SUBPIXEL_LAYOUT_HRGB = 1` — Horizontal RGB subpixel layout.
- `FONT_LCD_SUBPIXEL_LAYOUT_HBGR = 2` — Horizontal BGR subpixel layout.
- `FONT_LCD_SUBPIXEL_LAYOUT_VRGB = 3` — Vertical RGB subpixel layout.
- `FONT_LCD_SUBPIXEL_LAYOUT_VBGR = 4` — Vertical BGR subpixel layout.
- `FONT_LCD_SUBPIXEL_LAYOUT_MAX = 5` — Represents the size of the `FontLCDSubpixelLayout` enum.

## Enum Direction

- `DIRECTION_AUTO = 0` — Text direction is determined based on contents and current locale.
- `DIRECTION_LTR = 1` — Text is written from left to right.
- `DIRECTION_RTL = 2` — Text is written from right to left.
- `DIRECTION_INHERITED = 3` — Text writing direction is the same as base string writing direction.

## Enum Orientation

- `ORIENTATION_HORIZONTAL = 0` — Text is written horizontally.
- `ORIENTATION_VERTICAL = 1` — Left to right text is written vertically from top to bottom.

## Enum JustificationFlag

- `JUSTIFICATION_NONE = 0` — Do not justify text.
- `JUSTIFICATION_KASHIDA = 1` — Justify text by adding and removing kashidas.
- `JUSTIFICATION_WORD_BOUND = 2` — Justify text by changing width of the spaces between the words.
- `JUSTIFICATION_TRIM_EDGE_SPACES = 4` — Remove trailing and leading spaces from the justified text.
- `JUSTIFICATION_AFTER_LAST_TAB = 8` — Only apply justification to the part of the text after the last tab.
- `JUSTIFICATION_CONSTRAIN_ELLIPSIS = 16` — Apply justification to the trimmed line with ellipsis.
- `JUSTIFICATION_SKIP_LAST_LINE = 32` — Do not apply justification to the last line of the paragraph.
- `JUSTIFICATION_SKIP_LAST_LINE_WITH_VISIBLE_CHARS = 64` — Do not apply justification to the last line of the paragraph with visible characters (takes precedence over `JUSTIFICATION_SKIP_LAST_LINE`).
- `JUSTIFICATION_DO_NOT_SKIP_SINGLE_LINE = 128` — Always apply justification to the paragraphs with a single line (`JUSTIFICATION_SKIP_LAST_LINE` and `JUSTIFICATION_SKIP_LAST_LINE_WITH_VISIBLE_CHARS` are ignored).

## Enum AutowrapMode

- `AUTOWRAP_OFF = 0` — Autowrap is disabled.
- `AUTOWRAP_ARBITRARY = 1` — Wraps the text inside the node's bounding rectangle by allowing to break lines at arbitrary positions, which is useful when very limited space is available.
- `AUTOWRAP_WORD = 2` — Wraps the text inside the node's bounding rectangle by soft-breaking between words.
- `AUTOWRAP_WORD_SMART = 3` — Behaves similarly to `AUTOWRAP_WORD`, but force-breaks a word if that single word does not fit in one line.

## Enum LineBreakFlag

- `BREAK_NONE = 0` — Do not break the line.
- `BREAK_MANDATORY = 1` — Break the line at the line mandatory break characters (e.g.
- `BREAK_WORD_BOUND = 2` — Break the line between the words.
- `BREAK_GRAPHEME_BOUND = 4` — Break the line between any unconnected graphemes.
- `BREAK_ADAPTIVE = 8` — Should be used only in conjunction with `BREAK_WORD_BOUND`, break the line between any unconnected graphemes, if it's impossible to break it between the words.
- `BREAK_TRIM_EDGE_SPACES = 16` — Remove edge spaces from the broken line segments.
- `BREAK_TRIM_INDENT = 32` — Subtract first line indentation width from all lines after the first one.
- `BREAK_TRIM_START_EDGE_SPACES = 64` — Remove spaces and line break characters from the start of broken line segments.
- `BREAK_TRIM_END_EDGE_SPACES = 128` — Remove spaces and line break characters from the end of broken line segments.

## Enum VisibleCharactersBehavior

- `VC_CHARS_BEFORE_SHAPING = 0` — Trims text before the shaping. e.g, increasing `Label.visible_characters` or `RichTextLabel.visible_characters` value is visually identical to typing the text.
- `VC_CHARS_AFTER_SHAPING = 1` — Displays glyphs that are mapped to the first `Label.visible_characters` or `RichTextLabel.visible_characters` characters from the beginning of the text.
- `VC_GLYPHS_AUTO = 2` — Displays `Label.visible_ratio` or `RichTextLabel.visible_ratio` glyphs, starting from the left or from the right, depending on `Control.layout_direction` value.
- `VC_GLYPHS_LTR = 3` — Displays `Label.visible_ratio` or `RichTextLabel.visible_ratio` glyphs, starting from the left.
- `VC_GLYPHS_RTL = 4` — Displays `Label.visible_ratio` or `RichTextLabel.visible_ratio` glyphs, starting from the right.

## Enum OverrunBehavior

- `OVERRUN_NO_TRIMMING = 0` — No text trimming is performed.
- `OVERRUN_TRIM_CHAR = 1` — Trims the text per character.
- `OVERRUN_TRIM_WORD = 2` — Trims the text per word.
- `OVERRUN_TRIM_ELLIPSIS = 3` — Trims the text per character and adds an ellipsis to indicate that parts are hidden if trimmed text is 6 characters or longer.
- `OVERRUN_TRIM_WORD_ELLIPSIS = 4` — Trims the text per word and adds an ellipsis to indicate that parts are hidden if trimmed text is 6 characters or longer.
- `OVERRUN_TRIM_ELLIPSIS_FORCE = 5` — Trims the text per character and adds an ellipsis to indicate that parts are hidden regardless of trimmed text length.
- `OVERRUN_TRIM_WORD_ELLIPSIS_FORCE = 6` — Trims the text per word and adds an ellipsis to indicate that parts are hidden regardless of trimmed text length.

## Enum TextOverrunFlag

- `OVERRUN_NO_TRIM = 0` — No trimming is performed.
- `OVERRUN_TRIM = 1` — Trims the text when it exceeds the given width.
- `OVERRUN_TRIM_WORD_ONLY = 2` — Trims the text per word instead of per grapheme.
- `OVERRUN_ADD_ELLIPSIS = 4` — Determines whether an ellipsis should be added at the end of the text.
- `OVERRUN_ENFORCE_ELLIPSIS = 8` — Determines whether the ellipsis at the end of the text is enforced and may not be hidden.
- `OVERRUN_JUSTIFICATION_AWARE = 16` — Accounts for the text being justified before attempting to trim it (see `JustificationFlag`).
- `OVERRUN_SHORT_STRING_ELLIPSIS = 32` — Determines whether the ellipsis should be added regardless of the string length, otherwise it is added only if the string is 6 characters or longer.

## Enum GraphemeFlag

- `GRAPHEME_IS_VALID = 1` — Grapheme is supported by the font, and can be drawn.
- `GRAPHEME_IS_RTL = 2` — Grapheme is part of right-to-left or bottom-to-top run.
- `GRAPHEME_IS_VIRTUAL = 4` — Grapheme is not part of source text, it was added by justification process.
- `GRAPHEME_IS_SPACE = 8` — Grapheme is whitespace.
- `GRAPHEME_IS_BREAK_HARD = 16` — Grapheme is mandatory break point (e.g.
- `GRAPHEME_IS_BREAK_SOFT = 32` — Grapheme is optional break point (e.g. space).
- `GRAPHEME_IS_TAB = 64` — Grapheme is the tabulation character.
- `GRAPHEME_IS_ELONGATION = 128` — Grapheme is kashida.
- `GRAPHEME_IS_PUNCTUATION = 256` — Grapheme is punctuation character.
- `GRAPHEME_IS_UNDERSCORE = 512` — Grapheme is underscore character.
- `GRAPHEME_IS_CONNECTED = 1024` — Grapheme is connected to the previous grapheme.
- `GRAPHEME_IS_SAFE_TO_INSERT_TATWEEL = 2048` — It is safe to insert a U+0640 before this grapheme for elongation.
- `GRAPHEME_IS_EMBEDDED_OBJECT = 4096` — Grapheme is an object replacement character for the embedded object.
- `GRAPHEME_IS_SOFT_HYPHEN = 8192` — Grapheme is a soft hyphen.

## Enum Hinting

- `HINTING_NONE = 0` — Disables font hinting (smoother but less crisp).
- `HINTING_LIGHT = 1` — Use the light font hinting mode.
- `HINTING_NORMAL = 2` — Use the default font hinting mode (crisper but less smooth).

## Enum SubpixelPositioning

- `SUBPIXEL_POSITIONING_DISABLED = 0` — Glyph horizontal position is rounded to the whole pixel size, each glyph is rasterized once.
- `SUBPIXEL_POSITIONING_AUTO = 1` — Glyph horizontal position is rounded based on font size. - To one quarter of the pixel size if font size is smaller or equal to `SUBPIXEL_POSITIONING_ONE_QUARTER_MAX_SIZE`. - To one half of the pixel size if font size is smaller or equal to `SUBPIXEL_POSITIONING_ONE_HALF_MAX_SIZE`. - To the whole pixel size for larger fonts.
- `SUBPIXEL_POSITIONING_ONE_HALF = 2` — Glyph horizontal position is rounded to one half of the pixel size, each glyph is rasterized up to two times.
- `SUBPIXEL_POSITIONING_ONE_QUARTER = 3` — Glyph horizontal position is rounded to one quarter of the pixel size, each glyph is rasterized up to four times.
- `SUBPIXEL_POSITIONING_ONE_HALF_MAX_SIZE = 20` — Maximum font size which will use "one half of the pixel" subpixel positioning in `SUBPIXEL_POSITIONING_AUTO` mode.
- `SUBPIXEL_POSITIONING_ONE_QUARTER_MAX_SIZE = 16` — Maximum font size which will use "one quarter of the pixel" subpixel positioning in `SUBPIXEL_POSITIONING_AUTO` mode.

## Enum Feature

- `FEATURE_SIMPLE_LAYOUT = 1` — TextServer supports simple text layouts.
- `FEATURE_BIDI_LAYOUT = 2` — TextServer supports bidirectional text layouts.
- `FEATURE_VERTICAL_LAYOUT = 4` — TextServer supports vertical layouts.
- `FEATURE_SHAPING = 8` — TextServer supports complex text shaping.
- `FEATURE_KASHIDA_JUSTIFICATION = 16` — TextServer supports justification using kashidas.
- `FEATURE_BREAK_ITERATORS = 32` — TextServer supports complex line/word breaking rules (e.g. dictionary based).
- `FEATURE_FONT_BITMAP = 64` — TextServer supports loading bitmap fonts.
- `FEATURE_FONT_DYNAMIC = 128` — TextServer supports loading dynamic (TrueType, OpeType, etc.) fonts.
- `FEATURE_FONT_MSDF = 256` — TextServer supports multichannel signed distance field dynamic font rendering.
- `FEATURE_FONT_SYSTEM = 512` — TextServer supports loading system fonts.
- `FEATURE_FONT_VARIABLE = 1024` — TextServer supports variable fonts.
- `FEATURE_CONTEXT_SENSITIVE_CASE_CONVERSION = 2048` — TextServer supports locale dependent and context sensitive case conversion.
- `FEATURE_USE_SUPPORT_DATA = 4096` — TextServer require external data file for some features, see `load_support_data`.
- `FEATURE_UNICODE_IDENTIFIERS = 8192` — TextServer supports UAX #31 identifier validation, see `is_valid_identifier`.
- `FEATURE_UNICODE_SECURITY = 16384` — TextServer supports Unicode Technical Report #36 and Unicode Technical Standard #39 based spoof detection features.

## Enum ContourPointTag

- `CONTOUR_CURVE_TAG_ON = 1` — Contour point is on the curve.
- `CONTOUR_CURVE_TAG_OFF_CONIC = 0` — Contour point isn't on the curve, but serves as a control point for a conic (quadratic) Bézier arc.
- `CONTOUR_CURVE_TAG_OFF_CUBIC = 2` — Contour point isn't on the curve, but serves as a control point for a cubic Bézier arc.

## Enum SpacingType

- `SPACING_GLYPH = 0` — Spacing for each glyph.
- `SPACING_SPACE = 1` — Spacing for the space character.
- `SPACING_TOP = 2` — Spacing at the top of the line.
- `SPACING_BOTTOM = 3` — Spacing at the bottom of the line.
- `SPACING_MAX = 4` — Represents the size of the `SpacingType` enum.

## Enum FontStyle

- `FONT_BOLD = 1` — Font is bold.
- `FONT_ITALIC = 2` — Font is italic or oblique.
- `FONT_FIXED_WIDTH = 4` — Font has fixed-width characters (also known as monospace).

## Enum StructuredTextParser

- `STRUCTURED_TEXT_DEFAULT = 0` — Use default Unicode BiDi algorithm.
- `STRUCTURED_TEXT_URI = 1` — BiDi override for URI.
- `STRUCTURED_TEXT_FILE = 2` — BiDi override for file path.
- `STRUCTURED_TEXT_EMAIL = 3` — BiDi override for email.
- `STRUCTURED_TEXT_LIST = 4` — BiDi override for lists.
- `STRUCTURED_TEXT_GDSCRIPT = 5` — BiDi override for GDScript.
- `STRUCTURED_TEXT_CUSTOM = 6` — User defined structured text BiDi override function.

## Enum FixedSizeScaleMode

- `FIXED_SIZE_SCALE_DISABLE = 0` — Bitmap font is not scaled.
- `FIXED_SIZE_SCALE_INTEGER_ONLY = 1` — Bitmap font is scaled to the closest integer multiple of the font's fixed size.
- `FIXED_SIZE_SCALE_ENABLED = 2` — Bitmap font is scaled to an arbitrary (fractional) size.
