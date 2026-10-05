# ScriptBacktrace

**Inherits:** RefCounted

A captured backtrace of a specific script language.

ScriptBacktrace holds an already captured backtrace of a specific script language, such as GDScript or C#, which are captured using `Engine.capture_script_backtraces`. See `ProjectSettings.debug/settings/gdscript/always_track_call_stacks` and `ProjectSettings.debug/settings/gdscript/always_track_local_variables` for ways of controlling the contents of this class.

## Methods

- `format(indent_all: int = 0, indent_frames: int = 4) -> String` *const* — Converts the backtrace to a String, where the entire string will be indented by `indent_all` number of spaces, and the individual stack frames will be additionally indented by `indent_frames` number of spaces.
- `get_frame_count() -> int` *const* — Returns the number of stack frames in the backtrace.
- `get_frame_file(index: int) -> String` *const* — Returns the file name of the call site represented by the stack frame at the specified index.
- `get_frame_function(index: int) -> String` *const* — Returns the name of the function called at the stack frame at the specified index.
- `get_frame_line(index: int) -> int` *const* — Returns the line number of the call site represented by the stack frame at the specified index.
- `get_global_variable_count() -> int` *const* — Returns the number of global variables (e.g. autoload singletons) in the backtrace.
- `get_global_variable_name(variable_index: int) -> String` *const* — Returns the name of the global variable at the specified index.
- `get_global_variable_value(variable_index: int) -> Variant` *const* — Returns the value of the global variable at the specified index.
- `get_language_name() -> String` *const* — Returns the name of the script language that this backtrace was captured from.
- `get_local_variable_count(frame_index: int) -> int` *const* — Returns the number of local variables in the stack frame at the specified index.
- `get_local_variable_name(frame_index: int, variable_index: int) -> String` *const* — Returns the name of the local variable at the specified `variable_index` in the stack frame at the specified `frame_index`.
- `get_local_variable_value(frame_index: int, variable_index: int) -> Variant` *const* — Returns the value of the local variable at the specified `variable_index` in the stack frame at the specified `frame_index`.
- `get_member_variable_count(frame_index: int) -> int` *const* — Returns the number of member variables in the stack frame at the specified index.
- `get_member_variable_name(frame_index: int, variable_index: int) -> String` *const* — Returns the name of the member variable at the specified `variable_index` in the stack frame at the specified `frame_index`.
- `get_member_variable_value(frame_index: int, variable_index: int) -> Variant` *const* — Returns the value of the member variable at the specified `variable_index` in the stack frame at the specified `frame_index`.
- `is_empty() -> bool` *const* — Returns `true` if the backtrace has no stack frames.
