# EditorVCSInterface

**Inherits:** Object

Version Control System (VCS) interface, which reads and writes to the local VCS in use.

Defines the API that the editor uses to extract information from the underlying VCS. The implementation of this API is included in VCS plugins, which are GDExtension plugins that inherit EditorVCSInterface and are attached (on demand) to the singleton instance of EditorVCSInterface. Instead of performing the task themselves, all the virtual functions listed below are calling the internally overridden functions in the VCS plugins to provide a plug-n-play experience. A custom VCS plugin is supposed to inherit from EditorVCSInterface and override each of these virtual functions.

## Methods

- `_allow_amends() -> bool` *virtual* — Returns whether or not the plugin allows commit amends.
- `_checkout_branch(branch_name: String) -> bool` *virtual required* — Checks out a `branch_name` in the VCS.
- `_commit(msg: String, amend: bool) -> void` *virtual* — Commits the currently staged changes and applies the commit `msg` to the resulting commit.
- `_create_branch(branch_name: String) -> void` *virtual required* — Creates a new branch named `branch_name` in the VCS.
- `_create_remote(remote_name: String, remote_url: String) -> void` *virtual required* — Creates a new remote destination with name `remote_name` and points it to `remote_url`.
- `_discard_file(file_path: String) -> void` *virtual required* — Discards the changes made in a file present at `file_path`.
- `_fetch(remote: String) -> void` *virtual required* — Fetches new changes from the `remote`, but doesn't write changes to the current working directory.
- `_get_branch_list() -> String[]` *virtual required* — Gets an instance of an Array of Strings containing available branch names in the VCS.
- `_get_current_branch_name() -> String` *virtual required* — Gets the current branch name defined in the VCS.
- `_get_diff(identifier: String, area: int) -> Dictionary[]` *virtual required* — Returns an array of Dictionary items (see `create_diff_file`, `create_diff_hunk`, `create_diff_line`, `add_line_diffs_into_diff_hunk` and `add_diff_hunks_into_diff_file`), each containing information about a diff.
- `_get_line_diff(file_path: String, text: String) -> Dictionary[]` *virtual required* — Returns an Array of Dictionary items (see `create_diff_hunk`), each containing a line diff between a file at `file_path` and the `text` which is passed in.
- `_get_modified_files_data() -> Dictionary[]` *virtual required* — Returns an Array of Dictionary items (see `create_status_file`), each containing the status data of every modified file in the project folder.
- `_get_previous_commits(max_commits: int) -> Dictionary[]` *virtual required* — Returns an Array of Dictionary items (see `create_commit`), each containing the data for a past commit.
- `_get_remotes() -> String[]` *virtual required* — Returns an Array of Strings, each containing the name of a remote configured in the VCS.
- `_get_vcs_name() -> String` *virtual required* — Returns the name of the underlying VCS provider.
- `_initialize(project_path: String) -> bool` *virtual required* — Initializes the VCS plugin when called from the editor.
- `_pull(remote: String) -> void` *virtual required* — Pulls changes from the remote.
- `_push(remote: String, force: bool) -> void` *virtual required* — Pushes changes to the `remote`.
- `_remove_branch(branch_name: String) -> void` *virtual required* — Remove a branch from the local VCS.
- `_remove_remote(remote_name: String) -> void` *virtual required* — Remove a remote from the local VCS.
- `_set_credentials(username: String, password: String, ssh_public_key_path: String, ssh_private_key_path: String, ssh_passphrase: String) -> void` *virtual required* — Set user credentials in the underlying VCS.
- `_shut_down() -> bool` *virtual required* — Shuts down VCS plugin instance.
- `_stage_file(file_path: String) -> void` *virtual required* — Stages the file present at `file_path` to the staged area.
- `_unstage_file(file_path: String) -> void` *virtual required* — Unstages the file present at `file_path` from the staged area to the unstaged area.
- `add_diff_hunks_into_diff_file(diff_file: Dictionary, diff_hunks: Dictionary[]) -> Dictionary` — Helper function to add an array of `diff_hunks` into a `diff_file`.
- `add_line_diffs_into_diff_hunk(diff_hunk: Dictionary, line_diffs: Dictionary[]) -> Dictionary` — Helper function to add an array of `line_diffs` into a `diff_hunk`.
- `create_commit(msg: String, author: String, id: String, unix_timestamp: int, offset_minutes: int) -> Dictionary` — Helper function to create a commit Dictionary item.
- `create_diff_file(new_file: String, old_file: String) -> Dictionary` — Helper function to create a Dictionary for storing old and new diff file paths.
- `create_diff_hunk(old_start: int, new_start: int, old_lines: int, new_lines: int) -> Dictionary` — Helper function to create a Dictionary for storing diff hunk data.
- `create_diff_line(new_line_no: int, old_line_no: int, content: String, status: String) -> Dictionary` — Helper function to create a Dictionary for storing a line diff.
- `create_status_file(file_path: String, change_type: EditorVCSInterface.ChangeType, area: EditorVCSInterface.TreeArea) -> Dictionary` — Helper function to create a Dictionary used by editor to read the status of a file.
- `popup_error(msg: String) -> void` — Pops up an error message in the editor which is shown as coming from the underlying VCS.

## Enum ChangeType

- `CHANGE_TYPE_NEW = 0` — A new file has been added.
- `CHANGE_TYPE_MODIFIED = 1` — An earlier added file has been modified.
- `CHANGE_TYPE_RENAMED = 2` — An earlier added file has been renamed.
- `CHANGE_TYPE_DELETED = 3` — An earlier added file has been deleted.
- `CHANGE_TYPE_TYPECHANGE = 4` — An earlier added file has been typechanged.
- `CHANGE_TYPE_UNMERGED = 5` — A file is left unmerged.

## Enum TreeArea

- `TREE_AREA_COMMIT = 0` — A commit is encountered from the commit area.
- `TREE_AREA_STAGED = 1` — A file is encountered from the staged area.
- `TREE_AREA_UNSTAGED = 2` — A file is encountered from the unstaged area.
