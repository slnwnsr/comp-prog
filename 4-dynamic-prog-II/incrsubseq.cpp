#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "../helpers.h"
using namespace std;

/*
You are given an array containing n integers. Your task is to determine the longest increasing subsequence i
n the array, i.e., the longest subsequence where every element is larger than the previous one.
A subsequence is a sequence that can be derived from the array by deleting some elements without changing the
order of the remaining elements
Input:
The first line contains an integer n, the size of the array.
Then there are n integers x1, x2, ..., xn, the contents of the array.
Output:
Print the length of the longest increasing subsequence.
Ex. Input:              Output:
8                       4
7 3 5 3 6 2 9 8
4                       1
1 1 1 1
*/

int main()
{
    int n;
    cin >> n;
    vector<int> ints;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        ints.push_back(x);
    }

    // keep an array dp containing only the integers we want to keep
    // if the next int in ints > last non-infinity int in dp, replace the dp one with the smaller one from ints
    vector<int> dp(n + 1, 1e9 + 1);
    dp[0] = -(1e9 + 1);
    for (int x : ints)
    {
        // cout << "x in ints: " << x << endl;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        *it = x;
    }
    // printVec(dp);

    // count the number of non-infinity numbers = length of our subsequence
    int count = -1;
    // first element will always be -1e9 so start with count = -1
    for (int x : dp) {
        if (x < 1e9 + 1) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
