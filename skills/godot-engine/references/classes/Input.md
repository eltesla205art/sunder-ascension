# Input

**Inherits:** Object

A singleton for handling inputs.

The Input singleton handles key presses, mouse buttons and movement, gamepads, and input actions. Actions and their events can be set in the Input Map tab in Project > Project Settings, or with the InputMap class. Note: Input's methods reflect the global input state and are not affected by `Control.accept_event` or `Viewport.set_input_as_handled`, as those methods only deal with the way input is propagated in the SceneTree.

## Properties

- `emulate_mouse_from_touch: bool` — If `true`, sends mouse input events when tapping or swiping on the touchscreen.
- `emulate_touch_from_mouse: bool` — If `true`, sends touch input events when clicking or dragging the mouse.
- `ignore_joypad_on_unfocused_application: bool` — If `true`, joypad input (including motion sensors) and LED light changes will be ignored and joypad vibration will be stopped when the application is not focused.
- `mouse_mode: Input.MouseMode` — Controls the mouse mode.
- `use_accumulated_input: bool` — If `true`, similar input events sent by the operating system are accumulated.

## Methods

- `action_press(action: StringName, strength: float = 1.0) -> void` — Simulates pressing the specified input action.
- `action_release(action: StringName) -> void` — Releases the specified input action, if the action is currently pressed.
- `add_joy_mapping(mapping: String, update_existing: bool = false) -> void` — Adds a new joypad mapping entry (in SDL format) to the mapping database, and optionally updates the already connected devices.
- `clear_joy_motion_sensors_calibration(device: int) -> void` — Clears the calibration information for the specified joypad's motion sensors, if it has any and if they were calibrated.
- `flush_buffered_events() -> void` — Sends all buffered input events to the game loop.
- `get_accelerometer() -> Vector3` *const* — Returns the acceleration in m/s² of the device's accelerometer sensor, if the device has one.
- `get_action_raw_strength(action: StringName, exact_match: bool = false) -> float` *const* — Returns a value between `0.0` and `1.0` representing the raw intensity of the given action, ignoring the action's deadzone.
- `get_action_strength(action: StringName, exact_match: bool = false) -> float` *const* — Returns a value between `0.0` and `1.0` representing the intensity of the given action.
- `get_axis(negative_action: StringName, positive_action: StringName) -> float` *const* — Returns axis input value by specifying two actions, one negative and one positive.
- `get_connected_joypads() -> int[]` — Returns an Array containing the device IDs of all currently connected joypads.
- `get_current_cursor_shape() -> int[Input.CursorShape]` *const* — Returns the currently assigned cursor shape.
- `get_device_orientation() -> Quaternion` *const* — Returns the device's orientation as a Quaternion, using hardware-level sensor fusion for stable, drift-free results.
- `get_gravity() -> Vector3` *const* — Returns the gravity in m/s² of the device's accelerometer sensor, if the device has one.
- `get_gyroscope() -> Vector3` *const* — Returns the rotation rate in rad/s around a device's X, Y, and Z axes of the gyroscope sensor, if the device has one.
- `get_joy_accelerometer(device: int) -> Vector3` *const* — Returns the acceleration, including the force of gravity, in m/s² of the joypad's accelerometer sensor, if the joypad has one and it's currently enabled.
- `get_joy_axis(device: int, axis: JoyAxis) -> float` *const* — Returns the current value of the joypad axis at index `axis`.
- `get_joy_gravity(device: int) -> Vector3` *const* — Returns the gravity in m/s² of the joypad's accelerometer sensor, if the joypad has one and it's currently enabled.
- `get_joy_guid(device: int) -> String` *const* — Returns an SDL-compatible device GUID on platforms that use gamepad remapping, e.g.
- `get_joy_gyroscope(device: int) -> Vector3` *const* — Returns the rotation rate in rad/s around a joypad's X, Y, and Z axes of the gyroscope sensor, if the joypad has one and it's currently enabled.
- `get_joy_info(device: int) -> Dictionary` *const* — Returns a dictionary with extra platform-specific information about the device, e.g. the raw gamepad name from the OS or the Steam Input index.
- `get_joy_motion_sensors_calibration(device: int) -> Dictionary` *const* — Returns the calibration information about the specified joypad's motion sensors in the form of a Dictionary, if it has any and if they have been calibrated, otherwise returns an empty Dictionary.
- `get_joy_motion_sensors_rate(device: int) -> float` *const* — Returns the joypad's motion sensor rate in Hz, if the joypad has motion sensors and they're currently enabled.
- `get_joy_name(device: int) -> String` — Returns the name of the joypad at the specified device index, e.g.
- `get_joy_num_touchpads(device: int) -> int` *const* — Returns the number of touchpads on the specified joypad, if it has any.
- `get_joy_touchpad_finger_position(device: int, finger: int, touchpad: int = 0) -> Vector2` *const* — Returns the position of the specified finger on the specified touchpad on the joypad.
- `get_joy_touchpad_finger_pressure(device: int, finger: int, touchpad: int = 0) -> float` *const* — Returns the pressure of the specified finger on the specified touchpad on the joypad.
- `get_joy_touchpad_fingers(device: int, touchpad: int = 0) -> PackedInt32Array` *const* — Returns an array of finger IDs that are currently touching the specified touchpad on the joypad.
- `get_joy_vibration_duration(device: int) -> float` — Returns the duration of the current vibration effect in seconds.
- `get_joy_vibration_remaining_duration(device: int) -> float` — Returns the remaining duration of the current vibration effect in seconds.
- `get_joy_vibration_strength(device: int) -> Vector2` — Returns the strength of the joypad vibration: x is the strength of the weak motor, and y is the strength of the strong motor.
- `get_last_mouse_screen_velocity() -> Vector2` — Returns the last mouse velocity in screen coordinates.
- `get_last_mouse_velocity() -> Vector2` — Returns the last mouse velocity.
- `get_magnetometer() -> Vector3` *const* — Returns the magnetic field strength in micro-Tesla for all axes of the device's magnetometer sensor, if the device has one.
- `get_mouse_button_mask() -> int[MouseButtonMask]` *const* — Returns mouse buttons as a bitmask.
- `get_vector(negative_x: StringName, positive_x: StringName, negative_y: StringName, positive_y: StringName, deadzone: float = -1.0) -> Vector2` *const* — Returns an input vector by specifying four actions for the positive and negative X and Y axes.
- `has_joy_light(device: int) -> bool` *const* — Returns `true` if the joypad has an LED light that can change colors and/or brightness.
- `has_joy_motion_sensors(device: int) -> bool` *const* — Returns `true` if the joypad has motion sensors (gyroscope and/or accelerometer).
- `has_joy_vibration(device: int) -> bool` *const* — Returns `true` if the joypad supports vibration.
- `is_action_just_pressed(action: StringName, exact_match: bool = false) -> bool` *const* — Returns `true` when the user has started pressing the action event in the current frame or physics tick.
- `is_action_just_pressed_by_event(action: StringName, event: InputEvent, exact_match: bool = false) -> bool` *const* — Returns `true` when the user has started pressing the action event in the current frame or physics tick, and the first event that triggered action press in the current frame/physics tick was `event`.
- `is_action_just_released(action: StringName, exact_match: bool = false) -> bool` *const* — Returns `true` when the user stops pressing the action event in the current frame or physics tick.
- `is_action_just_released_by_event(action: StringName, event: InputEvent, exact_match: bool = false) -> bool` *const* — Returns `true` when the user stops pressing the action event in the current frame or physics tick, and the first event that triggered action release in the current frame/physics tick was `event`.
- `is_action_pressed(action: StringName, exact_match: bool = false) -> bool` *const* — Returns `true` if you are pressing the action event.
- `is_anything_pressed() -> bool` *const* — Returns `true` if any action, key, joypad button, or mouse button is being pressed.
- `is_joy_button_pressed(device: int, button: JoyButton) -> bool` *const* — Returns `true` if you are pressing the joypad button at index `button`.
- `is_joy_known(device: int) -> bool` — Returns `true` if the system knows the specified device.
- `is_joy_motion_sensors_auto_calibration_enabled(device: int) -> bool` *const* — Returns `true` if automatic calibration is enabled on the joypad's motion sensors.
- `is_joy_motion_sensors_calibrated(device: int) -> bool` *const* — Returns `true` if the joypad's motion sensors have been calibrated.
- `is_joy_motion_sensors_calibrating(device: int) -> bool` *const* — Returns `true` if the joypad's motion sensors are currently being manually calibrated.
- `is_joy_motion_sensors_enabled(device: int) -> bool` *const* — Returns `true` if the requested joypad has motion sensors (gyroscope and/or accelerometer) and they are currently enabled.
- `is_joy_vibrating(device: int) -> bool` — Returns `true` if the joypad is still vibrating after a call to `start_joy_vibration`.
- `is_key_label_pressed(keycode: Key) -> bool` *const* — Returns `true` if you are pressing the key with the `keycode` printed on it.
- `is_key_pressed(keycode: Key) -> bool` *const* — Returns `true` if you are pressing the Latin key in the current keyboard layout.
- `is_mouse_button_pressed(button: MouseButton) -> bool` *const* — Returns `true` if you are pressing the mouse button specified with `MouseButton`.
- `is_physical_key_pressed(keycode: Key) -> bool` *const* — Returns `true` if you are pressing the key in the physical location on the 101/102-key US QWERTY keyboard.
- `parse_input_event(event: InputEvent) -> void` — Feeds an InputEvent to the game.
- `remove_joy_mapping(guid: String) -> void` — Removes all mappings from the internal database that match the given GUID.
- `set_accelerometer(value: Vector3) -> void` — Sets the acceleration value of the accelerometer sensor.
- `set_custom_mouse_cursor(image: Resource, shape: Input.CursorShape = 0, hotspot: Vector2 = Vector2(0, 0)) -> void` — Sets a custom mouse cursor image, which is only visible inside the game window, for the given mouse `shape`.
- `set_default_cursor_shape(shape: Input.CursorShape = 0) -> void` — Sets the default cursor shape to be used in the viewport instead of `CURSOR_ARROW`.
- `set_device_orientation(value: Quaternion) -> void` — Sets the device orientation quaternion.
- `set_gravity(value: Vector3) -> void` — Sets the gravity value of the accelerometer sensor.
- `set_gyroscope(value: Vector3) -> void` — Sets the value of the rotation rate of the gyroscope sensor.
- `set_joy_light(device: int, color: Color) -> void` — Sets the joypad's LED light, if available, to the specified color.
- `set_joy_motion_sensors_auto_calibration_enabled(device: int, enable: bool) -> void` — Enables or disables automatic calibration of the joypad's gyroscope.
- `set_joy_motion_sensors_calibration(device: int, calibration_info: Dictionary) -> void` — Sets the specified joypad's calibration information.
- `set_joy_motion_sensors_enabled(device: int, enable: bool) -> void` — Enables or disables the motion sensors (gyroscope and/or accelerometer), if available, on the specified joypad.
- `set_magnetometer(value: Vector3) -> void` — Sets the value of the magnetic field of the magnetometer sensor.
- `should_ignore_device(vendor_id: int, product_id: int) -> bool` *const* — Queries whether an input device should be ignored or not.
- `start_joy_motion_sensors_calibration(device: int) -> void` — Starts the process of manually calibrating the specified joypad's gyroscope, if it has one.
- `start_joy_vibration(device: int, weak_magnitude: float, strong_magnitude: float, duration: float = 0) -> void` — Starts vibrating the joypad.
- `stop_joy_motion_sensors_calibration(device: int) -> void` — Stops the manual calibration process of the specified joypad's motion sensors.
- `stop_joy_vibration(device: int) -> void` — Stops the vibration of the joypad started with `start_joy_vibration`.
- `vibrate_handheld(duration_ms: int = 500, amplitude: float = -1.0) -> void` — Starts vibrating the handheld device for the specified duration in milliseconds.
- `warp_mouse(position: Vector2) -> void` — Sets the mouse position to the specified vector, provided in pixels and relative to an origin at the upper left corner of the currently focused Window Manager game window.

## Signals

- `joy_connection_changed(device: int, connected: bool)` — Emitted when a joypad device has been connected or disconnected.

## Enum MouseMode

- `MOUSE_MODE_VISIBLE = 0` — Makes the mouse cursor visible if it is hidden.
- `MOUSE_MODE_HIDDEN = 1` — Makes the mouse cursor hidden if it is visible.
- `MOUSE_MODE_CAPTURED = 2` — Captures the mouse.
- `MOUSE_MODE_CONFINED = 3` — Confines the mouse cursor to the game window, and make it visible.
- `MOUSE_MODE_CONFINED_HIDDEN = 4` — Confines the mouse cursor to the game window, and make it hidden.
- `MOUSE_MODE_MAX = 5` — Max value of the `MouseMode`.

## Enum CursorShape

- `CURSOR_ARROW = 0` — Arrow cursor.
- `CURSOR_IBEAM = 1` — I-beam cursor.
- `CURSOR_POINTING_HAND = 2` — Pointing hand cursor.
- `CURSOR_CROSS = 3` — Cross cursor.
- `CURSOR_WAIT = 4` — Wait cursor.
- `CURSOR_BUSY = 5` — Busy cursor.
- `CURSOR_DRAG = 6` — Drag cursor.
- `CURSOR_CAN_DROP = 7` — Can drop cursor.
- `CURSOR_FORBIDDEN = 8` — Forbidden cursor.
- `CURSOR_VSIZE = 9` — Vertical resize mouse cursor.
- `CURSOR_HSIZE = 10` — Horizontal resize mouse cursor.
- `CURSOR_BDIAGSIZE = 11` — Window resize mouse cursor.
- `CURSOR_FDIAGSIZE = 12` — Window resize mouse cursor.
- `CURSOR_MOVE = 13` — Move cursor.
- `CURSOR_VSPLIT = 14` — Vertical split mouse cursor.
- `CURSOR_HSPLIT = 15` — Horizontal split mouse cursor.
- `CURSOR_HELP = 16` — Help cursor.
