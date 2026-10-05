# VisualShaderNodeInput

**Inherits:** VisualShaderNode

Represents the input shader parameter within the visual shader graph.

Gives access to input variables (built-ins) available for the shader. See the shading reference for the list of available built-ins for each shader type (check `Tutorials` section for link).

## Properties

- `input_name: String` = `"[None]"` — One of the several input constants in lower-case style like: "vertex" (`VERTEX`) or "point_size" (`POINT_SIZE`).

## Methods

- `get_input_real_name() -> String` *const* — Returns a translated name of the current constant in the Godot Shader Language.

## Signals

- `input_type_changed()` — Emitted when input is changed via `input_name`.
