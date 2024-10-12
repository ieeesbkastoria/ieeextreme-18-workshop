//
//   CSAcademy Problem - Rigged Dice
//   From: IEEEXtreme 15.0
//   Solved By: Dimitrios and Petros Papakonstantinou
//   Submission Score: 100/100 (112ms - 776KB)
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000
#define MAX_ROUNDS 1000

int count_sixes(int *arr, int size) {
  int count = 0;
  for (int i = 0; i < size; ++i) {
    if (arr[i] == 6)
      ++count;
  }
  return count;
}

int main(void) {
  int game_num;
  if (scanf("%d", &game_num) != 1) {
    fprintf(stderr, "Error reading number of games\n");
    return 1;
  }
  getchar(); // Consume newline

  for (int game = 0; game < game_num; ++game) {
    int n;
    if (scanf("%d", &n) != 1) {
      fprintf(stderr, "Error reading number of rounds\n");
      return 1;
    }
    getchar(); // Consume newline

    int d1[MAX_ROUNDS], d2[MAX_ROUNDS];
    int d1_size = 0, d2_size = 0;
    int alice_total = 0, bob_total = 0;
    int current_alice_die1 = 1; // 1 for true, 0 for false

    char line[MAX_LINE];
    for (int i = 0; i < n; ++i) {
      if (fgets(line, sizeof(line), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        return 1;
      }

      int alice, bob;
      if (sscanf(line, "%d %d", &alice, &bob) != 2) {
        fprintf(stderr, "Error parsing input\n");
        return 1;
      }

      alice_total += alice;
      bob_total += bob;

      if (current_alice_die1) {
        d1[d1_size++] = alice;
        d2[d2_size++] = bob;
      } else {
        d2[d2_size++] = alice;
        d1[d1_size++] = bob;
      }

      if (alice_total != bob_total) {
        current_alice_die1 = !current_alice_die1;
      }
    }

    int d1_count = count_sixes(d1, d1_size);
    int d2_count = count_sixes(d2, d2_size);

    if (d1_count > d2_count) {
      printf("1\n");
    } else {
      printf("2\n");
    }
  }

  return 0;
}
