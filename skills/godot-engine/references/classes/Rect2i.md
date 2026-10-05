# Rect2i


A 2D axis-aligned bounding box using integer coordinates.

The Rect2i built-in Variant type represents an axis-aligned rectangle in a 2D space, using integer coordinates. It is defined by its `position` and `size`, which are Vector2i. Because it does not rotate, it is frequently used for fast overlap tests (see `intersects`). For floating-point coordinates, see Rect2.

## Properties

- `end: Vector2i` = `Vector2i(0, 0)` — The ending point.
- `position: Vector2i` = `Vector2i(0, 0)` — The origin point.
- `size: Vector2i` = `Vector2i(0, 0)` — The rectangle's width and height, starting from `position`.

## Constructors

- `Rect2i() -> Rect2i` — Constructs a Rect2i with its `position` and `size` set to `Vector2i.ZERO`.
- `Rect2i(from: Rect2i) -> Rect2i` — Constructs a Rect2i as a copy of the given Rect2i.
- `Rect2i(from: Rect2) -> Rect2i` — Constructs a Rect2i from a Rect2.
- `Rect2i(position: Vector2i, size: Vector2i) -> Rect2i` — Constructs a Rect2i by `position` and `size`.
- `Rect2i(x: int, y: int, width: int, height: int) -> Rect2i` — Constructs a Rect2i by setting its `position` to (`x`, `y`), and its `size` to (`width`, `height`).

## Methods

- `abs() -> Rect2i` *const* — Returns a Rect2i equivalent to this rectangle, with its width and height modified to be non-negative values, and with its `position` being the top-left corner of the rectangle.
- `encloses(b: Rect2i) -> bool` *const* — Returns `true` if this Rect2i completely encloses another one.
- `expand(to: Vector2i) -> Rect2i` *const* — Returns a copy of this rectangle expanded to align the edges with the given `to` point, if necessary.
- `get_area() -> int` *const* — Returns the rectangle's area.
- `get_center() -> Vector2i` *const* — Returns the center point of the rectangle.
- `grow(amount: int) -> Rect2i` *const* — Returns a copy of this rectangle extended on all sides by the given `amount`.
- `grow_individual(left: int, top: int, right: int, bottom: int) -> Rect2i` *const* — Returns a copy of this rectangle with its `left`, `top`, `right`, and `bottom` sides extended by the given amounts.
- `grow_side(side: int, amount: int) -> Rect2i` *const* — Returns a copy of this rectangle with its `side` extended by the given `amount` (see `Side` constants).
- `has_area() -> bool` *const* — Returns `true` if this rectangle has positive width and height.
- `has_point(point: Vector2i) -> bool` *const* — Returns `true` if the rectangle contains the given `point`.
- `intersection(b: Rect2i) -> Rect2i` *const* — Returns the intersection between this rectangle and `b`.
- `intersects(b: Rect2i) -> bool` *const* — Returns `true` if this rectangle overlaps with the `b` rectangle.
- `merge(b: Rect2i) -> Rect2i` *const* — Returns a Rect2i that encloses both this rectangle and `b` around the edges.

## Operators

- `operator !=(right: Rect2i) -> bool` — Returns `true` if the `position` or `size` of both rectangles are not equal.
- `operator ==(right: Rect2i) -> bool` — Returns `true` if both `position` and `size` of the rectangles are equal, respectively.
