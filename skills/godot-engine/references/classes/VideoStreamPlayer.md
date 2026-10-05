# VideoStreamPlayer

**Inherits:** Control

A control used for video playback.

A control used for playback of VideoStream resources. Supported video formats are Ogg Theora (`.ogv`, VideoStreamTheora) and any format exposed via a GDExtension plugin. Warning: On Web, video playback will perform poorly due to missing architecture-specific assembly optimizations.

## Properties

- `audio_track: int` = `0` — The embedded audio track to play.
- `autoplay: bool` = `false` — If `true`, playback starts when the scene loads.
- `buffering_msec: int` = `500` — Amount of time in milliseconds to store in buffer while playing.
- `bus: StringName` = `&"Master"` — Audio bus to use for sound playback.
- `expand: bool` = `false` — If `true`, the video scales to the control size.
- `loop: bool` = `false` — If `true`, the video restarts when it reaches its end.
- `paused: bool` = `false` — If `true`, the video is paused.
- `speed_scale: float` = `1.0` — The stream's current speed scale.
- `stream: VideoStream` — The assigned video stream.
- `stream_position: float` — The current position of the stream, in seconds.
- `volume: float` — Audio volume as a linear value.
- `volume_db: float` = `0.0` — Audio volume in dB.

## Methods

- `get_stream_length() -> float` *const* — The length of the current stream, in seconds.
- `get_stream_name() -> String` *const* — Returns the video stream's name, or `"<No Stream>"` if no video stream is assigned.
- `get_video_texture() -> Texture2D` *const* — Returns the current frame as a Texture2D.
- `is_playing() -> bool` *const* — Returns `true` if the video is playing.
- `play() -> void` — Starts the video playback from the beginning.
- `stop() -> void` — Stops the video playback and sets the stream position to 0.

## Signals

- `finished()` — Emitted when playback is finished.
