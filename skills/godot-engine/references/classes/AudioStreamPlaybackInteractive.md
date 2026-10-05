# AudioStreamPlaybackInteractive

**Inherits:** AudioStreamPlayback

Playback component of AudioStreamInteractive.

Playback component of AudioStreamInteractive. Contains functions to change the currently played clip.

## Methods

- `get_current_clip_index() -> int` *const* — Return the index of the currently playing clip.
- `switch_to_clip(clip_index: int) -> void` — Switch to a clip (by index).
- `switch_to_clip_by_name(clip_name: StringName) -> void` — Switch to a clip (by name).
