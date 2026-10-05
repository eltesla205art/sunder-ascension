# EditorDebuggerPlugin

**Inherits:** RefCounted

A base class to implement debugger plugins.

EditorDebuggerPlugin provides functions related to the editor side of the debugger. To interact with the debugger, an instance of this class must be added to the editor via `EditorPlugin.add_debugger_plugin`. Once added, the `_setup_session` callback will be called for every EditorDebuggerSession available to the plugin, and when new ones are created (the sessions may be inactive during this stage). You can retrieve the available EditorDebuggerSessions via `get_sessions` or get a specific one via `get_session`.

## Methods

- `_breakpoint_set_in_tree(script: Script, line: int, enabled: bool) -> void` *virtual* — Override this method to be notified when a breakpoint is set in the editor.
- `_breakpoints_cleared_in_tree() -> void` *virtual* — Override this method to be notified when all breakpoints are cleared in the editor.
- `_capture(message: String, data: Array, session_id: int) -> bool` *virtual* — Override this method to process incoming messages.
- `_goto_script_line(script: Script, line: int) -> void` *virtual* — Override this method to be notified when a breakpoint line has been clicked in the debugger breakpoint panel.
- `_has_capture(capture: String) -> bool` *virtual const* — Override this method to enable receiving messages from the debugger.
- `_setup_session(session_id: int) -> void` *virtual* — Override this method to be notified whenever a new EditorDebuggerSession is created.
- `get_session(id: int) -> EditorDebuggerSession` — Returns the EditorDebuggerSession with the given `id`.
- `get_sessions() -> Array` — Returns an array of EditorDebuggerSession currently available to this debugger plugin.
