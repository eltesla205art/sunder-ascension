# UndoRedo

**Inherits:** Object

Provides a high-level interface for implementing undo and redo operations.

UndoRedo works by registering methods and property changes inside "actions". You can create an action, then provide ways to do and undo this action using function calls and property changes, then commit the action. When an action is committed, all of the `do_*` methods will run. If the `undo` method is used, the `undo_*` methods will run.

## Properties

- `max_steps: int` = `0` — The maximum number of steps that can be stored in the undo/redo history.

## Methods

- `add_do_method(callable: Callable) -> void` — Register a Callable that will be called when the action is committed.
- `add_do_property(object: Object, property: StringName, value: Variant) -> void` — Register a `property` that would change its value to `value` when the action is committed.
- `add_do_reference(object: Object) -> void` — Register a reference to an object that will be erased if the "do" history is deleted.
- `add_undo_method(callable: Callable) -> void` — Register a Callable that will be called when the action is undone.
- `add_undo_property(object: Object, property: StringName, value: Variant) -> void` — Register a `property` that would change its value to `value` when the action is undone.
- `add_undo_reference(object: Object) -> void` — Register a reference to an object that will be erased if the "undo" history is deleted.
- `clear_history(increase_version: bool = true) -> void` — Clear the undo/redo history and associated references.
- `commit_action(execute: bool = true) -> void` — Commit the action.
- `create_action(name: String, merge_mode: UndoRedo.MergeMode = 0, backward_undo_ops: bool = false) -> void` — Create a new action.
- `end_force_keep_in_merge_ends() -> void` — Stops marking operations as to be processed even if the action gets merged with another in the `MERGE_ENDS` mode.
- `get_action_name(id: int) -> String` — Gets the action name from its index.
- `get_current_action() -> int` — Gets the index of the current action.
- `get_current_action_name() -> String` *const* — Gets the name of the current action, equivalent to `get_action_name(get_current_action())`.
- `get_history_count() -> int` — Returns how many elements are in the history.
- `get_version() -> int` *const* — Gets the version.
- `has_redo() -> bool` *const* — Returns `true` if a "redo" action is available.
- `has_undo() -> bool` *const* — Returns `true` if an "undo" action is available.
- `is_committing_action() -> bool` *const* — Returns `true` if the UndoRedo is currently committing the action, i.e. running its "do" method or property change (see `commit_action`).
- `redo() -> bool` — Redo the last action.
- `start_force_keep_in_merge_ends() -> void` — Marks the next "do" and "undo" operations to be processed even if the action gets merged with another in the `MERGE_ENDS` mode.
- `undo() -> bool` — Undo the last action.

## Signals

- `version_changed()` — Called when `undo` or `redo` was called.

## Enum MergeMode

- `MERGE_DISABLE = 0` — Makes "do"/"undo" operations stay in separate actions.
- `MERGE_ENDS = 1` — Merges this action with the previous one if they have the same name.
- `MERGE_ALL = 2` — Merges this action with the previous one if they have the same name.
