# Node3D

**Inherits:** Node

Base object in 3D space, inherited by all 3D nodes.

The Node3D node is the base representation of a node in 3D space. All other 3D nodes inherit from this class. Affine operations (translation, rotation, scale) are calculated in the coordinate system relative to the parent, unless the Node3D's `top_level` is `true`. In this coordinate system, affine operations correspond to direct affine operations on the Node3D's `transform`.

## Properties

- `basis: Basis` — Basis of the `transform` property.
- `global_basis: Basis` — Basis of the `global_transform` property.
- `global_position: Vector3` — Global position (translation) of this node in global space (relative to the world).
- `global_rotation: Vector3` — Global rotation of this node as Euler angles, in radians and in global space (relative to the world).
- `global_rotation_degrees: Vector3` — The `global_rotation` of this node, in degrees instead of radians.
- `global_transform: Transform3D` — The transformation of this node, in global space (relative to the world).
- `position: Vector3` = `Vector3(0, 0, 0)` — Position (translation) of this node in parent space (relative to the parent node).
- `quaternion: Quaternion` — Rotation of this node represented as a Quaternion in parent space (relative to the parent node).
- `rotation: Vector3` = `Vector3(0, 0, 0)` — Rotation of this node as Euler angles, in radians and in parent space (relative to the parent node).
- `rotation_degrees: Vector3` — The `rotation` of this node, in degrees instead of radians.
- `rotation_edit_mode: Node3D.RotationEditMode` = `0` — How this node's rotation and scale are displayed in the Inspector dock.
- `rotation_order: EulerOrder` = `2` — The axis rotation order of the `rotation` property.
- `scale: Vector3` = `Vector3(1, 1, 1)` — Scale of this node in local space (relative to this node).
- `top_level: bool` = `false` — If `true`, the node does not inherit its transformations from its parent.
- `transform: Transform3D` = `Transform3D(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)` — The local transformation of this node, in parent space (relative to the parent node).
- `visibility_parent: NodePath` = `NodePath("")` — Path to the visibility range parent for this node and its descendants.
- `visible: bool` = `true` — If `true`, this node can be visible.

## Methods

- `add_gizmo(gizmo: Node3DGizmo) -> void` — Attaches the given `gizmo` to this node.
- `clear_gizmos() -> void` — Clears all EditorNode3DGizmo objects attached to this node.
- `clear_subgizmo_selection() -> void` — Deselects all subgizmos for this node.
- `force_update_transform() -> void` — Forces the node's `global_transform` to update, by sending `NOTIFICATION_TRANSFORM_CHANGED`.
- `get_gizmos() -> Node3DGizmo[]` *const* — Returns all the EditorNode3DGizmo objects attached to this node.
- `get_global_transform_interpolated() -> Transform3D` — When using physics interpolation, there will be circumstances in which you want to know the interpolated (displayed) transform of a node rather than the standard transform (which may only be accurate to the most recent physics tick).
- `get_parent_node_3d() -> Node3D` *const* — Returns the parent Node3D that directly affects this node's `global_transform`.
- `get_world_3d() -> World3D` *const* — Returns the World3D this node is registered to.
- `global_rotate(axis: Vector3, angle: float) -> void` — Rotates this node's `global_basis` around the global `axis` by the given `angle`, in radians.
- `global_scale(scale: Vector3) -> void` — Scales this node's `global_basis` by the given `scale` factor.
- `global_translate(offset: Vector3) -> void` — Adds the given translation `offset` to the node's `global_position` in global space (relative to the world).
- `hide() -> void` — Prevents this node from being rendered.
- `is_local_transform_notification_enabled() -> bool` *const* — Returns `true` if the node receives `NOTIFICATION_LOCAL_TRANSFORM_CHANGED` whenever `transform` changes.
- `is_scale_disabled() -> bool` *const* — Returns `true` if this node's `global_transform` is automatically orthonormalized.
- `is_transform_notification_enabled() -> bool` *const* — Returns `true` if the node receives `NOTIFICATION_TRANSFORM_CHANGED` whenever `global_transform` changes.
- `is_visible_in_tree() -> bool` *const* — Returns `true` if this node is inside the scene tree and the `visible` property is `true` for this node and all of its Node3D ancestors in sequence.
- `look_at(target: Vector3, up: Vector3 = Vector3(0, 1, 0), use_model_front: bool = false) -> void` — Rotates the node so that the local forward axis (-Z, `Vector3.FORWARD`) points toward the `target` position.
- `look_at_from_position(position: Vector3, target: Vector3, up: Vector3 = Vector3(0, 1, 0), use_model_front: bool = false) -> void` — Moves the node to the specified `position`, then rotates the node to point toward the `target` position, similar to `look_at`.
- `orthonormalize() -> void` — Orthonormalizes this node's `basis`.
- `rotate(axis: Vector3, angle: float) -> void` — Rotates this node's `basis` around the `axis` by the given `angle`, in radians.
- `rotate_object_local(axis: Vector3, angle: float) -> void` — Rotates this node's `basis` around the `axis` by the given `angle`, in radians.
- `rotate_x(angle: float) -> void` — Rotates this node's `basis` around the X axis by the given `angle`, in radians.
- `rotate_y(angle: float) -> void` — Rotates this node's `basis` around the Y axis by the given `angle`, in radians.
- `rotate_z(angle: float) -> void` — Rotates this node's `basis` around the Z axis by the given `angle`, in radians.
- `scale_object_local(scale: Vector3) -> void` — Scales this node's `basis` by the given `scale` factor.
- `set_disable_scale(disable: bool) -> void` — If `true`, this node's `global_transform` is automatically orthonormalized.
- `set_identity() -> void` — Sets this node's `transform` to `Transform3D.IDENTITY`, which resets all transformations in parent space (`position`, `rotation`, and `scale`).
- `set_ignore_transform_notification(enabled: bool) -> void` — If `true`, the node will not receive `NOTIFICATION_TRANSFORM_CHANGED` or `NOTIFICATION_LOCAL_TRANSFORM_CHANGED`.
- `set_notify_local_transform(enable: bool) -> void` — If `true`, the node will receive `NOTIFICATION_LOCAL_TRANSFORM_CHANGED` whenever `transform` changes.
- `set_notify_transform(enable: bool) -> void` — If `true`, the node will receive `NOTIFICATION_TRANSFORM_CHANGED` whenever `global_transform` changes.
- `set_subgizmo_selection(gizmo: Node3DGizmo, id: int, transform: Transform3D) -> void` — Selects the `gizmo`'s subgizmo with the given `id` and sets its transform.
- `show() -> void` — Allows this node to be rendered.
- `to_global(local_point: Vector3) -> Vector3` *const* — Returns the `local_point` converted from this node's local space to global space.
- `to_local(global_point: Vector3) -> Vector3` *const* — Returns the `global_point` converted from global space to this node's local space.
- `translate(offset: Vector3) -> void` — Adds the given translation `offset` to the node's position, in local space (relative to this node).
- `translate_object_local(offset: Vector3) -> void` — Adds the given translation `offset` to the node's position, in local space (relative to this node).
- `update_gizmos() -> void` — Updates all the EditorNode3DGizmo objects attached to this node.

## Signals

- `visibility_changed()` — Emitted when this node's visibility changes (see `visible` and `is_visible_in_tree`).

## Enum RotationEditMode

- `ROTATION_EDIT_MODE_EULER = 0` — The rotation is edited using a Vector3 in Euler angles.
- `ROTATION_EDIT_MODE_QUATERNION = 1` — The rotation is edited using a Quaternion.
- `ROTATION_EDIT_MODE_BASIS = 2` — The rotation is edited using a Basis.

## Constants

- `NOTIFICATION_TRANSFORM_CHANGED = 2000` — Notification received when this node's `global_transform` changes, if `is_transform_notification_enabled` is `true`.
- `NOTIFICATION_ENTER_WORLD = 41` — Notification received when this node is registered to a new World3D (see `get_world_3d`).
- `NOTIFICATION_EXIT_WORLD = 42` — Notification received when this node is unregistered from the current World3D (see `get_world_3d`).
- `NOTIFICATION_VISIBILITY_CHANGED = 43` — Notification received when this node's visibility changes (see `visible` and `is_visible_in_tree`).
- `NOTIFICATION_LOCAL_TRANSFORM_CHANGED = 44` — Notification received when this node's `transform` changes, if `is_local_transform_notification_enabled` is `true`.
