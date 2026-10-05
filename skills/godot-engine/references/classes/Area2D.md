# Area2D

**Inherits:** CollisionObject2D

A region of 2D space that detects other CollisionObject2Ds entering or exiting it.

Area2D is a region of 2D space defined by one or multiple CollisionShape2D or CollisionPolygon2D child nodes. It detects when other CollisionObject2Ds enter or exit it, and it also keeps track of which collision objects haven't exited it yet (i.e. which one are overlapping it). This node can also locally alter or override physics parameters (gravity, damping) and route audio to custom audio buses. Note: Areas and bodies created with PhysicsServer2D might not interact as expected with Area2Ds, and might not emit signals or track objects correctly.

## Properties

- `angular_damp: float` = `1.0` — The rate at which objects stop spinning in this area.
- `angular_damp_space_override: Area2D.SpaceOverride` = `0` — Override mode for angular damping calculations within this area.
- `audio_bus_name: StringName` = `&"Master"` — The name of the area's audio bus.
- `audio_bus_override: bool` = `false` — If `true`, the area's audio bus overrides the default audio bus.
- `gravity: float` = `980.0` — The area's gravity intensity (in pixels per second squared).
- `gravity_direction: Vector2` = `Vector2(0, 1)` — The area's gravity vector (not normalized).
- `gravity_point: bool` = `false` — If `true`, gravity is calculated from a point (set via `gravity_point_center`).
- `gravity_point_center: Vector2` = `Vector2(0, 1)` — If gravity is a point (see `gravity_point`), this will be the point of attraction.
- `gravity_point_unit_distance: float` = `0.0` — The distance at which the gravity strength is equal to `gravity`.
- `gravity_space_override: Area2D.SpaceOverride` = `0` — Override mode for gravity calculations within this area.
- `linear_damp: float` = `0.1` — The rate at which objects stop moving in this area.
- `linear_damp_space_override: Area2D.SpaceOverride` = `0` — Override mode for linear damping calculations within this area.
- `monitorable: bool` = `true` — If `true`, other monitoring areas can detect this area.
- `monitoring: bool` = `true` — If `true`, the area detects bodies or areas entering and exiting it.
- `priority: int` = `0` — The area's priority.

## Methods

- `get_overlapping_areas() -> Area2D[]` *const* — Returns a list of intersecting Area2Ds.
- `get_overlapping_bodies() -> Node2D[]` *const* — Returns a list of intersecting PhysicsBody2Ds and TileMaps.
- `has_overlapping_areas() -> bool` *const* — Returns `true` if intersecting any Area2Ds, otherwise returns `false`.
- `has_overlapping_bodies() -> bool` *const* — Returns `true` if intersecting any PhysicsBody2Ds or TileMaps, otherwise returns `false`.
- `overlaps_area(area: Node) -> bool` *const* — Returns `true` if the given Area2D intersects or overlaps this Area2D, `false` otherwise.
- `overlaps_body(body: Node) -> bool` *const* — Returns `true` if the given physics body intersects or overlaps this Area2D, `false` otherwise.

## Signals

- `area_entered(area: Area2D)` — Emitted when the received `area` enters this area.
- `area_exited(area: Area2D)` — Emitted when the received `area` exits this area.
- `area_shape_entered(area_rid: RID, area: Area2D, area_shape_index: int, local_shape_index: int)` — Emitted when a Shape2D of the received `area` enters a shape of this area.
- `area_shape_exited(area_rid: RID, area: Area2D, area_shape_index: int, local_shape_index: int)` — Emitted when a Shape2D of the received `area` exits a shape of this area.
- `body_entered(body: Node2D)` — Emitted when the received `body` enters this area.
- `body_exited(body: Node2D)` — Emitted when the received `body` exits this area.
- `body_shape_entered(body_rid: RID, body: Node2D, body_shape_index: int, local_shape_index: int)` — Emitted when a Shape2D of the received `body` enters a shape of this area.
- `body_shape_exited(body_rid: RID, body: Node2D, body_shape_index: int, local_shape_index: int)` — Emitted when a Shape2D of the received `body` exits a shape of this area.

## Enum SpaceOverride

- `SPACE_OVERRIDE_DISABLED = 0` — This area does not affect gravity/damping.
- `SPACE_OVERRIDE_COMBINE = 1` — This area adds its gravity/damping values to whatever has been calculated so far (in `priority` order).
- `SPACE_OVERRIDE_COMBINE_REPLACE = 2` — This area adds its gravity/damping values to whatever has been calculated so far (in `priority` order), ignoring any lower priority areas.
- `SPACE_OVERRIDE_REPLACE = 3` — This area replaces any gravity/damping, even the defaults, ignoring any lower priority areas.
- `SPACE_OVERRIDE_REPLACE_COMBINE = 4` — This area replaces any gravity/damping calculated so far (in `priority` order), but keeps calculating the rest of the areas.
