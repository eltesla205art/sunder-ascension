# AnimatedTexture

**Inherits:** Texture2D
**Deprecated:** This class does not work properly in current versions and may be removed in the future. There is currently no equivalent workaround.

Proxy texture for simple frame-based animations.

AnimatedTexture is a resource format for frame-based animations, where multiple textures can be chained automatically with a predefined delay for each frame. Unlike AnimationPlayer or AnimatedSprite2D, it isn't a Node, but has the advantage of being usable anywhere a Texture2D resource can be used, e.g. in a TileSet. The playback of the animation is controlled by the `speed_scale` property, as well as each frame's duration (see `set_frame_duration`). The animation loops, i.e. it will restart at frame 0 automatically after playing the last frame.

## Properties

- `current_frame: int` — Sets the currently visible frame of the texture.
- `frames: int` = `1` — Number of frames to use in the animation.
- `one_shot: bool` = `false` — If `true`, the animation will only play once and will not loop back to the first frame after reaching the end.
- `pause: bool` = `false` — If `true`, the animation will pause where it currently is (i.e. at `current_frame`).
- `resource_local_to_scene: bool` = `false` — 
- `speed_scale: float` = `1.0` — The animation speed is multiplied by this value.

## Methods

- `get_frame_duration(frame: int) -> float` *const* — Returns the given `frame`'s duration, in seconds.
- `get_frame_texture(frame: int) -> Texture2D` *const* — Returns the given frame's Texture2D.
- `set_frame_duration(frame: int, duration: float) -> void` — Sets the duration of any given `frame`.
- `set_frame_texture(frame: int, texture: Texture2D) -> void` — Assigns a Texture2D to the given frame.

## Constants

- `MAX_FRAMES = 256` — The maximum number of frames supported by AnimatedTexture.
