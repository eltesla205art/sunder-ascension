# Node

**Inherits:** Object

Base class for all scene objects.

Nodes are Godot's building blocks. They can be assigned as the child of another node, resulting in a tree arrangement. A given node can contain any number of nodes as children with the requirement that all siblings (direct children of a node) should have unique names. A tree of nodes is called a scene.

## Properties

- `auto_translate_mode: Node.AutoTranslateMode` = `0` — Defines if any text should automatically change to its translated version depending on the current locale (for nodes such as Label, RichTextLabel, Window, etc.).
- `editor_description: String` = `""` — An optional description to the node.
- `multiplayer: MultiplayerAPI` — The MultiplayerAPI instance associated with this node.
- `name: StringName` — The name of the node.
- `owner: Node` — The owner of this node.
- `physics_interpolation_mode: Node.PhysicsInterpolationMode` = `0` — The physics interpolation mode to use for this node.
- `process_mode: Node.ProcessMode` = `0` — The node's processing behavior.
- `process_physics_priority: int` = `0` — Similar to `process_priority` but for `NOTIFICATION_PHYSICS_PROCESS`, `_physics_process`, or `NOTIFICATION_INTERNAL_PHYSICS_PROCESS`.
- `process_priority: int` = `0` — The node's execution order of the process callbacks (`_process`, `NOTIFICATION_PROCESS`, and `NOTIFICATION_INTERNAL_PROCESS`).
- `process_thread_group: Node.ProcessThreadGroup` = `0` — Set the process thread group for this node (basically, whether it receives `NOTIFICATION_PROCESS`, `NOTIFICATION_PHYSICS_PROCESS`, `_process` or `_physics_process` (and the internal versions) on the main thread or in a sub-thread.
- `process_thread_group_order: int` — Change the process thread group order.
- `process_thread_messages: Node.ProcessThreadMessages` — Set whether the current thread group will process messages (calls to `call_deferred_thread_group` on threads), and whether it wants to receive them during regular process or physics process callbacks.
- `scene_file_path: String` — The original scene's file path, if the node has been instantiated from a PackedScene file.
- `unique_name_in_owner: bool` = `false` — If `true`, the node can be accessed from any node sharing the same `owner` or from the `owner` itself, with special `%Name` syntax in `get_node`.

## Methods

- `_enter_tree() -> void` *virtual* — Called when the node enters the SceneTree (e.g. upon instantiating, scene changing, or after calling `add_child` in a script).
- `_exit_tree() -> void` *virtual* — Called when the node is about to leave the SceneTree (e.g. upon freeing, scene changing, or after calling `remove_child` in a script).
- `_get_accessibility_configuration_warnings() -> PackedStringArray` *virtual const* — The elements in the array returned from this method are displayed as warnings in the Scene dock if the script that overrides it is a `tool` script, and accessibility warnings are enabled in the editor settings.
- `_get_configuration_warnings() -> PackedStringArray` *virtual const* — The elements in the array returned from this method are displayed as warnings in the Scene dock if the script that overrides it is a `tool` script.
- `_get_focused_accessibility_element() -> RID` *virtual const* — Called during accessibility information updates to determine the currently focused sub-element, should return a sub-element RID or the value returned by `get_accessibility_element`.
- `_input(event: InputEvent) -> void` *virtual* — Called when there is an input event.
- `_physics_process(delta: float) -> void` *virtual* — Called once on each physics tick, and allows Nodes to synchronize their logic with physics ticks.
- `_process(delta: float) -> void` *virtual* — Called on each idle frame, prior to rendering, and after physics ticks have been processed.
- `_ready() -> void` *virtual* — Called when the node is "ready", i.e. when both the node and its children have entered the scene tree.
- `_shortcut_input(event: InputEvent) -> void` *virtual* — Called when an InputEventKey, InputEventShortcut, or InputEventJoypadButton hasn't been consumed by `_input` or any GUI Control item.
- `_unhandled_input(event: InputEvent) -> void` *virtual* — Called when an InputEvent hasn't been consumed by `_input` or any GUI Control item.
- `_unhandled_key_input(event: InputEvent) -> void` *virtual* — Called when an InputEventKey hasn't been consumed by `_input` or any GUI Control item.
- `add_child(node: Node, force_readable_name: bool = false, internal: Node.InternalMode = 0) -> void` — Adds a child `node`.
- `add_sibling(sibling: Node, force_readable_name: bool = false) -> void` — Adds a `sibling` node to this node's parent, and moves the added sibling right below this node.
- `add_to_group(group: StringName, persistent: bool = false) -> void` — Adds the node to the `group`.
- `atr(message: String, context: StringName = "") -> String` *const* — Translates a `message`, using the translation catalogs configured in the Project Settings.
- `atr_n(message: String, plural_message: StringName, n: int, context: StringName = "") -> String` *const* — Translates a `message` or `plural_message`, using the translation catalogs configured in the Project Settings.
- `call_deferred_thread_group(method: StringName) -> Variant` *vararg* — This function is similar to `Object.call_deferred` except that the call will take place when the node thread group is processed.
- `call_thread_safe(method: StringName) -> Variant` *vararg* — This function ensures that the calling of this function will succeed, no matter whether it's being done from a thread or not.
- `can_auto_translate() -> bool` *const* — Returns `true` if this node can automatically translate messages depending on the current locale.
- `can_process() -> bool` *const* — Returns `true` if the node can receive processing notifications and input callbacks (`NOTIFICATION_PROCESS`, `_input`, etc.) from the SceneTree and Viewport.
- `create_tween() -> Tween` — Creates a new Tween and binds it to this node.
- `duplicate(flags: int = 15) -> Node` *const* — Duplicates the node, returning a new node with all of its properties, signals, groups, and children copied from the original, recursively.
- `find_child(pattern: String, recursive: bool = true, owned: bool = true) -> Node` *const* — Finds the first descendant of this node whose `name` matches `pattern`, returning `null` if no match is found.
- `find_children(pattern: String, type: String = "", recursive: bool = true, owned: bool = true) -> Node[]` *const* — Finds all descendants of this node whose names match `pattern`, returning an empty Array if no match is found.
- `find_parent(pattern: String) -> Node` *const* — Finds the first ancestor of this node whose `name` matches `pattern`, returning `null` if no match is found.
- `get_accessibility_element() -> RID` *const* — Returns main accessibility element RID.
- `get_child(idx: int, include_internal: bool = false) -> Node` *const* — Fetches a child node by its index.
- `get_child_count(include_internal: bool = false) -> int` *const* — Returns the number of children of this node.
- `get_children(include_internal: bool = false) -> Node[]` *const* — Returns all children of this node inside an Array.
- `get_groups() -> StringName[]` *const* — Returns an Array of group names that the node has been added to.
- `get_index(include_internal: bool = false) -> int` *const* — Returns this node's order among its siblings.
- `get_last_exclusive_window() -> Window` *const* — Returns the Window that contains this node, or the last exclusive child in a chain of windows starting with the one that contains this node.
- `get_multiplayer_authority() -> int` *const* — Returns the peer ID of the multiplayer authority for this node.
- `get_node(path: NodePath) -> Node` *const* — Fetches a node.
- `get_node_and_resource(path: NodePath) -> Array` — Fetches a node and its most nested resource as specified by the NodePath's subname.
- `get_node_or_null(path: NodePath) -> Node` *const* — Fetches a node by NodePath.
- `get_node_rpc_config() -> Variant` *const* — Returns a Dictionary mapping method names to their RPC configuration defined for this node using `rpc_config`.
- `get_orphan_node_ids() -> int[]` *static* — Returns object IDs of all orphan nodes (nodes outside the SceneTree).
- `get_parent() -> Node` *const* — Returns this node's parent node, or `null` if the node doesn't have a parent.
- `get_path() -> NodePath` *const* — Returns the node's absolute path, relative to the `SceneTree.root`.
- `get_path_to(node: Node, use_unique_path: bool = false) -> NodePath` *const* — Returns the relative NodePath from this node to the specified `node`.
- `get_physics_process_delta_time() -> float` *const* — Returns the time elapsed (in seconds) since the last physics callback.
- `get_process_delta_time() -> float` *const* — Returns the time elapsed (in seconds) since the last process callback.
- `get_scene_instance_load_placeholder() -> bool` *const* — Returns `true` if this node is an instance load placeholder.
- `get_tree() -> SceneTree` *const* — Returns the SceneTree that contains this node.
- `get_tree_string() -> String` — Returns the tree as a String.
- `get_tree_string_pretty() -> String` — Similar to `get_tree_string`, this returns the tree as a String.
- `get_viewport() -> Viewport` *const* — Returns the node's closest Viewport ancestor, if the node is inside the tree.
- `get_window() -> Window` *const* — Returns the Window that contains this node.
- `has_node(path: NodePath) -> bool` *const* — Returns `true` if the `path` points to a valid node.
- `has_node_and_resource(path: NodePath) -> bool` *const* — Returns `true` if `path` points to a valid node and its subnames point to a valid Resource, e.g.
- `is_ancestor_of(node: Node) -> bool` *const* — Returns `true` if the given `node` is a direct or indirect child of this node.
- `is_displayed_folded() -> bool` *const* — Returns `true` if the node is folded (collapsed) in the Scene dock.
- `is_editable_instance(node: Node) -> bool` *const* — Returns `true` if `node` has editable children enabled relative to this node.
- `is_greater_than(node: Node) -> bool` *const* — Returns `true` if the given `node` occurs later in the scene hierarchy than this node.
- `is_in_group(group: StringName) -> bool` *const* — Returns `true` if this node has been added to the given `group`.
- `is_inside_tree() -> bool` *const* — Returns `true` if this node is currently inside a SceneTree.
- `is_multiplayer_authority() -> bool` *const* — Returns `true` if the local system is the multiplayer authority of this node.
- `is_node_ready() -> bool` *const* — Returns `true` if the node is ready, i.e. it's inside scene tree and all its children are initialized.
- `is_part_of_edited_scene() -> bool` *const* — Returns `true` if the node is part of the scene currently opened in the editor.
- `is_physics_interpolated() -> bool` *const* — Returns `true` if physics interpolation is enabled for this node (see `physics_interpolation_mode`).
- `is_physics_interpolated_and_enabled() -> bool` *const* — Returns `true` if physics interpolation is enabled (see `physics_interpolation_mode`) and enabled in the SceneTree.
- `is_physics_processing() -> bool` *const* — Returns `true` if physics processing is enabled (see `set_physics_process`).
- `is_physics_processing_internal() -> bool` *const* — Returns `true` if internal physics processing is enabled (see `set_physics_process_internal`).
- `is_processing() -> bool` *const* — Returns `true` if processing is enabled (see `set_process`).
- `is_processing_input() -> bool` *const* — Returns `true` if the node is processing input (see `set_process_input`).
- `is_processing_internal() -> bool` *const* — Returns `true` if internal processing is enabled (see `set_process_internal`).
- `is_processing_shortcut_input() -> bool` *const* — Returns `true` if the node is processing shortcuts (see `set_process_shortcut_input`).
- `is_processing_unhandled_input() -> bool` *const* — Returns `true` if the node is processing unhandled input (see `set_process_unhandled_input`).
- `is_processing_unhandled_key_input() -> bool` *const* — Returns `true` if the node is processing unhandled key input (see `set_process_unhandled_key_input`).
- `move_child(child_node: Node, to_index: int) -> void` — Moves `child_node` to the given index.
- `notify_deferred_thread_group(what: int) -> void` — Similar to `call_deferred_thread_group`, but for notifications.
- `notify_thread_safe(what: int) -> void` — Similar to `call_thread_safe`, but for notifications.
- `print_orphan_nodes() -> void` *static* — Prints all orphan nodes (nodes outside the SceneTree).
- `print_tree() -> void` — Prints the node and its children to the console, recursively.
- `print_tree_pretty() -> void` — Prints the node and its children to the console, recursively.
- `propagate_call(method: StringName, args: Array = [], parent_first: bool = false) -> void` — Calls the given `method` name, passing `args` as arguments, on this node and all of its children, recursively.
- `propagate_notification(what: int) -> void` — Calls `Object.notification` with `what` on this node and all of its children, recursively.
- `queue_accessibility_update() -> void` — Queues an accessibility information update for this node.
- `queue_free() -> void` — Queues this node to be deleted at the end of the current frame.
- `remove_child(node: Node) -> void` — Removes a child `node`.
- `remove_from_group(group: StringName) -> void` — Removes the node from the given `group`.
- `reparent(new_parent: Node, keep_global_transform: bool = true) -> void` — Changes the parent of this Node to the `new_parent`.
- `replace_by(node: Node, keep_groups: bool = false) -> void` — Replaces this node by the given `node`.
- `request_ready() -> void` — Requests `_ready` to be called again the next time the node enters the tree.
- `reset_physics_interpolation() -> void` — When physics interpolation is active, moving a node to a radically different transform (such as placement within a level) can result in a visible glitch as the object is rendered moving from the old to new position over the physics tick.
- `rpc(method: StringName) -> int[Error]` *vararg* — Sends a remote procedure call request for the given `method` to peers on the network (and locally), sending additional arguments to the method called by the RPC.
- `rpc_config(method: StringName, config: Variant) -> void` — Changes the RPC configuration for the given `method`.
- `rpc_id(peer_id: int, method: StringName) -> int[Error]` *vararg* — Sends a `rpc` to a specific peer identified by `peer_id` (see `MultiplayerPeer.set_target_peer`).
- `set_deferred_thread_group(property: StringName, value: Variant) -> void` — Similar to `call_deferred_thread_group`, but for setting properties.
- `set_display_folded(fold: bool) -> void` — If set to `true`, the node appears folded in the Scene dock.
- `set_editable_instance(node: Node, is_editable: bool) -> void` — Set to `true` to allow all nodes owned by `node` to be available, and editable, in the Scene dock, even if their `owner` is not the scene root.
- `set_multiplayer_authority(id: int, recursive: bool = true) -> void` — Sets the node's multiplayer authority to the peer with the given peer `id`.
- `set_physics_process(enable: bool) -> void` — If set to `true`, enables physics (fixed framerate) processing.
- `set_physics_process_internal(enable: bool) -> void` — If set to `true`, enables internal physics for this node.
- `set_process(enable: bool) -> void` — If set to `true`, enables processing.
- `set_process_input(enable: bool) -> void` — If set to `true`, enables input processing.
- `set_process_internal(enable: bool) -> void` — If set to `true`, enables internal processing for this node.
- `set_process_shortcut_input(enable: bool) -> void` — If set to `true`, enables shortcut processing for this node.
- `set_process_unhandled_input(enable: bool) -> void` — If set to `true`, enables unhandled input processing.
- `set_process_unhandled_key_input(enable: bool) -> void` — If set to `true`, enables unhandled key input processing.
- `set_scene_instance_load_placeholder(load_placeholder: bool) -> void` — If set to `true`, the node becomes an InstancePlaceholder when packed and instantiated from a PackedScene.
- `set_thread_safe(property: StringName, value: Variant) -> void` — Similar to `call_thread_safe`, but for setting properties.
- `set_translation_domain_inherited() -> void` — Makes this node inherit the translation domain from its parent node.
- `update_configuration_warnings() -> void` — Refreshes the warnings displayed for this node in the Scene dock.

## Signals

- `child_entered_tree(node: Node)` — Emitted when the child `node` enters the SceneTree, usually because this node entered the tree (see `tree_entered`), or `add_child` has been called.
- `child_exiting_tree(node: Node)` — Emitted when the child `node` is about to exit the SceneTree, usually because this node is exiting the tree (see `tree_exiting`), or because the child `node` is being removed or freed.
- `child_order_changed()` — Emitted when the list of children is changed.
- `editor_description_changed(node: Node)` — Emitted when the node's editor description field changed.
- `editor_state_changed()` — Emitted when an attribute of the node that is relevant to the editor is changed.
- `ready()` — Emitted when the node is considered ready, after `_ready` is called.
- `renamed()` — Emitted when the node's `name` is changed, if the node is inside the tree.
- `replacing_by(node: Node)` — Emitted when this node is being replaced by the `node`, see `replace_by`.
- `tree_entered()` — Emitted when the node enters the tree.
- `tree_exited()` — Emitted after the node exits the tree and is no longer active.
- `tree_exiting()` — Emitted when the node is just about to exit the tree.

## Enum ProcessMode

- `PROCESS_MODE_INHERIT = 0` — Inherits `process_mode` from the node's parent.
- `PROCESS_MODE_PAUSABLE = 1` — Processes when `SceneTree.paused` is `false`.
- `PROCESS_MODE_WHEN_PAUSED = 2` — Processes only when `SceneTree.paused` is `true`.
- `PROCESS_MODE_ALWAYS = 3` — Always processes.
- `PROCESS_MODE_DISABLED = 4` — Never processes.

## Enum ProcessThreadGroup

- `PROCESS_THREAD_GROUP_INHERIT = 0` — Process this node based on the thread group mode of the first parent (or grandparent) node that has a thread group mode that is not inherit.
- `PROCESS_THREAD_GROUP_MAIN_THREAD = 1` — Process this node (and child nodes set to inherit) on the main thread.
- `PROCESS_THREAD_GROUP_SUB_THREAD = 2` — Process this node (and child nodes set to inherit) on a sub-thread.

## Enum ProcessThreadMessages

- `FLAG_PROCESS_THREAD_MESSAGES = 1` — Allows this node to process threaded messages created with `call_deferred_thread_group` right before `_process` is called.
- `FLAG_PROCESS_THREAD_MESSAGES_PHYSICS = 2` — Allows this node to process threaded messages created with `call_deferred_thread_group` right before `_physics_process` is called.
- `FLAG_PROCESS_THREAD_MESSAGES_ALL = 3` — Allows this node to process threaded messages created with `call_deferred_thread_group` right before either `_process` or `_physics_process` are called.

## Enum PhysicsInterpolationMode

- `PHYSICS_INTERPOLATION_MODE_INHERIT = 0` — Inherits `physics_interpolation_mode` from the node's parent.
- `PHYSICS_INTERPOLATION_MODE_ON = 1` — Enables physics interpolation for this node and for children set to `PHYSICS_INTERPOLATION_MODE_INHERIT`.
- `PHYSICS_INTERPOLATION_MODE_OFF = 2` — Disables physics interpolation for this node and for children set to `PHYSICS_INTERPOLATION_MODE_INHERIT`.

## Enum DuplicateFlags

- `DUPLICATE_SIGNALS = 1` — Duplicate the node's signal connections that are connected with the `Object.CONNECT_PERSIST` flag.
- `DUPLICATE_GROUPS = 2` — Duplicate the node's groups.
- `DUPLICATE_SCRIPTS = 4` — Duplicate the node's script (also overriding the duplicated children's scripts, if combined with `DUPLICATE_USE_INSTANTIATION`).
- `DUPLICATE_USE_INSTANTIATION = 8` — Duplicate using `PackedScene.instantiate`.
- `DUPLICATE_INTERNAL_STATE = 16` — Duplicate also non-serializable variables (i.e. without `@GlobalScope.PROPERTY_USAGE_STORAGE`).
- `DUPLICATE_DEFAULT = 15` — Duplicate using default flags.

## Enum InternalMode

- `INTERNAL_MODE_DISABLED = 0` — The node will not be internal.
- `INTERNAL_MODE_FRONT = 1` — The node will be placed at the beginning of the parent's children, before any non-internal sibling.
- `INTERNAL_MODE_BACK = 2` — The node will be placed at the end of the parent's children, after any non-internal sibling.

## Enum AutoTranslateMode

- `AUTO_TRANSLATE_MODE_INHERIT = 0` — Inherits `auto_translate_mode` from the node's parent.
- `AUTO_TRANSLATE_MODE_ALWAYS = 1` — Always automatically translate.
- `AUTO_TRANSLATE_MODE_DISABLED = 2` — Never automatically translate.

## Constants

- `NOTIFICATION_ENTER_TREE = 10` — Notification received when the node enters a SceneTree.
- `NOTIFICATION_EXIT_TREE = 11` — Notification received when the node is about to exit a SceneTree.
- `NOTIFICATION_MOVED_IN_PARENT = 12` — 
- `NOTIFICATION_READY = 13` — Notification received when the node is ready.
- `NOTIFICATION_PAUSED = 14` — Notification received when the node is paused.
- `NOTIFICATION_UNPAUSED = 15` — Notification received when the node is unpaused.
- `NOTIFICATION_PHYSICS_PROCESS = 16` — Notification received from the tree every physics frame when `is_physics_processing` returns `true`.
- `NOTIFICATION_PROCESS = 17` — Notification received from the tree every rendered frame when `is_processing` returns `true`.
- `NOTIFICATION_PARENTED = 18` — Notification received when the node is set as a child of another node (see `add_child` and `add_sibling`).
- `NOTIFICATION_UNPARENTED = 19` — Notification received when the parent node calls `remove_child` on this node.
- `NOTIFICATION_SCENE_INSTANTIATED = 20` — Notification received only by the newly instantiated scene root node, when `PackedScene.instantiate` is completed.
- `NOTIFICATION_DRAG_BEGIN = 21` — Notification received when a drag operation begins.
- `NOTIFICATION_DRAG_END = 22` — Notification received when a drag operation ends.
- `NOTIFICATION_PATH_RENAMED = 23` — Notification received when the node's `name` or one of its ancestors' `name` is changed.
- `NOTIFICATION_CHILD_ORDER_CHANGED = 24` — Notification received when the list of children is changed.
- `NOTIFICATION_INTERNAL_PROCESS = 25` — Notification received from the tree every rendered frame when `is_processing_internal` returns `true`.
- `NOTIFICATION_INTERNAL_PHYSICS_PROCESS = 26` — Notification received from the tree every physics frame when `is_physics_processing_internal` returns `true`.
- `NOTIFICATION_POST_ENTER_TREE = 27` — Notification received when the node enters the tree, just before `NOTIFICATION_READY` may be received.
- `NOTIFICATION_DISABLED = 28` — Notification received when the node is disabled.
- `NOTIFICATION_ENABLED = 29` — Notification received when the node is enabled again after being disabled.
- `NOTIFICATION_RESET_PHYSICS_INTERPOLATION = 2001` — Notification received when `reset_physics_interpolation` is called on the node or its ancestors.
- `NOTIFICATION_EDITOR_PRE_SAVE = 9001` — Notification received right before the scene with the node is saved in the editor.
- `NOTIFICATION_EDITOR_POST_SAVE = 9002` — Notification received right after the scene with the node is saved in the editor.
- `NOTIFICATION_WM_MOUSE_ENTER = 1002` — Notification received when the mouse enters the window.
- `NOTIFICATION_WM_MOUSE_EXIT = 1003` — Notification received when the mouse leaves the window.
- `NOTIFICATION_WM_WINDOW_FOCUS_IN = 1004` — Notification received from the OS when the node's Window ancestor is focused.
- `NOTIFICATION_WM_WINDOW_FOCUS_OUT = 1005` — Notification received from the OS when the node's Window ancestor is defocused.
- `NOTIFICATION_WM_CLOSE_REQUEST = 1006` — Notification received from the OS when a close request is sent (e.g. closing the window with a "Close" button or `Alt + F4`).
- `NOTIFICATION_WM_GO_BACK_REQUEST = 1007` — Notification received from the OS when a go back request is sent (e.g. pressing the "Back" button on Android).
- `NOTIFICATION_WM_SIZE_CHANGED = 1008` — Notification received when the window is resized.
- `NOTIFICATION_WM_DPI_CHANGE = 1009` — Notification received from the OS when the screen's dots per inch (DPI) scale is changed.
- `NOTIFICATION_VP_MOUSE_ENTER = 1010` — Notification received when the mouse cursor enters the Viewport's visible area, that is not occluded behind other Controls or Windows, provided its `Viewport.gui_disable_input` is `false` and regardless if it's currently focused or not.
- `NOTIFICATION_VP_MOUSE_EXIT = 1011` — Notification received when the mouse cursor leaves the Viewport's visible area, that is not occluded behind other Controls or Windows, provided its `Viewport.gui_disable_input` is `false` and regardless if it's currently focused or not.
- `NOTIFICATION_WM_POSITION_CHANGED = 1012` — Notification received when the window is moved.
- `NOTIFICATION_WM_OUTPUT_MAX_LINEAR_VALUE_CHANGED = 1013` — Notification received when the output max linear value returned by `Window.get_output_max_linear_value` has changed.
- `NOTIFICATION_OS_MEMORY_WARNING = 2009` — Notification received from the OS when the application is exceeding its allocated memory.
- `NOTIFICATION_TRANSLATION_CHANGED = 2010` — Notification received when translations may have changed.
- `NOTIFICATION_WM_ABOUT = 2011` — Notification received from the OS when a request for "About" information is sent.
- `NOTIFICATION_CRASH = 2012` — Notification received from Godot's crash handler when the engine is about to crash.
- `NOTIFICATION_OS_IME_UPDATE = 2013` — Notification received from the OS when an update of the Input Method Engine occurs (e.g. change of IME cursor position or composition string).
- `NOTIFICATION_APPLICATION_RESUMED = 2014` — Notification received from the OS when the application is resumed.
- `NOTIFICATION_APPLICATION_PAUSED = 2015` — Notification received from the OS when the application is paused.
- `NOTIFICATION_APPLICATION_FOCUS_IN = 2016` — Notification received from the OS when the application is focused, i.e. when changing the focus from the OS desktop or a thirdparty application to any open window of the Godot instance.
- `NOTIFICATION_APPLICATION_FOCUS_OUT = 2017` — Notification received from the OS when the application is defocused, i.e. when changing the focus from any open window of the Godot instance to the OS desktop or a thirdparty application.
- `NOTIFICATION_TEXT_SERVER_CHANGED = 2018` — Notification received when the TextServer is changed.
- `NOTIFICATION_APPLICATION_PIP_MODE_ENTERED = 2019` — Notification received when the application enters picture-in-picture mode.
- `NOTIFICATION_APPLICATION_PIP_MODE_EXITED = 2020` — Notification received when the application exits picture-in-picture mode.
- `NOTIFICATION_ACCESSIBILITY_UPDATE = 3000` — Notification received when an accessibility information update is required.
- `NOTIFICATION_ACCESSIBILITY_INVALIDATE = 3001` — Notification received when accessibility elements are invalidated.
