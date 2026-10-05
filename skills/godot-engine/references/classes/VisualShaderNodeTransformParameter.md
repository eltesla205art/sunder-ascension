# VisualShaderNodeTransformParameter

**Inherits:** VisualShaderNodeParameter

A Transform3D parameter for use within the visual shader graph.

Translated to `uniform mat4` in the shader language.

## Properties

- `default_value: Transform3D` = `Transform3D(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)` — A default value to be assigned within the shader.
- `default_value_enabled: bool` = `false` — Enables usage of the `default_value`.
