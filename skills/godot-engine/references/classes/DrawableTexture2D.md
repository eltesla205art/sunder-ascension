# DrawableTexture2D

**Inherits:** Texture2D

A 2D texture that supports drawing to itself via Blit calls.

A 2D texture that can be modified via blit calls, copying from a target texture to itself. Primarily intended to be managed in code, a user must call `setup` to initialize the state before drawing. Each `blit_rect` call takes at least a rectangle, the area to draw to, and another texture, what to be drawn. The draw calls use a Texture_Blit Shader to process and calculate the result, pixel by pixel.

## Properties

- `resource_local_to_scene: bool` = `false` — 

## Methods

- `blit_rect(rect: Rect2i, source: Texture2D, modulate: Color = Color(1, 1, 1, 1), mipmap: int = 0, material: Material = null) -> void` — Draws to given `rect` on this texture by copying from the given `source`.
- `blit_rect_multi(rect: Rect2i, sources: Texture2D[], extra_targets: DrawableTexture2D[], modulate: Color = Color(1, 1, 1, 1), mipmap: int = 0, material: Material = null) -> void` — Draws to the given `rect` on this texture, as well as on up to 3 DrawableTexture `extra_targets`.
- `generate_mipmaps() -> void` — Re-calculates the mipmaps for this texture on demand.
- `get_use_mipmaps() -> bool` *const* — Returns `true` if mipmaps are set to be used on this DrawableTexture.
- `set_format(format: DrawableTexture2D.DrawableFormat) -> void` — Sets the format of this DrawableTexture.
- `set_use_mipmaps(mipmaps: bool) -> void` — Sets if mipmaps should be used on this DrawableTexture.
- `setup(width: int, height: int, format: DrawableTexture2D.DrawableFormat, color: Color = Color(1, 1, 1, 1), use_mipmaps: bool = false) -> void` — Initializes the DrawableTexture to a White texture of the given `width`, `height`, and `format`.

## Enum DrawableFormat

- `DRAWABLE_FORMAT_RGBA8 = 0` — OpenGL texture format RGBA with four components, each with a bitdepth of 8.
- `DRAWABLE_FORMAT_RGBA8_SRGB = 1` — OpenGL texture format RGBA with four components, each with a bitdepth of 8.
- `DRAWABLE_FORMAT_RGBAH = 2` — OpenGL texture format GL_RGBA16F where there are four components, each a 16-bit "half-precision" floating-point value.
- `DRAWABLE_FORMAT_RGBAF = 3` — OpenGL texture format GL_RGBA32F where there are four components, each a 32-bit floating-point value.
