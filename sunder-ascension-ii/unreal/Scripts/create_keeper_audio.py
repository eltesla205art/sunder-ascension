"""SUNDER: Ascension II — import the Keepers' music and voices and set them on the twelve Keeper Blueprints.

Run inside the Unreal Editor (Tools → Execute Python Script…) AFTER create_keepers.py, with the C++ in unreal/Source
compiled (it needs SunderKeeper's audio properties and SunderMusicSubsystem).

The sounds are the web game's own (web/keeper_audio.js), rendered to WAV by unreal/Tools/render_web_audio.cjs into
unreal/Content/Audio/Keepers:
  Music/   MUS_Keeper_<Name>_L1/L2/L3.wav: each Keeper's battle theme in three layers (held back / full / doubled),
           seamless same-length loops that the music subsystem plays in step and crossfades with the Keeper's phase;
           MUS_Keeper_ApepP3_*: Apep's final-form theme
  Voices/  SFX_Keeper_<Name>_Intro/Attack/Phase/Hurt/Death.wav

Does:
  1. imports them into /Game/Sunder/Audio/Keepers/Music and /Voices;
  2. sets the music to loop, to keep playing while silent (so the quiet layers stay in step) and to the Music group;
  3. sets MusicLayers, the five voices, and (Apep) FinalFormMusicLayers on every BP_Keeper_*.

Safe to run again. Untested until its first run.
"""
import os

import unreal

AUDIO_SOURCE_DIR = None   # None = ../Content/Audio/Keepers next to this script; set a path if you moved the script

MUSIC_DIR = "/Game/Sunder/Audio/Keepers/Music"
VOICE_DIR = "/Game/Sunder/Audio/Keepers/Voices"
KEEPER_DIR = "/Game/Sunder/Blueprints/Keepers"

KEEPERS = ["wepwawet", "sobek", "umbra", "nun", "sokar", "seraphs", "umbra_coiled", "hittite", "ammit",
           "overlord_echo", "umbra_unmasked", "apep"]
CUES = ["Intro", "Attack", "Phase", "Hurt", "Death"]

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []


def log(msg):
    unreal.log("[SunderKeeperAudio] " + msg)


def step(label, fn, *args):
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:   # the editor's Python API differs a little between versions
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderKeeperAudio] {} failed: {}".format(label, exc))
        return None


def camel(kid):
    return "".join(part.capitalize() for part in kid.split("_"))


def source_dir():
    if AUDIO_SOURCE_DIR:
        return AUDIO_SOURCE_DIR
    here = os.path.dirname(os.path.abspath(__file__))
    return os.path.normpath(os.path.join(here, "..", "Content", "Audio", "Keepers"))


# ------------------------------------------------------------------ 1. import
def import_folder(sub, dest):
    folder = os.path.join(source_dir(), sub)
    if not os.path.isdir(folder):
        raise RuntimeError("not found: {} (run node unreal/Tools/render_web_audio.cjs keepers)".format(folder))
    tasks = []
    for name in sorted(os.listdir(folder)):
        if not name.lower().endswith(".wav"):
            continue
        task = unreal.AssetImportTask()
        task.set_editor_property("filename", os.path.join(folder, name))
        task.set_editor_property("destination_path", dest)
        task.set_editor_property("destination_name", os.path.splitext(name)[0])
        task.set_editor_property("automated", True)
        task.set_editor_property("replace_existing", True)
        task.set_editor_property("save", True)
        tasks.append(task)
    if not tasks:
        raise RuntimeError("no .wav files in " + folder)
    TOOLS.import_asset_tasks(tasks)
    names = [os.path.splitext(os.path.basename(t.get_editor_property("filename")))[0] for t in tasks]
    missing = [n for n in names if not EAL.does_asset_exist("{}/{}".format(dest, n))]
    if missing:
        raise RuntimeError("{} of {} didn't import, e.g. {}".format(len(missing), len(names), missing[0]))
    log("imported {} sounds into {}".format(len(names), dest))
    return names


def sound(path, name):
    full = "{}/{}".format(path, name)
    return EAL.load_asset(full) if EAL.does_asset_exist(full) else None


# ------------------------------------------------------------------ 2. music settings
def set_music_settings(names):
    for name in names:
        wave = sound(MUSIC_DIR, name)
        if wave is None:
            continue
        wave.set_editor_property("looping", True)
        try:   # a silent layer must keep playing, or it restarts out of step when it fades back in
            wave.set_editor_property("virtualization_mode", unreal.VirtualizationMode.PLAY_WHEN_SILENT)
        except Exception as exc:
            MANUAL.append("{}: set Virtualization Mode = Play When Silent  ({})".format(name, exc))
        try:
            wave.set_editor_property("sound_group", unreal.SoundGroup.SOUNDGROUP_MUSIC)
        except Exception:
            pass
        EAL.save_loaded_asset(wave)


# ------------------------------------------------------------------ 3. the Keepers
def layers(theme):
    found = [sound(MUSIC_DIR, "MUS_Keeper_{}_L{}".format(theme, n)) for n in (1, 2, 3)]
    if any(s is None for s in found):
        raise RuntimeError("missing a layer of MUS_Keeper_" + theme)
    return found


def wire_keeper(kid):
    full = "{}/BP_Keeper_{}".format(KEEPER_DIR, camel(kid))
    if not EAL.does_asset_exist(full):
        raise RuntimeError(full + " not found; run create_keepers.py first")
    bp = EAL.load_asset(full)
    cdo = unreal.get_default_object(EAL.load_blueprint_class(full))
    cdo.set_editor_property("music_layers", layers(camel(kid)))
    if kid == "apep":
        cdo.set_editor_property("final_form_music_layers", layers("ApepP3"))
    for cue in CUES:
        s = sound(VOICE_DIR, "SFX_Keeper_{}_{}".format(camel(kid), cue))
        if s is not None:
            cdo.set_editor_property(cue.lower() + "_sound", s)
        else:
            MANUAL.append("BP_Keeper_{}: no {} voice".format(camel(kid), cue))
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    EAL.save_loaded_asset(bp)


def main():
    missing = [n for n in ("SunderKeeper", "SunderMusicSubsystem") if not hasattr(unreal, n)]
    if missing:
        unreal.log_error("[SunderKeeperAudio] C++ types not found: {}. Compile unreal/Source first.".format(", ".join(missing)))
        return
    for path in (MUSIC_DIR, VOICE_DIR):
        EAL.make_directory(path)

    music = step("import the music (39 loops)", import_folder, "Music", MUSIC_DIR)
    step("import the voices (60 cues)", import_folder, "Voices", VOICE_DIR)
    if music:
        step("music: loop, play when silent, Music group", set_music_settings, music)
    for kid in KEEPERS:
        step("BP_Keeper_{}: theme and voice".format(camel(kid)), wire_keeper, kid)

    MANUAL.append("Optional: route the music and voices through your own Sound Classes / Submixes for the options menu "
                  "(the music subsystem's MusicVolume and the Keepers' VoiceVolume work without them)")
    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)
    log("Play L_SunderArena: Wepwawet's theme starts as it arrives and builds with each phase.")


main()
