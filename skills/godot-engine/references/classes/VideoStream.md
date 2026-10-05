# VideoStream

**Inherits:** Resource

Base resource for video streams.

Base resource type for all video streams. Classes that derive from VideoStream can all be used as resource types to play back videos in VideoStreamPlayer.

## Properties

- `file: String` = `""` — The video file path or URI that this VideoStream resource handles.

## Methods

- `_instantiate_playback() -> VideoStreamPlayback` *virtual required* — Called when the video starts playing, to initialize and return a subclass of VideoStreamPlayback.
