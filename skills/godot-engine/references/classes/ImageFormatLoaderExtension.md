# ImageFormatLoaderExtension

**Inherits:** ImageFormatLoader

Base class for creating ImageFormatLoader extensions (adding support for extra image formats).

The engine supports multiple image formats out of the box (PNG, SVG, JPEG, WebP to name a few), but you can choose to implement support for additional image formats by extending this class. Be sure to respect the documented return types and values. You should create an instance of it, and call `add_format_loader` to register that loader during the initialization phase.

## Methods

- `_get_recognized_extensions() -> PackedStringArray` *virtual const* — Returns the list of file extensions for this image format.
- `_load_image(image: Image, fileaccess: FileAccess, flags: ImageFormatLoader.LoaderFlags, scale: float) -> int[Error]` *virtual* — Loads the content of `fileaccess` into the provided `image`.
- `add_format_loader() -> void` — Add this format loader to the engine, allowing it to recognize the file extensions returned by `_get_recognized_extensions`.
- `remove_format_loader() -> void` — Remove this format loader from the engine.
