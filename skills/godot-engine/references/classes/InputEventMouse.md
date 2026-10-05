# InputEventMouse

**Inherits:** InputEventWithModifiers

Base input event type for mouse events.

Stores general information about mouse events.

## Properties

- `button_mask: MouseButtonMask` = `0` — The mouse button mask identifier, one of or a bitwise combination of the `MouseButton` button masks.
- `device: int` = `32` — 
- `global_position: Vector2` = `Vector2(0, 0)` — When received in `Node._input` or `Node._unhandled_input`, returns the mouse's position in the root Viewport using the coordinate system of the root Viewport.
- `position: Vector2` = `Vector2(0, 0)` — When received in `Node._input` or `Node._unhandled_input`, returns the mouse's position in the Viewport this Node is in using the coordinate system of this Viewport.
