# VisualShaderNodeTextureParameter

**Inherits:** VisualShaderNodeParameter

Performs a uniform texture lookup within the visual shader graph.

Performs a lookup operation on the texture provided as a uniform for the shader.

## Properties

- `color_default: VisualShaderNodeTextureParameter.ColorDefault` = `0` — Sets the default color if no texture is assigned to the uniform.
- `texture_filter: VisualShaderNodeTextureParameter.TextureFilter` = `0` — Sets the texture filtering mode.
- `texture_repeat: VisualShaderNodeTextureParameter.TextureRepeat` = `0` — Sets the texture repeating mode.
- `texture_source: VisualShaderNodeTextureParameter.TextureSource` = `0` — Sets the texture source mode.
- `texture_type: VisualShaderNodeTextureParameter.TextureType` = `0` — Defines the type of data provided by the source texture.

## Enum TextureType

- `TYPE_DATA = 0` — No hints are added to the uniform declaration.
- `TYPE_COLOR = 1` — Adds `source_color` as hint to the uniform declaration for proper conversion from nonlinear sRGB encoding to linear encoding.
- `TYPE_NORMAL_MAP = 2` — Adds `hint_normal` as hint to the uniform declaration, which internally converts the texture for proper usage as normal map.
- `TYPE_ANISOTROPY = 3` — Adds `hint_anisotropy` as hint to the uniform declaration to use for a flowmap.
- `TYPE_MAX = 4` — Represents the size of the `TextureType` enum.

## Enum ColorDefault

- `COLOR_DEFAULT_WHITE = 0` — Defaults to fully opaque white color.
- `COLOR_DEFAULT_BLACK = 1` — Defaults to fully opaque black color.
- `COLOR_DEFAULT_TRANSPARENT = 2` — Defaults to fully transparent black color.
- `COLOR_DEFAULT_MAX = 3` — Represents the size of the `ColorDefault` enum.

## Enum TextureFilter

- `FILTER_DEFAULT = 0` — Sample the texture using the filter determined by the node this shader is attached to.
- `FILTER_NEAREST = 1` — The texture filter reads from the nearest pixel only.
- `FILTER_LINEAR = 2` — The texture filter blends between the nearest 4 pixels.
- `FILTER_NEAREST_MIPMAP = 3` — The texture filter reads from the nearest pixel and blends between the nearest 2 mipmaps (or uses the nearest mipmap if `ProjectSettings.rendering/textures/default_filters/use_nearest_mipmap_filter` is `true`).
- `FILTER_LINEAR_MIPMAP = 4` — The texture filter blends between the nearest 4 pixels and between the nearest 2 mipmaps (or uses the nearest mipmap if `ProjectSettings.rendering/textures/default_filters/use_nearest_mipmap_filter` is `true`).
- `FILTER_NEAREST_MIPMAP_ANISOTROPIC = 5` — The texture filter reads from the nearest pixel and blends between 2 mipmaps (or uses the nearest mipmap if `ProjectSettings.rendering/textures/default_filters/use_nearest_mipmap_filter` is `true`) based on the angle between the surface and the camera view.
- `FILTER_LINEAR_MIPMAP_ANISOTROPIC = 6` — The texture filter blends between the nearest 4 pixels and blends between 2 mipmaps (or uses the nearest mipmap if `ProjectSettings.rendering/textures/default_filters/use_nearest_mipmap_filter` is `true`) based on the angle between the surface and the camera view.
- `FILTER_MAX = 7` — Represents the size of the `TextureFilter` enum.

## Enum TextureRepeat

- `REPEAT_DEFAULT = 0` — Sample the texture using the repeat mode determined by the node this shader is attached to.
- `REPEAT_ENABLED = 1` — Texture will repeat normally.
- `REPEAT_DISABLED = 2` — Texture will not repeat.
- `REPEAT_MAX = 3` — Represents the size of the `TextureRepeat` enum.

## Enum TextureSource

- `SOURCE_NONE = 0` — The texture source is not specified in the shader.
- `SOURCE_SCREEN = 1` — The texture source is the screen texture which captures all opaque objects drawn this frame.
- `SOURCE_DEPTH = 2` — The texture source is the depth texture from the depth prepass.
- `SOURCE_NORMAL_ROUGHNESS = 3` — The texture source is the normal-roughness buffer from the depth prepass.
- `SOURCE_MAX = 4` — Represents the size of the `TextureSource` enum.
