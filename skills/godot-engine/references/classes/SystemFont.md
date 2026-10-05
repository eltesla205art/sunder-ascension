# SystemFont

**Inherits:** Font

A font loaded from a system font. Falls back to a default theme font if not implemented on the host OS.

SystemFont loads a font from a system font with the first matching name from `font_names`. It will attempt to match font style, but it's not guaranteed. The returned font might be part of a font collection or be a variable font with OpenType "weight", "width" and/or "italic" features set. You can create FontVariation of the system font for precise control over its features.

## Properties

- `allow_system_fallback: bool` = `true` — If set to `true`, system fonts can be automatically used as fallbacks.
- `antialiasing: TextServer.FontAntialiasing` = `1` — Font anti-aliasing mode.
- `disable_embedded_bitmaps: bool` = `true` — If set to `true`, embedded font bitmap loading is disabled (bitmap-only and color fonts ignore this property).
- `font_italic: bool` = `false` — If set to `true`, italic or oblique font is preferred.
- `font_names: PackedStringArray` = `PackedStringArray()` — Array of font family names to search, first matching font found is used.
- `font_stretch: int` = `100` — Preferred font stretch amount, compared to a normal width.
- `font_weight: int` = `400` — Preferred weight (boldness) of the font.
- `force_autohinter: bool` = `false` — If set to `true`, auto-hinting is supported and preferred over font built-in hinting.
- `generate_mipmaps: bool` = `false` — If set to `true`, generate mipmaps for the font textures.
- `hinting: TextServer.Hinting` = `1` — Font hinting mode.
- `keep_rounding_remainders: bool` = `true` — If set to `true`, when aligning glyphs to the pixel boundaries rounding remainders are accumulated to ensure more uniform glyph distribution.
- `modulate_color_glyphs: bool` = `false` — If set to `true`, color modulation is applied when drawing colored glyphs, otherwise it's applied to the monochrome glyphs only.
- `msdf_pixel_range: int` = `16` — The width of the range around the shape between the minimum and maximum representable signed distance.
- `msdf_size: int` = `48` — Source font size used to generate MSDF textures.
- `multichannel_signed_distance_field: bool` = `false` — If set to `true`, glyphs of all sizes are rendered using single multichannel signed distance field generated from the dynamic font vector data.
- `oversampling: float` = `0.0` — If set to a positive value, overrides the oversampling factor of the viewport this font is used in.
- `subpixel_positioning: TextServer.SubpixelPositioning` = `1` — Font glyph subpixel positioning mode.
