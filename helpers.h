#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

template <class T>
void printVec(const vector<T> &vec)
{
    for (auto val : vec)
    {
        cout << val << " ";
    }
    cout << endl;
}

template <class T>
void printVecOfVecs(const vector<vector<T> > &vec)
{
    for (const auto &innerVec : vec)
    {
        for (T val : innerVec)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

#endif
