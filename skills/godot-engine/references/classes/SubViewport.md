# SubViewport

**Inherits:** Viewport

An interface to a game world that doesn't create a window or draw to the screen directly.

SubViewport Isolates a rectangular region of a scene to be displayed independently. This can be used, for example, to display UI in 3D space. Note: SubViewport is a Viewport that isn't a Window, i.e. it doesn't draw anything by itself. To display anything, SubViewport must have a non-zero size and be either put inside a SubViewportContainer or assigned to a ViewportTexture.

## Properties

- `render_target_clear_mode: SubViewport.ClearMode` = `0` — The clear mode when the sub-viewport is used as a render target.
- `render_target_update_mode: SubViewport.UpdateMode` = `2` — The update mode when the sub-viewport is used as a render target.
- `size: Vector2i` = `Vector2i(512, 512)` — The width and height of the sub-viewport.
- `size_2d_override: Vector2i` = `Vector2i(0, 0)` — The 2D size override of the sub-viewport.
- `size_2d_override_stretch: bool` = `false` — If `true`, the 2D size override affects stretch as well.
- `view_count: int` = `1` — The number of view layers we are rendering to.

## Enum ClearMode

- `CLEAR_MODE_ALWAYS = 0` — Always clear the render target before drawing.
- `CLEAR_MODE_NEVER = 1` — Never clear the render target.
- `CLEAR_MODE_ONCE = 2` — Clear the render target on the next frame, then switch to `CLEAR_MODE_NEVER`.

## Enum UpdateMode

- `UPDATE_DISABLED = 0` — Do not update the render target.
- `UPDATE_ONCE = 1` — Update the render target once, then switch to `UPDATE_DISABLED`.
- `UPDATE_WHEN_VISIBLE = 2` — Update the render target only when it is visible.
- `UPDATE_WHEN_PARENT_VISIBLE = 3` — Update the render target only when its parent is visible.
- `UPDATE_ALWAYS = 4` — Always update the render target.
