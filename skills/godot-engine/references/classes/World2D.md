# World2D

**Inherits:** Resource

A resource that holds all components of a 2D world, such as a canvas and a physics space.

Class that has everything pertaining to a 2D world: A physics space, a canvas, and a sound space. 2D nodes register their resources into the current 2D world.

## Properties

- `canvas: RID` — The RID of this world's canvas resource.
- `direct_space_state: PhysicsDirectSpaceState2D` — Direct access to the world's physics 2D space state.
- `navigation_map: RID` — The RID of this world's navigation map.
- `space: RID` — The RID of this world's physics space resource.
