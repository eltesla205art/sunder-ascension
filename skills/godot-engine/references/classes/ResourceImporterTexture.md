# ResourceImporterTexture

**Inherits:** ResourceImporter

Imports an image for use in 2D or 3D rendering.

This importer imports CompressedTexture2D resources. If you need to process the image in scripts in a more convenient way, use ResourceImporterImage instead. See also ResourceImporterLayeredTexture.

## Properties

- `compress/channel_pack: int` = `0` — Controls how color channels should be used in the imported texture. sRGB Friendly: Prevents the R and RG color formats from being used, as they do not support nonlinear sRGB encoding.
- `compress/hdr_compression: int` = `1` — Controls how VRAM compression should be performed for HDR images.
- `compress/high_quality: bool` = `false` — If `true`, uses BPTC compression on desktop platforms and ASTC compression on mobile platforms.
- `compress/high_quality_mode: int` = `0` — Controls the priorities of the VRAM compression when `compress/high_quality` is enabled.
- `compress/lossy_quality: float` = `0.7` — The quality to use when using the Lossy compression mode.
- `compress/mode: int` = `0` — The compression mode to use.
- `compress/normal_map: int` = `0` — When using a texture as normal map, only the red and green channels are required.
- `compress/rdo_quality_loss: float` = `0.0` — If greater than or equal to `0.01`, enables Rate-Distortion Optimization (RDO) to reduce file size.
- `compress/uastc_level: int` = `0` — The UASTC encoding level.
- `detect_3d/compress_to: int` = `1` — This changes the `compress/mode` option that is used when a texture is detected as being used in 3D.
- `editor/convert_colors_with_editor_theme: bool` = `false` — If `true`, converts the imported image's colors to match `EditorSettings.interface/theme/icon_and_font_color`.
- `editor/scale_with_editor_scale: bool` = `false` — If `true`, scales the imported image to match `EditorSettings.interface/editor/appearance/custom_display_scale`.
- `mipmaps/alpha_test_threshold: float` = `0.5` — The alpha threshold used when preserving alpha test coverage across mipmap levels.
- `mipmaps/generate: bool` = `false` — If `true`, smaller versions of the texture are generated on import.
- `mipmaps/limit: int` = `-1` — Unimplemented.
- `mipmaps/preserve_alpha_test_coverage: bool` = `false` — If `true`, automatically adjusts alpha values to maintain consistent coverage when alpha testing is used.
- `process/channel_remap/alpha: int` = `3` — Specifies the data source of the output image's alpha channel.
- `process/channel_remap/blue: int` = `2` — Specifies the data source of the output image's blue channel.
- `process/channel_remap/green: int` = `1` — Specifies the data source of the output image's green channel.
- `process/channel_remap/red: int` = `0` — Specifies the data source of the output image's red channel.
- `process/fix_alpha_border: bool` = `true` — If `true`, puts pixels of the same surrounding color in transition from transparent to opaque areas.
- `process/hdr_as_srgb: bool` = `false` — Some HDR images you can find online may be broken and contain data that is encoded using the nonlinear sRGB transfer function (instead of using linear encoding).
- `process/hdr_clamp_exposure: bool` = `false` — If `true`, clamps exposure in the imported high dynamic range images using a smart clamping formula (without introducing visible clipping).
- `process/normal_map_invert_y: bool` = `false` *(deprecated)* — If `true`, convert the normal map from Y- (DirectX-style) to Y+ (OpenGL-style) by inverting its green color channel.
- `process/premult_alpha: bool` = `false` — An alternative to fixing darkened borders with `process/fix_alpha_border` is to use premultiplied alpha.
- `process/size_limit: int` = `0` — If set to a value greater than `0`, the size of the texture is limited on import to a value smaller than or equal to the value specified here.
- `roughness/mode: int` = `0` — The color channel to consider as a roughness map in this texture.
- `roughness/src_normal: String` = `""` — The path to the texture to consider as a normal map for roughness filtering on import.
- `svg/scale: float` = `1.0` — The scale the SVG should be rendered at, with `1.0` being the original design size.
