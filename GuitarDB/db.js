class Fret {
    constructor(stringNumber, fretNumber, note, octave) {
        this.stringNumber = stringNumber;
        this.fretNumber = fretNumber;
        this.note = note;
        this.octave = octave;
    }
}

var notes = ['A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#'];

class FretBoard {
    constructor(numberOfStrings = 6, numberOfFrets = 22, tuning = "EADGBE") {

        this.numberOfStrings = numberOfStrings;
        this.numberOfFrets = numberOfFrets;
        this.tuning = tuning;

        this.frets = [];

        for (let s = numberOfStrings; s >= 1; s--) {

            frets[s] = [];

            // set base note
            if (s == numberOfStrings) {
                this.frets[s][0] = new Fret(s, 0, tuning[numberOfStrings - s], 2);
            } else if (s == 2) {
                this.frets[s][0] = new Fret(s, 0, tuning[numberOfStrings - s], 3);
            }

            for (let f = 0; f < numberOfFrets + 1; f++) {

                // set the base note
                if (s == numberOfStrings && f == 0) {
                    this.frets[s][f] = new Fret(s, f, tuning[0], 2);
                } else {
                    this.frets[s][f] = new Fret(s, f, notes[(notes.indexOf(this.frets[s][f - 1].note) + 1) % notes.length], this.frets[s][f - 1].octave);
                    // if previous fret was a B, increment the octave
                    if (this.frets[s][f - 1].note == 'B') {
                        this.frets[s][f].octave++;
                    }
                }

            }
        }

    }

    ascendNote(note, octave, gap) {
        let index = notes.indexOf(note);
        let newNote = notes[(index + gap) % notes.length];
        if (index + gap >= notes.length) {
            octave++;
        }
        return [newNote, octave];
    }

    a(note, octave, gap) {
        let index = notes.indexOf(note);
        let newNote = notes[(index + gap) % notes.length];
        let newOctave = octave += Math.floor((index + gap) / notes.length);
        return [newNote, newOctave];
    }
}