# AudioListener2D

**Inherits:** Node2D

Overrides the location sounds are heard from.

Once added to the scene tree and enabled using `make_current`, this node will override the location sounds are heard from. Only one AudioListener2D can be current. Using `make_current` will disable the previous AudioListener2D. If there is no active AudioListener2D in the current Viewport, center of the screen will be used as a hearing point for the audio.

## Methods

- `clear_current() -> void` — Disables the AudioListener2D.
- `is_current() -> bool` *const* — Returns `true` if this AudioListener2D is currently active.
- `make_current() -> void` — Makes the AudioListener2D active, setting it as the hearing point for the sounds.
