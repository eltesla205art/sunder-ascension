# AudioStreamPlayback

**Inherits:** RefCounted

Meta class for playing back audio.

Can play, loop, pause a scroll through audio. See AudioStream and AudioStreamOggVorbis for usage.

## Methods

- `_get_loop_count() -> int` *virtual const* — Overridable method.
- `_get_parameter(name: StringName) -> Variant` *virtual const* — Return the current value of a playback parameter by name (see `AudioStream._get_parameter_list`).
- `_get_playback_position() -> float` *virtual required const* — Overridable method.
- `_is_playing() -> bool` *virtual required const* — Overridable method.
- `_mix(buffer: AudioFrame*, rate_scale: float, frames: int) -> int` *virtual required* — Override this method to customize how the audio stream is mixed.
- `_seek(position: float) -> void` *virtual* — Override this method to customize what happens when seeking this audio stream at the given `position`, such as by calling `AudioStreamPlayer.seek`.
- `_set_parameter(name: StringName, value: Variant) -> void` *virtual* — Set the current value of a playback parameter by name (see `AudioStream._get_parameter_list`).
- `_start(from_pos: float) -> void` *virtual required* — Override this method to customize what happens when the playback starts at the given position, such as by calling `AudioStreamPlayer.play`.
- `_stop() -> void` *virtual required* — Override this method to customize what happens when the playback is stopped, such as by calling `AudioStreamPlayer.stop`.
- `_tag_used_streams() -> void` *virtual* — Overridable method.
- `get_loop_count() -> int` *const* — Returns the number of times the stream has looped.
- `get_playback_position() -> float` *const* — Returns the current position in the stream, in seconds.
- `get_sample_playback() -> AudioSamplePlayback` *const* — Returns the AudioSamplePlayback associated with this AudioStreamPlayback for playing back the audio sample of this stream.
- `is_playing() -> bool` *const* — Returns `true` if the stream is playing.
- `mix_audio(rate_scale: float, frames: int) -> PackedVector2Array` — Mixes up to `frames` of audio from the stream from the current position, at a rate of `rate_scale`, advancing the stream.
- `seek(time: float = 0.0) -> void` — Seeks the stream at the given `time`, in seconds.
- `set_sample_playback(playback_sample: AudioSamplePlayback) -> void` — Associates AudioSamplePlayback to this AudioStreamPlayback for playing back the audio sample of this stream.
- `start(from_pos: float = 0.0) -> void` — Starts the stream from the given `from_pos`, in seconds.
- `stop() -> void` — Stops the stream.
