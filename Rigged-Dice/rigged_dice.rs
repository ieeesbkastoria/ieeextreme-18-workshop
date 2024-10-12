//
//   CSAcademy Problem - Rigged Dice
//   From: IEEEXtreme 15.0
//   Solved By: Dimitrios and Petros Papakonstantinou
//   Submission Score: 100/100 (74ms - 780KB)
//

use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    // Read number of games
    let game_num: i32 = lines.next().unwrap().unwrap().trim().parse().unwrap();

    for _ in 0..game_num {
        // Read number of rounds for each game
        let n: i32 = lines.next().unwrap().unwrap().trim().parse().unwrap();

        let mut d1 = Vec::new();
        let mut d2 = Vec::new();
        let mut alice_total = 0;
        let mut bob_total = 0;
        let mut current_alice_die1 = true;

        for _ in 0..n {
            let round: Vec<i32> = lines
                .next()
                .unwrap()
                .unwrap()
                .split_whitespace()
                .map(|x| x.parse().unwrap())
                .collect();

            let alice = round[0];
            let bob = round[1];

            alice_total += alice;
            bob_total += bob;

            if current_alice_die1 {
                d1.push(alice);
                d2.push(bob);
            } else {
                d2.push(alice);
                d1.push(bob);
            }

            if alice_total != bob_total {
                current_alice_die1 = !current_alice_die1;
            }
        }

        let d1_count = d1.iter().filter(|&&x| x == 6).count();
        let d2_count = d2.iter().filter(|&&x| x == 6).count();

        if d1_count > d2_count {
            println!("1");
        } else {
            println!("2");
        }
    }
}
