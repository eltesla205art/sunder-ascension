# InputEventScreenTouch

**Inherits:** InputEventFromWindow

Represents a screen touch event.

Stores information about multi-touch press/release input events. Supports touch press, touch release and `index` for multi-touch count and order.

## Properties

- `canceled: bool` = `false` — If `true`, the touch event has been canceled.
- `double_tap: bool` = `false` — If `true`, the touch's state is a double tap.
- `index: int` = `0` — The touch index in the case of a multi-touch event.
- `long_press: bool` = `false` — If `true`, the touch's state is a long press.
- `position: Vector2` = `Vector2(0, 0)` — The touch position in the viewport the node is in, using the coordinate system of this viewport.
- `pressed: bool` = `false` — If `true`, the touch's state is pressed.
