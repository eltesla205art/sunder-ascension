# ImageFormatLoader

**Inherits:** RefCounted

Base class to add support for specific image formats.

The engine supports multiple image formats out of the box (PNG, SVG, JPEG, WebP to name a few), but you can choose to implement support for additional image formats by extending ImageFormatLoaderExtension.

## Enum LoaderFlags

- `FLAG_NONE = 0` — Default loading behavior.
- `FLAG_FORCE_LINEAR = 1` — If set, the image is converted from sRGB to linear encoding.
- `FLAG_CONVERT_COLORS = 2` — If set, a predefined color map is applied to the image.
