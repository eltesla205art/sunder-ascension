# Projection


A 4×4 matrix for 3D projective transformations.

A 4×4 matrix used for 3D projective transformations. It can represent transformations such as translation, rotation, scaling, shearing, and perspective division. It consists of four Vector4 columns. For purely linear transformations (translation, rotation, and scale), it is recommended to use Transform3D, as it is more performant and requires less memory.

## Properties

- `w: Vector4` = `Vector4(0, 0, 0, 1)` — The projection matrix's W vector (column 3).
- `x: Vector4` = `Vector4(1, 0, 0, 0)` — The projection matrix's X vector (column 0).
- `y: Vector4` = `Vector4(0, 1, 0, 0)` — The projection matrix's Y vector (column 1).
- `z: Vector4` = `Vector4(0, 0, 1, 0)` — The projection matrix's Z vector (column 2).

## Constructors

- `Projection() -> Projection` — Constructs a default-initialized Projection identical to `IDENTITY`.
- `Projection(from: Projection) -> Projection` — Constructs a Projection as a copy of the given Projection.
- `Projection(from: Transform3D) -> Projection` — Constructs a Projection as a copy of the given Transform3D.
- `Projection(x_axis: Vector4, y_axis: Vector4, z_axis: Vector4, w_axis: Vector4) -> Projection` — Constructs a Projection from four Vector4 values (matrix columns).

## Methods

- `create_depth_correction(flip_y: bool) -> Projection` *static* — Creates a new Projection that projects positions from a depth range of `-1` to `1` to one that ranges from `0` to `1`, and flips the projected positions vertically, according to `flip_y`.
- `create_fit_aabb(aabb: AABB) -> Projection` *static* — Creates a new Projection that scales a given projection to fit around a given AABB in projection space.
- `create_for_hmd(eye: int, aspect: float, intraocular_dist: float, display_width: float, display_to_lens: float, oversample: float, z_near: float, z_far: float) -> Projection` *static* — Creates a new Projection for projecting positions onto a head-mounted display with the given X:Y aspect ratio, distance between eyes, display width, distance to lens, oversampling factor, and depth clipping planes.
- `create_frustum(left: float, right: float, bottom: float, top: float, z_near: float, z_far: float) -> Projection` *static* — Creates a new Projection that projects positions in a frustum with the given clipping planes.
- `create_frustum_aspect(size: float, aspect: float, offset: Vector2, z_near: float, z_far: float, flip_fov: bool = false) -> Projection` *static* — Creates a new Projection that projects positions in a frustum with the given size, X:Y aspect ratio, offset, and clipping planes.
- `create_light_atlas_rect(rect: Rect2) -> Projection` *static* — Creates a new Projection that projects positions into the given Rect2.
- `create_orthogonal(left: float, right: float, bottom: float, top: float, z_near: float, z_far: float) -> Projection` *static* — Creates a new Projection that projects positions using an orthogonal projection with the given clipping planes.
- `create_orthogonal_aspect(size: float, aspect: float, z_near: float, z_far: float, flip_fov: bool = false) -> Projection` *static* — Creates a new Projection that projects positions using an orthogonal projection with the given size, X:Y aspect ratio, and clipping planes.
- `create_perspective(fovy: float, aspect: float, z_near: float, z_far: float, flip_fov: bool = false) -> Projection` *static* — Creates a new Projection that projects positions using a perspective projection with the given Y-axis field of view (in degrees), X:Y aspect ratio, and clipping planes.
- `create_perspective_hmd(fovy: float, aspect: float, z_near: float, z_far: float, flip_fov: bool, eye: int, intraocular_dist: float, convergence_dist: float) -> Projection` *static* — Creates a new Projection that projects positions using a perspective projection with the given Y-axis field of view (in degrees), X:Y aspect ratio, and clipping distances.
- `determinant() -> float` *const* — Returns a scalar value that is the signed factor by which areas are scaled by this matrix.
- `flipped_y() -> Projection` *const* — Returns a copy of this Projection with the signs of the values of the Y column flipped.
- `get_aspect() -> float` *const* — Returns the X:Y aspect ratio of this Projection's viewport.
- `get_far_plane_half_extents() -> Vector2` *const* — Returns the dimensions of the far clipping plane of the projection, divided by two.
- `get_fov() -> float` *const* — Returns the horizontal field of view of the projection (in degrees).
- `get_fovy(fovx: float, aspect: float) -> float` *static* — Returns the vertical field of view of the projection (in degrees) associated with the given horizontal field of view (in degrees) and aspect ratio.
- `get_lod_multiplier() -> float` *const* — Returns the factor by which the visible level of detail is scaled by this Projection.
- `get_pixels_per_meter(for_pixel_width: int) -> int` *const* — Returns `for_pixel_width` divided by the viewport's width measured in meters on the near plane, after this Projection is applied.
- `get_projection_plane(plane: int) -> Plane` *const* — Returns the clipping plane of this Projection whose index is given by `plane`.
- `get_viewport_half_extents() -> Vector2` *const* — Returns the dimensions of the viewport plane that this Projection projects positions onto, divided by two.
- `get_z_far() -> float` *const* — Returns the distance for this Projection beyond which positions are clipped.
- `get_z_near() -> float` *const* — Returns the distance for this Projection before which positions are clipped.
- `inverse() -> Projection` *const* — Returns a Projection that performs the inverse of this Projection's projective transformation.
- `is_orthogonal() -> bool` *const* — Returns `true` if this Projection performs an orthogonal projection.
- `jitter_offseted(offset: Vector2) -> Projection` *const* — Returns a Projection with the X and Y values from the given Vector2 added to the first and second values of the final column respectively.
- `perspective_znear_adjusted(new_znear: float) -> Projection` *const* — Returns a Projection with the near clipping distance adjusted to be `new_znear`.

## Operators

- `operator !=(right: Projection) -> bool` — Returns `true` if the projections are not equal.
- `operator *(right: Projection) -> Projection` — Returns a Projection that applies the combined transformations of this Projection and `right`.
- `operator *(right: Vector4) -> Vector4` — Projects (multiplies) the given Vector4 by this Projection matrix.
- `operator ==(right: Projection) -> bool` — Returns `true` if the projections are equal.
- `operator [](index: int) -> Vector4` — Returns the column of the Projection with the given index.

## Enum Planes

- `PLANE_NEAR = 0` — The index value of the projection's near clipping plane.
- `PLANE_FAR = 1` — The index value of the projection's far clipping plane.
- `PLANE_LEFT = 2` — The index value of the projection's left clipping plane.
- `PLANE_TOP = 3` — The index value of the projection's top clipping plane.
- `PLANE_RIGHT = 4` — The index value of the projection's right clipping plane.
- `PLANE_BOTTOM = 5` — The index value of the projection bottom clipping plane.

## Constants

- `IDENTITY = Projection(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1)` — A Projection with no transformation defined.
- `ZERO = Projection(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)` — A Projection with all values initialized to 0.
