# AtlasTexture

**Inherits:** Texture2D

A texture that crops out part of another Texture2D.

Texture2D resource that draws only part of its `atlas` texture, as defined by the `region`. An additional `margin` can also be set, which is useful for small adjustments. Multiple AtlasTexture resources can be cropped from the same `atlas`. Packing many smaller textures into a singular large texture helps to optimize video memory costs and render calls.

## Properties

- `atlas: Texture2D` — The texture that contains the atlas.
- `filter_clip: bool` = `false` — If `true`, the area outside of the `region` is clipped to avoid bleeding of the surrounding texture pixels.
- `margin: Rect2` = `Rect2(0, 0, 0, 0)` — The margin around the `region`.
- `region: Rect2` = `Rect2(0, 0, 0, 0)` — The region used to draw the `atlas`.
- `resource_local_to_scene: bool` = `false` —
