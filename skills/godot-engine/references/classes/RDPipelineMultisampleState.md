# RDPipelineMultisampleState

**Inherits:** RefCounted

Pipeline multisample state (used by RenderingDevice).

RDPipelineMultisampleState is used to control how multisample or supersample antialiasing is being performed when rendering using RenderingDevice.

## Properties

- `enable_alpha_to_coverage: bool` = `false` — If `true`, alpha to coverage is enabled.
- `enable_alpha_to_one: bool` = `false` — If `true`, alpha is forced to either `0.0` or `1.0`.
- `enable_sample_shading: bool` = `false` — If `true`, enables per-sample shading which replaces MSAA by SSAA.
- `min_sample_shading: float` = `0.0` — The multiplier of `sample_count` that determines how many samples are performed for each fragment.
- `sample_count: RenderingDevice.TextureSamples` = `0` — The number of MSAA samples (or SSAA samples if `enable_sample_shading` is `true`) to perform.
- `sample_masks: int[]` = `[]` — The sample mask array.
