# GridContainer

**Inherits:** Container

A container that arranges its child controls in a grid layout.

GridContainer arranges its child controls in a grid layout. The number of columns is specified by the `columns` property, whereas the number of rows depends on how many are needed for the child controls. The number of rows and columns is preserved for every size of the container. Note: GridContainer only works with child nodes inheriting from Control.

## Properties

- `columns: int` = `1` — The number of columns in the GridContainer.

## Theme items

- `h_separation: int` (constant) = `4`
- `v_separation: int` (constant) = `4`
