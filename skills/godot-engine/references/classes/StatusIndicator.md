# StatusIndicator

**Inherits:** Node

Application status indicator (aka notification area icon). Note: Status indicator is implemented on macOS and Windows.



## Properties

- `icon: Texture2D` — Status indicator icon.
- `menu: NodePath` = `NodePath("")` — Status indicator native popup menu.
- `tooltip: String` = `""` — Status indicator tooltip.
- `visible: bool` = `true` — If `true`, the status indicator is visible.

## Methods

- `get_rect() -> Rect2` *const* — Returns the status indicator rectangle in screen coordinates.

## Signals

- `pressed(mouse_button: int, mouse_position: Vector2i)` — Emitted when the status indicator is pressed.
