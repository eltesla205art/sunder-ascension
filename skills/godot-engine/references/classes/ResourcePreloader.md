# ResourcePreloader

**Inherits:** Node

A node used to preload sub-resources inside a scene.

This node is used to preload sub-resources inside a scene, so when the scene is loaded, all the resources are ready to use and can be retrieved from the preloader. You can add the resources using the ResourcePreloader tab when the node is selected. GDScript has a simplified `@GDScript.preload` built-in method which can be used in most situations, leaving the use of ResourcePreloader for more advanced scenarios.

## Methods

- `add_resource(name: StringName, resource: Resource) -> void` — Adds a resource to the preloader with the given `name`.
- `get_resource(name: StringName) -> Resource` *const* — Returns the resource associated to `name`.
- `get_resource_list() -> PackedStringArray` *const* — Returns the list of resources inside the preloader.
- `has_resource(name: StringName) -> bool` *const* — Returns `true` if the preloader contains a resource associated to `name`.
- `remove_resource(name: StringName) -> void` — Removes the resource associated to `name` from the preloader.
- `rename_resource(name: StringName, newname: StringName) -> void` — Renames a resource inside the preloader from `name` to `newname`.
