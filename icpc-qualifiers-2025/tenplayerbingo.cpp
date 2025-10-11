#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "../helpers.h"
using namespace std;

// PASSED problem J Ten Player Bingo
// https://naq25.kattis.com/contests/naq25/problems/tenplayerbingo

// we have numbers 1 to 100 and each of the 10 players needs 10 numbers in this
// set, and any two players' numbers will not overlap
// the last player to yell bingo will be the player who needs the last number in
// the list, aka the player whose number equals the unit digit of the last number

int main()
{
    int lastNum = -1;
    for (int i = 0; i < 100; i++)
    {
        cin >> lastNum;
    }

    // extract unit digit of last number, which is the number of the player
    // who will call bingo out last
    int lastUnit = lastNum % 10;
    if (lastUnit == 0)
    {
        // handle edge case where the player number is 10
        lastUnit = 10;
    }

    cout << lastUnit << endl;

    return 0;
}
