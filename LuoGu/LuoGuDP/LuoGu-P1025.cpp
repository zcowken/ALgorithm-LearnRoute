#include <bits/stdc++.h>

using namespace std;
int n, k;
const int N = 10010;
int f[N][N];
int f2[N];

int sol2_f[N][N]; // sol2_f[i][j]代表数的和为i，由j个数组成的方案数目

class sol
{
public:
    void make()
    {
        init1();
        cout << "f[n][k]" << f[n][k] << endl;
        cout << "f2[n]" << f2[n];
    }
    void init1() // 计算有一个数有多少种方案组成
    {
        /*
        dp划分方式，
        f[i][j]:前i个数，装满背包总容量为j的方案数
        */
        cin >> n >> k;
        for (int i = 0; i <= n; i++)
        {
            f[i][0] = 1;
        }

        //  朴素方式
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         for (int k = 0; k * i <= j; k++)
        //         {
        //             f[i][j] += f[i - 1][j - k * i];
        //         }
        //     }
        // }
        // 二维优化
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {

        //         /*
        //         f[i][j] = f[i - 1][j]+ f[i-1][j-i]+f[i-1][j-2*i]+...+f[i-1][j-k*i]
        //         f[i][j-i] =             f[i-1][j-i]+f[i-1][j-2*i]+...+f[i-1][j-k*i]

        //         所以：
        //         f[i][j] = f[i-1][j]+f[i][j-1];
        //         */
        //         f[i][j] = f[i - 1][j] + f[i][j - i];
        //     }
        // }

        // 一维空间优化
        f2[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                f2[j] = f2[j] + f2[j - i];
            }
        }
    }
};

class sol2
{
public:
    void make()
    {
        init();
        int res = 0;
        for (int i = 0; i <= n; i++)
        {
            res += sol2_f[n][i];
        }
        // cout << res << endl;
        cout << sol2_f[n][k] << endl;
    }
    void init()
    {
        cin >> n >> k;

        sol2_f[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                sol2_f[i][j] = sol2_f[i - 1][j - 1] + sol2_f[i - j][j];
            }
        }
    }
};

int main()
{
    sol2().make();
    return 0;
}