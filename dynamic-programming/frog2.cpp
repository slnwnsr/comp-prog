#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void printvec(vector<int> vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int main()
{
    int N;
    cin >> N;

    int K;
    cin >> K;

    vector<int> heights(N);
    for (int i = 0; i < N; i++)
    {
        cin >> heights[i];
    }

    vector<int> costs(N);
    costs[0] = 0;
    costs[1] = abs(heights[0] - heights[1]);

    int curcost, i = 2, j = 1, cheapest = 1e9 + 7;
    while (i < N)
    {
        // find min potential cost to jump from the last K stones (but not going behind the 0th stone)
        while (j <= K && j <= i)
        {
            curcost = costs[i - j] + abs(heights[i] - heights[i - j]);
            if (curcost < cheapest)
            {
                cheapest = curcost;
            }
            j++;
        }

        costs[i] = cheapest;
        cheapest = 1e9 + 7;
        j = 1;
        i++;
    }

    // printf("Costs: ");
    // printvec(costs, N);

    cout << costs[N - 1] << endl;

    return 0;
}
