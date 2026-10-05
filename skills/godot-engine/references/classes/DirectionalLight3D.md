# DirectionalLight3D

**Inherits:** Light3D

Directional light from a distance, as from the Sun.

A directional light is a type of Light3D node that models an infinite number of parallel rays covering the entire scene. It is used for lights with strong intensity that are located far away from the scene to model sunlight or moonlight. Light is emitted in the -Z direction of the node's global basis. For an unrotated light, this means that the light is emitted forwards, illuminating the front side of a 3D model (see `Vector3.FORWARD` and `Vector3.MODEL_FRONT`).

## Properties

- `directional_shadow_blend_splits: bool` = `false` — If `true`, shadow detail is sacrificed in exchange for smoother transitions between splits.
- `directional_shadow_fade_start: float` = `0.8` — Proportion of `directional_shadow_max_distance` at which point the shadow starts to fade.
- `directional_shadow_max_distance: float` = `100.0` — The maximum distance for shadow splits.
- `directional_shadow_mode: DirectionalLight3D.ShadowMode` = `2` — The light's shadow rendering algorithm.
- `directional_shadow_pancake_size: float` = `20.0` — Sets the size of the directional shadow pancake.
- `directional_shadow_split_1: float` = `0.1` — The distance from camera to shadow split 1.
- `directional_shadow_split_2: float` = `0.2` — The distance from shadow split 1 to split 2.
- `directional_shadow_split_3: float` = `0.5` — The distance from shadow split 2 to split 3.
- `sky_mode: DirectionalLight3D.SkyMode` = `0` — Whether this DirectionalLight3D is visible in the sky, in the scene, or both in the sky and in the scene.

## Enum ShadowMode

- `SHADOW_ORTHOGONAL = 0` — Renders the entire scene's shadow map from an orthogonal point of view.
- `SHADOW_PARALLEL_2_SPLITS = 1` — Splits the view frustum in 2 areas, each with its own shadow map.
- `SHADOW_PARALLEL_4_SPLITS = 2` — Splits the view frustum in 4 areas, each with its own shadow map.

## Enum SkyMode

- `SKY_MODE_LIGHT_AND_SKY = 0` — Makes the light visible in both scene lighting and sky rendering.
- `SKY_MODE_LIGHT_ONLY = 1` — Makes the light visible in scene lighting only (including direct lighting and global illumination).
- `SKY_MODE_SKY_ONLY = 2` — Makes the light visible to sky shaders only.
