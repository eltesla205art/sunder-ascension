extends Node2D
## Parallax star/energy field — the void beyond the Atlantean gate.

var stars: Array = []
var vp: Vector2

func _ready() -> void:
	vp = get_viewport_rect().size
	for i in range(90):
		stars.append({
			"pos": Vector2(randf() * vp.x, randf() * vp.y),
			"speed": randf_range(40, 220),
			"size": randf_range(1.0, 3.0),
			"gold": randf() < 0.3
		})

func _process(delta: float) -> void:
	for s in stars:
		s.pos.y += s.speed * delta
		if s.pos.y > vp.y:
			s.pos.y = 0
			s.pos.x = randf() * vp.x
	queue_redraw()

func _draw() -> void:
	for s in stars:
		var col = Color(0.83, 0.68, 0.21) if s.gold else Color(0.6, 0.75, 0.9)
		col.a = clamp(s.speed / 220.0, 0.25, 1.0)
		draw_circle(s.pos, s.size, col)
