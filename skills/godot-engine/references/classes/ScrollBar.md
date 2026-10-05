# ScrollBar

**Inherits:** Range

Abstract base class for scrollbars.

Abstract base class for scrollbars, typically used to navigate through content that extends beyond the visible area of a control. Scrollbars are Range-based controls.

## Properties

- `custom_step: float` = `-1.0` — Overrides the step used when clicking increment and decrement buttons or when using arrow keys when the ScrollBar is focused.
- `focus_mode: Control.FocusMode` = `3` — 
- `step: float` = `0.0` — 

## Signals

- `scrolling()` — Emitted when the scrollbar is being scrolled.

## Theme items

- `icon_max_size: int` (constant) = `0`
- `decrement: Texture2D` (icon)
- `decrement_highlight: Texture2D` (icon)
- `decrement_pressed: Texture2D` (icon)
- `increment: Texture2D` (icon)
- `increment_highlight: Texture2D` (icon)
- `increment_pressed: Texture2D` (icon)
- `drag_ended_sound: AudioStream` (sound)
- `drag_started_sound: AudioStream` (sound)
- `value_change_rejected_sound: AudioStream` (sound)
- `value_changed_sound: AudioStream` (sound)
- `grabber: StyleBox` (style)
- `grabber_highlight: StyleBox` (style)
- `grabber_pressed: StyleBox` (style)
- `scroll: StyleBox` (style)
- `scroll_focus: StyleBox` (style)
