# TextureStreaming

**Inherits:** Object

Manages dynamic texture mipmap streaming to optimize VRAM usage.

The TextureStreaming singleton manages dynamic loading and unloading of texture mipmap levels based on what is visible in the current frame. This allows projects with many large textures to significantly reduce VRAM usage while maintaining visual quality for visible textures. Texture streaming works by analyzing shader feedback to determine which textures are actively being used and at what resolution they're being displayed. Textures that are far from the camera or not currently visible have their higher-resolution mipmap levels unloaded, while textures being displayed up close are loaded at higher resolutions.

## Properties

- `max_lod_override: int` = `-1` — Overrides the maximum LOD (mipmap level) that can be loaded for streamed textures at runtime.
- `memory_budget_mb_override: int` = `4294967295` — Overrides the memory budget for streamed textures at runtime (in megabytes).
- `min_lod_override: int` = `-1` — Overrides the minimum LOD (mipmap level) that textures start at when loaded.

## Methods

- `flush_texture_streaming() -> void` — Forces all currently queued texture streaming operations to complete immediately, bypassing the normal gradual transition and I/O throttling.
- `get_memory_budget_bytes_used() -> int` — Returns the current VRAM usage of streamed textures in bytes.

## Signals

- `flush_completed()` — Emitted when a texture streaming flush operation finishes, after `flush_texture_streaming` has been called and all managed textures have reached their target resolutions.
