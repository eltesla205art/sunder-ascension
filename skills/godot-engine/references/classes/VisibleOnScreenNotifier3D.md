# VisibleOnScreenNotifier3D

**Inherits:** VisualInstance3D

A box-shaped region of 3D space that detects whether it is visible on screen.

VisibleOnScreenNotifier3D represents a box-shaped region of 3D space. When any part of this region becomes visible on screen or in a Camera3D's view, it will emit a `screen_entered` signal, and likewise it will emit a `screen_exited` signal when no part of it remains visible. If you want a node to be enabled automatically when this region is visible on screen, use VisibleOnScreenEnabler3D. Note: VisibleOnScreenNotifier3D uses an approximate heuristic that doesn't take walls and other occlusion into account, unless occlusion culling is used.

## Properties

- `aabb: AABB` = `AABB(-1, -1, -1, 2, 2, 2)` — The VisibleOnScreenNotifier3D's bounding box.

## Methods

- `is_on_screen() -> bool` *const* — Returns `true` if the bounding box is on the screen.

## Signals

- `screen_entered()` — Emitted when the VisibleOnScreenNotifier3D enters the screen.
- `screen_exited()` — Emitted when the VisibleOnScreenNotifier3D exits the screen.
