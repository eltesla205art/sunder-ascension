# Quaternion


A unit quaternion used for representing 3D rotations.

The Quaternion built-in Variant type is a 4D data structure that represents rotation in the form of a Hamilton convention quaternion. Compared to the Basis type which can store both rotation and scale, quaternions can only store rotation. A Quaternion is composed by 4 floating-point components: `w`, `x`, `y`, and `z`. These components are very compact in memory, and because of this some operations are more efficient and less likely to cause floating-point errors.

## Properties

- `w: float` = `1.0` — W component of the quaternion.
- `x: float` = `0.0` — X component of the quaternion.
- `y: float` = `0.0` — Y component of the quaternion.
- `z: float` = `0.0` — Z component of the quaternion.

## Constructors

- `Quaternion() -> Quaternion` — Constructs a Quaternion identical to `IDENTITY`.
- `Quaternion(from: Quaternion) -> Quaternion` — Constructs a Quaternion as a copy of the given Quaternion.
- `Quaternion(arc_from: Vector3, arc_to: Vector3) -> Quaternion` — Constructs a Quaternion representing the shortest arc between `arc_from` and `arc_to`.
- `Quaternion(axis: Vector3, angle: float) -> Quaternion` — Constructs a Quaternion representing rotation around the `axis` by the given `angle`, in radians.
- `Quaternion(from: Basis) -> Quaternion` — Constructs a Quaternion from the given rotation Basis.
- `Quaternion(x: float, y: float, z: float, w: float) -> Quaternion` — Constructs a Quaternion defined by the given values.

## Methods

- `angle_to(to: Quaternion) -> float` *const* — Returns the angle between this quaternion and `to`.
- `dot(with: Quaternion) -> float` *const* — Returns the dot product between this quaternion and `with`.
- `exp() -> Quaternion` *const* — Returns the exponential of this quaternion.
- `from_euler(euler: Vector3) -> Quaternion` *static* — Constructs a new Quaternion from the given Vector3 of Euler angles, in radians.
- `get_angle() -> float` *const* — Returns the angle of the rotation represented by this quaternion.
- `get_axis() -> Vector3` *const* — Returns the rotation axis of the rotation represented by this quaternion.
- `get_euler(order: int = 2) -> Vector3` *const* — Returns this quaternion's rotation as a Vector3 of Euler angles, in radians.
- `inverse() -> Quaternion` *const* — Returns the inverse version of this quaternion, inverting the sign of every component except `w`.
- `is_equal_approx(to: Quaternion) -> bool` *const* — Returns `true` if this quaternion and `to` are approximately equal, by calling `@GlobalScope.is_equal_approx` on each component.
- `is_finite() -> bool` *const* — Returns `true` if this quaternion is finite, by calling `@GlobalScope.is_finite` on each component.
- `is_normalized() -> bool` *const* — Returns `true` if this quaternion is normalized.
- `length() -> float` *const* — Returns this quaternion's length, also called magnitude.
- `length_squared() -> float` *const* — Returns this quaternion's length, squared.
- `log() -> Quaternion` *const* — Returns the logarithm of this quaternion.
- `normalized() -> Quaternion` *const* — Returns a copy of this quaternion, normalized so that its length is `1.0`.
- `slerp(to: Quaternion, weight: float) -> Quaternion` *const* — Performs a spherical-linear interpolation with the `to` quaternion, given a `weight` and returns the result.
- `slerpni(to: Quaternion, weight: float) -> Quaternion` *const* — Performs a spherical-linear interpolation with the `to` quaternion, given a `weight` and returns the result.
- `spherical_cubic_interpolate(b: Quaternion, pre_a: Quaternion, post_b: Quaternion, weight: float) -> Quaternion` *const* — Performs a spherical cubic interpolation between quaternions `pre_a`, this quaternion, `b`, and `post_b`, by the given amount `weight`.
- `spherical_cubic_interpolate_in_time(b: Quaternion, pre_a: Quaternion, post_b: Quaternion, weight: float, b_t: float, pre_a_t: float, post_b_t: float) -> Quaternion` *const* — Performs a spherical cubic interpolation between quaternions `pre_a`, this quaternion, `b`, and `post_b`, by the given amount `weight`.

## Operators

- `operator !=(right: Quaternion) -> bool` — Returns `true` if the components of both quaternions are not exactly equal.
- `operator *(right: Quaternion) -> Quaternion` — Composes (multiplies) two quaternions.
- `operator *(right: Vector3) -> Vector3` — Rotates (multiplies) the `right` vector by this quaternion, returning a Vector3.
- `operator *(right: float) -> Quaternion` — Multiplies each component of the Quaternion by the right float value.
- `operator *(right: int) -> Quaternion` — Multiplies each component of the Quaternion by the right int value.
- `operator +(right: Quaternion) -> Quaternion` — Adds each component of the left Quaternion to the right Quaternion.
- `operator -(right: Quaternion) -> Quaternion` — Subtracts each component of the left Quaternion by the right Quaternion.
- `operator /(right: float) -> Quaternion` — Divides each component of the Quaternion by the right float value.
- `operator /(right: int) -> Quaternion` — Divides each component of the Quaternion by the right int value.
- `operator ==(right: Quaternion) -> bool` — Returns `true` if the components of both quaternions are exactly equal.
- `operator [](index: int) -> float` — Accesses each component of this quaternion by their index.
- `operator unary+() -> Quaternion` — Returns the same value as if the `+` was not there.
- `operator unary-() -> Quaternion` — Returns the negative value of the Quaternion.

## Constants

- `IDENTITY = Quaternion(0, 0, 0, 1)` — The identity quaternion, representing no rotation.
