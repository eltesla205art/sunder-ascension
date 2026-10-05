# AnimationNodeOneShot

**Inherits:** AnimationNodeSync

Plays an animation once in an AnimationNodeBlendTree.

A resource to add to an AnimationNodeBlendTree. This animation node will execute a sub-animation and return once it finishes. Blend times for fading in and out can be customized, as well as filters. After setting the request and changing the animation playback, the one-shot node automatically clears the request on the next process frame by setting its `request` value to `ONE_SHOT_REQUEST_NONE`.

## Properties

- `abort_on_reset: bool` = `false` — If `true`, the sub-animation will abort if resumed with a reset after a prior interruption.
- `autorestart: bool` = `false` — If `true`, the sub-animation will restart automatically after finishing.
- `autorestart_delay: float` = `1.0` — The delay after which the automatic restart is triggered, in seconds.
- `autorestart_random_delay: float` = `0.0` — If `autorestart` is `true`, a random additional delay (in seconds) between 0 and this value will be added to `autorestart_delay`.
- `break_loop_at_end: bool` = `false` — If `true`, breaks the loop at the end of the loop cycle for transition, even if the animation is looping.
- `fadein_curve: Curve` — Determines how cross-fading between animations is eased.
- `fadein_time: float` = `0.0` — The fade-in duration.
- `fadeout_curve: Curve` — Determines how cross-fading between animations is eased.
- `fadeout_time: float` = `0.0` — The fade-out duration.
- `mix_mode: AnimationNodeOneShot.MixMode` = `0` — The blend type.

## Enum OneShotRequest

- `ONE_SHOT_REQUEST_NONE = 0` — The default state of the request.
- `ONE_SHOT_REQUEST_FIRE = 1` — The request to play the animation connected to "shot" port.
- `ONE_SHOT_REQUEST_ABORT = 2` — The request to stop the animation connected to "shot" port.
- `ONE_SHOT_REQUEST_FADE_OUT = 3` — The request to fade out the animation connected to "shot" port.

## Enum MixMode

- `MIX_MODE_BLEND = 0` — Blends two animations.
- `MIX_MODE_ADD = 1` — Blends two animations additively.
