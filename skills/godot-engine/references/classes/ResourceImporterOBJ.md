# ResourceImporterOBJ

**Inherits:** ResourceImporter

Imports an OBJ 3D model as an independent Mesh or scene.

Unlike ResourceImporterScene, ResourceImporterOBJ will import a single Mesh resource by default instead of importing a PackedScene. This makes it easier to use the Mesh resource in nodes that expect direct Mesh resources, such as GridMap, GPUParticles3D or CPUParticles3D. Note that it is still possible to save mesh resources from 3D scenes using the Advanced Import Settings dialog, regardless of the source format. See also ResourceImporterScene, which is used for more advanced 3D formats such as glTF.

## Properties

- `force_disable_mesh_compression: bool` = `false` — If `true`, mesh compression will not be used.
- `generate_lightmap_uv2: bool` = `false` — If `true`, generates UV2 on import for LightmapGI baking.
- `generate_lightmap_uv2_texel_size: float` = `0.2` — Controls the size of each texel on the baked lightmap.
- `generate_lods: bool` = `true` — If `true`, generates lower detail variants of the mesh which will be displayed in the distance to improve rendering performance.
- `generate_shadow_mesh: bool` = `true` — If `true`, enables the generation of shadow meshes on import.
- `generate_tangents: bool` = `true` — If `true`, generate vertex tangents using Mikktspace if the source mesh doesn't have tangent data.
- `offset_mesh: Vector3` = `Vector3(0, 0, 0)` — Offsets the mesh's data by the specified value.
- `scale_mesh: Vector3` = `Vector3(1, 1, 1)` — Scales the mesh's data by the specified value.
