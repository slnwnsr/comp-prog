#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "../helpers.h"
using namespace std;

// PASSED problem I Star Guardians
// https://naq25.kattis.com/contests/naq25/problems/starguardians

int main()
{
    int N;
    cin >> N;
    vector<int> additionalProbs(N);
    for (int i = 0; i < N; i++)
    {
        cin >> additionalProbs[i];
    }
    vector<int> probsPerGuardian(N);
    for (int i = 0; i < N; i++)
    {
        cin >> probsPerGuardian[i];
    }
    printVec(additionalProbs);
    printVec(probsPerGuardian);

    // sort the guardians from most problems they can solve to least
    sort(probsPerGuardian.begin(), probsPerGuardian.end(), greater<int>());
    printVec(probsPerGuardian);

    // iterate through each guardian calculating the max average problems
    double maxAvgProbs = 0;
    double totalGuardianProbs = 0;
    for (int i = 0; i < N; i++)
    {
        totalGuardianProbs += probsPerGuardian[i];
        if ((totalGuardianProbs + additionalProbs[i]) / (i + 1) > maxAvgProbs)
        {
            maxAvgProbs = (totalGuardianProbs + additionalProbs[i]) / (i + 1);
        }
        cout << "Max avg probs for " << i << ": " << maxAvgProbs << endl;
    }
    printf("%lf\n", maxAvgProbs);

    return 0;
}
