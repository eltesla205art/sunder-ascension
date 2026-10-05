# Transform3D


A 3×4 matrix representing a 3D transformation.

The Transform3D built-in Variant type is a 3×4 matrix representing a transformation in 3D space. It contains a Basis, which on its own can represent rotation, scale, and shear. Additionally, combined with its own `origin`, the transform can also represent a translation. For a general introduction, see the Matrices and transforms tutorial.

## Properties

- `basis: Basis` = `Basis(1, 0, 0, 0, 1, 0, 0, 0, 1)` — The Basis of this transform.
- `origin: Vector3` = `Vector3(0, 0, 0)` — The translation offset of this transform.

## Constructors

- `Transform3D() -> Transform3D` — Constructs a Transform3D identical to `IDENTITY`.
- `Transform3D(from: Transform3D) -> Transform3D` — Constructs a Transform3D as a copy of the given Transform3D.
- `Transform3D(basis: Basis, origin: Vector3) -> Transform3D` — Constructs a Transform3D from a Basis and Vector3.
- `Transform3D(from: Projection) -> Transform3D` — Constructs a Transform3D from a Projection.
- `Transform3D(x_axis: Vector3, y_axis: Vector3, z_axis: Vector3, origin: Vector3) -> Transform3D` — Constructs a Transform3D from four Vector3 values (also called matrix columns).

## Methods

- `affine_inverse() -> Transform3D` *const* — Returns the inverted version of this transform.
- `interpolate_with(xform: Transform3D, weight: float) -> Transform3D` *const* — Returns the result of the linear interpolation between this transform and `xform` by the given `weight`.
- `inverse() -> Transform3D` *const* — Returns the inverted version of this transform.
- `is_equal_approx(xform: Transform3D) -> bool` *const* — Returns `true` if this transform and `xform` are approximately equal, by running `@GlobalScope.is_equal_approx` on each component.
- `is_finite() -> bool` *const* — Returns `true` if this transform is finite, by calling `@GlobalScope.is_finite` on each component.
- `looking_at(target: Vector3, up: Vector3 = Vector3(0, 1, 0), use_model_front: bool = false) -> Transform3D` *const* — Returns a copy of this transform rotated so that the forward axis (-Z) points towards the `target` position.
- `orthonormalized() -> Transform3D` *const* — Returns a copy of this transform with its `basis` orthonormalized.
- `rotated(axis: Vector3, angle: float) -> Transform3D` *const* — Returns a copy of this transform rotated around the given `axis` by the given `angle` (in radians).
- `rotated_local(axis: Vector3, angle: float) -> Transform3D` *const* — Returns a copy of this transform rotated around the given `axis` by the given `angle` (in radians).
- `scaled(scale: Vector3) -> Transform3D` *const* — Returns a copy of this transform scaled by the given `scale` factor.
- `scaled_local(scale: Vector3) -> Transform3D` *const* — Returns a copy of this transform scaled by the given `scale` factor.
- `translated(offset: Vector3) -> Transform3D` *const* — Returns a copy of this transform translated by the given `offset`.
- `translated_local(offset: Vector3) -> Transform3D` *const* — Returns a copy of this transform translated by the given `offset`.

## Operators

- `operator !=(right: Transform3D) -> bool` — Returns `true` if the components of both transforms are not equal.
- `operator *(right: AABB) -> AABB` — Transforms (multiplies) the AABB by this transformation matrix.
- `operator *(right: PackedVector3Array) -> PackedVector3Array` — Transforms (multiplies) every Vector3 element of the given PackedVector3Array by this transformation matrix.
- `operator *(right: Plane) -> Plane` — Transforms (multiplies) the Plane by this transformation matrix.
- `operator *(right: Transform3D) -> Transform3D` — Transforms (multiplies) this transform by the `right` transform.
- `operator *(right: Vector3) -> Vector3` — Transforms (multiplies) the Vector3 by this transformation matrix.
- `operator *(right: float) -> Transform3D` — Multiplies all components of the Transform3D by the given float, including the `origin`.
- `operator *(right: int) -> Transform3D` — Multiplies all components of the Transform3D by the given int, including the `origin`.
- `operator /(right: float) -> Transform3D` — Divides all components of the Transform3D by the given float, including the `origin`.
- `operator /(right: int) -> Transform3D` — Divides all components of the Transform3D by the given int, including the `origin`.
- `operator ==(right: Transform3D) -> bool` — Returns `true` if the components of both transforms are exactly equal.

## Constants

- `IDENTITY = Transform3D(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)` — The identity Transform3D.
- `FLIP_X = Transform3D(-1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)` — Transform3D with mirroring applied perpendicular to the YZ plane.
- `FLIP_Y = Transform3D(1, 0, 0, 0, -1, 0, 0, 0, 1, 0, 0, 0)` — Transform3D with mirroring applied perpendicular to the XZ plane.
- `FLIP_Z = Transform3D(1, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0)` — Transform3D with mirroring applied perpendicular to the XY plane.
