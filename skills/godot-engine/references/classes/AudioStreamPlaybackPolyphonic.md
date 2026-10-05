# AudioStreamPlaybackPolyphonic

**Inherits:** AudioStreamPlayback

Playback instance for AudioStreamPolyphonic.

Playback instance for AudioStreamPolyphonic. After setting the `stream` property of AudioStreamPlayer, AudioStreamPlayer2D, or AudioStreamPlayer3D, the playback instance can be obtained by calling `AudioStreamPlayer.get_stream_playback`, `AudioStreamPlayer2D.get_stream_playback` or `AudioStreamPlayer3D.get_stream_playback` methods.

## Methods

- `is_stream_playing(stream: int) -> bool` *const* — Returns `true` if the stream associated with the given integer ID is still playing.
- `play_stream(stream: AudioStream, from_offset: float = 0, volume_db: float = 0, pitch_scale: float = 1.0, playback_type: AudioServer.PlaybackType = 0, bus: StringName = &"Master") -> int` — Play an AudioStream at a given offset, volume, pitch scale, playback type, and bus.
- `set_stream_pitch_scale(stream: int, pitch_scale: float) -> void` — Change the stream pitch scale.
- `set_stream_volume(stream: int, volume_db: float) -> void` — Change the stream volume (in db).
- `stop_stream(stream: int) -> void` — Stop a stream.

## Constants

- `INVALID_ID = -1` — Returned by `play_stream` in case it could not allocate a stream for playback.
