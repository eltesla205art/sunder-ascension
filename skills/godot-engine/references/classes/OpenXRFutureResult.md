# OpenXRFutureResult

**Inherits:** RefCounted

Result object tracking the asynchronous result of an OpenXR Future object.

Result object tracking the asynchronous result of an OpenXR Future object, you can use this object to track the result status.

## Methods

- `cancel_future() -> void` — Cancel this future, this will interrupt and stop the asynchronous function.
- `get_future() -> int` *const* — Return the `XrFutureEXT` value this result relates to.
- `get_result_value() -> Variant` *const* — Returns the result value of our asynchronous function (if set by the extension).
- `get_status() -> int[OpenXRFutureResult.ResultStatus]` *const* — Returns the status of this result.
- `set_result_value(result_value: Variant) -> void` — Stores the result value we expose to the user.

## Signals

- `completed(result: OpenXRFutureResult)` — Emitted when the asynchronous function is finished or has been cancelled.

## Enum ResultStatus

- `RESULT_RUNNING = 0` — The asynchronous function is running.
- `RESULT_FINISHED = 1` — The asynchronous function has finished.
- `RESULT_CANCELLED = 2` — The asynchronous function has been cancelled.
