# FileDialog

**Inherits:** ConfirmationDialog

A dialog for selecting files or directories in the filesystem.

FileDialog is a preset dialog used to choose files and directories in the filesystem. It supports filter masks. FileDialog automatically sets its window title according to the `file_mode`, if `Window.title` is empty. Note: FileDialog is invisible by default.

## Properties

- `access: FileDialog.Access` = `0` — The file system access scope.
- `current_dir: String` — The current working directory of the file dialog.
- `current_file: String` — The currently selected file of the file dialog.
- `current_path: String` — The currently selected file path of the file dialog.
- `deleting_enabled: bool` = `true` — If `true`, the context menu will show the "Delete" option, which allows moving files and folders to trash.
- `dialog_hide_on_ok: bool` = `false` — 
- `display_mode: FileDialog.DisplayMode` = `0` — Display mode of the dialog's file list.
- `drive_selector_enabled: bool` = `true` — If `true`, shows the drive select dropdown next to the current path.
- `favorites_enabled: bool` = `true` — If `true`, shows the toggle favorite button and favorite list on the left side of the dialog.
- `file_filter_toggle_enabled: bool` = `true` — If `true`, shows the toggle file filter button.
- `file_mode: FileDialog.FileMode` = `4` — The dialog's open or save mode, which affects the selection behavior.
- `file_sort_options_enabled: bool` = `true` — If `true`, shows the file sorting options button.
- `filename_filter: String` = `""` — The filter for file names (case-insensitive).
- `filters: PackedStringArray` = `PackedStringArray()` — The available file type filters.
- `filters_enabled: bool` = `true` — If `true`, shows the file extension filter dropdown next to the file name.
- `folder_creation_enabled: bool` = `true` — If `true`, shows the button for creating new directories (when using `FILE_MODE_OPEN_DIR`, `FILE_MODE_OPEN_ANY`, or `FILE_MODE_SAVE_FILE`), and the context menu will have the "New Folder..." option.
- `hidden_files_toggle_enabled: bool` = `true` — If `true`, shows the toggle hidden files button.
- `layout_toggle_enabled: bool` = `true` — If `true`, shows the layout switch buttons (list/thumbnails).
- `mode_overrides_title: bool` = `true` *(deprecated)* — Has no effect and always equals to `true`.
- `navigation_buttons_enabled: bool` = `true` — If `true`, shows the go back/forward buttons on the toolbar.
- `option_count: int` = `0` — The number of additional OptionButtons and CheckBoxes in the dialog.
- `option_{index}/default: int` = `0` — The default value for the option at `index`.
- `option_{index}/name: String` = `""` — The name of the option at `index`.
- `option_{index}/values: PackedStringArray` = `PackedStringArray()` — The list of values for the option at `index`.
- `overwrite_warning_enabled: bool` = `true` — If `true`, the FileDialog will warn the user before overwriting files in save mode.
- `recent_list_enabled: bool` = `true` — If `true`, shows the recent directories list on the left side of the dialog.
- `root_subfolder: String` = `""` — If non-empty, the given sub-folder will be "root" of this FileDialog, i.e. user won't be able to go to its parent directory.
- `show_hidden_files: bool` = `false` — If `true`, the dialog will show hidden files.
- `size: Vector2i` = `Vector2i(640, 360)` — 
- `use_native_dialog: bool` = `false` — If `true`, and if supported by the current DisplayServer, OS native dialog will be used instead of custom one.

## Methods

- `add_filter(filter: String, description: String = "", mime_type: String = "") -> void` — Adds a comma-separated file extension `filter` and comma-separated MIME type `mime_type` option to the FileDialog with an optional `description`, which restricts what files can be picked.
- `add_option(name: String, values: PackedStringArray, default_value_index: int) -> void` — Adds an additional OptionButton to the file dialog.
- `clear_filename_filter() -> void` — Clear the filter for file names.
- `clear_filters() -> void` — Clear all the added filters in the dialog.
- `deselect_all() -> void` — Clear all currently selected items in the dialog.
- `get_favorite_list() -> PackedStringArray` *static* — Returns the list of favorite directories, which is shared by all FileDialog nodes.
- `get_line_edit() -> LineEdit` — Returns the LineEdit for the selected file.
- `get_option_default(option: int) -> int` *const* — Returns the default value index of the OptionButton or CheckBox with index `option`.
- `get_option_name(option: int) -> String` *const* — Returns the name of the OptionButton or CheckBox with index `option`.
- `get_option_values(option: int) -> PackedStringArray` *const* — Returns an array of values of the OptionButton with index `option`.
- `get_recent_list() -> PackedStringArray` *static* — Returns the list of recent directories, which is shared by all FileDialog nodes.
- `get_selected_options() -> Dictionary` *const* — Returns a Dictionary with the selected values of the additional OptionButtons and/or CheckBoxes.
- `get_vbox() -> VBoxContainer` — Returns the vertical box container of the dialog, custom controls can be added to it.
- `invalidate() -> void` — Invalidates and updates this dialog's content list.
- `is_customization_flag_enabled(flag: FileDialog.Customization) -> bool` *const* — Returns `true` if the provided `flag` is enabled.
- `popup_file_dialog() -> void` — Shows the FileDialog using the default size and position for file dialogs, and selects the file name if there is a current file.
- `set_customization_flag_enabled(flag: FileDialog.Customization, enabled: bool) -> void` — Sets the specified customization `flag`, allowing to customize the features available in this FileDialog.
- `set_favorite_list(favorites: PackedStringArray) -> void` *static* — Sets the list of favorite directories, which is shared by all FileDialog nodes.
- `set_get_icon_callback(callback: Callable) -> void` *static* — Sets the callback used by the FileDialog nodes to get a file icon, when `DISPLAY_LIST` mode is used.
- `set_get_thumbnail_callback(callback: Callable) -> void` *static* — Sets the callback used by the FileDialog nodes to get a file icon, when `DISPLAY_THUMBNAILS` mode is used.
- `set_option_default(option: int, default_value_index: int) -> void` — Sets the default value index of the OptionButton or CheckBox with index `option`.
- `set_option_name(option: int, name: String) -> void` — Sets the name of the OptionButton or CheckBox with index `option`.
- `set_option_values(option: int, values: PackedStringArray) -> void` — Sets the option values of the OptionButton with index `option`.
- `set_recent_list(recents: PackedStringArray) -> void` *static* — Sets the list of recent directories, which is shared by all FileDialog nodes.

## Signals

- `dir_selected(dir: String)` — Emitted when the user selects a directory.
- `file_selected(path: String)` — Emitted when the user selects a file by double-clicking it or pressing the OK button.
- `filename_filter_changed(filter: String)` — Emitted when the filter for file names changes.
- `files_selected(paths: PackedStringArray)` — Emitted when the user selects multiple files.

## Enum FileMode

- `FILE_MODE_OPEN_FILE = 0` — The dialog allows selecting one, and only one file.
- `FILE_MODE_OPEN_FILES = 1` — The dialog allows selecting multiple files.
- `FILE_MODE_OPEN_DIR = 2` — The dialog only allows selecting a directory, disallowing the selection of any file.
- `FILE_MODE_OPEN_ANY = 3` — The dialog allows selecting one file or directory.
- `FILE_MODE_SAVE_FILE = 4` — The dialog will warn when a file exists.

## Enum Access

- `ACCESS_RESOURCES = 0` — The dialog only allows accessing files under the Resource path (`res://`).
- `ACCESS_USERDATA = 1` — The dialog only allows accessing files under user data path (`user://`).
- `ACCESS_FILESYSTEM = 2` — The dialog allows accessing files on the whole file system.

## Enum DisplayMode

- `DISPLAY_THUMBNAILS = 0` — The dialog displays files as a grid of thumbnails.
- `DISPLAY_LIST = 1` — The dialog displays files as a list of filenames.

## Enum Customization

- `CUSTOMIZATION_HIDDEN_FILES = 0` — If enabled, shows the toggle hidden files button.
- `CUSTOMIZATION_CREATE_FOLDER = 1` — If enabled, shows the button for creating new directories (when using `FILE_MODE_OPEN_DIR`, `FILE_MODE_OPEN_ANY`, or `FILE_MODE_SAVE_FILE`).
- `CUSTOMIZATION_FILE_FILTER = 2` — If enabled, shows the toggle file filter button.
- `CUSTOMIZATION_FILE_SORT = 3` — If enabled, shows the file sorting options button.
- `CUSTOMIZATION_FAVORITES = 4` — If enabled, shows the toggle favorite button and favorite list on the left side of the dialog.
- `CUSTOMIZATION_RECENT = 5` — If enabled, shows the recent directories list on the left side of the dialog.
- `CUSTOMIZATION_LAYOUT = 6` — If enabled, shows the layout switch buttons (list/thumbnails).
- `CUSTOMIZATION_OVERWRITE_WARNING = 7` — If enabled, the FileDialog will warn the user before overwriting files in save mode.
- `CUSTOMIZATION_DELETE = 8` — If enabled, the context menu will show the "Delete" option, which allows moving files and folders to trash.
- `CUSTOMIZATION_NAVIGATION_BUTTONS = 9` — If enabled, shows the go back/forward buttons on the toolbar.
- `CUSTOMIZATION_DRIVE_SELECTOR = 10` — If enabled, shows the drive select dropdown next to the current path.
- `CUSTOMIZATION_FILTERS = 11` — If enabled, shows the file extension filter dropdown next to the file name.

## Theme items

- `file_disabled_color: Color` (color) = `Color(1, 1, 1, 0.25)`
- `file_icon_color: Color` (color) = `Color(1, 1, 1, 1)`
- `folder_icon_color: Color` (color) = `Color(1, 1, 1, 1)`
- `thumbnail_size: int` (constant) = `64`
- `back_folder: Texture2D` (icon)
- `create_folder: Texture2D` (icon)
- `favorite: Texture2D` (icon)
- `favorite_down: Texture2D` (icon)
- `favorite_up: Texture2D` (icon)
- `file: Texture2D` (icon)
- `file_thumbnail: Texture2D` (icon)
- `folder: Texture2D` (icon)
- `folder_thumbnail: Texture2D` (icon)
- `forward_folder: Texture2D` (icon)
- `list_mode: Texture2D` (icon)
- `menu_copy_path: Texture2D` (icon)
- `menu_delete: Texture2D` (icon)
- `menu_new_folder: Texture2D` (icon)
- `menu_open_bundle: Texture2D` (icon)
- `menu_refresh: Texture2D` (icon)
- `menu_show_in_file_manager: Texture2D` (icon)
- `parent_folder: Texture2D` (icon)
- `reload: Texture2D` (icon)
- `sort: Texture2D` (icon)
- `thumbnail_mode: Texture2D` (icon)
- `toggle_filename_filter: Texture2D` (icon)
- `toggle_hidden: Texture2D` (icon)
