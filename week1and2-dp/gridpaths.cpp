#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

/*
Consider an N×N grid whose squares may have traps. It is not allowed to move to a square with a trap.
Your task is to calculate the number of paths from the upper-left square to the lower-right square.
You can only move right or down.

notes:
- if there are no traps, you can answer right away
    - we know we must do M moves to the right and N moves to the bottom
    - choose N from M+N = (M+N)!/(M!N!) different ways if there were no traps
- big idea: for a single cell there are 2 ways to get to it, either from the left or above
- K1 ways to getting to a cell from the left, K2 ways to get to that cell from above = K1+K2 ways to reach that cell

make a 2D array which stores however many ways there are to get to cell [i][j]
1 way to get to the starting cell, only 1 way to get anwhere is first column and first row
0 ways to get to a trap
fill this array in a for loop row-by-row

for i = 1 -> N dp[i][0] = dp[i-1][0]
dp[0][i] ]
for i = 1 -> N
for i = 1 -> M
[i][j] = [i-1][j] + [i][j-1]

take care of first row and first column first then move on from there

*/

int main()
{
    int N;
    cin >> N;

    vector<vector<char> > grid(N, vector<char>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cin >> grid[i][j];
        }
    }

    // print grid
    std::cout << "Grid: \n";
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << '\n';
    }

    // grid to contain running number of paths
    vector<vector<int> > paths(N, vector<int>(N, 0));

    // begin with setting the first row and column
    for (int i = 0; i < N; i++)
    {
        if (grid[0][i] == '.')
        {
            paths[0][i] = 1;
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (grid[i][0] == '.')
        {
            paths[i][0] = 1;
        }
        else
        {
            break;
        }
    }

    // print paths
    std::cout << "Paths: \n";
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cout << paths[i][j] << ' ';
        }
        std::cout << '\n';
    }

    // now do inner grid
    // if the current char is not *, the # paths = # to the left + # above
    // if *, # paths = 0

    // Print the number of paths modulo 10^9 + 7
    // ^ dp[i][j] == (dp.... + dp..) %  1e9 + 7
    return 0;
}
