# TextServerDummy

**Inherits:** TextServerExtension

A dummy text server that can't render text or manage fonts.

A dummy TextServer interface that doesn't do anything. Useful for freeing up memory when rendering text is not needed, as text servers are resource-intensive. It can also be used for performance comparisons in complex GUIs to check the impact of text rendering. A dummy text server is always available at the start of a project.
