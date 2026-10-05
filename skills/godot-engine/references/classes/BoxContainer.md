# BoxContainer

**Inherits:** Container

A container that arranges its child controls horizontally or vertically.

A container that arranges its child controls horizontally or vertically, rearranging them automatically when their minimum size changes.

## Properties

- `alignment: BoxContainer.AlignmentMode` = `0` — The alignment of the container's children (must be one of `ALIGNMENT_BEGIN`, `ALIGNMENT_CENTER`, or `ALIGNMENT_END`).
- `reverse_sort: bool` = `false` — If `true`, the BoxContainer will arrange its children in reverse order.
- `vertical: bool` = `false` — If `true`, the BoxContainer will arrange its children vertically, rather than horizontally.

## Methods

- `add_spacer(begin: bool) -> Control` — Adds a Control node to the box as a spacer.

## Enum AlignmentMode

- `ALIGNMENT_BEGIN = 0` — The child controls will be arranged at the beginning of the container, i.e. top if orientation is vertical, left if orientation is horizontal (right for RTL layout).
- `ALIGNMENT_CENTER = 1` — The child controls will be centered in the container.
- `ALIGNMENT_END = 2` — The child controls will be arranged at the end of the container, i.e. bottom if orientation is vertical, right if orientation is horizontal (left for RTL layout).

## Theme items

- `separation: int` (constant) = `4`
