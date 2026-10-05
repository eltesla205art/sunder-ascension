# XRFaceModifier3D

**Inherits:** Node3D

A node for driving standard face meshes from XRFaceTracker weights.

This node applies weights from an XRFaceTracker to a mesh with supporting face blend shapes. The Unified Expressions blend shapes are supported, as well as ARKit and SRanipal blend shapes. The node attempts to identify blend shapes based on name matching. Blend shapes should match the names listed in the Unified Expressions Compatibility chart.

## Properties

- `face_tracker: StringName` = `&"/user/face_tracker"` — The XRFaceTracker path.
- `target: NodePath` = `NodePath("")` — The NodePath of the face MeshInstance3D.
