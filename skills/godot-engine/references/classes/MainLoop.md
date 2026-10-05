# MainLoop

**Inherits:** Object

Abstract base class for the game's main loop.

MainLoop is the abstract base class for a Godot project's game loop. It is inherited by SceneTree, which is the default game loop implementation used in Godot projects, though it is also possible to write and use one's own MainLoop subclass instead of the scene tree. Upon the application start, a MainLoop implementation must be provided to the OS; otherwise, the application will exit. This happens automatically (and a SceneTree is created) unless a MainLoop Script is provided from the command line (with e.g.

## Methods

- `_finalize() -> void` *virtual* — Called before the program exits.
- `_initialize() -> void` *virtual* — Called once during initialization.
- `_physics_process(delta: float) -> bool` *virtual* — Called each physics tick.
- `_process(delta: float) -> bool` *virtual* — Called on each idle frame, prior to rendering, and after physics ticks have been processed.

## Signals

- `on_request_permissions_result(permission: String, granted: bool)` — Emitted when a user responds to a permission request.

## Constants

- `NOTIFICATION_OS_MEMORY_WARNING = 2009` — Notification received from the OS when the application is exceeding its allocated memory.
- `NOTIFICATION_TRANSLATION_CHANGED = 2010` — Notification received when translations may have changed.
- `NOTIFICATION_WM_ABOUT = 2011` — Notification received from the OS when a request for "About" information is sent.
- `NOTIFICATION_CRASH = 2012` — Notification received from Godot's crash handler when the engine is about to crash.
- `NOTIFICATION_OS_IME_UPDATE = 2013` — Notification received from the OS when an update of the Input Method Engine occurs (e.g. change of IME cursor position or composition string).
- `NOTIFICATION_APPLICATION_RESUMED = 2014` — Notification received from the OS when the application is resumed.
- `NOTIFICATION_APPLICATION_PAUSED = 2015` — Notification received from the OS when the application is paused.
- `NOTIFICATION_APPLICATION_FOCUS_IN = 2016` — Notification received from the OS when the application is focused, i.e. when changing the focus from the OS desktop or a thirdparty application to any open window of the Godot instance.
- `NOTIFICATION_APPLICATION_FOCUS_OUT = 2017` — Notification received from the OS when the application is defocused, i.e. when changing the focus from any open window of the Godot instance to the OS desktop or a thirdparty application.
- `NOTIFICATION_TEXT_SERVER_CHANGED = 2018` — Notification received when text server is changed.
- `NOTIFICATION_APPLICATION_PIP_MODE_ENTERED = 2019` — Notification received when the application enters picture-in-picture mode.
- `NOTIFICATION_APPLICATION_PIP_MODE_EXITED = 2020` — Notification received when the application exits picture-in-picture mode.
