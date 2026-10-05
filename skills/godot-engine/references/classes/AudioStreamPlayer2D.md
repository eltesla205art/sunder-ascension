# AudioStreamPlayer2D

**Inherits:** Node2D

Plays positional sound in 2D space.

Plays audio that is attenuated with distance to the listener. By default, audio is heard from the screen center. This can be changed by adding an AudioListener2D node to the scene and enabling it by calling `AudioListener2D.make_current` on it. See also AudioStreamPlayer to play a sound non-positionally.

## Properties

- `area_mask: int` = `0` — Determines which Area2D layers affect the sound for reverb and audio bus effects.
- `attenuation: float` = `1.0` — The volume is attenuated over distance with this as an exponent.
- `autoplay: bool` = `false` — If `true`, audio plays when added to scene tree.
- `bus: StringName` = `&"Master"` — Bus on which this audio is playing.
- `max_distance: float` = `2000.0` — Maximum distance from which audio is still hearable.
- `max_polyphony: int` = `1` — The maximum number of sounds this node can play at the same time.
- `panning_strength: float` = `1.0` — Scales the panning strength for this node by multiplying the base `ProjectSettings.audio/general/2d_panning_strength` with this factor.
- `pitch_scale: float` = `1.0` — The pitch and the tempo of the audio, as a multiplier of the audio sample's sample rate.
- `playback_type: AudioServer.PlaybackType` = `0` — The playback type of the stream player.
- `playing: bool` = `false` — If `true`, audio is playing or is queued to be played (see `play`).
- `stream: AudioStream` — The AudioStream object to be played.
- `stream_paused: bool` = `false` — If `true`, the playback is paused.
- `volume_db: float` = `0.0` — Base volume before attenuation, in decibels.
- `volume_linear: float` — Base volume before attenuation, as a linear value.

## Methods

- `get_playback_position() -> float` — Returns the position in the AudioStream.
- `get_stream_playback() -> AudioStreamPlayback` — Returns the AudioStreamPlayback object associated with this AudioStreamPlayer2D.
- `has_stream_playback() -> bool` — Returns whether the AudioStreamPlayer can return the AudioStreamPlayback object or not.
- `play(from_position: float = 0.0) -> void` — Queues the audio to play on the next physics frame, from the given position `from_position`, in seconds.
- `seek(to_position: float) -> void` — Sets the position from which audio will be played, in seconds.
- `stop() -> void` — Stops the audio.

## Signals

- `finished()` — Emitted when the audio stops playing.
