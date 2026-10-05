# FontVariation

**Inherits:** Font

A variation of a font with additional settings.

Provides OpenType variations, simulated bold / slant, and additional font settings like OpenType features and extra spacing. To use simulated bold font variant:  To set the coordinate of multiple variation axes:

## Properties

- `base_font: Font` — Base font used to create a variation.
- `baseline_offset: float` = `0.0` — Extra baseline offset (as a fraction of font height).
- `opentype_features: Dictionary` = `{}` — A set of OpenType feature tags.
- `palette_custom_colors: PackedColorArray` = `PackedColorArray()` — An array of colors to override predefined palette.
- `palette_index: int` = `0` — A palette index.
- `spacing_bottom: int` = `0` — Extra spacing at the bottom of the line in pixels.
- `spacing_glyph: int` = `0` — Extra spacing between graphical glyphs.
- `spacing_space: int` = `0` — Extra width of the space glyphs.
- `spacing_top: int` = `0` — Extra spacing at the top of the line in pixels.
- `variation_embolden: float` = `0.0` — If is not equal to zero, emboldens the font outlines.
- `variation_face_index: int` = `0` — Active face index in the TrueType / OpenType collection file.
- `variation_opentype: Dictionary` = `{}` — Font OpenType variation coordinates.
- `variation_transform: Transform2D` = `Transform2D(1, 0, 0, 1, 0, 0)` — 2D transform, applied to the font outlines, can be used for slanting, flipping and rotating glyphs.

## Methods

- `set_spacing(spacing: TextServer.SpacingType, value: int) -> void` — Sets the spacing for `spacing` to `value` in pixels (not relative to the font size).
