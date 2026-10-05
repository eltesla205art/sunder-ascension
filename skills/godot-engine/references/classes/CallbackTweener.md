# CallbackTweener

**Inherits:** Tweener

Calls the specified method after optional delay.

CallbackTweener is used to call a method in a tweening sequence. See `Tween.tween_callback` for more usage information. The tweener will finish automatically if the callback's target object is freed. Note: `Tween.tween_callback` is the only correct way to create CallbackTweener.

## Methods

- `set_delay(delay: float) -> CallbackTweener` — Makes the callback call delayed by given time in seconds.
