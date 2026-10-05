# VisualShaderNodeTexture

**Inherits:** VisualShaderNode

Performs a 2D texture lookup within the visual shader graph.

Performs a lookup operation on the provided texture, with support for multiple texture sources to choose from.

## Properties

- `source: VisualShaderNodeTexture.Source` = `0` — Determines the source for the lookup.
- `texture: Texture2D` — The source texture, if needed for the selected `source`.
- `texture_type: VisualShaderNodeTexture.TextureType` = `0` — Specifies the type of the texture if `source` is set to `SOURCE_TEXTURE`.

## Enum Source

- `SOURCE_TEXTURE = 0` — Use the texture given as an argument for this function.
- `SOURCE_SCREEN = 1` — Use the current viewport's texture as the source.
- `SOURCE_2D_TEXTURE = 2` — Use the texture from this shader's texture built-in (e.g. a texture of a Sprite2D).
- `SOURCE_2D_NORMAL = 3` — Use the texture from this shader's normal map built-in.
- `SOURCE_DEPTH = 4` — Use the depth texture captured during the depth prepass.
- `SOURCE_PORT = 5` — Use the texture provided in the input port for this function.
- `SOURCE_3D_NORMAL = 6` — Use the normal buffer captured during the depth prepass.
- `SOURCE_ROUGHNESS = 7` — Use the roughness buffer captured during the depth prepass.
- `SOURCE_MAX = 8` — Represents the size of the `Source` enum.

## Enum TextureType

- `TYPE_DATA = 0` — No hints are added to the uniform declaration.
- `TYPE_COLOR = 1` — Adds `source_color` as hint to the uniform declaration for proper conversion from nonlinear sRGB encoding to linear encoding.
- `TYPE_NORMAL_MAP = 2` — Adds `hint_normal` as hint to the uniform declaration, which internally converts the texture for proper usage as normal map.
- `TYPE_MAX = 3` — Represents the size of the `TextureType` enum.
