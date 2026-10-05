# GPUParticlesCollisionHeightField3D

**Inherits:** GPUParticlesCollision3D

A real-time heightmap-shaped 3D particle collision shape affecting GPUParticles3D nodes.

A real-time heightmap-shaped 3D particle collision shape affecting GPUParticles3D nodes. Heightmap shapes allow for efficiently representing collisions for convex and concave objects with a single "floor" (such as terrain). This is less flexible than GPUParticlesCollisionSDF3D, but it doesn't require a baking step. GPUParticlesCollisionHeightField3D can also be regenerated in real-time when it is moved, when the camera moves, or even continuously.

## Properties

- `follow_camera_enabled: bool` = `false` — If `true`, the GPUParticlesCollisionHeightField3D will follow the current camera in global space.
- `heightfield_mask: int` = `1048575` — The visual layers to account for when updating the heightmap.
- `resolution: GPUParticlesCollisionHeightField3D.Resolution` = `2` — Higher resolutions can represent small details more accurately in large scenes, at the cost of lower performance.
- `size: Vector3` = `Vector3(2, 2, 2)` — The collision heightmap's size in 3D units.
- `update_mode: GPUParticlesCollisionHeightField3D.UpdateMode` = `0` — The update policy to use for the generated heightmap.

## Methods

- `get_heightfield_mask_value(layer_number: int) -> bool` *const* — Returns `true` if the specified layer of the `heightfield_mask` is enabled, given a `layer_number` between `1` and `20`, inclusive.
- `set_heightfield_mask_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `heightfield_mask`, given a `layer_number` between `1` and `20`, inclusive.

## Enum Resolution

- `RESOLUTION_256 = 0` — Generate a 256×256 heightmap.
- `RESOLUTION_512 = 1` — Generate a 512×512 heightmap.
- `RESOLUTION_1024 = 2` — Generate a 1024×1024 heightmap.
- `RESOLUTION_2048 = 3` — Generate a 2048×2048 heightmap.
- `RESOLUTION_4096 = 4` — Generate a 4096×4096 heightmap.
- `RESOLUTION_8192 = 5` — Generate a 8192×8192 heightmap.
- `RESOLUTION_MAX = 6` — Represents the size of the `Resolution` enum.

## Enum UpdateMode

- `UPDATE_MODE_WHEN_MOVED = 0` — Only update the heightmap when the GPUParticlesCollisionHeightField3D node is moved, or when the camera moves if `follow_camera_enabled` is `true`.
- `UPDATE_MODE_ALWAYS = 1` — Update the heightmap every frame.
