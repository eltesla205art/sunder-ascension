# IP

**Inherits:** Object

Internet protocol (IP) support functions such as DNS resolution.

IP contains support functions for the Internet Protocol (IP). TCP/IP support is in different classes (see StreamPeerTCP and TCPServer). IP provides DNS hostname resolution support, both blocking and threaded.

## Methods

- `clear_cache(hostname: String = "") -> void` — Removes all of a `hostname`'s cached references.
- `erase_resolve_item(id: int) -> void` — Removes a given item `id` from the queue.
- `get_local_addresses() -> PackedStringArray` *const* — Returns all the user's current IPv4 and IPv6 addresses as an array.
- `get_local_interfaces() -> Dictionary[]` *const* — Returns all network adapters as an array.
- `get_resolve_item_address(id: int) -> String` *const* — Returns a queued hostname's IP address, given its queue `id`.
- `get_resolve_item_addresses(id: int) -> Array` *const* — Returns resolved addresses, or an empty array if an error happened or resolution didn't happen yet (see `get_resolve_item_status`).
- `get_resolve_item_status(id: int) -> int[IP.ResolverStatus]` *const* — Returns a queued hostname's status as a `ResolverStatus` constant, given its queue `id`.
- `resolve_hostname(host: String, ip_type: IP.Type = 3) -> String` — Returns a given hostname's IPv4 or IPv6 address when resolved (blocking-type method).
- `resolve_hostname_addresses(host: String, ip_type: IP.Type = 3) -> PackedStringArray` — Resolves a given hostname in a blocking way.
- `resolve_hostname_queue_item(host: String, ip_type: IP.Type = 3) -> int` — Creates a queue item to resolve a hostname to an IPv4 or IPv6 address depending on the `Type` constant given as `ip_type`.

## Enum ResolverStatus

- `RESOLVER_STATUS_NONE = 0` — DNS hostname resolver status: No status.
- `RESOLVER_STATUS_WAITING = 1` — DNS hostname resolver status: Waiting.
- `RESOLVER_STATUS_DONE = 2` — DNS hostname resolver status: Done.
- `RESOLVER_STATUS_ERROR = 3` — DNS hostname resolver status: Error.

## Enum Type

- `TYPE_NONE = 0` — Address type: None.
- `TYPE_IPV4 = 1` — Address type: Internet protocol version 4 (IPv4).
- `TYPE_IPV6 = 2` — Address type: Internet protocol version 6 (IPv6).
- `TYPE_ANY = 3` — Address type: Any.

## Constants

- `RESOLVER_MAX_QUERIES = 256` — Maximum number of concurrent DNS resolver queries allowed, `RESOLVER_INVALID_ID` is returned if exceeded.
- `RESOLVER_INVALID_ID = -1` — Invalid ID constant.
