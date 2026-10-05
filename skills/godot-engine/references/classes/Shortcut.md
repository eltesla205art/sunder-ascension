# Shortcut

**Inherits:** Resource

A shortcut for binding input.

Shortcuts (also known as hotkeys) are containers of InputEvent resources. They are commonly used to interact with a Control element from an InputEvent. One shortcut can contain multiple InputEvent resources, making it possible to trigger one action with multiple different inputs. Example: Capture the `Ctrl + S` shortcut using a Shortcut resource:

## Properties

- `events: Array` = `[]` — The shortcut's InputEvent array.

## Methods

- `get_as_text() -> String` *const* — Returns the shortcut's first valid InputEvent as a String.
- `has_valid_event() -> bool` *const* — Returns whether `events` contains an InputEvent which is valid.
- `matches_event(event: InputEvent) -> bool` *const* — Returns whether any InputEvent in `events` equals `event`.
