#include <bits/stdc++.h>

using namespace std;

const int N = 210;
int f[N][N], v[N][N], w[N][N], s[N];
int f2[N];
int n, m;

class sol
{
public:
    void init()
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
            for (int j = 0; j < s[i]; j++)
            {
                cin >> v[i][j] >> w[i][j];
            }
        }
    }
    void make() // 经过让循环中获取到第i-1层次的数据后，可以正确产生答案
    {
        init();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                f[i][j] = f[i - 1][j]; // 这个是一定成立的

                for (int k = 0; k < s[i]; k++) // k=0的时候不会获取到i-1层次的数据来更新第i层次
                {
                    // f[i][j] = max(f[i][j], f[i - 1][j]);
                    if (v[i][k] <= j)
                    {
                        f[i][j] = max(f[i][j], f[i - 1][j - v[i][k]] + w[i][k]);
                    }
                }
            }
        }

        cout << f[n][m] << endl;
    }

    void make2()
    {
        init();
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 0; j--)
            {
                for (int k = 0; k < s[i]; k++) // k=0的时候会获取到i-1层次的数据来更新第i层次
                {
                    if (v[i][k] <= j)
                    {
                        f2[j] = max(f2[j], f2[j - v[i][k]] + w[i][k]);
                    }
                }
            }
        }

        cout << f2[m] << endl;
    }
};

int main()
{
    sol().make();
    return 0;
}