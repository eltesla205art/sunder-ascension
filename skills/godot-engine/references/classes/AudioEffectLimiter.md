# AudioEffectLimiter

**Inherits:** AudioEffect
**Deprecated:** Use AudioEffectHardLimiter instead.

Adds a soft-clip limiter audio effect to an audio bus.

A "limiter" is an audio effect designed to stop audio signals from exceeding a specified volume threshold level, and usually works by decreasing the volume or soft-clipping the audio. Adding one in the Master bus is always recommended to prevent clipping when the volume goes above 0 dB. Soft clipping starts to decrease the peaks a little below the volume threshold level and progressively increases its effect as the input volume increases such that the threshold level is never exceeded. If hard clipping is desired, consider `AudioEffectDistortion.MODE_CLIP`.

## Properties

- `ceiling_db: float` = `-0.1` — The waveform's maximum allowed value, in dB.
- `soft_clip_db: float` = `2.0` — Modifies the volume of the limited waves, in dB.
- `soft_clip_ratio: float` = `10.0` — This property has no effect on the audio.
- `threshold_db: float` = `0.0` — The volume threshold level from which the limiter begins to be active, in dB.
