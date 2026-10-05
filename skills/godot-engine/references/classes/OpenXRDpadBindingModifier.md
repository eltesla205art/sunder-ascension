# OpenXRDpadBindingModifier

**Inherits:** OpenXRIPBindingModifier

The DPad binding modifier converts an axis input to a dpad output.

The DPad binding modifier converts an axis input to a dpad output, emulating a DPad. New input paths for each dpad direction will be added to the interaction profile. When bound to actions the DPad emulation will be activated. You should not combine dpad inputs with normal inputs in the same action set for the same control, this will result in an error being returned when suggested bindings are submitted to OpenXR.

## Properties

- `action_set: OpenXRActionSet` — Action set for which this dpad binding modifier is active.
- `center_region: float` = `0.1` — Center region in which our center position of our dpad return `true`.
- `input_path: String` = `""` — Input path for this dpad binding modifier.
- `is_sticky: bool` = `false` — If `false`, when the joystick enters a new dpad zone this becomes `true`.
- `off_haptic: OpenXRHapticBase` — Haptic pulse to emit when the user releases the input.
- `on_haptic: OpenXRHapticBase` — Haptic pulse to emit when the user presses the input.
- `threshold: float` = `0.6` — When our input value is equal or larger than this value, our dpad in that direction becomes `true`.
- `threshold_released: float` = `0.4` — When our input value falls below this, our output becomes `false`.
- `wedge_angle: float` = `1.5707964` — The angle of each wedge that identifies the 4 directions of the emulated dpad.
