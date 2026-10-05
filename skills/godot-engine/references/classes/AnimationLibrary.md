# AnimationLibrary

**Inherits:** Resource

Container for Animation resources.

An animation library stores a set of animations accessible through StringName keys, for use with AnimationPlayer nodes.

## Methods

- `add_animation(name: StringName, animation: Animation) -> int[Error]` — Adds the `animation` to the library, accessible by the key `name`.
- `get_animation(name: StringName) -> Animation` *const* — Returns the Animation with the key `name`.
- `get_animation_list() -> StringName[]` *const* — Returns the keys for the Animations stored in the library.
- `get_animation_list_size() -> int` *const* — Returns the key count for the Animations stored in the library.
- `has_animation(name: StringName) -> bool` *const* — Returns `true` if the library stores an Animation with `name` as the key.
- `remove_animation(name: StringName) -> void` — Removes the Animation with the key `name`.
- `rename_animation(name: StringName, newname: StringName) -> void` — Changes the key of the Animation associated with the key `name` to `newname`.

## Signals

- `animation_added(anim_name: StringName)` — Emitted when an Animation is added, under the key `anim_name`.
- `animation_changed(anim_name: StringName)` — Emitted when there's a change in one of the animations, e.g. tracks are added, moved or have changed paths.
- `animation_removed(anim_name: StringName)` — Emitted when an Animation stored with the key `anim_name` is removed.
- `animation_renamed(old_name: StringName, new_name: StringName)` — Emitted when the key for an Animation is changed, from `old_name` to `new_name`.
