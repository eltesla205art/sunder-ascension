# CompressedTexture3D

**Inherits:** Texture3D

Texture with 3 dimensions, optionally compressed.

CompressedTexture3D is the VRAM-compressed counterpart of ImageTexture3D. The file extension for CompressedTexture3D files is `.ctex3d`. This file format is internal to Godot; it is created by importing other image formats with the import system. CompressedTexture3D uses VRAM compression, which allows to reduce memory usage on the GPU when rendering the texture.

## Properties

- `load_path: String` = `""` — The CompressedTexture3D's file path to a `.ctex3d` file.

## Methods

- `load(path: String) -> int[Error]` — Loads the texture from the specified `path`.
