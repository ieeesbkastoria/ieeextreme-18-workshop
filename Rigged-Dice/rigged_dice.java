//
//   CSAcademy Problem - Rigged Dice
//   From: IEEEXtreme 15.0
//   Solved By: Dimitrios and Petros Papakonstantinou
//   Submission Score: 100/100 (1183ms - 36.1MB)
//

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int game_num = scanner.nextInt();
    scanner.nextLine(); // Consume newline

    for (int game = 0; game < game_num; ++game) {
      int n = scanner.nextInt();
      scanner.nextLine(); // Consume newline

      List<Integer> d1 = new ArrayList<>();
      List<Integer> d2 = new ArrayList<>();
      int alice_total = 0, bob_total = 0;
      boolean current_alice_die1 = true;

      for (int i = 0; i < n; ++i) {
        String line = scanner.nextLine();
        String[] tokens = line.split(" ");
        int alice = Integer.parseInt(tokens[0]);
        int bob = Integer.parseInt(tokens[1]);

        alice_total += alice;
        bob_total += bob;

        if (current_alice_die1) {
          d1.add(alice);
          d2.add(bob);
        } else {
          d2.add(alice);
          d1.add(bob);
        }

        if (alice_total != bob_total) {
          current_alice_die1 = !current_alice_die1;
        }
      }

      long d1_count = d1.stream().filter(x -> x == 6).count();
      long d2_count = d2.stream().filter(x -> x == 6).count();

      if (d1_count > d2_count) {
        System.out.println("1");
      } else {
        System.out.println("2");
      }
    }

    scanner.close();
  }
}
