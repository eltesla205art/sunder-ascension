# BitMap

**Inherits:** Resource

Boolean matrix.

A two-dimensional array of boolean values, can be used to efficiently store a binary matrix (every matrix element takes only one bit) and query the values using natural cartesian coordinates.

## Methods

- `convert_to_image() -> Image` *const* — Returns an image of the same size as the bitmap and with an `Image.Format` of type `Image.FORMAT_L8`.
- `create(size: Vector2i) -> void` — Creates a bitmap with the specified size, filled with `false`.
- `create_from_image_alpha(image: Image, threshold: float = 0.1) -> void` — Creates a bitmap that matches the given image dimensions, every element of the bitmap is set to `false` if the alpha value of the image at that position is equal to `threshold` or less, and `true` in other case.
- `get_bit(x: int, y: int) -> bool` *const* — Returns bitmap's value at the specified position.
- `get_bitv(position: Vector2i) -> bool` *const* — Returns bitmap's value at the specified position.
- `get_size() -> Vector2i` *const* — Returns bitmap's dimensions.
- `get_true_bit_count() -> int` *const* — Returns the number of bitmap elements that are set to `true`.
- `grow_mask(pixels: int, rect: Rect2i) -> void` — Applies morphological dilation or erosion to the bitmap.
- `opaque_to_polygons(rect: Rect2i, epsilon: float = 2.0) -> PackedVector2Array[]` *const* — Creates an Array of polygons covering a rectangular portion of the bitmap.
- `resize(new_size: Vector2i) -> void` — Resizes the image to `new_size`.
- `set_bit(x: int, y: int, bit: bool) -> void` — Sets the bitmap's element at the specified position, to the specified value.
- `set_bit_rect(rect: Rect2i, bit: bool) -> void` — Sets a rectangular portion of the bitmap to the specified value.
- `set_bitv(position: Vector2i, bit: bool) -> void` — Sets the bitmap's element at the specified position, to the specified value.
