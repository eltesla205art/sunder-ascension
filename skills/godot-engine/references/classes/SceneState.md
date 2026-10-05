# SceneState

**Inherits:** RefCounted

Provides access to a scene file's information.

Maintains a list of resources, nodes, exported and overridden properties, and built-in scripts associated with a scene. They cannot be modified from a SceneState, only accessed. Useful for peeking into what a PackedScene contains without instantiating it. This class cannot be instantiated directly, it is retrieved for a given scene as the result of `PackedScene.get_state`.

## Methods

- `get_base_scene_state() -> SceneState` *const* — Returns the SceneState of the scene that this scene inherits from, or `null` if it doesn't inherit from any scene.
- `get_connection_binds(idx: int) -> Array` *const* — Returns the list of bound parameters for the signal at `idx`.
- `get_connection_count() -> int` *const* — Returns the number of signal connections in the scene.
- `get_connection_flags(idx: int) -> int` *const* — Returns the connection flags for the signal at `idx`.
- `get_connection_method(idx: int) -> StringName` *const* — Returns the method connected to the signal at `idx`.
- `get_connection_signal(idx: int) -> StringName` *const* — Returns the name of the signal at `idx`.
- `get_connection_source(idx: int) -> NodePath` *const* — Returns the path to the node that owns the signal at `idx`, relative to the root node.
- `get_connection_target(idx: int) -> NodePath` *const* — Returns the path to the node that owns the method connected to the signal at `idx`, relative to the root node.
- `get_connection_unbinds(idx: int) -> int` *const* — Returns the number of unbound parameters for the signal at `idx`.
- `get_node_count() -> int` *const* — Returns the number of nodes in the scene.
- `get_node_groups(idx: int) -> PackedStringArray` *const* — Returns the list of group names associated with the node at `idx`.
- `get_node_index(idx: int) -> int` *const* — Returns the node's index, which is its position relative to its siblings.
- `get_node_instance(idx: int) -> PackedScene` *const* — Returns a PackedScene for the node at `idx` (i.e. the whole branch starting at this node, with its child nodes and resources), or `null` if the node is not an instance.
- `get_node_instance_placeholder(idx: int) -> String` *const* — Returns the path to the represented scene file if the node at `idx` is an InstancePlaceholder.
- `get_node_name(idx: int) -> StringName` *const* — Returns the name of the node at `idx`.
- `get_node_owner_path(idx: int) -> NodePath` *const* — Returns the path to the owner of the node at `idx`, relative to the root node.
- `get_node_path(idx: int, for_parent: bool = false) -> NodePath` *const* — Returns the path to the node at `idx`.
- `get_node_property_count(idx: int) -> int` *const* — Returns the number of exported or overridden properties for the node at `idx`.
- `get_node_property_name(idx: int, prop_idx: int) -> StringName` *const* — Returns the name of the property at `prop_idx` for the node at `idx`.
- `get_node_property_value(idx: int, prop_idx: int) -> Variant` *const* — Returns the value of the property at `prop_idx` for the node at `idx`.
- `get_node_type(idx: int) -> StringName` *const* — Returns the type of the node at `idx`.
- `get_path() -> String` *const* — Returns the resource path to the represented PackedScene.
- `is_node_instance_placeholder(idx: int) -> bool` *const* — Returns `true` if the node at `idx` is an InstancePlaceholder.

## Enum GenEditState

- `GEN_EDIT_STATE_DISABLED = 0` — If passed to `PackedScene.instantiate`, blocks edits to the scene state.
- `GEN_EDIT_STATE_INSTANCE = 1` — If passed to `PackedScene.instantiate`, provides inherited scene resources to the local scene.
- `GEN_EDIT_STATE_MAIN = 2` — If passed to `PackedScene.instantiate`, provides local scene resources to the local scene.
- `GEN_EDIT_STATE_MAIN_INHERITED = 3` — If passed to `PackedScene.instantiate`, it's similar to `GEN_EDIT_STATE_MAIN`, but for the case where the scene is being instantiated to be the base of another one.
