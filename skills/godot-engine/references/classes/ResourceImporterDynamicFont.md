# ResourceImporterDynamicFont

**Inherits:** ResourceImporter

Imports a TTF, TTC, OTF, OTC, WOFF or WOFF2 font file for font rendering that adapts to any size.

Unlike bitmap fonts, dynamic fonts can be resized to any size and still look crisp. Dynamic fonts also optionally support MSDF font rendering, which allows for run-time scale changes with no re-rasterization cost. While WOFF and especially WOFF2 tend to result in smaller file sizes, there is no universally "better" font format. In most situations, it's recommended to use the font format that was shipped on the font developer's website.

## Properties

- `allow_system_fallback: bool` = `true` — If `true`, automatically use system fonts as a fallback if a glyph isn't found in this dynamic font.
- `antialiasing: int` = `1` — The font antialiasing method to use.
- `compress: bool` = `true` — If `true`, uses lossless compression for the resulting font.
- `disable_embedded_bitmaps: bool` = `true` — If set to `true`, embedded font bitmap loading is disabled (bitmap-only and color fonts ignore this property).
- `fallbacks: Array` = `[]` — List of font fallbacks to use if a glyph isn't found in this dynamic font.
- `force_autohinter: bool` = `false` — If `true`, forces generation of hinting data for the font using FreeType's autohinter.
- `generate_mipmaps: bool` = `false` — If `true`, this font will have mipmaps generated.
- `hinting: int` = `3` — The hinting mode to use.
- `keep_rounding_remainders: bool` = `true` — If set to `true`, when aligning glyphs to the pixel boundaries rounding remainders are accumulated to ensure more uniform glyph distribution.
- `language_support: Dictionary` = `{}` — Override the list of languages supported by this font.
- `modulate_color_glyphs: bool` = `false` — If set to `true`, color modulation is applied when drawing colored glyphs, otherwise it's applied to the monochrome glyphs only.
- `msdf_pixel_range: int` = `8` — The width of the range around the shape between the minimum and maximum representable signed distance.
- `msdf_size: int` = `48` — Source font size used to generate MSDF textures.
- `multichannel_signed_distance_field: bool` = `false` — If set to `true`, the font will use multichannel signed distance field (MSDF) for crisp rendering at any size.
- `opentype_features: Dictionary` = `{}` — The OpenType features to enable, disable or set a value for this font.
- `oversampling: float` = `0.0` — If set to a positive value, overrides the oversampling factor of the viewport this font is used in.
- `preload: Array` = `[]` — The glyph ranges to prerender.
- `script_support: Dictionary` = `{}` — Override the list of language scripts supported by this font.
- `subpixel_positioning: int` = `4` — Subpixel positioning improves font rendering appearance, especially at smaller font sizes.
