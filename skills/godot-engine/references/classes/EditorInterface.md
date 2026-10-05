# EditorInterface

**Inherits:** Object

Godot editor's interface.

EditorInterface gives you control over Godot editor's window. It allows customizing the window, saving and (re-)loading scenes, rendering mesh previews, inspecting and editing resources and objects, and provides access to EditorSettings, EditorFileSystem, EditorResourcePreview, ScriptEditor, the editor viewport, and information about scenes. Note: This class shouldn't be instantiated directly. Instead, access the singleton directly by its name.

## Properties

- `distraction_free_mode: bool` — If `true`, enables distraction-free mode which hides side docks to increase the space available for the main view.
- `movie_maker_enabled: bool` — If `true`, the Movie Maker mode is enabled in the editor.

## Methods

- `add_root_node(node: Node) -> void` — Makes `node` root of the currently opened scene.
- `close_scene() -> int[Error]` — Closes the currently active scene, discarding any pending changes in the process.
- `edit_node(node: Node) -> void` — Edits the given Node.
- `edit_resource(resource: Resource) -> void` — Edits the given Resource.
- `edit_script(script: Script, line: int = -1, column: int = 0, grab_focus: bool = true) -> void` — Edits the given Script.
- `get_base_control() -> Control` *const* — Returns the main container of Godot editor's window.
- `get_command_palette() -> EditorCommandPalette` *const* — Returns the editor's EditorCommandPalette instance.
- `get_current_directory() -> String` *const* — Returns the current directory being viewed in the FileSystemDock.
- `get_current_feature_profile() -> String` *const* — Returns the name of the currently activated feature profile.
- `get_current_path() -> String` *const* — Returns the current path being viewed in the FileSystemDock.
- `get_dock_by_name(name: String) -> EditorDock` — Returns an EditorDock with the specified `name`.
- `get_edited_scene_root() -> Node` *const* — Returns the edited (current) scene's root Node.
- `get_editor_language() -> String` *const* — Returns the language currently used for the editor interface.
- `get_editor_main_screen() -> VBoxContainer` *const* *(deprecated)* — Returns the editor control responsible for legacy main screen plugins and tools.
- `get_editor_paths() -> EditorPaths` *const* — Returns the EditorPaths singleton.
- `get_editor_scale() -> float` *const* — Returns the actual scale of the editor UI (`1.0` being 100% scale).
- `get_editor_settings() -> EditorSettings` *const* — Returns the editor's EditorSettings instance.
- `get_editor_theme() -> Theme` *const* — Returns the editor's Theme.
- `get_editor_toaster() -> EditorToaster` *const* — Returns the editor's EditorToaster.
- `get_editor_undo_redo() -> EditorUndoRedoManager` *const* — Returns the editor's EditorUndoRedoManager.
- `get_editor_viewport_2d() -> SubViewport` *const* — Returns the 2D editor SubViewport.
- `get_editor_viewport_3d(idx: int = 0) -> SubViewport` *const* — Returns the specified 3D editor SubViewport, from `0` to `3`.
- `get_file_system_dock() -> FileSystemDock` *const* — Returns the editor's FileSystemDock instance.
- `get_inspector() -> EditorInspector` *const* — Returns the editor's EditorInspector instance.
- `get_node_3d_rotate_snap() -> float` *const* — Returns the amount of degrees the 3D editor's rotational snapping is set to.
- `get_node_3d_scale_snap() -> float` *const* — Returns the amount of units the 3D editor's scale snapping is set to.
- `get_node_3d_translate_snap() -> float` *const* — Returns the amount of units the 3D editor's translation snapping is set to.
- `get_open_scene_roots() -> Node[]` *const* — Returns an array with references to the root nodes of the currently opened scenes.
- `get_open_scenes() -> PackedStringArray` *const* — Returns an array with the file paths of the currently opened scenes.
- `get_playing_scene() -> String` *const* — Returns the name of the scene that is being played.
- `get_resource_filesystem() -> EditorFileSystem` *const* — Returns the editor's EditorFileSystem instance.
- `get_resource_previewer() -> EditorResourcePreview` *const* — Returns the editor's EditorResourcePreview instance.
- `get_scene_paint_2d() -> ScenePaint2DEditor` *const* — Returns the editor's ScenePaint2DEditor instance.
- `get_script_editor() -> ScriptEditor` *const* — Returns the editor's ScriptEditor instance.
- `get_selected_paths() -> PackedStringArray` *const* — Returns an array containing the paths of the currently selected files (and directories) in the FileSystemDock.
- `get_selection() -> EditorSelection` *const* — Returns the editor's EditorSelection instance.
- `get_unsaved_scenes() -> PackedStringArray` *const* — Returns an array of file paths of currently unsaved scenes.
- `inspect_object(object: Object, for_property: String = "", inspector_only: bool = false) -> void` — Shows the given property on the given `object` in the editor's Inspector dock.
- `is_exiting() -> bool` *const* — Returns `true` if the editor is currently exiting.
- `is_multi_window_enabled() -> bool` *const* — Returns `true` if multiple window support is enabled in the editor.
- `is_node_3d_snap_enabled() -> bool` *const* — Returns `true` if the 3D editor currently has snapping mode enabled, and `false` otherwise.
- `is_object_edited(object: Object) -> bool` *const* — Returns `true` if the object has been marked as edited through `set_object_edited`.
- `is_playing_scene() -> bool` *const* — Returns `true` if a scene is currently being played, `false` otherwise.
- `is_plugin_enabled(plugin: String) -> bool` *const* — Returns `true` if the specified `plugin` is enabled.
- `make_mesh_previews(meshes: Mesh[], preview_size: int) -> Texture2D[]` — Returns mesh previews rendered at the given size as an Array of Texture2Ds.
- `mark_scene_as_unsaved() -> void` — Marks the current scene tab as unsaved.
- `open_scene_from_path(scene_filepath: String, set_inherited: bool = false) -> void` — Opens the scene at the given path.
- `play_current_scene() -> void` — Plays the currently active scene.
- `play_custom_scene(scene_filepath: String) -> void` — Plays the scene specified by its filepath.
- `play_main_scene() -> void` — Plays the main scene.
- `popup_create_dialog(callback: Callable, base_type: StringName = "", current_type: String = "", dialog_title: String = "", type_blocklist: StringName[] = []) -> void` — Pops up an editor dialog for creating an object.
- `popup_dialog(dialog: Window, rect: Rect2i = Rect2i(0, 0, 0, 0)) -> void` — Pops up the `dialog` in the editor UI with `Window.popup_exclusive`.
- `popup_dialog_centered(dialog: Window, minsize: Vector2i = Vector2i(0, 0)) -> void` — Pops up the `dialog` in the editor UI with `Window.popup_exclusive_centered`.
- `popup_dialog_centered_clamped(dialog: Window, minsize: Vector2i = Vector2i(0, 0), fallback_ratio: float = 0.75) -> void` — Pops up the `dialog` in the editor UI with `Window.popup_exclusive_centered_clamped`.
- `popup_dialog_centered_ratio(dialog: Window, ratio: float = 0.8) -> void` — Pops up the `dialog` in the editor UI with `Window.popup_exclusive_centered_ratio`.
- `popup_method_selector(object: Object, callback: Callable, current_value: String = "") -> void` — Pops up an editor dialog for selecting a method from `object`.
- `popup_node_selector(callback: Callable, valid_types: StringName[] = [], current_value: Node = null) -> void` — Pops up an editor dialog for selecting a Node from the edited scene.
- `popup_property_selector(object: Object, callback: Callable, type_filter: PackedInt32Array = PackedInt32Array(), current_value: String = "") -> void` — Pops up an editor dialog for selecting properties from `object`.
- `popup_quick_open(callback: Callable, base_types: StringName[] = []) -> void` — Pops up an editor dialog for quick selecting a resource file.
- `reload_scene_from_path(scene_filepath: String) -> void` — Reloads the scene at the given path.
- `restart_editor(save: bool = true) -> void` — Restarts the editor.
- `save_all_scenes() -> void` — Saves all opened scenes in the editor.
- `save_scene() -> int[Error]` — Saves the currently active scene.
- `save_scene_as(path: String, with_preview: bool = true) -> void` — Saves the currently active scene as a file at `path`.
- `select_file(file: String) -> void` — Selects the file, with the path provided by `file`, in the FileSystem dock.
- `set_current_feature_profile(profile_name: String) -> void` — Selects and activates the specified feature profile with the given `profile_name`.
- `set_main_screen_editor(name: String) -> void` *(deprecated)* — Sets the editor's current main screen to the one specified in `name`.
- `set_object_edited(object: Object, edited: bool) -> void` — If `edited` is `true`, the object is marked as edited.
- `set_plugin_enabled(plugin: String, enabled: bool) -> void` — Sets the enabled status of a plugin.
- `stop_playing_scene() -> void` — Stops the scene that is currently playing.
