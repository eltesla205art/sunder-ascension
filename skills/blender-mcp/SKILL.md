---
name: blender-mcp
description: "Drive a live Blender from Claude through MCP for Blender (ahujasid/mcp-for-blender): model, lay out scenes, write materials, rig, animate, retopologize, pull Poly Haven / Sketchfab / Poly Pizza assets, generate 3D (Tripo, Hyper3D Rodin, Hunyuan3D), visually verify with multi-angle captures, and export GLB for the SUNDER web (Three.js) or Godot builds. Use whenever the user mentions Blender, bpy, blender-mcp, mcp-for-blender, a .blend file, or wants a 3D model, prop, character, level blockout, or rig built or edited in Blender. Also use to install or troubleshoot the Blender MCP server and addon."
---

# Blender MCP

Two pieces talk to each other:

1. **Blender addon** (`addon.py`, enabled in Blender as *Interface: MCP for Blender*) runs a socket server inside Blender on `localhost:9876`.
2. **MCP server** (`uvx mcp-for-blender`, Python ≥3.10) speaks MCP to Claude over stdio and forwards commands to that socket.

Blender runs on the user's machine. A cloud session has no Blender, so the tools only work where Blender is open and the addon server is running.

Resolve `<this-skill-dir>` from the path of this loaded SKILL.md.

## References

| File | Read it when |
| --- | --- |
| `references/setup.md` | installing, wiring Claude Code / Desktop, ports, Docker, safe mode, `spawn uvx ENOENT`, connection refused |
| `references/guides/bpy.md` | before writing any non-trivial `execute_blender_code` script |
| `references/guides/scene.md` | building a scene: scale, grounding, generated vs. library assets, light, camera |
| `references/guides/materials.md` | shader nodes, Poly Haven textures, tiling, procedural looks |
| `references/guides/rigging.md` | armatures, Rigify, weights, checking deformation |
| `references/guides/animation.md` | keyframes, easing, cycles, NLA, camera moves |
| `references/guides/retopology.md` | cleaning generated or scanned meshes, decimation, UVs, baking |
| `references/guides/level-design.md` | game levels, modular kits, collision, export to engines |
| `references/game-export.md` | getting a model into `web/` (Three.js GLB) or `godot/assets` |

The guides are the upstream server's own `get_guide` topics, copied here so they are readable without a live connection. When connected, `get_guide(topic)` returns the version shipped with the installed server; prefer it if they differ.

## Quick install

```bash
# one-shot: installs uv if needed, configures MCP clients, installs + enables the addon
curl -LsSf https://www.mcp-for-blender.com/install.sh | sh        # macOS / Linux
# or, with uv already present
uvx mcp-for-blender setup

# Claude Code only, manual
claude mcp add blender uvx mcp-for-blender
uvx mcp-for-blender install-addon     # then enable it in Blender > Preferences > Add-ons
```

Restart the MCP client fully afterwards, open Blender, press `N` in the 3D viewport → **MCP for Blender** tab → **Start MCP Server** if it is not already running. Details and fixes: `references/setup.md`.

Check the link without MCP at all:

```bash
python3 <this-skill-dir>/scripts/blender_socket.py ping
```

## Tools

| Tool | Use |
| --- | --- |
| `get_addon_status` | First call. Blender version, addon/server match, which asset sources and generators are on |
| `get_scene_info` | Compact object list (`query=`, `root=`, `limit=`) |
| `execute_blender_code` | Run Python in Blender; whatever it prints comes back. Main modelling tool |
| `look` | One image: `viewport`, `angles`, `camera`, `topology`, `rig`, `frames` |
| `get_guide` | Load a workflow guide (topics above) |
| `search_assets` / `import_asset` | `polyhaven` (HDRIs, PBR textures, CC0 models), `sketchfab` (specific real models, check licence), `polypizza` (low-poly, credit CC-BY) |
| `generate_3d` | One textured object from a prompt or image path/URL. Costs the user money or a monthly generation |
| `disable_telemetry` | User asks to turn data collection off |

Always pass `user_prompt` with the user's own words, verbatim, on every call of a task.

## Workflow

1. `get_addon_status`, then `get_scene_info`. If the addon is outdated, tell the user to run `uvx mcp-for-blender install-addon` and re-enable it.
2. Load the matching guide before rigging, retopo, animation, level design, scene or material work.
3. Work in small `execute_blender_code` steps and print what you need to know (names, dimensions, counts).
4. After each meaningful change, `look` with the mode that answers the question. Judge the image, not your intent: fix floating, clipping, mis-scaled or hidden objects before moving on.
5. After any import or generation, use the reported `world_bounding_box` to fix scale (metres) and set the object on the ground.
6. For SUNDER assets, finish with `references/game-export.md`.

## Script rules (they run in someone else's Blender)

- Find shader nodes by type, never by name (names are localized):
  `next(n for n in mat.node_tree.nodes if n.type == "BSDF_PRINCIPLED")`.
- Never hardcode enum identifiers; read them from `bl_rna`, e.g.
  `[i.identifier for i in bpy.types.RenderSettings.bl_rna.properties["file_format"].enum_items]`.
- `scene.render.engine` under-reports: read the current value, set a new one inside `try/except TypeError` (the message lists valid engines).
- Material colour goes on shader node inputs; `material.diffuse_color` only changes the viewport.
- Prefer `bpy.data` / `bmesh` over `bpy.ops`; operators need the right context and mode.
- Don't delete or overwrite user objects, save over their `.blend`, or touch files outside the project without asking.

## Assets

- Generate hero and custom objects one at a time; never a whole scene, the ground, or parts to assemble. Duplicate (linked) for repeats.
- Use libraries for HDRIs, textures and generic props. Credit CC-BY creators.
- `generate_3d` usually takes 1–3 min; if it returns a job handle, call `generate_3d(job=..., name=...)` again to keep waiting.
- `threejs-3d-generator` (Tripo direct) is the alternative when Blender is not running; bring its GLB into Blender with `bpy.ops.import_scene.gltf` for cleanup.

## Safety

The addon's socket has no auth: anyone reaching the port can run Python in Blender. Keep it on `localhost`; tunnel over SSH for remote use. Set `BLENDER_MCP_SAFE_MODE=1` to block file, process and network access from scripts.
