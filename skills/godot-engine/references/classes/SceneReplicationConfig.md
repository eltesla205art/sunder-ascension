# SceneReplicationConfig

**Inherits:** Resource

Configuration for properties to synchronize with a MultiplayerSynchronizer.



## Methods

- `add_property(path: NodePath, index: int = -1) -> void` — Adds the property identified by the given `path` to the list of the properties being synchronized, optionally passing an `index`.
- `get_properties() -> NodePath[]` *const* — Returns a list of synchronized property NodePaths.
- `has_property(path: NodePath) -> bool` *const* — Returns `true` if the given `path` is configured for synchronization.
- `property_get_index(path: NodePath) -> int` *const* — Finds the index of the given `path`.
- `property_get_replication_mode(path: NodePath) -> int[SceneReplicationConfig.ReplicationMode]` — Returns the replication mode for the property identified by the given `path`.
- `property_get_spawn(path: NodePath) -> bool` — Returns `true` if the property identified by the given `path` is configured to be synchronized on spawn.
- `property_get_sync(path: NodePath) -> bool` *(deprecated)* — Returns `true` if the property identified by the given `path` is configured to be synchronized on process.
- `property_get_watch(path: NodePath) -> bool` *(deprecated)* — Returns `true` if the property identified by the given `path` is configured to be reliably synchronized when changes are detected on process.
- `property_set_replication_mode(path: NodePath, mode: SceneReplicationConfig.ReplicationMode) -> void` — Sets the synchronization mode for the property identified by the given `path`.
- `property_set_spawn(path: NodePath, enabled: bool) -> void` — Sets whether the property identified by the given `path` is configured to be synchronized on spawn.
- `property_set_sync(path: NodePath, enabled: bool) -> void` *(deprecated)* — Sets whether the property identified by the given `path` is configured to be synchronized on process.
- `property_set_watch(path: NodePath, enabled: bool) -> void` *(deprecated)* — Sets whether the property identified by the given `path` is configured to be reliably synchronized when changes are detected on process.
- `remove_property(path: NodePath) -> void` — Removes the property identified by the given `path` from the configuration.

## Enum ReplicationMode

- `REPLICATION_MODE_NEVER = 0` — Do not keep the given property synchronized.
- `REPLICATION_MODE_ALWAYS = 1` — Replicate the given property on process by constantly sending updates using unreliable transfer mode.
- `REPLICATION_MODE_ON_CHANGE = 2` — Replicate the given property on process by sending updates using reliable transfer mode when its value changes.
