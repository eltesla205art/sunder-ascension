# OpenXRHapticVibration

**Inherits:** OpenXRHapticBase

Vibration haptic feedback.

This haptic feedback resource makes it possible to define a vibration based haptic feedback pulse that can be triggered through actions in the OpenXR action map.

## Properties

- `amplitude: float` = `1.0` — The amplitude of the pulse between `0.0` and `1.0`.
- `duration: int` = `-1` — The duration of the pulse in nanoseconds.
- `frequency: float` = `0.0` — The frequency of the pulse in Hz.
