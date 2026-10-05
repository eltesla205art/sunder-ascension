# MultiMesh

**Inherits:** Resource

Provides high-performance drawing of a mesh multiple times using GPU instancing.

MultiMesh provides low-level mesh instancing. Drawing thousands of MeshInstance3D nodes can be slow, since each object is submitted to the GPU then drawn individually. MultiMesh is much faster as it can draw thousands of instances with a single draw call, resulting in less API overhead. As a drawback, if the instances are too far away from each other, performance may be reduced as every single instance will always render (they are spatially indexed as one, for the whole object).

## Properties

- `buffer: PackedFloat32Array` = `PackedFloat32Array()` — 
- `color_array: PackedColorArray` *(deprecated)* — Array containing each Color used by all instances of this mesh.
- `custom_aabb: AABB` = `AABB(0, 0, 0, 0, 0, 0)` — Custom AABB for this MultiMesh resource.
- `custom_data_array: PackedColorArray` *(deprecated)* — Array containing each custom data value used by all instances of this mesh, as a PackedColorArray.
- `instance_count: int` = `0` — Number of instances that will get drawn.
- `mesh: Mesh` — Mesh resource to be instanced.
- `physics_interpolation_quality: MultiMesh.PhysicsInterpolationQuality` = `0` — Choose whether to use an interpolation method that favors speed or quality.
- `transform_2d_array: PackedVector2Array` *(deprecated)* — Array containing each Transform2D value used by all instances of this mesh, as a PackedVector2Array.
- `transform_array: PackedVector3Array` *(deprecated)* — Array containing each Transform3D value used by all instances of this mesh, as a PackedVector3Array.
- `transform_format: MultiMesh.TransformFormat` = `0` — Format of transform used to transform mesh, either 2D or 3D.
- `use_colors: bool` = `false` — If `true`, the MultiMesh will use color data (see `set_instance_color`).
- `use_custom_data: bool` = `false` — If `true`, the MultiMesh will use custom data (see `set_instance_custom_data`).
- `visible_instance_count: int` = `-1` — Limits the number of instances drawn, -1 draws all instances.

## Methods

- `get_aabb() -> AABB` *const* — Returns the visibility axis-aligned bounding box in local space.
- `get_instance_color(instance: int) -> Color` *const* — Gets a specific instance's color multiplier.
- `get_instance_custom_data(instance: int) -> Color` *const* — Returns the custom data that has been set for a specific instance.
- `get_instance_transform(instance: int) -> Transform3D` *const* — Returns the Transform3D of a specific instance.
- `get_instance_transform_2d(instance: int) -> Transform2D` *const* — Returns the Transform2D of a specific instance.
- `reset_instance_physics_interpolation(instance: int) -> void` — When using physics interpolation, this function allows you to prevent interpolation on an instance in the current physics tick.
- `reset_instances_physics_interpolation() -> void` — When using physics interpolation, this function allows you to prevent interpolation for all instances in the current physics tick.
- `set_buffer_interpolated(buffer_curr: PackedFloat32Array, buffer_prev: PackedFloat32Array) -> void` — An alternative to setting the `buffer` property, which can be used with physics interpolation.
- `set_instance_color(instance: int, color: Color) -> void` — Sets the color of a specific instance by multiplying the mesh's existing vertex colors.
- `set_instance_custom_data(instance: int, custom_data: Color) -> void` — Sets custom data for a specific instance.
- `set_instance_transform(instance: int, transform: Transform3D) -> void` — Sets the Transform3D for a specific instance.
- `set_instance_transform_2d(instance: int, transform: Transform2D) -> void` — Sets the Transform2D for a specific instance.

## Enum TransformFormat

- `TRANSFORM_2D = 0` — Use this when using 2D transforms.
- `TRANSFORM_3D = 1` — Use this when using 3D transforms.

## Enum PhysicsInterpolationQuality

- `INTERP_QUALITY_FAST = 0` — Always interpolate using Basis lerping, which can produce warping artifacts in some situations.
- `INTERP_QUALITY_HIGH = 1` — Attempt to interpolate using Basis slerping (spherical linear interpolation) where possible, otherwise fall back to lerping.
