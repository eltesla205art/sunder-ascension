# ResourceImporterMP3

**Inherits:** ResourceImporter

Imports an MP3 audio file for playback.

MP3 is a lossy audio format, with worse audio quality compared to ResourceImporterOggVorbis at a given bitrate. In most cases, it's recommended to use Ogg Vorbis over MP3. However, if you're using an MP3 sound source with no higher quality source available, then it's recommended to use the MP3 file directly to avoid double lossy compression. MP3 requires more CPU to decode than ResourceImporterWAV.

## Properties

- `bar_beats: int` = `4` — The number of beats within a single bar in the audio track.
- `beat_count: int` = `0` — The length of the audio track, in beats.
- `bpm: float` = `0` — The tempo of the audio track, measured in beats per minute.
- `loop: bool` = `false` — If enabled, the audio will begin playing either from the beginning or from `loop_offset`, after playback ends by either reaching the end of the audio or reaching the end of the last beat according to the amount specified in `beat_count`.
- `loop_offset: float` = `0` — Determines where audio will start to loop after playback reaches the end of the audio.
