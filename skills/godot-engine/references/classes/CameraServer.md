# CameraServer

**Inherits:** Object

Server keeping track of different cameras accessible in Godot.

The CameraServer keeps track of different cameras accessible in Godot. These are external cameras such as webcams or the cameras on your phone. It is notably used to provide AR modules with a video feed from the camera. Note: This class is currently only implemented on Linux, Android, macOS, and iOS.

## Properties

- `monitoring_feeds: bool` = `false` — If `true`, the server is actively monitoring available camera feeds.

## Methods

- `add_feed(feed: CameraFeed) -> void` — Adds the camera `feed` to the camera server.
- `feeds() -> CameraFeed[]` — Returns an array of CameraFeeds.
- `get_feed(index: int) -> CameraFeed` — Returns the CameraFeed corresponding to the camera with the given `index`.
- `get_feed_count() -> int` — Returns the number of CameraFeeds registered.
- `remove_feed(feed: CameraFeed) -> void` — Removes the specified camera `feed`.

## Signals

- `camera_feed_added(id: int)` — Emitted when a CameraFeed is added (e.g. a webcam is plugged in).
- `camera_feed_removed(id: int)` — Emitted when a CameraFeed is removed (e.g. a webcam is unplugged).
- `camera_feeds_updated()` — Emitted when camera feeds are updated.

## Enum FeedImage

- `FEED_RGBA_IMAGE = 0` — The RGBA camera image.
- `FEED_YCBCR_IMAGE = 0` — The YCbCr camera image.
- `FEED_Y_IMAGE = 0` — The Y component camera image.
- `FEED_CBCR_IMAGE = 1` — The CbCr component camera image.
