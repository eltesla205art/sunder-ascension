# EditorNode3DGizmoPlugin

**Inherits:** Resource

A class used by the editor to define Node3D gizmo types.

EditorNode3DGizmoPlugin allows you to define a new type of Gizmo. There are two main ways to do so: extending EditorNode3DGizmoPlugin for the simpler gizmos, or creating a new EditorNode3DGizmo type. See the tutorial in the documentation for more info. To use EditorNode3DGizmoPlugin, register it using the `EditorPlugin.add_node_3d_gizmo_plugin` method first.

## Methods

- `_begin_handle_action(gizmo: EditorNode3DGizmo, handle_id: int, secondary: bool) -> void` *virtual*
- `_can_be_hidden() -> bool` *virtual const* — Override this method to define whether the gizmos handled by this plugin can be hidden or not.
- `_can_commit_handle_on_click() -> bool` *virtual const* — Override this method to define whether the gizmos should commit when the final handle position is the same as the initial one.
- `_commit_handle(gizmo: EditorNode3DGizmo, handle_id: int, secondary: bool, restore: Variant, cancel: bool) -> void` *virtual* — Override this method to commit a handle being edited (handles must have been previously added by `EditorNode3DGizmo.add_handles` during `_redraw`).
- `_commit_subgizmos(gizmo: EditorNode3DGizmo, ids: PackedInt32Array, restores: Transform3D[], cancel: bool) -> void` *virtual* — Override this method to commit a group of subgizmos being edited (see `_subgizmos_intersect_ray` and `_subgizmos_intersect_frustum`).
- `_create_gizmo(for_node_3d: Node3D) -> EditorNode3DGizmo` *virtual const* — Override this method to return a custom EditorNode3DGizmo for the 3D nodes of your choice, return `null` for the rest of nodes.
- `_get_gizmo_name() -> String` *virtual const* — Override this method to provide the name that will appear in the gizmo visibility menu.
- `_get_handle_name(gizmo: EditorNode3DGizmo, handle_id: int, secondary: bool) -> String` *virtual const* — Override this method to provide gizmo's handle names.
- `_get_handle_value(gizmo: EditorNode3DGizmo, handle_id: int, secondary: bool) -> Variant` *virtual const* — Override this method to return the current value of a handle.
- `_get_priority() -> int` *virtual const* — Override this method to set the gizmo's priority.
- `_get_subgizmo_transform(gizmo: EditorNode3DGizmo, subgizmo_id: int) -> Transform3D` *virtual const* — Override this method to return the current transform of a subgizmo.
- `_has_gizmo(for_node_3d: Node3D) -> bool` *virtual const* — Override this method to define which Node3D nodes have a gizmo from this plugin.
- `_is_handle_highlighted(gizmo: EditorNode3DGizmo, handle_id: int, secondary: bool) -> bool` *virtual const* — Override this method to return `true` whenever to given handle should be highlighted in the editor.
- `_is_selectable_when_hidden() -> bool` *virtual const* — Override this method to define whether Node3D with this gizmo should be selectable even when the gizmo is hidden.
- `_redraw(gizmo: EditorNode3DGizmo) -> void` *virtual* — Override this method to add all the gizmo elements whenever a gizmo update is requested.
- `_set_handle(gizmo: EditorNode3DGizmo, handle_id: int, secondary: bool, camera: Camera3D, screen_pos: Vector2) -> void` *virtual* — Override this method to update the node's properties when the user drags a gizmo handle (previously added with `EditorNode3DGizmo.add_handles`).
- `_set_subgizmo_transform(gizmo: EditorNode3DGizmo, subgizmo_id: int, transform: Transform3D) -> void` *virtual* — Override this method to update the node properties during subgizmo editing (see `_subgizmos_intersect_ray` and `_subgizmos_intersect_frustum`).
- `_subgizmos_intersect_frustum(gizmo: EditorNode3DGizmo, camera: Camera3D, frustum_planes: Plane[]) -> PackedInt32Array` *virtual const* — Override this method to allow selecting subgizmos using mouse drag box selection.
- `_subgizmos_intersect_ray(gizmo: EditorNode3DGizmo, camera: Camera3D, screen_pos: Vector2) -> int` *virtual const* — Override this method to allow selecting subgizmos using mouse clicks.
- `add_material(name: String, material: StandardMaterial3D) -> void` — Adds a new material to the internal material list for the plugin.
- `create_handle_material(name: String, billboard: bool = false, texture: Texture2D = null) -> void` — Creates a handle material with its variants (selected and/or editable) and adds them to the internal material list.
- `create_icon_material(name: String, texture: Texture2D, on_top: bool = false, color: Color = Color(1, 1, 1, 1)) -> void` — Creates an icon material with its variants (selected and/or editable) and adds them to the internal material list.
- `create_material(name: String, color: Color, billboard: bool = false, on_top: bool = false, use_vertex_color: bool = false) -> void` — Creates an unshaded material with its variants (selected and/or editable) and adds them to the internal material list.
- `get_material(name: String, gizmo: EditorNode3DGizmo = null) -> StandardMaterial3D` — Gets material from the internal list of materials.
