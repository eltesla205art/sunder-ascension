# AspectRatioContainer

**Inherits:** Container

A container that preserves the proportions of its child controls.

A container type that arranges its child controls in a way that preserves their proportions automatically when the container is resized. Useful when a container has a dynamic size and the child nodes must adjust their sizes accordingly without losing their aspect ratios.

## Properties

- `alignment_horizontal: AspectRatioContainer.AlignmentMode` = `1` — Specifies the horizontal relative position of child controls.
- `alignment_vertical: AspectRatioContainer.AlignmentMode` = `1` — Specifies the vertical relative position of child controls.
- `ratio: float` = `1.0` — The aspect ratio to enforce on child controls.
- `stretch_mode: AspectRatioContainer.StretchMode` = `2` — The stretch mode used to align child controls.

## Enum StretchMode

- `STRETCH_WIDTH_CONTROLS_HEIGHT = 0` — The height of child controls is automatically adjusted based on the width of the container.
- `STRETCH_HEIGHT_CONTROLS_WIDTH = 1` — The width of child controls is automatically adjusted based on the height of the container.
- `STRETCH_FIT = 2` — The bounding rectangle of child controls is automatically adjusted to fit inside the container while keeping the aspect ratio.
- `STRETCH_COVER = 3` — The width and height of child controls is automatically adjusted to make their bounding rectangle cover the entire area of the container while keeping the aspect ratio.

## Enum AlignmentMode

- `ALIGNMENT_BEGIN = 0` — Aligns child controls with the beginning (left or top) of the container.
- `ALIGNMENT_CENTER = 1` — Aligns child controls with the center of the container.
- `ALIGNMENT_END = 2` — Aligns child controls with the end (right or bottom) of the container.
