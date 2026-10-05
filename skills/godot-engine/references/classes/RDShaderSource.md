# RDShaderSource

**Inherits:** RefCounted

Shader source code (used by RenderingDevice).

Shader source code in text form. See also RDShaderFile. RDShaderSource is only meant to be used with the RenderingDevice API. It should not be confused with Godot's own Shader resource, which is what Godot's various nodes use for high-level shader programming.

## Properties

- `language: RenderingDevice.ShaderLanguage` = `0` — The language the shader is written in.
- `source_any_hit: String` = `""` — Source code for the shader's any hit stage.
- `source_closest_hit: String` = `""` — Source code for the shader's closest hit stage.
- `source_compute: String` = `""` — Source code for the shader's compute stage.
- `source_fragment: String` = `""` — Source code for the shader's fragment stage.
- `source_intersection: String` = `""` — Source code for the shader's intersection stage.
- `source_miss: String` = `""` — Source code for the shader's miss stage.
- `source_raygen: String` = `""` — Source code for the shader's ray generation stage.
- `source_tesselation_control: String` = `""` — Source code for the shader's tessellation control stage.
- `source_tesselation_evaluation: String` = `""` — Source code for the shader's tessellation evaluation stage.
- `source_vertex: String` = `""` — Source code for the shader's vertex stage.

## Methods

- `get_stage_source(stage: RenderingDevice.ShaderStage) -> String` *const* — Returns source code for the specified shader `stage`.
- `set_stage_source(stage: RenderingDevice.ShaderStage, source: String) -> void` — Sets `source` code for the specified shader `stage`.
