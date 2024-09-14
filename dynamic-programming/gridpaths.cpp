#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    char *stuff[N][N];
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            cin >> stuff[x][y];
        }
    }

    // vector<int> heights(N);
    // for (int x = 0; x < N; x++)
    // {
    //     for (int y = 0; y < N; y++)
    //     {
    //         cin >> heights[x+y];
    //     }
    // }

    return 0;
}
