# OS

**Inherits:** Object

Provides access to common operating system functionalities.

The OS class wraps the most common functionalities for communicating with the host operating system, such as the video driver, delays, environment variables, execution of binaries, command line, etc. Note: In Godot 4, OS functions related to window management, clipboard, and TTS were moved to the DisplayServer singleton (and the Window class). Functions related to time were removed and are only available in the Time class.

## Properties

- `delta_smoothing: bool` = `true` — If `true`, the engine filters the time delta measured between each frame, and attempts to compensate for random variation.
- `low_processor_usage_mode: bool` = `false` — If `true`, the engine optimizes for low processor usage by only refreshing the screen if needed.
- `low_processor_usage_mode_sleep_usec: int` = `6900` — The amount of sleeping between frames when the low-processor usage mode is enabled, in microseconds.

## Methods

- `add_logger(logger: Logger) -> void` — Add a custom logger to intercept the internal message stream.
- `alert(text: String, title: String = "Alert!") -> void` — Displays a modal dialog box using the host platform's implementation.
- `close_midi_inputs() -> void` — Shuts down the system MIDI driver.
- `crash(message: String) -> void` — Crashes the engine (or the editor if called within a `@tool` script).
- `create_instance(arguments: PackedStringArray) -> int` — Creates a new instance of Godot that runs independently.
- `create_process(path: String, arguments: PackedStringArray, open_console: bool = false) -> int` — Creates a new process that runs independently of Godot.
- `delay_msec(msec: int) -> void` *const* — Delays execution of the current thread by `msec` milliseconds.
- `delay_usec(usec: int) -> void` *const* — Delays execution of the current thread by `usec` microseconds.
- `execute(path: String, arguments: PackedStringArray, output: Array = [], read_stderr: bool = false, open_console: bool = false) -> int` — Executes the given process in a blocking way.
- `execute_with_pipe(path: String, arguments: PackedStringArray, blocking: bool = true) -> Dictionary` — Creates a new process that runs independently of Godot with redirected IO.
- `find_keycode_from_string(string: String) -> int[Key]` *const* — Finds the keycode for the given string.
- `get_cache_dir() -> String` *const* — Returns the global cache data directory according to the operating system's standards.
- `get_cmdline_args() -> PackedStringArray` — Returns the command-line arguments passed to the engine, excluding arguments processed by the engine, such as `--headless` and `--fullscreen`.
- `get_cmdline_user_args() -> PackedStringArray` — Returns the command-line user arguments passed to the engine.
- `get_config_dir() -> String` *const* — Returns the global user configuration directory according to the operating system's standards.
- `get_connected_midi_inputs() -> PackedStringArray` — Returns an array of connected MIDI device names, if they exist.
- `get_data_dir() -> String` *const* — Returns the global user data directory according to the operating system's standards.
- `get_distribution_name() -> String` *const* — Returns the name of the distribution for Linux and BSD platforms (e.g. "Ubuntu", "Manjaro", "OpenBSD", etc.).
- `get_entropy(size: int) -> PackedByteArray` — Generates a PackedByteArray of cryptographically secure random bytes with given `size`.
- `get_environment(variable: String) -> String` *const* — Returns the value of the given environment variable, or an empty string if `variable` doesn't exist.
- `get_executable_path() -> String` *const* — Returns the file path to the current engine executable.
- `get_granted_permissions() -> PackedStringArray` *const* — On Android devices: Returns the list of dangerous permissions that have been granted.
- `get_keycode_string(code: Key) -> String` *const* — Returns the given keycode as a String.
- `get_locale() -> String` *const* — Returns the host OS locale as a String of the form `language_Script_COUNTRY_VARIANT@extra`.
- `get_locale_language() -> String` *const* — Returns the host OS locale's 2 or 3-letter language code as a string which should be consistent on all platforms.
- `get_main_thread_id() -> int` *const* — Returns the ID of the main thread.
- `get_memory_info() -> Dictionary` *const* — Returns a Dictionary containing information about the current memory with the following entries: - `"physical"` - total amount of usable physical memory in bytes.
- `get_model_name() -> String` *const* — Returns the model name of the current device.
- `get_name() -> String` *const* — Returns the name of the host platform. - On Windows, this is `"Windows"`. - On macOS, this is `"macOS"`. - On Linux-based operating systems, this is `"Linux"`. - On BSD-based operating systems, this is `"FreeBSD"`, `"NetBSD"`, `"OpenBSD"`, or `"BSD"` as a fallback. - On Android, this is `"Android"`. - On iOS, this is `"iOS"`. - On Web, this is `"Web"`.
- `get_preferred_locales() -> PackedStringArray` *const* — Returns an array of locales preferred by the user, in order of preference.
- `get_process_exit_code(pid: int) -> int` *const* — Returns the exit code of a spawned process once it has finished running (see `is_process_running`).
- `get_process_id() -> int` *const* — Returns the number used by the host machine to uniquely identify this application.
- `get_processor_count() -> int` *const* — Returns the number of logical CPU cores available on the host machine.
- `get_processor_name() -> String` *const* — Returns the full name of the CPU model on the host machine (e.g.
- `get_restart_on_exit_arguments() -> PackedStringArray` *const* — Returns the list of command line arguments that will be used when the project automatically restarts using `set_restart_on_exit`.
- `get_static_memory_peak_usage() -> int` *const* — Returns the maximum amount of static memory used.
- `get_static_memory_usage() -> int` *const* — Returns the amount of static memory being used by the program in bytes.
- `get_stderr_type() -> int[OS.StdHandleType]` *const* — Returns the type of the standard error device.
- `get_stdin_type() -> int[OS.StdHandleType]` *const* — Returns the type of the standard input device.
- `get_stdout_type() -> int[OS.StdHandleType]` *const* — Returns the type of the standard output device.
- `get_system_ca_certificates() -> String` — Returns the list of certification authorities trusted by the operating system as a string of concatenated certificates in PEM format.
- `get_system_dir(dir: OS.SystemDir, shared_storage: bool = true) -> String` *const* — Returns the path to commonly used folders across different platforms, as defined by `dir`.
- `get_system_font_path(font_name: String, weight: int = 400, stretch: int = 100, italic: bool = false) -> String` *const* — Returns the path to the system font file with `font_name` and style.
- `get_system_font_path_for_text(font_name: String, text: String, locale: String = "", script: String = "", weight: int = 400, stretch: int = 100, italic: bool = false) -> PackedStringArray` *const* — Returns an array of the system substitute font file paths, which are similar to the font with `font_name` and style for the specified text, locale, and script.
- `get_system_fonts() -> PackedStringArray` *const* — Returns the list of font family names available.
- `get_temp_dir() -> String` *const* — Returns the global temporary data directory according to the operating system's standards.
- `get_thread_caller_id() -> int` *const* — Returns the ID of the current thread.
- `get_unique_id() -> String` *const* — Returns a string that is unique to the device.
- `get_user_data_dir() -> String` *const* — Returns the absolute directory path where user data is written (the `user://` directory in Godot).
- `get_version() -> String` *const* — Returns the exact production and build version of the operating system.
- `get_version_alias() -> String` *const* — Returns the branded version used in marketing, followed by the build number (on Windows), the version number (on macOS), or the SDK version and incremental build number (on Android).
- `get_video_adapter_driver_info() -> PackedStringArray` *const* — Returns the video adapter driver name and version for the user's currently active graphics card, as a PackedStringArray.
- `has_environment(variable: String) -> bool` *const* — Returns `true` if the environment variable with the name `variable` exists.
- `has_feature(tag_name: String) -> bool` *const* — Returns `true` if the feature for the given feature tag is supported in the currently running instance, depending on the platform, build, etc.
- `is_debug_build() -> bool` *const* — Returns `true` if the Godot binary used to run the project is a debug export template, or when running in the editor.
- `is_keycode_unicode(code: int) -> bool` *const* — Returns `true` if the input keycode corresponds to a Unicode character.
- `is_process_running(pid: int) -> bool` *const* — Returns `true` if the child process ID (`pid`) is still running or `false` if it has terminated.
- `is_restart_on_exit_set() -> bool` *const* — Returns `true` if the project will automatically restart when it exits for any reason, `false` otherwise.
- `is_sandboxed() -> bool` *const* — Returns `true` if the application is running in the sandbox.
- `is_stdout_verbose() -> bool` *const* — Returns `true` if the engine was executed with the `--verbose` or `-v` command line argument, or if `ProjectSettings.debug/settings/stdout/verbose_stdout` is `true`.
- `is_userfs_persistent() -> bool` *const* — Returns `true` if the `user://` file system is persistent, that is, its state is the same after a player quits and starts the game again.
- `kill(pid: int) -> int[Error]` — Kill (terminate) the process identified by the given process ID (`pid`), such as the ID returned by `execute` in non-blocking mode.
- `move_to_trash(path: String) -> int[Error]` *const* — Moves the file or directory at the given `path` to the system's recycle bin.
- `open_midi_inputs() -> void` — Initializes the singleton for the system MIDI driver, allowing Godot to receive InputEventMIDI.
- `open_with_program(program_path: String, paths: PackedStringArray) -> int[Error]` — Opens one or more files/directories with the specified application.
- `read_buffer_from_stdin(buffer_size: int = 1024) -> PackedByteArray` — Reads a user input as raw data from the standard input.
- `read_string_from_stdin(buffer_size: int = 1024) -> String` — Reads a user input as a UTF-8 encoded string from the standard input.
- `remove_logger(logger: Logger) -> void` — Remove a custom logger added by `add_logger`.
- `request_permission(name: String) -> bool` — Requests permission from the OS for the given `name`.
- `request_permissions() -> bool` — Requests dangerous permissions from the OS.
- `revoke_granted_permissions() -> void` — On macOS (sandboxed applications only), this function clears list of user selected folders accessible to the application.
- `set_environment(variable: String, value: String) -> void` *const* — Sets the value of the environment variable `variable` to `value`.
- `set_restart_on_exit(restart: bool, arguments: PackedStringArray = PackedStringArray()) -> void` — If `restart` is `true`, restarts the project automatically when it is exited with `SceneTree.quit` or `Node.NOTIFICATION_WM_CLOSE_REQUEST`.
- `set_thread_name(name: String) -> int[Error]` — Assigns the given name to the current thread.
- `set_use_file_access_save_and_swap(enabled: bool) -> void` — If `enabled` is `true`, when opening a file for writing, a temporary file is used in its place.
- `shell_open(uri: String) -> int[Error]` — Requests the OS to open a resource identified by `uri` with the most appropriate program.
- `shell_show_in_file_manager(file_or_dir_path: String, open_folder: bool = true) -> int[Error]` — Requests the OS to open the file manager, navigate to the given `file_or_dir_path` and select the target file or folder.
- `unset_environment(variable: String) -> void` *const* — Removes the given environment variable from the current environment, if it exists.

## Enum RenderingDriver

- `RENDERING_DRIVER_VULKAN = 0` — The Vulkan rendering driver.
- `RENDERING_DRIVER_OPENGL3 = 1` — The OpenGL 3 rendering driver.
- `RENDERING_DRIVER_D3D12 = 2` — The Direct3D 12 rendering driver.
- `RENDERING_DRIVER_METAL = 3` — The Metal rendering driver.

## Enum SystemDir

- `SYSTEM_DIR_DESKTOP = 0` — Refers to the Desktop directory path.
- `SYSTEM_DIR_DCIM = 1` — Refers to the DCIM (Digital Camera Images) directory path.
- `SYSTEM_DIR_DOCUMENTS = 2` — Refers to the Documents directory path.
- `SYSTEM_DIR_DOWNLOADS = 3` — Refers to the Downloads directory path.
- `SYSTEM_DIR_MOVIES = 4` — Refers to the Movies (or Videos) directory path.
- `SYSTEM_DIR_MUSIC = 5` — Refers to the Music directory path.
- `SYSTEM_DIR_PICTURES = 6` — Refers to the Pictures directory path.
- `SYSTEM_DIR_RINGTONES = 7` — Refers to the Ringtones directory path.

## Enum StdHandleType

- `STD_HANDLE_INVALID = 0` — Standard I/O device is invalid.
- `STD_HANDLE_CONSOLE = 1` — Standard I/O device is a console.
- `STD_HANDLE_FILE = 2` — Standard I/O device is a regular file.
- `STD_HANDLE_PIPE = 3` — Standard I/O device is a FIFO/pipe.
- `STD_HANDLE_UNKNOWN = 4` — Standard I/O device type is unknown.
