# StyleBox

**Inherits:** Resource

Abstract base class for defining stylized boxes for UI elements.

StyleBox is an abstract base class for drawing stylized boxes for UI elements. It is used for panels, buttons, LineEdit backgrounds, Tree backgrounds, etc. and also for testing a transparency mask for pointer signals. If mask test fails on a StyleBox assigned as mask to a control, clicks and motion signals will go through it to the one below. Note: For control nodes that have Theme Properties, the `focus` StyleBox is displayed over the `normal`, `hover` or `pressed` StyleBox.

## Properties

- `content_margin_bottom: float` = `-1.0` — The bottom margin for the contents of this style box.
- `content_margin_left: float` = `-1.0` — The left margin for the contents of this style box.
- `content_margin_right: float` = `-1.0` — The right margin for the contents of this style box.
- `content_margin_top: float` = `-1.0` — The top margin for the contents of this style box.

## Methods

- `_draw(to_canvas_item: RID, rect: Rect2) -> void` *virtual required const*
- `_get_draw_rect(rect: Rect2) -> Rect2` *virtual const*
- `_get_minimum_size() -> Vector2` *virtual const* — Virtual method to be implemented by the user.
- `_test_mask(point: Vector2, rect: Rect2) -> bool` *virtual const*
- `draw(canvas_item: RID, rect: Rect2) -> void` *const* — Draws this stylebox using a canvas item identified by the given RID.
- `get_content_margin(margin: Side) -> float` *const* — Returns the default margin of the specified `Side`.
- `get_current_item_drawn() -> CanvasItem` *const* — Returns the CanvasItem that handles its `CanvasItem.NOTIFICATION_DRAW` or `CanvasItem._draw` callback at this moment.
- `get_margin(margin: Side) -> float` *const* — Returns the content margin offset for the specified `Side`.
- `get_minimum_size() -> Vector2` *const* — Returns the minimum size that this stylebox can be shrunk to.
- `get_offset() -> Vector2` *const* — Returns the "offset" of a stylebox.
- `set_content_margin(margin: Side, offset: float) -> void` — Sets the default value of the specified `Side` to `offset` pixels.
- `set_content_margin_all(offset: float) -> void` — Sets the default margin to `offset` pixels for all sides.
- `test_mask(point: Vector2, rect: Rect2) -> bool` *const* — Test a position in a rectangle, return whether it passes the mask test.
