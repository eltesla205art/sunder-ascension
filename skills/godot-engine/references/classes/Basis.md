# Basis


A 3×3 matrix for representing 3D rotation and scale.

The Basis built-in Variant type is a 3×3 matrix used to represent 3D rotation, scale, and shear. It is frequently used within a Transform3D. A Basis is composed by 3 axis vectors, each representing a column of the matrix: `x`, `y`, and `z`. The length of each axis (`Vector3.length`) influences the basis's scale, while the direction of all axes influence the rotation.

## Properties

- `x: Vector3` = `Vector3(1, 0, 0)` — The basis's X axis, and the column `0` of the matrix.
- `y: Vector3` = `Vector3(0, 1, 0)` — The basis's Y axis, and the column `1` of the matrix.
- `z: Vector3` = `Vector3(0, 0, 1)` — The basis's Z axis, and the column `2` of the matrix.

## Constructors

- `Basis() -> Basis` — Constructs a Basis identical to `IDENTITY`.
- `Basis(from: Basis) -> Basis` — Constructs a Basis as a copy of the given Basis.
- `Basis(axis: Vector3, angle: float) -> Basis` — Constructs a Basis that only represents rotation, rotated around the `axis` by the given `angle`, in radians.
- `Basis(from: Quaternion) -> Basis` — Constructs a Basis that only represents rotation from the given Quaternion.
- `Basis(x_axis: Vector3, y_axis: Vector3, z_axis: Vector3) -> Basis` — Constructs a Basis from 3 axis vectors.

## Methods

- `determinant() -> float` *const* — Returns the determinant of this basis's matrix.
- `from_euler(euler: Vector3, order: int = 2) -> Basis` *static* — Constructs a new Basis that only represents rotation from the given Vector3 of Euler angles, in radians. - The `Vector3.x` should contain the angle around the `x` axis (pitch); - The `Vector3.y` should contain the angle around the `y` axis (yaw); - The `Vector3.z` should contain the angle around the `z` axis (roll).
- `from_scale(scale: Vector3) -> Basis` *static* — Constructs a new Basis that only represents scale, with no rotation or shear, from the given `scale` vector.
- `get_euler(order: int = 2) -> Vector3` *const* — Returns this basis's rotation as a Vector3 of Euler angles, in radians.
- `get_rotation_quaternion() -> Quaternion` *const* — Returns this basis's rotation as a Quaternion.
- `get_scale() -> Vector3` *const* — Returns the length of each axis of this basis, as a Vector3.
- `inverse() -> Basis` *const* — Returns the inverse of this basis's matrix.
- `is_conformal() -> bool` *const* — Returns `true` if this basis is conformal.
- `is_equal_approx(b: Basis) -> bool` *const* — Returns `true` if this basis and `b` are approximately equal, by calling `@GlobalScope.is_equal_approx` on all vector components.
- `is_finite() -> bool` *const* — Returns `true` if this basis is finite, by calling `@GlobalScope.is_finite` on all vector components.
- `is_orthonormal() -> bool` *const* — Returns `true` if this basis is orthonormal.
- `looking_at(target: Vector3, up: Vector3 = Vector3(0, 1, 0), use_model_front: bool = false) -> Basis` *static* — Creates a new Basis with a rotation such that the forward axis (-Z) points towards the `target` position.
- `orthonormalized() -> Basis` *const* — Returns the orthonormalized version of this basis.
- `rotated(axis: Vector3, angle: float) -> Basis` *const* — Returns a copy of this basis rotated around the given `axis` by the given `angle` (in radians).
- `scaled(scale: Vector3) -> Basis` *const* — Returns this basis with each axis's components scaled by the given `scale`'s components.
- `scaled_local(scale: Vector3) -> Basis` *const* — Returns this basis with each axis scaled by the corresponding component in the given `scale`.
- `slerp(to: Basis, weight: float) -> Basis` *const* — Performs a spherical-linear interpolation with the `to` basis, given a `weight`.
- `tdotx(with: Vector3) -> float` *const* — Returns the transposed dot product between `with` and the `x` axis (see `transposed`).
- `tdoty(with: Vector3) -> float` *const* — Returns the transposed dot product between `with` and the `y` axis (see `transposed`).
- `tdotz(with: Vector3) -> float` *const* — Returns the transposed dot product between `with` and the `z` axis (see `transposed`).
- `transposed() -> Basis` *const* — Returns the transposed version of this basis.

## Operators

- `operator !=(right: Basis) -> bool` — Returns `true` if the components of both Basis matrices are not equal.
- `operator *(right: Basis) -> Basis` — Transforms (multiplies) the `right` basis by this basis.
- `operator *(right: Vector3) -> Vector3` — Transforms (multiplies) the `right` vector by this basis, returning a Vector3.
- `operator *(right: float) -> Basis` — Multiplies all components of the Basis by the given float.
- `operator *(right: int) -> Basis` — Multiplies all components of the Basis by the given int.
- `operator /(right: float) -> Basis` — Divides all components of the Basis by the given float.
- `operator /(right: int) -> Basis` — Divides all components of the Basis by the given int.
- `operator ==(right: Basis) -> bool` — Returns `true` if the components of both Basis matrices are exactly equal.
- `operator [](index: int) -> Vector3` — Accesses each axis (column) of this basis by their index.

## Constants

- `IDENTITY = Basis(1, 0, 0, 0, 1, 0, 0, 0, 1)` — The identity Basis.
- `FLIP_X = Basis(-1, 0, 0, 0, 1, 0, 0, 0, 1)` — When any basis is multiplied by `FLIP_X`, it negates all components of the `x` axis (the X column).
- `FLIP_Y = Basis(1, 0, 0, 0, -1, 0, 0, 0, 1)` — When any basis is multiplied by `FLIP_Y`, it negates all components of the `y` axis (the Y column).
- `FLIP_Z = Basis(1, 0, 0, 0, 1, 0, 0, 0, -1)` — When any basis is multiplied by `FLIP_Z`, it negates all components of the `z` axis (the Z column).
