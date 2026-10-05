# WebRTCPeerConnectionExtension

**Inherits:** WebRTCPeerConnection





## Methods

- `_add_ice_candidate(sdp_mid_name: String, sdp_mline_index: int, sdp_name: String) -> int[Error]` *virtual required*
- `_close() -> void` *virtual required*
- `_create_data_channel(label: String, config: Dictionary) -> WebRTCDataChannel` *virtual required*
- `_create_offer() -> int[Error]` *virtual required*
- `_get_connection_state() -> int[WebRTCPeerConnection.ConnectionState]` *virtual required const*
- `_get_gathering_state() -> int[WebRTCPeerConnection.GatheringState]` *virtual required const*
- `_get_signaling_state() -> int[WebRTCPeerConnection.SignalingState]` *virtual required const*
- `_initialize(config: Dictionary) -> int[Error]` *virtual required*
- `_poll() -> int[Error]` *virtual required*
- `_set_local_description(type: String, sdp: String) -> int[Error]` *virtual required*
- `_set_remote_description(type: String, sdp: String) -> int[Error]` *virtual required*
