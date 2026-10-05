# AudioStreamOggVorbis

**Inherits:** AudioStream

A class representing an Ogg Vorbis audio stream.

The AudioStreamOggVorbis class is a specialized AudioStream for handling Ogg Vorbis file formats. It offers functionality for loading and playing back Ogg Vorbis files, as well as managing looping and other playback properties. More info can be found in ResourceImporterOggVorbis. This class is part of the audio stream system, which also supports WAV files through the AudioStreamWAV class, and MP3 files through the AudioStreamMP3 class.

## Properties

- `bar_beats: int` = `4` — The number of beats within a single bar in the audio track.
- `beat_count: int` = `0` — The length of the audio track, in beats.
- `bpm: float` = `0.0` — The tempo of the audio track, measured in beats per minute.
- `loop: bool` = `false` — If `true`, the stream will play again from the specified `loop_offset` once it reaches the end of the audio track, or once it reaches the end of the last beat according to the amount specified in `beat_count`.
- `loop_offset: float` = `0.0` — Time in seconds at which the stream starts after being looped.
- `packet_sequence: OggPacketSequence` — Contains the raw Ogg data for this stream.
- `tags: Dictionary` = `{}` — Contains user-defined tags if found in the Ogg Vorbis data.

## Methods

- `load_from_buffer(stream_data: PackedByteArray) -> AudioStreamOggVorbis` *static* — Creates a new AudioStreamOggVorbis instance from the given buffer.
- `load_from_file(path: String) -> AudioStreamOggVorbis` *static* — Creates a new AudioStreamOggVorbis instance from the given file path.
