# SpriteBase3D

**Inherits:** GeometryInstance3D

2D sprite node in 3D environment.

A node that displays 2D texture information in a 3D environment. See also Sprite3D where many other properties are defined.

## Properties

- `alpha_antialiasing_edge: float` = `0.0` — Threshold at which antialiasing will be applied on the alpha channel.
- `alpha_antialiasing_mode: BaseMaterial3D.AlphaAntiAliasing` = `0` — The type of alpha antialiasing to apply.
- `alpha_cut: SpriteBase3D.AlphaCutMode` = `0` — The alpha cutting mode to use for the sprite.
- `alpha_hash_scale: float` = `1.0` — The hashing scale for Alpha Hash.
- `alpha_scissor_threshold: float` = `0.5` — Threshold at which the alpha scissor will discard values.
- `axis: Vector3.Axis` = `2` — The direction in which the front of the texture faces.
- `billboard: BaseMaterial3D.BillboardMode` = `0` — The billboard mode to use for the sprite.
- `centered: bool` = `true` — If `true`, texture will be centered.
- `double_sided: bool` = `true` — If `true`, texture can be seen from the back as well, if `false`, it is invisible when looking at it from behind.
- `fixed_size: bool` = `false` — If `true`, the texture is rendered at the same size regardless of distance.
- `flip_h: bool` = `false` — If `true`, texture is flipped horizontally.
- `flip_v: bool` = `false` — If `true`, texture is flipped vertically.
- `modulate: Color` = `Color(1, 1, 1, 1)` — A color value used to multiply the texture's colors.
- `no_depth_test: bool` = `false` — If `true`, depth testing is disabled and the object will be drawn in render order.
- `offset: Vector2` = `Vector2(0, 0)` — The texture's drawing offset.
- `pixel_size: float` = `0.01` — The size of one pixel's width on the sprite to scale it in 3D.
- `render_priority: int` = `0` — Sets the render priority for the sprite.
- `shaded: bool` = `false` — If `true`, the Light3D in the Environment has effects on the sprite.
- `texture_filter: BaseMaterial3D.TextureFilter` = `3` — Filter flags for the texture.
- `transparent: bool` = `true` — If `true`, the texture's transparency and the opacity are used to make those parts of the sprite invisible.

## Methods

- `generate_triangle_mesh() -> TriangleMesh` *const* — Returns a TriangleMesh with the sprite's vertices following its current configuration (such as its `axis` and `pixel_size`).
- `get_draw_flag(flag: SpriteBase3D.DrawFlags) -> bool` *const* — Returns the value of the specified flag.
- `get_item_rect() -> Rect2` *const* — Returns the rectangle representing this sprite.
- `set_draw_flag(flag: SpriteBase3D.DrawFlags, enabled: bool) -> void` — If `true`, the specified flag will be enabled.

## Enum DrawFlags

- `FLAG_TRANSPARENT = 0` — If set, the texture's transparency and the opacity are used to make those parts of the sprite invisible.
- `FLAG_SHADED = 1` — If set, lights in the environment affect the sprite.
- `FLAG_DOUBLE_SIDED = 2` — If set, texture can be seen from the back as well.
- `FLAG_DISABLE_DEPTH_TEST = 3` — Disables the depth test, so this object is drawn on top of all others.
- `FLAG_FIXED_SIZE = 4` — Label is scaled by depth so that it always appears the same size on screen.
- `FLAG_MAX = 5` — Represents the size of the `DrawFlags` enum.

## Enum AlphaCutMode

- `ALPHA_CUT_DISABLED = 0` — This mode performs standard alpha blending.
- `ALPHA_CUT_DISCARD = 1` — This mode only allows fully transparent or fully opaque pixels.
- `ALPHA_CUT_OPAQUE_PREPASS = 2` — This mode draws fully opaque pixels in the depth prepass.
- `ALPHA_CUT_HASH = 3` — This mode draws cuts off all values below a spatially-deterministic threshold, the rest will remain opaque.
