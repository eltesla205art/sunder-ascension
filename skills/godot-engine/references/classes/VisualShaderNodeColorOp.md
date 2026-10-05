# VisualShaderNodeColorOp

**Inherits:** VisualShaderNode

A Color operator to be used within the visual shader graph.

Applies `operator` to two color inputs.

## Properties

- `operator: VisualShaderNodeColorOp.Operator` = `0` — An operator to be applied to the inputs.

## Enum Operator

- `OP_SCREEN = 0` — Produce a screen effect with the following formula:
- `OP_DIFFERENCE = 1` — Produce a difference effect with the following formula:
- `OP_DARKEN = 2` — Produce a darken effect with the following formula:
- `OP_LIGHTEN = 3` — Produce a lighten effect with the following formula:
- `OP_OVERLAY = 4` — Produce an overlay effect with the following formula:
- `OP_DODGE = 5` — Produce a dodge effect with the following formula:
- `OP_BURN = 6` — Produce a burn effect with the following formula:
- `OP_SOFT_LIGHT = 7` — Produce a soft light effect with the following formula:
- `OP_HARD_LIGHT = 8` — Produce a hard light effect with the following formula:
- `OP_MAX = 9` — Represents the size of the `Operator` enum.
