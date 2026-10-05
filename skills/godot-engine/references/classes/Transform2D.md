# Transform2D


A 2×3 matrix representing a 2D transformation.

The Transform2D built-in Variant type is a 2×3 matrix representing a transformation in 2D space. It contains three Vector2 values: `x`, `y`, and `origin`. Together, they can represent translation, rotation, scale, and skew. The `x` and `y` axes form a 2×2 matrix, known as the transform's basis.

## Properties

- `origin: Vector2` = `Vector2(0, 0)` — The translation offset of this transform, and the column `2` of the matrix.
- `x: Vector2` = `Vector2(1, 0)` — The transform basis's X axis, and the column `0` of the matrix.
- `y: Vector2` = `Vector2(0, 1)` — The transform basis's Y axis, and the column `1` of the matrix.

## Constructors

- `Transform2D() -> Transform2D` — Constructs a Transform2D identical to `IDENTITY`.
- `Transform2D(from: Transform2D) -> Transform2D` — Constructs a Transform2D as a copy of the given Transform2D.
- `Transform2D(rotation: float, position: Vector2) -> Transform2D` — Constructs a Transform2D from a given angle (in radians) and position.
- `Transform2D(rotation: float, scale: Vector2, skew: float, position: Vector2) -> Transform2D` — Constructs a Transform2D from a given angle (in radians), scale, skew (in radians), and position.
- `Transform2D(x_axis: Vector2, y_axis: Vector2, origin: Vector2) -> Transform2D` — Constructs a Transform2D from 3 Vector2 values representing `x`, `y`, and the `origin` (the three matrix columns).

## Methods

- `affine_inverse() -> Transform2D` *const* — Returns the inverted version of this transform.
- `basis_xform(v: Vector2) -> Vector2` *const* — Returns a copy of the `v` vector, transformed (multiplied) by the transform basis's matrix.
- `basis_xform_inv(v: Vector2) -> Vector2` *const* — Returns a copy of the `v` vector, transformed (multiplied) by the inverse transform basis's matrix (see `inverse`).
- `determinant() -> float` *const* — Returns the determinant of this transform basis's matrix.
- `get_origin() -> Vector2` *const* — Returns this transform's translation.
- `get_rotation() -> float` *const* — Returns this transform's rotation (in radians).
- `get_scale() -> Vector2` *const* — Returns the length of both `x` and `y`, as a Vector2.
- `get_skew() -> float` *const* — Returns this transform's skew (in radians).
- `interpolate_with(xform: Transform2D, weight: float) -> Transform2D` *const* — Returns the result of the linear interpolation between this transform and `xform` by the given `weight`.
- `inverse() -> Transform2D` *const* — Returns the inverted version of this transform.
- `is_conformal() -> bool` *const* — Returns `true` if this transform's basis is conformal.
- `is_equal_approx(xform: Transform2D) -> bool` *const* — Returns `true` if this transform and `xform` are approximately equal, by running `@GlobalScope.is_equal_approx` on each component.
- `is_finite() -> bool` *const* — Returns `true` if this transform is finite, by calling `@GlobalScope.is_finite` on each component.
- `looking_at(target: Vector2 = Vector2(0, 0)) -> Transform2D` *const* — Returns a copy of the transform rotated such that the rotated X-axis points towards the `target` position, in global space.
- `orthonormalized() -> Transform2D` *const* — Returns a copy of this transform with its basis orthonormalized.
- `rotated(angle: float) -> Transform2D` *const* — Returns a copy of this transform rotated by the given `angle` (in radians).
- `rotated_local(angle: float) -> Transform2D` *const* — Returns a copy of the transform rotated by the given `angle` (in radians).
- `scaled(scale: Vector2) -> Transform2D` *const* — Returns a copy of the transform scaled by the given `scale` factor.
- `scaled_local(scale: Vector2) -> Transform2D` *const* — Returns a copy of the transform scaled by the given `scale` factor.
- `translated(offset: Vector2) -> Transform2D` *const* — Returns a copy of the transform translated by the given `offset`.
- `translated_local(offset: Vector2) -> Transform2D` *const* — Returns a copy of the transform translated by the given `offset`.

## Operators

- `operator !=(right: Transform2D) -> bool` — Returns `true` if the components of both transforms are not equal.
- `operator *(right: PackedVector2Array) -> PackedVector2Array` — Transforms (multiplies) every Vector2 element of the given PackedVector2Array by this transformation matrix.
- `operator *(right: Rect2) -> Rect2` — Transforms (multiplies) the Rect2 by this transformation matrix.
- `operator *(right: Transform2D) -> Transform2D` — Transforms (multiplies) this transform by the `right` transform.
- `operator *(right: Vector2) -> Vector2` — Transforms (multiplies) the Vector2 by this transformation matrix.
- `operator *(right: float) -> Transform2D` — Multiplies all components of the Transform2D by the given float, including the `origin`.
- `operator *(right: int) -> Transform2D` — Multiplies all components of the Transform2D by the given int, including the `origin`.
- `operator /(right: float) -> Transform2D` — Divides all components of the Transform2D by the given float, including the `origin`.
- `operator /(right: int) -> Transform2D` — Divides all components of the Transform2D by the given int, including the `origin`.
- `operator ==(right: Transform2D) -> bool` — Returns `true` if the components of both transforms are exactly equal.
- `operator [](index: int) -> Vector2` — Accesses each axis (column) of this transform by their index.

## Constants

- `IDENTITY = Transform2D(1, 0, 0, 1, 0, 0)` — The identity Transform2D.
- `FLIP_X = Transform2D(-1, 0, 0, 1, 0, 0)` — When any transform is multiplied by `FLIP_X`, it negates all components of the `x` axis (the X column).
- `FLIP_Y = Transform2D(1, 0, 0, -1, 0, 0)` — When any transform is multiplied by `FLIP_Y`, it negates all components of the `y` axis (the Y column).
