extends Node
## AudioManager — background music system.
## Plays a looping heroic galaxy theme during stages, swaps to a tense boss
## theme when a boss appears, and fades between them.
##
## Drop your Suno tracks into assets/audio/ with these names and they play
## automatically — no code changes:
##   assets/audio/main_theme.ogg   (heroic galaxy stage music, looping)
##   assets/audio/boss_theme.ogg   (intense boss music, looping)
##   assets/audio/victory.ogg      (optional short victory sting)
## .ogg or .mp3 both work. If a file is missing, that cue is silently skipped.

var _music_player: AudioStreamPlayer
var _current: String = ""

const TRACKS := {
	"main": "res://assets/audio/main_theme.ogg",
	"boss": "res://assets/audio/boss_theme.ogg",
	"victory": "res://assets/audio/victory.ogg",
}
# fallbacks if you export mp3 instead of ogg
const ALT := {
	"main": "res://assets/audio/main_theme.mp3",
	"boss": "res://assets/audio/boss_theme.mp3",
	"victory": "res://assets/audio/victory.mp3",
}

func _ready() -> void:
	_music_player = AudioStreamPlayer.new()
	_music_player.bus = "Master"
	add_child(_music_player)

func play(track_key: String, fade_time: float = 0.8) -> void:
	if track_key == _current:
		return
	_current = track_key
	var stream := _load_stream(track_key)
	if stream == null:
		return  # file not added yet — silently skip
	if stream is AudioStreamOggVorbis:
		stream.loop = (track_key != "victory")
	# fade out old, swap, fade in
	if _music_player.playing:
		var t := create_tween()
		t.tween_property(_music_player, "volume_db", -40.0, fade_time * 0.5)
		await t.finished
	_music_player.stream = stream
	_music_player.volume_db = -40.0
	_music_player.play()
	var t2 := create_tween()
	t2.tween_property(_music_player, "volume_db", -6.0, fade_time)

func stop(fade_time: float = 0.6) -> void:
	_current = ""
	if not _music_player.playing:
		return
	var t := create_tween()
	t.tween_property(_music_player, "volume_db", -40.0, fade_time)
	await t.finished
	_music_player.stop()

func _load_stream(track_key: String) -> AudioStream:
	var path: String = TRACKS.get(track_key, "")
	if path != "" and ResourceLoader.exists(path):
		return load(path)
	var alt: String = ALT.get(track_key, "")
	if alt != "" and ResourceLoader.exists(alt):
		return load(alt)
	return null
