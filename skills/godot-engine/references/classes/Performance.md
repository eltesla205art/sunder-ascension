# Performance

**Inherits:** Object

Exposes performance-related data.

This class provides access to a number of different monitors related to performance, such as memory usage, draw calls, and FPS. These are the same as the values displayed in the Monitor tab in the editor's Debugger panel. By using the `get_monitor` method of this class, you can access this data from your code. You can add custom monitors using the `add_custom_monitor` method.

## Methods

- `add_custom_monitor(id: StringName, callable: Callable, arguments: Array = [], type: Performance.MonitorType = 0) -> void` — Adds a custom monitor with the name `id`.
- `get_custom_monitor(id: StringName) -> Variant` — Returns the value of custom monitor with given `id`.
- `get_custom_monitor_names() -> StringName[]` — Returns the names of active custom monitors in an Array.
- `get_custom_monitor_types() -> PackedInt32Array` — Returns the `MonitorType` values of active custom monitors in an Array.
- `get_monitor(monitor: Performance.Monitor) -> float` *const* — Returns the value of one of the available built-in monitors.
- `get_monitor_modification_time() -> int` — Returns the last tick in which custom monitor was added/removed (in microseconds since the engine started).
- `has_custom_monitor(id: StringName) -> bool` — Returns `true` if custom monitor with the given `id` is present, `false` otherwise.
- `remove_custom_monitor(id: StringName) -> void` — Removes the custom monitor with given `id`.

## Enum Monitor

- `TIME_FPS = 0` — The number of frames rendered in the last second.
- `TIME_PROCESS = 1` — Time it took to complete one frame, in seconds.
- `TIME_PHYSICS_PROCESS = 2` — Time it took to complete one physics frame, in seconds.
- `TIME_NAVIGATION_PROCESS = 3` — Time it took to complete one navigation step, in seconds.
- `MEMORY_STATIC = 4` — Static memory currently used, in bytes.
- `MEMORY_STATIC_MAX = 5` — Available static memory.
- `MEMORY_MESSAGE_BUFFER_MAX = 6` — Largest amount of memory the message queue buffer has used, in bytes.
- `OBJECT_COUNT = 7` — Number of objects currently instantiated (including nodes).
- `OBJECT_RESOURCE_COUNT = 8` — Number of resources currently used.
- `OBJECT_NODE_COUNT = 9` — Number of nodes currently instantiated in the scene tree.
- `OBJECT_ORPHAN_NODE_COUNT = 10` — Number of orphan nodes, i.e. nodes which are not parented to a node of the scene tree.
- `RENDER_TOTAL_OBJECTS_IN_FRAME = 11` — The total number of objects in the last rendered frame.
- `RENDER_TOTAL_PRIMITIVES_IN_FRAME = 12` — The total number of vertices or indices rendered in the last rendered frame.
- `RENDER_TOTAL_DRAW_CALLS_IN_FRAME = 13` — The total number of draw calls performed in the last rendered frame.
- `RENDER_VIDEO_MEM_USED = 14` — The amount of video memory used (texture and vertex memory combined, in bytes).
- `RENDER_TEXTURE_MEM_USED = 15` — The amount of texture memory used (in bytes).
- `RENDER_BUFFER_MEM_USED = 16` — The amount of render buffer memory used (in bytes).
- `PHYSICS_2D_ACTIVE_OBJECTS = 17` — Number of active RigidBody2D nodes in the game.
- `PHYSICS_2D_COLLISION_PAIRS = 18` — Number of collision pairs in the 2D physics engine.
- `PHYSICS_2D_ISLAND_COUNT = 19` — Number of islands in the 2D physics engine.
- `PHYSICS_3D_ACTIVE_OBJECTS = 20` — Number of active RigidBody3D and VehicleBody3D nodes in the game.
- `PHYSICS_3D_COLLISION_PAIRS = 21` — Number of collision pairs in the 3D physics engine.
- `PHYSICS_3D_ISLAND_COUNT = 22` — Number of islands in the 3D physics engine.
- `AUDIO_OUTPUT_LATENCY = 23` — Output latency of the AudioServer.
- `NAVIGATION_ACTIVE_MAPS = 24` — Number of active navigation maps in NavigationServer2D and NavigationServer3D.
- `NAVIGATION_REGION_COUNT = 25` — Number of active navigation regions in NavigationServer2D and NavigationServer3D.
- `NAVIGATION_AGENT_COUNT = 26` — Number of active navigation agents processing avoidance in NavigationServer2D and NavigationServer3D.
- `NAVIGATION_LINK_COUNT = 27` — Number of active navigation links in NavigationServer2D and NavigationServer3D.
- `NAVIGATION_POLYGON_COUNT = 28` — Number of navigation mesh polygons in NavigationServer2D and NavigationServer3D.
- `NAVIGATION_EDGE_COUNT = 29` — Number of navigation mesh polygon edges in NavigationServer2D and NavigationServer3D.
- `NAVIGATION_EDGE_MERGE_COUNT = 30` — Number of navigation mesh polygon edges that were merged due to edge key overlap in NavigationServer2D and NavigationServer3D.
- `NAVIGATION_EDGE_CONNECTION_COUNT = 31` — Number of polygon edges that are considered connected by edge proximity NavigationServer2D and NavigationServer3D.
- `NAVIGATION_EDGE_FREE_COUNT = 32` — Number of navigation mesh polygon edges that could not be merged in NavigationServer2D and NavigationServer3D.
- `NAVIGATION_OBSTACLE_COUNT = 33` — Number of active navigation obstacles in the NavigationServer2D and NavigationServer3D.
- `PIPELINE_COMPILATIONS_CANVAS = 34` — Number of pipeline compilations that were triggered by the 2D canvas renderer.
- `PIPELINE_COMPILATIONS_MESH = 35` — Number of pipeline compilations that were triggered by loading meshes.
- `PIPELINE_COMPILATIONS_SURFACE = 36` — Number of pipeline compilations that were triggered by building the surface cache before rendering the scene.
- `PIPELINE_COMPILATIONS_DRAW = 37` — Number of pipeline compilations that were triggered while drawing the scene.
- `PIPELINE_COMPILATIONS_SPECIALIZATION = 38` — Number of pipeline compilations that were triggered to optimize the current scene.
- `NAVIGATION_2D_ACTIVE_MAPS = 39` — Number of active navigation maps in the NavigationServer2D.
- `NAVIGATION_2D_REGION_COUNT = 40` — Number of active navigation regions in the NavigationServer2D.
- `NAVIGATION_2D_AGENT_COUNT = 41` — Number of active navigation agents processing avoidance in the NavigationServer2D.
- `NAVIGATION_2D_LINK_COUNT = 42` — Number of active navigation links in the NavigationServer2D.
- `NAVIGATION_2D_POLYGON_COUNT = 43` — Number of navigation mesh polygons in the NavigationServer2D.
- `NAVIGATION_2D_EDGE_COUNT = 44` — Number of navigation mesh polygon edges in the NavigationServer2D.
- `NAVIGATION_2D_EDGE_MERGE_COUNT = 45` — Number of navigation mesh polygon edges that were merged due to edge key overlap in the NavigationServer2D.
- `NAVIGATION_2D_EDGE_CONNECTION_COUNT = 46` — Number of polygon edges that are considered connected by edge proximity NavigationServer2D.
- `NAVIGATION_2D_EDGE_FREE_COUNT = 47` — Number of navigation mesh polygon edges that could not be merged in the NavigationServer2D.
- `NAVIGATION_2D_OBSTACLE_COUNT = 48` — Number of active navigation obstacles in the NavigationServer2D.
- `NAVIGATION_3D_ACTIVE_MAPS = 49` — Number of active navigation maps in the NavigationServer3D.
- `NAVIGATION_3D_REGION_COUNT = 50` — Number of active navigation regions in the NavigationServer3D.
- `NAVIGATION_3D_AGENT_COUNT = 51` — Number of active navigation agents processing avoidance in the NavigationServer3D.
- `NAVIGATION_3D_LINK_COUNT = 52` — Number of active navigation links in the NavigationServer3D.
- `NAVIGATION_3D_POLYGON_COUNT = 53` — Number of navigation mesh polygons in the NavigationServer3D.
- `NAVIGATION_3D_EDGE_COUNT = 54` — Number of navigation mesh polygon edges in the NavigationServer3D.
- `NAVIGATION_3D_EDGE_MERGE_COUNT = 55` — Number of navigation mesh polygon edges that were merged due to edge key overlap in the NavigationServer3D.
- `NAVIGATION_3D_EDGE_CONNECTION_COUNT = 56` — Number of polygon edges that are considered connected by edge proximity NavigationServer3D.
- `NAVIGATION_3D_EDGE_FREE_COUNT = 57` — Number of navigation mesh polygon edges that could not be merged in the NavigationServer3D.
- `NAVIGATION_3D_OBSTACLE_COUNT = 58` — Number of active navigation obstacles in the NavigationServer3D.
- `RENDER_STREAMING_TEXTURE_MEM_USED = 59` — The amount of memory used by texture streaming (in bytes).
- `MONITOR_MAX = 60` — Represents the size of the `Monitor` enum.

## Enum MonitorType

- `MONITOR_TYPE_QUANTITY = 0` — Monitor output is formatted as an integer value.
- `MONITOR_TYPE_MEMORY = 1` — Monitor output is formatted as computer memory.
- `MONITOR_TYPE_TIME = 2` — Monitor output is formatted as time in milliseconds.
- `MONITOR_TYPE_PERCENTAGE = 3` — Monitor output is formatted as a percentage.
