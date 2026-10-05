# FoldableContainer

**Inherits:** Container

A container that can be expanded/collapsed.

A container that can be expanded/collapsed, with a title that can be filled with controls, such as buttons. This is also called an accordion. The title can be positioned at the top or bottom of the container. The container can be expanded or collapsed by clicking the title or by pressing `ui_accept` when focused.

## Properties

- `focus_mode: Control.FocusMode` = `2` — 
- `foldable_group: FoldableGroup` — The FoldableGroup associated with the container.
- `folded: bool` = `false` — If `true`, the container will become folded and will hide all its children.
- `language: String` = `""` — Language code used for text shaping algorithms.
- `mouse_filter: Control.MouseFilter` = `0` — 
- `title: String` = `""` — The container's title text.
- `title_alignment: HorizontalAlignment` = `0` — Title's horizontal text alignment.
- `title_position: FoldableContainer.TitlePosition` = `0` — Title's position.
- `title_text_direction: Control.TextDirection` = `0` — Title text writing direction.
- `title_text_overrun_behavior: TextServer.OverrunBehavior` = `0` — Defines the behavior of the title when the text is longer than the available space.

## Methods

- `add_title_bar_control(control: Control) -> void` — Adds a Control that will be placed next to the container's title, obscuring the clickable area.
- `expand() -> void` — Expands the container and emits `folding_changed`.
- `fold() -> void` — Folds the container and emits `folding_changed`.
- `get_title_bar_control(index: int) -> Control` *const* — Returns the title bar Control at the given `index`, or `null` if the index is out of bounds.
- `get_title_bar_control_count() -> int` *const* — Returns the number of controls added to the title bar via `add_title_bar_control`.
- `remove_title_bar_control(control: Control) -> void` — Removes a Control added with `add_title_bar_control`.

## Signals

- `folding_changed(is_folded: bool)` — Emitted when the container is folded/expanded.

## Enum TitlePosition

- `POSITION_TOP = 0` — Makes the title appear at the top of the container.
- `POSITION_BOTTOM = 1` — Makes the title appear at the bottom of the container.

## Theme items

- `collapsed_font_color: Color` (color) = `Color(1, 1, 1, 1)`
- `font_color: Color` (color) = `Color(0.875, 0.875, 0.875, 1)`
- `font_outline_color: Color` (color) = `Color(1, 1, 1, 1)`
- `hover_font_color: Color` (color) = `Color(0.95, 0.95, 0.95, 1)`
- `h_separation: int` (constant) = `2`
- `icon_max_width: int` (constant) = `0`
- `outline_size: int` (constant) = `0`
- `font: Font` (font)
- `font_size: int` (font_size)
- `expanded_arrow: Texture2D` (icon)
- `expanded_arrow_mirrored: Texture2D` (icon)
- `folded_arrow: Texture2D` (icon)
- `folded_arrow_mirrored: Texture2D` (icon)
- `expanded_sound: AudioStream` (sound)
- `focus_sound: AudioStream` (sound)
- `folded_sound: AudioStream` (sound)
- `focus: StyleBox` (style)
- `panel: StyleBox` (style)
- `title_collapsed_hover_panel: StyleBox` (style)
- `title_collapsed_panel: StyleBox` (style)
- `title_hover_panel: StyleBox` (style)
- `title_panel: StyleBox` (style)
