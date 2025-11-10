#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "../helpers.h"
using namespace std;

/*
Have train trach toy pieces: straight/curved tracks, X connectors, Y connectors.
Given any amount of tracks and a specific amount of X and Y connectors, determine
if it is possible to create a closed loop.
Input:
Two integer numbers, the first being the amount of X crossings (0<=X,=1000) and the
second being the amount of Y crossings (0<=Y<=1000)
Output: "possible" if it is possible to make a loop, "impossible" otherwise
Notes:
- Eulerian circuit type question
- X and Y connectors are like nodes in a graph, X is even degree of 4, Y odd degree of 3
- if the total degree of the circuit is odd, we cannot make a circuit
- e.i. if the number of Y connectors is odd
*/

int main()
{
    int X, Y;
    cin >> X >> Y;

    if ((Y & 1) == 1)
    {
        cout << "impossible" << endl;
        return 0;
    }
    cout << "possible" << endl;
    return 0;
}
