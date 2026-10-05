# Camera3D

**Inherits:** Node3D

Camera node, displays from a point of view.

Camera3D is a special node that displays what is visible from its current location. Cameras register themselves in the nearest Viewport node (when ascending the tree). Only one camera can be active per viewport. If no viewport is available ascending the tree, the camera will register in the global viewport.

## Properties

- `attributes: CameraAttributes` — The CameraAttributes to use for this camera.
- `compositor: Compositor` — The Compositor to use for this camera.
- `cull_mask: int` = `1048575` — The culling mask that describes which `VisualInstance3D.layers` are rendered by this camera.
- `current: bool` = `false` — If `true`, the ancestor Viewport is currently using this camera.
- `doppler_tracking: Camera3D.DopplerTracking` = `0` — If not `DOPPLER_TRACKING_DISABLED`, this camera will simulate the Doppler effect for objects changed in particular `_process` methods.
- `environment: Environment` — The Environment to use for this camera.
- `far: float` = `4000.0` — The distance to the far culling boundary for this camera relative to its local Z axis.
- `fov: float` = `75.0` — The camera's field of view (also known as FOV), as an angle in degrees.
- `frustum_offset: Vector2` = `Vector2(0, 0)` — The camera's frustum offset.
- `h_offset: float` = `0.0` — The horizontal (X) offset of the camera viewport.
- `keep_aspect: Camera3D.KeepAspect` = `1` — The axis to lock during `fov`/`size` adjustments.
- `near: float` = `0.05` — The distance to the near culling boundary for this camera relative to its local Z axis.
- `projection: Camera3D.ProjectionType` = `0` — The camera's projection mode.
- `size: float` = `1.0` — The camera's size in meters measured as the diameter of the width or height, depending on `keep_aspect`.
- `v_offset: float` = `0.0` — The vertical (Y) offset of the camera viewport.

## Methods

- `clear_current(enable_next: bool = true) -> void` — If this is the current camera, remove it from being current.
- `get_camera_projection() -> Projection` *const* — Returns the projection matrix that this camera uses to render to its associated viewport.
- `get_camera_rid() -> RID` *const* — Returns the camera's RID from the RenderingServer.
- `get_camera_transform() -> Transform3D` *const* — Returns the transform of the camera plus the vertical (`v_offset`) and horizontal (`h_offset`) offsets; and any other adjustments made to the position and orientation of the camera by subclassed cameras such as XRCamera3D.
- `get_cull_mask_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `cull_mask` is enabled, given a `layer_number` between 1 and 20.
- `get_frustum() -> Plane[]` *const* — Returns the camera's frustum planes in world space units as an array of Planes in the following order: near, far, left, top, right, bottom.
- `get_pyramid_shape_rid() -> RID` — Returns the RID of a pyramid shape encompassing the camera's view frustum, ignoring the camera's near plane.
- `is_position_behind(world_point: Vector3) -> bool` *const* — Returns `true` if the given position is behind the camera (the blue part of the linked diagram).
- `is_position_in_frustum(world_point: Vector3) -> bool` *const* — Returns `true` if the given position is inside the camera's frustum (the green part of the linked diagram).
- `make_current() -> void` — Makes this camera the current camera for the Viewport (see class description).
- `project_local_ray_normal(screen_point: Vector2) -> Vector3` *const* — Returns a normal vector from the screen point location directed along the camera.
- `project_position(screen_point: Vector2, z_depth: float) -> Vector3` *const* — Returns the 3D point in world space that maps to the given 2D coordinate in the Viewport rectangle on a plane that is the given `z_depth` distance into the scene away from the camera.
- `project_ray_normal(screen_point: Vector2) -> Vector3` *const* — Returns a normal vector in world space, that is the result of projecting a point on the Viewport rectangle by the inverse camera projection.
- `project_ray_origin(screen_point: Vector2) -> Vector3` *const* — Returns a 3D position in world space, that is the result of projecting a point on the Viewport rectangle by the inverse camera projection.
- `set_cull_mask_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `cull_mask`, given a `layer_number` between 1 and 20.
- `set_frustum(size: float, offset: Vector2, z_near: float, z_far: float) -> void` — Sets the camera projection to frustum mode (see `PROJECTION_FRUSTUM`), by specifying a `size`, an `offset`, and the `z_near` and `z_far` clip planes in world space units.
- `set_orthogonal(size: float, z_near: float, z_far: float) -> void` — Sets the camera projection to orthogonal mode (see `PROJECTION_ORTHOGONAL`), by specifying a `size`, and the `z_near` and `z_far` clip planes in world space units.
- `set_perspective(fov: float, z_near: float, z_far: float) -> void` — Sets the camera projection to perspective mode (see `PROJECTION_PERSPECTIVE`), by specifying a `fov` (field of view) angle in degrees, and the `z_near` and `z_far` clip planes in world space units.
- `unproject_position(world_point: Vector3) -> Vector2` *const* — Returns the 2D coordinate in the Viewport rectangle that maps to the given 3D point in world space.

## Enum ProjectionType

- `PROJECTION_PERSPECTIVE = 0` — Perspective projection.
- `PROJECTION_ORTHOGONAL = 1` — Orthogonal projection, also known as orthographic projection.
- `PROJECTION_FRUSTUM = 2` — Frustum projection.

## Enum KeepAspect

- `KEEP_WIDTH = 0` — Preserves the horizontal aspect ratio; also known as Vert- scaling.
- `KEEP_HEIGHT = 1` — Preserves the vertical aspect ratio; also known as Hor+ scaling.

## Enum DopplerTracking

- `DOPPLER_TRACKING_DISABLED = 0` — Disables Doppler effect simulation (default).
- `DOPPLER_TRACKING_IDLE_STEP = 1` — Simulate Doppler effect by tracking positions of objects that are changed in `_process`.
- `DOPPLER_TRACKING_PHYSICS_STEP = 2` — Simulate Doppler effect by tracking positions of objects that are changed in `_physics_process`.
