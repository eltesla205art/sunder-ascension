# AudioStreamSynchronized

**Inherits:** AudioStream

Stream that can be fitted with sub-streams, which will be played in-sync.

This is a stream that can be fitted with sub-streams, which will be played in-sync. The streams begin at exactly the same time when play is pressed, and will end when the last of them ends. If one of the sub-streams loops, then playback will continue.

## Properties

- `stream_count: int` = `0` — Set the total amount of streams that will be played back synchronized.

## Methods

- `get_sync_stream(stream_index: int) -> AudioStream` *const* — Get one of the synchronized streams, by index.
- `get_sync_stream_volume(stream_index: int) -> float` *const* — Get the volume of one of the synchronized streams, by index.
- `set_sync_stream(stream_index: int, audio_stream: AudioStream) -> void` — Set one of the synchronized streams, by index.
- `set_sync_stream_volume(stream_index: int, volume_db: float) -> void` — Set the volume of one of the synchronized streams, by index.

## Constants

- `MAX_STREAMS = 32` — Maximum amount of streams that can be synchronized.
