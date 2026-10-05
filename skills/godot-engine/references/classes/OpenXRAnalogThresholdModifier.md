# OpenXRAnalogThresholdModifier

**Inherits:** OpenXRActionBindingModifier

The analog threshold binding modifier can modify a float input to a boolean input with specified thresholds.

The analog threshold binding modifier can modify a float input to a boolean input with specified thresholds. See XR_VALVE_analog_threshold for in-depth details.

## Properties

- `off_haptic: OpenXRHapticBase` — Haptic pulse to emit when the user releases the input.
- `off_threshold: float` = `0.4` — When our input value falls below this, our output becomes `false`.
- `on_haptic: OpenXRHapticBase` — Haptic pulse to emit when the user presses the input.
- `on_threshold: float` = `0.6` — When our input value is equal or larger than this value, our output becomes `true`.
