# WorldEnvironment

**Inherits:** Node

Default environment properties for the entire scene (post-processing effects, lighting and background settings).

The WorldEnvironment node is used to configure the default Environment for the scene. The parameters defined in the WorldEnvironment can be overridden by an Environment node set on the current Camera3D. Additionally, only one WorldEnvironment may be instantiated in a given scene at a time. The WorldEnvironment allows the user to specify default lighting parameters (e.g. ambient lighting), various post-processing effects (e.g.

## Properties

- `camera_attributes: CameraAttributes` — The default CameraAttributes resource to use if none set on the Camera3D.
- `compositor: Compositor` — The default Compositor resource to use if none set on the Camera3D.
- `environment: Environment` — The Environment resource used by this WorldEnvironment, defining the default properties.
