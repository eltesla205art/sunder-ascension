# AudioEffectSpectrumAnalyzer

**Inherits:** AudioEffect

Creates an AudioEffectInstance which performs frequency analysis and exposes results to be accessed in real-time.

Calculates a Fourier Transform of the audio signal. This effect does not alter the audio. Can be used for creating real-time audio visualizations, like a spectrogram. This resource configures an AudioEffectSpectrumAnalyzerInstance, which performs the actual analysis at runtime.

## Properties

- `buffer_length: float` = `2.0` — The length of the buffer to keep, in seconds.
- `fft_size: AudioEffectSpectrumAnalyzer.FFTSize` = `2` — The size of the Fast Fourier transform buffer.

## Enum FFTSize

- `FFT_SIZE_256 = 0` — Use a buffer of 256 samples for the Fast Fourier transform.
- `FFT_SIZE_512 = 1` — Use a buffer of 512 samples for the Fast Fourier transform.
- `FFT_SIZE_1024 = 2` — Use a buffer of 1024 samples for the Fast Fourier transform.
- `FFT_SIZE_2048 = 3` — Use a buffer of 2048 samples for the Fast Fourier transform.
- `FFT_SIZE_4096 = 4` — Use a buffer of 4096 samples for the Fast Fourier transform.
- `FFT_SIZE_MAX = 5` — Represents the size of the `FFTSize` enum.
