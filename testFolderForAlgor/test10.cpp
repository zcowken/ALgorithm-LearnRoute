#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> G;
    G = vector<vector<int>>(10);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cout << G[a][0];
}