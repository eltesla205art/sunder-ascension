# Exporting Blender assets for SUNDER

SUNDER ships two front ends: `web/` (single-file HTML5 / Three.js) and `godot/` (Godot project, assets under `godot/assets/`). glTF binary (`.glb`) works for both.

## Before export

- Units: metres, +Z up in Blender (the glTF exporter converts to +Y up).
- Apply transforms on meshes you will export: `bpy.ops.object.transform_apply(location=False, rotation=True, scale=True)` (select + make active first).
- Origin at the base centre for props and characters so they sit on the ground at y=0 in engine.
- Budgets for the web build: keep a prop under ~5k tris and a hero/character under ~20k; check with `look(mode="topology")` and decimate per `guides/retopology.md`.
- Materials: Principled BSDF only (base colour, metallic, roughness, normal, emission). Other nodes don't export; bake procedurals to images first.
- Textures: 1k–2k for the web build. Pack or keep them next to the `.blend`.
- Animations: one action per clip, named for the game (`idle`, `run`, `draw_bow`, `fire`). Push them to NLA tracks or the exporter only takes the active one.

## Export

```python
import bpy, os
out = "/abs/path/to/asset.glb"   # ask the user where; Blender runs on their machine
props = bpy.ops.export_scene.gltf.get_rna_type().properties.keys()
kwargs = dict(filepath=out, export_format="GLB", use_selection=True, export_apply=True)
if "export_draco_mesh_compression_enable" in props:
    kwargs["export_draco_mesh_compression_enable"] = False   # Three.js needs DRACOLoader if True
bpy.ops.export_scene.gltf(**{k: v for k, v in kwargs.items() if k in props})
print(out, os.path.getsize(out))
```

Exporter options change between Blender versions; filter keyword args against `props` as above instead of hardcoding.

## Into the game

- Three.js: `GLTFLoader().load('assets/name.glb', g => scene.add(g.scene))`; clips in `g.animations` drive an `AnimationMixer`. See the `threejs-3d-generator` skill's `references/threejs-integration.md`.
- Godot: drop the `.glb` into `godot/assets/`; Godot imports it as a scene. Collision: suffix mesh names `-col` / `-colonly` in Blender (see `guides/level-design.md`).

Verify the file opens before committing it, and keep the source `.blend` out of git unless the user wants it tracked.
