# PortableCompressedTexture2D

**Inherits:** Texture2D

Provides a compressed texture for disk and/or VRAM in a way that is portable.

This class allows storing compressed textures as self contained (not imported) resources. For 2D usage (compressed on disk, uncompressed on VRAM), the lossy and lossless modes are recommended. For 3D usage (compressed on VRAM) it depends on the target platform. If you intend to only use desktop, S3TC or BPTC are recommended.

## Properties

- `keep_compressed_buffer: bool` = `false` — If `true`, when running in the editor, this texture will keep the source-compressed data in memory, allowing the data to persist after loading.
- `resource_local_to_scene: bool` = `false` — 
- `size_override: Vector2` = `Vector2(0, 0)` — Allows overriding the texture's size (for 2D only).

## Methods

- `create_from_image(image: Image, compression_mode: PortableCompressedTexture2D.CompressionMode, normal_map: bool = false, lossy_quality: float = 0.8) -> void` — Initializes the compressed texture from a base image.
- `get_compression_mode() -> int[PortableCompressedTexture2D.CompressionMode]` *const* — Return the compression mode used (valid after initialized).
- `is_keeping_all_compressed_buffers() -> bool` *static* — Returns `true` if the flag is overridden for all textures of this type.
- `set_basisu_compressor_params(uastc_level: int, rdo_quality_loss: float) -> void` — Sets the compressor parameters for Basis Universal compression.
- `set_keep_all_compressed_buffers(keep: bool) -> void` *static* — If `keep` is `true`, overrides the flag globally for all textures of this type.

## Enum CompressionMode

- `COMPRESSION_MODE_LOSSLESS = 0` — 
- `COMPRESSION_MODE_LOSSY = 1` — 
- `COMPRESSION_MODE_BASIS_UNIVERSAL = 2` — 
- `COMPRESSION_MODE_S3TC = 3` — 
- `COMPRESSION_MODE_ETC2 = 4` — 
- `COMPRESSION_MODE_BPTC = 5` — 
- `COMPRESSION_MODE_ASTC = 6` —
