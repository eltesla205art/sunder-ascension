# GPUParticlesCollisionSDF3D

**Inherits:** GPUParticlesCollision3D

A baked signed distance field 3D particle collision shape affecting GPUParticles3D nodes.

A baked signed distance field 3D particle collision shape affecting GPUParticles3D nodes. Signed distance fields (SDF) allow for efficiently representing approximate collision shapes for convex and concave objects of any shape. This is more flexible than GPUParticlesCollisionHeightField3D, but it requires a baking step. Baking: The signed distance field texture can be baked by selecting the GPUParticlesCollisionSDF3D node in the editor, then clicking Bake SDF at the top of the 3D viewport.

## Properties

- `bake_mask: int` = `4294967295` — The visual layers to account for when baking the particle collision SDF.
- `resolution: GPUParticlesCollisionSDF3D.Resolution` = `2` — The bake resolution to use for the signed distance field `texture`.
- `size: Vector3` = `Vector3(2, 2, 2)` — The collision SDF's size in 3D units.
- `texture: Texture3D` — The 3D texture representing the signed distance field.
- `thickness: float` = `1.0` — The collision shape's thickness.

## Methods

- `get_bake_mask_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `bake_mask` is enabled, given a `layer_number` between 1 and 32.
- `set_bake_mask_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `bake_mask`, given a `layer_number` between 1 and 32.

## Enum Resolution

- `RESOLUTION_16 = 0` — Bake a 16×16×16 signed distance field.
- `RESOLUTION_32 = 1` — Bake a 32×32×32 signed distance field.
- `RESOLUTION_64 = 2` — Bake a 64×64×64 signed distance field.
- `RESOLUTION_128 = 3` — Bake a 128×128×128 signed distance field.
- `RESOLUTION_256 = 4` — Bake a 256×256×256 signed distance field.
- `RESOLUTION_512 = 5` — Bake a 512×512×512 signed distance field.
- `RESOLUTION_MAX = 6` — Represents the size of the `Resolution` enum.
