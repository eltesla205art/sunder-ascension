# Noise

**Inherits:** Resource

Abstract base class for noise generators.

This class defines the interface for noise generation libraries to inherit from. A default `get_seamless_image` implementation is provided for libraries that do not provide seamless noise. This function requests a larger image from the `get_image` method, reverses the quadrants of the image, then uses the strips of extra width to blend over the seams. Inheriting noise classes can optionally override this function to provide a more optimal algorithm.

## Methods

- `get_image(width: int, height: int, invert: bool = false, in_3d_space: bool = false, normalize: bool = true) -> Image` *const* — Returns an Image containing 2D noise values.
- `get_image_3d(width: int, height: int, depth: int, invert: bool = false, normalize: bool = true) -> Image[]` *const* — Returns an Array of Images containing 3D noise values for use with `ImageTexture3D.create`.
- `get_noise_1d(x: float) -> float` *const* — Returns the 1D noise value at the given (x) coordinate.
- `get_noise_2d(x: float, y: float) -> float` *const* — Returns the 2D noise value at the given position.
- `get_noise_2dv(v: Vector2) -> float` *const* — Returns the 2D noise value at the given position.
- `get_noise_3d(x: float, y: float, z: float) -> float` *const* — Returns the 3D noise value at the given position.
- `get_noise_3dv(v: Vector3) -> float` *const* — Returns the 3D noise value at the given position.
- `get_seamless_image(width: int, height: int, invert: bool = false, in_3d_space: bool = false, skirt: float = 0.1, normalize: bool = true) -> Image` *const* — Returns an Image containing seamless 2D noise values.
- `get_seamless_image_3d(width: int, height: int, depth: int, invert: bool = false, skirt: float = 0.1, normalize: bool = true) -> Image[]` *const* — Returns an Array of Images containing seamless 3D noise values for use with `ImageTexture3D.create`.
