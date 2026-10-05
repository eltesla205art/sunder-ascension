# OpenXRCompositionLayer

**Inherits:** Node3D

The parent class of all OpenXR composition layer nodes.

Composition layers allow 2D viewports to be displayed inside of the headset by the XR compositor through special projections that retain their quality. This allows for rendering clear text while keeping the layer at a native resolution. Note: If the OpenXR runtime doesn't support the given composition layer type, a fallback mesh can be generated with a ViewportTexture, in order to emulate the composition layer.

## Properties

- `alpha_blend: bool` = `false` — Enables the blending the layer using its alpha channel.
- `android_surface_size: Vector2i` = `Vector2i(1024, 1024)` — The size of the Android surface to create if `use_android_surface` is enabled.
- `enable_hole_punch: bool` = `false` — Enables a technique called "hole punching", which allows putting the composition layer behind the main projection layer (i.e. setting `sort_order` to a negative value) while "punching a hole" through everything rendered by Godot so that the layer is still visible.
- `eye_visibility: OpenXRCompositionLayer.EyeVisibility` = `0` — The eye(s) the composition layer is visible to.
- `layer_viewport: SubViewport` — The SubViewport to render on the composition layer.
- `protected_content: bool` = `false` — If enabled, the OpenXR swapchain will be created with the `XR_SWAPCHAIN_CREATE_PROTECTED_CONTENT_BIT` flag, which will protect its contents from CPU access.
- `sort_order: int` = `1` — The sort order for this composition layer.
- `swapchain_state_alpha_swizzle: OpenXRCompositionLayer.Swizzle` = `3` — The swizzle value for the alpha channel of the swapchain state.
- `swapchain_state_blue_swizzle: OpenXRCompositionLayer.Swizzle` = `2` — The swizzle value for the blue channel of the swapchain state.
- `swapchain_state_border_color: Color` = `Color(0, 0, 0, 0)` — The border color of the swapchain state that is used when the wrap mode clamps to the border.
- `swapchain_state_green_swizzle: OpenXRCompositionLayer.Swizzle` = `1` — The swizzle value for the green channel of the swapchain state.
- `swapchain_state_horizontal_wrap: OpenXRCompositionLayer.Wrap` = `0` — The horizontal wrap mode of the swapchain state.
- `swapchain_state_mag_filter: OpenXRCompositionLayer.Filter` = `1` — The magnification filter of the swapchain state.
- `swapchain_state_max_anisotropy: float` = `1.0` — The max anisotropy of the swapchain state.
- `swapchain_state_min_filter: OpenXRCompositionLayer.Filter` = `1` — The minification filter of the swapchain state.
- `swapchain_state_mipmap_mode: OpenXRCompositionLayer.MipmapMode` = `2` — The mipmap mode of the swapchain state.
- `swapchain_state_red_swizzle: OpenXRCompositionLayer.Swizzle` = `0` — The swizzle value for the red channel of the swapchain state.
- `swapchain_state_vertical_wrap: OpenXRCompositionLayer.Wrap` = `0` — The vertical wrap mode of the swapchain state.
- `use_android_surface: bool` = `false` — If enabled, an Android surface will be created (with the dimensions from `android_surface_size`) which will provide the 2D content for the composition layer, rather than using `layer_viewport`.

## Methods

- `get_android_surface() -> JavaObject` — Returns a JavaObject representing an `android.view.Surface` if `use_android_surface` is enabled and OpenXR has created the surface.
- `intersects_ray(origin: Vector3, direction: Vector3) -> Vector2` *const* — Returns UV coordinates where the given ray intersects with the composition layer.
- `is_natively_supported() -> bool` *const* — Returns `true` if the OpenXR runtime natively supports this composition layer type.

## Enum Filter

- `FILTER_NEAREST = 0` — Perform nearest-neighbor filtering when sampling the texture.
- `FILTER_LINEAR = 1` — Perform linear filtering when sampling the texture.
- `FILTER_CUBIC = 2` — Perform cubic filtering when sampling the texture.

## Enum MipmapMode

- `MIPMAP_MODE_DISABLED = 0` — Disable mipmapping.
- `MIPMAP_MODE_NEAREST = 1` — Use the mipmap of the nearest resolution.
- `MIPMAP_MODE_LINEAR = 2` — Use linear interpolation of the two mipmaps of the nearest resolution.

## Enum Wrap

- `WRAP_CLAMP_TO_BORDER = 0` — Clamp the texture to its specified border color.
- `WRAP_CLAMP_TO_EDGE = 1` — Clamp the texture to its edge color.
- `WRAP_REPEAT = 2` — Repeat the texture infinitely.
- `WRAP_MIRRORED_REPEAT = 3` — Repeat the texture infinitely, mirroring it on each repeat.
- `WRAP_MIRROR_CLAMP_TO_EDGE = 4` — Mirror the texture once and then clamp the texture to its edge color.

## Enum Swizzle

- `SWIZZLE_RED = 0` — Maps a color channel to the value of the red channel.
- `SWIZZLE_GREEN = 1` — Maps a color channel to the value of the green channel.
- `SWIZZLE_BLUE = 2` — Maps a color channel to the value of the blue channel.
- `SWIZZLE_ALPHA = 3` — Maps a color channel to the value of the alpha channel.
- `SWIZZLE_ZERO = 4` — Maps a color channel to the value of zero.
- `SWIZZLE_ONE = 5` — Maps a color channel to the value of one.

## Enum EyeVisibility

- `EYE_VISIBILITY_BOTH = 0` — The layer is visible to both the left and right eyes.
- `EYE_VISIBILITY_LEFT = 1` — The layer is visible only to the left eye.
- `EYE_VISIBILITY_RIGHT = 2` — The layer is visible only to the right eye.
