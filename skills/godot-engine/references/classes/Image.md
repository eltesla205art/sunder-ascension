# Image

**Inherits:** Resource

Image datatype.

Native image datatype. Contains image data which can be converted to an ImageTexture and provides commonly used image processing methods. The maximum width and height for an Image are `MAX_WIDTH` and `MAX_HEIGHT`. An Image cannot be assigned to a texture property of an object directly (such as `Sprite2D.texture`), and has to be converted manually to an ImageTexture first.

## Properties

- `data: Dictionary` = `{ "data": PackedByteArray(), "format": "Lum8", "height": 0, "mipmaps": false, "width": 0 }` — Holds all the image's color data in a given format.

## Methods

- `adjust_bcs(brightness: float, contrast: float, saturation: float) -> void` — Adjusts this image's `brightness`, `contrast`, and `saturation` by the given values.
- `blend_rect(src: Image, src_rect: Rect2i, dst: Vector2i) -> void` — Alpha-blends `src_rect` from `src` image to this image at coordinates `dst`, clipped accordingly to both image bounds.
- `blend_rect_mask(src: Image, mask: Image, src_rect: Rect2i, dst: Vector2i) -> void` — Alpha-blends `src_rect` from `src` image to this image using `mask` image at coordinates `dst`, clipped accordingly to both image bounds.
- `blit_rect(src: Image, src_rect: Rect2i, dst: Vector2i) -> void` — Copies `src_rect` from `src` image to this image at coordinates `dst`, clipped accordingly to both image bounds.
- `blit_rect_mask(src: Image, mask: Image, src_rect: Rect2i, dst: Vector2i) -> void` — Blits `src_rect` area from `src` image to this image at the coordinates given by `dst`, clipped accordingly to both image bounds.
- `bump_map_to_normal_map(bump_scale: float = 1.0) -> void` — Converts a bump map to a normal map.
- `clear_mipmaps() -> void` — Removes the image's mipmaps.
- `compress(mode: Image.CompressMode, source: Image.CompressSource = 0, profile: Image.CompressProfile = 0) -> int[Error]` — Compresses the image with a VRAM-compressed format to use less memory.
- `compress_from_channels(mode: Image.CompressMode, channels: Image.UsedChannels, profile: Image.CompressProfile = 0) -> int[Error]` — Compresses the image with a VRAM-compressed format to use less memory.
- `compute_image_metrics(compared_image: Image, use_luma: bool) -> Dictionary` — Compute image metrics on the current image and the compared image.
- `convert(format: Image.Format) -> void` — Converts this image's format to the given `format`.
- `copy_from(src: Image) -> void` — Copies `src` image to this image.
- `create(width: int, height: int, use_mipmaps: bool, format: Image.Format) -> Image` *static* *(deprecated)* — Creates an empty image of the given size and format.
- `create_empty(width: int, height: int, use_mipmaps: bool, format: Image.Format) -> Image` *static* — Creates an empty image of the given size and format.
- `create_from_data(width: int, height: int, use_mipmaps: bool, format: Image.Format, data: PackedByteArray) -> Image` *static* — Creates a new image of the given size and format.
- `crop(width: int, height: int) -> void` — Crops the image to the given `width` and `height`.
- `decompress() -> int[Error]` — Decompresses the image if it is VRAM-compressed in a supported format.
- `detect_alpha() -> int[Image.AlphaMode]` *const* — Returns `ALPHA_BLEND` if the image has data for alpha values.
- `detect_used_channels(source: Image.CompressSource = 0) -> int[Image.UsedChannels]` *const* — Returns the color channels used by this image.
- `fill(color: Color) -> void` — Fills the image with `color`.
- `fill_rect(rect: Rect2i, color: Color) -> void` — Fills `rect` with `color`.
- `fix_alpha_edges() -> void` — Blends low-alpha pixels with nearby pixels.
- `flip_x() -> void` — Flips the image horizontally.
- `flip_y() -> void` — Flips the image vertically.
- `generate_mipmaps(renormalize: bool = false, preserve_alpha_test_coverage: bool = false, alpha_test_threshold: float = 0.5) -> int[Error]` — Generates mipmaps for the image.
- `get_data() -> PackedByteArray` *const* — Returns a copy of the image's raw data.
- `get_data_size() -> int` *const* — Returns size (in bytes) of the image's raw data.
- `get_format() -> int[Image.Format]` *const* — Returns this image's format.
- `get_height() -> int` *const* — Returns the image's height.
- `get_mipmap_count() -> int` *const* — Returns the number of mipmap levels or 0 if the image has no mipmaps.
- `get_mipmap_offset(mipmap: int) -> int` *const* — Returns the offset where the image's mipmap with index `mipmap` is stored in the `data` dictionary.
- `get_pixel(x: int, y: int) -> Color` *const* — Returns the color of the pixel at `(x, y)`.
- `get_pixelv(point: Vector2i) -> Color` *const* — Returns the color of the pixel at `point`.
- `get_region(region: Rect2i) -> Image` *const* — Returns a new Image that is a copy of this Image's area specified with `region`.
- `get_size() -> Vector2i` *const* — Returns the image's size (width and height).
- `get_used_rect() -> Rect2i` *const* — Returns a Rect2i enclosing the visible portion of the image, considering each pixel with a non-zero alpha channel as visible.
- `get_width() -> int` *const* — Returns the image's width.
- `has_mipmaps() -> bool` *const* — Returns `true` if the image has generated mipmaps.
- `is_compressed() -> bool` *const* — Returns `true` if the image is compressed.
- `is_empty() -> bool` *const* — Returns `true` if the image has no data.
- `is_invisible() -> bool` *const* — Returns `true` if all the image's pixels have an alpha value of 0.
- `linear_to_srgb() -> void` — Converts the entire image from linear encoding to nonlinear sRGB encoding.
- `load(path: String) -> int[Error]` — Loads an image from file `path`.
- `load_bmp_from_buffer(buffer: PackedByteArray) -> int[Error]` — Loads an image from the binary contents of a BMP file.
- `load_dds_from_buffer(buffer: PackedByteArray) -> int[Error]` — Loads an image from the binary contents of a DDS file.
- `load_exr_from_buffer(buffer: PackedByteArray) -> int[Error]` — Loads an image from the binary contents of an OpenEXR file.
- `load_from_file(path: String) -> Image` *static* — Creates a new Image and loads data from the specified file.
- `load_jpg_from_buffer(buffer: PackedByteArray) -> int[Error]` — Loads an image from the binary contents of a JPEG file.
- `load_ktx_from_buffer(buffer: PackedByteArray) -> int[Error]` — Loads an image from the binary contents of a KTX file.
- `load_png_from_buffer(buffer: PackedByteArray) -> int[Error]` — Loads an image from the binary contents of a PNG file.
- `load_svg_from_buffer(buffer: PackedByteArray, scale: float = 1.0) -> int[Error]` — Loads an image from the UTF-8 binary contents of an uncompressed SVG file (.svg).
- `load_svg_from_string(svg_str: String, scale: float = 1.0) -> int[Error]` — Loads an image from the string contents of an SVG file (.svg).
- `load_tga_from_buffer(buffer: PackedByteArray) -> int[Error]` — Loads an image from the binary contents of a TGA file.
- `load_webp_from_buffer(buffer: PackedByteArray) -> int[Error]` — Loads an image from the binary contents of a WebP file.
- `normal_map_to_xy() -> void` — Converts the image's data to represent coordinates on a 3D plane.
- `premultiply_alpha() -> void` — Multiplies color values with alpha values.
- `resize(width: int, height: int, interpolation: Image.Interpolation = 1) -> void` — Resizes the image to the given `width` and `height`.
- `resize_to_po2(square: bool = false, interpolation: Image.Interpolation = 1) -> void` — Resizes the image to the nearest power of 2 for the width and height.
- `rgbe_to_srgb() -> Image` — Converts a standard linear RGBE (Red Green Blue Exponent) image to an image that uses nonlinear sRGB encoding.
- `rotate_90(direction: ClockDirection) -> void` — Rotates the image in the specified `direction` by `90` degrees.
- `rotate_180() -> void` — Rotates the image by `180` degrees.
- `save_dds(path: String) -> int[Error]` *const* — Saves the image as a DDS (DirectDraw Surface) file to `path`.
- `save_dds_to_buffer() -> PackedByteArray` *const* — Saves the image as a DDS (DirectDraw Surface) file to a byte array.
- `save_exr(path: String, grayscale: bool = false, color_image: bool = false, max_linear_value: float = -1.0) -> int[Error]` *const* — Saves the image as an EXR file to `path`.
- `save_exr_to_buffer(grayscale: bool = false, color_image: bool = false, max_linear_value: float = -1.0) -> PackedByteArray` *const* — Saves the image as an EXR file to a byte array.
- `save_jpg(path: String, quality: float = 0.75) -> int[Error]` *const* — Saves the image as a JPEG file to `path` with the specified `quality` between `0.01` and `1.0` (inclusive).
- `save_jpg_to_buffer(quality: float = 0.75) -> PackedByteArray` *const* — Saves the image as a JPEG file to a byte array with the specified `quality` between `0.01` and `1.0` (inclusive).
- `save_png(path: String) -> int[Error]` *const* — Saves the image as a PNG file to the file at `path`.
- `save_png_to_buffer() -> PackedByteArray` *const* — Saves the image as a PNG file to a byte array.
- `save_webp(path: String, lossy: bool = false, quality: float = 0.75) -> int[Error]` *const* — Saves the image as a WebP (Web Picture) file to the file at `path`.
- `save_webp_to_buffer(lossy: bool = false, quality: float = 0.75) -> PackedByteArray` *const* — Saves the image as a WebP (Web Picture) file to a byte array.
- `set_data(width: int, height: int, use_mipmaps: bool, format: Image.Format, data: PackedByteArray) -> void` — Overwrites data of an existing Image.
- `set_pixel(x: int, y: int, color: Color) -> void` — Sets the Color of the pixel at `(x, y)` to `color`.
- `set_pixelv(point: Vector2i, color: Color) -> void` — Sets the Color of the pixel at `point` to `color`.
- `shrink_x2() -> void` — Shrinks the image by a factor of 2 on each axis (this divides the pixel count by 4).
- `srgb_to_linear() -> void` — Converts the raw data from nonlinear sRGB encoding to linear encoding.

## Enum Format

- `FORMAT_L8 = 0` — Texture format with a single 8-bit depth representing luminance.
- `FORMAT_LA8 = 1` — OpenGL texture format with two values, luminance and alpha each stored with 8 bits.
- `FORMAT_R8 = 2` — OpenGL texture format `RED` with a single component and a bitdepth of 8.
- `FORMAT_RG8 = 3` — OpenGL texture format `RG` with two components and a bitdepth of 8 for each.
- `FORMAT_RGB8 = 4` — OpenGL texture format `RGB` with three components, each with a bitdepth of 8.
- `FORMAT_RGBA8 = 5` — OpenGL texture format `RGBA` with four components, each with a bitdepth of 8.
- `FORMAT_RGBA4444 = 6` — OpenGL texture format `RGBA` with four components, each with a bitdepth of 4.
- `FORMAT_RGB565 = 7` — OpenGL texture format `RGB` with three components.
- `FORMAT_RF = 8` — OpenGL texture format `GL_R32F` where there's one component, a 32-bit floating-point value.
- `FORMAT_RGF = 9` — OpenGL texture format `GL_RG32F` where there are two components, each a 32-bit floating-point values.
- `FORMAT_RGBF = 10` — OpenGL texture format `GL_RGB32F` where there are three components, each a 32-bit floating-point values.
- `FORMAT_RGBAF = 11` — OpenGL texture format `GL_RGBA32F` where there are four components, each a 32-bit floating-point values.
- `FORMAT_RH = 12` — OpenGL texture format `GL_R16F` where there's one component, a 16-bit "half-precision" floating-point value.
- `FORMAT_RGH = 13` — OpenGL texture format `GL_RG16F` where there are two components, each a 16-bit "half-precision" floating-point value.
- `FORMAT_RGBH = 14` — OpenGL texture format `GL_RGB16F` where there are three components, each a 16-bit "half-precision" floating-point value.
- `FORMAT_RGBAH = 15` — OpenGL texture format `GL_RGBA16F` where there are four components, each a 16-bit "half-precision" floating-point value.
- `FORMAT_RGBE9995 = 16` — A special OpenGL texture format where the three color components have 9 bits of precision and all three share a single 5-bit exponent.
- `FORMAT_DXT1 = 17` — The S3TC texture format that uses Block Compression 1, and is the smallest variation of S3TC, only providing 1 bit of alpha and color data being premultiplied with alpha.
- `FORMAT_DXT3 = 18` — The S3TC texture format that uses Block Compression 2, and color data is interpreted as not having been premultiplied by alpha.
- `FORMAT_DXT5 = 19` — The S3TC texture format also known as Block Compression 3 or BC3 that contains 64 bits of alpha channel data followed by 64 bits of DXT1-encoded color data.
- `FORMAT_RGTC_R = 20` — Texture format that uses Red Green Texture Compression, normalizing the red channel data using the same compression algorithm that DXT5 uses for the alpha channel.
- `FORMAT_RGTC_RG = 21` — Texture format that uses Red Green Texture Compression, normalizing the red and green channel data using the same compression algorithm that DXT5 uses for the alpha channel.
- `FORMAT_BPTC_RGBA = 22` — Texture format that uses BPTC compression with unsigned normalized RGBA components.
- `FORMAT_BPTC_RGBF = 23` — Texture format that uses BPTC compression with signed floating-point RGB components.
- `FORMAT_BPTC_RGBFU = 24` — Texture format that uses BPTC compression with unsigned floating-point RGB components.
- `FORMAT_ETC = 25` — Ericsson Texture Compression format 1, also referred to as "ETC1", and is part of the OpenGL ES graphics standard.
- `FORMAT_ETC2_R11 = 26` — Ericsson Texture Compression format 2 (`R11_EAC` variant), which provides one channel of unsigned data.
- `FORMAT_ETC2_R11S = 27` — Ericsson Texture Compression format 2 (`SIGNED_R11_EAC` variant), which provides one channel of signed data.
- `FORMAT_ETC2_RG11 = 28` — Ericsson Texture Compression format 2 (`RG11_EAC` variant), which provides two channels of unsigned data.
- `FORMAT_ETC2_RG11S = 29` — Ericsson Texture Compression format 2 (`SIGNED_RG11_EAC` variant), which provides two channels of signed data.
- `FORMAT_ETC2_RGB8 = 30` — Ericsson Texture Compression format 2 (`RGB8` variant), which is a follow-up of ETC1 and compresses RGB888 data.
- `FORMAT_ETC2_RGBA8 = 31` — Ericsson Texture Compression format 2 (`RGBA8`variant), which compresses RGBA8888 data with full alpha support.
- `FORMAT_ETC2_RGB8A1 = 32` — Ericsson Texture Compression format 2 (`RGB8_PUNCHTHROUGH_ALPHA1` variant), which compresses RGBA data to make alpha either fully transparent or fully opaque.
- `FORMAT_ETC2_RA_AS_RG = 33` — Ericsson Texture Compression format 2 (`RGBA8` variant), which compresses RA data and interprets it as two channels (red and green).
- `FORMAT_DXT5_RA_AS_RG = 34` — The S3TC texture format also known as Block Compression 3 or BC3, which compresses RA data and interprets it as two channels (red and green).
- `FORMAT_ASTC_4x4 = 35` — Adaptive Scalable Texture Compression.
- `FORMAT_ASTC_4x4_HDR = 36` — Same format as `FORMAT_ASTC_4x4`, but with the hint to let the GPU know it is used for HDR.
- `FORMAT_ASTC_8x8 = 37` — Adaptive Scalable Texture Compression.
- `FORMAT_ASTC_8x8_HDR = 38` — Same format as `FORMAT_ASTC_8x8`, but with the hint to let the GPU know it is used for HDR.
- `FORMAT_R16 = 39` — OpenGL texture format `GL_R16` where there's one component, a 16-bit unsigned normalized integer value.
- `FORMAT_RG16 = 40` — OpenGL texture format `GL_RG16` where there are two components, each a 16-bit unsigned normalized integer value.
- `FORMAT_RGB16 = 41` — OpenGL texture format `GL_RGB16` where there are three components, each a 16-bit unsigned normalized integer value.
- `FORMAT_RGBA16 = 42` — OpenGL texture format `GL_RGBA16` where there are four components, each a 16-bit unsigned normalized integer value.
- `FORMAT_R16I = 43` — OpenGL texture format `GL_R16UI` where there's one component, a 16-bit unsigned integer value.
- `FORMAT_RG16I = 44` — OpenGL texture format `GL_RG16UI` where there are two components, each a 16-bit unsigned integer value.
- `FORMAT_RGB16I = 45` — OpenGL texture format `GL_RGB16UI` where there are three components, each a 16-bit unsigned integer value.
- `FORMAT_RGBA16I = 46` — OpenGL texture format `GL_RGBA16UI` where there are four components, each a 16-bit unsigned integer value.
- `FORMAT_ASTC_6x6 = 47` — Adaptive Scalable Texture Compression.
- `FORMAT_ASTC_6x6_HDR = 48` — Same format as `FORMAT_ASTC_6x6`, but with the hint to let the GPU know it is used for HDR.
- `FORMAT_MAX = 49` — Represents the size of the `Format` enum.

## Enum Interpolation

- `INTERPOLATE_NEAREST = 0` — Performs nearest-neighbor interpolation.
- `INTERPOLATE_BILINEAR = 1` — Performs bilinear interpolation.
- `INTERPOLATE_CUBIC = 2` — Performs cubic interpolation.
- `INTERPOLATE_TRILINEAR = 3` — Performs bilinear separately on the two most-suited mipmap levels, then linearly interpolates between them.
- `INTERPOLATE_LANCZOS = 4` — Performs Lanczos interpolation.

## Enum AlphaMode

- `ALPHA_NONE = 0` — Image is fully opaque.
- `ALPHA_BIT = 1` — Image stores either fully opaque or fully transparent pixels.
- `ALPHA_BLEND = 2` — Image stores alpha data with values varying between `0.0` and `1.0`.

## Enum CompressMode

- `COMPRESS_S3TC = 0` — Use S3TC compression.
- `COMPRESS_ETC = 1` — Use ETC compression.
- `COMPRESS_ETC2 = 2` — Use ETC2 compression.
- `COMPRESS_BPTC = 3` — Use BPTC compression.
- `COMPRESS_ASTC = 4` — Use ASTC compression.
- `COMPRESS_MAX = 5` — Represents the size of the `CompressMode` enum.

## Enum UsedChannels

- `USED_CHANNELS_L = 0` — The image only uses one channel for luminance (grayscale).
- `USED_CHANNELS_LA = 1` — The image uses two channels for luminance and alpha, respectively.
- `USED_CHANNELS_R = 2` — The image only uses the red channel.
- `USED_CHANNELS_RG = 3` — The image uses two channels for red and green.
- `USED_CHANNELS_RGB = 4` — The image uses three channels for red, green, and blue.
- `USED_CHANNELS_RGBA = 5` — The image uses four channels for red, green, blue, and alpha.

## Enum CompressSource

- `COMPRESS_SOURCE_GENERIC = 0` — Source texture (before compression) is a regular texture.
- `COMPRESS_SOURCE_SRGB = 1` — Source texture (before compression) uses nonlinear sRGB encoding.
- `COMPRESS_SOURCE_NORMAL = 2` — Source texture (before compression) is a normal texture (e.g. it can be compressed into two channels).

## Enum CompressProfile

- `COMPRESS_PROFILE_AUTOMATIC = 0` — Automatically adjusts the quality level based on the number of unique color channels present in the image.
- `COMPRESS_PROFILE_MAX_QUALITY = 1` — Prioritizes highest quality over compression.
- `COMPRESS_PROFILE_COMPRESSED = 2` — Prioritizes some compression over quality.
- `COMPRESS_PROFILE_MAX_COMPRESSION = 3` — Prioritizes highest compression over quality.
- `COMPRESS_PROFILE_MAX = 4` — Represents the size of the `CompressProfile` enum.

## Enum ASTCFormat

- `ASTC_FORMAT_4x4 = 0` — Hint to indicate that the high quality 4×4 ASTC compression format should be used.
- `ASTC_FORMAT_8x8 = 1` — Hint to indicate that the low quality 8×8 ASTC compression format should be used.

## Constants

- `MAX_WIDTH = 16777216` — The maximal width allowed for Image resources.
- `MAX_HEIGHT = 16777216` — The maximal height allowed for Image resources.
