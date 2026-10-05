# CollisionObject2D

**Inherits:** Node2D

Abstract base class for 2D physics objects.

Abstract base class for 2D physics objects. CollisionObject2D can hold any number of Shape2Ds for collision. Each shape must be assigned to a shape owner. Shape owners are not nodes and do not appear in the editor, but are accessible through code using the `shape_owner_*` methods.

## Properties

- `collision_layer: int` = `1` — The physics layers this CollisionObject2D is in.
- `collision_mask: int` = `1` — The physics layers this CollisionObject2D scans.
- `collision_priority: float` = `1.0` — The priority used to solve colliding when occurring penetration.
- `disable_mode: CollisionObject2D.DisableMode` = `0` — Defines the behavior in physics when `Node.process_mode` is set to `Node.PROCESS_MODE_DISABLED`.
- `input_pickable: bool` = `true` — If `true`, this object is pickable.

## Methods

- `_input_event(viewport: Viewport, event: InputEvent, shape_idx: int) -> void` *virtual* — Detects unhandled mouse and touch InputEvents through `event` when they happen while hovering over the object.
- `_mouse_enter() -> void` *virtual* — Called when the mouse pointer enters any of this object's shapes.
- `_mouse_exit() -> void` *virtual* — Called when the mouse pointer exits all this object's shapes.
- `_mouse_shape_enter(shape_idx: int) -> void` *virtual* — Called when the mouse pointer enters any of this object's shapes or moves from one shape to another.
- `_mouse_shape_exit(shape_idx: int) -> void` *virtual* — Called when the mouse pointer exits any of this object's shapes.
- `create_shape_owner(owner: Object) -> int` — Creates a new shape owner for the given object.
- `get_collision_layer_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `collision_layer` is enabled, given a `layer_number` between 1 and 32.
- `get_collision_mask_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `collision_mask` is enabled, given a `layer_number` between 1 and 32.
- `get_rid() -> RID` *const* — Returns the object's RID.
- `get_shape_owner_one_way_collision_direction(owner_id: int) -> Vector2` *const* — Returns the `one_way_collision_direction` of the shape owner identified by the given `owner_id`.
- `get_shape_owner_one_way_collision_margin(owner_id: int) -> float` *const* — Returns the `one_way_collision_margin` of the shape owner identified by given `owner_id`.
- `get_shape_owners() -> PackedInt32Array` — Returns an Array of `owner_id` identifiers.
- `is_shape_owner_disabled(owner_id: int) -> bool` *const* — If `true`, the shape owner and its shapes are disabled.
- `is_shape_owner_one_way_collision_enabled(owner_id: int) -> bool` *const* — Returns `true` if collisions for the shape owner originating from this CollisionObject2D will not be reported to collided with CollisionObject2Ds.
- `remove_shape_owner(owner_id: int) -> void` — Removes the given shape owner.
- `set_collision_layer_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `collision_layer`, given a `layer_number` between 1 and 32.
- `set_collision_mask_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `collision_mask`, given a `layer_number` between 1 and 32.
- `shape_find_owner(shape_index: int) -> int` *const* — Returns the `owner_id` of the given shape.
- `shape_owner_add_shape(owner_id: int, shape: Shape2D) -> void` — Adds a Shape2D to the shape owner.
- `shape_owner_clear_shapes(owner_id: int) -> void` — Removes all shapes from the shape owner.
- `shape_owner_get_owner(owner_id: int) -> Object` *const* — Returns the parent object of the given shape owner.
- `shape_owner_get_shape(owner_id: int, shape_id: int) -> Shape2D` *const* — Returns the Shape2D with the given ID from the given shape owner.
- `shape_owner_get_shape_count(owner_id: int) -> int` *const* — Returns the number of shapes the given shape owner contains.
- `shape_owner_get_shape_index(owner_id: int, shape_id: int) -> int` *const* — Returns the child index of the Shape2D with the given ID from the given shape owner.
- `shape_owner_get_transform(owner_id: int) -> Transform2D` *const* — Returns the shape owner's Transform2D.
- `shape_owner_remove_shape(owner_id: int, shape_id: int) -> void` — Removes a shape from the given shape owner.
- `shape_owner_set_disabled(owner_id: int, disabled: bool) -> void` — If `true`, disables the given shape owner.
- `shape_owner_set_one_way_collision(owner_id: int, enable: bool) -> void` — If `enable` is `true`, collisions for the shape owner originating from this CollisionObject2D will not be reported to collided with CollisionObject2Ds.
- `shape_owner_set_one_way_collision_direction(owner_id: int, direction: Vector2) -> void` — Sets the `one_way_collision_direction` of the shape owner identified by the given `owner_id` to `direction`.
- `shape_owner_set_one_way_collision_margin(owner_id: int, margin: float) -> void` — Sets the `one_way_collision_margin` of the shape owner identified by given `owner_id` to `margin` pixels.
- `shape_owner_set_transform(owner_id: int, transform: Transform2D) -> void` — Sets the Transform2D of the given shape owner.

## Signals

- `input_event(viewport: Node, event: InputEvent, shape_idx: int)` — Emitted when an unhandled input event occurs.
- `mouse_entered()` — Emitted when the mouse pointer enters any of this object's shapes.
- `mouse_exited()` — Emitted when the mouse pointer exits all this object's shapes.
- `mouse_shape_entered(shape_idx: int)` — Emitted when the mouse pointer enters any of this object's shapes or moves from one shape to another.
- `mouse_shape_exited(shape_idx: int)` — Emitted when the mouse pointer exits any of this object's shapes.

## Enum DisableMode

- `DISABLE_MODE_REMOVE = 0` — When `Node.process_mode` is set to `Node.PROCESS_MODE_DISABLED`, remove from the physics simulation to stop all physics interactions with this CollisionObject2D.
- `DISABLE_MODE_MAKE_STATIC = 1` — When `Node.process_mode` is set to `Node.PROCESS_MODE_DISABLED`, make the body static.
- `DISABLE_MODE_KEEP_ACTIVE = 2` — When `Node.process_mode` is set to `Node.PROCESS_MODE_DISABLED`, do not affect the physics simulation.
