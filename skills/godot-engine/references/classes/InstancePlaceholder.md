# InstancePlaceholder

**Inherits:** Node

Placeholder for the root Node of a PackedScene.

Turning on the option Load As Placeholder for an instantiated scene in the editor causes it to be replaced by an InstancePlaceholder when running the game, this will not replace the node in the editor. This makes it possible to delay actually loading the scene until calling `create_instance`. This is useful to avoid loading large scenes all at once by loading parts of it selectively. Note: Like Node, InstancePlaceholder does not have a transform.

## Methods

- `create_instance(replace: bool = false, custom_scene: PackedScene = null) -> Node` — Call this method to actually load in the node.
- `get_instance_path() -> String` *const* — Gets the path to the PackedScene resource file that is loaded by default when calling `create_instance`.
- `get_stored_values(with_order: bool = false) -> Dictionary` — Returns the list of properties that will be applied to the node when `create_instance` is called.
