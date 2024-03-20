#include <bits/stdc++.h>
using namespace std;

class sol
{
#define maxn 100
    char G[maxn][maxn];
    int row[maxn], col[maxn];
    int dg[2 * maxn], udg[2 * maxn];

public:
    int n; // 皇后数目//同时代表着行数目
    int ans = 0;
    void init()
    {
        for (int i = 0; i < n; i++)
        {
            for (int i2 = 0; i2 < n; i2++)
            {
                G[i][i2] = '.';
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
        // dfs(0);
        dfs2(0, 0, 0);
    }

    void dfs(int r) // 写法分析1,传入参数为行，然后对列和对角线进行分析（高效模板）
    {
        if (r == n)
        {
            for (int i = 0; i < n; i++)
            {
                cout << G[i] << endl;
            }
            cout << "输出结果+1" << endl;
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (col[i] == false && dg[i + r] == false && udg[r - i + n] == false)
            {
                col[i] = dg[i + r] = udg[r - i + n] = true;
                G[r][i] = 'Q';
                dfs(r + 1);
                G[r][i] = '.';
                col[i] = dg[i + r] = udg[r - i + n] = false;
            }
        }
    }

    void dfs2(int x, int y, int s) // 朴素搜索遍历方法
    {
        if (s == n)
        {
            for (int i = 0; i < n; i++)
            {
                cout << G[i] << endl;
            }
            cout << "输出结果+1" << endl;
            return;
        }

        if (y >= n)
        {
            y = 0;
            x++;
        }
        if (x >= n)
        {
            if (s == n)
            {
                for (int i = 0; i < n; i++)
                {
                    cout << G[i] << endl;
                }
                cout << "输出结果+1" << endl;
                return;
            }
            // return;
        }

        dfs2(x, y + 1, s); //递归树思路写法
        if (row[x] == false && col[y] == false && dg[x + y] == false && udg[x - y + n] == false)
        {
            row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
            G[x][y] = 'Q';
            dfs2(x, y + 1, s + 1);
            G[x][y] = '.';
            row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
        }//递归树的思路写法是直接使用递归树的方式来进行递归操作的，递归深度多，时间较长。

        // for (int i = x; i < n; i++)//循环思路写法
        // {
        //     for (int j = y; j < n; j++)
        //     {
        //         if (row[i] == false && col[j] == false && dg[i + j] == false && udg[i - j + n] == false)
        //         {
        //             row[i] = col[j] = dg[i + j] = udg[i - j + n] = true;
        //             G[i][j] = 'Q';
        //             dfs2(x, y + 1, s + 1);
        //             G[i][j] = '.';
        //             row[i] = col[j] = dg[i + j] = udg[i - j + n] = false;
        //         }
        //     }
        // }
    }
};

int main()
{
    sol().make();

    return 0;
}