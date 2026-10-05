# BackBufferCopy

**Inherits:** Node2D

A node that copies a region of the screen to a buffer for access in shader code.

Node for back-buffering the currently-displayed screen. The region defined in the BackBufferCopy node is buffered with the content of the screen it covers, or the entire screen according to the `copy_mode`. It can be accessed in shader scripts using the screen texture (i.e. a uniform sampler with `hint_screen_texture`). Note: Since this node inherits from Node2D (and not Control), anchors and margins won't apply to child Control-derived nodes.

## Properties

- `copy_mode: BackBufferCopy.CopyMode` = `1` — Buffer mode.
- `rect: Rect2` = `Rect2(-100, -100, 200, 200)` — The area covered by the BackBufferCopy.

## Enum CopyMode

- `COPY_MODE_DISABLED = 0` — Disables the buffering mode.
- `COPY_MODE_RECT = 1` — BackBufferCopy buffers a rectangular region.
- `COPY_MODE_VIEWPORT = 2` — BackBufferCopy buffers the entire screen.
