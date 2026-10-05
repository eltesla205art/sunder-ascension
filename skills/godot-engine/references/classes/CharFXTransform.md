# CharFXTransform

**Inherits:** RefCounted

Controls how an individual character will be displayed in a RichTextEffect.

By setting various properties on this object, you can control how individual characters will be displayed in a RichTextEffect.

## Properties

- `color: Color` = `Color(0, 0, 0, 1)` — The color the character will be drawn with.
- `elapsed_time: float` = `0.0` — The time elapsed since the RichTextLabel was added to the scene tree (in seconds).
- `env: Dictionary` = `{}` — Contains the arguments passed in the opening BBCode tag.
- `font: RID` = `RID()` — TextServer RID of the font used to render glyph, this value can be used with `TextServer.font_*` methods to retrieve font information.
- `glyph_count: int` = `0` — Number of glyphs in the grapheme cluster.
- `glyph_flags: int` = `0` — Glyph flags.
- `glyph_index: int` = `0` — Glyph index specific to the `font`.
- `offset: Vector2` = `Vector2(0, 0)` — The position offset the character will be drawn with (in pixels).
- `outline: bool` = `false` — If `true`, FX transform is called for outline drawing.
- `range: Vector2i` = `Vector2i(0, 0)` — Absolute character range in the string, corresponding to the glyph.
- `relative_index: int` = `0` — The character offset of the glyph, relative to the current RichTextEffect custom block.
- `transform: Transform2D` = `Transform2D(1, 0, 0, 1, 0, 0)` — The current transform of the current glyph.
- `visible: bool` = `true` — If `true`, the character will be drawn.
