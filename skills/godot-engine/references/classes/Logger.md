# Logger

**Inherits:** RefCounted

Custom logger to receive messages from the internal error/warning stream.

Custom logger to receive messages from the internal error/warning stream. Loggers are registered via `OS.add_logger`.

## Methods

- `_log_error(function: String, file: String, line: int, code: String, rationale: String, editor_notify: bool, error_type: int, script_backtraces: ScriptBacktrace[]) -> void` *virtual* — Called when an error is logged.
- `_log_message(message: String, error: bool) -> void` *virtual* — Called when a message is logged.

## Enum ErrorType

- `ERROR_TYPE_ERROR = 0` — The message received is an error.
- `ERROR_TYPE_WARNING = 1` — The message received is a warning.
- `ERROR_TYPE_SCRIPT = 2` — The message received is a script error.
- `ERROR_TYPE_SHADER = 3` — The message received is a shader error.
