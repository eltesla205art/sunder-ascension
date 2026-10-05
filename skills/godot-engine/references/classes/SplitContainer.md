# SplitContainer

**Inherits:** Container

A container that arranges child controls horizontally or vertically and provides grabbers for adjusting the split ratios between them.

A container that arranges child controls horizontally or vertically and creates grabbers between them. The grabbers can be dragged around to change the size relations between the child controls.

## Properties

- `collapsed: bool` = `false` — If `true`, the draggers will be disabled and the children will be sized as if all `split_offsets` were `0`.
- `drag_area_highlight_in_editor: bool` = `false` — Highlights the drag area Rect2 so you can see where it is during development.
- `drag_area_margin_begin: int` = `0` — Reduces the size of the drag area and split bar `split_bar_background` at the beginning of the container.
- `drag_area_margin_end: int` = `0` — Reduces the size of the drag area and split bar `split_bar_background` at the end of the container.
- `drag_area_offset: int` = `0` — Shifts the drag area in the axis of the container to prevent the drag area from overlapping the ScrollBar or other selectable Control of a child node.
- `drag_nested_intersections: bool` = `false` — Adds extra draggers at the intersection of the draggers of two SplitContainers to allow dragging both at once.
- `dragger_visibility: SplitContainer.DraggerVisibility` = `0` — Determines the dragger's visibility.
- `dragging_enabled: bool` = `true` — Enables or disables split dragging.
- `split_offset: int` = `0` *(deprecated)* — The first element of `split_offsets`.
- `split_offsets: PackedInt32Array` = `PackedInt32Array(0)` — Offsets for each dragger in pixels.
- `touch_dragger_enabled: bool` = `false` — If `true`, a touch-friendly drag handle will be enabled for better usability on smaller screens.
- `vertical: bool` = `false` — If `true`, the SplitContainer will arrange its children vertically, rather than horizontally.

## Methods

- `clamp_split_offset(priority_index: int = 0) -> void` — Clamps the `split_offsets` values to ensure they are within valid ranges and do not overlap with each other.
- `get_drag_area_control() -> Control` *(deprecated)* — Returns the drag area Control.
- `get_drag_area_controls() -> Control[]` — Returns an Array of the drag area Controls.

## Signals

- `drag_ended()` — Emitted when the user ends dragging.
- `drag_started()` — Emitted when the user starts dragging.
- `dragged(offset: int)` — Emitted when any dragger is dragged by user.

## Enum DraggerVisibility

- `DRAGGER_VISIBLE = 0` — The split dragger icon is always visible when `autohide` is `false`, otherwise visible only when the cursor hovers it.
- `DRAGGER_HIDDEN = 1` — The split dragger icon is never visible regardless of the value of `autohide`.
- `DRAGGER_HIDDEN_COLLAPSED = 2` — The split dragger icon is not visible, and the split bar is collapsed to zero thickness.

## Theme items

- `touch_dragger_color: Color` (color) = `Color(1, 1, 1, 0.3)`
- `touch_dragger_hover_color: Color` (color) = `Color(1, 1, 1, 0.6)`
- `touch_dragger_pressed_color: Color` (color) = `Color(1, 1, 1, 1)`
- `autohide: int` (constant) = `1`
- `minimum_grab_thickness: int` (constant) = `6`
- `separation: int` (constant) = `12`
- `grabber: Texture2D` (icon)
- `h_grabber: Texture2D` (icon)
- `h_touch_dragger: Texture2D` (icon)
- `touch_dragger: Texture2D` (icon)
- `v_grabber: Texture2D` (icon)
- `v_touch_dragger: Texture2D` (icon)
- `split_bar_background: StyleBox` (style)
