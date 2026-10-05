# RDTextureFormat

**Inherits:** RefCounted

Texture format (used by RenderingDevice).

This object is used by RenderingDevice.

## Properties

- `array_layers: int` = `1` — The number of layers in the texture.
- `depth: int` = `1` — The texture's depth (in pixels).
- `format: RenderingDevice.DataFormat` = `8` — The texture's pixel data format.
- `height: int` = `1` — The texture's height (in pixels).
- `is_discardable: bool` = `false` — If a texture is discardable, its contents do not need to be preserved between frames.
- `is_resolve_buffer: bool` = `false` — The texture will be used as the destination of a resolve operation.
- `mipmaps: int` = `1` — The number of mipmaps available in the texture.
- `samples: RenderingDevice.TextureSamples` = `0` — The number of samples used when sampling the texture.
- `texture_type: RenderingDevice.TextureType` = `1` — The texture type.
- `usage_bits: RenderingDevice.TextureUsageBits` = `0` — The texture's usage bits, which determine what can be done using the texture.
- `width: int` = `1` — The texture's width (in pixels).

## Methods

- `add_shareable_format(format: RenderingDevice.DataFormat) -> void` — Adds `format` as a valid format for the corresponding RDTextureView's `RDTextureView.format_override` property.
- `remove_shareable_format(format: RenderingDevice.DataFormat) -> void` — Removes `format` from the list of valid formats that the corresponding RDTextureView's `RDTextureView.format_override` property can be set to.
