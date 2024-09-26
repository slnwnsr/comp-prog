#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

// template <int>
// istream &operator>>(istream &in, vector<int> &vec)
// {
//     for (int i = 0; i < vec.size(); ++i)
//         in >> vec[i];

//     return in;
// }

/*
N >= 1 houses have not been connected to internet. There are pairs of houses with a network
cable connecting them. House 1 is connected to the internet. A house is connected to the internet
if it is connected to a house that has internet.
Given a list of which pairs of houses are already connected by a network cable, determine which
houses are not yet connected to the internet.

Input: The first line of input contains two integers 1 ≤ N, M ≤ 200000, where N is the number of houses
and M is the number of network cables already deployed. Then follow M lines, each containing a pair
of distinct house numbers 1≤a,b≤N meaning that house a and house b are already connected by a network
cable. Each house pair is listed at most once in the input.
Output: if all houses have internet, out "Connected". Otherwise, print houses without internet
numbers in ascending order
eg. input:
6 4
1 2
2 3
3 4
5 6
output:
5
6

Notes:
- bfs or dfs are probably the solutions to this
- N are the number of verticies, M is number of edges, the following input is telling you the edges
- can conduct a search starting from node 1, adding each house that gets visited to a "has internet" list
- when the search terminates, look at what is NOT in the "has internet" list
*/

// will add this helper to a separate helper file later
void printAdj(const vector<vector<int> > &vec)
{
    for (const auto &innerVec : vec)
    {
        for (int val : innerVec)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

// will add this helper to a separate helper file later
void printVec(const vector<int> &vec)
{
    for (auto val : vec)
    {
        cout << val << " ";
    }
    cout << endl;
}

// depth-first search that will mark each node it visits on the vis vector
void dfs(vector<int> &vis, vector<vector<int> > &adj, int v)
{
    vis[v] = 1;
    for (int to : adj[v])
    {
        if (!vis[to])
        {
            dfs(vis, adj, to);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    int M;
    cin >> M;

    // create adjacency lists for each house/node
    vector<vector<int> > adj(N);

    int a, b;
    for (int i = 0; i < M; ++i)
    {
        cin >> a;
        cin >> b;
        a--;
        b--;
        // add the houses/nodes to each other's adjacency lists
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // create a list of houses/nodes we have visited: 0 = not visited, 1 = visited
    // visited means there is a path from house 1 to the current house, so that house has internet
    vector<int> hasInternet(N, 0);
    dfs(hasInternet, adj, 0);

    // cout the houses that DO NOT have internet
    int flag = 0;
    for (int i = 0; i < hasInternet.size(); i++)
    {
        if (hasInternet[i] == 0)
        {
            cout << (i + 1) << endl;
            flag = 1;
        }
    }
    // if all houses are connected, cout "Connected"
    if (!flag)
    {
        cout << "Connected" << endl;
    }

    return 0;
}
