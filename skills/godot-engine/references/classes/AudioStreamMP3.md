# AudioStreamMP3

**Inherits:** AudioStream

MP3 audio stream driver.

MP3 audio stream driver. See `data` if you want to load an MP3 file at run-time. More info can be found in ResourceImporterMP3. Note: This class can optionally support legacy MP1 and MP2 formats, provided that the engine is compiled with the `minimp3_extra_formats=yes` SCons option.

## Properties

- `bar_beats: int` = `4` — The number of beats within a single bar in the audio track.
- `beat_count: int` = `0` — The length of the audio track, in beats.
- `bpm: float` = `0.0` — The tempo of the audio track, measured in beats per minute.
- `data: PackedByteArray` = `PackedByteArray()` — Contains the audio data in bytes.
- `loop: bool` = `false` — If `true`, the stream will play again from the specified `loop_offset` once it reaches the end of the audio track, or once it reaches the end of the last beat according to the amount specified in `beat_count`.
- `loop_offset: float` = `0.0` — Time in seconds at which the stream starts after being looped.

## Methods

- `load_from_buffer(stream_data: PackedByteArray) -> AudioStreamMP3` *static* — Creates a new AudioStreamMP3 instance from the given buffer.
- `load_from_file(path: String) -> AudioStreamMP3` *static* — Creates a new AudioStreamMP3 instance from the given file path.
