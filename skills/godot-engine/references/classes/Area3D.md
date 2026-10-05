# Area3D

**Inherits:** CollisionObject3D

A region of 3D space that detects other CollisionObject3Ds entering or exiting it.

Area3D is a region of 3D space defined by one or multiple CollisionShape3D or CollisionPolygon3D child nodes. It detects when other CollisionObject3Ds enter or exit it, and it also keeps track of which collision objects haven't exited it yet (i.e. which one are overlapping it). This node can also locally alter or override physics parameters (gravity, damping) and route audio to custom audio buses. Note: Areas and bodies created with PhysicsServer3D might not interact as expected with Area3Ds, and might not emit signals or track objects correctly.

## Properties

- `angular_damp: float` = `0.1` — The rate at which objects stop spinning in this area.
- `angular_damp_space_override: Area3D.SpaceOverride` = `0` — Override mode for angular damping calculations within this area.
- `audio_bus_name: StringName` = `&"Master"` — The name of the area's audio bus.
- `audio_bus_override: bool` = `false` — If `true`, the area's audio bus overrides the default audio bus.
- `gravity: float` = `9.8` — The area's gravity intensity (in meters per second squared).
- `gravity_direction: Vector3` = `Vector3(0, -1, 0)` — The area's gravity vector (not normalized).
- `gravity_point: bool` = `false` — If `true`, gravity is calculated from a point (set via `gravity_point_center`).
- `gravity_point_center: Vector3` = `Vector3(0, -1, 0)` — If gravity is a point (see `gravity_point`), this will be the point of attraction.
- `gravity_point_unit_distance: float` = `0.0` — The distance at which the gravity strength is equal to `gravity`.
- `gravity_space_override: Area3D.SpaceOverride` = `0` — Override mode for gravity calculations within this area.
- `linear_damp: float` = `0.1` — The rate at which objects stop moving in this area.
- `linear_damp_space_override: Area3D.SpaceOverride` = `0` — Override mode for linear damping calculations within this area.
- `monitorable: bool` = `true` — If `true`, other monitoring areas can detect this area.
- `monitoring: bool` = `true` — If `true`, the area detects bodies or areas entering and exiting it.
- `priority: int` = `0` — The area's priority.
- `reverb_bus_amount: float` = `0.0` — The degree to which this area applies reverb to its associated audio.
- `reverb_bus_enabled: bool` = `false` — If `true`, the area applies reverb to its associated audio.
- `reverb_bus_name: StringName` = `&"Master"` — The name of the reverb bus to use for this area's associated audio.
- `reverb_bus_uniformity: float` = `0.0` — The degree to which this area's reverb is a uniform effect.
- `wind_attenuation_factor: float` = `0.0` — The exponential rate at which wind force decreases with distance from its origin.
- `wind_force_magnitude: float` = `0.0` — The magnitude of area-specific wind force.
- `wind_source_path: NodePath` = `NodePath("")` — The Node3D which is used to specify the direction and origin of an area-specific wind force.

## Methods

- `get_overlapping_areas() -> Area3D[]` *const* — Returns a list of intersecting Area3Ds.
- `get_overlapping_bodies() -> Node3D[]` *const* — Returns a list of intersecting PhysicsBody3Ds, SoftBody3Ds, and GridMaps.
- `has_overlapping_areas() -> bool` *const* — Returns `true` if intersecting any Area3Ds, otherwise returns `false`.
- `has_overlapping_bodies() -> bool` *const* — Returns `true` if intersecting any PhysicsBody3Ds, SoftBody3Ds, or GridMaps, otherwise returns `false`.
- `overlaps_area(area: Node) -> bool` *const* — Returns `true` if the given Area3D intersects or overlaps this Area3D, `false` otherwise.
- `overlaps_body(body: Node) -> bool` *const* — Returns `true` if the given physics body intersects or overlaps this Area3D, `false` otherwise.

## Signals

- `area_entered(area: Area3D)` — Emitted when the received `area` enters this area.
- `area_exited(area: Area3D)` — Emitted when the received `area` exits this area.
- `area_shape_entered(area_rid: RID, area: Area3D, area_shape_index: int, local_shape_index: int)` — Emitted when a Shape3D of the received `area` enters a shape of this area.
- `area_shape_exited(area_rid: RID, area: Area3D, area_shape_index: int, local_shape_index: int)` — Emitted when a Shape3D of the received `area` exits a shape of this area.
- `body_entered(body: Node3D)` — Emitted when the received `body` enters this area.
- `body_exited(body: Node3D)` — Emitted when the received `body` exits this area.
- `body_shape_entered(body_rid: RID, body: Node3D, body_shape_index: int, local_shape_index: int)` — Emitted when a Shape3D of the received `body` enters a shape of this area.
- `body_shape_exited(body_rid: RID, body: Node3D, body_shape_index: int, local_shape_index: int)` — Emitted when a Shape3D of the received `body` exits a shape of this area.

## Enum SpaceOverride

- `SPACE_OVERRIDE_DISABLED = 0` — This area does not affect gravity/damping.
- `SPACE_OVERRIDE_COMBINE = 1` — This area adds its gravity/damping values to whatever has been calculated so far (in `priority` order).
- `SPACE_OVERRIDE_COMBINE_REPLACE = 2` — This area adds its gravity/damping values to whatever has been calculated so far (in `priority` order), ignoring any lower priority areas.
- `SPACE_OVERRIDE_REPLACE = 3` — This area replaces any gravity/damping, even the defaults, ignoring any lower priority areas.
- `SPACE_OVERRIDE_REPLACE_COMBINE = 4` — This area replaces any gravity/damping calculated so far (in `priority` order), but keeps calculating the rest of the areas.
