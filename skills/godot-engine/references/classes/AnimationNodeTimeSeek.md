# AnimationNodeTimeSeek

**Inherits:** AnimationNode

A time-seeking animation node used in AnimationTree.

This animation node can be used to cause a seek command to happen to any sub-children of the animation graph. Use to play an Animation from the start or a certain playback position inside the AnimationNodeBlendTree. After setting the time and changing the animation playback, the time seek node automatically goes into sleep mode on the next process frame by setting its `seek_request` value to `-1.0`.

## Properties

- `explicit_elapse: bool` = `true` — If `true`, some processes are executed to handle keys between seeks, such as calculating root motion and finding the nearest discrete key.
