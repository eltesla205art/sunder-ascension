# AnimationNodeStateMachineTransition

**Inherits:** Resource

A transition within an AnimationNodeStateMachine connecting two AnimationRootNodes.

The path generated when using `AnimationNodeStateMachinePlayback.travel` is limited to the nodes connected by AnimationNodeStateMachineTransition. You can set the timing and conditions of the transition in detail.

## Properties

- `advance_condition: StringName` = `&""` — Turn on auto advance when this condition is set.
- `advance_expression: String` = `""` — Use an expression as a condition for state machine transitions.
- `advance_mode: AnimationNodeStateMachineTransition.AdvanceMode` = `1` — Determines whether the transition should be disabled, enabled when using `AnimationNodeStateMachinePlayback.travel`, or traversed automatically if the `advance_condition` and `advance_expression` checks are `true` (if assigned).
- `break_loop_at_end: bool` = `false` — If `true`, breaks the loop at the end of the loop cycle for transition, even if the animation is looping.
- `priority: int` = `1` — Lower priority transitions are preferred when travelling through the tree via `AnimationNodeStateMachinePlayback.travel` or `advance_mode` is set to `ADVANCE_MODE_AUTO`.
- `reset: bool` = `true` — If `true`, the destination animation is played back from the beginning when switched.
- `switch_mode: AnimationNodeStateMachineTransition.SwitchMode` = `0` — The transition type.
- `xfade_curve: Curve` — Ease curve for better control over cross-fade between this state and the next.
- `xfade_time: float` = `0.0` — The time to cross-fade between this state and the next.

## Signals

- `advance_condition_changed()` — Emitted when `advance_condition` is changed.

## Enum SwitchMode

- `SWITCH_MODE_IMMEDIATE = 0` — Switch to the next state immediately.
- `SWITCH_MODE_SYNC = 1` — Switch to the next state immediately, but will seek the new state to the playback position of the old state.
- `SWITCH_MODE_AT_END = 2` — Wait for the current state playback to end, then switch to the beginning of the next state animation.

## Enum AdvanceMode

- `ADVANCE_MODE_DISABLED = 0` — Don't use this transition.
- `ADVANCE_MODE_ENABLED = 1` — Only use this transition during `AnimationNodeStateMachinePlayback.travel`.
- `ADVANCE_MODE_AUTO = 2` — Automatically use this transition if the `advance_condition` and `advance_expression` checks are `true` (if assigned).
