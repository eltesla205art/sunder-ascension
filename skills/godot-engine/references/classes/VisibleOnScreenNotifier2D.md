# VisibleOnScreenNotifier2D

**Inherits:** Node2D

A rectangular region of 2D space that detects whether it is visible on screen.

VisibleOnScreenNotifier2D represents a rectangular region of 2D space. When any part of this region becomes visible on screen or in a viewport, it will emit a `screen_entered` signal, and likewise it will emit a `screen_exited` signal when no part of it remains visible. If you want a node to be enabled automatically when this region is visible on screen, use VisibleOnScreenEnabler2D. Note: VisibleOnScreenNotifier2D uses the render culling code to determine whether it's visible on screen, so it won't function unless `CanvasItem.visible` is set to `true`.

## Properties

- `rect: Rect2` = `Rect2(-10, -10, 20, 20)` — The VisibleOnScreenNotifier2D's bounding rectangle.
- `show_rect: bool` = `true` — If `true`, shows the rectangle area of `rect` in the editor with a translucent magenta fill.

## Methods

- `is_on_screen() -> bool` *const* — If `true`, the bounding rectangle is on the screen.

## Signals

- `screen_entered()` — Emitted when the VisibleOnScreenNotifier2D enters the screen.
- `screen_exited()` — Emitted when the VisibleOnScreenNotifier2D exits the screen.
