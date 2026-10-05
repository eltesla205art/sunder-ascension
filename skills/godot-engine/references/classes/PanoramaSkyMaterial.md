# PanoramaSkyMaterial

**Inherits:** Material

A material that provides a special texture to a Sky, usually an HDR panorama.

A resource referenced in a Sky that is used to draw a background. PanoramaSkyMaterial functions similar to skyboxes in other engines, except it uses an equirectangular sky map instead of a Cubemap. Using an HDR panorama is strongly recommended for accurate, high-quality reflections. Godot supports the Radiance HDR (`.hdr`) and OpenEXR (`.exr`) image formats for this purpose.

## Properties

- `energy_multiplier: float` = `1.0` — The sky's overall brightness multiplier.
- `filter: bool` = `true` — A boolean value to determine if the background texture should be filtered or not.
- `panorama: Texture2D` — Texture2D to be applied to the PanoramaSkyMaterial.
