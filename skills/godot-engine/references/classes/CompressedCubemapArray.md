# CompressedCubemapArray

**Inherits:** CompressedTextureLayered

An optionally compressed CubemapArray.

A cubemap array that is loaded from a `.ccubearray` file. This file format is internal to Godot; it is created by importing other image formats with the import system. CompressedCubemapArray can use one of 4 compression methods: - Lossless (WebP or PNG, uncompressed on the GPU) - Lossy (WebP, uncompressed on the GPU) - VRAM Compressed (compressed on the GPU) - VRAM Uncompressed (uncompressed on the GPU) - Basis Universal (compressed on the GPU. Lower file sizes than VRAM Compressed, but slower to compress and lower quality than VRAM Compressed) Only VRAM Compressed actually reduces the memory usage on the GPU.
