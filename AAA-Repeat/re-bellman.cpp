#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, w;
};
const int N = 10100;
int G[N][N]; // 出发点为1开始
Edge e[N];
int n, m, ans;
int k;
int start = 1, target;
int dist[N], back[N];
const int INF = 0x3f3f3f3f;
class sol
{
public:
    void init()
    {
        cin >> n >> m;
        cin >> k;

        for (int i = 1; i <= m; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            e[i].a = a;
            e[i].b = b;
            e[i].w = w;
        }
        memset(dist, 0x3f, sizeof(dist));
    }

    int bellman(int k) // k是松弛操作的次数
    {
        dist[start] = 0;
        for (int i = 0; i < k; i++)
        {
            memcpy(back, dist, sizeof(dist));
            for (int i = 1; i <= m; i++)
            {
                int a = e[i].a;
                int b = e[i].b;
                int w = e[i].w;
                if (back[a] + w < dist[b])
                {
                    dist[b] = back[a] + w;
                }
            }
        }

        return dist[n];
    }

    void make()
    {
        init();

        // cout << bellman(k) << endl;
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << dist[i] << " ";
        // }

        int res = bellman(k);
        if (res > 0x3f3f3f3f / 2)
        {
            cout << "impossible";
        }
        else
        {
            cout << res << endl;
        }
    }
};

int main()
{
    sol().make();
}

/*
测试数据
3 3 1
1 2 1
2 3 1
1 3 3

结果3
*/