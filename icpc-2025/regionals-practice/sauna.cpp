#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;

/*
Maintain the maximum minimum temperature required and the minimum maximum
temperature tolerable. If the interval is valid, the numbers in this interval
are all temperatures that everyone can agree to set the sauna to.
*/

int main()
{
    int N;
    cin >> N;
    int minTemp = -1;
    int maxTemp = (2e5) + 1;
    int a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        if (a > minTemp)
        {
            minTemp = a;
        }
        cin >> b;
        if (b < maxTemp)
        {
            maxTemp = b;
        }
    }

    if (minTemp < maxTemp)
    {
        cout << maxTemp - minTemp + 1 << " " << minTemp << endl;
    }
    else
    {
        cout << "bad news" << endl;
    }

    return 0;
}
