//
//   CSAcademy Problem - Rigged Dice
//   From: IEEEXtreme 15.0
//   Solved By: Dimitrios and Petros Papakonstantinou
//   Submission Score: 100/100 (1957ms - 36.6MB)
//

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let gameNum;
let currentGame = 0;
let n;
let currentRoll = 0;

function processGame() {
  let d1 = [], d2 = [];
  let aliceTotal = 0, bobTotal = 0;
  let currentAliceDie1 = true;

  function processRoll() {
    rl.question('', (line) => {
      const [alice, bob] = line.split(' ').map(Number);
      aliceTotal += alice;
      bobTotal += bob;

      if (currentAliceDie1) {
        d1.push(alice);
        d2.push(bob);
      } else {
        d2.push(alice);
        d1.push(bob);
      }

      if (aliceTotal !== bobTotal) {
        currentAliceDie1 = !currentAliceDie1;
      }

      currentRoll++;
      if (currentRoll < n) {
        processRoll();
      } else {
        const d1Count = d1.filter(x => x === 6).length;
        const d2Count = d2.filter(x => x === 6).length;

        console.log(d1Count > d2Count ? '1' : '2');

        currentGame++;
        if (currentGame < gameNum) {
          startNextGame();
        } else {
          rl.close();
        }
      }
    });
  }

  rl.question('', (input) => {
    n = parseInt(input);
    currentRoll = 0;
    processRoll();
  });
}

function startNextGame() {
  processGame();
}

rl.question('', (input) => {
  gameNum = parseInt(input);
  startNextGame();
});
