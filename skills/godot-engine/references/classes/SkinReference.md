# SkinReference

**Inherits:** RefCounted

A reference-counted holder object for a skeleton RID used in the RenderingServer.

An internal object containing a mapping from a Skin used within the context of a particular MeshInstance3D to refer to the skeleton's RID in the RenderingServer. See also `MeshInstance3D.get_skin_reference` and `RenderingServer.instance_attach_skeleton`. Note that despite the similar naming, the skeleton RID used in the RenderingServer does not have a direct one-to-one correspondence to a Skeleton3D node. In particular, a Skeleton3D node with no MeshInstance3D children may be unknown to the RenderingServer.

## Methods

- `get_skeleton() -> RID` *const* — Returns the RID owned by this SkinReference, as returned by `RenderingServer.skeleton_create`.
- `get_skin() -> Skin` *const* — Returns the Skin connected to this SkinReference.
