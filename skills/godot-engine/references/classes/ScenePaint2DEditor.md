# ScenePaint2DEditor

**Inherits:** Control

Class for interacting with the 2D editor's Scene Paint Mode.

This class is available only in the editor and cannot be instantiated. Access it using `EditorInterface.get_scene_paint_2d`. It provides methods for editor plugins to interact with the scene painting tool. Plugins can register custom scene providers, and set the scene to be painted.

## Methods

- `get_painted_scene() -> Node2D` *const* — Returns the painted scene, or `null` if none is selected.
- `register_scene_provider(control: Control, callback: Callable) -> void` — Registers a custom scene provider.
- `set_painted_scene(scene: Node2D) -> void` — Sets the scene sample to be painted.
- `unregister_scene_provider(control: Control) -> void` — Removes a previously registered scene provider.

## Signals

- `scene_painted(node: Node2D)` — Emitted for each new node created during drawing.
