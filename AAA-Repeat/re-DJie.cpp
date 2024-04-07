#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int n;
int m;
int start, tar;
int G[N][N];
int dist[N];
const int INF = 0x3f3f3f3f;

class sol
{
public:
    void init()
    {
        memset(dist, 0x3f, sizeof(dist));
        cin >> n >> m >> start;
        for (int i = 0; i < m; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            G[a][b] = w;
            G[b][a] = w;
        }
    }
    int dj(int start)
    {
        dist[start] = 0;
        queue<pair<int, int>> q;
        q.push({0, start});

        while (!q.empty())
        {
            int curr = q.front().second;
            int curr_dist = q.front().first;
            q.pop();

            for (int v = 1; v <= n; v++)
            {
                if (G[curr][v])
                {
                    if (G[curr][v] + curr_dist < dist[v] || dist[v] == INF)
                    {
                        dist[v] = G[curr][v] + curr_dist;
                        q.push({dist[v], v});
                    }
                }
            }
        }

        return dist[n];
    }

    void make()
    {
        init();
        cout << dj(start) << endl;

        for (int i = 1; i <= n; i++)
        {
            cout << dist[i] << " ";
        }
    }
};

int main()
{
    sol().make();
}

/*
10 15 1
1 2 1
1 4 3
2 3 2
3 4 1
3 5 5
3 6 7
4 5 3
5 6 2
6 1 100
5 7 6
7 8 7
8 9 8
9 10 9
1 9 100
2 10 7
结果：0 1 3 3 6 8 12 19 17 8
*/
