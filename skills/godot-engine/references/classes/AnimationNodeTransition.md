# AnimationNodeTransition

**Inherits:** AnimationNodeSync

A transition within an AnimationTree connecting two AnimationNodes.

Simple state machine for cases which don't require a more advanced AnimationNodeStateMachine. Animations can be connected to the inputs and transition times can be specified. After setting the request and changing the animation playback, the transition node automatically clears the request on the next process frame by setting its `transition_request` value to empty. Note: When using a cross-fade, `current_state` and `current_index` change to the next state immediately after the cross-fade begins.

## Properties

- `allow_transition_to_self: bool` = `false` — If `true`, allows transition to the self state.
- `input_count: int` = `0` — The number of enabled input ports for this animation node.
- `xfade_curve: Curve` — Determines how cross-fading between animations is eased.
- `xfade_time: float` = `0.0` — Cross-fading time (in seconds) between each animation connected to the inputs.

## Methods

- `is_input_loop_broken_at_end(input: int) -> bool` *const* — Returns whether the animation breaks the loop at the end of the loop cycle for transition.
- `is_input_reset(input: int) -> bool` *const* — Returns whether the animation restarts when the animation transitions from the other animation.
- `is_input_set_as_auto_advance(input: int) -> bool` *const* — Returns `true` if auto-advance is enabled for the given `input` index.
- `set_input_as_auto_advance(input: int, enable: bool) -> void` — Enables or disables auto-advance for the given `input` index.
- `set_input_break_loop_at_end(input: int, enable: bool) -> void` — If `true`, breaks the loop at the end of the loop cycle for transition, even if the animation is looping.
- `set_input_reset(input: int, enable: bool) -> void` — If `true`, the destination animation is restarted when the animation transitions.
