# AudioStreamPlaylist

**Inherits:** AudioStream

AudioStream that includes sub-streams and plays them back like a playlist.

An audio stream that can play back sub-streams in sequence. Streams can be added to the Playlist with `set_list_stream`, and shuffled with `shuffle`.

## Properties

- `fade_time: float` = `0.3` — Fade time used when a stream ends, when going to the next one.
- `loop: bool` = `true` — If `true`, the playlist will loop, otherwise the playlist will end when the last stream is finished.
- `shuffle: bool` = `false` — If `true`, the playlist will shuffle each time playback starts and each time it loops.
- `stream_count: int` = `0` — Amount of streams in the playlist.

## Methods

- `get_bpm() -> float` *const* — Returns the BPM of the playlist, which can vary depending on the clip being played.
- `get_list_stream(stream_index: int) -> AudioStream` *const* — Returns the stream at playback position index.
- `set_list_stream(stream_index: int, audio_stream: AudioStream) -> void` — Sets the stream at playback position index.

## Constants

- `MAX_STREAMS = 64` — Maximum amount of streams supported in the playlist.
