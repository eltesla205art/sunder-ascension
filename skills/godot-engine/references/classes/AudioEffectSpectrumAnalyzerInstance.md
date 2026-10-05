# AudioEffectSpectrumAnalyzerInstance

**Inherits:** AudioEffectInstance

Queryable instance of an AudioEffectSpectrumAnalyzer.

The runtime part of an AudioEffectSpectrumAnalyzer, which can be used to query the magnitude of a frequency range on its host bus. An instance of this class can be obtained with `AudioServer.get_bus_effect_instance`.

## Methods

- `get_magnitude_for_frequency_range(from_hz: float, to_hz: float, mode: AudioEffectSpectrumAnalyzerInstance.MagnitudeMode = 1) -> Vector2` *const* — Returns the magnitude of the frequencies from `from_hz` to `to_hz` in linear energy as a Vector2.

## Enum MagnitudeMode

- `MAGNITUDE_AVERAGE = 0` — Use the average value across the frequency range as magnitude.
- `MAGNITUDE_MAX = 1` — Use the maximum value of the frequency range as magnitude.
