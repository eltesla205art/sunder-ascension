# Path3D

**Inherits:** Node3D

Contains a Curve3D path for PathFollow3D nodes to follow.

Can have PathFollow3D child nodes moving along the Curve3D. See PathFollow3D for more information on the usage. Note that the path is considered as relative to the moved nodes (children of PathFollow3D). As such, the curve should usually start with a zero vector `(0, 0, 0)`.

## Properties

- `curve: Curve3D` — A Curve3D describing the path.
- `debug_custom_color: Color` = `Color(0, 0, 0, 1)` — The custom color used to draw the path in the editor.

## Signals

- `curve_changed()` — Emitted when the `curve` changes.
- `debug_color_changed()` — Emitted when the `debug_custom_color` changes.
