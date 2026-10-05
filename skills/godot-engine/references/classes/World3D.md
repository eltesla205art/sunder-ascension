# World3D

**Inherits:** Resource

A resource that holds all components of a 3D world, such as a visual scenario and a physics space.

Class that has everything pertaining to a world: A physics space, a visual scenario, and a sound space. 3D nodes register their resources into the current 3D world.

## Properties

- `camera_attributes: CameraAttributes` — The default CameraAttributes resource to use if none set on the Camera3D.
- `direct_space_state: PhysicsDirectSpaceState3D` — Direct access to the world's physics 3D space state.
- `environment: Environment` — The World3D's Environment.
- `fallback_environment: Environment` — The World3D's fallback environment will be used if `environment` fails or is missing.
- `navigation_map: RID` — The RID of this world's navigation map.
- `scenario: RID` — The World3D's visual scenario.
- `space: RID` — The World3D's physics space.
