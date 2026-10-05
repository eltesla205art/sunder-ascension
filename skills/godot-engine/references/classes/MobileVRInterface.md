# MobileVRInterface

**Inherits:** XRInterface

Generic mobile VR implementation.

This is a generic mobile VR implementation where you need to provide details about the phone and HMD used. It does not rely on any existing framework. This is the most basic interface we have. For the best effect, you need a mobile phone with a gyroscope and accelerometer.

## Properties

- `display_to_lens: float` = `4.0` — The distance between the display and the lenses inside of the device in centimeters.
- `display_width: float` = `14.5` — The width of the display in centimeters.
- `eye_height: float` = `1.85` — The height at which the camera is placed in relation to the ground (i.e.
- `iod: float` = `6.0` — The interocular distance, also known as the interpupillary distance.
- `k1: float` = `0.215` — The k1 lens factor is one of the two constants that define the strength of the lens used and directly influences the lens distortion effect.
- `k2: float` = `0.215` — The k2 lens factor, see k1.
- `offset_rect: Rect2` = `Rect2(0, 0, 1, 1)` — Set the offset rect relative to the area being rendered.
- `oversample: float` = `1.5` — The oversample setting.
- `vrs_min_radius: float` = `20.0` — The minimum radius around the focal point where full quality is guaranteed if VRS is used as a percentage of screen size.
- `vrs_strength: float` = `1.0` — The strength used to calculate the VRS density map.
- `xr_play_area_mode: XRInterface.PlayAreaMode` = `1` —
