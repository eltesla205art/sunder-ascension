# AudioEffectRecord

**Inherits:** AudioEffect

Audio effect used for recording the sound from an audio bus.

Allows the user to record the sound from an audio bus into an AudioStreamWAV. When used on the Master audio bus, this includes all audio output by Godot. Unlike AudioEffectCapture, this effect encodes the recording with the given format (8-bit, 16-bit, or compressed) instead of giving access to the raw audio samples. Can be used (with an AudioStreamMicrophone) to record from a microphone.

## Properties

- `format: AudioStreamWAV.Format` = `1` — Specifies the format in which the sample will be recorded.

## Methods

- `get_recording() -> AudioStreamWAV` *const* — Returns the recorded sample.
- `is_recording_active() -> bool` *const* — Returns whether the recording is active or not.
- `set_recording_active(record: bool) -> void` — If `true`, the sound will be recorded.
