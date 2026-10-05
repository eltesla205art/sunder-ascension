# AudioStreamPlayer3D

**Inherits:** Node3D

Plays positional sound in 3D space.

Plays audio with positional sound effects, based on the relative position of the audio listener. Positional effects include distance attenuation, directionality, and the Doppler effect. For greater realism, a low-pass filter is applied to distant sounds. This can be disabled by setting `attenuation_filter_cutoff_hz` to `20500`.

## Properties

- `area_mask: int` = `0` — Determines which Area3D layers affect the sound for reverb and audio bus effects.
- `attenuation_filter_cutoff_hz: float` = `5000.0` — The cutoff frequency of the attenuation low-pass filter, in Hz.
- `attenuation_filter_db: float` = `-24.0` — Amount how much the filter affects the loudness, in decibels.
- `attenuation_model: AudioStreamPlayer3D.AttenuationModel` = `0` — Decides if audio should get quieter with distance linearly, quadratically, logarithmically, or not be affected by distance, effectively disabling attenuation.
- `autoplay: bool` = `false` — If `true`, audio plays when the AudioStreamPlayer3D node is added to scene tree.
- `bus: StringName` = `&"Master"` — The bus on which this audio is playing.
- `doppler_tracking: AudioStreamPlayer3D.DopplerTracking` = `0` — Decides in which step the Doppler effect should be calculated.
- `emission_angle_degrees: float` = `45.0` — The angle in which the audio reaches a listener unattenuated.
- `emission_angle_enabled: bool` = `false` — If `true`, the audio should be attenuated according to the direction of the sound.
- `emission_angle_filter_attenuation_db: float` = `-12.0` — Attenuation factor used if listener is outside of `emission_angle_degrees` and `emission_angle_enabled` is set, in decibels.
- `max_db: float` = `3.0` — Sets the absolute maximum of the sound level, in decibels.
- `max_distance: float` = `0.0` — The distance past which the sound can no longer be heard at all.
- `max_polyphony: int` = `1` — The maximum number of sounds this node can play at the same time.
- `panning_strength: float` = `1.0` — Scales the panning strength for this node by multiplying the base `ProjectSettings.audio/general/3d_panning_strength` by this factor.
- `pitch_scale: float` = `1.0` — The pitch and the tempo of the audio, as a multiplier of the audio sample's sample rate.
- `playback_type: AudioServer.PlaybackType` = `0` — The playback type of the stream player.
- `playing: bool` = `false` — If `true`, audio is playing or is queued to be played (see `play`).
- `stream: AudioStream` — The AudioStream resource to be played.
- `stream_paused: bool` = `false` — If `true`, the playback is paused.
- `unit_size: float` = `10.0` — The factor for the attenuation effect.
- `volume_db: float` = `0.0` — The base sound level before attenuation, in decibels.
- `volume_linear: float` — The base sound level before attenuation, as a linear value.

## Methods

- `get_playback_position() -> float` — Returns the position in the AudioStream.
- `get_stream_playback() -> AudioStreamPlayback` — Returns the AudioStreamPlayback object associated with this AudioStreamPlayer3D.
- `has_stream_playback() -> bool` — Returns whether the AudioStreamPlayer can return the AudioStreamPlayback object or not.
- `play(from_position: float = 0.0) -> void` — Queues the audio to play on the next physics frame, from the given position `from_position`, in seconds.
- `seek(to_position: float) -> void` — Sets the position from which audio will be played, in seconds.
- `stop() -> void` — Stops the audio.

## Signals

- `finished()` — Emitted when the audio stops playing.

## Enum AttenuationModel

- `ATTENUATION_INVERSE_DISTANCE = 0` — Attenuation of loudness according to linear distance.
- `ATTENUATION_INVERSE_SQUARE_DISTANCE = 1` — Attenuation of loudness according to squared distance.
- `ATTENUATION_LOGARITHMIC = 2` — Attenuation of loudness according to logarithmic distance.
- `ATTENUATION_DISABLED = 3` — No attenuation of loudness according to distance.

## Enum DopplerTracking

- `DOPPLER_TRACKING_DISABLED = 0` — Disables doppler tracking.
- `DOPPLER_TRACKING_IDLE_STEP = 1` — Executes doppler tracking during process frames (see `Node.NOTIFICATION_INTERNAL_PROCESS`).
- `DOPPLER_TRACKING_PHYSICS_STEP = 2` — Executes doppler tracking during physics frames (see `Node.NOTIFICATION_INTERNAL_PHYSICS_PROCESS`).
