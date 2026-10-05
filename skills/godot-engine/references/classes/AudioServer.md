# AudioServer

**Inherits:** Object

Server interface for low-level audio access.

AudioServer is a low-level server interface for audio access. It is in charge of creating sample data (playable audio) as well as its playback via a voice interface.

## Properties

- `bus_count: int` = `1` — Number of available audio buses.
- `input_device: String` = `"Default"` — Name of the current device for audio input (see `get_input_device_list`).
- `output_device: String` = `"Default"` — Name of the current device for audio output (see `get_output_device_list`).
- `playback_speed_scale: float` = `1.0` — Scales the rate at which audio is played (i.e. setting it to `0.5` will make the audio be played at half its speed).

## Methods

- `add_bus(at_position: int = -1) -> void` — Adds a bus at `at_position`.
- `add_bus_effect(bus_idx: int, effect: AudioEffect, at_position: int = -1) -> void` — Adds an AudioEffect effect to the bus `bus_idx` at `at_position`.
- `generate_bus_layout() -> AudioBusLayout` *const* — Generates an AudioBusLayout using the available buses and effects.
- `get_bus_channels(bus_idx: int) -> int` *const* — Returns the number of channels of the bus at index `bus_idx`.
- `get_bus_effect(bus_idx: int, effect_idx: int) -> AudioEffect` — Returns the AudioEffect at position `effect_idx` in bus `bus_idx`.
- `get_bus_effect_count(bus_idx: int) -> int` — Returns the number of effects on the bus at `bus_idx`.
- `get_bus_effect_instance(bus_idx: int, effect_idx: int, channel: int = 0) -> AudioEffectInstance` — Returns the AudioEffectInstance assigned to the given bus and effect indices (and optionally channel).
- `get_bus_index(bus_name: StringName) -> int` *const* — Returns the index of the bus with the name `bus_name`.
- `get_bus_name(bus_idx: int) -> String` *const* — Returns the name of the bus with the index `bus_idx`.
- `get_bus_peak_volume_left_db(bus_idx: int, channel: int) -> float` *const* — Returns the peak volume of the left speaker at bus index `bus_idx` and channel index `channel`.
- `get_bus_peak_volume_right_db(bus_idx: int, channel: int) -> float` *const* — Returns the peak volume of the right speaker at bus index `bus_idx` and channel index `channel`.
- `get_bus_send(bus_idx: int) -> StringName` *const* — Returns the name of the bus that the bus at index `bus_idx` sends to.
- `get_bus_volume_db(bus_idx: int) -> float` *const* — Returns the volume of the bus at index `bus_idx` in dB.
- `get_bus_volume_linear(bus_idx: int) -> float` *const* — Returns the volume of the bus at index `bus_idx` as a linear value.
- `get_driver_name() -> String` *const* — Returns the name of the current audio driver.
- `get_input_buffer_length_frames() -> int` — Returns the absolute size of the microphone input buffer.
- `get_input_device_list() -> PackedStringArray` — Returns the names of all audio input devices detected on the system.
- `get_input_frames(frames: int) -> PackedVector2Array` — Returns a PackedVector2Array containing exactly `frames` audio samples from the internal microphone buffer if available, otherwise returns an empty PackedVector2Array.
- `get_input_frames_available() -> int` — Returns the number of frames available to read using `get_input_frames`.
- `get_input_mix_rate() -> float` *const* — Returns the sample rate at the input of the AudioServer.
- `get_mix_rate() -> float` *const* — Returns the sample rate at the output of the AudioServer.
- `get_output_device_list() -> PackedStringArray` — Returns the names of all audio output devices detected on the system.
- `get_output_latency() -> float` *const* — Returns the audio driver's effective output latency.
- `get_speaker_mode() -> int[AudioServer.SpeakerMode]` *const* — Returns the speaker configuration.
- `get_time_since_last_mix() -> float` *const* — Returns the relative time since the last mix occurred, in seconds.
- `get_time_to_next_mix() -> float` *const* — Returns the relative time until the next mix occurs, in seconds.
- `is_bus_bypassing_effects(bus_idx: int) -> bool` *const* — If `true`, the bus at index `bus_idx` is bypassing effects.
- `is_bus_effect_enabled(bus_idx: int, effect_idx: int) -> bool` *const* — If `true`, the effect at index `effect_idx` on the bus at index `bus_idx` is enabled.
- `is_bus_mute(bus_idx: int) -> bool` *const* — If `true`, the bus at index `bus_idx` is muted.
- `is_bus_solo(bus_idx: int) -> bool` *const* — If `true`, the bus at index `bus_idx` is in solo mode.
- `is_stream_registered_as_sample(stream: AudioStream) -> bool` — If `true`, the stream is registered as a sample.
- `lock() -> void` — Locks the audio driver's main loop.
- `move_bus(index: int, to_index: int) -> void` — Moves the bus from index `index` to index `to_index`.
- `register_stream_as_sample(stream: AudioStream) -> void` — Forces the registration of a stream as a sample.
- `remove_bus(index: int) -> void` — Removes the bus at index `index`.
- `remove_bus_effect(bus_idx: int, effect_idx: int) -> void` — Removes the effect at index `effect_idx` from the bus at index `bus_idx`.
- `set_bus_bypass_effects(bus_idx: int, enable: bool) -> void` — If `true`, the bus at index `bus_idx` is bypassing effects.
- `set_bus_effect_enabled(bus_idx: int, effect_idx: int, enabled: bool) -> void` — If `true`, the effect at index `effect_idx` on the bus at index `bus_idx` is enabled.
- `set_bus_layout(bus_layout: AudioBusLayout) -> void` — Overwrites the currently used AudioBusLayout.
- `set_bus_mute(bus_idx: int, enable: bool) -> void` — If `true`, the bus at index `bus_idx` is muted.
- `set_bus_name(bus_idx: int, name: String) -> void` — Sets the name of the bus at index `bus_idx` to `name`.
- `set_bus_send(bus_idx: int, send: StringName) -> void` — Connects the output of the bus at `bus_idx` to the bus named `send`.
- `set_bus_solo(bus_idx: int, enable: bool) -> void` — If `true`, the bus at index `bus_idx` is in solo mode.
- `set_bus_volume_db(bus_idx: int, volume_db: float) -> void` — Sets the volume in decibels of the bus at index `bus_idx` to `volume_db`.
- `set_bus_volume_linear(bus_idx: int, volume_linear: float) -> void` — Sets the volume as a linear value of the bus at index `bus_idx` to `volume_linear`.
- `set_enable_tagging_used_audio_streams(enable: bool) -> void` — If set to `true`, all instances of AudioStreamPlayback will call `AudioStreamPlayback._tag_used_streams` every mix step.
- `set_input_device_active(active: bool) -> int[Error]` — If `active` is `true`, starts the microphone input stream specified by `input_device` or returns an error if it failed.
- `swap_bus_effects(bus_idx: int, effect_idx: int, by_effect_idx: int) -> void` — Swaps the position of two effects in bus `bus_idx`.
- `unlock() -> void` — Unlocks the audio driver's main loop. (After locking it, you should always unlock it.)

## Signals

- `bus_layout_changed()` — Emitted when an audio bus is added, deleted, or moved.
- `bus_renamed(bus_index: int, old_name: StringName, new_name: StringName)` — Emitted when the audio bus at `bus_index` is renamed from `old_name` to `new_name`.

## Enum SpeakerMode

- `SPEAKER_MODE_STEREO = 0` — Two or fewer speakers were detected.
- `SPEAKER_SURROUND_31 = 1` — A 3.1 channel surround setup was detected.
- `SPEAKER_SURROUND_51 = 2` — A 5.1 channel surround setup was detected.
- `SPEAKER_SURROUND_71 = 3` — A 7.1 channel surround setup was detected.

## Enum PlaybackType

- `PLAYBACK_TYPE_DEFAULT = 0` — The playback will be considered of the type declared at `ProjectSettings.audio/general/default_playback_type`.
- `PLAYBACK_TYPE_STREAM = 1` — Force the playback to be considered as a stream.
- `PLAYBACK_TYPE_SAMPLE = 2` — Force the playback to be considered as a sample.
- `PLAYBACK_TYPE_MAX = 3` — Represents the size of the `PlaybackType` enum.
