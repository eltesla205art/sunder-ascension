# MeshLibrary

**Inherits:** Resource

Library of meshes.

A library of meshes. Contains a list of Mesh resources, each with a name and ID. Each item can also include collision and navigation shapes. This resource is used in GridMap.

## Properties

- `item/{index}/category: String` = `&""` — The item's category.
- `item/{index}/mesh: Mesh` — The item's mesh.
- `item/{index}/mesh_cast_shadow: int` = `1` — The shadow casting mode used by the item's mesh.
- `item/{index}/mesh_transform: Transform3D` = `Transform3D(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)` — The transform to apply to the item's mesh.
- `item/{index}/name: String` = `""` — The item's name, shown in the editor.
- `item/{index}/navigation_layers: int` = `1` — The item's navigation layers bitmask.
- `item/{index}/navigation_mesh: NavigationMesh` — The item's navigation mesh.
- `item/{index}/navigation_mesh_transform: Transform3D` = `Transform3D(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)` — The transform to apply to the item's navigation mesh.
- `item/{index}/preview: Texture2D` — The texture to use as the item's preview icon in the editor.
- `item/{index}/shapes: Array` = `[]` — The item's collision shapes.

## Methods

- `clear() -> void` — Clears the library.
- `create_item(id: int) -> void` — Creates a new item in the library with the given ID.
- `find_item_by_name(name: String) -> int` *const* — Returns the first item with the given name, or `-1` if no item is found.
- `get_item_category(id: int) -> StringName` *const* — Returns the category for a specific item `id`.
- `get_item_count() -> int` *const* — Returns the number of items present in the library.
- `get_item_list() -> PackedInt32Array` *const* — Returns the list of item IDs in use.
- `get_item_mesh(id: int) -> Mesh` *const* — Returns the item's mesh.
- `get_item_mesh_cast_shadow(id: int) -> int[RenderingServer.ShadowCastingSetting]` *const* — Returns the item's shadow casting mode.
- `get_item_mesh_transform(id: int) -> Transform3D` *const* — Returns the transform applied to the item's mesh.
- `get_item_name(id: int) -> String` *const* — Returns the item's name.
- `get_item_navigation_layers(id: int) -> int` *const* — Returns the item's navigation layers bitmask.
- `get_item_navigation_mesh(id: int) -> NavigationMesh` *const* — Returns the item's navigation mesh.
- `get_item_navigation_mesh_transform(id: int) -> Transform3D` *const* — Returns the transform applied to the item's navigation mesh.
- `get_item_preview(id: int) -> Texture2D` *const* — When running in the editor, returns a generated item preview (a 3D rendering in isometric perspective).
- `get_item_shapes(id: int) -> Array` *const* — Returns an item's collision shapes.
- `get_last_unused_item_id() -> int` *const* — Gets an unused ID for a new item.
- `remove_item(id: int) -> void` — Removes the item.
- `set_item_category(id: int, category: StringName) -> void` — Sets the `category` for a specific item `id` for organization in the GridMap editor.
- `set_item_mesh(id: int, mesh: Mesh) -> void` — Sets the item's mesh.
- `set_item_mesh_cast_shadow(id: int, shadow_casting_setting: RenderingServer.ShadowCastingSetting) -> void` — Sets the item's shadow casting mode to `shadow_casting_setting`.
- `set_item_mesh_transform(id: int, mesh_transform: Transform3D) -> void` — Sets the transform to apply to the item's mesh.
- `set_item_name(id: int, name: String) -> void` — Sets the item's name.
- `set_item_navigation_layers(id: int, navigation_layers: int) -> void` — Sets the item's navigation layers bitmask.
- `set_item_navigation_mesh(id: int, navigation_mesh: NavigationMesh) -> void` — Sets the item's navigation mesh.
- `set_item_navigation_mesh_transform(id: int, navigation_mesh: Transform3D) -> void` — Sets the transform to apply to the item's navigation mesh.
- `set_item_preview(id: int, texture: Texture2D) -> void` — Sets a texture to use as the item's preview icon in the editor.
- `set_item_shapes(id: int, shapes: Array) -> void` — Sets an item's collision shapes.
