# CollisionObject3D

**Inherits:** Node3D

Abstract base class for 3D physics objects.

Abstract base class for 3D physics objects. CollisionObject3D can hold any number of Shape3Ds for collision. Each shape must be assigned to a shape owner. Shape owners are not nodes and do not appear in the editor, but are accessible through code using the `shape_owner_*` methods.

## Properties

- `collision_layer: int` = `1` — The physics layers this CollisionObject3D is in.
- `collision_mask: int` = `1` — The physics layers this CollisionObject3D scans.
- `collision_priority: float` = `1.0` — The priority used to solve colliding when occurring penetration.
- `disable_mode: CollisionObject3D.DisableMode` = `0` — Defines the behavior in physics when `Node.process_mode` is set to `Node.PROCESS_MODE_DISABLED`.
- `input_capture_on_drag: bool` = `false` — If `true`, the CollisionObject3D will continue to receive input events as the mouse is dragged across its shapes.
- `input_ray_pickable: bool` = `true` — If `true`, this object is pickable.

## Methods

- `_input_event(camera: Camera3D, event: InputEvent, event_position: Vector3, normal: Vector3, shape_idx: int) -> void` *virtual* — Detects unhandled mouse and touch InputEvents through `event` when they happen while hovering over the object.
- `_mouse_enter() -> void` *virtual* — Called when the mouse pointer enters any of this object's shapes.
- `_mouse_exit() -> void` *virtual* — Called when the mouse pointer exits all this object's shapes.
- `create_shape_owner(owner: Object) -> int` — Creates a new shape owner for the given object.
- `get_collision_layer_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `collision_layer` is enabled, given a `layer_number` between 1 and 32.
- `get_collision_mask_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `collision_mask` is enabled, given a `layer_number` between 1 and 32.
- `get_rid() -> RID` *const* — Returns the object's RID.
- `get_shape_owners() -> PackedInt32Array` — Returns an Array of `owner_id` identifiers.
- `is_shape_owner_disabled(owner_id: int) -> bool` *const* — If `true`, the shape owner and its shapes are disabled.
- `remove_shape_owner(owner_id: int) -> void` — Removes the given shape owner.
- `set_collision_layer_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `collision_layer`, given a `layer_number` between 1 and 32.
- `set_collision_mask_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `collision_mask`, given a `layer_number` between 1 and 32.
- `shape_find_owner(shape_index: int) -> int` *const* — Returns the `owner_id` of the given shape.
- `shape_owner_add_shape(owner_id: int, shape: Shape3D) -> void` — Adds a Shape3D to the shape owner.
- `shape_owner_clear_shapes(owner_id: int) -> void` — Removes all shapes from the shape owner.
- `shape_owner_get_owner(owner_id: int) -> Object` *const* — Returns the parent object of the given shape owner.
- `shape_owner_get_shape(owner_id: int, shape_id: int) -> Shape3D` *const* — Returns the Shape3D with the given ID from the given shape owner.
- `shape_owner_get_shape_count(owner_id: int) -> int` *const* — Returns the number of shapes the given shape owner contains.
- `shape_owner_get_shape_index(owner_id: int, shape_id: int) -> int` *const* — Returns the child index of the Shape3D with the given ID from the given shape owner.
- `shape_owner_get_transform(owner_id: int) -> Transform3D` *const* — Returns the shape owner's Transform3D.
- `shape_owner_remove_shape(owner_id: int, shape_id: int) -> void` — Removes a shape from the given shape owner.
- `shape_owner_set_disabled(owner_id: int, disabled: bool) -> void` — If `true`, disables the given shape owner.
- `shape_owner_set_transform(owner_id: int, transform: Transform3D) -> void` — Sets the Transform3D of the given shape owner.

## Signals

- `input_event(camera: Node, event: InputEvent, event_position: Vector3, normal: Vector3, shape_idx: int)` — Emitted when an unhandled input event occurs.
- `mouse_entered()` — Emitted when the mouse pointer enters any of this object's shapes.
- `mouse_exited()` — Emitted when the mouse pointer exits all this object's shapes.

## Enum DisableMode

- `DISABLE_MODE_REMOVE = 0` — When `Node.process_mode` is set to `Node.PROCESS_MODE_DISABLED`, remove from the physics simulation to stop all physics interactions with this CollisionObject3D.
- `DISABLE_MODE_MAKE_STATIC = 1` — When `Node.process_mode` is set to `Node.PROCESS_MODE_DISABLED`, make the body static.
- `DISABLE_MODE_KEEP_ACTIVE = 2` — When `Node.process_mode` is set to `Node.PROCESS_MODE_DISABLED`, do not affect the physics simulation.
