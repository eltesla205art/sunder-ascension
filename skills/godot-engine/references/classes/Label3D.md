# Label3D

**Inherits:** GeometryInstance3D

A node for displaying plain text in 3D space.

A node for displaying plain text in 3D space. By adjusting various properties of this node, you can configure things such as the text's appearance and whether it always faces the camera.

## Properties

- `alpha_antialiasing_edge: float` = `0.0` — Threshold at which antialiasing will be applied on the alpha channel.
- `alpha_antialiasing_mode: BaseMaterial3D.AlphaAntiAliasing` = `0` — The type of alpha antialiasing to apply.
- `alpha_cut: Label3D.AlphaCutMode` = `0` — The alpha cutting mode to use for the sprite.
- `alpha_hash_scale: float` = `1.0` — The hashing scale for Alpha Hash.
- `alpha_scissor_threshold: float` = `0.5` — Threshold at which the alpha scissor will discard values.
- `autowrap_mode: TextServer.AutowrapMode` = `0` — If set to something other than `TextServer.AUTOWRAP_OFF`, the text gets wrapped inside the node's bounding rectangle.
- `autowrap_trim_flags: TextServer.LineBreakFlag` = `192` — Autowrap space trimming flags.
- `billboard: BaseMaterial3D.BillboardMode` = `0` — The billboard mode to use for the label.
- `cast_shadow: GeometryInstance3D.ShadowCastingSetting` = `0` — 
- `double_sided: bool` = `true` — If `true`, text can be seen from the back as well, if `false`, it is invisible when looking at it from behind.
- `fixed_size: bool` = `false` — If `true`, the label is rendered at the same size regardless of distance.
- `font: Font` — Font configuration used to display text.
- `font_size: int` = `32` — Font size of the Label3D's text.
- `gi_mode: GeometryInstance3D.GIMode` = `0` — 
- `horizontal_alignment: HorizontalAlignment` = `1` — Controls the text's horizontal alignment.
- `justification_flags: TextServer.JustificationFlag` = `163` — Line fill alignment rules.
- `language: String` = `""` — Language code used for line-breaking and text shaping algorithms.
- `line_spacing: float` = `0.0` — Additional vertical spacing between lines (in pixels), spacing is added to line descent.
- `modulate: Color` = `Color(1, 1, 1, 1)` — Text Color of the Label3D.
- `no_depth_test: bool` = `false` — If `true`, depth testing is disabled and the object will be drawn in render order.
- `offset: Vector2` = `Vector2(0, 0)` — The text drawing offset (in pixels).
- `outline_modulate: Color` = `Color(0, 0, 0, 1)` — The tint of text outline.
- `outline_render_priority: int` = `-1` — Sets the render priority for the text outline.
- `outline_size: int` = `12` — Text outline size.
- `pixel_size: float` = `0.005` — The size of one pixel's width on the label to scale it in 3D.
- `render_priority: int` = `0` — Sets the render priority for the text.
- `shaded: bool` = `false` — If `true`, the Light3D in the Environment has effects on the label.
- `structured_text_bidi_override: TextServer.StructuredTextParser` = `0` — Set BiDi algorithm override for the structured text.
- `structured_text_bidi_override_options: Array` = `[]` — Set additional options for BiDi override.
- `text: String` = `""` — The text to display on screen.
- `text_direction: TextServer.Direction` = `0` — Base text writing direction.
- `texture_filter: BaseMaterial3D.TextureFilter` = `3` — Filter flags for the texture.
- `uppercase: bool` = `false` — If `true`, all the text displays as UPPERCASE.
- `vertical_alignment: VerticalAlignment` = `1` — Controls the text's vertical alignment.
- `width: float` = `500.0` — Text width (in pixels), used for autowrap and fill alignment.

## Methods

- `generate_triangle_mesh() -> TriangleMesh` *const* — Returns a TriangleMesh with the label's vertices following its current configuration (such as its `pixel_size`).
- `get_draw_flag(flag: Label3D.DrawFlags) -> bool` *const* — Returns the value of the specified flag.
- `set_draw_flag(flag: Label3D.DrawFlags, enabled: bool) -> void` — If `true`, the specified `flag` will be enabled.

## Enum DrawFlags

- `FLAG_SHADED = 0` — If set, lights in the environment affect the label.
- `FLAG_DOUBLE_SIDED = 1` — If set, text can be seen from the back as well.
- `FLAG_DISABLE_DEPTH_TEST = 2` — Disables the depth test, so this object is drawn on top of all others.
- `FLAG_FIXED_SIZE = 3` — Label is scaled by depth so that it always appears the same size on screen.
- `FLAG_MAX = 4` — Represents the size of the `DrawFlags` enum.

## Enum AlphaCutMode

- `ALPHA_CUT_DISABLED = 0` — This mode performs standard alpha blending.
- `ALPHA_CUT_DISCARD = 1` — This mode only allows fully transparent or fully opaque pixels.
- `ALPHA_CUT_OPAQUE_PREPASS = 2` — This mode draws fully opaque pixels in the depth prepass.
- `ALPHA_CUT_HASH = 3` — This mode draws cuts off all values below a spatially-deterministic threshold, the rest will remain opaque.
