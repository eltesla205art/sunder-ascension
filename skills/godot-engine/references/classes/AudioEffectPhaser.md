# AudioEffectPhaser

**Inherits:** AudioEffect

Adds a phaser audio effect to an audio bus. Creates several notch and peak filters that sweep across the spectrum.

A "phaser" effect creates a copy of the original audio that phase-rotates differently across the entire frequency spectrum, with the use of a series of all-pass filter stages (6 in this effect). This copy modulates with a low-frequency oscillator and combines with the original audio, resulting in peaks and troughs that sweep across the spectrum. This effect can be used to create a "glassy" or "bubbly" sound.

## Properties

- `depth: float` = `1.0` — Intensity of the effect.
- `feedback: float` = `0.7` — The volume ratio of the filtered audio that is fed back to the all-pass filters.
- `range_max_hz: float` = `1600.0` — Determines the maximum frequency affected by the low-frequency oscillator modulations, in Hz.
- `range_min_hz: float` = `440.0` — Determines the minimum frequency affected by the low-frequency oscillator modulations, in Hz.
- `rate_hz: float` = `0.5` — Adjusts the rate in Hz at which the effect sweeps up and down across the frequency range.
