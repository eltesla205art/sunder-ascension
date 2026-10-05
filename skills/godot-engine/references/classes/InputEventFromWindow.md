# InputEventFromWindow

**Inherits:** InputEvent

Abstract base class for Viewport-based input events.

InputEventFromWindow represents events specifically received by windows. This includes mouse events, keyboard events in focused windows or touch screen actions.

## Properties

- `window_id: int` = `0` — The ID of a Window that received this event.
