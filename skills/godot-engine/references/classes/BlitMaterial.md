# BlitMaterial

**Inherits:** Material

A material that processes blit calls to a DrawableTexture.

A material resource that can be used by DrawableTextures when processing blit calls to draw.

## Properties

- `blend_mode: BlitMaterial.BlendMode` = `0` — The manner in which the newly blitted texture is blended with the original DrawableTexture.

## Enum BlendMode

- `BLEND_MODE_MIX = 0` — Mix blending mode.
- `BLEND_MODE_ADD = 1` — Additive blending mode.
- `BLEND_MODE_SUB = 2` — Subtractive blending mode.
- `BLEND_MODE_MUL = 3` — Multiplicative blending mode.
- `BLEND_MODE_DISABLED = 4` — No blending mode, direct color copy.
- `BLEND_MODE_PREMULTIPLIED_ALPHA = 5` — Mix blending mode.
