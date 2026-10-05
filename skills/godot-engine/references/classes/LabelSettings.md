# LabelSettings

**Inherits:** Resource

Provides common settings to customize the text in a Label.

LabelSettings is a resource that provides common settings to customize the text in a Label. It will take priority over the properties defined in `Control.theme`. The resource can be shared between multiple labels and changed on the fly, making it a convenient and flexible way to set up text style.

## Properties

- `font: Font` — Font used for the text.
- `font_color: Color` = `Color(1, 1, 1, 1)` — Color of the text.
- `font_size: int` = `16` — Size of the text.
- `line_spacing: float` = `3.0` — Additional vertical spacing between lines (in pixels), spacing is added to line descent.
- `outline_color: Color` = `Color(1, 1, 1, 1)` — The color of the outline.
- `outline_size: int` = `0` — Text outline size.
- `paragraph_spacing: float` = `0.0` — Vertical space between paragraphs.
- `shadow_color: Color` = `Color(0, 0, 0, 0)` — Color of the shadow effect.
- `shadow_offset: Vector2` = `Vector2(1, 1)` — Offset of the shadow effect, in pixels.
- `shadow_size: int` = `1` — Size of the shadow effect.
- `stacked_outline_count: int` = `0` — The number of stacked outlines.
- `stacked_outline_{index}/color: Color` = `Color(0, 0, 0, 1)` — The color of the outline at `index`.
- `stacked_outline_{index}/size: int` = `0` — The size of the outline at `index`.
- `stacked_shadow_count: int` = `0` — The number of stacked shadows.
- `stacked_shadow_{index}/color: Color` = `Color(0, 0, 0, 1)` — The color of the shadow at `index`.
- `stacked_shadow_{index}/offset: Vector2` = `Vector2(1, 1)` — The offset of the shadow at `index`.
- `stacked_shadow_{index}/outline_size: int` = `0` — The size of the shadow outline at `index`.

## Methods

- `add_stacked_outline(index: int = -1) -> void` — Adds a new stacked outline to the label at the given `index`.
- `add_stacked_shadow(index: int = -1) -> void` — Adds a new stacked shadow to the label at the given `index`.
- `get_stacked_outline_color(index: int) -> Color` *const* — Returns the color of the stacked outline at `index`.
- `get_stacked_outline_size(index: int) -> int` *const* — Returns the size of the stacked outline at `index`.
- `get_stacked_shadow_color(index: int) -> Color` *const* — Returns the color of the stacked shadow at `index`.
- `get_stacked_shadow_offset(index: int) -> Vector2` *const* — Returns the offset of the stacked shadow at `index`.
- `get_stacked_shadow_outline_size(index: int) -> int` *const* — Returns the outline size of the stacked shadow at `index`.
- `move_stacked_outline(from_index: int, to_position: int) -> void` — Moves the stacked outline at index `from_index` to the given position `to_position` in the array.
- `move_stacked_shadow(from_index: int, to_position: int) -> void` — Moves the stacked shadow at index `from_index` to the given position `to_position` in the array.
- `remove_stacked_outline(index: int) -> void` — Removes the stacked outline at index `index`.
- `remove_stacked_shadow(index: int) -> void` — Removes the stacked shadow at index `index`.
- `set_stacked_outline_color(index: int, color: Color) -> void` — Sets the color of the stacked outline identified by the given `index` to `color`.
- `set_stacked_outline_size(index: int, size: int) -> void` — Sets the size of the stacked outline identified by the given `index` to `size`.
- `set_stacked_shadow_color(index: int, color: Color) -> void` — Sets the color of the stacked shadow identified by the given `index` to `color`.
- `set_stacked_shadow_offset(index: int, offset: Vector2) -> void` — Sets the offset of the stacked shadow identified by the given `index` to `offset`.
- `set_stacked_shadow_outline_size(index: int, size: int) -> void` — Sets the outline size of the stacked shadow identified by the given `index` to `size`.
