# VisualShaderNodeIntParameter

**Inherits:** VisualShaderNodeParameter

A visual shader node for shader parameter (uniform) of type int.

A VisualShaderNodeParameter of type int. Offers additional customization for range of accepted values.

## Properties

- `default_value: int` = `0` — Default value of this parameter, which will be used if not set externally.
- `default_value_enabled: bool` = `false` — If `true`, the node will have a custom default value.
- `enum_names: PackedStringArray` = `PackedStringArray()` — The names used for the enum select in the editor.
- `hint: VisualShaderNodeIntParameter.Hint` = `0` — Range hint of this node.
- `max: int` = `100` — The maximum value this parameter can take.
- `min: int` = `0` — The minimum value this parameter can take.
- `step: int` = `1` — The step between parameter's values.

## Enum Hint

- `HINT_NONE = 0` — The parameter will not constrain its value.
- `HINT_RANGE = 1` — The parameter's value must be within the specified `min`/`max` range.
- `HINT_RANGE_STEP = 2` — The parameter's value must be within the specified range, with the given `step` between values.
- `HINT_ENUM = 3` — The parameter uses an enum to associate preset values to names in the editor.
- `HINT_MAX = 4` — Represents the size of the `Hint` enum.
