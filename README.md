# IEEEXtreme-18-Workshop

### Solution to the problems discussed in the IEEEXtreme-Countdown Workshop(13/10) by the [IEEE Student Branch University of Western Macedonia, Kastoria](https://www.instagram.com/ieeesbkastoria/). The two problems that will be discussed are [Rigged Dice](https://csacademy.com/ieeextreme-practice/task/rigged-dice/statement/) and [Maximum Exploitation](https://csacademy.com/ieeextreme-practice/task/exploitation/).

## Table of Contents

- [Rigged Dice](#rigged)
    * [Problem Overview](#rigged_overview)
    * [Solution](#rigged_solution)
- [Maximum Exploitation](#max)
    * [Problem Overview](#max_overview)
    * [Solution](#max_solution)
- [Credits](#credits)

<a name="rigged">

## Rigged Dice 

The code implementation in multiple languages for this problem in can be found [here](https://github.com/Turtel216/IEEEXtreme-Countdown/tree/main/Rigged-Dice).


<a name="rigged_overview">

### Problem Overview

- Alice and Bob play a dice game with two dice labeled Die 1 and Die 2.
- Each die has six faces valued from 1 to 6.
- Initially, Alice has Die 1 and Bob has Die 2.
- Both players start with a score of 0.
- The game consists of N rounds, where in each round both players roll their respective dice.
- They sum the rolled values to their respective scores.
- If the scores differ after any round, they exchange their dice.
- One of the dice is rigged:
    * Normal die: each value (1 to 6) has equal probability (1/6).
    * Rigged die: 6 appears with 2/7 probability; 1 to 5 appear with 1/7 probability.
- The goal: Identify which die is rigged based on the rolls.


<a name="rigged_solution">

### Solution 

1. **Tracking Dice Rolls and Exchanges**:
    - Use two vectors, d1 and d2, to keep track of the rolls made using Die 1 and Die 2, respectively.
    - Initially, Alice uses Die 1, and Bob uses Die 2. If their scores differ after a round, they swap dice.
2.  **Keeping Score**:
    - The total scores for Alice and Bob are updated after every round. If their scores differ, a dice swap occurs. This switch is tracked using the boolean variable ``current_alice_die1``.
3. **Recording Rolls**:
    - For each round, the rolled values are recorded in the appropriate vector based on whether Alice and Bob are using Die 1 or Die 2.
4. **Count the Number of Sixes**:
    - After all rounds, the solution counts how many times each die rolled a 6. This is done using the std::count() function for both d1 (rolls made with Die 1) and d2 (rolls made with Die 2).
5. **Determine Which Die Is Rigged**:
    - Since the rigged die rolls a 6 more frequently, the die that rolls more 6's is identified as the rigged one. If Die 1 rolled more 6’s, the solution outputs 1, otherwise it outputs 2.


<a name="max">

## Maximum Exploitation 

The code implementation in multiple languages for this problem in can be found [here](https://github.com/Turtel216/IEEEXtreme-Countdown/tree/main/Maximum-Exploitation).

<a name="max_overview">

### Problem Overview

- **Goal**: Maximize the resource collection on a matrix (representing a plain) by placing at most two rectangular plants.
- **Matrix Dimensions**: R × C
- **Plant Dimensions**: Either X × Y or Y × X
- **Restrictions**: Plants cannot overlap, but they may touch.
- **Objective**: Find the maximum resource that can be exploited by placing one or two plants.

<a name="max_solution">

### Solution 

#### Prefix Sum Matrix:

**Efficient calculation of submatrix sums**

- Reduces time complexity from brute-force sum calculation to constant time for any submatrix.
- Dynamic Programming Arrays:
- Row[]: Max resource from a plant in a row.
- Col[]: Max resource from a plant in a column.

#### Goal: Use these data structures to explore the placement of one or two plants efficiently.

#### Prefix Sum Calculation:
 - To calculate the sum of any submatrix in constant time:
    sum(r1, c1, r2, c2) = P[r2][c2] − P[r1−1][c2] − P[r2][c1−1] + P[r1−1][c1−1]

#### Dynamic Programming Updates:
- For every possible plant placement, update the maximum resource in Row and Col arrays.
- Compare both X✕Y and Y✕X orientations for maximum resource.

<a name="credits">

## Credits 

- [Dimitrios Papakonstantinou](https://github.com/Turtel216)
- Petros Papakonstantinou

**Spacial Thanks to our ambassador**

- [Παναγιώτης Παπαντώνης](https://github.com/PanagiotisPapantonis)
