#include <bits/stdc++.h>

using namespace std;

/*
染色法判断二分图
*/

class Solution //AC,判断二分图
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        memset(color, 0, sizeof(color));
        int ret = true;
        n = graph.size();
        // 开始记录
        // 邻接表格式
        G = graph;
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
};

int main()
{
}