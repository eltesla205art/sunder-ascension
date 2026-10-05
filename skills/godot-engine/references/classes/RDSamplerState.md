# RDSamplerState

**Inherits:** RefCounted

Sampler state (used by RenderingDevice).

This object is used by RenderingDevice.

## Properties

- `anisotropy_max: float` = `1.0` — Maximum anisotropy that can be used when sampling.
- `border_color: RenderingDevice.SamplerBorderColor` = `2` — The border color that will be returned when sampling outside the sampler's bounds and the `repeat_u`, `repeat_v` or `repeat_w` modes have repeating disabled.
- `compare_op: RenderingDevice.CompareOperator` = `7` — The compare operation to use.
- `enable_compare: bool` = `false` — If `true`, returned values will be based on the comparison operation defined in `compare_op`.
- `lod_bias: float` = `0.0` — The mipmap LOD bias to use.
- `mag_filter: RenderingDevice.SamplerFilter` = `0` — The sampler's magnification filter.
- `max_lod: float` = `1e+20` — The maximum mipmap LOD bias to display (lowest resolution).
- `min_filter: RenderingDevice.SamplerFilter` = `0` — The sampler's minification filter.
- `min_lod: float` = `0.0` — The minimum mipmap LOD bias to display (highest resolution).
- `mip_filter: RenderingDevice.SamplerFilter` = `0` — The filtering method to use for mipmaps.
- `repeat_u: RenderingDevice.SamplerRepeatMode` = `2` — The repeat mode to use along the U axis of UV coordinates.
- `repeat_v: RenderingDevice.SamplerRepeatMode` = `2` — The repeat mode to use along the V axis of UV coordinates.
- `repeat_w: RenderingDevice.SamplerRepeatMode` = `2` — The repeat mode to use along the W axis of UV coordinates.
- `unnormalized_uvw: bool` = `false` — If `true`, the texture will be sampled with coordinates ranging from 0 to the texture's resolution.
- `use_anisotropy: bool` = `false` — If `true`, perform anisotropic sampling.
