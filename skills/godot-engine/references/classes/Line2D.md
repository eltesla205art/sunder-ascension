# Line2D

**Inherits:** Node2D

A 2D polyline that can optionally be textured.

This node draws a 2D polyline, i.e. a shape consisting of several points connected by segments. Line2D is not a mathematical polyline, i.e. the segments are not infinitely thin. It is intended for rendering and it can be colored and optionally textured. Warning: Certain configurations may be impossible to draw nicely, such as very sharp angles.

## Properties

- `antialiased: bool` = `false` — If `true`, the polyline's border will be anti-aliased.
- `begin_cap_mode: Line2D.LineCapMode` = `0` — The style of the beginning of the polyline, if `closed` is `false`.
- `closed: bool` = `false` — If `true` and the polyline has more than 2 points, the last point and the first one will be connected by a segment.
- `default_color: Color` = `Color(1, 1, 1, 1)` — The color of the polyline.
- `end_cap_mode: Line2D.LineCapMode` = `0` — The style of the end of the polyline, if `closed` is `false`.
- `gradient: Gradient` — The gradient is drawn through the whole line from start to finish.
- `joint_mode: Line2D.LineJointMode` = `0` — The style of the connections between segments of the polyline.
- `points: PackedVector2Array` = `PackedVector2Array()` — The points of the polyline, interpreted in local 2D coordinates.
- `round_precision: int` = `8` — The smoothness used for rounded joints and caps.
- `sharp_limit: float` = `2.0` — Determines the miter limit of the polyline.
- `texture: Texture2D` — The texture used for the polyline.
- `texture_mode: Line2D.LineTextureMode` = `0` — The style to render the `texture` of the polyline.
- `width: float` = `10.0` — The polyline's width.
- `width_curve: Curve` — The polyline's width curve.

## Methods

- `add_point(position: Vector2, index: int = -1) -> void` — Adds a point with the specified `position` relative to the polyline's own position.
- `clear_points() -> void` — Removes all points from the polyline, making it empty.
- `get_point_count() -> int` *const* — Returns the number of points in the polyline.
- `get_point_position(index: int) -> Vector2` *const* — Returns the position of the point at index `index`.
- `remove_point(index: int) -> void` — Removes the point at index `index` from the polyline.
- `set_point_position(index: int, position: Vector2) -> void` — Overwrites the position of the point at the given `index` with the supplied `position`.

## Enum LineJointMode

- `LINE_JOINT_SHARP = 0` — Makes the polyline's joints pointy, connecting the sides of the two segments by extending them until they intersect.
- `LINE_JOINT_BEVEL = 1` — Makes the polyline's joints bevelled/chamfered, connecting the sides of the two segments with a simple line.
- `LINE_JOINT_ROUND = 2` — Makes the polyline's joints rounded, connecting the sides of the two segments with an arc.

## Enum LineCapMode

- `LINE_CAP_NONE = 0` — Draws no line cap.
- `LINE_CAP_BOX = 1` — Draws the line cap as a box, slightly extending the first/last segment.
- `LINE_CAP_ROUND = 2` — Draws the line cap as a semicircle attached to the first/last segment.

## Enum LineTextureMode

- `LINE_TEXTURE_NONE = 0` — Takes the left pixels of the texture and renders them over the whole polyline.
- `LINE_TEXTURE_TILE = 1` — Tiles the texture over the polyline.
- `LINE_TEXTURE_STRETCH = 2` — Stretches the texture across the polyline.
