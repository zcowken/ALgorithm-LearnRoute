#include <bits/stdc++.h>

using namespace std;

// 二分图的最大匹配（配对问题）
// 使用邻接表会降低更多的复杂度

/*

使用有向的邻接表的原因
实际上，男生和女生的编号是一致的，都是从1开始到ni
所以，要么把女生的号码在1的基础上加上男生的数量，
要么认为男生女生号码重合，此时使用有向边就可以满足（模仿方式为男生选择女生，此时有向边）

方法2将女生的号码加多n1，此时使用无向是没有影响的
因为dfs中的for枚举范围是1-n1号，女生指向男生的无向边是没有影响的

*/

#define N 10010
class graph
{
public:
    vector<vector<int>> G; // 邻接表存储方式
    int n1, n2, m;
    int ans = 0;
    int vis[N];
    int match[N];

    void init()
    {
        cin >> n1 >> n2 >> m;
        G = vector<vector<int>>(n1 + n2 + 10);

        while (m--)
        {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b); // 只使用单向边的原因是什么呢？在上方有解释
            G[b].push_back(a);
        }
    }

    void make()
    {
        init();
        for (int i = 1; i <= n1; i++)
        {
            memset(vis, 0, sizeof(vis));
            int res = dfs(i);
            if (res)
            {
                ans++;
            }
        }

        cout << ans << endl;
    }

    bool dfs(int u)
    {
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if (!vis[v])
            {
                vis[v] = true;
                if (match[v] == 0 || dfs(match[v]) == true)
                {
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
};

#define N 10010
class graph_method2 // 
{
public:
    vector<vector<int>> G; // 邻接表存储方式
    int n1, n2, m;
    int ans = 0;
    int vis[N];
    int match[N];

    void init()
    {
        cin >> n1 >> n2 >> m;
        G = vector<vector<int>>(n1 + n2 + 10);

        while (m--)
        {
            int a, b;
            cin >> a >> b;
            b += n1;
            G[a].push_back(b); // 只使用单向边的原因是什么呢？在上方有解释
            // G[b].push_back(a);
        }
    }

    void make()
    {
        init();
        for (int i = 1; i <= n1; i++)
        {
            memset(vis, 0, sizeof(vis));
            int res = dfs(i);
            if (res)
            {
                ans++;
            }
        }

        cout << ans << endl;
    }

    bool dfs(int u)
    {
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if (!vis[v])
            {
                vis[v] = true;
                if (match[v] == 0 || dfs(match[v]) == true)
                {
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    graph_method2().make();
}