# CanvasGroup

**Inherits:** Node2D

Merges several 2D nodes into a single draw operation.

Child CanvasItem nodes of a CanvasGroup are drawn as a single object. It allows to e.g. draw overlapping translucent 2D nodes without causing the overlapping sections to be more opaque than intended (set the `CanvasItem.self_modulate` property on the CanvasGroup to achieve this effect). Note: The CanvasGroup uses a custom shader to read from the backbuffer to draw its children. Assigning a Material to the CanvasGroup overrides the built-in shader.

## Properties

- `clear_margin: float` = `10.0` — Sets the size of the margin used to expand the clearing rect of this CanvasGroup.
- `fit_margin: float` = `10.0` — Sets the size of a margin used to expand the drawable rect of this CanvasGroup.
- `use_mipmaps: bool` = `false` — If `true`, calculates mipmaps for the backbuffer before drawing the CanvasGroup so that mipmaps can be used in a custom ShaderMaterial attached to the CanvasGroup.
