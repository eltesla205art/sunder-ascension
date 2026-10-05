# Camera2D

**Inherits:** Node2D

Camera node for 2D scenes.

Camera node for 2D scenes. It forces the screen (current layer) to scroll following this node. This makes it easier (and faster) to program scrollable scenes than manually changing the position of CanvasItem-based nodes. Cameras register themselves in the nearest Viewport node (when ascending the tree).

## Properties

- `anchor_mode: Camera2D.AnchorMode` = `1` — The Camera2D's anchor point.
- `custom_viewport: Node` — The custom Viewport node attached to the Camera2D.
- `drag_bottom_margin: float` = `0.2` — Bottom margin needed to drag the camera.
- `drag_horizontal_enabled: bool` = `false` — If `true`, the camera only moves when reaching the horizontal (left and right) drag margins.
- `drag_horizontal_offset: float` = `0.0` — The relative horizontal drag offset of the camera between the right (`-1`) and left (`1`) drag margins.
- `drag_left_margin: float` = `0.2` — Left margin needed to drag the camera.
- `drag_right_margin: float` = `0.2` — Right margin needed to drag the camera.
- `drag_top_margin: float` = `0.2` — Top margin needed to drag the camera.
- `drag_vertical_enabled: bool` = `false` — If `true`, the camera only moves when reaching the vertical (top and bottom) drag margins.
- `drag_vertical_offset: float` = `0.0` — The relative vertical drag offset of the camera between the bottom (`-1`) and top (`1`) drag margins.
- `editor_draw_drag_margin: bool` = `false` — If `true`, draws the camera's drag margin rectangle in the editor.
- `editor_draw_limits: bool` = `false` — If `true`, draws the camera's limits rectangle in the editor.
- `editor_draw_screen: bool` = `true` — If `true`, draws the camera's screen rectangle in the editor.
- `enabled: bool` = `true` — Controls whether the camera can be active or not.
- `ignore_rotation: bool` = `true` — If `true`, the camera's rendered view is not affected by its `Node2D.rotation` and `Node2D.global_rotation`.
- `limit_bottom: int` = `10000000` — Bottom scroll limit in pixels.
- `limit_enabled: bool` = `true` — If `true`, the limits will be enabled.
- `limit_left: int` = `-10000000` — Left scroll limit in pixels.
- `limit_right: int` = `10000000` — Right scroll limit in pixels.
- `limit_smoothed: bool` = `false` — If `true`, the camera smoothly stops when reaches its limits.
- `limit_top: int` = `-10000000` — Top scroll limit in pixels.
- `offset: Vector2` = `Vector2(0, 0)` — The camera's relative offset.
- `position_smoothing_enabled: bool` = `false` — If `true`, the camera's view smoothly moves towards its target position at `position_smoothing_speed`.
- `position_smoothing_speed: float` = `5.0` — Speed in pixels per second of the camera's smoothing effect when `position_smoothing_enabled` is `true`.
- `process_callback: Camera2D.Camera2DProcessCallback` = `1` — The camera's process callback.
- `rotation_smoothing_enabled: bool` = `false` — If `true`, the camera's view smoothly rotates, via asymptotic smoothing, to align with its target rotation at `rotation_smoothing_speed`.
- `rotation_smoothing_speed: float` = `5.0` — The angular, asymptotic speed of the camera's rotation smoothing effect when `rotation_smoothing_enabled` is `true`.
- `zoom: Vector2` = `Vector2(1, 1)` — The camera's zoom.

## Methods

- `align() -> void` — Aligns the camera to the tracked node.
- `force_update_scroll() -> void` — Forces the camera to update scroll immediately.
- `get_drag_margin(margin: Side) -> float` *const* — Returns the specified `Side`'s margin.
- `get_limit(margin: Side) -> int` *const* — Returns the camera limit for the specified `Side`.
- `get_screen_center_position() -> Vector2` *const* — Returns the center of the screen from this camera's point of view, in global coordinates.
- `get_screen_rotation() -> float` *const* — Returns the current screen rotation from this camera's point of view.
- `get_target_position() -> Vector2` *const* — Returns this camera's target position, in global coordinates.
- `is_current() -> bool` *const* — Returns `true` if this Camera2D is the active camera (see `Viewport.get_camera_2d`).
- `make_current() -> void` — Forces this Camera2D to become the current active one.
- `reset_smoothing() -> void` — Sets the camera's position immediately to its current smoothing destination.
- `set_drag_margin(margin: Side, drag_margin: float) -> void` — Sets the specified `Side`'s margin.
- `set_limit(margin: Side, limit: int) -> void` — Sets the camera limit for the specified `Side`.

## Enum AnchorMode

- `ANCHOR_MODE_FIXED_TOP_LEFT = 0` — The camera's position is fixed so that the top-left corner is always at the origin.
- `ANCHOR_MODE_DRAG_CENTER = 1` — The camera's position takes into account vertical/horizontal offsets and the screen size.

## Enum Camera2DProcessCallback

- `CAMERA2D_PROCESS_PHYSICS = 0` — The camera updates during physics frames (see `Node.NOTIFICATION_INTERNAL_PHYSICS_PROCESS`).
- `CAMERA2D_PROCESS_IDLE = 1` — The camera updates during process frames (see `Node.NOTIFICATION_INTERNAL_PROCESS`).
