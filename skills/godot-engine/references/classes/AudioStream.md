# AudioStream

**Inherits:** Resource

Base class for audio streams.

Base class for audio streams. Audio streams are used for sound effects and music playback, and support WAV (via AudioStreamWAV), Ogg (via AudioStreamOggVorbis), and MP3 (via AudioStreamMP3) file formats.

## Methods

- `_get_bar_beats() -> int` *virtual const* — Override this method to return the bar beats of this stream.
- `_get_beat_count() -> int` *virtual const* — Overridable method.
- `_get_bpm() -> float` *virtual const* — Overridable method.
- `_get_length() -> float` *virtual const* — Override this method to customize the returned value of `get_length`.
- `_get_parameter_list() -> Dictionary[]` *virtual const* — Return the controllable parameters of this stream.
- `_get_stream_name() -> String` *virtual const* *(deprecated)* — Override this method to customize the name assigned to this audio stream.
- `_get_tags() -> Dictionary` *virtual const* — Override this method to customize the tags for this audio stream.
- `_has_loop() -> bool` *virtual const* — Override this method to return `true` if this stream has a loop.
- `_instantiate_playback() -> AudioStreamPlayback` *virtual required const* — Override this method to customize the returned value of `instantiate_playback`.
- `_is_monophonic() -> bool` *virtual const* — Override this method to customize the returned value of `is_monophonic`.
- `can_be_sampled() -> bool` *const* — Returns if the current AudioStream can be used as a sample.
- `generate_sample() -> AudioSample` *const* — Generates an AudioSample based on the current stream.
- `get_length() -> float` *const* — Returns the length of the audio stream in seconds.
- `instantiate_playback() -> AudioStreamPlayback` — Returns a newly created AudioStreamPlayback intended to play this audio stream.
- `is_meta_stream() -> bool` *const* — Returns `true` if the stream is a collection of other streams, `false` otherwise.
- `is_monophonic() -> bool` *const* — Returns `true` if this audio stream only supports one channel (monophony), or `false` if the audio stream supports two or more channels (polyphony).

## Signals

- `parameter_list_changed()` — Signal to be emitted to notify when the parameter list changed.
