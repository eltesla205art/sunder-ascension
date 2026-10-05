# Resource

**Inherits:** RefCounted

Base class for serializable objects.

Resource is the base class for all Godot-specific resource types, serving primarily as data containers. Since they inherit from RefCounted, resources are reference-counted and freed when no longer in use. They can also be nested within other resources, and saved on disk. PackedScene, one of the most common Objects in a Godot project, is also a resource, uniquely capable of storing and instantiating the Nodes it contains as many times as desired.

## Properties

- `resource_local_to_scene: bool` = `false` — If `true`, the resource is duplicated for each instance of all scenes using it.
- `resource_name: String` = `""` — An optional name for this resource.
- `resource_path: String` = `""` — The unique path to this resource.
- `resource_scene_unique_id: String` — A unique identifier relative to this resource's scene.

## Methods

- `_get_rid() -> RID` *virtual const* — Override this method to return a custom RID when `get_rid` is called.
- `_reset_state() -> void` *virtual* — For resources that store state in non-exported properties, such as via `Object._validate_property` or `Object._get_property_list`, this method must be implemented to clear them.
- `_set_path_cache(path: String) -> void` *virtual const* — Override this method to execute additional logic after `set_path_cache` is called on this object.
- `_setup_local_to_scene() -> void` *virtual* — Override this method to customize the newly duplicated resource created from `PackedScene.instantiate`, if the original's `resource_local_to_scene` is set to `true`.
- `copy_from_resource(resource: Resource) -> int[Error]` — Copies the data from `resource` into this resource.
- `duplicate(deep: bool = false) -> Resource` *const* — Duplicates this resource, returning a new resource with its `export`ed or `PROPERTY_USAGE_STORAGE` properties copied from the original.
- `duplicate_deep(deep_subresources_mode: Resource.DeepDuplicateMode = 1) -> Resource` *const* — Duplicates this resource, deeply, like `duplicate` when passing `true`, with extra control over how subresources are handled.
- `emit_changed() -> void` — Emits the `changed` signal.
- `generate_scene_unique_id() -> String` *static* — Generates a unique identifier for a resource to be contained inside a PackedScene, based on the current date, time, and a random value.
- `get_id_for_path(path: String) -> String` *const* — From the internal cache for scene-unique IDs, returns the ID of this resource for the scene at `path`.
- `get_local_scene() -> Node` *const* — If `resource_local_to_scene` is set to `true` and the resource has been loaded from a PackedScene instantiation, returns the root Node of the scene where this resource is used.
- `get_rid() -> RID` *const* — Returns the RID of this resource (or an empty RID).
- `is_built_in() -> bool` *const* — Returns `true` if the resource is saved on disk as a part of another resource's file.
- `reset_state() -> void` — Makes the resource clear its non-exported properties.
- `set_id_for_path(path: String, id: String) -> void` — In the internal cache for scene-unique IDs, sets the ID of this resource to `id` for the scene at `path`.
- `set_path_cache(path: String) -> void` — Sets the resource's path to `path` without involving the resource cache.
- `setup_local_to_scene() -> void` *(deprecated)* — Calls `_setup_local_to_scene`.
- `take_over_path(path: String) -> void` — Sets the `resource_path` to `path`, potentially overriding an existing cache entry for this path.

## Signals

- `changed()` — Emitted when the resource changes, usually when one of its properties is modified.
- `setup_local_to_scene_requested()` — Emitted by a newly duplicated resource with `resource_local_to_scene` set to `true`.

## Enum DeepDuplicateMode

- `DEEP_DUPLICATE_NONE = 0` — No subresources at all are duplicated.
- `DEEP_DUPLICATE_INTERNAL = 1` — Only subresources without a path or with a scene-local path will be duplicated.
- `DEEP_DUPLICATE_ALL = 2` — Every subresource found will be duplicated, even if it has a non-local path.
