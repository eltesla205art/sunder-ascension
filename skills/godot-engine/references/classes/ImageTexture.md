# ImageTexture

**Inherits:** Texture2D

A Texture2D based on an Image.

A Texture2D based on an Image. For an image to be displayed, an ImageTexture has to be created from it using the `create_from_image` method:  This way, textures can be created at run-time by loading images both from within the editor and externally. Warning: Prefer to load imported textures with `@GDScript.load` over loading them from within the filesystem dynamically with `Image.load`, as it may not work in exported projects:  This is because images have to be imported as a CompressedTexture2D first to be loaded with `@GDScript.load`. If you'd still like to load an image file just like any other Resource, import it as an Image resource instead, and then load it normally using the `@GDScript.load` method.

## Properties

- `resource_local_to_scene: bool` = `false` — 

## Methods

- `create_from_image(image: Image) -> ImageTexture` *static* — Creates a new ImageTexture and initializes it by allocating and setting the data from an Image.
- `set_image(image: Image) -> void` — Replaces the texture's data with a new Image.
- `set_size_override(size: Vector2i) -> void` — Resizes the texture to the specified dimensions.
- `update(image: Image) -> void` — Replaces the texture's data with a new Image.
