# RDPipelineColorBlendState

**Inherits:** RefCounted

Pipeline color blend state (used by RenderingDevice).

This object is used by RenderingDevice.

## Properties

- `attachments: RDPipelineColorBlendStateAttachment[]` = `[]` — The attachments that are blended together.
- `blend_constant: Color` = `Color(0, 0, 0, 1)` — The constant color to blend with.
- `enable_logic_op: bool` = `false` — If `true`, performs the logic operation defined in `logic_op`.
- `logic_op: RenderingDevice.LogicOperation` = `0` — The logic operation to perform for blending.
