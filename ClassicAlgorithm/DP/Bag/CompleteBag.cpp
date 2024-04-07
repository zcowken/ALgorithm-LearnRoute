#include <bits/stdc++.h>

using namespace std;

const int N = 2022;
int f[N][N]; // 代表的是前i种类物品，容量为j的最大价值
int f2[N];
int v[N], w[N];
int n, m;

class sol
{
public:
    void init()
    {
        cin >> n >> m; // 容量最大为m，物品种类为n
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i] >> w[i];
        }
    }

    void make() // 一般会被卡时间
    {
        init();

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                f[i][j] = f[i - 1][j];
                for (int k = 0; k * v[i] <= j; k++)
                {
                    f[i][j] = max(f[i][j], f[i][j - k * v[i]] + k * w[i]);
                }
            }
        }
        cout << f[n][m] << endl;
    }

    void make2() // 三维压缩到二维
    {
        init();

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                f[i][j] = f[i - 1][j];

                if (j >= v[i])
                {
                    f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
                }
            }
        }
        cout << f[n][m] << endl;
    }

    void make3()
    {
        init();

        for (int i = 1; i <= n; i++) //三维到二维优化到一维
        {
            /*
                将f改为一维的f2的原因
                由于完全背包问题中
                f只是使用到了i-1层次的数据
                所以，利用滑动数组的思想
                i-1层次的数据可以被当前i层次给获取到
                所以，可以删除下标i的空间，将空间改为f2[j]的动态规划
               ###

                 首先 i下标 的数据无需关注，因为每一次更新完成后都是
                i以前的物品的最大价值，将i行去除的时候，准备更新i行的时候，
                f2[j]所存储的数据实际上就是f[i-1][j] (因为这是准备更新f2[j]之前)

               ###
                然后是考虑更新次序的问题
                由于f[i][j] = max(f[i-1][j],f[i][j - v[i]]+ w[i])
                可以发现，f[i][j-v[i]]在i层次更新的时候，使用的是i层次的数据更新的
                所以，需要从左到右更新，和01背包不同，不需要更改顺序（或者说完全背包问题的更新方式必须要从左到右，目的是获取到i层次的信息）
            */
            for (int j = v[i]; j <= m; j++)
            {
                f2[j] = max(f2[j], f2[j - v[i]] + w[i]);
            }
        }
        cout << f2[m] << endl;
    }
};

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    sol().make3();
    return 0;
}