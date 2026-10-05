# EditorFeatureProfile

**Inherits:** RefCounted

An editor feature profile which can be used to disable specific features.

An editor feature profile can be used to disable specific features of the Godot editor. When disabled, the features won't appear in the editor, which makes the editor less cluttered. This is useful in education settings to reduce confusion or when working in a team. For example, artists and level designers could use a feature profile that disables the script editor to avoid accidentally making changes to files they aren't supposed to edit.

## Methods

- `get_feature_name(feature: EditorFeatureProfile.Feature) -> String` — Returns the specified `feature`'s human-readable name.
- `is_class_disabled(class_name: StringName) -> bool` *const* — Returns `true` if the class specified by `class_name` is disabled.
- `is_class_editor_disabled(class_name: StringName) -> bool` *const* — Returns `true` if editing for the class specified by `class_name` is disabled.
- `is_class_property_disabled(class_name: StringName, property: StringName) -> bool` *const* — Returns `true` if `property` is disabled in the class specified by `class_name`.
- `is_feature_disabled(feature: EditorFeatureProfile.Feature) -> bool` *const* — Returns `true` if the `feature` is disabled.
- `load_from_file(path: String) -> int[Error]` — Loads an editor feature profile from a file.
- `save_to_file(path: String) -> int[Error]` — Saves the editor feature profile to a file in JSON format.
- `set_disable_class(class_name: StringName, disable: bool) -> void` — If `disable` is `true`, disables the class specified by `class_name`.
- `set_disable_class_editor(class_name: StringName, disable: bool) -> void` — If `disable` is `true`, disables editing for the class specified by `class_name`.
- `set_disable_class_property(class_name: StringName, property: StringName, disable: bool) -> void` — If `disable` is `true`, disables editing for `property` in the class specified by `class_name`.
- `set_disable_feature(feature: EditorFeatureProfile.Feature, disable: bool) -> void` — If `disable` is `true`, disables the editor feature specified in `feature`.

## Enum Feature

- `FEATURE_3D = 0` — The 3D editor.
- `FEATURE_SCRIPT = 1` — The Script tab, which contains the script editor and class reference browser.
- `FEATURE_ASSET_LIB = 2` — The Asset Store tab.
- `FEATURE_SCENE_TREE = 3` — Scene tree editing.
- `FEATURE_NODE_DOCK = 4` — The Node dock.
- `FEATURE_FILESYSTEM_DOCK = 5` — The FileSystem dock.
- `FEATURE_IMPORT_DOCK = 6` — The Import dock.
- `FEATURE_HISTORY_DOCK = 7` — The History dock.
- `FEATURE_GAME = 8` — The Game tab, which allows embedding the game window and selecting nodes by clicking inside of it.
- `FEATURE_SIGNALS_DOCK = 9` — The Signals dock.
- `FEATURE_GROUPS_DOCK = 10` — The Groups dock.
- `FEATURE_MAX = 11` — Represents the size of the `Feature` enum.
