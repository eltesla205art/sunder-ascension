# TabBar

**Inherits:** Control

A control that provides a horizontal bar with tabs.

A control that provides a horizontal bar with tabs. Similar to TabContainer but is only in charge of drawing tabs, not interacting with children.

## Properties

- `clip_tabs: bool` = `true` — If `true`, tabs overflowing this node's width will be hidden, displaying two navigation buttons instead.
- `close_with_middle_mouse: bool` = `true` — If `true`, middle-clicking on a tab will emit the `tab_close_pressed` signal.
- `current_tab: int` = `-1` — The index of the current selected tab.
- `deselect_enabled: bool` = `false` — If `true`, all tabs can be deselected so that no tab is selected.
- `drag_to_rearrange_enabled: bool` = `false` — If `true`, tabs can be rearranged with mouse drag.
- `focus_mode: Control.FocusMode` = `2` — 
- `max_tab_width: int` = `0` — Sets the maximum width which all tabs should be limited to.
- `scroll_to_selected: bool` = `true` — If `true`, the tab offset will be changed to keep the currently selected tab visible.
- `scrolling_enabled: bool` = `true` — if `true`, the mouse's scroll wheel can be used to navigate the scroll view.
- `select_with_rmb: bool` = `false` — If `true`, enables selecting a tab with the right mouse button.
- `switch_on_drag_hover: bool` = `true` — If `true`, hovering over a tab while dragging something will switch to that tab.
- `tab_alignment: TabBar.AlignmentMode` = `0` — The horizontal alignment of the tabs.
- `tab_close_display_policy: TabBar.CloseButtonDisplayPolicy` = `0` — When the close button will appear on the tabs.
- `tab_count: int` = `0` — The number of tabs currently in the bar.
- `tab_sizing: TabBar.SizingMode` = `0` — The sizing strategy used to determine tab widths.
- `tab_{index}/disabled: bool` = `false` — If `true`, the tab at `index` is disabled.
- `tab_{index}/icon: Texture2D` — If `true`, the tab at `index` is hidden.
- `tab_{index}/title: String` = `""` — The title text of the tab at `index`.
- `tab_{index}/tooltip: String` = `""` — The tooltip text of the tab at `index`.
- `tabs_rearrange_group: int` = `-1` — TabBars with the same rearrange group ID will allow dragging the tabs between them.

## Methods

- `add_tab(title: String = "", icon: Texture2D = null) -> void` — Adds a new tab.
- `clear_tabs() -> void` — Clears all tabs.
- `ensure_tab_visible(idx: int) -> void` — Moves the scroll view to make the tab visible.
- `get_offset_buttons_visible() -> bool` *const* — Returns `true` if the offset buttons (the ones that appear when there's not enough space for all tabs) are visible.
- `get_previous_tab() -> int` *const* — Returns the previously active tab index.
- `get_tab_button_icon(tab_idx: int) -> Texture2D` *const* — Returns the icon for the right button of the tab at index `tab_idx` or `null` if the right button has no icon.
- `get_tab_icon(tab_idx: int) -> Texture2D` *const* — Returns the icon for the tab at index `tab_idx` or `null` if the tab has no icon.
- `get_tab_icon_max_width(tab_idx: int) -> int` *const* — Returns the maximum allowed width of the icon for the tab at index `tab_idx`.
- `get_tab_idx_at_point(point: Vector2) -> int` *const* — Returns the index of the tab at local coordinates `point`.
- `get_tab_language(tab_idx: int) -> String` *const* — Returns tab title language code.
- `get_tab_metadata(tab_idx: int) -> Variant` *const* — Returns the metadata value set to the tab at index `tab_idx` using `set_tab_metadata`.
- `get_tab_offset() -> int` *const* — Returns the number of hidden tabs offsetted to the left.
- `get_tab_rect(tab_idx: int) -> Rect2` *const* — Returns tab Rect2 with local position and size.
- `get_tab_text_direction(tab_idx: int) -> int[Control.TextDirection]` *const* — Returns tab title text base writing direction.
- `get_tab_title(tab_idx: int) -> String` *const* — Returns the title of the tab at index `tab_idx`.
- `get_tab_tooltip(tab_idx: int) -> String` *const* — Returns the tooltip text of the tab at index `tab_idx`.
- `is_tab_disabled(tab_idx: int) -> bool` *const* — Returns `true` if the tab at index `tab_idx` is disabled.
- `is_tab_hidden(tab_idx: int) -> bool` *const* — Returns `true` if the tab at index `tab_idx` is hidden.
- `move_tab(from: int, to: int) -> void` — Moves a tab from `from` to `to`.
- `remove_tab(tab_idx: int) -> void` — Removes the tab at index `tab_idx`.
- `select_next_available() -> bool` — Selects the first available tab with greater index than the currently selected.
- `select_previous_available() -> bool` — Selects the first available tab with lower index than the currently selected.
- `set_tab_button_icon(tab_idx: int, icon: Texture2D) -> void` — Sets an `icon` for the button of the tab at index `tab_idx` (located to the right, before the close button), making it visible and clickable (See `tab_button_pressed`).
- `set_tab_disabled(tab_idx: int, disabled: bool) -> void` — If `disabled` is `true`, disables the tab at index `tab_idx`, making it non-interactable.
- `set_tab_hidden(tab_idx: int, hidden: bool) -> void` — If `hidden` is `true`, hides the tab at index `tab_idx`, making it disappear from the tab area.
- `set_tab_icon(tab_idx: int, icon: Texture2D) -> void` — Sets an `icon` for the tab at index `tab_idx`.
- `set_tab_icon_max_width(tab_idx: int, width: int) -> void` — Sets the maximum allowed width of the icon for the tab at index `tab_idx`.
- `set_tab_language(tab_idx: int, language: String) -> void` — Sets the language code of the title for the tab at index `tab_idx` to `language`.
- `set_tab_metadata(tab_idx: int, metadata: Variant) -> void` — Sets the metadata value for the tab at index `tab_idx`, which can be retrieved later using `get_tab_metadata`.
- `set_tab_text_direction(tab_idx: int, direction: Control.TextDirection) -> void` — Sets tab title base writing direction.
- `set_tab_title(tab_idx: int, title: String) -> void` — Sets a `title` for the tab at index `tab_idx`.
- `set_tab_tooltip(tab_idx: int, tooltip: String) -> void` — Sets a `tooltip` for tab at index `tab_idx`.

## Signals

- `active_tab_rearranged(idx_to: int)` — Emitted when the active tab is rearranged via mouse drag.
- `tab_button_pressed(tab: int)` — Emitted when a tab's right button is pressed.
- `tab_changed(tab: int)` — Emitted when switching to another tab.
- `tab_clicked(tab: int)` — Emitted when a tab is clicked, even if it is the current tab.
- `tab_close_pressed(tab: int)` — Emitted when a tab's close button is pressed or, if `close_with_middle_mouse` is `true`, when middle-clicking on a tab.
- `tab_hovered(tab: int)` — Emitted when a tab is hovered by the mouse.
- `tab_rmb_clicked(tab: int)` — Emitted when a tab is right-clicked.
- `tab_selected(tab: int)` — Emitted when a tab is selected via click, directional input, or script, even if it is the current tab.

## Enum AlignmentMode

- `ALIGNMENT_LEFT = 0` — Aligns tabs to the left.
- `ALIGNMENT_CENTER = 1` — Aligns tabs in the middle.
- `ALIGNMENT_RIGHT = 2` — Aligns tabs to the right.
- `ALIGNMENT_MAX = 3` — Represents the size of the `AlignmentMode` enum.

## Enum SizingMode

- `TAB_SIZING_FIT_CONTENT = 0` — Size tabs individually according to the size of their content.
- `TAB_SIZING_UNIFORM = 1` — Size tabs uniformly, with the widest tab determining the size of all tabs.
- `TAB_SIZING_JUSTIFY = 2` — Size tabs individually according to their content, expanding to the full width of the tab bar.
- `TAB_SIZING_EXPAND = 3` — Size tabs equally, expanding to the full width of the tab bar if there is room, otherwise fall back to `TAB_SIZING_FIT_CONTENT`.
- `TAB_SIZING_MAX = 4` — Represents the size of the `SizingMode` enum.

## Enum CloseButtonDisplayPolicy

- `CLOSE_BUTTON_SHOW_NEVER = 0` — Never show the close buttons.
- `CLOSE_BUTTON_SHOW_ACTIVE_ONLY = 1` — Only show the close button on the currently active tab.
- `CLOSE_BUTTON_SHOW_ALWAYS = 2` — Show the close button on all tabs.
- `CLOSE_BUTTON_MAX = 3` — Represents the size of the `CloseButtonDisplayPolicy` enum.

## Theme items

- `drop_mark_color: Color` (color) = `Color(1, 1, 1, 1)`
- `font_disabled_color: Color` (color) = `Color(0.875, 0.875, 0.875, 0.5)`
- `font_hovered_color: Color` (color) = `Color(0.95, 0.95, 0.95, 1)`
- `font_outline_color: Color` (color) = `Color(0, 0, 0, 1)`
- `font_selected_color: Color` (color) = `Color(0.95, 0.95, 0.95, 1)`
- `font_unselected_color: Color` (color) = `Color(0.7, 0.7, 0.7, 1)`
- `icon_disabled_color: Color` (color) = `Color(1, 1, 1, 1)`
- `icon_hovered_color: Color` (color) = `Color(1, 1, 1, 1)`
- `icon_selected_color: Color` (color) = `Color(1, 1, 1, 1)`
- `icon_unselected_color: Color` (color) = `Color(1, 1, 1, 1)`
- `h_separation: int` (constant) = `4`
- `hover_switch_wait_msec: int` (constant) = `500`
- `icon_max_width: int` (constant) = `0`
- `outline_size: int` (constant) = `0`
- `tab_separation: int` (constant) = `0`
- `font: Font` (font)
- `font_size: int` (font_size)
- `close: Texture2D` (icon)
- `decrement: Texture2D` (icon)
- `decrement_highlight: Texture2D` (icon)
- `drop_mark: Texture2D` (icon)
- `increment: Texture2D` (icon)
- `increment_highlight: Texture2D` (icon)
- `drag_ended_sound: AudioStream` (sound)
- `drag_started_sound: AudioStream` (sound)
- `focus_sound: AudioStream` (sound)
- `hover_sound: AudioStream` (sound)
- `pressed_disabled_sound: AudioStream` (sound)
- `pressed_sound: AudioStream` (sound)
- `button_highlight: StyleBox` (style)
- `button_pressed: StyleBox` (style)
- `tab_disabled: StyleBox` (style)
- `tab_focus: StyleBox` (style)
- `tab_hovered: StyleBox` (style)
- `tab_selected: StyleBox` (style)
- `tab_unselected: StyleBox` (style)
