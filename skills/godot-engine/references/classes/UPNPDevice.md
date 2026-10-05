# UPNPDevice

**Inherits:** RefCounted

Universal Plug and Play (UPnP) device.

Universal Plug and Play (UPnP) device. See UPNP for UPnP discovery and utility functions. Provides low-level access to UPNP control commands. Allows to manage port mappings (port forwarding) and to query network information of the device (like local and external IP address and status).

## Properties

- `description_url: String` = `""` — URL to the device description.
- `igd_control_url: String` = `""` — IDG control URL.
- `igd_our_addr: String` = `""` — Address of the local machine in the network connecting it to this UPNPDevice.
- `igd_service_type: String` = `""` — IGD service type.
- `igd_status: UPNPDevice.IGDStatus` = `9` — IGD status.
- `service_type: String` = `""` — Service type.

## Methods

- `add_port_mapping(port: int, port_internal: int = 0, desc: String = "", proto: String = "UDP", duration: int = 0) -> int` *const* — Adds a port mapping to forward the given external port on this UPNPDevice for the given protocol to the local machine.
- `delete_port_mapping(port: int, proto: String = "UDP") -> int` *const* — Deletes the port mapping identified by the given port and protocol combination on this device.
- `is_valid_gateway() -> bool` *const* — Returns `true` if this is a valid IGD (InternetGatewayDevice) which potentially supports port forwarding.
- `query_external_address() -> String` *const* — Returns the external IP address of this UPNPDevice or an empty string.

## Enum IGDStatus

- `IGD_STATUS_OK = 0` — OK.
- `IGD_STATUS_HTTP_ERROR = 1` — HTTP error.
- `IGD_STATUS_HTTP_EMPTY = 2` — Empty HTTP response.
- `IGD_STATUS_NO_URLS = 3` — Returned response contained no URLs.
- `IGD_STATUS_NO_IGD = 4` — Not a valid IGD.
- `IGD_STATUS_DISCONNECTED = 5` — Disconnected.
- `IGD_STATUS_UNKNOWN_DEVICE = 6` — Unknown device.
- `IGD_STATUS_INVALID_CONTROL = 7` — Invalid control.
- `IGD_STATUS_MALLOC_ERROR = 8` — Memory allocation error.
- `IGD_STATUS_UNKNOWN_ERROR = 9` — Unknown error.
