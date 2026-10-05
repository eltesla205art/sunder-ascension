# FABRIK3D

**Inherits:** IterateIK3D

Position based forward and backward reaching inverse kinematics solver.

FABRIK3D is position based IK, allowing precise and accurate tracking of targets. It's ideal for simple chains without limitations. The resulting twist around the forward vector will always be kept from the previous pose. Note: When the target is close to the root, it tends to produce zig-zag patterns, resulting in unnatural visual movement.
