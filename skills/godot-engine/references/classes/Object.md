# Object


Base class for all other classes in the engine.

An advanced Variant type. All classes in the engine inherit from Object. Each class may define new properties, methods or signals, which are available to all inheriting classes. For example, a Sprite2D instance is able to call `Node.add_child` because it inherits from Node.

## Methods

- `_get(property: StringName) -> Variant` *virtual* — Override this method to customize the behavior of `get`.
- `_get_property_list() -> Dictionary[]` *virtual* — Override this method to provide a custom list of additional properties to handle by the engine.
- `_init() -> void` *virtual* — Called when the object's script is instantiated, oftentimes after the object is initialized in memory (through `Object.new()` in GDScript, or `new GodotObject` in C#).
- `_iter_get(iter: Variant) -> Variant` *virtual* — Returns the current iterable value.
- `_iter_init(iter: Array) -> bool` *virtual* — Initializes the iterator.
- `_iter_next(iter: Array) -> bool` *virtual* — Moves the iterator to the next iteration.
- `_notification(what: int) -> void` *virtual* — Called when the object receives a notification, which can be identified in `what` by comparing it with a constant.
- `_property_can_revert(property: StringName) -> bool` *virtual* — Override this method to customize the given `property`'s revert behavior.
- `_property_get_revert(property: StringName) -> Variant` *virtual* — Override this method to customize the given `property`'s revert behavior.
- `_set(property: StringName, value: Variant) -> bool` *virtual* — Override this method to customize the behavior of `set`.
- `_to_string() -> String` *virtual* — Override this method to customize the return value of `to_string`, and therefore the object's representation as a String.
- `_validate_property(property: Dictionary) -> void` *virtual* — Override this method to customize existing properties.
- `add_user_signal(signal: String, arguments: Array = []) -> void` — Adds a user-defined signal named `signal`.
- `call(method: StringName) -> Variant` *vararg* — Calls the `method` on the object and returns the result.
- `call_deferred(method: StringName) -> Variant` *vararg* — Calls the `method` on the object during idle time.
- `callv(method: StringName, arg_array: Array) -> Variant` — Calls the `method` on the object and returns the result.
- `can_translate_messages() -> bool` *const* — Returns `true` if the object is allowed to translate messages with `tr` and `tr_n`.
- `cancel_free() -> void` — If this method is called during `NOTIFICATION_PREDELETE`, this object will reject being freed and will remain allocated.
- `connect(signal: StringName, callable: Callable, flags: int = 0) -> int[Error]` — Connects a `signal` by name to a `callable`.
- `disconnect(signal: StringName, callable: Callable) -> void` — Disconnects a `signal` by name from a given `callable`.
- `emit_signal(signal: StringName) -> int[Error]` *vararg* — Emits the given `signal` by name.
- `free() -> void` — Deletes the object from memory.
- `get(property: StringName) -> Variant` *const* — Returns the Variant value of the given `property`.
- `get_class() -> String` *const* — Returns the object's built-in class name, as a String.
- `get_incoming_connections() -> Dictionary[]` *const* — Returns an Array of signal connections received by this object.
- `get_indexed(property_path: NodePath) -> Variant` *const* — Gets the object's property indexed by the given `property_path`.
- `get_instance_id() -> int` *const* — Returns the object's unique instance ID.
- `get_meta(name: StringName, default: Variant = null) -> Variant` *const* — Returns the object's metadata value for the given entry `name`.
- `get_meta_list() -> StringName[]` *const* — Returns the object's metadata entry names as an Array of StringNames.
- `get_method_argument_count(method: StringName) -> int` *const* — Returns the number of arguments of the given `method` by name.
- `get_method_list() -> Dictionary[]` *const* — Returns this object's methods and their signatures as an Array of dictionaries.
- `get_property_list() -> Dictionary[]` *const* — Returns the object's property list as an Array of dictionaries.
- `get_script() -> Variant` *const* — Returns the object's Script instance, or `null` if no script is attached.
- `get_signal_connection_list(signal: StringName) -> Dictionary[]` *const* — Returns an Array of connections for the given `signal` name.
- `get_signal_list() -> Dictionary[]` *const* — Returns the list of existing signals as an Array of dictionaries.
- `get_translation_domain() -> StringName` *const* — Returns the name of the translation domain used by `tr` and `tr_n`.
- `has_connections(signal: StringName) -> bool` *const* — Returns `true` if any connection exists on the given `signal` name.
- `has_meta(name: StringName) -> bool` *const* — Returns `true` if a metadata entry is found with the given `name`.
- `has_method(method: StringName) -> bool` *const* — Returns `true` if the given `method` name exists in the object.
- `has_signal(signal: StringName) -> bool` *const* — Returns `true` if the given `signal` name exists in the object.
- `has_user_signal(signal: StringName) -> bool` *const* — Returns `true` if the given user-defined `signal` name exists.
- `is_blocking_signals() -> bool` *const* — Returns `true` if the object is blocking its signals from being emitted.
- `is_class(class: StringName) -> bool` *const* — Returns `true` if the object inherits from the given `class`.
- `is_connected(signal: StringName, callable: Callable) -> bool` *const* — Returns `true` if a connection exists between the given `signal` name and `callable`.
- `is_queued_for_deletion() -> bool` *const* — Returns `true` if the methods `Node.queue_free` or `SceneTree.queue_delete` was called for the object.
- `notification(what: int, reversed: bool = false) -> void` — Sends the given `what` notification to all classes inherited by the object, triggering calls to `_notification`, starting from the highest ancestor (the Object class) and going down to the object's script.
- `notify_property_list_changed() -> void` — Emits the `property_list_changed` signal.
- `property_can_revert(property: StringName) -> bool` *const* — Returns `true` if the given `property` has a custom default value.
- `property_get_revert(property: StringName) -> Variant` *const* — Returns the custom default value of the given `property`.
- `remove_meta(name: StringName) -> void` — Removes the given entry `name` from the object's metadata.
- `remove_user_signal(signal: StringName) -> void` — Removes the given user signal `signal` from the object.
- `set(property: StringName, value: Variant) -> void` — Assigns `value` to the given `property`.
- `set_block_signals(enable: bool) -> void` — If set to `true`, the object becomes unable to emit signals.
- `set_deferred(property: StringName, value: Variant) -> void` — Assigns `value` to the given `property`, at the end of the current frame.
- `set_indexed(property_path: NodePath, value: Variant) -> void` — Assigns a new `value` to the property identified by the `property_path`.
- `set_message_translation(enable: bool) -> void` — If set to `true`, allows the object to translate messages with `tr` and `tr_n`.
- `set_meta(name: StringName, value: Variant) -> void` — Adds or changes the entry `name` inside the object's metadata.
- `set_script(script: Variant) -> void` — Attaches `script` to the object, and instantiates it.
- `set_translation_domain(domain: StringName) -> void` — Sets the name of the translation domain used by `tr` and `tr_n`.
- `to_string() -> String` — Returns a String representing the object.
- `tr(message: StringName, context: StringName = &"") -> String` *const* — Translates a `message`, using the translation catalogs configured in the Project Settings.
- `tr_n(message: StringName, plural_message: StringName, n: int, context: StringName = &"") -> String` *const* — Translates a `message` or `plural_message`, using the translation catalogs configured in the Project Settings.

## Signals

- `property_list_changed()` — Emitted when `notify_property_list_changed` is called.
- `script_changed()` — Emitted when the object's script is changed.

## Enum ConnectFlags

- `CONNECT_DEFERRED = 1` — Deferred connections trigger their Callables on idle time (at the end of the frame), rather than instantly.
- `CONNECT_PERSIST = 2` — Persisting connections are stored when the object is serialized (such as when using `PackedScene.pack`).
- `CONNECT_ONE_SHOT = 4` — One-shot connections disconnect themselves after emission.
- `CONNECT_REFERENCE_COUNTED = 8` — Reference-counted connections can be assigned to the same Callable multiple times.
- `CONNECT_APPEND_SOURCE_OBJECT = 16` — On signal emission, the source object is automatically appended after the original arguments of the signal, regardless of the connected Callable's unbinds which affect only the original arguments of the signal (see `Callable.unbind`, `Callable.get_unbound_arguments_count`).

## Constants

- `NOTIFICATION_POSTINITIALIZE = 0` — Notification received when the object is initialized, before its script is attached.
- `NOTIFICATION_PREDELETE = 1` — Notification received when the object is about to be deleted.
- `NOTIFICATION_EXTENSION_RELOADED = 2` — Notification received when the object finishes hot reloading.
