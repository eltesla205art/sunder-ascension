# VisionOSXRInterface

**Inherits:** XRInterface

visionOS XR implementation for rendering in immersive mode, hand tracking, and controller tracking.

This is a visionOS XR implementation. It has three modules: - the CompositorServices module, to render with Godot in immersive mode - the hand tracking module, using Apple's ARKit - the spatial controller module, using Apple's ARKit and GCController. Those modules can be enabled/disabled independently. The rendering module uses the CompositorServices framework to render an Immersive scene.

## Properties

- `immersion_style: VisionOSXRInterface.ImmersionStyle` = `0` — Immersion style of the immersive scene.
- `persistent_system_overlays: VisionOSXRInterface.Visibility` = `0` — Visibility of the system overlays, such as the Home indicator.
- `upper_limb_visibility: VisionOSXRInterface.Visibility` = `0` — Visibility of the user's upper limbs.
- `xr_play_area_mode: XRInterface.PlayAreaMode` = `3` — 

## Enum ImmersionStyle

- `IMMERSION_STYLE_FULL = 0` — The rendered content replaces the passthrough view of the real environment.
- `IMMERSION_STYLE_MIXED = 1` — The rendered content is displayed along with the passthrough view of the real environment.
- `IMMERSION_STYLE_PROGRESSIVE = 2` — The rendered content is displayed in a portal whose immersion level the user controls with the Digital Crown.

## Enum Visibility

- `VISIBILITY_AUTOMATIC = 0` — The system decides whether the element is visible.
- `VISIBILITY_VISIBLE = 1` — The element is visible.
- `VISIBILITY_HIDDEN = 2` — The element is hidden.
