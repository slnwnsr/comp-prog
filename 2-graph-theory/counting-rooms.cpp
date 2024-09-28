#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "helpers.h"
using namespace std;
/*
You are given a map of a building, and your task is to count the number of its rooms. The size of
the map is n×m squares, and each square is either floor or wall. You can walk left, right, up, and
down through the floor squares.

Input: The first input line has two integers n and m: the height and width of the map. Then there
are n lines of m characters describing the map. Each character is either . (floor) or # (wall).
Output: Print one integer: the number of rooms.
ex. input:
5 8
########
#..#...#
####.#.#
#..#...#
########
output:
3

Notes:
- same approach as wheres-my-internet where you dfs a starting room and keep tabs on the nodes that
have not been visited
- continue to search the unvisited nodes until you have no unvisited nodes left, increment a counter
each time you start a search (since a connected group of unvisited nodes is a single room)
*/

void dfs(vector<vector<char> > &grid, int N, int M, int i, int j)
{
    // if the index passed is invalid or if the element is a wall, stop
    if (i < 0 || i >= N || j < 0 || j >= M || grid[i][j] == '#')
    {
        return;
    }
    // mark the element as visited by changing . to #
    grid[i][j] = '#';
    // dfs its neighbours
    dfs(grid, N, M, i - 1, j);
    dfs(grid, N, M, i, j + 1);
    dfs(grid, N, M, i + 1, j);
    dfs(grid, N, M, i, j - 1);
}

int main()
{
    int N;
    cin >> N;
    int M;
    cin >> M;
    // put grid of chars into 2D vector
    vector<vector<char> > grid(N, vector<char>(M));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            std::cin >> grid[i][j];
        }
    }

    // go through each element in the grid, if it's . (a room) then conduct dfs on that "room"
    // every time we initially call dfs from main we have encountered a new room, so rooms++
    int rooms = 0;

    // printVecOfVecs(grid);

    // run dfs for each element in the grid, will compute the number of rooms
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == '.')
            {
                dfs(grid, N, M, i, j);
                rooms++;
            }
        }
    }

    // printf("after full dfs:\n");
    // printVecOfVecs(grid);

    cout << rooms << endl;

    return 0;
}
