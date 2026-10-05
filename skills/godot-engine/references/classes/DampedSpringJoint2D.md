# DampedSpringJoint2D

**Inherits:** Joint2D

A physics joint that connects two 2D physics bodies with a spring-like force.

A physics joint that connects two 2D physics bodies with a spring-like force. This behaves like a spring that always wants to stretch to a given length.

## Properties

- `damping: float` = `1.0` — The spring joint's damping ratio.
- `length: float` = `50.0` — The spring joint's maximum length.
- `rest_length: float` = `0.0` — When the bodies attached to the spring joint move they stretch or squash it.
- `stiffness: float` = `20.0` — The higher the value, the less the bodies attached to the joint will deform it.
