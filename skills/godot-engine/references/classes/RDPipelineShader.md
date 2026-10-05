# RDPipelineShader

**Inherits:** RefCounted

Pipeline shader (used by RenderingDevice).

Wraps a shader resource and allows specialization constants to be applied at pipeline creation time. Used by `RenderingDevice.raytracing_pipeline_create` for ray generation, miss, and hit shaders. The pipeline selects the required shader stage automatically.

## Properties

- `shader: RID` = `RID()` — Shader resource.
- `specialization_constants: RDPipelineSpecializationConstant[]` = `[]` — Specialization constants applied to the selected shader stage at pipeline creation time.
