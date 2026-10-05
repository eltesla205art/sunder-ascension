# Decal

**Inherits:** VisualInstance3D

Node that projects a texture onto a MeshInstance3D.

Decals are used to project a texture onto a Mesh in the scene. Use Decals to add detail to a scene without affecting the underlying Mesh. They are often used to add weathering to building, add dirt or mud to the ground, or add variety to props. Decals can be moved at any time, making them suitable for things like blob shadows or laser sight dots.

## Properties

- `albedo_mix: float` = `1.0` — Blends the albedo Color of the decal with albedo Color of the underlying mesh.
- `cull_mask: int` = `1048575` — Specifies which `VisualInstance3D.layers` this decal will project on.
- `distance_fade_begin: float` = `40.0` — The distance from the camera at which the Decal begins to fade away (in 3D units).
- `distance_fade_enabled: bool` = `false` — If `true`, decals will smoothly fade away when far from the active Camera3D starting at `distance_fade_begin`.
- `distance_fade_length: float` = `10.0` — The distance over which the Decal fades (in 3D units).
- `emission_energy: float` = `1.0` — Energy multiplier for the emission texture.
- `lower_fade: float` = `0.3` — Sets the curve over which the decal will fade as the surface gets further from the center of the AABB.
- `modulate: Color` = `Color(1, 1, 1, 1)` — Changes the Color of the Decal by multiplying the albedo and emission colors with this value.
- `normal_fade: float` = `0.0` — Fades the Decal if the angle between the Decal's AABB and the target surface becomes too large.
- `size: Vector3` = `Vector3(2, 2, 2)` — Sets the size of the AABB used by the decal.
- `texture_albedo: Texture2D` — Texture2D with the base Color of the Decal.
- `texture_emission: Texture2D` — Texture2D with the emission Color of the Decal.
- `texture_normal: Texture2D` — Texture2D with the per-pixel normal map for the decal.
- `texture_orm: Texture2D` — Texture2D storing ambient occlusion, roughness, and metallic for the decal.
- `upper_fade: float` = `0.3` — Sets the curve over which the decal will fade as the surface gets further from the center of the AABB.

## Methods

- `get_texture(type: Decal.DecalTexture) -> Texture2D` *const* — Returns the Texture2D associated with the specified `DecalTexture`.
- `set_texture(type: Decal.DecalTexture, texture: Texture2D) -> void` — Sets the Texture2D associated with the specified `DecalTexture`.

## Enum DecalTexture

- `TEXTURE_ALBEDO = 0` — Texture2D corresponding to `texture_albedo`.
- `TEXTURE_NORMAL = 1` — Texture2D corresponding to `texture_normal`.
- `TEXTURE_ORM = 2` — Texture2D corresponding to `texture_orm`.
- `TEXTURE_EMISSION = 3` — Texture2D corresponding to `texture_emission`.
- `TEXTURE_MAX = 4` — Max size of `DecalTexture` enum.
