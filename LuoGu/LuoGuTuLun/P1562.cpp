#include <bits/stdc++.h>
using namespace std;

class sol
{
#define maxn 20
    char G[maxn][maxn];
    int row[maxn], col[maxn];
    int dg[2 * maxn], udg[2 * maxn];

public:
    int n;       // 皇后数目//同时代表着行数目
    int ans = 0; // ans为可行方案数目
    void init()
    {
        for (int i = 0; i < n; i++)
        {
            for (int i2 = 0; i2 < n; i2++)
            {
                cin >> G[i][i2];
            }
        }
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(dg, 0, sizeof(dg));
        memset(udg, 0, sizeof(udg));
    }

    void make()
    {
        cin >> n;
        init();
        dfs(0);
        cout << ans << endl;
    }

    void dfs(int r) // 写法分析1,传入参数为行，然后对列和对角线进行分析（高效模板）
    {
        if (r == n)
        {
            // for (int i = 0; i < n; i++)
            // {
            //     cout << G[i] << endl;
            // }
            // cout << "输出结果+1" << endl;
            ans += 1;
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (col[i] == false && dg[i + r] == false && udg[r - i + n] == false && G[r][i] != '.')
            {
                col[i] = dg[i + r] = udg[r - i + n] = true;
                G[r][i] = 'Q';
                dfs(r + 1);
                G[r][i] = '*';
                col[i] = dg[i + r] = udg[r - i + n] = false;
            }
        }
    }
};

int main()
{
    sol().make();

    return 0;
}