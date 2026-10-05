# OccluderInstance3D

**Inherits:** VisualInstance3D

Provides occlusion culling for 3D nodes, which improves performance in closed areas.

Occlusion culling can improve rendering performance in closed/semi-open areas by hiding geometry that is occluded by other objects. The occlusion culling system is mostly static. OccluderInstance3Ds can be moved or hidden at run-time, but doing so will trigger a background recomputation that can take several frames. It is recommended to only move OccluderInstance3Ds sporadically (e.g. for procedural generation purposes), rather than doing so every frame.

## Properties

- `bake_mask: int` = `4294967295` — The visual layers to account for when baking for occluders.
- `bake_simplification_distance: float` = `0.1` — The simplification distance to use for simplifying the generated occluder polygon (in 3D units).
- `occluder: Occluder3D` — The occluder resource for this OccluderInstance3D.

## Methods

- `get_bake_mask_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `bake_mask` is enabled, given a `layer_number` between 1 and 32.
- `set_bake_mask_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `bake_mask`, given a `layer_number` between 1 and 32.
