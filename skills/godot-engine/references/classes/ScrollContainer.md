# ScrollContainer

**Inherits:** Container

A container used to provide scrollbars to a child control when needed.

A container used to provide a child control with scrollbars when needed. Scrollbars will automatically be drawn at the right (for vertical) or bottom (for horizontal) and will enable dragging to move the viewable Control (and its children) within the ScrollContainer. Scrollbars will also automatically resize the grabber based on the `Control.custom_minimum_size` of the Control relative to the ScrollContainer.

## Properties

- `clip_contents: bool` = `true` — 
- `draw_focus_border: bool` = `false` — If `true`, `focus` is drawn when the ScrollContainer or one of its descendant nodes is focused.
- `follow_focus: bool` = `false` — If `true`, the ScrollContainer will automatically scroll to focused children (including indirect children) to make sure they are fully visible.
- `horizontal_scroll_mode: ScrollContainer.ScrollMode` = `1` — Controls whether horizontal scrollbar can be used and when it should be visible.
- `propagate_maximum_size: bool` = `false` — 
- `scroll_deadzone: int` = `0` — Deadzone for touch scrolling.
- `scroll_hint_mode: ScrollContainer.ScrollHintMode` = `0` — The way which scroll hints (indicators that show that the content can still be scrolled in a certain direction) will be shown.
- `scroll_horizontal: int` = `0` — The current horizontal scroll value.
- `scroll_horizontal_by_default: bool` = `false` — If `true`, the mouse wheel scrolls the view horizontally, and holding `Shift` scrolls vertically.
- `scroll_horizontal_custom_step: float` = `-1.0` — Overrides the `ScrollBar.custom_step` used when clicking the internal scroll bar's horizontal increment and decrement buttons or when using arrow keys when the ScrollBar is focused.
- `scroll_vertical: int` = `0` — The current vertical scroll value.
- `scroll_vertical_custom_step: float` = `-1.0` — Overrides the `ScrollBar.custom_step` used when clicking the internal scroll bar's vertical increment and decrement buttons or when using arrow keys when the ScrollBar is focused.
- `tile_scroll_hint: bool` = `false` — If `true`, the scroll hint texture will be tiled instead of stretched.
- `vertical_scroll_mode: ScrollContainer.ScrollMode` = `1` — Controls whether vertical scrollbar can be used and when it should be visible.

## Methods

- `ensure_control_visible(control: Control) -> void` — Ensures the given `control` is visible (must be a direct or indirect child of the ScrollContainer).
- `get_h_scroll_bar() -> HScrollBar` — Returns the horizontal scrollbar HScrollBar of this ScrollContainer.
- `get_v_scroll_bar() -> VScrollBar` — Returns the vertical scrollbar VScrollBar of this ScrollContainer.

## Signals

- `scroll_ended()` — Emitted when scrolling stops when dragging the scrollable area with a touch event.
- `scroll_started()` — Emitted when scrolling starts when dragging the scrollable area with a touch event.

## Enum ScrollMode

- `SCROLL_MODE_DISABLED = 0` — Scrolling disabled, scrollbar will be invisible.
- `SCROLL_MODE_AUTO = 1` — Scrolling enabled, scrollbar will be visible only if necessary, i.e. container's content is bigger than the container.
- `SCROLL_MODE_SHOW_ALWAYS = 2` — Scrolling enabled, scrollbar will be always visible.
- `SCROLL_MODE_SHOW_NEVER = 3` — Scrolling enabled, scrollbar will be hidden.
- `SCROLL_MODE_RESERVE = 4` — Combines `SCROLL_MODE_AUTO` and `SCROLL_MODE_SHOW_ALWAYS`.
- `SCROLL_MODE_MAXIMIZE_FIRST = 5` — Behaves like `SCROLL_MODE_AUTO`, but makes the ScrollContainer report a minimum size based on its content (limited by `Control.custom_maximum_size` when set on the corresponding axis).

## Enum ScrollHintMode

- `SCROLL_HINT_MODE_DISABLED = 0` — Scroll hints will never be shown.
- `SCROLL_HINT_MODE_ALL = 1` — Scroll hints will be shown at the top and bottom (if vertical), or left and right (if horizontal).
- `SCROLL_HINT_MODE_TOP_AND_LEFT = 2` — Scroll hints will be shown at the top (if vertical), or the left (if horizontal).
- `SCROLL_HINT_MODE_BOTTOM_AND_RIGHT = 3` — Scroll hints will be shown at the bottom (if horizontal), or the right (if horizontal).
- `SCROLL_HINT_MODE_TOP_AND_BOTTOM = 4` — Scroll hints will be shown at the top and bottom.
- `SCROLL_HINT_MODE_LEFT_AND_RIGHT = 5` — Scroll hints will be shown on the left and right.
- `SCROLL_HINT_MODE_TOP = 6` — Scroll hint will be shown at the top.
- `SCROLL_HINT_MODE_BOTTOM = 7` — Scroll hint will be shown at the bottom.
- `SCROLL_HINT_MODE_LEFT = 8` — Scroll hint will be shown on the left.
- `SCROLL_HINT_MODE_RIGHT = 9` — Scroll hint will be shown on the right.

## Theme items

- `scroll_hint_horizontal_color: Color` (color) = `Color(0, 0, 0, 1)`
- `scroll_hint_vertical_color: Color` (color) = `Color(0, 0, 0, 1)`
- `scrollbar_h_separation: int` (constant) = `0`
- `scrollbar_margin_bottom: int` (constant) = `-1`
- `scrollbar_margin_left: int` (constant) = `-1`
- `scrollbar_margin_right: int` (constant) = `-1`
- `scrollbar_margin_top: int` (constant) = `-1`
- `scrollbar_v_separation: int` (constant) = `0`
- `scroll_hint_horizontal: Texture2D` (icon)
- `scroll_hint_vertical: Texture2D` (icon)
- `focus: StyleBox` (style)
- `panel: StyleBox` (style)
