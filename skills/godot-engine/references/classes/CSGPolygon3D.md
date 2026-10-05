# CSGPolygon3D

**Inherits:** CSGPrimitive3D

Extrudes a 2D polygon shape to create a 3D mesh.

An array of 2D points is extruded to quickly and easily create a variety of 3D meshes. See also CSGMesh3D for using 3D meshes as CSG nodes. Note: CSG nodes are intended to be used for level prototyping. Creating CSG nodes has a significant CPU cost compared to creating a MeshInstance3D with a PrimitiveMesh.

## Properties

- `depth: float` = `1.0` — When `mode` is `MODE_DEPTH`, the depth of the extrusion.
- `material: Material` — Material to use for the resulting mesh.
- `mode: CSGPolygon3D.Mode` = `0` — The `mode` used to extrude the `polygon`.
- `path_continuous_u: bool` — When `mode` is `MODE_PATH`, by default, the top half of the `material` is stretched along the entire length of the extruded shape.
- `path_interval: float` — When `mode` is `MODE_PATH`, the path interval or ratio of path points to extrusions.
- `path_interval_type: CSGPolygon3D.PathIntervalType` — When `mode` is `MODE_PATH`, this will determine if the interval should be by distance (`PATH_INTERVAL_DISTANCE`) or subdivision fractions (`PATH_INTERVAL_SUBDIVIDE`).
- `path_joined: bool` — When `mode` is `MODE_PATH`, if `true` the ends of the path are joined, by adding an extrusion between the last and first points of the path.
- `path_local: bool` — When `mode` is `MODE_PATH`, if `true` the Transform3D of the CSGPolygon3D is used as the starting point for the extrusions, not the Transform3D of the `path_node`.
- `path_node: NodePath` — When `mode` is `MODE_PATH`, the location of the Path3D object used to extrude the `polygon`.
- `path_rotation: CSGPolygon3D.PathRotation` — When `mode` is `MODE_PATH`, the path rotation method used to rotate the `polygon` as it is extruded.
- `path_rotation_accurate: bool` — When `mode` is `MODE_PATH`, if `true` the polygon will be rotated according to the proper tangent of the path at the sampled points.
- `path_simplify_angle: float` — When `mode` is `MODE_PATH`, extrusions that are less than this angle, will be merged together to reduce polygon count.
- `path_u_distance: float` — When `mode` is `MODE_PATH`, this is the distance along the path, in meters, the texture coordinates will tile.
- `polygon: PackedVector2Array` = `PackedVector2Array(0, 0, 0, 1, 1, 1, 1, 0)` — The point array that defines the 2D polygon that is extruded.
- `smooth_faces: bool` = `false` — If `true`, applies smooth shading to the extrusions.
- `spin_degrees: float` — When `mode` is `MODE_SPIN`, the total number of degrees the `polygon` is rotated when extruding.
- `spin_sides: int` — When `mode` is `MODE_SPIN`, the number of extrusions made.

## Enum Mode

- `MODE_DEPTH = 0` — The `polygon` shape is extruded along the negative Z axis.
- `MODE_SPIN = 1` — The `polygon` shape is extruded by rotating it around the Y axis.
- `MODE_PATH = 2` — The `polygon` shape is extruded along the Path3D specified in `path_node`.

## Enum PathRotation

- `PATH_ROTATION_POLYGON = 0` — The `polygon` shape is not rotated.
- `PATH_ROTATION_PATH = 1` — The `polygon` shape is rotated along the path, but it is not rotated around the path axis.
- `PATH_ROTATION_PATH_FOLLOW = 2` — The `polygon` shape follows the path and its rotations around the path axis.

## Enum PathIntervalType

- `PATH_INTERVAL_DISTANCE = 0` — When `mode` is set to `MODE_PATH`, `path_interval` will determine the distance, in meters, each interval of the path will extrude.
- `PATH_INTERVAL_SUBDIVIDE = 1` — When `mode` is set to `MODE_PATH`, `path_interval` will subdivide the polygons along the path.
