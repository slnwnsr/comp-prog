#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <utility>
#include "../helpers.h"
using namespace std;

/*
You are given a map of a labyrinth, and your task is to find the shortest path from A to B.
You can walk left, right, up and down.

Input:
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the labyrinth. Each character is . (floor),
# (wall), A (start), or B (end). There is exactly one A and one B in the input.
Output:
First print "YES", if there is a path, and "NO" otherwise.
If there is a path, print the length of the shortest such path and its description as a string
consisting of characters L (left), R (right), U (up), and D (down). You can print any valid solution.

input:          output:
5 8             YES
########        9
#.A#...#        LDDRRRRRU
#.##.#B#
#......#
########

Notes:
- use BFS instead of DFS to find shortest path instead of just any path
- keep track of a visited node's parent and use that later to retrace the shortest path
*/

// bfs that branches outwards (radially?)
void bfs(vector<vector<char>> &grid, int N, int M, int i, int j)
{
    if (i < 0 || i >= N || j < 0 || j >= M || grid[i][j] != '.')
    {
        return;
    }

    // parent[i][j] = {x,y} contains the pair (coordinates) {x,y} of the parent of grid[i][j]
    vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(M));
    queue<pair<int, int>> q;
    q.push({i, j});

    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        // for each of the current node's neighbours, note their parent and add them to the queue
        // vector<pair<int, int> > moves = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<pair<int, int> > moves = {make_pair(0,1),make_pair(0,-1),make_pair(1,0),make_pair(-1,0)};
        for (auto [di, dj] : moves)
        {
            int ni = i + di, nj = j + dj;
            if (ni >= 0 && ni < N && nj >= 0 && nj < M && grid[ni][nj] == '.')
            {
                grid[ni][nj] = 'x'; // mark as visited
                q.push({ni, nj});
                parent[ni][nj] = {i, j}; // add parent
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;
    int M;
    cin >> M;
    // put grid of chars into 2D vector
    vector<vector<char>> grid(N, vector<char>(M));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            std::cin >> grid[i][j];
        }
    }

    printVecOfVecs(grid);

    bfs(grid, N, M, 1, 2);

    printVecOfVecs(grid);

    return 0;
}
