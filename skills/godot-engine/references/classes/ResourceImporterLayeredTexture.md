# ResourceImporterLayeredTexture

**Inherits:** ResourceImporter

Imports a 3-dimensional texture (Texture3D), a Texture2DArray, a Cubemap or a CubemapArray.

This imports a 3-dimensional texture, which can then be used in custom shaders, as a FogMaterial density map or as a GPUParticlesAttractorVectorField3D. See also ResourceImporterTexture and ResourceImporterTextureAtlas.

## Properties

- `compress/channel_pack: int` = `0` — Controls how color channels should be used in the imported texture. sRGB Friendly:, prevents the R and RG color formats from being used, as they do not support nonlinear sRGB encoding.
- `compress/hdr_compression: int` = `1` — Controls how VRAM compression should be performed for HDR images.
- `compress/high_quality: bool` = `false` — If `true`, uses BPTC compression on desktop platforms and ASTC compression on mobile platforms.
- `compress/high_quality_mode: int` = `0` — Controls the priorities of the VRAM compression when `compress/high_quality` is enabled.
- `compress/lossy_quality: float` = `0.7` — The quality to use when using the Lossy compression mode.
- `compress/mode: int` = `1` — The compression mode to use.
- `compress/rdo_quality_loss: float` = `0.0` — If greater than or equal to `0.01`, enables Rate-Distortion Optimization (RDO) to reduce file size.
- `compress/uastc_level: int` = `0` — The UASTC encoding level.
- `mipmaps/generate: bool` = `true` — If `true`, smaller versions of the texture are generated on import.
- `mipmaps/limit: int` = `-1` — Unimplemented.
- `slices/arrangement: int` = `1` — Controls how the cubemap's texture is internally laid out.
