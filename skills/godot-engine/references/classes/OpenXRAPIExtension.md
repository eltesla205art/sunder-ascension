# OpenXRAPIExtension

**Inherits:** RefCounted

Makes the OpenXR API available for GDExtension.

OpenXRAPIExtension makes OpenXR available for GDExtension. It provides the OpenXR API to GDExtension through the `get_instance_proc_addr` method, and the OpenXR instance through `get_instance`. It also provides methods for querying the status of OpenXR initialization, and helper methods for ease of use of the API with GDExtension.

## Methods

- `action_get_handle(action: RID) -> int` — Returns the corresponding `XrAction` OpenXR handle for the given action RID.
- `begin_debug_label_region(label_name: String) -> void` — Begins a new debug label region, this label will be reported in debug messages for any calls following this until `end_debug_label_region` is called.
- `can_render() -> bool` — Returns `true` if OpenXR is initialized for rendering with an XR viewport.
- `end_debug_label_region() -> void` — Marks the end of a debug label region.
- `find_action(name: String, action_set: RID) -> RID` — Returns the RID corresponding to an `Action` of a matching name, optionally limited to a specified action set.
- `get_error_string(result: int) -> String` — Returns an error string for the given XrResult.
- `get_hand_tracker(hand_index: int) -> int` — Returns the corresponding `XRHandTrackerEXT` handle for the given hand index value.
- `get_instance() -> int` — Returns the XrInstance created during the initialization of the OpenXR API.
- `get_instance_proc_addr(name: String) -> int` — Returns the function pointer of the OpenXR function with the specified name, cast to an integer.
- `get_next_frame_time() -> int` — Returns the predicted display timing for the next frame.
- `get_openxr_version() -> int` — Returns the version of OpenXR that was initialized.
- `get_play_space() -> int` — Returns the play space, which is an XrSpace cast to an integer.
- `get_predicted_display_time() -> int` — Returns the predicted display timing for the current frame.
- `get_primary_view_count() -> int` *const* — Returns the view count for the primary viewport.
- `get_projection_layer() -> int` — Returns a pointer to the render state's `XrCompositionLayerProjection` struct.
- `get_render_state_z_far() -> float` — Returns the far boundary value of the camera frustum.
- `get_render_state_z_near() -> float` — Returns the near boundary value of the camera frustum.
- `get_session() -> int` — Returns the OpenXR session, which is an XrSession cast to an integer.
- `get_supported_swapchain_formats() -> PackedInt64Array` — Returns an array of supported swapchain formats.
- `get_swapchain_format_name(swapchain_format: int) -> String` — Returns the name of the specified swapchain format.
- `get_system_id() -> int` — Returns the ID of the system, which is an XrSystemId cast to an integer.
- `get_view_configuration() -> int` *const* — Returns the view configuration type, which is an XrViewConfigurationType cast to an integer.
- `get_view_count() -> int` *const* — Returns the number of views.
- `insert_debug_label(label_name: String) -> void` — Inserts a debug label, this label is reported in any debug message resulting from the OpenXR calls that follows, until any of `begin_debug_label_region`, `end_debug_label_region`, or `insert_debug_label` is called.
- `is_environment_blend_mode_alpha_supported() -> int[OpenXRAPIExtension.OpenXRAlphaBlendModeSupport]` — Returns `OpenXRAPIExtension.OpenXRAlphaBlendModeSupport` denoting if `XRInterface.XR_ENV_BLEND_MODE_ALPHA_BLEND` is really supported, emulated or not supported at all.
- `is_initialized() -> bool` — Returns `true` if OpenXR is initialized.
- `is_running() -> bool` — Returns `true` if OpenXR is running (xrBeginSession was successfully called and the swapchains were created).
- `openxr_is_enabled(check_run_in_editor: bool) -> bool` *static* — Returns `true` if OpenXR is enabled.
- `openxr_swapchain_acquire(swapchain: int) -> void` — Acquires the image of the provided swapchain.
- `openxr_swapchain_create(create_flags: int, usage_flags: int, swapchain_format: int, width: int, height: int, sample_count: int, array_size: int) -> int` — Returns a pointer to a new swapchain created using the provided parameters.
- `openxr_swapchain_free(swapchain: int) -> void` — Destroys the provided swapchain and frees it from memory.
- `openxr_swapchain_get_image(swapchain: int) -> RID` — Returns the RID of the provided swapchain's image.
- `openxr_swapchain_get_swapchain(swapchain: int) -> int` — Returns the `XrSwapchain` handle of the provided swapchain.
- `openxr_swapchain_release(swapchain: int) -> void` — Releases the image of the provided swapchain.
- `register_composition_layer_provider(extension: OpenXRExtensionWrapper) -> void` — Registers the given extension as a composition layer provider.
- `register_frame_info_extension(extension: OpenXRExtensionWrapper) -> void` — Registers the given extension as modifying frame info via the `OpenXRExtensionWrapper._set_frame_wait_info_and_get_next_pointer`, `OpenXRExtensionWrapper._set_view_locate_info_and_get_next_pointer`, or `OpenXRExtensionWrapper._set_frame_end_info_and_get_next_pointer` virtual methods.
- `register_projection_layer_extension(extension: OpenXRExtensionWrapper) -> void` — Registers the given extension as modifying `XrCompositionLayerProjection` via the `OpenXRExtensionWrapper._set_projection_layer_and_get_next_pointer` virtual method.
- `register_projection_views_extension(extension: OpenXRExtensionWrapper) -> void` — Registers the given extension as a provider of additional data structures to projections views.
- `set_custom_play_space(space: const void*) -> void` — Sets the reference space used by OpenXR to the given XrSpace (cast to a `void *`).
- `set_emulate_environment_blend_mode_alpha_blend(enabled: bool) -> void` — If set to `true`, an OpenXR extension is loaded which is capable of emulating the `XRInterface.XR_ENV_BLEND_MODE_ALPHA_BLEND` blend mode.
- `set_object_name(object_type: int, object_handle: int, object_name: String) -> void` — Set the object name of an OpenXR object, used for debug output.
- `set_render_region(render_region: Rect2i) -> void` — Sets the render region to `render_region`, overriding the normal render target's rect.
- `set_velocity_depth_texture(render_target: RID) -> void` — Sets the render target of the velocity depth texture.
- `set_velocity_target_size(target_size: Vector2i) -> void` — Sets the target size of the velocity and velocity depth textures.
- `set_velocity_texture(render_target: RID) -> void` — Sets the render target of the velocity texture.
- `transform_from_pose(pose: const void*) -> Transform3D` — Creates a Transform3D from an XrPosef.
- `unregister_composition_layer_provider(extension: OpenXRExtensionWrapper) -> void` — Unregisters the given extension as a composition layer provider.
- `unregister_frame_info_extension(extension: OpenXRExtensionWrapper) -> void` — Unregisters the given extension as modifying frame info.
- `unregister_projection_layer_extension(extension: OpenXRExtensionWrapper) -> void` — Unregisters the given extension as modifying `XrCompositionLayerProjection`.
- `unregister_projection_views_extension(extension: OpenXRExtensionWrapper) -> void` — Unregisters the given extension as a provider of additional data structures to projections views.
- `update_main_swapchain_size() -> void` — Request the recommended resolution from the OpenXR runtime and update the main swapchain size if it has changed.
- `xr_result(result: int, format: String, args: Array) -> bool` — Returns `true` if the provided XrResult (cast to an integer) is successful.

## Enum OpenXRAlphaBlendModeSupport

- `OPENXR_ALPHA_BLEND_MODE_SUPPORT_NONE = 0` — Means that `XRInterface.XR_ENV_BLEND_MODE_ALPHA_BLEND` isn't supported at all.
- `OPENXR_ALPHA_BLEND_MODE_SUPPORT_REAL = 1` — Means that `XRInterface.XR_ENV_BLEND_MODE_ALPHA_BLEND` is really supported.
- `OPENXR_ALPHA_BLEND_MODE_SUPPORT_EMULATING = 2` — Means that `XRInterface.XR_ENV_BLEND_MODE_ALPHA_BLEND` is emulated.
