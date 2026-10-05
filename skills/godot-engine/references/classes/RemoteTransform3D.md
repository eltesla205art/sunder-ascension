# RemoteTransform3D

**Inherits:** Node3D

RemoteTransform3D pushes its own Transform3D to another Node3D derived Node in the scene.

RemoteTransform3D pushes its own Transform3D to another Node3D derived Node (called the remote node) in the scene. It can be set to update another Node's position, rotation and/or scale. It can use either global or local coordinates.

## Properties

- `remote_path: NodePath` = `NodePath("")` — The NodePath to the remote node, relative to the RemoteTransform3D's position in the scene.
- `update_position: bool` = `true` — If `true`, the remote node's position is updated.
- `update_rotation: bool` = `true` — If `true`, the remote node's rotation is updated.
- `update_scale: bool` = `true` — If `true`, the remote node's scale is updated.
- `use_global_coordinates: bool` = `true` — If `true`, global coordinates are used.

## Methods

- `force_update_cache() -> void` — RemoteTransform3D caches the remote node.
