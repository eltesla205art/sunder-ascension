# RID


A handle for a Resource's unique identifier.

The RID Variant type is used to access a low-level resource by its unique ID. RIDs are opaque, which means they do not grant access to the resource by themselves. They are used by the low-level server classes, such as DisplayServer, RenderingServer, TextServer, etc. A low-level resource may correspond to a high-level Resource, such as Texture or Mesh.

## Constructors

- `RID() -> RID` — Constructs an empty RID with the invalid ID `0`.
- `RID(from: RID) -> RID` — Constructs an RID as a copy of the given RID.

## Methods

- `get_id() -> int` *const* — Returns the ID of the referenced low-level resource.
- `is_valid() -> bool` *const* — Returns `true` if the RID is not `0`.

## Operators

- `operator !=(right: RID) -> bool` — Returns `true` if the RIDs are not equal.
- `operator <(right: RID) -> bool` — Returns `true` if the RID's ID is less than `right`'s ID.
- `operator <=(right: RID) -> bool` — Returns `true` if the RID's ID is less than or equal to `right`'s ID.
- `operator ==(right: RID) -> bool` — Returns `true` if both RIDs are equal, which means they both refer to the same low-level resource.
- `operator >(right: RID) -> bool` — Returns `true` if the RID's ID is greater than `right`'s ID.
- `operator >=(right: RID) -> bool` — Returns `true` if the RID's ID is greater than or equal to `right`'s ID.
