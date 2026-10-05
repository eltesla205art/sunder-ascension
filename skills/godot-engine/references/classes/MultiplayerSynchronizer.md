# MultiplayerSynchronizer

**Inherits:** Node

Synchronizes properties from the multiplayer authority to the remote peers.

By default, MultiplayerSynchronizer synchronizes configured properties to all peers. Visibility can be handled directly with `set_visibility_for` or as-needed with `add_visibility_filter` and `update_visibility`. MultiplayerSpawners will handle nodes according to visibility of synchronizers as long as the node at `root_path` was spawned by one. Internally, MultiplayerSynchronizer uses `MultiplayerAPI.object_configuration_add` to notify synchronization start passing the Node at `root_path` as the `object` and itself as the `configuration`, and uses `MultiplayerAPI.object_configuration_remove` to notify synchronization end in a similar way.

## Properties

- `delta_interval: float` = `0.0` — Time interval between delta synchronizations.
- `public_visibility: bool` = `true` — Whether synchronization should be visible to all peers by default.
- `replication_config: SceneReplicationConfig` — Resource containing which properties to synchronize.
- `replication_interval: float` = `0.0` — Time interval between synchronizations.
- `root_path: NodePath` = `NodePath("..")` — Node path that replicated properties are relative to.
- `visibility_update_mode: MultiplayerSynchronizer.VisibilityUpdateMode` = `0` — Specifies when visibility filters are updated.

## Methods

- `add_visibility_filter(filter: Callable) -> void` — Adds a peer visibility filter for this synchronizer.
- `get_visibility_for(peer: int) -> bool` *const* — Queries the current visibility for peer `peer`.
- `remove_visibility_filter(filter: Callable) -> void` — Removes a peer visibility filter from this synchronizer.
- `set_visibility_for(peer: int, visible: bool) -> void` — Sets the visibility of `peer` to `visible`.
- `update_visibility(for_peer: int = 0) -> void` — Updates the visibility of `for_peer` according to visibility filters.

## Signals

- `delta_synchronized()` — Emitted when a new delta synchronization state is received by this synchronizer after the properties have been updated.
- `synchronized()` — Emitted when a new synchronization state is received by this synchronizer after the properties have been updated.
- `visibility_changed(for_peer: int)` — Emitted when visibility of `for_peer` is updated.

## Enum VisibilityUpdateMode

- `VISIBILITY_PROCESS_IDLE = 0` — Visibility filters are updated during process frames (see `Node.NOTIFICATION_INTERNAL_PROCESS`).
- `VISIBILITY_PROCESS_PHYSICS = 1` — Visibility filters are updated during physics frames (see `Node.NOTIFICATION_INTERNAL_PHYSICS_PROCESS`).
- `VISIBILITY_PROCESS_NONE = 2` — Visibility filters are not updated automatically, and must be updated manually by calling `update_visibility`.
