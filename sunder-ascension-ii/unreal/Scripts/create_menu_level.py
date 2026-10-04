"""SUNDER: Ascension II — the title screen and hangar level, with the web game's menu sound.

Run inside the Unreal Editor (Tools → Execute Python Script…) AFTER create_arena_level.py, with the C++ in
unreal/Source compiled (SunderMenuGameMode, SunderStageAudio, SunderMusicSubsystem).

The sounds are the web game's own (web/menu_audio.js), rendered to WAV by unreal/Tools/render_web_audio.cjs into
unreal/Content/Audio/Menus:
  Music/     MUS_Menu_Title_L1..3 (the hero's theme, slow and wide), MUS_Menu_Hangar_L1..3 (a working groove)
  Ambience/  AMB_Menu_Title (wind at the crystal gate, the portal's hum, embers), AMB_Menu_Hangar (machinery, vents,
             clanks, the base PA): 24 s seamless loops
  Cues/      SFX_Menu_Title_Start, SFX_Menu_Hangar_Move/Mode/Back/Launch, SFX_Ship_Sunborn/Scarab/Ibis_Rev
             (and SFX_Menu_Title_Leaderboard, imported for later: the Unreal build has no leaderboard yet)

Does:
  1. imports them into /Game/Sunder/Audio/Menus, and the title art and ship sprites (art/blender) into /Game/Sunder/UI;
  2. makes DA_MenuAudio_Title and DA_MenuAudio_Hangar (theme + ambience for each screen);
  3. makes BP_SunderMenuGameMode with the sounds, the three ships and the backdrop;
  4. makes the level L_SunderTitle using it;
  5. (RETURN_TO_TITLE) sets BP_SunderGameMode to go back to the title after DAWN DENIED.

Open L_SunderTitle and press Play: Space / Enter to start, A / D to change ship, W / S Story or Swarm, Space to
launch into L_SunderArena, Esc back to the title. Safe to run again. Untested until its first run.
"""
import os

import unreal

RETURN_TO_TITLE = True
SOURCE_DIR = None   # None = the repo layout next to this script (../Content/Audio/Menus and ../../art/blender)

AUDIO_ROOT = "/Game/Sunder/Audio/Menus"
MUSIC_DIR = AUDIO_ROOT + "/Music"
AMB_DIR = AUDIO_ROOT + "/Ambience"
CUE_DIR = AUDIO_ROOT + "/Cues"
UI_DIR = "/Game/Sunder/UI"
BP_DIR = "/Game/Sunder/Blueprints"
MAP_DIR = "/Game/Sunder/Maps"
MAP_PATH = MAP_DIR + "/L_SunderTitle"

# The web game's three ships (web/game.html SHIPS): id, name, class, colour.
SHIPS = [
    ("sunborn", "SUNBORN THUNDER", "The Balanced Heir", "#E6C252"),
    ("scarab", "SCARAB WARBRINGER", "The Juggernaut", "#D94033"),
    ("ibis", "IBIS PHANTOM", "The Swift", "#4DD980"),
]

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []


def log(msg):
    unreal.log("[SunderMenu] " + msg)


def step(label, fn, *args):
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:   # the editor's Python API differs a little between versions
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderMenu] {} failed: {}".format(label, exc))
        return None


def repo_path(*parts):
    here = os.path.dirname(os.path.abspath(__file__))
    return os.path.normpath(os.path.join(SOURCE_DIR or os.path.join(here, ".."), *parts))


def color(hex_rgb):
    """sRGB hex → linear colour (the HUD converts back to sRGB when it draws)."""
    rgb = [int(hex_rgb[i:i + 2], 16) / 255.0 for i in (1, 3, 5)]
    lin = [c / 12.92 if c <= 0.04045 else ((c + 0.055) / 1.055) ** 2.4 for c in rgb]
    return unreal.LinearColor(lin[0], lin[1], lin[2], 1.0)


# ------------------------------------------------------------------ 1. import
def import_files(files, dest):
    """files: source paths, or (source path, asset name) pairs."""
    files = [f if isinstance(f, tuple) else (f, os.path.splitext(os.path.basename(f))[0]) for f in files]
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
    names = [asset_name for _, asset_name in files]
    missing = [n for n in names if not EAL.does_asset_exist("{}/{}".format(dest, n))]
    if missing:
        raise RuntimeError("{} of {} didn't import, e.g. {}".format(len(missing), len(names), missing[0]))
    return names


def import_audio(sub, dest):
    folder = repo_path("Content", "Audio", "Menus", sub)
    if not os.path.isdir(folder):
        raise RuntimeError("not found: {} (run node unreal/Tools/render_web_audio.cjs menus)".format(folder))
    files = [os.path.join(folder, n) for n in sorted(os.listdir(folder)) if n.lower().endswith(".wav")]
    names = import_files(files, dest)
    log("imported {} sounds into {}".format(len(names), dest))
    return names


def import_art():
    art = repo_path("..", "art", "blender")
    renamed = {"title_bg": "T_TitleBackdrop", "ship_sunborn": "T_Ship_Sunborn", "ship_scarab": "T_Ship_Scarab",
               "ship_ibis": "T_Ship_Ibis"}
    import_files([(os.path.join(art, k + ".png"), v) for k, v in renamed.items()], UI_DIR)
    textures = {}
    for new in renamed.values():
        tex = EAL.load_asset("{}/{}".format(UI_DIR, new))
        for prop, value in (("lod_group", unreal.TextureGroup.TEXTUREGROUP_UI),
                            ("mip_gen_settings", unreal.TextureMipGenSettings.TMGS_NO_MIPMAPS),
                            ("compression_settings", unreal.TextureCompressionSettings.TC_EDITOR_ICON),
                            ("never_stream", True)):
            try:
                tex.set_editor_property(prop, value)
            except Exception as exc:
                MANUAL.append("{}: set {} for UI  ({})".format(new, prop, exc))
        EAL.save_loaded_asset(tex)
        textures[new] = tex
    return textures


def sound(path, name):
    full = "{}/{}".format(path, name)
    return EAL.load_asset(full) if EAL.does_asset_exist(full) else None


def set_loop_settings(path, names, in_step):
    for name in names:
        wave = sound(path, name)
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


# ------------------------------------------------------------------ 2. the screens' sound
def build_screen_audio(screen):
    name = "DA_MenuAudio_" + screen
    full = "{}/{}".format(AUDIO_ROOT, name)
    if EAL.does_asset_exist(full):
        data = EAL.load_asset(full)
    else:
        factory = unreal.DataAssetFactory()
        factory.set_editor_property("data_asset_class", unreal.SunderStageAudio)
        data = TOOLS.create_asset(name, AUDIO_ROOT, unreal.SunderStageAudio, factory)
        if data is None:
            raise RuntimeError("could not create " + full)
    layers = [sound(MUSIC_DIR, "MUS_Menu_{}_L{}".format(screen, n)) for n in (1, 2, 3)]
    if any(s is None for s in layers):
        raise RuntimeError("missing a layer of MUS_Menu_" + screen)
    data.set_editor_property("stage_name", screen)
    data.set_editor_property("music_layers", layers)
    ambience = sound(AMB_DIR, "AMB_Menu_" + screen)
    if ambience is not None:
        data.set_editor_property("ambience", ambience)
    EAL.save_loaded_asset(data)
    return data


# ------------------------------------------------------------------ 3–5. game modes and the level
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


def build_menu_mode(screens, textures):
    bp, cls, cdo = blueprint("BP_SunderMenuGameMode", unreal.SunderMenuGameMode)
    if screens.get("Title") is not None:
        cdo.set_editor_property("title_audio", screens["Title"])
    if screens.get("Hangar") is not None:
        cdo.set_editor_property("hangar_audio", screens["Hangar"])
    for prop, name in (("start_sound", "SFX_Menu_Title_Start"), ("move_sound", "SFX_Menu_Hangar_Move"),
                       ("mode_sound", "SFX_Menu_Hangar_Mode"), ("back_sound", "SFX_Menu_Hangar_Back"),
                       ("launch_sound", "SFX_Menu_Hangar_Launch")):
        s = sound(CUE_DIR, name)
        if s is not None:
            cdo.set_editor_property(prop, s)
        else:
            MANUAL.append("BP_SunderMenuGameMode: no {}".format(name))
    ships = []
    for sid, title, ship_class, tint in SHIPS:
        ship = unreal.SunderMenuShip()
        ship.set_editor_property("id", sid)
        ship.set_editor_property("name", title)
        ship.set_editor_property("ship_class", ship_class)
        ship.set_editor_property("tint", color(tint))
        sprite = textures.get("T_Ship_" + sid.capitalize())
        if sprite is not None:
            ship.set_editor_property("sprite", sprite)
        rev = sound(CUE_DIR, "SFX_Ship_{}_Rev".format(sid.capitalize()))
        if rev is not None:
            ship.set_editor_property("rev_sound", rev)
        ships.append(ship)
    cdo.set_editor_property("ships", ships)
    if textures.get("T_TitleBackdrop") is not None:
        cdo.set_editor_property("backdrop", textures["T_TitleBackdrop"])
    cdo.set_editor_property("arena_level", "L_SunderArena")
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


def return_to_title():
    full = BP_DIR + "/BP_SunderGameMode"
    if not EAL.does_asset_exist(full):
        raise RuntimeError(full + " not found; run create_arena_level.py first")
    bp = EAL.load_asset(full)
    unreal.get_default_object(EAL.load_blueprint_class(full)).set_editor_property("menu_level", "L_SunderTitle")
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    EAL.save_loaded_asset(bp)


def main():
    missing = [n for n in ("SunderMenuGameMode", "SunderStageAudio", "SunderMusicSubsystem") if not hasattr(unreal, n)]
    if missing:
        unreal.log_error("[SunderMenu] C++ types not found: {}. Compile unreal/Source first.".format(", ".join(missing)))
        return
    for path in (AUDIO_ROOT, MUSIC_DIR, AMB_DIR, CUE_DIR, UI_DIR, BP_DIR, MAP_DIR):
        EAL.make_directory(path)

    music = step("import the menu music (6 loops)", import_audio, "Music", MUSIC_DIR)
    ambience = step("import the menu ambience (2 loops)", import_audio, "Ambience", AMB_DIR)
    step("import the menu cues and ship engines (9)", import_audio, "Cues", CUE_DIR)
    if music:
        step("music: loop, play when silent, Music group", set_loop_settings, MUSIC_DIR, music, True)
    if ambience:
        step("ambience: loop", set_loop_settings, AMB_DIR, ambience, False)
    textures = step("title art and ship sprites → /Game/Sunder/UI", import_art) or {}

    screens = {s: step("DA_MenuAudio_" + s, build_screen_audio, s) for s in ("Title", "Hangar")}
    mode = step("BP_SunderMenuGameMode", build_menu_mode, screens, textures)
    if mode is not None:
        step("L_SunderTitle", build_level, mode)
    if RETURN_TO_TITLE:
        step("BP_SunderGameMode: back to the title after DAWN DENIED", return_to_title)

    MANUAL.extend([
        "Project Settings → Maps & Modes: Game Default Map (and Editor Startup Map) = L_SunderTitle",
        "The arena doesn't read ?Ship= / ?Mode= yet: every launch flies BP_SunderShip",
    ])
    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)
    log("Open L_SunderTitle and press Play: Space start · A/D ship · W/S mode · Space launch · Esc back.")


main()
