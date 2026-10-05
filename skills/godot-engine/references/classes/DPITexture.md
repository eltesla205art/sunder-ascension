# DPITexture

**Inherits:** Texture2D

An automatically scalable Texture2D based on an SVG image.

An automatically scalable Texture2D based on an SVG image. DPITextures are used to automatically re-rasterize icons and other texture based UI theme elements to match viewport scale and font oversampling. See also `ProjectSettings.display/window/stretch/mode` ("canvas_items" mode) and `Viewport.oversampling_override`.

## Properties

- `base_scale: float` = `1.0` — Texture scale.
- `color_map: Dictionary` = `{}` — If set, remaps texture colors according to Color-Color map.
- `fix_alpha_border: bool` = `false` — If `true`, puts pixels of the same surrounding color in transition from transparent to opaque areas.
- `premult_alpha: bool` = `false` — An alternative to fixing darkened borders with `fix_alpha_border` is to use premultiplied alpha.
- `resource_local_to_scene: bool` = `false` — 
- `saturation: float` = `1.0` — Overrides texture saturation.

## Methods

- `create_from_string(source: String, scale: float = 1.0, saturation: float = 1.0, color_map: Dictionary = {}) -> DPITexture` *static* — Creates a new DPITexture and initializes it by allocating and setting the SVG data to `source`.
- `get_scaled_rid() -> RID` *const* — Returns the RID of the texture rasterized to match the oversampling of the currently drawn canvas item.
- `get_source() -> String` *const* — Returns this SVG texture's source code.
- `set_size_override(size: Vector2i) -> void` — Resizes the texture to the specified dimensions.
- `set_source(source: String) -> void` — Sets this SVG texture's source code.
