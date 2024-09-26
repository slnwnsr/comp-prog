#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
There are N stones, numbered 1,2,…,N. For each 1≤i≤N), the height of Stone i is hi.
There is a frog who is initially on Stone 1. He will repeat the following action some number of
times to reach Stone N:
If the frog is currently on Stone i, jump to either stone i+1 or stone i+2.
Here, a cost of |hi - hj| is incurred, where j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone N

notes:
- recursive algorithms here make too many calls very quickly
- build the array of costs as you go, looking at the last 2 stones and calculating the cheapest cost
  based on the cost of the (i-1 or i-2) stone plus the cost of getting from that stone to the current stone
*/

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
