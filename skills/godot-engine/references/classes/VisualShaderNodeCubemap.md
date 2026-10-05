# VisualShaderNodeCubemap

**Inherits:** VisualShaderNode

A Cubemap sampling node to be used within the visual shader graph.

Translated to `texture(cubemap, vec3)` in the shader language. Returns a color vector and alpha channel as scalar.

## Properties

- `cube_map: TextureLayered` — The Cubemap texture to sample when using `SOURCE_TEXTURE` as `source`.
- `source: VisualShaderNodeCubemap.Source` = `0` — Defines which source should be used for the sampling.
- `texture_type: VisualShaderNodeCubemap.TextureType` = `0` — Defines the type of data provided by the source texture.

## Enum Source

- `SOURCE_TEXTURE = 0` — Use the Cubemap set via `cube_map`.
- `SOURCE_PORT = 1` — Use the Cubemap sampler reference passed via the `samplerCube` port.
- `SOURCE_MAX = 2` — Represents the size of the `Source` enum.

## Enum TextureType

- `TYPE_DATA = 0` — No hints are added to the uniform declaration.
- `TYPE_COLOR = 1` — Adds `source_color` as hint to the uniform declaration for proper conversion from nonlinear sRGB encoding to linear encoding.
- `TYPE_NORMAL_MAP = 2` — Adds `hint_normal` as hint to the uniform declaration, which internally converts the texture for proper usage as normal map.
- `TYPE_MAX = 3` — Represents the size of the `TextureType` enum.
