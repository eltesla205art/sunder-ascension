# ResourceImporterStreamedTexture

**Inherits:** ResourceImporter

Imports an image as a streaming-capable texture for dynamic mipmap loading.

This importer creates StreamedTexture2D resources that support dynamic mipmap streaming. When texture streaming is enabled in the Project Settings (`ProjectSettings.rendering/textures/streaming/enabled`), these textures can have their mipmap levels dynamically loaded and unloaded based on usage, significantly reducing VRAM consumption for projects with many large textures. The streaming system monitors which textures are visible in each frame and loads appropriate mipmap levels accordingly. Textures that are far from the camera or not currently visible have their higher-resolution mipmap levels unloaded, while textures being displayed up close are loaded at higher resolutions.

## Properties

- `compress/channel_pack: int` = `0` — Controls how color channels should be used in the imported texture. sRGB Friendly: Prevents the R and RG color formats from being used, as they do not support nonlinear sRGB encoding.
- `compress/hdr_compression: int` = `1` — Controls how VRAM compression should be performed for HDR images.
- `compress/high_quality: bool` = `false` — If `true`, uses BPTC compression on desktop platforms and ASTC compression on mobile platforms.
- `compress/normal_map: int` = `0` — When using a texture as normal map, only the red and green channels are required.
- `roughness/mode: int` = `0` — The color channel to consider as a roughness map in this texture.
- `roughness/src_normal: String` = `""` — The path to the texture to consider as a normal map for roughness filtering on import.
- `streaming/max_lod_override: int` = `0` — The maximum LOD (mipmap level) that can be loaded for this texture.
- `streaming/min_lod_override: int` = `0` — The minimum LOD (mipmap level) the texture starts at when loaded.
