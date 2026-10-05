# AudioEffectChorus

**Inherits:** AudioEffect

Adds a chorus audio effect to an audio bus. Gives the impression of multiple audio sources.

A "chorus" effect creates multiple copies of the original audio (called "voices") with variations in pitch, and layers on top of the original, giving the impression that the sound comes from multiple sources. This creates spectral and spatial movement. Each voice is played a short period of time after the original audio, controlled by `delay`. An internal low-frequency oscillator (LFO) controls their pitch, and `depth` controls the LFO's maximum amount.

## Properties

- `dry: float` = `1.0` — The volume ratio of the original audio.
- `voice/1/cutoff_hz: float` = `8000.0` — The frequency threshold of the voice's low-pass filter in Hz.
- `voice/1/delay_ms: float` = `15.0` — The delay of the voice in milliseconds, compared to the original audio.
- `voice/1/depth_ms: float` = `2.0` — The depth of the voice's low-frequency oscillator in milliseconds.
- `voice/1/level_db: float` = `0.0` — The gain of the voice in dB.
- `voice/1/pan: float` = `-0.5` — The pan position of the voice.
- `voice/1/rate_hz: float` = `0.8` — The rate of the voice's low-frequency oscillator in Hz.
- `voice/2/cutoff_hz: float` = `8000.0` — The frequency threshold of the voice's low-pass filter in Hz.
- `voice/2/delay_ms: float` = `20.0` — The delay of the voice in milliseconds, compared to the original audio.
- `voice/2/depth_ms: float` = `3.0` — The depth of the voice's low-frequency oscillator in milliseconds.
- `voice/2/level_db: float` = `0.0` — The gain of the voice in dB.
- `voice/2/pan: float` = `0.5` — The pan position of the voice.
- `voice/2/rate_hz: float` = `1.2` — The rate of the voice's low-frequency oscillator in Hz.
- `voice/3/cutoff_hz: float` — The frequency threshold of the voice's low-pass filter in Hz.
- `voice/3/delay_ms: float` — The delay of the voice in milliseconds, compared to the original audio.
- `voice/3/depth_ms: float` — The depth of the voice's low-frequency oscillator in milliseconds.
- `voice/3/level_db: float` — The gain of the voice in dB.
- `voice/3/pan: float` — The pan position of the voice.
- `voice/3/rate_hz: float` — The rate of the voice's low-frequency oscillator in Hz.
- `voice/4/cutoff_hz: float` — The frequency threshold of the voice's low-pass filter in Hz.
- `voice/4/delay_ms: float` — The delay of the voice in milliseconds, compared to the original audio.
- `voice/4/depth_ms: float` — The depth of the voice's low-frequency oscillator in milliseconds.
- `voice/4/level_db: float` — The gain of the voice in dB.
- `voice/4/pan: float` — The pan position of the voice.
- `voice/4/rate_hz: float` — The rate of the voice's low-frequency oscillator in Hz.
- `voice_count: int` = `2` — The number of voices in the effect.
- `wet: float` = `0.5` — The volume ratio of all voices.

## Methods

- `get_voice_cutoff_hz(voice_idx: int) -> float` *const* — Returns the frequency threshold of a given `voice_idx`'s low-pass filter in Hz.
- `get_voice_delay_ms(voice_idx: int) -> float` *const* — Returns the delay of a given `voice_idx` in milliseconds, compared to the original audio.
- `get_voice_depth_ms(voice_idx: int) -> float` *const* — Returns the depth of a given `voice_idx`'s low-frequency oscillator in milliseconds.
- `get_voice_level_db(voice_idx: int) -> float` *const* — Returns the gain of a given `voice_idx` in dB.
- `get_voice_pan(voice_idx: int) -> float` *const* — Returns the pan position of a given `voice_idx`.
- `get_voice_rate_hz(voice_idx: int) -> float` *const* — Returns the rate of a given `voice_idx`'s low-frequency oscillator in Hz.
- `set_voice_cutoff_hz(voice_idx: int, cutoff_hz: float) -> void` — Sets the frequency threshold of a given `voice_idx`'s low-pass filter in Hz.
- `set_voice_delay_ms(voice_idx: int, delay_ms: float) -> void` — Sets the delay of a given `voice_idx` in milliseconds, compared to the original audio.
- `set_voice_depth_ms(voice_idx: int, depth_ms: float) -> void` — Sets the depth of a given `voice_idx`'s low-frequency oscillator in milliseconds.
- `set_voice_level_db(voice_idx: int, level_db: float) -> void` — Sets the gain of a given `voice_idx` in dB.
- `set_voice_pan(voice_idx: int, pan: float) -> void` — Sets the pan position of a given `voice_idx`.
- `set_voice_rate_hz(voice_idx: int, rate_hz: float) -> void` — Sets the rate of a given `voice_idx`'s low-frequency oscillator in Hz.
