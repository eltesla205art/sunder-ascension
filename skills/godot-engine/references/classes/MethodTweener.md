# MethodTweener

**Inherits:** Tweener

Interpolates an abstract value and supplies it to a method called over time.

MethodTweener is similar to a combination of CallbackTweener and PropertyTweener. It calls a method providing an interpolated value as a parameter. See `Tween.tween_method` for more usage information. The tweener will finish automatically if the callback's target object is freed.

## Methods

- `set_delay(delay: float) -> MethodTweener` — Sets the time in seconds after which the MethodTweener will start interpolating.
- `set_ease(ease: Tween.EaseType) -> MethodTweener` — Sets the type of used easing from `Tween.EaseType`.
- `set_trans(trans: Tween.TransitionType) -> MethodTweener` — Sets the type of used transition from `Tween.TransitionType`.
