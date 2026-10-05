# Sky

**Inherits:** Resource

Defines a 3D environment's background by using a Material.

The Sky class uses a Material to render a 3D environment's background and the light it emits by updating the reflection/radiance cubemaps.

## Properties

- `process_mode: Sky.ProcessMode` = `0` — The method for generating the radiance map from the sky.
- `radiance_size: Sky.RadianceSize` = `3` — The Sky's radiance map size.
- `sky_material: Material` — Material used to draw the background.

## Enum RadianceSize

- `RADIANCE_SIZE_32 = 0` — Radiance texture size is 32×32 pixels.
- `RADIANCE_SIZE_64 = 1` — Radiance texture size is 64×64 pixels.
- `RADIANCE_SIZE_128 = 2` — Radiance texture size is 128×128 pixels.
- `RADIANCE_SIZE_256 = 3` — Radiance texture size is 256×256 pixels.
- `RADIANCE_SIZE_512 = 4` — Radiance texture size is 512×512 pixels.
- `RADIANCE_SIZE_1024 = 5` — Radiance texture size is 1024×1024 pixels.
- `RADIANCE_SIZE_2048 = 6` — Radiance texture size is 2048×2048 pixels.
- `RADIANCE_SIZE_MAX = 7` — Represents the size of the `RadianceSize` enum.

## Enum ProcessMode

- `PROCESS_MODE_AUTOMATIC = 0` — Automatically selects the appropriate process mode based on your sky shader.
- `PROCESS_MODE_QUALITY = 1` — Uses high quality importance sampling to process the radiance map.
- `PROCESS_MODE_INCREMENTAL = 2` — Uses the same high quality importance sampling to process the radiance map as `PROCESS_MODE_QUALITY`, but updates over several frames.
- `PROCESS_MODE_REALTIME = 3` — Uses the fast filtering algorithm to process the radiance map.
