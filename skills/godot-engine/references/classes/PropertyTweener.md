# PropertyTweener

**Inherits:** Tweener

Interpolates an Object's property over time.

PropertyTweener is used to interpolate a property in an object. See `Tween.tween_property` for more usage information. The tweener will finish automatically if the target object is freed. Note: `Tween.tween_property` is the only correct way to create PropertyTweener.

## Methods

- `as_relative() -> PropertyTweener` — When called, the final value will be used as a relative value instead.
- `from(value: Variant) -> PropertyTweener` — Sets a custom initial value to the PropertyTweener.
- `from_current() -> PropertyTweener` — Makes the PropertyTweener use the current property value (i.e. at the time of creating this PropertyTweener) as a starting point.
- `set_custom_interpolator(interpolator_method: Callable) -> PropertyTweener` — Allows interpolating the value with a custom easing function.
- `set_delay(delay: float) -> PropertyTweener` — Sets the time in seconds after which the PropertyTweener will start interpolating.
- `set_ease(ease: Tween.EaseType) -> PropertyTweener` — Sets the type of used easing from `Tween.EaseType`.
- `set_trans(trans: Tween.TransitionType) -> PropertyTweener` — Sets the type of used transition from `Tween.TransitionType`.
