# StreamedTexture2D

**Inherits:** Texture2D

A texture that supports dynamic mipmap streaming for optimized VRAM usage.

StreamedTexture2D is a texture type that supports dynamic mipmap streaming. When texture streaming is enabled in the Project Settings (`ProjectSettings.rendering/textures/streaming/enabled`), these textures can have their mipmap levels dynamically loaded and unloaded based on usage. The texture streaming system monitors which textures are visible in each frame and at what resolution they're being displayed. Textures that are far from the camera or not currently visible have their higher-resolution mipmap levels unloaded to save VRAM, while textures being displayed up close are loaded at higher resolutions.

## Properties

- `load_path: String` = `""` — The StreamedTexture2D's file path to a `.stex` file.
- `max_lod_override: int` = `0` — Overrides the maximum LOD (mipmap level) that can be loaded for this specific texture.
- `min_lod_override: int` = `0` — Overrides the minimum LOD (mipmap level) this texture starts at when loaded.
- `resource_local_to_scene: bool` = `false` — 

## Methods

- `load(path: String) -> int[Error]` — Loads the texture from the specified `path`.
