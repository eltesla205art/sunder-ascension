# AudioEffectEQ

**Inherits:** AudioEffect

Base class for audio equalizers (EQ). Gives you control over frequencies. Use it to create a custom equalizer if AudioEffectEQ6, AudioEffectEQ10, or AudioEffectEQ21 don't fit your needs.

An "equalizer" gives you control over the gain of frequencies in the entire spectrum, by allowing their adjustment through bands. A band is a point in the frequency spectrum, and each band means a division of the spectrum that can be adjusted. Use equalizers to compensate for existing deficiencies in the audio, make room for other elements, or remove undesirable frequencies. AudioEffectEQs are useful on the Master bus to balance the entire mix or give it more character.

## Methods

- `get_band_count() -> int` *const* — Returns the number of bands of the equalizer.
- `get_band_gain_db(band_idx: int) -> float` *const* — Returns the band's gain at the specified index, in dB.
- `set_band_gain_db(band_idx: int, volume_db: float) -> void` — Sets band's gain at the specified index, in dB.
