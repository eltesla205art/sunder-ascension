# InputEventGesture

**Inherits:** InputEventWithModifiers

Abstract base class for touch gestures.

InputEventGestures are sent when a user performs a supported gesture on a touch screen. Gestures can't be emulated using mouse, because they typically require multi-touch.

## Properties

- `device: int` = `0` — 
- `position: Vector2` = `Vector2(0, 0)` — The local gesture position relative to the Viewport.
