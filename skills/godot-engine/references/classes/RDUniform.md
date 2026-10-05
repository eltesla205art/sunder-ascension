# RDUniform

**Inherits:** RefCounted

Shader uniform (used by RenderingDevice).

This object is used by RenderingDevice.

## Properties

- `binding: int` = `0` — The uniform's binding.
- `uniform_type: RenderingDevice.UniformType` = `3` — The uniform's data type.

## Methods

- `add_id(id: RID) -> void` — Binds the given id to the uniform.
- `clear_ids() -> void` — Unbinds all ids currently bound to the uniform.
- `get_ids() -> RID[]` *const* — Returns an array of all ids currently bound to the uniform.
