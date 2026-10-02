/* SUNDER: Ascension II — stage audio for the Twelve Hours. Plugs into the engine in keeper_audio.js (load that first).
   Each Hour has its own theme (building with your progress toward the Keeper), an ambience that runs through the
   whole stage, and four cues: start (the gate opens), wave (a formation arrives), down (an enemy falls, layered on
   the game's explosion) and clear (the Keeper is beaten). Ids are the stage art keys, e.g. 'stage_horizon'.
   Themes and voice layers use the same notation as keeper_audio.js. */
(function (root) {
'use strict';
const KA = root.KeeperAudio || (typeof require === 'function' ? require('./keeper_audio.js') : null);
const { hiss, chime, thump, degree, hz } = KA.kit;
const HERO = '69 . 72 76 . 74 72 . 69 . 72 76 79 . 77 74';

// ------------------------------------------------------------------ themes: lighter than the Keepers', one per Hour
const themes = {
  // Act I — Dusk
  stage_horizon: { bpm: 120, root: 45, scale: 'hijaz', bassType: 'triangle', bassVol: 0.07, leadType: 'square', leadVol: 0.025,
    bass: '0 . 0 . 4 . 3 . 0 . 0 . 1 . 0 .',
    lead: '4 . . 5 4 . 2 . 1 . . . . . . . 2 . 4 5 . 4 2 . 1 . 0 . . . . .',
    drums: 'k...h...k.k.h...' },
  stage_delta: { bpm: 104, root: 43, scale: 'phrygian', bassType: 'triangle', bassVol: 0.07, leadType: 'triangle', leadVol: 0.04, leadLen: 1.4, pad: true,
    bass: '0 . . . . . 0 . 1 . . . 0 . . .',
    lead: '7 . . 6 . 4 . . 3 . . . . . . . 4 . 6 7 . 8 7 . 6 . . 4 . . . .',
    drums: 'k.......k...s...' },
  stage_mirror: { bpm: 126, root: 47, scale: 'harmonic', bassType: 'sawtooth', bassLp: 500, leadType: 'sine', leadVol: 0.05, echo: true,
    bass: '0 . 0 0 . 0 5 . 4 . 4 4 . 4 3 .',
    lead: '7 . 9 . 11 . 9 . 8 . . . . . . . 7 . 6 . 4 . 6 . 7 . . . . . . .',
    drums: 'k..hk..hk..hk.hh' },
  // Act II — Midnight
  stage_spires: { bpm: 96, root: 38, scale: 'dorian', bassType: 'triangle', bassVol: 0.08, leadType: 'sine', leadVol: 0.05, leadLen: 1.6, pad: true, echo: true,
    bass: '0 . . . . . . . 3 . . . . . . . 5 . . . . . . . 4 . . . 3 . . .',
    lead: '9 . . 8 . 7 . . 6 . . . . . . . 7 . . 8 . 9 . . 11 . . 9 . . . .',
    drums: 'k.......h.......k.....k.h.......' },
  stage_sokar: { bpm: 118, root: 50, scale: 'phrygian', bassType: 'sawtooth', bassLp: 600, leadType: 'square', leadVol: 0.025,
    bass: '0 . . 0 . . 0 . 1 . . 1 . . 0 .',
    lead: '4 . 3 . 1 . 0 . 1 . 3 . 4 . . . 5 . 4 . 3 . 1 . 0 . . . . . . .',
    drums: 'k..sk..sk..sk.ss' },
  stage_firelake: { bpm: 132, root: 40, scale: 'hijaz', bassType: 'sawtooth', bassLp: 700, leadType: 'sawtooth', leadLp: 1800, leadVol: 0.025,
    bass: '0 0 . 0 . 0 1 . 0 0 . 0 . 3 1 .',
    lead: '4 . . 4 5 . 4 . 2 . 1 . . . . . 4 . . 4 5 . 7 . 5 . 4 . . . . .',
    drums: 'k.h.k.hsk.h.k.hs' },
  // Act III — The Deep Night
  stage_coils: { bpm: 110, root: 41, scale: 'phrygian', bassType: 'sawtooth', bassLp: 450, sub: true, leadType: 'triangle', leadVol: 0.04, echo: true,
    bass: '0 . . . 0 . . 1 0 . . . -1 . . .',
    lead: '7 . 8 . . . 7 . . . 5 . . . . . 4 . 5 . . . 4 . . . 1 . . . . .',
    drums: 'k.....h.k.....h.' },
  stage_ironsky: { bpm: 128, root: 40, scale: 'minor', bassType: 'square', bassLp: 700, bassVol: 0.045, leadType: 'square', leadVol: 0.022,
    bass: '0 . 0 . 0 . 0 . 3 . 3 . 2 . 2 .',
    lead: '7 . 7 . 6 . 4 . 6 . . . 4 . . . 7 . 7 . 9 . 10 . 9 . 7 . . . . .',
    drums: 'k.s.k.s.k.s.kks.' },
  stage_judgement: { bpm: 100, root: 41, scale: 'harmonic', bassType: 'triangle', bassVol: 0.08, leadType: 'triangle', leadVol: 0.045, leadLen: 1.5, pad: true,
    bass: '0 . . . . . . . 5 . . . 4 . . .',
    lead: '4 . . . 6 . . . 7 . . . . . . . 8 . 7 . 6 . 4 . 3 . . . . . . .',
    drums: 'k.......s.......' },
  // Act IV — Dawn or Nothing
  stage_starfall: { bpm: 140, root: 49, scale: 'double', bassType: 'sawtooth', bassLp: 800, leadType: 'square', leadVol: 0.025, echo: true,
    bass: '0 . 0 . 4 . 4 . 3 . 3 . 1 . 1 .',
    lead: '11 . 10 . 9 . 7 . 8 . . . 7 . . . 9 . 8 . 7 . 5 . 4 . . . . . . .',
    drums: 'k.h.s.h.k.h.s.hh' },
  stage_heart: { bpm: 116, raw: true, bassType: 'triangle', bassVol: 0.08, leadType: 'triangle', leadVol: 0.045, leadLen: 1.3, pad: true,
    bass: '45 . . . 41 . . . 43 . . . 40 . . .',            // the hero's theme, slow, at the Heart of Atlantis
    lead: HERO + ' 72 . 74 76 . 79 81 . 79 . 76 . 74 . . .',
    drums: 'k.......k.k.s...' },
  stage_apep: { bpm: 146, root: 45, scale: 'double', bassType: 'sawtooth', bassLp: 700, leadType: 'sawtooth', leadLp: 2200, leadVol: 0.028,
    bass: '0 0 . 0 1 . 0 . 0 0 . 0 4 3 1 .',
    lead: '7 . 9 . 11 . 10 . 9 . . . . . . . 7 . 8 . 9 . 8 . 7 . 4 . 5 . . .',
    drums: 'k.hsk.hskkhsk.hs' },
};

// ------------------------------------------------------------------ cues
// start: a three-note call in the Hour's key; clear: an arpeggio fanfare ending on the octave. Both carry the
// Hour's own texture (its `flavour`), which also colours each enemy explosion (`down`) and formation alerts (`wave`).
function call(spec, type){
  const r = spec.root + 12;
  return [0, 2, 4].map((d, i) => ({ w: type, f: hz(degree(r, spec.scale, d)), d: 0.32, v: 0.05, at: i * 0.14, lp: [2400, 1400] }))
    .concat({ w: type, f: hz(degree(r, spec.scale, 4)), d: 1.0, v: 0.04, at: 0.42, lp: [2400, 900] });
}
function fanfare(spec, type){
  const r = spec.root + 12, notes = [0, 2, 4, 7];
  return notes.map((d, i) => ({ w: type, f: hz(degree(r, spec.scale, d)), d: 0.28, v: 0.05, at: i * 0.12, lp: [3000, 2000] }))
    .concat([0, 4, 7].map(d => ({ w: 'sawtooth', f: hz(degree(r, spec.scale, d)), d: 1.6, v: 0.03, at: 0.5, a: 0.05, lp: [2600, 700] })))
    .concat(chime(hz(degree(r + 12, spec.scale, 7)), 0.5, 0.03, 1.6));
}
const FLAVOUR = {
  stage_horizon:   { down: [{ w: 'noise', d: 0.25, v: 0.05, bp: [900, 300], q: 0.7 }],                          // sand puff
                     wave: [{ w: 'triangle', f: [1250, 1180], d: 0.3, v: 0.04, rep: 2, gap: 0.16 }] },           // rail bell
  stage_delta:     { down: [{ w: 'noise', d: 0.3, v: 0.06, lp: [2400, 300] }, { w: 'sine', f: [600, 1400], d: 0.06, v: 0.03, at: 0.05 }],
                     wave: [{ w: 'sine', f: [300, 900], d: 0.06, v: 0.05, rep: 4, gap: 0.07 }] },               // splash; bubbles
  stage_mirror:    { down: [{ w: 'noise', d: 0.2, v: 0.05, hp: [3500, 6000] }, chime(2637, 0.02, 0.02, 0.3)],
                     wave: [chime(1760, 0, 0.04, 0.5), chime(2349, 0.12, 0.035, 0.5)] },                         // glass
  stage_spires:    { down: [{ w: 'sine', f: [400, 1200], d: 0.05, v: 0.035, rep: 3, gap: 0.05 }],
                     wave: [{ w: 'sine', f: [180, 260], d: 0.8, v: 0.06, a: 0.2, vib: [3, 8] }] },              // bubbles; deep call
  stage_sokar:     { down: [{ w: 'noise', d: 0.3, v: 0.05, bp: [1500, 500], q: 0.8 }],
                     wave: [{ w: 'sawtooth', f: [1900, 1300], d: 0.4, v: 0.035, bp: [2400, 1800], q: 3, vib: [30, 50] }] },
  stage_firelake:  { down: [{ w: 'square', f: [70, 70], d: 0.015, v: 0.04, rep: 4, gap: 0.05, hp: [2500, 2500] }],
                     wave: [{ w: 'noise', d: 0.5, v: 0.07, lp: [500, 2500], a: 0.2 }] },                        // embers; flare
  stage_coils:     { down: [hiss(0.25, 0.04)],
                     wave: [hiss(0.7, 0.06), { w: 'triangle', f: [1760, 1700], d: 0.5, v: 0.02, at: 0.2 }] },
  stage_ironsky:   { down: [{ w: 'noise', d: 0.05, v: 0.06, bp: [2500, 2500], q: 6 }],                          // metal
                     wave: [{ w: 'sawtooth', f: [220, 208], d: 0.6, v: 0.05, lp: [1100, 800], a: 0.05 }] },     // horn
  stage_judgement: { down: [{ w: 'sine', f: [120, 60], d: 0.15, v: 0.06 }, chime(1320, 0.02, 0.012, 0.4)],
                     wave: [chime(440, 0, 0.05, 1.4), chime(660, 0, 0.025, 1.2)] },                              // bell
  stage_starfall:  { down: [{ w: 'triangle', f: [2400, 1200], d: 0.15, v: 0.025 }],
                     wave: [{ w: 'sine', f: [3000, 700], d: 0.7, v: 0.03 }, { w: 'sine', f: [2600, 600], d: 0.7, v: 0.025, at: 0.15 }] },
  stage_heart:     { down: [thump(90, 0, 0.06)],
                     wave: [thump(70, 0, 0.14), thump(64, 0.22, 0.1)] },                                        // heartbeat
  stage_apep:      { down: [hiss(0.2, 0.035), { w: 'sine', f: [90, 40], d: 0.15, v: 0.05 }],
                     wave: [{ w: 'sine', f: [50, 35], d: 1.0, v: 0.1, a: 0.2 }, hiss(0.8, 0.06, 0.2)] },
};
const LEAD_TYPE = { stage_delta: 'triangle', stage_spires: 'triangle', stage_judgement: 'triangle', stage_heart: 'triangle' };
const voices = {};
for (const id in themes){
  const spec = themes[id].raw ? { root: 45, scale: 'minor' } : themes[id], type = LEAD_TYPE[id] || 'square';
  voices[id] = { start: call(spec, type).concat(FLAVOUR[id].wave), wave: FLAVOUR[id].wave,
                 down: FLAVOUR[id].down, clear: fanfare(spec, type) };
}

// ------------------------------------------------------------------ ambience: the place itself
const ambience = {
  stage_horizon: { beds: [{ w: 'noise', v: 0.05, bp: 600, q: 0.7, trem: [0.13, 0.5], sweep: [0.07, 300] }],      // desert wind
    events: [{ every: [3, 7], layers: [{ w: 'triangle', f: [1250, 1180], d: 0.4, v: 0.015, rep: 2, gap: 0.25 }] },    // rail clank
             { every: [8, 14], layers: [{ w: 'sine', f: [300, 420], d: 2, v: 0.012, a: 0.8, vib: [4, 10] }] }] },    // far howl
  stage_delta: { beds: [{ w: 'noise', v: 0.05, lp: 500, trem: [0.35, 0.6] }],                                    // floodwater
    events: [{ every: [0.8, 2.2], layers: [{ w: 'sine', f: [900, 1500], d: 0.06, v: 0.02 }] },                       // drips
             { every: [4, 9], layers: [{ w: 'square', f: [180, 170], d: 0.05, v: 0.012, rep: 3, gap: 0.09, lp: [600, 600] }] }] },
  stage_mirror: { beds: [{ w: 'noise', v: 0.022, hp: 4000, trem: [0.2, 0.6] }, { w: 'sine', f: 123.5, v: 0.012, trem: [0.07, 0.5] }],
    events: [{ every: [1.5, 4], layers: [chime(2637, 0, 0.012, 1.2)] }, { every: [2, 5], layers: [chime(3136, 0, 0.01, 1.0)] }] },
  stage_spires: { beds: [{ w: 'noise', v: 0.04, lp: 180, trem: [0.08, 0.4] }, { w: 'sine', f: 55, v: 0.015, trem: [0.1, 0.3] }],
    events: [{ every: [1, 3], layers: [{ w: 'sine', f: [350, 1100], d: 0.05, v: 0.02, rep: 4, gap: 0.08 }] },
             { every: [9, 16], layers: [{ w: 'sine', f: [180, 260], d: 1.6, v: 0.02, a: 0.6, vib: [3, 8] }] }] },   // whale
  stage_sokar: { beds: [{ w: 'noise', v: 0.06, bp: 700, q: 0.6, trem: [0.18, 0.7], sweep: [0.11, 400] },        // gusts
                        { w: 'noise', v: 0.015, hp: 5000, trem: [0.3, 0.5] }],                                    // sand hiss
    events: [{ every: [10, 18], layers: [{ w: 'sawtooth', f: [1900, 1200], d: 0.5, v: 0.012, bp: [2400, 1800], q: 3, vib: [30, 50] }] }] },
  stage_firelake: { beds: [{ w: 'noise', v: 0.06, lp: 700, trem: [0.25, 0.4] }],                                // fire roar
    events: [{ every: [0.15, 0.6], layers: [{ w: 'square', f: [80, 80], d: 0.015, v: 0.025, hp: [2500, 2500] }] },  // crackle
             { every: [2, 5], layers: [{ w: 'sine', f: [220, 90], d: 0.25, v: 0.03 }] }] },                          // lava bloop
  stage_coils: { beds: [{ w: 'sawtooth', f: 41.2, v: 0.015, lp: 180, trem: [0.07, 0.5] }, { w: 'noise', v: 0.02, hp: 4500, trem: [0.11, 0.8] }],
    events: [{ every: [5, 10], layers: [{ w: 'noise', d: 2, v: 0.03, hp: [3500, 6000], a: 1 }] },
             { every: [4, 8], layers: [{ w: 'triangle', f: [1760, 1700], d: 1, v: 0.01 }] }] },
  stage_ironsky: { beds: [{ w: 'noise', v: 0.04, lp: 160, trem: [0.1, 0.4] }, { w: 'noise', v: 0.02, hp: 5000 }],  // storm, rain
    events: [{ every: [7, 14], layers: [{ w: 'noise', d: 2.5, v: 0.07, lp: [900, 120], a: 0.05 }] },                  // thunder
             { every: [3, 6], layers: [{ w: 'noise', d: 0.05, v: 0.035, bp: [2500, 2500], q: 6 }] }] },
  stage_judgement: { beds: [{ w: 'sine', f: 55, v: 0.014, trem: [0.05, 0.3] }, { w: 'sine', f: 82.4, v: 0.009, trem: [0.07, 0.4] },
                            { w: 'noise', v: 0.012, bp: 900, q: 0.8, trem: [0.09, 0.6] }],
    events: [{ every: [8, 12], layers: [chime(440, 0, 0.025, 3), chime(660, 0, 0.012, 2.4)] },                      // bell
             { every: [5, 9], layers: [{ w: 'noise', d: 0.6, v: 0.02, bp: [1800, 2600], q: 5, a: 0.2 }] }] },       // whisper
  stage_starfall: { beds: [{ w: 'noise', v: 0.02, hp: 6000, trem: [0.3, 0.6] }, { w: 'sine', f: 98, v: 0.015, trem: [0.1, 0.5] }],
    events: [{ every: [1.5, 4], layers: [{ w: 'sine', f: [3000, 700], d: 0.9, v: 0.012 }] },                         // falling stars
             { every: [6, 11], layers: [{ w: 'noise', d: 1, v: 0.035, lp: [600, 100] }] }] },                         // impacts
  stage_heart: { beds: [{ w: 'sine', f: 65.4, v: 0.012, trem: [0.15, 0.3] }, { w: 'noise', v: 0.015, lp: 300 }],
    events: [{ every: [1.15, 1.15], layers: [thump(70, 0, 0.1), thump(64, 0.22, 0.075)] }] },                       // the Heart beats
  stage_apep: { beds: [{ w: 'noise', v: 0.04, lp: 220, trem: [0.12, 0.8] }, { w: 'sawtooth', f: 36.7, v: 0.012, lp: 120 }],  // breathing
    events: [{ every: [4, 8], layers: [hiss(1.2, 0.04)] },
             { every: [6, 12], layers: [{ w: 'sine', f: [45, 30], d: 2, v: 0.05, a: 0.5 }] }] },
};

const STAGE_CUES = ['start', 'wave', 'down', 'clear'];
KA.register({ themes, voices, ambience });
KA.STAGE_CUES = STAGE_CUES;
if (typeof module !== 'undefined' && module.exports) module.exports = KA;
})(typeof window !== 'undefined' ? window : globalThis);
