# CompressedTexture2DArray

**Inherits:** CompressedTextureLayered

Array of 2-dimensional textures, optionally compressed.

A texture array that is loaded from a `.ctexarray` file. This file format is internal to Godot; it is created by importing other image formats with the import system. CompressedTexture2DArray can use one of 4 compression methods: - Lossless (WebP or PNG, uncompressed on the GPU) - Lossy (WebP, uncompressed on the GPU) - VRAM Compressed (compressed on the GPU) - VRAM Uncompressed (uncompressed on the GPU) - Basis Universal (compressed on the GPU. Lower file sizes than VRAM Compressed, but slower to compress and lower quality than VRAM Compressed) Only VRAM Compressed actually reduces the memory usage on the GPU.
