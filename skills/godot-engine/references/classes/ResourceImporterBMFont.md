# ResourceImporterBMFont

**Inherits:** ResourceImporter

Imports a bitmap font in the BMFont (`.fnt`) format.

The BMFont format is a format created by the BMFont program. Many BMFont-compatible programs also exist, like BMGlyph. Compared to ResourceImporterImageFont, ResourceImporterBMFont supports bitmap fonts with varying glyph widths/heights. See also ResourceImporterDynamicFont.

## Properties

- `compress: bool` = `true` — If `true`, uses lossless compression for the resulting font.
- `fallbacks: Array` = `[]` — List of font fallbacks to use if a glyph isn't found in this bitmap font.
- `scaling_mode: int` = `2` — Font scaling mode.
