# Light2D

**Inherits:** Node2D

Casts light in a 2D environment.

Casts light in a 2D environment. A light is defined as a color, an energy value, a mode (see constants), and various other parameters (range and shadows-related).

## Properties

- `blend_mode: Light2D.BlendMode` = `0` — The Light2D's blend mode.
- `color: Color` = `Color(1, 1, 1, 1)` — The Light2D's Color.
- `editor_only: bool` = `false` — If `true`, Light2D will only appear when editing the scene.
- `enabled: bool` = `true` — If `true`, Light2D will emit light.
- `energy: float` = `1.0` — The Light2D's energy value.
- `range_item_cull_mask: int` = `1` — The layer mask.
- `range_layer_max: int` = `0` — Maximum layer value of objects that are affected by the Light2D.
- `range_layer_min: int` = `0` — Minimum layer value of objects that are affected by the Light2D.
- `range_z_max: int` = `1024` — Maximum `z` value of objects that are affected by the Light2D.
- `range_z_min: int` = `-1024` — Minimum `z` value of objects that are affected by the Light2D.
- `shadow_color: Color` = `Color(0, 0, 0, 0)` — Color of shadows cast by the Light2D.
- `shadow_enabled: bool` = `false` — If `true`, the Light2D will cast shadows.
- `shadow_filter: Light2D.ShadowFilter` = `0` — Shadow filter type.
- `shadow_filter_smooth: float` = `0.0` — Smoothing value for shadows.
- `shadow_item_cull_mask: int` = `1` — The shadow mask.

## Methods

- `get_height() -> float` *const* — Returns the light's height, which is used in 2D normal mapping.
- `set_height(height: float) -> void` — Sets the light's height, which is used in 2D normal mapping.

## Enum ShadowFilter

- `SHADOW_FILTER_NONE = 0` — No filter applies to the shadow map.
- `SHADOW_FILTER_PCF5 = 1` — Percentage closer filtering (5 samples) applies to the shadow map.
- `SHADOW_FILTER_PCF13 = 2` — Percentage closer filtering (13 samples) applies to the shadow map.

## Enum BlendMode

- `BLEND_MODE_ADD = 0` — Adds the value of pixels corresponding to the Light2D to the values of pixels under it.
- `BLEND_MODE_SUB = 1` — Subtracts the value of pixels corresponding to the Light2D to the values of pixels under it, resulting in inversed light effect.
- `BLEND_MODE_MIX = 2` — Mix the value of pixels corresponding to the Light2D to the values of pixels under it by linear interpolation.
