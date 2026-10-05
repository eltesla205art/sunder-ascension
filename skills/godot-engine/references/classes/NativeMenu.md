# NativeMenu

**Inherits:** Object

A server interface for OS native menus.

NativeMenu handles low-level access to the OS native global menu bar and popup menus. Note: This is low-level API, consider using MenuBar with `MenuBar.prefer_global_menu` set to `true`, and PopupMenu with `PopupMenu.prefer_native_menu` set to `true`. To create a menu, use `create_menu`, add menu items using `add_*_item` methods. To remove a menu, use `free_menu`.

## Methods

- `add_check_item(rid: RID, label: String, callback: Callable = Callable(), key_callback: Callable = Callable(), tag: Variant = null, accelerator: Key = 0, index: int = -1) -> int` — Adds a new checkable item with text `label` to the global menu `rid`.
- `add_icon_check_item(rid: RID, icon: Texture2D, label: String, callback: Callable = Callable(), key_callback: Callable = Callable(), tag: Variant = null, accelerator: Key = 0, index: int = -1) -> int` — Adds a new checkable item with text `label` and icon `icon` to the global menu `rid`.
- `add_icon_item(rid: RID, icon: Texture2D, label: String, callback: Callable = Callable(), key_callback: Callable = Callable(), tag: Variant = null, accelerator: Key = 0, index: int = -1) -> int` — Adds a new item with text `label` and icon `icon` to the global menu `rid`.
- `add_icon_radio_check_item(rid: RID, icon: Texture2D, label: String, callback: Callable = Callable(), key_callback: Callable = Callable(), tag: Variant = null, accelerator: Key = 0, index: int = -1) -> int` — Adds a new radio-checkable item with text `label` and icon `icon` to the global menu `rid`.
- `add_item(rid: RID, label: String, callback: Callable = Callable(), key_callback: Callable = Callable(), tag: Variant = null, accelerator: Key = 0, index: int = -1) -> int` — Adds a new item with text `label` to the global menu `rid`.
- `add_multistate_item(rid: RID, label: String, max_states: int, default_state: int, callback: Callable = Callable(), key_callback: Callable = Callable(), tag: Variant = null, accelerator: Key = 0, index: int = -1) -> int` — Adds a new item with text `label` to the global menu `rid`.
- `add_radio_check_item(rid: RID, label: String, callback: Callable = Callable(), key_callback: Callable = Callable(), tag: Variant = null, accelerator: Key = 0, index: int = -1) -> int` — Adds a new radio-checkable item with text `label` to the global menu `rid`.
- `add_separator(rid: RID, index: int = -1) -> int` — Adds a separator between items to the global menu `rid`.
- `add_submenu_item(rid: RID, label: String, submenu_rid: RID, tag: Variant = null, index: int = -1) -> int` — Adds an item that will act as a submenu of the global menu `rid`.
- `clear(rid: RID) -> void` — Removes all items from the global menu `rid`.
- `create_menu() -> RID` — Creates a new global menu object.
- `find_item_index_with_submenu(rid: RID, submenu_rid: RID) -> int` *const* — Returns the index of the item with the submenu specified by `submenu_rid`.
- `find_item_index_with_tag(rid: RID, tag: Variant) -> int` *const* — Returns the index of the item with the specified `tag`.
- `find_item_index_with_text(rid: RID, text: String) -> int` *const* — Returns the index of the item with the specified `text`.
- `free_menu(rid: RID) -> void` — Frees a global menu object created by this NativeMenu.
- `get_item_accelerator(rid: RID, idx: int) -> int[Key]` *const* — Returns the accelerator of the item at index `idx`.
- `get_item_callback(rid: RID, idx: int) -> Callable` *const* — Returns the callback of the item at index `idx`.
- `get_item_count(rid: RID) -> int` *const* — Returns number of items in the global menu `rid`.
- `get_item_icon(rid: RID, idx: int) -> Texture2D` *const* — Returns the icon of the item at index `idx`.
- `get_item_indentation_level(rid: RID, idx: int) -> int` *const* — Returns the horizontal offset of the item at the given `idx`.
- `get_item_key_callback(rid: RID, idx: int) -> Callable` *const* — Returns the callback of the item accelerator at index `idx`.
- `get_item_max_states(rid: RID, idx: int) -> int` *const* — Returns number of states of a multistate item.
- `get_item_state(rid: RID, idx: int) -> int` *const* — Returns the state of a multistate item.
- `get_item_submenu(rid: RID, idx: int) -> RID` *const* — Returns the submenu ID of the item at index `idx`.
- `get_item_tag(rid: RID, idx: int) -> Variant` *const* — Returns the metadata of the specified item, which might be of any type.
- `get_item_text(rid: RID, idx: int) -> String` *const* — Returns the text of the item at index `idx`.
- `get_item_tooltip(rid: RID, idx: int) -> String` *const* — Returns the tooltip associated with the specified index `idx`.
- `get_minimum_width(rid: RID) -> float` *const* — Returns global menu minimum width.
- `get_popup_close_callback(rid: RID) -> Callable` *const* — Returns global menu close callback.
- `get_popup_open_callback(rid: RID) -> Callable` *const* — Returns global menu open callback.
- `get_size(rid: RID) -> Vector2` *const* — Returns global menu size.
- `get_system_menu(menu_id: NativeMenu.SystemMenus) -> RID` *const* — Returns RID of a special system menu.
- `get_system_menu_name(menu_id: NativeMenu.SystemMenus) -> String` *const* — Returns readable name of a special system menu.
- `get_system_menu_text(menu_id: NativeMenu.SystemMenus) -> String` *const* — Returns the text of the system menu item.
- `has_feature(feature: NativeMenu.Feature) -> bool` *const* — Returns `true` if the specified `feature` is supported by the current NativeMenu, `false` otherwise.
- `has_menu(rid: RID) -> bool` *const* — Returns `true` if `rid` is valid global menu.
- `has_system_menu(menu_id: NativeMenu.SystemMenus) -> bool` *const* — Returns `true` if a special system menu is supported.
- `is_item_checkable(rid: RID, idx: int) -> bool` *const* — Returns `true` if the item at index `idx` is checkable in some way, i.e. if it has a checkbox or radio button.
- `is_item_checked(rid: RID, idx: int) -> bool` *const* — Returns `true` if the item at index `idx` is checked.
- `is_item_disabled(rid: RID, idx: int) -> bool` *const* — Returns `true` if the item at index `idx` is disabled.
- `is_item_hidden(rid: RID, idx: int) -> bool` *const* — Returns `true` if the item at index `idx` is hidden.
- `is_item_indeterminate(rid: RID, idx: int) -> bool` *const* — Returns `true` if the item at index `idx` is indeterminate.
- `is_item_radio_checkable(rid: RID, idx: int) -> bool` *const* — Returns `true` if the item at index `idx` has radio button-style checkability.
- `is_opened(rid: RID) -> bool` *const* — Returns `true` if the menu is currently opened.
- `is_system_menu(rid: RID) -> bool` *const* — Return `true` is global menu is a special system menu.
- `popup(rid: RID, position: Vector2i) -> void` — Shows the global menu at `position` in the screen coordinates.
- `remove_item(rid: RID, idx: int) -> void` — Removes the item at index `idx` from the global menu `rid`.
- `set_interface_direction(rid: RID, is_rtl: bool) -> void` — Sets the menu text layout direction from right-to-left if `is_rtl` is `true`.
- `set_item_accelerator(rid: RID, idx: int, keycode: Key) -> void` — Sets the accelerator of the item at index `idx`.
- `set_item_callback(rid: RID, idx: int, callback: Callable) -> void` — Sets the callback of the item at index `idx`.
- `set_item_checkable(rid: RID, idx: int, checkable: bool) -> void` — Sets whether the item at index `idx` has a checkbox.
- `set_item_checked(rid: RID, idx: int, checked: bool) -> void` — Sets the checkstate status of the item at index `idx`.
- `set_item_disabled(rid: RID, idx: int, disabled: bool) -> void` — Enables/disables the item at index `idx`.
- `set_item_hidden(rid: RID, idx: int, hidden: bool) -> void` — Hides/shows the item at index `idx`.
- `set_item_hover_callbacks(rid: RID, idx: int, callback: Callable) -> void` — Sets the callback of the item at index `idx`.
- `set_item_icon(rid: RID, idx: int, icon: Texture2D) -> void` — Replaces the Texture2D icon of the specified `idx`.
- `set_item_indentation_level(rid: RID, idx: int, level: int) -> void` — Sets the horizontal offset of the item at the given `idx`.
- `set_item_indeterminate(rid: RID, idx: int, indeterminate: bool) -> void` — Sets the indeterminate status of the item at index `idx`.
- `set_item_index(rid: RID, idx: int, target_idx: int) -> int` — Changes the index of the item at index `idx` to be at index `target_idx`.
- `set_item_key_callback(rid: RID, idx: int, key_callback: Callable) -> void` — Sets the callback of the item at index `idx`.
- `set_item_max_states(rid: RID, idx: int, max_states: int) -> void` — Sets number of state of a multistate item.
- `set_item_radio_checkable(rid: RID, idx: int, checkable: bool) -> void` — Sets the type of the item at the specified index `idx` to radio button.
- `set_item_state(rid: RID, idx: int, state: int) -> void` — Sets the state of a multistate item.
- `set_item_submenu(rid: RID, idx: int, submenu_rid: RID) -> void` — Sets the submenu RID of the item at index `idx`.
- `set_item_tag(rid: RID, idx: int, tag: Variant) -> void` — Sets the metadata of an item, which may be of any type.
- `set_item_text(rid: RID, idx: int, text: String) -> void` — Sets the text of the item at index `idx`.
- `set_item_tooltip(rid: RID, idx: int, tooltip: String) -> void` — Sets the String tooltip of the item at the specified index `idx`.
- `set_minimum_width(rid: RID, width: float) -> void` — Sets the minimum width of the global menu.
- `set_popup_close_callback(rid: RID, callback: Callable) -> void` — Registers callable to emit when the menu is about to show.
- `set_popup_open_callback(rid: RID, callback: Callable) -> void` — Registers callable to emit after the menu is closed.
- `set_system_menu_text(menu_id: NativeMenu.SystemMenus, name: String) -> void` — Sets the text of the system menu item.

## Enum Feature

- `FEATURE_GLOBAL_MENU = 0` — NativeMenu supports native global main menu.
- `FEATURE_POPUP_MENU = 1` — NativeMenu supports native popup menus.
- `FEATURE_OPEN_CLOSE_CALLBACK = 2` — NativeMenu supports menu open and close callbacks.
- `FEATURE_HOVER_CALLBACK = 3` — NativeMenu supports menu item hover callback.
- `FEATURE_KEY_CALLBACK = 4` — NativeMenu supports menu item accelerator/key callback.

## Enum SystemMenus

- `INVALID_MENU_ID = 0` — Invalid special system menu ID.
- `MAIN_MENU_ID = 1` — Global main menu ID.
- `APPLICATION_MENU_ID = 2` — Application (first menu after "Apple" menu on macOS) menu ID.
- `WINDOW_MENU_ID = 3` — "Window" menu ID (on macOS this menu includes standard window control items and a list of open windows).
- `HELP_MENU_ID = 4` — "Help" menu ID (on macOS this menu includes help search bar).
- `DOCK_MENU_ID = 5` — Dock icon right-click menu ID (on macOS this menu include standard application control items and a list of open windows).
