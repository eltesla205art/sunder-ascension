# Range

**Inherits:** Control

Abstract base class for controls that represent a number within a range.

Range is an abstract base class for controls that represent a number within a range, using a configured `step` and `page` size. See e.g. ScrollBar and Slider for examples of higher-level nodes using Range.

## Properties

- `allow_greater: bool` = `false` — If `true`, `value` may be greater than `max_value`.
- `allow_lesser: bool` = `false` — If `true`, `value` may be less than `min_value`.
- `exp_edit: bool` = `false` — If `true`, and `min_value` is greater or equal to `0`, `value` will be represented exponentially rather than linearly.
- `max_value: float` = `100.0` — Maximum value.
- `min_value: float` = `0.0` — Minimum value.
- `page: float` = `0.0` — Page size.
- `ratio: float` — The value mapped between 0 and 1.
- `rounded: bool` = `false` — If `true`, `value` will always be rounded to the nearest integer.
- `size_flags_vertical: Control.SizeFlags` = `0` — 
- `step: float` = `0.01` — If greater than `0.0`, `value` will always be rounded to a multiple of this property's value above `min_value`.
- `value: float` = `0.0` — Range's current value.

## Methods

- `_value_changed(new_value: float) -> void` *virtual* — Called when the Range's value is changed (following the same conditions as `value_changed`).
- `set_value_no_signal(value: float) -> void` — Sets the Range's current value to the specified `value`, without emitting the `value_changed` signal.
- `share(with: Node) -> void` — Binds two Ranges together along with any ranges previously grouped with either of them.
- `unshare() -> void` — Stops the Range from sharing its member variables with any other.

## Signals

- `changed()` — Emitted when `min_value`, `max_value`, `page`, or `step` change.
- `value_changed(value: float)` — Emitted when `value` changes.
