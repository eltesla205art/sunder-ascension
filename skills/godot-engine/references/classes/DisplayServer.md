# DisplayServer

**Inherits:** Object

A server interface for low-level window management.

DisplayServer handles everything related to window management. It is separated from OS as a single operating system may support multiple display servers. Headless mode: Starting the engine with the `--headless` command line argument disables all rendering and window management functions. Most functions from DisplayServer will return dummy values in this case.

## Methods

- `accessibility_create_element(window_id: int, role: DisplayServer.AccessibilityRole) -> RID` *(deprecated)* — Creates a new, empty accessibility element resource.
- `accessibility_create_sub_element(parent_rid: RID, role: DisplayServer.AccessibilityRole, insert_pos: int = -1) -> RID` *(deprecated)* — Creates a new, empty accessibility sub-element resource.
- `accessibility_create_sub_text_edit_elements(parent_rid: RID, shaped_text: RID, min_height: float, insert_pos: int = -1, is_last_line: bool = false) -> RID` *(deprecated)* — Creates a new, empty accessibility sub-element from the shaped text buffer.
- `accessibility_element_get_meta(id: RID) -> Variant` *const* *(deprecated)* — Returns the metadata of the accessibility element `id`.
- `accessibility_element_set_meta(id: RID, meta: Variant) -> void` *(deprecated)* — Sets the metadata of the accessibility element `id` to `meta`.
- `accessibility_free_element(id: RID) -> void` *(deprecated)* — Frees the accessibility element `id` created by `accessibility_create_element`, `accessibility_create_sub_element`, or `accessibility_create_sub_text_edit_elements`.
- `accessibility_get_window_root(window_id: int) -> RID` *const* *(deprecated)* — Returns the main accessibility element of the OS native window.
- `accessibility_has_element(id: RID) -> bool` *const* *(deprecated)* — Returns `true` if `id` is a valid accessibility element.
- `accessibility_screen_reader_active() -> int` *const* — Returns `1` if a screen reader, Braille display or other assistive app is active, `0` otherwise.
- `accessibility_set_window_focused(window_id: int, focused: bool) -> void` *(deprecated)* — Sets the window focused state for assistive apps.
- `accessibility_set_window_rect(window_id: int, rect_out: Rect2, rect_in: Rect2) -> void` *(deprecated)* — Sets window outer (with decorations) and inner (without decorations) bounds for assistive apps.
- `accessibility_should_increase_contrast() -> int` *const* — Returns `1` if a high-contrast user interface theme should be used, `0` otherwise.
- `accessibility_should_reduce_animation() -> int` *const* — Returns `1` if flashing, blinking, and other moving content that can cause seizures in users with photosensitive epilepsy should be disabled, `0` otherwise.
- `accessibility_should_reduce_transparency() -> int` *const* — Returns `1` if background images, transparency, and other features that can reduce the contrast between the foreground and background should be disabled, `0` otherwise.
- `accessibility_update_add_action(id: RID, action: DisplayServer.AccessibilityAction, callable: Callable) -> void` *(deprecated)* — Adds a callback for the accessibility action (action which can be performed by using a special screen reader command or buttons on the Braille display), and marks this action as supported.
- `accessibility_update_add_child(id: RID, child_id: RID) -> void` *(deprecated)* — Adds a child accessibility element.
- `accessibility_update_add_custom_action(id: RID, action_id: int, action_description: String) -> void` *(deprecated)* — Adds support for a custom accessibility action.
- `accessibility_update_add_related_controls(id: RID, related_id: RID) -> void` *(deprecated)* — Adds an element that is controlled by this element.
- `accessibility_update_add_related_described_by(id: RID, related_id: RID) -> void` *(deprecated)* — Adds an element that describes this element.
- `accessibility_update_add_related_details(id: RID, related_id: RID) -> void` *(deprecated)* — Adds an element that details this element.
- `accessibility_update_add_related_flow_to(id: RID, related_id: RID) -> void` *(deprecated)* — Adds an element that this element flow into.
- `accessibility_update_add_related_labeled_by(id: RID, related_id: RID) -> void` *(deprecated)* — Adds an element that labels this element.
- `accessibility_update_add_related_radio_group(id: RID, related_id: RID) -> void` *(deprecated)* — Adds an element that is part of the same radio group.
- `accessibility_update_set_active_descendant(id: RID, other_id: RID) -> void` *(deprecated)* — Adds an element that is an active descendant of this element.
- `accessibility_update_set_background_color(id: RID, color: Color) -> void` *(deprecated)* — Sets element background color.
- `accessibility_update_set_bounds(id: RID, rect: Rect2) -> void` *(deprecated)* — Sets element bounding box, relative to the node position.
- `accessibility_update_set_checked(id: RID, checekd: bool) -> void` *(deprecated)* — Sets element checked state.
- `accessibility_update_set_classname(id: RID, classname: String) -> void` *(deprecated)* — Sets element class name.
- `accessibility_update_set_color_value(id: RID, color: Color) -> void` *(deprecated)* — Sets element color value.
- `accessibility_update_set_description(id: RID, description: String) -> void` *(deprecated)* — Sets element accessibility description.
- `accessibility_update_set_error_message(id: RID, other_id: RID) -> void` *(deprecated)* — Sets an element which contains an error message for this element.
- `accessibility_update_set_extra_info(id: RID, name: String) -> void` *(deprecated)* — Sets element accessibility extra information added to the element name.
- `accessibility_update_set_flag(id: RID, flag: DisplayServer.AccessibilityFlags, value: bool) -> void` *(deprecated)* — Sets element flag.
- `accessibility_update_set_focus(id: RID) -> void` *(deprecated)* — Sets currently focused element.
- `accessibility_update_set_foreground_color(id: RID, color: Color) -> void` *(deprecated)* — Sets element foreground color.
- `accessibility_update_set_in_page_link_target(id: RID, other_id: RID) -> void` *(deprecated)* — Sets target element for the link.
- `accessibility_update_set_language(id: RID, language: String) -> void` *(deprecated)* — Sets element text language.
- `accessibility_update_set_list_item_count(id: RID, size: int) -> void` *(deprecated)* — Sets number of items in the list.
- `accessibility_update_set_list_item_expanded(id: RID, expanded: bool) -> void` *(deprecated)* — Sets list/tree item expanded status.
- `accessibility_update_set_list_item_index(id: RID, index: int) -> void` *(deprecated)* — Sets the position of the element in the list.
- `accessibility_update_set_list_item_level(id: RID, level: int) -> void` *(deprecated)* — Sets the hierarchical level of the element in the list.
- `accessibility_update_set_list_item_selected(id: RID, selected: bool) -> void` *(deprecated)* — Sets list/tree item selected status.
- `accessibility_update_set_list_orientation(id: RID, vertical: bool) -> void` *(deprecated)* — Sets the orientation of the list elements.
- `accessibility_update_set_live(id: RID, live: DisplayServer.AccessibilityLiveMode) -> void` *(deprecated)* — Sets the priority of the live region updates.
- `accessibility_update_set_member_of(id: RID, group_id: RID) -> void` *(deprecated)* — Sets the element to be a member of the group.
- `accessibility_update_set_name(id: RID, name: String) -> void` *(deprecated)* — Sets element accessibility name.
- `accessibility_update_set_next_on_line(id: RID, other_id: RID) -> void` *(deprecated)* — Sets next element on the line.
- `accessibility_update_set_num_jump(id: RID, jump: float) -> void` *(deprecated)* — Sets numeric value jump.
- `accessibility_update_set_num_range(id: RID, min: float, max: float) -> void` *(deprecated)* — Sets numeric value range.
- `accessibility_update_set_num_step(id: RID, step: float) -> void` *(deprecated)* — Sets numeric value step.
- `accessibility_update_set_num_value(id: RID, position: float) -> void` *(deprecated)* — Sets numeric value.
- `accessibility_update_set_placeholder(id: RID, placeholder: String) -> void` *(deprecated)* — Sets placeholder text.
- `accessibility_update_set_popup_type(id: RID, popup: DisplayServer.AccessibilityPopupType) -> void` *(deprecated)* — Sets popup type for popup buttons.
- `accessibility_update_set_previous_on_line(id: RID, other_id: RID) -> void` *(deprecated)* — Sets previous element on the line.
- `accessibility_update_set_role(id: RID, role: DisplayServer.AccessibilityRole) -> void` *(deprecated)* — Sets element accessibility role.
- `accessibility_update_set_role_description(id: RID, description: String) -> void` *(deprecated)* — Sets element accessibility role description text.
- `accessibility_update_set_scroll_x(id: RID, position: float) -> void` *(deprecated)* — Sets scroll bar x position.
- `accessibility_update_set_scroll_x_range(id: RID, min: float, max: float) -> void` *(deprecated)* — Sets scroll bar x range.
- `accessibility_update_set_scroll_y(id: RID, position: float) -> void` *(deprecated)* — Sets scroll bar y position.
- `accessibility_update_set_scroll_y_range(id: RID, min: float, max: float) -> void` *(deprecated)* — Sets scroll bar y range.
- `accessibility_update_set_shortcut(id: RID, shortcut: String) -> void` *(deprecated)* — Sets the list of keyboard shortcuts used by element.
- `accessibility_update_set_state_description(id: RID, description: String) -> void` *(deprecated)* — Sets human-readable description of the current checked state.
- `accessibility_update_set_table_cell_position(id: RID, row_index: int, column_index: int) -> void` *(deprecated)* — Sets cell position in the table.
- `accessibility_update_set_table_cell_span(id: RID, row_span: int, column_span: int) -> void` *(deprecated)* — Sets cell row/column span.
- `accessibility_update_set_table_column_count(id: RID, count: int) -> void` *(deprecated)* — Sets number of columns in the table.
- `accessibility_update_set_table_column_index(id: RID, index: int) -> void` *(deprecated)* — Sets position of the column.
- `accessibility_update_set_table_row_count(id: RID, count: int) -> void` *(deprecated)* — Sets number of rows in the table.
- `accessibility_update_set_table_row_index(id: RID, index: int) -> void` *(deprecated)* — Sets position of the row in the table.
- `accessibility_update_set_text_align(id: RID, align: HorizontalAlignment) -> void` *(deprecated)* — Sets element text alignment.
- `accessibility_update_set_text_decorations(id: RID, underline: bool, strikethrough: bool, overline: bool) -> void` *(deprecated)* — Sets text underline/overline/strikethrough.
- `accessibility_update_set_text_orientation(id: RID, vertical: bool) -> void` *(deprecated)* — Sets text orientation.
- `accessibility_update_set_text_selection(id: RID, text_start_id: RID, start_char: int, text_end_id: RID, end_char: int) -> void` *(deprecated)* — Sets text selection to the text field.
- `accessibility_update_set_tooltip(id: RID, tooltip: String) -> void` *(deprecated)* — Sets tooltip text.
- `accessibility_update_set_transform(id: RID, transform: Transform2D) -> void` *(deprecated)* — Sets element 2D transform.
- `accessibility_update_set_url(id: RID, url: String) -> void` *(deprecated)* — Sets link URL.
- `accessibility_update_set_value(id: RID, value: String) -> void` *(deprecated)* — Sets element text value.
- `beep() -> void` *const* — Plays the beep sound from the operative system, if possible.
- `clipboard_get() -> String` *const* — Returns the user's clipboard as a string if possible.
- `clipboard_get_image() -> Image` *const* — Returns the user's clipboard as an image if possible.
- `clipboard_get_primary() -> String` *const* — Returns the user's primary clipboard as a string if possible.
- `clipboard_has() -> bool` *const* — Returns `true` if there is a text content on the user's clipboard.
- `clipboard_has_image() -> bool` *const* — Returns `true` if there is an image content on the user's clipboard.
- `clipboard_set(clipboard: String) -> void` — Sets the user's clipboard content to the given string.
- `clipboard_set_primary(clipboard_primary: String) -> void` — Sets the user's primary clipboard content to the given string.
- `color_picker(callback: Callable) -> bool` — Displays OS native color picker.
- `create_status_indicator(icon: Texture2D, tooltip: String, callback: Callable) -> int` — Creates a new application status indicator with the specified icon, tooltip, and activation callback.
- `cursor_get_shape() -> int[DisplayServer.CursorShape]` *const* — Returns the default mouse cursor shape set by `cursor_set_shape`.
- `cursor_set_custom_image(cursor: Resource, shape: DisplayServer.CursorShape = 0, hotspot: Vector2 = Vector2(0, 0)) -> void` — Sets a custom mouse cursor image for the given `shape`.
- `cursor_set_shape(shape: DisplayServer.CursorShape) -> void` — Sets the default mouse cursor shape.
- `delete_status_indicator(id: int) -> void` — Removes the application status indicator.
- `dialog_input_text(title: String, description: String, existing_text: String, callback: Callable) -> int[Error]` — Shows a text input dialog which uses the operating system's native look-and-feel.
- `dialog_show(title: String, description: String, buttons: PackedStringArray, callback: Callable) -> int[Error]` — Shows a text dialog which uses the operating system's native look-and-feel.
- `enable_for_stealing_focus(process_id: int) -> void` — Allows the `process_id` PID to steal focus from this window.
- `file_dialog_show(title: String, current_directory: String, filename: String, show_hidden: bool, mode: DisplayServer.FileDialogMode, filters: PackedStringArray, callback: Callable, parent_window_id: int = 0) -> int[Error]` — Displays OS native dialog for selecting files or directories in the file system.
- `file_dialog_with_options_show(title: String, current_directory: String, root: String, filename: String, show_hidden: bool, mode: DisplayServer.FileDialogMode, filters: PackedStringArray, options: Dictionary[], callback: Callable, parent_window_id: int = 0) -> int[Error]` — Displays OS native dialog for selecting files or directories in the file system with additional user selectable options.
- `force_process_and_drop_events() -> void` — Forces window manager processing while ignoring all InputEvents.
- `get_accent_color() -> Color` *const* — Returns OS theme accent color.
- `get_base_color() -> Color` *const* — Returns the OS theme base color (default control background).
- `get_display_cutouts(screen: int = -1) -> Rect2[]` *const* — Returns an Array of Rect2, each of which is the bounding rectangle for a display cutout or notch.
- `get_display_safe_area(screen: int = -1) -> Rect2i` *const* — Returns the unobscured area of the display where interactive controls should be rendered.
- `get_keyboard_focus_screen() -> int` *const* — Returns the index of the screen containing the window with the keyboard focus, or the primary screen if there's no focused window.
- `get_name() -> String` *const* — Returns the name of the DisplayServer currently in use.
- `get_primary_screen() -> int` *const* — Returns the index of the primary screen.
- `get_screen_count() -> int` *const* — Returns the number of displays available.
- `get_screen_from_rect(rect: Rect2) -> int` *const* — Returns the index of the screen that overlaps the most with the given rectangle.
- `get_swap_cancel_ok() -> bool` — Returns `true` if positions of OK and Cancel buttons are swapped in dialogs.
- `get_window_at_screen_position(position: Vector2i) -> int` *const* — Returns the ID of the window at the specified screen `position` (in pixels).
- `get_window_list() -> PackedInt32Array` *const* — Returns the list of Godot window IDs belonging to this process.
- `global_menu_add_check_item(menu_root: String, label: String, callback: Callable = Callable(), key_callback: Callable = Callable(), tag: Variant = null, accelerator: Key = 0, index: int = -1) -> int` *(deprecated)* — Adds a new checkable item with text `label` to the global menu with ID `menu_root`.
- `global_menu_add_icon_check_item(menu_root: String, icon: Texture2D, label: String, callback: Callable = Callable(), key_callback: Callable = Callable(), tag: Variant = null, accelerator: Key = 0, index: int = -1) -> int` *(deprecated)* — Adds a new checkable item with text `label` and icon `icon` to the global menu with ID `menu_root`.
- `global_menu_add_icon_item(menu_root: String, icon: Texture2D, label: String, callback: Callable = Callable(), key_callback: Callable = Callable(), tag: Variant = null, accelerator: Key = 0, index: int = -1) -> int` *(deprecated)* — Adds a new item with text `label` and icon `icon` to the global menu with ID `menu_root`.
- `global_menu_add_icon_radio_check_item(menu_root: String, icon: Texture2D, label: String, callback: Callable = Callable(), key_callback: Callable = Callable(), tag: Variant = null, accelerator: Key = 0, index: int = -1) -> int` *(deprecated)* — Adds a new radio-checkable item with text `label` and icon `icon` to the global menu with ID `menu_root`.
- `global_menu_add_item(menu_root: String, label: String, callback: Callable = Callable(), key_callback: Callable = Callable(), tag: Variant = null, accelerator: Key = 0, index: int = -1) -> int` *(deprecated)* — Adds a new item with text `label` to the global menu with ID `menu_root`.
- `global_menu_add_multistate_item(menu_root: String, label: String, max_states: int, default_state: int, callback: Callable = Callable(), key_callback: Callable = Callable(), tag: Variant = null, accelerator: Key = 0, index: int = -1) -> int` *(deprecated)* — Adds a new item with text `label` to the global menu with ID `menu_root`.
- `global_menu_add_radio_check_item(menu_root: String, label: String, callback: Callable = Callable(), key_callback: Callable = Callable(), tag: Variant = null, accelerator: Key = 0, index: int = -1) -> int` *(deprecated)* — Adds a new radio-checkable item with text `label` to the global menu with ID `menu_root`.
- `global_menu_add_separator(menu_root: String, index: int = -1) -> int` *(deprecated)* — Adds a separator between items to the global menu with ID `menu_root`.
- `global_menu_add_submenu_item(menu_root: String, label: String, submenu: String, index: int = -1) -> int` *(deprecated)* — Adds an item that will act as a submenu of the global menu `menu_root`.
- `global_menu_clear(menu_root: String) -> void` *(deprecated)* — Removes all items from the global menu with ID `menu_root`.
- `global_menu_get_item_accelerator(menu_root: String, idx: int) -> int[Key]` *const* *(deprecated)* — Returns the accelerator of the item at index `idx`.
- `global_menu_get_item_callback(menu_root: String, idx: int) -> Callable` *const* *(deprecated)* — Returns the callback of the item at index `idx`.
- `global_menu_get_item_count(menu_root: String) -> int` *const* *(deprecated)* — Returns number of items in the global menu with ID `menu_root`.
- `global_menu_get_item_icon(menu_root: String, idx: int) -> Texture2D` *const* *(deprecated)* — Returns the icon of the item at index `idx`.
- `global_menu_get_item_indentation_level(menu_root: String, idx: int) -> int` *const* *(deprecated)* — Returns the horizontal offset of the item at the given `idx`.
- `global_menu_get_item_index_from_tag(menu_root: String, tag: Variant) -> int` *const* *(deprecated)* — Returns the index of the item with the specified `tag`.
- `global_menu_get_item_index_from_text(menu_root: String, text: String) -> int` *const* *(deprecated)* — Returns the index of the item with the specified `text`.
- `global_menu_get_item_key_callback(menu_root: String, idx: int) -> Callable` *const* *(deprecated)* — Returns the callback of the item accelerator at index `idx`.
- `global_menu_get_item_max_states(menu_root: String, idx: int) -> int` *const* *(deprecated)* — Returns number of states of a multistate item.
- `global_menu_get_item_state(menu_root: String, idx: int) -> int` *const* *(deprecated)* — Returns the state of a multistate item.
- `global_menu_get_item_submenu(menu_root: String, idx: int) -> String` *const* *(deprecated)* — Returns the submenu ID of the item at index `idx`.
- `global_menu_get_item_tag(menu_root: String, idx: int) -> Variant` *const* *(deprecated)* — Returns the metadata of the specified item, which might be of any type.
- `global_menu_get_item_text(menu_root: String, idx: int) -> String` *const* *(deprecated)* — Returns the text of the item at index `idx`.
- `global_menu_get_item_tooltip(menu_root: String, idx: int) -> String` *const* *(deprecated)* — Returns the tooltip associated with the specified index `idx`.
- `global_menu_get_system_menu_roots() -> Dictionary` *const* *(deprecated)* — Returns Dictionary of supported system menu IDs and names.
- `global_menu_is_item_checkable(menu_root: String, idx: int) -> bool` *const* *(deprecated)* — Returns `true` if the item at index `idx` is checkable in some way, i.e. if it has a checkbox or radio button.
- `global_menu_is_item_checked(menu_root: String, idx: int) -> bool` *const* *(deprecated)* — Returns `true` if the item at index `idx` is checked.
- `global_menu_is_item_disabled(menu_root: String, idx: int) -> bool` *const* *(deprecated)* — Returns `true` if the item at index `idx` is disabled.
- `global_menu_is_item_hidden(menu_root: String, idx: int) -> bool` *const* *(deprecated)* — Returns `true` if the item at index `idx` is hidden.
- `global_menu_is_item_radio_checkable(menu_root: String, idx: int) -> bool` *const* *(deprecated)* — Returns `true` if the item at index `idx` has radio button-style checkability.
- `global_menu_remove_item(menu_root: String, idx: int) -> void` *(deprecated)* — Removes the item at index `idx` from the global menu `menu_root`.
- `global_menu_set_item_accelerator(menu_root: String, idx: int, keycode: Key) -> void` *(deprecated)* — Sets the accelerator of the item at index `idx`.
- `global_menu_set_item_callback(menu_root: String, idx: int, callback: Callable) -> void` *(deprecated)* — Sets the callback of the item at index `idx`.
- `global_menu_set_item_checkable(menu_root: String, idx: int, checkable: bool) -> void` *(deprecated)* — Sets whether the item at index `idx` has a checkbox.
- `global_menu_set_item_checked(menu_root: String, idx: int, checked: bool) -> void` *(deprecated)* — Sets the checkstate status of the item at index `idx`.
- `global_menu_set_item_disabled(menu_root: String, idx: int, disabled: bool) -> void` *(deprecated)* — Enables/disables the item at index `idx`.
- `global_menu_set_item_hidden(menu_root: String, idx: int, hidden: bool) -> void` *(deprecated)* — Hides/shows the item at index `idx`.
- `global_menu_set_item_hover_callbacks(menu_root: String, idx: int, callback: Callable) -> void` *(deprecated)* — Sets the callback of the item at index `idx`.
- `global_menu_set_item_icon(menu_root: String, idx: int, icon: Texture2D) -> void` *(deprecated)* — Replaces the Texture2D icon of the specified `idx`.
- `global_menu_set_item_indentation_level(menu_root: String, idx: int, level: int) -> void` *(deprecated)* — Sets the horizontal offset of the item at the given `idx`.
- `global_menu_set_item_key_callback(menu_root: String, idx: int, key_callback: Callable) -> void` *(deprecated)* — Sets the callback of the item at index `idx`.
- `global_menu_set_item_max_states(menu_root: String, idx: int, max_states: int) -> void` *(deprecated)* — Sets number of state of a multistate item.
- `global_menu_set_item_radio_checkable(menu_root: String, idx: int, checkable: bool) -> void` *(deprecated)* — Sets the type of the item at the specified index `idx` to radio button.
- `global_menu_set_item_state(menu_root: String, idx: int, state: int) -> void` *(deprecated)* — Sets the state of a multistate item.
- `global_menu_set_item_submenu(menu_root: String, idx: int, submenu: String) -> void` *(deprecated)* — Sets the submenu of the item at index `idx`.
- `global_menu_set_item_tag(menu_root: String, idx: int, tag: Variant) -> void` *(deprecated)* — Sets the metadata of an item, which may be of any type.
- `global_menu_set_item_text(menu_root: String, idx: int, text: String) -> void` *(deprecated)* — Sets the text of the item at index `idx`.
- `global_menu_set_item_tooltip(menu_root: String, idx: int, tooltip: String) -> void` *(deprecated)* — Sets the String tooltip of the item at the specified index `idx`.
- `global_menu_set_popup_callbacks(menu_root: String, open_callback: Callable, close_callback: Callable) -> void` *(deprecated)* — Registers callables to emit when the menu is respectively about to show or closed.
- `has_additional_outputs() -> bool` *const* — Returns `true` if any additional outputs have been registered via `register_additional_output`.
- `has_feature(feature: DisplayServer.Feature) -> bool` *const* — Returns `true` if the specified `feature` is supported by the current DisplayServer, `false` otherwise.
- `has_hardware_keyboard() -> bool` *const* — Returns `true` if a hardware keyboard is connected.
- `help_set_search_callbacks(search_callback: Callable, action_callback: Callable) -> void` — Sets native help system search callbacks.
- `hide_toast_notification(id: int) -> void` — Hides the toast notification with `id` returned by `send_toast_notification`.
- `ime_get_selection() -> Vector2i` *const* — Returns the text selection in the Input Method Editor composition string, with the Vector2i's `x` component being the caret position and `y` being the length of the selection.
- `ime_get_text() -> String` *const* — Returns the composition string contained within the Input Method Editor window.
- `is_dark_mode() -> bool` *const* — Returns `true` if OS is using dark mode.
- `is_dark_mode_supported() -> bool` *const* — Returns `true` if OS supports dark mode.
- `is_in_pip_mode(window_id: int = 0) -> bool` — Returns `true` if the application is in picture-in-picture mode.
- `is_touchscreen_available() -> bool` *const* — Returns `true` if touch events are available (Android or iOS), the capability is detected on the Web platform or if `ProjectSettings.input_devices/pointing/emulate_touch_from_mouse` is `true`.
- `is_window_transparency_available() -> bool` *const* — Returns `true` if the window background can be made transparent.
- `keyboard_get_current_layout() -> int` *const* — Returns active keyboard layout index.
- `keyboard_get_keycode_from_physical(keycode: Key) -> int[Key]` *const* — Converts a physical (US QWERTY) `keycode` to one in the active keyboard layout.
- `keyboard_get_label_from_physical(keycode: Key) -> int[Key]` *const* — Converts a physical (US QWERTY) `keycode` to localized label printed on the key in the active keyboard layout.
- `keyboard_get_layout_count() -> int` *const* — Returns the number of keyboard layouts.
- `keyboard_get_layout_language(index: int) -> String` *const* — Returns the ISO-639/BCP-47 language code of the keyboard layout at position `index`.
- `keyboard_get_layout_name(index: int) -> String` *const* — Returns the localized name of the keyboard layout at position `index`.
- `keyboard_set_current_layout(index: int) -> void` — Sets the active keyboard layout.
- `mouse_get_button_state() -> int[MouseButtonMask]` *const* — Returns the current state of mouse buttons (whether each button is pressed) as a bitmask.
- `mouse_get_mode() -> int[DisplayServer.MouseMode]` *const* — Returns the current mouse mode.
- `mouse_get_position() -> Vector2i` *const* — Returns the mouse cursor's current position in screen coordinates.
- `mouse_set_mode(mouse_mode: DisplayServer.MouseMode) -> void` — Sets the current mouse mode.
- `pip_mode_enter(window_id: int = 0) -> void` — Enters picture-in-picture mode.
- `pip_mode_set_aspect_ratio(numerator: int, denominator: int, window_id: int = 0) -> void` — Specifies the aspect ratio for picture-in-picture mode.
- `pip_mode_set_auto_enter_on_background(auto_enter_on_background: bool, window_id: int = 0) -> void` — Specifies whether picture-in-picture mode should be entered automatically when the application goes in the background.
- `process_events() -> void` — Perform window manager processing, including input flushing.
- `register_additional_output(object: Object) -> void` — Registers an Object which represents an additional output that will be rendered too, beyond normal windows.
- `screen_get_dpi(screen: int = -1) -> int` *const* — Returns the dots per inch density of the specified screen.
- `screen_get_image(screen: int = -1) -> Image` *const* — Returns a screenshot of the `screen`.
- `screen_get_image_rect(rect: Rect2i) -> Image` *const* — Returns a screenshot of the screen region defined by `rect`.
- `screen_get_max_scale() -> float` *const* — Returns the greatest scale factor of all screens.
- `screen_get_orientation(screen: int = -1) -> int[DisplayServer.ScreenOrientation]` *const* — Returns the `screen`'s current orientation.
- `screen_get_pixel(position: Vector2i) -> Color` *const* — Returns the color of the pixel at the given screen `position`.
- `screen_get_position(screen: int = -1) -> Vector2i` *const* — Returns the screen's top-left corner position in pixels.
- `screen_get_refresh_rate(screen: int = -1) -> float` *const* — Returns the current refresh rate of the specified screen.
- `screen_get_scale(screen: int = -1) -> float` *const* — Returns the scale factor of the specified screen by index.
- `screen_get_size(screen: int = -1) -> Vector2i` *const* — Returns the screen's size in pixels.
- `screen_get_usable_rect(screen: int = -1) -> Rect2i` *const* — Returns the portion of the screen that is not obstructed by a status bar in pixels.
- `screen_is_kept_on() -> bool` *const* — Returns `true` if the screen should never be turned off by the operating system's power-saving measures.
- `screen_set_keep_on(enable: bool) -> void` — Sets whether the screen should never be turned off by the operating system's power-saving measures.
- `screen_set_orientation(orientation: DisplayServer.ScreenOrientation, screen: int = -1) -> void` — Sets the `screen`'s `orientation`.
- `send_toast_notification(title: String, text: String, image: Texture2D, callback: Callable) -> int` — Displays a toast notification with `title`, `text`, and optionally `image`.
- `set_hardware_keyboard_connection_change_callback(callable: Callable) -> void` — Sets the callback that should be called when a hardware keyboard is connected or disconnected.
- `set_icon(image: Image) -> void` — Sets the application icon and icons of all windows with an Image.
- `set_native_icon(filename: String) -> void` — Sets the window icon (usually displayed in the top-left corner) in the operating system's native format.
- `set_system_theme_change_callback(callable: Callable) -> void` — Sets the callback that should be called when the system's theme settings are changed.
- `show_emoji_and_symbol_picker() -> void` *const* — Opens system emoji and symbol picker.
- `status_indicator_get_rect(id: int) -> Rect2` *const* — Returns the rectangle for the given status indicator `id` in screen coordinates.
- `status_indicator_set_callback(id: int, callback: Callable) -> void` — Sets the application status indicator activation callback.
- `status_indicator_set_icon(id: int, icon: Texture2D) -> void` — Sets the application status indicator icon.
- `status_indicator_set_menu(id: int, menu_rid: RID) -> void` — Sets the application status indicator native popup menu.
- `status_indicator_set_tooltip(id: int, tooltip: String) -> void` — Sets the application status indicator tooltip.
- `tablet_get_current_driver() -> String` *const* — Returns current active tablet driver name.
- `tablet_get_driver_count() -> int` *const* — Returns the total number of available tablet drivers.
- `tablet_get_driver_name(idx: int) -> String` *const* — Returns the tablet driver name for the given index.
- `tablet_set_current_driver(name: String) -> void` — Set active tablet driver name.
- `tts_get_voices() -> Dictionary[]` *const* — Returns an Array of voice information dictionaries.
- `tts_get_voices_for_language(language: String) -> PackedStringArray` *const* — Returns a PackedStringArray of voice identifiers for the `language`.
- `tts_is_paused() -> bool` *const* — Returns `true` if the synthesizer is in a paused state.
- `tts_is_speaking() -> bool` *const* — Returns `true` if the synthesizer is generating speech, or have utterance waiting in the queue.
- `tts_pause() -> void` — Puts the synthesizer into a paused state.
- `tts_resume() -> void` — Resumes the synthesizer if it was paused.
- `tts_set_utterance_callback(event: DisplayServer.TTSUtteranceEvent, callable: Callable) -> void` — Adds a callback, which is called when the utterance has started, finished, canceled or reached a text boundary. - `TTS_UTTERANCE_STARTED`, `TTS_UTTERANCE_ENDED`, and `TTS_UTTERANCE_CANCELED` callable's method should take one int parameter, the utterance ID. - `TTS_UTTERANCE_BOUNDARY` callable's method should take two int parameters, the index of the character and the utterance ID.
- `tts_speak(text: String, voice: String, volume: int = 50, pitch: float = 1.0, rate: float = 1.0, utterance_id: int = 0, interrupt: bool = false) -> void` — Adds an utterance to the queue.
- `tts_stop() -> void` — Stops synthesis in progress and removes all utterances from the queue.
- `unregister_additional_output(object: Object) -> void` — Unregisters an Object representing an additional output, that was registered via `register_additional_output`.
- `virtual_keyboard_get_height() -> int` *const* — Returns the on-screen keyboard's height in pixels.
- `virtual_keyboard_hide() -> void` — Hides the virtual keyboard if it is shown, does nothing otherwise.
- `virtual_keyboard_show(existing_text: String, position: Rect2 = Rect2(0, 0, 0, 0), type: DisplayServer.VirtualKeyboardType = 0, max_length: int = -1, cursor_start: int = -1, cursor_end: int = -1) -> void` — Shows the virtual keyboard if the platform has one.
- `warp_mouse(position: Vector2i) -> void` — Sets the mouse cursor position to the given `position` relative to an origin at the upper left corner of the currently focused game Window Manager window.
- `window_can_draw(window_id: int = 0) -> bool` *const* — Returns `true` if anything can be drawn in the window specified by `window_id`, `false` otherwise.
- `window_get_active_popup() -> int` *const* — Returns ID of the active popup window, or `INVALID_WINDOW_ID` if there is none.
- `window_get_attached_instance_id(window_id: int = 0) -> int` *const* — Returns the `Object.get_instance_id` of the Window the `window_id` is attached to.
- `window_get_current_screen(window_id: int = 0) -> int` *const* — Returns the screen the window specified by `window_id` is currently positioned on.
- `window_get_flag(flag: DisplayServer.WindowFlags, window_id: int = 0) -> bool` *const* — Returns the current value of the given window's `flag`.
- `window_get_hdr_output_current_max_luminance(window_id: int = 0) -> float` *const* — When `window_is_hdr_output_enabled` returns `true`, this returns the current maximum luminance in nits (cd/m²) for HDR output by the window specified by `window_id`.
- `window_get_hdr_output_current_reference_luminance(window_id: int = 0) -> float` *const* — When `window_is_hdr_output_enabled` returns `true`, this returns the current reference white luminance in nits (cd/m²) for HDR output by the window specified by `window_id`.
- `window_get_hdr_output_max_luminance(window_id: int = 0) -> float` *const* — Returns the maximum luminance in nits (cd/m²) set for HDR output by the window specified by `window_id`.
- `window_get_hdr_output_reference_luminance(window_id: int = 0) -> float` *const* — Returns the reference white luminance in nits (cd/m²) set for HDR output by the window specified by `window_id`.
- `window_get_max_size(window_id: int = 0) -> Vector2i` *const* — Returns the window's maximum size (in pixels).
- `window_get_min_size(window_id: int = 0) -> Vector2i` *const* — Returns the window's minimum size (in pixels).
- `window_get_mode(window_id: int = 0) -> int[DisplayServer.WindowMode]` *const* — Returns the mode of the given window.
- `window_get_native_handle(handle_type: DisplayServer.HandleType, window_id: int = 0) -> int` *const* — Returns internal structure pointers for use in plugins.
- `window_get_output_max_linear_value(window_id: int = 0) -> float` *const* — Returns the maximum value for linear color components that can be displayed for the window specified by `window_id`, regardless of SDR or HDR output.
- `window_get_popup_safe_rect(window: int) -> Rect2i` *const* — Returns the bounding box of control, or menu item that was used to open the popup window, in the screen coordinate system.
- `window_get_position(window_id: int = 0) -> Vector2i` *const* — Returns the position of the client area of the given window on the screen.
- `window_get_position_with_decorations(window_id: int = 0) -> Vector2i` *const* — Returns the position of the given window on the screen including the borders drawn by the operating system.
- `window_get_safe_title_margins(window_id: int = 0) -> Vector3i` *const* — Returns left margins (`x`), right margins (`y`) and height (`z`) of the title that are safe to use (contains no buttons or other elements) when `WINDOW_FLAG_EXTEND_TO_TITLE` flag is set.
- `window_get_size(window_id: int = 0) -> Vector2i` *const* — Returns the size of the window specified by `window_id` (in pixels), excluding the borders drawn by the operating system.
- `window_get_size_with_decorations(window_id: int = 0) -> Vector2i` *const* — Returns the size of the window specified by `window_id` (in pixels), including the borders drawn by the operating system.
- `window_get_title_size(title: String, window_id: int = 0) -> Vector2i` *const* — Returns the estimated window title bar size (including text and window buttons) for the window specified by `window_id` (in pixels).
- `window_get_vsync_mode(window_id: int = 0) -> int[DisplayServer.VSyncMode]` *const* — Returns the V-Sync mode of the given window.
- `window_is_focused(window_id: int = 0) -> bool` *const* — Returns `true` if the window specified by `window_id` is focused.
- `window_is_hdr_output_enabled(window_id: int = 0) -> bool` *const* — Returns `true` if HDR output is currently enabled for the window specified by `window_id`.
- `window_is_hdr_output_requested(window_id: int = 0) -> bool` *const* — Returns `true` if HDR output is requested for the window specified by `window_id`.
- `window_is_hdr_output_supported(window_id: int = 0) -> bool` *const* — Returns `true` if the window specified by `window_id` supports HDR output.
- `window_is_maximize_allowed(window_id: int = 0) -> bool` *const* — Returns `true` if the given window can be maximized (the maximize button is enabled).
- `window_maximize_on_title_dbl_click() -> bool` *const* — Returns `true` if double-clicking on a window's title should maximize it.
- `window_minimize_on_title_dbl_click() -> bool` *const* — Returns `true` if double-clicking on a window's title should minimize it.
- `window_move_to_foreground(window_id: int = 0) -> void` — Moves the window specified by `window_id` to the foreground, so that it is visible over other windows.
- `window_request_attention(window_id: int = 0) -> void` — Makes the window specified by `window_id` request attention, which is materialized by the window title and taskbar entry blinking until the window is focused.
- `window_request_hdr_output(enable: bool, window_id: int = 0) -> void` — If `enable` is `true`, HDR output is requested for the window specified by `window_id`.
- `window_set_color(color: Color) -> void` — Sets the background color of the root window.
- `window_set_current_screen(screen: int, window_id: int = 0) -> void` — Moves the window specified by `window_id` to the specified `screen`.
- `window_set_drop_files_callback(callback: Callable, window_id: int = 0) -> void` — Sets the `callback` that should be called when files are dropped from the operating system's file manager to the window specified by `window_id`.
- `window_set_exclusive(window_id: int, exclusive: bool) -> void` — If set to `true`, this window will always stay on top of its parent window, parent window will ignore input while this window is opened.
- `window_set_flag(flag: DisplayServer.WindowFlags, enabled: bool, window_id: int = 0) -> void` — Enables or disables the given window's given `flag`.
- `window_set_hdr_output_max_luminance(max_luminance: float, window_id: int = 0) -> void` — Sets the maximum luminance in nits (cd/m²) for HDR output by the window specified by `window_id`.
- `window_set_hdr_output_reference_luminance(reference_luminance: float, window_id: int = 0) -> void` — Sets the reference white luminance in nits (cd/m²) for HDR output by the window specified by `window_id`.
- `window_set_icon(icon: Image, window_id: int = 0) -> void` — Sets the window icon (usually displayed in the top-left corner) for the window specified by `window_id`.
- `window_set_ime_active(active: bool, window_id: int = 0) -> void` — Sets whether Input Method Editor should be enabled for the window specified by `window_id`.
- `window_set_ime_position(position: Vector2i, window_id: int = 0) -> void` — Sets the position of the Input Method Editor popup for the specified `window_id`.
- `window_set_input_event_callback(callback: Callable, window_id: int = 0) -> void` — Sets the `callback` that should be called when any InputEvent is sent to the window specified by `window_id`.
- `window_set_input_text_callback(callback: Callable, window_id: int = 0) -> void` — Sets the `callback` that should be called when text is entered using the virtual keyboard to the window specified by `window_id`.
- `window_set_max_size(max_size: Vector2i, window_id: int = 0) -> void` — Sets the maximum size of the window specified by `window_id` in pixels.
- `window_set_min_size(min_size: Vector2i, window_id: int = 0) -> void` — Sets the minimum size for the given window to `min_size` in pixels.
- `window_set_mode(mode: DisplayServer.WindowMode, window_id: int = 0) -> void` — Sets window mode for the given window to `mode`.
- `window_set_mouse_passthrough(region: PackedVector2Array, window_id: int = 0) -> void` — Sets a polygonal region of the window which accepts mouse events.
- `window_set_popup_safe_rect(window: int, rect: Rect2i) -> void` — Sets the bounding box of control, or menu item that was used to open the popup window, in the screen coordinate system.
- `window_set_position(position: Vector2i, window_id: int = 0) -> void` — Sets the position of the given window to `position`.
- `window_set_rect_changed_callback(callback: Callable, window_id: int = 0) -> void` — Sets the `callback` that will be called when the window specified by `window_id` is moved or resized.
- `window_set_size(size: Vector2i, window_id: int = 0) -> void` — Sets the size of the given window to `size` (in pixels).
- `window_set_taskbar_progress_state(state: DisplayServer.ProgressState, window_id: int = 0) -> void` — Sets the type and state of the progress bar on the taskbar/dock icon of the window specified by `window_id`.
- `window_set_taskbar_progress_value(value: float, window_id: int = 0) -> void` — Creates a progress bar on the taskbar/dock icon of the window specified by `window_id` if it does not exist, sets the progress of the icon.
- `window_set_title(title: String, window_id: int = 0) -> void` — Sets the title of the given window to `title`.
- `window_set_transient(window_id: int, parent_window_id: int) -> void` — Sets window transient parent.
- `window_set_vsync_mode(vsync_mode: DisplayServer.VSyncMode, window_id: int = 0) -> void` — Sets the V-Sync mode of the given window.
- `window_set_window_buttons_offset(offset: Vector2i, window_id: int = 0) -> void` — When `WINDOW_FLAG_EXTEND_TO_TITLE` flag is set, set offset to the center of the first titlebar button.
- `window_set_window_event_callback(callback: Callable, window_id: int = 0) -> void` — Sets the `callback` that will be called when an event occurs in the window specified by `window_id`.
- `window_start_drag(window_id: int = 0) -> void` — Starts an interactive drag operation on the window with the given `window_id`, using the current mouse position.
- `window_start_resize(edge: DisplayServer.WindowResizeEdge, window_id: int = 0) -> void` — Starts an interactive resize operation on the window with the given `window_id`, using the current mouse position.

## Signals

- `orientation_changed(orientation: DisplayServer.SensorOrientation)` — Emitted when the screen orientation changes.

## Enum Feature

- `FEATURE_GLOBAL_MENU = 0` — Display server supports global menu.
- `FEATURE_SUBWINDOWS = 1` — Display server supports multiple windows that can be moved outside of the main window.
- `FEATURE_TOUCHSCREEN = 2` — Display server supports touchscreen input.
- `FEATURE_MOUSE = 3` — Display server supports mouse input.
- `FEATURE_MOUSE_WARP = 4` — Display server supports warping mouse coordinates to keep the mouse cursor constrained within an area, but looping when one of the edges is reached.
- `FEATURE_CLIPBOARD = 5` — Display server supports setting and getting clipboard data.
- `FEATURE_VIRTUAL_KEYBOARD = 6` — Display server supports popping up a virtual keyboard when requested to input text without a physical keyboard.
- `FEATURE_CURSOR_SHAPE = 7` — Display server supports setting the mouse cursor shape to be different from the default.
- `FEATURE_CUSTOM_CURSOR_SHAPE = 8` — Display server supports setting the mouse cursor shape to a custom image.
- `FEATURE_NATIVE_DIALOG = 9` — Display server supports spawning text dialogs using the operating system's native look-and-feel.
- `FEATURE_IME = 10` — Display server supports Input Method Editor, which is commonly used for inputting Chinese/Japanese/Korean text.
- `FEATURE_WINDOW_TRANSPARENCY = 11` — Display server supports windows can use per-pixel transparency to make windows behind them partially or fully visible.
- `FEATURE_HIDPI = 12` — Display server supports querying the operating system's display scale factor.
- `FEATURE_ICON = 13` — Display server supports changing the window icon (usually displayed in the top-left corner).
- `FEATURE_NATIVE_ICON = 14` — Display server supports changing the window icon (usually displayed in the top-left corner).
- `FEATURE_ORIENTATION = 15` — Display server supports changing the screen orientation.
- `FEATURE_SWAP_BUFFERS = 16` — Display server supports V-Sync status can be changed from the default (which is forced to be enabled platforms not supporting this feature).
- `FEATURE_CLIPBOARD_PRIMARY = 18` — Display server supports Primary clipboard can be used.
- `FEATURE_TEXT_TO_SPEECH = 19` — Display server supports text-to-speech.
- `FEATURE_EXTEND_TO_TITLE = 20` — Display server supports expanding window content to the title.
- `FEATURE_SCREEN_CAPTURE = 21` — Display server supports reading screen pixels.
- `FEATURE_STATUS_INDICATOR = 22` — Display server supports application status indicators.
- `FEATURE_NATIVE_HELP = 23` — Display server supports native help system search callbacks.
- `FEATURE_NATIVE_DIALOG_INPUT = 24` — Display server supports spawning text input dialogs using the operating system's native look-and-feel.
- `FEATURE_NATIVE_DIALOG_FILE = 25` — Display server supports spawning dialogs for selecting files or directories using the operating system's native look-and-feel.
- `FEATURE_NATIVE_DIALOG_FILE_EXTRA = 26` — The display server supports all features of `FEATURE_NATIVE_DIALOG_FILE`, with the added functionality of Options and native dialog file access to `res://` and `user://` paths.
- `FEATURE_WINDOW_DRAG = 27` — The display server supports initiating window drag and resize operations on demand.
- `FEATURE_SCREEN_EXCLUDE_FROM_CAPTURE = 28` — Display server supports `WINDOW_FLAG_EXCLUDE_FROM_CAPTURE` window flag.
- `FEATURE_WINDOW_EMBEDDING = 29` — Display server supports embedding a window from another process.
- `FEATURE_NATIVE_DIALOG_FILE_MIME = 30` — Native file selection dialog supports MIME types as filters.
- `FEATURE_EMOJI_AND_SYMBOL_PICKER = 31` — Display server supports system emoji and symbol picker.
- `FEATURE_NATIVE_COLOR_PICKER = 32` — Display server supports native color picker.
- `FEATURE_SELF_FITTING_WINDOWS = 33` — Display server automatically fits popups according to the screen boundaries.
- `FEATURE_ACCESSIBILITY_SCREEN_READER = 34` — Display server supports interaction with screen reader or Braille display.
- `FEATURE_HDR_OUTPUT = 35` — Display server supports HDR output.
- `FEATURE_PIP_MODE = 36` — Display server supports putting the application in picture-in-picture mode.
- `FEATURE_EMBEDDED = 37` — Display server is embedding windows to another process. macOS

## Enum AccessibilityRole

- `ROLE_UNKNOWN = 0` — Unknown or custom role.
- `ROLE_DEFAULT_BUTTON = 1` — Default dialog button element.
- `ROLE_AUDIO = 2` — Audio player element.
- `ROLE_VIDEO = 3` — Video player element.
- `ROLE_STATIC_TEXT = 4` — Non-editable text label.
- `ROLE_CONTAINER = 5` — Container element.
- `ROLE_PANEL = 6` — Panel container element.
- `ROLE_BUTTON = 7` — Button element.
- `ROLE_LINK = 8` — Link element.
- `ROLE_CHECK_BOX = 9` — Check box element.
- `ROLE_RADIO_BUTTON = 10` — Radio button element.
- `ROLE_CHECK_BUTTON = 11` — Check button element.
- `ROLE_SCROLL_BAR = 12` — Scroll bar element.
- `ROLE_SCROLL_VIEW = 13` — Scroll container element.
- `ROLE_SPLITTER = 14` — Container splitter handle element.
- `ROLE_SLIDER = 15` — Slider element.
- `ROLE_SPIN_BUTTON = 16` — Spin box element.
- `ROLE_PROGRESS_INDICATOR = 17` — Progress indicator element.
- `ROLE_TEXT_FIELD = 18` — Editable text field element.
- `ROLE_MULTILINE_TEXT_FIELD = 19` — Multiline editable text field element.
- `ROLE_COLOR_PICKER = 20` — Color picker element.
- `ROLE_TABLE = 21` — Table element.
- `ROLE_CELL = 22` — Table/tree cell element.
- `ROLE_ROW = 23` — Table/tree row element.
- `ROLE_ROW_GROUP = 24` — Table/tree row group element.
- `ROLE_ROW_HEADER = 25` — Table/tree row header element.
- `ROLE_COLUMN_HEADER = 26` — Table/tree column header element.
- `ROLE_TREE = 27` — Tree view element.
- `ROLE_TREE_ITEM = 28` — Tree view item element.
- `ROLE_LIST = 29` — List element.
- `ROLE_LIST_ITEM = 30` — List item element.
- `ROLE_LIST_BOX = 31` — List view element.
- `ROLE_LIST_BOX_OPTION = 32` — List view item element.
- `ROLE_TAB_BAR = 33` — Tab bar element.
- `ROLE_TAB = 34` — Tab bar item element.
- `ROLE_TAB_PANEL = 35` — Tab panel element.
- `ROLE_MENU_BAR = 36` — Menu bar element.
- `ROLE_MENU = 37` — Popup menu element.
- `ROLE_MENU_ITEM = 38` — Popup menu item element.
- `ROLE_MENU_ITEM_CHECK_BOX = 39` — Popup menu check button item element.
- `ROLE_MENU_ITEM_RADIO = 40` — Popup menu radio button item element.
- `ROLE_IMAGE = 41` — Image element.
- `ROLE_WINDOW = 42` — Window element.
- `ROLE_TITLE_BAR = 43` — Embedded window title bar element.
- `ROLE_DIALOG = 44` — Dialog window element.
- `ROLE_TOOLTIP = 45` — Tooltip element.
- `ROLE_REGION = 46` — Region/landmark element.
- `ROLE_TEXT_RUN = 47` — Unifor text run.

## Enum AccessibilityPopupType

- `POPUP_MENU = 0` — Popup menu.
- `POPUP_LIST = 1` — Popup list.
- `POPUP_TREE = 2` — Popup tree view.
- `POPUP_DIALOG = 3` — Popup dialog.

## Enum AccessibilityFlags

- `FLAG_HIDDEN = 0` — Element is hidden for accessibility tools.
- `FLAG_MULTISELECTABLE = 1` — Element supports multiple item selection.
- `FLAG_REQUIRED = 2` — Element require user input.
- `FLAG_VISITED = 3` — Element is a visited link.
- `FLAG_BUSY = 4` — Element content is not ready (e.g. loading).
- `FLAG_MODAL = 5` — Element is modal window.
- `FLAG_TOUCH_PASSTHROUGH = 6` — Element allows touches to be passed through when a screen reader is in touch exploration mode.
- `FLAG_READONLY = 7` — Element is text field with selectable but read-only text.
- `FLAG_DISABLED = 8` — Element is disabled.
- `FLAG_CLIPS_CHILDREN = 9` — Element clips children.

## Enum AccessibilityAction

- `ACTION_CLICK = 0` — Single click action, callback argument is not set.
- `ACTION_FOCUS = 1` — Focus action, callback argument is not set.
- `ACTION_BLUR = 2` — Blur action, callback argument is not set.
- `ACTION_COLLAPSE = 3` — Collapse action, callback argument is not set.
- `ACTION_EXPAND = 4` — Expand action, callback argument is not set.
- `ACTION_DECREMENT = 5` — Decrement action, callback argument is not set.
- `ACTION_INCREMENT = 6` — Increment action, callback argument is not set.
- `ACTION_HIDE_TOOLTIP = 7` — Hide tooltip action, callback argument is not set.
- `ACTION_SHOW_TOOLTIP = 8` — Show tooltip action, callback argument is not set.
- `ACTION_SET_TEXT_SELECTION = 9` — Set text selection action, callback argument is set to Dictionary with the following keys: - `"start_element"` accessibility element of the selection start. - `"start_char"` character offset relative to the accessibility element of the selection start. - `"end_element"` accessibility element of the selection end. - `"end_char"` character offset relative to the accessibility element of the selection end.
- `ACTION_REPLACE_SELECTED_TEXT = 10` — Replace text action, callback argument is set to String with the replacement text.
- `ACTION_SCROLL_BACKWARD = 11` — Scroll backward action, callback argument is not set.
- `ACTION_SCROLL_DOWN = 12` — Scroll down action, callback argument is set to `AccessibilityScrollUnit`.
- `ACTION_SCROLL_FORWARD = 13` — Scroll forward action, callback argument is not set.
- `ACTION_SCROLL_LEFT = 14` — Scroll left action, callback argument is set to `AccessibilityScrollUnit`.
- `ACTION_SCROLL_RIGHT = 15` — Scroll right action, callback argument is set to `AccessibilityScrollUnit`.
- `ACTION_SCROLL_UP = 16` — Scroll up action, callback argument is set to `AccessibilityScrollUnit`.
- `ACTION_SCROLL_INTO_VIEW = 17` — Scroll into view action, callback argument is set to `AccessibilityScrollHint`.
- `ACTION_SCROLL_TO_POINT = 18` — Scroll to point action, callback argument is set to Vector2 with the relative point coordinates.
- `ACTION_SET_SCROLL_OFFSET = 19` — Set scroll offset action, callback argument is set to Vector2 with the scroll offset.
- `ACTION_SET_VALUE = 20` — Set value action, callback argument is set to String or number with the new value.
- `ACTION_SHOW_CONTEXT_MENU = 21` — Show context menu action, callback argument is not set.
- `ACTION_CUSTOM = 22` — Custom action, callback argument is set to the integer action ID.

## Enum AccessibilityLiveMode

- `LIVE_OFF = 0` — Indicates that updates to the live region should not be presented.
- `LIVE_POLITE = 1` — Indicates that updates to the live region should be presented at the next opportunity (for example at the end of speaking the current sentence).
- `LIVE_ASSERTIVE = 2` — Indicates that updates to the live region have the highest priority and should be presented immediately.

## Enum AccessibilityScrollUnit

- `SCROLL_UNIT_ITEM = 0` — The amount by which to scroll.
- `SCROLL_UNIT_PAGE = 1` — The amount by which to scroll.

## Enum AccessibilityScrollHint

- `SCROLL_HINT_TOP_LEFT = 0` — A preferred position for the node scrolled into view.
- `SCROLL_HINT_BOTTOM_RIGHT = 1` — A preferred position for the node scrolled into view.
- `SCROLL_HINT_TOP_EDGE = 2` — A preferred position for the node scrolled into view.
- `SCROLL_HINT_BOTTOM_EDGE = 3` — A preferred position for the node scrolled into view.
- `SCROLL_HINT_LEFT_EDGE = 4` — A preferred position for the node scrolled into view.
- `SCROLL_HINT_RIGHT_EDGE = 5` — A preferred position for the node scrolled into view.

## Enum MouseMode

- `MOUSE_MODE_VISIBLE = 0` — Makes the mouse cursor visible if it is hidden.
- `MOUSE_MODE_HIDDEN = 1` — Makes the mouse cursor hidden if it is visible.
- `MOUSE_MODE_CAPTURED = 2` — Captures the mouse.
- `MOUSE_MODE_CONFINED = 3` — Confines the mouse cursor to the game window, and make it visible.
- `MOUSE_MODE_CONFINED_HIDDEN = 4` — Confines the mouse cursor to the game window, and make it hidden.
- `MOUSE_MODE_MAX = 5` — Max value of the `MouseMode`.

## Enum ScreenOrientation

- `SCREEN_LANDSCAPE = 0` — Default landscape orientation.
- `SCREEN_PORTRAIT = 1` — Default portrait orientation.
- `SCREEN_REVERSE_LANDSCAPE = 2` — Reverse landscape orientation (upside down).
- `SCREEN_REVERSE_PORTRAIT = 3` — Reverse portrait orientation (upside down).
- `SCREEN_SENSOR_LANDSCAPE = 4` — Automatic landscape orientation (default or reverse depending on sensor).
- `SCREEN_SENSOR_PORTRAIT = 5` — Automatic portrait orientation (default or reverse depending on sensor).
- `SCREEN_SENSOR = 6` — Automatic landscape or portrait orientation (default or reverse depending on sensor).

## Enum SensorOrientation

- `SENSOR_ORIENTATION_UNDEFINED = 0` — Unspecified screen sensor orientation.
- `SENSOR_ORIENTATION_PORTRAIT = 1` — Portrait orientation (either standard portrait or reverse portrait).
- `SENSOR_ORIENTATION_LANDSCAPE = 2` — Landscape orientation (either standard landscape or reverse landscape).

## Enum VirtualKeyboardType

- `KEYBOARD_TYPE_DEFAULT = 0` — Default text virtual keyboard.
- `KEYBOARD_TYPE_MULTILINE = 1` — Multiline virtual keyboard.
- `KEYBOARD_TYPE_NUMBER = 2` — Virtual number keypad, useful for PIN entry.
- `KEYBOARD_TYPE_NUMBER_DECIMAL = 3` — Virtual number keypad, useful for entering fractional numbers.
- `KEYBOARD_TYPE_PHONE = 4` — Virtual phone number keypad.
- `KEYBOARD_TYPE_EMAIL_ADDRESS = 5` — Virtual keyboard with additional keys to assist with typing email addresses.
- `KEYBOARD_TYPE_PASSWORD = 6` — Virtual keyboard for entering a password.
- `KEYBOARD_TYPE_URL = 7` — Virtual keyboard with additional keys to assist with typing URLs.

## Enum CursorShape

- `CURSOR_ARROW = 0` — Arrow cursor shape.
- `CURSOR_IBEAM = 1` — I-beam cursor shape.
- `CURSOR_POINTING_HAND = 2` — Pointing hand cursor shape.
- `CURSOR_CROSS = 3` — Crosshair cursor.
- `CURSOR_WAIT = 4` — Wait cursor.
- `CURSOR_BUSY = 5` — Wait cursor.
- `CURSOR_DRAG = 6` — Dragging hand cursor.
- `CURSOR_CAN_DROP = 7` — "Can drop" cursor.
- `CURSOR_FORBIDDEN = 8` — Forbidden cursor.
- `CURSOR_VSIZE = 9` — Vertical resize cursor.
- `CURSOR_HSIZE = 10` — Horizontal resize cursor.
- `CURSOR_BDIAGSIZE = 11` — Secondary diagonal resize cursor (top-right/bottom-left).
- `CURSOR_FDIAGSIZE = 12` — Main diagonal resize cursor (top-left/bottom-right).
- `CURSOR_MOVE = 13` — Move cursor.
- `CURSOR_VSPLIT = 14` — Vertical split cursor.
- `CURSOR_HSPLIT = 15` — Horizontal split cursor.
- `CURSOR_HELP = 16` — Help cursor.
- `CURSOR_MAX = 17` — Represents the size of the `CursorShape` enum.

## Enum FileDialogMode

- `FILE_DIALOG_MODE_OPEN_FILE = 0` — The native file dialog allows selecting one, and only one file.
- `FILE_DIALOG_MODE_OPEN_FILES = 1` — The native file dialog allows selecting multiple files.
- `FILE_DIALOG_MODE_OPEN_DIR = 2` — The native file dialog only allows selecting a directory, disallowing the selection of any file.
- `FILE_DIALOG_MODE_OPEN_ANY = 3` — The native file dialog allows selecting one file or directory.
- `FILE_DIALOG_MODE_SAVE_FILE = 4` — The native file dialog will warn when a file exists.

## Enum WindowMode

- `WINDOW_MODE_WINDOWED = 0` — Windowed mode, i.e.
- `WINDOW_MODE_MINIMIZED = 1` — Minimized window mode, i.e.
- `WINDOW_MODE_MAXIMIZED = 2` — Maximized window mode, i.e.
- `WINDOW_MODE_FULLSCREEN = 3` — Full screen mode with full multi-window support.
- `WINDOW_MODE_EXCLUSIVE_FULLSCREEN = 4` — A single window full screen mode.

## Enum ProgressState

- `PROGRESS_STATE_NOPROGRESS = 0` — Stops displaying progress and returns the button to its normal state.
- `PROGRESS_STATE_INDETERMINATE = 1` — The progress indicator shows an indeterminate progress.
- `PROGRESS_STATE_NORMAL = 2` — The progress indicator shows progress normally.
- `PROGRESS_STATE_ERROR = 3` — The progress indicator shows that an error has occurred.
- `PROGRESS_STATE_PAUSED = 4` — The progress indicator shows it was paused.

## Enum WindowFlags

- `WINDOW_FLAG_RESIZE_DISABLED = 0` — The window can't be resized by dragging its resize grip.
- `WINDOW_FLAG_BORDERLESS = 1` — The window do not have native title bar and other decorations.
- `WINDOW_FLAG_ALWAYS_ON_TOP = 2` — The window is floating on top of all other windows.
- `WINDOW_FLAG_TRANSPARENT = 3` — The window background can be transparent.
- `WINDOW_FLAG_NO_FOCUS = 4` — The window can't be focused.
- `WINDOW_FLAG_POPUP = 5` — Window is part of menu or OptionButton dropdown.
- `WINDOW_FLAG_EXTEND_TO_TITLE = 6` — Window content is expanded to the full size of the window.
- `WINDOW_FLAG_MOUSE_PASSTHROUGH = 7` — All mouse events are passed to the underlying window of the same application.
- `WINDOW_FLAG_SHARP_CORNERS = 8` — Window style is overridden, forcing sharp corners.
- `WINDOW_FLAG_EXCLUDE_FROM_CAPTURE = 9` — Window is excluded from screenshots taken by `screen_get_image`, `screen_get_image_rect`, and `screen_get_pixel`.
- `WINDOW_FLAG_POPUP_WM_HINT = 10` — Signals the window manager that this window is supposed to be an implementation-defined "popup" (usually a floating, borderless, untileable and immovable child window).
- `WINDOW_FLAG_MINIMIZE_DISABLED = 11` — Window minimize button is disabled.
- `WINDOW_FLAG_MAXIMIZE_DISABLED = 12` — Window maximize button is disabled.
- `WINDOW_FLAG_MAX = 13` — Represents the size of the `WindowFlags` enum.

## Enum WindowEvent

- `WINDOW_EVENT_MOUSE_ENTER = 0` — Sent when the mouse pointer enters the window.
- `WINDOW_EVENT_MOUSE_EXIT = 1` — Sent when the mouse pointer exits the window.
- `WINDOW_EVENT_FOCUS_IN = 2` — Sent when the window grabs focus.
- `WINDOW_EVENT_FOCUS_OUT = 3` — Sent when the window loses focus.
- `WINDOW_EVENT_CLOSE_REQUEST = 4` — Sent when the user has attempted to close the window (e.g. close button is pressed).
- `WINDOW_EVENT_GO_BACK_REQUEST = 5` — Sent when the device "Back" button is pressed.
- `WINDOW_EVENT_DPI_CHANGE = 6` — Sent when the window is moved to the display with different DPI, or display DPI is changed.
- `WINDOW_EVENT_TITLEBAR_CHANGE = 7` — Sent when the window title bar decoration is changed (e.g.
- `WINDOW_EVENT_FORCE_CLOSE = 8` — Sent when the window has been forcibly closed by the display server.
- `WINDOW_EVENT_OUTPUT_MAX_LINEAR_VALUE_CHANGED = 9` — Sent when the output max linear value returned by `Window.get_output_max_linear_value` has changed.

## Enum WindowResizeEdge

- `WINDOW_EDGE_TOP_LEFT = 0` — Top-left edge of a window.
- `WINDOW_EDGE_TOP = 1` — Top edge of a window.
- `WINDOW_EDGE_TOP_RIGHT = 2` — Top-right edge of a window.
- `WINDOW_EDGE_LEFT = 3` — Left edge of a window.
- `WINDOW_EDGE_RIGHT = 4` — Right edge of a window.
- `WINDOW_EDGE_BOTTOM_LEFT = 5` — Bottom-left edge of a window.
- `WINDOW_EDGE_BOTTOM = 6` — Bottom edge of a window.
- `WINDOW_EDGE_BOTTOM_RIGHT = 7` — Bottom-right edge of a window.
- `WINDOW_EDGE_MAX = 8` — Represents the size of the `WindowResizeEdge` enum.

## Enum NotificationStatus

- `NOTIFICATION_ACTIVATED = 0` — User activates a toast notification through a click or touch.
- `NOTIFICATION_DISMISSED = 1` — A toast notification expires or is explicitly dismissed by the user.
- `NOTIFICATION_FAILED = 2` — Attempts to raise a toast notification failed.

## Enum VSyncMode

- `VSYNC_DISABLED = 0` — No vertical synchronization, which means the engine will display frames as fast as possible (tearing may be visible).
- `VSYNC_ENABLED = 1` — Default vertical synchronization mode, the image is displayed only on vertical blanking intervals (no tearing is visible).
- `VSYNC_ADAPTIVE = 2` — Behaves like `VSYNC_DISABLED` when the framerate drops below the screen's refresh rate to reduce stuttering (tearing may be visible).
- `VSYNC_MAILBOX = 3` — Displays the most recent image in the queue on vertical blanking intervals, while rendering to the other images (no tearing is visible).

## Enum HandleType

- `DISPLAY_HANDLE = 0` — Display handle: - Linux (X11): `X11::Display*` for the display. - Linux (Wayland): `wl_display` for the display. - Android: `EGLDisplay` for the display.
- `WINDOW_HANDLE = 1` — Window handle: - Windows: `HWND` for the window. - Linux (X11): `X11::Window*` for the window. - Linux (Wayland): `wl_surface` for the window. - macOS: `NSWindow*` for the window. - iOS: `UIViewController*` for the view controller. - Android: `jObject` for the activity.
- `WINDOW_VIEW = 2` — Window view: - Windows: `HDC` for the window (only with the Compatibility renderer). - macOS: `NSView*` for the window main view. - iOS: `UIView*` for the window main view.
- `OPENGL_CONTEXT = 3` — OpenGL context (only with the Compatibility renderer): - Windows: `HGLRC` for the window (native GL), or `EGLContext` for the window (ANGLE). - Linux (X11): `GLXContext*` for the window. - Linux (Wayland): `EGLContext` for the window. - macOS: `NSOpenGLContext*` for the window (native GL), or `EGLContext` for the window (ANGLE). - Android: `EGLContext` for the window.
- `EGL_DISPLAY = 4` — - Windows: `EGLDisplay` for the window (ANGLE). - macOS: `EGLDisplay` for the window (ANGLE). - Linux (Wayland): `EGLDisplay` for the window.
- `EGL_CONFIG = 5` — - Windows: `EGLConfig` for the window (ANGLE). - macOS: `EGLConfig` for the window (ANGLE). - Linux (Wayland): `EGLConfig` for the window.
- `GLX_VISUALID = 6` — The GLX `VisualID` for the window.
- `GLX_FBCONFIG = 7` — The `GLXFBConfig` for the window.

## Enum TTSUtteranceEvent

- `TTS_UTTERANCE_STARTED = 0` — Utterance has begun to be spoken.
- `TTS_UTTERANCE_ENDED = 1` — Utterance was successfully finished.
- `TTS_UTTERANCE_CANCELED = 2` — Utterance was canceled, or TTS service was unable to process it.
- `TTS_UTTERANCE_BOUNDARY = 3` — Utterance reached a word or sentence boundary.

## Constants

- `INVALID_SCREEN = -1` — The ID that refers to a screen that does not exist.
- `SCREEN_WITH_MOUSE_FOCUS = -4` — Represents the screen containing the mouse pointer.
- `SCREEN_WITH_KEYBOARD_FOCUS = -3` — Represents the screen containing the window with the keyboard focus.
- `SCREEN_PRIMARY = -2` — Represents the primary screen.
- `SCREEN_OF_MAIN_WINDOW = -1` — Represents the screen where the main window is located.
- `MAIN_WINDOW_ID = 0` — The ID of the main window spawned by the engine, which can be passed to methods expecting a `window_id`.
- `INVALID_WINDOW_ID = -1` — The ID that refers to a nonexistent window.
- `INVALID_INDICATOR_ID = -1` — The ID that refers to a nonexistent application status indicator.
- `INVALID_NOTIFICATION_ID = -1` — The ID that refers to a nonexistent toast notification.
