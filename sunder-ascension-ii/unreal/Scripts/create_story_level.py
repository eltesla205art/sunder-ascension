"""SUNDER: Ascension II — story mode: the story screens and the hour map, with the web game's words and sound.

Run inside the Unreal Editor (Tools → Execute Python Script…) LAST, after create_keepers.py, create_stage_audio.py and
create_menu_level.py, with the C++ in unreal/Source compiled (SunderStoryGameMode, SunderStoryData,
SunderStorySubsystem).

Reads:
  unreal/Content/Story/story.json   the web game's words (unreal/Tools/export_story_text.cjs): the opening crawl, each
                                    Hour's name, act, Keeper, briefing and gate-open line, the act interludes, the dawn
                                    ending and DAWN DENIED
  unreal/Content/Audio/Story        web/story_audio.js rendered by unreal/Tools/render_web_audio.cjs story:
                                    Music/MUS_Story_Opening|Map|Briefing|Interlude|Victory|Defeat_L1..3,
                                    Ambience/AMB_Story_Opening|Map, Cues/SFX_Story_Begin|Map|Gate|Briefing|Interlude|Dawn|Denied
  art/blender/stages, art/blender/keepers   each Hour's backdrop and its Keeper's portrait, for the briefings

Does:
  1. imports the sound into /Game/Sunder/Audio/Story and the art into /Game/Sunder/UI/Stages and /Keepers;
  2. makes DA_StoryAudio_Opening and DA_StoryAudio_Map (theme + ambience);
  3. makes DA_StoryData: the words, the twelve Hours (each with its DA_StageAudio_*, BP_Keeper_*, DA_Waves_HourNN_*
     from create_hour_waves.py, backdrop, portrait), DA_TestWaves for any Hour without its own waves, and the story
     screens' music and cues;
  4. makes BP_SunderStoryGameMode and the level L_SunderStory;
  5. points the hangar's Story mode at it (BP_SunderMenuGameMode → Story Level, Story Data).

Then: title → hangar → Story → the crawl → the hour map → a briefing → the arena flies that Hour (its waves, its
Keeper, its sound) → Hour survived / DAWN DENIED → … → dawn. Safe to run again. Untested until its first run.
"""
import json
import os

import unreal

SOURCE_DIR = None   # None = the repo layout next to this script

AUDIO_ROOT = "/Game/Sunder/Audio/Story"
MUSIC_DIR = AUDIO_ROOT + "/Music"
AMB_DIR = AUDIO_ROOT + "/Ambience"
CUE_DIR = AUDIO_ROOT + "/Cues"
STAGE_AUDIO_DIR = "/Game/Sunder/Audio/Stages"
UI_DIR = "/Game/Sunder/UI"
STAGE_ART_DIR = UI_DIR + "/Stages"
PORTRAIT_DIR = UI_DIR + "/Keepers"
BP_DIR = "/Game/Sunder/Blueprints"
KEEPER_DIR = BP_DIR + "/Keepers"
WAVE_DIR = "/Game/Sunder/Waves"
MAP_DIR = "/Game/Sunder/Maps"
MAP_PATH = MAP_DIR + "/L_SunderStory"
STORY_DATA = AUDIO_ROOT + "/DA_StoryData"
THEMES = ["Opening", "Map", "Briefing", "Interlude", "Victory", "Defeat"]
CUES = ["Begin", "Map", "Gate", "Briefing", "Interlude", "Dawn", "Denied"]

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []


def log(msg):
    unreal.log("[SunderStory] " + msg)


def step(label, fn, *args):
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:   # the editor's Python API differs a little between versions
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderStory] {} failed: {}".format(label, exc))
        return None


def repo_path(*parts):
    here = os.path.dirname(os.path.abspath(__file__))
    return os.path.normpath(os.path.join(SOURCE_DIR or os.path.join(here, ".."), *parts))


def camel(text):
    return "".join(part.capitalize() for part in text.split("_"))


def color(hex_rgb):
    """sRGB hex → linear colour (the HUD converts back to sRGB when it draws)."""
    rgb = [int(hex_rgb[i:i + 2], 16) / 255.0 for i in (1, 3, 5)]
    lin = [c / 12.92 if c <= 0.04045 else ((c + 0.055) / 1.055) ** 2.4 for c in rgb]
    return unreal.LinearColor(lin[0], lin[1], lin[2], 1.0)


def asset(path, name):
    full = "{}/{}".format(path, name)
    return EAL.load_asset(full) if EAL.does_asset_exist(full) else None


# ------------------------------------------------------------------ 1. import
def import_files(files, dest):
    """files: (source path, asset name) pairs."""
    tasks = []
    for source, asset_name in files:
        if not os.path.isfile(source):
            raise RuntimeError("not found: " + source)
        task = unreal.AssetImportTask()
        task.set_editor_property("filename", source)
        task.set_editor_property("destination_path", dest)
        task.set_editor_property("destination_name", asset_name)
        task.set_editor_property("automated", True)
        task.set_editor_property("replace_existing", True)
        task.set_editor_property("save", True)
        tasks.append(task)
    TOOLS.import_asset_tasks(tasks)
    names = [n for _, n in files]
    missing = [n for n in names if not EAL.does_asset_exist("{}/{}".format(dest, n))]
    if missing:
        raise RuntimeError("{} of {} didn't import, e.g. {}".format(len(missing), len(names), missing[0]))
    return names


def import_audio(sub, dest):
    folder = repo_path("Content", "Audio", "Story", sub)
    if not os.path.isdir(folder):
        raise RuntimeError("not found: {} (run node unreal/Tools/render_web_audio.cjs story)".format(folder))
    files = [(os.path.join(folder, n), os.path.splitext(n)[0]) for n in sorted(os.listdir(folder)) if n.lower().endswith(".wav")]
    names = import_files(files, dest)
    log("imported {} sounds into {}".format(len(names), dest))
    return names


def set_loop_settings(path, names, in_step):
    for name in names:
        wave = asset(path, name)
        if wave is None:
            continue
        wave.set_editor_property("looping", True)
        if in_step:   # a silent layer must keep playing, or it restarts out of step when it fades back in
            try:
                wave.set_editor_property("virtualization_mode", unreal.VirtualizationMode.PLAY_WHEN_SILENT)
            except Exception as exc:
                MANUAL.append("{}: set Virtualization Mode = Play When Silent  ({})".format(name, exc))
            try:
                wave.set_editor_property("sound_group", unreal.SoundGroup.SOUNDGROUP_MUSIC)
            except Exception:
                pass
        EAL.save_loaded_asset(wave)


def ui_texture(tex, name):
    for prop, value in (("lod_group", unreal.TextureGroup.TEXTUREGROUP_UI),
                        ("mip_gen_settings", unreal.TextureMipGenSettings.TMGS_NO_MIPMAPS),
                        ("compression_settings", unreal.TextureCompressionSettings.TC_EDITOR_ICON),
                        ("never_stream", True)):
        try:
            tex.set_editor_property(prop, value)
        except Exception as exc:
            MANUAL.append("{}: set {} for UI  ({})".format(name, prop, exc))
    EAL.save_loaded_asset(tex)


def import_art(story):
    stages = repo_path("..", "art", "blender", "stages")
    keepers = repo_path("..", "art", "blender", "keepers")
    stage_files = [(os.path.join(stages, "stage_{}.png".format(h["stage"])), "T_Stage_" + camel(h["stage"])) for h in story["hours"]]
    portrait_files = [(os.path.join(keepers, "keeper_{}_portrait.png".format(h["keeper_id"])), "T_Portrait_" + camel(h["keeper_id"]))
                      for h in story["hours"]]
    import_files(stage_files, STAGE_ART_DIR)
    import_files(portrait_files, PORTRAIT_DIR)
    for path, files in ((STAGE_ART_DIR, stage_files), (PORTRAIT_DIR, portrait_files)):
        for _, name in files:
            ui_texture(asset(path, name), name)
    if asset(UI_DIR, "T_TitleBackdrop") is None:          # create_menu_level.py imports it; import it here if not
        import_files([(repo_path("..", "art", "blender", "title_bg.png"), "T_TitleBackdrop")], UI_DIR)
        ui_texture(asset(UI_DIR, "T_TitleBackdrop"), "T_TitleBackdrop")


# ------------------------------------------------------------------ 2–3. data
def data_asset(path, name, cls):
    full = "{}/{}".format(path, name)
    if EAL.does_asset_exist(full):
        return EAL.load_asset(full)
    factory = unreal.DataAssetFactory()
    factory.set_editor_property("data_asset_class", cls)
    data = TOOLS.create_asset(name, path, cls, factory)
    if data is None:
        raise RuntimeError("could not create " + full)
    return data


def layers(theme):
    found = [asset(MUSIC_DIR, "MUS_Story_{}_L{}".format(theme, n)) for n in (1, 2, 3)]
    if any(s is None for s in found):
        raise RuntimeError("missing a layer of MUS_Story_" + theme)
    return found


def build_screen_audio(screen):
    data = data_asset(AUDIO_ROOT, "DA_StoryAudio_" + screen, unreal.SunderStageAudio)
    data.set_editor_property("stage_name", screen)
    data.set_editor_property("music_layers", layers(screen))
    ambience = asset(AMB_DIR, "AMB_Story_" + screen)
    if ambience is not None:
        data.set_editor_property("ambience", ambience)
    EAL.save_loaded_asset(data)
    return data


def build_hour(h):
    hour = unreal.SunderStoryHour()
    for prop, key in (("name", "name"), ("subtitle", "subtitle"), ("keeper_name", "keeper"), ("quote", "quote"),
                      ("brief", "brief"), ("clear_line", "clear"), ("interlude", "interlude")):
        hour.set_editor_property(prop, h[key])
    hour.set_editor_property("tint", color(h["tint"]))
    stage_audio = asset(STAGE_AUDIO_DIR, "DA_StageAudio_" + camel(h["stage"]))
    if stage_audio is not None:
        hour.set_editor_property("stage_audio", stage_audio)
    else:
        MANUAL.append("Hour {}: no DA_StageAudio_{} (run create_stage_audio.py, then this again)".format(h["num"], camel(h["stage"])))
    keeper_bp = "{}/BP_Keeper_{}".format(KEEPER_DIR, camel(h["keeper_id"]))
    if EAL.does_asset_exist(keeper_bp):
        hour.set_editor_property("keeper", EAL.load_blueprint_class(keeper_bp))
    else:
        MANUAL.append("Hour {}: no {} (run create_keepers.py, then this again)".format(h["num"], keeper_bp))
    waves = asset(WAVE_DIR + "/Hours", "DA_Waves_Hour{:02d}_{}".format(h["num"], camel(h["stage"])))
    if waves is not None:                                     # create_hour_waves.py; it fills these in if run later
        hour.set_editor_property("waves", waves)
    backdrop = asset(STAGE_ART_DIR, "T_Stage_" + camel(h["stage"]))
    if backdrop is not None:
        hour.set_editor_property("backdrop", backdrop)
    portrait = asset(PORTRAIT_DIR, "T_Portrait_" + camel(h["keeper_id"]))
    if portrait is not None:
        hour.set_editor_property("keeper_portrait", portrait)
    return hour


def build_story_data(story, screens):
    data = data_asset(AUDIO_ROOT, "DA_StoryData", unreal.SunderStoryData)
    data.set_editor_property("opening", story["opening"])
    data.set_editor_property("victory", story["victory"])
    data.set_editor_property("defeat_tag", story["defeat"])
    data.set_editor_property("hours", [build_hour(h) for h in story["hours"]])
    waves = asset(WAVE_DIR, "DA_TestWaves")
    if waves is not None:
        data.set_editor_property("enemy_waves", waves)
    else:
        MANUAL.append("DA_StoryData: set Enemy Waves (run create_enemies_and_waves.py)")
    backdrop = asset(UI_DIR, "T_TitleBackdrop")
    if backdrop is not None:
        data.set_editor_property("map_backdrop", backdrop)
    if screens.get("Opening") is not None:
        data.set_editor_property("opening_audio", screens["Opening"])
    if screens.get("Map") is not None:
        data.set_editor_property("map_audio", screens["Map"])
    for theme in ("Briefing", "Interlude", "Victory", "Defeat"):
        data.set_editor_property(theme.lower() + "_music", layers(theme))
    for cue in CUES:
        s = asset(CUE_DIR, "SFX_Story_" + cue)
        if s is not None:
            data.set_editor_property(cue.lower() + "_sound", s)
        else:
            MANUAL.append("DA_StoryData: no SFX_Story_" + cue)
    EAL.save_loaded_asset(data)
    return data


# ------------------------------------------------------------------ 4–5. game mode, level, hangar
def blueprint(name, parent):
    full = "{}/{}".format(BP_DIR, name)
    if EAL.does_asset_exist(full):
        bp = EAL.load_asset(full)
    else:
        factory = unreal.BlueprintFactory()
        factory.set_editor_property("parent_class", parent)
        bp = TOOLS.create_asset(name, BP_DIR, unreal.Blueprint, factory)
        if bp is None:
            raise RuntimeError("could not create " + full)
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    cls = EAL.load_blueprint_class(full)
    return bp, cls, unreal.get_default_object(cls)


def build_story_mode(story_data):
    bp, cls, cdo = blueprint("BP_SunderStoryGameMode", unreal.SunderStoryGameMode)
    cdo.set_editor_property("story_data", story_data)
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    EAL.save_loaded_asset(bp)
    return cls


def build_level(mode_class):
    levels = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
    if EAL.does_asset_exist(MAP_PATH):
        if not levels.load_level(MAP_PATH):
            raise RuntimeError("could not open " + MAP_PATH)
    elif not levels.new_level(MAP_PATH):
        raise RuntimeError("could not create " + MAP_PATH)
    world = unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem).get_editor_world()
    world.get_world_settings().set_editor_property("default_game_mode", mode_class)
    levels.save_current_level()


def hook_hangar(story_data):
    full = BP_DIR + "/BP_SunderMenuGameMode"
    if not EAL.does_asset_exist(full):
        raise RuntimeError(full + " not found; run create_menu_level.py first")
    bp = EAL.load_asset(full)
    cdo = unreal.get_default_object(EAL.load_blueprint_class(full))
    cdo.set_editor_property("story_level", "L_SunderStory")
    cdo.set_editor_property("story_data", story_data)
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    EAL.save_loaded_asset(bp)


def main():
    missing = [n for n in ("SunderStoryGameMode", "SunderStoryData", "SunderStoryHour", "SunderStageAudio")
               if not hasattr(unreal, n)]
    if missing:
        unreal.log_error("[SunderStory] C++ types not found: {}. Compile unreal/Source first.".format(", ".join(missing)))
        return
    story_file = repo_path("Content", "Story", "story.json")
    if not os.path.isfile(story_file):
        unreal.log_error("[SunderStory] not found: {} (run node unreal/Tools/export_story_text.cjs)".format(story_file))
        return
    with open(story_file, encoding="utf-8") as f:
        story = json.load(f)
    for path in (AUDIO_ROOT, MUSIC_DIR, AMB_DIR, CUE_DIR, UI_DIR, STAGE_ART_DIR, PORTRAIT_DIR, BP_DIR, MAP_DIR):
        EAL.make_directory(path)

    music = step("import the story music (18 loops)", import_audio, "Music", MUSIC_DIR)
    ambience = step("import the story ambience (2 loops)", import_audio, "Ambience", AMB_DIR)
    step("import the story cues (7)", import_audio, "Cues", CUE_DIR)
    if music:
        step("music: loop, play when silent, Music group", set_loop_settings, MUSIC_DIR, music, True)
    if ambience:
        step("ambience: loop", set_loop_settings, AMB_DIR, ambience, False)
    step("stage backdrops and Keeper portraits → /Game/Sunder/UI", import_art, story)

    screens = {s: step("DA_StoryAudio_" + s, build_screen_audio, s) for s in ("Opening", "Map")}
    data = step("DA_StoryData ({} Hours)".format(len(story["hours"])), build_story_data, story, screens)
    if data is not None:
        mode = step("BP_SunderStoryGameMode", build_story_mode, data)
        if mode is not None:
            step("L_SunderStory", build_level, mode)
        step("BP_SunderMenuGameMode: Story mode → L_SunderStory", hook_hangar, data)

    if not any(asset(WAVE_DIR + "/Hours", "DA_Waves_Hour{:02d}_{}".format(h["num"], camel(h["stage"]))) for h in story["hours"]):
        MANUAL.append("Run create_hour_waves.py for each Hour's own waves (until then every Hour flies DA_TestWaves)")
    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)
    log("Play L_SunderTitle → Space → Story → Space: the crawl, then the hour map.")


main()
