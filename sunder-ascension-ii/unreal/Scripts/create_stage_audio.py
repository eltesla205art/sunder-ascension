"""SUNDER: Ascension II — import the twelve Hours' music, ambience and cues, and give them to the wave sets.

Run inside the Unreal Editor (Tools → Execute Python Script…) AFTER create_enemies_and_waves.py (and create_keepers.py
for the gauntlet), with the C++ in unreal/Source compiled (it needs SunderStageAudio and SunderMusicSubsystem).

The sounds are the web game's own (web/stage_audio.js), rendered to WAV by unreal/Tools/render_web_audio.cjs into
unreal/Content/Audio/Stages:
  Music/     MUS_Stage_<Hour>_L1/L2/L3.wav: each Hour's theme in three layers, seamless same-length loops
  Ambience/  AMB_Stage_<Hour>.wav: the place itself (wind, floodwater, fire, rain, a heartbeat...), a 24 s seamless loop
  Cues/      SFX_Stage_<Hour>_Start/Wave/Down/Clear.wav

Does:
  1. imports them into /Game/Sunder/Audio/Stages/Music, /Ambience and /Cues;
  2. sets the music to loop and keep playing while silent (so the quiet layers stay in step), the ambience to loop;
  3. makes DA_StageAudio_<Hour> for all twelve Hours in /Game/Sunder/Audio/Stages;
  4. gives DA_TestWaves the first Hour (Horizon), and each wave of DA_KeeperGauntlet its own Hour's sound.

Safe to run again. Untested until its first run.
"""
import os

import unreal

AUDIO_SOURCE_DIR = None   # None = ../Content/Audio/Stages next to this script; set a path if you moved the script
TEST_WAVES_STAGE = "horizon"

ROOT = "/Game/Sunder/Audio/Stages"
MUSIC_DIR = ROOT + "/Music"
AMB_DIR = ROOT + "/Ambience"
CUE_DIR = ROOT + "/Cues"
WAVE_DIR = "/Game/Sunder/Waves"

# The Twelve Hours in order (web/game.html STAGES: stage art keys), with their names.
STAGES = [
    ("horizon", "Hour of the Western Horizon"), ("delta", "Hour of the Drowned Fields"), ("mirror", "Hour of the Mirror"),
    ("spires", "Hour of the Sunken Spires"), ("sokar", "Hour of Sokar's Sand"), ("firelake", "Hour of the Lake of Fire"),
    ("coils", "Hour of the Coiled One"), ("ironsky", "Hour of the Iron Sky"), ("judgement", "Hour of the Judgement Hall"),
    ("starfall", "Hour of the Starfall"), ("heart", "Hour of the Heart"), ("apep", "Hour of Apep"),
]
CUES = ["Start", "Wave", "Down", "Clear"]

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []


def log(msg):
    unreal.log("[SunderStageAudio] " + msg)


def step(label, fn, *args):
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:   # the editor's Python API differs a little between versions
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderStageAudio] {} failed: {}".format(label, exc))
        return None


def camel(sid):
    return sid.capitalize()


def source_dir():
    if AUDIO_SOURCE_DIR:
        return AUDIO_SOURCE_DIR
    here = os.path.dirname(os.path.abspath(__file__))
    return os.path.normpath(os.path.join(here, "..", "Content", "Audio", "Stages"))


# ------------------------------------------------------------------ 1. import
def import_folder(sub, dest):
    folder = os.path.join(source_dir(), sub)
    if not os.path.isdir(folder):
        raise RuntimeError("not found: {} (run node unreal/Tools/render_web_audio.cjs stages)".format(folder))
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


# ------------------------------------------------------------------ 2. loop settings
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


# ------------------------------------------------------------------ 3. the stage audio assets
def build_stage(sid, title):
    name = "DA_StageAudio_" + camel(sid)
    full = "{}/{}".format(ROOT, name)
    if EAL.does_asset_exist(full):
        data = EAL.load_asset(full)
    else:
        factory = unreal.DataAssetFactory()
        factory.set_editor_property("data_asset_class", unreal.SunderStageAudio)
        data = TOOLS.create_asset(name, ROOT, unreal.SunderStageAudio, factory)
        if data is None:
            raise RuntimeError("could not create " + full)
    layers = [sound(MUSIC_DIR, "MUS_Stage_{}_L{}".format(camel(sid), n)) for n in (1, 2, 3)]
    if any(s is None for s in layers):
        raise RuntimeError("missing a layer of MUS_Stage_" + camel(sid))
    data.set_editor_property("stage_name", title)
    data.set_editor_property("music_layers", layers)
    ambience = sound(AMB_DIR, "AMB_Stage_" + camel(sid))
    if ambience is not None:
        data.set_editor_property("ambience", ambience)
    for cue in CUES:
        s = sound(CUE_DIR, "SFX_Stage_{}_{}".format(camel(sid), cue))
        if s is not None:
            data.set_editor_property(cue.lower() + "_sound", s)
        else:
            MANUAL.append("{}: no {} cue".format(name, cue))
    EAL.save_loaded_asset(data)
    return data


# ------------------------------------------------------------------ 4. the wave sets
def wave_set(name):
    full = "{}/{}".format(WAVE_DIR, name)
    if not EAL.does_asset_exist(full):
        raise RuntimeError(full + " not found")
    return EAL.load_asset(full)


def give_test_waves(stage):
    data = wave_set("DA_TestWaves")
    data.set_editor_property("stage_audio", stage)
    EAL.save_loaded_asset(data)


def give_gauntlet(stages):
    data = wave_set("DA_KeeperGauntlet")
    waves = list(data.get_editor_property("waves"))
    for i, wave in enumerate(waves):
        label = str(wave.get_editor_property("wave_name"))     # "HOUR n", as create_keepers.py names them
        try:
            hour = int(label.split()[-1])
        except ValueError:
            hour = i + 1
        sid = STAGES[(hour - 1) % len(STAGES)][0]
        if stages.get(sid) is not None:
            wave.set_editor_property("stage_audio", stages[sid])
            waves[i] = wave
    data.set_editor_property("waves", waves)
    EAL.save_loaded_asset(data)


def main():
    missing = [n for n in ("SunderStageAudio", "SunderMusicSubsystem") if not hasattr(unreal, n)]
    if missing:
        unreal.log_error("[SunderStageAudio] C++ types not found: {}. Compile unreal/Source first.".format(", ".join(missing)))
        return
    for path in (ROOT, MUSIC_DIR, AMB_DIR, CUE_DIR):
        EAL.make_directory(path)

    music = step("import the music (36 loops)", import_folder, "Music", MUSIC_DIR)
    ambience = step("import the ambience (12 loops)", import_folder, "Ambience", AMB_DIR)
    step("import the cues (48)", import_folder, "Cues", CUE_DIR)
    if music:
        step("music: loop, play when silent, Music group", set_loop_settings, MUSIC_DIR, music, True)
    if ambience:
        step("ambience: loop", set_loop_settings, AMB_DIR, ambience, False)

    stages = {}
    for sid, title in STAGES:
        stages[sid] = step("DA_StageAudio_" + camel(sid), build_stage, sid, title)

    if stages.get(TEST_WAVES_STAGE) is not None:
        step("DA_TestWaves → DA_StageAudio_" + camel(TEST_WAVES_STAGE), give_test_waves, stages[TEST_WAVES_STAGE])
    step("DA_KeeperGauntlet: each Keeper's Hour", give_gauntlet, stages)

    MANUAL.append("Optional: for your own stages, make a wave set per Hour and set its Stage Audio to that Hour's "
                  "DA_StageAudio_* (its theme builds a layer each third of the way through its enemy waves)")
    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)
    log("Play L_SunderArena: the Horizon's wind and theme start with the first wave and build toward Wepwawet.")


main()
