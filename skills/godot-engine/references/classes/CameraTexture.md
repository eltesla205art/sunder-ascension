# CameraTexture

**Inherits:** Texture2D

Texture provided by a CameraFeed.

This texture gives access to the camera texture provided by a CameraFeed. Note: Many cameras supply YCbCr images which need to be converted in a shader.

## Properties

- `camera_feed_id: int` = `0` — The ID of the CameraFeed for which we want to display the image.
- `camera_is_active: bool` = `false` — Convenience property that gives access to the active property of the CameraFeed.
- `resource_local_to_scene: bool` = `false` — 
- `which_feed: CameraServer.FeedImage` = `0` — Which image within the CameraFeed we want access to, important if the camera image is split in a Y and CbCr component.
