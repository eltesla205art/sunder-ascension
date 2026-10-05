# PhysicsServer3DRenderingServerHandler

**Inherits:** Object

A class used to provide `PhysicsServer3DExtension._soft_body_update_rendering_server` with a rendering handler for soft bodies.



## Methods

- `_set_aabb(aabb: AABB) -> void` *virtual required* — Called by the PhysicsServer3D to set the bounding box for the SoftBody3D.
- `_set_normal(vertex_id: int, normal: Vector3) -> void` *virtual required* — Called by the PhysicsServer3D to set the normal for the SoftBody3D vertex at the index specified by `vertex_id`.
- `_set_vertex(vertex_id: int, vertex: Vector3) -> void` *virtual required* — Called by the PhysicsServer3D to set the position for the SoftBody3D vertex at the index specified by `vertex_id`.
- `set_aabb(aabb: AABB) -> void` — Sets the bounding box for the SoftBody3D.
- `set_normal(vertex_id: int, normal: Vector3) -> void` — Sets the normal for the SoftBody3D vertex at the index specified by `vertex_id`.
- `set_vertex(vertex_id: int, vertex: Vector3) -> void` — Sets the position for the SoftBody3D vertex at the index specified by `vertex_id`.
