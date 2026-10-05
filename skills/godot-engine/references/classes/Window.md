# Window

**Inherits:** Viewport

Base class for all windows, dialogs, and popups.

A node that creates a window. The window can either be a native system window or embedded inside another Window (see `Viewport.gui_embed_subwindows`). At runtime, Windows will not close automatically when requested. You need to handle it manually using the `close_requested` signal (this applies both to pressing the close button and clicking outside of a popup).

## Properties

- `accessibility_description: String` = `""` — The human-readable node description that is reported to assistive apps.
- `accessibility_name: String` = `""` — The human-readable node name that is reported to assistive apps.
- `always_on_top: bool` = `false` — If `true`, the window will be on top of all other windows.
- `auto_translate: bool` *(deprecated)* — Toggles if any text should automatically change to its translated version depending on the current locale.
- `borderless: bool` = `false` — If `true`, the window will have no borders.
- `content_scale_aspect: Window.ContentScaleAspect` = `0` — Specifies how the content's aspect behaves when the Window is resized.
- `content_scale_factor: float` = `1.0` — Specifies the base scale of Window's content when its `size` is equal to `content_scale_size`.
- `content_scale_mode: Window.ContentScaleMode` = `0` — Specifies how the content is scaled when the Window is resized.
- `content_scale_size: Vector2i` = `Vector2i(0, 0)` — The content's base size in "virtual" pixels.
- `content_scale_stretch: Window.ContentScaleStretch` = `0` — The policy to use to determine the final scale factor for 2D elements.
- `current_screen: int` — The screen the window is currently on.
- `exclude_from_capture: bool` = `false` — If `true`, the Window is excluded from screenshots taken by `DisplayServer.screen_get_image`, `DisplayServer.screen_get_image_rect`, and `DisplayServer.screen_get_pixel`.
- `exclusive: bool` = `false` — If `true`, the Window will be in exclusive mode.
- `extend_to_title: bool` = `false` — If `true`, the Window contents is expanded to the full size of the window, window title bar is transparent.
- `force_native: bool` = `false` — If `true`, native window will be used regardless of parent viewport and project settings.
- `fullscreen_shortcut_enabled: bool` = `false` — If `true`, allows the user to toggle fullscreen mode by pressing the shortcut defined in `ProjectSettings.input/ui_toggle_fullscreen` (`Alt + Enter` by default).
- `hdr_output_requested: bool` = `false` — If `true`, requests HDR output for the Window, falling back to SDR if not supported, and automatically switching between HDR and SDR as the window moves between screens, screen capabilities change, or system settings are modified.
- `initial_position: Window.WindowInitialPosition` = `0` — Specifies the initial type of position for the Window.
- `keep_title_visible: bool` = `false` — If `true`, the Window width is expanded to keep the title bar text fully visible.
- `max_size: Vector2i` = `Vector2i(0, 0)` — If non-zero, the Window can't be resized to be bigger than this size.
- `maximize_disabled: bool` = `false` — If `true`, the Window's maximize button is disabled.
- `min_size: Vector2i` = `Vector2i(0, 0)` — If non-zero, the Window can't be resized to be smaller than this size.
- `minimize_disabled: bool` = `false` — If `true`, the Window's minimize button is disabled.
- `mode: Window.Mode` = `0` — Set's the window's current mode.
- `mouse_passthrough: bool` = `false` — If `true`, all mouse events will be passed to the underlying window of the same application.
- `mouse_passthrough_polygon: PackedVector2Array` = `PackedVector2Array()` — Sets a polygonal region of the window which accepts mouse events.
- `nonclient_area: Rect2i` = `Rect2i(0, 0, 0, 0)` — If set, defines the window's custom decoration area which will receive mouse input, even if normal input to the window is blocked (such as when it has an exclusive child opened).
- `popup_window: bool` = `false` — If `true`, the Window will be considered a popup.
- `popup_wm_hint: bool` = `false` — If `true`, the Window will signal to the window manager that it is supposed to be an implementation-defined "popup" (usually a floating, borderless, untileable and immovable child window).
- `position: Vector2i` = `Vector2i(0, 0)` — The window's position in pixels.
- `sharp_corners: bool` = `false` — If `true`, the Window will override the OS window style to display sharp corners.
- `size: Vector2i` = `Vector2i(100, 100)` — The window's size in pixels.
- `theme: Theme` — The Theme resource this node and all its Control and Window children use.
- `theme_type_variation: StringName` = `&""` — The name of a theme type variation used by this Window to look up its own theme items.
- `title: String` = `""` — The window's title.
- `transient: bool` = `false` — If `true`, the Window is transient, i.e. it's considered a child of another Window.
- `transient_to_focused: bool` = `false` — If `true`, and the Window is `transient`, this window will (at the time of becoming visible) become transient to the currently focused window instead of the immediate parent window in the hierarchy.
- `transparent: bool` = `false` — If `true`, the Window's background can be transparent.
- `unfocusable: bool` = `false` — If `true`, the Window can't be focused nor interacted with.
- `unresizable: bool` = `false` — If `true`, the window can't be resized.
- `visible: bool` = `true` — If `true`, the window is visible.
- `wrap_controls: bool` = `false` — If `true`, the window's size will automatically update when a child node is added or removed, ignoring `min_size` if the new size is bigger.

## Methods

- `_get_contents_minimum_size() -> Vector2` *virtual const* — Virtual method to be implemented by the user.
- `add_theme_color_override(name: StringName, color: Color) -> void` — Creates a local override for a theme Color with the specified `name`.
- `add_theme_constant_override(name: StringName, constant: int) -> void` — Creates a local override for a theme constant with the specified `name`.
- `add_theme_font_override(name: StringName, font: Font) -> void` — Creates a local override for a theme Font with the specified `name`.
- `add_theme_font_size_override(name: StringName, font_size: int) -> void` — Creates a local override for a theme font size with the specified `name`.
- `add_theme_icon_override(name: StringName, texture: Texture2D) -> void` — Creates a local override for a theme icon with the specified `name`.
- `add_theme_sound_override(name: StringName, sound: AudioStream) -> void` — Creates a local override for a theme sound with the specified `name`.
- `add_theme_stylebox_override(name: StringName, stylebox: StyleBox) -> void` — Creates a local override for a theme StyleBox with the specified `name`.
- `begin_bulk_theme_override() -> void` — Prevents `*_theme_*_override` methods from emitting `NOTIFICATION_THEME_CHANGED` until `end_bulk_theme_override` is called.
- `can_draw() -> bool` *const* — Returns whether the window is being drawn to the screen.
- `child_controls_changed() -> void` — Requests an update of the Window size to fit underlying Control nodes.
- `end_bulk_theme_override() -> void` — Ends a bulk theme override update.
- `get_contents_minimum_size() -> Vector2` *const* — Returns the combined minimum size from the child Control nodes of the window.
- `get_flag(flag: Window.Flags) -> bool` *const* — Returns `true` if the `flag` is set.
- `get_focused_window() -> Window` *static* — Returns the focused window.
- `get_layout_direction() -> int[Window.LayoutDirection]` *const* — Returns layout direction and text writing direction.
- `get_output_max_linear_value() -> float` *const* — Returns the maximum value for linear color components that can be displayed in this window, regardless of SDR or HDR output.
- `get_position_with_decorations() -> Vector2i` *const* — Returns the window's position including its border.
- `get_size_with_decorations() -> Vector2i` *const* — Returns the window's size including its border.
- `get_theme_color(name: StringName, theme_type: StringName = &"") -> Color` *const* — Returns a Color from the first matching Theme in the tree if that Theme has a color item with the specified `name` and `theme_type`.
- `get_theme_constant(name: StringName, theme_type: StringName = &"") -> int` *const* — Returns a constant from the first matching Theme in the tree if that Theme has a constant item with the specified `name` and `theme_type`.
- `get_theme_default_base_scale() -> float` *const* — Returns the default base scale value from the first matching Theme in the tree if that Theme has a valid `Theme.default_base_scale` value.
- `get_theme_default_font() -> Font` *const* — Returns the default font from the first matching Theme in the tree if that Theme has a valid `Theme.default_font` value.
- `get_theme_default_font_size() -> int` *const* — Returns the default font size value from the first matching Theme in the tree if that Theme has a valid `Theme.default_font_size` value.
- `get_theme_font(name: StringName, theme_type: StringName = &"") -> Font` *const* — Returns a Font from the first matching Theme in the tree if that Theme has a font item with the specified `name` and `theme_type`.
- `get_theme_font_size(name: StringName, theme_type: StringName = &"") -> int` *const* — Returns a font size from the first matching Theme in the tree if that Theme has a font size item with the specified `name` and `theme_type`.
- `get_theme_icon(name: StringName, theme_type: StringName = &"") -> Texture2D` *const* — Returns an icon from the first matching Theme in the tree if that Theme has an icon item with the specified `name` and `theme_type`.
- `get_theme_sound(name: StringName, theme_type: StringName = &"") -> AudioStream` *const* — Returns a sound from the first matching Theme in the tree if that Theme has a sound item with the specified `name` and `theme_type`.
- `get_theme_stylebox(name: StringName, theme_type: StringName = &"") -> StyleBox` *const* — Returns a StyleBox from the first matching Theme in the tree if that Theme has a stylebox item with the specified `name` and `theme_type`.
- `get_window_id() -> int` *const* — Returns the ID of the window.
- `grab_focus() -> void` — Causes the window to grab focus, allowing it to receive user input.
- `has_focus() -> bool` *const* — Returns `true` if the window is focused.
- `has_theme_color(name: StringName, theme_type: StringName = &"") -> bool` *const* — Returns `true` if there is a matching Theme in the tree that has a color item with the specified `name` and `theme_type`.
- `has_theme_color_override(name: StringName) -> bool` *const* — Returns `true` if there is a local override for a theme Color with the specified `name` in this Control node.
- `has_theme_constant(name: StringName, theme_type: StringName = &"") -> bool` *const* — Returns `true` if there is a matching Theme in the tree that has a constant item with the specified `name` and `theme_type`.
- `has_theme_constant_override(name: StringName) -> bool` *const* — Returns `true` if there is a local override for a theme constant with the specified `name` in this Control node.
- `has_theme_font(name: StringName, theme_type: StringName = &"") -> bool` *const* — Returns `true` if there is a matching Theme in the tree that has a font item with the specified `name` and `theme_type`.
- `has_theme_font_override(name: StringName) -> bool` *const* — Returns `true` if there is a local override for a theme Font with the specified `name` in this Control node.
- `has_theme_font_size(name: StringName, theme_type: StringName = &"") -> bool` *const* — Returns `true` if there is a matching Theme in the tree that has a font size item with the specified `name` and `theme_type`.
- `has_theme_font_size_override(name: StringName) -> bool` *const* — Returns `true` if there is a local override for a theme font size with the specified `name` in this Control node.
- `has_theme_icon(name: StringName, theme_type: StringName = &"") -> bool` *const* — Returns `true` if there is a matching Theme in the tree that has an icon item with the specified `name` and `theme_type`.
- `has_theme_icon_override(name: StringName) -> bool` *const* — Returns `true` if there is a local override for a theme icon with the specified `name` in this Control node.
- `has_theme_sound(name: StringName, theme_type: StringName = &"") -> bool` *const* — Returns `true` if there is a matching Theme in the tree that has a sound item with the specified `name` and `theme_type`.
- `has_theme_sound_override(name: StringName) -> bool` *const* — Returns `true` if there is a local override for a theme sound with the specified `name` in this Control node.
- `has_theme_stylebox(name: StringName, theme_type: StringName = &"") -> bool` *const* — Returns `true` if there is a matching Theme in the tree that has a stylebox item with the specified `name` and `theme_type`.
- `has_theme_stylebox_override(name: StringName) -> bool` *const* — Returns `true` if there is a local override for a theme StyleBox with the specified `name` in this Control node.
- `hide() -> void` — Hides the window.
- `is_embedded() -> bool` *const* — Returns `true` if the window is currently embedded in another window.
- `is_layout_rtl() -> bool` *const* — Returns `true` if the layout is right-to-left.
- `is_maximize_allowed() -> bool` *const* — Returns `true` if the window can be maximized (the maximize button is enabled).
- `is_using_font_oversampling() -> bool` *const* — Returns `true` if font oversampling is enabled.
- `move_to_center() -> void` — Centers the window in the current screen.
- `move_to_foreground() -> void` *(deprecated)* — Causes the window to grab focus, allowing it to receive user input.
- `popup(rect: Rect2i = Rect2i(0, 0, 0, 0)) -> void` — Shows the Window and makes it transient (see `transient`).
- `popup_centered(minsize: Vector2i = Vector2i(0, 0)) -> void` — Popups the Window at the center of the current screen, with optionally given minimum size.
- `popup_centered_clamped(minsize: Vector2i = Vector2i(0, 0), fallback_ratio: float = 0.75) -> void` — Popups the Window centered inside its parent Window.
- `popup_centered_ratio(ratio: float = 0.8) -> void` — If Window is embedded, popups the Window centered inside its embedder and sets its size as a `ratio` of embedder's size.
- `popup_exclusive(from_node: Node, rect: Rect2i = Rect2i(0, 0, 0, 0)) -> void` — Attempts to parent this dialog to the last exclusive window relative to `from_node`, and then calls `Window.popup` on it.
- `popup_exclusive_centered(from_node: Node, minsize: Vector2i = Vector2i(0, 0)) -> void` — Attempts to parent this dialog to the last exclusive window relative to `from_node`, and then calls `Window.popup_centered` on it.
- `popup_exclusive_centered_clamped(from_node: Node, minsize: Vector2i = Vector2i(0, 0), fallback_ratio: float = 0.75) -> void` — Attempts to parent this dialog to the last exclusive window relative to `from_node`, and then calls `Window.popup_centered_clamped` on it.
- `popup_exclusive_centered_ratio(from_node: Node, ratio: float = 0.8) -> void` — Attempts to parent this dialog to the last exclusive window relative to `from_node`, and then calls `Window.popup_centered_ratio` on it.
- `popup_exclusive_on_parent(from_node: Node, parent_rect: Rect2i) -> void` — Attempts to parent this dialog to the last exclusive window relative to `from_node`, and then calls `Window.popup_on_parent` on it.
- `popup_on_parent(parent_rect: Rect2i) -> void` — Popups the Window with a position shifted by parent Window's position.
- `remove_theme_color_override(name: StringName) -> void` — Removes a local override for a theme Color with the specified `name` previously added by `add_theme_color_override` or via the Inspector dock.
- `remove_theme_constant_override(name: StringName) -> void` — Removes a local override for a theme constant with the specified `name` previously added by `add_theme_constant_override` or via the Inspector dock.
- `remove_theme_font_override(name: StringName) -> void` — Removes a local override for a theme Font with the specified `name` previously added by `add_theme_font_override` or via the Inspector dock.
- `remove_theme_font_size_override(name: StringName) -> void` — Removes a local override for a theme font size with the specified `name` previously added by `add_theme_font_size_override` or via the Inspector dock.
- `remove_theme_icon_override(name: StringName) -> void` — Removes a local override for a theme icon with the specified `name` previously added by `add_theme_icon_override` or via the Inspector dock.
- `remove_theme_sound_override(name: StringName) -> void` — Removes a local override for a theme sound with the specified `name` previously added by `add_theme_sound_override` or via the Inspector dock.
- `remove_theme_stylebox_override(name: StringName) -> void` — Removes a local override for a theme StyleBox with the specified `name` previously added by `add_theme_stylebox_override` or via the Inspector dock.
- `request_attention() -> void` — Tells the OS that the Window needs an attention.
- `reset_size() -> void` — Resets the size to the minimum size, which is the max of `min_size` and (if `wrap_controls` is enabled) `get_contents_minimum_size`.
- `set_flag(flag: Window.Flags, enabled: bool) -> void` — Sets a specified window flag.
- `set_ime_active(active: bool) -> void` — If `active` is `true`, enables system's native IME (Input Method Editor).
- `set_ime_position(position: Vector2i) -> void` — Moves IME to the given position.
- `set_layout_direction(direction: Window.LayoutDirection) -> void` — Sets layout direction and text writing direction.
- `set_taskbar_progress_state(state: DisplayServer.ProgressState) -> void` — Sets the type and state of the progress bar on the taskbar/dock icon of the Window.
- `set_taskbar_progress_value(value: float) -> void` — Creates a progress bar on the taskbar/dock icon of the Window if it does not exist, sets the progress of the icon.
- `set_unparent_when_invisible(unparent: bool) -> void` — If `unparent` is `true`, the window is automatically unparented when going invisible.
- `set_use_font_oversampling(enable: bool) -> void` — Enables font oversampling.
- `show() -> void` — Makes the Window appear.
- `start_drag() -> void` — Starts an interactive drag operation on the window, using the current mouse position.
- `start_resize(edge: DisplayServer.WindowResizeEdge) -> void` — Starts an interactive resize operation on the window, using the current mouse position.

## Signals

- `about_to_popup()` — Emitted right after `popup` call, before the Window appears or does anything.
- `close_requested()` — Emitted when the Window's close button is pressed or when `popup_window` is enabled and user clicks outside the window.
- `dpi_changed()` — Emitted when the Window's DPI changes as a result of OS-level changes (e.g. moving the window from a Retina display to a lower resolution one).
- `files_dropped(files: PackedStringArray)` — Emitted when files are dragged from the OS file manager and dropped in the game window.
- `focus_entered()` — Emitted when the Window gains focus.
- `focus_exited()` — Emitted when the Window loses its focus.
- `go_back_requested()` — Emitted when a go back request is sent (e.g. pressing the "Back" button on Android), right after `Node.NOTIFICATION_WM_GO_BACK_REQUEST`.
- `mouse_entered()` — Emitted when the mouse cursor enters the Window's visible area, that is not occluded behind other Controls or windows, provided its `Viewport.gui_disable_input` is `false` and regardless if it's currently focused or not.
- `mouse_exited()` — Emitted when the mouse cursor leaves the Window's visible area, that is not occluded behind other Controls or windows, provided its `Viewport.gui_disable_input` is `false` and regardless if it's currently focused or not.
- `nonclient_window_input(event: InputEvent)` — Emitted when the mouse event is received by the custom decoration area defined by `nonclient_area`, and normal input to the window is blocked (such as when it has an exclusive child opened).
- `output_max_linear_value_changed(output_max_linear_value: float)` — Emitted when the output max linear value returned by `Window.get_output_max_linear_value` has changed.
- `theme_changed()` — Emitted when the `NOTIFICATION_THEME_CHANGED` notification is sent.
- `title_changed()` — Emitted when window title bar text is changed.
- `titlebar_changed()` — Emitted when window title bar decorations are changed, e.g. macOS window enter/exit full screen mode, or extend-to-title flag is changed.
- `visibility_changed()` — Emitted when Window is made visible or disappears.
- `window_input(event: InputEvent)` — Emitted when the Window is currently focused and receives any input, passing the received event as an argument.

## Enum Mode

- `MODE_WINDOWED = 0` — Windowed mode, i.e.
- `MODE_MINIMIZED = 1` — Minimized window mode, i.e.
- `MODE_MAXIMIZED = 2` — Maximized window mode, i.e.
- `MODE_FULLSCREEN = 3` — Full screen mode with full multi-window support.
- `MODE_EXCLUSIVE_FULLSCREEN = 4` — A single window full screen mode.

## Enum Flags

- `FLAG_RESIZE_DISABLED = 0` — The window can't be resized by dragging its resize grip.
- `FLAG_BORDERLESS = 1` — The window do not have native title bar and other decorations.
- `FLAG_ALWAYS_ON_TOP = 2` — The window is floating on top of all other windows.
- `FLAG_TRANSPARENT = 3` — The window background can be transparent.
- `FLAG_NO_FOCUS = 4` — The window can't be focused.
- `FLAG_POPUP = 5` — Window is part of menu or OptionButton dropdown.
- `FLAG_EXTEND_TO_TITLE = 6` — Window content is expanded to the full size of the window.
- `FLAG_MOUSE_PASSTHROUGH = 7` — All mouse events are passed to the underlying window of the same application.
- `FLAG_SHARP_CORNERS = 8` — Window style is overridden, forcing sharp corners.
- `FLAG_EXCLUDE_FROM_CAPTURE = 9` — Windows is excluded from screenshots taken by `DisplayServer.screen_get_image`, `DisplayServer.screen_get_image_rect`, and `DisplayServer.screen_get_pixel`.
- `FLAG_POPUP_WM_HINT = 10` — Signals the window manager that this window is supposed to be an implementation-defined "popup" (usually a floating, borderless, untileable and immovable child window).
- `FLAG_MINIMIZE_DISABLED = 11` — Window minimize button is disabled.
- `FLAG_MAXIMIZE_DISABLED = 12` — Window maximize button is disabled.
- `FLAG_MAX = 13` — Max value of the `Flags`.

## Enum ContentScaleMode

- `CONTENT_SCALE_MODE_DISABLED = 0` — The content will not be scaled to match the Window's size (`content_scale_size` is ignored).
- `CONTENT_SCALE_MODE_CANVAS_ITEMS = 1` — The content will be rendered at the target size.
- `CONTENT_SCALE_MODE_VIEWPORT = 2` — The content will be rendered at the base size and then scaled to the target size.

## Enum ContentScaleAspect

- `CONTENT_SCALE_ASPECT_IGNORE = 0` — The aspect will be ignored.
- `CONTENT_SCALE_ASPECT_KEEP = 1` — The content's aspect will be preserved.
- `CONTENT_SCALE_ASPECT_KEEP_WIDTH = 2` — The content can be expanded vertically.
- `CONTENT_SCALE_ASPECT_KEEP_HEIGHT = 3` — The content can be expanded horizontally.
- `CONTENT_SCALE_ASPECT_EXPAND = 4` — The content's aspect will be preserved.

## Enum ContentScaleStretch

- `CONTENT_SCALE_STRETCH_FRACTIONAL = 0` — The content will be stretched according to a fractional factor.
- `CONTENT_SCALE_STRETCH_INTEGER = 1` — The content will be stretched only according to an integer factor, preserving sharp pixels.

## Enum LayoutDirection

- `LAYOUT_DIRECTION_INHERITED = 0` — Automatic layout direction, determined from the parent window layout direction.
- `LAYOUT_DIRECTION_APPLICATION_LOCALE = 1` — Automatic layout direction, determined from the current locale.
- `LAYOUT_DIRECTION_LTR = 2` — Left-to-right layout direction.
- `LAYOUT_DIRECTION_RTL = 3` — Right-to-left layout direction.
- `LAYOUT_DIRECTION_SYSTEM_LOCALE = 4` — Automatic layout direction, determined from the system locale.
- `LAYOUT_DIRECTION_MAX = 5` — Represents the size of the `LayoutDirection` enum.
- `LAYOUT_DIRECTION_LOCALE = 1` — 

## Enum WindowInitialPosition

- `WINDOW_INITIAL_POSITION_ABSOLUTE = 0` — Initial window position is determined by `position`.
- `WINDOW_INITIAL_POSITION_CENTER_PRIMARY_SCREEN = 1` — Initial window position is the center of the primary screen.
- `WINDOW_INITIAL_POSITION_CENTER_MAIN_WINDOW_SCREEN = 2` — Initial window position is the center of the main window screen.
- `WINDOW_INITIAL_POSITION_CENTER_OTHER_SCREEN = 3` — Initial window position is the center of `current_screen` screen.
- `WINDOW_INITIAL_POSITION_CENTER_SCREEN_WITH_MOUSE_FOCUS = 4` — Initial window position is the center of the screen containing the mouse pointer.
- `WINDOW_INITIAL_POSITION_CENTER_SCREEN_WITH_KEYBOARD_FOCUS = 5` — Initial window position is the center of the screen containing the window with the keyboard focus.

## Constants

- `NOTIFICATION_VISIBILITY_CHANGED = 30` — Emitted when Window's visibility changes, right before `visibility_changed`.
- `NOTIFICATION_THEME_CHANGED = 32` — Sent when the node needs to refresh its theme items.

## Theme items

- `title_color: Color` (color) = `Color(0.875, 0.875, 0.875, 1)`
- `title_outline_modulate: Color` (color) = `Color(0, 0, 0, 1)`
- `close_h_offset: int` (constant) = `18`
- `close_v_offset: int` (constant) = `24`
- `resize_margin: int` (constant) = `4`
- `title_height: int` (constant) = `36`
- `title_outline_size: int` (constant) = `0`
- `title_font: Font` (font)
- `title_font_size: int` (font_size)
- `close: Texture2D` (icon)
- `close_pressed: Texture2D` (icon)
- `embedded_border: StyleBox` (style)
- `embedded_unfocused_border: StyleBox` (style)
