# Tween

**Inherits:** RefCounted

Lightweight object used for general-purpose animation via script, using Tweeners.

Tweens are mostly useful for animations requiring a numerical property to be interpolated over a range of values. The name tween comes from in-betweening, an animation technique where you specify keyframes and the computer interpolates the frames that appear between them. Animating something with a Tween is called tweening. Tween is more suited than AnimationPlayer for animations where you don't know the final values in advance.

## Methods

- `bind_node(node: Node) -> Tween` — Binds this Tween with the given `node`.
- `chain() -> Tween` — Used to chain two Tweeners after `set_parallel` is called with `true`.
- `custom_step(delta: float) -> bool` — Processes the Tween by the given `delta` value, in seconds.
- `get_loops_left() -> int` *const* — Returns the number of remaining loops for this Tween (see `set_loops`).
- `get_total_elapsed_time() -> float` *const* — Returns the total time in seconds the Tween has been animating (i.e. the time since it started, not counting pauses etc.).
- `has_tweeners() -> bool` *const* — Returns `true` if any Tweener has been added to the Tween and the Tween is valid.
- `interpolate_value(initial_value: Variant, delta_value: Variant, elapsed_time: float, duration: float, trans_type: Tween.TransitionType, ease_type: Tween.EaseType) -> Variant` *static* — This method can be used for manual interpolation of a value, when you don't want Tween to do animating for you.
- `is_running() -> bool` — Returns whether the Tween is currently running, i.e. it wasn't paused and it's not finished.
- `is_valid() -> bool` — Returns whether the Tween is valid.
- `kill() -> void` — Aborts all tweening operations and invalidates the Tween.
- `parallel() -> Tween` — Makes the next Tweener run parallelly to the previous one.
- `pause() -> void` — Pauses the tweening.
- `play() -> void` — Resumes a paused or stopped Tween.
- `set_ease(ease: Tween.EaseType) -> Tween` — Sets the default ease type for PropertyTweeners and MethodTweeners appended after this method.
- `set_ignore_time_scale(ignore: bool = true) -> Tween` — If `ignore` is `true`, the tween will ignore `Engine.time_scale` and update with the real, elapsed time.
- `set_loops(loops: int = 0) -> Tween` — Sets the number of times the tweening sequence will be repeated, i.e.
- `set_parallel(parallel: bool = true) -> Tween` — If `parallel` is `true`, the Tweeners appended after this method will by default run simultaneously, as opposed to sequentially.
- `set_pause_mode(mode: Tween.TweenPauseMode) -> Tween` — Determines the behavior of the Tween when the SceneTree is paused.
- `set_process_mode(mode: Tween.TweenProcessMode) -> Tween` — Determines whether the Tween should run after process frames (see `Node._process`) or physics frames (see `Node._physics_process`).
- `set_speed_scale(speed: float) -> Tween` — Scales the speed of tweening.
- `set_trans(trans: Tween.TransitionType) -> Tween` — Sets the default transition type for PropertyTweeners and MethodTweeners appended after this method.
- `stop() -> void` — Stops the tweening and resets the Tween to its initial state.
- `tween_await(signal: Signal) -> AwaitTweener` — Creates and appends an AwaitTweener.
- `tween_callback(callback: Callable) -> CallbackTweener` — Creates and appends a CallbackTweener.
- `tween_interval(time: float) -> IntervalTweener` — Creates and appends an IntervalTweener.
- `tween_method(method: Callable, from: Variant, to: Variant, duration: float) -> MethodTweener` — Creates and appends a MethodTweener.
- `tween_property(object: Object, property: NodePath, final_val: Variant, duration: float) -> PropertyTweener` — Creates and appends a PropertyTweener.
- `tween_subtween(subtween: Tween) -> SubtweenTweener` — Creates and appends a SubtweenTweener.

## Signals

- `finished()` — Emitted when the Tween has finished all tweening.
- `loop_finished(loop_count: int)` — Emitted when a full loop is complete (see `set_loops`), providing the loop index.
- `step_finished(idx: int)` — Emitted when one step of the Tween is complete, providing the step index.

## Enum TweenProcessMode

- `TWEEN_PROCESS_PHYSICS = 0` — The Tween updates after each physics frame (see `Node._physics_process`).
- `TWEEN_PROCESS_IDLE = 1` — The Tween updates after each process frame (see `Node._process`).

## Enum TweenPauseMode

- `TWEEN_PAUSE_BOUND = 0` — If the Tween has a bound node, it will process when that node can process (see `Node.process_mode`).
- `TWEEN_PAUSE_STOP = 1` — If SceneTree is paused, the Tween will also pause.
- `TWEEN_PAUSE_PROCESS = 2` — The Tween will process regardless of whether SceneTree is paused.

## Enum TransitionType

- `TRANS_LINEAR = 0` — The animation is interpolated linearly.
- `TRANS_SINE = 1` — The animation is interpolated using a sine function.
- `TRANS_QUINT = 2` — The animation is interpolated with a quintic (to the power of 5) function.
- `TRANS_QUART = 3` — The animation is interpolated with a quartic (to the power of 4) function.
- `TRANS_QUAD = 4` — The animation is interpolated with a quadratic (to the power of 2) function.
- `TRANS_EXPO = 5` — The animation is interpolated with an exponential (to the power of x) function.
- `TRANS_ELASTIC = 6` — The animation is interpolated with elasticity, wiggling around the edges.
- `TRANS_CUBIC = 7` — The animation is interpolated with a cubic (to the power of 3) function.
- `TRANS_CIRC = 8` — The animation is interpolated with a function using square roots.
- `TRANS_BOUNCE = 9` — The animation is interpolated by bouncing at the end.
- `TRANS_BACK = 10` — The animation is interpolated backing out at ends.
- `TRANS_SPRING = 11` — The animation is interpolated like a spring towards the end.

## Enum EaseType

- `EASE_IN = 0` — The interpolation starts slowly and speeds up towards the end.
- `EASE_OUT = 1` — The interpolation starts quickly and slows down towards the end.
- `EASE_IN_OUT = 2` — A combination of `EASE_IN` and `EASE_OUT`.
- `EASE_OUT_IN = 3` — A combination of `EASE_IN` and `EASE_OUT`.
