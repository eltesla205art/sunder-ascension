# AudioEffectHardLimiter

**Inherits:** AudioEffect

Adds a limiter audio effect to an audio bus. Prevents audio signals from exceeding a specified volume level.

A "limiter" disallows audio signals from exceeding a given volume threshold level in dB. Hard limiters predict volume peaks, and will smoothly apply gain reduction when a peak crosses the ceiling threshold level to prevent clipping. It preserves the waveform and prevents it from crossing the ceiling threshold level. Adding one in the Master bus is recommended as a safety measure to prevent sudden volume peaks from occurring, and to prevent distortion caused by clipping, when the volume exceeds 0 dB.

## Properties

- `ceiling_db: float` = `-0.3` — The waveform's maximum allowed value, in dB.
- `pre_gain_db: float` = `0.0` — Gain before limiting, in dB.
- `release: float` = `0.1` — Time it takes in seconds for the gain reduction to fully release.
