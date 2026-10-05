# AudioEffectFilter

**Inherits:** AudioEffect

Base class for filters. Use effects that inherit this class instead of using it directly.

A "filter" controls the gain of frequencies, using `cutoff_hz` as a frequency threshold. Filters can help to give room for each sound, and create interesting effects. There are different types of filter that inherit this class: Shelf filters: AudioEffectLowShelfFilter and AudioEffectHighShelfFilter Band-pass and notch filters: AudioEffectBandPassFilter, AudioEffectBandLimitFilter, and AudioEffectNotchFilter Low/high-pass filters: AudioEffectLowPassFilter and AudioEffectHighPassFilter

## Properties

- `cutoff_hz: float` = `2000.0` — Frequency threshold for the filter, in Hz.
- `db: AudioEffectFilter.FilterDB` = `0` — Steepness of the cutoff curve in dB per octave (twice the frequency above `cutoff_hz`, or half the frequency below `cutoff_hz`), also known as the "order" of the filter.
- `gain: float` = `1.0` — Gain of the frequencies affected by the filter.
- `resonance: float` = `0.5` — Gain at or directly next to the `cutoff_hz` frequency threshold.

## Enum FilterDB

- `FILTER_6DB = 0` — Cutting off at 6 dB per octave.
- `FILTER_12DB = 1` — Cutting off at 12 dB per octave.
- `FILTER_18DB = 2` — Cutting off at 18 dB per octave.
- `FILTER_24DB = 3` — Cutting off at 24 dB per octave.
