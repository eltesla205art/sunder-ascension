# OpenXRInterface

**Inherits:** XRInterface

Our OpenXR interface.

The OpenXR interface allows Godot to interact with OpenXR runtimes and make it possible to create XR experiences and games. Due to the needs of OpenXR this interface works slightly different than other plugin based XR interfaces. It needs to be initialized when Godot starts. You need to enable OpenXR, settings for this can be found in your games project settings under the XR heading.

## Properties

- `display_refresh_rate: float` = `0.0` — The display refresh rate for the current HMD.
- `foveation_dynamic: bool` = `false` — If `true`, enables dynamic foveation adjustment.
- `foveation_level: int` = `0` — The foveation level, from `0` (off) to `3` (high).
- `foveation_with_subsampled_images: bool` = `false` — If `true`, enables subsampled images with foveation, which can provide a performance boost on Vulkan.
- `render_target_size_multiplier: float` = `1.0` — The render size multiplier for the current HMD.
- `vrs_min_radius: float` = `20.0` — The minimum radius around the focal point where full quality is guaranteed if VRS is used as a percentage of screen size.
- `vrs_strength: float` = `1.0` — The strength used to calculate the VRS density map.

## Methods

- `get_action_sets() -> Array` *const* — Returns a list of action sets registered with Godot (loaded from the action map at runtime).
- `get_active_view_configuration() -> int[OpenXRInterface.ViewConfiguration]` *const* — Gets the active view configuration.
- `get_available_display_refresh_rates() -> Array` *const* — Returns a list of display refresh rates supported by the current HMD.
- `get_hand_joint_angular_velocity(hand: OpenXRInterface.Hand, joint: OpenXRInterface.HandJoints) -> Vector3` *const* *(deprecated)* — If handtracking is enabled, returns the angular velocity of a joint (`joint`) of a hand (`hand`) as provided by OpenXR.
- `get_hand_joint_flags(hand: OpenXRInterface.Hand, joint: OpenXRInterface.HandJoints) -> int[OpenXRInterface.HandJointFlags]` *const* *(deprecated)* — If handtracking is enabled, returns flags that inform us of the validity of the tracking data.
- `get_hand_joint_linear_velocity(hand: OpenXRInterface.Hand, joint: OpenXRInterface.HandJoints) -> Vector3` *const* *(deprecated)* — If handtracking is enabled, returns the linear velocity of a joint (`joint`) of a hand (`hand`) as provided by OpenXR.
- `get_hand_joint_position(hand: OpenXRInterface.Hand, joint: OpenXRInterface.HandJoints) -> Vector3` *const* *(deprecated)* — If handtracking is enabled, returns the position of a joint (`joint`) of a hand (`hand`) as provided by OpenXR.
- `get_hand_joint_radius(hand: OpenXRInterface.Hand, joint: OpenXRInterface.HandJoints) -> float` *const* *(deprecated)* — If handtracking is enabled, returns the radius of a joint (`joint`) of a hand (`hand`) as provided by OpenXR.
- `get_hand_joint_rotation(hand: OpenXRInterface.Hand, joint: OpenXRInterface.HandJoints) -> Quaternion` *const* *(deprecated)* — If handtracking is enabled, returns the rotation of a joint (`joint`) of a hand (`hand`) as provided by OpenXR.
- `get_hand_tracking_source(hand: OpenXRInterface.Hand) -> int[OpenXRInterface.HandTrackedSource]` *const* *(deprecated)* — If handtracking is enabled and hand tracking source is supported, gets the source of the hand tracking data for `hand`.
- `get_motion_range(hand: OpenXRInterface.Hand) -> int[OpenXRInterface.HandMotionRange]` *const* — If handtracking is enabled and motion range is supported, gets the currently configured motion range for `hand`.
- `get_recommended_target_size() -> Vector2` *const* — Returns the recommended render target size from the OpenXR runtime.
- `get_session_state() -> int[OpenXRInterface.SessionState]` — Returns the current state of our OpenXR session.
- `is_action_set_active(name: String) -> bool` *const* — Returns `true` if the given action set is active.
- `is_eye_gaze_interaction_supported() -> bool` — Returns the capabilities of the eye gaze interaction extension.
- `is_foveation_supported() -> bool` *const* — Returns `true` if OpenXR's foveation extension is supported.
- `is_hand_interaction_supported() -> bool` *const* — Returns `true` if OpenXR's hand interaction profile is supported and enabled.
- `is_hand_tracking_supported() -> bool` — Returns `true` if OpenXR's hand tracking is supported and enabled.
- `is_user_presence_supported() -> bool` *const* — Returns `true` if OpenXR's user presence extension is supported and enabled.
- `is_user_present() -> bool` *const* — Returns `true` if system has detected the presence of a user in the XR experience.
- `set_action_set_active(name: String, active: bool) -> void` — Sets the given action set as active or inactive.
- `set_cpu_level(level: OpenXRInterface.PerfSettingsLevel) -> void` — Sets the CPU performance level of the OpenXR device.
- `set_gpu_level(level: OpenXRInterface.PerfSettingsLevel) -> void` — Sets the GPU performance level of the OpenXR device.
- `set_motion_range(hand: OpenXRInterface.Hand, motion_range: OpenXRInterface.HandMotionRange) -> void` — If handtracking is enabled and motion range is supported, sets the currently configured motion range for `hand` to `motion_range`.

## Signals

- `cpu_level_changed(sub_domain: int, from_level: int, to_level: int)` — Informs the device CPU performance level has changed in the specified subdomain.
- `gpu_level_changed(sub_domain: int, from_level: int, to_level: int)` — Informs the device GPU performance level has changed in the specified subdomain.
- `instance_exiting()` — Informs our OpenXR instance is exiting.
- `pose_recentered()` — Informs the user queued a recenter of the player position.
- `refresh_rate_changed(refresh_rate: float)` — Informs the user the HMD refresh rate has changed.
- `session_begun()` — Informs our OpenXR session has been started.
- `session_focussed()` — Informs our OpenXR session now has focus, for example output is sent to the HMD and we're receiving XR input.
- `session_loss_pending()` — Informs our OpenXR session is in the process of being lost.
- `session_stopping()` — Informs our OpenXR session is stopping.
- `session_synchronized()` — Informs our OpenXR session has been synchronized.
- `session_visible()` — Informs our OpenXR session is now visible, for example output is sent to the HMD but we don't receive XR input.
- `user_presence_changed(is_user_present: bool)` — Signal emitted when the user presence value changes.

## Enum SessionState

- `SESSION_STATE_UNKNOWN = 0` — The state of the session is unknown, we haven't tried setting up OpenXR yet.
- `SESSION_STATE_IDLE = 1` — The initial state after the OpenXR session is created or after the session is destroyed.
- `SESSION_STATE_READY = 2` — OpenXR is ready to begin our session.
- `SESSION_STATE_SYNCHRONIZED = 3` — The application has synched its frame loop with the runtime but we're not rendering anything.
- `SESSION_STATE_VISIBLE = 4` — The application has synched its frame loop with the runtime and we're rendering output to the user, however we receive no user input.
- `SESSION_STATE_FOCUSED = 5` — The application has synched its frame loop with the runtime, we're rendering output to the user and we're receiving XR input.
- `SESSION_STATE_STOPPING = 6` — Our session is being stopped.
- `SESSION_STATE_LOSS_PENDING = 7` — The session is about to be lost.
- `SESSION_STATE_EXITING = 8` — The OpenXR instance is about to be destroyed and we're exiting.

## Enum ViewConfiguration

- `VIEW_CONFIGURATION_MONO = 0` — Our XR output configuration is monoscopic.
- `VIEW_CONFIGURATION_STEREO = 1` — Our XR output configuration is stereoscopic.
- `VIEW_CONFIGURATION_STEREO_WITH_INSET = 2` — Our XR output configuration is stereoscopic with an additional foveated inset render.
- `VIEW_CONFIGURATION_UNSET = 254` — Our XR output configuration has not yet been determined.
- `VIEW_CONFIGURATION_UNKNOWN = 255` — Our XR output configuration is unknown.

## Enum Hand

- `HAND_LEFT = 0` — Left hand.
- `HAND_RIGHT = 1` — Right hand.
- `HAND_MAX = 2` — Maximum value for the hand enum.

## Enum HandMotionRange

- `HAND_MOTION_RANGE_UNOBSTRUCTED = 0` — Full hand range, if user closes their hands, we make a full fist.
- `HAND_MOTION_RANGE_CONFORM_TO_CONTROLLER = 1` — Conform to controller, if user closes their hands, the tracked data conforms to the shape of the controller.
- `HAND_MOTION_RANGE_MAX = 2` — Maximum value for the motion range enum.

## Enum HandTrackedSource

- `HAND_TRACKED_SOURCE_UNKNOWN = 0` — The source of hand tracking data is unknown (the extension is likely unsupported).
- `HAND_TRACKED_SOURCE_UNOBSTRUCTED = 1` — The source of hand tracking is unobstructed, this means that an accurate method of hand tracking is used, e.g. optical hand tracking, data gloves, etc.
- `HAND_TRACKED_SOURCE_CONTROLLER = 2` — The source of hand tracking is a controller, bone positions are inferred from controller inputs.
- `HAND_TRACKED_SOURCE_MAX = 3` — Represents the size of the `HandTrackedSource` enum.

## Enum HandJoints

- `HAND_JOINT_PALM = 0` — Palm joint.
- `HAND_JOINT_WRIST = 1` — Wrist joint.
- `HAND_JOINT_THUMB_METACARPAL = 2` — Thumb metacarpal joint.
- `HAND_JOINT_THUMB_PROXIMAL = 3` — Thumb proximal joint.
- `HAND_JOINT_THUMB_DISTAL = 4` — Thumb distal joint.
- `HAND_JOINT_THUMB_TIP = 5` — Thumb tip joint.
- `HAND_JOINT_INDEX_METACARPAL = 6` — Index finger metacarpal joint.
- `HAND_JOINT_INDEX_PROXIMAL = 7` — Index finger phalanx proximal joint.
- `HAND_JOINT_INDEX_INTERMEDIATE = 8` — Index finger phalanx intermediate joint.
- `HAND_JOINT_INDEX_DISTAL = 9` — Index finger phalanx distal joint.
- `HAND_JOINT_INDEX_TIP = 10` — Index finger tip joint.
- `HAND_JOINT_MIDDLE_METACARPAL = 11` — Middle finger metacarpal joint.
- `HAND_JOINT_MIDDLE_PROXIMAL = 12` — Middle finger phalanx proximal joint.
- `HAND_JOINT_MIDDLE_INTERMEDIATE = 13` — Middle finger phalanx intermediate joint.
- `HAND_JOINT_MIDDLE_DISTAL = 14` — Middle finger phalanx distal joint.
- `HAND_JOINT_MIDDLE_TIP = 15` — Middle finger tip joint.
- `HAND_JOINT_RING_METACARPAL = 16` — Ring finger metacarpal joint.
- `HAND_JOINT_RING_PROXIMAL = 17` — Ring finger phalanx proximal joint.
- `HAND_JOINT_RING_INTERMEDIATE = 18` — Ring finger phalanx intermediate joint.
- `HAND_JOINT_RING_DISTAL = 19` — Ring finger phalanx distal joint.
- `HAND_JOINT_RING_TIP = 20` — Ring finger tip joint.
- `HAND_JOINT_LITTLE_METACARPAL = 21` — Pinky finger metacarpal joint.
- `HAND_JOINT_LITTLE_PROXIMAL = 22` — Pinky finger phalanx proximal joint.
- `HAND_JOINT_LITTLE_INTERMEDIATE = 23` — Pinky finger phalanx intermediate joint.
- `HAND_JOINT_LITTLE_DISTAL = 24` — Pinky finger phalanx distal joint.
- `HAND_JOINT_LITTLE_TIP = 25` — Pinky finger tip joint.
- `HAND_JOINT_MAX = 26` — Represents the size of the `HandJoints` enum.

## Enum PerfSettingsLevel

- `PERF_SETTINGS_LEVEL_POWER_SAVINGS = 0` — The application has entered a non-XR section (head-locked / static screen), during which power savings are to be prioritized.
- `PERF_SETTINGS_LEVEL_SUSTAINED_LOW = 1` — The application has entered a low and stable complexity section, during which reducing power is more important than occasional late rendering frames.
- `PERF_SETTINGS_LEVEL_SUSTAINED_HIGH = 2` — The application has entered a high or dynamic complexity section, during which the XR Runtime strives for consistent XR compositing and frame rendering within a thermally sustainable range.
- `PERF_SETTINGS_LEVEL_BOOST = 3` — The application has entered a section with very high complexity, during which the XR Runtime is allowed to step up beyond the thermally sustainable range.

## Enum PerfSettingsSubDomain

- `PERF_SETTINGS_SUB_DOMAIN_COMPOSITING = 0` — The compositing performance within the runtime has reached a new level.
- `PERF_SETTINGS_SUB_DOMAIN_RENDERING = 1` — The application rendering performance has reached a new level.
- `PERF_SETTINGS_SUB_DOMAIN_THERMAL = 2` — The temperature of the device has reached a new level.

## Enum PerfSettingsNotificationLevel

- `PERF_SETTINGS_NOTIF_LEVEL_NORMAL = 0` — The sub-domain has reached a level where no further actions other than currently applied are necessary.
- `PERF_SETTINGS_NOTIF_LEVEL_WARNING = 1` — The sub-domain has reached an early warning level where the application should start proactive mitigation actions.
- `PERF_SETTINGS_NOTIF_LEVEL_IMPAIRED = 2` — The sub-domain has reached a critical level where the application should start drastic mitigation actions.

## Enum HandJointFlags

- `HAND_JOINT_NONE = 0` — No flags are set.
- `HAND_JOINT_ORIENTATION_VALID = 1` — If set, the orientation data is valid, otherwise, the orientation data is unreliable and should not be used.
- `HAND_JOINT_ORIENTATION_TRACKED = 2` — If set, the orientation data comes from tracking data, otherwise, the orientation data contains predicted data.
- `HAND_JOINT_POSITION_VALID = 4` — If set, the positional data is valid, otherwise, the positional data is unreliable and should not be used.
- `HAND_JOINT_POSITION_TRACKED = 8` — If set, the positional data comes from tracking data, otherwise, the positional data contains predicted data.
- `HAND_JOINT_LINEAR_VELOCITY_VALID = 16` — If set, our linear velocity data is valid, otherwise, the linear velocity data is unreliable and should not be used.
- `HAND_JOINT_ANGULAR_VELOCITY_VALID = 32` — If set, our angular velocity data is valid, otherwise, the angular velocity data is unreliable and should not be used.
