# VisibleOnScreenEnabler3D

**Inherits:** VisibleOnScreenNotifier3D

A box-shaped region of 3D space that, when visible on screen, enables a target node.

VisibleOnScreenEnabler3D contains a box-shaped region of 3D space and a target node. The target node will be automatically enabled (via its `Node.process_mode` property) when any part of this region becomes visible on the screen, and automatically disabled otherwise. This can for example be used to activate enemies only when the player approaches them. See VisibleOnScreenNotifier3D if you only want to be notified when the region is visible on screen.

## Properties

- `enable_mode: VisibleOnScreenEnabler3D.EnableMode` = `0` — Determines how the target node is enabled.
- `enable_node_path: NodePath` = `NodePath("..")` — The path to the target node, relative to the VisibleOnScreenEnabler3D.

## Enum EnableMode

- `ENABLE_MODE_INHERIT = 0` — Corresponds to `Node.PROCESS_MODE_INHERIT`.
- `ENABLE_MODE_ALWAYS = 1` — Corresponds to `Node.PROCESS_MODE_ALWAYS`.
- `ENABLE_MODE_WHEN_PAUSED = 2` — Corresponds to `Node.PROCESS_MODE_WHEN_PAUSED`.
