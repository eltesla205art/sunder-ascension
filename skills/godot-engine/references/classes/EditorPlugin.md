# EditorPlugin

**Inherits:** Node

Used by the editor to extend its functionality.

Plugins are used by the editor to extend functionality. The most common types of plugins are those which edit a given node or resource type, import plugins and export plugins. See also EditorScript to add functions to the editor. Note: Some names in this class contain "left" or "right" (e.g.

## Methods

- `_apply_changes() -> void` *virtual* — This method is called when the editor is about to save the project, switch to another tab, etc.
- `_build() -> bool` *virtual* — This method is called when the editor is about to run the project.
- `_clear() -> void` *virtual* — Clear all the state and reset the object being edited to zero.
- `_disable_plugin() -> void` *virtual* — Called by the engine when the user disables the EditorPlugin in the Plugin tab of the project settings window.
- `_edit(object: Object) -> void` *virtual* — This function is used for plugins that edit specific object types (nodes or resources).
- `_enable_plugin() -> void` *virtual* — Called by the engine when the user enables the EditorPlugin in the Plugin tab of the project settings window.
- `_forward_3d_draw_over_viewport(viewport_control: Control) -> void` *virtual* — Called by the engine when the 3D editor's viewport is updated.
- `_forward_3d_force_draw_over_viewport(viewport_control: Control) -> void` *virtual* — This method is the same as `_forward_3d_draw_over_viewport`, except it draws on top of everything.
- `_forward_3d_gui_input(viewport_camera: Camera3D, event: InputEvent) -> int` *virtual* — Called when there is a root node in the current edited scene, `_handles` is implemented, and an InputEvent happens in the 3D viewport.
- `_forward_canvas_draw_over_viewport(viewport_control: Control) -> void` *virtual* — Called by the engine when the 2D editor's viewport is updated.
- `_forward_canvas_force_draw_over_viewport(viewport_control: Control) -> void` *virtual* — This method is the same as `_forward_canvas_draw_over_viewport`, except it draws on top of everything.
- `_forward_canvas_gui_input(event: InputEvent) -> bool` *virtual* — Called when there is a root node in the current edited scene, `_handles` is implemented, and an InputEvent happens in the 2D viewport.
- `_get_breakpoints() -> PackedStringArray` *virtual const* — This is for editors that edit script-based objects.
- `_get_plugin_icon() -> Texture2D` *virtual const* *(deprecated)* — Override this method in your plugin to return a Texture2D in order to give it an icon.
- `_get_plugin_name() -> String` *virtual const* — Override this method in your plugin to provide the name of the plugin when displayed in the Godot editor.
- `_get_state() -> Dictionary` *virtual const* — Override this method to provide a state data you want to be saved, like view position, grid settings, folding, etc.
- `_get_unsaved_status(for_scene: String) -> String` *virtual const* — Override this method to provide a custom message that lists unsaved changes.
- `_get_window_layout(configuration: ConfigFile) -> void` *virtual* — Override this method to provide the GUI layout of the plugin or any other data you want to be stored.
- `_handles(object: Object) -> bool` *virtual const* — Implement this function if your plugin edits a specific type of object (Resource or Node).
- `_has_main_screen() -> bool` *virtual const* *(deprecated)* — Return `true` if this is a main screen editor plugin (it goes in the workspace selector together with 2D, 3D, Script, Game, and Asset Store).
- `_make_visible(visible: bool) -> void` *virtual* — This function will be called when the editor is requested to become visible.
- `_run_scene(scene: String, args: PackedStringArray) -> PackedStringArray` *virtual const* — This function is called when an individual scene is about to be played in the editor.
- `_save_external_data() -> void` *virtual* — This method is called after the editor saves the project or when it's closed.
- `_set_state(state: Dictionary) -> void` *virtual* — Restore the state saved by `_get_state`.
- `_set_window_layout(configuration: ConfigFile) -> void` *virtual* — Restore the plugin GUI layout and data saved by `_get_window_layout`.
- `add_autoload_singleton(name: String, path: String) -> void` — Adds a script at `path` to the Autoload list as `name`.
- `add_context_menu_plugin(slot: EditorContextMenuPlugin.ContextMenuSlot, plugin: EditorContextMenuPlugin) -> void` — Adds a plugin to the context menu.
- `add_control_to_bottom_panel(control: Control, title: String, shortcut: Shortcut = null) -> Button` *(deprecated)* — Adds a control to the bottom panel (together with Output, Debug, Animation, etc.).
- `add_control_to_container(container: EditorPlugin.CustomControlContainer, control: Control) -> void` — Adds a custom control to a container in the editor UI.
- `add_control_to_dock(slot: EditorPlugin.DockSlot, control: Control, shortcut: Shortcut = null) -> void` *(deprecated)* — Adds the control to a specific dock slot.
- `add_custom_type(type: String, base: String, script: Script, icon: Texture2D) -> void` — Adds a custom type, which will appear in the list of nodes or resources.
- `add_debugger_plugin(script: EditorDebuggerPlugin) -> void` — Adds a Script as debugger plugin to the Debugger.
- `add_dock(dock: EditorDock) -> void` — Adds a new dock.
- `add_export_platform(platform: EditorExportPlatform) -> void` — Registers a new EditorExportPlatform.
- `add_export_plugin(plugin: EditorExportPlugin) -> void` — Registers a new EditorExportPlugin.
- `add_import_plugin(importer: EditorImportPlugin, first_priority: bool = false) -> void` — Registers a new EditorImportPlugin.
- `add_inspector_plugin(plugin: EditorInspectorPlugin) -> void` — Registers a new EditorInspectorPlugin.
- `add_node_3d_gizmo_plugin(plugin: EditorNode3DGizmoPlugin) -> void` — Registers a new EditorNode3DGizmoPlugin.
- `add_resource_conversion_plugin(plugin: EditorResourceConversionPlugin) -> void` — Registers a new EditorResourceConversionPlugin.
- `add_scene_format_importer_plugin(scene_format_importer: EditorSceneFormatImporter, first_priority: bool = false) -> void` — Registers a new EditorSceneFormatImporter.
- `add_scene_post_import_plugin(scene_import_plugin: EditorScenePostImportPlugin, first_priority: bool = false) -> void` — Add an EditorScenePostImportPlugin.
- `add_tool_menu_item(name: String, callable: Callable) -> void` — Adds a custom menu item to Project > Tools named `name`.
- `add_tool_submenu_item(name: String, submenu: PopupMenu) -> void` — Adds a custom PopupMenu submenu under Project > Tools > `name`.
- `add_translation_parser_plugin(parser: EditorTranslationParserPlugin) -> void` — Registers a custom translation parser plugin for extracting translatable strings from custom files.
- `add_undo_redo_inspector_hook_callback(callable: Callable) -> void` — Hooks a callback into the undo/redo action creation when a property is modified in the inspector.
- `get_editor_interface() -> EditorInterface` *(deprecated)* — Returns the EditorInterface singleton instance.
- `get_export_as_menu() -> PopupMenu` — Returns the PopupMenu under Scene > Export As....
- `get_plugin_version() -> String` *const* — Provide the version of the plugin declared in the `plugin.cfg` config file.
- `get_script_create_dialog() -> ScriptCreateDialog` — Gets the Editor's dialog used for making scripts.
- `get_undo_redo() -> EditorUndoRedoManager` — Gets the undo/redo object.
- `hide_bottom_panel() -> void` — Minimizes the bottom panel.
- `make_bottom_panel_item_visible(item: Control) -> void` — Makes a specific item in the bottom panel visible.
- `queue_save_layout() -> void` — Queue save the project's editor layout.
- `remove_autoload_singleton(name: String) -> void` — Removes an Autoload `name` from the list.
- `remove_context_menu_plugin(plugin: EditorContextMenuPlugin) -> void` — Removes the specified context menu plugin.
- `remove_control_from_bottom_panel(control: Control) -> void` *(deprecated)* — Removes the control from the bottom panel.
- `remove_control_from_container(container: EditorPlugin.CustomControlContainer, control: Control) -> void` — Removes the control from the specified container.
- `remove_control_from_docks(control: Control) -> void` *(deprecated)* — Removes the control from the dock.
- `remove_custom_type(type: String) -> void` — Removes a custom type added by `add_custom_type`.
- `remove_debugger_plugin(script: EditorDebuggerPlugin) -> void` — Removes the debugger plugin with given script from the Debugger.
- `remove_dock(dock: EditorDock) -> void` — Removes `dock` from the available docks.
- `remove_export_platform(platform: EditorExportPlatform) -> void` — Removes an export platform registered by `add_export_platform`.
- `remove_export_plugin(plugin: EditorExportPlugin) -> void` — Removes an export plugin registered by `add_export_plugin`.
- `remove_import_plugin(importer: EditorImportPlugin) -> void` — Removes an import plugin registered by `add_import_plugin`.
- `remove_inspector_plugin(plugin: EditorInspectorPlugin) -> void` — Removes an inspector plugin registered by `add_inspector_plugin`.
- `remove_node_3d_gizmo_plugin(plugin: EditorNode3DGizmoPlugin) -> void` — Removes a gizmo plugin registered by `add_node_3d_gizmo_plugin`.
- `remove_resource_conversion_plugin(plugin: EditorResourceConversionPlugin) -> void` — Removes a resource conversion plugin registered by `add_resource_conversion_plugin`.
- `remove_scene_format_importer_plugin(scene_format_importer: EditorSceneFormatImporter) -> void` — Removes a scene format importer registered by `add_scene_format_importer_plugin`.
- `remove_scene_post_import_plugin(scene_import_plugin: EditorScenePostImportPlugin) -> void` — Remove the EditorScenePostImportPlugin, added with `add_scene_post_import_plugin`.
- `remove_tool_menu_item(name: String) -> void` — Removes a menu `name` from Project > Tools.
- `remove_translation_parser_plugin(parser: EditorTranslationParserPlugin) -> void` — Removes a custom translation parser plugin registered by `add_translation_parser_plugin`.
- `remove_undo_redo_inspector_hook_callback(callable: Callable) -> void` — Removes a callback previously added by `add_undo_redo_inspector_hook_callback`.
- `set_dock_tab_icon(control: Control, icon: Texture2D) -> void` *(deprecated)* — Sets the tab icon for the given control in a dock slot.
- `set_force_draw_over_forwarding_enabled() -> void` — Enables calling of `_forward_canvas_force_draw_over_viewport` for the 2D editor and `_forward_3d_force_draw_over_viewport` for the 3D editor when their viewports are updated.
- `set_input_event_forwarding_always_enabled() -> void` — Use this method if you always want to receive inputs from 3D view screen inside `_forward_3d_gui_input`.
- `update_overlays() -> int` *const* — Updates the overlays of the 2D and 3D editor viewport.

## Signals

- `main_screen_changed(screen_name: String)` — Emitted when user changes the workspace (2D, 3D, Script, Game, Asset Store).
- `project_settings_changed()` — Emitted when any project setting has changed.
- `resource_saved(resource: Resource)` — Emitted when the given `resource` was saved on disc.
- `scene_changed(scene_root: Node)` — Emitted when the scene is changed in the editor.
- `scene_closed(filepath: String)` — Emitted when user closes a scene.
- `scene_saved(filepath: String)` — Emitted when a scene was saved on disc.

## Enum CustomControlContainer

- `CONTAINER_TOOLBAR = 0` — Main editor toolbar, next to play buttons.
- `CONTAINER_SPATIAL_EDITOR_MENU = 1` — The toolbar that appears when 3D editor is active.
- `CONTAINER_SPATIAL_EDITOR_SIDE_LEFT = 2` — Left sidebar of the 3D editor.
- `CONTAINER_SPATIAL_EDITOR_SIDE_RIGHT = 3` — Right sidebar of the 3D editor.
- `CONTAINER_SPATIAL_EDITOR_BOTTOM = 4` — Bottom panel of the 3D editor.
- `CONTAINER_CANVAS_EDITOR_MENU = 5` — The toolbar that appears when 2D editor is active.
- `CONTAINER_CANVAS_EDITOR_SIDE_LEFT = 6` — Left sidebar of the 2D editor.
- `CONTAINER_CANVAS_EDITOR_SIDE_RIGHT = 7` — Right sidebar of the 2D editor.
- `CONTAINER_CANVAS_EDITOR_BOTTOM = 8` — Bottom panel of the 2D editor.
- `CONTAINER_INSPECTOR_BOTTOM = 9` — Bottom section of the inspector.
- `CONTAINER_PROJECT_SETTING_TAB_LEFT = 10` — Tab of Project Settings dialog, to the left of other tabs.
- `CONTAINER_PROJECT_SETTING_TAB_RIGHT = 11` — Tab of Project Settings dialog, to the right of other tabs.

## Enum DockSlot

- `DOCK_SLOT_NONE = -1` — The dock is closed.
- `DOCK_SLOT_LEFT_UL = 0` — Dock slot, left side, upper-left (empty in default layout).
- `DOCK_SLOT_LEFT_BL = 1` — Dock slot, left side, bottom-left (empty in default layout).
- `DOCK_SLOT_LEFT_UR = 2` — Dock slot, left side, upper-right (in default layout includes Scene and Import docks).
- `DOCK_SLOT_LEFT_BR = 3` — Dock slot, left side, bottom-right (in default layout includes FileSystem dock).
- `DOCK_SLOT_RIGHT_UL = 4` — Dock slot, right side, upper-left (in default layout includes Inspector, Node, and History docks).
- `DOCK_SLOT_RIGHT_BL = 5` — Dock slot, right side, bottom-left (empty in default layout).
- `DOCK_SLOT_RIGHT_UR = 6` — Dock slot, right side, upper-right (empty in default layout).
- `DOCK_SLOT_RIGHT_BR = 7` — Dock slot, right side, bottom-right (empty in default layout).
- `DOCK_SLOT_BOTTOM = 8` — Bottom panel.
- `DOCK_SLOT_MAX = 9` — Represents the size of the `DockSlot` enum.

## Enum AfterGUIInput

- `AFTER_GUI_INPUT_PASS = 0` — Forwards the InputEvent to other EditorPlugins.
- `AFTER_GUI_INPUT_STOP = 1` — Prevents the InputEvent from reaching other Editor classes.
- `AFTER_GUI_INPUT_CUSTOM = 2` — Pass the InputEvent to other editor plugins except the main Node3D one.
