# OpenXRFutureExtension

**Inherits:** OpenXRExtensionWrapper

The OpenXR Future extension allows for asynchronous APIs to be used.

This is a support extension in OpenXR that allows other OpenXR extensions to start asynchronous functions and get a callback after this function finishes. It is not intended for consumption within GDScript but can be accessed from GDExtension.

## Methods

- `cancel_future(future: int) -> void` — Cancels an in-progress future.
- `is_active() -> bool` *const* — Returns `true` if futures are available in the OpenXR runtime used.
- `register_future(future: int, on_success: Callable = Callable()) -> OpenXRFutureResult` — Register an OpenXR Future object so we monitor for completion.
