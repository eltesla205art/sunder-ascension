# AudioStreamGeneratorPlayback

**Inherits:** AudioStreamPlaybackResampled

Plays back audio generated using AudioStreamGenerator.

This class is meant to be used with AudioStreamGenerator to play back the generated audio in real-time.

## Methods

- `can_push_buffer(amount: int) -> bool` *const* — Returns `true` if a buffer of the size `amount` can be pushed to the audio sample data buffer without overflowing it, `false` otherwise.
- `clear_buffer() -> void` — Clears the audio sample data buffer.
- `get_frames_available() -> int` *const* — Returns the number of frames that can be pushed to the audio sample data buffer without overflowing it.
- `get_skips() -> int` *const* — Returns the number of times the playback skipped due to a buffer underrun in the audio sample data.
- `push_buffer(frames: PackedVector2Array) -> bool` — Pushes several audio data frames to the buffer.
- `push_frame(frame: Vector2) -> bool` — Pushes a single audio data frame to the buffer.
