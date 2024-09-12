#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> heights(N);
    for (int i = 0; i < N; i++)
    {
        cin >> heights[i];
    }

    vector<int> costs(N);
    costs[0] = 0;
    costs[1] = abs(heights[0] - heights[1]);

    int i = 2;
    while (i < N)
    {
        int cost1 = costs[i - 2] + abs(heights[i] - heights[i - 2]);
        int cost2 = costs[i - 1] + abs(heights[i] - heights[i - 1]);

        costs[i] = min(cost1, cost2);
        i++;
    }

    cout << costs[N - 1] << endl;

    return 0;
}
