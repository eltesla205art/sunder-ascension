# RDPipelineDepthStencilState

**Inherits:** RefCounted

Pipeline depth/stencil state (used by RenderingDevice).

RDPipelineDepthStencilState controls the way depth and stencil comparisons are performed when sampling those values using RenderingDevice.

## Properties

- `back_op_compare: RenderingDevice.CompareOperator` = `7` — The method used for comparing the previous back stencil value and `back_op_reference`.
- `back_op_compare_mask: int` = `0` — Selects which bits from the back stencil value will be compared.
- `back_op_depth_fail: RenderingDevice.StencilOperation` = `1` — The operation to perform on the stencil buffer for back pixels that pass the stencil test but fail the depth test.
- `back_op_fail: RenderingDevice.StencilOperation` = `1` — The operation to perform on the stencil buffer for back pixels that fail the stencil test.
- `back_op_pass: RenderingDevice.StencilOperation` = `1` — The operation to perform on the stencil buffer for back pixels that pass the stencil test.
- `back_op_reference: int` = `0` — The value the previous back stencil value will be compared to.
- `back_op_write_mask: int` = `0` — Selects which bits from the back stencil value will be changed.
- `depth_compare_operator: RenderingDevice.CompareOperator` = `7` — The method used for comparing the previous and current depth values.
- `depth_range_max: float` = `0.0` — The maximum depth that returns `true` for `enable_depth_range`.
- `depth_range_min: float` = `0.0` — The minimum depth that returns `true` for `enable_depth_range`.
- `enable_depth_range: bool` = `false` — If `true`, each depth value will be tested to see if it is between `depth_range_min` and `depth_range_max`.
- `enable_depth_test: bool` = `false` — If `true`, enables depth testing which allows objects to be automatically occluded by other objects based on their depth.
- `enable_depth_write: bool` = `false` — If `true`, writes to the depth buffer whenever the depth test returns `true`.
- `enable_stencil: bool` = `false` — If `true`, enables stencil testing.
- `front_op_compare: RenderingDevice.CompareOperator` = `7` — The method used for comparing the previous front stencil value and `front_op_reference`.
- `front_op_compare_mask: int` = `0` — Selects which bits from the front stencil value will be compared.
- `front_op_depth_fail: RenderingDevice.StencilOperation` = `1` — The operation to perform on the stencil buffer for front pixels that pass the stencil test but fail the depth test.
- `front_op_fail: RenderingDevice.StencilOperation` = `1` — The operation to perform on the stencil buffer for front pixels that fail the stencil test.
- `front_op_pass: RenderingDevice.StencilOperation` = `1` — The operation to perform on the stencil buffer for front pixels that pass the stencil test.
- `front_op_reference: int` = `0` — The value the previous front stencil value will be compared to.
- `front_op_write_mask: int` = `0` — Selects which bits from the front stencil value will be changed.
