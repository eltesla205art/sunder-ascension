# AudioEffectDistortion

**Inherits:** AudioEffect

Adds a distortion audio effect to an audio bus. Remaps audio samples using a nonlinear function to achieve a distorted sound.

A "distortion" effect modifies the waveform via a nonlinear mathematical function (see available ones in `Mode`), based on the amplitude of the waveform's samples. Note: In a nonlinear function, an input sample at x amplitude value, will either have its amplitude increased or decreased to a y value, based on the function value at x, which is why even at the same `drive`, the output sound will vary depending on the input's volume. To change the volume while maintaining the output waveform, use `post_gain`. In this effect, each type is a different nonlinear function.

## Properties

- `drive: float` = `0.0` — Distortion intensity.
- `keep_hf_hz: float` = `16000.0` — High-pass filter, in Hz.
- `mode: AudioEffectDistortion.Mode` = `0` — Distortion type.
- `post_gain: float` = `0.0` — Gain after the effect, in dB.
- `pre_gain: float` = `0.0` — Gain before the effect, in dB.

## Enum Mode

- `MODE_CLIP = 0` — Flattens the waveform at 0 dB in a sharp manner.
- `MODE_ATAN = 1` — Flattens the waveform in a smooth manner, following an arctangent curve.
- `MODE_LOFI = 2` — Decreases audio bit depth to achieve a low-resolution audio signal, going from 16-bit to 2-bit.
- `MODE_OVERDRIVE = 3` — Emulates the warm distortion produced by a field effect transistor, which is commonly used in solid-state musical instrument amplifiers.
- `MODE_WAVESHAPE = 4` — Flattens the waveform in a smooth manner, until it reaches a sharp peak at `drive = 1`, following a generic absolute sigmoid function.
