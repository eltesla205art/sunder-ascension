# JavaScriptBridge

**Inherits:** Object

Singleton that connects the engine with the browser's JavaScript context in Web export.

The JavaScriptBridge singleton is implemented only in the Web export. It's used to access the browser's JavaScript context. This allows interaction with embedding pages or calling third-party JavaScript APIs. Note: This singleton can be disabled at build-time to improve security.

## Methods

- `create_callback(callable: Callable) -> JavaScriptObject` — Creates a reference to a Callable that can be used as a callback by JavaScript.
- `create_object(object: String) -> Variant` *vararg* — Creates a new JavaScript object using the `new` constructor.
- `download_buffer(buffer: PackedByteArray, name: String, mime: String = "application/octet-stream") -> void` — Prompts the user to download a file containing the specified `buffer`.
- `eval(code: String, use_global_execution_context: bool = false) -> Variant` — Execute the string `code` as JavaScript code within the browser window.
- `force_fs_sync() -> void` — Force synchronization of the persistent file system (when enabled).
- `get_interface(interface: String) -> JavaScriptObject` — Returns an interface to a JavaScript object that can be used by scripts.
- `is_js_buffer(javascript_object: JavaScriptObject) -> bool` — Returns `true` if the given `javascript_object` is of type ArrayBuffer, DataView, or one of the many typed array objects.
- `js_buffer_to_packed_byte_array(javascript_buffer: JavaScriptObject) -> PackedByteArray` — Returns a copy of `javascript_buffer`'s contents as a PackedByteArray.
- `pwa_needs_update() -> bool` *const* — Returns `true` if a new version of the progressive web app is waiting to be activated.
- `pwa_update() -> int[Error]` — Performs the live update of the progressive web app.

## Signals

- `pwa_update_available()` — Emitted when an update for this progressive web app has been detected but is waiting to be activated because a previous version is active.
