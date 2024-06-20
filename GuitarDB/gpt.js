const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// 定义吉他音符顺序
const notes = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B'];

// 获取音符和八度
function getNoteAndOctave(startNote, fret) {
  const [note, octave] = startNote;
  const noteIndex = notes.indexOf(note);
  const newNoteIndex = (noteIndex + fret) % 12;
  const newOctave = octave + Math.floor((noteIndex + fret) / 12);
  return [notes[newNoteIndex], newOctave];
}

// 吉他调音
const standardTuning = [
  ['E', 2], ['A', 2], ['D', 3], ['G', 3], ['B', 3], ['E', 4]
];

rl.question('Enter number of strings (default 6): ', (numOfStringInput) => {
  const numOfString = numOfStringInput ? parseInt(numOfStringInput) : 6;

  rl.question('Enter number of frets (default 22): ', (numOfFretInput) => {
    const numOfFret = numOfFretInput ? parseInt(numOfFretInput) : 22;

    rl.question('Enter tuning (default EADGBE): ', (tuningInput) => {
      const tuning = tuningInput ? tuningInput : 'EADGBE';

      const userTuning = tuning.split('').map((note, i) => [note, standardTuning[i][1]]);
      
      console.log('\nGuitar Fretboard:\n');
      for (let string = 0; string < numOfString; string++) {
        let fretboardLine = `String ${numOfString - string}: `;
        for (let fret = 0; fret <= numOfFret; fret++) {
          const [note, octave] = getNoteAndOctave(userTuning[string], fret);
          fretboardLine += `${note}${octave} `;
        }
        console.log(fretboardLine);
      }
      rl.close();
    });
  });
});
