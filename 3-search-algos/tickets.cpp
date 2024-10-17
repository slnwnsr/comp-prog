#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <set>
#include <math.h>
#include "../helpers.h"

using namespace std;

/*
There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.
Each customer announces the maximum price they are willing to pay for a ticket, and after this, they will
get a ticket with the nearest possible price such that it does not exceed the maximum price.
Input:
The first input line contains integers n and m: the number of tickets and the number of customers.
The next line contains n integers h1, ..., hn: the price of each ticket.
The last line contains m integers t1, ..., tn: the maximum price for each customer in the order they arrive.
Output:
Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.
If a customer cannot get any ticket, print -1.
Ex. input:          output:
5 3                 3
5 3 7 8 5           8
4 8 3               -1

Notes:
- Sort the price array and binary search to find the largest <= ticket price for the customer
- Put price array into a binary search tree
*/

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
   // get customer and ticket info
    multiset<int> customers;
    int a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        customers.insert(a);
    }
    vector<int> tickets(0, m);
    int b;
    for (int i = 0; i < m; ++i)
    {
        cin >> b;
    }

    return 0;
}
