# ReflectionProbe

**Inherits:** VisualInstance3D

Captures its surroundings to create fast, accurate reflections from a given point.

Captures its surroundings as a cubemap, and stores versions of it with increasing levels of blur to simulate different material roughnesses. The ReflectionProbe is used to create high-quality reflections at a low performance cost (when `update_mode` is `UPDATE_ONCE`). ReflectionProbes can be blended together and with the rest of the scene smoothly. ReflectionProbes can also be combined with VoxelGI, SDFGI (`Environment.sdfgi_enabled`) and screen-space reflections (`Environment.ssr_enabled`) to get more accurate reflections in specific areas.

## Properties

- `ambient_color: Color` = `Color(0, 0, 0, 1)` — The custom ambient color to use within the ReflectionProbe's box defined by its `size`.
- `ambient_color_energy: float` = `1.0` — The custom ambient color energy to use within the ReflectionProbe's box defined by its `size`.
- `ambient_mode: ReflectionProbe.AmbientMode` = `1` — The ambient color to use within the ReflectionProbe's box defined by its `size`.
- `blend_distance: float` = `1.0` — Defines the distance in meters over which a probe blends into the scene.
- `box_projection: bool` = `false` — If `true`, enables box projection.
- `cull_mask: int` = `1048575` — Sets the cull mask which determines what objects are drawn by this probe.
- `enable_shadows: bool` = `false` — If `true`, computes shadows in the reflection probe.
- `intensity: float` = `1.0` — Defines the reflection intensity.
- `interior: bool` = `false` — If `true`, reflections will ignore sky contribution.
- `max_distance: float` = `0.0` — The maximum distance away from the ReflectionProbe an object can be before it is culled.
- `mesh_lod_threshold: float` = `1.0` — The automatic LOD bias to use for meshes rendered within the ReflectionProbe (this is analog to `Viewport.mesh_lod_threshold`).
- `origin_offset: Vector3` = `Vector3(0, 0, 0)` — Sets the origin offset to be used when this ReflectionProbe is in `box_projection` mode.
- `reflection_mask: int` = `1048575` — Sets the reflection mask which determines what objects have reflections applied from this probe.
- `size: Vector3` = `Vector3(20, 20, 20)` — The size of the reflection probe.
- `update_mode: ReflectionProbe.UpdateMode` = `0` — Sets how frequently the ReflectionProbe is updated.

## Enum UpdateMode

- `UPDATE_ONCE = 0` — Update the probe once on the next frame (recommended for most objects).
- `UPDATE_ALWAYS = 1` — Update the probe every frame.

## Enum AmbientMode

- `AMBIENT_DISABLED = 0` — Do not apply any ambient lighting inside the ReflectionProbe's box defined by its `size`.
- `AMBIENT_ENVIRONMENT = 1` — Apply automatically-sourced environment lighting inside the ReflectionProbe's box defined by its `size`.
- `AMBIENT_COLOR = 2` — Apply custom ambient lighting inside the ReflectionProbe's box defined by its `size`.
