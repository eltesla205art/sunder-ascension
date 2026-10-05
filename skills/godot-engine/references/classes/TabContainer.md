# TabContainer

**Inherits:** Container

A container that creates a tab for each child control, displaying only the active tab's control.

Arranges child controls into a tabbed view, creating a tab for each one. The active tab's corresponding control is made visible, while all other child controls are hidden. Ignores non-control children. Note: The drawing of the clickable tabs is handled by this node; TabBar is not needed.

## Properties

- `all_tabs_in_front: bool` *(deprecated)* — This doesn't do anything.
- `clip_tabs: bool` = `true` — If `true`, tabs overflowing this node's width will be hidden, displaying two navigation buttons instead.
- `current_tab: int` = `-1` — The current tab index.
- `deselect_enabled: bool` = `false` — If `true`, all tabs can be deselected so that no tab is selected.
- `drag_to_rearrange_enabled: bool` = `false` — If `true`, tabs can be rearranged with mouse drag.
- `switch_on_drag_hover: bool` = `true` — If `true`, hovering over a tab while dragging something will switch to that tab.
- `tab_alignment: TabBar.AlignmentMode` = `0` — The position at which tabs will be placed.
- `tab_focus_mode: Control.FocusMode` = `2` — The focus access mode for the internal TabBar node.
- `tab_sizing: TabBar.SizingMode` = `0` — The sizing strategy used to determine tab widths.
- `tab_{index}/disabled: bool` = `false` — If `true`, the tab at `index` is disabled.
- `tab_{index}/hidden: bool` = `false` — If `true`, the tab at `index` is hidden.
- `tab_{index}/icon: Texture2D` — The title text of the tab at `index`.
- `tab_{index}/title: String` = `""` — The tooltip text of the tab at `index`.
- `tabs_position: TabContainer.TabPosition` = `0` — The horizontal alignment of the tabs.
- `tabs_rearrange_group: int` = `-1` — TabContainers with the same rearrange group ID will allow dragging the tabs between them.
- `tabs_visible: bool` = `true` — If `true`, tabs are visible.
- `use_hidden_tabs_for_min_size: bool` = `false` — If `true`, child Control nodes that are hidden have their minimum size take into account in the total, instead of only the currently visible one.

## Methods

- `get_current_tab_control() -> Control` *const* — Returns the child Control node located at the active tab index.
- `get_popup() -> Popup` *const* — Returns the Popup node instance if one has been set already with `set_popup`.
- `get_previous_tab() -> int` *const* — Returns the previously active tab index.
- `get_tab_bar() -> TabBar` *const* — Returns the TabBar contained in this container.
- `get_tab_button_icon(tab_idx: int) -> Texture2D` *const* — Returns the button icon from the tab at index `tab_idx`.
- `get_tab_control(tab_idx: int) -> Control` *const* — Returns the Control node from the tab at index `tab_idx`.
- `get_tab_count() -> int` *const* — Returns the number of tabs.
- `get_tab_icon(tab_idx: int) -> Texture2D` *const* — Returns the Texture2D for the tab at index `tab_idx` or `null` if the tab has no Texture2D.
- `get_tab_icon_max_width(tab_idx: int) -> int` *const* — Returns the maximum allowed width of the icon for the tab at index `tab_idx`.
- `get_tab_idx_at_point(point: Vector2) -> int` *const* — Returns the index of the tab at local coordinates `point`.
- `get_tab_idx_from_control(control: Control) -> int` *const* — Returns the index of the tab tied to the given `control`.
- `get_tab_metadata(tab_idx: int) -> Variant` *const* — Returns the metadata value set to the tab at index `tab_idx` using `set_tab_metadata`.
- `get_tab_title(tab_idx: int) -> String` *const* — Returns the title of the tab at index `tab_idx`.
- `get_tab_tooltip(tab_idx: int) -> String` *const* — Returns the tooltip text of the tab at index `tab_idx`.
- `is_tab_disabled(tab_idx: int) -> bool` *const* — Returns `true` if the tab at index `tab_idx` is disabled.
- `is_tab_hidden(tab_idx: int) -> bool` *const* — Returns `true` if the tab at index `tab_idx` is hidden.
- `select_next_available() -> bool` — Selects the first available tab with greater index than the currently selected.
- `select_previous_available() -> bool` — Selects the first available tab with lower index than the currently selected.
- `set_popup(popup: Node) -> void` — If set on a Popup node instance, a popup menu icon appears in the top-right corner of the TabContainer (setting it to `null` will make it go away).
- `set_tab_button_icon(tab_idx: int, icon: Texture2D) -> void` — Sets the button icon from the tab at index `tab_idx`.
- `set_tab_disabled(tab_idx: int, disabled: bool) -> void` — If `disabled` is `true`, disables the tab at index `tab_idx`, making it non-interactable.
- `set_tab_hidden(tab_idx: int, hidden: bool) -> void` — If `hidden` is `true`, hides the tab at index `tab_idx`, making it disappear from the tab area.
- `set_tab_icon(tab_idx: int, icon: Texture2D) -> void` — Sets an icon for the tab at index `tab_idx`.
- `set_tab_icon_max_width(tab_idx: int, width: int) -> void` — Sets the maximum allowed width of the icon for the tab at index `tab_idx`.
- `set_tab_metadata(tab_idx: int, metadata: Variant) -> void` — Sets the metadata value for the tab at index `tab_idx`, which can be retrieved later using `get_tab_metadata`.
- `set_tab_title(tab_idx: int, title: String) -> void` — Sets a custom title for the tab at index `tab_idx` (tab titles default to the name of the indexed child node).
- `set_tab_tooltip(tab_idx: int, tooltip: String) -> void` — Sets a custom tooltip text for tab at index `tab_idx`.

## Signals

- `active_tab_rearranged(idx_to: int)` — Emitted when the active tab is rearranged via mouse drag.
- `pre_popup_pressed()` — Emitted when the TabContainer's Popup button is clicked.
- `tab_button_pressed(tab: int)` — Emitted when the user clicks on the button icon on this tab.
- `tab_changed(tab: int)` — Emitted when switching to another tab.
- `tab_clicked(tab: int)` — Emitted when a tab is clicked, even if it is the current tab.
- `tab_hovered(tab: int)` — Emitted when a tab is hovered by the mouse.
- `tab_selected(tab: int)` — Emitted when a tab is selected via click, directional input, or script, even if it is the current tab.

## Enum TabPosition

- `POSITION_TOP = 0` — Places the tab bar at the top.
- `POSITION_BOTTOM = 1` — Places the tab bar at the bottom.
- `POSITION_MAX = 2` — Represents the size of the `TabPosition` enum.

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
- `icon_max_width: int` (constant) = `0`
- `icon_separation: int` (constant) = `4`
- `outline_size: int` (constant) = `0`
- `side_margin: int` (constant) = `8`
- `tab_separation: int` (constant) = `0`
- `font: Font` (font)
- `font_size: int` (font_size)
- `decrement: Texture2D` (icon)
- `decrement_highlight: Texture2D` (icon)
- `drop_mark: Texture2D` (icon)
- `increment: Texture2D` (icon)
- `increment_highlight: Texture2D` (icon)
- `menu: Texture2D` (icon)
- `menu_highlight: Texture2D` (icon)
- `drag_ended_sound: AudioStream` (sound)
- `drag_started_sound: AudioStream` (sound)
- `focus_sound: AudioStream` (sound)
- `hover_sound: AudioStream` (sound)
- `pressed_disabled_sound: AudioStream` (sound)
- `pressed_sound: AudioStream` (sound)
- `panel: StyleBox` (style)
- `tab_disabled: StyleBox` (style)
- `tab_focus: StyleBox` (style)
- `tab_hovered: StyleBox` (style)
- `tab_selected: StyleBox` (style)
- `tab_unselected: StyleBox` (style)
- `tabbar_background: StyleBox` (style)
