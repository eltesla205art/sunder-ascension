# @GDScript


Built-in GDScript constants, functions, and annotations.

A list of utility functions and annotations accessible from any script written in GDScript. For the list of global functions and constants that can be accessed in any scripting language, see @GlobalScope.

## Methods

- `Color8(r8: int, g8: int, b8: int, a8: int = 255) -> Color` *(deprecated)* — Returns a Color constructed from red (`r8`), green (`g8`), blue (`b8`), and optionally alpha (`a8`) integer channels, each divided by `255.0` for their final value.
- `assert(condition: bool, message: String = "") -> void` — Asserts that the `condition` is `true`.
- `char(code: int) -> String` — Returns a single character (as a String of length 1) of the given Unicode code point `code`.
- `convert(what: Variant, type: Variant.Type) -> Variant` *(deprecated)* — Converts `what` to `type` in the best way possible.
- `dict_to_inst(dictionary: Dictionary) -> Object` *(deprecated)* — Converts a `dictionary` (created with `inst_to_dict`) back to an Object instance.
- `get_stack() -> Array` — Returns an array of dictionaries representing the current call stack.
- `inst_to_dict(instance: Object) -> Dictionary` *(deprecated)* — Returns the passed `instance` converted to a Dictionary.
- `is_instance_of(value: Variant, type: Variant) -> bool` — Returns `true` if `value` is an instance of `type`.
- `len(var: Variant) -> int` — Returns the length of the given Variant `var`.
- `load(path: String) -> Resource` — Returns a Resource from the filesystem located at the absolute `path`.
- `ord(char: String) -> int` — Returns an integer representing the Unicode code point of the given character `char`, which should be a string of length 1.
- `preload(path: String) -> Resource` — Returns a Resource from the filesystem located at `path`.
- `print_debug() -> void` *vararg* — Like `@GlobalScope.print`, but includes the current stack frame when running with the debugger turned on.
- `print_stack() -> void` — Prints a stack trace at the current code location.
- `range() -> Array` *vararg* — Returns an array with the given range.
- `type_exists(type: StringName) -> bool` *(deprecated)* — Returns `true` if the given Object-derived class exists in ClassDB.

## Constants

- `PI = 3.14159265358979` — Constant that represents how many times the diameter of a circle fits around its perimeter.
- `TAU = 6.28318530717959` — The circle constant, the circumference of the unit circle in radians.
- `INF = inf` — Positive floating-point infinity.
- `NAN = nan` — "Not a Number", an invalid floating-point value.

## Annotations

- `@abstract()` — Marks a class or a method as abstract.
- `@export()` — Mark the following property as exported (editable in the Inspector dock and saved to disk).
- `@export_category(name: String)` — Define a new category for the following exported properties.
- `@export_color_no_alpha()` — Export a Color, Array[Color], or PackedColorArray property without allowing its transparency (`Color.a`) to be edited.
- `@export_custom(hint: PropertyHint, hint_string: String, usage: PropertyUsageFlags = 6)` — Allows you to set a custom hint, hint string, and usage flags for the exported property.
- `@export_dir()` — Export a String, Array[String], or PackedStringArray property as a path to a directory.
- `@export_enum(names: String)` — Export an int, String, StringName, Array[int], Array[String], Array[StringName], PackedByteArray, PackedInt32Array, PackedInt64Array, or PackedStringArray property as an enumerated list of options (or an array of options).
- `@export_exp_easing(hints: String = "")` — Export a floating-point property with an easing editor widget.
- `@export_file(filter: String = "")` — Export a String, Array[String], or PackedStringArray property as a path to a file.
- `@export_file_path(filter: String = "")` — Same as `@export_file`, except the file will be stored as a raw path.
- `@export_flags(names: String)` — Export an integer property as a bit flag field.
- `@export_flags_2d_navigation()` — Export an integer property as a bit flag field for 2D navigation layers.
- `@export_flags_2d_physics()` — Export an integer property as a bit flag field for 2D physics layers.
- `@export_flags_2d_render()` — Export an integer property as a bit flag field for 2D render layers.
- `@export_flags_3d_navigation()` — Export an integer property as a bit flag field for 3D navigation layers.
- `@export_flags_3d_physics()` — Export an integer property as a bit flag field for 3D physics layers.
- `@export_flags_3d_render()` — Export an integer property as a bit flag field for 3D render layers.
- `@export_flags_avoidance()` — Export an integer property as a bit flag field for navigation avoidance layers.
- `@export_global_dir()` — Export a String, Array[String], or PackedStringArray property as an absolute path to a directory.
- `@export_global_file(filter: String = "")` — Export a String, Array[String], or PackedStringArray property as an absolute path to a file.
- `@export_group(name: String, prefix: String = "")` — Define a new group for the following exported properties.
- `@export_multiline(hint: String = "")` — Export a String, Array[String], PackedStringArray, Dictionary or Array[Dictionary] property with a large TextEdit widget instead of a LineEdit.
- `@export_node_path(type: String = "")` — Export a NodePath or Array[NodePath] property with a filter for allowed node types.
- `@export_placeholder(placeholder: String)` — Export a String, Array[String], or PackedStringArray property with a placeholder text displayed in the editor widget when no value is present.
- `@export_range(min: float, max: float, step: float = 1.0, extra_hints: String = "")` — Export an int, float, Array[int], Array[float], PackedByteArray, PackedInt32Array, PackedInt64Array, PackedFloat32Array, or PackedFloat64Array property as a range value.
- `@export_storage()` — Export a property with `PROPERTY_USAGE_STORAGE` flag.
- `@export_subgroup(name: String, prefix: String = "")` — Define a new subgroup for the following exported properties.
- `@export_tool_button(text: String, icon: String = "")` — Export a Callable property as a clickable button with the label `text`.
- `@icon(icon_path: String)` — Add a custom icon to the current script.
- `@onready()` — Mark the following property as assigned when the Node is ready.
- `@rpc(mode: String = "authority", sync: String = "call_remote", transfer_mode: String = "reliable", transfer_channel: int = 0)` — Mark the following method for remote procedure calls.
- `@static_unload()` — Make a script with static variables to not persist after all references are lost.
- `@tool()` — Mark the current script as a tool script, allowing it to be loaded and executed by the editor.
- `@warning_ignore(warning: String)` — Mark the following statement to ignore the specified `warning`.
- `@warning_ignore_restore(warning: String)` — Stops ignoring the listed warning types after `@warning_ignore_start`.
- `@warning_ignore_start(warning: String)` — Starts ignoring the listed warning types until the end of the file or the `@warning_ignore_restore` annotation with the given warning type.
