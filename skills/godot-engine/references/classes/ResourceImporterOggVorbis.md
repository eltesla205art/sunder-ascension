# ResourceImporterOggVorbis

**Inherits:** ResourceImporter

Imports an Ogg Vorbis audio file for playback.

Ogg Vorbis is a lossy audio format, with better audio quality compared to ResourceImporterMP3 at a given bitrate. In most cases, it's recommended to use Ogg Vorbis over MP3. However, if you're using an MP3 sound source with no higher quality source available, then it's recommended to use the MP3 file directly to avoid double lossy compression. Ogg Vorbis requires more CPU to decode than ResourceImporterWAV.

## Properties

- `bar_beats: int` = `4` — The number of beats within a single bar in the audio track.
- `beat_count: int` = `0` — The length of the audio track, in beats.
- `bpm: float` = `0` — The tempo of the audio track, measured in beats per minute.
- `loop: bool` = `false` — If enabled, the audio will begin playing either from the beginning or from `loop_offset`, after playback ends by either reaching the end of the audio or reaching the end of the last beat according to the amount specified in `beat_count`.
- `loop_offset: float` = `0` — Determines where audio will start to loop after playback reaches the end of the audio.

## Methods

- `load_from_buffer(stream_data: PackedByteArray) -> AudioStreamOggVorbis` *static* *(deprecated)* — Creates a new AudioStreamOggVorbis instance from the given buffer.
- `load_from_file(path: String) -> AudioStreamOggVorbis` *static* *(deprecated)* — Creates a new AudioStreamOggVorbis instance from the given file path.
