# AnimationNodeAnimation

**Inherits:** AnimationRootNode

An input animation for an AnimationNodeBlendTree.

A resource to add to an AnimationNodeBlendTree. Only has one output port using the `animation` property. Used as an input for AnimationNodes that blend animations together.

## Properties

- `advance_on_start: bool` = `false` — If `true`, on receiving a request to play an animation from the start, the first frame is not drawn, but only processed, and playback starts from the next frame.
- `animation: StringName` = `&""` — Animation to use as an output.
- `loop_mode: Animation.LoopMode` — If `use_custom_timeline` is `true`, override the loop settings of the original Animation resource with the value.
- `play_mode: AnimationNodeAnimation.PlayMode` = `0` — Determines the playback direction of the animation.
- `start_offset: float` — If `use_custom_timeline` is `true`, offset the start position of the animation.
- `stretch_time_scale: bool` — If `true`, scales the time so that the length specified in `timeline_length` is one cycle.
- `timeline_length: float` — The length of the custom timeline.
- `use_custom_timeline: bool` = `false` — If `true`, AnimationNode provides an animation based on the Animation resource with some parameters adjusted.

## Enum PlayMode

- `PLAY_MODE_FORWARD = 0` — Plays animation in forward direction.
- `PLAY_MODE_BACKWARD = 1` — Plays animation in backward direction.
