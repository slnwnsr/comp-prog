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
Vasiliy likes to rest after a hard work, so you may often meet him in some bar nearby. As all programmers do, he
loves the famous drink "Beecola", which can be bought in n different shops in the city. It's known that the price
of one bottle in the shop i is equal to xi coins.
Vasiliy plans to buy his favorite drink for q consecutive days. He knows, that on the i-th day he will be able to
spent mi coins. Now, for each of the days he want to know in how many different shops he can buy a bottle of "Beecola".
Input:
The first line of the input contains a single integer n (1 ≤ n ≤ 100 000) — the number of shops in the city that
sell Vasiliy's favourite drink.
The second line contains n integers xi (1 ≤ xi ≤ 100 000) — prices of the bottles of the drink in the i-th shop.
The third line contains a single integer q (1 ≤ q ≤ 100 000) — the number of days Vasiliy plans to buy the drink.
Then follow q lines each containing one integer mi (1 ≤ mi ≤ 109) — the number of coins Vasiliy can spent on the i-th day.
Output:
Print q integers. The i-th of them should be equal to the number of shops where Vasiliy will be able to buy a
bottle of the drink on the i-th day.
Ex. input:          output:
5                   0
3 10 8 6 11         4
4                   1
1                   5
10
3
11

Notes:
- Sort the array containing the prices of the drinks from each store
- Use binary search on each
*/

// from GeeksforGeeks https://www.geeksforgeeks.org/binary-search/
// we return the index at which the first element larger or equal to x is + 1, which is the number of affordable shops
int binarySearchCount(vector<int> &arr, int &n, int &key)
{
    int left = 0, right = n;
    int mid;
    while (left < right)
    {
        mid = (right + left) >> 1;
        // cout << "mid: " << mid << endl;

        if (arr[mid] == key)
        {
            // while (mid + 1 < n && arr[mid + 1] == key)
            //     {mid++;}
            break;
        }
        // if key is smaller, ignore right half
        else if (arr[mid] > key)
        {
            right = mid;
        }
        // if key is greater, ignore left half
        else
        {
            left = mid + 1;
        }
    }

    // if key is not found in array then it will be before mid
    while (mid > -1 && arr[mid] > key)
    {
        mid--;
    }

    return mid + 1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> shops(0);
    int a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        shops.push_back(a);
    }
    int m;
    cin >> m;
    vector<int> coins(0);
    int b;
    for (int i = 0; i < m; ++i)
    {
        cin >> b;
        coins.push_back(b);
    }

    // printVec(shops);
    // printVec(coins);

    // sort shops in ascending order
    sort(shops.begin(), shops.end());
    cout << "sorted shop array: " << endl;
    printVec(shops);

    // find the number of shops we can afford by binary searching the daily amount of coins in the shops array
    int shopsSize = shops.size();
    for (int i = 0; i < coins.size(); i++)
    {
        cout << binarySearchCount(shops, shopsSize, coins[i]) << endl;
    }

    return 0;
}
