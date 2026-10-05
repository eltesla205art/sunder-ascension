# VisualShaderNodeColorConstant

**Inherits:** VisualShaderNodeConstant

A Color constant to be used within the visual shader graph.

Has two output ports representing RGB and alpha channels of Color. Translated to `vec3 rgb` and `float alpha` in the shader language.

## Properties

- `constant: Color` = `Color(1, 1, 1, 1)` — A Color constant which represents a state of this node.
