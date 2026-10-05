# ShaderMaterial

**Inherits:** Material

A material defined by a custom Shader program and the values of its shader parameters.

A material that uses a custom Shader program to render visual items (canvas items, meshes, skies, fog), or to process particles. Compared to other materials, ShaderMaterial gives deeper control over the generated shader code. For more information, see the shaders documentation index below. Multiple ShaderMaterials can use the same shader and configure different values for the shader uniforms.

## Properties

- `shader: Shader` — The Shader program used to render this material.

## Methods

- `get_shader_parameter(param: StringName) -> Variant` *const* — Returns the current value set for this material of a uniform in the shader.
- `set_shader_parameter(param: StringName, value: Variant) -> void` — Changes the value set for this material of a uniform in the shader.
