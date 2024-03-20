#include <bits/stdc++.h>
using namespace std;

// 邻接表格式
class sol
{
public:
#define N 1010
    int color[N];
    vector<vector<int>> G; // 邻接表的方式存储
    int n;
    bool dfs(int u, int c) // 染色法函数，搜搜函数，搜索到两个相连的点的颜色相同的时候，返回false
    {
        color[u] = c;
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if (!color[v])
            {
                bool t = dfs(v, 3 - c);
                if (t == false)
                {
                    return false;
                }
            }
            else if (color[u] == color[v])
            {
                return false;
            }
        }
        return true; // 从u点出发寻找的点的颜色都已寻找完毕同时没有相连的点的颜色未相同的时候，返回真
    }

    int make()
    {
        memset(color, 0, sizeof(color));
        int ret = true;
        cin >> n;
        int m;
        cin >> m;

        // 开始记录
        // 邻接表格式
        G = vector<vector<int>>(n);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        for (int i = 0; i < n; i++)
        {
            if (color[i] == false)
            {
                int res = dfs(i, 1);
                if (res == false)
                {
                    ret = false;
                    break;
                }
            }
        }

        return ret;
    }
};

#define N2 1010
#define INF 0x3f3f3f3f
int G[N2][N2];
int n;
int color[N2];
class sol_matirx
{
public:
    bool dfs(int u, int c)
    {
        color[u] = c;
        for (int i = 0; i < n; i++)
        {
            int v = i;

            if (G[u][i] != INF && u != v)
            {
                if (color[v] == false)
                {
                    bool t = dfs(v, 3 - c);
                    if (t == false)
                    {
                        return false;
                    }
                }
                else if (color[u] == color[v])
                {
                    return false;
                }
            }
        }
        return true;
    }

    void init()
    {

        int m; // 边数目

        cin >> n >> m;
        memset(G, 0x3f, sizeof(G));
        memset(color, 0, sizeof(color));
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            G[a][b] = 1;
            G[b][a] = 1;
        }
    }

    bool make()
    {
        init();
        bool ret = true;
        for (int i = 0; i < n; i++)
        {
            if (color[i] == false)
            {
                int res = dfs(i, 1);
                if (res == false)
                {
                    ret = false;
                    break;
                }
            }
        }

        return ret;
    }
};

int main()
{
    cout << sol_matirx().make();
    return 0;
}

/*

测试数据
@1.
4 5
0 1
0 3
1 2
3 2
0 2


@2.
4 4
0 1
0 3
1 2
3 2
*/