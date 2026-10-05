# VideoStreamPlayback

**Inherits:** Resource

Internal class used by VideoStream to manage playback state when played from a VideoStreamPlayer.

This class is intended to be overridden by video decoder extensions with custom implementations of VideoStream.

## Methods

- `_get_channels() -> int` *virtual const* — Returns the number of audio channels.
- `_get_length() -> float` *virtual const* — Returns the video duration in seconds, if known, or 0 if unknown.
- `_get_mix_rate() -> int` *virtual const* — Returns the audio sample rate used for mixing.
- `_get_playback_position() -> float` *virtual const* — Return the current playback timestamp.
- `_get_texture() -> Texture2D` *virtual const* — Allocates a Texture2D in which decoded video frames will be drawn.
- `_is_paused() -> bool` *virtual const* — Returns the paused status, as set by `_set_paused`.
- `_is_playing() -> bool` *virtual const* — Returns the playback state, as determined by calls to `_play` and `_stop`.
- `_play() -> void` *virtual* — Called in response to `VideoStreamPlayer.autoplay` or `VideoStreamPlayer.play`.
- `_seek(time: float) -> void` *virtual* — Seeks to `time` seconds.
- `_set_audio_track(idx: int) -> void` *virtual* — Select the audio track `idx`.
- `_set_paused(paused: bool) -> void` *virtual* — Set the paused status of video playback.
- `_stop() -> void` *virtual* — Stops playback.
- `_update(delta: float) -> void` *virtual required* — Ticks video playback for `delta` seconds.
- `mix_audio(num_frames: int, buffer: PackedFloat32Array = PackedFloat32Array(), offset: int = 0) -> int` — Render `num_frames` audio frames (of `_get_channels` floats each) from `buffer`, starting from index `offset` in the array.
