# PopupMenu

**Inherits:** Popup

A modal window used to display a list of options.

PopupMenu is a modal window used to display a list of options. Useful for toolbars and context menus. The size of a PopupMenu can be limited by using `Window.max_size`. If the height of the list of items is larger than the maximum height of the PopupMenu, a ScrollContainer within the popup will allow the user to scroll the contents.

## Properties

- `allow_search: bool` = `true` — If `true`, allows navigating PopupMenu with letter keys.
- `canvas_item_default_texture_filter: Viewport.DefaultCanvasItemTextureFilter` = `4` — 
- `canvas_item_default_texture_repeat: Viewport.DefaultCanvasItemTextureRepeat` = `3` — 
- `hide_on_checkable_item_selection: bool` = `true` — If `true`, hides the PopupMenu when a checkbox or radio button is selected.
- `hide_on_item_selection: bool` = `true` — If `true`, hides the PopupMenu when an item is selected.
- `hide_on_state_item_selection: bool` = `false` — If `true`, hides the PopupMenu when a state item is selected.
- `item_count: int` = `0` — The number of items currently in the list.
- `item_{index}/checkable: int` = `0` — The checkable item type of the item at `index`.
- `item_{index}/checked: bool` = `false` — If `true`, the item at `index` is checked.
- `item_{index}/disabled: bool` = `false` — If `true`, the item at `index` is disabled.
- `item_{index}/icon: Texture2D` — The icon of the item at `index`.
- `item_{index}/id: int` = `0` — The ID of the item at `index`.
- `item_{index}/indeterminate: bool` = `false` — If `true`, the item at `index` is in an indeterminate state.
- `item_{index}/separator: bool` = `false` — If `true`, the item at `index` is a separator.
- `item_{index}/text: String` = `""` — The text of the item at `index`.
- `prefer_native_menu: bool` = `false` — If `true`, MenuBar will use native menu when supported.
- `search_bar_enabled: bool` = `false` — If `true`, shows a search bar at the top of the PopupMenu for filtering items.
- `search_bar_fuzzy_search_enabled: bool` = `true` — If `true`, enables fuzzy searching in the PopupMenu search bar.
- `search_bar_fuzzy_search_max_misses: int` = `2` — Sets the maximum number of mismatches allowed in each search result when fuzzy searching is enabled for the PopupMenu search bar.
- `search_bar_min_item_count: int` = `0` — Sets the minimum number of items required for the search bar to be visible.
- `shrink_height: bool` = `true` — If `true`, shrinks PopupMenu to minimum height when it's shown.
- `shrink_width: bool` = `true` — If `true`, shrinks PopupMenu to minimum width when it's shown.
- `submenu_popup_delay: float` = `0.2` — Sets the delay time in seconds for the submenu item to popup on mouse hovering.
- `system_menu_id: NativeMenu.SystemMenus` = `0` — If set to one of the values of `NativeMenu.SystemMenus`, this PopupMenu is bound to the special system menu.
- `transparent: bool` = `true` — 
- `transparent_bg: bool` = `true` — 

## Methods

- `activate_item_by_event(event: InputEvent, for_global_only: bool = false) -> bool` — Checks the provided `event` against the PopupMenu's shortcuts and accelerators, and activates the first item with matching events.
- `add_check_item(label: String, id: int = -1, accel: Key = 0) -> void` — Adds a new checkable item with text `label`.
- `add_check_shortcut(shortcut: Shortcut, id: int = -1, global: bool = false) -> void` — Adds a new checkable item and assigns the specified Shortcut to it.
- `add_icon_check_item(texture: Texture2D, label: String, id: int = -1, accel: Key = 0) -> void` — Adds a new checkable item with text `label` and icon `texture`.
- `add_icon_check_shortcut(texture: Texture2D, shortcut: Shortcut, id: int = -1, global: bool = false) -> void` — Adds a new checkable item and assigns the specified Shortcut and icon `texture` to it.
- `add_icon_item(texture: Texture2D, label: String, id: int = -1, accel: Key = 0) -> void` — Adds a new item with text `label` and icon `texture`.
- `add_icon_radio_check_item(texture: Texture2D, label: String, id: int = -1, accel: Key = 0) -> void` — Same as `add_icon_check_item`, but uses a radio check button.
- `add_icon_radio_check_shortcut(texture: Texture2D, shortcut: Shortcut, id: int = -1, global: bool = false) -> void` — Same as `add_icon_check_shortcut`, but uses a radio check button.
- `add_icon_shortcut(texture: Texture2D, shortcut: Shortcut, id: int = -1, global: bool = false, allow_echo: bool = false) -> void` — Adds a new item and assigns the specified Shortcut and icon `texture` to it.
- `add_item(label: String, id: int = -1, accel: Key = 0) -> void` — Adds a new item with text `label`.
- `add_multistate_item(label: String, max_states: int, default_state: int = 0, id: int = -1, accel: Key = 0) -> void` — Adds a new multistate item with text `label`.
- `add_radio_check_item(label: String, id: int = -1, accel: Key = 0) -> void` — Adds a new radio check button with text `label`.
- `add_radio_check_shortcut(shortcut: Shortcut, id: int = -1, global: bool = false) -> void` — Adds a new radio check button and assigns a Shortcut to it.
- `add_separator(label: String = "", id: int = -1) -> void` — Adds a separator between items.
- `add_shortcut(shortcut: Shortcut, id: int = -1, global: bool = false, allow_echo: bool = false) -> void` — Adds a Shortcut.
- `add_submenu_item(label: String, submenu: String, id: int = -1) -> void` *(deprecated)* — Adds an item that will act as a submenu of the parent PopupMenu node when clicked.
- `add_submenu_node_item(label: String, submenu: PopupMenu, id: int = -1) -> void` — Adds an item that will act as a submenu of the parent PopupMenu node when clicked.
- `clear(free_submenus: bool = false) -> void` — Removes all items from the PopupMenu.
- `get_focused_item() -> int` *const* — Returns the index of the currently focused item.
- `get_item_accelerator(index: int) -> int[Key]` *const* — Returns the accelerator of the item at the given `index`.
- `get_item_auto_translate_mode(index: int) -> int[Node.AutoTranslateMode]` *const* — Returns the auto translate mode of the item at the given `index`.
- `get_item_icon(index: int) -> Texture2D` *const* — Returns the icon of the item at the given `index`.
- `get_item_icon_max_width(index: int) -> int` *const* — Returns the maximum allowed width of the icon for the item at the given `index`.
- `get_item_icon_modulate(index: int) -> Color` *const* — Returns a Color modulating the item's icon at the given `index`.
- `get_item_id(index: int) -> int` *const* — Returns the ID of the item at the given `index`.
- `get_item_indent(index: int) -> int` *const* — Returns the horizontal offset of the item at the given `index`.
- `get_item_index(id: int) -> int` *const* — Returns the index of the item containing the specified `id`.
- `get_item_language(index: int) -> String` *const* — Returns item's text language code.
- `get_item_metadata(index: int) -> Variant` *const* — Returns the metadata of the specified item, which might be of any type.
- `get_item_multistate(index: int) -> int` *const* — Returns the state of the item at the given `index`.
- `get_item_multistate_max(index: int) -> int` *const* — Returns the max states of the item at the given `index`.
- `get_item_shortcut(index: int) -> Shortcut` *const* — Returns the Shortcut associated with the item at the given `index`.
- `get_item_submenu(index: int) -> String` *const* *(deprecated)* — Returns the submenu name of the item at the given `index`.
- `get_item_submenu_node(index: int) -> PopupMenu` *const* — Returns the submenu of the item at the given `index`, or `null` if no submenu was added.
- `get_item_text(index: int) -> String` *const* — Returns the text of the item at the given `index`.
- `get_item_text_direction(index: int) -> int[Control.TextDirection]` *const* — Returns item's text base writing direction.
- `get_item_tooltip(index: int) -> String` *const* — Returns the tooltip associated with the item at the given `index`.
- `is_item_checkable(index: int) -> bool` *const* — Returns `true` if the item at the given `index` is checkable in some way, i.e. if it has a checkbox or radio button.
- `is_item_checked(index: int) -> bool` *const* — Returns `true` if the item at the given `index` is checked.
- `is_item_disabled(index: int) -> bool` *const* — Returns `true` if the item at the given `index` is disabled.
- `is_item_indeterminate(index: int) -> bool` *const* — Returns `true` if the item at the given `index` is in an indeterminate state.
- `is_item_radio_checkable(index: int) -> bool` *const* — Returns `true` if the item at the given `index` has radio button-style checkability.
- `is_item_separator(index: int) -> bool` *const* — Returns `true` if the item is a separator.
- `is_item_shortcut_disabled(index: int) -> bool` *const* — Returns `true` if the specified item's shortcut is disabled.
- `is_native_menu() -> bool` *const* — Returns `true` if the system native menu is supported and currently used by this PopupMenu.
- `is_system_menu() -> bool` *const* — Returns `true` if the menu is bound to the special system menu.
- `remove_item(index: int) -> void` — Removes the item at the given `index` from the menu.
- `scroll_to_item(index: int) -> void` — Moves the scroll view to make the item at the given `index` visible.
- `set_focused_item(index: int) -> void` — Sets the currently focused item as the given `index`.
- `set_item_accelerator(index: int, accel: Key) -> void` — Sets the accelerator of the item at the given `index`.
- `set_item_as_checkable(index: int, enable: bool) -> void` — Sets whether the item at the given `index` has a checkbox.
- `set_item_as_radio_checkable(index: int, enable: bool) -> void` — Sets the type of the item at the given `index` to radio button.
- `set_item_as_separator(index: int, enable: bool) -> void` — Mark the item at the given `index` as a separator, which means that it would be displayed as a line.
- `set_item_auto_translate_mode(index: int, mode: Node.AutoTranslateMode) -> void` — Sets the auto translate mode of the item at the given `index`.
- `set_item_checked(index: int, checked: bool) -> void` — Sets the checkstate status of the item at the given `index`.
- `set_item_disabled(index: int, disabled: bool) -> void` — Enables/disables the item at the given `index`.
- `set_item_icon(index: int, icon: Texture2D) -> void` — Replaces the Texture2D icon of the item at the given `index`.
- `set_item_icon_max_width(index: int, width: int) -> void` — Sets the maximum allowed width of the icon for the item at the given `index`.
- `set_item_icon_modulate(index: int, modulate: Color) -> void` — Sets a modulating Color of the item's icon at the given `index`.
- `set_item_id(index: int, id: int) -> void` — Sets the `id` of the item at the given `index`.
- `set_item_indent(index: int, indent: int) -> void` — Sets the horizontal offset of the item at the given `index`.
- `set_item_indeterminate(index: int, indeterminate: bool) -> void` — Sets the indeterminate status of the item at the given `index`.
- `set_item_index(index: int, target_index: int) -> void` — Changes the index of the item at index `index` to be at index `target_index`.
- `set_item_language(index: int, language: String) -> void` — Sets the language code of the text for the item at the given index to `language`.
- `set_item_metadata(index: int, metadata: Variant) -> void` — Sets the metadata of an item, which may be of any type.
- `set_item_multistate(index: int, state: int) -> void` — Sets the state of a multistate item.
- `set_item_multistate_max(index: int, max_states: int) -> void` — Sets the max states of a multistate item.
- `set_item_shortcut(index: int, shortcut: Shortcut, global: bool = false) -> void` — Sets a Shortcut for the item at the given `index`.
- `set_item_shortcut_disabled(index: int, disabled: bool) -> void` — Disables the Shortcut of the item at the given `index`.
- `set_item_submenu(index: int, submenu: String) -> void` *(deprecated)* — Sets the submenu of the item at the given `index`.
- `set_item_submenu_node(index: int, submenu: PopupMenu) -> void` — Sets the submenu of the item at the given `index`.
- `set_item_text(index: int, text: String) -> void` — Sets the text of the item at the given `index`.
- `set_item_text_direction(index: int, direction: Control.TextDirection) -> void` — Sets item's text base writing direction.
- `set_item_tooltip(index: int, tooltip: String) -> void` — Sets the String tooltip of the item at the given `index`.
- `toggle_item_checked(index: int) -> void` — Toggles the check state of the item at the given `index`.
- `toggle_item_multistate(index: int) -> void` — Cycle to the next state of a multistate item.

## Signals

- `id_focused(id: int)` — Emitted when the user navigated to an item of some `id` using the `ProjectSettings.input/ui_up` or `ProjectSettings.input/ui_down` input action.
- `id_pressed(id: int)` — Emitted when an item of some `id` is pressed.
- `index_pressed(index: int)` — Emitted when an item of some `index` is pressed.
- `menu_changed()` — Emitted when any item is added, modified or removed.

## Theme items

- `font_accelerator_color: Color` (color) = `Color(0.7, 0.7, 0.7, 0.8)`
- `font_color: Color` (color) = `Color(0.875, 0.875, 0.875, 1)`
- `font_disabled_color: Color` (color) = `Color(0.4, 0.4, 0.4, 0.8)`
- `font_hover_color: Color` (color) = `Color(0.875, 0.875, 0.875, 1)`
- `font_outline_color: Color` (color) = `Color(0, 0, 0, 1)`
- `font_separator_color: Color` (color) = `Color(0.875, 0.875, 0.875, 1)`
- `font_separator_outline_color: Color` (color) = `Color(0, 0, 0, 1)`
- `gutter_compact: int` (constant) = `1`
- `h_separation: int` (constant) = `4`
- `icon_max_width: int` (constant) = `0`
- `indent: int` (constant) = `10`
- `item_end_padding: int` (constant) = `2`
- `item_start_padding: int` (constant) = `2`
- `outline_size: int` (constant) = `0`
- `search_bar_separation: int` (constant) = `4`
- `separator_outline_size: int` (constant) = `0`
- `v_separation: int` (constant) = `4`
- `font: Font` (font)
- `font_separator: Font` (font)
- `font_separator_size: int` (font_size)
- `font_size: int` (font_size)
- `checked: Texture2D` (icon)
- `checked_disabled: Texture2D` (icon)
- `indeterminate: Texture2D` (icon)
- `indeterminate_disabled: Texture2D` (icon)
- `radio_checked: Texture2D` (icon)
- `radio_checked_disabled: Texture2D` (icon)
- `radio_unchecked: Texture2D` (icon)
- `radio_unchecked_disabled: Texture2D` (icon)
- `search: Texture2D` (icon)
- `submenu: Texture2D` (icon)
- `submenu_mirrored: Texture2D` (icon)
- `unchecked: Texture2D` (icon)
- `unchecked_disabled: Texture2D` (icon)
- `item_activated_disabled_sound: AudioStream` (sound)
- `item_activated_sound: AudioStream` (sound)
- `item_hovered_sound: AudioStream` (sound)
- `hover: StyleBox` (style)
- `labeled_separator_left: StyleBox` (style)
- `labeled_separator_right: StyleBox` (style)
- `panel: StyleBox` (style)
- `separator: StyleBox` (style)
