# EditorUndoRedoManager

**Inherits:** Object

Manages undo history of scenes opened in the editor.

EditorUndoRedoManager is a manager for UndoRedo objects associated with edited scenes. Each scene has its own undo history and EditorUndoRedoManager ensures that each action performed in the editor gets associated with a proper scene. For actions not related to scenes (ProjectSettings edits, external resources, etc.), a separate global history is used. The usage is mostly the same as UndoRedo.

## Methods

- `add_do_method(object: Object, method: StringName) -> void` *vararg* — Register a method that will be called when the action is committed (i.e. the "do" action).
- `add_do_property(object: Object, property: StringName, value: Variant) -> void` — Register a property value change for "do".
- `add_do_reference(object: Object) -> void` — Register a reference for "do" that will be erased if the "do" history is lost.
- `add_undo_method(object: Object, method: StringName) -> void` *vararg* — Register a method that will be called when the action is undone (i.e. the "undo" action).
- `add_undo_property(object: Object, property: StringName, value: Variant) -> void` — Register a property value change for "undo".
- `add_undo_reference(object: Object) -> void` — Register a reference for "undo" that will be erased if the "undo" history is lost.
- `clear_history(id: int = -99, increase_version: bool = true) -> void` — Clears the given undo history.
- `commit_action(execute: bool = true) -> void` — Commits the action.
- `create_action(name: String, merge_mode: UndoRedo.MergeMode = 0, custom_context: Object = null, backward_undo_ops: bool = false, mark_unsaved: bool = true) -> void` — Create a new action.
- `force_fixed_history() -> void` — Forces the next operation (e.g.
- `get_history_undo_redo(id: int) -> UndoRedo` *const* — Returns the UndoRedo object associated with the given history `id`.
- `get_object_history_id(object: Object) -> int` *const* — Returns the history ID deduced from the given `object`.
- `is_committing_action() -> bool` *const* — Returns `true` if the EditorUndoRedoManager is currently committing the action, i.e. running its "do" method or property change (see `commit_action`).

## Signals

- `history_changed()` — Emitted when the list of actions in any history has changed, either when an action is committed or a history is cleared.
- `version_changed()` — Emitted when the version of any history has changed as a result of undo or redo call.

## Enum SpecialHistory

- `GLOBAL_HISTORY = 0` — Global history not associated with any scene, but with external resources etc.
- `REMOTE_HISTORY = -9` — History associated with remote inspector.
- `INVALID_HISTORY = -99` — Invalid "null" history.
