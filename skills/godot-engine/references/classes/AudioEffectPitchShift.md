# AudioEffectPitchShift

**Inherits:** AudioEffect

Adds a pitch-shifting audio effect to an audio bus. Raises or lowers the pitch of the input audio.

Allows modulation of pitch without modifying speed. All frequencies can be raised or lowered with minimal effect on transients.

## Properties

- `fft_size: AudioEffectPitchShift.FFTSize` = `3` — The size of the Fast Fourier transform buffer.
- `oversampling: int` = `4` — The oversampling factor to use.
- `pitch_scale: float` = `1.0` — The pitch scale to use.

## Enum FFTSize

- `FFT_SIZE_256 = 0` — Use a buffer of 256 samples for the Fast Fourier transform.
- `FFT_SIZE_512 = 1` — Use a buffer of 512 samples for the Fast Fourier transform.
- `FFT_SIZE_1024 = 2` — Use a buffer of 1024 samples for the Fast Fourier transform.
- `FFT_SIZE_2048 = 3` — Use a buffer of 2048 samples for the Fast Fourier transform.
- `FFT_SIZE_4096 = 4` — Use a buffer of 4096 samples for the Fast Fourier transform.
- `FFT_SIZE_MAX = 5` — Represents the size of the `FFTSize` enum.
