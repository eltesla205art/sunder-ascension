# ResourceImporterSVG

**Inherits:** ResourceImporter

Imports an SVG file as an automatically scalable texture for use in UI elements and 2D rendering.

This importer imports DPITexture resources. See also ResourceImporterTexture and ResourceImporterImage.

## Properties

- `base_scale: float` = `1.0` — Texture scale.
- `color_map: Dictionary` = `{}` — If set, remaps texture colors according to Color-Color map.
- `compress: bool` = `true` — If `true`, uses lossless compression for the SVG source.
- `fix_alpha_border: bool` = `false` — If `true`, puts pixels of the same surrounding color in transition from transparent to opaque areas.
- `premult_alpha: bool` = `false` — An alternative to fixing darkened borders with `fix_alpha_border` is to use premultiplied alpha.
- `saturation: float` = `1.0` — Overrides texture saturation.
