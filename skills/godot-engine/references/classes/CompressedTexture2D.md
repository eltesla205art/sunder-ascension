# CompressedTexture2D

**Inherits:** Texture2D

Texture with 2 dimensions, optionally compressed.

A texture that is loaded from a `.ctex` file. This file format is internal to Godot; it is created by importing other image formats with the import system. CompressedTexture2D can use one of 4 compression methods (including a lack of any compression): - Lossless (WebP or PNG, uncompressed on the GPU) - Lossy (WebP, uncompressed on the GPU) - VRAM Compressed (compressed on the GPU) - VRAM Uncompressed (uncompressed on the GPU) - Basis Universal (compressed on the GPU. Lower file sizes than VRAM Compressed, but slower to compress and lower quality than VRAM Compressed) Only VRAM Compressed actually reduces the memory usage on the GPU.

## Properties

- `load_path: String` = `""` — The CompressedTexture2D's file path to a `.ctex` file.
- `resource_local_to_scene: bool` = `false` — 

## Methods

- `load(path: String) -> int[Error]` — Loads the texture from the specified `path`.
