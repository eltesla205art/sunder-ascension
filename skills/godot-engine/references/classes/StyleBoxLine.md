# StyleBoxLine

**Inherits:** StyleBox

A StyleBox that displays a single line of a given color and thickness.

A StyleBox that displays a single line of a given color and thickness. The line can be either horizontal or vertical. Useful for separators.

## Properties

- `color: Color` = `Color(0, 0, 0, 1)` — The line's color.
- `grow_begin: float` = `1.0` — The number of pixels the line will extend before the StyleBoxLine's bounds.
- `grow_end: float` = `1.0` — The number of pixels the line will extend past the StyleBoxLine's bounds.
- `thickness: int` = `1` — The line's thickness in pixels.
- `vertical: bool` = `false` — If `true`, the line will be vertical.
