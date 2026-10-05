# ResourceImporterImageFont

**Inherits:** ResourceImporter

Imports a bitmap font where all glyphs have the same width and height.

This image-based workflow can be easier to use than ResourceImporterBMFont, but it requires all glyphs to have the same width and height, glyph advances and drawing offsets can be customized. This makes ResourceImporterImageFont most suited to fixed-width fonts. See also ResourceImporterDynamicFont.

## Properties

- `ascent: int` = `0` — Font ascent (number of pixels above the baseline).
- `character_margin: Rect2i` = `Rect2i(0, 0, 0, 0)` — Margin applied around every imported glyph.
- `character_ranges: PackedStringArray` = `PackedStringArray()` — The character ranges to import from the font image.
- `columns: int` = `1` — Number of columns in the font image.
- `compress: bool` = `true` — If `true`, uses lossless compression for the resulting font.
- `descent: int` = `0` — Font descent (number of pixels below the baseline).
- `fallbacks: Array` = `[]` — List of font fallbacks to use if a glyph isn't found in this bitmap font.
- `image_margin: Rect2i` = `Rect2i(0, 0, 0, 0)` — Margin to cut on the sides of the entire image.
- `kerning_pairs: PackedStringArray` = `PackedStringArray()` — Kerning pairs for the font.
- `rows: int` = `1` — Number of rows in the font image.
- `scaling_mode: int` = `2` — Font scaling mode.
