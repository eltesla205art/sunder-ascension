# GLTFSpecGloss

**Inherits:** Resource

Archived glTF extension for specular/glossy materials.

KHR_materials_pbrSpecularGlossiness is an archived glTF extension. This means that it is deprecated and not recommended for new files. However, it is still supported for loading old files.

## Properties

- `diffuse_factor: Color` = `Color(1, 1, 1, 1)` — The reflected diffuse factor of the material.
- `diffuse_img: Image` — The diffuse texture.
- `gloss_factor: float` = `1.0` — The glossiness or smoothness of the material.
- `spec_gloss_img: Image` — The specular-glossiness texture.
- `specular_factor: Color` = `Color(1, 1, 1, 1)` — The specular RGB color of the material.
