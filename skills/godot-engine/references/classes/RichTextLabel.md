# RichTextLabel

**Inherits:** Control

A control for displaying text that can contain different font styles, images, and basic formatting.

A control for displaying text that can contain custom fonts, images, and basic formatting. RichTextLabel manages these as an internal tag stack. It also adapts itself to given width/heights. Note: `newline`, `push_paragraph`, `"\n"`, `"\r\n"`, the `p` tag, and alignment tags start a new paragraph.

## Properties

- `autowrap_mode: TextServer.AutowrapMode` = `3` — If set to something other than `TextServer.AUTOWRAP_OFF`, the text gets wrapped inside the node's bounding rectangle.
- `autowrap_trim_flags: TextServer.LineBreakFlag` = `192` — Autowrap space trimming flags.
- `bbcode_enabled: bool` = `false` — If `true`, the label uses BBCode formatting.
- `clip_contents: bool` = `true` — 
- `context_menu_enabled: bool` = `false` — If `true`, a right-click displays the context menu.
- `custom_effects: Array` = `[]` — The currently installed custom effects.
- `deselect_on_focus_loss_enabled: bool` = `true` — If `true`, the selected text will be deselected when focus is lost.
- `drag_and_drop_selection_enabled: bool` = `true` — If `true`, allow drag and drop of selected text.
- `fit_content: bool` = `false` — If `true`, the label's minimum size will be automatically updated to fit its content, matching the behavior of Label.
- `focus_mode: Control.FocusMode` = `3` — 
- `hint_underlined: bool` = `true` — If `true`, the label underlines hint tags such as `[hint=description]{text}[/hint]`.
- `horizontal_alignment: HorizontalAlignment` = `0` — Controls the text's horizontal alignment.
- `justification_flags: TextServer.JustificationFlag` = `163` — Line fill alignment rules.
- `language: String` = `""` — Language code used for line-breaking and text shaping algorithms.
- `maximum_font_size: int` = `60` — The maximum font size used when `resize_font_to_fit` is enabled.
- `meta_underlined: bool` = `true` — If `true`, the label underlines meta tags such as `{text}`.
- `minimum_font_size: int` = `10` — The minimum font size used when `resize_font_to_fit` is enabled.
- `progress_bar_delay: int` = `1000` — The delay after which the loading progress bar is displayed, in milliseconds.
- `resize_font_to_fit: bool` = `false` — If `true`, the text size will automatically shrink or grow to fit within the node's bounding rectangle.
- `resource_access_flags: RichTextLabel.ResourceAccessFlag` = `3` — The set of locations BBCode is allowed to load resource files from.
- `scroll_active: bool` = `true` — If `true`, the scrollbar is visible.
- `scroll_following: bool` = `false` — If `true`, the window scrolls down to display new content automatically.
- `scroll_following_visible_characters: bool` = `false` — If `true`, the window scrolls to display the last visible line when `visible_characters` or `visible_ratio` is changed.
- `selection_enabled: bool` = `false` — If `true`, the label allows text selection.
- `shortcut_keys_enabled: bool` = `true` — If `true`, shortcut keys for context menu items are enabled, even if the context menu is disabled.
- `structured_text_bidi_override: TextServer.StructuredTextParser` = `0` — Set BiDi algorithm override for the structured text.
- `structured_text_bidi_override_options: Array` = `[]` — Set additional options for BiDi override.
- `tab_size: int` = `4` — The number of spaces associated with a single tab length.
- `tab_stops: PackedFloat32Array` = `PackedFloat32Array()` — Aligns text to the given tab-stops.
- `text: String` = `""` — The label's text in BBCode format.
- `text_direction: Control.TextDirection` = `0` — Base text writing direction.
- `threaded: bool` = `false` — If `true`, text processing is done in a background thread.
- `vertical_alignment: VerticalAlignment` = `0` — Controls the text's vertical alignment.
- `visible_characters: int` = `-1` — The number of characters to display.
- `visible_characters_behavior: TextServer.VisibleCharactersBehavior` = `0` — The clipping behavior when `visible_characters` or `visible_ratio` is set.
- `visible_ratio: float` = `1.0` — The fraction of characters to display, relative to the total number of characters (see `get_total_character_count`).

## Methods

- `add_hr(width: int = 90, height: int = 2, color: Color = Color(1, 1, 1, 1), alignment: HorizontalAlignment = 1, width_in_percent: bool = true, height_in_percent: bool = false) -> void` — Adds a horizontal rule that can be used to separate content.
- `add_image(image: Texture2D, width: float = 0, height: float = 0, color: Color = Color(1, 1, 1, 1), inline_align: InlineAlignment = 5, region: Rect2 = Rect2(0, 0, 0, 0), key: Variant = null, pad: bool = false, tooltip: String = "", width_unit: RichTextLabel.ImageUnit = 0, height_unit: RichTextLabel.ImageUnit = 0, alt_text: String = "") -> void` — Adds an image's opening and closing tags to the tag stack, optionally providing a `width` and `height` to resize the image, a `color` to tint the image and a `region` to only use parts of the image.
- `add_text(text: String) -> void` — Adds raw non-BBCode-parsed text to the tag stack.
- `append_text(bbcode: String) -> void` — Parses `bbcode` and adds tags to the tag stack as needed.
- `clear() -> void` — Clears the tag stack, causing the label to display nothing.
- `deselect() -> void` — Clears the current selection.
- `get_character_line(character: int) -> int` — Returns the line number of the character position provided.
- `get_character_paragraph(character: int) -> int` — Returns the paragraph number of the character position provided.
- `get_content_height() -> int` *const* — Returns the height of the content.
- `get_content_width() -> int` *const* — Returns the width of the content.
- `get_line_count() -> int` *const* — Returns the total number of lines in the text.
- `get_line_height(line: int) -> int` *const* — Returns the height of the line found at the provided index.
- `get_line_offset(line: int) -> float` — Returns the vertical offset of the line found at the provided index.
- `get_line_range(line: int) -> Vector2i` — Returns the indexes of the first and last visible characters for the given `line`, as a Vector2i.
- `get_line_width(line: int) -> int` *const* — Returns the width of the line found at the provided index.
- `get_menu() -> PopupMenu` *const* — Returns the PopupMenu of this RichTextLabel.
- `get_paragraph_count() -> int` *const* — Returns the total number of paragraphs (newlines or `p` tags in the tag stack's text tags).
- `get_paragraph_offset(paragraph: int) -> float` — Returns the vertical offset of the paragraph found at the provided index.
- `get_parsed_text() -> String` *const* — Returns the text without BBCode mark-up.
- `get_rendered_font_size() -> int` *const* — Returns the font size that is currently used for rendering.
- `get_selected_text() -> String` *const* — Returns the current selection text.
- `get_selection_from() -> int` *const* — Returns the current selection's first character index if a selection is active, `-1` otherwise.
- `get_selection_line_offset() -> float` *const* — Returns the current selection's vertical line offset if a selection is active, `-1.0` otherwise.
- `get_selection_to() -> int` *const* — Returns the current selection's last character index if a selection is active, `-1` otherwise.
- `get_total_character_count() -> int` *const* — Returns the total number of characters from text tags.
- `get_v_scroll_bar() -> VScrollBar` — Returns the vertical scrollbar.
- `get_visible_content_rect() -> Rect2i` *const* — Returns the bounding rectangle of the visible content.
- `get_visible_line_count() -> int` *const* — Returns the number of visible lines.
- `get_visible_paragraph_count() -> int` *const* — Returns the number of visible paragraphs.
- `install_effect(effect: Variant) -> void` — Installs a custom effect.
- `invalidate_paragraph(paragraph: int) -> bool` — Invalidates `paragraph` and all subsequent paragraphs cache.
- `is_finished() -> bool` *const* — If `threaded` is enabled, returns `true` if the background thread has finished text processing, otherwise always returns `true`.
- `is_menu_visible() -> bool` *const* — Returns whether the menu is visible.
- `is_ready() -> bool` *const* *(deprecated)* — If `threaded` is enabled, returns `true` if the background thread has finished text processing, otherwise always returns `true`.
- `menu_option(option: int) -> void` — Executes a given action as defined in the `MenuItems` enum.
- `newline() -> void` — Adds a newline tag to the tag stack.
- `parse_bbcode(bbcode: String) -> void` — The assignment version of `append_text`.
- `parse_expressions_for_values(expressions: PackedStringArray) -> Dictionary` — Parses BBCode parameter `expressions` into a dictionary.
- `pop() -> void` — Terminates the current tag.
- `pop_all() -> void` — Terminates all tags opened by `push_*` methods.
- `pop_context() -> void` — Terminates tags opened after the last `push_context` call (including context marker), or all tags if there's no context marker on the stack.
- `push_bgcolor(bgcolor: Color) -> void` — Adds a `bgcolor` tag to the tag stack.
- `push_bold() -> void` — Adds a `` tag with a bold font to the tag stack.
- `push_bold_italics() -> void` — Adds a `` tag with a bold italics font to the tag stack.
- `push_cell() -> void` — Adds a `` tag to the tag stack.
- `push_color(color: Color) -> void` — Adds a `` tag to the tag stack.
- `push_context() -> void` — Adds a context marker to the tag stack.
- `push_customfx(effect: RichTextEffect, env: Dictionary) -> void` — Adds a custom effect tag to the tag stack.
- `push_dropcap(string: String, font: Font, size: int, dropcap_margins: Rect2 = Rect2(0, 0, 0, 0), color: Color = Color(1, 1, 1, 1), outline_size: int = 0, outline_color: Color = Color(0, 0, 0, 0)) -> void` — Adds a `dropcap` tag to the tag stack.
- `push_fgcolor(fgcolor: Color) -> void` — Adds a `fgcolor` tag to the tag stack.
- `push_font(font: Font, font_size: int = 0) -> void` — Adds a `` tag to the tag stack.
- `push_font_size(font_size: int) -> void` — Adds a `font_size` tag to the tag stack.
- `push_hint(description: String) -> void` — Adds a `hint` tag to the tag stack.
- `push_indent(level: int) -> void` — Adds an `indent` tag to the tag stack.
- `push_italics() -> void` — Adds a `` tag with an italics font to the tag stack.
- `push_language(language: String) -> void` — Adds language code used for text shaping algorithm and Open-Type font features.
- `push_list(level: int, type: RichTextLabel.ListType, capitalize: bool, bullet: String = "•") -> void` — Adds `ol` or `ul` tag to the tag stack.
- `push_meta(data: Variant, underline_mode: RichTextLabel.MetaUnderline = 1, tooltip: String = "") -> void` — Adds a meta tag to the tag stack.
- `push_mono() -> void` — Adds a `` tag with a monospace font to the tag stack.
- `push_normal() -> void` — Adds a `` tag with a normal font to the tag stack.
- `push_outline_color(color: Color) -> void` — Adds a `outline_color` tag to the tag stack.
- `push_outline_size(outline_size: int) -> void` — Adds a `outline_size` tag to the tag stack.
- `push_paragraph(alignment: HorizontalAlignment, base_direction: Control.TextDirection = 0, language: String = "", st_parser: TextServer.StructuredTextParser = 0, justification_flags: TextServer.JustificationFlag = 163, tab_stops: PackedFloat32Array = PackedFloat32Array()) -> void` — Adds a `p` tag to the tag stack.
- `push_strikethrough(color: Color = Color(0, 0, 0, 0)) -> void` — Adds a `` tag to the tag stack.
- `push_table(columns: int, inline_align: InlineAlignment = 0, align_to_row: int = -1, name: String = "") -> void` — Adds a `` tag to the tag stack.
- `push_underline(color: Color = Color(0, 0, 0, 0)) -> void` — Adds a `` tag to the tag stack.
- `reload_effects() -> void` — Reloads custom effects.
- `remove_paragraph(paragraph: int, no_invalidate: bool = false) -> bool` — Removes a paragraph of content from the label.
- `scroll_to_line(line: int) -> void` — Scrolls the window's top line to match `line`.
- `scroll_to_paragraph(paragraph: int) -> void` — Scrolls the window's top line to match the first line of the `paragraph`.
- `scroll_to_selection() -> void` — Scrolls to the beginning of the current selection.
- `select_all() -> void` — Selects all the text.
- `set_cell_border_color(color: Color) -> void` — Sets the color of a table cell's border.
- `set_cell_padding(padding: Rect2) -> void` — Sets inner padding of a table cell.
- `set_cell_row_background_color(odd_row_bg: Color, even_row_bg: Color) -> void` — Sets the color of a table cell.
- `set_cell_size_override(min_size: Vector2, max_size: Vector2) -> void` — Sets minimum and maximum size overrides for a table cell.
- `set_table_column_expand(column: int, expand: bool, ratio: int = 1, shrink: bool = true) -> void` — Edits the selected column's expansion options.
- `set_table_column_name(column: int, name: String) -> void` — Sets table column name for assistive apps.
- `update_image(key: Variant, mask: RichTextLabel.ImageUpdateMask, image: Texture2D, width: float = 0, height: float = 0, color: Color = Color(1, 1, 1, 1), inline_align: InlineAlignment = 5, region: Rect2 = Rect2(0, 0, 0, 0), pad: bool = false, tooltip: String = "", width_unit: RichTextLabel.ImageUnit = 0, height_unit: RichTextLabel.ImageUnit = 0) -> void` — Updates the existing images with the key `key`.

## Signals

- `finished()` — Triggered when the document is fully loaded.
- `meta_clicked(meta: Variant)` — Triggered when the user clicks on content between meta (URL) tags.
- `meta_hover_ended(meta: Variant)` — Triggers when the mouse exits a meta tag.
- `meta_hover_started(meta: Variant)` — Triggers when the mouse enters a meta tag.

## Enum ListType

- `LIST_NUMBERS = 0` — Each list item has a number marker.
- `LIST_LETTERS = 1` — Each list item has a letter marker.
- `LIST_ROMAN = 2` — Each list item has a Roman numeral marker.
- `LIST_DOTS = 3` — Each list item has a filled circle marker.

## Enum MenuItems

- `MENU_COPY = 0` — Copies the selected text.
- `MENU_SELECT_ALL = 1` — Selects the whole RichTextLabel text.
- `MENU_MAX = 2` — Represents the size of the `MenuItems` enum.

## Enum MetaUnderline

- `META_UNDERLINE_NEVER = 0` — The meta tag does not display an underline, even if `meta_underlined` is `true`.
- `META_UNDERLINE_ALWAYS = 1` — If `meta_underlined` is `true`, the meta tag always displays an underline.
- `META_UNDERLINE_ON_HOVER = 2` — If `meta_underlined` is `true`, the meta tag displays an underline when hovered by the mouse cursor.

## Enum ImageUpdateMask

- `UPDATE_TEXTURE = 1` — If this bit is set, `update_image` changes image texture.
- `UPDATE_SIZE = 2` — If this bit is set, `update_image` changes image size.
- `UPDATE_COLOR = 4` — If this bit is set, `update_image` changes image color.
- `UPDATE_ALIGNMENT = 8` — If this bit is set, `update_image` changes image inline alignment.
- `UPDATE_REGION = 16` — If this bit is set, `update_image` changes image texture region.
- `UPDATE_PAD = 32` — If this bit is set, `update_image` changes image padding.
- `UPDATE_TOOLTIP = 64` — If this bit is set, `update_image` changes image tooltip.
- `UPDATE_WIDTH_UNIT = 128` — If this bit is set, `update_image` changes the units used to calculate image size.

## Enum ResourceAccessFlag

- `RESOURCE_ACCESS_RESOURCES = 1` — Allows accessing files under the Resource path (`res://`).
- `RESOURCE_ACCESS_USERDATA = 2` — Allows accessing files under the user data path (`user://`).
- `RESOURCE_ACCESS_FILESYSTEM = 4` — Allows accessing files on the whole local file system.
- `RESOURCE_ACCESS_PIPE = 8` — Allows accessing named pipes (`pipe://`).
- `RESOURCE_ACCESS_NETWORK = 16` — Allows accessing files on network shares.

## Enum ImageUnit

- `IMAGE_UNIT_PIXEL = 0` — Image size is given in pixels.
- `IMAGE_UNIT_PERCENT = 1` — Image size is given as a percentage of the RichTextLabel's width.
- `IMAGE_UNIT_EM = 2` — Image size is given as a multiplier of the surrounding font size.

## Theme items

- `default_color: Color` (color) = `Color(1, 1, 1, 1)`
- `font_outline_color: Color` (color) = `Color(0, 0, 0, 1)`
- `font_selected_color: Color` (color) = `Color(0, 0, 0, 0)`
- `font_shadow_color: Color` (color) = `Color(0, 0, 0, 0)`
- `selection_color: Color` (color) = `Color(0.1, 0.1, 1, 0.8)`
- `table_border: Color` (color) = `Color(0, 0, 0, 0)`
- `table_even_row_bg: Color` (color) = `Color(0, 0, 0, 0)`
- `table_odd_row_bg: Color` (color) = `Color(0, 0, 0, 0)`
- `line_separation: int` (constant) = `0`
- `outline_size: int` (constant) = `0`
- `paragraph_separation: int` (constant) = `0`
- `shadow_offset_x: int` (constant) = `1`
- `shadow_offset_y: int` (constant) = `1`
- `shadow_outline_size: int` (constant) = `1`
- `strikethrough_alpha: int` (constant) = `50`
- `table_h_separation: int` (constant) = `3`
- `table_v_separation: int` (constant) = `3`
- `text_highlight_h_padding: int` (constant) = `3`
- `text_highlight_v_padding: int` (constant) = `3`
- `underline_alpha: int` (constant) = `50`
- `bold_font: Font` (font)
- `bold_italics_font: Font` (font)
- `italics_font: Font` (font)
- `mono_font: Font` (font)
- `normal_font: Font` (font)
- `bold_font_size: int` (font_size)
- `bold_italics_font_size: int` (font_size)
- `italics_font_size: int` (font_size)
- `mono_font_size: int` (font_size)
- `normal_font_size: int` (font_size)
- `horizontal_rule: Texture2D` (icon)
- `focus: StyleBox` (style)
- `normal: StyleBox` (style)
