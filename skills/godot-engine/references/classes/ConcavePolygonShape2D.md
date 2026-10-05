# ConcavePolygonShape2D

**Inherits:** Shape2D

A 2D polyline shape used for physics collision.

A 2D polyline shape, intended for use in physics. Used internally in CollisionPolygon2D when it's in `CollisionPolygon2D.BUILD_SEGMENTS` mode. Being just a collection of interconnected line segments, ConcavePolygonShape2D is the most freely configurable single 2D shape. It can be used to form polygons of any nature, or even shapes that don't enclose an area.

## Properties

- `segments: PackedVector2Array` = `PackedVector2Array()` — The array of points that make up the ConcavePolygonShape2D's line segments.
