# VehicleWheel3D

**Inherits:** Node3D

A 3D physics body for a VehicleBody3D that simulates the behavior of a wheel.

A node used as a child of a VehicleBody3D parent to simulate the behavior of one of its wheels. This node also acts as a collider to detect if the wheel is touching a surface. Note: This class has known issues and isn't designed to provide realistic 3D vehicle physics. If you want advanced vehicle physics, you may need to write your own physics integration using another PhysicsBody3D class.

## Properties

- `brake: float` = `0.0` — Slows down the wheel by applying a braking force.
- `damping_compression: float` = `0.83` — The damping applied to the suspension spring when being compressed, meaning when the wheel is moving up relative to the vehicle.
- `damping_relaxation: float` = `0.88` — The damping applied to the suspension spring when rebounding or extending, meaning when the wheel is moving down relative to the vehicle.
- `engine_force: float` = `0.0` — Accelerates the wheel by applying an engine force.
- `physics_interpolation_mode: Node.PhysicsInterpolationMode` = `2` — 
- `steering: float` = `0.0` — The steering angle for the wheel, in radians.
- `suspension_max_force: float` = `6000.0` — The maximum force the spring can resist.
- `suspension_stiffness: float` = `5.88` — The stiffness of the suspension, measured in Newtons per millimeter (N/mm), or megagrams per second squared (Mg/s²).
- `suspension_travel: float` = `0.2` — This is the distance the suspension can travel.
- `use_as_steering: bool` = `false` — If `true`, this wheel will be turned when the car steers.
- `use_as_traction: bool` = `false` — If `true`, this wheel transfers engine force to the ground to propel the vehicle forward.
- `wheel_friction_slip: float` = `10.5` — This determines how much grip this wheel has.
- `wheel_radius: float` = `0.5` — The radius of the wheel in meters.
- `wheel_rest_length: float` = `0.15` — This is the distance in meters the wheel is lowered from its origin point.
- `wheel_roll_influence: float` = `0.1` — This value affects the roll of your vehicle.

## Methods

- `get_contact_body() -> Node3D` *const* — Returns the contacting body node if valid in the tree, as Node3D.
- `get_contact_normal() -> Vector3` *const* — Returns the normal of the suspension's collision in world space if the wheel is in contact.
- `get_contact_point() -> Vector3` *const* — Returns the point of the suspension's collision in world space if the wheel is in contact.
- `get_rpm() -> float` *const* — Returns the rotational speed of the wheel in revolutions per minute.
- `get_skidinfo() -> float` *const* — Returns a value between 0.0 and 1.0 that indicates whether this wheel is skidding. 0.0 is skidding (the wheel has lost grip, e.g. icy terrain), 1.0 means not skidding (the wheel has full grip, e.g. dry asphalt road).
- `is_in_contact() -> bool` *const* — Returns `true` if this wheel is in contact with a surface.
