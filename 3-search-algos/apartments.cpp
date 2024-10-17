#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <math.h>
#include "../helpers.h"

using namespace std;

/*
There are n applicants and m apartments, and n applicants will accept an apartment within the acceptable range.
Input:
The first input line has three integers n, m, and k: the number of applicants, the number of apartments,
and the maximum allowed difference.
The next line contains n integers a1, ..., an: the desired apartment size of applicant i If the desired
size of an applicant is x, he or she will accept any apartment whose size is between x−k and x+k.
The last line contains m integers b1, ..., bm: the size of each apartment.
Output:
Print one integer: the number of applicants who will get an apartment.
Ex. input:          output:
4 3 5               2
60 45 80 60
30 60 75

Notes:
- Have two pointers for each array, and move them based on if the other pointer's value is valid or not
*/

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int k;
    cin >> k;

    // get applicant and apartment info
    vector<int> applicants(0, n);
    int a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        applicants.push_back(a);
    }
    vector<int> apartments(0, m);
    int b;
    for (int i = 0; i < m; ++i)
    {
        cin >> b;
        apartments.push_back(b);
    }

    // printVec(applicants);
    // printVec(apartments);

    // sort both arrays in ascending order
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    // printVec(applicants);
    // printVec(apartments);

    int asize = applicants.size();
    int bsize = apartments.size();
    int count = 0;
    int i = 0, j = 0;

    // walk through each array, checking if applicants[i] is in range of apartments[j]
    while (i < asize && j < bsize)
    {
        if (abs(applicants[i] - apartments[j]) <= k)
        {
            // if applicant and apartment are a match
            count++;
            i++;
            j++;
        }
        else if (applicants[i] < apartments[j])
        {
            // if applicant is too small for any appartment
            i++;
        }
        else
        {
            // if apartment is too small for any applicant
            j++;
        }
    }

    cout << count << endl;

    return 0;
}
