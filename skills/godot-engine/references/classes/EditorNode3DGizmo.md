# EditorNode3DGizmo

**Inherits:** Node3DGizmo

Gizmo for editing Node3D objects.

Gizmo that is used for providing custom visualization and editing (handles and subgizmos) for Node3D objects. Can be overridden to create custom gizmos, but for simple gizmos creating an EditorNode3DGizmoPlugin is usually recommended.

## Methods

- `_begin_handle_action(id: int, secondary: bool) -> void` *virtual*
- `_commit_handle(id: int, secondary: bool, restore: Variant, cancel: bool) -> void` *virtual* — Override this method to commit a handle being edited (handles must have been previously added by `add_handles`).
- `_commit_subgizmos(ids: PackedInt32Array, restores: Transform3D[], cancel: bool) -> void` *virtual* — Override this method to commit a group of subgizmos being edited (see `_subgizmos_intersect_ray` and `_subgizmos_intersect_frustum`).
- `_get_handle_name(id: int, secondary: bool) -> String` *virtual const* — Override this method to return the name of an edited handle (handles must have been previously added by `add_handles`).
- `_get_handle_value(id: int, secondary: bool) -> Variant` *virtual const* — Override this method to return the current value of a handle.
- `_get_subgizmo_transform(id: int) -> Transform3D` *virtual const* — Override this method to return the current transform of a subgizmo.
- `_is_handle_highlighted(id: int, secondary: bool) -> bool` *virtual const* — Override this method to return `true` whenever the given handle should be highlighted in the editor.
- `_redraw() -> void` *virtual* — Override this method to add all the gizmo elements whenever a gizmo update is requested.
- `_set_handle(id: int, secondary: bool, camera: Camera3D, point: Vector2) -> void` *virtual* — Override this method to update the node properties when the user drags a gizmo handle (previously added with `add_handles`).
- `_set_subgizmo_transform(id: int, transform: Transform3D) -> void` *virtual* — Override this method to update the node properties during subgizmo editing (see `_subgizmos_intersect_ray` and `_subgizmos_intersect_frustum`).
- `_subgizmos_intersect_frustum(camera: Camera3D, frustum: Plane[]) -> PackedInt32Array` *virtual const* — Override this method to allow selecting subgizmos using mouse drag box selection.
- `_subgizmos_intersect_ray(camera: Camera3D, point: Vector2) -> int` *virtual const* — Override this method to allow selecting subgizmos using mouse clicks.
- `add_collision_segments(segments: PackedVector3Array) -> void` — Adds the specified `segments` to the gizmo's collision shape for picking.
- `add_collision_triangles(triangles: TriangleMesh) -> void` — Adds collision triangles to the gizmo for picking.
- `add_handles(handles: PackedVector3Array, material: Material, ids: PackedInt32Array, billboard: bool = false, secondary: bool = false) -> void` — Adds a list of handles (points) which can be used to edit the properties of the gizmo's Node3D.
- `add_lines(lines: PackedVector3Array, material: Material, billboard: bool = false, modulate: Color = Color(1, 1, 1, 1)) -> void` — Adds lines to the gizmo (as sets of 2 points), with a given material.
- `add_mesh(mesh: Mesh, material: Material = null, transform: Transform3D = Transform3D(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0), skeleton: SkinReference = null) -> void` — Adds a mesh to the gizmo with the specified `material`, local `transform` and `skeleton`.
- `add_unscaled_billboard(material: Material, default_scale: float = 1, modulate: Color = Color(1, 1, 1, 1)) -> void` — Adds an unscaled billboard for visualization and selection.
- `clear() -> void` — Removes everything in the gizmo including meshes, collisions and handles.
- `get_node_3d() -> Node3D` *const* — Returns the Node3D node associated with this gizmo.
- `get_plugin() -> EditorNode3DGizmoPlugin` *const* — Returns the EditorNode3DGizmoPlugin that owns this gizmo.
- `get_subgizmo_selection() -> PackedInt32Array` *const* — Returns a list of the currently selected subgizmos.
- `is_selected() -> bool` *const* — Returns `true` if this gizmo is currently selected.
- `is_subgizmo_selected(id: int) -> bool` *const* — Returns `true` if the given subgizmo is currently selected.
- `set_hidden(hidden: bool) -> void` — Sets the gizmo's hidden state.
- `set_node_3d(node: Node) -> void` — Sets the reference Node3D node for the gizmo.
