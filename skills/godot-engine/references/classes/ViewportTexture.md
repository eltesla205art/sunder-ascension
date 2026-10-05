# ViewportTexture

**Inherits:** Texture2D

Provides the content of a Viewport as a dynamic texture.

A ViewportTexture provides the content of a Viewport as a dynamic Texture2D. This can be used to combine the rendering of Control, Node2D and Node3D nodes. For example, you can use this texture to display a 3D scene inside a TextureRect, or a 2D overlay in a Sprite3D. To get a ViewportTexture in code, use the `Viewport.get_texture` method on the target viewport.

## Properties

- `viewport_path: NodePath` = `NodePath("")` — The path to the Viewport node to display.
