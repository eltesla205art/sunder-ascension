# FontFile

**Inherits:** Font

Holds font source data and prerendered glyph cache, imported from a dynamic or a bitmap font.

FontFile contains a set of glyphs to represent Unicode characters imported from a font file, as well as a cache of rasterized glyphs, and a set of fallback Fonts to use. Use FontVariation to access specific OpenType variation of the font, create simulated bold / slanted version, and draw lines of text. For more complex text processing, use FontVariation in conjunction with TextLine or TextParagraph. Supported font formats: - Dynamic font importer: TrueType (.ttf), TrueType collection (.ttc), OpenType (.otf), OpenType collection (.otc), WOFF (.woff), WOFF2 (.woff2), Type 1 (.pfb, .pfm). - Bitmap font importer: AngelCode BMFont (.fnt, .font), text and binary (version 3) format variants. - Monospace image font importer: All supported image formats.

## Properties

- `allow_system_fallback: bool` = `true` — If set to `true`, system fonts can be automatically used as fallbacks.
- `antialiasing: TextServer.FontAntialiasing` = `1` — Font anti-aliasing mode.
- `data: PackedByteArray` = `PackedByteArray()` — Contents of the dynamic font source file.
- `disable_embedded_bitmaps: bool` = `true` — If set to `true`, embedded font bitmap loading is disabled (bitmap-only and color fonts ignore this property).
- `fixed_size: int` = `0` — Font size, used only for the bitmap fonts.
- `fixed_size_scale_mode: TextServer.FixedSizeScaleMode` = `0` — Scaling mode, used only for the bitmap fonts with `fixed_size` greater than zero.
- `font_name: String` = `""` — Font family name.
- `font_stretch: int` = `100` — Font stretch amount, compared to a normal width.
- `font_style: TextServer.FontStyle` = `0` — Font style flags.
- `font_weight: int` = `400` — Weight (boldness) of the font.
- `force_autohinter: bool` = `false` — If set to `true`, auto-hinting is supported and preferred over font built-in hinting.
- `generate_mipmaps: bool` = `false` — If set to `true`, generate mipmaps for the font textures.
- `hinting: TextServer.Hinting` = `1` — Font hinting mode.
- `keep_rounding_remainders: bool` = `true` — If set to `true`, when aligning glyphs to the pixel boundaries rounding remainders are accumulated to ensure more uniform glyph distribution.
- `modulate_color_glyphs: bool` = `false` — If set to `true`, color modulation is applied when drawing colored glyphs, otherwise it's applied to the monochrome glyphs only.
- `msdf_pixel_range: int` = `16` — The width of the range around the shape between the minimum and maximum representable signed distance.
- `msdf_size: int` = `48` — Source font size used to generate MSDF textures.
- `multichannel_signed_distance_field: bool` = `false` — If set to `true`, glyphs of all sizes are rendered using single multichannel signed distance field (MSDF) generated from the dynamic font vector data.
- `opentype_feature_overrides: Dictionary` = `{}` — Font OpenType feature set override.
- `oversampling: float` = `0.0` — If set to a positive value, overrides the oversampling factor of the viewport this font is used in.
- `style_name: String` = `""` — Font style name.
- `subpixel_positioning: TextServer.SubpixelPositioning` = `1` — Font glyph subpixel positioning mode.

## Methods

- `clear_cache() -> void` — Removes all font cache entries.
- `clear_glyphs(cache_index: int, size: Vector2i) -> void` — Removes all rendered glyph information from the cache entry.
- `clear_kerning_map(cache_index: int, size: int) -> void` — Removes all kerning overrides.
- `clear_size_cache(cache_index: int) -> void` — Removes all font sizes from the cache entry.
- `clear_textures(cache_index: int, size: Vector2i) -> void` — Removes all textures from font cache entry.
- `get_cache_ascent(cache_index: int, size: int) -> float` *const* — Returns the font ascent (number of pixels above the baseline).
- `get_cache_count() -> int` *const* — Returns number of the font cache entries.
- `get_cache_descent(cache_index: int, size: int) -> float` *const* — Returns the font descent (number of pixels below the baseline).
- `get_cache_scale(cache_index: int, size: int) -> float` *const* — Returns scaling factor of the color bitmap font.
- `get_cache_underline_position(cache_index: int, size: int) -> float` *const* — Returns pixel offset of the underline below the baseline.
- `get_cache_underline_thickness(cache_index: int, size: int) -> float` *const* — Returns thickness of the underline in pixels.
- `get_char_from_glyph_index(size: int, glyph_index: int) -> int` *const* — Returns character code associated with `glyph_index`, or `0` if `glyph_index` is invalid.
- `get_embolden(cache_index: int) -> float` *const* — Returns embolden strength, if is not equal to zero, emboldens the font outlines.
- `get_extra_baseline_offset(cache_index: int) -> float` *const* — Returns extra baseline offset (as a fraction of font height).
- `get_extra_spacing(cache_index: int, spacing: TextServer.SpacingType) -> int` *const* — Returns spacing for `spacing` in pixels (not relative to the font size).
- `get_face_index(cache_index: int) -> int` *const* — Returns an active face index in the TrueType / OpenType collection.
- `get_glyph_advance(cache_index: int, size: int, glyph: int) -> Vector2` *const* — Returns glyph advance (offset of the next glyph).
- `get_glyph_index(size: int, char: int, variation_selector: int) -> int` *const* — Returns the glyph index of a `char`, optionally modified by the `variation_selector`.
- `get_glyph_list(cache_index: int, size: Vector2i) -> PackedInt32Array` *const* — Returns list of rendered glyphs in the cache entry.
- `get_glyph_offset(cache_index: int, size: Vector2i, glyph: int) -> Vector2` *const* — Returns glyph offset from the baseline.
- `get_glyph_size(cache_index: int, size: Vector2i, glyph: int) -> Vector2` *const* — Returns glyph size.
- `get_glyph_texture_idx(cache_index: int, size: Vector2i, glyph: int) -> int` *const* — Returns index of the cache texture containing the glyph.
- `get_glyph_uv_rect(cache_index: int, size: Vector2i, glyph: int) -> Rect2` *const* — Returns rectangle in the cache texture containing the glyph.
- `get_kerning(cache_index: int, size: int, glyph_pair: Vector2i) -> Vector2` *const* — Returns kerning for the pair of glyphs.
- `get_kerning_list(cache_index: int, size: int) -> Vector2i[]` *const* — Returns list of the kerning overrides.
- `get_language_support_override(language: String) -> bool` *const* — Returns `true` if support override is enabled for the `language`.
- `get_language_support_overrides() -> PackedStringArray` *const* — Returns list of language support overrides.
- `get_script_support_override(script: String) -> bool` *const* — Returns `true` if support override is enabled for the `script`.
- `get_script_support_overrides() -> PackedStringArray` *const* — Returns list of script support overrides.
- `get_size_cache_list(cache_index: int) -> Vector2i[]` *const* — Returns list of the font sizes in the cache.
- `get_texture_count(cache_index: int, size: Vector2i) -> int` *const* — Returns number of textures used by font cache entry.
- `get_texture_image(cache_index: int, size: Vector2i, texture_index: int) -> Image` *const* — Returns a copy of the font cache texture image.
- `get_texture_offsets(cache_index: int, size: Vector2i, texture_index: int) -> PackedInt32Array` *const* — Returns a copy of the array containing glyph packing data.
- `get_transform(cache_index: int) -> Transform2D` *const* — Returns 2D transform, applied to the font outlines, can be used for slanting, flipping and rotating glyphs.
- `get_variation_coordinates(cache_index: int) -> Dictionary` *const* — Returns variation coordinates for the specified font cache entry.
- `load_bitmap_font(path: String) -> int[Error]` — Loads an AngelCode BMFont (.fnt, .font) bitmap font from file `path`.
- `load_dynamic_font(path: String) -> int[Error]` — Loads a TrueType (.ttf), OpenType (.otf), WOFF (.woff), WOFF2 (.woff2) or Type 1 (.pfb, .pfm) dynamic font from file `path`.
- `remove_cache(cache_index: int) -> void` — Removes specified font cache entry.
- `remove_glyph(cache_index: int, size: Vector2i, glyph: int) -> void` — Removes specified rendered glyph information from the cache entry.
- `remove_kerning(cache_index: int, size: int, glyph_pair: Vector2i) -> void` — Removes kerning override for the pair of glyphs.
- `remove_language_support_override(language: String) -> void` — Remove language support override.
- `remove_script_support_override(script: String) -> void` — Removes script support override.
- `remove_size_cache(cache_index: int, size: Vector2i) -> void` — Removes specified font size from the cache entry.
- `remove_texture(cache_index: int, size: Vector2i, texture_index: int) -> void` — Removes specified texture from the cache entry.
- `render_glyph(cache_index: int, size: Vector2i, index: int) -> void` — Renders specified glyph to the font cache texture.
- `render_range(cache_index: int, size: Vector2i, start: int, end: int) -> void` — Renders the range of characters to the font cache texture.
- `set_cache_ascent(cache_index: int, size: int, ascent: float) -> void` — Sets the font ascent (number of pixels above the baseline).
- `set_cache_descent(cache_index: int, size: int, descent: float) -> void` — Sets the font descent (number of pixels below the baseline).
- `set_cache_scale(cache_index: int, size: int, scale: float) -> void` — Sets scaling factor of the color bitmap font.
- `set_cache_underline_position(cache_index: int, size: int, underline_position: float) -> void` — Sets pixel offset of the underline below the baseline.
- `set_cache_underline_thickness(cache_index: int, size: int, underline_thickness: float) -> void` — Sets thickness of the underline in pixels.
- `set_embolden(cache_index: int, strength: float) -> void` — Sets embolden strength, if is not equal to zero, emboldens the font outlines.
- `set_extra_baseline_offset(cache_index: int, baseline_offset: float) -> void` — Sets extra baseline offset (as a fraction of font height).
- `set_extra_spacing(cache_index: int, spacing: TextServer.SpacingType, value: int) -> void` — Sets the spacing for `spacing` to `value` in pixels (not relative to the font size).
- `set_face_index(cache_index: int, face_index: int) -> void` — Sets an active face index in the TrueType / OpenType collection.
- `set_glyph_advance(cache_index: int, size: int, glyph: int, advance: Vector2) -> void` — Sets glyph advance (offset of the next glyph).
- `set_glyph_offset(cache_index: int, size: Vector2i, glyph: int, offset: Vector2) -> void` — Sets glyph offset from the baseline.
- `set_glyph_size(cache_index: int, size: Vector2i, glyph: int, gl_size: Vector2) -> void` — Sets glyph size.
- `set_glyph_texture_idx(cache_index: int, size: Vector2i, glyph: int, texture_idx: int) -> void` — Sets index of the cache texture containing the glyph.
- `set_glyph_uv_rect(cache_index: int, size: Vector2i, glyph: int, uv_rect: Rect2) -> void` — Sets rectangle in the cache texture containing the glyph.
- `set_kerning(cache_index: int, size: int, glyph_pair: Vector2i, kerning: Vector2) -> void` — Sets kerning for the pair of glyphs.
- `set_language_support_override(language: String, supported: bool) -> void` — Adds override for `Font.is_language_supported`.
- `set_script_support_override(script: String, supported: bool) -> void` — Adds override for `Font.is_script_supported`.
- `set_texture_image(cache_index: int, size: Vector2i, texture_index: int, image: Image) -> void` — Sets font cache texture image.
- `set_texture_offsets(cache_index: int, size: Vector2i, texture_index: int, offset: PackedInt32Array) -> void` — Sets array containing glyph packing data.
- `set_transform(cache_index: int, transform: Transform2D) -> void` — Sets 2D transform, applied to the font outlines, can be used for slanting, flipping, and rotating glyphs.
- `set_variation_coordinates(cache_index: int, variation_coordinates: Dictionary) -> void` — Sets variation coordinates for the specified font cache entry.
