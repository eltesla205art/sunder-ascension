# VisualShaderNodeVarying

**Inherits:** VisualShaderNode

A visual shader node that represents a "varying" shader value.

Varying values are shader variables that can be passed between shader functions, e.g. from Vertex shader to Fragment shader.

## Properties

- `varying_name: String` = `"[None]"` — Name of the variable.
- `varying_type: VisualShader.VaryingType` = `0` — Type of the variable.
