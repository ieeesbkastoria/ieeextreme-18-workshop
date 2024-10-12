//
//   CSAcademy Problem - Rigged Dice
//   From: IEEEXtreme 15.0
//   Solved By: Dimitrios and Petros Papakonstantinou
//   Submission Score: 100/100 (180ms - 780KB)
//

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(void) {
  int game_num;
  std::cin >> game_num;
  std::cin.ignore(); // Consume newline

  for (int game = 0; game < game_num; ++game) {
    int n;
    std::cin >> n;
    std::cin.ignore(); // Consume newline

    std::vector<int> d1, d2;
    int alice_total = 0, bob_total = 0;
    bool current_alice_die1 = true;

    for (int i = 0; i < n; ++i) {
      std::string line;
      std::getline(std::cin, line);
      std::istringstream iss(line);
      int alice, bob;
      iss >> alice >> bob;

      alice_total += alice;
      bob_total += bob;

      if (current_alice_die1) {
        d1.push_back(alice);
        d2.push_back(bob);
      } else {
        d2.push_back(alice);
        d1.push_back(bob);
      }

      if (alice_total != bob_total) {
        current_alice_die1 = !current_alice_die1;
      }
    }

    int d1_count = std::count(d1.begin(), d1.end(), 6);
    int d2_count = std::count(d2.begin(), d2.end(), 6);

    if (d1_count > d2_count) {
      std::cout << "1" << std::endl;
    } else {
      std::cout << "2" << std::endl;
    }
  }

  return 0;
}
