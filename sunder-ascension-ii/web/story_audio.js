/* SUNDER: Ascension II — audio for the story screens and the hour map. Plugs into the engine in keeper_audio.js.
   Opening crawl, hour map (building act by act), Hour briefings (over that Hour's own ambience), act interludes,
   the true ending at dawn, and DAWN DENIED. Cues are voices of id 'story'. Same notation as keeper_audio.js. */
(function (root) {
'use strict';
const KA = root.KeeperAudio || (typeof require === 'function' ? require('./keeper_audio.js') : null);
const { chime } = KA.kit;
const QUIET = '................';

const themes = {
  // the crawl: a slow desert lament, one deep drum per bar
  story_opening: { bpm: 72, root: 38, scale: 'hijaz', bassType: 'triangle', bassVol: 0.12, leadType: 'sine', leadVol: 0.08, leadLen: 2,
    pad: true, padVol: 0.02, echo: true,
    bass: '0 . . . . . . . . . . . . . . . 1 . . . . . . . 0 . . . . . . .',
    lead: '7 . . . 8 . . . 7 . . . 5 . 4 . 4 . . . . . . . . . . . . . . . 4 . 5 . 7 . 8 . 7 . . . . . . . 5 . 4 . 1 . . . 0 . . . . . . .',
    drums: 'k...............................' },
  // the hour map: the road to dawn; its layer climbs with the act
  story_map: { bpm: 100, root: 45, scale: 'dorian', bassType: 'triangle', bassVol: 0.07, leadType: 'square', leadVol: 0.024, pad: true,
    bass: '0 . . 0 4 . . . 3 . . 3 2 . . .',
    lead: '4 . 5 . 7 . . . 6 . 5 . 4 . . . 2 . 4 . 5 . 4 . 2 . 1 . 0 . . .',
    drums: 'k...h...k.k.h...' },
  // a briefing: low and watchful, under the Hour's own ambience
  story_briefing: { bpm: 90, root: 40, scale: 'phrygian', bassType: 'sawtooth', bassLp: 300, bassVol: 0.06, leadType: 'sine', leadVol: 0.035, echo: true,
    bass: '0 . . . . . . . 0 . . . . . . 1',
    lead: '. . . . . . . . 8 . . 7 . . . . . . . . . . . . 5 . . 4 . . . .',
    drums: 'k.......k.......' },
  // between acts: the hero's theme remembered, slow
  story_interlude: { bpm: 76, raw: true, bassType: 'triangle', bassVol: 0.12, leadType: 'triangle', leadVol: 0.08, leadLen: 2.5, pad: true, padVol: 0.024,
    bass: '45 . . . . . . . 41 . . . . . . . 38 . . . . . . . 40 . . . . . . .',
    lead: '69 . . . 72 . . . 76 . . . 74 . . . 72 . . . . . . . 69 . . . . . . .',
    drums: QUIET },
  // the true ending: the hero's theme in a major key, at sunrise
  story_victory: { bpm: 120, raw: true, bassType: 'triangle', bassVol: 0.08, leadType: 'square', leadVol: 0.03, pad: true,
    bass: '45 . 45 . 50 . 50 . 52 . 52 . 45 . 49 .',
    lead: '69 . 73 76 . 74 73 . 69 . 73 76 81 . 78 76 81 . 80 78 . 76 74 . 76 . 78 81 85 . . .',
    drums: 'k.h.s.h.k.h.s.hs' },
  // DAWN DENIED
  story_defeat: { bpm: 66, raw: true, bassType: 'triangle', bassVol: 0.11, leadType: 'triangle', leadVol: 0.07, leadLen: 2, pad: true, padVol: 0.022,
    bass: '45 . . . . . . . 44 . . . . . . . 43 . . . . . . . 41 . . . 40 . . .',
    lead: '76 . . . 74 . . . 72 . . . 71 . . . 69 . . . . . . . 68 . . . 69 . . .',
    drums: QUIET },
};

const voices = {
  story: {
    begin: [{ w: 'sine', f: [110, 108], d: 4, v: 0.08, a: 0.02 }, { w: 'sine', f: [220, 216], d: 3, v: 0.03 },      // gong
            { w: 'sine', f: [60, 38], d: 1.2, v: 0.14 }, { w: 'noise', d: 2.5, v: 0.04, lp: [1200, 150], a: 0.05 }],
    map: [{ w: 'noise', d: 0.6, v: 0.06, bp: [400, 2500], q: 0.8, a: 0.3 }, chime(1320, 0.5, 0.03, 1.0)],          // onto the map
    gate: [chime(880, 0, 0.04, 1.2), chime(1320, 0.08, 0.035, 1.2),                                                 // a gate opens
           { w: 'sawtooth', f: [110, 220], d: 0.8, v: 0.04, lp: [300, 2000], a: 0.2 }],
    briefing: [{ w: 'square', f: [1500, 1500], d: 0.03, v: 0.015, rep: 4, gap: 0.06, lp: [3000, 3000] },            // transmission
               { w: 'sawtooth', f: [82, 78], d: 1.2, v: 0.06, lp: [600, 300], at: 0.3, a: 0.1 }],
    interlude: [chime(330, 0, 0.06, 3.5), chime(495, 0, 0.03, 3)],                                                  // a bell between acts
    dawn: [...[220, 277, 330, 440].map(f => ({ w: 'sawtooth', f, d: 3.5, v: 0.035, lp: [400, 3000], a: 1.0 })),     // sunrise
           chime(1760, 1.0, 0.03, 2), chime(2217, 1.3, 0.025, 2), chime(2637, 1.6, 0.025, 2),
           { w: 'noise', d: 2.5, v: 0.05, lp: [300, 5000], a: 1.2 }],
    denied: [{ w: 'sawtooth', f: [220, 55], d: 2.2, v: 0.07, lp: [1500, 200] }, { w: 'sine', f: [65, 60], d: 3, v: 0.1 },
             { w: 'noise', d: 2, v: 0.05, lp: [800, 100] }],
  },
};

const ambience = {
  story_opening: { beds: [{ w: 'noise', v: 0.035, bp: 300, q: 0.7, trem: [0.07, 0.7], sweep: [0.04, 150] },     // wind in the void
                          { w: 'sine', f: 55, v: 0.01, trem: [0.1, 0.5] }],
    events: [{ every: [9, 14], layers: [chime(220, 0, 0.02, 4)] }, { every: [3, 6], layers: [chime(2093, 0, 0.006, 1.5)] }] },
  story_map: { beds: [{ w: 'noise', v: 0.012, hp: 6000, trem: [0.3, 0.6] }, { w: 'sine', f: 98, v: 0.008, trem: [0.25, 0.5] }],  // stars, gates
    events: [{ every: [1.5, 3.5], layers: [chime(3136, 0, 0.006, 1.2)] },
             { every: [8, 14], layers: [{ w: 'square', f: [1200, 1200], d: 0.04, v: 0.008, rep: 3, gap: 0.08, lp: [3000, 3000] }] }] },
};

KA.register({ themes, voices, ambience });
KA.STORY_CUES = ['begin', 'map', 'gate', 'briefing', 'interlude', 'dawn', 'denied'];
if (typeof module !== 'undefined' && module.exports) module.exports = KA;
})(typeof window !== 'undefined' ? window : globalThis);
