# CanvasTexture

**Inherits:** Texture2D

Texture with optional normal and specular maps for use in 2D rendering.

CanvasTexture is an alternative to ImageTexture for 2D rendering. It allows using normal maps and specular maps in any node that inherits from CanvasItem. CanvasTexture also allows overriding the texture's filter and repeat mode independently of the node's properties (or the project settings). Note: CanvasTexture cannot be used in 3D.

## Properties

- `diffuse_texture: Texture2D` — The diffuse (color) texture to use.
- `normal_texture: Texture2D` — The normal map texture to use.
- `resource_local_to_scene: bool` = `false` — 
- `specular_color: Color` = `Color(1, 1, 1, 1)` — The multiplier for specular reflection colors.
- `specular_shininess: float` = `1.0` — The specular exponent for Light2D specular reflections.
- `specular_texture: Texture2D` — The specular map to use for Light2D specular reflections.
- `texture_filter: CanvasItem.TextureFilter` = `0` — The texture filtering mode to use when drawing this CanvasTexture.
- `texture_repeat: CanvasItem.TextureRepeat` = `0` — The texture repeat mode to use when drawing this CanvasTexture.
