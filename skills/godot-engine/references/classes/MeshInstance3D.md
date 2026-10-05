# MeshInstance3D

**Inherits:** GeometryInstance3D

Node that instances meshes into a scenario.

MeshInstance3D is a node that takes a Mesh resource and adds it to the current scenario by creating an instance of it. This is the class most often used to render 3D geometry and can be used to instance a single Mesh in many places. This allows reusing geometry, which can save on resources. When a Mesh has to be instantiated more than thousands of times at close proximity, consider using a MultiMesh in a MultiMeshInstance3D instead.

## Properties

- `mesh: Mesh` — The Mesh resource for the instance.
- `skeleton: NodePath` = `NodePath("")` — NodePath to the Skeleton3D associated with the instance.
- `skin: Skin` — The Skin to be used by this instance.

## Methods

- `bake_mesh_from_current_blend_shape_mix(existing: ArrayMesh = null) -> ArrayMesh` — Takes a snapshot from the current ArrayMesh with all blend shapes applied according to their current weights and bakes it to the provided `existing` mesh.
- `bake_mesh_from_current_skeleton_pose(existing: ArrayMesh = null) -> ArrayMesh` — Takes a snapshot of the current animated skeleton pose of the skinned mesh and bakes it to the provided `existing` mesh.
- `create_convex_collision(clean: bool = true, simplify: bool = false) -> void` — This helper creates a StaticBody3D child node with a ConvexPolygonShape3D collision shape calculated from the mesh geometry.
- `create_debug_tangents() -> void` — This helper creates a MeshInstance3D child node with gizmos at every vertex calculated from the mesh geometry.
- `create_multiple_convex_collisions(settings: MeshConvexDecompositionSettings = null) -> void` — This helper creates a StaticBody3D child node with multiple ConvexPolygonShape3D collision shapes calculated from the mesh geometry via convex decomposition.
- `create_trimesh_collision() -> void` — This helper creates a StaticBody3D child node with a ConcavePolygonShape3D collision shape calculated from the mesh geometry.
- `find_blend_shape_by_name(name: StringName) -> int` — Returns the index of the blend shape with the given `name`.
- `get_active_material(surface: int) -> Material` *const* — Returns the Material that will be used by the Mesh when drawing.
- `get_blend_shape_count() -> int` *const* — Returns the number of blend shapes available.
- `get_blend_shape_value(blend_shape_idx: int) -> float` *const* — Returns the value of the blend shape at the given `blend_shape_idx`.
- `get_skin_reference() -> SkinReference` *const* — Returns the internal SkinReference containing the skeleton's RID attached to this RID.
- `get_surface_override_material(surface: int) -> Material` *const* — Returns the override Material for the specified `surface` of the Mesh resource.
- `get_surface_override_material_count() -> int` *const* — Returns the number of surface override materials.
- `set_blend_shape_value(blend_shape_idx: int, value: float) -> void` — Sets the value of the blend shape at `blend_shape_idx` to `value`.
- `set_surface_override_material(surface: int, material: Material) -> void` — Sets the override `material` for the specified `surface` of the Mesh resource.
