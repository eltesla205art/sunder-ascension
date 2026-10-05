# VisualShaderNodeFloatParameter

**Inherits:** VisualShaderNodeParameter

A scalar float parameter to be used within the visual shader graph.

Translated to `uniform float` in the shader language.

## Properties

- `default_value: float` = `0.0` — A default value to be assigned within the shader.
- `default_value_enabled: bool` = `false` — Enables usage of the `default_value`.
- `hint: VisualShaderNodeFloatParameter.Hint` = `0` — A hint applied to the uniform, which controls the values it can take when set through the Inspector.
- `max: float` = `1.0` — Minimum value for range hints.
- `min: float` = `0.0` — Maximum value for range hints.
- `step: float` = `0.1` — Step (increment) value for the range hint with step.

## Enum Hint

- `HINT_NONE = 0` — No hint used.
- `HINT_RANGE = 1` — A range hint for scalar value, which limits possible input values between `min` and `max`.
- `HINT_RANGE_STEP = 2` — A range hint for scalar value with step, which limits possible input values between `min` and `max`, with a step (increment) of `step`).
- `HINT_MAX = 3` — Represents the size of the `Hint` enum.
