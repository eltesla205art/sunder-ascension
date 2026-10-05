# CompositorEffect

**Inherits:** Resource

This resource allows for creating a custom rendering effect.

This resource defines a custom rendering effect that can be applied to Viewports through the viewports' Environment. You can implement a callback that is called during rendering at a given stage of the rendering pipeline and allows you to insert additional passes. Note that this callback happens on the rendering thread. CompositorEffect is an abstract base class and must be extended to implement specific rendering logic.

## Properties

- `access_resolved_color: bool` — If `true` and MSAA is enabled, this will trigger a color buffer resolve before the effect is run.
- `access_resolved_depth: bool` — If `true` and MSAA is enabled, this will trigger a depth buffer resolve before the effect is run.
- `effect_callback_type: CompositorEffect.EffectCallbackType` — The type of effect that is implemented, determines at what stage of rendering the callback is called.
- `enabled: bool` — If `true` this rendering effect is applied to any viewport it is added to.
- `needs_motion_vectors: bool` — If `true` this triggers motion vectors being calculated during the opaque render state.
- `needs_normal_roughness: bool` — If `true` this triggers normal and roughness data to be output during our depth pre-pass, only applicable for the Forward+ renderer.
- `needs_separate_specular: bool` — If `true` this triggers specular data being rendered to a separate buffer and combined after effects have been applied, only applicable for the Forward+ renderer.

## Methods

- `_render_callback(effect_callback_type: int, render_data: RenderData) -> void` *virtual* — Implement this function with your custom rendering code.

## Enum EffectCallbackType

- `EFFECT_CALLBACK_TYPE_PRE_OPAQUE = 0` — The callback is called before our opaque rendering pass, but after depth prepass (if applicable).
- `EFFECT_CALLBACK_TYPE_POST_OPAQUE = 1` — The callback is called after our opaque rendering pass, but before our sky is rendered.
- `EFFECT_CALLBACK_TYPE_POST_SKY = 2` — The callback is called after our sky is rendered, but before our back buffers are created (and if enabled, before subsurface scattering and/or screen space reflections).
- `EFFECT_CALLBACK_TYPE_PRE_TRANSPARENT = 3` — The callback is called before our transparent rendering pass, but after our sky is rendered and we've created our back buffers.
- `EFFECT_CALLBACK_TYPE_POST_TRANSPARENT = 4` — The callback is called after our transparent rendering pass, but before any built-in post-processing effects and output to our render target.
- `EFFECT_CALLBACK_TYPE_MAX = 5` — Represents the size of the `EffectCallbackType` enum.
