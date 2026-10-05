# XRPose

**Inherits:** RefCounted

This object contains all data related to a pose on a tracked object.

XR runtimes often identify multiple locations on devices such as controllers that are spatially tracked. Orientation, location, linear velocity and angular velocity are all provided for each pose by the XR runtime. This object contains this state of a pose.

## Properties

- `angular_velocity: Vector3` = `Vector3(0, 0, 0)` — The angular velocity for this pose.
- `has_tracking_data: bool` = `false` — If `true` our tracking data is up to date.
- `linear_velocity: Vector3` = `Vector3(0, 0, 0)` — The linear velocity of this pose.
- `name: StringName` = `&""` — The name of this pose.
- `tracking_confidence: XRPose.TrackingConfidence` = `0` — The tracking confidence for this pose, provides insight on how accurate the spatial positioning of this record is.
- `transform: Transform3D` = `Transform3D(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)` — The transform containing the original and transform as reported by the XR runtime.

## Methods

- `get_adjusted_transform() -> Transform3D` *const* — Returns the `transform` with world scale and our reference frame applied.

## Enum TrackingConfidence

- `XR_TRACKING_CONFIDENCE_NONE = 0` — No tracking information is available for this pose.
- `XR_TRACKING_CONFIDENCE_LOW = 1` — Tracking information may be inaccurate or estimated.
- `XR_TRACKING_CONFIDENCE_HIGH = 2` — Tracking information is considered accurate and up to date.
