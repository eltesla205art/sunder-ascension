# MultiplayerAPIExtension

**Inherits:** MultiplayerAPI

Base class used for extending the MultiplayerAPI.

This class can be used to extend or replace the default MultiplayerAPI implementation via script or extensions. The following example extend the default implementation (SceneMultiplayer) by logging every RPC being made, and every object being configured for replication. Then in your main scene or in an autoload call `SceneTree.set_multiplayer` to start using your custom MultiplayerAPI:  Native extensions can alternatively use the `MultiplayerAPI.set_default_interface` method during initialization to configure themselves as the default implementation.

## Methods

- `_get_multiplayer_peer() -> MultiplayerPeer` *virtual* — Called when the `MultiplayerAPI.multiplayer_peer` is retrieved.
- `_get_peer_ids() -> PackedInt32Array` *virtual const* — Callback for `MultiplayerAPI.get_peers`.
- `_get_remote_sender_id() -> int` *virtual const* — Callback for `MultiplayerAPI.get_remote_sender_id`.
- `_get_unique_id() -> int` *virtual const* — Callback for `MultiplayerAPI.get_unique_id`.
- `_object_configuration_add(object: Object, configuration: Variant) -> int[Error]` *virtual* — Callback for `MultiplayerAPI.object_configuration_add`.
- `_object_configuration_remove(object: Object, configuration: Variant) -> int[Error]` *virtual* — Callback for `MultiplayerAPI.object_configuration_remove`.
- `_poll() -> int[Error]` *virtual* — Callback for `MultiplayerAPI.poll`.
- `_rpc(peer: int, object: Object, method: StringName, args: Array) -> int[Error]` *virtual* — Callback for `MultiplayerAPI.rpc`.
- `_set_multiplayer_peer(multiplayer_peer: MultiplayerPeer) -> void` *virtual* — Called when the `MultiplayerAPI.multiplayer_peer` is set.
