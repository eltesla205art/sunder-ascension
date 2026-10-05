# OpenXRExtensionWrapper

**Inherits:** Object

Allows implementing OpenXR extensions with GDExtension.

OpenXRExtensionWrapper allows implementing OpenXR extensions with GDExtension. The extension should be registered with `register_extension_wrapper`. When OpenXRInterface is initialized as the primary interface and any Viewport has `Viewport.use_xr` set to `true`, OpenXR will become involved in Godot's rendering process. If `ProjectSettings.rendering/driver/threads/thread_model` is set to "Separate", Godot's renderer will run on its own thread, and special care must be taken in all OpenXRExtensionWrappers in order to prevent crashes or unexpected behavior.

## Methods

- `_get_camera_offsets(tracker_name: StringName) -> Transform3D[]` *virtual* — Returns an array of offsets for each view rendered for the given camera, if this camera is handled by this extension.
- `_get_camera_projections(tracker_name: StringName, aspect: float, z_near: float, z_far: float) -> Projection[]` *virtual* — Returns an array of projections for each view rendered for the given camera, if this camera is handled by this extension.
- `_get_composition_layer(index: int) -> int` *virtual* — Returns a pointer to an `XrCompositionLayerBaseHeader` struct to provide the given composition layer.
- `_get_composition_layer_count() -> int` *virtual* — Returns the number of composition layers this extension wrapper provides via `_get_composition_layer`.
- `_get_composition_layer_order(index: int) -> int` *virtual* — Returns an integer that will be used to sort the given composition layer provided via `_get_composition_layer`.
- `_get_requested_extensions(xr_version: int) -> Dictionary` *virtual* — Returns a Dictionary of OpenXR extensions related to this extension.
- `_get_suggested_tracker_names() -> PackedStringArray` *virtual* — Returns a PackedStringArray of positional tracker names that are used within the extension wrapper.
- `_get_viewport_composition_layer_extension_properties() -> Dictionary[]` *virtual* — Gets an array of Dictionarys that represent properties, just like `Object._get_property_list`, that will be added to OpenXRCompositionLayer nodes.
- `_get_viewport_composition_layer_extension_property_defaults() -> Dictionary` *virtual* — Gets a Dictionary containing the default values for the properties returned by `_get_viewport_composition_layer_extension_properties`.
- `_on_before_instance_created() -> void` *virtual* — Called before the OpenXR instance is created.
- `_on_event_polled(event: const void*) -> bool` *virtual* — Called when there is an OpenXR event to process.
- `_on_instance_created(instance: int) -> void` *virtual* — Called right after the OpenXR instance is created.
- `_on_instance_destroyed() -> void` *virtual* — Called right before the OpenXR instance is destroyed.
- `_on_main_swapchains_created() -> void` *virtual* — Called right after the main swapchains are (re)created.
- `_on_post_draw_viewport(viewport: RID) -> void` *virtual* — Called right after the given viewport is rendered.
- `_on_pre_draw_viewport(viewport: RID) -> void` *virtual* — Called right before the given viewport is rendered.
- `_on_pre_render() -> void` *virtual* — Called right before the XR viewports begin their rendering step.
- `_on_process() -> void` *virtual* — Called as part of the OpenXR process handling.
- `_on_register_metadata(interaction_profile_metadata: OpenXRInteractionProfileMetadata) -> void` *virtual* — Allows extensions to register additional controller metadata.
- `_on_session_created(session: int) -> void` *virtual* — Called right after the OpenXR session is created.
- `_on_session_destroyed() -> void` *virtual* — Called right before the OpenXR session is destroyed.
- `_on_state_exiting() -> void` *virtual* — Called when the OpenXR session state is changed to exiting.
- `_on_state_focused() -> void` *virtual* — Called when the OpenXR session state is changed to focused.
- `_on_state_idle() -> void` *virtual* — Called when the OpenXR session state is changed to idle.
- `_on_state_loss_pending() -> void` *virtual* — Called when the OpenXR session state is changed to loss pending.
- `_on_state_ready() -> void` *virtual* — Called when the OpenXR session state is changed to ready.
- `_on_state_stopping() -> void` *virtual* — Called when the OpenXR session state is changed to stopping.
- `_on_state_synchronized() -> void` *virtual* — Called when the OpenXR session state is changed to synchronized.
- `_on_state_visible() -> void` *virtual* — Called when the OpenXR session state is changed to visible.
- `_on_sync_actions() -> void` *virtual* — Called when OpenXR has performed its action sync.
- `_on_viewport_composition_layer_destroyed(layer: const void*) -> void` *virtual* — Called when a composition layer created via OpenXRCompositionLayer is destroyed.
- `_prepare_view_configuration(view_count: int) -> void` *virtual* — Called before `_set_view_configuration_and_get_next_pointer` to allow the extension to reserve data for the given number of views.
- `_print_view_configuration_info(view: int) -> void` *virtual const* — Called to allow an extension to print additional information about its view configuration, if applicable.
- `_set_android_surface_swapchain_create_info_and_get_next_pointer(property_values: Dictionary, next_pointer: void*) -> int` *virtual* — Add additional data structures to Android surface swapchains created by OpenXRCompositionLayer.
- `_set_frame_end_info_and_get_next_pointer(next_pointer: void*) -> int` *virtual* — Add additional data structures to `XrFrameEndInfo`.
- `_set_frame_wait_info_and_get_next_pointer(next_pointer: void*) -> int` *virtual* — Add additional data structures to `XrFrameWaitInfo`.
- `_set_hand_joint_locations_and_get_next_pointer(hand_index: int, next_pointer: void*) -> int` *virtual* — Add additional data structures when each hand tracker is created.
- `_set_instance_create_info_and_get_next_pointer(xr_version: int, next_pointer: void*) -> int` *virtual* — Add additional data structures when the OpenXR instance is created.
- `_set_projection_layer_and_get_next_pointer(next_pointer: void*) -> int` *virtual* — Adds additional data structures to `XrCompositionLayerProjection`.
- `_set_projection_views_and_get_next_pointer(view_index: int, next_pointer: void*) -> int` *virtual* — Add additional data structures to the projection view of the given `view_index`.
- `_set_reference_space_create_info_and_get_next_pointer(reference_space_type: int, next_pointer: void*) -> int` *virtual* — Add additional data structures to `XrReferenceSpaceCreateInfo`.
- `_set_session_create_and_get_next_pointer(next_pointer: void*) -> int` *virtual* — Add additional data structures when the OpenXR session is created.
- `_set_spatial_container_create_info_and_get_next_pointer(spatial_container: RID, next_pointer: void*) -> int` *virtual* — Add additional data structures when the spatial container is created.
- `_set_spatial_container_views_locate_info_and_get_next_pointer(spatial_container: RID, next_pointer: void*) -> int` *virtual* — Add additional data structures to `XrSpatialContainerViewsLocateInfoEXT` for the spatial container specified by `spatial_container`.
- `_set_swapchain_create_info_and_get_next_pointer(next_pointer: void*) -> int` *virtual* — Add additional data structures when creating OpenXR swapchains.
- `_set_system_properties_and_get_next_pointer(next_pointer: void*) -> int` *virtual* — Add additional data structures when querying OpenXR system abilities.
- `_set_view_configuration_and_get_next_pointer(view: int, next_pointer: void*) -> int` *virtual* — Add additional data structures when querying OpenXR view configuration.
- `_set_view_locate_info_and_get_next_pointer(next_pointer: void*) -> int` *virtual* — Add additional data structures to `XrViewLocateInfo`.
- `_set_viewport_composition_layer_and_get_next_pointer(layer: const void*, property_values: Dictionary, next_pointer: void*) -> int` *virtual* — Add additional data structures to composition layers created by OpenXRCompositionLayer.
- `get_openxr_api() -> OpenXRAPIExtension` — Returns the created OpenXRAPIExtension, which can be used to access the OpenXR API.
- `register_extension_wrapper() -> void` — Registers the extension.
