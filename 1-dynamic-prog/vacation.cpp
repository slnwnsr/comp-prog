#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

/*
Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of N days. For each i (1 <= i <= N) , Taro will choose one of the following a
ctivities and do it on the i-th day:

A: Swim in the sea. Gain ai points of happiness.
B: Catch bugs in the mountains. Gain bi points of happiness.
C: Do homework at home. Gain ci points of happiness.

As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.
Find the maximum possible total points of happiness that Taro gains.

notes:
- know how much joy each activity would give joy
- rows correspond to the days: first row is first day, etc
- cannot do same activity twice in a row
- what is the maximum joy you can get?

dp[day][activity]

have a table with a, b, c as y
day numbers x

each cell records the most joy you could get that day
first row is just the value from the days
subsequent rows are the day-activities current joy + the max of the joy before it that is NOT the current activity's joy


*/

int main()
{
    return 0;
}
