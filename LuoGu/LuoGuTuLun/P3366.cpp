#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
int G[N][N];
#define INF 0x3f3f3f3f

class graph_prim
{
public:
    int dist[N];
    int vis[N];
    int n, m;
    void init()
    {
        memset(G, 0x3f, sizeof(G));
        memset(dist, 0x3f, sizeof(dist));
        cin >> n;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            G[a][b] = min(w, G[a][b]);
            G[b][a] = G[a][b];
        }
    }

    void make()
    {
        init();
        int ret = prim();
        if (ret != INF)
        {
            cout << ret << endl;
        }
        else
        {
            cout << "orz" << endl;
        }
    }

    int prim() // n^2算法的prim
    {
        int res = 0;

        // 在本prim算法当中，开始的是没有点被选择的，所以，一开始一定会选择到INF的点，此时i是为0的，所以，权值的加入在i > 0 的时候来加入
        for (int i = 0; i < n; i++)
        {
            int t = -1;
            for (int j = 1; j <= n; j++)
            {
                if (!vis[j] && (t == -1 || dist[t] > dist[j]))
                {
                    t = j; // 选择当前最近的点
                }
            }

            vis[t] = true;

            if (i != 0 && dist[t] == INF)
            {
                return INF;
            }

            // cout << t << " " << dist[t] << endl;
            if (i != 0)
            {
                res += dist[t];
            }

            for (int j = 1; j <= n; j++)
            {
                // 更新集合内的点到别的点的最小距离
                dist[j] = min(dist[j], G[t][j]);
            }
        }

        return res;
    }

    class CMP
    {
    public:
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            return a.first > b.first;
        }
    };
    int prim2_heap()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, CMP> q;

        int res = 0;
        dist[1] = 0;
        q.push(pair<int, int>(dist[1], 1));
        vis[1] = true;

        while (!q.empty())
        {
            int curr = q.top().second;
            int curr_dist = q.top().first;
            q.pop();
            if (vis[curr] == false)
            {
                res += dist[curr];
            }

            vis[curr] = true;

            for (int i = 1; i <= n; i++)
            {
                dist[i] = min(dist[i], G[curr][i]);
                if (!vis[i])
                {
                    q.push({dist[i], i});
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == false)
            {
                res = INF;
            }
        }

        return res;
    }
};

int main()
{
    graph_prim().make();
}