# Slider

**Inherits:** Range

Abstract base class for sliders.

Abstract base class for sliders, used to adjust a value by moving a grabber along a horizontal or vertical axis. Sliders are Range-based controls.

## Properties

- `editable: bool` = `true` — If `true`, the slider can be interacted with.
- `focus_mode: Control.FocusMode` = `2` — 
- `scrollable: bool` = `true` — If `true`, the value can be changed using the mouse wheel.
- `step: float` = `1.0` — 
- `tick_count: int` = `0` — Number of ticks displayed on the slider, including border ticks.
- `ticks_on_borders: bool` = `false` — If `true`, the slider will display ticks for minimum and maximum values.
- `ticks_position: Slider.TickPosition` = `0` — Sets the position of the ticks.

## Signals

- `drag_ended(value_changed: bool)` — Emitted when the grabber stops being dragged.
- `drag_started()` — Emitted when the grabber starts being dragged.

## Enum TickPosition

- `TICK_POSITION_BOTTOM_RIGHT = 0` — Places the ticks at the bottom of the HSlider, or right of the VSlider.
- `TICK_POSITION_TOP_LEFT = 1` — Places the ticks at the top of the HSlider, or left of the VSlider.
- `TICK_POSITION_BOTH = 2` — Places the ticks at the both sides of the slider.
- `TICK_POSITION_CENTER = 3` — Places the ticks at the center of the slider.

## Theme items

- `center_grabber: int` (constant) = `0`
- `grabber_max_size: int` (constant) = `0`
- `grabber_offset: int` (constant) = `0`
- `tick_max_size: int` (constant) = `0`
- `tick_offset: int` (constant) = `0`
- `grabber: Texture2D` (icon)
- `grabber_disabled: Texture2D` (icon)
- `grabber_highlight: Texture2D` (icon)
- `tick: Texture2D` (icon)
- `drag_ended_sound: AudioStream` (sound)
- `drag_started_sound: AudioStream` (sound)
- `focus_sound: AudioStream` (sound)
- `value_change_rejected_sound: AudioStream` (sound)
- `value_changed_sound: AudioStream` (sound)
- `grabber_area: StyleBox` (style)
- `grabber_area_highlight: StyleBox` (style)
- `slider: StyleBox` (style)
