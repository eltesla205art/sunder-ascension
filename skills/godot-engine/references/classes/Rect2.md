# Rect2


A 2D axis-aligned bounding box using floating-point coordinates.

The Rect2 built-in Variant type represents an axis-aligned rectangle in a 2D space. It is defined by its `position` and `size`, which are Vector2. It is frequently used for fast overlap tests (see `intersects`). Although Rect2 itself is axis-aligned, it can be combined with Transform2D to represent a rotated or skewed rectangle.

## Properties

- `end: Vector2` = `Vector2(0, 0)` — The ending point.
- `position: Vector2` = `Vector2(0, 0)` — The origin point.
- `size: Vector2` = `Vector2(0, 0)` — The rectangle's width and height, starting from `position`.

## Constructors

- `Rect2() -> Rect2` — Constructs a Rect2 with its `position` and `size` set to `Vector2.ZERO`.
- `Rect2(from: Rect2) -> Rect2` — Constructs a Rect2 as a copy of the given Rect2.
- `Rect2(from: Rect2i) -> Rect2` — Constructs a Rect2 from a Rect2i.
- `Rect2(position: Vector2, size: Vector2) -> Rect2` — Constructs a Rect2 by `position` and `size`.
- `Rect2(x: float, y: float, width: float, height: float) -> Rect2` — Constructs a Rect2 by setting its `position` to (`x`, `y`), and its `size` to (`width`, `height`).

## Methods

- `abs() -> Rect2` *const* — Returns a Rect2 equivalent to this rectangle, with its width and height modified to be non-negative values, and with its `position` being the top-left corner of the rectangle.
- `encloses(b: Rect2) -> bool` *const* — Returns `true` if this rectangle completely encloses the `b` rectangle.
- `expand(to: Vector2) -> Rect2` *const* — Returns a copy of this rectangle expanded to align the edges with the given `to` point, if necessary.
- `get_area() -> float` *const* — Returns the rectangle's area.
- `get_center() -> Vector2` *const* — Returns the center point of the rectangle.
- `get_support(direction: Vector2) -> Vector2` *const* — Returns the vertex's position of this rect that's the farthest in the given direction.
- `grow(amount: float) -> Rect2` *const* — Returns a copy of this rectangle extended on all sides by the given `amount`.
- `grow_individual(left: float, top: float, right: float, bottom: float) -> Rect2` *const* — Returns a copy of this rectangle with its `left`, `top`, `right`, and `bottom` sides extended by the given amounts.
- `grow_side(side: int, amount: float) -> Rect2` *const* — Returns a copy of this rectangle with its `side` extended by the given `amount` (see `Side` constants).
- `has_area() -> bool` *const* — Returns `true` if this rectangle has positive width and height.
- `has_point(point: Vector2) -> bool` *const* — Returns `true` if the rectangle contains the given `point`.
- `intersection(b: Rect2) -> Rect2` *const* — Returns the intersection between this rectangle and `b`.
- `intersects(b: Rect2, include_borders: bool = false) -> bool` *const* — Returns `true` if this rectangle overlaps with the `b` rectangle.
- `is_equal_approx(rect: Rect2) -> bool` *const* — Returns `true` if this rectangle and `rect` are approximately equal, by calling `Vector2.is_equal_approx` on the `position` and the `size`.
- `is_finite() -> bool` *const* — Returns `true` if this rectangle's values are finite, by calling `Vector2.is_finite` on the `position` and the `size`.
- `merge(b: Rect2) -> Rect2` *const* — Returns a Rect2 that encloses both this rectangle and `b` around the edges.

## Operators

- `operator !=(right: Rect2) -> bool` — Returns `true` if the `position` or `size` of both rectangles are not equal.
- `operator *(right: Transform2D) -> Rect2` — Inversely transforms (multiplies) the Rect2 by the given Transform2D transformation matrix, under the assumption that the transformation basis is orthonormal (i.e. rotation/reflection is fine, scaling/skew is not).
- `operator ==(right: Rect2) -> bool` — Returns `true` if both `position` and `size` of the rectangles are exactly equal, respectively.
