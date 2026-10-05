# VisualShaderNodeBillboard

**Inherits:** VisualShaderNode

A node that controls how the object faces the camera to be used within the visual shader graph.

The output port of this node needs to be connected to `Model View Matrix` port of VisualShaderNodeOutput.

## Properties

- `billboard_type: VisualShaderNodeBillboard.BillboardType` = `1` — Controls how the object faces the camera.
- `keep_scale: bool` = `false` — If `true`, the shader will keep the scale set for the mesh.

## Enum BillboardType

- `BILLBOARD_TYPE_DISABLED = 0` — Billboarding is disabled and the node does nothing.
- `BILLBOARD_TYPE_ENABLED = 1` — A standard billboarding algorithm is enabled.
- `BILLBOARD_TYPE_FIXED_Y = 2` — A billboarding algorithm to rotate around Y-axis is enabled.
- `BILLBOARD_TYPE_PARTICLES = 3` — A billboarding algorithm designed to use on particles is enabled.
- `BILLBOARD_TYPE_MAX = 4` — Represents the size of the `BillboardType` enum.
