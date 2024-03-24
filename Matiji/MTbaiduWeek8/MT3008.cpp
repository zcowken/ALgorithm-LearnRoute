#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int ma[N][N];
int ma2[N][N];
int n, m;
int ans = INT_MAX;
int sum = 0;

class sol
{
public:
    int en(int l, int w) // 模拟方式的规律化很重要
    {
        for (int i = 1; i <= n - l + 1; i += 1)
        {
            for (int j = 1; j <= m - w + 1; j += 1)
            {
                int temp = ma2[i][j];
                for (int i2 = i; i2 < i + l; i2++)
                {
                    for (int j2 = j; j2 < j + w; j2++)
                    {
                        ma2[i2][j2] -= temp;
                        if (ma2[i2][j2] < 0)
                        {
                            return 0;
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (ma2[i][j] != 0)
                {
                    return 0;
                }
            }
        }

        return 1;
    }

    void
    make()
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> ma[i][j];
                sum += ma[i][j];
            }
        }

        // 运算开始

        for (int i = 1; i <= n; i++) // 枚举长和宽度
        {
            for (int j = 1; j <= m; j++)
            {
                if (sum % (i * j) != 0)
                {
                    continue;
                }

                memcpy(ma2, ma, sizeof(ma));
                if (en(i, j))
                {
                    // cout << i << ":" << j << " " << sum / (i * j) << endl;
                    ans = min(ans, sum / (i * j));
                }
            }
        }

        cout << ans << endl;
    }
};

int main()
{
    sol().make();
    return 0;
}