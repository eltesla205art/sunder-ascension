"""SUNDER: Ascension II — the ship's pickup, bomb and hit sounds.

Run inside the Unreal Editor (Tools → Execute Python Script…) AFTER create_arena_level.py, with the C++ in unreal/Source
compiled (SunderShipPawn's sound properties).

The sounds are the web game's own little synth (web/game.html sfx()), rendered to WAV by
unreal/Tools/render_web_audio.cjs effects into unreal/Content/Audio/Effects as SFX_Game_<Kind>.wav.

Does:
  1. imports all of them into /Game/Sunder/Audio/Effects (Power, Life, Bomb, Hit, and Shoot, Boom, BigBoom, Select for
     later use);
  2. sets them on BP_SunderShip, as the web game plays them:
       Pickup Sound = SFX_Game_Power   weapon, power and bomb pickups
       Life Sound   = SFX_Game_Life    life and shield pickups
       Bomb Sound   = SFX_Game_Bomb    using a bomb
       Hit Sound    = SFX_Game_Hit     a shield soaking a hit, or the hull taking one

Safe to run again. Untested until its first run.
"""
import os

import unreal

SOURCE_DIR = None   # None = ../Content/Audio/Effects next to this script

SOUND_DIR = "/Game/Sunder/Audio/Effects"
SHIP_BP = "/Game/Sunder/Blueprints/BP_SunderShip"
SHIP_SOUNDS = {"pickup_sound": "SFX_Game_Power", "life_sound": "SFX_Game_Life", "bomb_sound": "SFX_Game_Bomb",
               "hit_sound": "SFX_Game_Hit"}

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []


def log(msg):
    unreal.log("[SunderShipSounds] " + msg)


def step(label, fn, *args):
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:   # the editor's Python API differs a little between versions
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderShipSounds] {} failed: {}".format(label, exc))
        return None


def source_dir():
    if SOURCE_DIR:
        return SOURCE_DIR
    here = os.path.dirname(os.path.abspath(__file__))
    return os.path.normpath(os.path.join(here, "..", "Content", "Audio", "Effects"))


def import_sounds():
    folder = source_dir()
    if not os.path.isdir(folder):
        raise RuntimeError("not found: {} (run node unreal/Tools/render_web_audio.cjs effects)".format(folder))
    tasks = []
    for name in sorted(os.listdir(folder)):
        if not name.lower().endswith(".wav"):
            continue
        task = unreal.AssetImportTask()
        task.set_editor_property("filename", os.path.join(folder, name))
        task.set_editor_property("destination_path", SOUND_DIR)
        task.set_editor_property("destination_name", os.path.splitext(name)[0])
        task.set_editor_property("automated", True)
        task.set_editor_property("replace_existing", True)
        task.set_editor_property("save", True)
        tasks.append(task)
    if not tasks:
        raise RuntimeError("no .wav files in " + folder)
    TOOLS.import_asset_tasks(tasks)
    names = [os.path.splitext(os.path.basename(t.get_editor_property("filename")))[0] for t in tasks]
    missing = [n for n in names if not EAL.does_asset_exist("{}/{}".format(SOUND_DIR, n))]
    if missing:
        raise RuntimeError("{} of {} didn't import, e.g. {}".format(len(missing), len(names), missing[0]))
    log("imported {} sounds into {}".format(len(names), SOUND_DIR))


def wire_ship():
    if not EAL.does_asset_exist(SHIP_BP):
        raise RuntimeError(SHIP_BP + " not found; run create_arena_level.py first")
    bp = EAL.load_asset(SHIP_BP)
    cdo = unreal.get_default_object(EAL.load_blueprint_class(SHIP_BP))
    for prop, name in SHIP_SOUNDS.items():
        full = "{}/{}".format(SOUND_DIR, name)
        if EAL.does_asset_exist(full):
            cdo.set_editor_property(prop, EAL.load_asset(full))
        else:
            MANUAL.append("BP_SunderShip: no {} for {}".format(name, prop))
    unreal.BlueprintEditorLibrary.compile_blueprint(bp)
    EAL.save_loaded_asset(bp)


def main():
    if not hasattr(unreal, "SunderShipPawn"):
        unreal.log_error("[SunderShipSounds] C++ types not found: SunderShipPawn. Compile unreal/Source first.")
        return
    EAL.make_directory(SOUND_DIR)
    step("import the game sounds", import_sounds)
    step("BP_SunderShip: pickup, life, bomb and hit sounds", wire_ship)
    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)
    log("Play: pickups chime, bombs roar, and hits thud, as in the web game.")


main()
