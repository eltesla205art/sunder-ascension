# RDFramebufferPass

**Inherits:** RefCounted

Framebuffer pass attachment description (used by RenderingDevice).

This class contains the list of attachment descriptions for a framebuffer pass. Each points with an index to a previously supplied list of texture attachments. Multipass framebuffers can optimize some configurations in mobile. On desktop, they provide little to no advantage.

## Properties

- `color_attachments: PackedInt32Array` = `PackedInt32Array()` — Color attachments in order starting from 0.
- `depth_attachment: int` = `-1` — Depth attachment.
- `input_attachments: PackedInt32Array` = `PackedInt32Array()` — Used for multipass framebuffers (more than one render pass).
- `preserve_attachments: PackedInt32Array` = `PackedInt32Array()` — Attachments to preserve in this pass (otherwise they are erased).
- `resolve_attachments: PackedInt32Array` = `PackedInt32Array()` — If the color attachments are multisampled, non-multisampled resolve attachments can be provided.

## Constants

- `ATTACHMENT_UNUSED = -1` — Attachment is unused.
