/* SUNDER: Ascension II — Keeper audio, and the engine the stage audio (stage_audio.js) plugs into.
   Every Keeper has its own battle theme and its own voice (intro, attack, phase, hurt, death),
   synthesised live with Web Audio: no audio files to load.
   Used by game.html (boss fights) and keepers.html (the Keeper Codex). Plain script; also loads in Node for tests.

   Themes are written in scale degrees (0 = the key's root; 7 = an octave up in a 7-note scale; '.' = rest), or in
   MIDI notes when `raw` is set. Bass plays from `root`, lead two octaves higher. Layers build with the boss phase:
   1 = bass, kick and the lead held back; 2 = full lead, snare and hats; 3 = + lead and bass doubled an octave up
   and double-time hats.
   Voice cues are lists of synth layers: w = wave ('sine' 'square' 'sawtooth' 'triangle' 'noise'), f = [Hz from, to],
   d = seconds, v = peak gain, at = delay, a = attack time, lp/hp/bp = filter sweep [Hz from, to], q = filter Q,
   vib = [rate Hz, depth Hz], rep/gap = repeat count and spacing. */
(function (root) {
'use strict';

const SCALES = {
  hijaz:    [0, 1, 4, 5, 7, 8, 10],   // Phrygian dominant: the desert sound of Act I
  phrygian: [0, 1, 3, 5, 7, 8, 10],
  dorian:   [0, 2, 3, 5, 7, 9, 10],
  harmonic: [0, 2, 3, 5, 7, 8, 11],
  double:   [0, 1, 4, 5, 7, 8, 11],   // double harmonic
  minor:    [0, 2, 3, 5, 7, 8, 10],
  locrian:  [0, 1, 3, 5, 6, 8, 10],
};

// The hero's theme (Part 1 'main' lead) and Part 1's boss theme, quoted by UMBRA and the Overlord's Echo
const HERO = '69 . 72 76 . 74 72 . 69 . 72 76 79 . 77 74';
const MIRROR = '69 . 66 62 . 64 66 . 69 . 66 62 59 . 61 64';      // the hero's theme turned upside down

const THEMES = {
  wepwawet: { bpm: 132, root: 45, scale: 'hijaz', bassType: 'sawtooth', bassLp: 700, leadType: 'square',
    bass: '0 0 . 0 0 . 4 3 0 0 . 0 1 . 0 -1',
    lead: '0 . 1 2 . 4 . 2 1 . 0 . . . . . 4 . 5 4 . 2 1 . 2 . 1 0 . -1 0 .',
    drums: 'k.h.s.h.k.k.s.hh' },
  sobek: { bpm: 112, root: 43, scale: 'phrygian', bassType: 'sawtooth', bassLp: 500, leadType: 'sawtooth', leadLp: 1400,
    bass: '0 . . 0 . . 1 . 0 . . 0 . 3 1 .',
    lead: '4 . . 3 1 . 0 . . . . . 1 . 3 . 4 . . 5 4 . 3 1 0 . . . . . . .',
    drums: 'k..k..s.k.k...s.' },
  umbra: { bpm: 150, raw: true, bassType: 'sawtooth', bassLp: 600, leadType: 'square', echo: true,
    bass: '45 45 . 45 41 41 . 41 43 43 . 43 40 . 44 .',
    lead: MIRROR + ' 57 . 60 62 . 64 65 . 68 . 64 . 69 . . .',
    drums: 'k.h.s.hhk.h.s.h.' },
  nun: { bpm: 92, root: 38, scale: 'dorian', bassType: 'triangle', bassVol: 0.09, leadType: 'sine', leadVol: 0.05, leadLen: 1.8, pad: true,
    bass: '0 . . . . . . . -2 . . . . . -1 . 0 . . . . . . . 3 . . . 2 . . .',
    lead: '7 . . . 6 . 4 . 5 . . . . . . . 7 . 8 . 9 . . . 6 . . . 4 . . .',
    drums: 'k.......s.......k.....k.s.......' },
  sokar: { bpm: 140, root: 50, scale: 'double', bassType: 'sawtooth', bassLp: 800, leadType: 'square',
    bass: '0 . 0 . 0 . 4 . 3 . 3 . 1 . 0 .',
    lead: '7 8 7 6 . 4 . . 5 6 5 4 . 1 . . 4 5 6 7 8 . 7 . 6 5 4 . 1 . 0 .',
    drums: 'k.hsk.h.k.hsk.hs' },
  seraphs: { bpm: 158, root: 47, scale: 'hijaz', bassType: 'sawtooth', bassLp: 900, leadType: 'sawtooth', leadLp: 2600,
    bass: '0 0 0 . 0 0 1 . 0 0 0 . 3 2 1 .',
    lead: '4 . 5 . 4 2 . 1 2 . . . . . . . 4 5 7 . 5 4 2 . 1 2 1 0 . . . .',
    drums: 'k.hsk.hsk.hsk.ss' },
  umbra_coiled: { bpm: 160, raw: true, transpose: -2, bassType: 'sawtooth', bassLp: 500, leadType: 'sawtooth', leadLp: 2000, echo: true,
    bass: '45 45 . 45 46 . 45 . 45 45 . 45 41 . 40 .',
    lead: MIRROR + ' 57 . 58 62 . 58 57 . 56 . 57 . 62 . . .',
    drums: 'k.hhs.hhk.hhs.hs' },
  hittite: { bpm: 126, root: 40, scale: 'minor', bassType: 'square', bassLp: 900, bassVol: 0.05, leadType: 'sawtooth', leadLp: 1800,
    bass: '0 0 7 0 0 0 6 0 0 0 7 0 3 0 2 0',
    lead: '4 . . 4 . . 4 . 5 . 4 . 2 . . . 4 . . 4 . . 4 . 7 . 6 . 4 . . .',
    drums: 'k.s.k.s.kks.k.ss' },
  ammit: { bpm: 108, root: 41, scale: 'harmonic', bassType: 'sawtooth', bassLp: 600, leadType: 'triangle', leadVol: 0.05, leadLen: 1.5, pad: true,
    bass: '0 . . . 0 . . . 5 . . . 4 . . .',
    lead: '7 . 9 . 8 . 7 . 6 . . . 4 . . . 7 . 9 . 10 . 9 . 8 . 7 . 6 . . .',
    drums: 'k...s...k.k.s...' },
  overlord_echo: { bpm: 148, raw: true, bassType: 'triangle', bassVol: 0.08, leadType: 'square', echo: true,
    bass: '41 41 41 47 41 41 41 46 41 41 41 47 41 44 46 47',
    lead: '. 65 . 68 . 65 71 . . 65 . 68 72 . 71 68',
    drums: 'k.h.s.h.k.h.s.hh' },
  umbra_unmasked: { bpm: 152, raw: true, bassType: 'sawtooth', bassLp: 700, leadType: 'square', pad: true,
    bass: '45 45 . 45 41 41 . 41 43 43 . 43 44 . 44 .',
    lead: HERO + ' 81 . 79 76 . 74 72 . 74 . 76 79 81 . . .',
    drums: 'k.h.s.h.k.hks.h.' },
  apep: { bpm: 96, root: 36, scale: 'locrian', bassType: 'sawtooth', bassLp: 400, bassVol: 0.09, sub: true, leadType: 'sawtooth', leadLp: 1200,
    bass: '0 . . 0 . . . . 1 . . 0 . . . . 0 . . 0 . . 4 . 3 . . 1 . . . .',
    lead: '4 . . . 3 . . . 1 . . . . . . . 4 . . . 5 . 4 . 3 . 1 . 0 . . .',
    drums: 'k.....k.s.......k.....k.s...s.s.' },
  apep_p3: { bpm: 172, root: 36, scale: 'double', bassType: 'sawtooth', bassLp: 600, sub: true, leadType: 'sawtooth', leadLp: 2400,
    bass: '0 0 . 0 1 1 . 1 0 0 . 0 4 3 1 .',
    lead: '7 . 8 . 7 4 . 5 4 . 1 . 0 . . . 7 8 9 . 8 7 . 5 4 5 4 1 0 . . .',
    drums: 'k.hsk.hskkhsk.ss' },
};

// ------------------------------------------------------------------ the Keepers' voices
const hiss = (d, v, at = 0) => ({ w: 'noise', d, v, at, hp: [3500, 6000], a: 0.15 });
const chime = (hz, at, v = 0.04, d = 1.2) => ({ w: 'sine', f: [hz, hz], d, v, at });
const thump = (hz, at = 0, v = 0.16) => ({ w: 'sine', f: [hz, 38], d: 0.22, v, at });
const hurt = hz => [{ w: 'square', f: [hz, hz * 0.6], d: 0.05, v: 0.025, bp: [hz * 2, hz * 1.5], q: 3 }];

const VOICES = {
  wepwawet: {   // a jackal howl over the stomp of a war-walker
    intro: [{ w: 'sawtooth', f: [220, 520], d: 0.7, v: 0.08, lp: [1200, 2600], vib: [6, 12], a: 0.2 },
            { w: 'sawtooth', f: [520, 330], d: 1.0, v: 0.07, at: 0.62, lp: [2400, 900], vib: [5, 18] },
            { w: 'sine', f: [90, 40], d: 0.25, v: 0.2, rep: 3, gap: 0.36 }],
    attack: [{ w: 'square', f: [200, 700], d: 0.12, v: 0.035, lp: [1500, 3000] },
             { w: 'noise', d: 0.15, v: 0.06, at: 0.1, bp: [2000, 800], q: 2 }],
    phase: [{ w: 'sawtooth', f: [260, 640], d: 0.55, v: 0.08, vib: [7, 20], lp: [1500, 3000] }, thump(90, 0.1)],
    hurt: hurt(600),
    death: [{ w: 'sawtooth', f: [520, 90], d: 1.8, v: 0.1, lp: [2500, 300], vib: [5, 25] },
            { w: 'noise', d: 1.2, v: 0.08, lp: [3000, 200] }],
  },
  sobek: {      // a crocodile's growl, floodwater and a snapping jaw
    intro: [{ w: 'sawtooth', f: [70, 55], d: 1.6, v: 0.14, lp: [500, 300], vib: [18, 6], a: 0.3 },
            { w: 'square', f: [35, 30], d: 1.6, v: 0.07, lp: [200, 150], a: 0.3 },
            { w: 'noise', d: 1.4, v: 0.06, bp: [600, 300], q: 1.5, a: 0.4 },
            { w: 'noise', d: 0.08, v: 0.2, at: 1.45, hp: [1500, 1500] }],
    attack: [{ w: 'noise', d: 0.07, v: 0.12, hp: [1200, 1200] }, { w: 'sine', f: [160, 60], d: 0.12, v: 0.12 }],
    phase: [{ w: 'sawtooth', f: [65, 50], d: 0.8, v: 0.13, lp: [450, 250], vib: [18, 6] },
            { w: 'noise', d: 0.9, v: 0.08, lp: [2400, 300] }],
    hurt: hurt(300),
    death: [{ w: 'sawtooth', f: [80, 30], d: 2.0, v: 0.14, lp: [600, 120], vib: [12, 8] },
            { w: 'noise', d: 1.5, v: 0.1, lp: [2000, 200], at: 0.3 }],
  },
  umbra: {      // glass: a reversed shimmer over a low drone
    intro: [{ w: 'sine', f: [880, 1760], d: 1.2, v: 0.05, a: 0.9 },
            { w: 'triangle', f: [1320, 660], d: 1.4, v: 0.04, a: 0.8, vib: [9, 15] },
            { w: 'noise', d: 0.6, v: 0.05, at: 1.0, bp: [6000, 3000], q: 4 },
            { w: 'sawtooth', f: [55, 55], d: 1.8, v: 0.05, lp: [300, 600], a: 0.6 }],
    attack: [{ w: 'triangle', f: [1800, 900], d: 0.12, v: 0.04 }, { w: 'sine', f: [2400, 1200], d: 0.1, v: 0.02, at: 0.03 }],
    phase: [{ w: 'sawtooth', f: [110, 440], d: 0.8, v: 0.06, a: 0.7, lp: [400, 4000] }, chime(1760, 0.75, 0.04, 0.6)],
    hurt: hurt(1400),
    death: [{ w: 'noise', d: 1.2, v: 0.1, hp: [3000, 6000] },
            chime(2637, 0.05, 0.03, 0.5), chime(2093, 0.15, 0.03, 0.6), chime(1568, 0.3, 0.03, 0.8), chime(1047, 0.5, 0.04, 1.2)],
  },
  nun: {        // something vast sings in the deep; bubbles rise
    intro: [{ w: 'sine', f: [90, 140], d: 1.0, v: 0.12, vib: [3, 6], a: 0.4 },
            { w: 'sine', f: [140, 70], d: 1.3, v: 0.1, at: 0.9, vib: [3, 8] },
            { w: 'sine', f: [400, 1200], d: 0.05, v: 0.03, rep: 10, gap: 0.11, at: 0.3 },
            { w: 'noise', d: 2.0, v: 0.06, lp: [200, 120], a: 0.5 }],
    attack: [{ w: 'sine', f: [300, 900], d: 0.06, v: 0.04, rep: 3, gap: 0.05 }],
    phase: [{ w: 'sawtooth', f: [45, 45], d: 1.2, v: 0.1, a: 0.6, lp: [200, 900] }, { w: 'sine', f: [110, 165], d: 1.0, v: 0.08, vib: [3, 6] }],
    hurt: hurt(250),
    death: [{ w: 'sine', f: [120, 40], d: 2.5, v: 0.14, vib: [2, 6] },
            { w: 'sine', f: [300, 1400], d: 0.05, v: 0.03, rep: 16, gap: 0.09 }],
  },
  sokar: {      // a war-hawk's screech and beating wings
    intro: [{ w: 'sawtooth', f: [1800, 1100], d: 0.5, v: 0.12, bp: [2500, 1800], q: 3, vib: [30, 60] },
            { w: 'sawtooth', f: [2000, 900], d: 0.7, v: 0.12, at: 0.45, bp: [2600, 1500], q: 3, vib: [25, 70] },
            { w: 'noise', d: 0.18, v: 0.14, lp: [900, 300], rep: 4, gap: 0.28, at: 0.2 }],
    attack: [{ w: 'noise', d: 0.1, v: 0.06, bp: [3500, 1500], q: 2 }, { w: 'sawtooth', f: [1500, 1000], d: 0.08, v: 0.025, bp: [2000, 1500], q: 3 }],
    phase: [{ w: 'sawtooth', f: [2200, 1200], d: 0.5, v: 0.05, bp: [2800, 1800], q: 3, vib: [30, 60] },
            { w: 'noise', d: 0.18, v: 0.08, lp: [900, 300], rep: 2, gap: 0.25 }],
    hurt: hurt(1800),
    death: [{ w: 'sawtooth', f: [2000, 300], d: 1.4, v: 0.06, bp: [2400, 600], q: 3, vib: [20, 80] },
            { w: 'noise', d: 1.4, v: 0.06, bp: [1200, 400], q: 0.8, at: 0.2 }],
  },
  seraphs: {    // four cobras hiss as the lake catches fire
    intro: [hiss(1.2, 0.07), { w: 'noise', d: 1.6, v: 0.1, lp: [800, 1800], a: 0.4 },
            { w: 'square', f: [60, 60], d: 0.02, v: 0.05, rep: 12, gap: 0.09, hp: [2000, 2000] },
            { w: 'sawtooth', f: [220, 180], d: 1.0, v: 0.04, vib: [24, 20], lp: [1500, 1500], at: 0.5 }],
    attack: [{ w: 'noise', d: 0.25, v: 0.07, bp: [600, 2500], q: 1.2 }],
    phase: [{ w: 'noise', d: 0.9, v: 0.11, lp: [600, 3000], a: 0.3 }, hiss(0.6, 0.06, 0.4)],
    hurt: hurt(900),
    death: [hiss(1.6, 0.08), { w: 'noise', d: 2.0, v: 0.1, lp: [2500, 150] },
            { w: 'square', f: [60, 60], d: 0.02, v: 0.04, rep: 16, gap: 0.12, hp: [2000, 2000] }],
  },
  umbra_coiled: {   // UMBRA's glass, wound in Apep's hiss
    intro: [hiss(1.5, 0.08), { w: 'sine', f: [880, 1760], d: 1.2, v: 0.045, a: 0.9 },
            { w: 'sawtooth', f: [49, 49], d: 1.8, v: 0.06, lp: [250, 700], a: 0.6 },
            { w: 'triangle', f: [1320, 620], d: 1.0, v: 0.035, at: 0.8, vib: [12, 25] }],
    attack: [hiss(0.18, 0.05), { w: 'triangle', f: [1700, 850], d: 0.12, v: 0.035, at: 0.04 }],
    phase: [hiss(0.8, 0.08), { w: 'sawtooth', f: [98, 392], d: 0.8, v: 0.06, a: 0.7, lp: [400, 4000] }],
    hurt: hurt(1200),
    death: [hiss(1.8, 0.08), { w: 'noise', d: 1.2, v: 0.1, hp: [3000, 6000], at: 0.2 },
            chime(2489, 0.25, 0.03, 0.5), chime(1865, 0.4, 0.03, 0.7), chime(1245, 0.6, 0.035, 1.2)],
  },
  hittite: {    // an iron engine spins up; rotors clank; a war horn
    intro: [{ w: 'sawtooth', f: [40, 110], d: 1.6, v: 0.1, lp: [300, 900], a: 0.4 },
            { w: 'square', f: [80, 220], d: 1.6, v: 0.035, lp: [500, 1200], a: 0.4 },
            { w: 'noise', d: 0.05, v: 0.12, bp: [2500, 2500], q: 6, rep: 4, gap: 0.35 },
            { w: 'sawtooth', f: [110, 104], d: 1.0, v: 0.08, at: 1.2, lp: [900, 700], a: 0.08 }],
    attack: [thump(120, 0, 0.15), { w: 'noise', d: 0.12, v: 0.07, lp: [1800, 400] }],
    phase: [{ w: 'sawtooth', f: [110, 104], d: 0.9, v: 0.08, lp: [900, 700], a: 0.08 },
            { w: 'noise', d: 0.05, v: 0.12, bp: [2500, 2500], q: 6, rep: 2, gap: 0.2 }],
    hurt: hurt(500),
    death: [{ w: 'sawtooth', f: [120, 25], d: 2.2, v: 0.12, lp: [900, 150] },
            { w: 'noise', d: 0.06, v: 0.1, bp: [3000, 2000], q: 5, rep: 7, gap: 0.17, at: 0.2 }],
  },
  ammit: {      // a beast's roar, then the scales of judgement ring
    intro: [{ w: 'sawtooth', f: [110, 80], d: 1.4, v: 0.12, lp: [900, 500], vib: [20, 10], a: 0.15 },
            { w: 'noise', d: 1.3, v: 0.08, bp: [500, 300], q: 1, a: 0.15 },
            chime(880, 1.3, 0.06, 1.4), chime(1318, 1.3, 0.035, 1.2)],
    attack: [{ w: 'noise', d: 0.06, v: 0.1, hp: [1500, 1500] }, thump(140, 0.02, 0.12)],
    phase: [chime(440, 0, 0.07, 1.6), chime(660, 0, 0.04, 1.4), chime(880, 0.02, 0.03, 1.0)],
    hurt: hurt(400),
    death: [{ w: 'sawtooth', f: [120, 40], d: 1.8, v: 0.12, lp: [900, 150], vib: [16, 10] },
            chime(880, 1.0, 0.05, 1.8), chime(1108, 1.0, 0.035, 1.6)],
  },
  overlord_echo: {  // the Overlord's crystal chord, ringing back from the dark
    intro: [{ w: 'sine', f: [523, 523], d: 2.0, v: 0.04, a: 0.6, rep: 3, gap: 0.4 },
            { w: 'sine', f: [659, 659], d: 1.8, v: 0.035, a: 0.6, at: 0.1, rep: 3, gap: 0.4 },
            { w: 'sine', f: [784, 784], d: 1.6, v: 0.03, a: 0.6, at: 0.2, rep: 3, gap: 0.4 },
            { w: 'sawtooth', f: [65, 65], d: 2.4, v: 0.05, lp: [200, 500], a: 0.8 }],
    attack: [{ w: 'triangle', f: [1568, 1568], d: 0.2, v: 0.035, rep: 2, gap: 0.15 }],
    phase: [{ w: 'sawtooth', f: [523, 523], d: 0.5, v: 0.04, lp: [3000, 800] },
            { w: 'sawtooth', f: [622, 622], d: 0.5, v: 0.035, lp: [3000, 800] },
            { w: 'sawtooth', f: [784, 784], d: 0.5, v: 0.03, lp: [3000, 800] }],
    hurt: hurt(2000),
    death: [{ w: 'noise', d: 1.4, v: 0.1, hp: [2500, 7000] },
            { w: 'triangle', f: [2093, 2093], d: 0.4, v: 0.03, rep: 6, gap: 0.18, at: 0.1 }, chime(523, 0.4, 0.04, 2.0)],
  },
  umbra_unmasked: { // the mask tears; the hero's golden chord breaks through
    intro: [{ w: 'noise', d: 0.8, v: 0.18, bp: [300, 4000], q: 3 },
            { w: 'sawtooth', f: [220, 220], d: 1.4, v: 0.08, lp: [400, 3000], a: 0.5, at: 0.6 },
            { w: 'sawtooth', f: [277, 277], d: 1.4, v: 0.07, lp: [400, 3000], a: 0.5, at: 0.6 },
            { w: 'sawtooth', f: [330, 330], d: 1.4, v: 0.06, lp: [400, 3000], a: 0.5, at: 0.6 }],
    attack: [{ w: 'square', f: [1200, 2400], d: 0.08, v: 0.03 }, { w: 'triangle', f: [1800, 900], d: 0.1, v: 0.03, at: 0.04 }],
    phase: [{ w: 'noise', d: 0.3, v: 0.1, bp: [800, 3000], q: 2 }, chime(1760, 0.2, 0.04, 0.8)],
    hurt: hurt(1600),
    death: [{ w: 'noise', d: 1.0, v: 0.09, hp: [3000, 6000] },
            chime(440, 0.4, 0.05, 2.2), chime(554, 0.5, 0.045, 2.1), chime(659, 0.6, 0.04, 2.0), chime(880, 0.7, 0.035, 1.9)],
  },
  apep: {       // the Serpent of Unmaking
    intro: [{ w: 'sawtooth', f: [55, 38], d: 2.4, v: 0.16, lp: [400, 180], vib: [10, 4], a: 0.4 },
            { w: 'sine', f: [40, 30], d: 2.4, v: 0.2, a: 0.4 },
            hiss(1.4, 0.08, 1.2), { w: 'triangle', f: [1760, 880], d: 1.8, v: 0.02, at: 0.2, vib: [7, 30] }],
    attack: [thump(70, 0, 0.16), hiss(0.2, 0.05, 0.05)],
    phase: [{ w: 'sawtooth', f: [60, 40], d: 1.2, v: 0.14, lp: [500, 200], vib: [10, 4] }, hiss(0.9, 0.08, 0.3),
            { w: 'noise', d: 0.4, v: 0.08, hp: [2500, 5000], at: 0.1 }],
    hurt: hurt(200),
    death: [{ w: 'sawtooth', f: [70, 20], d: 3.2, v: 0.16, lp: [500, 80], vib: [8, 6] }, { w: 'sine', f: [45, 22], d: 3.2, v: 0.2 },
            { w: 'noise', d: 1.6, v: 0.1, hp: [3000, 7000], at: 0.6 }, hiss(2.0, 0.06, 1.0)],
  },
};
const CUES = ['intro', 'attack', 'phase', 'hurt', 'death'];
const LIMIT = { attack: 0.45, hurt: 0.1, down: 0.12, wave: 1.5, move: 0.08 };
const DUCK = { intro: 1, death: 1, phase: 1, start: 1, launch: 1, begin: 1, dawn: 1, denied: 1 };   // cues the music steps back for   // seconds between repeats, so a barrage doesn't become noise
// Ambience (registered by stage_audio.js): looping beds plus scattered events. A bed is one held source:
// w, f, v, one filter (lp/hp/bp in Hz, q), trem = [rate Hz, depth 0..1] on its level, sweep = [rate Hz, Hz] on its filter.
// An event is { every: [min, max] seconds, layers: [voice layers] }.
const AMBIENCE = {};

// ------------------------------------------------------------------ compile themes to MIDI
function degree(rootNote, scale, d){
  const s = SCALES[scale], n = s.length, o = Math.floor(d / n);
  return rootNote + 12 * o + s[((d % n) + n) % n];
}
function line(spec, text, base){
  return text.trim().split(/\s+/).map(tok => {
    if (tok === '.') return 0;
    const v = Number(tok);
    return spec.raw ? v + (spec.transpose || 0) : degree(base, spec.scale, v);
  });
}
function compile(id){
  const s = THEMES[id];
  const bass = line(s, s.bass, s.root), lead = line(s, s.lead, (s.root || 0) + 24);
  // pads follow the bass: a triad on it (scale triad for degree themes, minor triad for MIDI ones)
  const padChord = midi => s.raw ? [midi + 12, midi + 15, midi + 19]
    : [midi + 12, degree(midi + 12, s.scale, 2), degree(midi + 12, s.scale, 4)];
  return { id, bpm: s.bpm, stepDur: 60 / s.bpm / 2, bass, lead, drums: s.drums, padChord: s.pad ? padChord : null,
    bassType: s.bassType || 'triangle', bassVol: s.bassVol || 0.06, bassLp: s.bassLp || 0, sub: !!s.sub,
    leadType: s.leadType || 'square', leadVol: s.leadVol || 0.03, leadLp: s.leadLp || 0, leadLen: s.leadLen || 0.85,
    echo: !!s.echo, padVol: s.padVol || 0.012 };
}
const COMPILED = {};
for (const id in THEMES) COMPILED[id] = compile(id);
// more content (the stages) plugs in here: { themes, voices, ambience }
function register(pack){
  for (const id in pack.themes || {}){ THEMES[id] = pack.themes[id]; COMPILED[id] = compile(id); }
  Object.assign(VOICES, pack.voices || {});
  Object.assign(AMBIENCE, pack.ambience || {});
}
const hz = midi => 440 * Math.pow(2, (midi - 69) / 12);

// ------------------------------------------------------------------ the engine
function createEngine(ctx, destination){
  const master = ctx.createDynamicsCompressor();
  master.threshold.value = -16; master.knee.value = 8; master.ratio.value = 4;
  master.attack.value = 0.004; master.release.value = 0.2;
  master.connect(destination || ctx.destination);
  const musicBus = ctx.createGain(); musicBus.gain.value = 0.85; musicBus.connect(master);
  const sfxBus = ctx.createGain(); sfxBus.gain.value = 1; sfxBus.connect(master);
  const ambBus = ctx.createGain(); ambBus.gain.value = 0.65; ambBus.connect(master);
  const noise = ctx.createBuffer(1, Math.floor(ctx.sampleRate * 2), ctx.sampleRate);
  { const ch = noise.getChannelData(0); let x = 12345;
    for (let i = 0; i < ch.length; i++){ x = (x * 1103515245 + 12345) % 2147483648; ch[i] = x / 1073741824 - 1; } }

  function sweep(param, f, t, d){
    const a = Array.isArray(f) ? f[0] : f, b = Array.isArray(f) ? f[1] : f;
    param.setValueAtTime(a, t);
    if (b !== a) param.exponentialRampToValueAtTime(b, t + d);
  }
  function layer(L, t0, bus){
    for (let r = 0; r < (L.rep || 1); r++){
      const t = t0 + (L.at || 0) + r * (L.gap || 0), d = L.d;
      let src, lfo = null;
      if (L.w === 'noise'){ src = ctx.createBufferSource(); src.buffer = noise; src.loop = true; }
      else {
        src = ctx.createOscillator(); src.type = L.w; sweep(src.frequency, L.f, t, d);
        if (L.vib){
          lfo = ctx.createOscillator(); lfo.frequency.value = L.vib[0];
          const lg = ctx.createGain(); lg.gain.value = L.vib[1]; lfo.connect(lg); lg.connect(src.frequency);
        }
      }
      let node = src;
      for (const [key, type] of [['lp', 'lowpass'], ['hp', 'highpass'], ['bp', 'bandpass']]){
        if (!L[key]) continue;
        const fl = ctx.createBiquadFilter(); fl.type = type; fl.Q.value = L.q || 0.8;
        sweep(fl.frequency, L[key], t, d); node.connect(fl); node = fl;
      }
      const g = ctx.createGain(), att = Math.min(L.a || 0.008, d * 0.8);
      g.gain.setValueAtTime(0.0001, t);
      g.gain.linearRampToValueAtTime(L.v, t + att);
      g.gain.exponentialRampToValueAtTime(0.0001, t + d);
      node.connect(g); g.connect(bus);
      src.start(t); src.stop(t + d + 0.05);
      if (lfo){ lfo.start(t); lfo.stop(t + d + 0.05); }
    }
  }
  function note(midi, t, d, type, vol, lp, a){
    if (!midi) return;
    layer({ w: type, f: hz(midi), d, v: vol, lp: lp ? [lp, lp] : null, a: a || 0.012 }, t, musicBus);
  }
  function drum(kind, t, vol = 1){
    if (kind === 'k') layer({ w: 'sine', f: [150, 42], d: 0.14, v: 0.13 * vol }, t, musicBus);
    else if (kind === 's'){
      layer({ w: 'noise', d: 0.13, v: 0.06 * vol, bp: [1800, 1800], q: 0.7 }, t, musicBus);
      layer({ w: 'triangle', f: [190, 150], d: 0.08, v: 0.04 * vol }, t, musicBus);
    } else if (kind === 'h') layer({ w: 'noise', d: 0.035, v: 0.022 * vol, hp: [7000, 7000] }, t, musicBus);
  }
  function step(th, i, t, lvl){
    const sd = th.stepDur, b = th.bass[i % th.bass.length], l = th.lead[i % th.lead.length];
    if (b){
      note(b, t, sd * 0.92, th.bassType, th.bassVol, th.bassLp);
      if (th.sub) note(b - 12, t, sd * 0.95, 'sine', th.bassVol * 0.8);
      if (lvl >= 3) note(b + 12, t, sd * 0.6, 'square', th.bassVol * 0.3, 1400);
    }
    if (l){
      note(l, t, sd * th.leadLen, th.leadType, th.leadVol * (lvl >= 2 ? 1 : 0.5), th.leadLp);
      if (th.echo) note(l, t + sd * 1.5, sd * th.leadLen, th.leadType, th.leadVol * 0.35, th.leadLp);
      if (lvl >= 3) note(l + 12, t, sd * th.leadLen * 0.8, 'triangle', th.leadVol * 0.55);
    }
    if (th.padChord && i % 8 === 0){
      const root = th.bass[i % th.bass.length] || th.bass.find(n => n);
      for (const n of th.padChord(root)) note(n, t, sd * 8, 'sawtooth', th.padVol, 800, 0.3);
    }
    const k = th.drums[i % th.drums.length];
    if (k === 'k') drum('k', t);
    if (lvl >= 2 && (k === 's' || k === 'h')) drum(k, t);
    if (lvl >= 3) drum('h', t + sd / 2, 0.7);
  }

  // ambience: beds run until stopped; events are drawn from a seeded generator so offline renders repeat exactly
  function rng(seed){ let a = seed >>> 0; return () => { a = (a + 0x6D2B79F5) >>> 0; let t = a;
    t = Math.imul(t ^ (t >>> 15), t | 1); t ^= t + Math.imul(t ^ (t >>> 7), t | 61); return ((t ^ (t >>> 14)) >>> 0) / 4294967296; }; }
  function startBeds(spec, t){
    return spec.beds.map(B => {
      let src;
      if (B.w === 'noise'){ src = ctx.createBufferSource(); src.buffer = noise; src.loop = true; }
      else { src = ctx.createOscillator(); src.type = B.w; src.frequency.value = B.f; }
      const stops = [src];
      let node = src;
      const key = B.lp ? 'lp' : B.hp ? 'hp' : B.bp ? 'bp' : null;
      if (key){
        const fl = ctx.createBiquadFilter();
        fl.type = { lp: 'lowpass', hp: 'highpass', bp: 'bandpass' }[key]; fl.frequency.value = B[key]; fl.Q.value = B.q || 0.8;
        if (B.sweep){
          const o = ctx.createOscillator(), og = ctx.createGain();
          o.frequency.value = B.sweep[0]; og.gain.value = B.sweep[1]; o.connect(og); og.connect(fl.frequency); stops.push(o);
        }
        node.connect(fl); node = fl;
      }
      const env = ctx.createGain();                       // fades the bed in and out
      env.gain.setValueAtTime(0.0001, t); env.gain.linearRampToValueAtTime(B.v, t + 1.5);
      node.connect(env); node = env;
      if (B.trem){                                        // slow swell, after the fade so silence stays silent
        const tg = ctx.createGain(); tg.gain.value = 1 - B.trem[1] / 2;
        const o = ctx.createOscillator(), og = ctx.createGain();
        o.frequency.value = B.trem[0]; og.gain.value = B.trem[1] / 2; o.connect(og); og.connect(tg.gain); stops.push(o);
        node.connect(tg); node = tg;
      }
      node.connect(ambBus);
      for (const n of stops) n.start(t);
      return { env, stops };
    });
  }
  function stopBeds(beds, t){
    for (const b of beds){
      b.env.gain.cancelScheduledValues(t);
      b.env.gain.setValueAtTime(Math.max(b.env.gain.value, 0.0001), t);
      b.env.gain.linearRampToValueAtTime(0.0001, t + 0.8);
      for (const n of b.stops) n.stop(t + 0.85);
    }
  }
  function eventsUntil(amb, until){
    amb.spec.events.forEach((E, i) => {
      while (amb.next[i] < until){
        for (const L of E.layers) layer(L, amb.next[i], ambBus);
        amb.next[i] += E.every[0] + amb.rand() * (E.every[1] - E.every[0]);
      }
    });
  }
  function openAmbience(id, t){
    const spec = AMBIENCE[id]; if (!spec) return null;
    const rand = rng(id.length * 7919 + 17);
    return { id, spec, rand, beds: startBeds(spec, t), next: spec.events.map(E => t + 1 + rand() * E.every[1]) };
  }

  const last = {};
  const live = { theme: null, step: 0, nextT: 0, layer: 1, timer: null, amb: null };
  function pump(){
    const th = live.theme;
    if (th) while (live.nextT < ctx.currentTime + 0.15){
      step(th, live.step, live.nextT, live.layer);
      live.step++; live.nextT += th.stepDur;
    }
    if (live.amb) eventsUntil(live.amb, ctx.currentTime + 0.15);
  }
  function timer(){
    const need = !!(live.theme || live.amb);
    if (need && !live.timer && typeof setInterval === 'function') live.timer = setInterval(pump, 25);
    if (!need && live.timer){ clearInterval(live.timer); live.timer = null; }
  }
  function duck(t, d){
    musicBus.gain.cancelScheduledValues(t);
    musicBus.gain.setValueAtTime(musicBus.gain.value, t);
    musicBus.gain.linearRampToValueAtTime(0.4, t + 0.08);
    musicBus.gain.setValueAtTime(0.4, t + d);
    musicBus.gain.linearRampToValueAtTime(0.85, t + d + 0.6);
  }
  return {
    hasTheme: id => !!COMPILED[id],
    hasVoice: (id, cue) => !!(VOICES[id] && VOICES[id][cue]),
    hasAmbience: id => !!AMBIENCE[id],
    get playing(){ return live.theme ? live.theme.id : null; },
    get ambient(){ return live.amb ? live.amb.id : null; },
    voice(id, cue, when){
      const layers = VOICES[id] && VOICES[id][cue];
      if (!layers) return false;
      const t = when === undefined ? ctx.currentTime + 0.01 : when, key = id + ':' + cue;
      if (LIMIT[cue] && last[key] !== undefined && t - last[key] < LIMIT[cue]) return false;
      last[key] = t;
      for (const L of layers) layer(L, t, sfxBus);
      if (DUCK[cue])
        duck(t, Math.max(...layers.map(L => (L.at || 0) + (L.rep ? (L.rep - 1) * (L.gap || 0) : 0) + L.d)) * 0.7);
      return true;
    },
    startTheme(id, lvl, delay){                     // delay: seconds of silence first (after a fanfare or a cry)
      this.stopTheme();
      const th = COMPILED[id]; if (!th) return false;
      Object.assign(live, { theme: th, step: 0, nextT: ctx.currentTime + 0.06 + (delay || 0), layer: lvl || 1 });
      pump(); timer();
      return true;
    },
    stopTheme(){ live.theme = null; timer(); },
    startAmbience(id){
      if (live.amb && live.amb.id === id) return true;
      this.stopAmbience();
      live.amb = openAmbience(id, ctx.currentTime + 0.02);
      timer();
      return !!live.amb;
    },
    stopAmbience(){ if (live.amb) stopBeds(live.amb.beds, ctx.currentTime); live.amb = null; timer(); },
    setLayer(n){ live.layer = Math.max(1, Math.min(3, n)); },
    // offline rendering (previews, tests): schedule `seconds` of a theme up front; layer may be a function of time
    scheduleTheme(id, seconds, lvl, start){
      const th = COMPILED[id]; let t = start || 0.05, i = 0;
      while (t < seconds){ step(th, i++, t, typeof lvl === 'function' ? lvl(t) : (lvl || 1)); t += th.stepDur; }
      return i;
    },
    scheduleAmbience(id, seconds, start){
      const amb = openAmbience(id, start || 0); if (!amb) return false;
      eventsUntil(amb, seconds - 1); stopBeds(amb.beds, seconds - 0.9);
      return true;
    },
    musicBus, sfxBus, ambBus,
  };
}

const API = { THEMES, VOICES, CUES, SCALES, COMPILED, AMBIENCE, LIMIT, createEngine, register,
  kit: { hiss, chime, thump, degree, hz } };
root.KeeperAudio = API;
if (typeof module !== 'undefined' && module.exports) module.exports = API;
})(typeof window !== 'undefined' ? window : globalThis);
