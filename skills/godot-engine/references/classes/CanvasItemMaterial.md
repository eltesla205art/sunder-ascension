# CanvasItemMaterial

**Inherits:** Material

A material for CanvasItems.

CanvasItemMaterials provide a means of modifying the textures associated with a CanvasItem. They specialize in describing blend and lighting behaviors for textures. Use a ShaderMaterial to more fully customize a material's interactions with a CanvasItem.

## Properties

- `blend_mode: CanvasItemMaterial.BlendMode` = `0` — The manner in which a material's rendering is applied to underlying textures.
- `light_mode: CanvasItemMaterial.LightMode` = `0` — The manner in which material reacts to lighting.
- `particles_anim_h_frames: int` — The number of columns in the spritesheet assigned as Texture2D for a GPUParticles2D or CPUParticles2D.
- `particles_anim_loop: bool` — If `true`, the particles animation will loop.
- `particles_anim_v_frames: int` — The number of rows in the spritesheet assigned as Texture2D for a GPUParticles2D or CPUParticles2D.
- `particles_animation: bool` = `false` — If `true`, enable spritesheet-based animation features when assigned to GPUParticles2D and CPUParticles2D nodes.

## Enum BlendMode

- `BLEND_MODE_MIX = 0` — Mix blending mode.
- `BLEND_MODE_ADD = 1` — Additive blending mode.
- `BLEND_MODE_SUB = 2` — Subtractive blending mode.
- `BLEND_MODE_MUL = 3` — Multiplicative blending mode.
- `BLEND_MODE_PREMULT_ALPHA = 4` — Mix blending mode.

## Enum LightMode

- `LIGHT_MODE_NORMAL = 0` — Render the material using both light and non-light sensitive material properties.
- `LIGHT_MODE_UNSHADED = 1` — Render the material as if there were no light.
- `LIGHT_MODE_LIGHT_ONLY = 2` — Render the material as if there were only light.
