# ExternalTexture

**Inherits:** Texture2D

Texture which displays the content of an external buffer.

Displays the content of an external buffer provided by the platform. Requires the OES_EGL_image_external extension (OpenGL) or VK_ANDROID_external_memory_android_hardware_buffer extension (Vulkan). Note: This is currently only supported in Android builds.

## Properties

- `resource_local_to_scene: bool` = `false` — 
- `size: Vector2` = `Vector2(256, 256)` — External texture size.

## Methods

- `get_external_texture_id() -> int` *const* — Returns the external texture ID.
- `set_external_buffer_id(external_buffer_id: int) -> void` — Sets the external buffer ID.
