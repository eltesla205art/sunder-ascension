# AnimationNodeSync

**Inherits:** AnimationNode

Base class for AnimationNodes with multiple input ports that must be synchronized.

An animation node used to combine, mix, or blend two or more animations together while keeping them synchronized within an AnimationTree.

## Properties

- `sync: bool` = `false` — If `false`, the blended animations' frame are stopped when the blend value is `0`.
