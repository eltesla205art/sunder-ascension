# AudioStreamPlayer

**Inherits:** Node

A node for audio playback.

The AudioStreamPlayer node plays an audio stream non-positionally. It is ideal for user interfaces, menus, or background music. To use this node, `stream` needs to be set to a valid AudioStream resource. Playing more than one sound at the same time is also supported, see `max_polyphony`.

## Properties

- `autoplay: bool` = `false` — If `true`, this node calls `play` when entering the tree.
- `bus: StringName` = `&"Master"` — The target bus name.
- `max_polyphony: int` = `1` — The maximum number of sounds this node can play at the same time.
- `mix_target: AudioStreamPlayer.MixTarget` = `0` — The mix target channels.
- `pitch_scale: float` = `1.0` — The audio's pitch and tempo, as a multiplier of the `stream`'s sample rate.
- `playback_type: AudioServer.PlaybackType` = `0` — The playback type of the stream player.
- `playing: bool` = `false` — If `true`, this node is playing sounds.
- `stream: AudioStream` — The AudioStream resource to be played.
- `stream_paused: bool` = `false` — If `true`, the sounds are paused.
- `volume_db: float` = `0.0` — Volume of sound, in decibels.
- `volume_linear: float` — Volume of sound, as a linear value.

## Methods

- `get_playback_position() -> float` — Returns the position in the AudioStream of the latest sound, in seconds.
- `get_stream_playback() -> AudioStreamPlayback` — Returns the latest AudioStreamPlayback of this node, usually the most recently created by `play`.
- `has_stream_playback() -> bool` — Returns `true` if any sound is active, even if `stream_paused` is set to `true`.
- `play(from_position: float = 0.0) -> void` — Plays a sound from the beginning, or the given `from_position` in seconds.
- `seek(to_position: float) -> void` — Restarts all sounds to be played from the given `to_position`, in seconds.
- `stop() -> void` — Stops all sounds from this node.

## Signals

- `finished()` — Emitted when a sound finishes playing without interruptions.

## Enum MixTarget

- `MIX_TARGET_STEREO = 0` — The audio will be played only on the first channel.
- `MIX_TARGET_SURROUND = 1` — The audio will be played on all surround channels.
- `MIX_TARGET_CENTER = 2` — The audio will be played on the second channel, which is usually the center.
