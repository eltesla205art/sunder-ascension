# VisualShaderNodeGroup

**Inherits:** VisualShaderNode

A visual shader node that instances a VisualShaderGroup.

Represents a VisualShaderGroup inside a VisualShader or another VisualShaderGroup. Its input and output ports are defined by the assigned `group` resource. If the group contains nodes incompatible with the current shader context, the outputs will use default values and a warning will be shown.

## Properties

- `group: VisualShaderGroup` — The VisualShaderGroup resource instanced by this node.
