# OpenXRFrameSynthesisExtension

**Inherits:** OpenXRExtensionWrapper

The OpenXR Frame synthesis extension allows for advanced reprojection at low(er) framerates.

This class implements the OpenXR Frame synthesis extension. When enabled in the project settings and supported by the XR runtime in use, frame synthesis uses advanced reprojection techniques to inject additional frames so that your XR experience hits the full frame rate of the device.

## Properties

- `enabled: bool` = `false` — Enable frame synthesis.
- `relax_frame_interval: bool` = `false` — If `true` this informs the XR runtime we will be providing frames at a greatly reduced rate.

## Methods

- `is_available() -> bool` *const* — Returns `true` if frame synthesis is enabled in the project settings and the current XR runtime supports frame synthesis.
- `skip_next_frame() -> void` — Queues the next frame to be skipped when supplying motion vector and depth data.
