#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;

/*
Maintain a map of every available letter and for each team name, check if the
letter is still available.
If it is, mark it as unavailable. If not, that team cannot make their name.
If all letters in the team name are available, that team can make their name.
*/

int main()
{
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int P, T;
    cin >> P >> T;

    // create map of problems that can be indexed by the letter
    unordered_map<char, bool> letters;
    for (int i = 0; i < 26; i++)
    {
        letters.insert(pair<char, bool>(alphabet[i], (i < P)));
    }

    char str[80] = {'\0'};
    bool canBeFirstSolver = 1;
    int numFirstSolvers = 0;

    // for every team, check the availability of their letters
    for (int i = 0; i < T; i++)
    {
        cin >> str;
        for (auto let : str)
        {
            if (let == '\0' || let == '\n')
            {
                continue;
            }
            if (letters.at(let) == 1)
            {
                // if the letter is available, mark as unavailable
                letters.at(let) = 0;
            }
            else
            {
                // if letter unavailable, this team cannot be a first solver
                canBeFirstSolver = 0;
            }
            cout << let << endl;
        }
        if (canBeFirstSolver)
        {
            numFirstSolvers++;
        }
        cout << str << endl;

        memset(str, '\0', 80);
        canBeFirstSolver = 1;
    }

    cout << numFirstSolvers << endl;

    return 0;
}
