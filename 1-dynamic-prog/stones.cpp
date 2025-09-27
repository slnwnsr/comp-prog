#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "../helpers.h"
using namespace std;

/*
There is a set A = {a1, a2, ... an} consisting of N positive integers. Taro and
Jiro will play the following game against each other.
Initially, we have a pile consisting of K stones. The two players perform the
following operation alternately, starting from Taro:
Choose an element x in A, and remove exactly x stones from the pile.
A player loses when he becomes unable to play. Assuming that both players play
optimally, determine the winner.
Constraints
All values in input are integers. 1≤N≤100, 1≤K≤10, 1≤a1≤a2≤...≤K
Input
Input is given from Standard Input in the following format:
N K
a1 a2 ... aN
Output
If Taro will win, print First; if Jiro will win, print Second.

Notes:
- Build a dp array where dp[i] = 1 if the current player will win, 0 if they lose

*/

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<bool> state(K + 1, 0);

    // i is the number of stones left at the state i of the game
    state[0] = 0;
    for (int i = 1; i < K + 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // mark 1 if there is a move that will force your opponent to lose
            if (i - A[j] >= 0 && state[i - A[j]] == 0)
            {
                state[i] = 1;
                break;
            }
        }
        // leave as 0 if there are no moves you can make to force the opponent to lose
    }

    if (state[K] == 0)
    {
        cout << "Second" << endl;
    }
    else
    {
        cout << "First" << endl;
    }
    return 0;
}
