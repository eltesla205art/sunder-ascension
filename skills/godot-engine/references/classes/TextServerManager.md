# TextServerManager

**Inherits:** Object

A singleton for managing TextServer implementations.

TextServerManager is the API backend for loading, enumerating, and switching TextServers. Note: Switching text server at runtime is possible, but will invalidate all fonts and text buffers. Make sure to unload all controls, fonts, and themes before doing so.

## Methods

- `add_interface(interface: TextServer) -> void` — Registers a TextServer interface.
- `find_interface(name: String) -> TextServer` *const* — Finds an interface by its `name`.
- `get_interface(idx: int) -> TextServer` *const* — Returns the interface registered at a given index.
- `get_interface_count() -> int` *const* — Returns the number of interfaces currently registered.
- `get_interfaces() -> Dictionary[]` *const* — Returns a list of available interfaces, with the index and name of each interface.
- `get_primary_interface() -> TextServer` *const* — Returns the primary TextServer interface currently in use.
- `remove_interface(interface: TextServer) -> void` — Removes an interface.
- `set_primary_interface(index: TextServer) -> void` — Sets the primary TextServer interface.

## Signals

- `interface_added(interface_name: StringName)` — Emitted when a new interface has been added.
- `interface_removed(interface_name: StringName)` — Emitted when an interface is removed.
