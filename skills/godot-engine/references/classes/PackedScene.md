# PackedScene

**Inherits:** Resource

An abstraction of a serialized scene.

A simplified interface to a scene file. Provides access to operations and checks that can be performed on the scene resource itself. Can be used to save a node to a file. When saving, the node as well as all the nodes it owns get saved (see `Node.owner` property).

## Methods

- `can_instantiate() -> bool` *const* — Returns `true` if the scene file has nodes.
- `get_state() -> SceneState` *const* — Returns the SceneState representing the scene file contents.
- `instantiate(edit_state: PackedScene.GenEditState = 0) -> Node` *const* — Instantiates the scene's node hierarchy.
- `pack(path: Node) -> int[Error]` — Packs the `path` node, and all owned sub-nodes, into this PackedScene.

## Enum GenEditState

- `GEN_EDIT_STATE_DISABLED = 0` — If passed to `instantiate`, blocks edits to the scene state.
- `GEN_EDIT_STATE_INSTANCE = 1` — If passed to `instantiate`, provides local scene resources to the local scene.
- `GEN_EDIT_STATE_MAIN = 2` — If passed to `instantiate`, provides local scene resources to the local scene.
- `GEN_EDIT_STATE_MAIN_INHERITED = 3` — It's similar to `GEN_EDIT_STATE_MAIN`, but for the case where the scene is being instantiated to be the base of another one.
