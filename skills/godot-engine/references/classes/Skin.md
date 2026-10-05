# Skin

**Inherits:** Resource

A list of inverse bind poses and corresponding bones.

Skin contains a list of bind pose matrices and a list of either bone names if bones are named, or bone indices if bones are not named. The bind pose matrix, also called offset matrix or inverse bind matrix, is a Transform3D offset that is multiplied with a bone's transform to get from vertex space to bone space.

## Methods

- `add_bind(bone: int, pose: Transform3D) -> void` — Adds a bind pose matrix of `pose` and associated bone index `bone` to the bind pose list and increases the bind count by 1.
- `add_named_bind(name: String, pose: Transform3D) -> void` — Like `add_bind` but adds a bone `name` instead of a bone index.
- `clear_binds() -> void` — Clears the bind pose list.
- `get_bind_bone(bind_index: int) -> int` *const* — Returns the bone index associated with bind pose `bind_index`.
- `get_bind_count() -> int` *const* — Returns the length of the bind pose list.
- `get_bind_name(bind_index: int) -> StringName` *const* — Returns the bone name associated with bind pose `bind_index`.
- `get_bind_pose(bind_index: int) -> Transform3D` *const* — Returns the bind pose matrix at `bind_index`.
- `set_bind_bone(bind_index: int, bone: int) -> void` — Sets the bone index of bind pose `bind_index` to the given index `bone`.
- `set_bind_count(bind_count: int) -> void` — Resizes the bind pose list to a length of `bind_count`.
- `set_bind_name(bind_index: int, name: StringName) -> void` — Sets the name of the bone in bind pose `bind_index` to `name`.
- `set_bind_pose(bind_index: int, pose: Transform3D) -> void` — Sets the bind pose `bind_index` with the given offset matrix `pose`.
