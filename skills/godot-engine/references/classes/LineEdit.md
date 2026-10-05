# LineEdit

**Inherits:** Control

An input field for single-line text.

LineEdit provides an input field for editing a single line of text. - When the LineEdit control is focused using the keyboard arrow keys, it will only gain focus and not enter edit mode. - To enter edit mode, click on the control with the mouse, see also `keep_editing_on_text_submit`. - To exit edit mode, press `ui_text_submit` or `ui_cancel` (by default `Escape`) actions. - Check `edit`, `unedit`, `is_editing`, and `editing_toggled` for more information. While entering text, it is possible to insert special characters using Unicode, OEM or Windows alt codes: - To enter Unicode codepoints, hold `Alt` and type the codepoint on the numpad. For example, to enter the character `á` (U+00E1), hold `Alt` and type `+E1` on the numpad (the leading zeroes can be omitted). - To enter OEM codepoints, hold `Alt` and type the code on the numpad. For example, to enter the character `á` (OEM 160), hold `Alt` and type `160` on the numpad. - To enter Windows codepoints, hold `Alt` and type the code on the numpad.

## Properties

- `alignment: HorizontalAlignment` = `0` — The text's horizontal alignment.
- `backspace_deletes_composite_character_enabled: bool` = `false` — If `true` and `caret_mid_grapheme` is `false`, backspace deletes an entire composite character such as ❤️‍🩹, instead of deleting part of the composite character.
- `caret_blink: bool` = `false` — If `true`, makes the caret blink.
- `caret_blink_interval: float` = `0.65` — The interval at which the caret blinks (in seconds).
- `caret_column: int` = `0` — The caret's column position inside the LineEdit.
- `caret_force_displayed: bool` = `false` — If `true`, the LineEdit will always show the caret, even if not editing or focus is lost.
- `caret_mid_grapheme: bool` = `false` — Allow moving caret, selecting and removing the individual composite character components.
- `clear_button_enabled: bool` = `false` — If `true`, the LineEdit will show a clear button if `text` is not empty, which can be used to clear the text quickly.
- `context_menu_enabled: bool` = `true` — If `true`, the context menu will appear when right-clicked.
- `deselect_on_focus_loss_enabled: bool` = `true` — If `true`, the selected text will be deselected when focus is lost.
- `drag_and_drop_selection_enabled: bool` = `true` — If `true`, allow drag and drop of selected text.
- `draw_control_chars: bool` = `false` — If `true`, control characters are displayed.
- `editable: bool` = `true` — If `false`, existing text cannot be modified and new text cannot be added.
- `emoji_menu_enabled: bool` = `true` — If `true`, "Emoji and Symbols" menu is enabled.
- `expand_to_text_length: bool` = `false` — If `true`, the LineEdit width will increase to stay longer than the `text`.
- `flat: bool` = `false` — If `true`, the LineEdit doesn't display decoration.
- `focus_mode: Control.FocusMode` = `2` — 
- `icon_expand_mode: LineEdit.ExpandMode` = `0` — Define the scaling behavior of the `right_icon`.
- `keep_editing_on_text_submit: bool` = `false` — If `true`, the LineEdit will not exit edit mode when text is submitted by pressing `ui_text_submit` action (by default: `Enter` or `Kp Enter`).
- `language: String` = `""` — Language code used for line-breaking and text shaping algorithms.
- `max_length: int` = `0` — Maximum number of characters that can be entered inside the LineEdit.
- `middle_mouse_paste_enabled: bool` = `true` — If `false`, using middle mouse button to paste clipboard will be disabled.
- `mouse_default_cursor_shape: Control.CursorShape` = `1` — 
- `placeholder_text: String` = `""` — Text shown when the LineEdit is empty.
- `right_icon: Texture2D` — Sets the icon that will appear in the right end of the LineEdit if there's no `text`, or always, if `clear_button_enabled` is set to `false`.
- `right_icon_scale: float` = `1.0` — Scale ratio of the icon when `icon_expand_mode` is set to `EXPAND_MODE_FIT_TO_LINE_EDIT`.
- `secret: bool` = `false` — If `true`, every character is replaced with the secret character (see `secret_character`).
- `secret_character: String` = `"•"` — The character to use to mask secret input.
- `select_all_on_focus: bool` = `false` — If `true`, the LineEdit will select the whole text when it gains focus.
- `selecting_enabled: bool` = `true` — If `false`, it's impossible to select the text using mouse nor keyboard.
- `shortcut_keys_enabled: bool` = `true` — If `true`, shortcut keys for context menu items are enabled, even if the context menu is disabled.
- `structured_text_bidi_override: TextServer.StructuredTextParser` = `0` — Set BiDi algorithm override for the structured text.
- `structured_text_bidi_override_options: Array` = `[]` — Set additional options for BiDi override.
- `text: String` = `""` — String value of the LineEdit.
- `text_direction: Control.TextDirection` = `0` — Base text writing direction.
- `virtual_keyboard_enabled: bool` = `true` — If `true`, the native virtual keyboard is enabled on platforms that support it.
- `virtual_keyboard_show_on_focus: bool` = `true` — If `true`, the native virtual keyboard is shown on focus events on platforms that support it.
- `virtual_keyboard_type: LineEdit.VirtualKeyboardType` = `0` — Specifies the type of virtual keyboard to show.

## Methods

- `apply_ime() -> void` — Applies text from the Input Method Editor (IME) and closes the IME if it is open.
- `cancel_ime() -> void` — Closes the Input Method Editor (IME) if it is open.
- `clear() -> void` — Erases the LineEdit's `text`.
- `delete_char_at_caret() -> void` — Deletes one character at the caret's current position (equivalent to pressing `Delete`).
- `delete_text(from_column: int, to_column: int) -> void` — Deletes a section of the `text` going from position `from_column` to `to_column`.
- `deselect() -> void` — Clears the current selection.
- `edit(hide_focus: bool = false) -> void` — Allows entering edit mode whether the LineEdit is focused or not.
- `get_menu() -> PopupMenu` *const* — Returns the PopupMenu of this LineEdit.
- `get_next_composite_character_column(column: int) -> int` *const* — Returns the correct column at the end of a composite character like ❤️‍🩹 (mending heart; Unicode: `U+2764 U+FE0F U+200D U+1FA79`) which is comprised of more than one Unicode code point, if the caret is at the start of the composite character.
- `get_previous_composite_character_column(column: int) -> int` *const* — Returns the correct column at the start of a composite character like ❤️‍🩹 (mending heart; Unicode: `U+2764 U+FE0F U+200D U+1FA79`) which is comprised of more than one Unicode code point, if the caret is at the end of the composite character.
- `get_scroll_offset() -> float` *const* — Returns the scroll offset due to `caret_column`, as a number of characters.
- `get_selected_text() -> String` — Returns the text inside the selection.
- `get_selection_from_column() -> int` *const* — Returns the selection begin column.
- `get_selection_to_column() -> int` *const* — Returns the selection end column.
- `has_ime_text() -> bool` *const* — Returns `true` if the user has text in the Input Method Editor (IME).
- `has_redo() -> bool` *const* — Returns `true` if a "redo" action is available.
- `has_selection() -> bool` *const* — Returns `true` if the user has selected text.
- `has_undo() -> bool` *const* — Returns `true` if an "undo" action is available.
- `insert_text_at_caret(text: String) -> void` — Inserts `text` at the caret.
- `is_editing() -> bool` *const* — Returns whether the LineEdit is being edited.
- `is_menu_visible() -> bool` *const* — Returns whether the menu is visible.
- `menu_option(option: int) -> void` — Executes a given action as defined in the `MenuItems` enum.
- `select(from: int = 0, to: int = -1) -> void` — Selects characters inside LineEdit between `from` and `to`.
- `select_all() -> void` — Selects the whole String.
- `unedit() -> void` — Allows exiting edit mode while preserving focus.

## Signals

- `editing_toggled(toggled_on: bool)` — Emitted when the LineEdit switches in or out of edit mode.
- `text_change_rejected(rejected_substring: String)` — Emitted when appending text that overflows the `max_length`.
- `text_changed(new_text: String)` — Emitted when the text changes.
- `text_submitted(new_text: String)` — Emitted when the user presses the `ui_text_submit` action (by default: `Enter` or `Kp Enter`) while the LineEdit has focus.

## Enum MenuItems

- `MENU_CUT = 0` — Cuts (copies and clears) the selected text.
- `MENU_COPY = 1` — Copies the selected text.
- `MENU_PASTE = 2` — Pastes the clipboard text over the selected text (or at the caret's position).
- `MENU_CLEAR = 3` — Erases the whole LineEdit text.
- `MENU_SELECT_ALL = 4` — Selects the whole LineEdit text.
- `MENU_UNDO = 5` — Undoes the previous action.
- `MENU_REDO = 6` — Reverse the last undo action.
- `MENU_SUBMENU_TEXT_DIR = 7` — ID of "Text Writing Direction" submenu.
- `MENU_DIR_INHERITED = 8` — Sets text direction to inherited.
- `MENU_DIR_AUTO = 9` — Sets text direction to automatic.
- `MENU_DIR_LTR = 10` — Sets text direction to left-to-right.
- `MENU_DIR_RTL = 11` — Sets text direction to right-to-left.
- `MENU_DISPLAY_UCC = 12` — Toggles control character display.
- `MENU_SUBMENU_INSERT_UCC = 13` — ID of "Insert Control Character" submenu.
- `MENU_INSERT_LRM = 14` — Inserts left-to-right mark (LRM) character.
- `MENU_INSERT_RLM = 15` — Inserts right-to-left mark (RLM) character.
- `MENU_INSERT_LRE = 16` — Inserts start of left-to-right embedding (LRE) character.
- `MENU_INSERT_RLE = 17` — Inserts start of right-to-left embedding (RLE) character.
- `MENU_INSERT_LRO = 18` — Inserts start of left-to-right override (LRO) character.
- `MENU_INSERT_RLO = 19` — Inserts start of right-to-left override (RLO) character.
- `MENU_INSERT_PDF = 20` — Inserts pop direction formatting (PDF) character.
- `MENU_INSERT_ALM = 21` — Inserts Arabic letter mark (ALM) character.
- `MENU_INSERT_LRI = 22` — Inserts left-to-right isolate (LRI) character.
- `MENU_INSERT_RLI = 23` — Inserts right-to-left isolate (RLI) character.
- `MENU_INSERT_FSI = 24` — Inserts first strong isolate (FSI) character.
- `MENU_INSERT_PDI = 25` — Inserts pop direction isolate (PDI) character.
- `MENU_INSERT_ZWJ = 26` — Inserts zero width joiner (ZWJ) character.
- `MENU_INSERT_ZWNJ = 27` — Inserts zero width non-joiner (ZWNJ) character.
- `MENU_INSERT_WJ = 28` — Inserts word joiner (WJ) character.
- `MENU_INSERT_SHY = 29` — Inserts soft hyphen (SHY) character.
- `MENU_EMOJI_AND_SYMBOL = 30` — Opens system emoji and symbol picker.
- `MENU_MAX = 31` — Represents the size of the `MenuItems` enum.

## Enum VirtualKeyboardType

- `KEYBOARD_TYPE_DEFAULT = 0` — Default text virtual keyboard.
- `KEYBOARD_TYPE_MULTILINE = 1` — Multiline virtual keyboard.
- `KEYBOARD_TYPE_NUMBER = 2` — Virtual number keypad, useful for PIN entry.
- `KEYBOARD_TYPE_NUMBER_DECIMAL = 3` — Virtual number keypad, useful for entering fractional numbers.
- `KEYBOARD_TYPE_PHONE = 4` — Virtual phone number keypad.
- `KEYBOARD_TYPE_EMAIL_ADDRESS = 5` — Virtual keyboard with additional keys to assist with typing email addresses.
- `KEYBOARD_TYPE_PASSWORD = 6` — Virtual keyboard for entering a password.
- `KEYBOARD_TYPE_URL = 7` — Virtual keyboard with additional keys to assist with typing URLs.

## Enum ExpandMode

- `EXPAND_MODE_ORIGINAL_SIZE = 0` — Use the original size for the right icon.
- `EXPAND_MODE_FIT_TO_TEXT = 1` — Scale the right icon's size to match the size of the text.
- `EXPAND_MODE_FIT_TO_LINE_EDIT = 2` — Scale the right icon to fit the LineEdit.

## Theme items

- `caret_color: Color` (color) = `Color(0.95, 0.95, 0.95, 1)`
- `clear_button_color: Color` (color) = `Color(0.875, 0.875, 0.875, 1)`
- `clear_button_color_pressed: Color` (color) = `Color(1, 1, 1, 1)`
- `font_color: Color` (color) = `Color(0.875, 0.875, 0.875, 1)`
- `font_outline_color: Color` (color) = `Color(0, 0, 0, 1)`
- `font_placeholder_color: Color` (color) = `Color(0.875, 0.875, 0.875, 0.6)`
- `font_selected_color: Color` (color) = `Color(1, 1, 1, 1)`
- `font_uneditable_color: Color` (color) = `Color(0.875, 0.875, 0.875, 0.5)`
- `selection_color: Color` (color) = `Color(0.5, 0.5, 0.5, 1)`
- `caret_width: int` (constant) = `1`
- `minimum_character_width: int` (constant) = `4`
- `outline_size: int` (constant) = `0`
- `font: Font` (font)
- `font_size: int` (font_size)
- `clear: Texture2D` (icon)
- `caret_move_rejected_sound: AudioStream` (sound)
- `caret_moved_sound: AudioStream` (sound)
- `focus_sound: AudioStream` (sound)
- `text_change_rejected_sound: AudioStream` (sound)
- `text_changed_sound: AudioStream` (sound)
- `text_submitted_sound: AudioStream` (sound)
- `focus: StyleBox` (style)
- `normal: StyleBox` (style)
- `read_only: StyleBox` (style)
