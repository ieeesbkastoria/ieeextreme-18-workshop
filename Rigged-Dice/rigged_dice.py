#
#   CSAcademy Problem - Rigged Dice
#   From: IEEEXtreme 15.0
#   Solved By: Dimitrios and Petros Papakonstantinou
#   Submission Score: 100/100 (112ms - 776KB)
#

def process_game():
    n = int(input())
    d1, d2 = [], []
    alice_total, bob_total = 0, 0
    current_alice_die1 = True

    for _ in range(n):
        alice, bob = map(int, input().split())
        alice_total += alice
        bob_total += bob

        if current_alice_die1:
            d1.append(alice)
            d2.append(bob)
        else:
            d2.append(alice)
            d1.append(bob)

        if alice_total != bob_total:
            current_alice_die1 = not current_alice_die1

    d1_count = d1.count(6)
    d2_count = d2.count(6)

    print("1" if d1_count > d2_count else "2")

def main():
    game_num = int(input())
    for _ in range(game_num):
        process_game()

if __name__ == "__main__":
    main()
