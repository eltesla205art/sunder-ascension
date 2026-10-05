# ColorPicker

**Inherits:** VBoxContainer

A widget that provides an interface for selecting or modifying a color.

A widget that provides an interface for selecting or modifying a color. It can optionally provide functionalities like a color sampler (eyedropper), color modes, and presets. Note: This control is the color picker widget itself. You can use a ColorPickerButton instead if you need a button that brings up a ColorPicker in a popup.

## Properties

- `can_add_swatches: bool` = `true` — If `true`, it's possible to add presets under Swatches.
- `color: Color` = `Color(1, 1, 1, 1)` — The currently selected color.
- `color_mode: ColorPicker.ColorModeType` = `0` — The currently selected color mode.
- `color_modes_visible: bool` = `true` — If `true`, the color mode buttons are visible.
- `deferred_mode: bool` = `false` — If `true`, the color will apply only after the user releases the mouse button, otherwise it will apply immediately even in mouse motion event (which can cause performance issues).
- `edit_alpha: bool` = `true` — If `true`, shows an alpha channel slider (opacity).
- `edit_intensity: bool` = `true` — If `true`, shows an intensity slider.
- `hex_visible: bool` = `true` — If `true`, the hex color code input field is visible.
- `picker_shape: ColorPicker.PickerShapeType` = `0` — The shape of the color space view.
- `presets_visible: bool` = `true` — If `true`, the Swatches and Recent Colors presets are visible.
- `sampler_visible: bool` = `true` — If `true`, the color sampler and color preview are visible.
- `sliders_visible: bool` = `true` — If `true`, the color sliders are visible.

## Methods

- `add_preset(color: Color) -> void` — Adds the given color to a list of color presets.
- `add_recent_preset(color: Color) -> void` — Adds the given color to a list of color recent presets so that it can be picked later.
- `erase_preset(color: Color) -> void` — Removes the given color from the list of color presets of this color picker.
- `erase_recent_preset(color: Color) -> void` — Removes the given color from the list of color recent presets of this color picker.
- `get_presets() -> PackedColorArray` *const* — Returns the list of colors in the presets of the color picker.
- `get_recent_presets() -> PackedColorArray` *const* — Returns the list of colors in the recent presets of the color picker.

## Signals

- `color_changed(color: Color)` — Emitted when the color is changed.
- `preset_added(color: Color)` — Emitted when a preset is added.
- `preset_removed(color: Color)` — Emitted when a preset is removed.

## Enum ColorModeType

- `MODE_RGB = 0` — Allows editing the color with Red/Green/Blue sliders in sRGB color space.
- `MODE_HSV = 1` — Allows editing the color with Hue/Saturation/Value sliders.
- `MODE_RAW = 2` — 
- `MODE_LINEAR = 2` — Allows editing the color with Red/Green/Blue sliders in linear color space.
- `MODE_OKHSL = 3` — Allows editing the color with Hue/Saturation/Lightness sliders.

## Enum PickerShapeType

- `SHAPE_HSV_RECTANGLE = 0` — HSV Color Model rectangle color space.
- `SHAPE_HSV_WHEEL = 1` — HSV Color Model rectangle color space with a wheel.
- `SHAPE_VHS_CIRCLE = 2` — HSV Color Model circle color space.
- `SHAPE_OKHSL_CIRCLE = 3` — HSL OK Color Model circle color space.
- `SHAPE_NONE = 4` — The color space shape and the shape select button are hidden.
- `SHAPE_OK_HS_RECTANGLE = 5` — OKHSL Color Model rectangle with constant lightness.
- `SHAPE_OK_HL_RECTANGLE = 6` — OKHSL Color Model rectangle with constant saturation.

## Theme items

- `focused_not_editing_cursor_color: Color` (color) = `Color(1, 1, 1, 0.275)`
- `center_slider_grabbers: int` (constant) = `1`
- `h_width: int` (constant) = `30`
- `label_width: int` (constant) = `10`
- `margin: int` (constant) = `4`
- `sv_height: int` (constant) = `256`
- `sv_width: int` (constant) = `256`
- `add_preset: Texture2D` (icon)
- `bar_arrow: Texture2D` (icon)
- `color_copy: Texture2D` (icon)
- `color_hue: Texture2D` (icon)
- `color_script: Texture2D` (icon)
- `expanded_arrow: Texture2D` (icon)
- `folded_arrow: Texture2D` (icon)
- `menu_option: Texture2D` (icon)
- `overbright_indicator: Texture2D` (icon)
- `picker_cursor: Texture2D` (icon)
- `picker_cursor_bg: Texture2D` (icon)
- `sample_bg: Texture2D` (icon)
- `sample_revert: Texture2D` (icon)
- `screen_picker: Texture2D` (icon)
- `shape_circle: Texture2D` (icon)
- `shape_rect: Texture2D` (icon)
- `shape_rect_wheel: Texture2D` (icon)
- `picker_focus_circle: StyleBox` (style)
- `picker_focus_rectangle: StyleBox` (style)
- `sample_focus: StyleBox` (style)
