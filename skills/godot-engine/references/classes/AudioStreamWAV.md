# AudioStreamWAV

**Inherits:** AudioStream

Stores audio data loaded from WAV files.

AudioStreamWAV stores sound samples loaded from WAV files. To play the stored sound, use an AudioStreamPlayer (for non-positional audio) or AudioStreamPlayer2D/AudioStreamPlayer3D (for positional audio). The sound can be looped. This class can also be used to store dynamically-generated PCM audio data.

## Properties

- `data: PackedByteArray` = `PackedByteArray()` — Contains the audio data in bytes.
- `format: AudioStreamWAV.Format` = `0` — Audio format.
- `loop_begin: int` = `0` — The loop start point (in number of samples, relative to the beginning of the stream).
- `loop_end: int` = `0` — The loop end point (in number of samples, relative to the beginning of the stream).
- `loop_mode: AudioStreamWAV.LoopMode` = `0` — The loop mode.
- `mix_rate: int` = `44100` — The sample rate for mixing this audio.
- `stereo: bool` = `false` — If `true`, audio is stereo.
- `tags: Dictionary` = `{}` — Contains user-defined tags if found in the WAV data.

## Methods

- `load_from_buffer(stream_data: PackedByteArray, options: Dictionary = {}) -> AudioStreamWAV` *static* — Creates a new AudioStreamWAV instance from the given buffer.
- `load_from_file(path: String, options: Dictionary = {}) -> AudioStreamWAV` *static* — Creates a new AudioStreamWAV instance from the given file path.
- `save_to_wav(path: String) -> int[Error]` — Saves the AudioStreamWAV as a WAV file to `path`.

## Enum Format

- `FORMAT_8_BITS = 0` — 8-bit PCM audio codec.
- `FORMAT_16_BITS = 1` — 16-bit PCM audio codec.
- `FORMAT_IMA_ADPCM = 2` — Audio is lossily compressed as IMA ADPCM.
- `FORMAT_QOA = 3` — Audio is lossily compressed as Quite OK Audio.

## Enum LoopMode

- `LOOP_DISABLED = 0` — Audio does not loop.
- `LOOP_FORWARD = 1` — Audio loops the data between `loop_begin` and `loop_end`, playing forward only.
- `LOOP_PINGPONG = 2` — Audio loops the data between `loop_begin` and `loop_end`, playing back and forth.
- `LOOP_BACKWARD = 3` — Audio loops the data between `loop_begin` and `loop_end`, playing backward only.
