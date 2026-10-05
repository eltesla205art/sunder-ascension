# CharacterBody3D

**Inherits:** PhysicsBody3D

A 3D physics body specialized for characters moved by script.

CharacterBody3D is a specialized class for physics bodies that are meant to be user-controlled. They are not affected by physics at all, but they affect other physics bodies in their path. They are mainly used to provide high-level API to move objects with wall and slope detection (`move_and_slide` method) in addition to the general collision detection provided by `PhysicsBody3D.move_and_collide`. This makes it useful for highly configurable physics bodies that must move in specific ways and collide with the world, as is often the case with user-controlled characters.

## Properties

- `floor_block_on_wall: bool` = `true` — If `true`, the body will be able to move on the floor only.
- `floor_constant_speed: bool` = `false` — If `false` (by default), the body will move faster on downward slopes and slower on upward slopes.
- `floor_max_angle: float` = `0.7853982` — Maximum angle (in radians) where a slope is still considered a floor (or a ceiling), rather than a wall, when calling `move_and_slide`.
- `floor_snap_length: float` = `0.1` — Sets a snapping distance.
- `floor_stop_on_slope: bool` = `true` — If `true`, the body will not slide on slopes when calling `move_and_slide` when the body is standing still.
- `max_slides: int` = `6` — Maximum number of times the body can change direction before it stops when calling `move_and_slide`.
- `motion_mode: CharacterBody3D.MotionMode` = `0` — Sets the motion mode which defines the behavior of `move_and_slide`.
- `platform_floor_layers: int` = `4294967295` — Collision layers that will be included for detecting floor bodies that will act as moving platforms to be followed by the CharacterBody3D.
- `platform_on_leave: CharacterBody3D.PlatformOnLeave` = `0` — Sets the behavior to apply when you leave a moving platform.
- `platform_wall_layers: int` = `0` — Collision layers that will be included for detecting wall bodies that will act as moving platforms to be followed by the CharacterBody3D.
- `safe_margin: float` = `0.001` — Extra margin used for collision recovery when calling `move_and_slide`.
- `slide_on_ceiling: bool` = `true` — If `true`, during a jump against the ceiling, the body will slide, if `false` it will be stopped and will fall vertically.
- `up_direction: Vector3` = `Vector3(0, 1, 0)` — Vector pointing upwards, used to determine what is a wall and what is a floor (or a ceiling) when calling `move_and_slide`.
- `velocity: Vector3` = `Vector3(0, 0, 0)` — Current velocity vector (typically meters per second), used and modified during calls to `move_and_slide`.
- `wall_min_slide_angle: float` = `0.2617994` — Minimum angle (in radians) where the body is allowed to slide when it encounters a wall.

## Methods

- `apply_floor_snap() -> void` — Allows to manually apply a snap to the floor regardless of the body's velocity.
- `get_floor_angle(up_direction: Vector3 = Vector3(0, 1, 0)) -> float` *const* — Returns the floor's collision angle at the last collision point according to `up_direction`, which is `Vector3.UP` by default.
- `get_floor_normal() -> Vector3` *const* — Returns the collision normal of the floor at the last collision point.
- `get_last_motion() -> Vector3` *const* — Returns the last motion applied to the CharacterBody3D during the last call to `move_and_slide`.
- `get_last_slide_collision() -> KinematicCollision3D` — Returns a KinematicCollision3D if a collision occurred.
- `get_platform_angular_velocity() -> Vector3` *const* — Returns the angular velocity of the platform at the last collision point.
- `get_platform_velocity() -> Vector3` *const* — Returns the linear velocity of the platform at the last collision point.
- `get_position_delta() -> Vector3` *const* — Returns the travel (position delta) that occurred during the last call to `move_and_slide`.
- `get_real_velocity() -> Vector3` *const* — Returns the current real velocity since the last call to `move_and_slide`.
- `get_slide_collision(slide_idx: int) -> KinematicCollision3D` — Returns a KinematicCollision3D, which contains information about a collision that occurred during the last call to `move_and_slide`.
- `get_slide_collision_count() -> int` *const* — Returns the number of times the body collided and changed direction during the last call to `move_and_slide`.
- `get_wall_normal() -> Vector3` *const* — Returns the collision normal of the wall at the last collision point.
- `is_on_ceiling() -> bool` *const* — Returns `true` if the body collided with the ceiling on the last call of `move_and_slide`.
- `is_on_ceiling_only() -> bool` *const* — Returns `true` if the body collided only with the ceiling on the last call of `move_and_slide`.
- `is_on_floor() -> bool` *const* — Returns `true` if the body collided with the floor on the last call of `move_and_slide`.
- `is_on_floor_only() -> bool` *const* — Returns `true` if the body collided only with the floor on the last call of `move_and_slide`.
- `is_on_wall() -> bool` *const* — Returns `true` if the body collided with a wall on the last call of `move_and_slide`.
- `is_on_wall_only() -> bool` *const* — Returns `true` if the body collided only with a wall on the last call of `move_and_slide`.
- `move_and_slide() -> bool` — Moves the body based on `velocity`.

## Enum MotionMode

- `MOTION_MODE_GROUNDED = 0` — Apply when notions of walls, ceiling and floor are relevant.
- `MOTION_MODE_FLOATING = 1` — Apply when there is no notion of floor or ceiling.

## Enum PlatformOnLeave

- `PLATFORM_ON_LEAVE_ADD_VELOCITY = 0` — Add the last platform velocity to the `velocity` when you leave a moving platform.
- `PLATFORM_ON_LEAVE_ADD_UPWARD_VELOCITY = 1` — Add the last platform velocity to the `velocity` when you leave a moving platform, but any downward motion is ignored.
- `PLATFORM_ON_LEAVE_DO_NOTHING = 2` — Do nothing when leaving a platform.
