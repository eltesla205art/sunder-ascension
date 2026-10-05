# VehicleBody3D

**Inherits:** RigidBody3D

A 3D physics body that simulates the behavior of a car.

This physics body implements all the physics logic needed to simulate a car. It is based on the raycast vehicle system commonly found in physics engines. Aside from a CollisionShape3D for the main body of the vehicle, you must also add a VehicleWheel3D node for each wheel. You should also add a MeshInstance3D to this node for the 3D model of the vehicle, but this model should generally not include meshes for the wheels.

## Properties

- `brake: float` = `0.0` — Slows down the vehicle by applying a braking force.
- `engine_force: float` = `0.0` — Accelerates the vehicle by applying an engine force.
- `mass: float` = `40.0` — 
- `steering: float` = `0.0` — The steering angle for the vehicle.
