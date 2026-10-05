# TextMesh

**Inherits:** PrimitiveMesh

Generate a PrimitiveMesh from the text.

Generate a PrimitiveMesh from the text. TextMesh can be generated only when using dynamic fonts with vector glyph contours. Bitmap fonts (including bitmap data in the TrueType/OpenType containers, like color emoji fonts) are not supported. The UV layout is arranged in 4 horizontal strips, top to bottom: 40% of the height for the front face, 40% for the back face, 10% for the outer edges and 10% for the inner edges.

## Properties

- `autowrap_mode: TextServer.AutowrapMode` = `0` — If set to something other than `TextServer.AUTOWRAP_OFF`, the text gets wrapped inside the node's bounding rectangle.
- `curve_step: float` = `0.5` — Step (in pixels) used to approximate Bézier curves.
- `depth: float` = `0.05` — Depths of the mesh, if set to `0.0` only front surface, is generated, and UV layout is changed to use full texture for the front face only.
- `font: Font` — Font configuration used to display text.
- `font_size: int` = `16` — Font size of the TextMesh's text.
- `horizontal_alignment: HorizontalAlignment` = `1` — Controls the text's horizontal alignment.
- `justification_flags: TextServer.JustificationFlag` = `163` — Line fill alignment rules.
- `language: String` = `""` — Language code used for line-breaking and text shaping algorithms.
- `line_spacing: float` = `0.0` — Additional vertical spacing between lines (in pixels), spacing is added to line descent.
- `offset: Vector2` = `Vector2(0, 0)` — The text drawing offset (in pixels).
- `pixel_size: float` = `0.01` — The size of one pixel's width on the text to scale it in 3D.
- `structured_text_bidi_override: TextServer.StructuredTextParser` = `0` — Set BiDi algorithm override for the structured text.
- `structured_text_bidi_override_options: Array` = `[]` — Set additional options for BiDi override.
- `text: String` = `""` — The text to generate mesh from.
- `text_direction: TextServer.Direction` = `0` — Base text writing direction.
- `uppercase: bool` = `false` — If `true`, all the text displays as UPPERCASE.
- `vertical_alignment: VerticalAlignment` = `1` — Controls the text's vertical alignment.
- `width: float` = `500.0` — Text width (in pixels), used for fill alignment.
