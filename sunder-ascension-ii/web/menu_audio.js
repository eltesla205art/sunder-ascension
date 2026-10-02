/* SUNDER: Ascension II — title screen and hangar audio. Plugs into the engine in keeper_audio.js (load that first).
   Title: the hero's theme, slow and wide, over wind at the crystal gate, the portal's hum and drifting embers.
   Hangar: a working groove over machinery, vents, clanks and the base PA. Interface cues for both, and an engine
   signature for each ship that plays when you pick it and again when you launch. Same notation as keeper_audio.js. */
(function (root) {
'use strict';
const KA = root.KeeperAudio || (typeof require === 'function' ? require('./keeper_audio.js') : null);
const { hiss, chime } = KA.kit;
const HERO = '69 . 72 76 . 74 72 . 69 . 72 76 79 . 77 74';

const themes = {
  menu_title: { bpm: 84, raw: true, bassType: 'triangle', bassVol: 0.08, leadType: 'triangle', leadVol: 0.05, leadLen: 1.6, pad: true, echo: true,
    bass: '45 . . . . . . . 41 . . . . . . . 43 . . . . . . . 40 . . . 44 . . .',
    lead: HERO + ' 72 . 74 76 . . 79 . 77 . 76 74 72 . . .',
    drums: 'k...............k.......s.......' },
  menu_hangar: { bpm: 112, root: 45, scale: 'minor', bassType: 'square', bassLp: 800, bassVol: 0.045, leadType: 'square', leadVol: 0.022,
    bass: '0 0 7 0 0 0 5 0 3 3 10 3 2 2 9 2',
    lead: '. . . . 4 . . 3 4 . . . . . . . . . . . 6 . . 4 7 . . . . . . .',
    drums: 'k.h.s.h.k.hhs.h.' },
};

const voices = {
  menu_title: {
    // the gate surges open as you press start
    start: [{ w: 'noise', d: 1.0, v: 0.1, lp: [300, 4000], a: 0.6 },
            ...[220, 277, 330, 440].map((f, i) => ({ w: 'sine', f, d: 1.6, v: 0.035 - i * 0.004, a: 0.3, at: 0.35 })),
            chime(1760, 0.6, 0.03, 1.4)],
    leaderboard: [chime(1320, 0, 0.035, 0.6), chime(1760, 0.1, 0.03, 0.8)],
  },
  menu_hangar: {
    move: [{ w: 'square', f: [300, 600], d: 0.18, v: 0.02, lp: [1500, 1500] },                   // servo turns the bay
           { w: 'noise', d: 0.06, v: 0.06, bp: [1200, 1200], q: 4, at: 0.18 }],                    // and locks
    mode: [{ w: 'triangle', f: [660, 660], d: 0.08, v: 0.04 }, { w: 'triangle', f: [990, 990], d: 0.12, v: 0.035, at: 0.07 }],
    back: [{ w: 'triangle', f: [660, 440], d: 0.2, v: 0.04 }],
    launch: [{ w: 'noise', d: 1.2, v: 0.12, bp: [300, 3000], q: 0.8, a: 0.4 },
             { w: 'sawtooth', f: [80, 600], d: 1.0, v: 0.05, lp: [400, 2500], a: 0.3 },
             { w: 'sine', f: [120, 40], d: 0.6, v: 0.16, at: 1.0 }, hiss(0.8, 0.05, 1.0)],
  },
  // each ship's engine, revved on the pad
  ship_sunborn: { rev: [{ w: 'sawtooth', f: [110, 440], d: 0.6, v: 0.05, lp: [600, 3000], a: 0.15 },
                        { w: 'noise', d: 0.5, v: 0.04, bp: [800, 2400], q: 1, a: 0.2 }] },
  ship_scarab:  { rev: [{ w: 'sawtooth', f: [55, 160], d: 0.8, v: 0.07, lp: [300, 1200], a: 0.2 },
                        { w: 'square', f: [40, 80], d: 0.8, v: 0.03, lp: [200, 400], a: 0.2 },
                        { w: 'noise', d: 0.06, v: 0.07, bp: [900, 900], q: 4, at: 0.75 }] },
  ship_ibis:    { rev: [{ w: 'triangle', f: [400, 1800], d: 0.45, v: 0.04, vib: [12, 25], a: 0.1 },
                        { w: 'noise', d: 0.4, v: 0.04, hp: [2500, 6000], a: 0.15 }] },
};

const ambience = {
  menu_title: { beds: [{ w: 'noise', v: 0.04, bp: 500, q: 0.6, trem: [0.09, 0.6], sweep: [0.05, 250] },    // wind at the gate
                       { w: 'sine', f: 110, v: 0.012, trem: [0.5, 0.4] }, { w: 'sine', f: 165, v: 0.008, trem: [0.33, 0.5] }],  // portal hum
    events: [{ every: [0.4, 1.5], layers: [{ w: 'square', f: [80, 80], d: 0.015, v: 0.015, hp: [2500, 2500] }] },  // embers
             { every: [3, 7], layers: [chime(2637, 0, 0.008, 1.5)] }] },                                           // crystal
  menu_hangar: { beds: [{ w: 'sawtooth', f: 50, v: 0.02, lp: 160 }, { w: 'noise', v: 0.03, lp: 450, trem: [0.2, 0.3] },
                        { w: 'sine', f: 120, v: 0.006 }],                                                          // hum, vents, mains
    events: [{ every: [3, 7], layers: [{ w: 'noise', d: 0.06, v: 0.03, bp: [1800, 1800], q: 5, rep: 2, gap: 0.12 }] },  // clanks
             { every: [12, 20], layers: [chime(880, 0, 0.015, 0.8), chime(1109, 0.25, 0.015, 1.0)] },                   // PA
             { every: [6, 11], layers: [{ w: 'noise', d: 0.8, v: 0.025, hp: [2000, 4000], a: 0.1 }] },                    // hydraulics
             { every: [9, 15], layers: [{ w: 'square', f: [180, 220], d: 0.5, v: 0.006, lp: [600, 600], vib: [30, 20] }] }] },  // drill
};

KA.register({ themes, voices, ambience });
KA.MENU_CUES = { menu_title: ['start', 'leaderboard'], menu_hangar: ['move', 'mode', 'back', 'launch'] };
if (typeof module !== 'undefined' && module.exports) module.exports = KA;
})(typeof window !== 'undefined' ? window : globalThis);
