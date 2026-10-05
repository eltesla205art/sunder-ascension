# AudioStreamGenerator

**Inherits:** AudioStream

An audio stream with utilities for procedural sound generation.

AudioStreamGenerator is a type of audio stream that does not play back sounds on its own; instead, it expects a script to generate audio data for it. See also AudioStreamGeneratorPlayback. Here's a sample on how to use it to generate a sine wave:  In the example above, the "AudioStreamPlayer" node must use an AudioStreamGenerator as its stream. The `fill_buffer` function provides audio data for approximating a sine wave.

## Properties

- `buffer_length: float` = `0.5` — The length of the buffer to generate (in seconds).
- `mix_rate: float` = `44100.0` — The sample rate to use (in Hz).
- `mix_rate_mode: AudioStreamGenerator.AudioStreamGeneratorMixRate` = `2` — Mixing rate mode.

## Enum AudioStreamGeneratorMixRate

- `MIX_RATE_OUTPUT = 0` — Current AudioServer output mixing rate.
- `MIX_RATE_INPUT = 1` — Current AudioServer input mixing rate.
- `MIX_RATE_CUSTOM = 2` — Custom mixing rate, specified by `mix_rate`.
- `MIX_RATE_MAX = 3` — Maximum value for the mixing rate mode enum.
