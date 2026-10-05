# EditorScript

**Inherits:** RefCounted

Base script that can be used to add extension functions to the editor.

Scripts extending this class and implementing its `_run` method can be executed from the Script Editor's File > Run menu option (or by pressing `Ctrl + Shift + X`) while the editor is running. This is useful for adding custom in-editor functionality to Godot. For more complex additions, consider using EditorPlugins instead. If a script extending this class also has a global class name, it will be included in the editor's command palette.

## Methods

- `_run() -> void` *virtual required* — This method is executed by the Editor when File > Run is used.
- `add_root_node(node: Node) -> void` *(deprecated)* — Makes `node` root of the currently opened scene.
- `get_editor_interface() -> EditorInterface` *const* *(deprecated)* — Returns the EditorInterface singleton instance.
- `get_scene() -> Node` *const* *(deprecated)* — Returns the edited (current) scene's root Node.
