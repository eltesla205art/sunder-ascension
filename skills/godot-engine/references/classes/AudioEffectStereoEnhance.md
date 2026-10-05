# AudioEffectStereoEnhance

**Inherits:** AudioEffect

Adds a stereo manipulation audio effect to an audio bus. Controls gain of the side channels, and widens the stereo image.

Adjusts gain of the left and right channels, and makes mono sounds stereo through phase shifting.

## Properties

- `pan_pullout: float` = `1.0` — Gain of the side channels, if they exist.
- `surround: float` = `0.0` — Widens the stereo image through phase shifting in conjunction with `time_pullout_ms`.
- `time_pullout_ms: float` = `0.0` — Widens the stereo image through phase shifting in conjunction with `surround`.
