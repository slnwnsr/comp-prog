#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iomanip>
#include "../helpers.h"
using namespace std;

/*
There are N items, numbered For each Ni, Item i has a weight of wi and a
value of vi.
Taro has decided to choose some of the N items and carry them home in a
knapsack. The capacity of the knapsack is W, which means that the sum of
the weights of items taken must be at most W.
Find the maximum possible sum of the values of items that Taro takes home.

Notes:
- OPT(i, w) = max value attainable by using w1, ..., wi with max capacity w
- OPT(i, w) = {OPT(i-1, w) if w < wi}
            {max(OPT(i-1, w), vi + OPT(i-1, w-wi)) otherwise}
- need to divide DP values by some large number to avoid overflow
*/

int main()
{
    int N, W;
    cin >> N >> W;

    vector<int> weights(N + 1, 0);
    vector<int> values(N + 1, 0);
    for (int i = 1; i < N + 1; i++)
    {
        cin >> weights[i];
        cin >> values[i];
    }
    // printVec(weights);
    // printVec(values);

    // 2D array tracking the cumulative max value that you can hold at weight j
    // after adding item i to the pool of items you can choose from
    vector<vector<double>> DP(N + 1, vector<double>(W + 1, 0));
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (j < weights[i])
            {
                DP[i][j] = DP[i - 1][j];
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], (values[i] / 1e9) + DP[i - 1][j - weights[i]]);
            }
        }
    }
    // printVecOfVecs(DP);

    cout << fixed << setprecision(0) << (DP[N][W] * 1e9) << endl;

    return 0;
}
