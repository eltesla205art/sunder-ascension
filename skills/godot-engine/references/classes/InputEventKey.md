# InputEventKey

**Inherits:** InputEventWithModifiers

Represents a key on a keyboard being pressed or released.

An input event for keys on a keyboard. Supports key presses, key releases and `echo` events. It can also be received in `Node._unhandled_key_input`. Note: Events received from the keyboard usually have all properties set.

## Properties

- `echo: bool` = `false` — If `true`, the key was already pressed before this event.
- `key_label: Key` = `0` — Represents the localized label printed on the key in the current keyboard layout, which corresponds to one of the `Key` constants or any valid Unicode character.
- `keycode: Key` = `0` — Latin label printed on the key in the current keyboard layout, which corresponds to one of the `Key` constants.
- `location: KeyLocation` = `0` — Represents the location of a key which has both left and right versions, such as `Shift` or `Alt`.
- `physical_keycode: Key` = `0` — Represents the physical location of a key on the 101/102-key US QWERTY keyboard, which corresponds to one of the `Key` constants.
- `pressed: bool` = `false` — If `true`, the key's state is pressed.
- `unicode: int` = `0` — The key Unicode character code (when relevant), shifted by modifier keys.

## Methods

- `as_text_key_label() -> String` *const* — Returns a String representation of the event's `key_label` and modifiers.
- `as_text_keycode() -> String` *const* — Returns a String representation of the event's `keycode` and modifiers.
- `as_text_location() -> String` *const* — Returns a String representation of the event's `location`.
- `as_text_physical_keycode() -> String` *const* — Returns a String representation of the event's `physical_keycode` and modifiers.
- `get_key_label_with_modifiers() -> int[Key]` *const* — Returns the localized key label combined with modifier keys such as `Shift` or `Alt`.
- `get_keycode_with_modifiers() -> int[Key]` *const* — Returns the Latin keycode combined with modifier keys such as `Shift` or `Alt`.
- `get_physical_keycode_with_modifiers() -> int[Key]` *const* — Returns the physical keycode combined with modifier keys such as `Shift` or `Alt`.
