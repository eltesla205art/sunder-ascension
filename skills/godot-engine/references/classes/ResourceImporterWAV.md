# ResourceImporterWAV

**Inherits:** ResourceImporter

Imports a WAV audio file for playback.

WAV is an uncompressed format, which can provide higher quality compared to Ogg Vorbis and MP3. It also has the lowest CPU cost to decode. This means high numbers of WAV sounds can be played at the same time, even on low-end devices. By default, Godot imports WAV files using the lossy Quite OK Audio compression.

## Properties

- `compress/mode: int` = `2` — The compression mode to use on import. - PCM (Uncompressed): Imports audio data without any form of compression, preserving the highest possible quality.
- `edit/loop_begin: int` = `0` — The begin loop point to use when `edit/loop_mode` is Forward, Ping-Pong, or Backward.
- `edit/loop_end: int` = `-1` — The end loop point to use when `edit/loop_mode` is Forward, Ping-Pong, or Backward.
- `edit/loop_mode: int` = `0` — Controls how audio should loop. - Detect From WAV: Uses loop information from the WAV metadata. - Disabled: Don't loop audio, even if the metadata indicates the file playback should loop. - Forward: Standard audio looping.
- `edit/normalize: bool` = `false` — If `true`, normalize the audio volume so that its peak volume is equal to 0 dB.
- `edit/trim: bool` = `false` — If `true`, automatically trim the beginning and end of the audio if it's lower than -50 dB after normalization (see `edit/normalize`).
- `force/8_bit: bool` = `false` — If `true`, forces the imported audio to use 8-bit quantization if the source file is 16-bit or higher.
- `force/max_rate: bool` = `false` — If set to a value greater than `0`, forces the audio's sample rate to be reduced to a value lower than or equal to the value specified in `force/max_rate_hz`.
- `force/max_rate_hz: float` = `44100` — The frequency to limit the imported audio sample to (in Hz).
- `force/mono: bool` = `false` — If `true`, forces the imported audio to be mono if the source file is stereo.
