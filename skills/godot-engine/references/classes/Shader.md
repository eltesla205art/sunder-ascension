# Shader

**Inherits:** Resource

A shader implemented in the Godot shading language.

A custom shader program implemented in the Godot shading language, saved with the `.gdshader` extension. This class is used by a ShaderMaterial and allows you to write your own custom behavior for rendering visual items or updating particle information. For a detailed explanation and usage, please see the tutorials linked below.

## Properties

- `code: String` = `""` — Returns the shader's code as the user has written it, not the full generated code used internally.

## Methods

- `get_default_texture_parameter(name: StringName, index: int = 0) -> Texture` *const* — Returns the texture that is set as default for the specified parameter.
- `get_mode() -> int[Shader.Mode]` *const* — Returns the shader mode for the shader.
- `get_shader_uniform_list(get_groups: bool = false) -> Array` — Returns the list of shader uniforms that can be assigned to a ShaderMaterial, for use with `ShaderMaterial.set_shader_parameter` and `ShaderMaterial.get_shader_parameter`.
- `inspect_native_shader_code() -> void` — Only available when running in the editor.
- `set_default_texture_parameter(name: StringName, texture: Texture, index: int = 0) -> void` — Sets the default texture to be used with a texture uniform.
- `set_include_path(path: String) -> void` — Sets the include path for this shader.

## Enum Mode

- `MODE_SPATIAL = 0` — Mode used to draw all 3D objects.
- `MODE_CANVAS_ITEM = 1` — Mode used to draw all 2D objects.
- `MODE_PARTICLES = 2` — Mode used to calculate particle information on a per-particle basis.
- `MODE_SKY = 3` — Mode used for drawing skies.
- `MODE_FOG = 4` — Mode used for setting the color and density of volumetric fog effect.
- `MODE_TEXTURE_BLIT = 5` — Mode used for drawing to DrawableTexture resources via blit calls.
