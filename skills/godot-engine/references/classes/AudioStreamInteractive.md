# AudioStreamInteractive

**Inherits:** AudioStream

Audio stream that can playback music interactively, combining clips and a transition table.

This is an audio stream that can playback music interactively, combining clips and a transition table. Clips must be added first, and then the transition rules via the `add_transition`. Additionally, this stream exports a property parameter to control the playback via AudioStreamPlayer, AudioStreamPlayer2D, or AudioStreamPlayer3D. The way this is used is by filling a number of clips, then configuring the transition table.

## Properties

- `clip_count: int` = `0` — Amount of clips contained in this interactive player.
- `initial_clip: int` = `0` — Index of the initial clip, which will be played first when this stream is played.

## Methods

- `add_transition(from_clip: int, to_clip: int, from_time: AudioStreamInteractive.TransitionFromTime, to_time: AudioStreamInteractive.TransitionToTime, fade_mode: AudioStreamInteractive.FadeMode, fade_beats: float, use_filler_clip: bool = false, filler_clip: int = -1, hold_previous: bool = false) -> void` — Add a transition between two clips.
- `erase_transition(from_clip: int, to_clip: int) -> void` — Erase a transition by providing `from_clip` and `to_clip` clip indices.
- `get_clip_auto_advance(clip_index: int) -> int[AudioStreamInteractive.AutoAdvanceMode]` *const* — Return whether a clip has auto-advance enabled.
- `get_clip_auto_advance_next_clip(clip_index: int) -> int` *const* — Return the clip towards which the clip referenced by `clip_index` will auto-advance to.
- `get_clip_name(clip_index: int) -> StringName` *const* — Return the name of a clip.
- `get_clip_stream(clip_index: int) -> AudioStream` *const* — Return the AudioStream associated with a clip.
- `get_transition_fade_beats(from_clip: int, to_clip: int) -> float` *const* — Return the time (in beats) for a transition (see `add_transition`).
- `get_transition_fade_mode(from_clip: int, to_clip: int) -> int[AudioStreamInteractive.FadeMode]` *const* — Return the mode for a transition (see `add_transition`).
- `get_transition_filler_clip(from_clip: int, to_clip: int) -> int` *const* — Return the filler clip for a transition (see `add_transition`).
- `get_transition_from_time(from_clip: int, to_clip: int) -> int[AudioStreamInteractive.TransitionFromTime]` *const* — Return the source time position for a transition (see `add_transition`).
- `get_transition_list() -> PackedInt32Array` *const* — Return the list of transitions (from, to interleaved).
- `get_transition_to_time(from_clip: int, to_clip: int) -> int[AudioStreamInteractive.TransitionToTime]` *const* — Return the destination time position for a transition (see `add_transition`).
- `has_transition(from_clip: int, to_clip: int) -> bool` *const* — Returns `true` if a given transition exists (was added via `add_transition`).
- `is_transition_holding_previous(from_clip: int, to_clip: int) -> bool` *const* — Return whether a transition uses the hold previous functionality (see `add_transition`).
- `is_transition_using_filler_clip(from_clip: int, to_clip: int) -> bool` *const* — Return whether a transition uses the filler clip functionality (see `add_transition`).
- `set_clip_auto_advance(clip_index: int, mode: AudioStreamInteractive.AutoAdvanceMode) -> void` — Set whether a clip will auto-advance by changing the auto-advance mode.
- `set_clip_auto_advance_next_clip(clip_index: int, auto_advance_next_clip: int) -> void` — Set the index of the next clip towards which this clip will auto advance to when finished.
- `set_clip_name(clip_index: int, name: StringName) -> void` — Set the name of the current clip (for easier identification).
- `set_clip_stream(clip_index: int, stream: AudioStream) -> void` — Set the AudioStream associated with the current clip.

## Enum TransitionFromTime

- `TRANSITION_FROM_TIME_IMMEDIATE = 0` — Start transition as soon as possible, don't wait for any specific time position.
- `TRANSITION_FROM_TIME_NEXT_BEAT = 1` — Transition when the clip playback position reaches the next beat.
- `TRANSITION_FROM_TIME_NEXT_BAR = 2` — Transition when the clip playback position reaches the next bar.
- `TRANSITION_FROM_TIME_END = 3` — Transition when the current clip finished playing.

## Enum TransitionToTime

- `TRANSITION_TO_TIME_SAME_POSITION = 0` — Transition to the same position in the destination clip.
- `TRANSITION_TO_TIME_START = 1` — Transition to the start of the destination clip.
- `TRANSITION_TO_TIME_PREVIOUS_POSITION = 2` — Transition to the last played position in the destination clip, if there was a previous transition from that clip.

## Enum FadeMode

- `FADE_DISABLED = 0` — Do not use fade for the transition.
- `FADE_IN = 1` — Use a fade-in in the next clip, let the current clip finish.
- `FADE_OUT = 2` — Use a fade-out in the current clip, the next clip will start by itself.
- `FADE_CROSS = 3` — Use a cross-fade between clips.
- `FADE_AUTOMATIC = 4` — Use automatic fade logic depending on the transition from/to.

## Enum AutoAdvanceMode

- `AUTO_ADVANCE_DISABLED = 0` — Disable auto-advance (default).
- `AUTO_ADVANCE_ENABLED = 1` — Enable auto-advance, a clip must be specified.
- `AUTO_ADVANCE_RETURN_TO_HOLD = 2` — Enable auto-advance, but instead of specifying a clip, the playback will return to hold (see `add_transition`).

## Constants

- `CLIP_ANY = -1` — This constant describes that any clip is valid for a specific transition as either source or destination.
