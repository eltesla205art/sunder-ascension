# RenderingDevice

**Inherits:** Object

Abstraction for working with modern low-level graphics APIs.

RenderingDevice is an abstraction for working with modern low-level graphics APIs such as Vulkan. Compared to RenderingServer (which works with Godot's own rendering subsystems), RenderingDevice is much lower-level and allows working more directly with the underlying graphics APIs. RenderingDevice is used in Godot to provide support for several modern low-level graphics APIs while reducing the amount of code duplication required. RenderingDevice can also be used in your own projects to perform things that are not exposed by RenderingServer or high-level nodes, such as using compute shaders.

## Methods

- `barrier(from: RenderingDevice.BarrierMask = 32767, to: RenderingDevice.BarrierMask = 32767) -> void` *(deprecated)* — This method does nothing.
- `blas_build(blas: RID) -> int[Error]` — Builds the `blas`.
- `blas_create(geometries: RDAccelerationStructureGeometry[], flags: RenderingDevice.AccelerationStructureFlagBits) -> RID` — Creates a new Bottom-Level Acceleration Structure (BLAS).
- `buffer_clear(buffer: RID, offset: int, size_bytes: int) -> int[Error]` — Clears the contents of the `buffer`, clearing `size_bytes` bytes, starting at `offset`.
- `buffer_copy(src_buffer: RID, dst_buffer: RID, src_offset: int, dst_offset: int, size: int) -> int[Error]` — Copies `size` bytes from the `src_buffer` at `src_offset` into `dst_buffer` at `dst_offset`.
- `buffer_get_data(buffer: RID, offset_bytes: int = 0, size_bytes: int = 0) -> PackedByteArray` — Returns a copy of the data of the specified `buffer`, optionally `offset_bytes` and `size_bytes` can be set to copy only a portion of the buffer.
- `buffer_get_data_async(buffer: RID, callback: Callable, offset_bytes: int = 0, size_bytes: int = 0) -> int[Error]` — Asynchronous version of `buffer_get_data`.
- `buffer_get_device_address(buffer: RID) -> int` — Returns the address of the given `buffer` which can be passed to shaders in any way to access underlying data.
- `buffer_update(buffer: RID, offset: int, size_bytes: int, data: PackedByteArray) -> int[Error]` — Updates a region of `size_bytes` bytes, starting at `offset`, in the buffer, with the specified `data`.
- `capture_timestamp(name: String) -> void` — Creates a timestamp marker with the specified `name`.
- `compute_list_add_barrier(compute_list: int) -> void` — Raises a Vulkan compute barrier in the specified `compute_list`.
- `compute_list_begin() -> int` — Starts a list of compute commands created with the `compute_*` methods.
- `compute_list_bind_compute_pipeline(compute_list: int, compute_pipeline: RID) -> void` — Tells the GPU what compute pipeline to use when processing the compute list.
- `compute_list_bind_uniform_set(compute_list: int, uniform_set: RID, set_index: int) -> void` — Binds the `uniform_set` to this `compute_list`.
- `compute_list_dispatch(compute_list: int, x_groups: int, y_groups: int, z_groups: int) -> void` — Submits the compute list for processing on the GPU.
- `compute_list_dispatch_indirect(compute_list: int, buffer: RID, offset: int) -> void` — Submits the compute list for processing on the GPU with the given group counts stored in the `buffer` at `offset`.
- `compute_list_end() -> void` — Finishes a list of compute commands created with the `compute_*` methods.
- `compute_list_set_push_constant(compute_list: int, buffer: PackedByteArray, size_bytes: int) -> void` — Sets the push constant data to `buffer` for the specified `compute_list`.
- `compute_pipeline_create(shader: RID, specialization_constants: RDPipelineSpecializationConstant[] = []) -> RID` — Creates a new compute pipeline.
- `compute_pipeline_is_valid(compute_pipeline: RID) -> bool` — Returns `true` if the compute pipeline specified by the `compute_pipeline` RID is valid, `false` otherwise.
- `create_local_device() -> RenderingDevice` — Create a new local RenderingDevice.
- `draw_command_begin_label(name: String, color: Color) -> void` — Create a command buffer debug label region that can be displayed in third-party tools such as RenderDoc.
- `draw_command_end_label() -> void` — Ends the command buffer debug label region started by a `draw_command_begin_label` call.
- `draw_command_insert_label(name: String, color: Color) -> void` *(deprecated)* — This method does nothing.
- `draw_list_begin(framebuffer: RID, draw_flags: RenderingDevice.DrawFlags = 0, clear_color_values: PackedColorArray = PackedColorArray(), clear_depth_value: float = 1.0, clear_stencil_value: int = 0, region: Rect2 = Rect2(0, 0, 0, 0), breadcrumb: int = 0) -> int` — Starts a list of raster drawing commands created with the `draw_*` methods.
- `draw_list_begin_for_screen(screen: int = 0, clear_color: Color = Color(0, 0, 0, 1)) -> int` — High-level variant of `draw_list_begin`, with the parameters automatically being adjusted for drawing onto the window specified by the `screen` ID.
- `draw_list_begin_split(framebuffer: RID, splits: int, initial_color_action: RenderingDevice.InitialAction, final_color_action: RenderingDevice.FinalAction, initial_depth_action: RenderingDevice.InitialAction, final_depth_action: RenderingDevice.FinalAction, clear_color_values: PackedColorArray = PackedColorArray(), clear_depth: float = 1.0, clear_stencil: int = 0, region: Rect2 = Rect2(0, 0, 0, 0), storage_textures: RID[] = []) -> PackedInt64Array` *(deprecated)* — This method does nothing and always returns an empty PackedInt64Array.
- `draw_list_bind_index_array(draw_list: int, index_array: RID) -> void` — Binds `index_array` to the specified `draw_list`.
- `draw_list_bind_render_pipeline(draw_list: int, render_pipeline: RID) -> void` — Binds `render_pipeline` to the specified `draw_list`.
- `draw_list_bind_uniform_set(draw_list: int, uniform_set: RID, set_index: int) -> void` — Binds `uniform_set` to the specified `draw_list`.
- `draw_list_bind_vertex_array(draw_list: int, vertex_array: RID) -> void` — Binds `vertex_array` to the specified `draw_list`.
- `draw_list_bind_vertex_buffers_format(draw_list: int, vertex_format: int, vertex_count: int, vertex_buffers: RID[], offsets: PackedInt64Array = PackedInt64Array()) -> void` — Binds a set of `vertex_buffers` directly to the specified `draw_list` using `vertex_format` without creating a vertex array RID.
- `draw_list_disable_scissor(draw_list: int) -> void` — Removes and disables the scissor rectangle for the specified `draw_list`.
- `draw_list_draw(draw_list: int, use_indices: bool, instances: int, procedural_vertex_count: int = 0) -> void` — Submits `draw_list` for rendering on the GPU.
- `draw_list_draw_indirect(draw_list: int, use_indices: bool, buffer: RID, offset: int = 0, draw_count: int = 1, stride: int = 0) -> void` — Submits `draw_list` for rendering on the GPU with the given parameters stored in the `buffer` at `offset`.
- `draw_list_enable_scissor(draw_list: int, rect: Rect2 = Rect2(0, 0, 0, 0)) -> void` — Creates a scissor rectangle and enables it for the specified `draw_list`.
- `draw_list_end() -> void` — Finishes a list of raster drawing commands created with the `draw_*` methods.
- `draw_list_set_blend_constants(draw_list: int, color: Color) -> void` — Sets blend constants for the specified `draw_list` to `color`.
- `draw_list_set_push_constant(draw_list: int, buffer: PackedByteArray, size_bytes: int) -> void` — Sets the push constant data to `buffer` for the specified `draw_list`.
- `draw_list_switch_to_next_pass() -> int` — Switches to the next draw pass.
- `draw_list_switch_to_next_pass_split(splits: int) -> PackedInt64Array` *(deprecated)* — This method does nothing and always returns an empty PackedInt64Array.
- `framebuffer_create(textures: RID[], validate_with_format: int = -1, view_count: int = 1) -> RID` — Creates a new framebuffer.
- `framebuffer_create_empty(size: Vector2i, samples: RenderingDevice.TextureSamples = 0, validate_with_format: int = -1) -> RID` — Creates a new empty framebuffer.
- `framebuffer_create_multipass(textures: RID[], passes: RDFramebufferPass[], validate_with_format: int = -1, view_count: int = 1) -> RID` — Creates a new multipass framebuffer.
- `framebuffer_format_create(attachments: RDAttachmentFormat[], view_count: int = 1) -> int` — Creates a new framebuffer format with the specified `attachments` and `view_count`.
- `framebuffer_format_create_empty(samples: RenderingDevice.TextureSamples = 0) -> int` — Creates a new empty framebuffer format with the specified number of `samples` and returns its ID.
- `framebuffer_format_create_multipass(attachments: RDAttachmentFormat[], passes: RDFramebufferPass[], view_count: int = 1) -> int` — Creates a multipass framebuffer format with the specified `attachments`, `passes` and `view_count` and returns its ID.
- `framebuffer_format_get_texture_samples(format: int, render_pass: int = 0) -> int[RenderingDevice.TextureSamples]` — Returns the number of texture samples used for the given framebuffer `format` ID (returned by `framebuffer_get_format`).
- `framebuffer_get_format(framebuffer: RID) -> int` — Returns the format ID of the framebuffer specified by the `framebuffer` RID.
- `framebuffer_is_valid(framebuffer: RID) -> bool` *const* — Returns `true` if the framebuffer specified by the `framebuffer` RID is valid, `false` otherwise.
- `free_rid(rid: RID) -> void` — Tries to free an object in the RenderingDevice.
- `full_barrier() -> void` *(deprecated)* — This method does nothing.
- `get_captured_timestamp_cpu_time(index: int) -> int` *const* — Returns the timestamp in CPU time for the rendering step specified by `index` (in microseconds since the engine started).
- `get_captured_timestamp_gpu_time(index: int) -> int` *const* — Returns the timestamp in GPU time for the rendering step specified by `index` (in nanoseconds since the engine started).
- `get_captured_timestamp_name(index: int) -> String` *const* — Returns the timestamp's name for the rendering step specified by `index`.
- `get_captured_timestamps_count() -> int` *const* — Returns the total number of timestamps (rendering steps) available for profiling.
- `get_captured_timestamps_frame() -> int` *const* — Returns the index of the last frame rendered that has rendering timestamps available for querying.
- `get_device_allocation_count() -> int` *const* — Returns how many allocations the GPU has performed for internal driver structures.
- `get_device_allocs_by_object_type(type: int) -> int` *const* — Same as `get_device_allocation_count` but filtered for a given object type.
- `get_device_memory_by_object_type(type: int) -> int` *const* — Same as `get_device_total_memory` but filtered for a given object type.
- `get_device_name() -> String` *const* — Returns the name of the video adapter (e.g. "GeForce GTX 1080/PCIe/SSE2").
- `get_device_pipeline_cache_uuid() -> String` *const* — Returns the universally unique identifier for the pipeline cache.
- `get_device_total_memory() -> int` *const* — Returns how much bytes the GPU is using.
- `get_device_vendor_name() -> String` *const* — Returns the vendor of the video adapter (e.g. "NVIDIA Corporation").
- `get_driver_allocation_count() -> int` *const* — Returns how many allocations the GPU driver has performed for internal driver structures.
- `get_driver_allocs_by_object_type(type: int) -> int` *const* — Same as `get_driver_allocation_count` but filtered for a given object type.
- `get_driver_and_device_memory_report() -> String` *const* — Returns string report in CSV format using the following methods: - `get_tracked_object_name` - `get_tracked_object_type_count` - `get_driver_total_memory` - `get_driver_allocation_count` - `get_driver_memory_by_object_type` - `get_driver_allocs_by_object_type` - `get_device_total_memory` - `get_device_allocation_count` - `get_device_memory_by_object_type` - `get_device_allocs_by_object_type` This is only used by Vulkan in debug builds.
- `get_driver_memory_by_object_type(type: int) -> int` *const* — Same as `get_driver_total_memory` but filtered for a given object type.
- `get_driver_resource(resource: RenderingDevice.DriverResource, rid: RID, index: int) -> int` — Returns the unique identifier of the driver `resource` for the specified `rid`.
- `get_driver_total_memory() -> int` *const* — Returns how much bytes the GPU driver is using for internal driver structures.
- `get_frame_delay() -> int` *const* — Returns the frame count kept by the graphics API.
- `get_memory_usage(type: RenderingDevice.MemoryType) -> int` *const* — Returns the memory usage in bytes corresponding to the given `type`.
- `get_perf_report() -> String` *const* — Returns a string with a performance report from the past frame.
- `get_tracked_object_name(type_index: int) -> String` *const* — Returns the name of the type of object for the given `type_index`.
- `get_tracked_object_type_count() -> int` *const* — Returns how many types of trackable objects there are.
- `has_feature(feature: RenderingDevice.Features) -> bool` *const* — Returns `true` if the `feature` is supported by the GPU.
- `hit_sbt_create(raytracing_pipeline: RID, initial_hit_group_capacity: int) -> RID` — Creates a new hit shader binding table (SBT).
- `hit_sbt_range_alloc(hit_sbt: RID, hit_group_count: int) -> int` — Allocates a contiguous range of SBT entries from `hit_sbt`.
- `hit_sbt_range_free(hit_sbt: RID, range: int) -> int[Error]` — Frees a hit SBT range previously allocated with `hit_sbt_range_alloc`.
- `hit_sbt_range_update(hit_sbt: RID, range: int, offset: int, hit_group_indices: PackedInt32Array) -> int[Error]` — Updates the contents of a hit SBT range.
- `hit_sbt_set_pipeline(hit_sbt: RID, raytracing_pipeline: RID) -> int[Error]` — Sets a new `raytracing_pipeline` for `hit_sbt`.
- `index_array_create(index_buffer: RID, index_offset: int, index_count: int) -> RID` — Creates a new index array.
- `index_buffer_create(size_indices: int, format: RenderingDevice.IndexBufferFormat, data: PackedByteArray = PackedByteArray(), use_restart_indices: bool = false, creation_bits: RenderingDevice.BufferCreationBits = 0) -> RID` — Creates a new index buffer.
- `limit_get(limit: RenderingDevice.Limit) -> int` *const* — Returns the value of the specified `limit`.
- `raytracing_list_begin() -> int` — Starts a list of raytracing commands.
- `raytracing_list_bind_raytracing_pipeline(raytracing_list: int, raytracing_pipeline: RID) -> void` — Binds `raytracing_pipeline` to the specified `raytracing_list`.
- `raytracing_list_bind_uniform_set(raytracing_list: int, uniform_set: RID, set_index: int) -> void` — Binds the `uniform_set` to this `raytracing_list`.
- `raytracing_list_end() -> void` — Finishes a list of raytracing commands created with the `raytracing_*` methods.
- `raytracing_list_set_push_constant(raytracing_list: int, buffer: PackedByteArray, size_bytes: int) -> void` — Sets the push constant data to `buffer` for the specified `raytracing_list`.
- `raytracing_list_trace_rays(raytracing_list: int, raygen_shader_index: int, hit_sbt: RID, width: int, height: int, depth: int) -> void` — Initializes a raytracing dispatch for `raytracing_list`, launching `width` × `height` × `depth` rays.
- `raytracing_pipeline_create(raygen_shaders: RDPipelineShader[], miss_shaders: RDPipelineShader[], hit_groups: RDHitGroup[], max_trace_recursion_depth: int) -> RID` — Creates a new raytracing pipeline.
- `raytracing_pipeline_is_valid(raytracing_pipeline: RID) -> bool` — Returns `true` if the raytracing pipeline specified by the `raytracing_pipeline` RID is valid, `false` otherwise.
- `render_pipeline_create(shader: RID, framebuffer_format: int, vertex_format: int, primitive: RenderingDevice.RenderPrimitive, rasterization_state: RDPipelineRasterizationState, multisample_state: RDPipelineMultisampleState, stencil_state: RDPipelineDepthStencilState, color_blend_state: RDPipelineColorBlendState, dynamic_state_flags: RenderingDevice.PipelineDynamicStateFlags = 0, for_render_pass: int = 0, specialization_constants: RDPipelineSpecializationConstant[] = []) -> RID` — Creates a new render pipeline.
- `render_pipeline_is_valid(render_pipeline: RID) -> bool` — Returns `true` if the render pipeline specified by the `render_pipeline` RID is valid, `false` otherwise.
- `sampler_create(state: RDSamplerState) -> RID` — Creates a new sampler.
- `sampler_is_format_supported_for_filter(format: RenderingDevice.DataFormat, sampler_filter: RenderingDevice.SamplerFilter) -> bool` *const* — Returns `true` if implementation supports using a texture of `format` with the given `sampler_filter`.
- `screen_get_framebuffer_format(screen: int = 0) -> int` *const* — Returns the framebuffer format of the given screen.
- `screen_get_height(screen: int = 0) -> int` *const* — Returns the window height matching the graphics API context for the given window ID (in pixels).
- `screen_get_width(screen: int = 0) -> int` *const* — Returns the window width matching the graphics API context for the given window ID (in pixels).
- `set_resource_name(id: RID, name: String) -> void` — Sets the resource name for `id` to `name`.
- `shader_compile_binary_from_spirv(spirv_data: RDShaderSPIRV, name: String = "") -> PackedByteArray` — Compiles a binary shader from `spirv_data` and returns the compiled binary data as a PackedByteArray.
- `shader_compile_spirv_from_source(shader_source: RDShaderSource, allow_cache: bool = true) -> RDShaderSPIRV` — Compiles a SPIR-V from the shader source code in `shader_source` and returns the SPIR-V as an RDShaderSPIRV.
- `shader_create_from_bytecode(binary_data: PackedByteArray, placeholder_rid: RID = RID()) -> RID` — Creates a new shader instance from a binary compiled shader.
- `shader_create_from_spirv(spirv_data: RDShaderSPIRV, name: String = "") -> RID` — Creates a new shader instance from SPIR-V intermediate code.
- `shader_create_placeholder() -> RID` — Create a placeholder RID by allocating an RID without initializing it for use in `shader_create_from_bytecode`.
- `shader_get_vertex_input_attribute_mask(shader: RID) -> int` — Returns the internal vertex input mask.
- `storage_buffer_create(size_bytes: int, data: PackedByteArray = PackedByteArray(), usage: RenderingDevice.StorageBufferUsage = 0, creation_bits: RenderingDevice.BufferCreationBits = 0) -> RID` — Creates a storage buffer with the specified `data` and `usage`.
- `submit() -> void` — Pushes the frame setup and draw command buffers then marks the local device as currently processing (which allows calling `sync`).
- `sync() -> void` — Forces a synchronization between the CPU and GPU, which may be required in certain cases.
- `texture_buffer_create(size_bytes: int, format: RenderingDevice.DataFormat, data: PackedByteArray = PackedByteArray()) -> RID` — Creates a new texture buffer.
- `texture_clear(texture: RID, color: Color, base_mipmap: int, mipmap_count: int, base_layer: int, layer_count: int) -> int[Error]` — Clears the specified `texture` by replacing all of its pixels with the specified `color`.
- `texture_copy(from_texture: RID, to_texture: RID, from_pos: Vector3, to_pos: Vector3, size: Vector3, src_mipmap: int, dst_mipmap: int, src_layer: int, dst_layer: int) -> int[Error]` — Copies the `from_texture` to `to_texture` with the specified `from_pos`, `to_pos` and `size` coordinates.
- `texture_create(format: RDTextureFormat, view: RDTextureView, data: PackedByteArray[] = []) -> RID` — Creates a new texture.
- `texture_create_from_extension(type: RenderingDevice.TextureType, format: RenderingDevice.DataFormat, samples: RenderingDevice.TextureSamples, usage_flags: RenderingDevice.TextureUsageBits, image: int, width: int, height: int, depth: int, layers: int, mipmaps: int = 1) -> RID` — Returns an RID for an existing `image` (`VkImage`) with the given `type`, `format`, `samples`, `usage_flags`, `width`, `height`, `depth`, `layers`, and `mipmaps`.
- `texture_create_shared(view: RDTextureView, with_texture: RID) -> RID` — Creates a shared texture using the specified `view` and the texture information from `with_texture`.
- `texture_create_shared_from_slice(view: RDTextureView, with_texture: RID, layer: int, mipmap: int, mipmaps: int = 1, slice_type: RenderingDevice.TextureSliceType = 0, layers: int = 0) -> RID` — Creates a shared texture using the specified `view` and the texture information from `with_texture`'s `layer` and `mipmap`.
- `texture_get_data(texture: RID, layer: int) -> PackedByteArray` — Returns the `texture` data for the specified `layer` as raw binary data.
- `texture_get_data_async(texture: RID, layer: int, callback: Callable) -> int[Error]` — Asynchronous version of `texture_get_data`.
- `texture_get_format(texture: RID) -> RDTextureFormat` — Returns the data format used to create this texture.
- `texture_get_native_handle(texture: RID) -> int` *(deprecated)* — Returns the internal graphics handle for this texture object.
- `texture_is_discardable(texture: RID) -> bool` — Returns `true` if the `texture` is discardable, `false` otherwise.
- `texture_is_format_supported_for_usage(format: RenderingDevice.DataFormat, usage_flags: RenderingDevice.TextureUsageBits) -> bool` *const* — Returns `true` if the specified `format` is supported for the given `usage_flags`, `false` otherwise.
- `texture_is_shared(texture: RID) -> bool` — Returns `true` if the `texture` is shared, `false` otherwise.
- `texture_is_valid(texture: RID) -> bool` — Returns `true` if the `texture` is valid, `false` otherwise.
- `texture_resolve_multisample(from_texture: RID, to_texture: RID) -> int[Error]` — Resolves the `from_texture` texture onto `to_texture` with multisample antialiasing enabled.
- `texture_set_discardable(texture: RID, discardable: bool) -> void` — Updates the discardable property of `texture`.
- `texture_update(texture: RID, layer: int, data: PackedByteArray) -> int[Error]` — Updates texture data with new data, replacing the previous data in place.
- `tlas_build(tlas: RID, instances: RDAccelerationStructureInstance[]) -> int[Error]` — Builds the `tlas`.
- `tlas_create(max_instance_count: int, flags: RenderingDevice.AccelerationStructureFlagBits) -> RID` — Creates a new Top-Level Acceleration Structure (TLAS).
- `uniform_buffer_create(size_bytes: int, data: PackedByteArray = PackedByteArray(), creation_bits: RenderingDevice.BufferCreationBits = 0) -> RID` — Creates a new uniform buffer.
- `uniform_set_create(uniforms: RDUniform[], shader: RID, shader_set: int) -> RID` — Creates a new uniform set.
- `uniform_set_is_valid(uniform_set: RID) -> bool` — Checks if the `uniform_set` is valid, i.e. is owned.
- `vertex_array_create(vertex_count: int, vertex_format: int, src_buffers: RID[], offsets: PackedInt64Array = PackedInt64Array()) -> RID` — Creates a vertex array based on the specified buffers.
- `vertex_buffer_create(size_bytes: int, data: PackedByteArray = PackedByteArray(), creation_bits: RenderingDevice.BufferCreationBits = 0) -> RID` — Creates a new vertex buffer.
- `vertex_format_create(vertex_descriptions: RDVertexAttribute[]) -> int` — Creates a new vertex format with the specified `vertex_descriptions`.

## Enum DeviceType

- `DEVICE_TYPE_OTHER = 0` — Rendering device type does not match any of the other enum values or is unknown.
- `DEVICE_TYPE_INTEGRATED_GPU = 1` — Rendering device is an integrated GPU, which is typically (but not always) slower than dedicated GPUs (`DEVICE_TYPE_DISCRETE_GPU`).
- `DEVICE_TYPE_DISCRETE_GPU = 2` — Rendering device is a dedicated GPU, which is typically (but not always) faster than integrated GPUs (`DEVICE_TYPE_INTEGRATED_GPU`).
- `DEVICE_TYPE_VIRTUAL_GPU = 3` — Rendering device is an emulated GPU in a virtual environment.
- `DEVICE_TYPE_CPU = 4` — Rendering device is provided by software emulation (such as Lavapipe or SwiftShader).
- `DEVICE_TYPE_MAX = 5` — Represents the size of the `DeviceType` enum.

## Enum DriverResource

- `DRIVER_RESOURCE_LOGICAL_DEVICE = 0` — Specific device object based on a physical device (`rid` parameter is ignored). - Vulkan: Vulkan device driver resource (`VkDevice`). - D3D12: D3D12 device driver resource (`ID3D12Device`). - Metal: Metal device driver resource (`MTLDevice`).
- `DRIVER_RESOURCE_PHYSICAL_DEVICE = 1` — Physical device the specific logical device is based on (`rid` parameter is ignored). - Vulkan: `VkPhysicalDevice`. - D3D12: `IDXGIAdapter`.
- `DRIVER_RESOURCE_TOPMOST_OBJECT = 2` — Top-most graphics API entry object (`rid` parameter is ignored). - Vulkan: `VkInstance`.
- `DRIVER_RESOURCE_COMMAND_QUEUE = 3` — The main graphics-compute command queue (`rid` parameter is ignored). - Vulkan: `VkQueue`. - D3D12: `ID3D12CommandQueue`. - Metal: `MTLCommandQueue`.
- `DRIVER_RESOURCE_QUEUE_FAMILY = 4` — The specific family the main queue belongs to (`rid` parameter is ignored). - Vulkan: The queue family index, a `uint32_t`.
- `DRIVER_RESOURCE_TEXTURE = 5` — - Vulkan: `VkImage`. - D3D12: `ID3D12Resource`.
- `DRIVER_RESOURCE_TEXTURE_VIEW = 6` — The view of an owned or shared texture. - Vulkan: `VkImageView`. - D3D12: `ID3D12Resource`.
- `DRIVER_RESOURCE_TEXTURE_DATA_FORMAT = 7` — The native id of the data format of the texture. - Vulkan: `VkFormat`. - D3D12: `DXGI_FORMAT`.
- `DRIVER_RESOURCE_SAMPLER = 8` — - Vulkan: `VkSampler`.
- `DRIVER_RESOURCE_UNIFORM_SET = 9` — - Vulkan: `VkDescriptorSet`.
- `DRIVER_RESOURCE_BUFFER = 10` — Buffer of any kind of (storage, vertex, etc.). - Vulkan: `VkBuffer`. - D3D12: `ID3D12Resource`.
- `DRIVER_RESOURCE_COMPUTE_PIPELINE = 11` — - Vulkan: `VkPipeline`. - Metal: `MTLComputePipelineState`.
- `DRIVER_RESOURCE_RENDER_PIPELINE = 12` — - Vulkan: `VkPipeline`. - Metal: `MTLRenderPipelineState`.
- `DRIVER_RESOURCE_VULKAN_DEVICE = 0` — 
- `DRIVER_RESOURCE_VULKAN_PHYSICAL_DEVICE = 1` — 
- `DRIVER_RESOURCE_VULKAN_INSTANCE = 2` — 
- `DRIVER_RESOURCE_VULKAN_QUEUE = 3` — 
- `DRIVER_RESOURCE_VULKAN_QUEUE_FAMILY_INDEX = 4` — 
- `DRIVER_RESOURCE_VULKAN_IMAGE = 5` — 
- `DRIVER_RESOURCE_VULKAN_IMAGE_VIEW = 6` — 
- `DRIVER_RESOURCE_VULKAN_IMAGE_NATIVE_TEXTURE_FORMAT = 7` — 
- `DRIVER_RESOURCE_VULKAN_SAMPLER = 8` — 
- `DRIVER_RESOURCE_VULKAN_DESCRIPTOR_SET = 9` — 
- `DRIVER_RESOURCE_VULKAN_BUFFER = 10` — 
- `DRIVER_RESOURCE_VULKAN_COMPUTE_PIPELINE = 11` — 
- `DRIVER_RESOURCE_VULKAN_RENDER_PIPELINE = 12` — 

## Enum DataFormat

- `DATA_FORMAT_R4G4_UNORM_PACK8 = 0` — 4-bit-per-channel red/green channel data format, packed into 8 bits.
- `DATA_FORMAT_R4G4B4A4_UNORM_PACK16 = 1` — 4-bit-per-channel red/green/blue/alpha channel data format, packed into 16 bits.
- `DATA_FORMAT_B4G4R4A4_UNORM_PACK16 = 2` — 4-bit-per-channel blue/green/red/alpha channel data format, packed into 16 bits.
- `DATA_FORMAT_R5G6B5_UNORM_PACK16 = 3` — Red/green/blue channel data format with 5 bits of red, 6 bits of green and 5 bits of blue, packed into 16 bits.
- `DATA_FORMAT_B5G6R5_UNORM_PACK16 = 4` — Blue/green/red channel data format with 5 bits of blue, 6 bits of green and 5 bits of red, packed into 16 bits.
- `DATA_FORMAT_R5G5B5A1_UNORM_PACK16 = 5` — Red/green/blue/alpha channel data format with 5 bits of red, 6 bits of green, 5 bits of blue and 1 bit of alpha, packed into 16 bits.
- `DATA_FORMAT_B5G5R5A1_UNORM_PACK16 = 6` — Blue/green/red/alpha channel data format with 5 bits of blue, 6 bits of green, 5 bits of red and 1 bit of alpha, packed into 16 bits.
- `DATA_FORMAT_A1R5G5B5_UNORM_PACK16 = 7` — Alpha/red/green/blue channel data format with 1 bit of alpha, 5 bits of red, 6 bits of green and 5 bits of blue, packed into 16 bits.
- `DATA_FORMAT_R8_UNORM = 8` — 8-bit-per-channel unsigned floating-point red channel data format with normalized value.
- `DATA_FORMAT_R8_SNORM = 9` — 8-bit-per-channel signed floating-point red channel data format with normalized value.
- `DATA_FORMAT_R8_USCALED = 10` — 8-bit-per-channel unsigned floating-point red channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_R8_SSCALED = 11` — 8-bit-per-channel signed floating-point red channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_R8_UINT = 12` — 8-bit-per-channel unsigned integer red channel data format.
- `DATA_FORMAT_R8_SINT = 13` — 8-bit-per-channel signed integer red channel data format.
- `DATA_FORMAT_R8_SRGB = 14` — 8-bit-per-channel unsigned floating-point red channel data format with normalized value and nonlinear sRGB encoding.
- `DATA_FORMAT_R8G8_UNORM = 15` — 8-bit-per-channel unsigned floating-point red/green channel data format with normalized value.
- `DATA_FORMAT_R8G8_SNORM = 16` — 8-bit-per-channel signed floating-point red/green channel data format with normalized value.
- `DATA_FORMAT_R8G8_USCALED = 17` — 8-bit-per-channel unsigned floating-point red/green channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_R8G8_SSCALED = 18` — 8-bit-per-channel signed floating-point red/green channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_R8G8_UINT = 19` — 8-bit-per-channel unsigned integer red/green channel data format.
- `DATA_FORMAT_R8G8_SINT = 20` — 8-bit-per-channel signed integer red/green channel data format.
- `DATA_FORMAT_R8G8_SRGB = 21` — 8-bit-per-channel unsigned floating-point red/green channel data format with normalized value and nonlinear sRGB encoding.
- `DATA_FORMAT_R8G8B8_UNORM = 22` — 8-bit-per-channel unsigned floating-point red/green/blue channel data format with normalized value.
- `DATA_FORMAT_R8G8B8_SNORM = 23` — 8-bit-per-channel signed floating-point red/green/blue channel data format with normalized value.
- `DATA_FORMAT_R8G8B8_USCALED = 24` — 8-bit-per-channel unsigned floating-point red/green/blue channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_R8G8B8_SSCALED = 25` — 8-bit-per-channel signed floating-point red/green/blue channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_R8G8B8_UINT = 26` — 8-bit-per-channel unsigned integer red/green/blue channel data format.
- `DATA_FORMAT_R8G8B8_SINT = 27` — 8-bit-per-channel signed integer red/green/blue channel data format.
- `DATA_FORMAT_R8G8B8_SRGB = 28` — 8-bit-per-channel unsigned floating-point red/green/blue channel data format with normalized value and nonlinear sRGB encoding.
- `DATA_FORMAT_B8G8R8_UNORM = 29` — 8-bit-per-channel unsigned floating-point blue/green/red channel data format with normalized value.
- `DATA_FORMAT_B8G8R8_SNORM = 30` — 8-bit-per-channel signed floating-point blue/green/red channel data format with normalized value.
- `DATA_FORMAT_B8G8R8_USCALED = 31` — 8-bit-per-channel unsigned floating-point blue/green/red channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_B8G8R8_SSCALED = 32` — 8-bit-per-channel signed floating-point blue/green/red channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_B8G8R8_UINT = 33` — 8-bit-per-channel unsigned integer blue/green/red channel data format.
- `DATA_FORMAT_B8G8R8_SINT = 34` — 8-bit-per-channel signed integer blue/green/red channel data format.
- `DATA_FORMAT_B8G8R8_SRGB = 35` — 8-bit-per-channel unsigned floating-point blue/green/red data format with normalized value and nonlinear sRGB encoding.
- `DATA_FORMAT_R8G8B8A8_UNORM = 36` — 8-bit-per-channel unsigned floating-point red/green/blue/alpha channel data format with normalized value.
- `DATA_FORMAT_R8G8B8A8_SNORM = 37` — 8-bit-per-channel signed floating-point red/green/blue/alpha channel data format with normalized value.
- `DATA_FORMAT_R8G8B8A8_USCALED = 38` — 8-bit-per-channel unsigned floating-point red/green/blue/alpha channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_R8G8B8A8_SSCALED = 39` — 8-bit-per-channel signed floating-point red/green/blue/alpha channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_R8G8B8A8_UINT = 40` — 8-bit-per-channel unsigned integer red/green/blue/alpha channel data format.
- `DATA_FORMAT_R8G8B8A8_SINT = 41` — 8-bit-per-channel signed integer red/green/blue/alpha channel data format.
- `DATA_FORMAT_R8G8B8A8_SRGB = 42` — 8-bit-per-channel unsigned floating-point red/green/blue/alpha channel data format with normalized value and nonlinear sRGB encoding.
- `DATA_FORMAT_B8G8R8A8_UNORM = 43` — 8-bit-per-channel unsigned floating-point blue/green/red/alpha channel data format with normalized value.
- `DATA_FORMAT_B8G8R8A8_SNORM = 44` — 8-bit-per-channel signed floating-point blue/green/red/alpha channel data format with normalized value.
- `DATA_FORMAT_B8G8R8A8_USCALED = 45` — 8-bit-per-channel unsigned floating-point blue/green/red/alpha channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_B8G8R8A8_SSCALED = 46` — 8-bit-per-channel signed floating-point blue/green/red/alpha channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_B8G8R8A8_UINT = 47` — 8-bit-per-channel unsigned integer blue/green/red/alpha channel data format.
- `DATA_FORMAT_B8G8R8A8_SINT = 48` — 8-bit-per-channel signed integer blue/green/red/alpha channel data format.
- `DATA_FORMAT_B8G8R8A8_SRGB = 49` — 8-bit-per-channel unsigned floating-point blue/green/red/alpha channel data format with normalized value and nonlinear sRGB encoding.
- `DATA_FORMAT_A8B8G8R8_UNORM_PACK32 = 50` — 8-bit-per-channel unsigned floating-point alpha/red/green/blue channel data format with normalized value, packed in 32 bits.
- `DATA_FORMAT_A8B8G8R8_SNORM_PACK32 = 51` — 8-bit-per-channel signed floating-point alpha/red/green/blue channel data format with normalized value, packed in 32 bits.
- `DATA_FORMAT_A8B8G8R8_USCALED_PACK32 = 52` — 8-bit-per-channel unsigned floating-point alpha/red/green/blue channel data format with scaled value (value is converted from integer to float), packed in 32 bits.
- `DATA_FORMAT_A8B8G8R8_SSCALED_PACK32 = 53` — 8-bit-per-channel signed floating-point alpha/red/green/blue channel data format with scaled value (value is converted from integer to float), packed in 32 bits.
- `DATA_FORMAT_A8B8G8R8_UINT_PACK32 = 54` — 8-bit-per-channel unsigned integer alpha/red/green/blue channel data format, packed in 32 bits.
- `DATA_FORMAT_A8B8G8R8_SINT_PACK32 = 55` — 8-bit-per-channel signed integer alpha/red/green/blue channel data format, packed in 32 bits.
- `DATA_FORMAT_A8B8G8R8_SRGB_PACK32 = 56` — 8-bit-per-channel unsigned floating-point alpha/red/green/blue channel data format with normalized value and nonlinear sRGB encoding, packed in 32 bits.
- `DATA_FORMAT_A2R10G10B10_UNORM_PACK32 = 57` — Unsigned floating-point alpha/red/green/blue channel data format with normalized value, packed in 32 bits.
- `DATA_FORMAT_A2R10G10B10_SNORM_PACK32 = 58` — Signed floating-point alpha/red/green/blue channel data format with normalized value, packed in 32 bits.
- `DATA_FORMAT_A2R10G10B10_USCALED_PACK32 = 59` — Unsigned floating-point alpha/red/green/blue channel data format with normalized value, packed in 32 bits.
- `DATA_FORMAT_A2R10G10B10_SSCALED_PACK32 = 60` — Signed floating-point alpha/red/green/blue channel data format with normalized value, packed in 32 bits.
- `DATA_FORMAT_A2R10G10B10_UINT_PACK32 = 61` — Unsigned integer alpha/red/green/blue channel data format with normalized value, packed in 32 bits.
- `DATA_FORMAT_A2R10G10B10_SINT_PACK32 = 62` — Signed integer alpha/red/green/blue channel data format with normalized value, packed in 32 bits.
- `DATA_FORMAT_A2B10G10R10_UNORM_PACK32 = 63` — Unsigned floating-point alpha/blue/green/red channel data format with normalized value, packed in 32 bits.
- `DATA_FORMAT_A2B10G10R10_SNORM_PACK32 = 64` — Signed floating-point alpha/blue/green/red channel data format with normalized value, packed in 32 bits.
- `DATA_FORMAT_A2B10G10R10_USCALED_PACK32 = 65` — Unsigned floating-point alpha/blue/green/red channel data format with normalized value, packed in 32 bits.
- `DATA_FORMAT_A2B10G10R10_SSCALED_PACK32 = 66` — Signed floating-point alpha/blue/green/red channel data format with normalized value, packed in 32 bits.
- `DATA_FORMAT_A2B10G10R10_UINT_PACK32 = 67` — Unsigned integer alpha/blue/green/red channel data format with normalized value, packed in 32 bits.
- `DATA_FORMAT_A2B10G10R10_SINT_PACK32 = 68` — Signed integer alpha/blue/green/red channel data format with normalized value, packed in 32 bits.
- `DATA_FORMAT_R16_UNORM = 69` — 16-bit-per-channel unsigned floating-point red channel data format with normalized value.
- `DATA_FORMAT_R16_SNORM = 70` — 16-bit-per-channel signed floating-point red channel data format with normalized value.
- `DATA_FORMAT_R16_USCALED = 71` — 16-bit-per-channel unsigned floating-point red channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_R16_SSCALED = 72` — 16-bit-per-channel signed floating-point red channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_R16_UINT = 73` — 16-bit-per-channel unsigned integer red channel data format.
- `DATA_FORMAT_R16_SINT = 74` — 16-bit-per-channel signed integer red channel data format.
- `DATA_FORMAT_R16_SFLOAT = 75` — 16-bit-per-channel signed floating-point red channel data format with the value stored as-is.
- `DATA_FORMAT_R16G16_UNORM = 76` — 16-bit-per-channel unsigned floating-point red/green channel data format with normalized value.
- `DATA_FORMAT_R16G16_SNORM = 77` — 16-bit-per-channel signed floating-point red/green channel data format with normalized value.
- `DATA_FORMAT_R16G16_USCALED = 78` — 16-bit-per-channel unsigned floating-point red/green channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_R16G16_SSCALED = 79` — 16-bit-per-channel signed floating-point red/green channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_R16G16_UINT = 80` — 16-bit-per-channel unsigned integer red/green channel data format.
- `DATA_FORMAT_R16G16_SINT = 81` — 16-bit-per-channel signed integer red/green channel data format.
- `DATA_FORMAT_R16G16_SFLOAT = 82` — 16-bit-per-channel signed floating-point red/green channel data format with the value stored as-is.
- `DATA_FORMAT_R16G16B16_UNORM = 83` — 16-bit-per-channel unsigned floating-point red/green/blue channel data format with normalized value.
- `DATA_FORMAT_R16G16B16_SNORM = 84` — 16-bit-per-channel signed floating-point red/green/blue channel data format with normalized value.
- `DATA_FORMAT_R16G16B16_USCALED = 85` — 16-bit-per-channel unsigned floating-point red/green/blue channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_R16G16B16_SSCALED = 86` — 16-bit-per-channel signed floating-point red/green/blue channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_R16G16B16_UINT = 87` — 16-bit-per-channel unsigned integer red/green/blue channel data format.
- `DATA_FORMAT_R16G16B16_SINT = 88` — 16-bit-per-channel signed integer red/green/blue channel data format.
- `DATA_FORMAT_R16G16B16_SFLOAT = 89` — 16-bit-per-channel signed floating-point red/green/blue channel data format with the value stored as-is.
- `DATA_FORMAT_R16G16B16A16_UNORM = 90` — 16-bit-per-channel unsigned floating-point red/green/blue/alpha channel data format with normalized value.
- `DATA_FORMAT_R16G16B16A16_SNORM = 91` — 16-bit-per-channel signed floating-point red/green/blue/alpha channel data format with normalized value.
- `DATA_FORMAT_R16G16B16A16_USCALED = 92` — 16-bit-per-channel unsigned floating-point red/green/blue/alpha channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_R16G16B16A16_SSCALED = 93` — 16-bit-per-channel signed floating-point red/green/blue/alpha channel data format with scaled value (value is converted from integer to float).
- `DATA_FORMAT_R16G16B16A16_UINT = 94` — 16-bit-per-channel unsigned integer red/green/blue/alpha channel data format.
- `DATA_FORMAT_R16G16B16A16_SINT = 95` — 16-bit-per-channel signed integer red/green/blue/alpha channel data format.
- `DATA_FORMAT_R16G16B16A16_SFLOAT = 96` — 16-bit-per-channel signed floating-point red/green/blue/alpha channel data format with the value stored as-is.
- `DATA_FORMAT_R32_UINT = 97` — 32-bit-per-channel unsigned integer red channel data format.
- `DATA_FORMAT_R32_SINT = 98` — 32-bit-per-channel signed integer red channel data format.
- `DATA_FORMAT_R32_SFLOAT = 99` — 32-bit-per-channel signed floating-point red channel data format with the value stored as-is.
- `DATA_FORMAT_R32G32_UINT = 100` — 32-bit-per-channel unsigned integer red/green channel data format.
- `DATA_FORMAT_R32G32_SINT = 101` — 32-bit-per-channel signed integer red/green channel data format.
- `DATA_FORMAT_R32G32_SFLOAT = 102` — 32-bit-per-channel signed floating-point red/green channel data format with the value stored as-is.
- `DATA_FORMAT_R32G32B32_UINT = 103` — 32-bit-per-channel unsigned integer red/green/blue channel data format.
- `DATA_FORMAT_R32G32B32_SINT = 104` — 32-bit-per-channel signed integer red/green/blue channel data format.
- `DATA_FORMAT_R32G32B32_SFLOAT = 105` — 32-bit-per-channel signed floating-point red/green/blue channel data format with the value stored as-is.
- `DATA_FORMAT_R32G32B32A32_UINT = 106` — 32-bit-per-channel unsigned integer red/green/blue/alpha channel data format.
- `DATA_FORMAT_R32G32B32A32_SINT = 107` — 32-bit-per-channel signed integer red/green/blue/alpha channel data format.
- `DATA_FORMAT_R32G32B32A32_SFLOAT = 108` — 32-bit-per-channel signed floating-point red/green/blue/alpha channel data format with the value stored as-is.
- `DATA_FORMAT_R64_UINT = 109` — 64-bit-per-channel unsigned integer red channel data format.
- `DATA_FORMAT_R64_SINT = 110` — 64-bit-per-channel signed integer red channel data format.
- `DATA_FORMAT_R64_SFLOAT = 111` — 64-bit-per-channel signed floating-point red channel data format with the value stored as-is.
- `DATA_FORMAT_R64G64_UINT = 112` — 64-bit-per-channel unsigned integer red/green channel data format.
- `DATA_FORMAT_R64G64_SINT = 113` — 64-bit-per-channel signed integer red/green channel data format.
- `DATA_FORMAT_R64G64_SFLOAT = 114` — 64-bit-per-channel signed floating-point red/green channel data format with the value stored as-is.
- `DATA_FORMAT_R64G64B64_UINT = 115` — 64-bit-per-channel unsigned integer red/green/blue channel data format.
- `DATA_FORMAT_R64G64B64_SINT = 116` — 64-bit-per-channel signed integer red/green/blue channel data format.
- `DATA_FORMAT_R64G64B64_SFLOAT = 117` — 64-bit-per-channel signed floating-point red/green/blue channel data format with the value stored as-is.
- `DATA_FORMAT_R64G64B64A64_UINT = 118` — 64-bit-per-channel unsigned integer red/green/blue/alpha channel data format.
- `DATA_FORMAT_R64G64B64A64_SINT = 119` — 64-bit-per-channel signed integer red/green/blue/alpha channel data format.
- `DATA_FORMAT_R64G64B64A64_SFLOAT = 120` — 64-bit-per-channel signed floating-point red/green/blue/alpha channel data format with the value stored as-is.
- `DATA_FORMAT_B10G11R11_UFLOAT_PACK32 = 121` — Unsigned floating-point blue/green/red data format with the value stored as-is, packed in 32 bits.
- `DATA_FORMAT_E5B9G9R9_UFLOAT_PACK32 = 122` — Unsigned floating-point exposure/blue/green/red data format with the value stored as-is, packed in 32 bits.
- `DATA_FORMAT_D16_UNORM = 123` — 16-bit unsigned floating-point depth data format with normalized value.
- `DATA_FORMAT_X8_D24_UNORM_PACK32 = 124` — 24-bit unsigned floating-point depth data format with normalized value, plus 8 unused bits, packed in 32 bits.
- `DATA_FORMAT_D32_SFLOAT = 125` — 32-bit signed floating-point depth data format with the value stored as-is.
- `DATA_FORMAT_S8_UINT = 126` — 8-bit unsigned integer stencil data format.
- `DATA_FORMAT_D16_UNORM_S8_UINT = 127` — 16-bit unsigned floating-point depth data format with normalized value, plus 8 bits of stencil in unsigned integer format.
- `DATA_FORMAT_D24_UNORM_S8_UINT = 128` — 24-bit unsigned floating-point depth data format with normalized value, plus 8 bits of stencil in unsigned integer format.
- `DATA_FORMAT_D32_SFLOAT_S8_UINT = 129` — 32-bit signed floating-point depth data format with the value stored as-is, plus 8 bits of stencil in unsigned integer format.
- `DATA_FORMAT_BC1_RGB_UNORM_BLOCK = 130` — VRAM-compressed unsigned red/green/blue channel data format with normalized value.
- `DATA_FORMAT_BC1_RGB_SRGB_BLOCK = 131` — VRAM-compressed unsigned red/green/blue channel data format with normalized value and nonlinear sRGB encoding.
- `DATA_FORMAT_BC1_RGBA_UNORM_BLOCK = 132` — VRAM-compressed unsigned red/green/blue/alpha channel data format with normalized value.
- `DATA_FORMAT_BC1_RGBA_SRGB_BLOCK = 133` — VRAM-compressed unsigned red/green/blue/alpha channel data format with normalized value and nonlinear sRGB encoding.
- `DATA_FORMAT_BC2_UNORM_BLOCK = 134` — VRAM-compressed unsigned red/green/blue/alpha channel data format with normalized value.
- `DATA_FORMAT_BC2_SRGB_BLOCK = 135` — VRAM-compressed unsigned red/green/blue/alpha channel data format with normalized value and nonlinear sRGB encoding.
- `DATA_FORMAT_BC3_UNORM_BLOCK = 136` — VRAM-compressed unsigned red/green/blue/alpha channel data format with normalized value.
- `DATA_FORMAT_BC3_SRGB_BLOCK = 137` — VRAM-compressed unsigned red/green/blue/alpha channel data format with normalized value and nonlinear sRGB encoding.
- `DATA_FORMAT_BC4_UNORM_BLOCK = 138` — VRAM-compressed unsigned red channel data format with normalized value.
- `DATA_FORMAT_BC4_SNORM_BLOCK = 139` — VRAM-compressed signed red channel data format with normalized value.
- `DATA_FORMAT_BC5_UNORM_BLOCK = 140` — VRAM-compressed unsigned red/green channel data format with normalized value.
- `DATA_FORMAT_BC5_SNORM_BLOCK = 141` — VRAM-compressed signed red/green channel data format with normalized value.
- `DATA_FORMAT_BC6H_UFLOAT_BLOCK = 142` — VRAM-compressed unsigned red/green/blue channel data format with the floating-point value stored as-is.
- `DATA_FORMAT_BC6H_SFLOAT_BLOCK = 143` — VRAM-compressed signed red/green/blue channel data format with the floating-point value stored as-is.
- `DATA_FORMAT_BC7_UNORM_BLOCK = 144` — VRAM-compressed unsigned red/green/blue/alpha channel data format with normalized value.
- `DATA_FORMAT_BC7_SRGB_BLOCK = 145` — VRAM-compressed unsigned red/green/blue/alpha channel data format with normalized value and nonlinear sRGB encoding.
- `DATA_FORMAT_ETC2_R8G8B8_UNORM_BLOCK = 146` — VRAM-compressed unsigned red/green/blue channel data format with normalized value.
- `DATA_FORMAT_ETC2_R8G8B8_SRGB_BLOCK = 147` — VRAM-compressed unsigned red/green/blue channel data format with normalized value and nonlinear sRGB encoding.
- `DATA_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK = 148` — VRAM-compressed unsigned red/green/blue/alpha channel data format with normalized value.
- `DATA_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK = 149` — VRAM-compressed unsigned red/green/blue/alpha channel data format with normalized value and nonlinear sRGB encoding.
- `DATA_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK = 150` — VRAM-compressed unsigned red/green/blue/alpha channel data format with normalized value.
- `DATA_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK = 151` — VRAM-compressed unsigned red/green/blue/alpha channel data format with normalized value and nonlinear sRGB encoding.
- `DATA_FORMAT_EAC_R11_UNORM_BLOCK = 152` — 11-bit VRAM-compressed unsigned red channel data format with normalized value.
- `DATA_FORMAT_EAC_R11_SNORM_BLOCK = 153` — 11-bit VRAM-compressed signed red channel data format with normalized value.
- `DATA_FORMAT_EAC_R11G11_UNORM_BLOCK = 154` — 11-bit VRAM-compressed unsigned red/green channel data format with normalized value.
- `DATA_FORMAT_EAC_R11G11_SNORM_BLOCK = 155` — 11-bit VRAM-compressed signed red/green channel data format with normalized value.
- `DATA_FORMAT_ASTC_4x4_UNORM_BLOCK = 156` — VRAM-compressed unsigned floating-point data format with normalized value, packed in 4×4 blocks (highest quality).
- `DATA_FORMAT_ASTC_4x4_SRGB_BLOCK = 157` — VRAM-compressed unsigned floating-point data format with normalized value and nonlinear sRGB encoding, packed in 4×4 blocks (highest quality).
- `DATA_FORMAT_ASTC_5x4_UNORM_BLOCK = 158` — VRAM-compressed unsigned floating-point data format with normalized value, packed in 5×4 blocks.
- `DATA_FORMAT_ASTC_5x4_SRGB_BLOCK = 159` — VRAM-compressed unsigned floating-point data format with normalized value and nonlinear sRGB encoding, packed in 5×4 blocks.
- `DATA_FORMAT_ASTC_5x5_UNORM_BLOCK = 160` — VRAM-compressed unsigned floating-point data format with normalized value, packed in 5×5 blocks.
- `DATA_FORMAT_ASTC_5x5_SRGB_BLOCK = 161` — VRAM-compressed unsigned floating-point data format with normalized value and nonlinear sRGB encoding, packed in 5×5 blocks.
- `DATA_FORMAT_ASTC_6x5_UNORM_BLOCK = 162` — VRAM-compressed unsigned floating-point data format with normalized value, packed in 6×5 blocks.
- `DATA_FORMAT_ASTC_6x5_SRGB_BLOCK = 163` — VRAM-compressed unsigned floating-point data format with normalized value and nonlinear sRGB encoding, packed in 6×5 blocks.
- `DATA_FORMAT_ASTC_6x6_UNORM_BLOCK = 164` — VRAM-compressed unsigned floating-point data format with normalized value, packed in 6×6 blocks.
- `DATA_FORMAT_ASTC_6x6_SRGB_BLOCK = 165` — VRAM-compressed unsigned floating-point data format with normalized value and nonlinear sRGB encoding, packed in 6×6 blocks.
- `DATA_FORMAT_ASTC_8x5_UNORM_BLOCK = 166` — VRAM-compressed unsigned floating-point data format with normalized value, packed in 8×5 blocks.
- `DATA_FORMAT_ASTC_8x5_SRGB_BLOCK = 167` — VRAM-compressed unsigned floating-point data format with normalized value and nonlinear sRGB encoding, packed in 8×5 blocks.
- `DATA_FORMAT_ASTC_8x6_UNORM_BLOCK = 168` — VRAM-compressed unsigned floating-point data format with normalized value, packed in 8×6 blocks.
- `DATA_FORMAT_ASTC_8x6_SRGB_BLOCK = 169` — VRAM-compressed unsigned floating-point data format with normalized value and nonlinear sRGB encoding, packed in 8×6 blocks.
- `DATA_FORMAT_ASTC_8x8_UNORM_BLOCK = 170` — VRAM-compressed unsigned floating-point data format with normalized value, packed in 8×8 blocks.
- `DATA_FORMAT_ASTC_8x8_SRGB_BLOCK = 171` — VRAM-compressed unsigned floating-point data format with normalized value and nonlinear sRGB encoding, packed in 8×8 blocks.
- `DATA_FORMAT_ASTC_10x5_UNORM_BLOCK = 172` — VRAM-compressed unsigned floating-point data format with normalized value, packed in 10×5 blocks.
- `DATA_FORMAT_ASTC_10x5_SRGB_BLOCK = 173` — VRAM-compressed unsigned floating-point data format with normalized value and nonlinear sRGB encoding, packed in 10×5 blocks.
- `DATA_FORMAT_ASTC_10x6_UNORM_BLOCK = 174` — VRAM-compressed unsigned floating-point data format with normalized value, packed in 10×6 blocks.
- `DATA_FORMAT_ASTC_10x6_SRGB_BLOCK = 175` — VRAM-compressed unsigned floating-point data format with normalized value and nonlinear sRGB encoding, packed in 10×6 blocks.
- `DATA_FORMAT_ASTC_10x8_UNORM_BLOCK = 176` — VRAM-compressed unsigned floating-point data format with normalized value, packed in 10×8 blocks.
- `DATA_FORMAT_ASTC_10x8_SRGB_BLOCK = 177` — VRAM-compressed unsigned floating-point data format with normalized value and nonlinear sRGB encoding, packed in 10×8 blocks.
- `DATA_FORMAT_ASTC_10x10_UNORM_BLOCK = 178` — VRAM-compressed unsigned floating-point data format with normalized value, packed in 10×10 blocks.
- `DATA_FORMAT_ASTC_10x10_SRGB_BLOCK = 179` — VRAM-compressed unsigned floating-point data format with normalized value and nonlinear sRGB encoding, packed in 10×10 blocks.
- `DATA_FORMAT_ASTC_12x10_UNORM_BLOCK = 180` — VRAM-compressed unsigned floating-point data format with normalized value, packed in 12×10 blocks.
- `DATA_FORMAT_ASTC_12x10_SRGB_BLOCK = 181` — VRAM-compressed unsigned floating-point data format with normalized value and nonlinear sRGB encoding, packed in 12×10 blocks.
- `DATA_FORMAT_ASTC_12x12_UNORM_BLOCK = 182` — VRAM-compressed unsigned floating-point data format with normalized value, packed in 12 blocks (lowest quality).
- `DATA_FORMAT_ASTC_12x12_SRGB_BLOCK = 183` — VRAM-compressed unsigned floating-point data format with normalized value and nonlinear sRGB encoding, packed in 12 blocks (lowest quality).
- `DATA_FORMAT_G8B8G8R8_422_UNORM = 184` — 8-bit-per-channel unsigned floating-point green/blue/red channel data format with normalized value.
- `DATA_FORMAT_B8G8R8G8_422_UNORM = 185` — 8-bit-per-channel unsigned floating-point blue/green/red channel data format with normalized value.
- `DATA_FORMAT_G8_B8_R8_3PLANE_420_UNORM = 186` — 8-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, stored across 3 separate planes (green + blue + red).
- `DATA_FORMAT_G8_B8R8_2PLANE_420_UNORM = 187` — 8-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, stored across 2 separate planes (green + blue/red).
- `DATA_FORMAT_G8_B8_R8_3PLANE_422_UNORM = 188` — 8-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, stored across 2 separate planes (green + blue + red).
- `DATA_FORMAT_G8_B8R8_2PLANE_422_UNORM = 189` — 8-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, stored across 2 separate planes (green + blue/red).
- `DATA_FORMAT_G8_B8_R8_3PLANE_444_UNORM = 190` — 8-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, stored across 3 separate planes.
- `DATA_FORMAT_R10X6_UNORM_PACK16 = 191` — 10-bit-per-channel unsigned floating-point red channel data with normalized value, plus 6 unused bits, packed in 16 bits.
- `DATA_FORMAT_R10X6G10X6_UNORM_2PACK16 = 192` — 10-bit-per-channel unsigned floating-point red/green channel data with normalized value, plus 6 unused bits after each channel, packed in 2×16 bits.
- `DATA_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16 = 193` — 10-bit-per-channel unsigned floating-point red/green/blue/alpha channel data with normalized value, plus 6 unused bits after each channel, packed in 4×16 bits.
- `DATA_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16 = 194` — 10-bit-per-channel unsigned floating-point green/blue/green/red channel data with normalized value, plus 6 unused bits after each channel, packed in 4×16 bits.
- `DATA_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16 = 195` — 10-bit-per-channel unsigned floating-point blue/green/red/green channel data with normalized value, plus 6 unused bits after each channel, packed in 4×16 bits.
- `DATA_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16 = 196` — 10-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, plus 6 unused bits after each channel.
- `DATA_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16 = 197` — 10-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, plus 6 unused bits after each channel.
- `DATA_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16 = 198` — 10-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, plus 6 unused bits after each channel.
- `DATA_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16 = 199` — 10-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, plus 6 unused bits after each channel.
- `DATA_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16 = 200` — 10-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, plus 6 unused bits after each channel.
- `DATA_FORMAT_R12X4_UNORM_PACK16 = 201` — 12-bit-per-channel unsigned floating-point red channel data with normalized value, plus 6 unused bits, packed in 16 bits.
- `DATA_FORMAT_R12X4G12X4_UNORM_2PACK16 = 202` — 12-bit-per-channel unsigned floating-point red/green channel data with normalized value, plus 6 unused bits after each channel, packed in 2×16 bits.
- `DATA_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16 = 203` — 12-bit-per-channel unsigned floating-point red/green/blue/alpha channel data with normalized value, plus 6 unused bits after each channel, packed in 4×16 bits.
- `DATA_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16 = 204` — 12-bit-per-channel unsigned floating-point green/blue/green/red channel data with normalized value, plus 6 unused bits after each channel, packed in 4×16 bits.
- `DATA_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16 = 205` — 12-bit-per-channel unsigned floating-point blue/green/red/green channel data with normalized value, plus 6 unused bits after each channel, packed in 4×16 bits.
- `DATA_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16 = 206` — 12-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, plus 6 unused bits after each channel.
- `DATA_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16 = 207` — 12-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, plus 6 unused bits after each channel.
- `DATA_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16 = 208` — 12-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, plus 6 unused bits after each channel.
- `DATA_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16 = 209` — 12-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, plus 6 unused bits after each channel.
- `DATA_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16 = 210` — 12-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, plus 6 unused bits after each channel.
- `DATA_FORMAT_G16B16G16R16_422_UNORM = 211` — 16-bit-per-channel unsigned floating-point green/blue/red channel data format with normalized value.
- `DATA_FORMAT_B16G16R16G16_422_UNORM = 212` — 16-bit-per-channel unsigned floating-point blue/green/red channel data format with normalized value.
- `DATA_FORMAT_G16_B16_R16_3PLANE_420_UNORM = 213` — 16-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, plus 6 unused bits after each channel.
- `DATA_FORMAT_G16_B16R16_2PLANE_420_UNORM = 214` — 16-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, plus 6 unused bits after each channel.
- `DATA_FORMAT_G16_B16_R16_3PLANE_422_UNORM = 215` — 16-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, plus 6 unused bits after each channel.
- `DATA_FORMAT_G16_B16R16_2PLANE_422_UNORM = 216` — 16-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, plus 6 unused bits after each channel.
- `DATA_FORMAT_G16_B16_R16_3PLANE_444_UNORM = 217` — 16-bit-per-channel unsigned floating-point green/blue/red channel data with normalized value, plus 6 unused bits after each channel.
- `DATA_FORMAT_ASTC_4x4_SFLOAT_BLOCK = 218` — 
- `DATA_FORMAT_ASTC_5x4_SFLOAT_BLOCK = 219` — 
- `DATA_FORMAT_ASTC_5x5_SFLOAT_BLOCK = 220` — 
- `DATA_FORMAT_ASTC_6x5_SFLOAT_BLOCK = 221` — 
- `DATA_FORMAT_ASTC_6x6_SFLOAT_BLOCK = 222` — 
- `DATA_FORMAT_ASTC_8x5_SFLOAT_BLOCK = 223` — 
- `DATA_FORMAT_ASTC_8x6_SFLOAT_BLOCK = 224` — 
- `DATA_FORMAT_ASTC_8x8_SFLOAT_BLOCK = 225` — 
- `DATA_FORMAT_ASTC_10x5_SFLOAT_BLOCK = 226` — 
- `DATA_FORMAT_ASTC_10x6_SFLOAT_BLOCK = 227` — 
- `DATA_FORMAT_ASTC_10x8_SFLOAT_BLOCK = 228` — 
- `DATA_FORMAT_ASTC_10x10_SFLOAT_BLOCK = 229` — 
- `DATA_FORMAT_ASTC_12x10_SFLOAT_BLOCK = 230` — 
- `DATA_FORMAT_ASTC_12x12_SFLOAT_BLOCK = 231` — 
- `DATA_FORMAT_MAX = 232` — Represents the size of the `DataFormat` enum.

## Enum BarrierMask

- `BARRIER_MASK_VERTEX = 1` — Vertex shader barrier mask.
- `BARRIER_MASK_FRAGMENT = 8` — Fragment shader barrier mask.
- `BARRIER_MASK_COMPUTE = 2` — Compute barrier mask.
- `BARRIER_MASK_TRANSFER = 4` — Transfer barrier mask.
- `BARRIER_MASK_RASTER = 9` — Raster barrier mask (vertex and fragment).
- `BARRIER_MASK_ALL_BARRIERS = 32767` — Barrier mask for all types (vertex, fragment, compute, transfer).
- `BARRIER_MASK_NO_BARRIER = 32768` — No barrier for any type.

## Enum TextureType

- `TEXTURE_TYPE_1D = 0` — 1-dimensional texture.
- `TEXTURE_TYPE_2D = 1` — 2-dimensional texture.
- `TEXTURE_TYPE_3D = 2` — 3-dimensional texture.
- `TEXTURE_TYPE_CUBE = 3` — Cubemap texture.
- `TEXTURE_TYPE_1D_ARRAY = 4` — Array of 1-dimensional textures.
- `TEXTURE_TYPE_2D_ARRAY = 5` — Array of 2-dimensional textures.
- `TEXTURE_TYPE_CUBE_ARRAY = 6` — Array of Cubemap textures.
- `TEXTURE_TYPE_MAX = 7` — Represents the size of the `TextureType` enum.

## Enum TextureSamples

- `TEXTURE_SAMPLES_1 = 0` — Perform 1 texture sample (this is the fastest but lowest-quality for antialiasing).
- `TEXTURE_SAMPLES_2 = 1` — Perform 2 texture samples.
- `TEXTURE_SAMPLES_4 = 2` — Perform 4 texture samples.
- `TEXTURE_SAMPLES_8 = 3` — Perform 8 texture samples.
- `TEXTURE_SAMPLES_16 = 4` — Perform 16 texture samples.
- `TEXTURE_SAMPLES_32 = 5` — Perform 32 texture samples.
- `TEXTURE_SAMPLES_64 = 6` — Perform 64 texture samples (this is the slowest but highest-quality for antialiasing).
- `TEXTURE_SAMPLES_MAX = 7` — Represents the size of the `TextureSamples` enum.

## Enum TextureUsageBits

- `TEXTURE_USAGE_SAMPLING_BIT = 1` — Texture can be sampled.
- `TEXTURE_USAGE_COLOR_ATTACHMENT_BIT = 2` — Texture can be used as a color attachment in a framebuffer.
- `TEXTURE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT = 4` — Texture can be used as a depth/stencil attachment in a framebuffer.
- `TEXTURE_USAGE_DEPTH_RESOLVE_ATTACHMENT_BIT = 4096` — Texture can be used as a depth/stencil resolve attachment in a framebuffer.
- `TEXTURE_USAGE_STORAGE_BIT = 8` — Texture can be used as a storage image.
- `TEXTURE_USAGE_STORAGE_ATOMIC_BIT = 16` — Texture can be used as a storage image with support for atomic operations.
- `TEXTURE_USAGE_CPU_READ_BIT = 32` — Texture can be read back on the CPU using `texture_get_data` faster than without this bit, since it is always kept in the system memory.
- `TEXTURE_USAGE_CAN_UPDATE_BIT = 64` — Texture can be updated using `texture_update`.
- `TEXTURE_USAGE_CAN_COPY_FROM_BIT = 128` — Texture can be a source for `texture_copy`.
- `TEXTURE_USAGE_CAN_COPY_TO_BIT = 256` — Texture can be a destination for `texture_copy`.
- `TEXTURE_USAGE_INPUT_ATTACHMENT_BIT = 512` — Texture can be used as a input attachment in a framebuffer.

## Enum TextureSwizzle

- `TEXTURE_SWIZZLE_IDENTITY = 0` — Return the sampled value as-is.
- `TEXTURE_SWIZZLE_ZERO = 1` — Always return `0.0` when sampling.
- `TEXTURE_SWIZZLE_ONE = 2` — Always return `1.0` when sampling.
- `TEXTURE_SWIZZLE_R = 3` — Sample the red color channel.
- `TEXTURE_SWIZZLE_G = 4` — Sample the green color channel.
- `TEXTURE_SWIZZLE_B = 5` — Sample the blue color channel.
- `TEXTURE_SWIZZLE_A = 6` — Sample the alpha channel.
- `TEXTURE_SWIZZLE_MAX = 7` — Represents the size of the `TextureSwizzle` enum.

## Enum TextureSliceType

- `TEXTURE_SLICE_2D = 0` — 2-dimensional texture slice.
- `TEXTURE_SLICE_CUBEMAP = 1` — Cubemap texture slice.
- `TEXTURE_SLICE_3D = 2` — 3-dimensional texture slice.
- `TEXTURE_SLICE_2D_ARRAY = 3` — 2-dimensional texture array slice.

## Enum SamplerFilter

- `SAMPLER_FILTER_NEAREST = 0` — Nearest-neighbor sampler filtering.
- `SAMPLER_FILTER_LINEAR = 1` — Bilinear sampler filtering.

## Enum SamplerRepeatMode

- `SAMPLER_REPEAT_MODE_REPEAT = 0` — Sample with repeating enabled.
- `SAMPLER_REPEAT_MODE_MIRRORED_REPEAT = 1` — Sample with mirrored repeating enabled.
- `SAMPLER_REPEAT_MODE_CLAMP_TO_EDGE = 2` — Sample with repeating disabled.
- `SAMPLER_REPEAT_MODE_CLAMP_TO_BORDER = 3` — Sample with repeating disabled.
- `SAMPLER_REPEAT_MODE_MIRROR_CLAMP_TO_EDGE = 4` — Sample with mirrored repeating enabled, but only once.
- `SAMPLER_REPEAT_MODE_MAX = 5` — Represents the size of the `SamplerRepeatMode` enum.

## Enum SamplerBorderColor

- `SAMPLER_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK = 0` — Return a floating-point transparent black color when sampling outside the `[0.0, 1.0]` range.
- `SAMPLER_BORDER_COLOR_INT_TRANSPARENT_BLACK = 1` — Return an integer transparent black color when sampling outside the `[0.0, 1.0]` range.
- `SAMPLER_BORDER_COLOR_FLOAT_OPAQUE_BLACK = 2` — Return a floating-point opaque black color when sampling outside the `[0.0, 1.0]` range.
- `SAMPLER_BORDER_COLOR_INT_OPAQUE_BLACK = 3` — Return an integer opaque black color when sampling outside the `[0.0, 1.0]` range.
- `SAMPLER_BORDER_COLOR_FLOAT_OPAQUE_WHITE = 4` — Return a floating-point opaque white color when sampling outside the `[0.0, 1.0]` range.
- `SAMPLER_BORDER_COLOR_INT_OPAQUE_WHITE = 5` — Return an integer opaque white color when sampling outside the `[0.0, 1.0]` range.
- `SAMPLER_BORDER_COLOR_MAX = 6` — Represents the size of the `SamplerBorderColor` enum.

## Enum VertexFrequency

- `VERTEX_FREQUENCY_VERTEX = 0` — Vertex attribute addressing is a function of the vertex.
- `VERTEX_FREQUENCY_INSTANCE = 1` — Vertex attribute addressing is a function of the instance index.

## Enum IndexBufferFormat

- `INDEX_BUFFER_FORMAT_UINT16 = 0` — Index buffer in 16-bit unsigned integer format.
- `INDEX_BUFFER_FORMAT_UINT32 = 1` — Index buffer in 32-bit unsigned integer format.

## Enum StorageBufferUsage

- `STORAGE_BUFFER_USAGE_DISPATCH_INDIRECT = 1` — 

## Enum BufferCreationBits

- `BUFFER_CREATION_DEVICE_ADDRESS_BIT = 1` — Optionally, set this flag if you wish to use `buffer_get_device_address` functionality.
- `BUFFER_CREATION_AS_STORAGE_BIT = 2` — Set this flag so that it is created as storage.
- `BUFFER_CREATION_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT = 8` — Allows usage of this buffer as input data for an acceleration structure build operation.

## Enum AccelerationStructureFlagBits

- `ACCELERATION_STRUCTURE_ALLOW_UPDATE_BIT = 1` — Allows the acceleration structure to be updated after it has been built.
- `ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT = 2` — Allows the acceleration structure to be compacted to reduce memory usage after it has been built.
- `ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT = 4` — Prioritizes ray traversal performance over build performance when building the acceleration structure.
- `ACCELERATION_STRUCTURE_PREFER_FAST_BUILD_BIT = 8` — Prioritizes build performance over ray traversal performance when building the acceleration structure.
- `ACCELERATION_STRUCTURE_LOW_MEMORY_BIT = 16` — Reduces the memory usage of the acceleration structure, potentially at the cost of reduced ray traversal performance.

## Enum AccelerationStructureGeometryFlagBits

- `ACCELERATION_STRUCTURE_GEOMETRY_OPAQUE_BIT = 1` — An opaque geometry does not invoke the any hit shaders.
- `ACCELERATION_STRUCTURE_GEOMETRY_NO_DUPLICATE_ANY_HIT_INVOCATION_BIT = 2` — This geometry only calls the any hit shader a single time for each primitive.

## Enum AccelerationStructureInstanceFlagBits

- `ACCELERATION_STRUCTURE_INSTANCE_TRIANGLE_FACING_CULL_DISABLE_BIT = 1` — Disables triangle face culling for this instance during ray traversal.
- `ACCELERATION_STRUCTURE_INSTANCE_TRIANGLE_FLIP_FACING_BIT = 2` — Flips the triangle facing direction for this instance during ray traversal.
- `ACCELERATION_STRUCTURE_INSTANCE_FORCE_OPAQUE_BIT = 4` — Forces all geometries in this instance to be treated as opaque, preventing any hit shaders from being invoked.
- `ACCELERATION_STRUCTURE_INSTANCE_FORCE_NO_OPAQUE_BIT = 8` — Forces all geometries in this instance to be treated as non-opaque, allowing any hit shaders to be invoked.

## Enum UniformType

- `UNIFORM_TYPE_SAMPLER = 0` — Sampler uniform.
- `UNIFORM_TYPE_SAMPLER_WITH_TEXTURE = 1` — Sampler uniform with a texture.
- `UNIFORM_TYPE_TEXTURE = 2` — Texture uniform.
- `UNIFORM_TYPE_IMAGE = 3` — Image uniform.
- `UNIFORM_TYPE_TEXTURE_BUFFER = 4` — Texture buffer uniform.
- `UNIFORM_TYPE_SAMPLER_WITH_TEXTURE_BUFFER = 5` — Sampler uniform with a texture buffer.
- `UNIFORM_TYPE_IMAGE_BUFFER = 6` — Image buffer uniform.
- `UNIFORM_TYPE_UNIFORM_BUFFER = 7` — Uniform buffer uniform.
- `UNIFORM_TYPE_STORAGE_BUFFER = 8` — Storage buffer uniform.
- `UNIFORM_TYPE_INPUT_ATTACHMENT = 9` — Input attachment uniform.
- `UNIFORM_TYPE_UNIFORM_BUFFER_DYNAMIC = 10` — Same as UNIFORM_TYPE_UNIFORM_BUFFER but for buffers created with BUFFER_CREATION_DYNAMIC_PERSISTENT_BIT.
- `UNIFORM_TYPE_STORAGE_BUFFER_DYNAMIC = 11` — Same as UNIFORM_TYPE_STORAGE_BUFFER but for buffers created with BUFFER_CREATION_DYNAMIC_PERSISTENT_BIT.
- `UNIFORM_TYPE_ACCELERATION_STRUCTURE = 12` — Acceleration structure uniform.
- `UNIFORM_TYPE_MAX = 13` — Represents the size of the `UniformType` enum.

## Enum RenderPrimitive

- `RENDER_PRIMITIVE_POINTS = 0` — Point rendering primitive (with constant size, regardless of distance from camera).
- `RENDER_PRIMITIVE_LINES = 1` — Line list rendering primitive.
- `RENDER_PRIMITIVE_LINES_WITH_ADJACENCY = 2` — Line list rendering primitive with adjacency.
- `RENDER_PRIMITIVE_LINESTRIPS = 3` — Line strip rendering primitive.
- `RENDER_PRIMITIVE_LINESTRIPS_WITH_ADJACENCY = 4` — Line strip rendering primitive with adjacency.
- `RENDER_PRIMITIVE_TRIANGLES = 5` — Triangle list rendering primitive.
- `RENDER_PRIMITIVE_TRIANGLES_WITH_ADJACENCY = 6` — Triangle list rendering primitive with adjacency.
- `RENDER_PRIMITIVE_TRIANGLE_STRIPS = 7` — Triangle strip rendering primitive.
- `RENDER_PRIMITIVE_TRIANGLE_STRIPS_WITH_AJACENCY = 8` — Triangle strip rendering primitive with adjacency.
- `RENDER_PRIMITIVE_TRIANGLE_STRIPS_WITH_RESTART_INDEX = 9` — Triangle strip rendering primitive with primitive restart enabled.
- `RENDER_PRIMITIVE_TESSELATION_PATCH = 10` — Tessellation patch rendering primitive.
- `RENDER_PRIMITIVE_MAX = 11` — Represents the size of the `RenderPrimitive` enum.

## Enum PolygonCullMode

- `POLYGON_CULL_DISABLED = 0` — Do not use polygon front face or backface culling.
- `POLYGON_CULL_FRONT = 1` — Use polygon frontface culling (faces pointing towards the camera are hidden).
- `POLYGON_CULL_BACK = 2` — Use polygon backface culling (faces pointing away from the camera are hidden).

## Enum PolygonFrontFace

- `POLYGON_FRONT_FACE_CLOCKWISE = 0` — Clockwise winding order to determine which face of a polygon is its front face.
- `POLYGON_FRONT_FACE_COUNTER_CLOCKWISE = 1` — Counter-clockwise winding order to determine which face of a polygon is its front face.

## Enum StencilOperation

- `STENCIL_OP_KEEP = 0` — Keep the current stencil value.
- `STENCIL_OP_ZERO = 1` — Set the stencil value to `0`.
- `STENCIL_OP_REPLACE = 2` — Replace the existing stencil value with the new one.
- `STENCIL_OP_INCREMENT_AND_CLAMP = 3` — Increment the existing stencil value and clamp to the maximum representable unsigned value if reached.
- `STENCIL_OP_DECREMENT_AND_CLAMP = 4` — Decrement the existing stencil value and clamp to the minimum value if reached.
- `STENCIL_OP_INVERT = 5` — Bitwise-invert the existing stencil value.
- `STENCIL_OP_INCREMENT_AND_WRAP = 6` — Increment the stencil value and wrap around to `0` if reaching the maximum representable unsigned.
- `STENCIL_OP_DECREMENT_AND_WRAP = 7` — Decrement the stencil value and wrap around to the maximum representable unsigned if reaching the minimum.
- `STENCIL_OP_MAX = 8` — Represents the size of the `StencilOperation` enum.

## Enum CompareOperator

- `COMPARE_OP_NEVER = 0` — "Never" comparison (opposite of `COMPARE_OP_ALWAYS`).
- `COMPARE_OP_LESS = 1` — "Less than" comparison.
- `COMPARE_OP_EQUAL = 2` — "Equal" comparison.
- `COMPARE_OP_LESS_OR_EQUAL = 3` — "Less than or equal" comparison.
- `COMPARE_OP_GREATER = 4` — "Greater than" comparison.
- `COMPARE_OP_NOT_EQUAL = 5` — "Not equal" comparison.
- `COMPARE_OP_GREATER_OR_EQUAL = 6` — "Greater than or equal" comparison.
- `COMPARE_OP_ALWAYS = 7` — "Always" comparison (opposite of `COMPARE_OP_NEVER`).
- `COMPARE_OP_MAX = 8` — Represents the size of the `CompareOperator` enum.

## Enum LogicOperation

- `LOGIC_OP_CLEAR = 0` — Clear logic operation (result is always `0`).
- `LOGIC_OP_AND = 1` — AND logic operation.
- `LOGIC_OP_AND_REVERSE = 2` — AND logic operation with the destination operand being inverted.
- `LOGIC_OP_COPY = 3` — Copy logic operation (keeps the source value as-is).
- `LOGIC_OP_AND_INVERTED = 4` — AND logic operation with the source operand being inverted.
- `LOGIC_OP_NO_OP = 5` — No-op logic operation (keeps the destination value as-is).
- `LOGIC_OP_XOR = 6` — Exclusive or (XOR) logic operation.
- `LOGIC_OP_OR = 7` — OR logic operation.
- `LOGIC_OP_NOR = 8` — Not-OR (NOR) logic operation.
- `LOGIC_OP_EQUIVALENT = 9` — Not-XOR (XNOR) logic operation.
- `LOGIC_OP_INVERT = 10` — Invert logic operation.
- `LOGIC_OP_OR_REVERSE = 11` — OR logic operation with the destination operand being inverted.
- `LOGIC_OP_COPY_INVERTED = 12` — NOT logic operation (inverts the value).
- `LOGIC_OP_OR_INVERTED = 13` — OR logic operation with the source operand being inverted.
- `LOGIC_OP_NAND = 14` — Not-AND (NAND) logic operation.
- `LOGIC_OP_SET = 15` — SET logic operation (result is always `1`).
- `LOGIC_OP_MAX = 16` — Represents the size of the `LogicOperation` enum.

## Enum BlendFactor

- `BLEND_FACTOR_ZERO = 0` — Constant `0.0` blend factor.
- `BLEND_FACTOR_ONE = 1` — Constant `1.0` blend factor.
- `BLEND_FACTOR_SRC_COLOR = 2` — Color blend factor is `source color`.
- `BLEND_FACTOR_ONE_MINUS_SRC_COLOR = 3` — Color blend factor is `1.0 - source color`.
- `BLEND_FACTOR_DST_COLOR = 4` — Color blend factor is `destination color`.
- `BLEND_FACTOR_ONE_MINUS_DST_COLOR = 5` — Color blend factor is `1.0 - destination color`.
- `BLEND_FACTOR_SRC_ALPHA = 6` — Color and alpha blend factor is `source alpha`.
- `BLEND_FACTOR_ONE_MINUS_SRC_ALPHA = 7` — Color and alpha blend factor is `1.0 - source alpha`.
- `BLEND_FACTOR_DST_ALPHA = 8` — Color and alpha blend factor is `destination alpha`.
- `BLEND_FACTOR_ONE_MINUS_DST_ALPHA = 9` — Color and alpha blend factor is `1.0 - destination alpha`.
- `BLEND_FACTOR_CONSTANT_COLOR = 10` — Color blend factor is `blend constant color`.
- `BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR = 11` — Color blend factor is `1.0 - blend constant color`.
- `BLEND_FACTOR_CONSTANT_ALPHA = 12` — Color and alpha blend factor is `blend constant alpha` (see `draw_list_set_blend_constants`).
- `BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA = 13` — Color and alpha blend factor is `1.0 - blend constant alpha` (see `draw_list_set_blend_constants`).
- `BLEND_FACTOR_SRC_ALPHA_SATURATE = 14` — Color blend factor is `min(source alpha, 1.0 - destination alpha)`.
- `BLEND_FACTOR_SRC1_COLOR = 15` — Color blend factor is `second source color`.
- `BLEND_FACTOR_ONE_MINUS_SRC1_COLOR = 16` — Color blend factor is `1.0 - second source color`.
- `BLEND_FACTOR_SRC1_ALPHA = 17` — Color and alpha blend factor is `second source alpha`.
- `BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA = 18` — Color and alpha blend factor is `1.0 - second source alpha`.
- `BLEND_FACTOR_MAX = 19` — Represents the size of the `BlendFactor` enum.

## Enum BlendOperation

- `BLEND_OP_ADD = 0` — Additive blending operation (`source + destination`).
- `BLEND_OP_SUBTRACT = 1` — Subtractive blending operation (`source - destination`).
- `BLEND_OP_REVERSE_SUBTRACT = 2` — Reverse subtractive blending operation (`destination - source`).
- `BLEND_OP_MINIMUM = 3` — Minimum blending operation (keep the lowest value of the two).
- `BLEND_OP_MAXIMUM = 4` — Maximum blending operation (keep the highest value of the two).
- `BLEND_OP_MAX = 5` — Represents the size of the `BlendOperation` enum.

## Enum PipelineDynamicStateFlags

- `DYNAMIC_STATE_LINE_WIDTH = 1` — Allows dynamically changing the width of rendering lines.
- `DYNAMIC_STATE_DEPTH_BIAS = 2` — Allows dynamically changing the depth bias.
- `DYNAMIC_STATE_BLEND_CONSTANTS = 4` — 
- `DYNAMIC_STATE_DEPTH_BOUNDS = 8` — 
- `DYNAMIC_STATE_STENCIL_COMPARE_MASK = 16` — 
- `DYNAMIC_STATE_STENCIL_WRITE_MASK = 32` — 
- `DYNAMIC_STATE_STENCIL_REFERENCE = 64` — 

## Enum InitialAction

- `INITIAL_ACTION_LOAD = 0` — Load the previous contents of the framebuffer.
- `INITIAL_ACTION_CLEAR = 1` — Clear the whole framebuffer or its specified region.
- `INITIAL_ACTION_DISCARD = 2` — Ignore the previous contents of the framebuffer.
- `INITIAL_ACTION_MAX = 3` — Represents the size of the `InitialAction` enum.
- `INITIAL_ACTION_CLEAR_REGION = 1` — 
- `INITIAL_ACTION_CLEAR_REGION_CONTINUE = 1` — 
- `INITIAL_ACTION_KEEP = 0` — 
- `INITIAL_ACTION_DROP = 2` — 
- `INITIAL_ACTION_CONTINUE = 0` — 

## Enum FinalAction

- `FINAL_ACTION_STORE = 0` — Store the result of the draw list in the framebuffer.
- `FINAL_ACTION_DISCARD = 1` — Discard the contents of the framebuffer.
- `FINAL_ACTION_MAX = 2` — Represents the size of the `FinalAction` enum.
- `FINAL_ACTION_READ = 0` — 
- `FINAL_ACTION_CONTINUE = 0` — 

## Enum ShaderStage

- `SHADER_STAGE_VERTEX = 0` — Vertex shader stage.
- `SHADER_STAGE_FRAGMENT = 1` — Fragment shader stage (called "pixel shader" in Direct3D).
- `SHADER_STAGE_TESSELATION_CONTROL = 2` — Tessellation control shader stage.
- `SHADER_STAGE_TESSELATION_EVALUATION = 3` — Tessellation evaluation shader stage.
- `SHADER_STAGE_COMPUTE = 4` — Compute shader stage.
- `SHADER_STAGE_RAYGEN = 5` — Ray generation shader stage.
- `SHADER_STAGE_ANY_HIT = 6` — Any hit shader stage.
- `SHADER_STAGE_CLOSEST_HIT = 7` — Closest hit shader stage.
- `SHADER_STAGE_MISS = 8` — Miss shader stage.
- `SHADER_STAGE_INTERSECTION = 9` — Intersection shader stage.
- `SHADER_STAGE_MAX = 10` — Represents the size of the `ShaderStage` enum.
- `SHADER_STAGE_VERTEX_BIT = 1` — Vertex shader stage bit (see also `SHADER_STAGE_VERTEX`).
- `SHADER_STAGE_FRAGMENT_BIT = 2` — Fragment shader stage bit (see also `SHADER_STAGE_FRAGMENT`).
- `SHADER_STAGE_TESSELATION_CONTROL_BIT = 4` — Tessellation control shader stage bit (see also `SHADER_STAGE_TESSELATION_CONTROL`).
- `SHADER_STAGE_TESSELATION_EVALUATION_BIT = 8` — Tessellation evaluation shader stage bit (see also `SHADER_STAGE_TESSELATION_EVALUATION`).
- `SHADER_STAGE_COMPUTE_BIT = 16` — Compute shader stage bit (see also `SHADER_STAGE_COMPUTE`).
- `SHADER_STAGE_RAYGEN_BIT = 32` — Ray generation shader stage bit (see also `SHADER_STAGE_RAYGEN`).
- `SHADER_STAGE_ANY_HIT_BIT = 64` — Any hit shader stage bit (see also `SHADER_STAGE_ANY_HIT`).
- `SHADER_STAGE_CLOSEST_HIT_BIT = 128` — Closest hit shader stage bit (see also `SHADER_STAGE_CLOSEST_HIT`).
- `SHADER_STAGE_MISS_BIT = 256` — Miss shader stage bit (see also `SHADER_STAGE_MISS`).
- `SHADER_STAGE_INTERSECTION_BIT = 512` — Intersection shader stage bit (see also `SHADER_STAGE_INTERSECTION`).

## Enum ShaderLanguage

- `SHADER_LANGUAGE_GLSL = 0` — Khronos' GLSL shading language (used natively by OpenGL and Vulkan).
- `SHADER_LANGUAGE_HLSL = 1` — Microsoft's High-Level Shading Language (used natively by Direct3D, but can also be used in Vulkan).

## Enum PipelineSpecializationConstantType

- `PIPELINE_SPECIALIZATION_CONSTANT_TYPE_BOOL = 0` — Boolean specialization constant.
- `PIPELINE_SPECIALIZATION_CONSTANT_TYPE_INT = 1` — Integer specialization constant.
- `PIPELINE_SPECIALIZATION_CONSTANT_TYPE_FLOAT = 2` — Floating-point specialization constant.

## Enum Features

- `SUPPORTS_METALFX_SPATIAL = 3` — Support for MetalFX spatial upscaling.
- `SUPPORTS_METALFX_TEMPORAL = 4` — Support for MetalFX temporal upscaling.
- `SUPPORTS_BUFFER_DEVICE_ADDRESS = 6` — Features support for buffer device address extension.
- `SUPPORTS_IMAGE_ATOMIC_32_BIT = 7` — Support for 32-bit image atomic operations.
- `SUPPORTS_RAY_QUERY = 11` — Support for ray query extension.
- `SUPPORTS_RAYTRACING_PIPELINE = 12` — Support for raytracing pipeline extension.
- `SUPPORTS_HDR_OUTPUT = 13` — Support for high dynamic range (HDR) output.
- `SUPPORTS_RASTERIZATION_RATE_MAP = 14` — Support for rasterization rate maps.

## Enum Limit

- `LIMIT_MAX_BOUND_UNIFORM_SETS = 0` — Maximum number of uniform sets that can be bound at a given time.
- `LIMIT_MAX_FRAMEBUFFER_COLOR_ATTACHMENTS = 1` — Maximum number of color framebuffer attachments that can be used at a given time.
- `LIMIT_MAX_TEXTURES_PER_UNIFORM_SET = 2` — Maximum number of textures that can be used per uniform set.
- `LIMIT_MAX_SAMPLERS_PER_UNIFORM_SET = 3` — Maximum number of samplers that can be used per uniform set.
- `LIMIT_MAX_STORAGE_BUFFERS_PER_UNIFORM_SET = 4` — Maximum number of storage buffers per uniform set.
- `LIMIT_MAX_STORAGE_IMAGES_PER_UNIFORM_SET = 5` — Maximum number of storage images per uniform set.
- `LIMIT_MAX_UNIFORM_BUFFERS_PER_UNIFORM_SET = 6` — Maximum number of uniform buffers per uniform set.
- `LIMIT_MAX_DRAW_INDEXED_INDEX = 7` — Maximum index for an indexed draw command.
- `LIMIT_MAX_FRAMEBUFFER_HEIGHT = 8` — Maximum height of a framebuffer (in pixels).
- `LIMIT_MAX_FRAMEBUFFER_WIDTH = 9` — Maximum width of a framebuffer (in pixels).
- `LIMIT_MAX_TEXTURE_ARRAY_LAYERS = 10` — Maximum number of texture array layers.
- `LIMIT_MAX_TEXTURE_SIZE_1D = 11` — Maximum supported 1-dimensional texture size (in pixels on a single axis).
- `LIMIT_MAX_TEXTURE_SIZE_2D = 12` — Maximum supported 2-dimensional texture size (in pixels on a single axis).
- `LIMIT_MAX_TEXTURE_SIZE_3D = 13` — Maximum supported 3-dimensional texture size (in pixels on a single axis).
- `LIMIT_MAX_TEXTURE_SIZE_CUBE = 14` — Maximum supported cubemap texture size (in pixels on a single axis of a single face).
- `LIMIT_MAX_TEXTURES_PER_SHADER_STAGE = 15` — Maximum number of textures per shader stage.
- `LIMIT_MAX_SAMPLERS_PER_SHADER_STAGE = 16` — Maximum number of samplers per shader stage.
- `LIMIT_MAX_STORAGE_BUFFERS_PER_SHADER_STAGE = 17` — Maximum number of storage buffers per shader stage.
- `LIMIT_MAX_STORAGE_IMAGES_PER_SHADER_STAGE = 18` — Maximum number of storage images per shader stage.
- `LIMIT_MAX_UNIFORM_BUFFERS_PER_SHADER_STAGE = 19` — Maximum number of uniform buffers per uniform set.
- `LIMIT_MAX_PUSH_CONSTANT_SIZE = 20` — Maximum size of a push constant.
- `LIMIT_MAX_UNIFORM_BUFFER_SIZE = 21` — Maximum size of a uniform buffer.
- `LIMIT_MAX_VERTEX_INPUT_ATTRIBUTE_OFFSET = 22` — Maximum vertex input attribute offset.
- `LIMIT_MAX_VERTEX_INPUT_ATTRIBUTES = 23` — Maximum number of vertex input attributes.
- `LIMIT_MAX_VERTEX_INPUT_BINDINGS = 24` — Maximum number of vertex input bindings.
- `LIMIT_MAX_VERTEX_INPUT_BINDING_STRIDE = 25` — Maximum vertex input binding stride.
- `LIMIT_MIN_UNIFORM_BUFFER_OFFSET_ALIGNMENT = 26` — Minimum uniform buffer offset alignment.
- `LIMIT_MAX_COMPUTE_SHARED_MEMORY_SIZE = 27` — Maximum shared memory size for compute shaders.
- `LIMIT_MAX_COMPUTE_WORKGROUP_COUNT_X = 28` — Maximum number of workgroups for compute shaders on the X axis.
- `LIMIT_MAX_COMPUTE_WORKGROUP_COUNT_Y = 29` — Maximum number of workgroups for compute shaders on the Y axis.
- `LIMIT_MAX_COMPUTE_WORKGROUP_COUNT_Z = 30` — Maximum number of workgroups for compute shaders on the Z axis.
- `LIMIT_MAX_COMPUTE_WORKGROUP_INVOCATIONS = 31` — Maximum number of workgroup invocations for compute shaders.
- `LIMIT_MAX_COMPUTE_WORKGROUP_SIZE_X = 32` — Maximum workgroup size for compute shaders on the X axis.
- `LIMIT_MAX_COMPUTE_WORKGROUP_SIZE_Y = 33` — Maximum workgroup size for compute shaders on the Y axis.
- `LIMIT_MAX_COMPUTE_WORKGROUP_SIZE_Z = 34` — Maximum workgroup size for compute shaders on the Z axis.
- `LIMIT_MAX_VIEWPORT_DIMENSIONS_X = 35` — Maximum viewport width (in pixels).
- `LIMIT_MAX_VIEWPORT_DIMENSIONS_Y = 36` — Maximum viewport height (in pixels).
- `LIMIT_METALFX_TEMPORAL_SCALER_MIN_SCALE = 46` — Returns the smallest value for `ProjectSettings.rendering/scaling_3d/scale` when using the MetalFX temporal upscaler.
- `LIMIT_METALFX_TEMPORAL_SCALER_MAX_SCALE = 47` — Returns the largest value for `ProjectSettings.rendering/scaling_3d/scale` when using the MetalFX temporal upscaler.

## Enum MemoryType

- `MEMORY_TEXTURES = 0` — Memory taken by textures.
- `MEMORY_BUFFERS = 1` — Memory taken by buffers.
- `MEMORY_TOTAL = 2` — Total memory taken.

## Enum BreadcrumbMarker

- `NONE = 0` — No breadcrumb marker will be added.
- `REFLECTION_PROBES = 65536` — During a GPU crash in dev or debug mode, Godot's error message will include `"REFLECTION_PROBES"` for added context as to when the crash occurred.
- `SKY_PASS = 131072` — During a GPU crash in dev or debug mode, Godot's error message will include `"SKY_PASS"` for added context as to when the crash occurred.
- `LIGHTMAPPER_PASS = 196608` — During a GPU crash in dev or debug mode, Godot's error message will include `"LIGHTMAPPER_PASS"` for added context as to when the crash occurred.
- `SHADOW_PASS_DIRECTIONAL = 262144` — During a GPU crash in dev or debug mode, Godot's error message will include `"SHADOW_PASS_DIRECTIONAL"` for added context as to when the crash occurred.
- `SHADOW_PASS_CUBE = 327680` — During a GPU crash in dev or debug mode, Godot's error message will include `"SHADOW_PASS_CUBE"` for added context as to when the crash occurred.
- `OPAQUE_PASS = 393216` — During a GPU crash in dev or debug mode, Godot's error message will include `"OPAQUE_PASS"` for added context as to when the crash occurred.
- `ALPHA_PASS = 458752` — During a GPU crash in dev or debug mode, Godot's error message will include `"ALPHA_PASS"` for added context as to when the crash occurred.
- `TRANSPARENT_PASS = 524288` — During a GPU crash in dev or debug mode, Godot's error message will include `"TRANSPARENT_PASS"` for added context as to when the crash occurred.
- `POST_PROCESSING_PASS = 589824` — During a GPU crash in dev or debug mode, Godot's error message will include `"POST_PROCESSING_PASS"` for added context as to when the crash occurred.
- `BLIT_PASS = 655360` — During a GPU crash in dev or debug mode, Godot's error message will include `"BLIT_PASS"` for added context as to when the crash occurred.
- `UI_PASS = 720896` — During a GPU crash in dev or debug mode, Godot's error message will include `"UI_PASS"` for added context as to when the crash occurred.
- `DEBUG_PASS = 786432` — During a GPU crash in dev or debug mode, Godot's error message will include `"DEBUG_PASS"` for added context as to when the crash occurred.

## Enum DrawFlags

- `DRAW_DEFAULT_ALL = 0` — Do not clear or ignore any attachments.
- `DRAW_CLEAR_COLOR_0 = 1` — Clear the first color attachment.
- `DRAW_CLEAR_COLOR_1 = 2` — Clear the second color attachment.
- `DRAW_CLEAR_COLOR_2 = 4` — Clear the third color attachment.
- `DRAW_CLEAR_COLOR_3 = 8` — Clear the fourth color attachment.
- `DRAW_CLEAR_COLOR_4 = 16` — Clear the fifth color attachment.
- `DRAW_CLEAR_COLOR_5 = 32` — Clear the sixth color attachment.
- `DRAW_CLEAR_COLOR_6 = 64` — Clear the seventh color attachment.
- `DRAW_CLEAR_COLOR_7 = 128` — Clear the eighth color attachment.
- `DRAW_CLEAR_COLOR_MASK = 255` — Mask for clearing all color attachments.
- `DRAW_CLEAR_COLOR_ALL = 255` — Clear all color attachments.
- `DRAW_IGNORE_COLOR_0 = 256` — Ignore the previous contents of the first color attachment.
- `DRAW_IGNORE_COLOR_1 = 512` — Ignore the previous contents of the second color attachment.
- `DRAW_IGNORE_COLOR_2 = 1024` — Ignore the previous contents of the third color attachment.
- `DRAW_IGNORE_COLOR_3 = 2048` — Ignore the previous contents of the fourth color attachment.
- `DRAW_IGNORE_COLOR_4 = 4096` — Ignore the previous contents of the fifth color attachment.
- `DRAW_IGNORE_COLOR_5 = 8192` — Ignore the previous contents of the sixth color attachment.
- `DRAW_IGNORE_COLOR_6 = 16384` — Ignore the previous contents of the seventh color attachment.
- `DRAW_IGNORE_COLOR_7 = 32768` — Ignore the previous contents of the eighth color attachment.
- `DRAW_IGNORE_COLOR_MASK = 65280` — Mask for ignoring all the previous contents of the color attachments.
- `DRAW_IGNORE_COLOR_ALL = 65280` — Ignore the previous contents of all color attachments.
- `DRAW_CLEAR_DEPTH = 65536` — Clear the depth attachment.
- `DRAW_IGNORE_DEPTH = 131072` — Ignore the previous contents of the depth attachment.
- `DRAW_CLEAR_STENCIL = 262144` — Clear the stencil attachment.
- `DRAW_IGNORE_STENCIL = 524288` — Ignore the previous contents of the stencil attachment.
- `DRAW_CLEAR_ALL = 327935` — Clear all attachments.
- `DRAW_IGNORE_ALL = 720640` — Ignore the previous contents of all attachments.

## Constants

- `INVALID_ID = -1` — Returned by functions that return an ID if a value is invalid.
- `INVALID_FORMAT_ID = -1` — Returned by functions that return a format ID if a value is invalid.
