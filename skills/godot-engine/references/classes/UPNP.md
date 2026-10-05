# UPNP

**Inherits:** RefCounted

Universal Plug and Play (UPnP) functions for network device discovery, querying and port forwarding.

This class can be used to discover compatible UPNPDevices on the local network and execute commands on them, like managing port mappings (for port forwarding/NAT traversal) and querying the local and remote network IP address. Note that methods on this class are synchronous and block the calling thread. To forward a specific port (here `7777`, note both `discover` and `add_port_mapping` can return errors that should be checked):  To close a specific port (e.g. after you have finished using it):  Note: UPnP discovery blocks the current thread. To perform discovery without blocking the main thread, use Threads like this:  Terminology: In the context of UPnP networking, "gateway" (or "internet gateway device", short IGD) refers to network devices that allow computers in the local network to access the internet ("wide area network", WAN).

## Properties

- `discover_ipv6: bool` = `false` — If `true`, IPv6 is used for UPNPDevice discovery.
- `discover_local_port: int` = `0` — If `0`, the local port to use for discovery is chosen automatically by the system.
- `discover_multicast_if: String` = `""` — Multicast interface to use for discovery.

## Methods

- `add_device(device: UPNPDevice) -> void` — Adds the given UPNPDevice to the list of discovered devices.
- `add_port_mapping(port: int, port_internal: int = 0, desc: String = "", proto: String = "UDP", duration: int = 0) -> int` *const* — Adds a mapping to forward the external `port` (between 1 and 65535, although recommended to use port 1024 or above) on the default gateway (see `get_gateway`) to the `port_internal` on the local machine for the given protocol `proto` (either `"TCP"` or `"UDP"`, with UDP being the default).
- `clear_devices() -> void` — Clears the list of discovered devices.
- `delete_port_mapping(port: int, proto: String = "UDP") -> int` *const* — Deletes the port mapping for the given port and protocol combination on the default gateway (see `get_gateway`) if one exists.
- `discover(timeout: int = 2000, ttl: int = 2, device_filter: String = "InternetGatewayDevice") -> int` — Discovers local UPNPDevices.
- `get_device(index: int) -> UPNPDevice` *const* — Returns the UPNPDevice at the given `index`.
- `get_device_count() -> int` *const* — Returns the number of discovered UPNPDevices.
- `get_gateway() -> UPNPDevice` *const* — Returns the default gateway.
- `query_external_address() -> String` *const* — Returns the external IP address of the default gateway (see `get_gateway`) as string.
- `remove_device(index: int) -> void` — Removes the device at `index` from the list of discovered devices.
- `set_device(index: int, device: UPNPDevice) -> void` — Sets the device at `index` from the list of discovered devices to `device`.

## Enum UPNPResult

- `UPNP_RESULT_SUCCESS = 0` — UPNP command or discovery was successful.
- `UPNP_RESULT_NOT_AUTHORIZED = 1` — Not authorized to use the command on the UPNPDevice.
- `UPNP_RESULT_PORT_MAPPING_NOT_FOUND = 2` — No port mapping was found for the given port, protocol combination on the given UPNPDevice.
- `UPNP_RESULT_INCONSISTENT_PARAMETERS = 3` — Inconsistent parameters.
- `UPNP_RESULT_NO_SUCH_ENTRY_IN_ARRAY = 4` — No such entry in array.
- `UPNP_RESULT_ACTION_FAILED = 5` — The action failed.
- `UPNP_RESULT_SRC_IP_WILDCARD_NOT_PERMITTED = 6` — The UPNPDevice does not allow wildcard values for the source IP address.
- `UPNP_RESULT_EXT_PORT_WILDCARD_NOT_PERMITTED = 7` — The UPNPDevice does not allow wildcard values for the external port.
- `UPNP_RESULT_INT_PORT_WILDCARD_NOT_PERMITTED = 8` — The UPNPDevice does not allow wildcard values for the internal port.
- `UPNP_RESULT_REMOTE_HOST_MUST_BE_WILDCARD = 9` — The remote host value must be a wildcard.
- `UPNP_RESULT_EXT_PORT_MUST_BE_WILDCARD = 10` — The external port value must be a wildcard.
- `UPNP_RESULT_NO_PORT_MAPS_AVAILABLE = 11` — No port maps are available.
- `UPNP_RESULT_CONFLICT_WITH_OTHER_MECHANISM = 12` — Conflict with other mechanism.
- `UPNP_RESULT_CONFLICT_WITH_OTHER_MAPPING = 13` — Conflict with an existing port mapping.
- `UPNP_RESULT_SAME_PORT_VALUES_REQUIRED = 14` — External and internal port values must be the same.
- `UPNP_RESULT_ONLY_PERMANENT_LEASE_SUPPORTED = 15` — Only permanent leases are supported.
- `UPNP_RESULT_INVALID_GATEWAY = 16` — Invalid gateway.
- `UPNP_RESULT_INVALID_PORT = 17` — Invalid port.
- `UPNP_RESULT_INVALID_PROTOCOL = 18` — Invalid protocol.
- `UPNP_RESULT_INVALID_DURATION = 19` — Invalid duration.
- `UPNP_RESULT_INVALID_ARGS = 20` — Invalid arguments.
- `UPNP_RESULT_INVALID_RESPONSE = 21` — Invalid response.
- `UPNP_RESULT_INVALID_PARAM = 22` — Invalid parameter.
- `UPNP_RESULT_HTTP_ERROR = 23` — HTTP error.
- `UPNP_RESULT_SOCKET_ERROR = 24` — Socket error.
- `UPNP_RESULT_MEM_ALLOC_ERROR = 25` — Error allocating memory.
- `UPNP_RESULT_NO_GATEWAY = 26` — No gateway available.
- `UPNP_RESULT_NO_DEVICES = 27` — No devices available.
- `UPNP_RESULT_UNKNOWN_ERROR = 28` — Unknown error.
