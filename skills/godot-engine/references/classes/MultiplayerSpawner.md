# MultiplayerSpawner

**Inherits:** Node

Automatically replicates spawnable nodes from the authority to other multiplayer peers.

Spawnable scenes can be configured in the editor or through code (see `add_spawnable_scene`). Also supports custom node spawns through `spawn`, calling `spawn_function` on all peers. Internally, MultiplayerSpawner uses `MultiplayerAPI.object_configuration_add` to notify spawns passing the spawned node as the `object` and itself as the `configuration`, and `MultiplayerAPI.object_configuration_remove` to notify despawns in a similar way.

## Properties

- `spawn_function: Callable` — Method called on all peers when a custom `spawn` is requested by the authority.
- `spawn_limit: int` = `0` — Maximum number of nodes allowed to be spawned by this spawner.
- `spawn_path: NodePath` = `NodePath("")` — Path to the spawn root.

## Methods

- `add_spawnable_scene(path: String) -> void` — Adds a scene path to spawnable scenes, making it automatically replicated from the multiplayer authority to other peers when added as children of the node pointed by `spawn_path`.
- `clear_spawnable_scenes() -> void` — Clears all spawnable scenes.
- `get_spawnable_scene(index: int) -> String` *const* — Returns the spawnable scene path by index.
- `get_spawnable_scene_count() -> int` *const* — Returns the count of spawnable scene paths.
- `spawn(data: Variant = null) -> Node` — Requests a custom spawn, with `data` passed to `spawn_function` on all peers.

## Signals

- `despawned(node: Node)` — Emitted when a spawnable scene or custom spawn was despawned by the multiplayer authority.
- `spawned(node: Node)` — Emitted when a spawnable scene or custom spawn was spawned by the multiplayer authority.
