# SceneTree

**Inherits:** MainLoop

Manages the game loop via a hierarchy of nodes.

As one of the most important classes, the SceneTree manages the hierarchy of nodes in a scene, as well as scenes themselves. Nodes can be added, fetched and removed. The whole scene tree (and thus the current scene) can be paused. Scenes can be loaded, switched and reloaded.

## Properties

- `auto_accept_quit: bool` = `true` — If `true`, the application automatically accepts quitting requests.
- `current_scene: Node` — The root node of the currently loaded main scene, usually as a direct child of `root`.
- `debug_collisions_hint: bool` = `false` — If `true`, collision shapes will be visible when running the game from the editor for debugging purposes.
- `debug_navigation_hint: bool` = `false` — If `true`, navigation polygons will be visible when running the game from the editor for debugging purposes.
- `debug_paths_hint: bool` = `false` — If `true`, curves from Path2D and Path3D nodes will be visible when running the game from the editor for debugging purposes.
- `edited_scene_root: Node` — The root of the scene currently being edited in the editor.
- `multiplayer_poll: bool` = `true` — If `true` (default value), enables automatic polling of the MultiplayerAPI for this SceneTree during `process_frame`.
- `paused: bool` = `false` — If `true`, the scene tree is considered paused.
- `physics_interpolation: bool` = `false` — If `true`, the renderer will interpolate the transforms of objects (both physics and non-physics) between the last two transforms, so that smooth motion is seen even when physics ticks do not coincide with rendered frames.
- `quit_on_go_back: bool` = `true` — If `true`, the application quits automatically when navigating back (e.g. using the system "Back" button on Android).
- `root: Window` — The tree's root Window.

## Methods

- `call_group(group: StringName, method: StringName) -> void` *vararg* — Calls `method` on each node inside this tree added to the given `group`.
- `call_group_flags(flags: int, group: StringName, method: StringName) -> void` *vararg* — Calls the given `method` on each node inside this tree added to the given `group`.
- `change_scene_to_file(path: String) -> int[Error]` — Changes the running scene to the one at the given `path`, after loading it into a PackedScene and creating a new instance.
- `change_scene_to_node(node: Node) -> int[Error]` — Changes the running scene to the provided Node.
- `change_scene_to_packed(packed_scene: PackedScene) -> int[Error]` — Changes the running scene to a new instance of the given PackedScene (which must be valid).
- `create_timer(time_sec: float, process_always: bool = true, process_in_physics: bool = false, ignore_time_scale: bool = false) -> SceneTreeTimer` — Returns a new SceneTreeTimer.
- `create_tween() -> Tween` — Creates and returns a new Tween processed in this tree.
- `get_first_node_in_group(group: StringName) -> Node` — Returns the first Node found inside the tree, that has been added to the given `group`, in scene hierarchy order.
- `get_frame() -> int` *const* — Returns how many physics process steps have been processed, since the application started.
- `get_multiplayer(for_path: NodePath = NodePath("")) -> MultiplayerAPI` *const* — Searches for the MultiplayerAPI configured for the given path, if one does not exist it searches the parent paths until one is found.
- `get_node_count() -> int` *const* — Returns the number of nodes inside this tree.
- `get_node_count_in_group(group: StringName) -> int` *const* — Returns the number of nodes assigned to the given group.
- `get_nodes_in_group(group: StringName) -> Node[]` — Returns an Array containing all nodes inside this tree, that have been added to the given `group`, in scene hierarchy order.
- `get_processed_tweens() -> Tween[]` — Returns an Array of currently existing Tweens in the tree, including paused tweens.
- `has_group(name: StringName) -> bool` *const* — Returns `true` if a node added to the given group `name` exists in the tree.
- `is_accessibility_enabled() -> bool` *const* — Returns `true` if accessibility features are enabled, and accessibility information updates are actively processed.
- `is_accessibility_supported() -> bool` *const* — Returns `true` if accessibility features are supported by the OS and enabled in project settings.
- `notify_group(group: StringName, notification: int) -> void` — Calls `Object.notification` with the given `notification` to all nodes inside this tree added to the `group`.
- `notify_group_flags(call_flags: int, group: StringName, notification: int) -> void` — Calls `Object.notification` with the given `notification` to all nodes inside this tree added to the `group`.
- `queue_delete(obj: Object) -> void` — Queues the given `obj` to be deleted, calling its `Object.free` at the end of the current frame.
- `quit(exit_code: int = 0) -> void` — Quits the application at the end of the current iteration, with the given `exit_code`.
- `reload_current_scene() -> int[Error]` — Reloads the currently active scene, replacing `current_scene` with a new instance of its original PackedScene.
- `set_group(group: StringName, property: String, value: Variant) -> void` — Sets the given `property` to `value` on all nodes inside this tree added to the given `group`.
- `set_group_flags(call_flags: int, group: StringName, property: String, value: Variant) -> void` — Sets the given `property` to `value` on all nodes inside this tree added to the given `group`.
- `set_multiplayer(multiplayer: MultiplayerAPI, root_path: NodePath = NodePath("")) -> void` — Sets a custom MultiplayerAPI with the given `root_path` (controlling also the relative subpaths), or override the default one if `root_path` is empty.
- `unload_current_scene() -> void` — If a current scene is loaded, calling this method will unload it.

## Signals

- `node_added(node: Node)` — Emitted when the `node` enters this tree.
- `node_configuration_warning_changed(node: Node)` — Emitted when the `node`'s `Node.update_configuration_warnings` is called.
- `node_removed(node: Node)` — Emitted when the `node` exits this tree.
- `node_renamed(node: Node)` — Emitted when the `node`'s `Node.name` is changed.
- `physics_frame()` — Emitted immediately before `Node._physics_process` is called on every node in this tree.
- `process_frame()` — Emitted immediately before `Node._process` is called on every node in this tree.
- `scene_changed()` — Emitted after the new scene is added to scene tree and initialized.
- `tree_changed()` — Emitted any time the tree's hierarchy changes (nodes being moved, renamed, etc.).
- `tree_process_mode_changed()` — Emitted when the `Node.process_mode` of any node inside the tree is changed.

## Enum GroupCallFlags

- `GROUP_CALL_DEFAULT = 0` — Call nodes within a group with no special behavior (default).
- `GROUP_CALL_REVERSE = 1` — Call nodes within a group in reverse tree hierarchy order (all nested children are called before their respective parent nodes).
- `GROUP_CALL_DEFERRED = 2` — Call nodes within a group at the end of the current frame (can be either process or physics frame), similar to `Object.call_deferred`.
- `GROUP_CALL_UNIQUE = 4` — Call nodes within a group only once, even if the call is executed many times in the same frame.
