#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
int f[N][N];
int n, m;
const int M = 300010;
int f2[M];
int v[M], w[M], s[M];
int cnt = 0;

class sol
{
public:
    void make1() // 最原始的多重背包，容易超时，2000*2000*s[i]，会存在超时问题
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i] >> w[i] >> s[i];
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= s[i]; k++)
                {
                    if (k * v[i] <= j)
                    {
                        f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
                    }
                }
            }
        }
        cout << f[n][m] << endl;
    }

    void make2() // 二进制优化，将多重背包问题改变为01背包问题，然后使用01背包问题的一维优化来减少时间
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            int v1, w1, s1;
            cin >> v1 >> w1 >> s1;
            int k = 1;

            while (k <= s1)
            {
                cnt++;
                v[cnt] = v1 * k; // 将2的k次方个某物品压缩为一个物品，使其呈现0-1背包问题特点
                w[cnt] = w1 * k;
                s1 -= k;
                k *= 2;
            }
            if (s1 != 0)
            {
                cnt++;
                v[cnt] = v1 * s1; // 将2的k次方个某物品压缩为一个物品，使其呈现0-1背包问题特点
                w[cnt] = w1 * s1;
            }
        }

        // 开始0-1背包问题的模板
        n = cnt; // 总物品个数n需要修改为cnt
        // show();
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= v[i]; j--)
            {
                f2[j] = max(f2[j], f2[j - v[i]] + w[i]);
            }
        }

        cout << f2[m] << endl;
    }

    void show()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << v[i] << " ";
        }cout<<endl;
        for (int i = 1; i <= n; i++)
        {
            cout << w[i] << " ";
        }
    }
};

int main()
{
    sol().make2();
    return 0;
}