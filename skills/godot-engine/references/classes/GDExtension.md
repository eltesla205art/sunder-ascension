# GDExtension

**Inherits:** Resource

A native library for GDExtension.

The GDExtension resource type represents a shared library which can expand the functionality of the engine. The GDExtensionManager singleton is responsible for loading, reloading, and unloading GDExtension resources. Note: GDExtension itself is not a scripting language and has no relation to GDScript resources.

## Methods

- `get_minimum_library_initialization_level() -> int[GDExtension.InitializationLevel]` *const* — Returns the lowest level required for this extension to be properly initialized (see the `InitializationLevel` enum).
- `is_library_open() -> bool` *const* — Returns `true` if this extension's library has been opened.

## Enum InitializationLevel

- `INITIALIZATION_LEVEL_CORE = 0` — The library is initialized at the same time as the core features of the engine.
- `INITIALIZATION_LEVEL_SERVERS = 1` — The library is initialized at the same time as the engine's servers (such as RenderingServer or PhysicsServer3D).
- `INITIALIZATION_LEVEL_SCENE = 2` — The library is initialized at the same time as the engine's scene-related classes.
- `INITIALIZATION_LEVEL_EDITOR = 3` — The library is initialized at the same time as the engine's editor classes.
