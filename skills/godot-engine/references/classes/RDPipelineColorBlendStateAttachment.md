# RDPipelineColorBlendStateAttachment

**Inherits:** RefCounted

Pipeline color blend state attachment (used by RenderingDevice).

Controls how blending between source and destination fragments is performed when using RenderingDevice. For reference, this is how common user-facing blend modes are implemented in Godot's 2D renderer: Mix:  Add:  Subtract:  Multiply:  Pre-multiplied alpha:

## Properties

- `alpha_blend_op: RenderingDevice.BlendOperation` = `0` — The blend mode to use for the alpha channel.
- `color_blend_op: RenderingDevice.BlendOperation` = `0` — The blend mode to use for the red/green/blue color channels.
- `dst_alpha_blend_factor: RenderingDevice.BlendFactor` = `0` — Controls how the blend factor for the alpha channel is determined based on the destination's fragments.
- `dst_color_blend_factor: RenderingDevice.BlendFactor` = `0` — Controls how the blend factor for the color channels is determined based on the destination's fragments.
- `enable_blend: bool` = `false` — If `true`, performs blending between the source and destination according to the factors defined in `src_color_blend_factor`, `dst_color_blend_factor`, `src_alpha_blend_factor` and `dst_alpha_blend_factor`.
- `src_alpha_blend_factor: RenderingDevice.BlendFactor` = `0` — Controls how the blend factor for the alpha channel is determined based on the source's fragments.
- `src_color_blend_factor: RenderingDevice.BlendFactor` = `0` — Controls how the blend factor for the color channels is determined based on the source's fragments.
- `write_a: bool` = `true` — If `true`, writes the new alpha channel to the final result.
- `write_b: bool` = `true` — If `true`, writes the new blue color channel to the final result.
- `write_g: bool` = `true` — If `true`, writes the new green color channel to the final result.
- `write_r: bool` = `true` — If `true`, writes the new red color channel to the final result.

## Methods

- `set_as_mix() -> void` — Convenience method to perform standard mix blending with straight (non-premultiplied) alpha.
