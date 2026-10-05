# @GlobalScope


Global scope constants and functions.

A list of global scope enumerated constants and built-in functions. This is all that resides in the globals, constants regarding error codes, keycodes, property hints, etc. Singletons are also documented here, since they can be accessed from anywhere. For the entries that can only be accessed from scripts written in GDScript, see @GDScript.

## Properties

- `AccessibilityServer: AccessibilityServer` — The AccessibilityServer singleton.
- `AudioServer: AudioServer` — The AudioServer singleton.
- `CameraServer: CameraServer` — The CameraServer singleton.
- `ClassDB: ClassDB` — The ClassDB singleton.
- `DisplayServer: DisplayServer` — The DisplayServer singleton.
- `EditorInterface: EditorInterface` — The EditorInterface singleton.
- `Engine: Engine` — The Engine singleton.
- `EngineDebugger: EngineDebugger` — The EngineDebugger singleton.
- `GDExtensionManager: GDExtensionManager` — The GDExtensionManager singleton.
- `GDScriptLanguageProtocol: GDScriptLanguageProtocol` — The GDScriptLanguageProtocol singleton.
- `Geometry2D: Geometry2D` — The Geometry2D singleton.
- `Geometry3D: Geometry3D` — The Geometry3D singleton.
- `IP: IP` — The IP singleton.
- `Input: Input` — The Input singleton.
- `InputMap: InputMap` — The InputMap singleton.
- `JavaClassWrapper: JavaClassWrapper` — The JavaClassWrapper singleton.
- `JavaScriptBridge: JavaScriptBridge` — The JavaScriptBridge singleton.
- `Marshalls: Marshalls` — The Marshalls singleton.
- `NativeMenu: NativeMenu` — The NativeMenu singleton.
- `NavigationMeshGenerator: NavigationMeshGenerator` — The NavigationMeshGenerator singleton.
- `NavigationServer2D: NavigationServer2D` — The NavigationServer2D singleton.
- `NavigationServer2DManager: NavigationServer2DManager` — The NavigationServer2DManager singleton.
- `NavigationServer3D: NavigationServer3D` — The NavigationServer3D singleton.
- `NavigationServer3DManager: NavigationServer3DManager` — The NavigationServer3DManager singleton.
- `OS: OS` — The OS singleton.
- `Performance: Performance` — The Performance singleton.
- `PhysicsServer2D: PhysicsServer2D` — The PhysicsServer2D singleton.
- `PhysicsServer2DManager: PhysicsServer2DManager` — The PhysicsServer2DManager singleton.
- `PhysicsServer3D: PhysicsServer3D` — The PhysicsServer3D singleton.
- `PhysicsServer3DManager: PhysicsServer3DManager` — The PhysicsServer3DManager singleton.
- `ProjectSettings: ProjectSettings` — The ProjectSettings singleton.
- `RenderingServer: RenderingServer` — The RenderingServer singleton.
- `ResourceLoader: ResourceLoader` — The ResourceLoader singleton.
- `ResourceSaver: ResourceSaver` — The ResourceSaver singleton.
- `ResourceUID: ResourceUID` — The ResourceUID singleton.
- `TextServerManager: TextServerManager` — The TextServerManager singleton.
- `TextureStreaming: TextureStreaming` — The TextureStreaming singleton.
- `ThemeDB: ThemeDB` — The ThemeDB singleton.
- `Time: Time` — The Time singleton.
- `TranslationServer: TranslationServer` — The TranslationServer singleton.
- `WorkerThreadPool: WorkerThreadPool` — The WorkerThreadPool singleton.
- `XRServer: XRServer` — The XRServer singleton.

## Methods

- `abs(x: Variant) -> Variant` — Returns the absolute value of a Variant parameter `x` (i.e. non-negative value).
- `absf(x: float) -> float` — Returns the absolute value of float parameter `x` (i.e. positive value).
- `absi(x: int) -> int` — Returns the absolute value of int parameter `x` (i.e. positive value).
- `acos(x: float) -> float` — Returns the arc cosine of `x` in radians.
- `acosh(x: float) -> float` — Returns the hyperbolic arc (also called inverse) cosine of `x`, returning a value in radians.
- `angle_difference(from: float, to: float) -> float` — Returns the difference between the two angles (in radians), in the range of `[-PI, +PI]`.
- `asin(x: float) -> float` — Returns the arc sine of `x` in radians.
- `asinh(x: float) -> float` — Returns the hyperbolic arc (also called inverse) sine of `x`, returning a value in radians.
- `atan(x: float) -> float` — Returns the arc tangent of `x` in radians.
- `atan2(y: float, x: float) -> float` — Returns the arc tangent of `y/x` in radians.
- `atanh(x: float) -> float` — Returns the hyperbolic arc (also called inverse) tangent of `x`, returning a value in radians.
- `bezier_derivative(start: float, control_1: float, control_2: float, end: float, t: float) -> float` — Returns the derivative at the given `t` on a one-dimensional Bézier curve defined by the given `control_1`, `control_2`, and `end` points.
- `bezier_interpolate(start: float, control_1: float, control_2: float, end: float, t: float) -> float` — Returns the point at the given `t` on a one-dimensional Bézier curve defined by the given `control_1`, `control_2`, and `end` points.
- `bytes_to_var(bytes: PackedByteArray) -> Variant` — Decodes a byte array back to a Variant value, without decoding objects.
- `bytes_to_var_with_objects(bytes: PackedByteArray) -> Variant` — Decodes a byte array back to a Variant value.
- `ceil(x: Variant) -> Variant` — Rounds `x` upward (towards positive infinity), returning the smallest whole number that is not less than `x`.
- `ceilf(x: float) -> float` — Rounds `x` upward (towards positive infinity), returning the smallest whole number that is not less than `x`.
- `ceili(x: float) -> int` — Rounds `x` upward (towards positive infinity), returning the smallest whole number that is not less than `x`.
- `clamp(value: Variant, min: Variant, max: Variant) -> Variant` — Clamps the `value`, returning a Variant not less than `min` and not more than `max`.
- `clampf(value: float, min: float, max: float) -> float` — Clamps the `value`, returning a float not less than `min` and not more than `max`.
- `clampi(value: int, min: int, max: int) -> int` — Clamps the `value`, returning an int not less than `min` and not more than `max`.
- `cos(angle_rad: float) -> float` — Returns the cosine of angle `angle_rad` in radians.
- `cosh(x: float) -> float` — Returns the hyperbolic cosine of `x` in radians.
- `cubic_interpolate(from: float, to: float, pre: float, post: float, weight: float) -> float` — Cubic interpolates between two values by the factor defined in `weight` with `pre` and `post` values.
- `cubic_interpolate_angle(from: float, to: float, pre: float, post: float, weight: float) -> float` — Cubic interpolates between two rotation values with shortest path by the factor defined in `weight` with `pre` and `post` values.
- `cubic_interpolate_angle_in_time(from: float, to: float, pre: float, post: float, weight: float, to_t: float, pre_t: float, post_t: float) -> float` — Cubic interpolates between two rotation values with shortest path by the factor defined in `weight` with `pre` and `post` values.
- `cubic_interpolate_in_time(from: float, to: float, pre: float, post: float, weight: float, to_t: float, pre_t: float, post_t: float) -> float` — Cubic interpolates between two values by the factor defined in `weight` with `pre` and `post` values.
- `db_to_linear(db: float) -> float` — Converts from decibels to linear energy (audio).
- `deg_to_rad(deg: float) -> float` — Converts an angle expressed in degrees to radians.
- `ease(x: float, curve: float) -> float` — Returns an "eased" value of `x` based on an easing function defined with `curve`.
- `error_string(error: int) -> String` — Returns a human-readable name for the given `Error` code.
- `exp(x: float) -> float` — The natural exponential function.
- `floor(x: Variant) -> Variant` — Rounds `x` downward (towards negative infinity), returning the largest whole number that is not more than `x`.
- `floorf(x: float) -> float` — Rounds `x` downward (towards negative infinity), returning the largest whole number that is not more than `x`.
- `floori(x: float) -> int` — Rounds `x` downward (towards negative infinity), returning the largest whole number that is not more than `x`.
- `fmod(x: float, y: float) -> float` — Returns the floating-point remainder of `x` divided by `y`, keeping the sign of `x`.
- `fposmod(x: float, y: float) -> float` — Returns the floating-point modulus of `x` divided by `y`, wrapping equally in positive and negative.
- `hash(variable: Variant) -> int` — Returns the integer hash of the passed `variable`.
- `instance_from_id(instance_id: int) -> Object` — Returns the Object that corresponds to `instance_id`.
- `inverse_lerp(from: float, to: float, weight: float) -> float` — Returns an interpolation or extrapolation factor considering the range specified in `from` and `to`, and the interpolated value specified in `weight`.
- `is_equal_approx(a: float, b: float) -> bool` — Returns `true` if `a` and `b` are approximately equal to each other.
- `is_finite(x: float) -> bool` — Returns whether `x` is a finite value, i.e. it is not `@GDScript.NAN`, positive infinity, or negative infinity.
- `is_inf(x: float) -> bool` — Returns `true` if `x` is either positive infinity or negative infinity.
- `is_instance_id_valid(id: int) -> bool` — Returns `true` if the Object that corresponds to `id` is a valid object (e.g. has not been deleted from memory).
- `is_instance_valid(instance: Variant) -> bool` — Returns `true` if `instance` is a valid Object (e.g. has not been deleted from memory).
- `is_nan(x: float) -> bool` — Returns `true` if `x` is a NaN ("Not a Number" or invalid) value.
- `is_same(a: Variant, b: Variant) -> bool` — Returns `true`, for value types, if `a` and `b` share the same value.
- `is_zero_approx(x: float) -> bool` — Returns `true` if `x` is zero or almost zero.
- `lerp(from: Variant, to: Variant, weight: Variant) -> Variant` — Linearly interpolates between two values by the factor defined in `weight`.
- `lerp_angle(from: float, to: float, weight: float) -> float` — Linearly interpolates between two angles (in radians) by a `weight` value between 0.0 and 1.0.
- `lerpf(from: float, to: float, weight: float) -> float` — Linearly interpolates between two values by the factor defined in `weight`.
- `linear_to_db(lin: float) -> float` — Converts from linear energy to decibels (audio).
- `log(x: float) -> float` — Returns the natural logarithm of `x` (base e, with e being approximately 2.71828).
- `max() -> Variant` *vararg* — Returns the maximum of the given numeric values.
- `maxf(a: float, b: float) -> float` — Returns the maximum of two float values.
- `maxi(a: int, b: int) -> int` — Returns the maximum of two int values.
- `min() -> Variant` *vararg* — Returns the minimum of the given numeric values.
- `minf(a: float, b: float) -> float` — Returns the minimum of two float values.
- `mini(a: int, b: int) -> int` — Returns the minimum of two int values.
- `move_toward(from: float, to: float, delta: float) -> float` — Moves `from` toward `to` by the `delta` amount.
- `nearest_po2(value: int) -> int` — Returns the smallest integer power of 2 that is greater than or equal to `value`.
- `pingpong(value: float, length: float) -> float` — Wraps `value` between `0` and the `length`.
- `posmod(x: int, y: int) -> int` — Returns the integer modulus of `x` divided by `y` that wraps equally in positive and negative.
- `pow(base: float, exp: float) -> float` — Returns the result of `base` raised to the power of `exp`.
- `print() -> void` *vararg* — Converts one or more arguments of any type to string in the best way possible and prints them to the console.
- `print_rich() -> void` *vararg* — Converts one or more arguments of any type to string in the best way possible and prints them to the console.
- `print_verbose() -> void` *vararg* — If verbose mode is enabled (`OS.is_stdout_verbose` returning `true`), converts one or more arguments of any type to string in the best way possible and prints them to the console.
- `printerr() -> void` *vararg* — Prints one or more arguments to strings in the best way possible to standard error line.
- `printraw() -> void` *vararg* — Prints one or more arguments to strings in the best way possible to the OS terminal.
- `prints() -> void` *vararg* — Prints one or more arguments to the console with a space between each argument.
- `printt() -> void` *vararg* — Prints one or more arguments to the console with a tab between each argument.
- `push_error() -> void` *vararg* — Pushes an error message to Godot's built-in debugger and to the OS terminal.
- `push_warning() -> void` *vararg* — Pushes a warning message to Godot's built-in debugger and to the OS terminal.
- `rad_to_deg(rad: float) -> float` — Converts an angle expressed in radians to degrees.
- `rand_from_seed(seed: int) -> PackedInt64Array` — Given a `seed`, returns a PackedInt64Array of size `2`, where its first element is the randomized int value, and the second element is the same as `seed`.
- `randf() -> float` — Returns a random floating-point value between `0.0` and `1.0` (inclusive).
- `randf_range(from: float, to: float) -> float` — Returns a random floating-point value between `from` and `to` (inclusive).
- `randfn(mean: float, deviation: float) -> float` — Returns a normally-distributed, pseudo-random floating-point value from the specified `mean` and a standard `deviation`.
- `randi() -> int` — Returns a random unsigned 32-bit integer.
- `randi_range(from: int, to: int) -> int` — Returns a random signed 32-bit integer between `from` and `to` (inclusive).
- `randomize() -> void` — Randomizes the seed (or the internal state) of the random number generator.
- `remap(value: float, istart: float, istop: float, ostart: float, ostop: float) -> float` — Maps a `value` from range `[istart, istop]` to `[ostart, ostop]`.
- `rid_allocate_id() -> int` — Allocates a unique ID which can be used by the implementation to construct an RID.
- `rid_from_int64(base: int) -> RID` — Creates an RID from a `base`.
- `rotate_toward(from: float, to: float, delta: float) -> float` — Rotates `from` toward `to` by the `delta` amount.
- `round(x: Variant) -> Variant` — Rounds `x` to the nearest whole number, with halfway cases rounded away from 0.
- `roundf(x: float) -> float` — Rounds `x` to the nearest whole number, with halfway cases rounded away from 0.
- `roundi(x: float) -> int` — Rounds `x` to the nearest whole number, with halfway cases rounded away from 0.
- `seed(base: int) -> void` — Sets the seed for the random number generator to `base`.
- `sign(x: Variant) -> Variant` — Returns the same type of Variant as `x`, with `-1` for negative values, `1` for positive values, and `0` for zeros.
- `signf(x: float) -> float` — Returns `-1.0` if `x` is negative, `1.0` if `x` is positive, and `0.0` if `x` is zero.
- `signi(x: int) -> int` — Returns `-1` if `x` is negative, `1` if `x` is positive, and `0` if `x` is zero.
- `sin(angle_rad: float) -> float` — Returns the sine of angle `angle_rad` in radians.
- `sinh(x: float) -> float` — Returns the hyperbolic sine of `x`.
- `smoothstep(from: float, to: float, x: float) -> float` — Returns a smooth cubic Hermite interpolation between `0` and `1`.
- `snapped(x: Variant, step: Variant) -> Variant` — Returns the multiple of `step` that is the closest to `x`.
- `snappedf(x: float, step: float) -> float` — Returns the multiple of `step` that is the closest to `x`.
- `snappedi(x: float, step: int) -> int` — Returns the multiple of `step` that is the closest to `x`.
- `sqrt(x: float) -> float` — Returns the square root of `x`, where `x` is a non-negative number.
- `step_decimals(x: float) -> int` — Returns the position of the first non-zero digit, after the decimal point.
- `str() -> String` *vararg* — Converts one or more arguments of any Variant type to a String in the best way possible.
- `str_to_var(string: String) -> Variant` — Converts a formatted `string` that was returned by `var_to_str` to the original Variant.
- `tan(angle_rad: float) -> float` — Returns the tangent of angle `angle_rad` in radians.
- `tanh(x: float) -> float` — Returns the hyperbolic tangent of `x`.
- `type_convert(variant: Variant, type: int) -> Variant` — Converts the given `variant` to the given `type`, using the `Variant.Type` values.
- `type_string(type: int) -> String` — Returns a human-readable name of the given `type`, using the `Variant.Type` values.
- `typeof(variable: Variant) -> int` — Returns the internal type of the given `variable`, using the `Variant.Type` values.
- `var_to_bytes(variable: Variant) -> PackedByteArray` — Encodes a Variant value to a byte array, without encoding objects.
- `var_to_bytes_with_objects(variable: Variant) -> PackedByteArray` — Encodes a Variant value to a byte array.
- `var_to_str(variable: Variant) -> String` — Converts a Variant `variable` to a formatted String that can then be parsed using `str_to_var`.
- `weakref(obj: Variant) -> Variant` — Returns a WeakRef instance holding a weak reference to `obj`.
- `wrap(value: Variant, min: Variant, max: Variant) -> Variant` — Wraps the Variant `value` between `min` and `max`.
- `wrapf(value: float, min: float, max: float) -> float` — Wraps the float `value` between `min` and `max`.
- `wrapi(value: int, min: int, max: int) -> int` — Wraps the integer `value` between `min` and `max`.

## Enum Side

- `SIDE_LEFT = 0` — Left side, usually used for Control or StyleBox-derived classes.
- `SIDE_TOP = 1` — Top side, usually used for Control or StyleBox-derived classes.
- `SIDE_RIGHT = 2` — Right side, usually used for Control or StyleBox-derived classes.
- `SIDE_BOTTOM = 3` — Bottom side, usually used for Control or StyleBox-derived classes.

## Enum Corner

- `CORNER_TOP_LEFT = 0` — Top-left corner.
- `CORNER_TOP_RIGHT = 1` — Top-right corner.
- `CORNER_BOTTOM_RIGHT = 2` — Bottom-right corner.
- `CORNER_BOTTOM_LEFT = 3` — Bottom-left corner.

## Enum Orientation

- `VERTICAL = 1` — General vertical alignment, usually used for Separator, ScrollBar, Slider, etc.
- `HORIZONTAL = 0` — General horizontal alignment, usually used for Separator, ScrollBar, Slider, etc.

## Enum ClockDirection

- `CLOCKWISE = 0` — Clockwise rotation.
- `COUNTERCLOCKWISE = 1` — Counter-clockwise rotation.

## Enum HorizontalAlignment

- `HORIZONTAL_ALIGNMENT_LEFT = 0` — Horizontal left alignment, usually for text-derived classes.
- `HORIZONTAL_ALIGNMENT_CENTER = 1` — Horizontal center alignment, usually for text-derived classes.
- `HORIZONTAL_ALIGNMENT_RIGHT = 2` — Horizontal right alignment, usually for text-derived classes.
- `HORIZONTAL_ALIGNMENT_FILL = 3` — Expand row to fit width, usually for text-derived classes.

## Enum VerticalAlignment

- `VERTICAL_ALIGNMENT_TOP = 0` — Vertical top alignment, usually for text-derived classes.
- `VERTICAL_ALIGNMENT_CENTER = 1` — Vertical center alignment, usually for text-derived classes.
- `VERTICAL_ALIGNMENT_BOTTOM = 2` — Vertical bottom alignment, usually for text-derived classes.
- `VERTICAL_ALIGNMENT_FILL = 3` — Expand rows to fit height, usually for text-derived classes.

## Enum InlineAlignment

- `INLINE_ALIGNMENT_TOP_TO = 0` — Aligns the top of the inline object (e.g. image, table) to the position of the text specified by `INLINE_ALIGNMENT_TO_*` constant.
- `INLINE_ALIGNMENT_CENTER_TO = 1` — Aligns the center of the inline object (e.g. image, table) to the position of the text specified by `INLINE_ALIGNMENT_TO_*` constant.
- `INLINE_ALIGNMENT_BASELINE_TO = 3` — Aligns the baseline (user defined) of the inline object (e.g. image, table) to the position of the text specified by `INLINE_ALIGNMENT_TO_*` constant.
- `INLINE_ALIGNMENT_BOTTOM_TO = 2` — Aligns the bottom of the inline object (e.g. image, table) to the position of the text specified by `INLINE_ALIGNMENT_TO_*` constant.
- `INLINE_ALIGNMENT_TO_TOP = 0` — Aligns the position of the inline object (e.g. image, table) specified by `INLINE_ALIGNMENT_*_TO` constant to the top of the text.
- `INLINE_ALIGNMENT_TO_CENTER = 4` — Aligns the position of the inline object (e.g. image, table) specified by `INLINE_ALIGNMENT_*_TO` constant to the center of the text.
- `INLINE_ALIGNMENT_TO_BASELINE = 8` — Aligns the position of the inline object (e.g. image, table) specified by `INLINE_ALIGNMENT_*_TO` constant to the baseline of the text.
- `INLINE_ALIGNMENT_TO_BOTTOM = 12` — Aligns inline object (e.g. image, table) to the bottom of the text.
- `INLINE_ALIGNMENT_TOP = 0` — Aligns top of the inline object (e.g. image, table) to the top of the text.
- `INLINE_ALIGNMENT_CENTER = 5` — Aligns center of the inline object (e.g. image, table) to the center of the text.
- `INLINE_ALIGNMENT_BOTTOM = 14` — Aligns bottom of the inline object (e.g. image, table) to the bottom of the text.
- `INLINE_ALIGNMENT_IMAGE_MASK = 3` — A bit mask for `INLINE_ALIGNMENT_*_TO` alignment constants.
- `INLINE_ALIGNMENT_TEXT_MASK = 12` — A bit mask for `INLINE_ALIGNMENT_TO_*` alignment constants.

## Enum EulerOrder

- `EULER_ORDER_XYZ = 0` — Specifies that Euler angles should be in intrinsic XYZ order.
- `EULER_ORDER_XZY = 1` — Specifies that Euler angles should be in intrinsic XZY order.
- `EULER_ORDER_YXZ = 2` — Specifies that Euler angles should be in intrinsic YXZ order.
- `EULER_ORDER_YZX = 3` — Specifies that Euler angles should be in intrinsic YZX order.
- `EULER_ORDER_ZXY = 4` — Specifies that Euler angles should be in intrinsic ZXY order.
- `EULER_ORDER_ZYX = 5` — Specifies that Euler angles should be in intrinsic ZYX order.

## Enum Key

- `KEY_NONE = 0` — Enum value which doesn't correspond to any key.
- `KEY_SPECIAL = 4194304` — Keycodes with this bit applied are non-printable.
- `KEY_ESCAPE = 4194305` — Escape key.
- `KEY_TAB = 4194306` — Tab key.
- `KEY_BACKTAB = 4194307` — Shift + Tab key.
- `KEY_BACKSPACE = 4194308` — Backspace key.
- `KEY_ENTER = 4194309` — Return key (on the main keyboard).
- `KEY_KP_ENTER = 4194310` — Enter key on the numeric keypad.
- `KEY_INSERT = 4194311` — Insert key.
- `KEY_DELETE = 4194312` — Delete key.
- `KEY_PAUSE = 4194313` — Pause key.
- `KEY_PRINT = 4194314` — Print Screen key.
- `KEY_SYSREQ = 4194315` — System Request key.
- `KEY_CLEAR = 4194316` — Clear key.
- `KEY_HOME = 4194317` — Home key.
- `KEY_END = 4194318` — End key.
- `KEY_LEFT = 4194319` — Left arrow key.
- `KEY_UP = 4194320` — Up arrow key.
- `KEY_RIGHT = 4194321` — Right arrow key.
- `KEY_DOWN = 4194322` — Down arrow key.
- `KEY_PAGEUP = 4194323` — Page Up key.
- `KEY_PAGEDOWN = 4194324` — Page Down key.
- `KEY_SHIFT = 4194325` — Shift key.
- `KEY_CTRL = 4194326` — Control key.
- `KEY_META = 4194327` — Meta key.
- `KEY_ALT = 4194328` — Alt key.
- `KEY_CAPSLOCK = 4194329` — Caps Lock key.
- `KEY_NUMLOCK = 4194330` — Num Lock key.
- `KEY_SCROLLLOCK = 4194331` — Scroll Lock key.
- `KEY_F1 = 4194332` — F1 key.
- `KEY_F2 = 4194333` — F2 key.
- `KEY_F3 = 4194334` — F3 key.
- `KEY_F4 = 4194335` — F4 key.
- `KEY_F5 = 4194336` — F5 key.
- `KEY_F6 = 4194337` — F6 key.
- `KEY_F7 = 4194338` — F7 key.
- `KEY_F8 = 4194339` — F8 key.
- `KEY_F9 = 4194340` — F9 key.
- `KEY_F10 = 4194341` — F10 key.
- `KEY_F11 = 4194342` — F11 key.
- `KEY_F12 = 4194343` — F12 key.
- `KEY_F13 = 4194344` — F13 key.
- `KEY_F14 = 4194345` — F14 key.
- `KEY_F15 = 4194346` — F15 key.
- `KEY_F16 = 4194347` — F16 key.
- `KEY_F17 = 4194348` — F17 key.
- `KEY_F18 = 4194349` — F18 key.
- `KEY_F19 = 4194350` — F19 key.
- `KEY_F20 = 4194351` — F20 key.
- `KEY_F21 = 4194352` — F21 key.
- `KEY_F22 = 4194353` — F22 key.
- `KEY_F23 = 4194354` — F23 key.
- `KEY_F24 = 4194355` — F24 key.
- `KEY_F25 = 4194356` — F25 key.
- `KEY_F26 = 4194357` — F26 key.
- `KEY_F27 = 4194358` — F27 key.
- `KEY_F28 = 4194359` — F28 key.
- `KEY_F29 = 4194360` — F29 key.
- `KEY_F30 = 4194361` — F30 key.
- `KEY_F31 = 4194362` — F31 key.
- `KEY_F32 = 4194363` — F32 key.
- `KEY_F33 = 4194364` — F33 key.
- `KEY_F34 = 4194365` — F34 key.
- `KEY_F35 = 4194366` — F35 key.
- `KEY_KP_MULTIPLY = 4194433` — Multiply (*) key on the numeric keypad.
- `KEY_KP_DIVIDE = 4194434` — Divide (/) key on the numeric keypad.
- `KEY_KP_SUBTRACT = 4194435` — Subtract (-) key on the numeric keypad.
- `KEY_KP_PERIOD = 4194436` — Period (.) key on the numeric keypad.
- `KEY_KP_ADD = 4194437` — Add (+) key on the numeric keypad.
- `KEY_KP_0 = 4194438` — Number 0 on the numeric keypad.
- `KEY_KP_1 = 4194439` — Number 1 on the numeric keypad.
- `KEY_KP_2 = 4194440` — Number 2 on the numeric keypad.
- `KEY_KP_3 = 4194441` — Number 3 on the numeric keypad.
- `KEY_KP_4 = 4194442` — Number 4 on the numeric keypad.
- `KEY_KP_5 = 4194443` — Number 5 on the numeric keypad.
- `KEY_KP_6 = 4194444` — Number 6 on the numeric keypad.
- `KEY_KP_7 = 4194445` — Number 7 on the numeric keypad.
- `KEY_KP_8 = 4194446` — Number 8 on the numeric keypad.
- `KEY_KP_9 = 4194447` — Number 9 on the numeric keypad.
- `KEY_MENU = 4194370` — Context menu key.
- `KEY_HYPER = 4194371` — Hyper key. (On Linux/X11 only).
- `KEY_HELP = 4194373` — Help key.
- `KEY_BACK = 4194376` — Back key.
- `KEY_FORWARD = 4194377` — Forward key.
- `KEY_STOP = 4194378` — Media stop key.
- `KEY_REFRESH = 4194379` — Refresh key.
- `KEY_VOLUMEDOWN = 4194380` — Volume down key.
- `KEY_VOLUMEMUTE = 4194381` — Mute volume key.
- `KEY_VOLUMEUP = 4194382` — Volume up key.
- `KEY_MEDIAPLAY = 4194388` — Media play key.
- `KEY_MEDIASTOP = 4194389` — Media stop key.
- `KEY_MEDIAPREVIOUS = 4194390` — Previous song key.
- `KEY_MEDIANEXT = 4194391` — Next song key.
- `KEY_MEDIARECORD = 4194392` — Media record key.
- `KEY_HOMEPAGE = 4194393` — Home page key.
- `KEY_FAVORITES = 4194394` — Favorites key.
- `KEY_SEARCH = 4194395` — Search key.
- `KEY_STANDBY = 4194396` — Standby key.
- `KEY_OPENURL = 4194397` — Open URL / Launch Browser key.
- `KEY_LAUNCHMAIL = 4194398` — Launch Mail key.
- `KEY_LAUNCHMEDIA = 4194399` — Launch Media key.
- `KEY_LAUNCH0 = 4194400` — Launch Shortcut 0 key.
- `KEY_LAUNCH1 = 4194401` — Launch Shortcut 1 key.
- `KEY_LAUNCH2 = 4194402` — Launch Shortcut 2 key.
- `KEY_LAUNCH3 = 4194403` — Launch Shortcut 3 key.
- `KEY_LAUNCH4 = 4194404` — Launch Shortcut 4 key.
- `KEY_LAUNCH5 = 4194405` — Launch Shortcut 5 key.
- `KEY_LAUNCH6 = 4194406` — Launch Shortcut 6 key.
- `KEY_LAUNCH7 = 4194407` — Launch Shortcut 7 key.
- `KEY_LAUNCH8 = 4194408` — Launch Shortcut 8 key.
- `KEY_LAUNCH9 = 4194409` — Launch Shortcut 9 key.
- `KEY_LAUNCHA = 4194410` — Launch Shortcut A key.
- `KEY_LAUNCHB = 4194411` — Launch Shortcut B key.
- `KEY_LAUNCHC = 4194412` — Launch Shortcut C key.
- `KEY_LAUNCHD = 4194413` — Launch Shortcut D key.
- `KEY_LAUNCHE = 4194414` — Launch Shortcut E key.
- `KEY_LAUNCHF = 4194415` — Launch Shortcut F key.
- `KEY_GLOBE = 4194416` — "Globe" key on Mac / iPad keyboard.
- `KEY_KEYBOARD = 4194417` — "On-screen keyboard" key on iPad keyboard.
- `KEY_JIS_EISU = 4194418` — 英数 key on Mac keyboard.
- `KEY_JIS_KANA = 4194419` — かな key on Mac keyboard.
- `KEY_UNKNOWN = 8388607` — Unknown key.
- `KEY_SPACE = 32` — Space key.
- `KEY_EXCLAM = 33` — Exclamation mark (`!`) key.
- `KEY_QUOTEDBL = 34` — Double quotation mark (`"`) key.
- `KEY_NUMBERSIGN = 35` — Number sign or hash (`#`) key.
- `KEY_DOLLAR = 36` — Dollar sign (`$`) key.
- `KEY_PERCENT = 37` — Percent sign (`%`) key.
- `KEY_AMPERSAND = 38` — Ampersand (`&`) key.
- `KEY_APOSTROPHE = 39` — Apostrophe (`'`) key.
- `KEY_PARENLEFT = 40` — Left parenthesis (`(`) key.
- `KEY_PARENRIGHT = 41` — Right parenthesis (`)`) key.
- `KEY_ASTERISK = 42` — Asterisk (`*`) key.
- `KEY_PLUS = 43` — Plus (`+`) key.
- `KEY_COMMA = 44` — Comma (`,`) key.
- `KEY_MINUS = 45` — Minus (`-`) key.
- `KEY_PERIOD = 46` — Period (`.`) key.
- `KEY_SLASH = 47` — Slash (`/`) key.
- `KEY_0 = 48` — Number 0 key.
- `KEY_1 = 49` — Number 1 key.
- `KEY_2 = 50` — Number 2 key.
- `KEY_3 = 51` — Number 3 key.
- `KEY_4 = 52` — Number 4 key.
- `KEY_5 = 53` — Number 5 key.
- `KEY_6 = 54` — Number 6 key.
- `KEY_7 = 55` — Number 7 key.
- `KEY_8 = 56` — Number 8 key.
- `KEY_9 = 57` — Number 9 key.
- `KEY_COLON = 58` — Colon (`:`) key.
- `KEY_SEMICOLON = 59` — Semicolon (`;`) key.
- `KEY_LESS = 60` — Less-than sign (`<`) key.
- `KEY_EQUAL = 61` — Equal sign (`=`) key.
- `KEY_GREATER = 62` — Greater-than sign (`>`) key.
- `KEY_QUESTION = 63` — Question mark (`?`) key.
- `KEY_AT = 64` — At sign (`@`) key.
- `KEY_A = 65` — A key.
- `KEY_B = 66` — B key.
- `KEY_C = 67` — C key.
- `KEY_D = 68` — D key.
- `KEY_E = 69` — E key.
- `KEY_F = 70` — F key.
- `KEY_G = 71` — G key.
- `KEY_H = 72` — H key.
- `KEY_I = 73` — I key.
- `KEY_J = 74` — J key.
- `KEY_K = 75` — K key.
- `KEY_L = 76` — L key.
- `KEY_M = 77` — M key.
- `KEY_N = 78` — N key.
- `KEY_O = 79` — O key.
- `KEY_P = 80` — P key.
- `KEY_Q = 81` — Q key.
- `KEY_R = 82` — R key.
- `KEY_S = 83` — S key.
- `KEY_T = 84` — T key.
- `KEY_U = 85` — U key.
- `KEY_V = 86` — V key.
- `KEY_W = 87` — W key.
- `KEY_X = 88` — X key.
- `KEY_Y = 89` — Y key.
- `KEY_Z = 90` — Z key.
- `KEY_BRACKETLEFT = 91` — Left bracket (`[`) key.
- `KEY_BACKSLASH = 92` — Backslash (`\`) key.
- `KEY_BRACKETRIGHT = 93` — Right bracket (`]`) key.
- `KEY_ASCIICIRCUM = 94` — Caret (`^`) key.
- `KEY_UNDERSCORE = 95` — Underscore (`_`) key.
- `KEY_QUOTELEFT = 96` — Backtick (```) key.
- `KEY_BRACELEFT = 123` — Left brace (`{`) key.
- `KEY_BAR = 124` — Vertical bar or pipe (`|`) key.
- `KEY_BRACERIGHT = 125` — Right brace (`}`) key.
- `KEY_ASCIITILDE = 126` — Tilde (`~`) key.
- `KEY_YEN = 165` — Yen symbol (`¥`) key.
- `KEY_SECTION = 167` — Section sign (`§`) key.

## Enum KeyModifierMask

- `KEY_CODE_MASK = 8388607` — Bit mask with all bits enabled except for modifier keys.
- `KEY_MODIFIER_MASK = 2130706432` — Bit mask with all modifier bits enabled.
- `KEY_MASK_CMD_OR_CTRL = 16777216` — Automatically remapped to `KEY_META` on macOS and `KEY_CTRL` on other platforms, this mask is never set in the actual events, and should be used for key mapping only.
- `KEY_MASK_SHIFT = 33554432` — Shift key mask.
- `KEY_MASK_ALT = 67108864` — Alt or Option (on macOS) key mask.
- `KEY_MASK_META = 134217728` — Command (on macOS) or Meta/Windows key mask.
- `KEY_MASK_CTRL = 268435456` — Control key mask.
- `KEY_MASK_KPAD = 536870912` — Keypad key mask.
- `KEY_MASK_GROUP_SWITCH = 1073741824` — Group Switch key mask.

## Enum KeyLocation

- `KEY_LOCATION_UNSPECIFIED = 0` — Used for keys which only appear once, or when a comparison doesn't need to differentiate the `LEFT` and `RIGHT` versions.
- `KEY_LOCATION_LEFT = 1` — A key which is to the left of its twin.
- `KEY_LOCATION_RIGHT = 2` — A key which is to the right of its twin.

## Enum MouseButton

- `MOUSE_BUTTON_NONE = 0` — Enum value which doesn't correspond to any mouse button.
- `MOUSE_BUTTON_LEFT = 1` — Primary mouse button, usually assigned to the left button.
- `MOUSE_BUTTON_RIGHT = 2` — Secondary mouse button, usually assigned to the right button.
- `MOUSE_BUTTON_MIDDLE = 3` — Middle mouse button.
- `MOUSE_BUTTON_WHEEL_UP = 4` — Mouse wheel scrolling up.
- `MOUSE_BUTTON_WHEEL_DOWN = 5` — Mouse wheel scrolling down.
- `MOUSE_BUTTON_WHEEL_LEFT = 6` — Mouse wheel left button (only present on some mice).
- `MOUSE_BUTTON_WHEEL_RIGHT = 7` — Mouse wheel right button (only present on some mice).
- `MOUSE_BUTTON_XBUTTON1 = 8` — Extra mouse button 1.
- `MOUSE_BUTTON_XBUTTON2 = 9` — Extra mouse button 2.

## Enum MouseButtonMask

- `MOUSE_BUTTON_MASK_LEFT = 1` — Primary mouse button mask, usually for the left button.
- `MOUSE_BUTTON_MASK_RIGHT = 2` — Secondary mouse button mask, usually for the right button.
- `MOUSE_BUTTON_MASK_MIDDLE = 4` — Middle mouse button mask.
- `MOUSE_BUTTON_MASK_MB_XBUTTON1 = 128` — Extra mouse button 1 mask.
- `MOUSE_BUTTON_MASK_MB_XBUTTON2 = 256` — Extra mouse button 2 mask.

## Enum JoyButton

- `JOY_BUTTON_INVALID = -1` — An invalid game controller button.
- `JOY_BUTTON_A = 0` — Game controller SDL button A.
- `JOY_BUTTON_B = 1` — Game controller SDL button B.
- `JOY_BUTTON_X = 2` — Game controller SDL button X.
- `JOY_BUTTON_Y = 3` — Game controller SDL button Y.
- `JOY_BUTTON_BACK = 4` — Game controller SDL back button.
- `JOY_BUTTON_GUIDE = 5` — Game controller SDL guide button.
- `JOY_BUTTON_START = 6` — Game controller SDL start button.
- `JOY_BUTTON_LEFT_STICK = 7` — Game controller SDL left stick button.
- `JOY_BUTTON_RIGHT_STICK = 8` — Game controller SDL right stick button.
- `JOY_BUTTON_LEFT_SHOULDER = 9` — Game controller SDL left shoulder button.
- `JOY_BUTTON_RIGHT_SHOULDER = 10` — Game controller SDL right shoulder button.
- `JOY_BUTTON_DPAD_UP = 11` — Game controller D-pad up button.
- `JOY_BUTTON_DPAD_DOWN = 12` — Game controller D-pad down button.
- `JOY_BUTTON_DPAD_LEFT = 13` — Game controller D-pad left button.
- `JOY_BUTTON_DPAD_RIGHT = 14` — Game controller D-pad right button.
- `JOY_BUTTON_MISC1 = 15` — Game controller SDL miscellaneous button.
- `JOY_BUTTON_PADDLE1 = 16` — Game controller SDL paddle 1 button.
- `JOY_BUTTON_PADDLE2 = 17` — Game controller SDL paddle 2 button.
- `JOY_BUTTON_PADDLE3 = 18` — Game controller SDL paddle 3 button.
- `JOY_BUTTON_PADDLE4 = 19` — Game controller SDL paddle 4 button.
- `JOY_BUTTON_TOUCHPAD = 20` — Game controller SDL touchpad button.
- `JOY_BUTTON_MISC2 = 21` — Game controller SDL miscellaneous button.
- `JOY_BUTTON_MISC3 = 22` — Game controller SDL miscellaneous button.
- `JOY_BUTTON_MISC4 = 23` — Game controller SDL miscellaneous button.
- `JOY_BUTTON_MISC5 = 24` — Game controller SDL miscellaneous button.
- `JOY_BUTTON_MISC6 = 25` — Game controller SDL miscellaneous button.
- `JOY_BUTTON_SDL_MAX = 26` — The number of SDL game controller buttons.
- `JOY_BUTTON_MAX = 128` — The maximum number of game controller buttons supported by the engine.

## Enum JoyAxis

- `JOY_AXIS_INVALID = -1` — An invalid game controller axis.
- `JOY_AXIS_LEFT_X = 0` — Game controller left joystick x-axis.
- `JOY_AXIS_LEFT_Y = 1` — Game controller left joystick y-axis.
- `JOY_AXIS_RIGHT_X = 2` — Game controller right joystick x-axis.
- `JOY_AXIS_RIGHT_Y = 3` — Game controller right joystick y-axis.
- `JOY_AXIS_TRIGGER_LEFT = 4` — Game controller left trigger axis.
- `JOY_AXIS_TRIGGER_RIGHT = 5` — Game controller right trigger axis.
- `JOY_AXIS_SDL_MAX = 6` — The number of SDL game controller axes.
- `JOY_AXIS_MAX = 10` — The maximum number of game controller axes: OpenVR supports up to 5 Joysticks making a total of 10 axes.

## Enum MIDIMessage

- `MIDI_MESSAGE_NONE = 0` — Does not correspond to any MIDI message.
- `MIDI_MESSAGE_NOTE_OFF = 8` — MIDI message sent when a note is released.
- `MIDI_MESSAGE_NOTE_ON = 9` — MIDI message sent when a note is pressed.
- `MIDI_MESSAGE_AFTERTOUCH = 10` — MIDI message sent to indicate a change in pressure while a note is being pressed down, also called aftertouch.
- `MIDI_MESSAGE_CONTROL_CHANGE = 11` — MIDI message sent when a controller value changes.
- `MIDI_MESSAGE_PROGRAM_CHANGE = 12` — MIDI message sent when the MIDI device changes its current instrument (also called program or preset).
- `MIDI_MESSAGE_CHANNEL_PRESSURE = 13` — MIDI message sent to indicate a change in pressure for the whole channel.
- `MIDI_MESSAGE_PITCH_BEND = 14` — MIDI message sent when the value of the pitch bender changes, usually a wheel on the MIDI device.
- `MIDI_MESSAGE_SYSTEM_EXCLUSIVE = 240` — MIDI system exclusive (SysEx) message.
- `MIDI_MESSAGE_QUARTER_FRAME = 241` — MIDI message sent every quarter frame to keep connected MIDI devices synchronized.
- `MIDI_MESSAGE_SONG_POSITION_POINTER = 242` — MIDI message sent to jump onto a new position in the current sequence or song.
- `MIDI_MESSAGE_SONG_SELECT = 243` — MIDI message sent to select a sequence or song to play.
- `MIDI_MESSAGE_TUNE_REQUEST = 246` — MIDI message sent to request a tuning calibration.
- `MIDI_MESSAGE_TIMING_CLOCK = 248` — MIDI message sent 24 times after `MIDI_MESSAGE_QUARTER_FRAME`, to keep connected MIDI devices synchronized.
- `MIDI_MESSAGE_START = 250` — MIDI message sent to start the current sequence or song from the beginning.
- `MIDI_MESSAGE_CONTINUE = 251` — MIDI message sent to resume from the point the current sequence or song was paused.
- `MIDI_MESSAGE_STOP = 252` — MIDI message sent to pause the current sequence or song.
- `MIDI_MESSAGE_ACTIVE_SENSING = 254` — MIDI message sent repeatedly while the MIDI device is idle, to tell the receiver that the connection is alive.
- `MIDI_MESSAGE_SYSTEM_RESET = 255` — MIDI message sent to reset a MIDI device to its default state, as if it was just turned on.

## Enum Error

- `OK = 0` — Methods that return `Error` return `OK` when no error occurred.
- `FAILED = 1` — Generic error.
- `ERR_UNAVAILABLE = 2` — Unavailable error.
- `ERR_UNCONFIGURED = 3` — Unconfigured error.
- `ERR_UNAUTHORIZED = 4` — Unauthorized error.
- `ERR_PARAMETER_RANGE_ERROR = 5` — Parameter range error.
- `ERR_OUT_OF_MEMORY = 6` — Out of memory (OOM) error.
- `ERR_FILE_NOT_FOUND = 7` — File: Not found error.
- `ERR_FILE_BAD_DRIVE = 8` — File: Bad drive error.
- `ERR_FILE_BAD_PATH = 9` — File: Bad path error.
- `ERR_FILE_NO_PERMISSION = 10` — File: No permission error.
- `ERR_FILE_ALREADY_IN_USE = 11` — File: Already in use error.
- `ERR_FILE_CANT_OPEN = 12` — File: Can't open error.
- `ERR_FILE_CANT_WRITE = 13` — File: Can't write error.
- `ERR_FILE_CANT_READ = 14` — File: Can't read error.
- `ERR_FILE_UNRECOGNIZED = 15` — File: Unrecognized error.
- `ERR_FILE_CORRUPT = 16` — File: Corrupt error.
- `ERR_FILE_MISSING_DEPENDENCIES = 17` — File: Missing dependencies error.
- `ERR_FILE_EOF = 18` — File: End of file (EOF) error.
- `ERR_CANT_OPEN = 19` — Can't open error.
- `ERR_CANT_CREATE = 20` — Can't create error.
- `ERR_QUERY_FAILED = 21` — Query failed error.
- `ERR_ALREADY_IN_USE = 22` — Already in use error.
- `ERR_LOCKED = 23` — Locked error.
- `ERR_TIMEOUT = 24` — Timeout error.
- `ERR_CANT_CONNECT = 25` — Can't connect error.
- `ERR_CANT_RESOLVE = 26` — Can't resolve error.
- `ERR_CONNECTION_ERROR = 27` — Connection error.
- `ERR_CANT_ACQUIRE_RESOURCE = 28` — Can't acquire resource error.
- `ERR_CANT_FORK = 29` — Can't fork process error.
- `ERR_INVALID_DATA = 30` — Invalid data error.
- `ERR_INVALID_PARAMETER = 31` — Invalid parameter error.
- `ERR_ALREADY_EXISTS = 32` — Already exists error.
- `ERR_DOES_NOT_EXIST = 33` — Does not exist error.
- `ERR_DATABASE_CANT_READ = 34` — Database: Read error.
- `ERR_DATABASE_CANT_WRITE = 35` — Database: Write error.
- `ERR_COMPILATION_FAILED = 36` — Compilation failed error.
- `ERR_METHOD_NOT_FOUND = 37` — Method not found error.
- `ERR_LINK_FAILED = 38` — Linking failed error.
- `ERR_SCRIPT_FAILED = 39` — Script failed error.
- `ERR_CYCLIC_LINK = 40` — Cycling link (import cycle) error.
- `ERR_INVALID_DECLARATION = 41` — Invalid declaration error.
- `ERR_DUPLICATE_SYMBOL = 42` — Duplicate symbol error.
- `ERR_PARSE_ERROR = 43` — Parse error.
- `ERR_BUSY = 44` — Busy error.
- `ERR_SKIP = 45` — Skip error.
- `ERR_HELP = 46` — Help error.
- `ERR_BUG = 47` — Bug error, caused by an implementation issue in the method.
- `ERR_PRINTER_ON_FIRE = 48` — Printer on fire error (this is an easter egg, no built-in methods return this error code).

## Enum PropertyHint

- `PROPERTY_HINT_NONE = 0` — The property has no hint for the editor.
- `PROPERTY_HINT_RANGE = 1` — Hints that an int, float, or packed/typed Array property containing int or float types should be within a range specified via the hint string `"min,max"` or `"min,max,step"`.
- `PROPERTY_HINT_ENUM = 2` — Hints that an int, String, or StringName property is an enumerated value to pick in a list specified via a hint string.
- `PROPERTY_HINT_ENUM_SUGGESTION = 3` — Hints that a String or StringName property can be an enumerated value to pick in a list specified via a hint string such as `"Hello,Something,Else"`.
- `PROPERTY_HINT_EXP_EASING = 4` — Hints that a float property should be edited using a curve editor showing an exponential easing function.
- `PROPERTY_HINT_LINK = 5` — Hints that a vector property should allow its components to be linked.
- `PROPERTY_HINT_FLAGS = 6` — Hints that an int property is a bitmask with named bit flags.
- `PROPERTY_HINT_LAYERS_2D_RENDER = 7` — Hints that an int property is a bitmask using the optionally named 2D render layers.
- `PROPERTY_HINT_LAYERS_2D_PHYSICS = 8` — Hints that an int property is a bitmask using the optionally named 2D physics layers.
- `PROPERTY_HINT_LAYERS_2D_NAVIGATION = 9` — Hints that an int property is a bitmask using the optionally named 2D navigation layers.
- `PROPERTY_HINT_LAYERS_3D_RENDER = 10` — Hints that an int property is a bitmask using the optionally named 3D render layers.
- `PROPERTY_HINT_LAYERS_3D_PHYSICS = 11` — Hints that an int property is a bitmask using the optionally named 3D physics layers.
- `PROPERTY_HINT_LAYERS_3D_NAVIGATION = 12` — Hints that an int property is a bitmask using the optionally named 3D navigation layers.
- `PROPERTY_HINT_LAYERS_AVOIDANCE = 37` — Hints that an integer property is a bitmask using the optionally named avoidance layers.
- `PROPERTY_HINT_FILE = 13` — Hints that a String property is a path to a file.
- `PROPERTY_HINT_DIR = 14` — Hints that a String property is a path to a directory.
- `PROPERTY_HINT_GLOBAL_FILE = 15` — Hints that a String property is an absolute path to a file outside the project folder.
- `PROPERTY_HINT_GLOBAL_DIR = 16` — Hints that a String property is an absolute path to a directory outside the project folder.
- `PROPERTY_HINT_RESOURCE_TYPE = 17` — Hints that a property is an instance of a Resource-derived type, optionally specified via the hint string (e.g.
- `PROPERTY_HINT_MULTILINE_TEXT = 18` — Hints that a String property is text with line breaks.
- `PROPERTY_HINT_EXPRESSION = 19` — Hints that a String property is an Expression.
- `PROPERTY_HINT_PLACEHOLDER_TEXT = 20` — Hints that a String property should show a placeholder text on its input field, if empty.
- `PROPERTY_HINT_COLOR_NO_ALPHA = 21` — Hints that a Color property should be edited without affecting its transparency (`Color.a` is not editable).
- `PROPERTY_HINT_OBJECT_ID = 22` — Hints that the property's value is an object encoded as object ID, with its type specified in the hint string.
- `PROPERTY_HINT_TYPE_STRING = 23` — If a property is String, hints that the property represents a particular type (class).
- `PROPERTY_HINT_NODE_PATH_TO_EDITED_NODE = 24` — 
- `PROPERTY_HINT_OBJECT_TOO_BIG = 25` — Hints that an object is too big to be sent via the debugger.
- `PROPERTY_HINT_NODE_PATH_VALID_TYPES = 26` — Hints that the hint string specifies valid node types for property of type NodePath.
- `PROPERTY_HINT_SAVE_FILE = 27` — Hints that a String property is a path to a file.
- `PROPERTY_HINT_GLOBAL_SAVE_FILE = 28` — Hints that a String property is a path to a file.
- `PROPERTY_HINT_INT_IS_OBJECTID = 29` — 
- `PROPERTY_HINT_INT_IS_POINTER = 30` — Hints that an int property is a pointer.
- `PROPERTY_HINT_ARRAY_TYPE = 31` — Hints that a property is an Array with the stored type specified in the hint string.
- `PROPERTY_HINT_DICTIONARY_TYPE = 38` — Hints that a property is a Dictionary with the stored types specified in the hint string.
- `PROPERTY_HINT_LOCALE_ID = 32` — Hints that a string property is a locale code.
- `PROPERTY_HINT_LOCALIZABLE_STRING = 33` — Hints that a dictionary property is string translation map.
- `PROPERTY_HINT_NODE_TYPE = 34` — Hints that a property is an instance of a Node-derived type, optionally specified via the hint string (e.g.
- `PROPERTY_HINT_HIDE_QUATERNION_EDIT = 35` — Hints that a quaternion property should disable the temporary euler editor.
- `PROPERTY_HINT_PASSWORD = 36` — Hints that a string property is a password, and every character is replaced with the secret character.
- `PROPERTY_HINT_TOOL_BUTTON = 39` — Hints that a Callable property should be displayed as a clickable button.
- `PROPERTY_HINT_ONESHOT = 40` — Hints that a property will be changed on its own after setting, such as `AudioStreamPlayer.playing` or `GPUParticles3D.emitting`.
- `PROPERTY_HINT_GROUP_ENABLE = 42` — Hints that a boolean property will enable the feature associated with the group that it occurs in.
- `PROPERTY_HINT_INPUT_NAME = 43` — Hints that a String or StringName property is the name of an input action.
- `PROPERTY_HINT_FILE_PATH = 44` — Like `PROPERTY_HINT_FILE`, but the property is stored as a raw path, not UID.
- `PROPERTY_HINT_AUDIO_BUS = 45` — Hints that a String or StringName property is the name of an audio bus.
- `PROPERTY_HINT_MAX = 46` — Represents the size of the `PropertyHint` enum.

## Enum PropertyUsageFlags

- `PROPERTY_USAGE_NONE = 0` — The property is not stored, and does not display in the editor.
- `PROPERTY_USAGE_STORAGE = 2` — The property is serialized and saved in the scene file (default for exported properties).
- `PROPERTY_USAGE_EDITOR = 4` — The property is shown in the EditorInspector (default for exported properties).
- `PROPERTY_USAGE_INTERNAL = 8` — The property is excluded from the class reference.
- `PROPERTY_USAGE_CHECKABLE = 16` — The property can be checked in the EditorInspector.
- `PROPERTY_USAGE_CHECKED = 32` — The property is checked in the EditorInspector.
- `PROPERTY_USAGE_GROUP = 64` — Used to group properties together in the editor.
- `PROPERTY_USAGE_CATEGORY = 128` — Used to categorize properties together in the editor.
- `PROPERTY_USAGE_SUBGROUP = 256` — Used to group properties together in the editor in a subgroup (under a group).
- `PROPERTY_USAGE_CLASS_IS_BITFIELD = 512` — The property is a bitfield, i.e. it contains multiple flags represented as bits.
- `PROPERTY_USAGE_NO_INSTANCE_STATE = 1024` — The property does not save its state in PackedScene.
- `PROPERTY_USAGE_RESTART_IF_CHANGED = 2048` — Editing the property prompts the user for restarting the editor.
- `PROPERTY_USAGE_SCRIPT_VARIABLE = 4096` — The property is a script variable.
- `PROPERTY_USAGE_STORE_IF_NULL = 8192` — The property value of type Object will be stored even if its value is `null`.
- `PROPERTY_USAGE_UPDATE_ALL_IF_MODIFIED = 16384` — If this property is modified, all inspector fields will be refreshed.
- `PROPERTY_USAGE_SCRIPT_DEFAULT_VALUE = 32768` — 
- `PROPERTY_USAGE_CLASS_IS_ENUM = 65536` — The property is a variable of enum type, i.e. it only takes named integer constants from its associated enumeration.
- `PROPERTY_USAGE_NIL_IS_VARIANT = 131072` — If property has `nil` as default value, its type will be Variant.
- `PROPERTY_USAGE_ARRAY = 262144` — The property is the element count of a property array, i.e. a list of groups of related properties.
- `PROPERTY_USAGE_ALWAYS_DUPLICATE = 524288` — When duplicating a resource with `Resource.duplicate`, and this flag is set on a property of that resource, the property should always be duplicated, regardless of the `subresources` bool parameter.
- `PROPERTY_USAGE_NEVER_DUPLICATE = 1048576` — When duplicating a resource with `Resource.duplicate`, and this flag is set on a property of that resource, the property should never be duplicated, regardless of the `subresources` bool parameter.
- `PROPERTY_USAGE_HIGH_END_GFX = 2097152` — The property is only shown in the editor if modern renderers are supported (the Compatibility rendering method is excluded).
- `PROPERTY_USAGE_NODE_PATH_FROM_SCENE_ROOT = 4194304` — The NodePath property will always be relative to the scene's root.
- `PROPERTY_USAGE_RESOURCE_NOT_PERSISTENT = 8388608` — Use when a resource is created on the fly, i.e. the getter will always return a different instance.
- `PROPERTY_USAGE_KEYING_INCREMENTS = 16777216` — Inserting an animation key frame of this property will automatically increment the value, allowing to easily keyframe multiple values in a row.
- `PROPERTY_USAGE_DEFERRED_SET_RESOURCE = 33554432` — 
- `PROPERTY_USAGE_EDITOR_INSTANTIATE_OBJECT = 67108864` — When this property is a Resource and base object is a Node, a resource instance will be automatically created whenever the node is created in the editor.
- `PROPERTY_USAGE_EDITOR_BASIC_SETTING = 134217728` — The property is considered a basic setting and will appear even when advanced mode is disabled.
- `PROPERTY_USAGE_READ_ONLY = 268435456` — The property is read-only in the EditorInspector.
- `PROPERTY_USAGE_SECRET = 536870912` — An export preset property with this flag contains confidential information and is stored separately from the rest of the export preset configuration.
- `PROPERTY_USAGE_DEFAULT = 6` — Default usage (storage and editor).
- `PROPERTY_USAGE_NO_EDITOR = 2` — Default usage but without showing the property in the editor (storage).

## Enum MethodFlags

- `METHOD_FLAG_NORMAL = 1` — Flag for a normal method.
- `METHOD_FLAG_EDITOR = 2` — Flag for an editor method.
- `METHOD_FLAG_CONST = 4` — Flag for a constant method.
- `METHOD_FLAG_VIRTUAL = 8` — Flag for a virtual method.
- `METHOD_FLAG_VARARG = 16` — Flag for a method with a variable number of arguments.
- `METHOD_FLAG_STATIC = 32` — Flag for a static method.
- `METHOD_FLAG_OBJECT_CORE = 64` — Used internally.
- `METHOD_FLAG_VIRTUAL_REQUIRED = 128` — Flag for a virtual method that is required.
- `METHOD_FLAGS_DEFAULT = 1` — Default method flags (normal).

## Enum Variant.Type

- `TYPE_NIL = 0` — Variable is `null`.
- `TYPE_BOOL = 1` — Variable is of type bool.
- `TYPE_INT = 2` — Variable is of type int.
- `TYPE_FLOAT = 3` — Variable is of type float.
- `TYPE_STRING = 4` — Variable is of type String.
- `TYPE_VECTOR2 = 5` — Variable is of type Vector2.
- `TYPE_VECTOR2I = 6` — Variable is of type Vector2i.
- `TYPE_RECT2 = 7` — Variable is of type Rect2.
- `TYPE_RECT2I = 8` — Variable is of type Rect2i.
- `TYPE_VECTOR3 = 9` — Variable is of type Vector3.
- `TYPE_VECTOR3I = 10` — Variable is of type Vector3i.
- `TYPE_TRANSFORM2D = 11` — Variable is of type Transform2D.
- `TYPE_VECTOR4 = 12` — Variable is of type Vector4.
- `TYPE_VECTOR4I = 13` — Variable is of type Vector4i.
- `TYPE_PLANE = 14` — Variable is of type Plane.
- `TYPE_QUATERNION = 15` — Variable is of type Quaternion.
- `TYPE_AABB = 16` — Variable is of type AABB.
- `TYPE_BASIS = 17` — Variable is of type Basis.
- `TYPE_TRANSFORM3D = 18` — Variable is of type Transform3D.
- `TYPE_PROJECTION = 19` — Variable is of type Projection.
- `TYPE_COLOR = 20` — Variable is of type Color.
- `TYPE_STRING_NAME = 21` — Variable is of type StringName.
- `TYPE_NODE_PATH = 22` — Variable is of type NodePath.
- `TYPE_RID = 23` — Variable is of type RID.
- `TYPE_OBJECT = 24` — Variable is of type Object.
- `TYPE_CALLABLE = 25` — Variable is of type Callable.
- `TYPE_SIGNAL = 26` — Variable is of type Signal.
- `TYPE_DICTIONARY = 27` — Variable is of type Dictionary.
- `TYPE_ARRAY = 28` — Variable is of type Array.
- `TYPE_PACKED_BYTE_ARRAY = 29` — Variable is of type PackedByteArray.
- `TYPE_PACKED_INT32_ARRAY = 30` — Variable is of type PackedInt32Array.
- `TYPE_PACKED_INT64_ARRAY = 31` — Variable is of type PackedInt64Array.
- `TYPE_PACKED_FLOAT32_ARRAY = 32` — Variable is of type PackedFloat32Array.
- `TYPE_PACKED_FLOAT64_ARRAY = 33` — Variable is of type PackedFloat64Array.
- `TYPE_PACKED_STRING_ARRAY = 34` — Variable is of type PackedStringArray.
- `TYPE_PACKED_VECTOR2_ARRAY = 35` — Variable is of type PackedVector2Array.
- `TYPE_PACKED_VECTOR3_ARRAY = 36` — Variable is of type PackedVector3Array.
- `TYPE_PACKED_COLOR_ARRAY = 37` — Variable is of type PackedColorArray.
- `TYPE_PACKED_VECTOR4_ARRAY = 38` — Variable is of type PackedVector4Array.
- `TYPE_MAX = 39` — Represents the size of the `Variant.Type` enum.

## Enum Variant.Operator

- `OP_EQUAL = 0` — Equality operator (`==`).
- `OP_NOT_EQUAL = 1` — Inequality operator (`!=`).
- `OP_LESS = 2` — Less than operator (`<`).
- `OP_LESS_EQUAL = 3` — Less than or equal operator (`<=`).
- `OP_GREATER = 4` — Greater than operator (`>`).
- `OP_GREATER_EQUAL = 5` — Greater than or equal operator (`>=`).
- `OP_ADD = 6` — Addition operator (`+`).
- `OP_SUBTRACT = 7` — Subtraction operator (`-`).
- `OP_MULTIPLY = 8` — Multiplication operator (`*`).
- `OP_DIVIDE = 9` — Division operator (`/`).
- `OP_NEGATE = 10` — Unary negation operator (`-`).
- `OP_POSITIVE = 11` — Unary plus operator (`+`).
- `OP_MODULE = 12` — Remainder/modulo operator (`%`).
- `OP_POWER = 13` — Power operator (`**`).
- `OP_SHIFT_LEFT = 14` — Left shift operator (`<<`).
- `OP_SHIFT_RIGHT = 15` — Right shift operator (`>>`).
- `OP_BIT_AND = 16` — Bitwise AND operator (`&`).
- `OP_BIT_OR = 17` — Bitwise OR operator (`|`).
- `OP_BIT_XOR = 18` — Bitwise XOR operator (`^`).
- `OP_BIT_NEGATE = 19` — Bitwise NOT operator (`~`).
- `OP_AND = 20` — Logical AND operator (`and` or `&&`).
- `OP_OR = 21` — Logical OR operator (`or` or `||`).
- `OP_XOR = 22` — Logical XOR operator (not implemented in GDScript).
- `OP_NOT = 23` — Logical NOT operator (`not` or `!`).
- `OP_IN = 24` — Logical IN operator (`in`).
- `OP_MAX = 25` — Represents the size of the `Variant.Operator` enum.

## Constants

- `UINT8_MAX = 255` — Maximum value of an 8-bit unsigned integer.
- `UINT16_MAX = 65535` — Maximum value of a 16-bit unsigned integer.
- `UINT32_MAX = 4294967295` — Maximum value of a 32-bit unsigned integer.
- `INT8_MIN = -128` — Minimum value of an 8-bit signed integer.
- `INT8_MAX = 127` — Maximum value of an 8-bit signed integer.
- `INT16_MIN = -32768` — Minimum value of a 16-bit signed integer.
- `INT16_MAX = 32767` — Maximum value of a 16-bit signed integer.
- `INT32_MIN = -2147483648` — Minimum value of a 32-bit signed integer.
- `INT32_MAX = 2147483647` — Maximum value of a 32-bit signed integer.
- `INT64_MIN = -9223372036854775808` — Minimum value of a 64-bit signed integer.
- `INT64_MAX = 9223372036854775807` — Maximum value of a 64-bit signed integer.
