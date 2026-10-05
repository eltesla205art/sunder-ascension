# AudioStreamPlaybackResampled

**Inherits:** AudioStreamPlayback

Playback class used for resampled AudioStreams.

Playback class used to mix an AudioStream's audio samples to `AudioServer.get_mix_rate` using cubic interpolation.

## Methods

- `_get_stream_sampling_rate() -> float` *virtual required const* — Returns an AudioStream's sample rate, in Hz.
- `_mix_resampled(dst_buffer: AudioFrame*, frame_count: int) -> int` *virtual required* — Called by `begin_resample` to mix an AudioStream to `AudioServer.get_mix_rate`.
- `begin_resample() -> void` — Called when an AudioStream is played.
