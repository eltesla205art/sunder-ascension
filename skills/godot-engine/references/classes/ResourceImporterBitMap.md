# ResourceImporterBitMap

**Inherits:** ResourceImporter

Imports a BitMap resource (2D array of boolean values).

BitMap resources are typically used as click masks in TextureButton and TouchScreenButton.

## Properties

- `create_from: int` = `0` — The data source to use for generating the bitmap.
- `threshold: float` = `0.5` — The threshold to use to determine which bits should be considered enabled or disabled.
