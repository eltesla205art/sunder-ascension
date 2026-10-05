# OpenXRAndroidThreadSettingsExtension

**Inherits:** OpenXRExtensionWrapper

Wraps the XR_KHR_android_thread_settings extension.

For XR to be comfortable, it is important for applications to deliver frames quickly and consistently. In order to make sure the important application threads get their full share of time, these threads must be identified to the system, which will adjust their scheduling priority accordingly.

## Methods

- `set_application_thread_type(thread_type: OpenXRAndroidThreadSettingsExtension.ThreadType, thread_id: int = 0) -> bool` — Sets the thread type of the given thread, so that the XR runtime can adjust its scheduling priority accordingly.

## Enum ThreadType

- `THREAD_TYPE_APPLICATION_MAIN = 0` — Hints to the XR runtime that the thread is doing time critical CPU tasks.
- `THREAD_TYPE_APPLICATION_WORKER = 1` — Hints to the XR runtime that the thread is doing background CPU tasks.
- `THREAD_TYPE_RENDERER_MAIN = 2` — Hints to the XR runtime that the thread is doing time critical graphics device tasks.
- `THREAD_TYPE_RENDERER_WORKER = 3` — Hints to the XR runtime that the thread is doing background graphics device tasks.
