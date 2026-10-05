# FlowContainer

**Inherits:** Container

A container that arranges its child controls horizontally or vertically and wraps them around at the borders.

A container that arranges its child controls horizontally or vertically and wraps them around at the borders. This is similar to how text in a book wraps around when no more words can fit on a line.

## Properties

- `alignment: FlowContainer.AlignmentMode` = `0` — The alignment of the container's children (must be one of `ALIGNMENT_BEGIN`, `ALIGNMENT_CENTER`, or `ALIGNMENT_END`).
- `last_wrap_alignment: FlowContainer.LastWrapAlignmentMode` = `0` — The wrap behavior of the last, partially filled row or column (must be one of `LAST_WRAP_ALIGNMENT_INHERIT`, `LAST_WRAP_ALIGNMENT_BEGIN`, `LAST_WRAP_ALIGNMENT_CENTER`, or `LAST_WRAP_ALIGNMENT_END`).
- `reverse_fill: bool` = `false` — If `true`, reverses fill direction.
- `vertical: bool` = `false` — If `true`, the FlowContainer will arrange its children vertically, rather than horizontally.

## Methods

- `get_line_count() -> int` *const* — Returns the current line count.

## Enum AlignmentMode

- `ALIGNMENT_BEGIN = 0` — The child controls will be arranged at the beginning of the container, i.e. top if orientation is vertical, left if orientation is horizontal (right for RTL layout).
- `ALIGNMENT_CENTER = 1` — The child controls will be centered in the container.
- `ALIGNMENT_END = 2` — The child controls will be arranged at the end of the container, i.e. bottom if orientation is vertical, right if orientation is horizontal (left for RTL layout).

## Enum LastWrapAlignmentMode

- `LAST_WRAP_ALIGNMENT_INHERIT = 0` — The last partially filled row or column will wrap aligned to the previous row or column in accordance with `alignment`.
- `LAST_WRAP_ALIGNMENT_BEGIN = 1` — The last partially filled row or column will wrap aligned to the beginning of the previous row or column.
- `LAST_WRAP_ALIGNMENT_CENTER = 2` — The last partially filled row or column will wrap aligned to the center of the previous row or column.
- `LAST_WRAP_ALIGNMENT_END = 3` — The last partially filled row or column will wrap aligned to the end of the previous row or column.

## Theme items

- `h_separation: int` (constant) = `4`
- `v_separation: int` (constant) = `4`
